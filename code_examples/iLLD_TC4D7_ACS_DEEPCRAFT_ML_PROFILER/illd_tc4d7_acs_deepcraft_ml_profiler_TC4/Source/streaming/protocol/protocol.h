/*
* The MIT License (MIT)
*
* Copyright � 2024- Imagimob AB
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

/*
 * This is an API built on top of the Protocol Buffers files: model.proto and 
 * protocol.proto. For more detailed information on the data structures and 
 * protocol definitions, please refer to those files.
 */

#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include <stdbool.h>
#include "protocol.pb.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                                  Defines                                   *
 *****************************************************************************/

#define PROTOCOL_VERSION \
(protocol_Version) {     \
    .major= 2,            \
    .minor= 3,            \
    .build= 20241218,     \
    .revision= 0          \
}

 // Handy when compiling with -Wextra (as you should :-)
#define UNUSED(x) (void)(x)

 // Return status codes
#define PROTOCOL_STATUS_SUCCESS                   (0)   // Operation completed successfully
#define PROTOCOL_STATUS_UNSPECIFIED_ERROR         (-1)  // An unspecified error occurred
#define PROTOCOL_STATUS_NULL_ARGUMENT             (-2)  // Null argument provided
#define PROTOCOL_STATUS_INVALID_OPTION_TYPE       (-3)  // Invalid option type
#define PROTOCOL_STATUS_INVALID_REQUEST_TYPE      (-4)  // Invalid request type
#define PROTOCOL_STATUS_INVALID_RESPONSE_TYPE     (-5)  // Invalid response type
#define PROTOCOL_STATUS_MAX_RANK_REACHED          (-6)  // Maximum rank reached
#define PROTOCOL_STATUS_OSTREAM_ERROR             (-7)  // Output stream error
#define PROTOCOL_STATUS_ISTREAM_ERROR             (-8)  // Input stream error
#define PROTOCOL_STATUS_FAILED_TO_DECODE_REQUEST  (-9)  // Failed to decode request
#define PROTOCOL_STATUS_FAILED_TO_ENCODE_RESPONSE (-10) // Failed to encode response
#define PROTOCOL_STATUS_NO_SUCH_OPTION            (-11) // No such option
#define PROTOCOL_STATUS_NO_SUCH_DEVICE            (-12) // No such device
#define PROTOCOL_STATUS_NO_SUCH_STREAM            (-13) // No such stream
#define PROTOCOL_STATUS_VALUE_OUT_OF_RANGE        (-14) // Value out of range
#define PROTOCOL_STATUS_DEVICE_NOT_ACTIVE         (-15) // Device not active
#define PROTOCOL_STATUS_WRONG_STREAM_DIRECTION    (-16) // Wrong stream direction
#define PROTOCOL_STATUS_FRAME_COUNT_EXCEEDED      (-17) // Frame count exceeded
#define PROTOCOL_STATUS_INVALID_FRAME_SIZE        (-18) // Invalid frame size
#define PROTOCOL_STATUS_MEMORY_ERROR              (-19) // Memory allocation failed
#define PROTOCOL_STATUS_DEVICE_ALREADY_ACTIVE     (-20) // Device already active
#define PROTOCOL_STATUS_DEVICE_BUSY               (-21) // Device busy with another stream


/******************************************************************************
 *                                   Types                                    *
 *****************************************************************************/

// Predefined. See documentation for protocol_s.
typedef struct protocol_s protocol_t;

// Function pointer typedefs for device manager callbacks (see device_manager_t)
typedef bool (*protocol_configure_streams_fn)(protocol_t* protocol, int device, void* arg);
typedef void (*protocol_device_start_fn)(protocol_t* protocol, int device, pb_ostream_t* ostream, void* arg);
typedef void (*protocol_device_stop_fn)(protocol_t* protocol, int device, pb_ostream_t* ostream, void* arg);
typedef void (*protocol_device_poll_fn)(protocol_t* protocol, int device, pb_ostream_t* ostream, void* arg);
typedef bool (*protocol_data_received)(protocol_t* protocol, protocol_DataChunk *msg, pb_istream_t* istream, void* arg);
    
