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
/*! \file Ifx_firComplexF32.c
 *
 * \brief FIR for complex float values
 *
 *
 * A FIR Filter is a digital electronic filter. It executes the calculation
 *     y[n]=sum(from k=0 to k=M) b[k]*x[n-k]
 * where b[k] is the filter-coefficient taken from the array b[]
 * and x[n-k] is one value from the input signal array x[].
 * Depending on the coefficients in b[] it can function as a high-pass filter,
 * low-pass filer, band-pass filter etc...
 */

#include "dsplib-internal.h"

void Ifx_firComplexF32_ref (struct Ifx_firComplexF32State * state);

void
Ifx_firComplexF32_ref (struct Ifx_firComplexF32State * state)
{
    uint32 i, j;
    cfloat32 * y = state->y;
    cfloat32 * c = state->c;
    cfloat32 * x = state->x;
    cfloat32 * s = state->s;
    uint32 m = state->m;
    uint32 n = state->n;

    memset (y, 0, sizeof(cfloat32)*n);
    for (i=0; i<n; i++)
        for (j=0; j<m; j++) {
            uint32 k = i+j;
            cfloat32 z;
            z.real = c[j].real*x[i].real - c[j].imag*x[i].imag;
            z.imag = c[j].real*x[i].imag + c[j].real*x[i].imag;
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
Ifx_firComplexF32 (struct Ifx_firComplexF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_firComplexF32_ref (state);
        break;
    default:
        Ifx_warnAboutUnimplementedMode (mode, "firComplexF32");
        Ifx_firComplexF32_ref (state);
        break;
    }
}
