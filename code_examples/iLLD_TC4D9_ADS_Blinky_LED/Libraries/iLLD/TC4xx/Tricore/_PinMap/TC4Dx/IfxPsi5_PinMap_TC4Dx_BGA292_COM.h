/**
 * \file IfxPsi5_PinMap_TC4Dx_BGA292_COM.h
 * \brief PSI5  details
 * \ingroup IfxLld_Psi5
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
 * \defgroup IfxLld_Psi5_
 * \ingroup IfxLld_Psi5
 * \defgroup IfxLld_Psi5__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Psi5_
 * \defgroup IfxLld_Psi5__PinTables PinTables
 * \ingroup IfxLld_Psi5_
 */

#ifndef IFXPSI5_PINMAP_TC4DX_BGA292_COM_H
#define IFXPSI5_PINMAP_TC4DX_BGA292_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPsi5_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPSI5_PINMAP_NUM_MODULES      1

#define IFXPSI5_PINMAP_NUM_CHANNELS     2

#define IFXPSI5_PINMAP_RX_IN_NUM_ITEMS  3

#define IFXPSI5_PINMAP_TX_OUT_NUM_ITEMS 3

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief RXD inputs (receive data) channel 0
 */
IFX_EXTERN IfxPsi5_Rx_In  IfxPsi5_RX0A_P00_1_IN;

/** \brief RXD inputs (receive data) channel 0
 */
IFX_EXTERN IfxPsi5_Rx_In  IfxPsi5_RX0B_P02_3_IN;

/** \brief RXD inputs (receive data) channel 0
 */
IFX_EXTERN IfxPsi5_Rx_In  IfxPsi5_RX0C_P33_1_IN;

/** \brief RXD inputs (receive data) channel 1
 */
IFX_EXTERN IfxPsi5_Rx_In  IfxPsi5_RX1A_P00_3_IN;

/** \brief RXD inputs (receive data) channel 1
 */
IFX_EXTERN IfxPsi5_Rx_In  IfxPsi5_RX1B_P02_5_IN;

/** \brief RXD inputs (receive data) channel 1
 */
IFX_EXTERN IfxPsi5_Rx_In  IfxPsi5_RX1C_P33_3_IN;

/** \brief TXD outputs (send data)
 */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX0_P00_2_OUT;

/** \brief TXD outputs (send data)
 */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX0_P02_2_OUT;

/** \brief TXD outputs (send data)
 */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX0_P33_2_OUT;

/** \brief TXD outputs (send data)
 */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX1_P00_4_OUT;

/** \brief TXD outputs (send data)
 */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX1_P02_6_OUT;

/** \brief TXD outputs (send data)
 */
IFX_EXTERN IfxPsi5_Tx_Out IfxPsi5_TX1_P33_4_OUT;

/** \addtogroup IfxLld_Psi5__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxPsi5_Rx_In Table
 */
IFX_EXTERN IFX_CONST IfxPsi5_Rx_In  *IfxPsi5_Rx_In_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_RX_IN_NUM_ITEMS];

/** \brief IfxPsi5_Tx_Out Table
 */
IFX_EXTERN IFX_CONST IfxPsi5_Tx_Out *IfxPsi5_Tx_Out_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_TX_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXPSI5_PINMAP_TC4DX_BGA292_COM_H */
