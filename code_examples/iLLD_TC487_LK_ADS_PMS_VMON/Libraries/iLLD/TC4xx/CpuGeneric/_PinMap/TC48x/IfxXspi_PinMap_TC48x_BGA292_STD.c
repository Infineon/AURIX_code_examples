/**
 * \file IfxXspi_PinMap_TC48x_BGA292_STD.c
 * \brief XSPI  details
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
#if defined(DEVICE_TC48X) && defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "IfxXspi_PinMap_TC48x_BGA292_STD.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxXspi_Clk_Out    IfxXspi0_CLK_P11_4_OUT = {&MODULE_XSPI0, {&MODULE_P11, 4}, IfxPort_OutputIdx_alt15};

IfxXspi_Clk_Out    IfxXspi0_CLK_P20_13_OUT = {&MODULE_XSPI0, {&MODULE_P20, 13}, IfxPort_OutputIdx_alt15};

IfxXspi_Cs_Out     IfxXspi0_CS_P11_11_OUT = {&MODULE_XSPI0, {&MODULE_P11, 11}, IfxPort_OutputIdx_alt15};

IfxXspi_Cs_Out     IfxXspi0_CS_P11_8_OUT = {&MODULE_XSPI0, {&MODULE_P11, 8}, IfxPort_OutputIdx_alt15};

IfxXspi_Cs_Out     IfxXspi0_CS_P20_0_OUT = {&MODULE_XSPI0, {&MODULE_P20, 0}, IfxPort_OutputIdx_alt15};

IfxXspi_Cs_Out     IfxXspi0_CS_P20_14_OUT = {&MODULE_XSPI0, {&MODULE_P20, 14}, IfxPort_OutputIdx_alt15};

IfxXspi_Txd0_InOut IfxXspi0_TXD0_P11_7_INOUT = {&MODULE_XSPI0, {&MODULE_P11, 7}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd0_InOut IfxXspi0_TXD0_P20_3_INOUT = {&MODULE_XSPI0, {&MODULE_P20, 3}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd1_InOut IfxXspi0_TXD1_P11_5_INOUT = {&MODULE_XSPI0, {&MODULE_P11, 5}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd1_InOut IfxXspi0_TXD1_P20_6_INOUT = {&MODULE_XSPI0, {&MODULE_P20, 6}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd2_InOut IfxXspi0_TXD2_P11_1_INOUT = {&MODULE_XSPI0, {&MODULE_P11, 1}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd2_InOut IfxXspi0_TXD2_P20_9_INOUT = {&MODULE_XSPI0, {&MODULE_P20, 9}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd3_InOut IfxXspi0_TXD3_P11_0_INOUT = {&MODULE_XSPI0, {&MODULE_P11, 0}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxXspi_Txd3_InOut IfxXspi0_TXD3_P15_2_INOUT = {&MODULE_XSPI0, {&MODULE_P15, 2}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

/** \addtogroup IfxLld_Xspi__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxXspi_Clk_Out    *IfxXspi_Clk_Out_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_CLK_OUT_NUM_ITEMS] = {
    {
        &IfxXspi0_CLK_P11_4_OUT,
        &IfxXspi0_CLK_P20_13_OUT,
        NULL_PTR,
    },
};

IFX_CONST IfxXspi_Cs_Out     *IfxXspi_Cs_Out_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_CS_OUT_NUM_ITEMS] = {
    {
        &IfxXspi0_CS_P11_8_OUT,
        &IfxXspi0_CS_P11_11_OUT,
        &IfxXspi0_CS_P20_0_OUT,
        &IfxXspi0_CS_P20_14_OUT,
    },
};

IFX_CONST IfxXspi_Txd0_InOut *IfxXspi_Txd0_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD0_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD0_P11_7_INOUT,
        &IfxXspi0_TXD0_P20_3_INOUT,
    },
};

IFX_CONST IfxXspi_Txd1_InOut *IfxXspi_Txd1_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD1_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD1_P11_5_INOUT,
        &IfxXspi0_TXD1_P20_6_INOUT,
    },
};

IFX_CONST IfxXspi_Txd2_InOut *IfxXspi_Txd2_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD2_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD2_P11_1_INOUT,
        &IfxXspi0_TXD2_P20_9_INOUT,
    },
};

IFX_CONST IfxXspi_Txd3_InOut *IfxXspi_Txd3_InOut_pinTable[IFXXSPI_PINMAP_NUM_MODULES][IFXXSPI_PINMAP_TXD3_INOUT_NUM_ITEMS] = {
    {
        &IfxXspi0_TXD3_P11_0_INOUT,
        &IfxXspi0_TXD3_P15_2_INOUT,
    },
};

/** \} */

#endif
