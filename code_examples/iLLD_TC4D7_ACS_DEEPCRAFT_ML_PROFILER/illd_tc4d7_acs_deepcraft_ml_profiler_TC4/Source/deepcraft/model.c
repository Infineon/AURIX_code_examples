/*
* ImagiNet Compiler 5.15.5946.65534+0cd5177a7e845dbc189d9b707351412cf6d641f3
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 08/25/2026 12:54:27 UTC. Any changes will be lost.
* 
* Model ID  9cbeb729-5789-4dfd-8e76-d6331c8ea02b
* 
* Exported functions:
* 
*  @param args_0_0 args_0:0. Input float[1,50,40].
*  @param identity_0 Identity:0. Output float[1,36].
*  void IMAI_compute(const float *args_0_0, float *identity_0);
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

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "model.h"

#ifdef __GNUC__
	#define ALIGNED(x) __attribute__((aligned(x)))
#else
	#define ALIGNED(x) __declspec(align(x))
#endif

#if defined(__GNUC__) || defined(__clang__)
	#define ATTRIB_WEAK  __attribute__((weak))
#else
	#define ATTRIB_WEAK 
#endif
extern void entry(const float *args_0_0, float *Identity_0);


// Working memory

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_ERROR -2
#define IPWIN_RET_STREAMEND -3

#ifdef IMAI_PROFILING
	static uint32_t region_profile_visits[IMAI_REGIONS_COUNT];
	static uint64_t region_start[IMAI_REGIONS_COUNT];
	static uint64_t region_profile_sum[IMAI_REGIONS_COUNT];
	static uint64_t region_profile_max[IMAI_REGIONS_COUNT];
	static char* region_names[] = IMAI_REGIONS_NAMES;
	static const char* region_notes[] = IMAI_REGIONS_NOTES;

	#define __HOOK_REGION(entered, region_id) hook_region(entered, region_id)
	#define __CLOSE_HOOKS() close_regions()

	int IMAI_get_ticks(uint64_t *val) { return 0; }
    int (*IMAI_get_ticks_ptr)(uint64_t* val) = &IMAI_get_ticks;

	ATTRIB_WEAK void IMAI_hook_region(bool entered, int32_t region_id) {
		uint64_t ticks = 0;
		// assign the current tick count with a BSP or custom function
		IMAI_get_ticks_ptr(&ticks);
		 if (entered) {
			 region_start[region_id] = ticks;
		}
		else {
			ticks = ticks - region_start[region_id];
			region_profile_visits[region_id]++;
			if (ticks > region_profile_max[region_id])
				region_profile_max[region_id] = ticks;
			region_profile_sum[region_id] += ticks;
		}
	}
	
	static bool region_entered[IMAI_REGIONS_COUNT];
	
	static inline void hook_region(bool entered, int32_t region_id) {
		region_entered[region_id] = entered;
		IMAI_hook_region(entered, region_id);
	}
	
	static inline void close_regions() {
		uint32_t i = 0;
		for (i = 0; i < IMAI_REGIONS_COUNT; i++)
			if (region_entered[i])
				hook_region(false, i);
	}

	void IMAI_print_region_profiling(void) {
		uint32_t i = 0;
		printf("Region profiling results:\r\n");
		for (i = 0; i < IMAI_REGIONS_COUNT; i++) {
			if (region_notes[i] != NULL && region_notes[i][0] != '\0') {
				printf("Region \"%s\"; %s\r\n",
					region_names[i],
					region_notes[i]);
			}
			else {
				printf("Region \"%s\"; visits: %lu, max cycles: %-10.2f, avg cycles: %-10.2f\r\n",
					region_names[i],
					(unsigned long)region_profile_visits[i],
					(float)region_profile_max[i],
					(float)region_profile_sum[i] / region_profile_visits[i]);
			}
		}
		printf("\r\n");
	}
#else
	#define __HOOK_REGION(entered, region_id) do { } while(0)
	#define __CLOSE_HOOKS() do { } while(0)

	void IMAI_print_region_profiling(void) {
		(void)0;
	}
#endif

#ifndef __CLOSE_HOOKS
	#define __CLOSE_HOOKS() do { } while(0)
#endif
#define __RETURN_ERROR(_exp) do { int __ret = (_exp); if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } } while(0)
#define __RETURN_ALWAYS(_exp) __CLOSE_HOOKS(); return (_exp)
#define __RETURN_ERROR_BREAK_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) break; if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __RETURN_ERROR_BREAK_EMPTY_END(_exp) {  int __ret = (_exp); if(__ret == -1 || __ret == -3) break; if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __RETURN_ERROR_CANCEL_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) { __CLOSE_HOOKS(); return 0; } if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __BREAK_ERROR(_exp) {  int __ret = (_exp); if(__ret < 0) break; }
#define __CONTINUE_ON_EMPTY(_exp) {  int __ret = (_exp); if(__ret < -1) { __CLOSE_HOOKS(); return __ret; } }

/*
*  @param args_0_0 args_0:0. Input float[1,50,40].
*  @param identity_0 Identity:0. Output float[1,36].
*/
void IMAI_compute(const float *restrict args_0_0, float *restrict identity_0) {    
    __HOOK_REGION(true, 0);
    entry(args_0_0, identity_0);
    __HOOK_REGION(false, 0);
}

