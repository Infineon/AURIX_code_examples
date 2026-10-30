/**
 * \file IfxPsi5s_PinMap_TC4Dx_BGA292_COM.h
 * \brief PSI5S  details
 * \ingroup IfxLld_Psi5s
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
 * \defgroup IfxLld_Psi5s_
 * \ingroup IfxLld_Psi5s
 * \defgroup IfxLld_Psi5s__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Psi5s_
 * \defgroup IfxLld_Psi5s__PinTables PinTables
 * \ingroup IfxLld_Psi5s_
 */

#ifndef IFXPSI5S_PINMAP_TC4DX_BGA292_COM_H
#define IFXPSI5S_PINMAP_TC4DX_BGA292_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPsi5s_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPSI5S_PINMAP_NUM_MODULES       1

#define IFXPSI5S_PINMAP_CLK_OUT_NUM_ITEMS 2

#define IFXPSI5S_PINMAP_RX_IN_NUM_ITEMS   4

#define IFXPSI5S_PINMAP_TX_OUT_NUM_ITEMS  3

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief PSI5S CLK is a clock that can be used on a pin to drive the external PHY.
 */
IFX_EXTERN IfxPsi5s_Clk_Out IfxPsi5s_CLK_P02_4_OUT;

/** \brief PSI5S CLK is a clock that can be used on a pin to drive the external PHY.
 */
IFX_EXTERN IfxPsi5s_Clk_Out IfxPsi5s_CLK_P33_10_OUT;

/** \brief RX data input
 */
IFX_EXTERN IfxPsi5s_Rx_In   IfxPsi5s_RXA_P00_3_IN;

/** \brief RX data input
 */
IFX_EXTERN IfxPsi5s_Rx_In   IfxPsi5s_RXB_P02_5_IN;

/** \brief RX data input
 */
IFX_EXTERN IfxPsi5s_Rx_In   IfxPsi5s_RXC_P33_5_IN;

/** \brief RX data input
 */
IFX_EXTERN IfxPsi5s_Rx_In   IfxPsi5s_RXD_P33_7_IN;

/** \brief TX data output
 */
IFX_EXTERN IfxPsi5s_Tx_Out  IfxPsi5s_TX_P00_4_OUT;

/** \brief TX data output
 */
IFX_EXTERN IfxPsi5s_Tx_Out  IfxPsi5s_TX_P02_6_OUT;

/** \brief TX data output
 */
IFX_EXTERN IfxPsi5s_Tx_Out  IfxPsi5s_TX_P33_6_OUT;

/** \addtogroup IfxLld_Psi5s__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxPsi5s_Clk_Out Table
 */
IFX_EXTERN IFX_CONST IfxPsi5s_Clk_Out *IfxPsi5s_Clk_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_CLK_OUT_NUM_ITEMS];

/** \brief IfxPsi5s_Rx_In Table
 */
IFX_EXTERN IFX_CONST IfxPsi5s_Rx_In   *IfxPsi5s_Rx_In_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_RX_IN_NUM_ITEMS];

/** \brief IfxPsi5s_Tx_Out Table
 */
IFX_EXTERN IFX_CONST IfxPsi5s_Tx_Out  *IfxPsi5s_Tx_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_TX_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXPSI5S_PINMAP_TC4DX_BGA292_COM_H */
