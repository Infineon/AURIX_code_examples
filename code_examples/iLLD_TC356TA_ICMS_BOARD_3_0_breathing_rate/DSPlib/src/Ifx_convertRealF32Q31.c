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
/*! \file Ifx_convertRealF32Q31.c
 *
 * \brief converts 32-bit float numbers to 32-bit fixed-point numbers
 *
 * converts 32-bit float numbers to 32-bit fixed-point numbers
 */

#include "dsplib-internal.h"

static void
Ifx_convertRealF32Q31_ref (sint32 * y, float32 * x, uint32 n)
{
    uint32 i;
    for (i=0; i<n; i++) {
        if (x[i] <= -1.0f)
            y[i] = 0x80000000;
        else if (x[i] >= 1.0f)
            y[i] = 0x7fffffff;
        else
            y[i] = (sint32) (x[i]*2147483647.0f);
    }
}

static void
Ifx_convertRealF32Q31_optimizedC (sint32 * y, float32 * x, uint32 n)
{
    uint32 i;
    for (i=0; i<n; i++)
        y[i] = (sint32) (x[i]*2147483648.0f);
}

void
Ifx_convertRealF32Q31 (struct Ifx_convertRealF32Q31State * state)
{
    enum Ifx_mode mode = state->mode;
    float32 * x = state->x;
    sint32 * y = state->y;
    uint32 n = state->n;

    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "convertRealF32Q31");
        Ifx_convertRealF32Q31_ref (y,x,n);
        return;
    case IFX_MODE_OPTIMIZED_C:
        Ifx_convertRealF32Q31_optimizedC (y,x,n);
        return;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_convertRealF32Q31_ref (y,x,n);
        return;
    }
}
