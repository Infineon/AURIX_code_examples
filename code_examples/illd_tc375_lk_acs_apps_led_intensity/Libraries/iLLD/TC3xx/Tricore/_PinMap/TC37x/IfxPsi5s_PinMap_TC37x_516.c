/**
 * \file IfxPsi5s_PinMap_TC37x_516.c
 * \brief PSI5S I/O map
 * \ingroup IfxLld_Psi5s
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

#if defined DEVICE_TC37X && defined IFX_PIN_PACKAGE_516
#include "IfxPsi5s_PinMap_TC37x_516.h"

IfxPsi5s_Clk_Out IfxPsi5s_CLK_P02_4_OUT = {&MODULE_PSI5S, {&MODULE_P02, 4}, IfxPort_OutputIdx_alt4};
IfxPsi5s_Clk_Out IfxPsi5s_CLK_P33_10_OUT = {&MODULE_PSI5S, {&MODULE_P33,10}, IfxPort_OutputIdx_alt5};
IfxPsi5s_Rx_In IfxPsi5s_RXA_P00_3_IN = {&MODULE_PSI5S, {&MODULE_P00, 3}, Ifx_RxSel_a};
IfxPsi5s_Rx_In IfxPsi5s_RXB_P02_5_IN = {&MODULE_PSI5S, {&MODULE_P02, 5}, Ifx_RxSel_b};
IfxPsi5s_Rx_In IfxPsi5s_RXC_P33_5_IN = {&MODULE_PSI5S, {&MODULE_P33, 5}, Ifx_RxSel_c};
IfxPsi5s_Tx_Out IfxPsi5s_TX_P00_4_OUT = {&MODULE_PSI5S, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt2};
IfxPsi5s_Tx_Out IfxPsi5s_TX_P02_6_OUT = {&MODULE_PSI5S, {&MODULE_P02, 6}, IfxPort_OutputIdx_alt2};
IfxPsi5s_Tx_Out IfxPsi5s_TX_P33_6_OUT = {&MODULE_PSI5S, {&MODULE_P33, 6}, IfxPort_OutputIdx_alt7};


const IfxPsi5s_Clk_Out *IfxPsi5s_Clk_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_CLK_OUT_NUM_ITEMS] = {
    {
        &IfxPsi5s_CLK_P02_4_OUT,
        &IfxPsi5s_CLK_P33_10_OUT
    }
};

const IfxPsi5s_Rx_In *IfxPsi5s_Rx_In_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_RX_IN_NUM_ITEMS] = {
    {
        &IfxPsi5s_RXA_P00_3_IN,
        &IfxPsi5s_RXB_P02_5_IN,
        &IfxPsi5s_RXC_P33_5_IN
    }
};

const IfxPsi5s_Tx_Out *IfxPsi5s_Tx_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_TX_OUT_NUM_ITEMS] = {
    {
        &IfxPsi5s_TX_P00_4_OUT,
        &IfxPsi5s_TX_P02_6_OUT,
        &IfxPsi5s_TX_P33_6_OUT
    }
};
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
