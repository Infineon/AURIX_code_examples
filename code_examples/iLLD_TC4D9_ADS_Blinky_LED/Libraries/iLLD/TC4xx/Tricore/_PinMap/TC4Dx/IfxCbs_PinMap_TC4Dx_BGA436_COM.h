/**
 * \file IfxCbs_PinMap_TC4Dx_BGA436_COM.h
 * \brief CBS  details
 * \ingroup IfxLld_Cbs
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
 * \defgroup IfxLld_Cbs_
 * \ingroup IfxLld_Cbs
 * \defgroup IfxLld_Cbs__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Cbs_
 * \defgroup IfxLld_Cbs__PinTables PinTables
 * \ingroup IfxLld_Cbs_
 */

#ifndef IFXCBS_PINMAP_TC4DX_BGA436_COM_H
#define IFXCBS_PINMAP_TC4DX_BGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxCbs_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXCBS_PINMAP_NUM_MODULES       1

#define IFXCBS_PINMAP_NUM_CHANNELS      8

#define IFXCBS_PINMAP_TGI_IN_NUM_ITEMS  1

#define IFXCBS_PINMAP_TGO_OUT_NUM_ITEMS 1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI0_P20_0_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI1_P20_1_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI2_P21_6_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI3_P21_7_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI4_P32_6_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI5_P32_7_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI6_P33_14_IN;

/** \brief Trigger input
 */
IFX_EXTERN IfxCbs_Tgi_In  IfxCbs_TGI7_P33_15_IN;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO0_P20_0_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO1_P20_1_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO2_P21_6_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO3_P21_7_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO4_P32_6_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO5_P32_7_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO6_P33_14_OUT;

/** \brief Trigger output
 */
IFX_EXTERN IfxCbs_Tgo_Out IfxCbs_TGO7_P33_15_OUT;

/** \addtogroup IfxLld_Cbs__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxCbs_Tgi_In Table
 */
IFX_EXTERN IFX_CONST IfxCbs_Tgi_In  *IfxCbs_Tgi_In_pinTable[IFXCBS_PINMAP_NUM_MODULES][IFXCBS_PINMAP_NUM_CHANNELS][IFXCBS_PINMAP_TGI_IN_NUM_ITEMS];

/** \brief IfxCbs_Tgo_Out Table
 */
IFX_EXTERN IFX_CONST IfxCbs_Tgo_Out *IfxCbs_Tgo_Out_pinTable[IFXCBS_PINMAP_NUM_MODULES][IFXCBS_PINMAP_NUM_CHANNELS][IFXCBS_PINMAP_TGO_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXCBS_PINMAP_TC4DX_BGA436_COM_H */
