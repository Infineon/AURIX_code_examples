/**
 * \file IfxCanxl_PinMap_TC4Dx_BGA292_COM.h
 * \brief CANXL  details
 * \ingroup IfxLld_Canxl
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
 * \defgroup IfxLld_Canxl_
 * \ingroup IfxLld_Canxl
 * \defgroup IfxLld_Canxl__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Canxl_
 * \defgroup IfxLld_Canxl__PinTables PinTables
 * \ingroup IfxLld_Canxl_
 */

#ifndef IFXCANXL_PINMAP_TC4DX_BGA292_COM_H
#define IFXCANXL_PINMAP_TC4DX_BGA292_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxCanxl_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXCANXL_PINMAP_NUM_MODULES       1

#define IFXCANXL_PINMAP_NUM_NODES         4

#define IFXCANXL_PINMAP_RXD_IN_NUM_ITEMS  8

#define IFXCANXL_PINMAP_TXD_OUT_NUM_ITEMS 7

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD00A_P14_8_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD00B_P14_1_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD00C_P02_1_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD00E_P10_7_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD00G_P01_5_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD01A_P14_4_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD01C_P02_3_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD01D_P14_2_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD02C_P14_7_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD03B_P15_1_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD03C_P00_6_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Rxd_In  IfxCanxl_RXD03E_P00_12_IN;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD00_P01_4_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD00_P02_0_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD00_P14_0_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD00_P14_10_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD00_P15_0_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD01_P02_2_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD01_P14_0_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD01_P14_3_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD01_P14_5_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD02_P14_10_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD03_P00_5_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD03_P14_3_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD03_P14_5_OUT;

/** \brief
 */
IFX_EXTERN IfxCanxl_Txd_Out IfxCanxl_TXD03_P15_0_OUT;

/** \addtogroup IfxLld_Canxl__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxCanxl_Rxd_In Table
 */
IFX_EXTERN IFX_CONST IfxCanxl_Rxd_In  *IfxCanxl_Rxd_In_pinTable[IFXCANXL_PINMAP_NUM_MODULES][IFXCANXL_PINMAP_NUM_NODES][IFXCANXL_PINMAP_RXD_IN_NUM_ITEMS];

/** \brief IfxCanxl_Txd_Out Table
 */
IFX_EXTERN IFX_CONST IfxCanxl_Txd_Out *IfxCanxl_Txd_Out_pinTable[IFXCANXL_PINMAP_NUM_MODULES][IFXCANXL_PINMAP_NUM_NODES][IFXCANXL_PINMAP_TXD_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXCANXL_PINMAP_TC4DX_BGA292_COM_H */
