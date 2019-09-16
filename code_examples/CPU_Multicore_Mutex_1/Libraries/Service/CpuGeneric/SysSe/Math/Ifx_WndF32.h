/**
 * \file Ifx_WndF32.h
 * \brief Windowing function
 * \ingroup library_srvsw_sysse_math_f32_wnd
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
 * \defgroup library_srvsw_sysse_math_f32_wnd Window functions
 * \ingroup library_srvsw_sysse_math_f32
 */

#ifndef IFX_WNDF32_H
#define IFX_WNDF32_H

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
