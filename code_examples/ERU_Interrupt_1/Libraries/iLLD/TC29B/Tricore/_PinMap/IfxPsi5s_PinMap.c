/**
 * \file IfxPsi5s_PinMap.c
 * \brief PSI5S I/O map
 * \ingroup IfxLld_Psi5s
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
 */

#include "IfxPsi5s_PinMap.h"

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
