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
/*! \file Ifx_fftComplexF32.c
 *
 * \brief perform FFT on complex float values
 *
 * An FFT (Fast Fourier Transform) calculates the frequency spectrum of a signal,
 * as a signal usually consists of many different periodic functions with different
 * frequencies. It is a computationally efficient discrete Fourier transform (DFT).
 * The algorithm is after Cooley-Tukey.
 * See www.inf.fh-flensburg.de/lang/algorithmen/fft/fft.htm
 */

#include "dsplib-internal.h"

#if HAVE_LIBFFTW
# include <fftw3.h>
#endif /* HAVE_LIBFFTW */

/* eval is used by the FFT function below */
static void
evalF32(cfloat32 * data, uint32 n)
{
    uint32 i,istep, j, k,kmax;
    cfloat32 temp, twiddle;

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
            IFX_CRU_F32(twiddle,k,istep);
            for (i=k; i<n; i+=istep) {
                j=i+kmax;
                IFX_CMUL_F32(temp, twiddle, data[j]);
                IFX_CSUB_F32(data[j], data[i], temp);
                IFX_CADD_F32(data[i], data[i], temp);
            }
        }
    }
}

static void
Ifx_fftComplexF32_ref (struct Ifx_fftComplexF32State * state)
{
    cfloat32 * x = state->x;
    cfloat32 * y = state->y;
    uint32 n = state->n;
    uint32 i;

    for(i=0;i<n;i++)
        y[i]=x[i];

    evalF32(y, n);
}

void
Ifx_fftComplexF32 (struct Ifx_fftComplexF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
# if HAVE_LIBFFTW
    case IFX_MODE_EXTERNAL_LIBRARY:
    {
        int i;
        fftw_complex *data, *result;
        fftw_plan plan;

        data   = ( fftw_complex* ) fftw_malloc( sizeof( fftw_complex ) * state->n );
        result = ( fftw_complex* ) fftw_malloc( sizeof( fftw_complex ) * state->n );
        plan   = fftw_plan_dft_1d(state->n, data, result, FFTW_FORWARD, FFTW_ESTIMATE);

        /* populate input data */
        for (i=0; i<state->n ; ++i) {
            data[i][0] = (double) state->x[i].real;
            data[i][1] = (double) state->x[i].imag;
        }
     
        fftw_execute( plan );

        /* copy result */
        for (i=0; i<state->n ; ++i) {
            state->y[i].real = result[i][0];
            state->y[i].imag = result[i][1];
        }        

        fftw_destroy_plan (plan);
        fftw_free (data);
        fftw_free (result);     

        return;
    }
    break;
# endif /* HAVE_LIBFFTW */

    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_fftComplexF32_ref (state);
        return;

    default: 
        Ifx_warnAboutUnimplementedMode (mode, "fftComplexF32");
        Ifx_fftComplexF32_ref (state);
        return;
    }
}
