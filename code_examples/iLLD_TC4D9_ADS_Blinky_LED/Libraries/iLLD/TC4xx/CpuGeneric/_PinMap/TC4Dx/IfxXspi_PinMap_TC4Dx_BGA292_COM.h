/**
 * \file IfxXspi_PinMap_TC4Dx_BGA292_COM.h
 * \brief XSPI  details
 * \ingroup IfxLld_Xspi
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
 * \defgroup IfxLld_Xspi_
 * \ingroup IfxLld_Xspi
 * \defgroup IfxLld_Xspi__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Xspi_
 * \defgroup IfxLld_Xspi__PinTables PinTables
 * \ingroup IfxLld_Xspi_
 */

#ifndef IFXXSPI_PINMAP_TC4DX_BGA292_COM_H
#define IFXXSPI_PINMAP_TC4DX_BGA292_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxXspi_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXXSPI_PINMAP_NUM_MODULES          1

#define IFXXSPI_PINMAP_CLK_OUT_NUM_ITEMS    3

#define IFXXSPI_PINMAP_CS_OUT_NUM_ITEMS     4

#define IFXXSPI_PINMAP_DM_INOUT_NUM_ITEMS   1

#define IFXXSPI_PINMAP_TXD0_INOUT_NUM_ITEMS 2

#define IFXXSPI_PINMAP_TXD1_INOUT_NUM_ITEMS 2

#define IFXXSPI_PINMAP_TXD2_INOUT_NUM_ITEMS 2

#define IFXXSPI_PINMAP_TXD3_INOUT_NUM_ITEMS 2

#define IFXXSPI_PINMAP_TXD4_INOUT_NUM_ITEMS 1

#define IFXXSPI_PINMAP_TXD5_INOUT_NUM_ITEMS 1

#define IFXXSPI_PINMAP_TXD6_INOUT_NUM_ITEMS 1

#define IFXXSPI_PINMAP_TXD7_INOUT_NUM_ITEMS 1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief
 */
IFX_EXTERN IfxXspi_Clk_Out    IfxXspi0_CLK_P16_0_OUT;

/** \brief
 */
IFX_EXTERN IfxXspi_Clk_Out    IfxXspi0_CLK_P16_1_OUT;

/** \brief
 */
IFX_EXTERN IfxXspi_Clk_Out    IfxXspi0_CLK_P20_13_OUT;

/** \brief
 */
IFX_EXTERN IfxXspi_Cs_Out     IfxXspi0_CS_P16_13_OUT;

/** \brief
 */
IFX_EXTERN IfxXspi_Cs_Out     IfxXspi0_CS_P16_4_OUT;

/** \brief
 */
IFX_EXTERN IfxXspi_Cs_Out     IfxXspi0_CS_P20_0_OUT;

/** \brief
 */
IFX_EXTERN IfxXspi_Cs_Out     IfxXspi0_CS_P20_14_OUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Dm_InOut   IfxXspi0_DM_P16_2_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd0_InOut IfxXspi0_TXD0_P16_7_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd0_InOut IfxXspi0_TXD0_P20_3_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd1_InOut IfxXspi0_TXD1_P16_3_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd1_InOut IfxXspi0_TXD1_P20_6_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd2_InOut IfxXspi0_TXD2_P16_5_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd2_InOut IfxXspi0_TXD2_P20_9_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd3_InOut IfxXspi0_TXD3_P15_2_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd3_InOut IfxXspi0_TXD3_P16_6_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd4_InOut IfxXspi0_TXD4_P16_8_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd5_InOut IfxXspi0_TXD5_P16_9_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd6_InOut IfxXspi0_TXD6_P16_10_INOUT;

/** \brief and
 */
IFX_EXTERN IfxXspi_Txd7_InOut IfxXspi0_TXD7_P16_12_INOUT;

/** \addtogroup IfxLld_Xspi__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxXspi_Clk_Out Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Clk_Out    *IfxXspi_Clk_Out_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_CLK_OUT_NUM_ITEMS];

/** \brief IfxXspi_Cs_Out Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Cs_Out     *IfxXspi_Cs_Out_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_CS_OUT_NUM_ITEMS];

/** \brief IfxXspi_Dm_InOut Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Dm_InOut   *IfxXspi_Dm_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_DM_INOUT_NUM_ITEMS];

/** \brief IfxXspi_Txd0_InOut Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Txd0_InOut *IfxXspi_Txd0_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD0_INOUT_NUM_ITEMS];

/** \brief IfxXspi_Txd1_InOut Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Txd1_InOut *IfxXspi_Txd1_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD1_INOUT_NUM_ITEMS];

/** \brief IfxXspi_Txd2_InOut Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Txd2_InOut *IfxXspi_Txd2_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD2_INOUT_NUM_ITEMS];

/** \brief IfxXspi_Txd3_InOut Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Txd3_InOut *IfxXspi_Txd3_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD3_INOUT_NUM_ITEMS];

/** \brief IfxXspi_Txd4_InOut Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Txd4_InOut *IfxXspi_Txd4_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD4_INOUT_NUM_ITEMS];

/** \brief IfxXspi_Txd5_InOut Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Txd5_InOut *IfxXspi_Txd5_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD5_INOUT_NUM_ITEMS];

/** \brief IfxXspi_Txd6_InOut Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Txd6_InOut *IfxXspi_Txd6_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD6_INOUT_NUM_ITEMS];

/** \brief IfxXspi_Txd7_InOut Table
 */
IFX_EXTERN IFX_CONST IfxXspi_Txd7_InOut *IfxXspi_Txd7_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD7_INOUT_NUM_ITEMS];

/** \} */

#endif /* IFXXSPI_PINMAP_TC4DX_BGA292_COM_H */
