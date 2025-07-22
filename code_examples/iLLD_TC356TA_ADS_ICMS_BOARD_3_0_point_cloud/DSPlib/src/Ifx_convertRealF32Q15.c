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
/*! \file Ifx_convertRealF32Q15.c
 *
 * \brief converts 32-bit float numbers to 16-bit fixed-point numbers
 *
 * converts 32-bit float numbers to 16-bit fixed-point numbers
 */

#include "dsplib-internal.h"

static void
Ifx_convertRealF32Q15_ref (sint16 * y, float32 * x, uint32 n)
{
    uint32 i;
    for (i=0; i<n; i++) {
        if (x[i] <= -1.0f)
            y[i] = 0x8000;
        else if (x[i] >= 1.0f)
            y[i] = 0x7fff;
        else
            y[i] = (sint16) (x[i]*32767.0f);
    }
}

static void
Ifx_convertRealF32Q15_optimizedC (sint16 * y, float32 * x, uint32 n)
{
    uint32 i;
    for (i=0; i<n; i++)
        y[i] = (sint16) (x[i]*32768.0f);
}

void
Ifx_convertRealF32Q15 (struct Ifx_convertRealF32Q15State * state)
{
    enum Ifx_mode mode = state->mode;
    float32 * x = state->x;
    sint16 * y = state->y;
    uint32 n = state->n;

    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "convertRealF32Q15");
        Ifx_convertRealF32Q15_ref (y,x,n);
        return;
    case IFX_MODE_OPTIMIZED_C:
        Ifx_convertRealF32Q15_optimizedC (y,x,n);
        return;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_convertRealF32Q15_ref (y,x,n);
        return;
    }
}
