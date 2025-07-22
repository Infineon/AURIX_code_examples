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
/*! \file Ifx_corrRealF32.c
 *
 * \brief real signal correlation
 *
 * Computing the correlation of two 32-bit float number vectors
 *`The correlation function describes the relationship between different values of (in this case) vectors x (with length m) and
 * y (with length n) at different locations.
 *
 * see http://de.wikipedia.org/wiki/Korrelation
 */

#include "dsplib-internal.h"

static void
Ifx_corrRealF32_ref (struct Ifx_corrRealF32State * state)
{
    float32 * r = state->r;
    float32 * x = state->x;
    float32 * y = state->y;
    uint32 m = state->m;
    uint32 n = state->n;
    uint32 i,j;

    memset (r, 0, sizeof(float32)*(m+n-1));
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            r[i+m-1-j] += x[j]*y[i];
}

void
Ifx_corrRealF32 (struct Ifx_corrRealF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "corrRealF32");
        Ifx_corrRealF32_ref (state);
        return;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_corrRealF32_ref (state);
        return;
    }
}
