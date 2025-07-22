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
/*! \file Ifx_vecDotQ15.c
 *
 * \brief dot product of two Q15 vectors with Q15 result
 *
 *  Created on: 27.05.2015
 *      Author: gordon
 */

#include "dsplib-internal.h"

static void
Ifx_vecDotQ15_ref (struct Ifx_vecDotQ15State * state)
{
    sint16 * x = state->x;
    sint16 * y = state->y;
    uint16_least shift = state->shift;
    uint32 n = state->n;
    sint64 sum = 0;
    sint64 dX, dY;

    uint32 i;
    for (i=0; i<n; i++) {
    	dX = x[i];
    	dY = y[i];
    	sum += dX*dY;
    }
    sum >>= 15+shift;
    state->dot = sum;
}

void
Ifx_vecDotQ15(struct Ifx_vecDotQ15State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
    	Ifx_vecDotQ15_ref (state);
    	return;

    case IFX_MODE_OPTIMIZED_ASM:
    	state->dot = Ifx_vecDotQ15_fast (state->n, state->x, state->y, state->shift);
    	return;

    default:
        Ifx_warnAboutUnimplementedMode (mode, "vecDotQ15");
    	Ifx_vecDotQ15_ref (state);
    	return;
    }
}
