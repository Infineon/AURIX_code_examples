/**
 * \file IfxPsi5_PinMap_TC4Dx_BGA436_COM.c
 * \brief PSI5  details
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
#if defined(DEVICE_TC4DX) && defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "IfxPsi5_PinMap_TC4Dx_BGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxPsi5_Rx_In  IfxPsi5_RX0A_P00_1_IN = {&MODULE_PSI5, (IfxPsi5_ChannelId)0, {&MODULE_P00, 1}, Ifx_RxSel_a};

IfxPsi5_Rx_In  IfxPsi5_RX0B_P02_3_IN = {&MODULE_PSI5, (IfxPsi5_ChannelId)0, {&MODULE_P02, 3}, Ifx_RxSel_b};

IfxPsi5_Rx_In  IfxPsi5_RX0C_P33_1_IN = {&MODULE_PSI5, (IfxPsi5_ChannelId)0, {&MODULE_P33, 1}, Ifx_RxSel_c};

IfxPsi5_Rx_In  IfxPsi5_RX1A_P00_3_IN = {&MODULE_PSI5, (IfxPsi5_ChannelId)1, {&MODULE_P00, 3}, Ifx_RxSel_a};

IfxPsi5_Rx_In  IfxPsi5_RX1B_P02_5_IN = {&MODULE_PSI5, (IfxPsi5_ChannelId)1, {&MODULE_P02, 5}, Ifx_RxSel_b};

IfxPsi5_Rx_In  IfxPsi5_RX1C_P33_3_IN = {&MODULE_PSI5, (IfxPsi5_ChannelId)1, {&MODULE_P33, 3}, Ifx_RxSel_c};

IfxPsi5_Tx_Out IfxPsi5_TX0_P00_2_OUT = {&MODULE_PSI5, (IfxPsi5_ChannelId)0, {&MODULE_P00, 2}, IfxPort_OutputIdx_alt4};

IfxPsi5_Tx_Out IfxPsi5_TX0_P02_2_OUT = {&MODULE_PSI5, (IfxPsi5_ChannelId)0, {&MODULE_P02, 2}, IfxPort_OutputIdx_alt4};

IfxPsi5_Tx_Out IfxPsi5_TX0_P33_2_OUT = {&MODULE_PSI5, (IfxPsi5_ChannelId)0, {&MODULE_P33, 2}, IfxPort_OutputIdx_alt4};

IfxPsi5_Tx_Out IfxPsi5_TX1_P00_4_OUT = {&MODULE_PSI5, (IfxPsi5_ChannelId)1, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt4};

IfxPsi5_Tx_Out IfxPsi5_TX1_P02_6_OUT = {&MODULE_PSI5, (IfxPsi5_ChannelId)1, {&MODULE_P02, 6}, IfxPort_OutputIdx_alt4};

IfxPsi5_Tx_Out IfxPsi5_TX1_P33_4_OUT = {&MODULE_PSI5, (IfxPsi5_ChannelId)1, {&MODULE_P33, 4}, IfxPort_OutputIdx_alt4};

/** \addtogroup IfxLld_Psi5__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxPsi5_Rx_In  *IfxPsi5_Rx_In_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_RX_IN_NUM_ITEMS] = {
    {
        {
            &IfxPsi5_RX0A_P00_1_IN,
            &IfxPsi5_RX0B_P02_3_IN,
            &IfxPsi5_RX0C_P33_1_IN,
        },
        {
            &IfxPsi5_RX1A_P00_3_IN,
            &IfxPsi5_RX1B_P02_5_IN,
            &IfxPsi5_RX1C_P33_3_IN,
        },
    },
};

IFX_CONST IfxPsi5_Tx_Out *IfxPsi5_Tx_Out_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_TX_OUT_NUM_ITEMS] = {
    {
        {
            &IfxPsi5_TX0_P00_2_OUT,
            &IfxPsi5_TX0_P02_2_OUT,
            &IfxPsi5_TX0_P33_2_OUT,
        },
        {
            &IfxPsi5_TX1_P00_4_OUT,
            &IfxPsi5_TX1_P02_6_OUT,
            &IfxPsi5_TX1_P33_4_OUT,
        },
    },
};

/** \} */

#endif
