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
/*! \file Ifx_firComplexQ15.c
 *
 * \brief FIR for complex Q15 values
 *
 *
 * A FIR Filter is a digital electronic filter. It executes the calculation
 *     y[n]=sum(from k=0 to k=M) b[k]*x[n-k]
 * where b[k] is the filter-coefficient taken from the array b[]
 * and x[n-k] is one value from the input signal array x[].
 * Depending on the coefficients in b[] it can function as a high-pass filter,
 * low-pass filer, band-pass filter etc...
 *
 * \todo fix Ifx_firComplexQ15
 */

#include "dsplib-internal.h"

void Ifx_firComplexQ15_ref (struct Ifx_firComplexQ15State * state);

void
Ifx_firComplexQ15_ref (struct Ifx_firComplexQ15State * state)
{
    uint32 i, j;
    csint16 * y = state->y;
    csint16 * c = state->c;
    csint16 * x = state->x;
    csint16 * s = state->s;
    uint32 m = state->m;
    uint32 n = state->n;

    memset (y, 0, sizeof(csint16)*n);
    for (i=0; i<n; i++)
        for (j=0; j<m; j++) {
            uint32 k = i+j;
            csint32 z;
            z.real = (sint32)c[j].real*(sint32)x[i].real - (sint32)c[j].imag*(sint32)x[i].imag;
            z.imag = (sint32)c[j].real*(sint32)x[i].imag + (sint32)c[j].real*(sint32)x[i].imag;
	    z.real = (z.real+(1<<14))>>15;
	    z.imag = (z.imag+(1<<14))>>15;
            if (k<n) {
                y[k].real += z.real;
                y[k].imag += z.imag;
            } else {
                s[k-n].real += z.real;
                s[k-n].imag += z.imag;
            }
        }
}

void
Ifx_firComplexQ15 (struct Ifx_firComplexQ15State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "firComplexQ15");
        Ifx_firComplexQ15_ref (state);
        break;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_firComplexQ15_ref (state);
        break;
    }
}
