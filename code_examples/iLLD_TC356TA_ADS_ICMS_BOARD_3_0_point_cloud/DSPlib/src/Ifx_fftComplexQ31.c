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
/*! \file Ifx_fftComplexQ31.c
 *
 * \brief FFT on complex Q31 values.
 *
 * An FFT (Fast Fourier Transform) calculates the frequency spectrum of a signal,
 * as a signal usually consists of many different periodic functions with different
 * frequencies. It is a computationally efficient discrete Fourier transform (DFT).
 * The algorithm is after Cooley-Tukey.
 * from www.inf.fh-flensburg.de/lang/algorithmen/fft/fft.htm
 */

#include "dsplib-internal.h"
#ifdef HWFFT
#include "Ifx_hwfftAccelerator.h"
#endif /* HWFFT */


/* eval is used by the FFT function below */
static void
evalQ31(csint32 *data, uint32 n)
{
    uint32 i,istep, j, k,kmax;
    csint32 temp, twiddle;

    /* bit-reverse shuffle */
    for (i=0,j=0; i<n; i++) {
        if (j > i) {
            temp=data[j];
            data[j]=data[i];
            data[i]=temp;
        }
        for (k=n>>1; 1<=k&&k<=j; k>>=1)
            j -= k;
        j += k;
    }
    /* FFT iteration */
    for (kmax=1; kmax<n; kmax=istep) {
        istep=kmax<<1;
        for (k=0; k<kmax; k++) {
            IFX_CRU_Q31(twiddle,k,istep);
            for (i=k; i<n; i+=istep) {
                j=i+kmax;
                IFX_CMUL_Q31(temp, twiddle, data[j]);
                IFX_CSUB_Q31(data[j], data[i], temp);
                IFX_CADD_Q31(data[i], data[i], temp);
            }
        }
    }
}

static void
Ifx_fftComplexQ31_ref (struct Ifx_fftComplexQ31State * state)
{
    csint32 * x = state->x;
    csint32 * y = state->y;
    uint32 n = state->n;
    uint32 i;

    for(i=0;i<n;i++)
        y[i]=x[i];

    evalQ31(y, n);
}

void
Ifx_fftComplexQ31 (struct Ifx_fftComplexQ31State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {

    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_fftComplexQ31_ref (state);
        break;
    case IFX_MODE_OPTIMIZED_ASM:
    	Ifx_fftComplexQ31a (state);
        break;
#ifdef HWFFT
    case IFX_MODE_HARDWARE_ACCELERATOR:
        Ifx_hwfftComplexQ31 (state, &fftJobConfig);
        break;
#endif /* HWFFT */
    default:
        Ifx_warnAboutUnimplementedMode (mode, "fftComplexQ31");
        Ifx_fftComplexQ31_ref (state);
        break;
    }
}
