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
/*! \file Ifx_sumRealQ31.c
 *
 * \brief sum of Q31 vector
 *
 * sum of values of a vector of Q31 values.
 */

#include "dsplib-internal.h"

static void
Ifx_sumRealQ31_ref (struct Ifx_sumRealQ31State * state)
{

    sint32 y = 0;
    sint32 * x = state->x;
    uint32 n = state->n;

    uint32 i;
    for (i=0; i<n; i++)
        y += x[i];
    state->y = y;
}

void
Ifx_sumRealQ31 (struct Ifx_sumRealQ31State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "sumRealQ31");
        Ifx_sumRealQ31_ref (state);
        break;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_sumRealQ31_ref (state);
        break;
    }
}
