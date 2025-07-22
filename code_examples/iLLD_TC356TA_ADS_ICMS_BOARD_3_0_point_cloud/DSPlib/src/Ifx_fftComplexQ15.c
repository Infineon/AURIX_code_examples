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
/*! \file Ifx_fftComplexQ15.c
 *
 * \brief FFT on complex Q15 values.
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

#if HAVE_LIBFFTW
# include <fftw3.h>
#endif /* HAVE_LIBFFTW */

/* eval is used by the FFT function below */
static void
evalQ15(csint16 *data, uint32 n)
{
    uint32 i,istep, j, k,kmax;
    csint16 temp, twiddle;
	
    /* bit-reverse shuffle */
    for (i=0,j=0; i<n; i++) {
        if (j > i) {
            temp=data[j];
            data[j]=data[i];
            data[i]=temp;
        }
        for (k=n>>1; 1<=k && k<=j; k>>=1)
            j -= k;
        j += k;
    }

    /* FFT iteration */
    for (kmax=1; kmax<n; kmax=istep) { 
        istep=kmax<<1;
		
        for (k=0; k<kmax; k++) {
            IFX_CRU_Q15(twiddle,k,istep);
            for (i=k; i<n; i+=istep) {
                j=i+kmax;
                IFX_CMUL_Q15(temp, twiddle, data[j]);
                IFX_CSUB_Q15(data[j], data[i], temp);
                IFX_CADD_Q15(data[i], data[i], temp);
            }
        }
    }
}

static void
Ifx_fftComplexQ15_ref (struct Ifx_fftComplexQ15State * state)
{
    csint16 * x = state->x;
    csint16 * y = state->y;
    uint32 n = state->n;
    uint32 i;
    for(i=0;i<n;i++)
        y[i]=x[i];
	
    evalQ15(y, n);
}

void
Ifx_fftComplexQ15 (struct Ifx_fftComplexQ15State * state)
{
	enum Ifx_mode mode = state->mode;
    switch (mode) {
#if HAVE_LIBFFTW
    case IFX_MODE_EXTERNAL_LIBRARY :
    {
		int i;
        fftw_complex *data, *result;
        fftw_plan plan;
        double scale = 32767.0 / state->n;

        data   = ( fftw_complex* ) fftw_malloc( sizeof( fftw_complex ) * state->n );
        result = ( fftw_complex* ) fftw_malloc( sizeof( fftw_complex ) * state->n );
        plan   = fftw_plan_dft_1d(state->n, data, result, FFTW_FORWARD, FFTW_ESTIMATE);

        /* populate input data */
        for (i=0; i<state->n ; ++i) {
            data[i][0] = (double) state->x[i].real / 32767.0;
            data[i][1] = (double) state->x[i].imag / 32767.0;
        }
     
        fftw_execute( plan );

        /* copy result */
        for (i=0; i<state->n ; ++i) {
            state->y[i].real = result[i][0] * scale;
            state->y[i].imag = result[i][1] * scale;
        }        

        fftw_destroy_plan (plan);
        fftw_free (data);
        fftw_free (result);   
       
    }
	break;
# endif /* HAVE_LIBFFTW */

#if IFX_TRICORE_TARGET
    case IFX_MODE_OPTIMIZED_ASM :
	{
    	switch(state->n){

		/* All the implemented following variants overwrite input signal x */
		case 16:
				Ifx_fftComplexQ15_16hp (state->y,    /*!< OUT vector[16] result. Frequency spectrum */
										state->x);   /*!< IN  vector[16] signal input */
				break;

		case 32:
				Ifx_fftComplexQ15_32hp (state->y,    /*!< OUT vector[16] result. Frequency spectrum */
										state->x);   /*!< IN  vector[16] signal input */
				break;

		case 64:
				Ifx_fftComplexQ15_64hp (state->y,    /*!< OUT vector[16] result. Frequency spectrum */
										state->x);   /*!< IN  vector[16] signal input */
				break;

		case 128:
				Ifx_fftComplexQ15_128hp (state->y,   /*!< OUT vector[16] result. Frequency spectrum */
										state->x);   /*!< IN  vector[16] signal input */
				break;

		case 256:
				Ifx_fftComplexQ15_256hp (state->y,   /*!< OUT vector[16] result. Frequency spectrum */
										state->x);   /*!< IN  vector[16] signal input */
				break;

		case 512:
				Ifx_fftComplexQ15_512hp (state->y,   /*!< OUT vector[16] result. Frequency spectrum */
										state->x);   /*!< IN  vector[16] signal input */
				break;

		case 1024:
				Ifx_fftComplexQ15_1024hp (state->y,   /*!< OUT vector[16] result. Frequency spectrum */
										state->x);  /*!< IN  vector[16] signal input */
				break;
		}
	}	

	break;
#ifdef HWFFT
    case IFX_MODE_HARDWARE_ACCELERATOR:
        Ifx_hwfftComplexQ15 (state, &fftJobConfig);
        break;
#endif /* HWFFT */

#endif /* IFX_TRICORE_TARGET */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
		Ifx_fftComplexQ15_ref (state);
		return;
	default:
        Ifx_warnAboutUnimplementedMode (mode, "fftComplexQ15");
		Ifx_fftComplexQ15_ref (state);
		return;
	}
}
