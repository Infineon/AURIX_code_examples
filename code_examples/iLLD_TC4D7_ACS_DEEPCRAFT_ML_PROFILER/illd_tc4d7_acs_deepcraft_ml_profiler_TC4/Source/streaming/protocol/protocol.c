/*
* The MIT License (MIT)
* 
* Copyright � 2024 Imagimob AB
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy 
* of this software and associated documentation files (the �Software�), to deal 
* in the Software without restriction, including without limitation the rights 
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
* copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in 
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED �AS IS�, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
* THE SOFTWARE.
* 
*/

#include <stdlib.h>
#include <string.h>
#include "protocol.h"
#include "pb_encode.h"
#include "pb_decode.h"
#include "pb_common.h"
#include "pb.h"

#ifndef pmem_malloc
#define pmem_malloc(size) malloc(size)
#endif

#ifndef pmem_realloc
#define pmem_realloc(ptr, size) realloc(ptr, size)
#endif

#ifndef pmem_free
#define pmem_free(ptr) free(ptr)
#endif

// Helper structure to save password during queries.
// Passwords are masked and can not be retrieved from queries.
typedef struct {
    protocol_Option* option;
    char* original_password;
} password_backup_t;


/*****************************************************************************
 *                           Declarations Internal                           *
 ****************************************************************************/

static protocol_Option* protocol_create_option(
    protocol_Device* device,
    int option_id,
    const char* name,
    const char* description)
{
    int option_index = device->options_count++;
    device->options = (protocol_Option*)pmem_realloc(device->options, sizeof(protocol_Option) * device->options_count);
    if (device->options == NULL)
        return NULL;
    protocol_Option* option = &device->options[option_index];
    option->option_id = option_id;
    option->name = (char*)name;
    option->description = (char*)description;

    return option;  
}

// Return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code, 
// see protocol_get_error_msg().
static int protocol_find_option(
    protocol_t* protocol,
    int device_id, 
    int option_id, 
    protocol_Option** result)
{
    if (protocol == NULL || result == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];

    protocol_Option* option = NULL;
    for (int i = 0; i < device->options_count; i++) {
        if (device->options[i].option_id == option_id) {
            option = &device->options[i];
            break;
        }
    }

    if (option == NULL)
        return PROTOCOL_STATUS_NO_SUCH_OPTION;

    *result = option;

    return PROTOCOL_STATUS_SUCCESS;
}

// Helper function to save passwords and mask them out
static void save_and_mask_passwords(protocol_Device* device, password_backup_t** backups, size_t* backup_count) {
    for (pb_size_t j = 0; j < device->options_count; ++j) {
        protocol_Option* option = &device->options[j];
        if (option->which_value == protocol_Option_password_type_tag) {
            (*backup_count)++;
            *backups = (password_backup_t *)pmem_realloc(*backups, *backup_count * sizeof(password_backup_t));
            (*backups)[*backup_count - 1].option = option;
            (*backups)[*backup_count - 1].original_password = option->value.password_type.current_value;
            option->value.password_type.current_value = "(hidden)";  // Mask out the password
        }
    }
}

// return true to keep the connection open, false to close
static bool protocol_process_capabilities_request(
    protocol_t* protocol,
    protocol_Request* request,
    pb_ostream_t* ostream)
{
    if (protocol == NULL || request == NULL || ostream == NULL)
        return false;

    protocol_Response response;
    response.which_response_type = protocol_Response_capabilities_tag;
    response.response_type.capabilities.tag = request->request_type.capabilities.tag;

    protocol_Board* board = &protocol->board;

    int request_filter = request->request_type.capabilities.device;

    password_backup_t* backups = NULL;
    size_t backup_count = 0;

    // request_filter is 0 or positive send only device config.
    if (request_filter >= 0) {
        if (request_filter >= board->devices_count)
            return protocol_send_error_code(PROTOCOL_STATUS_NO_SUCH_DEVICE, ostream);

        // Copy board
        protocol_Board response_board = *board;

        // Return only request_filter device
        response_board.devices_count = 1;
        response_board.devices = &board->devices[request_filter];
        response.response_type.capabilities.board = &response_board;

        save_and_mask_passwords(&board->devices[request_filter], &backups, &backup_count);
    }

    // request_filter is negative send all device configs.
    else {
        for (pb_size_t i = 0; i < board->devices_count; i++) {
            save_and_mask_passwords(&board->devices[i], &backups, &backup_count);
        }

        response.response_type.capabilities.board = board;  // Use state object 
    }

    bool result = pb_encode_ex(ostream, protocol_Response_fields, &response, PB_ENCODE_DELIMITED);

    // Restore the original passwords
    for (size_t i = 0; i < backup_count; i++) {
        backups[i].option->value.password_type.current_value = backups[i].original_password;
    }

    pmem_free(backups);

    return result;
}

