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
/*! \file Ifx_corrRealQ31.c
 *
 * \brief correlation of real Q31 vectors.
 *
 * Computing the correlation of two 32-bit fixed-point number vectors.
 * The correlation function describes the relationship between different values of (in this case)
 * vectors x (with length m) and y (with length n) at different locations.
 */

#include "dsplib-internal.h"

static void
Ifx_corrRealQ31_ref (struct Ifx_corrRealQ31State * state)
{
    sint32 * r = state->r;
    sint32 * x = state->x;
    sint32 * y = state->y;
    uint32 m = state->m;
    uint32 n = state->n;
    uint32 i,j;

    memset (r, 0, sizeof(sint32)*(m+n-1));
    for (i=0; i<n; i++)
        for (j=0; j<m; j++) {
            sint64 z = (sint64)x[j]*(sint64)y[i];
            z += 1<<30;
            z >>= 31;
            r[i+m-1-j] += (sint32) z;
        }
}

void
Ifx_corrRealQ31 (struct Ifx_corrRealQ31State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_corrRealQ31_ref (state);
        return;
    default:
        Ifx_warnAboutUnimplementedMode (mode, "corrRealQ31");
        Ifx_corrRealQ31_ref (state);
        return;
    }
}
