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
/*! \file Ifx_mtxHrmComplexF32.c
 *
 * \brief transpose matrix
 *
 * transpose a complex floating point matrix
 */

#include "dsplib-internal.h"

static void
Ifx_mtxHrmComplexF32_ref (struct Ifx_mtxHrmComplexF32State * state)
{
    cfloat32 * mtx = state->mtx;
    cfloat32 * hrm = state->hrm;
    uint32 m = state->m;
    uint32 n = state->n;
    uint32 i,j;
    for (i=0; i<m; i++)
        for (j=0; j<n; j++) {
            hrm[j*m+i].real = +mtx[i*n+j].real;
            hrm[j*m+i].imag = -mtx[i*n+j].imag;
        }
}

void
Ifx_mtxHrmComplexF32 (struct Ifx_mtxHrmComplexF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_mtxHrmComplexF32_ref (state);
        return;
#if IFX_TRICORE_TARGET 
    case IFX_MODE_OPTIMIZED_ASM:
        if (state->m==1&&state->n==8 || state->m==8&&state->n==1)
            Ifx_mtxHrmComplexF32_fast1x8 (state->hrm, state->mtx);
        else
            Ifx_mtxHrmComplexF32_fast (state->m, state->n, state->hrm, state->mtx);
        return;
#endif /* IFX_TRICORE_TARGET  */
    default:
        Ifx_warnAboutUnimplementedMode (mode, "mtxHrmComplexF32");
        Ifx_mtxHrmComplexF32_ref (state);
        return;
    }
}
