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
/*! \file Ifx_firRealQ31.c
 *
 * \brief FIR for real Q31 values
 *
 *
 * A FIR Filter is a digital electronic filter. It executes the calculation
 *     y[n]=sum(from k=0 to k=M) b[k]*x[n-k]
 * where b[k] is the filter-coefficient taken from the array b[]
 * and x[n-k] is one value from the input signal array x[].
 * Depending on the coefficients in b[] it can function as a high-pass filter,
 * low-pass filer, band-pass filter etc...
 *
 * \todo fix Ifx_firRealQ31
 */

#include "dsplib-internal.h"

void Ifx_firRealQ31_ref (struct Ifx_firRealQ31State *);

void
Ifx_firRealQ31_ref (struct Ifx_firRealQ31State * state)
{
    int i, j;
    sint32 * y = state->y;
    sint32 * c = state->c;
    sint32 * x = state->x;
    sint32 * s = state->s;
    uint32 m = state->m;
    uint32 n = state->n;

    memset (y, 0, sizeof(sint32)*n);
    for (i=0; i<n; i++)
        for (j=0; j<m; j++) {
            int k = i+j;
            sint64 z = (sint64)c[j]*(sint64)x[i];
	    z = (z+(1<<30))>>31;
            if (k<n) y[k] += z;
            else s[k-n] += z;
        }
}

void
Ifx_firRealQ31 (struct Ifx_firRealQ31State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "firRealQ31");
        Ifx_firRealQ31_ref (state);
        break;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_firRealQ31_ref (state);
        break;
    }
}
