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
/*! \file Ifx_mtxLusRealF32.c
 *
 * \brief LU-decomposed matrix equation solver
 *
 * solve a linear equation based on a LU decomposed matrix
 *
 * Solves a linear equation of the type Ax=b
 * where A is a matrix and x,b vectors.
 * Rewrite equatione as LUx=Pb.
 * Solve equation Ly=Pb for y then Ux=y for x.
 */

#include "dsplib-internal.h"

#if _MSC_VER
#pragma warning( once : 4018 )
#endif /* _MSC_VER */

void
Ifx_mtxLusRealF32 (struct Ifx_mtxLusRealF32State * state)
{
    uint32 n = state->n;
    float32 * mtx = state->mtx;
    uint32 * piv = state->piv;
    float32 * y = state->y;
    float32 * x = state->x;
    sint32 i,j;
    sint32 idx;
    float32 sum;
    sint32 start = -1;


    /* copy into result */
    for (i=0; i<n; i++)
        x[i] = y[i];

    /* forward substitution */
    for (i=0; i<n; i++) {
        idx = piv[i];
        sum = x[idx];
        x[idx] = x[i]; /* 'unpermute' y on the fly */
        /* only sum elements after non-zero pivot */
        if (start>=0){
            for (j=start; j<i; j++)
                sum -= mtx[i*n+j]*x[j];
        }
        else if (sum!=0.0f) start=i;
        x[i] = sum;
    }

    /* backward substituation */
    for (i=n-1; i>=0 ;i--) {
        sum = x[i];
        for (j=i+1; j<n; j++)
            sum -= mtx[i*n+j]*x[j];
        x[i] = sum/mtx[i*n+i];
    }

}
