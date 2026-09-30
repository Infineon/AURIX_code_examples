/**
 * \file Ifx_LutLSincosF32.h
 * \brief Sin/Cos linear approximated lookup functions with fixed-point angle data type
 * \ingroup library_srvsw_sysse_math_lut_lsincos
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
 * \defgroup library_srvsw_sysse_math_lut_lsincos Linear trigonometric Look-ups
 * \ingroup library_srvsw_sysse_math_f32_lut
 *
 */

#ifndef IFX_LUTLSINCOSF32_H
#define IFX_LUTLSINCOSF32_H 1
//________________________________________________________________________________________

#include "IFX_Cf32.h"
#include "Ifx_Lut.h"
#include "Ifx_LutIndexedLinearF32.h"
//________________________________________________________________________________________

/**
 * \brief Look-up table for sin */
IFX_EXTERN const Ifx_LutIndexedLinearF32 Ifx_g_LutLSincosF32;

/**
 * \brief Sine lookup function
 * \param fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1)
 * \return sin(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \ingroup library_srvsw_sysse_math_lut_lsincos
 */
IFX_INLINE float32 Ifx_LutLSincosF32_sin(Ifx_Lut_FxpAngle fxpAngle)
{
    fxpAngle = fxpAngle & (IFX_LUT_ANGLE_RESOLUTION - 1);

    return Ifx_LutIndexedLinearF32_search(&Ifx_g_LutLSincosF32, fxpAngle);
}


/**
 * \brief Cosine lookup function
 * \param fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1), which represents 0 .. 2*IFX_PI
 * \return cos(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \ingroup library_srvsw_sysse_math_lut_lsincos
 */
IFX_INLINE float32 Ifx_LutLSincosF32_cos(Ifx_Lut_FxpAngle fxpAngle)
{
    return Ifx_LutLSincosF32_sin((IFX_LUT_ANGLE_PI / 2) - fxpAngle);
}


/**
 * \brief Sine and Cosine lookup function
 * \param fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1), which represents 0 .. 2*IFX_PI
 * \retval real = cos(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \retval imag = sin(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \ingroup library_srvsw_sysse_math_lut_lsincos
 */
IFX_INLINE cfloat32 Ifx_LutLSincosF32_cossin(Ifx_Lut_FxpAngle fxpAngle)
{
    cfloat32 result;
    result.imag = Ifx_LutLSincosF32_sin(fxpAngle);
    result.real = Ifx_LutLSincosF32_sin((IFX_LUT_ANGLE_PI / 2) - fxpAngle);
    return result;
}


//________________________________________________________________________________________
#endif
