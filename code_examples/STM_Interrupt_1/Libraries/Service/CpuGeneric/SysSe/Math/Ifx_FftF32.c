/**
 * \file Ifx_FftF32.c
 * \brief Floating-point Fast Fourier Transform
 *
 *
 * \version disabled
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#include "Ifx_FftF32.h"
#include <math.h>

//#include "Compiler.h"

cfloat32 *Ifx_FftF32_generateTwiddleFactor(cfloat32 *TF, short nX)
{
    int    i;
    double Theta;

    // prepare twiddle coefficients
    for (i = 0; i < nX / 2; i++)
    {
        Theta      = 2 * IFX_PI * i / nX;

        TF[i].real = (float32)(cosf(Theta));
        TF[i].imag = (float32)(-sinf(Theta));
    }

    return TF;
}


/******************************************************************************/
unsigned short Ifx_FftF32_reverseBits(unsigned short n, unsigned bits)
{
    /* This code is from:
     * http://graphics.stanford.edu/~seander/bithacks.html
     * */
    unsigned long v = n; // 32-bit word to reverse bit order

    // swap odd and even bits
    v = ((v >> 1) & 0x55555555UL) | ((v & 0x55555555UL) << 1);
    // swap consecutive pairs
    v = ((v >> 2) & 0x33333333UL) | ((v & 0x33333333UL) << 2);
    // swap nibbles ...
    v = ((v >> 4) & 0x0F0F0F0FUL) | ((v & 0x0F0F0F0FUL) << 4);
    // swap bytes
    v = ((v >> 8) & 0x00FF00FFUL) | ((v & 0x00FF00FFUL) << 8);
    // swap 2-byte long pairs
    v = (v >> 16) | (v << 16);

    v = v >> (32 - bits);
    return (unsigned short)v;
}


/******************************************************************************/
void Ifx_FftF32_radix2DecimationInTime(cfloat32 *R, unsigned long p)
{
    /* http://www.engineeringproductivitytools.com/stuff/T0001/PT04.HTM#Head317
     * */
    /*Perform in place Ifx_FftF32_radix2DecimationInTime of 2^p points (=size of f)
     * N.B. The input array f is in bit reversed order! So all the
     * 'even' input samples are in the 'top' half, all the 'odd'
     * input samples are in the 'bottom' halR..etc (recursively).
     */
    /*Ifx_FftF32_radix2DecimationInTime*/
    unsigned long Bp, Np, Npx, P, b, k, BaseT, BaseB;
    cfloat32      top, bot;
    /*initialise pass parameters*/
    Bp = 1 << (p - 1); /*No. of blocks*/
    Np = 2;            /*No. of points in each block*/

    /*perform p passes*/
    for (P = 0; P < p; P++)
    {
        /*pass loop*/
        Npx   = Np >> 1; /*No. of butterflies*/
        BaseT = 0;       /*Reset even base index*/

        for (b = 0; b < Bp; b++)
        {
            /*block loop*/
            BaseB = BaseT + Npx; /*calc odd base index*/

            for (k = 0; k < Npx; k++)
            {
                //printf("P = %d; b = %d; Np = %d; k = %d\n", P, b, Np, k);
                /*butterfly loop*/
                top          = Ifx_FftF32_lookUpTwiddleFactor(Np, k);
                bot          = IFX_Cf32_mul(&R[BaseB + k], &top); /*twiddle the odd n results*/
                top          = R[BaseT + k];
                R[BaseT + k] = IFX_Cf32_add(&top, &bot);          /*top    subset*/
                R[BaseB + k] = IFX_Cf32_sub(&top, &bot);          /*bottom subset*/
            } /*butterfly loop*/

            BaseT = BaseT + Np;                                   /*start of next block*/
        } /*block loop*/

        /*calc parameters for next pass*/
        Bp = Bp >> 1; /*half as many blocks*/
        Np = Np << 1; /*twice as many points in each block*/
    } /*pass loop*/
} /*Ifx_FftF32_radix2DecimationInTime*/


cfloat32 *Ifx_FftF32_radix2(cfloat32 *R, const cfloat32 *X, unsigned short nX)
{
    unsigned int   logN = 31 - __clz(nX);
    unsigned short n, k;

    /* Arrange in bit-reversed index */
    for (n = 0; n < nX; n++)
    {
        //k = Ifx_FftF32_reverseBits(n, logN);
        k    = Ifx_FftF32_lookUpReversedBits(n, logN);
        R[k] = X[n];
    }

    Ifx_FftF32_radix2DecimationInTime(R, logN);

    return R;
}


cfloat32 *Ifx_FftF32_radix2I(cfloat32 *R, const cfloat32 *X, unsigned short nX)
{
    unsigned int   logN = 31 - __clz(nX);
    unsigned short n, k = 0;

    /* Arrange in bit-reversed index, and conjugate the input */
    for (n = 0; n < nX; n++)
    {
        //k = Ifx_FftF32_reverseBits(n, logN);
        k         = Ifx_FftF32_lookUpReversedBits(n, logN);
        R[k].real = X[n].real;
        R[k].imag = -X[n].imag;
    }

    Ifx_FftF32_radix2DecimationInTime(R, logN);

    /* Conjugate the output */
    for (n = 0; n < nX; n++)
    {
        R[n].imag = -R[n].imag;
    }

    return R;
}
