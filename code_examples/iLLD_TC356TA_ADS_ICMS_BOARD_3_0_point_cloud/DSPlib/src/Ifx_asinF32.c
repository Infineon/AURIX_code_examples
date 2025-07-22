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
/*! \file Ifx_asinF32.c
 *
 * \brief compute arcus sine of argument
 *
 * \a Ifx_asinF32 function compute the inverse of the sine function.
 *
 * IN and OUT in rad, IN range [-1,1]
 *
 */

#include "dsplib-internal.h"

static float32
Ifx_asinF32_ref (float32 x)
{
    uint32 i;
    float32 result;

    if(x==0)
    	return 0.0f;

    if (x < -1.0f || 1.0f < x) {
        Ifx_error (IFX_ERR_ERROR,
                   "asin(%g): argument out of range [-1;1]\n", x);
        result = IFX_NAN;
    } else {
        float32 term = x;
        result = x;
        for (i=3; term/(float32)i/result>=FLT_EPSILON; i+=2) {
            term *= ((float32)(i-2)/(float32)(i-1)*x*x);
            result += (term/i);
        }
    }
    return result;
}

static float32
Ifx_asinF32_optimizedC (float32 x)
{
    float32 result, sign = 1.0f;
    float32 a,b;
    uint32 idx;

    /* make result positive */
    if (x<0.0f) {
        sign = -sign;
        x = -x;
    }
	
	/* case x = 1 */
	if (x==1.0f) {
		result = IFX_M_PI_2;
		return result;
	}

    if (x<1.0f) {
		/* now, we can assume x : [0,1[ */
		idx = (int)(x*(float32)IFX_ASIN_TABLE_N); 
		a = Ifx_asinTableF32[idx].a;
		b = Ifx_asinTableF32[idx].b;
		result = a*x + b;

		/* apply sign */
		result = IFX_COPYSIGN_F32(result,sign);
    } else {
        Ifx_error (IFX_ERR_ERROR,
                   "asin(%g): argument out of range [-1;1]\n", x);
        result = IFX_NAN;
    }
    
    return result;
}


float32
Ifx_asinF32 (float32 x, enum Ifx_mode mode)
{
    switch (mode) {
#if IFX_TRICORE_TARGET
    case IFX_MODE_OPTIMIZED_ASM:
        return Ifx_asinF32_fast (x);
#endif /* IFX_TRICORE_TARGET */
    case IFX_MODE_OPTIMIZED_C:
        return Ifx_asinF32_optimizedC (x);
# if HAVE_LIBM
    case IFX_MODE_EXTERNAL_LIBRARY:
        return asinf (x);
# endif /* HAVE_LIBM */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        return Ifx_asinF32_ref (x);
    default:
        Ifx_warnAboutUnimplementedMode (mode, "asinF32");
        return Ifx_asinF32_ref (x);
    }
}
