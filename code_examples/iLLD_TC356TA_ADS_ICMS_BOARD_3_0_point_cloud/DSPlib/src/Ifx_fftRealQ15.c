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
/*! \file Ifx_fftRealQ15.c
 *
 * \brief FFT of real Q15 values
 *
 * An FFT (Fast Fourier Transform) calculates the frequency spectrum of a signal,
 * as a signal usually consists of many different periodic functions with different
 * frequencies. It is a computationally efficient discrete Fourier transform (DFT).
 * from numerical recipes in C
 *
 * Input : x[0...N-1]
 * Output : positive frequency half of its Fourier Transform. y[0...N-1]
 * The real-valued first and last components of the complex transform are returned as elements y[0] and y[1],
 * respectively.
 * To have the entire spectrum : F[N-n]* = F[n] 
 *
 * See "Numerical Recipes in C", 2nd ed., algorithm realft, p. 536.
 *
 */

#include "dsplib-internal.h"
#ifdef HWFFT
#include "Ifx_hwfftAccelerator.h"
#endif /* HWFFT */

static void Ifx_fftRealQ15_ref (struct Ifx_fftRealQ15State * state)
{
    /* parameters from caller */
	enum Ifx_mode mode = state->mode;
	sint16 * x = state->x;
    csint16 * y = state->y;
    uint32 n = state->n;

    sint16 c1=0x4000;  /*0.5*/
    sint16 c2=0xc000;  /*-0.5*/

    /* intermediate complex FFT */
    struct Ifx_fftComplexQ15State fft_state;
    /* rearrangement postprocessing */
    uint32 i, n2 = n>>1, n4 = n>>2;
    sint16 temp,temp1,temp2,temp3,temp4;
    csint16 h1, h2;
    csint16 ctemp, twiddle, *data = (csint16*) y;

    /* perform complex FFT */
    fft_state.mode = mode;
    fft_state.y = (csint16*) y;
    fft_state.x = (csint16*) x;
    fft_state.n = n2;
    Ifx_fftComplexQ15 (&fft_state);


/*
    implementation post processing - reference code
    for (i=1; i<n4; i++) {
        // Part1
    	IFX_CRU_F32(twiddle,i,n);
        h1.real =  0.5f*(data[i].real + data[n2-i].real);
        h1.imag =  0.5f*(data[i].imag - data[n2-i].imag);
        h2.real =  0.5f*(data[i].imag + data[n2-i].imag);
        h2.imag = -0.5f*(data[i].real - data[n2-i].real);
        // Part2
        data[i].real    =  h1.real +twiddle.real*h2.real -twiddle.imag*h2.imag;
        data[i].imag    =  h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real;
        data[n2-i].real =  h1.real -twiddle.real*h2.real +twiddle.imag*h2.imag;
        data[n2-i].imag = -h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real;
    }
*/
    for (i=1; i<n4; i++) {

        /* Q15 implementation post processing part1 */
    	IFX_CRU_Q15(twiddle,i,n);

    	//----------------
    	/* h1.real =  0.5f*(data[i].real + data[n2-i].real); */
    	IFX_ADD_Q15(h1.real,data[i].real,data[n2-i].real);
    	IFX_MUL_Q15(h1.real,c1,h1.real);

    	/* h1.imag =  0.5f*(data[i].imag - data[n2-i].imag); */
    	IFX_SUB_Q15(h1.imag,data[i].imag,data[n2-i].imag);
    	IFX_MUL_Q15(h1.imag,c1,h1.imag);

    	//----------------
    	/* h2.real =  0.5f*(data[i].imag + data[n2-i].imag); */
    	IFX_ADD_Q15(h2.real,data[i].imag,data[n2-i].imag);
    	IFX_MUL_Q15(h2.real,c1,h2.real);

    	/* h2.imag = -0.5f*(data[i].real - data[n2-i].real); */
    	IFX_SUB_Q15(h2.imag,data[i].real,data[n2-i].real);
    	IFX_MUL_Q15(h2.imag,c2,h2.imag);

    	/*------------------------------------------*/
        /* Q15 implementation post processing part2 */

	    //data[i].real =  h1.real +twiddle.real*h2.real -twiddle.imag*h2.imag;
    	IFX_MUL_Q15(temp1,twiddle.real,h2.real);
    	IFX_MUL_Q15(temp2,twiddle.imag,h2.imag);
		data[i].real = h1.real+temp1-temp2;

     	//data[i].imag =  h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real;
     	IFX_MUL_Q15(temp3,twiddle.real,h2.imag);
     	IFX_MUL_Q15(temp4,twiddle.imag,h2.real);
		data[i].imag = h1.imag+temp3+temp4;

    	//data[n2-i].real = h1.real -twiddle.real*h2.real +twiddle.imag*h2.imag;
		data[n2-i].real = h1.real -(temp1-temp2);

    	//F32 data[n2-i].imag = -h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real;
		data[n2-i].imag = -h1.imag+temp3+temp4;

    }

    data[n4].real = data[n4].real/2;
    data[n4].imag = -data[n4].imag/2;

    /* implementation postprocessing */
    temp=data[0].real;
    data[0].real = (temp+data[0].imag)/2;
    data[0].imag = (temp-data[0].imag)/2;
}

void Ifx_fftRealQ15 (struct Ifx_fftRealQ15State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
#ifdef HWFFT
    case IFX_MODE_HARDWARE_ACCELERATOR:
	{	
        Ifx_hwfftRealQ15 (state, &fftJobConfig);
        return;
	}
#endif /* HWFFT */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
    	Ifx_fftRealQ15_ref (state);
		break;
	default:
        Ifx_warnAboutUnimplementedMode (mode, "fftRealQ15");
        Ifx_fftRealQ15_ref (state);
    }
}
