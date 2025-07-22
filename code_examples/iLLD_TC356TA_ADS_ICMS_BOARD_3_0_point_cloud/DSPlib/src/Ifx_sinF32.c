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
/*! \file Ifx_sinF32.c
 *
 * \brief sine function
 *
 * Calculates the sine of a value
 * IN and OUT in rad
 *
 */

#include "dsplib-internal.h"

# define HAVE_LIBM 1

static float32
Ifx_sinF32_ref (float32 x)
{
	uint32 i;
    float32 result, term;
	
	if(x==0)
		return 0.0f;
		
	/* bring result into range [-pi;pi] */
	x = fmodf (x, IFX_M_2PI);
	result=x;
	term=x;
	for (i=3; IFX_ABS_F32(term/result) >= IFX_FLT_EPSILON; i+=2) {
		term *= -1.0f*x*x/(float32)i/(float32)(i-1);
		result += term;
	}
	return result;
}

//original function, adapted for new input range
static float32 
Ifx_sinF32_optimizedC(float32 x) 
{
	float32 result, sign = 1.0f;
	float32 a, b;
	uint32 idx;

	// Using period 2pi - put input value into [-pi - pi]
	if (x > IFX_M_PI) {
		/* 0.15915f = 1/(2pi) */
		x = x - (int) ((x + IFX_M_PI) * 0.1591549430918f) * IFX_M_2PI;
	} else if (x < -IFX_M_PI) {
		x = x - (int) ((x - IFX_M_PI) * 0.1591549430918f) * IFX_M_2PI;
	}

	// make result positive - put value into [0 - pi]
	if (x < 0.0f) {
		sign = -sign;
		x = -x;
	}

	// Using symmetry - put input value into [0 - 0.5*pi]
	if (x > IFX_M_PI_2) {
		x = IFX_M_PI - x;
	}

	//now, we can assume x : [0;pi/2]
	/* case x = IFX_M_PI_2 */
	if (x==IFX_M_PI_2) {
		result = 1.0f;
		return result;
	}
	idx = (int) (x * (128.0 / IFX_M_PI_2));
	a = Ifx_sinTableF32[idx].a;
	b = Ifx_sinTableF32[idx].b;
	result = a * x + b;

	// apply sign
	result = IFX_COPYSIGN_F32(result, sign);

	return result;
}

float32
Ifx_sinF32 (float32 x, enum Ifx_mode mode)
{
    switch (mode) {
#if IFX_TRICORE_TARGET 
    case IFX_MODE_OPTIMIZED_ASM:
        return Ifx_sinF32_fast (x);
#endif /* IFX_TRICORE_TARGET  */
    case IFX_MODE_OPTIMIZED_C:
        return Ifx_sinF32_optimizedC (x);
# if HAVE_LIBM
    case IFX_MODE_EXTERNAL_LIBRARY:
        return sinf (x);
# endif /* HAVE_LIBM */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        return Ifx_sinF32_ref (x);
    default:
        Ifx_warnAboutUnimplementedMode (mode, "sinF32");
        return Ifx_sinF32_ref (x);
    }
}
