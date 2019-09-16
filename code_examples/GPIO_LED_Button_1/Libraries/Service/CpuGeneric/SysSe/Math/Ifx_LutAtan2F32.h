/**
 * \file Ifx_LutAtan2F32.h
 * \brief Floating point signal, vector, and matrix library
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
 * \defgroup library_srvsw_sysse_math_lut_atan2 ATAN lookup table
 * \ingroup library_srvsw_sysse_math_f32_lut
 */

#ifndef IFX_LUTATAN2F32_H
#define IFX_LUTATAN2F32_H
//----------------------------------------------------------------------------------------
#include "Ifx_Lut.h"

//----------------------------------------------------------------------------------------

#define IFX_LUTATAN2F32_SIZE (1024)           /**< \brief size of Ifx_LutAtan2F32 table */

//----------------------------------------------------------------------------------------

/** \brief Table I for Ifx_LutAtan2F32_fxpAngle() */
IFX_EXTERN IFX_LUT_TABLE Ifx_Lut_FxpAngle Ifx_g_LutAtan2F32_FxpAngle_table[IFX_LUTATAN2F32_SIZE + 1];
IFX_EXTERN IFX_LUT_TABLE float32          Ifx_g_LutAtan2F32_table[IFX_LUTATAN2F32_SIZE + 1];

/** \brief Initialise the lookup tables
 * \ingroup library_srvsw_sysse_math_lut_atan2
 */
IFX_EXTERN void Ifx_LutAtan2F32_init(void);

/**
 * \brief Look-up arcus tangent value of y/x.
 * \return fxpAngle 0 .. (IFX_LUT_ANGLE_RESOLUTION - 1), which represents 0 .. 2*IFX_PI
 * \ingroup library_srvsw_sysse_math_lut_atan2
 */
IFX_EXTERN Ifx_Lut_FxpAngle Ifx_LutAtan2F32_fxpAngle(float32 x, float32 y);
IFX_EXTERN float32          Ifx_LutAtan2F32_float32(float32 y, float32 x);

#endif
