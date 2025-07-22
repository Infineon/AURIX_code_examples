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
/*! \file Ifx_mtxAddRealF32.c
 *
 * \brief add two matrices
 *
 * Function to add two matrices
 */

#include "dsplib-internal.h"

static void
Ifx_mtxAddRealF32_ref (struct Ifx_mtxAddRealF32State * state)
{
    float32 * dst = state->dst;
    float32 * src1 = state->src1; /* IN  vector[m*n], first addend. */
    float32 * src2 = state->src2; /* IN  vector[m*n], second addend. */
    uint32 m = state->m;          /* IN  number of rows in matrix. */ 
    uint32 n = state->n;          /* IN  number of columns in matrix. */

    uint32 i,j;
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            dst[i*n+j] = src1[i*n+j] + src2[i*n+j];
}

void
Ifx_mtxAddRealF32 (struct Ifx_mtxAddRealF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_mtxAddRealF32_ref (state);
        break;
#if IFX_TRICORE_TARGET 
    case IFX_MODE_OPTIMIZED_ASM:
    	Ifx_mtxAddRealF32_fast (state->m, state->n, state->dst, state->src1, state->src2);
    	break;
#endif /* IFX_TRICORE_TARGET  */
    default:
        Ifx_warnAboutUnimplementedMode (mode, "mtxAddRealF32");
        Ifx_mtxAddRealF32_ref (state);
        break;
    }
}
