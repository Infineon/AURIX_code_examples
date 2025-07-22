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

/*! \file Ifx_mtxMulComplexF32.c
 *
 * \brief multiply two matrices
 *
 * Multiplying two matrices dst = src1*scr2
 */

#include <dsplib.h>
#include "dsplib-internal.h"

/*
Optimized Asm implementation in file Ifx_mtxMulComplexF32a.asm
void
Ifx_mtxMulComplexF32a (struct Ifx_mtxMulComplexF32State * state)
*/

void
Ifx_mtxMulComplexF32_ref (struct Ifx_mtxMulComplexF32State * state)
{
    uint32 i, j, k;
    cfloat32 * dst = state->dst;
    cfloat32 * src1 = state->src1;
    cfloat32 * src2 = state->src2;
    uint32 m = state->m; /*!< IN  number of rows in result matrix */
    uint32 n = state->n; /*!< IN  number of columns in result matrix */
    uint32 l = state->l; /*!< IN  number of adjacent rows/columns */

    for (i=0; i<m; i++){           /* all rows  */
        for (j=0; j<n; j++) {      /* one row   */
	      dst[i*n+j].real = 0.0f;
          dst[i*n+j].imag = 0.0f;

          for (k=0; k<l; k++){      /* one value */
            dst[i*n+j].real += src1[i*l+k].real * src2[k*n+j].real - (src1[i*l+k].imag * src2[k*n+j].imag);
            dst[i*n+j].imag += src1[i*l+k].real * src2[k*n+j].imag + (src1[i*l+k].imag * src2[k*n+j].real);
	      }
        }
    }
};

void
Ifx_mtxMulComplexF32 (struct Ifx_mtxMulComplexF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_OPTIMIZED_ASM:
    	Ifx_mtxMulComplexF32_asm(state);
    break;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_mtxMulComplexF32_ref (state);
    break;

    default:
        Ifx_warnAboutUnimplementedMode (mode, "mtxMulComplexF32");
        Ifx_mtxMulComplexF32_ref (state);
        break;
    }
}
