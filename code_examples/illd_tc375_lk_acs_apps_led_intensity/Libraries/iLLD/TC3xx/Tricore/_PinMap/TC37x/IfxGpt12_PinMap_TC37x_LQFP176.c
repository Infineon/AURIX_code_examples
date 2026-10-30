/**
 * \file IfxGpt12_PinMap_TC37x_LQFP176.c
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
 */
#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if defined DEVICE_TC37X && defined IFX_PIN_PACKAGE_LQFP176
#include "IfxGpt12_PinMap_TC37x_LQFP176.h"

IfxGpt12_Capin_In IfxGpt120_CAPINA_P13_2_IN = {&MODULE_GPT120, {&MODULE_P13, 2}, Ifx_RxSel_a};
IfxGpt12_TxEud_In IfxGpt120_T2EUDA_P00_8_IN = {&MODULE_GPT120, 2, {&MODULE_P00, 8}, Ifx_RxSel_a};
IfxGpt12_TxEud_In IfxGpt120_T2EUDB_P33_6_IN = {&MODULE_GPT120, 2, {&MODULE_P33, 6}, Ifx_RxSel_b};
IfxGpt12_TxEud_In IfxGpt120_T3EUDA_P02_7_IN = {&MODULE_GPT120, 3, {&MODULE_P02, 7}, Ifx_RxSel_a};
IfxGpt12_TxEud_In IfxGpt120_T3EUDB_P10_7_IN = {&MODULE_GPT120, 3, {&MODULE_P10, 7}, Ifx_RxSel_b};
IfxGpt12_TxEud_In IfxGpt120_T4EUDA_P00_9_IN = {&MODULE_GPT120, 4, {&MODULE_P00, 9}, Ifx_RxSel_a};
IfxGpt12_TxEud_In IfxGpt120_T4EUDB_P33_5_IN = {&MODULE_GPT120, 4, {&MODULE_P33, 5}, Ifx_RxSel_b};
IfxGpt12_TxEud_In IfxGpt120_T5EUDA_P21_6_IN = {&MODULE_GPT120, 5, {&MODULE_P21, 6}, Ifx_RxSel_a};
IfxGpt12_TxEud_In IfxGpt120_T5EUDB_P10_1_IN = {&MODULE_GPT120, 5, {&MODULE_P10, 1}, Ifx_RxSel_b};
IfxGpt12_TxEud_In IfxGpt120_T6EUDA_P20_0_IN = {&MODULE_GPT120, 6, {&MODULE_P20, 0}, Ifx_RxSel_a};
IfxGpt12_TxEud_In IfxGpt120_T6EUDB_P10_0_IN = {&MODULE_GPT120, 6, {&MODULE_P10, 0}, Ifx_RxSel_b};
IfxGpt12_TxIn_In IfxGpt120_T2INA_P00_7_IN = {&MODULE_GPT120, 2, {&MODULE_P00, 7}, Ifx_RxSel_a};
IfxGpt12_TxIn_In IfxGpt120_T2INB_P33_7_IN = {&MODULE_GPT120, 2, {&MODULE_P33, 7}, Ifx_RxSel_b};
IfxGpt12_TxIn_In IfxGpt120_T3INA_P02_6_IN = {&MODULE_GPT120, 3, {&MODULE_P02, 6}, Ifx_RxSel_a};
IfxGpt12_TxIn_In IfxGpt120_T3INB_P10_4_IN = {&MODULE_GPT120, 3, {&MODULE_P10, 4}, Ifx_RxSel_b};
IfxGpt12_TxIn_In IfxGpt120_T4INA_P02_8_IN = {&MODULE_GPT120, 4, {&MODULE_P02, 8}, Ifx_RxSel_a};
IfxGpt12_TxIn_In IfxGpt120_T4INB_P10_8_IN = {&MODULE_GPT120, 4, {&MODULE_P10, 8}, Ifx_RxSel_b};
IfxGpt12_TxIn_In IfxGpt120_T5INA_P21_7_IN = {&MODULE_GPT120, 5, {&MODULE_P21, 7}, Ifx_RxSel_a};
IfxGpt12_TxIn_In IfxGpt120_T5INB_P10_3_IN = {&MODULE_GPT120, 5, {&MODULE_P10, 3}, Ifx_RxSel_b};
IfxGpt12_TxIn_In IfxGpt120_T6INA_P20_3_IN = {&MODULE_GPT120, 6, {&MODULE_P20, 3}, Ifx_RxSel_a};
IfxGpt12_TxIn_In IfxGpt120_T6INB_P10_2_IN = {&MODULE_GPT120, 6, {&MODULE_P10, 2}, Ifx_RxSel_b};
IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P10_6_OUT = {&MODULE_GPT120, 3, {&MODULE_P10, 6}, IfxPort_OutputIdx_alt4};
IfxGpt12_TxOut_Out IfxGpt120_T3OUT_P21_6_OUT = {&MODULE_GPT120, 3, {&MODULE_P21, 6}, IfxPort_OutputIdx_alt7};
IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P10_5_OUT = {&MODULE_GPT120, 6, {&MODULE_P10, 5}, IfxPort_OutputIdx_alt5};
IfxGpt12_TxOut_Out IfxGpt120_T6OUT_P21_7_OUT = {&MODULE_GPT120, 6, {&MODULE_P21, 7}, IfxPort_OutputIdx_alt7};


