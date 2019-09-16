/**
 * \file Ifx_FftF32.h
 * \brief Floating-point Fast Fourier Transform
 * \ingroup library_srvsw_sysse_math_f32_fft
 *
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
 * \defgroup library_srvsw_sysse_math_f32_fft Floating-point FFT
 * This module implements the Fast Fourier Transform in single precision floating-point
 * \ingroup library_srvsw_sysse_math_f32
 *
 */

#ifndef IFX_FFTF32_H
#define IFX_FFTF32_H

#include "Ifx_Cf32.h"

/** \brief Maximum FFT resolution (bits).
 * If redefined, then \ref Ifx_g_FftF32_bitReverseTable and \ref Ifx_g_FftF32_twiddleTable shall be regenerated. */
#define IFX_FFTF32_MAX_RESOLUTION (14)

/** \brief Maximum FFT length.
 * If redefined, then \ref Ifx_g_FftF32_bitReverseTable and \ref Ifx_g_FftF32_twiddleTable shall be regenerated. */
#define IFX_FFTF32_MAX_LENGTH     (1U << IFX_FFTF32_MAX_RESOLUTION)

/** \brief Bit reversal table */
IFX_EXTERN IFX_CONST uint16   Ifx_g_FftF32_bitReverseTable[IFX_FFTF32_MAX_LENGTH];

/** \brief Twiddle factor table */
IFX_EXTERN IFX_CONST cfloat32 Ifx_g_FftF32_twiddleTable[IFX_FFTF32_MAX_LENGTH / 2];

//----------------------------------------------------------------------------------------
/** \addtogroup library_srvsw_sysse_math_f32_fft
 * \{ */

/** \name Transform functions
 * \{ */

/** \brief Twiddle factor generator */
IFX_EXTERN cfloat32 *Ifx_FftF32_generateTwiddleFactor(cfloat32 *TF, sint16 nX);

/** \brief Radix-2 Fast-Fourier Transform */
IFX_EXTERN cfloat32 *Ifx_FftF32_radix2(cfloat32 *R, const cfloat32 *X, uint16 nX);

/** \brief Radix-2 Inverse Fast-Fourier Transform */
IFX_EXTERN cfloat32 *Ifx_FftF32_radix2I(cfloat32 *R, const cfloat32 *X, uint16 nX);

/** \} */
//----------------------------------------------------------------------------------------
/** \name Utility functions
 * \{ */

/** \brief Lookup from \ref Ifx_g_FftF32_bitReverseTable the bit-reversed \<n\> with \<bits\> as number of bits */
IFX_INLINE uint16 Ifx_FftF32_lookUpReversedBits(uint16 n, unsigned bits)
{
    unsigned shift = IFX_FFTF32_MAX_RESOLUTION - bits;
    uint16   index = Ifx_g_FftF32_bitReverseTable[n];
    return index >> shift;
}


/** \brief Lookup from \ref Ifx_g_FftF32_twiddleTable the twiddle factor for N, k */
IFX_INLINE cfloat32 Ifx_FftF32_lookUpTwiddleFactor(sint32 N, sint32 k)
{
    return Ifx_g_FftF32_twiddleTable[k * IFX_FFTF32_MAX_LENGTH / N];
}


/** \brief Calculate the bit-reversed \<n\> with \<bits\> as number of bits */
IFX_EXTERN uint16 Ifx_FftF32_reverseBits(uint16 n, unsigned bits);

/** \} */
//----------------------------------------------------------------------------------------
/** \} */

#endif /* IFX_FFTF32_H */
