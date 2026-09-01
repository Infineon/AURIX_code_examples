/**
 * \file IfxPms_PinMap_TC48x_BGA224_STD.h
 * \brief PMS  details
 * \ingroup IfxLld_Pms
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
 * \defgroup IfxLld_Pms_Pinmap Pms Pinmap Structure
 * \ingroup IfxLld_Pms
 * \defgroup IfxLld_Pms__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Pms_
 * \defgroup IfxLld_Pms__PinTables PinTables
 * \ingroup IfxLld_Pms_
 */

#ifndef IFXPMS_PINMAP_TC48X_BGA224_STD_H
#define IFXPMS_PINMAP_TC48X_BGA224_STD_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPms_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPMS_PINMAP_NUM_MODULES            1

#define IFXPMS_PINMAP_DCDCSYNC_OUT_NUM_ITEMS 2

#define IFXPMS_PINMAP_ESR_OUT_NUM_ITEMS 1
#define IFXPMS_PINMAP_RTCOUT_OUT_NUM_ITEMS   1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief
 */
IFX_EXTERN IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_2_OUT;

/** \brief
 */
IFX_EXTERN IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_4_OUT;

/** \brief
 */
IFX_EXTERN IfxPms_Esr_Out IfxPms_ESR2PORST_P33_11_OUT;
IFX_EXTERN IfxPms_Rtcout_Out   IfxPms_RTCOUT_P33_11_OUT;

/** \addtogroup IfxLld_Pms__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxPms_Dcdcsync_Out Table
 */
IFX_EXTERN IFX_CONST IfxPms_Dcdcsync_Out *IfxPms_Dcdcsync_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_DCDCSYNC_OUT_NUM_ITEMS];

IFX_EXTERN IFX_CONST IfxPms_Esr_Out* IfxPms_Esr_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_ESR_OUT_NUM_ITEMS];
/** \brief IfxPms_Rtcout_Out Table
 */
IFX_EXTERN IFX_CONST IfxPms_Rtcout_Out   *IfxPms_Rtcout_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_RTCOUT_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXPMS_PINMAP_TC48X_BGA224_STD_H */
