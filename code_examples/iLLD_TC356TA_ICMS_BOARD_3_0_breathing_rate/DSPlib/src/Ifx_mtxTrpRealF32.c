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
/*! \file Ifx_mtxTrpRealF32.c
 *
 * \brief transpose matrix
 *
 * transpose a real floating point matrix
 */

#include "dsplib-internal.h"

static void
Ifx_mtxTrpRealF32_ref (struct Ifx_mtxTrpRealF32State * state)
{
    float32 * mtx = state->mtx;
    float32 * trp = state->trp;
    uint32 m = state->m;
    uint32 n = state->n;
    uint32 i,j;
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            trp[j*m+i] = mtx[i*n+j];
}

void
Ifx_mtxTrpRealF32 (struct Ifx_mtxTrpRealF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_mtxTrpRealF32_ref (state);
        return;
#if IFX_TRICORE_TARGET 
    case IFX_MODE_OPTIMIZED_ASM:
        Ifx_mtxTrpRealF32_fast (state->m, state->n, state->trp, state->mtx);
        return;
#endif /* IFX_TRICORE_TARGET  */
    default:
        Ifx_warnAboutUnimplementedMode (mode, "mtxTrpRealF32");
        Ifx_mtxTrpRealF32_ref (state);
        return;
    }
}
