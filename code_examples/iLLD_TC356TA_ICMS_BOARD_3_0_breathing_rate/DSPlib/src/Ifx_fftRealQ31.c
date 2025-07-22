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
/*! \file Ifx_fftRealQ31.c
 *
 * \brief FFT of real Q31 values
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
#ifdef HWFFT
#include "Ifx_hwfftAccelerator.h"
#endif /* HWFFT */

static void
Ifx_fftRealQ31_ref (struct Ifx_fftRealQ31State * state)
{
    /* parameters from caller */
	enum Ifx_mode mode = state->mode;
	sint32 * x = state->x;
    sint32 * y = state->y;
    uint32 n = state->n;

    sint32 c1=0x40000000;  /*0.5*/
    sint32 c2=0xc0000000;  /*-0.5*/

    /* intermediate complex FFT */
    struct Ifx_fftComplexQ31State fft_state;
    /* rearrangement postprocessing */
    uint32 i, n2 = n>>1, n4 = n>>2;
    sint32 temp,temp1,temp2,temp3,temp4;
    csint32 h1, h2;
    csint32 ctemp, twiddle, *data = (csint32*) y;

    /* perform complex FFT */
    fft_state.mode = mode;
    fft_state.y = (csint32*) y;
    fft_state.x = (csint32*) x;
    fft_state.n = n2;
    Ifx_fftComplexQ31 (&fft_state);


/*
    implementation post processing - reference code
    for (i=1; i<n4; i++) {
        Part1
    	IFX_CRU_F32(twiddle,i,n);
        h1.real =  0.5f*(data[i].real + data[n2-i].real);
        h1.imag =  0.5f*(data[i].imag - data[n2-i].imag);
        h2.real =  0.5f*(data[i].imag + data[n2-i].imag);
        h2.imag = -0.5f*(data[i].real - data[n2-i].real);
        Part2
        data[i].real    =  h1.real +twiddle.real*h2.real -twiddle.imag*h2.imag;
        data[i].imag    =  h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real;
        data[n2-i].real =  h1.real -twiddle.real*h2.real +twiddle.imag*h2.imag;
        data[n2-i].imag = -h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real;
    }
*/
    for (i=1; i<n4; i++) {

        /* Q31 implementation post processing part1 */
    	IFX_CRU_Q31(twiddle,i,n);

    	/* h1.real =  0.5f*(data[i].real + data[n2-i].real); */
    	IFX_ADD_Q31(h1.real,data[i].real,data[n2-i].real);
    	IFX_MUL_Q31(h1.real,c1,h1.real);

    	/* h1.imag =  0.5f*(data[i].imag - data[n2-i].imag); */
    	IFX_SUB_Q31(h1.imag,data[i].imag,data[n2-i].imag);
    	IFX_MUL_Q31(h1.imag,c1,h1.imag);

    	/*----------------*/
    	/* h2.real =  0.5f*(data[i].imag + data[n2-i].imag); */
    	IFX_ADD_Q31(h2.real,data[i].imag,data[n2-i].imag);
    	IFX_MUL_Q31(h2.real,c1,h2.real);

    	/* h2.imag = -0.5f*(data[i].real - data[n2-i].real); */
    	IFX_SUB_Q31(h2.imag,data[i].real,data[n2-i].real);
    	IFX_MUL_Q31(h2.imag,c2,h2.imag);

    	/*------------------------------------------*/
        /* Q31 implementation post processing part2 */

	    /* data[i].real =  h1.real +twiddle.real*h2.real -twiddle.imag*h2.imag; */
    	IFX_MUL_Q31(temp1,twiddle.real,h2.real);
    	IFX_MUL_Q31(temp2,twiddle.imag,h2.imag);
    	data[i].real = h1.real+temp1-temp2;

     	/* data[i].imag =  h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real; */
     	IFX_MUL_Q31(temp3,twiddle.real,h2.imag);
     	IFX_MUL_Q31(temp4,twiddle.imag,h2.real);
    	data[i].imag = h1.imag+temp3+temp4;

    	/* data[n2-i].real = h1.real -twiddle.real*h2.real +twiddle.imag*h2.imag; */
    	data[n2-i].real = h1.real -(temp1-temp2);

    	/* data[n2-i].imag = -h1.imag +twiddle.real*h2.imag +twiddle.imag*h2.real; */
    	data[n2-i].imag = -h1.imag+temp3+temp4;

    }

    data[n4].real = data[n4].real/2;
    data[n4].imag = -data[n4].imag/2;

    /* implementation postprocessing */
    temp=data[0].real;
    data[0].real = (temp+data[0].imag)/2;
    data[0].imag = (temp-data[0].imag)/2;
}

void
Ifx_fftRealQ31 (struct Ifx_fftRealQ31State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
#ifdef HWFFT
    case IFX_MODE_HARDWARE_ACCELERATOR:
        Ifx_hwfftRealQ31 (state, &fftJobConfig);
        break;
#endif /* HWFFT */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
    	Ifx_fftRealQ31_ref (state);
    	break;
    default:
        Ifx_warnAboutUnimplementedMode (mode, "fftRealQ31");
    	Ifx_fftRealQ31_ref (state);
    	break;
    }
}