// return true to keep the connection open, false to close
static bool protocol_process_config_request(
    protocol_t* protocol,
    protocol_Request* request,
    pb_ostream_t* ostream)
{
    if (protocol == NULL || request == NULL || ostream == NULL)
        return false;

    protocol_DeviceConfigurationRequest* config_request = &request->request_type.config;
    int device_id = config_request->device;

    // Check device_id is valid
    if (device_id < 0 || device_id >= protocol->board.devices_count)
        return protocol_send_error_code(PROTOCOL_STATUS_NO_SUCH_DEVICE, ostream);

    // Update model object with new config values
    int status = 0;
    for (int i = 0; i < config_request->options_count; i++) {
        protocol_OptionValue* option = &config_request->options[i];
        int option_id = option->option_id;

        switch (option->which_value) {
        case protocol_OptionValue_int_value_tag:
            status = protocol_set_option_int(protocol, device_id, option_id, option->value.int_value);
            break;
        case protocol_OptionValue_float_value_tag:
            status = protocol_set_option_float(protocol, device_id, option_id, option->value.float_value);
            break;
        case protocol_OptionValue_bool_value_tag:
            status = protocol_set_option_bool(protocol, device_id, option_id, option->value.bool_value);
            break;
        case protocol_OptionValue_oneof_value_tag:
            status = protocol_set_option_oneof(protocol, device_id, option_id, option->value.oneof_value);
            break;
         case protocol_OptionValue_blob_value_tag:
            status = protocol_set_option_blob(protocol, device_id, option_id, option->value.blob_value);
            break;
         case protocol_OptionValue_string_value_tag:
             status = protocol_set_option_string(protocol, device_id, option_id, option->value.string_value);
             break;
         case protocol_OptionValue_password_value_tag:
             status = protocol_set_option_password(protocol, device_id, option_id, option->value.password_value);
             break;
        }

        // Abort on error, but keep the connection open, unless failed to send the error
        if (status != PROTOCOL_STATUS_SUCCESS)
            return protocol_send_error_code(status, ostream);
    }

    // Update the streams
    device_manager_t* manager = &protocol->device_managers[device_id];
    protocol_configure_streams_fn configure_streams = manager->configure_streams;
    if (configure_streams != NULL) {
        configure_streams(protocol, device_id, manager->arg);
    }

    // Create an updated DeviceConfigurationResponse
    protocol_Response response;
    response.which_response_type = protocol_Response_config_tag;
    response.response_type.config.tag = request->request_type.config.tag;
    protocol_DeviceConfigurationResponse* response_msg = &response.response_type.config;
    protocol_Device* device = &protocol->board.devices[device_id];
    response_msg->device = device_id;
    response_msg->options_count = device->options_count;
    response_msg->options = (protocol_OptionValue *)malloc(sizeof(protocol_OptionValue) * device->options_count);
    response_msg->status_message = device->status_message;
    for (int i = 0; i < device->options_count; i++) {
        protocol_Option* source = &device->options[i];
        protocol_OptionValue* target = &response_msg->options[i];
        target->option_id = source->option_id;

        switch (source->which_value) {
        case protocol_Option_int_type_tag:
            target->which_value = protocol_OptionValue_int_value_tag;
            target->value.int_value = source->value.int_type.current_value;
            break;
        case protocol_Option_float_type_tag:
            target->which_value = protocol_OptionValue_float_value_tag;
            target->value.float_value = source->value.float_type.current_value;
            break;
        case protocol_Option_bool_type_tag:
            target->which_value = protocol_OptionValue_bool_value_tag;
            target->value.bool_value = source->value.bool_type.current_value;
            break;
        case protocol_Option_oneof_type_tag:
            target->which_value = protocol_OptionValue_oneof_value_tag;
            target->value.oneof_value = source->value.oneof_type.current_index;
            break;
        case protocol_Option_blob_type_tag:
            target->which_value = protocol_OptionValue_blob_value_tag;
            target->value.blob_value = source->value.blob_type.current_value;
            break;
        case protocol_Option_string_type_tag:
            target->which_value = protocol_OptionValue_string_value_tag;
            target->value.string_value = source->value.string_type.current_value;
            break;
        case protocol_Option_password_type_tag:
            target->which_value = protocol_OptionValue_password_value_tag;
            target->value.password_value = "(hidden)";
            break;
        }
    }
    response_msg->streams_count = device->streams_count;
    response_msg->streams = device->streams;
    response_msg->status = device->status;

    // Send the DeviceConfigurationResponse 
    if (!pb_encode_ex(ostream, protocol_Response_fields, &response, PB_ENCODE_DELIMITED))
        return false;

    return true;
}
 
// Return true to keep the connection open, false to close
static bool protocol_process_start_request(
    protocol_t* protocol,
    protocol_Request* request,
    pb_ostream_t* ostream)
{
    if (protocol == NULL || request == NULL || ostream == NULL)
        return false;

    protocol_StartRequest* start_request = &request->request_type.start;
    int device_id = start_request->device;

    // Check device_id is valid
    protocol_Board* board = &protocol->board;
    if (device_id < 0 || device_id >= board->devices_count)
        return protocol_send_error_code(PROTOCOL_STATUS_NO_SUCH_DEVICE, ostream);

    device_manager_t* manager = &protocol->device_managers[device_id];
    if (manager->busy != NULL && manager->busy != ostream)
        return protocol_send_error_code(PROTOCOL_STATUS_DEVICE_BUSY, ostream);

    protocol_device_start_fn start_fn = manager->start;
    protocol_DeviceStatus status = board->devices[device_id].status;
    if (status == protocol_DeviceStatus_DEVICE_STATUS_READY || status == protocol_DeviceStatus_DEVICE_STATUS_ERROR) {
        manager->busy = ostream;
        if (start_fn != NULL)
            start_fn(protocol, device_id, ostream, manager->arg);   
    }
    else if (status == protocol_DeviceStatus_DEVICE_STATUS_ACTIVE || status == protocol_DeviceStatus_DEVICE_STATUS_ACTIVE_WAIT) {
        return protocol_send_error_code(PROTOCOL_STATUS_DEVICE_ALREADY_ACTIVE, ostream);
    }

    return true;
}

