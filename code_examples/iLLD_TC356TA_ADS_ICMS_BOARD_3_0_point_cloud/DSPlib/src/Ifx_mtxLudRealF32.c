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
/*! \file Ifx_mtxLudRealF32.c
 *
 * \brief LU decomposition, Crout's algorithm
 *
 * see:
 * Press and Flannery and Teukolsky and Vetterling:
 *   Numerical Recipes in C, 1st edition, Cambridge University Press,
 *   Cambridge, 1988, pages 42ff
 *
 * For input matrix X, finds L and U matrices such that PX = LU
 * Where P is a permutation matrix.
 * A permutation matrix is a square binary matrix that has exactly
 *  one entry 1 in each row and each column and 0s elsewhere.
 * The LUP decomposition makes it easier to solve systems of equations.
 */

#include "dsplib-internal.h"

/* part1 of option for selecting IFX_ALLOC_TMP_VECTOR
 * or allocating on stack (MEMALLOC 0)
 */
#define MAXN 64
#define MEMALOC 0

void
Ifx_mtxLudRealF32 (struct Ifx_mtxLudRealF32State * state)
{
    float32 * mtx = state->mtx;
    uint32 n = state->n;
    uint32 * piv = state->piv;
    uint32 i,j,k, i_max = 0xffffffff;
    uint8 parity = 1;
#if MEMALOC
    IFX_ALLOC_TMP_VECTOR(float32,row_scale,n*n);
#else
    float32 row_scale[MAXN*MAXN];
#endif
    float32 alpha, beta, alpha_max;

    /* initialize pivot table */
    for (i=0; i<n; i++)
        piv[i] = i;

    /* determine row scaling factors */
    for (i=0; i<n; i++) {
        float32 row_max = 0.0f;
        for (j=0; j<n; j++) {
            if (mtx[i*n+j]!=0) {
                float32 my_abs = fabsf (mtx[i*n+j]);
                if (my_abs>row_max)
                    row_max = my_abs;
            }
        }
        if (row_max==0.0) {
            Ifx_error (IFX_ERR_ERROR, "SVD matrix is singular\n");
            return;
        }
        row_scale[i] = 1.0f/row_max;
    }

    /* main loop */
    for (j=0; j<n; j++) { /* loop over columns */
        /* find beta_{i,j} */
        for (i=0; i<j; i++) {
            beta = mtx[i*n+j];
            for (k=0; k<i; k++)
                beta -= mtx[i*n+k]*mtx[k*n+j];
            mtx[i*n+j] = beta;
        }

        /* search pivot */
        alpha_max = 0.0f;
        for (i=j; i<n; i++) {
            beta = mtx[i*n+j];
            for (k=0; k<j; k++)
                beta -= mtx[i*n+k]*mtx[k*n+j];
            mtx[i*n+j] = beta;
            alpha = row_scale[i]*IFX_ABS_F32(beta);
            if (alpha>=alpha_max) {
                /* record potential pivot element */
                alpha_max = alpha;
                i_max = i;
            }
        }

        if (j != i_max) {
            /* interchange rows */
            for (k=0; k<n; k++) {
                float32 tmp = mtx[i_max*n+k];
                mtx[i_max*n+k] = mtx[j*n+k];
                mtx[j*n+k] = tmp;
            }
            parity = !parity;
            row_scale[i_max] = row_scale[j];
        }
        /* record pivot selection */
        piv[j] = i_max;
        /* check if matrix is singular again,
         * may continue with very small value */
        if (mtx[j*n+j] == 0.0) {
            Ifx_error (IFX_ERR_ERROR, "SVD matrix is singular\n");
            mtx[j*n+j] = FLT_EPSILON;
        }

        /* divide by pivot element */
        if (j!=n-1) {
            float32 scale = 1.0f / mtx[j*n+j];
            for (i=j+1; i<n; i++)
                mtx [i*n+j] *= scale;
        }
    }
#if MEMALOC
    IFX_FREE_TMP_VECTOR(float32,row_scale,n*n);
#endif
}