const IfxGpt12_Capin_In *IfxGpt12_Capin_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_CAPIN_IN_NUM_ITEMS] = {
    {
        &IfxGpt120_CAPINA_P13_2_IN
    }
};

const IfxGpt12_TxEud_In *IfxGpt12_TxEud_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXEUD_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR
        },
        {
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxGpt120_T2EUDA_P00_8_IN,
            &IfxGpt120_T2EUDB_P33_6_IN
        },
        {
            &IfxGpt120_T3EUDA_P02_7_IN,
            &IfxGpt120_T3EUDB_P10_7_IN
        },
        {
            &IfxGpt120_T4EUDA_P00_9_IN,
            &IfxGpt120_T4EUDB_P33_5_IN
        },
        {
            &IfxGpt120_T5EUDA_P21_6_IN,
            &IfxGpt120_T5EUDB_P10_1_IN
        },
        {
            &IfxGpt120_T6EUDA_P20_0_IN,
            &IfxGpt120_T6EUDB_P10_0_IN
        }
    }
};

const IfxGpt12_TxIn_In *IfxGpt12_TxIn_In_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXIN_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR
        },
        {
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxGpt120_T2INA_P00_7_IN,
            &IfxGpt120_T2INB_P33_7_IN
        },
        {
            &IfxGpt120_T3INA_P02_6_IN,
            &IfxGpt120_T3INB_P10_4_IN
        },
        {
            &IfxGpt120_T4INA_P02_8_IN,
            &IfxGpt120_T4INB_P10_8_IN
        },
        {
            &IfxGpt120_T5INA_P21_7_IN,
            &IfxGpt120_T5INB_P10_3_IN
        },
        {
            &IfxGpt120_T6INA_P20_3_IN,
            &IfxGpt120_T6INB_P10_2_IN
        }
    }
};

const IfxGpt12_TxOut_Out *IfxGpt12_TxOut_Out_pinTable[IFXGPT12_PINMAP_NUM_MODULES][IFXGPT12_PINMAP_NUM_TIMERS][IFXGPT12_PINMAP_TXOUT_OUT_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR
        },
        {
            NULL_PTR,
            NULL_PTR
        },
        {
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxGpt120_T3OUT_P10_6_OUT,
            &IfxGpt120_T3OUT_P21_6_OUT
        },
        {
            NULL_PTR,
            NULL_PTR
        },
        {
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxGpt120_T6OUT_P10_5_OUT,
            &IfxGpt120_T6OUT_P21_7_OUT
        }
    }
};
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
