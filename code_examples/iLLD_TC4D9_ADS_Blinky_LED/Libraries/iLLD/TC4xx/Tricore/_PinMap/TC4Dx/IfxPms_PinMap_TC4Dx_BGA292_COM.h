/**
 * \file IfxPms_PinMap_TC4Dx_BGA292_COM.h
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
 * Version: MC_ACE_A3G_HWA_Ports/Unknown
 * Document: TC4Dx_Pin_Assignment_v0.45_LETH_patched.xls
 *
 * \defgroup IfxLld_Pms_
 * \ingroup IfxLld_Pms
 * \defgroup IfxLld_Pms__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Pms_
 * \defgroup IfxLld_Pms__PinTables PinTables
 * \ingroup IfxLld_Pms_
 */

#ifndef IFXPMS_PINMAP_TC4DX_BGA292_COM_H
#define IFXPMS_PINMAP_TC4DX_BGA292_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPms_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPMS_PINMAP_NUM_MODULES            1

#define IFXPMS_PINMAP_DCDCSYNC_OUT_NUM_ITEMS 2

#define IFXPMS_PINMAP_PMS_IN_NUM_ITEMS       1

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
IFX_EXTERN IfxPms_Pms_In       IfxPms_PMS_TESTMUX_PAD_P02_1_IN;

/** \brief
 */
IFX_EXTERN IfxPms_Rtcout_Out   IfxPms_RTCOUT_P33_11_OUT;

/** \addtogroup IfxLld_Pms__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxPms_Dcdcsync_Out Table
 */
IFX_EXTERN IFX_CONST IfxPms_Dcdcsync_Out *IfxPms_Dcdcsync_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_DCDCSYNC_OUT_NUM_ITEMS];

/** \brief IfxPms_Pms_In Table
 */
IFX_EXTERN IFX_CONST IfxPms_Pms_In       *IfxPms_Pms_In_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_PMS_IN_NUM_ITEMS];

/** \brief IfxPms_Rtcout_Out Table
 */
IFX_EXTERN IFX_CONST IfxPms_Rtcout_Out   *IfxPms_Rtcout_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_RTCOUT_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXPMS_PINMAP_TC4DX_BGA292_COM_H */
