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

/*! \file Ifx_firRealQ15.c
 *
 * \brief FIR for real Q15 values
 *
 *
 * A FIR Filter is a digital electronic filter. It executes the calculation
 *     y[n]=sum(from k=0 to k=M) b[k]*x[n-k]
 * where b[k] is the filter-coefficient taken from the array b[]
 * and x[n-k] is one value from the input signal array x[].
 * Depending on the coefficients in b[] it can function as a high-pass filter,
 * low-pass filer, band-pass filter etc...
 *
 * \todo fix Ifx_firRealQ15
 *
 */

#include "dsplib-internal.h"

void Ifx_firRealQ15_ref (struct Ifx_firRealQ15State *);

void Ifx_firRealQ15_ref (struct Ifx_firRealQ15State * state)
{
    uint32 i, j;
    sint16 * y = state->y;
    sint16 * c = state->c;
    sint16 * x = state->x;
    sint16 * s = state->s;
    uint32 m = state->m;
    uint32 n = state->n;

    memset (y, 0, sizeof(sint16)*n);

    for (i=0; i<n; i++){
        for (j=0; j<m; j++) {
            int k = i+j;
            sint32 z;
            IFX_MUL_Q15(z,c[j],x[i]);
            if (k<n) y[k] += (sint16)z;
            else s[k-n] += (sint16)z;
        }
	}
	memmove(y+n,s,sizeof(sint16)*(m-1));
}

void Ifx_firRealQ15 (struct Ifx_firRealQ15State * state)
{
    enum Ifx_mode mode = state->mode;
    Ifx_CircularBuffer coeffs = { state->c, 0, sizeof(sint16)*(state->m) };
    Ifx_CircularBuffer im_state = { state->s, 0, sizeof(sint16)*(state->m) };
    switch (mode) {
		case IFX_MODE_REFERENCE_IMPLEMENTATION:
			Ifx_firRealQ15_ref (state);
			break;
		case IFX_MODE_OPTIMIZED_ASM:
			Ifx_firRealQ15_fast (state->x,state->y,coeffs,&im_state,state->n);
			break;
		default:
			Ifx_warnAboutUnimplementedMode (mode, "firRealQ15");
			Ifx_firRealQ15_ref (state);
			break;
    }
}
