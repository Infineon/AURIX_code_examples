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
/*! \file Ifx_atan2F32.c
 *
 * \brief compute arcus tangent with two arguments
 *
 * \a Ifx_atan2F32s function compute the inverse of the tangent function.
 * This function evaluates the inverse tangent function and correctly
 * decodes the quadrant of the angle.
 *
 */

#include "dsplib-internal.h"

static float32
Ifx_atan2F32_ref (float32 y,float32 x)
{
    enum Ifx_mode mode = IFX_MODE_REFERENCE_IMPLEMENTATION;
    if (x > IFX_FLT_EPSILON)
        return Ifx_atanF32 (y/x, mode);
    else if (x < -IFX_FLT_EPSILON) {
        if (y >= 0.0f)
            return Ifx_atanF32 (y/x, mode) + IFX_M_PI;
        else /* y < 0.0 */
            return Ifx_atanF32 (y/x, mode) - IFX_M_PI;
    } else /* x == 0.0 */ {
        if (y > IFX_FLT_EPSILON)
            return IFX_M_PI_2;
        else if (y < -IFX_FLT_EPSILON)
            return -IFX_M_PI_2;
        else /* y == 0.0 */
            return 0.0f;
    }
}

/* optimized implementation
 * according to 
 * Wikipedia
 * https://de.wikipedia.org/wiki/Arkustangens#N.C3.A4herungsweise_Berechnung
 * and
 * Richard G. Lyons: Performing efficient arctangent approximation
 * ee times, 6/8/2011
 */

#define F 0.28f

static float32
Ifx_atanF32_optimizedC (float32 y,float32 x, float32 offset)
{
    float32 result;
    float32 y2 = y*y;
    float32 x2 = x*x;
    if (y2<=x2) {
        /* |y/x| <= 1 */
        result = x*y/(x2+F*y2);
    } else {
        union {float32 f; uint32 i;} yu, xu;
        xu.f = x;
        yu.f = y;
        if ((xu.i^yu.i)&0x80000000) {
            /* |y/x| < -1 */
            result = -IFX_M_PI_2 - x*y/(y2+F*x2);
        } else {
            /* |y/x| > +1 */
            result = +IFX_M_PI_2 - x*y/(y2+F*x2);
        }
    }
    return result + offset;
}

static float32
Ifx_atan2F32_optimizedC (float32 y,float32 x)
{
    float32 result;
    if (x > IFX_FLT_EPSILON)
        result = Ifx_atanF32_optimizedC (y,x, 0.0f);
    else if (x < -IFX_FLT_EPSILON) {
        if (y >= 0.0f)
            result = Ifx_atanF32_optimizedC (y,x, IFX_M_PI);
        else /* y < 0.0 */
            result = Ifx_atanF32_optimizedC (y,x,-IFX_M_PI);
    } else /* x == 0.0 */ {
        if (y > IFX_FLT_EPSILON)
            result = IFX_M_PI_2;
        else if (y < -IFX_FLT_EPSILON)
            result = -IFX_M_PI_2;
        else /* y == 0.0 */
            result = 0.0f;
    }
    return result;
}

float32
Ifx_atan2F32 (float32 y,float32 x, enum Ifx_mode mode)
{
    switch (mode) {
    case IFX_MODE_OPTIMIZED_C:
        return Ifx_atan2F32_optimizedC (y,x);
# if HAVE_LIBM
    case IFX_MODE_EXTERNAL_LIBRARY:
        return atan2f (y,x);
# endif /* HAVE_LIBM */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        return Ifx_atan2F32_ref (y,x);
    default:
        Ifx_warnAboutUnimplementedMode (mode, "tan2F32");
        return Ifx_atan2F32_ref (y,x);
    }
}
