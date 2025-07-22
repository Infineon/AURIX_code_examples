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
/*! \file Ifx_acosF32.c
 *
 * \brief compute arcus cosine of argument
 *
 * \a Ifx_acosF32 function compute the inverse of the cosine function.
 *
 * IN and OUT in rad, IN range [-1,1]
 *
 */

#include "dsplib-internal.h"

static float32
Ifx_acosF32_ref (float32 x)
{
    float32 result;
    enum Ifx_mode mode = IFX_MODE_REFERENCE_IMPLEMENTATION;

    if (x < -1.0f || 1.0f < x) {
        Ifx_error (IFX_ERR_ERROR,
                   "acos(%g): argument out of range [-1;1]\n", x);
        result = IFX_NAN;
    } else
        result = IFX_M_PI_2 - Ifx_asinF32 (x, mode);

    return result;
}

static float32
Ifx_acosF32_optimizedC (float32 x)
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
		result = 0.0f;
		return result;
	}
	
    if (x<1.0f) {

    	/* now, we can assume x : [0,1[ */
    	idx = (int)(x*(float32)IFX_ASIN_TABLE_N);
    	a = Ifx_asinTableF32 [idx].a;
    	b = Ifx_asinTableF32 [idx].b;
        result = a*x + b;

    	/* apply sign */
    	result = IFX_COPYSIGN_F32(result,sign);
        
        /* make acos from asin */
    	result = IFX_M_PI_2 - result;
    } else {
        Ifx_error (IFX_ERR_ERROR,
                   "acos(%g): argument out of range [-1;1]\n", x);
        result = IFX_NAN;
    }

    return result;
}


float32
Ifx_acosF32 (float32 x, enum Ifx_mode mode)
{
    switch (mode) {
#if IFX_TRICORE_TARGET
    case IFX_MODE_OPTIMIZED_ASM:
        return Ifx_acosF32_fast (x);
#endif /* IFX_TRICORE_TARGET */
    case IFX_MODE_OPTIMIZED_C:
        return Ifx_acosF32_optimizedC (x);
# if HAVE_LIBM
    case IFX_MODE_EXTERNAL_LIBRARY:
        return acosf (x);
# endif /* HAVE_LIBM */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        return Ifx_acosF32_ref (x);
    default:
        Ifx_warnAboutUnimplementedMode (mode, "acosF32");
        return Ifx_acosF32_ref (x);
    }
}
