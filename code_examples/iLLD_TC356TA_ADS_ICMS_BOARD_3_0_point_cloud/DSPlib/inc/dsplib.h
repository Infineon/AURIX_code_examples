/*****************************************************************************
*
* Copyright (C) 2022 Infineon Technologies AG. All rights reserved.
*
* Infineon Technologies AG (INFINEON) is supplying this file for use
* exclusively with Infineon's microcontroller products. This file can be freely
* distributed within development tools and software supporting such microcontroller
* products.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL, 
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
******************************************************************************/

/*!
 * \file dsplib.h
 * \brief Infineon DSP library API include file
 *
 * This file contains the API header for the Infineon DSP library.
 *
 * Revision: 07.2022
 */

#ifndef IFX_DSPLIB_H
#define IFX_DSPLIB_H

//#include "Ifx_Types.h"

/*! \addtogroup runtime
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * External Include Files                                               *
 *                                                                      *
\************************************************************************/

#if _MSC_VER
typedef __int8 sint8;      			/*        -128 .. +127            */
typedef unsigned __int8 uint8;     	/*           0 .. 255             */
typedef __int16 sint16;    			/*      -32768 .. +32767          */
typedef unsigned __int16 uint16;   	/*           0 .. 65535           */
typedef __int32 sint32;    			/* -2147483648 .. +2147483647     */
typedef unsigned __int32 uint32;   	/*           0 .. 4294967295      */
typedef __int64 sint64;
typedef unsigned __int64 uint64;

typedef unsigned uint8_least;      	/* At least 8 bit                 */
typedef unsigned uint16_least;    	/* At least 16 bit                */
typedef unsigned uint32_least;    	/* At least 32 bit                */
typedef int sint8_least;     	 	/* At least 7 bit + 1 bit sign    */
typedef int sint16_least;    		/* At least 15 bit + 1 bit sign   */
typedef int sint32_least;    		/* At least 31 bit + 1 bit sign   */

typedef float float32;
typedef double float64;

#include <float.h>
#define IFX_FLT_EPSILON FLT_EPSILON
/*!< FLT_EPSILON is the positive difference between 1.0f and the next higher
 *   representable number of float data type. It is about 0.0000001 */
#define IFX_Q15_EPSILON (powf(2.0f,-15.0f))
#define IFX_Q31_EPSILON (powf(2.0f,-31.0f))

extern unsigned int Ifx_internalNan[1];
extern unsigned int Ifx_internalInf[1];

#define IFX_NAN (*(float32*)Ifx_internalNan)
#define IFX_INFINITY (*(float32*)Ifx_internalInf)

#define _USE_MATH_DEFINES
#include <math.h>
#define IFX_M_2PI ((float32)(2.0f*M_PI))   /*!< \brief definition of 2 times Pi (2*3.14159...) */
#define IFX_M_PI ((float32)M_PI)           /*!< \brief definition Pi */
#define IFX_M_PI_2 ((float32)M_PI_2)       /*!< \brief definition Pi/2 (2*3.14159...) */
#define IFX_M_PI_4 ((float32)M_PI_4)       /*!< \brief definition of Pi/4 (2*3.14159...) */
/*! copy sign from the second argument to the number given in the first argument */
#define IFX_COPYSIGN_F32(X,Y) ((float32)_copysign((X),(Y)))

#include <string.h>
#define Ifx_memset memset       /*!< \brief The function memset(void *buffer, int ch, size_t count) copies ch into the first count characters of buffer, and returns buffer.*/
#define Ifx_memcpy memcpy       /*!< \brief The function memcpy(void *to, const void *from, size_t count) copies count characters from the array from to the array to. memcpy() returns to.*/
/*!< \brief memset */

#include <assert.h>
#define Ifx_assert assert
/*!< \brief assert */

#include <malloc.h>
#define IFX_ALLOC_TMP_VECTOR(TYPE,NAME,DIM) TYPE *NAME = (TYPE*) _alloca ((DIM)*sizeof(TYPE))
#define IFX_FREE_TMP_VECTOR(TYPE,NAME,DIM) do {} while (0)

#define HAVE_STDIO 1
#define HAVE_FILEIO 1
#define HAVE_LIBM 1
#undef HAVE_LIBFFTW
#undef HAVE_CIRCULAR_BUFFER

#endif /* _MSVC_VER */

#if IFX_TRICORE_TARGET

#if IFX_TARGET_TRICORE_PLS_ECLIPSE
#include <stdint.h>
typedef int8_t sint8;      /*        -128 .. +127            */
typedef uint8_t uint8;     /*           0 .. 255             */
typedef int16_t sint16;    /*      -32768 .. +32767          */
typedef uint16_t uint16;   /*           0 .. 65535           */
typedef int32_t sint32;    /* -2147483648 .. +2147483647     */
typedef uint32_t uint32;   /*           0 .. 4294967295      */
typedef int64_t sint64;
typedef uint64_t uint64;

typedef uint_least8_t uint8_least;      /* At least 8 bit                 */
typedef uint_least16_t uint16_least;    /* At least 16 bit                */
typedef uint_least32_t uint32_least;    /* At least 32 bit                */
typedef uint_least8_t sint8_least;      /* At least 7 bit + 1 bit sign    */
typedef uint_least16_t sint16_least;    /* At least 15 bit + 1 bit sign   */
typedef uint_least32_t sint32_least;    /* At least 31 bit + 1 bit sign   */

typedef float float32;
typedef double float64;
#endif /* IFX_TARGET_TRICORE_PLS_ECLIPSE */

#if IFX_TARGET_TRICORE_APPLICATION_FRAMEWORK
#include <Ifx_Types.h>
#define IFX_NAN (*(float32*)Ifx_internalNan)
#define IFX_INFINITY (*(float32*)Ifx_internalInf)
#endif /* IFX_TARGET_TRICORE_APPLICATION_FRAMEWORK */

#include <float.h>
#define IFX_FLT_EPSILON FLT_EPSILON
/*!< FLT_EPSILON is the positive difference between 1.0f and the next higher
 *   representable number of float data type. It is about 0.0000001 */
#define IFX_Q15_EPSILON (powf(2.0f,-15.0f))
#define IFX_Q31_EPSILON (powf(2.0f,-31.0f))

extern unsigned int Ifx_internalNan[1];
extern unsigned int Ifx_internalInf[1];

#define IFX_NAN (*(float32*)Ifx_internalNan)
#define IFX_INFINITY (*(float32*)Ifx_internalInf)

#include <math.h>
#define IFX_M_2PI (2.0f*IFX_M_PI)   	 /*!< \brief definition of 2 times Pi (2*3.14159...) */
#define IFX_M_PI 3.1415926535f           /*!< \brief definition Pi							 */
#define IFX_M_PI_2 (IFX_M_PI*0.5f)       /*!< \brief definition Pi/2 (2*3.14159...) 		 */
#define IFX_M_PI_4 (IFX_M_PI*0.25f)      /*!< \brief definition of Pi/4 (2*3.14159...) 		 */
/*! copy sign from the second argument to the number given in the first argument */
#define IFX_COPYSIGN_F32(X,Y) (copysignf((X),(Y)))

#include <string.h>
#define Ifx_memset memset       /*!< \brief The function memset(void *buffer, int ch, size_t count) copies ch into the first count characters of buffer, and returns buffer.*/
#define Ifx_memcpy memcpy       /*!< \brief The function memcpy(void *to, const void *from, size_t count) copies count characters from the array from to the array to. memcpy() returns to.*/
/*!< \brief memset */

#if IFX_TARGET_TRICORE_PLS_ECLIPSE
#include <assert.h>
#define Ifx_assert assert
#endif /* IFX_TARGET_TRICORE_PLS_ECLIPSE */

#if IFX_TARGET_TRICORE_APPLICATION_FRAMEWORK
#include "Ifx_Assert.h"   /*for Gcc11*/
//#include "Assert.h"         /* for TASKING*/
#define Ifx_assert(P) IFX_ASSERT(0,(P)) /*!< \brief assert */
#endif /* IFX_TARGET_TRICORE_APPLICATION_FRAMEWORK */

#include <stdlib.h>
#define IFX_ALLOC_TMP_VECTOR(TYPE,NAME,DIM) TYPE NAME[DIM]
#define IFX_FREE_TMP_VECTOR(TYPE,NAME,DIM) do {} while (0)

#define HAVE_STDIO 1
#undef HAVE_FILEIO
#define HAVE_LIBM 1
#undef HAVE_LIBFFTW
#define HAVE_CIRCULAR_BUFFER 1

#endif /* IFX_TRICORE_TARGET */

#if __unix__
# include <stdint.h>
typedef int8_t sint8;      /*        -128 .. +127            */
typedef uint8_t uint8;     /*           0 .. 255             */
typedef int16_t sint16;    /*      -32768 .. +32767          */
typedef uint16_t uint16;   /*           0 .. 65535           */
typedef int32_t sint32;    /* -2147483648 .. +2147483647     */
typedef uint32_t uint32;   /*           0 .. 4294967295      */
typedef int64_t sint64;
typedef uint64_t uint64;

typedef uint_least8_t uint8_least;      /* At least 8 bit                 */
typedef uint_least16_t uint16_least;    /* At least 16 bit                */
typedef uint_least32_t uint32_least;    /* At least 32 bit                */
typedef uint_least8_t sint8_least;      /* At least 7 bit + 1 bit sign    */
typedef uint_least16_t sint16_least;    /* At least 15 bit + 1 bit sign   */
typedef uint_least32_t sint32_least;    /* At least 31 bit + 1 bit sign   */

typedef float float32;
typedef double float64;

#include <float.h>
#define IFX_FLT_EPSILON FLT_EPSILON
/*!< FLT_EPSILON is the positive difference between 1.0f and the next higher
 *   representable number of float data type. It is about 0.0000001 */
#define IFX_Q15_EPSILON (powf(2.0f,-15.0f))
#define IFX_Q31_EPSILON (powf(2.0f,-31.0f))

#define IFX_NAN NAN
#define IFX_INFINITY INFINITY

#include <math.h>
#define IFX_M_2PI ((float32)(2.0*M_PI))   /*!< \brief definition of 2 times Pi (2*3.14159...) */
#define IFX_M_PI ((float32)M_PI)           /*!< \brief definition Pi */
#define IFX_M_PI_2 ((float32)M_PI_2)       /*!< \brief definition Pi/2 (2*3.14159...) */
#define IFX_M_PI_4 ((float32)M_PI_4)       /*!< \brief definition of Pi/4 (2*3.14159...) */
/*! copy sign from the second argument to the number given in the first argument */
#define IFX_COPYSIGN_F32(X,Y) (copysignf((X),(Y)))

