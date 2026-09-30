/**
 * \file IfxClock_PinMap_TC48x_BGA224_STD.h
 * \brief CLOCK  details
 * \ingroup IfxLld_Clock
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
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
 *
 * Version: MC_ACE_A3G_PRQ_Package_Pinning/v8.2.1.1.2
 * Document: TC48x_A21_Pin_Assignment_v0.2.6_20251118.xls 
 *
 * \defgroup IfxLld_Clock_Pinmap Clock Pinmap Structure
 * \ingroup IfxLld_Clock
 * \defgroup IfxLld_Clock__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Clock_
 * \defgroup IfxLld_Clock__PinTables PinTables
 * \ingroup IfxLld_Clock_
 */

#ifndef IFXCLOCK_PINMAP_TC48X_BGA224_STD_H
#define IFXCLOCK_PINMAP_TC48X_BGA224_STD_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxClock_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXCLOCK_PINMAP_NUM_MODULES          1

#define IFXCLOCK_PINMAP_NUM_EXTCLK_OUTPUTS   2

#define IFXCLOCK_PINMAP_EXTCLK_OUT_NUM_ITEMS 3

#define IFXCLOCK_PINMAP_SYSCLK_IN_NUM_ITEMS  1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief
 */
IFX_EXTERN IfxClock_Sysclk_In  IfxClock_CLKA_SYSCLK_P20_0_IN;

/** \brief
 */
IFX_EXTERN IfxClock_Extclk_Out IfxClock_EXTCLK0_P23_1_OUT;

/** \brief
 */
IFX_EXTERN IfxClock_Extclk_Out IfxClock_EXTCLK1_P11_12_OUT;

/** \brief
 */
IFX_EXTERN IfxClock_Extclk_Out IfxClock_EXTCLK1_P32_4_OUT;

/** \addtogroup IfxLld_Clock__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxClock_Extclk_Out Table
 */
IFX_EXTERN IFX_CONST IfxClock_Extclk_Out *IfxClock_Extclk_Out_pinTable[IFXCLOCK_PINMAP_NUM_MODULES][IFXCLOCK_PINMAP_NUM_EXTCLK_OUTPUTS][IFXCLOCK_PINMAP_EXTCLK_OUT_NUM_ITEMS];

/** \brief IfxClock_Sysclk_In Table
 */
IFX_EXTERN IFX_CONST IfxClock_Sysclk_In  *IfxClock_Sysclk_In_pinTable[IFXCLOCK_PINMAP_NUM_MODULES][IFXCLOCK_PINMAP_SYSCLK_IN_NUM_ITEMS];

/** \} */

#endif /* IFXCLOCK_PINMAP_TC48X_BGA224_STD_H */