typedef void (*protocol_watchdog_reset_fn)(protocol_t* protocol);
typedef void (*protocol_board_reset_fn)(protocol_t* protocol);

/*
* Callback for writing payload.
* Used by protocol_send_data_chunk().
*
* @param protocol: A pointer to the protocol_t object.
* @param device_id: The ID of the device.
* @param stream_id: The ID of the stream.
* @param total_bytes: Total bytes that must be written with one or more calls to pb_write().
* @param ostream: The protobuf underlying transport stream passed to pb_write().
* @param arg: User defined argument, defined in device_manager_t.arg.
*
* @return false on IO errors. This will cause encoding to abort.
*
* @example:
* bool write_payload(
*    protocol_t* protocol,
*    int device_id,
*    int32_t stream_id,
*    int32_t frame_count,
*    int32_t total_bytes,
*    pb_ostream_t* ostream,
*    void *arg)
* {
*    // total_bytes is defined as: frame_count * shape.flat * sizeof(element_type)
*    // The data can be written with a single or multiple calls to pb_write()
*    uint8_t data[total_bytes]; // your data to send
*    return pb_write(ostream, data, total_bytes);
* }
*/
typedef bool (*protocol_write_payload_fn)(
    protocol_t* protocol,
    int device_id,
    int stream_id,
    int frame_count,
    int total_bytes,
    pb_ostream_t* ostream,
    void* arg);

typedef struct {
    /*
    * User defined argument passed to all callback functions. 
    */
    void* arg;

    /*
    * If set the device is busy with this stream.    
    */
    pb_ostream_t* busy;

    /*
    * Callback that is invoked every time a DeviceConfigurationRequest is received.
    * It should update the protocol->board->devices[device]->stream[] objects.
    * It can be done using helper functions e.g. protocol_clear_streams(),
    * protocol_add_stream(), protocol_add_stream_rank().
    * 
    * The method should call protocol_set_device_status(status, msg) to update the 
    * status indicating if the device is ready or have an invalid mix of settings. 
    * 
    * May be NULL for devices that do not need to reconfigure their streams or
    * need to validate any options.
    */
    protocol_configure_streams_fn configure_streams;

    /*
    * Callback that is invoked when the device received a start request.
    * This function should initialize/start the device and call 
    * protocol_set_device_status(protocol_DeviceStatus_Active).
    * An device in Active state is sending and accepting DataChunk messages.
    */
    protocol_device_start_fn start;

    /*
    * Callback that is invoked when the device received a stop request.
    * This function should stop the device and call protocol_set_device_status(protocol_DeviceStatus_Ready).
    */
    protocol_device_stop_fn stop;

    /*
    * When protocol_call_device_poll() is called, each device that is in the 
    * Active state gets its poll callback invoked.
    * This function should call protocol_send_data_chunk() if it have any data to send. 
    */
    protocol_device_poll_fn poll;

    /*
    * If the device (Playback- or Model device) receives a DataChunk message this
    * callback is invoked. May be NULL.
    */
    protocol_data_received data_received;
} device_manager_t;

/*
* This is the main structure for the protocol implementation.
*/
typedef struct protocol_s {
    /* 
    * The current board state. 
    */
    protocol_Board board;

    /*
    * Collection of callback functions to manage device events.
    * Array of length board->devices_count
    */
    device_manager_t* device_managers;  
    
    /*
    * Called when a WatchdogResetRequest message is received.
    */
    protocol_watchdog_reset_fn watchdog_reset;

    /*
    * Called when a ResetRequest message is received.
    */
    protocol_board_reset_fn board_reset;
} protocol_t;

/******************************************************************************
 *                                Functions                                   *
 *****************************************************************************/

 /**
  * Create a new protocol_t object.
  *
  * @param board_name: The name of the board.
  * @param serial_uuid: 16 bytes serial number UUID. Used by host software to uniquely identify a device.
  * @param firmware_version: The version of the firmware.
  * 
  * @return A pointer to the newly created protocol_t object, or NULL on failure.
  */