#include <string.h>
#define Ifx_memset memset       /*!< \brief The function memset(void *buffer, int ch, size_t count) copies ch into the first count characters of buffer, and returns buffer.*/
#define Ifx_memcpy memcpy       /*!< \brief The function memcpy(void *to, const void *from, size_t count) copies count characters from the array from to the array to. memcpy() returns to.*/
/*!< \brief memset */

#include <assert.h>
#define Ifx_assert assert
/*!< \brief assert */

#include <stdlib.h>
#define IFX_ALLOC_TMP_VECTOR(TYPE,NAME,DIM) TYPE NAME[DIM]
#define IFX_FREE_TMP_VECTOR(TYPE,NAME,DIM) do {} while (0)

#define HAVE_STDIO 1
#define HAVE_FILEIO 1
#define HAVE_LIBM 1
#define HAVE_LIBFFTW 1
#undef HAVE_CIRCULAR_BUFFER

#endif /* __unix__ */

#if HAVE_STDIO
#include <stdio.h>
#endif /* HAVE_STDIO */

#if !HAVE_CIRCULAR_BUFFER
/*! hardware accelerated circular buffer structure */
typedef struct Ifx_CircularBuffer_t {
    uint32 base;
    uint16 index;
    uint16 limit;
} Ifx_CircularBuffer_t;
#endif

/************************************************************************\
 *                                                                      *
 * Data Structures                                                      *
 *                                                                      *
\************************************************************************/
/* In addition to the existing types in Ifx_Types.h */
/*! complex number with 8-bit integers (Q7) */
typedef struct csint8_t   { sint8   real /*!< real part */,imag; /*!< imaginary part */ } csint8;
/*! complex number with 64-bit integers */
typedef struct csint64_t  { sint64  real /*!< real part */,imag; /*!< imaginary part */ } csint64;

/*! @}*/

/*! \addtogroup macros
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * Macros                                                               *
 *                                                                      *
\************************************************************************/
/*! \section naming convention
 * Abbreviations for macro names:
 * \li \c Q15 means that we deal with a 16 bit fixed-point number,
 * where 15 bits are behind the comma, one bit is responsible for the sign
 * \li \c Q31 means that we deal with a 32 bit fixed-point number,
 * where 31 bits are behind the comma, one bit is responsible for the sign
 * \li \c F32 means that we deal with a 32 bit float
 */

/*! compute the N-th complex root of unity raised to I, with Q15 output */
#define IFX_CRU_Q15(RES,I,N) do { \
    float32 phi = -IFX_M_2PI*(float32)(I)/((float32)(N)); \
    (RES).real = (sint16) (Ifx_cosF32(phi,IFX_MODE_ALGORITHMIC)*32767.0f); \
    (RES).imag = (sint16) (Ifx_sinF32(phi,IFX_MODE_ALGORITHMIC)*32767.0f); \
} while(0)
/*! compute the N-th complex root of unity raised to I, with Q31 output */
#define IFX_CRU_Q31(RES,I,N) do { \
    float32 phi = -IFX_M_2PI*(float32)(I)/((float32)(N)); \
    (RES).real = (sint32) (Ifx_cosF32(phi,IFX_MODE_ALGORITHMIC)*2147483647.0); \
    (RES).imag = (sint32) (Ifx_sinF32(phi,IFX_MODE_ALGORITHMIC)*2147483647.0); \
} while(0)
#define IFX_CRU_F32_N 1024
extern cfloat32 Ifx_cruF32[IFX_CRU_F32_N];
/*! compute the N-th complex root of unity raised to I, as IEEE float output */
#define IFX_CRU_F32(RES,I,N) do {                                       \
       Ifx_assert (0<=(I) && (I)<(N));                                 \
        switch ((N)) {                                                  \
            case 1:                                                     \
                (RES).real = 1.0f;                                      \
                (RES).imag = 0.0f;                                      \
                break;                                                  \
            case 2:                                                     \
                (RES) = Ifx_cruF32[(I)<<9];                             \
                break;                                                  \
            case 4:                                                     \
                (RES) = Ifx_cruF32[(I)<<8];                             \
                break;                                                  \
            case 8:                                                     \
                (RES) = Ifx_cruF32[(I)<<7];                             \
                break;                                                  \
            case 16:                                                    \
                (RES) = Ifx_cruF32[(I)<<6];                             \
                break;                                                  \
            case 32:                                                    \
                (RES) = Ifx_cruF32[(I)<<5];                             \
                break;                                                  \
            case 64:                                                    \
                (RES) = Ifx_cruF32[(I)<<4];                             \
                break;                                                  \
            case 128:                                                   \
                (RES) = Ifx_cruF32[(I)<<3];                             \
                break;                                                  \
            case 256:                                                   \
                (RES) = Ifx_cruF32[(I)<<2];                             \
                break;                                                  \
            case 512:                                                   \
                (RES) = Ifx_cruF32[(I)<<1];                             \
                break;                                                  \
            case 1024:                                                  \
                (RES) = Ifx_cruF32[(I)];                                \
                break;                                                  \
            default:                                                    \
            {                                                           \
                float32 phi = -IFX_M_2PI*(float32)(I)/((float32)(N));   \
                Ifx_error (IFX_ERR_WARN,                                \
                           "IFX_CRU_F32(%d,%d) not accelerated\n",      \
                           (I), (N));                                   \
                (RES).real = Ifx_cosF32(phi,IFX_MODE_ALGORITHMIC);      \
                (RES).imag = Ifx_sinF32(phi,IFX_MODE_ALGORITHMIC);      \
            }                                                           \
        }                                                               \
} while(0)

/*! multiply two complex numbers in Q15 */
#define IFX_CMUL_Q15(RES,C1,C2) do { \
    sint32 help1,help2; \
    help1 = (sint32) (C1).real * (sint32) (C2).real - (sint32) (C1).imag * (sint32) (C2).imag; \
    help2 = (sint32) (C1).real * (sint32) (C2).imag + (sint32) (C1).imag * (sint32) (C2).real; \
	if (help1>=(0x7fff<<15)) help1 = (0x7fff<<15); /* saturate on overflow */ \
    if (help2>=(0x7fff<<15)) help2 = (0x7fff<<15); /* saturate on overflow */ \
    help1 = (help1+(1<<14))>>15; \
    help2 = (help2+(1<<14))>>15; \
    (RES).real = help1; \
    (RES).imag = help2; \
} while(0)
/*! multiply two complex numbers in Q31 */
#define IFX_CMUL_Q31(RES,C1,C2) do { \
    sint64 help1,help2; \
    help1 = (sint64) (C1).real * (sint64) (C2).real - (sint64) (C1).imag * (sint64) (C2).imag; \
    help2 = (sint64) (C1).real * (sint64) (C2).imag + (sint64) (C1).imag * (sint64) (C2).real; \
	if (help1>=(0x7fffffffll<<31)) help1 = (0x7fffffffll<<31); /* saturate on overflow */ \
    if (help2>=(0x7fffffffll<<31)) help2 = (0x7fffffffll<<31); /* saturate on overflow */ \
    help1 = (help1+(1<<30))>>31; \
    help2 = (help2+(1<<30))>>31; \
    (RES).real = (sint32) help1; \
    (RES).imag = (sint32) help2; \
} while(0)
/*! multiply two complex numbers in float32 */
#define IFX_CMUL_F32(RES,C1,C2) do { \
    (RES).real = (C1).real * (C2).real - (C1).imag * (C2).imag; \
    (RES).imag = (C1).real * (C2).imag + (C1).imag * (C2).real; \
} while(0)

/*! add two complex number in 32-bit IEEE float */
#define IFX_CADD_F32(RES,C1,C2) do { \
    (RES).real = (C1).real + (C2).real; \
    (RES).imag = (C1).imag + (C2).imag; \
} while(0)
/*! add two complex number in Q15 and divide result by 2 */
#define IFX_CADD_Q15(RES,C1,C2) do { \
    sint32 help1,help2; \
    help1 = (sint32)(C1).real + (sint32)(C2).real; \
    help2 = (sint32)(C1).imag + (sint32)(C2).imag; \
    (RES).real = (sint16)(help1>>1); \
    (RES).imag = (sint16)(help2>>1); \
} while(0)
/*! add two complex number in Q32 and divide result by 2 */
#define IFX_CADD_Q31(RES,C1,C2) do { \
    sint64 help1,help2; \
    help1 = (sint64)(C1).real + (sint64)(C2).real; \
    help2 = (sint64)(C1).imag + (sint64)(C2).imag; \
    (RES).real = (sint32)(help1>>1); \
    (RES).imag = (sint32)(help2>>1); \
} while(0)

/*! subtract two complex number in Q15 and divide result by 2 */
#define IFX_CSUB_Q15(RES,C1,C2) do { \
    sint32 help1,help2; \
    help1 = (sint32)(C1).real - (sint32)(C2).real; \
    help2 = (sint32)(C1).imag - (sint32)(C2).imag; \
    (RES).real = (sint16)(help1>>1); \
    (RES).imag = (sint16)(help2>>1); \
} while(0)
/*! subtract two complex number in Q31 and divide result by 2 */
#define IFX_CSUB_Q31(RES,C1,C2) do { \
    sint64 help1,help2; \
    help1 = (sint64)(C1).real - (sint64)(C2).real; \
    help2 = (sint64)(C1).imag - (sint64)(C2).imag; \
    (RES).real = (sint32)(help1>>1); \
    (RES).imag = (sint32)(help2>>1); \
} while(0)
/*! subtract two complex number in 32-bit IEEE float */
#define IFX_CSUB_F32(RES,C1,C2) do { \
    (RES).real = (C1).real - (C2).real; \
    (RES).imag = (C1).imag - (C2).imag; \
} while(0)

/*! multiply two numbers in Q15 arithmetics */
#define IFX_MUL_Q15(RES,Z1,Z2) do { \
    sint32 a; \
    a = (sint32) (Z1) * (sint32) (Z2); \
    (RES) = (a+(1<<14))>>15; \
} while(0)
/*! multiply two numbers in Q31 arithmetics */
#define IFX_MUL_Q31(RES,Z1,Z2) do { \
    sint64 a; \
    a = (sint64) (Z1) * (sint64) (Z2); \
    (RES) = (sint32)((a+(1<<30))>>31); \
} while(0)

