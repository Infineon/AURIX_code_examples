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
/*! \file Ifx_kalman.c
 *
 * \brief Kalman filter
 *
 * The Kalman filter eliminates the disturbance of input signals to find
 * the statistically optimal signal of the underlying system state.
 *
 *   PART 1: Prediction
 *      STEP 1: x_apri = a*x_apos + b*u
 *      STEP 2: p_apri = a*p_apos*(a_trp) + q
 *                       where a_trp stands for the transpose of a
 *   PART 2: Correction
 *      STEP 3: k = p_apri*(c_trp)*(c*p_apri*(c_trp) + r)^(-1)
 *      STEP 4: x_apos = x_apri + k*(y-c*x_apri)
 *      STEP 5: p_apos = (id - k*c)*p_apri
 *                       where id stands for the unit matrix
 *
 * Sources:
 * \li Bakkalaureatsarbeit "Implementierung eines Kalman Filters zur Positionsbestimmung eines Modellautos" by Josef M. Trojer, TU Wien
 * \li "An Introduction to the Kalman Filter" by Greg Welch and Gary Bishop, University of North Carolina at Chapel Hill
 * \li "Kalman Filter - Ortsbezogene Anwendungen und Dienste" by Stephan Meyer, Georg-Simon-Ohm-Hochschule Nürnberg
 * \li "Kalman Filtering - Implementation with Matlab" by Rachel Kleinbauer, Universität Stuttgart
 *
 */

#include "dsplib-internal.h"

#define DO_FILEIO 1