protocol_t* protocol_create(
    const char* board_name, 
    const uint8_t* serial_uuid,
    protocol_Version firmware_version);

/**
 * Free any memory allocated.
 *
 * @param protocol The protocol_t object to free.
 */
void protocol_delete(protocol_t* protocol);

/**
 * Set the watchdog board option.
 *
 * @param protocol: The protocol_t object.
 * @param watchdog_timeout_milliseconds: The timeout in milliseconds.
 * @param watchdog_reset: The callback function for watchdog reset.
 */
void protocol_configure_watchdog(
    protocol_t* protocol,
    int watchdog_timeout_milliseconds,
    protocol_watchdog_reset_fn watchdog_reset);

/**
 * Register a new device.
 *
 * @param protocol: The protocol_t object.
 * @param type: The type of device.
 * @param name: The name of the device.
 * @param description: The description of the device.
 * @param device_manager: The device manager callback functions.
 * 
 * @return The new device_id (index) or a negative value on error.
 */
int protocol_add_device(
    protocol_t* protocol, 
    protocol_DeviceType type, 
    const char* name,
    const char* description,
    device_manager_t device_manager);

/**
 * Register a new integer option to a device.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param name: The name of the option.
 * @param description: The description of the option.
 * @param default_value: The default value of the option.
 * @param min_value: The minimum value of the option.
 * @param max_value: The maximum value of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_add_option_int(
    protocol_t* protocol,
    int device_id, 
    int option_id,
    const char* name,
    const char* description, 
    int default_value, 
    int min_value, 
    int max_value);

/**
 * Update an existing integer option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The new value of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_set_option_int(protocol_t* protocol, int device_id, int option_id, int value);

/**
 * Read an integer option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The current value of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_get_option_int(protocol_t* protocol, int device_id, int option_id, int* value);

/**
 * Register a new float option to a device.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param name: The name of the option.
 * @param description: The description of the option.
 * @param default_value: The default value of the option.
 * @param min_value: The minimum value of the option.
 * @param max_value: The maximum value of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_add_option_float(
    protocol_t* protocol, 
    int device_id, 
    int option_id, 
    const char* name, 
    const char* description, 
    float default_value, 
    float min_value, 
    float max_value);

/**
 * Update an existing float option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The new value of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_set_option_float(protocol_t* protocol, int device_id, int option_id, float value);

/**
 * Read a float option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The current value of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_get_option_float(protocol_t* protocol, int device_id, int option_id, float* value);

/**
 * Register a new boolean option to a device.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param name: The name of the option.
 * @param description: The description of the option.
 * @param default_value: The default value of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_add_option_bool(
    protocol_t* protocol,
    int device_id,
    int option_id, 
    const char* name, 
    const char* description, 
    bool default_value);

/**
 * Update an existing boolean option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The new value of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_set_option_bool(protocol_t* protocol, int device_id, int option_id, bool value);

/**
 * Read a boolean option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The current value of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_get_option_bool(protocol_t* protocol, int device_id, int option_id, bool* value);

/**
 * Register a new oneof option to a device.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param name: The name of the option.
 * @param description: The description of the option.
 * @param default_index: The default index of the option.
 * @param items: The items of the option.
 * @param item_count: The number of items.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_add_option_oneof(
    protocol_t* protocol, 
    int device_id, 
    int option_id,
    const char* name, 
    const char* description, 
    int default_index, 
    const char** items,
    int item_count);

/**
 * Update an existing oneof option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param index: The new index of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_set_option_oneof(protocol_t* protocol, int device_id, int option_id, int index);

/**
 * Read a oneof option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param index: The current index of the option.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_get_option_oneof(protocol_t* protocol, int device_id, int option_id, int* index);

/**
 * Register a new blob option to a device.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param name: The name of the option.
 * @param description: The description of the option.
 * @param default_value: The default value of the option.
 *
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_add_option_blob(
    protocol_t* protocol,
    int device_id,
    int option_id,
    const char* name,
    const char* description,
    pb_bytes_array_t* default_value);

/**
 * Update an existing blob option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The new value of the option.
 *
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_set_option_blob(protocol_t* protocol, int device_id, int option_id, pb_bytes_array_t* value);

/**
 * Read a blob option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The current value of the option.
 *
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_get_option_blob(protocol_t* protocol, int device_id, int option_id, pb_bytes_array_t** value);

/**
 * Register a new string option to a device.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param name: The name of the option.
 * @param description: The description of the option.
 * @param default_value: The default value of the option.
 *
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_add_option_string(
    protocol_t* protocol,
    int device_id,
    int option_id,
    const char* name,
    const char* description,
    char* default_value);

/**
 * Update an existing string option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The new value of the option.
 *
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_set_option_string(protocol_t* protocol, int device_id, int option_id, char* value);

/**
 * Read a string option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The current value of the option.
 *
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_get_option_string(protocol_t* protocol, int device_id, int option_id, char** value);

/**
 * Register a new hidden password string option to a device.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param name: The name of the option.
 * @param description: The description of the option.
 * @param default_value: The default value of the option.
 *
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_add_option_password(
    protocol_t* protocol,
    int device_id,
    int option_id,
    const char* name,
    const char* description);

/**
 * Update an existing hidden password string option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The new value of the option.
 *
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_set_option_password(protocol_t* protocol, int device_id, int option_id, char* value);

/**
 * Read a hidden password string option value.
 *
 * @param protocol: The protocol_t object.
 * @param device_id: The ID of the device.
 * @param option_id: The ID of the option.
 * @param value: The current value of the option.
 *
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_get_option_password(protocol_t* protocol, int device_id, int option_id, char** value);

/**
 * Clear any registered streams for a given device.
 *
 * @param protocol: The protocol_t object.
 * @param device: The ID of the device.
 * 
 * @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
 */