/*! add two numbers in Q15 arithmetics, and divide result by 2 */
#define IFX_ADD_Q15(RES,Z1,Z2) do { \
    sint32 a; \
    a = (sint32) (Z1) + (sint32) (Z2); \
    (RES) = (sint16)(a>>1); \
} while(0)
/*! add two numbers in Q31 arithmetics, and divide result by 2  */
#define IFX_ADD_Q31(RES,Z1,Z2) do { \
    sint64 a; \
    a = (sint64) (Z1) + (sint64) (Z2); \
    (RES) = (sint32)(a>>1); \
} while(0)

/*! subtract two numbers in Q15 arithmetics, and divide result by 2 */
#define IFX_SUB_Q15(RES,Z1,Z2) do { \
    sint32 a; \
    a = (sint32) (Z1) - (sint32) (Z2); \
    (RES) = (sint16)(a>>1); \
} while(0)
/*! subtract two numbers in Q31 arithmetics, and divide result by 2 */
#define IFX_SUB_Q31(RES,Z1,Z2) do { \
    sint64 a; \
    a = (sint64) (Z1) - (sint64) (Z2); \
    (RES) = (sint32)(a>>1); \
} while(0)
/*! absolute value of floating point value */
#define IFX_ABS_F32(X) (IFX_COPYSIGN_F32((X),1.0f))
/*! square value in floating point */
#define IFX_SQR_F32(X) ((float32)(X)*(float32)(X))
/*! maximum value in floating point */
#define IFX_MAX_F32(X,Y) ((X)>=(Y)?(X):(Y))
/*! minimum value in floating point */
#define IFX_MIN_F32(X,Y) ((X)<=(Y)?(X):(Y))

/*! absolute value of integer */
#define IFX_ABS_INT(X) ((X)>0?(X):-(X))
/*! absolute value of complex number */
#define IFX_ABS_CF32(X) (Ifx_sqrtF32((IFX_SQR_F32((X).real)+IFX_SQR_F32((X).imag)),IFX_MODE_ALGORITHMIC))
/*! floating point modulo */
#define IFX_MOD_F32(X,Y) (fmodf((X),(Y)))
/*! floating point power */
#define IFX_POW_F32(X,Y) (powf((X),(Y)))

/*! @}*/

/*! \addtogroup context
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * IFX Context                                                          *
 *                                                                      *
\************************************************************************/

/*! DSP library context
 * \brief this is an opaque data structure.
 */
struct Ifx_context {
    void * context_info; /*!< some information on the context */
    int context_number; /*!< some information on the context */
};
typedef struct Ifx_context * Ifx_hContext; /*!< context handle */

/*! create context
 * \brief create a new IFX context
 */
Ifx_hContext Ifx_create_context ();
/*! dispose context
 * \brief dispose IFX context
 */
void Ifx_dispose_context (Ifx_hContext);

/*! mode of operation for implementation */
#define IFX_MODE_MAX 7
enum Ifx_mode {
    IFX_MODE_EXTERNAL_LIBRARY=0, 							/*!< use reference implementation from external library 			 */
    IFX_MODE_REFERENCE_IMPLEMENTATION=1, 					/*!< use slow but safe reference implementation. 
															 * No reference to external libraries needed 						 */
    IFX_MODE_ALGORITHMIC=IFX_MODE_REFERENCE_IMPLEMENTATION, /*!< algorithmic mode,
                                                             * obsolete, use IFX_MODE_REFERENCE_IMPLEMENTATION instead. 		 */
    IFX_MODE_OPTIMIZED_C=2, 								/*!< optimized C language implementation 							 */
    IFX_MODE_OPTIMIZED_ASM=3, 								/*!< optimized assembly language implementation 					 */
    IFX_MODE_HARDWARE_ACCELERATOR=4, 						/*!< use hardware accelerator (only available in TC23 TC26 and TC29) */
    IFX_MODE_LOOKUP_TABLE=5, 								/*!< look-up table 													 */
    IFX_MODE_LOOKUP_TABLE_WITH_INTERPOLATION=6 				/*!< look-up table with interpolation 								 */
};

/*! severity of an error in the library.
 * This also gives the information if continuation of the function is possible
 */
enum Ifx_error_severity {
    IFX_ERR_NONE, /*!< \brief no error has occurred */
    IFX_ERR_INFO, /*!< \brief information message */
    IFX_ERR_WARN, /*!< \brief warning */
    IFX_ERR_ERROR, /*!< \brief severe failure, continuation is possible */
    IFX_ERR_PANIC, /*!< \brief severe failure, continuation is not possible */
};

/*! report an error from the library */
void Ifx_error (enum Ifx_error_severity, const char * format, ...);

/*!  */
extern void Ifx_catchError(void);

/*! @}*/

/*! \addtogroup fractional
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * fractional (16-bit and 32-bit variants)                              *
 *                                                                      *
\************************************************************************/

/*!
 * sine function Q15 format
 * \param[in]  x 32 bit (3Q29) radian input in the range [-pi, pi]
 * \return sine value in 1Q15
 */
sint16 Ifx_sinQ15(sint32  x );

/*!
 * cosine function Q15
 * \param[in]  x 32 bit (3Q29) radian input in the range [-pi, pi]
 * \return cosine value in 1Q15
 */
sint16 Ifx_cosQ15(sint32  x);


/*!
* inverse tangent function
* \param[in]  x tan value in (16Q16), range [-2^15,2^15)
* \return  arctan(x) in radians [-p/2,p/2] 2Q14 format
*/
sint16 Ifx_atanQ15(sint32  x);


/*!
* inverse tangent function, 2 parameters
* \param[in] y 16 bit Imag part of complex plane
* \param[in] x 16 bit Real part of complex plane
* \return  arctan(y/x) in radians [-pi,pi], 3Q13 format
*/
sint16
Ifx_atan2Q15(
		sint16 y,
		sint16 x);

/*! sqrt function
* \param[in]  x value in 16Q16 range [0, 2^14)
* \return  sqrt value in (8Q8)
*/
sint16 Ifx_sqrtQ15(sint32 x );

/*! @}*/

/*! \addtogroup conversions
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * conversions (fixed-point <-> floating-point)                         *
 *                                                                      *
\************************************************************************/

/*! convert fixed-point Q15 data to 32-bit IEEE floating point
* If the data overflows, saturation is applied */
struct Ifx_convertRealQ15F32State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    float32 * y; /*!< OUT vector[n] result */
    sint16 * x;  /*!< IN  vector[n] input */
    uint32 n;    /*!< IN  number of samples in vector */
};

/*! convert Q31 fixed-point to IEEE float
 * If the data overflows, saturation is applied */
struct Ifx_convertRealQ31F32State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    float32 * y; /*!< OUT vector[n] result */
    sint32 * x;  /*!< IN  vector[n] input */
    uint32 n;    /*!< IN  number of samples in vector */
};

/*! \brief convert 32-bit IEEE float to Q15 fixed-point */
struct Ifx_convertRealF32Q15State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    sint16 * y; /*!< OUT vector[n] result */
    float32 * x;  /*!< IN  vector[n] input */
    uint32 n;    /*!< IN  number of samples in vector */
};

/*! convert 32-bit IEEE float values to Q31 values */
struct Ifx_convertRealF32Q31State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    sint32 * y; /*!< OUT vector[n] result */
    float32 * x;  /*!< IN  vector[n] input */
    uint32 n;    /*!< IN  number of samples in vector */
};

/*! Fractional to FPU conversion
 * Convert a list of variables (table, matrix) from fractional to Floating point
 */
void Ifx_convertRealQ15F32 (struct Ifx_convertRealQ15F32State *); /*!< convert Q15 to 32-bit IEEE float */
void Ifx_convertRealQ31F32 (struct Ifx_convertRealQ31F32State *); /*!< convert Q31 to 32-bit IEEE float */
void Ifx_convertRealF32Q15 (struct Ifx_convertRealF32Q15State *); /*!< convert 32-bit IEEE float to Q15 */
void Ifx_convertRealF32Q31 (struct Ifx_convertRealF32Q31State *); /*!< convert 32-bit IEEE float to Q31 */

/*! @}*/

/*! \addtogroup floating
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * Mathematic library (floating point)                                  *
 *                                                                      *
\************************************************************************/

/*! \brief Floating point square root */
/*! Computes square root of elements of a 2D table or of a list (1D table)
 * Example: power of a signal
 */
struct Ifx_sqrtRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * dst; /*!< OUT vector[n] destination of square roots */
    float32 * src; /*!< IN  vector[n] source for square roots */
    uint32 n; /*!< IN  number of elements in array */
};
void Ifx_sqrtRealF32 (struct Ifx_sqrtRealF32State *); /*!< component-wise square root of vector */

/*! compute square root of number */
float32 Ifx_sqrtF32 (float32, enum Ifx_mode);
/*! compute square root of number (assembly optimized function) */
float32 Ifx_sqrtF32_fast (float32);

/*! exponential function */
extern float32 Ifx_expF32_fast (float32);
float32 Ifx_expF32 (float32, enum Ifx_mode); /*!< exponential function */

/*! logarithmic function */
float32 Ifx_logF32 (float32, enum Ifx_mode); /*!< logarithmic function */

/* Cosine, Sine, Tg,
 * Computes Cosine, Sine or Tangente 3 variants: algorithmic; look-up table; look-up table with interpolation
 * Look-up table: 16KB data allowed per function
 */
/*! sine function */
float32 Ifx_sinF32 (float32, enum Ifx_mode);
/*! sine assembly optimized function */
float32 Ifx_sinF32_fast (float32);

/*! cosine function */
float32 Ifx_cosF32 (float32, enum Ifx_mode);
/*! cosine assembly optimized function */
float32 Ifx_cosF32_fast (float32);

/*! tangent function */
float32 Ifx_tanF32 (float32, enum Ifx_mode);
/*! tangent assembly optimized function */
float32 Ifx_tanF32_fast (float32);

/* Inv-Cos, Inv-Sin, Inv-Tg
 * IN and OUT in rad, IN range preferably [-pi,pi]
 * Computes inverse (Cosine, Sine or Tangente) 3 variants: algorithmic; look-up table; look-up table with interpolation
 * Look-up table: 16KB data allowed per function (ex: Inv-Sin and Inv-Tg used in radar)
 */
/*! inverse sine function */
float32 Ifx_asinF32 (float32, enum Ifx_mode);
/*! inverse sine assembly optimized function */
float32 Ifx_asinF32_fast (float32);

/*! inverse cosine function */
float32 Ifx_acosF32 (float32, enum Ifx_mode);
/*! inverse cosine assembly optimized function */
float32 Ifx_acosF32_fast (float32);

