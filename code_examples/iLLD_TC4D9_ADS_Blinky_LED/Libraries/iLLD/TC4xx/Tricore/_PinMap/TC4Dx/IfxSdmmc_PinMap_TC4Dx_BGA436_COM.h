/**
 * \file IfxSdmmc_PinMap_TC4Dx_BGA436_COM.h
 * \brief SDMMC  details
 * \ingroup IfxLld_Sdmmc
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
 * \defgroup IfxLld_Sdmmc_
 * \ingroup IfxLld_Sdmmc
 * \defgroup IfxLld_Sdmmc__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Sdmmc_
 * \defgroup IfxLld_Sdmmc__PinTables PinTables
 * \ingroup IfxLld_Sdmmc_
 */

#ifndef IFXSDMMC_PINMAP_TC4DX_BGA436_COM_H
#define IFXSDMMC_PINMAP_TC4DX_BGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxSdmmc_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXSDMMC_PINMAP_NUM_MODULES          1

#define IFXSDMMC_PINMAP_CLK_OUT_NUM_ITEMS    1

#define IFXSDMMC_PINMAP_CLKRX_IN_NUM_ITEMS   1

#define IFXSDMMC_PINMAP_CMD_INOUT_NUM_ITEMS  1

#define IFXSDMMC_PINMAP_DAT0_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT1_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT2_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT3_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT4_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT5_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT6_INOUT_NUM_ITEMS 1

#define IFXSDMMC_PINMAP_DAT7_INOUT_NUM_ITEMS 1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Delayed card clock
 */
IFX_EXTERN IfxSdmmc_Clkrx_In   IfxSdmmc0_CLKRX_P15_1_IN;

/** \brief Card clock
 */
IFX_EXTERN IfxSdmmc_Clk_Out    IfxSdmmc0_CLK_P15_1_OUT;

/** \brief Command out and Command in
 */
IFX_EXTERN IfxSdmmc_Cmd_InOut  IfxSdmmc0_CMD_P15_3_INOUT;

/** \brief Write data out and Read data in
 */
IFX_EXTERN IfxSdmmc_Dat0_InOut IfxSdmmc0_DAT0_P20_7_INOUT;

/** \brief Write data out and Read data in
 */
IFX_EXTERN IfxSdmmc_Dat1_InOut IfxSdmmc0_DAT1_P20_8_INOUT;

/** \brief Write data out and Read data in
 */
IFX_EXTERN IfxSdmmc_Dat2_InOut IfxSdmmc0_DAT2_P20_10_INOUT;

/** \brief Write data out and Read data in
 */
IFX_EXTERN IfxSdmmc_Dat3_InOut IfxSdmmc0_DAT3_P20_11_INOUT;

/** \brief Write data out and Read data in
 */
IFX_EXTERN IfxSdmmc_Dat4_InOut IfxSdmmc0_DAT4_P20_12_INOUT;

/** \brief Write data out and Read data in
 */
IFX_EXTERN IfxSdmmc_Dat5_InOut IfxSdmmc0_DAT5_P20_13_INOUT;

/** \brief Write data out and Read data in
 */
IFX_EXTERN IfxSdmmc_Dat6_InOut IfxSdmmc0_DAT6_P20_14_INOUT;

/** \brief Write data out and Read data in
 */
IFX_EXTERN IfxSdmmc_Dat7_InOut IfxSdmmc0_DAT7_P15_0_INOUT;

/** \addtogroup IfxLld_Sdmmc__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxSdmmc_Clk_Out Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Clk_Out    *IfxSdmmc_Clk_Out_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_CLK_OUT_NUM_ITEMS];

/** \brief IfxSdmmc_Clkrx_In Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Clkrx_In   *IfxSdmmc_Clkrx_In_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_CLKRX_IN_NUM_ITEMS];

/** \brief IfxSdmmc_Cmd_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Cmd_InOut  *IfxSdmmc_Cmd_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_CMD_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat0_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat0_InOut *IfxSdmmc_Dat0_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT0_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat1_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat1_InOut *IfxSdmmc_Dat1_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT1_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat2_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat2_InOut *IfxSdmmc_Dat2_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT2_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat3_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat3_InOut *IfxSdmmc_Dat3_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT3_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat4_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat4_InOut *IfxSdmmc_Dat4_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT4_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat5_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat5_InOut *IfxSdmmc_Dat5_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT5_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat6_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat6_InOut *IfxSdmmc_Dat6_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT6_INOUT_NUM_ITEMS];

/** \brief IfxSdmmc_Dat7_InOut Table
 */
IFX_EXTERN IFX_CONST IfxSdmmc_Dat7_InOut *IfxSdmmc_Dat7_InOut_pinTable[IFXSDMMC_PINMAP_NUM_MODULES][IFXSDMMC_PINMAP_DAT7_INOUT_NUM_ITEMS];

/** \} */

#endif /* IFXSDMMC_PINMAP_TC4DX_BGA436_COM_H */
