/**
 * \file Ifx_LutAtan2F32.h
 * \brief Floating point signal, vector, and matrix library
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
 * \defgroup library_srvsw_sysse_math_lut_atan2 ATAN lookup table
 * \ingroup library_srvsw_sysse_math_f32_lut
 */

#ifndef IFX_LUTATAN2F32_H
#define IFX_LUTATAN2F32_H 1
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