/*! inverse tangent function */
float32 Ifx_atanF32 (float32, enum Ifx_mode);
/*! inverse tangent assembly optimized function */
float32 Ifx_atanF32_fast (float32);

/*! inverse tangent function, 2 parameters */
float32 Ifx_atan2F32 (float32 y,float32 x, enum Ifx_mode);
/*! inverse tangent assembly optimized function, 2 parameters */
float32 Ifx_atan2F32_fast (float32);

/*! Vector squared length
 *! Computes the sum of  (real)2 + (imaginary)2 for each element of a list
 * (ex: FFT result)
 */
struct Ifx_cabs2F32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * dst; /*!< OUT vector[n] destination of squares */
    cfloat32 * src; /*!< IN  vector[n] source of complex values */
    uint32 n; /*!< IN  number of elements in vector */
};
void Ifx_cabs2F32 (struct Ifx_cabs2F32State *); /*!< component-wise complex square absolute value of vector */

/*! Vector length
 *! Computes the sum of  sqrt[(real)2 + (imaginary)2 ] for each element of a list
 * (ex: FFT result)
 */
struct Ifx_cabsF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * dst; /*!< OUT vector[n] destination of absolute values */
    cfloat32 * src; /*!< IN  vector[n] source of complex values */
    uint32 n; /*!< IN  number of elements in vector */
};
void Ifx_cabsF32 (struct Ifx_cabsF32State *); /*!< component-wise complex absolute value of vector */
void Ifx_cabsF32_fast (struct Ifx_cabsF32State * state); /*!< assembly optimiwed component-wise complex square absolute value of vector */

/*! sum a vector of F32 float data */
struct Ifx_sumRealF32State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    float32 y;   /*!< OUT result */
    float32 * x; /*!< IN  vector[n] input */
    uint32 n;    /*!< IN  number of samples in vector */
};
/*! Sum
 * Computes the sum of a collection of samples; (real or complex)
 * For average / threshold computation
 */
void Ifx_sumRealF32 (struct Ifx_sumRealF32State *); /*!< sum of vector of F32 float data */

/*! find the min value of a vector of F32 values */
struct Ifx_minRealF32State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    float32 y;   /*!< OUT result */
    float32 * x; /*!< IN  vector[n] input*/
    uint32 n;    /*!< IN  number of samples in vector */
};

/*! Min
 *  Find the min value of a vector of F32 type
 */
void Ifx_minRealF32 (struct Ifx_minRealF32State * state); /*!<  find the min value of a vector of F32 type */

/*! find the max value of a vector of F32 values */
struct Ifx_maxRealF32State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    float32 y;   /*!< OUT result */
    float32 * x; /*!< IN  vector[n] input*/
    uint32 n;    /*!< IN  number of samples in vector */
};

/*! max
 *  Find the max value of a vector of F32 type
 */
void Ifx_maxRealF32 (struct Ifx_maxRealF32State * state); /*!<  find the max value of a vector of F32 type */

/*! @}*/

/*! \addtogroup Matrix_F32_Real
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * Matrix library (floating point Real)                                 *
 *                                                                      *
\************************************************************************/

/*! Matrix add
 * Radar, sensor fusion
 */
struct Ifx_mtxAddRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * dst;  /*!< OUT vector[m*n], sum. The result is a matrix which is stored internally as a vector (see row major) */
    float32 * src1; /*!< IN  vector[m*n], first addend. */
    float32 * src2; /*!< IN  vector[m*n], second addend */
    uint32 m;       /*!< IN  number of rows in matrix */
    uint32 n;       /*!< IN  number of columns in matrix */
};
/*
        Calculates the sum of two matrices dst = src1 + src2
*/
extern void Ifx_mtxAddRealF32_fast (uint32 m, uint32 n, float32 * dst, float32 * src1, float32 * src2); /*! fast matrix addition */
void Ifx_mtxAddRealF32 (struct Ifx_mtxAddRealF32State *); /*!< matrix addition */

/*! Matrix subtraction
 * Radar, sensor fusion
 */
struct Ifx_mtxSubRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * dst;  /*!< OUT vector[m*n], sum. The result is a matrix which is stored internally as a vector (see row major) */
    float32 * src1; /*!< IN  vector[m*n], first addend. */
    float32 * src2; /*!< IN  vector[m*n], second addend */
    uint32 m;       /*!< IN  number of rows in matrix */
    uint32 n;       /*!< IN  number of columns in matrix */
};
/*
        Calculates the difference of two matrices dst = src1 - src2
*/
extern void Ifx_mtxSubRealF32_fast (uint32 m, uint32 n, float32 * dst, float32 * src1, float32 * src2); /*! fast matrix subtraction */
void Ifx_mtxSubRealF32 (struct Ifx_mtxSubRealF32State *); /*!< matrix subtraction */

/*! Matrix multiplication
 * 2 function variants 1 variant for (n,m) x (n,1)
 * Radar, sensor fusion
 */
struct Ifx_mtxMulRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * dst;  /*!< OUT vector[m][*n], sum */
    float32 * src1; /*!< IN  vector[m*l], first addend */
    float32 * src2; /*!< IN  vector[l*n], second addend */
    uint32 m;       /*!< IN  number of rows in result matrix */
    uint32 n;       /*!< IN  number of columns in result matrix */
    uint32 l;       /*!< IN  number of adjecant rows/columns */
};
/*! Calculates the product of two matrices dst[M][N] = src1[M][L] * src2[L][N]
 */
void Ifx_mtxMulRealF32 (struct Ifx_mtxMulRealF32State *);
void Ifx_mtxMulRealF32_fast (struct Ifx_mtxMulRealF32State *);

/*! Transpose of a matrix */
struct Ifx_mtxTrpRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * mtx;  /*!< IN vector[m*n] */
    float32 * trp;  /*!< OUT vector[n*m] */
    uint32 m;       /*!< IN  number of rows in mtx, number of columns in trp */
    uint32 n;       /*!< IN  number of columns in matrix, number of rows in trp */
};
void Ifx_mtxTrpRealF32_fast (uint32 m, uint32 n, float32 * trp, float32 * mtx); /*! fast matrix transpose */
void Ifx_mtxTrpRealF32 (struct Ifx_mtxTrpRealF32State *); /*!< matrix transpose */

/*! Hermitian of a matrix */
struct Ifx_mtxHrmComplexF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    cfloat32 * mtx;  /*!< IN vector[m*n] */
    cfloat32 * hrm;  /*!< OUT vector[n*m] */
    uint32 m;       /*!< IN  number of rows in mtx, number of columns in hrm */
    uint32 n;       /*!< IN  number of columns in matrix, number of rows in hrm */
};
void Ifx_mtxHrmComplexF32_fast (uint32 m, uint32 n, cfloat32 * hrm, cfloat32 * mtx); /*! fast hermitian matrix for 1x8 or 8x1 matrices */
void Ifx_mtxHrmComplexF32_fast1x8 (cfloat32 * hrm, cfloat32 * mtx); /*! fast hermitian matrix */
void Ifx_mtxHrmComplexF32 (struct Ifx_mtxHrmComplexF32State *); /*!< hermitian matrix */

/*! Matrix inversion
 * Radar, sensor fusion
 */
struct Ifx_mtxInvRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * dst;  /*!< OUT vector[n*n] */
    float32 * src;  /*!< IN  vector[n*n], matrix is destroyed during computation */
    uint32 n;       /*!< IN  number of rows/columns in matrix */
};
/*!
        Calculates the Inverse Matrix of the regular Matrix src. dst=src^(-1)
*/
void Ifx_mtxInvRealF32 (struct Ifx_mtxInvRealF32State *);

/*! \brief LUP decomposition
 * For input matrix X, finds L and U matrices such that PX = LU Where P is a permutation matrix.
 * A permutation matrix is a square binary matrix that has exactly one entry 1 in each row and each column and 0s elsewhere.
 * The LUP decomposition makes it easier to solve systems of equations.
 */
struct Ifx_mtxLudRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * mtx;  /*!< INOUT vector[n*n] input and result matrix */
    /* TODO: move n to the back of the argument list */
    uint32 n; /*!< IN number of rows/columns in matrix */
    uint32 * piv; /*!< IN vector[n] pivot table which describes the Permutation matrix. E.g. if piv={1,3,2}, then P={ {1,0,0}, {0,0,1}, {0,1,0} } */
};
void Ifx_mtxLudRealF32 (struct Ifx_mtxLudRealF32State *); /*!< LU-decomposition of matrix */

/*!     \brief LU solve
 *      solve a linear equation based on a LU decomposed matrix
        Solves a linear equation of the type Ax=b where A is a matrix and x and b vectors. Rewrite equation as LUx=Pb. Solve equation Ly=Pb for y then Ux=y for x.
*/
struct Ifx_mtxLusRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    /* TODO: move n to the back of the argument list */
    uint32 n; /*!< IN number of rows/columns in matrix */
    float32 * mtx;  /*!< IN vector[n*n] LU matrix */
    uint32 * piv; /*!< IN vector[n] pivot table */
    float32 * y; /*!< IN vector[n] input vector of equation, destroyed during computation */
    float32 * x; /*!< OUT vector[n] result vector */
};
void Ifx_mtxLusRealF32 (struct Ifx_mtxLusRealF32State *); /*!< solve equation on LU-decomposed matrix */


/*!
	The correlation function describes the relationship between different values of (in this case) vectors x (with length m) and
	y (with length n) at different locations.
*/
struct Ifx_corrRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * r;  /*!< OUT vector[m+n-1] output signal */
    float32 * x;  /*!< IN  vector[m] first input signal */
    float32 * y;  /*!< IN  vector[n] second input signal */
    uint32 m;  /*!< IN  length of first input signal */
    uint32 n;  /*!< IN  length of second input signal */
};

/*! Cross correlation
 * Computes cross correlation in input vector x and vector y. result in vector r
 * In signal processing the correlation function measures the similarity of two waveforms.
 */
void Ifx_corrRealF32 (struct Ifx_corrRealF32State *); /*!< real signal correlation with floating point */


/*! Singular Value Decomposition
 * Of a 2x2 matrix into 3 (2x2) matrices
 * details = US patent 7205932 + on the web
 * New: up to 16x16 matrix
 * Radar
 */
