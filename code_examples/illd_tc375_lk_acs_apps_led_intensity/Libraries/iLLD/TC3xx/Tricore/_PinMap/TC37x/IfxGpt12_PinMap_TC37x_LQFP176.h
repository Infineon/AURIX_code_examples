/**
 * \file IfxGpt12_PinMap_TC37x_LQFP176.h
 * \brief GPT12 I/O map
 * \ingroup IfxLld_Gpt12
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Gpt12_pinmap GPT12 Pin Mapping
 * \ingroup IfxLld_Gpt12
 */

#ifndef IFXGPT12_PINMAP_TC37X_LQFP176_H
#define IFXGPT12_PINMAP_TC37X_LQFP176_H 1

#include <IfxGpt12_reg.h>
#include <_Impl/IfxGpt12_cfg.h>
#include <Port/Std/IfxPort.h>
#include "Ifx_PinMap.h"

/** \addtogroup IfxLld_Gpt12_pinmap
 * \{ */

/** \brief CAPIN pin mapping structure */
typedef const struct
{
    Ifx_GPT12*        module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxGpt12_Capin_In;

/** \brief TxEUD pin mapping structure */
typedef const struct
{
    Ifx_GPT12*        module;   /**< \brief Base address */
    uint8             timer;    /**< \brief Timer number */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxGpt12_TxEud_In;

/** \brief TxIN pin mapping structure */
typedef const struct
{
    Ifx_GPT12*        module;   /**< \brief Base address */
    uint8             timer;    /**< \brief Timer number */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxGpt12_TxIn_In;

/** \brief TxOUT pin mapping structure */
typedef const struct
{
    Ifx_GPT12*        module;   /**< \brief Base address */
    uint8             timer;    /**< \brief Timer number */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxGpt12_TxOut_Out;

IFX_EXTERN IfxGpt12_Capin_In IfxGpt120_CAPINA_P13_2_IN;  /**< \brief Trigger input to capture value of timer T5 into CAPREL register */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T2EUDA_P00_8_IN;  /**< \brief Count direction control input of timer T2 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T2EUDB_P33_6_IN;  /**< \brief Count direction control input of timer T2 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T3EUDA_P02_7_IN;  /**< \brief Count direction control input of core timer T3 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T3EUDB_P10_7_IN;  /**< \brief Count direction control input of core timer T3 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T4EUDA_P00_9_IN;  /**< \brief Count direction control input of timer T4 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T4EUDB_P33_5_IN;  /**< \brief Count direction control input of timer T4 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T5EUDA_P21_6_IN;  /**< \brief Count direction control input of timer T5 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T5EUDB_P10_1_IN;  /**< \brief Count direction control input of timer T5 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T6EUDA_P20_0_IN;  /**< \brief Count direction control input of core timer T6 */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T6EUDB_P10_0_IN;  /**< \brief Count direction control input of core timer T6 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T2INA_P00_7_IN;  /**< \brief Trigger/gate input of timer T2 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T2INB_P33_7_IN;  /**< \brief Trigger/gate input of timer T2 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T3INA_P02_6_IN;  /**< \brief Trigger/gate input of core timer T3 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T3INB_P10_4_IN;  /**< \brief Trigger/gate input of core timer T3 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T4INA_P02_8_IN;  /**< \brief Trigger/gate input of timer T4 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T4INB_P10_8_IN;  /**< \brief Trigger/gate input of timer T4 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T5INA_P21_7_IN;  /**< \brief Trigger/gate input of timer T5 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T5INB_P10_3_IN;  /**< \brief Trigger/gate input of timer T5 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T6INA_P20_3_IN;  /**< \brief Trigger/gate input of core timer T6 */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T6INB_P10_2_IN;  /**< \brief Trigger/gate input of core timer T6 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P10_6_OUT;  /**< \brief External output for overflow/underflow detection of core timer T3 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P21_6_OUT;  /**< \brief External output for overflow/underflow detection of core timer T3 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P10_5_OUT;  /**< \brief External output for overflow/underflow detection of core timer T6 */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P21_7_OUT;  /**< \brief External output for overflow/underflow detection of core timer T6 */

/** \brief Table dimensions */
#define IFXGPT12_PINMAP_NUM_MODULES 1
#define IFXGPT12_PINMAP_NUM_TIMERS 7
#define IFXGPT12_PINMAP_CAPIN_IN_NUM_ITEMS 1
#define IFXGPT12_PINMAP_TXEUD_IN_NUM_ITEMS 2
#define IFXGPT12_PINMAP_TXIN_IN_NUM_ITEMS 2
#define IFXGPT12_PINMAP_TXOUT_OUT_NUM_ITEMS 2


/** \brief IfxGpt12_Capin_In table */
IFX_EXTERN const IfxGpt12_Capin_In *IfxGpt12_Capin_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_CAPIN_IN_NUM_ITEMS];

/** \brief IfxGpt12_TxEud_In table */
IFX_EXTERN const IfxGpt12_TxEud_In *IfxGpt12_TxEud_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXEUD_IN_NUM_ITEMS];

/** \brief IfxGpt12_TxIn_In table */
IFX_EXTERN const IfxGpt12_TxIn_In *IfxGpt12_TxIn_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXIN_IN_NUM_ITEMS];

/** \brief IfxGpt12_TxOut_Out table */
IFX_EXTERN const IfxGpt12_TxOut_Out *IfxGpt12_TxOut_Out_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXOUT_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXGPT12_PINMAP_TC37X_LQFP176_H */
