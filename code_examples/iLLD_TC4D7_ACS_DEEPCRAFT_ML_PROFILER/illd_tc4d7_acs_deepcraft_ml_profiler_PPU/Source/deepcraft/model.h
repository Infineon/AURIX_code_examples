/*
* ImagiNet Compiler 5.15.5946.65534+0cd5177a7e845dbc189d9b707351412cf6d641f3
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 08/27/2026 09:49:10 UTC. Any changes will be lost.
* 
* Model ID  ddd312c1-9dcc-4aab-9883-0f089df56fab
* 
* Exported functions:
* 
*  @param keras_tensor keras_tensor. Input float[1,28,28].
*  @param output_0 output_0. Output float[1,10].
*  void IMAI_compute(const float __vccm *keras_tensor, float __vccm *output_0);
* 
*  @description: Closes and flushes streams, free any heap allocated memory.
*  void IMAI_finalize(void);
* 
*  @description: Resets windows and neural networks(i.e. RNNs) to initial state.
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_soft_reset(void);
* 
*  @description: Initializes buffers to initial state.
*  void IMAI_init(void);
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
* 
* Notes:
* 	-> This code was generated with DEEPCRAFT™ Model Converter using:
* 		onnx2c-ifx (bundled).
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define IMAI_API_FUNCTION

// AURIX PPU (ARC) keeps model I/O in vector RAM (VCCM); arc_vector.h
// provides the __vccm address-space qualifier used on the model I/O.
#include <arc_vector.h>

typedef int8_t q7_t;         // 8-bit fractional data type in Q1.7 format.
typedef int16_t q15_t;       // 16-bit fractional data type in Q1.15 format.
typedef int32_t q31_t;       // 32-bit fractional data type in Q1.31 format.
typedef int64_t q63_t;       // 64-bit fractional data type in Q1.63 format.
typedef float timestamp_t;

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xc1, 0x12, 0xd3, 0xdd, 0xcc, 0x9d, 0xab, 0x4a, 0x98, 0x83, 0x0f, 0x08, 0x9d, 0xf5, 0x6f, 0xab}


// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_Q7	(0x31)
#define IMAGINET_TYPES_Q15	(0x32)
#define IMAGINET_TYPES_Q31	(0x34)
#define IMAGINET_TYPES_BOOL	(0x41)
#define IMAGINET_TYPES_STRING	(0x54)
#define IMAGINET_TYPES_D8	(0x61)
#define IMAGINET_TYPES_D16	(0x62)
#define IMAGINET_TYPES_D32	(0x64)
#define IMAGINET_TYPES_UINT8	(0x71)
#define IMAGINET_TYPES_UINT16	(0x72)
#define IMAGINET_TYPES_UINT32	(0x74)
#define IMAGINET_TYPES_UINT64	(0x78)


#define IMAI_COMPUTE_INPUTS (1)
#define IMAI_COMPUTE_OUTPUTS (1)
#define IMAI_COMPUTE_IN_TYPE float
#define IMAI_COMPUTE_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_COMPUTE_OUT_TYPE float
#define IMAI_COMPUTE_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_COMPUTE_OUT_NO_COPY false

// keras_tensor [1,28,28] (3136 bytes)
#define IMAI_KERAS_TENSOR_RANK (3)
#define IMAI_KERAS_TENSOR_SHAPE ((int[]){28, 28, 1})
#define IMAI_KERAS_TENSOR_COUNT (784)
#define IMAI_KERAS_TENSOR_BYTES (3136)
#define IMAI_KERAS_TENSOR_TYPE float
#define IMAI_KERAS_TENSOR_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_KERAS_TENSOR_SHIFT 0
#define IMAI_KERAS_TENSOR_OFFSET 0
#define IMAI_KERAS_TENSOR_SCALE 1
#define IMAI_KERAS_TENSOR_SYMBOLS { }

// output_0 [1,10] (40 bytes)
#define IMAI_OUTPUT_0_RANK (2)
#define IMAI_OUTPUT_0_SHAPE ((int[]){10, 1})
#define IMAI_OUTPUT_0_COUNT (10)
#define IMAI_OUTPUT_0_BYTES (40)
#define IMAI_OUTPUT_0_TYPE float
#define IMAI_OUTPUT_0_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_OUTPUT_0_SHIFT 0
#define IMAI_OUTPUT_0_OFFSET 0
#define IMAI_OUTPUT_0_SCALE 1
#define IMAI_OUTPUT_0_SYMBOLS { }

#define IMAI_KEY_MAX (1)

#define IMAI_MODEL_RNN false

// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_ERROR -2
#define IMAI_RET_STREAMEND -3

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_ERROR -2
#define IPWIN_RET_STREAMEND -3

// Exported methods
void IMAI_compute(const float __vccm *restrict keras_tensor, float __vccm *restrict output_0);
void IMAI_finalize(void);
int IMAI_soft_reset(void);
void IMAI_init(void);

// Symbol IMAI_PROFILING must be defined to enable profiling of models
// Symbol IMAI_PROFILING_LOG will enable printing the raw outputs of neural networks
/// @brief This method will print the region profiling results
void IMAI_print_region_profiling(void);
/// @brief Point this function pointer to your custom tick count function. This should populate the value pointed to by val with the current tick count.
extern int (*IMAI_get_ticks_ptr)(uint64_t*);

// Profiling regions
#define IMAI_REGIONS_COUNT 1
#define IMAI_REGIONS_NAMES {\
	"MNIST_MLP",\
}
#define IMAI_REGIONS_NOTES {\
	NULL,\
}

// Call macros — invoke any exported function via a void* array of arguments
#define IMAI_COMPUTE_PTR(a) IMAI_compute((const float __vccm *)(a)[0], (float __vccm *)(a)[1])
#define IMAI_FINALIZE_PTR(a) IMAI_finalize()
#define IMAI_SOFT_RESET_PTR(a) IMAI_soft_reset()
#define IMAI_INIT_PTR(a) IMAI_init()

typedef enum {
    IMAI_PARAM_UNDEFINED = 0,
    IMAI_PARAM_INPUT = 1,
    IMAI_PARAM_OUTPUT = 2,
    IMAI_PARAM_REFERENCE = 3,
    IMAI_PARAM_HANDLE = 7,
    IMAI_PARAM_CALLBACK = 8,
    IMAI_PARAM_OUTPUT_REF = 18,
} IMAI_param_attrib;

typedef char *label_text_t;

typedef struct {
    char* name;
    int size;
    label_text_t *labels;
} IMAI_shape_dim;

typedef struct {
    char* name;
    IMAI_param_attrib attrib;
    int32_t rank;
    IMAI_shape_dim *shape;
    int32_t count;
    int32_t bytes;
    int32_t type_id;
    float frequency;
    int shift;
    float scale;
    long offset;
} IMAI_param_def;

typedef enum {
    IMAI_FUNC_ATTRIB_NONE = 0,
    IMAI_FUNC_ATTRIB_CAN_FAIL = 1,
    IMAI_FUNC_ATTRIB_PUBLIC = 2,
    IMAI_FUNC_ATTRIB_INIT = 4,
    IMAI_FUNC_ATTRIB_DESTRUCTOR = 8,
} IMAI_func_attrib;

typedef struct {
    char* name;
    char* description;
    void* fn_ptr;
    IMAI_func_attrib attrib;
    int32_t param_count;
    IMAI_param_def *param_list;
} IMAI_func_def;

typedef struct {
    uint32_t size;
    uint32_t peak_usage;
} IMAI_mem_usage;

typedef enum {
    IMAI_API_TYPE_UNDEFINED = 0,
    IMAI_API_TYPE_FUNCTION = 1,
    IMAI_API_TYPE_QUEUE = 2,
    IMAI_API_TYPE_QUEUE_TIME = 3,
    IMAI_API_TYPE_CALLBACK = 4,
    IMAI_API_TYPE_CALLBACK_TIME = 5,
} IMAI_api_type;

typedef struct {
    uint32_t api_ver;
    uint8_t id[16];
    IMAI_api_type api_type;
    char* prefix;
    IMAI_mem_usage buffer_mem;
    IMAI_mem_usage static_mem;
    IMAI_mem_usage readonly_mem;
    int32_t func_count;
    IMAI_func_def *func_list;
} IMAI_api_def;

IMAI_api_def *IMAI_api(void);

#define IMAI_INPUT_META_COUNT 1
#define IMAI_OUTPUT_META_COUNT 1
#define IMAI_INPUT_META(i) ((IMAI_param_def*)(&IMAI_api()->func_list[0].param_list[(i)]))
#define IMAI_OUTPUT_META(i) ((IMAI_param_def*)(&IMAI_api()->func_list[0].param_list[(i) + 1]))