struct Ifx_mtxSvdRealF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    float32 * a; /*!< INOUT vector[m*n] input matrix, output: column orthogonal matrix u */
    float32 * w; /*!< OUT vector[n] diagonal matrix */
    float32 * v; /*!< OUT vector[n*n] orthogonal matrix */
    uint32 m;       /*!< IN  number of rows in matrix */
    uint32 n;       /*!< IN  number of columns in matrix */
};
/*!
        SVD:
        Calculates the Singular Value Decomposition of a Matrix C (not necessarily regular, complex or real).
        C = U * SIGMA * V* .
        U is a unitary matrix (=square complex matrix whose columns are orthogonal to each other).
        SIGMA is a non-square, thus rectangular, diagonal matrix. The diagonal entries are the singular values of the matrix.
        V* is the conjugate transpose of a real or complex unitary matrix V.
*/
void Ifx_mtxSvdRealF32 (struct Ifx_mtxSvdRealF32State *);

 
 /* Kalman filter
 * Motor control,  sensor fusion
 */

/*! The Kalman filter eliminates the disturbance of input signals 
 * to find the statistically optimal signal of the underlying system state. 
 * 
 * x(k) = a*x(k-1) +b*u(k) + w
 *                              where w ~ N(0,q) is gaussian noise with covariance q
 * x = c*y + v
 *              where v r ~ N(0,r) is gaussian noise with covariance r
 */
struct Ifx_kalmanState {
    enum Ifx_mode mode; /*!< IN mode for computation */
    float32 * x;        /*!< INOUT vector[n] system status.9
                         * x(k) = a*x(k-1) +b*u(k) + w where w is the process noise. */
    float32 * a;        /*!< IN vector[n*n] connects previous state with following state (makes prediction). */
    float32 * b;        /*!< IN nector[n*l] that transforms the manual change to fit the system status vector */
    float32 * u;        /*!< IN vector[l] manual change to the system status. */
    float32 * q;        /*!< IN vector[n*n] covariance matrix of w (w: process noise). */
    float32 * y;        /*!< IN vector[m] incoming measurements. x = c*y + v where v is the noise of the measurements */
    float32 * c;        /*!< IN vector[m*n] transforms the measurements to fit the system status vector. */
    float32 * r;        /*!< IN vector[m*m] Covariance matrix of v (v: measurement noise). */
    float32 * p;        /*!< INOUT vector[n*n] Covariance matrix of system noise. */
    uint32 n;           /*!< see above */
    uint32 m;           /*!< see above */
    uint32 l;           /*!< see above */
};
/*! Kalman filter */
void Ifx_kalman (struct Ifx_kalmanState *);
 
/*! @}*/

/*! \addtogroup Matrix_F32_Complex
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * Matrix library (floating point Complex)                              *
 *                                                                      *
\************************************************************************/

/*! Computes the addition of two matrices dst[m][n] = src1[m][n] + src2[m][n] */
void Ifx_mtxAddComplexF32_fast(uint32 m, uint32 n, cfloat32 * dst, cfloat32 * src1, cfloat32 * src2);

/*! Computes the subtraction of two matrices dst[m][n] = src1[m][n] - src2[m][n] */
void Ifx_mtxSubComplexF32_fast(uint32 m, uint32 n, cfloat32 * dst, cfloat32 * src1, cfloat32 * src2);

/*! Scales an F32 complex matrix with a F32 real factor */
void Ifx_mtxScalingComplexF32_fast(uint32 m, uint32 n, float32 scale, cfloat32 * dst, cfloat32 * src);

/*! Matrix multiplication (complex F32) */
struct Ifx_mtxMulComplexF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    cfloat32 * dst;  /*!< OUT vector[m*n], sum */
    cfloat32 * src1; /*!< IN  vector[m*l], first addend */
    cfloat32 * src2; /*!< IN  vector[l*n], second addend */
    uint32 m;       /*!< IN  number of rows in result matrix */
    uint32 n;       /*!< IN  number of columns in result matrix */
    uint32 l;       /*!< IN  number of adjecant rows/columns */
};

/*! Calculates the product of two matrices dst[M][N] = src1[M][L] * src2[L][N] */
void Ifx_mtxMulComplexF32 (struct Ifx_mtxMulComplexF32State * state);
/*! Calculates the product of two matrices dst[M][N] = src1[M][L] * src2[L][N] */
void Ifx_mtxMulComplexF32_asm (struct Ifx_mtxMulComplexF32State * state);

/*! Assembly optimized function calculating the conjugate of a complex matrix dst[M][N] = conj(src[M][N]) */
void Ifx_mtxConjComplexF32_fast(uint32 m, uint32 n, cfloat32 * dst, cfloat32 * src);

/*! @}*/


/*! \addtogroup Matrix_Q15_Real
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * Matrix library (fixed point)                                     	*
 *                                                                      *
\************************************************************************/

/*! Matrix Add and Sub structure */
struct Ifx_mtxRealQ15State {
    sint16 * src1; /*!< IN  vector[m*n] */
    sint16 * src2; /*!< IN  vector[m*n] */
    sint16 * dst;  /*!< OUT vector[m*n], sum (or diff). The result is a matrix which is stored internally as a vector (see row major) */
    uint32 m;       /*!< IN  number of rows in matrix */
    uint32 n;       /*!< IN  number of columns in matrix */
};

/*! Calculates the sum of two matrices dst = src1 + src2 */
void Ifx_mtxAddRealQ15_fast (struct Ifx_mtxRealQ15State * state); 	/*! fast matrix addition 									*/
void Ifx_mtxAddRealQ15_fast4N (struct Ifx_mtxRealQ15State * state); /*! fast matrix addition with nRows*nCols divisible by 4 	*/

/*! Calculates the difference of two matrices dst = src1 - src2 */
void Ifx_mtxSubRealQ15_fast (struct Ifx_mtxRealQ15State * state); 	/*! fast matrix subtraction								 		*/
void Ifx_mtxSubRealQ15_fast4N (struct Ifx_mtxRealQ15State * state); /*! fast matrix subtraction with nRows*nCols divisible by 4 	*/

/*! Calculates the Schur Product of two matrices dst = src1 .* src2 (Element-wise Multiplication) */
void Ifx_mtxSchurRealQ15_fast (struct Ifx_mtxRealQ15State * state);   /*! fast matrix Schur Product								 	*/
void Ifx_mtxSchurRealQ15_fast4N (struct Ifx_mtxRealQ15State * state); /*! fast matrix Schur Product with nRows*nCols divisible by 4 	*/

/*! Matrix-Matrix multiplication	*/
struct Ifx_mtxMulRealQ15State {
    sint16 * src1;  /*! < IN  vector[m*n] */
    sint16 * src2;  /*! < IN  vector[n*k] */
    sint16 * dst;   /*! < OUT vector[m*k], product. The result is a matrix which is stored internally as a vector (see row major) */
    uint32 m;       /*! < IN  number of rows of matrix src1 		*/
    uint32 n;       /*! < IN  number of columns of matrix src1 	*/
    uint32 k;       /*! < IN  number of columns of matrix src2 	*/
};
/*! Calculates the product of two matrices dst = src1 * src2 */
void Ifx_mtxMulRealQ15_fast (struct Ifx_mtxMulRealQ15State * state); 	/*! fast matrix-matrix multiplication */

/*! Matrix-Scalar multiplication	*/
struct Ifx_mtxMulScalarRealQ15State {
    sint16 * src; 	/*! < IN  vector[m*n] */
    sint16 * dst;   /*! < OUT vector[m*n], product. The result is a matrix which is stored internally as a vector (see row major) */
    uint32 m;       /*! < IN  number of rows of matrix src 		*/
    uint32 n;       /*! < IN  number of columns of matrix src 	*/
    sint16 scalar;  /*! < IN  scalar		*/
};
/*! Calculates the product of a matrix with a scalar: dst = src * scalar */
void Ifx_mtxMulScalarRealQ15_fast (struct Ifx_mtxMulScalarRealQ15State * state); 	/*! fast matrix-scalar multiplication */
void Ifx_mtxMulScalarRealQ15_fast8N (struct Ifx_mtxMulScalarRealQ15State * state); 	/*! fast matrix-scalar multiplication with nRows*nCols divisible by 8 	*/

/*! Matrix Transpose	*/
struct Ifx_mtxTransRealQ15State {
    sint16 * src;  /*! < IN  vector[m*n] */
    sint16 * dst;  /*! < OUT vector[m*k], tranposed. The result is a matrix which is stored internally as a vector (see row major) */
    uint32 m;      /*! < IN  number of rows of matrix src 		*/
    uint32 n;      /*! < IN  number of columns of matrix src 	*/
};
/*! Computes the matrix transpose dst = T(src) */
void Ifx_mtxTransRealQ15_fast (struct Ifx_mtxTransRealQ15State * state); 	/*! fast matrix Transpose */

/*! Matrix Window Copy */
struct Ifx_mtxWinCopyRealQ15State {
    sint16 * src;  /*! < IN  vector[m*n] */
    sint16 * dst;  /*! < OUT vector[u*v], sub-matrix. The result is the copy of a sub-matrix contained in matrix src */
    uint32 m;      /*! < IN  number of rows of matrix src 		*/
    uint32 n;      /*! < IN  number of columns of matrix src 	*/
    uint32 u;      /*! < IN  number of rows of matrix dst		*/
    uint32 v;      /*! < IN  number of columns of matrix dst 	*/
    uint32 start;  /*! < IN  copy start index in matrix src		*/
};
/*! Copies a sub-matrix dst contained in matrix src */
void Ifx_mtxWinCopyRealQ15_fast(struct Ifx_mtxWinCopyRealQ15State * state); 	/*! fast matrix window copy */
void Ifx_mtxWinCopyRealQ15_fast2N(struct Ifx_mtxWinCopyRealQ15State * state); 	/*! fast matrix window copy for dst matrix size (both row and column) divisible by 2 */
void Ifx_mtxWinCopyRealQ15_fast4N(struct Ifx_mtxWinCopyRealQ15State * state); 	/*! fast matrix window copy for dst matrix size (both row and column) divisible by 4 */

/*! Computes a 1/4 Matrix Space Reduction */
void Ifx_mtxSpaceReducRealQ15_fast(struct Ifx_mtxTransRealQ15State * state);	/*! for src matrix where Col size divisible by 4 */
void Ifx_mtxSpaceReducRealQ15_fast8N(struct Ifx_mtxTransRealQ15State * state);	/*! 1/4 Matrix Space Reduction for src matrix where Col size divisible by 8 */

/*! @}*/


/*! \addtogroup Filters
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * Filters 								                                *
 *                                                                      *
\************************************************************************/

