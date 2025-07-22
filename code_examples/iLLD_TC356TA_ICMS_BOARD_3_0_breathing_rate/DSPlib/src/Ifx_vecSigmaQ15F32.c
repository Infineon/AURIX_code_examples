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
/*! \file Ifx_vecSigmaQ15F32.c
 *
 * \brief variance (sigma) of Q15 vector
 *
 *  Created on: 27.05.2015
 *      Author: gordon
 */

#include "dsplib-internal.h"

static void
Ifx_vecSigmaQ15F32_ref (struct Ifx_vecSigmaQ15F32State * state)
{
    sint16 * x = state->x;
    uint32 n = state->n;
    uint32 adj = state->adj;
    float32 sum;
    float32 avg;
    float32 sum2;
    float32 sigma;
    uint32 i;

    sum = 0.0;
    for (i=0; i<n; i++) {
    	float fX = x[i] / 32768.0;
    	sum += fX;
    }
    avg = sum/n;

    sum2 = 0.0;
    for (i=0; i<n; i++) {
    	float fX = x[i] / 32768.0;
    	sum2 += (fX-avg)*(fX-avg);
    }

    sigma = sqrt (sum2 / (n-adj));

    state->sigma = sigma;
    state->avg = avg;
}

void
Ifx_vecSigmaQ15F32(struct Ifx_vecSigmaQ15F32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
    	Ifx_vecSigmaQ15F32_ref (state);
    	return;
    case IFX_MODE_OPTIMIZED_ASM:
    	state->sigma = Ifx_vecSigmaQ15F32_fast (state->n, state->x, state->adj, &state->avg);
    	return;
    default:
        Ifx_warnAboutUnimplementedMode (mode, "vecSigmaQ15F32");
    	Ifx_vecSigmaQ15F32_ref (state);
    	return;
    }
}
