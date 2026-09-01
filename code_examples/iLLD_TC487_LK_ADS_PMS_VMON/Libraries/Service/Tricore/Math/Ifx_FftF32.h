/**
 * \file Ifx_FftF32.h
 * \brief Floating-point Fast Fourier Transform
 * \ingroup library_srvsw_sysse_math_f32_fft
 *
 *
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) licenses this file to you under the
 * Infineon Automotive SW Lab License v2025-01 (IFASLL). You may not use
 * this file except in compliance with IFASLL.
 *
 * The full license text is contained in IFASLL202501.pdf delivered with this SW.
 * Unless required by applicable law or agreed to in writing, software distributed
 * under this license is distributed "AS IS" without any warranty or liability of any
 * kind and Infineon hereby expressly disclaims any warranties or representations,
 * whether express, implied, statutory or otherwise, including but not limited to
 * warranties of workmanship, merchantability, fitness for a particular purpose,
 * defects in the licensed items, or non-infringement of third parties'
 * intellectual property rights. See the full license text for the specific
 * language governing permissions and limitations under IFASLL.
 *
 * \defgroup library_srvsw_sysse_math_f32_fft Floating-point FFT
 * This module implements the Fast Fourier Transform in single precision floating-point
 * \ingroup library_srvsw_sysse_math_f32
 *
 */

#ifndef IFX_FFTF32_H
#define IFX_FFTF32_H 1

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
