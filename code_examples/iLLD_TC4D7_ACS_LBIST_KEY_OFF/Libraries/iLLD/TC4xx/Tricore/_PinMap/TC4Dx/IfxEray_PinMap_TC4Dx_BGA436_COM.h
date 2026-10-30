/**
 * \file IfxEray_PinMap_TC4Dx_BGA436_COM.h
 * \brief ERAY  details
 * \ingroup IfxLld_Eray
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
 * \defgroup IfxLld_Eray_
 * \ingroup IfxLld_Eray
 * \defgroup IfxLld_Eray__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Eray_
 * \defgroup IfxLld_Eray__PinTables PinTables
 * \ingroup IfxLld_Eray_
 */

#ifndef IFXERAY_PINMAP_TC4DX_BGA436_COM_H
#define IFXERAY_PINMAP_TC4DX_BGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxEray_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXERAY_PINMAP_NUM_MODULES        2

#define IFXERAY_PINMAP_NUM_NODES          2

#define IFXERAY_PINMAP_RXD_IN_NUM_ITEMS   4

#define IFXERAY_PINMAP_TXD_OUT_NUM_ITEMS  5

#define IFXERAY_PINMAP_TXEN_OUT_NUM_ITEMS 5

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Receive Channel A0
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDA0_P14_8_IN;

/** \brief Receive Channel A2
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDA2_P02_1_IN;

/** \brief Receive Channel A3
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDA3_P14_1_IN;

/** \brief Receive Channel B0
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDB0_P14_7_IN;

/** \brief Receive Channel B2
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDB2_P02_3_IN;

/** \brief Receive Channel B3
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray0_RXDB3_P14_1_IN;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDA_P02_0_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDA_P10_0_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDA_P10_10_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDA_P14_0_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDA_P14_10_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDB_P02_2_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDB_P10_5_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDB_P14_0_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray0_TXDB_P14_5_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENA_P02_4_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENA_P10_9_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENA_P14_9_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P02_5_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P10_6_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P10_9_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P14_6_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray0_TXENB_P14_9_OUT;

/** \brief Receive Channel A0
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDA0_P14_8_IN;

/** \brief Receive Channel A1
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDA1_P01_1_IN;

/** \brief Receive Channel A3
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDA3_P10_8_IN;

/** \brief Receive Channel B0
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDB0_P14_7_IN;

/** \brief Receive Channel B1
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDB1_P01_8_IN;

/** \brief Receive Channel B2
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDB2_P03_6_IN;

/** \brief Receive Channel B3
 */
IFX_EXTERN IfxEray_Rxd_In   IfxEray1_RXDB3_P10_7_IN;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDA_P01_12_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDA_P10_10_OUT;

/** \brief Transmit Channel A
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDA_P14_10_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDB_P01_13_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDB_P10_0_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDB_P10_5_OUT;

/** \brief Transmit Channel B
 */
IFX_EXTERN IfxEray_Txd_Out  IfxEray1_TXDB_P14_5_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENA_P01_14_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENA_P10_9_OUT;

/** \brief Transmit Enable Channel A
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENA_P14_9_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENB_P02_15_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENB_P04_2_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENB_P10_6_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENB_P10_9_OUT;

/** \brief Transmit Enable Channel B
 */
IFX_EXTERN IfxEray_Txen_Out IfxEray1_TXENB_P14_6_OUT;

/** \addtogroup IfxLld_Eray__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxEray_Rxd_In Table
 */
IFX_EXTERN IFX_CONST IfxEray_Rxd_In   *IfxEray_Rxd_In_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_RXD_IN_NUM_ITEMS];

/** \brief IfxEray_Txd_Out Table
 */
IFX_EXTERN IFX_CONST IfxEray_Txd_Out  *IfxEray_Txd_Out_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_TXD_OUT_NUM_ITEMS];

/** \brief IfxEray_Txen_Out Table
 */
IFX_EXTERN IFX_CONST IfxEray_Txen_Out *IfxEray_Txen_Out_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_TXEN_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXERAY_PINMAP_TC4DX_BGA436_COM_H */