static void
Ifx_kalman_ref (struct Ifx_kalmanState * state)
{
    float32 * x = state->x;
    float32 * a = state->a;
    float32 * b = state->b;
    float32 * u = state->u;
    float32 * q = state->q;
    float32 * y = state->y;
    float32 * c = state->c;
    float32 * r = state->r;
    float32 * p = state->p;
    uint32 n = state->n;
    uint32 m = state->m;
    uint32 l = state->l;

    uint32 i,j;
    IFX_ALLOC_TMP_VECTOR(float32,x_apos,n);       /* measurement vector from matrix y */
    IFX_ALLOC_TMP_VECTOR(float32,p_apos,n*n); 
    IFX_ALLOC_TMP_VECTOR(float32,x_apr,n);
    IFX_ALLOC_TMP_VECTOR(float32,bu,n);          /* step 1.2 */
    IFX_ALLOC_TMP_VECTOR(float32,ap,n*n);        /* step 2.1 */
    IFX_ALLOC_TMP_VECTOR(float32,a_trp,n*n);     /* step 2.2 */
    IFX_ALLOC_TMP_VECTOR(float32,apa_trp,n*n);   /* step 2.3 */
    IFX_ALLOC_TMP_VECTOR(float32,p_apr,n*n);     /* step 2.4 */
    IFX_ALLOC_TMP_VECTOR(float32,c_trp,m*n);     /* step 3.1 */
    IFX_ALLOC_TMP_VECTOR(float32,p_aprc_trp,n*m);/* step 3.2 */
    IFX_ALLOC_TMP_VECTOR(float32,cp_aprc_trp,m*m); /* step 3.3 */
    IFX_ALLOC_TMP_VECTOR(float32,denom,m*m);     /* step 3.4 */
    IFX_ALLOC_TMP_VECTOR(float32,denom_inv,m*m); /* step 3.5 */
    IFX_ALLOC_TMP_VECTOR(float32,k,n*m);         /* step 3.6 */
    IFX_ALLOC_TMP_VECTOR(float32,cx_apr,m);      /* step 4.1 */
    IFX_ALLOC_TMP_VECTOR(float32,diff,m);        /* step 4.2 */
    IFX_ALLOC_TMP_VECTOR(float32,kdiff,n);       /* step 4.3 */
    IFX_ALLOC_TMP_VECTOR(float32,kc,n*n);        /* step 5.1 */
    IFX_ALLOC_TMP_VECTOR(float32,iddiff,n*n);    /* step 5.2 */
    IFX_ALLOC_TMP_VECTOR(float32,id,n*n);        /* float needed for mtxSub_ */

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            id[i*n+j] = ( i==j ? 1.0f : 0.0f );

    /* The IN vector x describes the x_apos for the first Kalman-cycle */
    for (i=0;i<n;i++)
        x_apos[i] = x[i];

    /* The IN vector p describes the p_apos for the first Kalman-cycle */
    for (i=0;i<(n*n);i++)
        p_apos[i] = p[i];

    /* begin of Kalman-cycle */

    /* PART 1: PREDICTION */

    /* STEP 1 make a prediciton x_apr = A*x_apost + b*u  */

    /* STEP 1.1 x_apr = a*x_apos, [nx1]=[nxn]*[nx1] */
    {
        struct Ifx_mtxMulRealF32State state_step11 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            x_apr, a, x_apos, n, 1, n
        };
        Ifx_mtxMulRealF32 (&state_step11);
    }

    /* STEP 1.2 bu = b*u [nx1]=[nxl]*[lx1] */
    {
        struct Ifx_mtxMulRealF32State state_step12 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            bu, b, u, n, 1, l
        };
        Ifx_mtxMulRealF32 (&state_step12);
    }

    /* STEP 1.3 x_apr = x_apr + bu. x_apr is of type [nx1] */
    {
        struct Ifx_mtxAddRealF32State state_step13 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            x_apr, x_apr,bu, n, 1
        };
        Ifx_mtxAddRealF32 (&state_step13);
    }

    /* STEP 2 calculate the matrix p_apr = a*(p_apos)*(a_trp) + q,
     * a_trp stands of the transpose of a.  */

    /* STEP 2.1 ap = a*p_apos. ap is of type [nxn]=[nxn]*[nxn] */
    {
        struct Ifx_mtxMulRealF32State state_step21 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            ap, a, p_apos, n, n, n
        };
        Ifx_mtxMulRealF32 (&state_step21);
    }

    /* STEP 2.2 calculate transpose of a: a_trp. a_trp is of type [nxn] */
    {
        struct Ifx_mtxTrpRealF32State state_step22 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            a, a_trp, n, n
        };
        Ifx_mtxTrpRealF32 (&state_step22);
    }

    /* STEP 2.3 calculate the product apa_trp = (a*p_apos)*a_trp.
     * apa_trp is of type [nxn] */
    {
        struct Ifx_mtxMulRealF32State state_step23 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            apa_trp, ap, a_trp, n, n, n
        };
        Ifx_mtxMulRealF32 (&state_step23);
    }

    /* STEP 2.4 Calculate the final matrix p_apr by summing up:
     * p_apr = a*(p_apos)*a_trp + q  */
    {
        struct Ifx_mtxAddRealF32State state_step24 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            p_apr, apa_trp,q, n, n
        };
        Ifx_mtxAddRealF32 (&state_step24);
    }

    /* PART 3: The Prediction  */

    /* STEP 3: Calculating the Kalman-Gain
     * K = p_apr*(c_trp)*(c*p_apr*(c_trp) + r)^(-1) */

    /* STEP 3.1: Calculate the transpose of c: c_trp.
     * c_trp is of type nxm */
    {
        struct Ifx_mtxTrpRealF32State state_step31= {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            c, c_trp, m, n
        };
        Ifx_mtxTrpRealF32(&state_step31);
    }

    /* STEP 3.2: p_aprc_trp = p_apr*(c_trp), [nxm]=[nxn]*[nxm] */
    {
        struct Ifx_mtxMulRealF32State state_step32 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            p_aprc_trp, p_apr, c_trp, n, m, n
        };
        Ifx_mtxMulRealF32 (&state_step32);
    }

    /* STEP 3.3: cp_aprc_trp = c*p_apr*(c_trp), [mxm]=[mxn]*[nxm] */
    {
        struct Ifx_mtxMulRealF32State state_step33 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            cp_aprc_trp, c, p_aprc_trp, m, m, n
        };
        Ifx_mtxMulRealF32 (&state_step33);
    }

    /* STEP 3.4: add r to get the denominator.
     * denom & r are of type [mxm] */
    {
        struct Ifx_mtxAddRealF32State state_step34 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            denom, cp_aprc_trp,r, m, m
        };
        Ifx_mtxAddRealF32 (&state_step34);
    }

    /* STEP 3.5: Calculate the inverse of the denominator denom. */
    {
        struct Ifx_mtxInvRealF32State state_step35 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            denom_inv, denom, m
        };
        Ifx_mtxInvRealF32(&state_step35);
    }

    /* STEP 3.6: Multiply the Kalman gain by multiplication:
     * k=(p_aprc_trp)*(denom_inv). [nxm]=[nxm]*[mxm] */
    {
        struct Ifx_mtxMulRealF32State state_step36 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            k, p_aprc_trp, denom_inv, n, m, m
        };
        Ifx_mtxMulRealF32 (&state_step36);
    }

    /* STEP 4: Calculate x_apos = x_apr +k*(y-c*x_apr),
     * where y is the vector with the measurement */

    /* STEP 4.1: calculate cx_apr=c*(x_apr), [mx1]=[mxn]*[nx1] */
    {
        struct Ifx_mtxMulRealF32State state_step41 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            cx_apr, c, x_apr, m, 1, n
        };
        Ifx_mtxMulRealF32 (&state_step41);
    }

    /* STEP 4.2: substract cx_apr from the measurement
     * vector diff=y-cx_apr */

    {
        struct Ifx_mtxSubRealF32State state_step42 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            diff,y,cx_apr, m, 1
        };
        Ifx_mtxSubRealF32 (&state_step42);
    }

    /* STEP 4.3: kdiff = k*diff  [nx1]=[nxm]*[mx1] */

    {
        struct Ifx_mtxMulRealF32State state_step43 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            kdiff,k, diff, n, 1, m
        };
        Ifx_mtxMulRealF32 (&state_step43);
    }

    /* STEP 4.4: x_apos = x_apr + kdiff */
    {
        struct Ifx_mtxAddRealF32State state_step44 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            x, x_apr,kdiff, n, 1
        };
        Ifx_mtxAddRealF32 (&state_step44);
    }

    /* STEP 5: Calculate p_apos = (id - k*c)*p_apr.
     * id is the unit matrix. */

    /* STEP 5.1 Calculate the product kc = k*c [nxn]=[nxm]*[mxn] */
    {
        struct Ifx_mtxMulRealF32State state_step51 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            kc,k,c, n, n, m
        };
        Ifx_mtxMulRealF32 (&state_step51);
    }

    /* STEP 5.2: Calculate the difference iddiff = id-kc */
    {
        struct Ifx_mtxSubRealF32State state_step52 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            iddiff,id,kc, n, n
        };
        Ifx_mtxSubRealF32 (&state_step52);
    }

    /* STEP 5.3: p_apos = iddiff*p_apr */
    {
        struct Ifx_mtxMulRealF32State state_step53 = {
			IFX_MODE_REFERENCE_IMPLEMENTATION,
            p,iddiff,p_apr, n, n, n
        };
        Ifx_mtxMulRealF32 (&state_step53);
    }
}

void Ifx_kalman (struct Ifx_kalmanState * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "kalman");
        Ifx_kalman_ref (state);
        break;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_kalman_ref (state);
        break;
    }
}
