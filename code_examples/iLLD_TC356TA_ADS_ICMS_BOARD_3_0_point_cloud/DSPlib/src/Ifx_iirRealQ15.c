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

/*! \file Ifx_iirRealQ15.c
 *
 * \brief IIR for real Q15 values
 *
 *
 * A FIR Filter is a digital electronic filter. It executes the calculation
 *     y[n]=sum(from k=0 to k=M) b[k]*x[n-k]
 * where b[k] is the filter-coefficient taken from the array b[]
 * and x[n-k] is one value from the input signal array x[].
 * Depending on the coefficients in b[] it can function as a high-pass filter,
 * low-pass filer, band-pass filter etc...
 *
 * \todo fix Ifx_iirRealQ15
 */

#include "dsplib-internal.h"

void Ifx_iirRealQ15_ref (struct Ifx_iirRealQ15State *);

void
Ifx_iirRealQ15_ref (struct Ifx_iirRealQ15State * state)
{
    sint64 i;
    sint64 j;
    sint16 * y = state->y;
    sint16 * a = state->a;
    sint16 * b = state->b;
    sint16 * x = state->x;
    sint16 * s = state->s;
    uint32 m = state->m;
    uint32 n = state->n;

    memset (y, 0, sizeof(sint16)*n);
    for (i=0; i<n; ++i) {
    	sint32 z = x[i];
    	sint32 w = 0;
    	uint32 c = 0;
		for(j=i-1; j>=0; --j) {
			z += b[++c]*x[j];
			w += a[c]*x[j];
		}
		for(j=0; j<(m-i); ++j) {
			z += b[++c]*s[j];
			w += a[c]*s[j];
		}
		w += a[0]*z;
		w += 1<<14;
		w >>= 15;
		y[i] = w;
	}
    memmove(s+n,s,(m-n)*sizeof(sint16));
    memcpy(s,x,n*sizeof(sint16));
}

void
Ifx_iirRealQ15 (struct Ifx_iirRealQ15State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
		case IFX_MODE_REFERENCE_IMPLEMENTATION:
			Ifx_iirRealQ15_ref (state);
	        break;
		case IFX_MODE_OPTIMIZED_ASM:
			/* Ifx_iirRealQ15_fast(sint16 *x,sint16 *y,sint16 *c,sint16 *d,uint32 nBiq,uint32 nX) */
	        break;
		default:
			Ifx_warnAboutUnimplementedMode (mode, "iirRealQ15");
			Ifx_iirRealQ15_ref (state);
			break;
    }
}
