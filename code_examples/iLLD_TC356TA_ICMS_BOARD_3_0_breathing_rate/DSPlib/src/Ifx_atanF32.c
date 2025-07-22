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
/*! \file Ifx_atanF32.c
 *
 * \brief compute arcus tangent of argument
 *
 * \a Ifx_atanF32 function compute the inverse of the tangent function.
 * computation using taylor series in origin
 * see http://de.wikipedia.org/wiki/Arkustangens_und_Arkuskotangens
 *
 */

#include "dsplib-internal.h"

static float32 Ifx_atanF32_ref (float32 x)
{
    int i;
    float32 y = 0.0f;
    float32 xn;
    float factor = 1.0f;
    enum Ifx_mode mode = IFX_MODE_REFERENCE_IMPLEMENTATION;

    /* make sure that argument is smaller than 1.0 */
    if (x<0.0f) {
        factor = -1.0f;
        x = -x;
    }
    while (x > 0.5f) {
        factor *= 2.0f;
        x = x / (1.0f + Ifx_sqrtF32(1.0f + x*x, mode));
    }
    xn = x;
    /* actual arcustangent series */
    for(i=1; xn>=FLT_EPSILON; i+=4) {
        y += 1.0f/i*xn;
        xn *= x*x;
        y -= 1.0f/(i+2)*xn;
        xn *= x*x;
    }
    return factor*y;
}

/* optimized implementation
 * according to 
 * Wikipedia
 * https://de.wikipedia.org/wiki/Arkustangens#N.C3.A4herungsweise_Berechnung
 * and
 * Richard G. Lyons: Performing efficient arctangent approximation
 * ee times, 6/8/2011
 */

#define F 0.28125f

static float32 Ifx_atanF32_optimizedC (float32 x)
{
    float32 result;
    float32 x2 = x*x;
    if (x2<=1.0f) {
        /* |x| <= 1 */
        result = x/(1.0f+F*x2);
    } else {
        if (x<-1.0f) {
            /* |x| < -1 */
            result = -IFX_M_PI_2 - x/(x2+F);
        } else {
            /* |x| > +1 */
            result = +IFX_M_PI_2 - x/(x2+F);
        }
    }
    return result;    
}

float32 Ifx_atanF32 (float32 x, enum Ifx_mode mode)
{
    switch (mode) {
#if IFX_TRICORE_TARGET 
    case IFX_MODE_OPTIMIZED_ASM:
        return Ifx_atanF32_fast (x);
#endif /* IFX_TRICORE_TARGET  */
    case IFX_MODE_OPTIMIZED_C:
        return Ifx_atanF32_optimizedC (x);
# if HAVE_LIBM
    case IFX_MODE_EXTERNAL_LIBRARY:
        return atanf (x);
# endif /* HAVE_LIBM */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        return Ifx_atanF32_ref (x);
    default:
        Ifx_warnAboutUnimplementedMode (mode, "atanF32");
        return Ifx_atanF32_ref (x);
    }
}
