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
/*! \file Ifx_corrRealQ15.c
 *
 * \brief correlation of Q15 vectors
 *
 * Computing the correlation of two 16-bit fixed-point number vectors
 * The correlation function describes the relationship between different values of
 * (in this case) vectors x (with length m) and y (with length n) at different locations.
 */

#include "dsplib-internal.h"


static void
Ifx_corrRealQ15_ref (struct Ifx_corrRealQ15State * state)
{
    sint16 * r = state->r;
    sint16 * x = state->x;
    sint16 * y = state->y;
    uint32 m = state->m;
    uint32 n = state->n;
    uint32 i,j;

    memset (r, 0, sizeof(sint16)*(m+n-1));
    for (i=0; i<n; i++)
        for (j=0; j<m; j++) {
            sint32 z = (sint32)x[j]*(sint32)y[i];
            z += 1<<14;
            z >>= 15;
            r[i+m-1-j] += z;
        }
}

void
Ifx_corrRealQ15 (struct Ifx_corrRealQ15State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "corrRealF32");
        Ifx_corrRealQ15_ref (state);
        return;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_corrRealQ15_ref (state);
        return;
    }
}