/*! FIR:
 * A FIR Filter is a digital electronic filter. It executes the calculation
 *   y[n]=sum(from k=0 to k=M) b[k]*x[n-k]
 * where b[k] is the filter-coefficient taken from the array b[] and
 * x[n-k] is one value from the input signal array x[].
 * Depending on the coefficients in b[] it can function as a high-pass filter,
 * low-pass filer, band-pass filter etc...
 */

struct Ifx_firRealQ15State {
    enum Ifx_mode mode; /*!< IN mode for computtypedef struct csint32_t  { sint32  real,imag; } csint32;ation */
    sint16 * y; /*!< OUT vector[n] result */
    sint16 * c; /*!< IN  vector[m] coeffients. The coefficients decide  */
    sint16 * x; /*!< IN  vector[n] input signal */
    sint16 * s; /*!< INOUT vector[m-1] intermediate state */
    uint32 m;   /*!< IN  number of coefficients */
    uint32 n;   /*!< IN  number of samples in input signal */
};

/*! real FIR filter on Q31 fixed-point values */
struct Ifx_firRealQ31State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    sint32 * y; /*!< OUT vector[n] result */
    sint32 * c; /*!< IN  vector[m] coeffients */
    sint32 * x; /*!< IN  vector[n] input signal */
    sint32 * s; /*!< INOUT vector[m-1] intermediate state */
    uint32 m;   /*!< IN  number of coefficients */
    uint32 n;   /*!< IN  number of samples in input signal */
};

/*! complex FIR filter on Q15 fixed-point data */
struct Ifx_firComplexQ15State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    csint16 * y; /*!< OUT vector[n] result */
    csint16 * c; /*!< IN  vector[m] coeffients */
    csint16 * x; /*!< IN  vector[n] input signal */
    csint16 * s; /*!< INOUT vector[m-1] intermediate state */
    uint32 m;   /*!< IN  number of coefficients */
    uint32 n;   /*!< IN  number of samples in input signal */
};

/*! complex FIR filter on Q31 fixed-point data */
struct Ifx_firComplexQ31State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    csint32 * y; /*!< OUT vector[n] result */
    csint32 * c; /*!< IN  vector[m] coeffients */
    csint32 * x; /*!< IN  vector[n] input signal */
    csint32 * s; /*!< INOUT vector[m-1] intermediate state */
    uint32 m;   /*!< IN  number of coefficients */
    uint32 n;   /*!< IN  number of samples in input signal */
};

/*! FIR filter n Tap; coefficients in RAM
 * Real FIR Complex FIR
 * Operand length is multiple of 2
 * \brief FIR filter
 */
void Ifx_firRealQ15 (struct Ifx_firRealQ15State *);
void Ifx_firRealQ31 (struct Ifx_firRealQ31State *); /*!< real FIR on Q31 fixed-point data */
void Ifx_firComplexQ15 (struct Ifx_firComplexQ15State *); /*!< complex FIR on Q15 fixed-point data */
void Ifx_firComplexQ31 (struct Ifx_firComplexQ31State *); /*!< complex FIR on Q31 fixed-point data */

struct Ifx_iirRealQ15State {
    enum Ifx_mode mode; /*!< IN mode for computation typedef struct csint32_t  { sint32  real,imag; } csint32; */
    sint16 * y; /*!< OUT vector[n] result */
    sint16 * a; /*!< IN  vector[m] alpha coeffients. */
    sint16 * b; /*!< IN  vector[m] beta coeffients. */
    sint16 * x; /*!< IN  vector[n] input signal */
    sint16 * s; /*!< INOUT vector[m-1] intermediate state */
    uint32 m;   /*!< IN  number of coefficients */
    uint32 n;   /*!< IN  number of samples in input signal */
};

void Ifx_iirRealQ15 (struct Ifx_iirRealQ15State *);

/*! FIR filter Q15 format
* \param[in] x vector[n] input signal
* \param[out] y vector[n] result
* \param[in] c vector[m] coefficients
* \param[in,out] s vector[m-1] intermediate state
* \param[in] n number of samples in input signal
 */
void Ifx_firRealQ15_fast(
                sint16 *    x,
                sint16 *    y,
                Ifx_CircularBuffer c,
                Ifx_CircularBuffer * s,
                uint32      n
                );



/*! IIR biquad filter Q15 format, 5 coefficients per biquad
* \param[in] x vector[nX] input signal
* \param[out] y vector[nX] result
* \param[in] c vector[5*nBiq] coefficients
* \param[in,out] d vector[2*nBiq] delay line
* \param[in] nBiq number of biquads
* \param[in] nX number of samples in input signal
 */
void Ifx_iirRealQ15_fast(
                sint16 *    x,
                sint16 *    y,
                sint16 *	c,
                sint16 *	d,
                uint32      nBiq,
                uint32      nX
                );


/*! complex FIR filter on 32-bit IEEE floating point values */
struct Ifx_firComplexF32State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    cfloat32 * y; /*!< OUT vector[n] result */
    cfloat32 * c; /*!< IN  vector[m] coeffients */
    cfloat32 * x; /*!< IN  vector[n] input signal */
    cfloat32 * s; /*!< INOUT vector[m-1] intermediate state */
    uint32 m;   /*!< IN  number of coefficients */
    uint32 n;   /*!< IN  number of samples in input signal */
};

/*! FIR filter n Tap
 * Complex FIR
 * Operand length is multiple of 2
 */
void Ifx_firComplexF32 (struct Ifx_firComplexF32State *); /*!< complex FIR filter */


/*! real FIR on 32-bit IEEE floating point data */
struct Ifx_firRealF32State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    float32 * y; /*!< OUT vector[n] result */
    float32 * c; /*!< IN  vector[m] coeffients */
    float32 * x; /*!< IN  vector[n] input signal */
    float32 * s; /*!< INOUT vector[m-1] intermediate state */
    uint32 m;   /*!< IN  number of coefficients */
    uint32 n;   /*!< IN  number of samples in input signal */
};
 
 /*! FIR filter n Tap
 * Real FIR 
 * Operand length is multiple of 2
 */
void Ifx_firRealF32 (struct Ifx_firRealF32State *); /*!< real FIR filter */

/*! Real FIR on 32-bit IEEE floating point data with the previous data */
struct Ifx_firRealF32AudioState {
    enum Ifx_mode mode; /*!< IN mode for computation */
    float32 * y; /*!< OUT vector[n] result */
    float32 * c; /*!< IN  vector[m] coefficients */
    float32 * x; /*!< IN  vector[n] input signal */
    float32 * p; /*!< IN vector[m-1] previous input */
    uint32 m;   /*!< IN  number of coefficients */
    uint32 n;   /*!< IN  number of samples in input signal */
};
void Ifx_firRealF32Audio (struct Ifx_firRealF32AudioState *); /*!< real FIR filter taking account previous data */


/*! @}*/


/*! \addtogroup Vector
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * Vector                              									*
 *                                                                      *
\************************************************************************/

/*! finds max value in array and the index of this value
* \param[in] X pointer to input vector[n] components
* \param[in] nX number of samples in vector (nX >= 4)
* \param[in] pos Pointer to variable which stores position of max value
* \param[out] pos Index of max value [first element = position 0, second = position 1, ...]
* \return  max value
 */
sint16 Ifx_maxposRealQ15(sint16 *X, uint16 nX, uint16 *pos );


/*! finds max value in array
* \param[in] x vector[n] input
* \param[in] n number of samples in vector
* \return  max value
 */
sint16 Ifx_maxRealQ15(
                sint16* x,
                uint32 n);


/*! finds min value in array
* \param[in] X pointer to input vector[n] components
* \param[in] nX number of samples in vector (nX >= 4)
* \param[in] pos Pointer to variable which stores position of min value
* \param[out] pos Index of min value [first element = position 0, second = position 1, ...]
* \return  min value
 */
sint16 Ifx_minposRealQ15(sint16 *X, uint16 nX, uint16 *pos );


/*! finds min value in array and the index of this value
* \param[in] x vector[n] input
* \param[in] n number of samples in vector
* \return  min value
 */
sint16 Ifx_minRealQ15(
                sint16* x,
                uint32 n);


/*! Windowing Function on Q31 fixed-point data */
struct Ifx_windowApplyQ31State {
	enum Ifx_mode mode;               /*!< IN mode for computation */
    csint32 * x;                      /*!< IN vector [n] Complex Vector on which window coefficients should be applied */
    csint32 * y;                      /*!< OUT vector[n] Complex Result Vector */
    sint32 * w;                       /*!< IN vector[n/2] Real Vector of window coefficients  */
    uint32 n;                         /*!< IN  full window length */
};

void
Ifx_windowApplyQ31a (struct Ifx_windowApplyQ31State * state);  /*!< complex windowing on Q31 fixed-point data */


/*! Windowing Function on F32 fixed-point data */
struct Ifx_windowApplyF32State {
	enum Ifx_mode mode;           /*!< IN mode for computation */
    cfloat32 * x;                 /*!< IN vector [n] Complex Vector on which window coefficients should be applied */
    cfloat32 * y;                 /*!< OUT vector[n] Complex Result Vector */
    float32 * w;                  /*!< IN vector[n/2] Real Vector of window coefficients  */
    uint32 n;                     /*!< IN  full window length */
};

void Ifx_windowApplyF32_fast (struct Ifx_windowApplyF32State * state); /*!< complex windowing on F32 complex data */


/*!< component-wise complex absolute value of vector */
struct Ifx_cabsQ15State {
    enum Ifx_mode mode;   /*!< IN  Not used in this implementation */
    sint16 * dst;         /*!< OUT vector[n] destination of absolute values */
    csint16 * src;        /*!< IN  vector[n] source of complex values */
    uint32 n;             /*!< IN  number of elements in vector */
};


void Ifx_cabsQ15 (struct Ifx_cabsQ15State *); /*!< component-wise complex absolute value of vector */

/*!
 * absolute function Q15 format
 * \param[in]  x 16 bit (1Q15)
 * \return absolute value in 1Q15
 */
sint16 Ifx_AbsQ15(sint16 X);


/*! computes the sum of a vector of Q15 values */
struct Ifx_sumRealQ15State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    sint16 y;   /*!< OUT result */
    sint16 * x; /*!< IN  vector[n] input*/
    uint32 n;   /*!< IN  number of samples in vector */
};


/*! sum a vector of Q31 fixed-point data */
struct Ifx_sumRealQ31State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    sint32 y;   /*!< OUT result */
    sint32 * x; /*!< IN  vector[n] input */
    uint32 n;   /*!< IN  number of samples in vector */
};


/*! Sum
 * Computes the sum of a collection of samples; (real or complex)
 * For average / threshold computation
 */
