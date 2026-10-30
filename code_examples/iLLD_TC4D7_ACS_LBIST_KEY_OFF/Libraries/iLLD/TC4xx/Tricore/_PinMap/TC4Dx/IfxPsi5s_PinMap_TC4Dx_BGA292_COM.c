/**
 * \file IfxPsi5s_PinMap_TC4Dx_BGA292_COM.c
 * \brief PSI5S  details
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(__TASKING__)
#pragma warning 508
#endif

#if defined(__ghs__)
#pragma ghs nowarning 96
#endif
#include "Ifx_PinMap.h"
#if defined(DEVICE_TC4DX) && defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "IfxPsi5s_PinMap_TC4Dx_BGA292_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxPsi5s_Clk_Out IfxPsi5s_CLK_P02_4_OUT = {&MODULE_PSI5S0, {&MODULE_P02, 4}, IfxPort_OutputIdx_alt4};

IfxPsi5s_Clk_Out IfxPsi5s_CLK_P33_10_OUT = {&MODULE_PSI5S0, {&MODULE_P33, 10}, IfxPort_OutputIdx_alt5};

IfxPsi5s_Rx_In   IfxPsi5s_RXA_P00_3_IN = {&MODULE_PSI5S0, {&MODULE_P00, 3}, Ifx_RxSel_a};

IfxPsi5s_Rx_In   IfxPsi5s_RXB_P02_5_IN = {&MODULE_PSI5S0, {&MODULE_P02, 5}, Ifx_RxSel_b};

IfxPsi5s_Rx_In   IfxPsi5s_RXC_P33_5_IN = {&MODULE_PSI5S0, {&MODULE_P33, 5}, Ifx_RxSel_c};

IfxPsi5s_Rx_In   IfxPsi5s_RXD_P33_7_IN = {&MODULE_PSI5S0, {&MODULE_P33, 7}, Ifx_RxSel_d};

IfxPsi5s_Tx_Out  IfxPsi5s_TX_P00_4_OUT = {&MODULE_PSI5S0, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt2};

IfxPsi5s_Tx_Out  IfxPsi5s_TX_P02_6_OUT = {&MODULE_PSI5S0, {&MODULE_P02, 6}, IfxPort_OutputIdx_alt2};

IfxPsi5s_Tx_Out  IfxPsi5s_TX_P33_6_OUT = {&MODULE_PSI5S0, {&MODULE_P33, 6}, IfxPort_OutputIdx_alt7};

/** \addtogroup IfxLld_Psi5s__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxPsi5s_Clk_Out *IfxPsi5s_Clk_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_CLK_OUT_NUM_ITEMS] = {
    {
        &IfxPsi5s_CLK_P02_4_OUT,
        &IfxPsi5s_CLK_P33_10_OUT,
    },
};

IFX_CONST IfxPsi5s_Rx_In   *IfxPsi5s_Rx_In_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_RX_IN_NUM_ITEMS] = {
    {
        &IfxPsi5s_RXA_P00_3_IN,
        &IfxPsi5s_RXB_P02_5_IN,
        &IfxPsi5s_RXC_P33_5_IN,
        &IfxPsi5s_RXD_P33_7_IN,
    },
};

IFX_CONST IfxPsi5s_Tx_Out  *IfxPsi5s_Tx_Out_pinTable[IFXPSI5S_PINMAP_NUM_MODULES][IFXPSI5S_PINMAP_TX_OUT_NUM_ITEMS] = {
    {
        &IfxPsi5s_TX_P00_4_OUT,
        &IfxPsi5s_TX_P02_6_OUT,
        &IfxPsi5s_TX_P33_6_OUT,
    },
};

/** \} */

#endif
