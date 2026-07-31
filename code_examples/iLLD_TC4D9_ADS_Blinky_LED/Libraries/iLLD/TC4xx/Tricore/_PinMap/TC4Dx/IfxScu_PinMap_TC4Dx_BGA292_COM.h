/**
 * \file IfxScu_PinMap_TC4Dx_BGA292_COM.h
 * \brief SCU  details
 * \ingroup IfxLld_Scu
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
 * \defgroup IfxLld_Scu_
 * \ingroup IfxLld_Scu
 * \defgroup IfxLld_Scu__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Scu_
 * \defgroup IfxLld_Scu__PinTables PinTables
 * \ingroup IfxLld_Scu_
 */

#ifndef IFXSCU_PINMAP_TC4DX_BGA292_COM_H
#define IFXSCU_PINMAP_TC4DX_BGA292_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxScu_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXSCU_PINMAP_NUM_MODULES      1

#define IFXSCU_PINMAP_NUM_REQUESTS     8

#define IFXSCU_PINMAP_REQ_IN_NUM_ITEMS 7

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief ERU channel 0 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ0A_P15_4_IN;

/** \brief ERU channel 0 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ0B_P10_7_IN;

/** \brief ERU channel 0 input F
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ0F_P02_7_IN;

/** \brief ERU channel 1 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ1A_P14_3_IN;

/** \brief ERU channel 1 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ1B_P10_8_IN;

/** \brief ERU channel 1 input G
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ1G_P16_1_IN;

/** \brief ERU channel 2 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ2A_P10_2_IN;

/** \brief ERU channel 2 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ2B_P02_1_IN;

/** \brief ERU channel 2 input C
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ2C_P00_4_IN;

/** \brief ERU channel 3 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ3A_P10_3_IN;

/** \brief ERU channel 3 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ3B_P14_1_IN;

/** \brief ERU channel 3 input C
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ3C_P02_0_IN;

/** \brief ERU channel 4 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ4A_P33_7_IN;

/** \brief ERU channel 4 input D
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ4D_P15_5_IN;

/** \brief ERU channel 5 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ5A_P15_8_IN;

/** \brief ERU channel 5 input G
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ5G_P02_8_IN;

/** \brief ERU channel 6 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ6A_P20_0_IN;

/** \brief ERU channel 6 input F
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ6F_P23_1_IN;

/** \brief ERU channel 7 input A
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ7A_P20_9_IN;

/** \brief ERU channel 7 input B
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ7B_P15_1_IN;

/** \brief ERU channel 7 input G
 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ7G_P02_11_IN;

/** \addtogroup IfxLld_Scu__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxScu_Req_In Table
 */
IFX_EXTERN IFX_CONST IfxScu_Req_In *IfxScu_Req_In_pinTable[IFXSCU_PINMAP_NUM_MODULES][IFXSCU_PINMAP_NUM_REQUESTS][IFXSCU_PINMAP_REQ_IN_NUM_ITEMS];

/** \} */

#endif /* IFXSCU_PINMAP_TC4DX_BGA292_COM_H */
