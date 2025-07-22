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

/*
 * This function is used in conjunction with the FFT Ifx_fftComlexQ31a.asm
 * to generate the twiddle factors
 */
#include <math.h>
#include "dsplib.h"
#define pi  3.14159265359

/*---------------------------------------------------------------
Function:    TwiddleFactor
Description: Generate twiddle factor array for FFT algorithms.
Returns:     A pointer to complex array of twiddle factors.
----------------------------------------------------------------*/

inline sint32 _FloatToQ31(float x)
{
	unsigned int dataB= 0;
	signed int ret;
	__asm__ volatile ("ftoq31 %0,%1,%2":"=d"(ret):"d"(x),"d"(dataB));
	return ret;
}


csint32* Ifx_tfComplexQ31a(csint32 *TF, int nX )
{
    int i;
    float Theta;

    /* prepare twiddle coefficients */
    for( i = 0; i < nX/2; i++ )
    {
        Theta = 2 * pi * i / nX;

        TF[i].real =  _FloatToQ31(cos(Theta));

        TF[i].imag =  _FloatToQ31(-sin(Theta));

    }

    return TF;
}

/* For test only */
sint32 f2i(float a)
{
  return(_FloatToQ31(a));
}



