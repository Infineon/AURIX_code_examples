/**
 * \file IfxGpt12_PinMap_TC48x_BGA292_STD.h
 * \brief GPT12  details
 * \ingroup IfxLld_Gpt12
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
 * Version: MC_ACE_A3G_PRQ_Package_Pinning/v8.2.1.1.2
 * Document: TC48x_A21_Pin_Assignment_v0.2.6_20251118.xls 
 *
 * \defgroup IfxLld_Gpt12_Pinmap Gpt12 Pinmap Structure
 * \ingroup IfxLld_Gpt12
 * \defgroup IfxLld_Gpt12__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Gpt12_
 * \defgroup IfxLld_Gpt12__PinTables PinTables
 * \ingroup IfxLld_Gpt12_
 */

#ifndef IFXGPT12_PINMAP_TC48X_BGA292_STD_H
#define IFXGPT12_PINMAP_TC48X_BGA292_STD_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxGpt12_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXGPT12_PINMAP_NUM_MODULES         4

#define IFXGPT12_PINMAP_CAPIN_IN_NUM_ITEMS  8

#define IFXGPT12_PINMAP_NUM_TIMERS          7

#define IFXGPT12_PINMAP_TXEUD_IN_NUM_ITEMS  2

#define IFXGPT12_PINMAP_TXIN_IN_NUM_ITEMS   2

#define IFXGPT12_PINMAP_TXOUT_OUT_NUM_ITEMS 3

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief
 */
IFX_EXTERN IfxGpt12_Capin_In  IfxGpt120_CAPINA_P13_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_Capin_In  IfxGpt120_CAPINB3_P33_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt120_T2EUDB_P33_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T2INA_P00_7_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T2INB_P33_7_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt120_T3EUDA_P02_7_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt120_T3EUDB_P10_7_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T3INA_P02_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T3INB_P10_4_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P10_6_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P21_6_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt120_T4EUDA_P00_9_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt120_T4EUDB_P33_5_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T4INA_P02_8_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T4INB_P10_8_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt120_T5EUDA_P21_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt120_T5EUDB_P10_1_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T5INA_P21_7_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T5INB_P10_3_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt120_T6EUDA_P20_0_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt120_T6EUDB_P10_0_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T6INA_P20_3_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt120_T6INB_P10_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P10_5_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P21_7_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_Capin_In  IfxGpt121_CAPINA_P00_0_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_Capin_In  IfxGpt121_CAPINB3_P02_1_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt121_T2EUDA_P00_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt121_T2EUDB_P11_11_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T2INA_P00_1_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T2INB_P11_10_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt121_T3EUDA_P00_10_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt121_T3EUDB_P11_3_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T3INA_P00_11_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T3INB_P11_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt121_T3OUT_P00_6_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt121_T3OUT_P11_9_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt121_T4EUDB_P11_12_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T4INA_P00_12_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T4INB_P11_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt121_T5EUDA_P00_5_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt121_T5EUDB_P11_9_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T5INA_P00_4_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T5INB_P11_8_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt121_T6EUDA_P00_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt121_T6EUDB_P13_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T6INA_P00_7_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt121_T6INB_P13_0_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt121_T6OUT_P00_9_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt121_T6OUT_P13_1_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_Capin_In  IfxGpt122_CAPINA_P33_1_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_Capin_In  IfxGpt122_CAPINB3_P23_3_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T2EUDA_P33_7_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T2EUDB_P20_3_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T2INA_P33_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T2INB_P20_0_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T3EUDA_P34_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T3EUDB_P22_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T3INA_P34_1_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T3INB_P22_5_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt122_T3OUT_P21_1_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt122_T3OUT_P33_2_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T4EUDA_P33_9_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T4EUDB_P20_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T4INA_P34_3_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T4INB_P22_7_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T5EUDA_P33_12_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T5EUDB_P22_9_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T5INA_P33_11_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T5INB_P22_8_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T6EUDA_P33_13_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt122_T6EUDB_P22_11_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T6INA_P33_0_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt122_T6INB_P22_10_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt122_T6OUT_P22_9_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt122_T6OUT_P33_3_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_Capin_In  IfxGpt123_CAPINA_P23_1_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_Capin_In  IfxGpt123_CAPINB3_P15_7_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T2EUDA_P22_1_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T2EUDB_P15_1_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T2INA_P22_0_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T2INB_P15_0_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T3EUDA_P21_3_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T3EUDB_P14_8_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T3INA_P21_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T3INB_P14_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt123_T3OUT_P10_4_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt123_T3OUT_P14_4_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt123_T3OUT_P21_5_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T4EUDA_P22_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T4EUDB_P15_2_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T4INA_P21_4_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T4INB_P14_10_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T5EUDA_P22_4_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T5EUDB_P15_3_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T5INA_P22_3_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T5INB_P15_4_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T6EUDA_P21_0_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxEud_In  IfxGpt123_T6EUDB_P15_6_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T6INA_P21_5_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxIn_In   IfxGpt123_T6INB_P15_5_IN;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt123_T6OUT_P15_8_OUT;

/** \brief
 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt123_T6OUT_P21_0_OUT;

/** \addtogroup IfxLld_Gpt12__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxGpt12_Capin_In Table
 */
IFX_EXTERN IFX_CONST IfxGpt12_Capin_In  *IfxGpt12_Capin_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_CAPIN_IN_NUM_ITEMS];

/** \brief IfxGpt12_TxEud_In Table
 */
IFX_EXTERN IFX_CONST IfxGpt12_TxEud_In  *IfxGpt12_TxEud_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXEUD_IN_NUM_ITEMS];

/** \brief IfxGpt12_TxIn_In Table
 */
IFX_EXTERN IFX_CONST IfxGpt12_TxIn_In   *IfxGpt12_TxIn_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXIN_IN_NUM_ITEMS];

/** \brief IfxGpt12_TxOut_Out Table
 */
IFX_EXTERN IFX_CONST IfxGpt12_TxOut_Out *IfxGpt12_TxOut_Out_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXOUT_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXGPT12_PINMAP_TC48X_BGA292_STD_H */
