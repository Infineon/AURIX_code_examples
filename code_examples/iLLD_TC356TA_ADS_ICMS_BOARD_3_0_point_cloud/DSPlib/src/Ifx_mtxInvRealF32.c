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
/*! \file Ifx_mtxInvRealF32.c
 *
 * \brief matrix inversion
 *
 * Calculates the Inverse Matrix of the regular Matrix src. dst=src^(-1)
 */

#include "dsplib-internal.h"

/* part1 of option for selecting IFX_ALLOC_TMP_VECTOR
 * or allocating on stack (MEMALLOC 0)
 */
#define MAXN 256
#define MEMALOC 0

void
Ifx_mtxInvRealF32 (struct Ifx_mtxInvRealF32State * state)
{
    enum Ifx_mode mode = state->mode;
    float32 * dst = state->dst;
    float32 * src = state->src;
    uint32 n = state->n;
    uint32 i,j;
#if !MEMALOC
    /* locate variables on stack */
    uint32 pivot[MAXN];
    float32 y[MAXN];
    float32 x[MAXN];
#endif

#if MEMALOC
    IFX_ALLOC_TMP_VECTOR(uint32,pivot,n);
#endif
    struct Ifx_mtxLudRealF32State lud_state = {
        mode, src, n, pivot
    };

#if MEMALOC
    IFX_ALLOC_TMP_VECTOR(float32,y,n);
    IFX_ALLOC_TMP_VECTOR(float32,x,n);
#endif
    struct Ifx_mtxLusRealF32State lus_state = {
        mode, n, src, pivot, y, x
    };

    /* prepare LU decomposition of matrix */
    Ifx_mtxLudRealF32 (&lud_state); /* changes matrix src */

    for (j=0; j<n; j++) {
        /* solve for jth unit vector */
        for (i=0; i<n; i++) {
            y[i] = (i==j ? 1.0f : 0.0f);
        }

        Ifx_mtxLusRealF32 (&lus_state);

        /* copy into result */
        for (i=0; i<n; i++){
            dst[i*n+j] = x[i];
        }
    }
#if MEMALOC
    IFX_FREE_TMP_VECTOR(float32,x,n);
    IFX_FREE_TMP_VECTOR(float32,y,n);
    IFX_FREE_TMP_VECTOR(uint32,pivot,n);
#endif

}
