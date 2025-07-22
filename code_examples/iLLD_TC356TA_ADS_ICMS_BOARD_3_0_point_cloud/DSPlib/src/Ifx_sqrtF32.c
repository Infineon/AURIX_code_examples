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
/*! \file Ifx_sqrtF32.c
 *
 * \brief square root function
 *
 * computation of square root with newton iteration
 *
 * Calculates the square root of a value
 */

#include "dsplib-internal.h"

static float32
Ifx_sqrtF32_ref (float32 a)
{
    float32 xn;
    if (a < 0.0f) {
        Ifx_error (IFX_ERR_ERROR, "sqrt(%g) of negative number\n", a);
        xn = IFX_NAN;
    } else if (a == 0.0f) {
        xn = 0.0f;
    } else {
        xn = a;
        while (fabs ((xn*xn-a)/a) >= 2.0*FLT_EPSILON) {
            xn = 0.5f * (xn + a/xn);
        }
    }
    return xn;
}

extern float32 Ifx_sqrtF32_optimizedC (float32 a);

float32
Ifx_sqrtF32_optimizedC (float32 a)
{
	float32 xn;
    float32 approx0, approx1;

    if (a < 0.0f) {
        Ifx_error (IFX_ERR_ERROR, "sqrt(%g) of negative number\n", a);
        xn = IFX_NAN;
    } else if (a == 0.0f) {
        xn = 0.0f;
    } else {
        __asm("qseed.f %0,%1":"=d"(approx0):"d"(a));
    	approx1 = approx0 * (1.5  - (0.5 * (a * approx0) * approx0));
    	xn = a * approx1;
    	xn = xn * (1.5 - (0.5 * (xn) * approx1));
    }
    return xn;
}

float32
Ifx_sqrtF32 (float32 x, enum Ifx_mode mode)
{
    switch (mode) {
#if IFX_TRICORE_TARGET 
    case IFX_MODE_OPTIMIZED_ASM:
        return Ifx_sqrtF32_fast (x);
#endif /* IFX_TRICORE_TARGET  */
#if IFX_TRICORE_TARGET
    case IFX_MODE_OPTIMIZED_C:
        return Ifx_sqrtF32_optimizedC (x);
#endif /* IFX_TRICORE_TARGET */
# if HAVE_LIBM
    case IFX_MODE_EXTERNAL_LIBRARY:
        return sqrtf (x);
# endif /* HAVE_LIBM */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        return Ifx_sqrtF32_ref (x);
    default:
        Ifx_warnAboutUnimplementedMode (mode, "sqrtF32");
        return Ifx_sqrtF32_ref (x);
    }
}