int protocol_clear_streams(protocol_t* protocol, int device);

/**
* Register a new stream.
* See message StreamConfig in model.proto.
* 
* @param protocol: A pointer to the protocol_t object.
* @param device_id: The ID of the device.
* @param name: The name of the stream.
* @param direction: The direction of the stream.
* @param datatype: The data type of the stream.
* @param frequency: The frequency of the stream.
* @param max_frame_count: The maximum number of frames in each DataChunk.
* @param unit: The unit name if available. e.g. m/s� (feel free to use unicode)
* 
* @return The new stream_id (index) or a negative value on error.
*/
int protocol_add_stream(
    protocol_t* protocol, 
    int device_id, 
    const char* name, 
    protocol_StreamDirection direction, 
    protocol_DataType datatype, 
    float frequency,              
    int32_t max_frame_count,            
    const char* unit);         

/**
* Set quantization options for stream.
* 
* For D types: 
*   real_value = (int_value - offset) * scale
* 
* For Q types:
*   real_value = int8_value / (128 >> shift)
*   real_value = int16_value / (32768 >> shift)
*   real_value = int32_value / (2147483648 >> shift)
* 
* @param protocol: A pointer to the protocol_t object.
* @param device_id: The ID of the device.
* @param stream_id: The stream ID (index) to configure.
* @param shift: The shift for quantized data streams. Default to 0. Only used for types DATA_TYPE_Qxx. 
* @param scale: The scale for quantized data streams. Default to 1. Only used for types DATA_TYPE_Dxx.
* @param offset: The offset for quantized data streams. Default to 0. Only used for types DATA_TYPE_Dxx.
* 
* @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
*/
int protocol_set_stream_quantization_options(
    protocol_t* protocol,
    int device_id,
    int stream_id,
    int32_t shift,
    float scale,
    int64_t offset);

/*
* Add a tensor dimension (rank). 
* See Dimension in file model.proto
* 
* @param protocol: A pointer to the protocol_t object.
* @param device_id: The ID of the device.
* @param stream_id: The ID of the stream.
* @param name: The name of the dimension.
* @param size: The size of the dimension.
* @param labels: An array of labels for the dimension.
* 
* @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
*
* @example:
* // Adding a stereo audio stream dimension. Shape [2]
* const char* audio_labels[] = {"Left", "Right"};
* protocol_add_stream_rank(protocol, device_id, stream_id, "Audio Channel", 2, audio_labels);
*
* @example:
* // Adding dimensions for a camera stream. Shape [640,480,3]
* const char* color_labels[] = {"Red", "Green", "Blue"};
* protocol_add_stream_rank(protocol, device_id, stream_id, "Width", 640, NULL);
* protocol_add_stream_rank(protocol, device_id, stream_id, "Height", 480, NULL);
* protocol_add_stream_rank(protocol, device_id, stream_id, "Color", 3, color_labels);
*/
int protocol_add_stream_rank(
    protocol_t* protocol, 
    int device_id,
    int stream_id, 
    const char* name, 
    int size, 
    const char** labels);