// Return true to keep the connection open, false to close
static bool protocol_process_stop_request(
    protocol_t* protocol,
    protocol_Request* request,
    pb_ostream_t* ostream)
{
    if (protocol == NULL || request == NULL || ostream == NULL)
        return false;

    protocol_StopRequest* stop_request = &request->request_type.stop;
    int device_id = stop_request->device;

    // Check device_id is valid
    protocol_Board* board = &protocol->board;
    if (device_id >= board->devices_count)
        return protocol_send_error_code(PROTOCOL_STATUS_NO_SUCH_DEVICE, ostream);

    if (device_id >= 0) {
        device_manager_t* manager = &protocol->device_managers[device_id];
        
        // Comment out this if it should be possible stop streams from other connections
        if (manager->busy != NULL && manager->busy != ostream)
            return protocol_send_error_code(PROTOCOL_STATUS_DEVICE_BUSY, ostream);
    
        protocol_device_stop_fn stop_fn = protocol->device_managers[device_id].stop;
        protocol_DeviceStatus status = board->devices[device_id].status;
        if (stop_fn != NULL 
            && (status == protocol_DeviceStatus_DEVICE_STATUS_ACTIVE || status == protocol_DeviceStatus_DEVICE_STATUS_ACTIVE_WAIT)) {
            stop_fn(protocol, device_id, ostream, manager->arg);
        }
        manager->busy = NULL;
    }
    else {
        for (int i = 0; i < protocol->board.devices_count; i++) {
            device_manager_t* manager = &protocol->device_managers[i];
            protocol_device_stop_fn stop_fn = manager->stop;
            protocol_DeviceStatus status = board->devices[i].status;
            if (stop_fn != NULL 
                && (status == protocol_DeviceStatus_DEVICE_STATUS_ACTIVE || status == protocol_DeviceStatus_DEVICE_STATUS_ACTIVE_WAIT)) {
                stop_fn(protocol, i, ostream, manager->arg);
            }
            manager->busy = NULL;
        }
    }

    return true;
}

static bool protocol_discard_data(pb_istream_t* stream) 
{
    uint8_t discard[64];
    for (int i = stream->bytes_left; i > 0; i -= sizeof(discard)) {
        int read_count = i;
        if (read_count > (int)sizeof(discard))
            read_count = sizeof(discard);
        if (!pb_read(stream, discard, read_count))
            return false;
    }

    return true;
}

static bool protocol_process_data_chunk(pb_istream_t* istream, const pb_field_t* field, void** arg) {
    void** args = (void**)*arg;
    protocol_t* protocol = (protocol_t*)args[0];
    pb_ostream_t* ostream = (pb_ostream_t*)args[1];

    protocol_DataChunk* request = (protocol_DataChunk*)field->message;

    int device_id = request->device;
    int stream_id = request->stream;
    int byte_count = istream->bytes_left;

    protocol_Board* board = &protocol->board;

    // Check device_id
    if (device_id < 0 || device_id >= board->devices_count) {
        protocol_send_error_code(PROTOCOL_STATUS_NO_SUCH_DEVICE, ostream);
        protocol_discard_data(istream);
        return true;
    }

    protocol_Device* device = &board->devices[device_id];

    // Check stream_id
    if (stream_id < 0 || stream_id >= device->streams_count) {
        protocol_send_error_code(PROTOCOL_STATUS_NO_SUCH_STREAM, ostream);
        protocol_discard_data(istream);
        return true;
    }

    protocol_StreamConfig* stream = &device->streams[stream_id];

    // Check stream direction
    if (stream->direction != protocol_StreamDirection_STREAM_DIRECTION_INPUT) {
        protocol_send_error_code(PROTOCOL_STATUS_WRONG_STREAM_DIRECTION, ostream);
        protocol_discard_data(istream);
        return true;
    }

    if (stream->max_frame_count != -1 && request->frame_count > stream->max_frame_count) {
        protocol_send_error_code(PROTOCOL_STATUS_FRAME_COUNT_EXCEEDED, ostream);
        istream->bytes_left = 0;
        return true;
    }

    // TODO: save shape_flat so that we do compute it each time
    int shape_flat = 1;
    for (int i = 0; i < stream->shape_count; i++) {
        shape_flat *= stream->shape[i].size;
    }
    if(byte_count != request->frame_count * shape_flat * protocol_get_datatype_size(stream->datatype))
    {
        /*printf("INVALID FRAME SIZE, shape_flat=%d, frame_count=%d, element_size=%d, total_expected=%d, total_received=%d\n",
            shape_flat,
            request->frame_count,
            protocol_get_datatype_size(stream->datatype),
            request->frame_count * shape_flat * protocol_get_datatype_size(stream->datatype),
            byte_count);*/
        protocol_send_error_code(PROTOCOL_STATUS_INVALID_FRAME_SIZE, ostream);
        protocol_discard_data(istream);
        return true;
    }

    device_manager_t* device_manager = &protocol->device_managers[device_id];
    protocol_data_received callback = device_manager->data_received;

    if (callback != NULL) {
        return callback(protocol, request, istream, device_manager->arg);
    }

    // Ignore all the data
    protocol_discard_data(istream);

    return true;
}

static bool protocol_decode_payload(pb_istream_t* stream, const pb_field_t* field, void** arg)
{
    UNUSED(stream);

    if (field->tag == protocol_Request_data_tag)
    {
        protocol_DataChunk* data = field->pData;
        data->payload.funcs.decode = protocol_process_data_chunk;
        data->payload.arg = *arg;
    }

    return true;
}

static bool protocol_encode_payload(pb_ostream_t* stream, const pb_field_t* field, void* const* arg) 
{
    void** args = (void**)*arg;

    protocol_t* protocol = (protocol_t*)args[0];
    int total_size = *(int *)args[1];
    protocol_write_payload_fn callback = (protocol_write_payload_fn)args[2];
    void* user_arg = args[3];

    protocol_DataChunk* msg = (protocol_DataChunk*)field->message;

    if (!pb_encode_tag_for_field(stream, field))
        return false;

    if (!pb_encode_varint(stream, total_size))
        return false;

    if (stream->callback == NULL)
        return pb_write(stream, NULL, total_size);

    return callback(protocol, msg->device, msg->stream, msg->frame_count, total_size, stream, user_arg);
}

