/**
 * \file IfxCanxl_PinMap_TC4Dx_BGA436_COM.c
 * \brief CANXL  details
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
#include "IfxCanxl_PinMap_TC4Dx_BGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxCanxl_Rxd_In  IfxCanxl_RXD00A_P14_8_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P14, 8}, Ifx_RxSel_a};

IfxCanxl_Rxd_In  IfxCanxl_RXD00B_P14_1_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P14, 1}, Ifx_RxSel_b};

IfxCanxl_Rxd_In  IfxCanxl_RXD00C_P02_1_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P02, 1}, Ifx_RxSel_c};

IfxCanxl_Rxd_In  IfxCanxl_RXD00E_P10_7_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P10, 7}, Ifx_RxSel_e};

IfxCanxl_Rxd_In  IfxCanxl_RXD00F_P15_12_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P15, 12}, Ifx_RxSel_f};

IfxCanxl_Rxd_In  IfxCanxl_RXD00G_P01_5_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P01, 5}, Ifx_RxSel_g};

IfxCanxl_Rxd_In  IfxCanxl_RXD00H_P14_12_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P14, 12}, Ifx_RxSel_h};

IfxCanxl_Rxd_In  IfxCanxl_RXD01A_P14_4_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)1, {&MODULE_P14, 4}, Ifx_RxSel_a};

IfxCanxl_Rxd_In  IfxCanxl_RXD01C_P02_3_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)1, {&MODULE_P02, 3}, Ifx_RxSel_c};

IfxCanxl_Rxd_In  IfxCanxl_RXD01D_P14_2_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)1, {&MODULE_P14, 2}, Ifx_RxSel_d};

IfxCanxl_Rxd_In  IfxCanxl_RXD02A_P01_1_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)2, {&MODULE_P01, 1}, Ifx_RxSel_a};

IfxCanxl_Rxd_In  IfxCanxl_RXD02B_P10_11_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)2, {&MODULE_P10, 11}, Ifx_RxSel_b};

IfxCanxl_Rxd_In  IfxCanxl_RXD02C_P14_7_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)2, {&MODULE_P14, 7}, Ifx_RxSel_c};

IfxCanxl_Rxd_In  IfxCanxl_RXD02D_P04_4_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)2, {&MODULE_P04, 4}, Ifx_RxSel_d};

IfxCanxl_Rxd_In  IfxCanxl_RXD03A_P01_8_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P01, 8}, Ifx_RxSel_a};

IfxCanxl_Rxd_In  IfxCanxl_RXD03B_P15_1_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P15, 1}, Ifx_RxSel_b};

IfxCanxl_Rxd_In  IfxCanxl_RXD03C_P00_6_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P00, 6}, Ifx_RxSel_c};

IfxCanxl_Rxd_In  IfxCanxl_RXD03E_P00_12_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P00, 12}, Ifx_RxSel_e};

IfxCanxl_Rxd_In  IfxCanxl_RXD03H_P04_6_IN = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P04, 6}, Ifx_RxSel_h};

IfxCanxl_Txd_Out IfxCanxl_TXD00_P01_4_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P01, 4}, IfxPort_OutputIdx_alt8};

IfxCanxl_Txd_Out IfxCanxl_TXD00_P02_0_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P02, 0}, IfxPort_OutputIdx_alt8};

IfxCanxl_Txd_Out IfxCanxl_TXD00_P10_0_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P10, 0}, IfxPort_OutputIdx_alt7};

IfxCanxl_Txd_Out IfxCanxl_TXD00_P14_0_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P14, 0}, IfxPort_OutputIdx_alt13};

IfxCanxl_Txd_Out IfxCanxl_TXD00_P14_10_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P14, 10}, IfxPort_OutputIdx_alt13};

IfxCanxl_Txd_Out IfxCanxl_TXD00_P15_0_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P15, 0}, IfxPort_OutputIdx_alt11};

IfxCanxl_Txd_Out IfxCanxl_TXD00_P15_13_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)0, {&MODULE_P15, 13}, IfxPort_OutputIdx_alt13};

IfxCanxl_Txd_Out IfxCanxl_TXD01_P02_2_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)1, {&MODULE_P02, 2}, IfxPort_OutputIdx_alt8};

IfxCanxl_Txd_Out IfxCanxl_TXD01_P14_0_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)1, {&MODULE_P14, 0}, IfxPort_OutputIdx_alt15};

IfxCanxl_Txd_Out IfxCanxl_TXD01_P14_3_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)1, {&MODULE_P14, 3}, IfxPort_OutputIdx_alt13};

IfxCanxl_Txd_Out IfxCanxl_TXD01_P14_5_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)1, {&MODULE_P14, 5}, IfxPort_OutputIdx_alt13};

IfxCanxl_Txd_Out IfxCanxl_TXD02_P01_0_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)2, {&MODULE_P01, 0}, IfxPort_OutputIdx_alt8};

IfxCanxl_Txd_Out IfxCanxl_TXD02_P01_12_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)2, {&MODULE_P01, 12}, IfxPort_OutputIdx_alt8};

IfxCanxl_Txd_Out IfxCanxl_TXD02_P04_3_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)2, {&MODULE_P04, 3}, IfxPort_OutputIdx_alt13};

IfxCanxl_Txd_Out IfxCanxl_TXD02_P10_10_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)2, {&MODULE_P10, 10}, IfxPort_OutputIdx_alt12};

IfxCanxl_Txd_Out IfxCanxl_TXD02_P14_10_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)2, {&MODULE_P14, 10}, IfxPort_OutputIdx_alt15};

IfxCanxl_Txd_Out IfxCanxl_TXD03_P00_5_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P00, 5}, IfxPort_OutputIdx_alt8};

IfxCanxl_Txd_Out IfxCanxl_TXD03_P01_13_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P01, 13}, IfxPort_OutputIdx_alt8};

IfxCanxl_Txd_Out IfxCanxl_TXD03_P14_3_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P14, 3}, IfxPort_OutputIdx_alt15};

IfxCanxl_Txd_Out IfxCanxl_TXD03_P14_5_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P14, 5}, IfxPort_OutputIdx_alt15};

IfxCanxl_Txd_Out IfxCanxl_TXD03_P15_0_OUT = {&MODULE_CANXL0, (IfxCanxl_NodeId)3, {&MODULE_P15, 0}, IfxPort_OutputIdx_alt14};

/** \addtogroup IfxLld_Canxl__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxCanxl_Rxd_In  *IfxCanxl_Rxd_In_pinTable[IFXCANXL_PINMAP_NUM_MODULES][IFXCANXL_PINMAP_NUM_NODES][IFXCANXL_PINMAP_RXD_IN_NUM_ITEMS] = {
    {
        {
            &IfxCanxl_RXD00A_P14_8_IN,
            &IfxCanxl_RXD00B_P14_1_IN,
            &IfxCanxl_RXD00C_P02_1_IN,
            NULL_PTR,
            &IfxCanxl_RXD00E_P10_7_IN,
            &IfxCanxl_RXD00F_P15_12_IN,
            &IfxCanxl_RXD00G_P01_5_IN,
            &IfxCanxl_RXD00H_P14_12_IN,
        },
        {
            &IfxCanxl_RXD01A_P14_4_IN,
            NULL_PTR,
            &IfxCanxl_RXD01C_P02_3_IN,
            &IfxCanxl_RXD01D_P14_2_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxCanxl_RXD02A_P01_1_IN,
            &IfxCanxl_RXD02B_P10_11_IN,
            &IfxCanxl_RXD02C_P14_7_IN,
            &IfxCanxl_RXD02D_P04_4_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxCanxl_RXD03A_P01_8_IN,
            &IfxCanxl_RXD03B_P15_1_IN,
            &IfxCanxl_RXD03C_P00_6_IN,
            NULL_PTR,
            &IfxCanxl_RXD03E_P00_12_IN,
            NULL_PTR,
            NULL_PTR,
            &IfxCanxl_RXD03H_P04_6_IN,
        },
    },
};

IFX_CONST IfxCanxl_Txd_Out *IfxCanxl_Txd_Out_pinTable[IFXCANXL_PINMAP_NUM_MODULES][IFXCANXL_PINMAP_NUM_NODES][IFXCANXL_PINMAP_TXD_OUT_NUM_ITEMS] = {
    {
        {
            &IfxCanxl_TXD00_P01_4_OUT,
            &IfxCanxl_TXD00_P02_0_OUT,
            &IfxCanxl_TXD00_P10_0_OUT,
            &IfxCanxl_TXD00_P14_0_OUT,
            &IfxCanxl_TXD00_P14_10_OUT,
            &IfxCanxl_TXD00_P15_0_OUT,
            &IfxCanxl_TXD00_P15_13_OUT,
        },
        {
            &IfxCanxl_TXD01_P02_2_OUT,
            &IfxCanxl_TXD01_P14_0_OUT,
            &IfxCanxl_TXD01_P14_3_OUT,
            &IfxCanxl_TXD01_P14_5_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxCanxl_TXD02_P01_0_OUT,
            &IfxCanxl_TXD02_P01_12_OUT,
            &IfxCanxl_TXD02_P04_3_OUT,
            &IfxCanxl_TXD02_P10_10_OUT,
            &IfxCanxl_TXD02_P14_10_OUT,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxCanxl_TXD03_P00_5_OUT,
            &IfxCanxl_TXD03_P01_13_OUT,
            &IfxCanxl_TXD03_P14_3_OUT,
            &IfxCanxl_TXD03_P14_5_OUT,
            &IfxCanxl_TXD03_P15_0_OUT,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

/** \} */

#endif
