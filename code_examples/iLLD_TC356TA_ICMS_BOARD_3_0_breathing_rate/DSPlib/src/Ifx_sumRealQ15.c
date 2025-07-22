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
/*! \file Ifx_sumRealQ15.c
 *
 * \brief sum of Q15 vector
 *
 * Calculates the norm of a vector (=sum of vector-entries)
 */

#include "dsplib-internal.h"

static void
Ifx_sumRealQ15_ref (struct Ifx_sumRealQ15State * state)
{
    sint16 y = 0;
    sint16 * x = state->x;
    uint32 n = state->n;

    uint32 i;
    for (i=0; i<n; i++)
        y += x[i];
    state->y=y;
}

void
Ifx_sumRealQ15 (struct Ifx_sumRealQ15State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "sumRealQ15");
        Ifx_sumRealQ15_ref (state);
        break;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_sumRealQ15_ref (state);
        break;
    }
}
