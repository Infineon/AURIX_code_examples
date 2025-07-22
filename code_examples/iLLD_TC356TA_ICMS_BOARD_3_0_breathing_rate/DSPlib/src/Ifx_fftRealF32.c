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
/*! \file Ifx_fftRealF32.c
 *
 * \brief FFT of real floating point values
 *
 * An FFT (Fast Fourier Transform) calculates the frequency spectrum of a signal,
 * as a signal usually consists of many different periodic functions with different
 * frequencies. It is a computationally efficient discrete Fourier transform (DFT).
 * from numerical recipes in C
 *
 * See "Numerical Recipes in C", 2nd ed., algorithm realft, p. 417f.
 *
 */

#include "dsplib-internal.h"

#if HAVE_LIBFFTW
# include <fftw3.h>
#endif /* HAVE_LIBFFTW */

static void
Ifx_fftRealF32_ref (struct Ifx_fftRealF32State * state)
{
    /* parameters from caller */
    enum Ifx_mode mode = state->mode;
    float32 * x = state->x;
    float32 * y = state->y;
    uint32 n = state->n;
    /* intermediate complex FFT */
    struct Ifx_fftComplexF32State fft_state;
    /* rearrangement postprocessing */
    uint32 i, n2 = n>>1, n4 = n>>2;
    float32 temp;
    cfloat32 ctemp, h1, h2, twiddle, *data = (cfloat32*) y;
        
    /* perform complex FFT */
    fft_state.mode = mode;
    fft_state.y = (cfloat32*) y;
    fft_state.x = (cfloat32*) x;
    fft_state.n = n2;
    Ifx_fftComplexF32 (&fft_state);


    /* postprocessing */
    for (i=1; i<n4; i++) {
        IFX_CRU_F32(twiddle,i,n);
        h1.real =  0.5f*(data[i].real + data[n2-i].real);
        h1.imag =  0.5f*(data[i].imag - data[n2-i].imag);
        h2.real =  0.5f*(data[i].imag + data[n2-i].imag);
        h2.imag = -0.5f*(data[i].real - data[n2-i].real);
        data[i].real    =  h1.real +twiddle.real*h2.real -twiddle.imag*h2.imag;
        data[i].imag    =  h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real;
        data[n2-i].real =  h1.real -twiddle.real*h2.real +twiddle.imag*h2.imag;
        data[n2-i].imag = -h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real;
    }
	
    data[n4].imag = -data[n4].imag;

    /* implementation postprocessing */
    temp=data[0].real;
    data[0].real = temp+data[0].imag;
    data[0].imag = temp-data[0].imag;

}

void
Ifx_fftRealF32 (struct Ifx_fftRealF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
# if HAVE_LIBFFTW
    case IFX_MODE_EXTERNAL_LIBRARY:
    {
        int i;
        double *data;
        fftw_complex *result;
        fftw_plan plan;

        data   = ( double* ) fftw_malloc( sizeof( double ) * state->n );
        result = ( fftw_complex* ) fftw_malloc( sizeof( fftw_complex ) * (state->n/2+1) );
        plan   = fftw_plan_dft_r2c_1d(state->n, data, result, FFTW_ESTIMATE);

        /* populate input data */
        for (i=0; i<state->n ; ++i)
            data[i] = (double) state->x[i];
     
        fftw_execute( plan );

        /* copy result */
        state->y[0] = result[0][0];
        Ifx_assert (result[0][1]==0.0f);
        state->y[1] = result[state->n/2][0];
        Ifx_assert (result[state->n/2][1]==0.0f);
        for (i=1; i<state->n ; ++i) {
            state->y[2*i] = result[i][0];
            state->y[2*i+1] = result[i][1];
        }        

        fftw_destroy_plan (plan);
        fftw_free (data);
        fftw_free (result);     

        return;
    }
# endif /* HAVE_LIBFFTW */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_fftRealF32_ref (state);
        break;
	default:
        Ifx_warnAboutUnimplementedMode (mode, "fftRealF32");
        Ifx_fftRealF32_ref (state);
    }
}
