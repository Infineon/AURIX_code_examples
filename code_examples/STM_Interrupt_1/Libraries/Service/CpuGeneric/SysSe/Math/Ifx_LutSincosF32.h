/**
 * \file Ifx_LutSincosF32.h
 * \brief Sin/Cos lookup functions with fixed-point angle data type
 * \ingroup library_srvsw_sysse_math_lut_sincos
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
 * \defgroup library_srvsw_sysse_math_lut_sincos Sinus and cosinus Look-ups
 * \ingroup library_srvsw_sysse_math_f32_lut
 *
 */

#ifndef IFX_LUTSINCOSF32_H
#define IFX_LUTSINCOSF32_H
//________________________________________________________________________________________

#include "SysSe/Math/Ifx_Cf32.h"
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