/*
* Closes and flushes streams, free any heap allocated memory.
* 
*/
void IMAI_finalize(void) {    
}

/*
* Resets windows and neural networks(i.e. RNNs) to initial state.
* 
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_soft_reset(void) {    
    return 0;
}

/*
* Initializes buffers to initial state.
* 
*/
void IMAI_init(void) {    
}

static IMAI_api_def _IMAI_api_def = {
    .api_ver = 1,
    .id = {0x29, 0xb7, 0xbe, 0x9c, 0x89, 0x57, 0xfd, 0x4d, 0x8e, 0x76, 0xd6, 0x33, 0x1c, 0x8e, 0xa0, 0x2b},
    .api_type = IMAI_API_TYPE_FUNCTION,
    .prefix = "IMAI_",
    .buffer_mem = {
        .size = 0,
        .peak_usage = 0,
    },
    .static_mem = {
        .size = 0,
        .peak_usage = 0,
    },
    .readonly_mem = {
        .size = 0,
        .peak_usage = 0,
    },
    .func_count = 4,
    .func_list = (IMAI_func_def[]) {
        {
            .name = "IMAI_compute",
            .description = "",
            .fn_ptr = IMAI_compute,
            .attrib = 2,
            .param_count = 2,
            .param_list = (IMAI_param_def[]) {
                {
                    .name = "args_0_0",
                    .attrib = IMAI_PARAM_INPUT,
                    .rank = 3,
                    .shape = (IMAI_shape_dim[]) {
                        {
                            .name = "",
                            .size = 40,
                        },
                        {
                            .name = "",
                            .size = 50,
                        },
                        {
                            .name = "",
                            .size = 1,
                        },
                    },
                    .count = 2000,
                    .bytes = 8000,
                    .type_id = IMAGINET_TYPES_FLOAT32,
                    .frequency = 1,
                    .shift = 0,
                    .scale = 1,
                    .offset = 0,
                },
                {
                    .name = "identity_0",
                    .attrib = IMAI_PARAM_OUTPUT,
                    .rank = 2,
                    .shape = (IMAI_shape_dim[]) {
                        {
                            .name = "",
                            .size = 36,
                        },
                        {
                            .name = "",
                            .size = 1,
                        },
                    },
                    .count = 36,
                    .bytes = 144,
                    .type_id = IMAGINET_TYPES_FLOAT32,
                    .frequency = 1,
                    .shift = 0,
                    .scale = 1,
                    .offset = 0,
                },
            },
        },
        {
            .name = "IMAI_finalize",
            .description = "Closes and flushes streams, free any heap allocated memory.",
            .fn_ptr = IMAI_finalize,
            .attrib = 10,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
        {
            .name = "IMAI_soft_reset",
            .description = "Resets windows and neural networks(i.e. RNNs) to initial state.",
            .fn_ptr = IMAI_soft_reset,
            .attrib = 67,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
        {
            .name = "IMAI_init",
            .description = "Initializes buffers to initial state.",
            .fn_ptr = IMAI_init,
            .attrib = 6,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
    },
};

IMAI_api_def *IMAI_api(void) {
    return &_IMAI_api_def;
}

