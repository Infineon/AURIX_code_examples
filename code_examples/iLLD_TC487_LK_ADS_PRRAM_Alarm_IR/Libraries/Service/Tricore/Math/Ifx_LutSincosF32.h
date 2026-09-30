/**
 * \file Ifx_LutSincosF32.h
 * \brief Sin/Cos lookup functions with fixed-point angle data type
 * \ingroup library_srvsw_sysse_math_lut_sincos
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
 * \defgroup library_srvsw_sysse_math_lut_sincos Sinus and cosinus Look-ups
 * \ingroup library_srvsw_sysse_math_f32_lut
 *
 */

#ifndef IFX_LUTSINCOSF32_H
#define IFX_LUTSINCOSF32_H 1
//________________________________________________________________________________________

#include "Ifx_Cf32.h"
#include "Ifx_Lut.h"
//________________________________________________________________________________________

/**
 * \brief Look-up table for sin(IFX_PI*2*k/IFX_LUT_ANGLE_RESOLUTION),
 * where k = 0..IFX_LUT_ANGLE_RESOLUTION */
IFX_EXTERN IFX_LUT_TABLE float32 Ifx_g_LutSincosF32_table[(IFX_LUT_ANGLE_PI / 2) + 1];

/** \brief Initialise the lookup tables
 * \note This is not required if (\ref IFX_LUT_TABLE_CONST == 1)
 * \ingroup library_srvsw_sysse_math_lut_sincos
 */
IFX_EXTERN void Ifx_LutSincosF32_init(void);

/**
 * \brief Sine lookup function
 * \param fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1)
 * \return sin(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \ingroup library_srvsw_sysse_math_lut_sincos
 */
IFX_EXTERN float32 Ifx_LutSincosF32_sin(Ifx_Lut_FxpAngle fxpAngle);

/**
 * \brief Cosine lookup function
 * \param fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1), which represents 0 .. 2*IFX_PI
 * \return cos(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \ingroup library_srvsw_sysse_math_lut_sincos
 */
IFX_INLINE float32 Ifx_LutSincosF32_cos(Ifx_Lut_FxpAngle fxpAngle)
{
    return Ifx_LutSincosF32_sin((IFX_LUT_ANGLE_PI / 2) - fxpAngle);
}


/**
 * \brief Sine and Cosine lookup function
 * \param fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1), which represents 0 .. 2*IFX_PI
 * \retval real = cos(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \retval imag = sin(2*IFX_PI*fxpAngle/IFX_LUT_ANGLE_RESOLUTION)
 * \ingroup library_srvsw_sysse_math_lut_sincos
 */
IFX_INLINE cfloat32 Ifx_LutSincosF32_cossin(Ifx_Lut_FxpAngle fxpAngle)
{
    cfloat32 result;
    result.imag = Ifx_LutSincosF32_sin(fxpAngle);
    result.real = Ifx_LutSincosF32_sin((IFX_LUT_ANGLE_PI / 2) - fxpAngle);
    return result;
}


//________________________________________________________________________________________
#endif
