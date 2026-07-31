/**
 * \file IfxHsct_PinMap_TC4Dx_BGA292_COM.c
 * \brief HSCT  details
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
#include "IfxHsct_PinMap_TC4Dx_BGA292_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxHsct_Rxdn_In    IfxHsct_RXDN_P21_0_IN = {&MODULE_HSCT1, {&MODULE_P21, 0}, Ifx_RxSel_a};

IfxHsct_Rxdn_In    IfxHsct_RXDN_P21_2_IN = {&MODULE_HSCT0, {&MODULE_P21, 2}, Ifx_RxSel_a};

IfxHsct_Rxdp_In    IfxHsct_RXDP_P21_1_IN = {&MODULE_HSCT1, {&MODULE_P21, 1}, Ifx_RxSel_a};

IfxHsct_Rxdp_In    IfxHsct_RXDP_P21_3_IN = {&MODULE_HSCT0, {&MODULE_P21, 3}, Ifx_RxSel_a};

IfxHsct_Sysclk_Out IfxHsct_SYSCLK_OUT_P20_0_OUT = {&MODULE_HSCT0, {&MODULE_P20, 0}, IfxPort_OutputIdx_general};

IfxHsct_Txdn_Out   IfxHsct_TXDN_P21_4_OUT = {&MODULE_HSCT0, {&MODULE_P21, 4}, IfxPort_OutputIdx_general};

IfxHsct_Txdn_Out   IfxHsct_TXDN_P22_2_OUT = {&MODULE_HSCT1, {&MODULE_P22, 2}, IfxPort_OutputIdx_general};

IfxHsct_Txdp_Out   IfxHsct_TXDP_P21_5_OUT = {&MODULE_HSCT0, {&MODULE_P21, 5}, IfxPort_OutputIdx_general};

IfxHsct_Txdp_Out   IfxHsct_TXDP_P22_3_OUT = {&MODULE_HSCT1, {&MODULE_P22, 3}, IfxPort_OutputIdx_general};

/** \addtogroup IfxLld_Hsct__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxHsct_Rxdn_In    *IfxHsct_Rxdn_In_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_RXDN_IN_NUM_ITEMS] = {
    {
        &IfxHsct_RXDN_P21_2_IN,
    },
    {
        &IfxHsct_RXDN_P21_0_IN,
    },
};

IFX_CONST IfxHsct_Rxdp_In    *IfxHsct_Rxdp_In_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_RXDP_IN_NUM_ITEMS] = {
    {
        &IfxHsct_RXDP_P21_3_IN,
    },
    {
        &IfxHsct_RXDP_P21_1_IN,
    },
};

IFX_CONST IfxHsct_Sysclk_Out *IfxHsct_Sysclk_Out_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_SYSCLK_OUT_NUM_ITEMS] = {
    {
        &IfxHsct_SYSCLK_OUT_P20_0_OUT,
    },
    {
        NULL_PTR,
    },
};

IFX_CONST IfxHsct_Txdn_Out   *IfxHsct_Txdn_Out_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_TXDN_OUT_NUM_ITEMS] = {
    {
        &IfxHsct_TXDN_P21_4_OUT,
    },
    {
        &IfxHsct_TXDN_P22_2_OUT,
    },
};

IFX_CONST IfxHsct_Txdp_Out   *IfxHsct_Txdp_Out_pinTable[IFXHSCT_PINMAP_NUM_MODULES][IFXHSCT_PINMAP_TXDP_OUT_NUM_ITEMS] = {
    {
        &IfxHsct_TXDP_P21_5_OUT,
    },
    {
        &IfxHsct_TXDP_P22_3_OUT,
    },
};

/** \} */

#endif