/*
* Set device status with an optional message.
* 
* Note, When the device status is changed from 
* DEVICE_STATUS_READY or DEVICE_STATUS_ERROR 
* to
* DEVICE_STATUS_ACTIVE or DEVICE_ACTIVE_WAIT 
* all the streams frame counters are cleared.
*
* @param protocol: A pointer to the protocol_t object.
* @param device_id: The ID of the device.
* @param status: The new status of the device.
* @param message: An optional message associated with the status.
* 
* @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
*/
int protocol_set_device_status(
    protocol_t* protocol,
    int device_id,
    protocol_DeviceStatus status,
    const char* message);

/*
* Sends a DataChunk message on the given device/stream.
* See protocol_write_payload_fn for more information.
* 
* @param protocol: A pointer to the protocol_t object.
* @param device: The ID of the device.
* @param stream: The ID of the stream.
* @param frame_count: The number of frames in the message.
* @param frames_skipped: The number of frames skipped between the last sent chunk and this. Default 0. 
*   The stream frame counter will be updated as: stream->current_frame += frame_count + frames_skipped
* @param ostream: The output stream to send the message.
* @param callback: The callback function to write the payload.
* 
* @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
*/
int protocol_send_data_chunk(
    protocol_t* protocol,
    int device,
    int stream,
    int frame_count,
    int frames_skipped,
    pb_ostream_t* ostream,
    protocol_write_payload_fn callback);

/*
* Sends a DataInquire message on the given device/stream.
*
* @param protocol: A pointer to the protocol_t object.
* @param device: The ID of the device.
* @param stream: The ID of the stream.
* @param frame_count: The number of frames to request.
* @param ostream: The output stream to send the message.
*
* @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
*/
int protocol_send_data_inquire(
    protocol_t* protocol,
    int device,
    int stream,
    int frame_count,
    pb_ostream_t* ostream);

/*
* Reads and processes a message from istream, any response is written to given ostream.
* 
* @param protocol: A pointer to the protocol_t object.
* @param istream: The input stream to read the message.
* @param ostream: The output stream to write any response.
* 
* @return PROTOCOL_STATUS_SUCCESS (0) on success, or a negative error code.
*/
int protocol_process_request(protocol_t* protocol, pb_istream_t* istream, pb_ostream_t* ostream);

/*
* Calls all device_manager_t.poll() for each device that is in Active state.
*
* @param protocol: A pointer to the protocol_t object.
* @param ostream: The output stream to write any data.
*/
void protocol_call_device_poll(protocol_t* protocol, pb_ostream_t* ostream);

/*
* Sends an ErrorResponse message.
*
* @param code: The error code.
* @param error: The error message.
* @param ostream: The output stream to write the error message.
*
* @return true on success, false otherwise.
*/
bool protocol_send_error_message(int code, const char* error, pb_ostream_t* ostream);

/*
* Sends an ErrorResponse message using a predefined error code message.
*
* @param code: The error code.
* @param ostream: The output stream to write the error message.
*
* @return true on success, false otherwise.
*/
bool protocol_send_error_code(int code, pb_ostream_t* ostream);


/*
* Gets a short (static) string describing the given error code.
*
* @param error: The error code.
*
* @return A short description of the error.
*/
const char* protocol_get_error_msg(int error);

/*
* Returns the number of bytes required to store a given data type.
*
* @param type: The data type.
*
* @return The number of bytes required for the data type.
*/
int protocol_get_datatype_size(protocol_DataType type);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _PROTOCOL_H_ */