void Ifx_sumRealQ15 (struct Ifx_sumRealQ15State *); /*!< sum of vector of Q15 fixed-point data */
void Ifx_sumRealQ31 (struct Ifx_sumRealQ31State *); /*!< sum of vector of Q31 fixed-point data */

/*! \brief average of Q15 vector, fixed point result */
struct Ifx_vecAvgQ15State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    uint32 n; /*!< IN number of elements in vector */
    sint16 * x; /*!< IN vector[n] input vector */
    sint16_least avg; /*!< OUT average value */
};
extern sint16 Ifx_vecAvgQ15_fast(uint16_least n, sint16 * x); /*! fast vector average of Q15 vector */
void Ifx_vecAvgQ15(struct Ifx_vecAvgQ15State *); /*! fast vector average of Q15 vector */

/*! \brief average of Q15 vector, floating point result */
struct Ifx_vecAvgQ15F32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    uint32 n; /*!< IN number of elements in vector */
    sint16 * x; /*!< IN vector[n] input vector */
    float32 avg; /*!< OUT average value */
};
extern float32 Ifx_vecAvgQ15F32_fast(uint16_least n, sint16 * x);
void Ifx_vecAvgQ15F32(struct Ifx_vecAvgQ15F32State *);

/*! \brief absolute value of Q15 vector */
struct Ifx_vecAbsQ15F32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    uint32 n; /*!< IN number of elements in vector */
    sint16 * x; /*!< IN vector[n] input vector */
    float32 abs; /*!< OUT absolute value */
};
extern float32 Ifx_vecAbsQ15F32_fast(uint16_least n, sint16 *x); 
void Ifx_vecAbsQ15F32(struct Ifx_vecAbsQ15F32State *);

/*! dot product of two Q15 vectors with F32 result */
struct Ifx_vecDotQ15F32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    uint32 n; /*!< IN number of elements in vector */
    sint16 * x; /*!< IN vector[n] input vector */
    sint16 * y; /*!< IN vector[n] input vector */
    float32 dot; /*!< OUT dot product */
};
extern float32 Ifx_vecDotQ15F32_fast(uint16_least n, sint16 *x, sint16 *y);
void Ifx_vecDotQ15F32(struct Ifx_vecDotQ15F32State *);

/*! dot product of two Q15 vectors with Q15 result */
struct Ifx_vecDotQ15State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    uint32 n; /*!< IN number of elements in vector */
    sint16 * x; /*!< IN vector[n] input vector */
    sint16 * y; /*!< IN vector[n] input vector */
    uint32 shift; /*!< IN shift amount */
    sint32 dot; /*!< OUT dot product */
};
extern sint32 Ifx_vecDotQ15_fast(uint16_least n, sint16 *x, sint16 *y, uint16_least shift);
void Ifx_vecDotQ15(struct Ifx_vecDotQ15State *);

/*! variance (sigma) of Q15 vector */
struct Ifx_vecSigmaQ15F32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    uint32 n; /*!< IN number of elements in vector */
    sint16 * x; /*!< IN vector[n] input vector */
    uint32 adj; /*!< IN adjustment factor. Use 0 to obtain the population variance, use 1 for sample variance */
    float32 sigma; /*!< OUT sigma */
    float32 avg; /*!< OUT average */
};
float32 Ifx_vecSigmaQ15F32_fast(uint16_least n, sint16 *v, uint16_least adj, float32 * pAvg);
void Ifx_vecSigmaQ15F32(struct Ifx_vecSigmaQ15F32State *);


/* correlation
 * Computes the correlation of the arrays x and y. result is in array r.
 * Sensor fusion
 */
/*! Cross correlation
 * Computes cross correlation in input vector x and vector y. result in vector r
 */
struct Ifx_corrRealQ15State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    sint16 * r;  /*!< OUT vector[m+n-1] output signal */
    sint16 * x;  /*!< IN  vector[m] first input signal */
    sint16 * y;  /*!< IN  vector[n] second input signal */
    uint32 m;  /*!< IN  length of first input signal */
    uint32 n;  /*!< IN  length of second input signal */
};

/*! signal correlation on real vector with Q31 fixed-point data */
struct Ifx_corrRealQ31State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    sint32 * r;  /*!< OUT vector[m+n-1] output signal */
    sint32 * x;  /*!< IN  vector[m] first input signal */
    sint32 * y;  /*!< IN  vector[n] second input signal */
    uint32 m;  /*!< IN  length of first input signal */
    uint32 n;  /*!< IN  length of second input signal */
};

void Ifx_corrRealQ15 (struct Ifx_corrRealQ15State *); /*!< signal correlation of real signal in Q15 fixed-point */
void Ifx_corrRealQ31 (struct Ifx_corrRealQ31State *); /*!< signal correlation of real signal in Q31 fixed-point */



/*! @}*/


/*! \addtogroup FFT
 *  @{
 */
/************************************************************************\
 *                                                                      *
 * FFT                              									*
 *                                                                      *
\************************************************************************/
/*! real FFT on 32-bit floating point values */
struct Ifx_fftRealF32State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    cfloat32 * y; /*!< OUT vector[n] result */
    float32 * x; /*!< IN  vector[n] input */
    uint32 n;   /*!< IN  number of samples in vector */
};
/*! complex FFT on 32-bit IEEE float data */
struct Ifx_fftComplexF32State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    cfloat32 * y; /*!< OUT vector[n] result */
    cfloat32 * x; /*!< IN  vector[n] input */
    uint32 n;   /*!< IN  number of samples in vector */
};

/*! FFT n points Out of place
 * Real FFT  Complex FFT
 * n is power of 2
 * radar; powertrain
 */
void Ifx_fftRealF32 (struct Ifx_fftRealF32State *); /*!< real FFT */
void Ifx_fftComplexF32 (struct Ifx_fftComplexF32State *); /*!< complex FFT */


/*!< Complex FFT on Q31 fixed-point data */
struct Ifx_fftComplexQ31aState {
    enum Ifx_mode mode; /*!< IN mode for computation */
    csint32 * r;        /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint32 * x;        /*!< IN  vector[n] input. Values of signal */
	csint32 * tf;       /*!< IN  vector[n] input. Twiddle factors */
    uint32 n;           /*!< IN  number of samples in vector */
    uint32 sf;          /*!< OUT  scale factor by which output is scaled down */
};
void Ifx_fftComplexQ31a (struct Ifx_fftComplexQ31aState * state); /*!< complex FFT on Q31 fixed-point data */

/*!
        Definition of structures for FFT (explanation see below)
*/

struct Ifx_fftRealQ15State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    csint16 * y; /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x)*/
    sint16 * x; /*!< IN  vector[n] input. Values of signal*/
    uint32 n;   /*!< IN  number of samples in vector */
};



/*! real FFT on 32-bit fixed-point Q31 data */
struct Ifx_fftRealQ31State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    sint32 * y; /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    sint32 * x; /*!< IN  vector[n] input. Values of signal */
    uint32 n;   /*!< IN  number of samples in vector */
};

/*! complex FFT on Q15 fixed-point data */
struct Ifx_fftComplexQ15State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    csint16 * y; /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint16 * x; /*!< IN  vector[n] input. Values of signal */
    uint32 n;   /*!< IN  number of samples in vector */
};


/*! complex FFT on Q31 data */
struct Ifx_fftComplexQ31State {
    enum Ifx_mode mode; /*!< IN mode for computation */
    csint32 * y; /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint32 * x; /*!< IN  vector[n] input. Values of signal */
    uint32 n;   /*!< IN  number of samples in vector */
};

/* FFT n points Out of place; coefficients in RAM
 * Real FFT  Complex FFT
 * n is power of 2
 */

/*! FFT:
 * An FFT (Fast Fourier Transform) calculates the frequency spectrum of a signal,
 * as a signal usually consists of many different periodic functions with different frequencies.
 * It is a computationally efficient discrete Fourier transform (DFT).
*/

void Ifx_fftRealQ15 (struct Ifx_fftRealQ15State *); /*!< real FFT on Q15 fixed-point data */
void Ifx_fftRealQ31 (struct Ifx_fftRealQ31State *); /*!< real FFT on Q31 fixed-point data */
void Ifx_fftComplexQ15 (struct Ifx_fftComplexQ15State *); /*!< complex FFT on Q15 fixed-point data */
void Ifx_fftComplexQ31 (struct Ifx_fftComplexQ31State *); /*!< complex FFT on Q31 fixed-point data */


/* High performance variants of  Ifx_fftCOmplexQ15 with predefined sizes for best optimization */

void Ifx_fftComplexQ15_16hp( /*!< complex FFT Radix-4 size 16 on Q15 fixed-point data */
    csint16 * y, /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint16 * x  /*!< IN  vector[n] input. Values of signal, will be overwritten */
);

void Ifx_fftComplexQ15_32hp( /*!< complex FFT Radix-4  size 32 on Q15 fixed-point data */
    csint16 * y, /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint16 * x  /*!< IN  vector[n] input. Values of signal, will be overwritten */
);

void Ifx_fftComplexQ15_64hp( /*!< complex FFT Radix-4  size 64 on Q15 fixed-point data */
    csint16 * y, /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint16 * x  /*!< IN  vector[n] input. Values of signal, will be overwritten */
);

void Ifx_fftComplexQ15_128hp( /*!< complex FFT Radix-4 size 128 on Q15 fixed-point data */
    csint16 * y, /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint16 * x  /*!< IN  vector[n] input. Values of signal, will be overwritten */
);

void Ifx_fftComplexQ15_256hp( /*!< complex FFT Radix-4  size 256 on Q15 fixed-point data */
    csint16 * y, /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint16 * x  /*!< IN  vector[n] input. Values of signal, will be overwritten */
);

void Ifx_fftComplexQ15_512hp( /*!< complex FFT Radix-4  size 512 on Q15 fixed-point data */
    csint16 * y, /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint16 * x  /*!< IN  vector[n] input. Values of signal, will be overwritten */
);

void Ifx_fftComplexQ15_1024hp( /*!< complex FFT Radix-4 size 1024 on Q15 fixed-point data */
    csint16 * y, /*!< OUT vector[n] result. Frequency spectrum (FFT of vector x) */
    csint16 * x  /*!< IN  vector[n] input. Values of signal, will be overwritten */
);


/*! Minimum; maximum
 * Finds the indexes of the points below or above a threshold
 * FFT peak detection
 */
