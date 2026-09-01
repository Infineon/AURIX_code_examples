/**
 * \file Ifx_WndF32.h
 * \brief Windowing function
 * \ingroup library_srvsw_sysse_math_f32_wnd
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
 * \defgroup library_srvsw_sysse_math_f32_wnd Window functions
 * \ingroup library_srvsw_sysse_math_f32
 */

#ifndef IFX_WNDF32_H
#define IFX_WNDF32_H 1

#include "Ifx_Cf32.h"

#define IFX_WNDF32_TABLE_LENGTH (1024)

/** \addtogroup library_srvsw_sysse_math_f32_wnd
 * \{ */

IFX_EXTERN CONST_CFG float32 Ifx_g_WndF32_hannTable[IFX_WNDF32_TABLE_LENGTH / 2];
IFX_EXTERN CONST_CFG float32 Ifx_g_WndF32_blackmanHarrisTable[IFX_WNDF32_TABLE_LENGTH / 2];

/** \brief Apply a window to complex array x which has nX length.
 *
 * Example: Ifx_WndF32_apply(x, Ifx_g_WndF32_hannTable, 1024); */
IFX_INLINE void Ifx_WndF32_apply(cfloat32 *x, CONST_CFG float32 *window, short nX)
{
    VecWin_f32(&x->real, window, nX, IFX_WNDF32_TABLE_LENGTH, 2, 1);
}


/** \} */

#endif /* IFX_WNDF32_H */
