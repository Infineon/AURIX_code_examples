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
/*! \file Ifx_tanF32.c
 *
 * \brief tangent function
 *
 * Calculates the tangent function of a value.
 * Reihenentwicklung mit Bernoulli-Polynomen
 * http://de.wikipedia.org/wiki/Tangens_und_Kotangens
 * http://de.wikipedia.org/wiki/Bernoulli-Zahlen
 */

#include "dsplib-internal.h"

static float32
Ifx_tanF32_ref (float32 x)
{
    enum Ifx_mode mode = IFX_MODE_REFERENCE_IMPLEMENTATION;

    /* normalize input */
    x = IFX_MOD_F32 (x+IFX_M_PI, IFX_M_PI)-IFX_M_PI;

    return Ifx_sinF32 (x, mode) / Ifx_cosF32 (x, mode);
}

float32
Ifx_tanF32 (float32 x, enum Ifx_mode mode)
{
    switch (mode) {
#if IFX_TRICORE_TARGET
    case IFX_MODE_OPTIMIZED_ASM:
        return Ifx_tanF32_fast (x);
#endif /* IFX_TRICORE_TARGET*/
# if HAVE_LIBM
    case IFX_MODE_EXTERNAL_LIBRARY:
        return tanf (x);
# endif /* HAVE_LIBM */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        return Ifx_tanF32_ref (x);
    default:
        Ifx_warnAboutUnimplementedMode (mode, "tanF32");
        return Ifx_tanF32_ref (x);
    }
}