/*****************************************************************************
 *                            Declarations Public                            *
 ****************************************************************************/

protocol_t* protocol_create(
    const char* board_name, 
    const uint8_t* serial,
    protocol_Version firmware_version)
{
    protocol_t* protocol = (protocol_t*)pmem_malloc(sizeof(protocol_t));
    if (protocol == NULL)
        return NULL;
    protocol->device_managers = NULL;
    protocol->board_reset = NULL;
    
    protocol_Board* board = &protocol->board;
    if (board == NULL)
        return NULL;
    memcpy(&board->serial.uuid[0], serial, 16);
    board->name = (char*)board_name;
    board->firmware_version = firmware_version;
    board->protocol_version = PROTOCOL_VERSION;
    board->watchdog_timeout = 0;
    board->devices_count = 0;
    board->devices = NULL;

    return protocol;
}

void protocol_configure_watchdog(
    protocol_t* protocol,
    int watchdog_timeout_milliseconds,
    protocol_watchdog_reset_fn watchdog_reset)
{
    protocol->board.watchdog_timeout = watchdog_timeout_milliseconds;
    protocol->watchdog_reset = watchdog_reset;
}

void protocol_delete(protocol_t* protocol) 
{
    int status = 0;
    if (protocol == NULL)
        return;

    protocol_Board* board = &protocol->board;
    if (board != NULL) {
        for (int i = 0; i < board->devices_count; i++) {
            protocol_Device* device = &board->devices[i];
            status = protocol_clear_streams(protocol, i);
            if(PROTOCOL_STATUS_SUCCESS != status)
            {
                return;
            }
            for (int j = 0; j < device->options_count; j++) {
                protocol_Option* option = &device->options[j];
                if (option->which_value == protocol_Option_oneof_type_tag) {
                    pmem_free(option->value.oneof_type.items);
                } else if (option->which_value == protocol_Option_blob_type_tag) {
                    if(option->value.blob_type.current_value != NULL)
                        pmem_free(option->value.blob_type.current_value);
                    if (option->value.blob_type.default_value != NULL)
                        pmem_free(option->value.blob_type.default_value);
                } else if (option->which_value == protocol_Option_string_type_tag) {
                    if (option->value.string_type.current_value != NULL)
                        pmem_free(option->value.string_type.current_value);
                    if (option->value.string_type.default_value != NULL)
                        pmem_free(option->value.string_type.default_value);
                } else if (option->which_value == protocol_Option_password_type_tag) {
                    if (option->value.password_type.current_value != NULL)
                        pmem_free(option->value.password_type.current_value);
                }
            }
            pmem_free(device->options);
        }
        pmem_free(board->devices);
    }

    pmem_free(protocol->device_managers);
    pmem_free(protocol);
}

