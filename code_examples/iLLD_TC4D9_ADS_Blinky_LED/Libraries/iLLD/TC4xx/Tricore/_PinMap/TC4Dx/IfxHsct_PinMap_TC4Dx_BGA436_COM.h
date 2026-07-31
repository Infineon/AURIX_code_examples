/**
 * \file IfxHsct_PinMap_TC4Dx_BGA436_COM.h
 * \brief HSCT  details
 * \ingroup IfxLld_Hsct
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
 * \defgroup IfxLld_Hsct_
 * \ingroup IfxLld_Hsct
 * \defgroup IfxLld_Hsct__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Hsct_
 * \defgroup IfxLld_Hsct__PinTables PinTables
 * \ingroup IfxLld_Hsct_
 */

#ifndef IFXHSCT_PINMAP_TC4DX_BGA436_COM_H
#define IFXHSCT_PINMAP_TC4DX_BGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxHsct_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXHSCT_PINMAP_NUM_MODULES          2

#define IFXHSCT_PINMAP_RXDN_IN_NUM_ITEMS    1

#define IFXHSCT_PINMAP_RXDP_IN_NUM_ITEMS    1

#define IFXHSCT_PINMAP_SYSCLK_OUT_NUM_ITEMS 1

#define IFXHSCT_PINMAP_TXDN_OUT_NUM_ITEMS   1

#define IFXHSCT_PINMAP_TXDP_OUT_NUM_ITEMS   1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Rx data
 */
IFX_EXTERN IfxHsct_Rxdn_In    IfxHsct_RXDN_P21_0_IN;

/** \brief Rx data
 */
IFX_EXTERN IfxHsct_Rxdn_In    IfxHsct_RXDN_P21_2_IN;

/** \brief Rx data
 */
IFX_EXTERN IfxHsct_Rxdp_In    IfxHsct_RXDP_P21_1_IN;

/** \brief Rx data
 */
IFX_EXTERN IfxHsct_Rxdp_In    IfxHsct_RXDP_P21_3_IN;

/** \brief sys clock output
 */
IFX_EXTERN IfxHsct_Sysclk_Out IfxHsct_SYSCLK_OUT_P20_0_OUT;

/** \brief Tx data
 */
IFX_EXTERN IfxHsct_Txdn_Out   IfxHsct_TXDN_P21_4_OUT;

/** \brief Tx data
 */
IFX_EXTERN IfxHsct_Txdn_Out   IfxHsct_TXDN_P22_2_OUT;

/** \brief Tx data
 */
IFX_EXTERN IfxHsct_Txdp_Out   IfxHsct_TXDP_P21_5_OUT;

/** \brief Tx data
 */
IFX_EXTERN IfxHsct_Txdp_Out   IfxHsct_TXDP_P22_3_OUT;

/** \addtogroup IfxLld_Hsct__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxHsct_Rxdn_In Table
 */
IFX_EXTERN IFX_CONST IfxHsct_Rxdn_In    *IfxHsct_Rxdn_In_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_RXDN_IN_NUM_ITEMS];

/** \brief IfxHsct_Rxdp_In Table
 */
IFX_EXTERN IFX_CONST IfxHsct_Rxdp_In    *IfxHsct_Rxdp_In_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_RXDP_IN_NUM_ITEMS];

/** \brief IfxHsct_Sysclk_Out Table
 */
IFX_EXTERN IFX_CONST IfxHsct_Sysclk_Out *IfxHsct_Sysclk_Out_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_SYSCLK_OUT_NUM_ITEMS];

/** \brief IfxHsct_Txdn_Out Table
 */
IFX_EXTERN IFX_CONST IfxHsct_Txdn_Out   *IfxHsct_Txdn_Out_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_TXDN_OUT_NUM_ITEMS];

/** \brief IfxHsct_Txdp_Out Table
 */
IFX_EXTERN IFX_CONST IfxHsct_Txdp_Out   *IfxHsct_Txdp_Out_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_TXDP_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXHSCT_PINMAP_TC4DX_BGA436_COM_H */
