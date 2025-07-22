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
/*! \file Ifx_vecAvgQ15F32.c
 *
 * \brief average of Q15 vector, floating point result
 *
 *  Created on: 27.05.2015
 *      Author: gordon
 */

#include "dsplib-internal.h"

static void
Ifx_vecAvgQ15F32_ref (struct Ifx_vecAvgQ15F32State * state)
{
    sint16 * x = state->x;
    uint32 n = state->n;
	float64 sum = 0.0;

    uint32 i;
    for (i=0; i<n; i++)
    	sum += x[i]/32768.0;
    state->avg = (float32) (sum/n);
}

void
Ifx_vecAvgQ15F32(struct Ifx_vecAvgQ15F32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
    	Ifx_vecAvgQ15F32_ref (state);
    	return;
    case IFX_MODE_OPTIMIZED_ASM:
    	state->avg = Ifx_vecAvgQ15F32_fast (state->n, state->x);
    return;
    default:
        Ifx_warnAboutUnimplementedMode (mode, "vecAvgQ15F32");
    	Ifx_vecAvgQ15F32_ref (state);
    	return;
    }
}
