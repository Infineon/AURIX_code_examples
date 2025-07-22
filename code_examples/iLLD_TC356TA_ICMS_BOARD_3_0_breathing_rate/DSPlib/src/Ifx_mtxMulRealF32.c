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
/*! \file Ifx_mtxMulRealF32.c
 *
 * \brief multiply two matrices
 *
 * Multiplying two matrices dst = src1*scr2
 */

#include "dsplib-internal.h"

static void
Ifx_mtxMulRealF32_ref (struct Ifx_mtxMulRealF32State * state)
{
    uint32 i, j, k;
    float32 * dst = state->dst;
    float32 * src1 = state->src1;
    float32 * src2 = state->src2;
    uint32 m = state->m; /*!< IN  number of rows in result matrix */
    uint32 n = state->n; /*!< IN  number of columns in result matrix */
    uint32 l = state->l; /*!< IN  number of adjecant rows/columns */

    for (i=0; i<m; i++)
        for (j=0; j<n; j++) {
	    dst[i*n+j] = 0.0f;
	    for (k=0; k<l; k++)
                dst[i*n+j] += src1[i*l+k] * src2[k*n+j];
        }
}

void
Ifx_mtxMulRealF32 (struct Ifx_mtxMulRealF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_mtxMulRealF32_ref (state);
        break;
#if IFX_TRICORE_TARGET
    case IFX_MODE_OPTIMIZED_ASM:
    	Ifx_mtxMulRealF32_fast (state);
    	break;
#endif /* IFX_TRICORE_TARGET */
    default:
        Ifx_warnAboutUnimplementedMode (mode, "mtxMulRealF32");
        Ifx_mtxMulRealF32_ref (state);
        break;
    }
}