int protocol_add_device(
    protocol_t* protocol,
    protocol_DeviceType type, 
    const char* name,
    const char* description, 
    device_manager_t device_manager)
{
    if (protocol == NULL || name == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;
    int deviceIndex = board->devices_count++;

    board->devices = (protocol_Device*)pmem_realloc(board->devices, sizeof(protocol_Device) * board->devices_count);
    if (board->devices == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;
    protocol_Device* device = &board->devices[deviceIndex];
    device->device_id = deviceIndex;
    device->name = (char *)name;
    device->description = (char*)description;
    device->type = type;
    device->options_count = 0;
    device->options = NULL;
    device->streams_count = 0;
    device->streams = NULL;
    device->status = protocol_DeviceStatus_DEVICE_STATUS_READY;
    device->status_message = NULL;
    
    protocol->device_managers = (device_manager_t*)pmem_realloc(protocol->device_managers, sizeof(device_manager_t) * board->devices_count);
    if (protocol->device_managers == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;

    device_manager.busy = NULL;
    protocol->device_managers[deviceIndex] = device_manager;

    return deviceIndex;
}

int protocol_add_option_int(
    protocol_t* protocol, 
    int device_id,
    int option_id, 
    const char* name, 
    const char* description,
    int default_value, 
    int min_value, 
    int max_value) 
{
    if(protocol == NULL || name == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    if (default_value > max_value || default_value < min_value)
        return PROTOCOL_STATUS_VALUE_OUT_OF_RANGE;

    protocol_Device* device = &board->devices[device_id];
    protocol_Option* option = protocol_create_option(device, option_id, name, description);
    if(option == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;

    option->which_value = protocol_Option_int_type_tag;
    option->value.int_type.default_value = default_value;
    option->value.int_type.current_value = default_value;
    option->value.int_type.min_value = min_value;
    option->value.int_type.max_value = max_value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_set_option_int(
    protocol_t* protocol, 
    int device_id,
    int option_id, 
    int value)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_int_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    if (value > option->value.int_type.max_value || value < option->value.int_type.min_value)
        return PROTOCOL_STATUS_VALUE_OUT_OF_RANGE;

    option->value.int_type.current_value = value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_get_option_int(
    protocol_t* protocol,
    int device_id,
    int option_id, 
    int* value) 
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_int_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    *value = option->value.int_type.current_value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_add_option_float(
    protocol_t* protocol,
    int device_id,
    int option_id,
    const char* name,
    const char* description,
    float default_value,
    float min_value,
    float max_value) 
{
    if (protocol == NULL || name == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    if (default_value > max_value || default_value < min_value)
        return PROTOCOL_STATUS_VALUE_OUT_OF_RANGE;

    protocol_Device* device = &board->devices[device_id];
    protocol_Option* option = protocol_create_option(device, option_id, name, description);
    if (option == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;

    option->which_value = protocol_Option_float_type_tag;
    option->value.float_type.default_value = default_value;
    option->value.float_type.current_value = default_value;
    option->value.float_type.min_value = min_value;
    option->value.float_type.max_value = max_value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_set_option_float(
    protocol_t* protocol, 
    int device_id, 
    int option_id, 
    float value)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_float_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    if (value > option->value.float_type.max_value || value < option->value.float_type.min_value)
        return PROTOCOL_STATUS_VALUE_OUT_OF_RANGE;

    option->value.float_type.current_value = value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_get_option_float(
    protocol_t* protocol, 
    int device_id, 
    int option_id, 
    float* value) 
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_float_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    *value = option->value.float_type.current_value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_add_option_bool(
    protocol_t* protocol,
    int device_id,
    int option_id,
    const char* name,
    const char* description,
    bool default_value)
{
    if (protocol == NULL || name == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];
    protocol_Option* option = protocol_create_option(device, option_id, name, description);
    if (option == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;

    option->which_value = protocol_Option_bool_type_tag;
    option->value.bool_type.default_value = default_value;
    option->value.bool_type.current_value = default_value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_set_option_bool(
    protocol_t* protocol, 
    int device_id, 
    int option_id,
    bool value)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_bool_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    option->value.bool_type.current_value = value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_get_option_bool(
    protocol_t* protocol, 
    int device_id, 
    int option_id, 
    bool* value) 
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_bool_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    *value = option->value.bool_type.current_value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_add_option_oneof(
    protocol_t* protocol, 
    int device_id,
    int option_id, 
    const char* name, 
    const char* description, 
    int default_index,
    const char** items, 
    int item_count) 
{
    if (protocol == NULL || name == NULL || items == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    if (default_index >= item_count || default_index < 0)
        return PROTOCOL_STATUS_VALUE_OUT_OF_RANGE;

    protocol_Device* device = &board->devices[device_id];
    protocol_Option* option = protocol_create_option(device, option_id, name, description);

    if (option == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;

    option->which_value = protocol_Option_oneof_type_tag;
    option->value.oneof_type.default_index = default_index;
    option->value.oneof_type.current_index = default_index;
    option->value.oneof_type.items_count = item_count;
    option->value.oneof_type.items = (char**)pmem_malloc(sizeof(char*) * item_count);

    if (option->value.oneof_type.items == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;

    for (int i = 0; i < item_count; i++) {
        option->value.oneof_type.items[i] = (char *)items[i];
    }

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_set_option_oneof(
    protocol_t* protocol,
    int device_id, 
    int option_id, 
    int index)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_oneof_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    if (index >= option->value.oneof_type.items_count || index < 0)
        return PROTOCOL_STATUS_VALUE_OUT_OF_RANGE;

    option->value.oneof_type.current_index = index;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_get_option_oneof(
    protocol_t* protocol, 
    int device_id, 
    int option_id,
    int* index) 
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_oneof_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    *index = option->value.oneof_type.current_index;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_add_option_blob(
    protocol_t* protocol,
    int device_id,
    int option_id,
    const char* name,
    const char* description,
    pb_bytes_array_t* default_value)
{
    if (protocol == NULL || name == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];
    protocol_Option* option = protocol_create_option(device, option_id, name, description);
    if (option == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;

    option->which_value = protocol_Option_blob_type_tag;

    if (default_value == NULL) {
        option->value.blob_type.default_value = NULL;
        option->value.blob_type.current_value = NULL;
    }
    else {
        /* coverity[leaked_storage] */
        pb_bytes_array_t* default_copy = (pb_bytes_array_t*)pmem_malloc(PB_BYTES_ARRAY_T_ALLOCSIZE(default_value->size));
        memcpy(default_copy, default_value, PB_BYTES_ARRAY_T_ALLOCSIZE(default_value->size));
        option->value.blob_type.default_value = default_copy;

        /* coverity[leaked_storage] */
        pb_bytes_array_t* current_copy = (pb_bytes_array_t*)pmem_malloc(PB_BYTES_ARRAY_T_ALLOCSIZE(default_value->size));
        memcpy(current_copy, default_value, PB_BYTES_ARRAY_T_ALLOCSIZE(default_value->size));
        option->value.blob_type.current_value = current_copy;
    }

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_set_option_blob(
    protocol_t* protocol,
    int device_id,
    int option_id,
    pb_bytes_array_t* value)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_blob_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    if (option->value.blob_type.current_value != NULL) {
        pmem_free(option->value.blob_type.current_value);
    }

    if (value == NULL) {
        option->value.blob_type.current_value = NULL;
    }
    else {
        pb_bytes_array_t* copy = (pb_bytes_array_t*)pmem_malloc(PB_BYTES_ARRAY_T_ALLOCSIZE(value->size));
        memcpy(copy, value, PB_BYTES_ARRAY_T_ALLOCSIZE(value->size));
        option->value.blob_type.current_value = copy;
    }

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_get_option_blob(
    protocol_t* protocol,
    int device_id,
    int option_id,
    pb_bytes_array_t** value)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_blob_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    *value = option->value.blob_type.current_value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_add_option_string(
    protocol_t* protocol,
    int device_id,
    int option_id,
    const char* name,
    const char* description,
    char* default_value)
{
    if (protocol == NULL || name == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];
    protocol_Option* option = protocol_create_option(device, option_id, name, description);
    if (option == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;

    option->which_value = protocol_Option_string_type_tag;

    if (default_value == NULL) {
        option->value.string_type.default_value = NULL;
        option->value.string_type.current_value = NULL;
    }
    else {
        int len = strlen(default_value) + 1;
        /* coverity[leaked_storage] */
        char* default_copy = (char*)pmem_malloc(len);
        memcpy(default_copy, default_value, len);
        option->value.string_type.default_value = default_copy;

        /* coverity[leaked_storage] */
        char* current_copy = (char*)pmem_malloc(len);
        memcpy(current_copy, default_value, len);
        option->value.string_type.current_value = current_copy;
    }

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_set_option_string(
    protocol_t* protocol,
    int device_id,
    int option_id,
    char* value)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_string_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    if (option->value.string_type.current_value != NULL) {
        pmem_free(option->value.string_type.current_value);
    }

    if (value == NULL) {
        option->value.string_type.current_value = NULL;
    }
    else {
        int len = strlen(value) + 1;
        char* copy = (char*)pmem_malloc(len);
        memcpy(copy, value, len);
        option->value.string_type.current_value = copy;
    }

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_get_option_string(
    protocol_t* protocol,
    int device_id,
    int option_id,
    char** value)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_string_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    *value = option->value.string_type.current_value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_add_option_password(
    protocol_t* protocol,
    int device_id,
    int option_id,
    const char* name,
    const char* description)
{
    if (protocol == NULL || name == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];
    protocol_Option* option = protocol_create_option(device, option_id, name, description);
    if (option == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;

    option->which_value = protocol_Option_password_type_tag;
    option->value.password_type.current_value = NULL;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_set_option_password(
    protocol_t* protocol,
    int device_id,
    int option_id,
    char* value)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_password_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    if (option->value.password_type.current_value != NULL) {
        pmem_free(option->value.password_type.current_value);
    }

    if (value == NULL) {
        option->value.password_type.current_value = NULL;
    }
    else {
        int len = strlen(value) + 1;
        char* copy = (char*)pmem_malloc(len);
        memcpy(copy, value, len);
        option->value.password_type.current_value = copy;
    }

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_get_option_password(
    protocol_t* protocol,
    int device_id,
    int option_id,
    char** value)
{
    protocol_Option* option;
    int status = protocol_find_option(protocol, device_id, option_id, &option);
    if (status != PROTOCOL_STATUS_SUCCESS)
        return status;

    if (option->which_value != protocol_Option_password_type_tag)
        return PROTOCOL_STATUS_INVALID_OPTION_TYPE;

    *value = option->value.password_type.current_value;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_clear_streams(protocol_t* protocol, int device_id) 
{
    if (protocol == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];

    for (int i = 0; i < device->streams_count; i++) {
        protocol_StreamConfig* stream = &device->streams[i];
        for (int j = 0; j < stream->shape_count; j++) {
            protocol_Dimension* dimension = &stream->shape[j];
            char** labels = dimension->labels;
            if (labels != NULL)
                pmem_free(labels);
        }
    }

    pmem_free(device->streams);
    device->streams = NULL;
    device->streams_count = 0;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_add_stream(
    protocol_t* protocol,
    int device_id,
    const char* name,
    protocol_StreamDirection direction,
    protocol_DataType datatype,
    float frequency,
    int32_t max_frame_count,
    const char* unit)
{
    if (protocol == NULL || name == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];

    int stream_id = device->streams_count++;
    device->streams = (protocol_StreamConfig*)pmem_realloc(device->streams, sizeof(protocol_StreamConfig) * device->streams_count);
    if (device->streams == NULL)
        return PROTOCOL_STATUS_MEMORY_ERROR;
    protocol_StreamConfig* stream = &device->streams[stream_id];

    stream->name = (char*)name;
    stream->direction = direction;
    stream->datatype = datatype;
    stream->shape_count = 0;
    stream->frequency = frequency;
    stream->max_frame_count = max_frame_count;
    stream->unit = (char *)unit;
    stream->current_frame = 0;
    stream->frames_dropped = 0;
    stream->scale = 1;
    stream->offset = 0;
    stream->shift = 0;

    return stream_id;
}

int protocol_set_stream_quantization_options(
    protocol_t* protocol,
    int device_id,
    int stream_id,
    int32_t shift,
    float scale,
    int64_t offset)
{
    if (protocol == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];

    // Check stream_id
    if (stream_id < 0 || stream_id >= device->streams_count)
        return PROTOCOL_STATUS_NO_SUCH_STREAM;

    protocol_StreamConfig* stream = &device->streams[stream_id];

    stream->shift = shift;
    stream->offset = offset;
    stream->scale = scale;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_add_stream_rank(
    protocol_t* protocol, 
    int device_id, 
    int stream_id, 
    const char* name, 
    int size, 
    const char** labels)
{
    if (protocol == NULL || name == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];

    if (stream_id < 0 || stream_id >= device->streams_count)
        return PROTOCOL_STATUS_NO_SUCH_STREAM;

    protocol_StreamConfig* stream = &device->streams[stream_id];

    int dim_count = stream->shape_count++;
    protocol_Dimension* dim = &stream->shape[dim_count];

    dim->name = (char*)name;
    dim->size = size;

    if (labels != NULL) {
        dim->labels_count = size;
        dim->labels = (char**)pmem_malloc(sizeof(char*) * size);
        if (dim->labels == NULL)
            return PROTOCOL_STATUS_MEMORY_ERROR;
        for (int i = 0; i < size; i++) {
            dim->labels[i] = (char *)labels[i];
        }
    } else {
        dim->labels = NULL;
        dim->labels_count = 0;
    }

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_set_device_status(
    protocol_t* protocol,
    int device_id,
    protocol_DeviceStatus status,
    const char* message)
{
    if (protocol == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];
    
    if ((device->status == protocol_DeviceStatus_DEVICE_STATUS_READY || device->status == protocol_DeviceStatus_DEVICE_STATUS_ERROR) &&
        (status == protocol_DeviceStatus_DEVICE_STATUS_ACTIVE || status == protocol_DeviceStatus_DEVICE_STATUS_ACTIVE_WAIT)) {
        for (int i = 0; i < device->streams_count; i++) {
            device->streams[i].current_frame = 0;
            device->streams[i].frames_dropped = 0;
        }
    }

    if (status == protocol_DeviceStatus_DEVICE_STATUS_READY || status == protocol_DeviceStatus_DEVICE_STATUS_ERROR)
        protocol->device_managers[device_id].busy = NULL;

    device->status = status;
    device->status_message = (char*)message;

    return PROTOCOL_STATUS_SUCCESS;
}

int protocol_process_request(
    protocol_t* protocol,
    pb_istream_t* istream, 
    pb_ostream_t* ostream) 
{
    if (protocol == NULL || istream == NULL || ostream == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Request request = protocol_Request_init_zero;

    static void* args[2];
    args[0] = protocol;
    args[1] = ostream;
    request.cb_request_type.funcs.decode = protocol_decode_payload;
    request.cb_request_type.arg = args;

    if (!pb_decode_ex(istream, protocol_Request_fields, &request, PB_DECODE_DELIMITED))
        return PROTOCOL_STATUS_FAILED_TO_DECODE_REQUEST;

    switch (request.which_request_type) 
    {
    case protocol_Request_capabilities_tag:
        protocol_process_capabilities_request(protocol, &request, ostream);
        break;

    case protocol_Request_config_tag:
        protocol_process_config_request(protocol, &request, ostream);
        break;

    case protocol_Request_start_tag:
        protocol_process_start_request(protocol, &request, ostream);
        break;

    case protocol_Request_stop_tag:
        protocol_process_stop_request(protocol, &request, ostream);
        break;

    case protocol_Request_watchdog_reset_tag:
        if(protocol->watchdog_reset != NULL)
            protocol->watchdog_reset(protocol);
        break;

    case protocol_Request_data_tag:
        break;

    case protocol_Request_reset_tag:
        if (protocol->board_reset != NULL)
            protocol->board_reset(protocol);
        break;

    default:
        return PROTOCOL_STATUS_INVALID_REQUEST_TYPE;
    }

    pb_release(protocol_Request_fields, &request);

    return PROTOCOL_STATUS_SUCCESS;
}

void protocol_call_device_poll(
    protocol_t* protocol,
    pb_ostream_t* ostream)
{
    for (int i = 0; i < protocol->board.devices_count; i++) {
        device_manager_t* manager = &protocol->device_managers[i];
        
        if (manager->busy != ostream)
            continue;

        protocol_device_poll_fn poll = manager->poll;
        if (poll != NULL && protocol->board.devices[i].status == protocol_DeviceStatus_DEVICE_STATUS_ACTIVE)
            poll(protocol, i, ostream, manager->arg);
    }
}

int protocol_send_data_inquire(
    protocol_t* protocol,
    int device_id,
    int stream_id,
    int frame_count,
    pb_ostream_t* ostream)
{
    if (protocol == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];

    if (device->status != protocol_DeviceStatus_DEVICE_STATUS_ACTIVE
        && device->status != protocol_DeviceStatus_DEVICE_STATUS_ACTIVE_WAIT) {
        return PROTOCOL_STATUS_DEVICE_NOT_ACTIVE;
    }

    if (stream_id < 0 || stream_id >= device->streams_count)
        return PROTOCOL_STATUS_NO_SUCH_STREAM;

    protocol_StreamConfig* stream = &device->streams[stream_id];
    if (stream->direction != protocol_StreamDirection_STREAM_DIRECTION_INPUT)
        return PROTOCOL_STATUS_WRONG_STREAM_DIRECTION;

    static protocol_Response response;
    response.which_response_type = protocol_Response_data_inquire_tag;
    protocol_DataInquire* inquire = &response.response_type.data_inquire;

    inquire->device = device_id;
    inquire->frame_count = frame_count;
    inquire->stream = stream_id;

    if (!pb_encode_ex(ostream, protocol_Response_fields, &response, PB_ENCODE_DELIMITED))
        return PROTOCOL_STATUS_FAILED_TO_ENCODE_RESPONSE;

    return PROTOCOL_STATUS_SUCCESS;
}


int protocol_send_data_chunk(
    protocol_t* protocol,
    int device_id,
    int stream_id,
    int frame_count,
    int frames_skipped,
    pb_ostream_t* ostream,
    protocol_write_payload_fn callback) 
{
    if (protocol == NULL)
        return PROTOCOL_STATUS_NULL_ARGUMENT;

    protocol_Board* board = &protocol->board;

    if (device_id < 0 || device_id >= board->devices_count)
        return PROTOCOL_STATUS_NO_SUCH_DEVICE;

    protocol_Device* device = &board->devices[device_id];

    if (device->status != protocol_DeviceStatus_DEVICE_STATUS_ACTIVE
        && device->status != protocol_DeviceStatus_DEVICE_STATUS_ACTIVE_WAIT) {
        return PROTOCOL_STATUS_DEVICE_NOT_ACTIVE;
    }

    if (stream_id < 0 || stream_id >= device->streams_count)
        return PROTOCOL_STATUS_NO_SUCH_STREAM;

    protocol_StreamConfig* stream = &device->streams[stream_id];

    // TODO: save shape_flat so that we do compute it each time
    int shape_flat = 1;
    for (int i = 0; i < stream->shape_count; i++) {
        shape_flat *= stream->shape[i].size;
    }

    static protocol_Response response;
    response.which_response_type = protocol_Response_data_tag;
    protocol_DataChunk* data = &response.response_type.data;
    
    // Fill the message with some data
    data->device = device_id;
    data->stream = stream_id;
    data->frame_count = frame_count;
    data->frame_number = stream->current_frame + frames_skipped;
    data->timestamps_count = 0;
    data->timestamps = NULL;
    stream->current_frame += frame_count + frames_skipped;
    stream->frames_dropped += frames_skipped;

    // Set the callback and argument for the payload
    static void* args[4];
    static int total_size;
    total_size = frame_count * shape_flat * protocol_get_datatype_size(stream->datatype);
    args[0] = protocol;
    args[1] = &total_size;
    args[2] = (void*)callback;
    args[3] = protocol->device_managers[device_id].arg;
    data->payload.funcs.encode = protocol_encode_payload;
    data->payload.arg = args;

    if (!pb_encode_ex(ostream, protocol_Response_fields, &response, PB_ENCODE_DELIMITED))
        return PROTOCOL_STATUS_FAILED_TO_ENCODE_RESPONSE;

    return PROTOCOL_STATUS_SUCCESS;
}

bool protocol_send_error_message(int code, const char* error, pb_ostream_t* ostream) 
{
    protocol_Response response;
    response.which_response_type = protocol_Response_error_tag;
    response.response_type.error.error_code = code;
    response.response_type.error.error_message = (char*)error;

    if (!pb_encode_ex(ostream, protocol_Response_fields, &response, PB_ENCODE_DELIMITED))
        return false;

    return true;
}

bool protocol_send_error_code(int code, pb_ostream_t* ostream) 
{
    protocol_Response response;
    response.which_response_type = protocol_Response_error_tag;
    response.response_type.error.error_code = code;
    response.response_type.error.error_message = (char *) protocol_get_error_msg(code);

    if (!pb_encode_ex(ostream, protocol_Response_fields, &response, PB_ENCODE_DELIMITED))
        return false;

    return true;
}

const char* protocol_get_error_msg(int error) 
{
    if (error >= PROTOCOL_STATUS_SUCCESS)
        return "Success";
    switch (error)
    {
    case PROTOCOL_STATUS_UNSPECIFIED_ERROR: return "Unspecified error.";
    case PROTOCOL_STATUS_NULL_ARGUMENT: return "Invalid argument.";
    case PROTOCOL_STATUS_INVALID_OPTION_TYPE: return "Option type do not match.";
    case PROTOCOL_STATUS_MAX_RANK_REACHED: return "Max tensor rank exceeded.";
    case PROTOCOL_STATUS_OSTREAM_ERROR: return "Output stream error.";
    case PROTOCOL_STATUS_ISTREAM_ERROR: return "Input stream error.";
    case PROTOCOL_STATUS_INVALID_REQUEST_TYPE: return "Unexpected request type.";
    case PROTOCOL_STATUS_FAILED_TO_DECODE_REQUEST: return "Request decode error.";
    case PROTOCOL_STATUS_FAILED_TO_ENCODE_RESPONSE: return "Response encode error.";
    case PROTOCOL_STATUS_NO_SUCH_DEVICE: return "No such device exist.";
    case PROTOCOL_STATUS_NO_SUCH_OPTION: return "No such option exist.";
    case PROTOCOL_STATUS_NO_SUCH_STREAM: return "No such stream exist";
    case PROTOCOL_STATUS_VALUE_OUT_OF_RANGE: return "Option value out of range.";
    case PROTOCOL_STATUS_DEVICE_NOT_ACTIVE: return "Device not active.";
    case PROTOCOL_STATUS_WRONG_STREAM_DIRECTION: return "Wrong stream direction.";
    case PROTOCOL_STATUS_FRAME_COUNT_EXCEEDED: return "Frame count exceeded.";
    case PROTOCOL_STATUS_INVALID_FRAME_SIZE: return "Invalid frame size.";
    case PROTOCOL_STATUS_MEMORY_ERROR: return "Memory allocation error.";
    case PROTOCOL_STATUS_DEVICE_ALREADY_ACTIVE: return "Device already active.";
    case PROTOCOL_STATUS_DEVICE_BUSY: return "Device busy with another stream.";
    default:
        return "Unknown error.";
    }
}

int protocol_get_datatype_size(protocol_DataType type)
{
    switch (type) {
    case protocol_DataType_DATA_TYPE_UNKNOWN: return -1;
    case protocol_DataType_DATA_TYPE_U8: return 1;
    case protocol_DataType_DATA_TYPE_S8: return 1;
    case protocol_DataType_DATA_TYPE_U16: return 2;
    case protocol_DataType_DATA_TYPE_S16: return 2;
    case protocol_DataType_DATA_TYPE_U32: return 4;
    case protocol_DataType_DATA_TYPE_S32: return 4;
    case protocol_DataType_DATA_TYPE_F32: return 4;
    case protocol_DataType_DATA_TYPE_F64: return 8;
    case protocol_DataType_DATA_TYPE_Q7: return 1;
    case protocol_DataType_DATA_TYPE_Q15: return 2;
    case protocol_DataType_DATA_TYPE_Q31: return 4;
    case protocol_DataType_DATA_TYPE_D8: return 1;
    case protocol_DataType_DATA_TYPE_D16: return 2;
    case protocol_DataType_DATA_TYPE_D32: return 4;

    default: return -1;
    }
}
