/**
 * \file IfxGpt12_PinMap.h
 * \brief GPT12 I/O map
 * \ingroup IfxLld_Gpt12
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Gpt12_pinmap GPT12 Pin Mapping
 * \ingroup IfxLld_Gpt12
 */

#ifndef IFXGPT12_PINMAP_H
#define IFXGPT12_PINMAP_H

#include <IfxGpt12_reg.h>
#include <_Impl/IfxGpt12_cfg.h>
#include <Port/Std/IfxPort.h>

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

IFX_EXTERN IfxGpt12_Capin_In IfxGpt120_CAPINA_P13_2_IN;  /**< \brief GPT120_CAPINA: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T2EUDA_P00_8_IN;  /**< \brief GPT120_T2EUDA: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T2EUDB_P33_6_IN;  /**< \brief GPT120_T2EUDB: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T3EUDA_P02_7_IN;  /**< \brief GPT120_T3EUDA: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T3EUDB_P10_7_IN;  /**< \brief GPT120_T3EUDB: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T4EUDA_P00_9_IN;  /**< \brief GPT120_T4EUDA: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T4EUDB_P33_5_IN;  /**< \brief GPT120_T4EUDB: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T5EUDA_P21_6_IN;  /**< \brief GPT120_T5EUDA: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T5EUDB_P10_1_IN;  /**< \brief GPT120_T5EUDB: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T6EUDA_P20_0_IN;  /**< \brief GPT120_T6EUDA: GPT120 input */
IFX_EXTERN IfxGpt12_TxEud_In IfxGpt120_T6EUDB_P10_0_IN;  /**< \brief GPT120_T6EUDB: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T2INA_P00_7_IN;  /**< \brief GPT120_T2INA: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T2INB_P33_7_IN;  /**< \brief GPT120_T2INB: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T3INA_P02_6_IN;  /**< \brief GPT120_T3INA: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T3INB_P10_4_IN;  /**< \brief GPT120_T3INB: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T4INA_P02_8_IN;  /**< \brief GPT120_T4INA: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T4INB_P10_8_IN;  /**< \brief GPT120_T4INB: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T5INA_P21_7_IN;  /**< \brief GPT120_T5INA: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T5INB_P10_3_IN;  /**< \brief GPT120_T5INB: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T6INA_P20_3_IN;  /**< \brief GPT120_T6INA: GPT120 input */
IFX_EXTERN IfxGpt12_TxIn_In IfxGpt120_T6INB_P10_2_IN;  /**< \brief GPT120_T6INB: GPT120 input */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P10_6_OUT;  /**< \brief GPT120_T3OUT: GPT120 output */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P21_6_OUT;  /**< \brief GPT120_T3OUT: GPT120 output */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P10_5_OUT;  /**< \brief GPT120_T6OUT: GPT120 output */
IFX_EXTERN IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P21_7_OUT;  /**< \brief GPT120_T6OUT: GPT120 output */

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

#endif /* IFXGPT12_PINMAP_H */