struct Ifx_fftPeakDetectComplexQ15State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    csint16 * dst; /*!< OUT vector[n] destination signal (FFT of source) */
    csint16 * src; /*!< IN  vector[n] source signal */
    uint32 n; /*!< IN  vector length n */
    uint32 m; /*!< IN  number of peaks detected by algorithm */
    csint16 * peak_val; /*!< OUT vector[m] square absolute values of detected peaks */
	sint16 * val; /*! < buffer memory of peak_val */
    uint32 * peak_idx; /*!< OUT vector[m] indices of detected peaks */
	uint32 * idx; /*! < buffer memory of peak_idx */
};
void Ifx_fftPeakDetectComplexQ15 (struct Ifx_fftPeakDetectComplexQ15State *); /*!< FFT with peak detection */

/*! @}*/

/*! \addtogroup image
 *  @{
 */

/************************************************************************\
 *                                                                      *
 * Image processing library (fractional)                                *
 *                                                                      *
\************************************************************************/

/*! image BINARIZATION:
 * The Image Binarization program changes a picture from levels of grey to black/white.
 * If the level of grey of a picture is higher than the threshold, it is changed to black,
 * otherwise to white.
 */
//struct Ifx_imgBinarizationState {
//    enum Ifx_mode mode;   /*!< IN mode for computation */
//    uint8 * dst;     /*!< OUT vector[m*n] destination image (8 bits per byte) */
//    sint16 * src;    /*!< IN  vector[m*n] source image */
//    uint32 m;        /*!< IN  width of image */
//    uint32 n;        /*!< IN  height of image */
//    sint16 threshold; /*!< IN  threshold value */
//};
//void Ifx_imgBinarization (struct Ifx_imgBinarizationState *); /*!< image binarization */
//
///* Gausian Blur */
///*!
//	The result of blurring an image by a Gaussian function is called Guassian blur.
//	It is used to reduce image noise and reduce detail. The transformation is applied
//	to each pixel in the image. In this case the Gaussian function is two dimensional.
//*/
//
//struct Ifx_imgGaussBlurState {
//    enum Ifx_mode mode;   			/*!< IN mode for computation */
//    sint16 * dst;    				/*!< OUT vector[m*n] destination image; resulting image after applying the Gaussian function */
//    sint16 * src;    				/*!< IN  vector[m*n] source image; image to be Gaussian blured */
//    uint32 m;        				/*!< IN  width of image */
//    uint32 n;        				/*!< IN  height of image */
//    float32 sigma;     				/*!< IN  gauss sigma value, which is the standard deviation of the Gaussian distribution and also
//                                             determines the size of the kernel*/
//};
//void Ifx_imgGaussBlur (struct Ifx_imgGaussBlurState *); /*!< image gaussian blur */
//
///* Prewitt */
//
///*!
//	The Prewitt-Operator detects edges, similar to the Sobel operator. It computes an approximation of the gradient of the image intensity input sint16 * src.
//	The result is an image which finally shows the edges of the source image.
//*/
//
//struct Ifx_imgPrewittState {
//    enum Ifx_mode mode;   /*!< IN mode for computation */
//    sint16 * dst;     /*!< OUT vector[m*n] destination image */
//    sint16 * src;    /*!< IN  vector[m*n] source image */
//    uint32 m;        /*!< IN  width of image */
//    uint32 n;        /*!< IN  height of image */
//};
//void Ifx_imgPrewitt (struct Ifx_imgPrewittState *); /*!< image Rewitt filter */
//
///*! image convolution with 3x3 matrix */
//struct Ifx_imgConvState {
//    enum Ifx_mode mode;   /*!< IN mode for computation */
//    sint16 * dst;    /*!< OUT vector[m*n] destination image */
//    sint16 * src;    /*!< IN  vector[m*n] source image */
//    uint32 m;        /*!< IN  width of image */
//    uint32 n;        /*!< IN  height of image */
//    sint16 * kernel; /*!< IN  vector[3*3] filter kernel 3x3 */
//};
//
///*! 2D convolution with 3x3 kernel
// * 2D convolution on MxN input image using a 3x3 kernel
// * Entry ADAS
// */
//void Ifx_imgConv (struct Ifx_imgConvState *);
//
///* Sobel 3x3 filter
// * Sobel filter on MxN input image
// * Entry ADAS
// */
// /*! Definition of Structure for the Sobel-Filter (explanation see below) */
//struct Ifx_imgSobel3x3Q15State {
//    enum Ifx_mode mode;   /*!< IN mode for computation */
//    csint16 * dst;    	  /*!< OUT vector[m*n] gradient in x,y direction */
//    sint16 * src;    	  /*!< IN  vector[m*n] source image */
//    uint32 m;        	  /*!< IN  width of image */
//    uint32 n;        	  /*!< IN  height of image */
//};
///*!
//        SOBEL:
//        A Sobel filter detects edges in a picture. Sobel3x3Horz uses a 3x3 matrix for detecting vertical edges by moving
//        the matrix horizontally over the picture. Sobel3xVert uses a 3x3 matrix for detecting horizontal edges by moving
//        the matrix vertically over the picture.
//*/
//void Ifx_imgSobel3x3Q15 (struct Ifx_imgSobel3x3Q15State *);
//
///*! Sobel 3x3 horizontal filter
// * Sobel horizontal filter on MxN input image
// * Entry ADAS
// */
//struct Ifx_imgSobel3x3HorzQ15State {
//    enum Ifx_mode mode;   /*!< IN mode for computation */
//    sint16 * dst;    /*!< OUT vector[m*n] gradient in horizontal (x) direction */
//    sint16 * src;    /*!< IN  vector[m*n] source image */
//    uint32 m;        /*!< IN  width of image */
//    uint32 n;        /*!< IN  height of image */
//};
//void Ifx_imgSobel3x3HorzQ15 (struct Ifx_imgSobel3x3HorzQ15State *); /*!< 3x3 horizontal Sobel filter */
//
//
///*! Sobel 3x3 vertical filter
// * Sobel vertical filter on MxN input image
// * Entry ADAS
// */
//struct Ifx_imgSobel3x3VertQ15State {
//    enum Ifx_mode mode;   /*!< IN mode for computation */
//    sint16 * dst;    /*!< OUT vector[m*n] gradient in vertical (y) direction */
//    sint16 * src;    /*!< IN  vector[m*n] source image */
//    uint32 m;        /*!< IN  width of image */
//    uint32 n;        /*!< IN  height of image */
//};
//void Ifx_imgSobel3x3VertQ15 (struct Ifx_imgSobel3x3VertQ15State *); /*!< 3x3 horizontal Sobel filter */


#if HAVE_STDIO

/* CIF low level driver
 * Image capture in double buffer
 * Image capture with 3 data paths in double buffers:
 *  + 1 entire image;
 *  + 1 lower half image;
 *  + 1 entire image in MJPEG)
 */

/*! write Q15 data to monochrome image */
void Ifx_bmpWriteQ15 (FILE *, sint16 * data, uint32 width, uint32 height);
/*! write binary data to black/white image */
void Ifx_bmpWriteB (FILE *, uint8 * data, uint32 width, uint32 height);
/*! write RGB color image */
void Ifx_bmpWriteRGB (FILE *, uint8 * data, uint32 width, uint32 height);

/*! read monochrome image to Q15 vector */
void Ifx_bmpReadQ15 (FILE *, sint16 ** data, uint32 * width, uint32 * height);

#endif /* HAVE_STDIO */

/*! @}*/

/*! \addtogroup statistic_sorting
 *  @{
 */

/*! finds median of array \n
 * In case x has even number of elements and data is sorted:\n
 * median = (x[(n/2)-1]+x[n/2])/2 \n
 * In case has odd number of elements and data is sorted:\n
 * median = x[n/2]\n
 * \param[in] x vector of size n input
 * \param[in] n number of samples in vector
 * \return  median value
 */
float32
Ifx_medianRealF32(
		        float32 * x,
		        uint32 n
		        );


/*! sort the input in x array in increasing order
* \param[in,out] x vector[n] input/output
* \param[in] n number of samples in vector x
 */
void
Ifx_qsortF32 (
		   float32 *x,
		   uint32 n
		   );
/*! @}*/


/*! square of the absolute value of complex number */
#define IFX_SQR_ABS_CF32(X) (IFX_SQR_F32((X).real)+IFX_SQR_F32((X).imag))
/*! initializing of a complex variable */
#define IFX_INIT_CF32(X,R,I) do { \
    (X).real = (R); \
    (X).imag = (I); \
} while(0)
/*! multiply a complex number in float32 by a real scalar*/
#define IFX_S_CMUL_F32(RES,C,S) do { \
    (RES).real = (C).real * (S); \
    (RES).imag = (C).imag * (S); \
} while(0)
/*! dividing a complex number in float32 by a real scalar*/
#define IFX_S_CDIV_F32(RES,C,S) do { \
    (RES).real = (C).real / (S); \
    (RES).imag = (C).imag / (S); \
} while(0)
/*! multiply two complex numbers in float32, by initially conjugating the first one */
#define IFX_CMUL_CONJ_F32(RES,C1,C2) do { \
    (RES).real = (C1).real * (C2).real + (C1).imag * (C2).imag; \
    (RES).imag = (C1).real * (C2).imag - (C1).imag * (C2).real; \
} while(0)
/*! swap two complex numbers with the help of a third */
#define IFX_SWAP_CF32(C1,C2,A) do { \
    (A).real= (C1).real; \
    (A).imag= (C1).imag; \
    (C1).real= (C2).real; \
    (C1).imag= (C2).imag; \
    (C2).real= (A).real; \
    (C2).imag= (A).imag; \
} while(0)

struct Ifx_mtxSvdComplexF32State {
    enum Ifx_mode mode;   /*!< IN mode for computation */
    cfloat32 * a; /*!< INOUT vector[m*n] input matrix, output: column orthogonal matrix u */
    float32 * w;  /*!< OUT vector[n] diagonal matrix */
    cfloat32 * v; /*!< OUT vector[n*n] orthogonal matrix */
    uint32 m;       /*!< IN  number of rows in matrix */
    uint32 n;       /*!< IN  number of columns in matrix */
};

/*!
        SVD:
        Calculates the Singular Value Decomposition of a Matrix C (not necessarily regular, complex or real).
        C = U * SIGMA * V* .
        U is a unitary matrix (=square complex matrix whose columns are orthogonal to each other).
        SIGMA is a non-square, thus rectangular, diagonal matrix. The diagonal entries are the singular values of the matrix.
        V* is the conjugate transpose of a real or complex unitary matrix V.
*/
void Ifx_mtxSvdComplexF32 (struct Ifx_mtxSvdComplexF32State *);


#endif /* IFX_DSPLIB_H */


