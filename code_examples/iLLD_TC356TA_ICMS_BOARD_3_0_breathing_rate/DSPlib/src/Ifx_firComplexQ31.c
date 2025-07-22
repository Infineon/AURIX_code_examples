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
/*! \file Ifx_firComplexQ31.c
 *
 * \brief FIR for complex Q31 values
 *
 *
 * A FIR Filter is a digital electronic filter. It executes the calculation
 *     y[n]=sum(from k=0 to k=M) b[k]*x[n-k]
 * where b[k] is the filter-coefficient taken from the array b[]
 * and x[n-k] is one value from the input signal array x[].
 * Depending on the coefficients in b[] it can function as a high-pass filter,
 * low-pass filer, band-pass filter etc...
 *
 * \todo fix Ifx_firComplexQ31
 */

#include "dsplib-internal.h"

void Ifx_firComplexQ31_ref (struct Ifx_firComplexQ31State *);

void
Ifx_firComplexQ31_ref (struct Ifx_firComplexQ31State * state)
{
    uint32 i, j;
    csint32 * y = state->y;
    csint32 * c = state->c;
    csint32 * x = state->x;
    csint32 * s = state->s;
    uint32 m = state->m;
    uint32 n = state->n;

    memset (y, 0, sizeof(csint32)*n);
    for (i=0; i<n; i++)
        for (j=0; j<m; j++) {
            uint32 k = i+j;
            csint64 z;
            z.real = (sint64)c[j].real*(sint64)x[i].real - (sint64)c[j].imag*(sint64)x[i].imag;
            z.imag = (sint64)c[j].real*(sint64)x[i].imag + (sint64)c[j].real*(sint64)x[i].imag;
	    z.real = (z.real+(1<<30))>>31;
	    z.imag = (z.imag+(1<<30))>>31;
            if (k<n) {
                y[k].real += (sint32)z.real;
                y[k].imag += (sint32)z.imag;
            } else {
                s[k-n].real += (sint32)z.real;
                s[k-n].imag += (sint32)z.imag;
            }
        }
}

void
Ifx_firComplexQ31 (struct Ifx_firComplexQ31State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "firComplexQ31");
        Ifx_firComplexQ31_ref (state);
        break;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_firComplexQ31_ref (state);
        break;
    }
}
