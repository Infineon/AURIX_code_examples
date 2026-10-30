/**
 * \file IfxEray_PinMap_TC37x_516.c
 * \brief ERAY I/O map
 * \ingroup IfxLld_Eray
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
#include "IfxEray_PinMap_TC37x_516.h"

IfxEray_Rxd_In IfxEray0_RXDA0_P14_8_IN = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14, 8}, Ifx_RxSel_a};
IfxEray_Rxd_In IfxEray0_RXDA1_P11_9_IN = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P11, 9}, Ifx_RxSel_b};
IfxEray_Rxd_In IfxEray0_RXDA2_P02_1_IN = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P02, 1}, Ifx_RxSel_c};
IfxEray_Rxd_In IfxEray0_RXDA3_P14_1_IN = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14, 1}, Ifx_RxSel_d};
IfxEray_Rxd_In IfxEray0_RXDB0_P14_7_IN = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 7}, Ifx_RxSel_a};
IfxEray_Rxd_In IfxEray0_RXDB1_P11_10_IN = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P11,10}, Ifx_RxSel_b};
IfxEray_Rxd_In IfxEray0_RXDB2_P02_3_IN = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P02, 3}, Ifx_RxSel_c};
IfxEray_Rxd_In IfxEray0_RXDB3_P14_1_IN = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 1}, Ifx_RxSel_d};
IfxEray_Txd_Out IfxEray0_TXDA_P02_0_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P02, 0}, IfxPort_OutputIdx_alt6};
IfxEray_Txd_Out IfxEray0_TXDA_P11_3_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P11, 3}, IfxPort_OutputIdx_alt4};
IfxEray_Txd_Out IfxEray0_TXDA_P14_0_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14, 0}, IfxPort_OutputIdx_alt3};
IfxEray_Txd_Out IfxEray0_TXDA_P14_10_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14,10}, IfxPort_OutputIdx_alt6};
IfxEray_Txd_Out IfxEray0_TXDB_P02_2_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P02, 2}, IfxPort_OutputIdx_alt6};
IfxEray_Txd_Out IfxEray0_TXDB_P11_12_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P11,12}, IfxPort_OutputIdx_alt4};
IfxEray_Txd_Out IfxEray0_TXDB_P14_0_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 0}, IfxPort_OutputIdx_alt4};
IfxEray_Txd_Out IfxEray0_TXDB_P14_5_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 5}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENA_P02_4_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P02, 4}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENA_P11_6_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P11, 6}, IfxPort_OutputIdx_alt4};
IfxEray_Txen_Out IfxEray0_TXENA_P14_9_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14, 9}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENB_P02_5_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P02, 5}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENB_P11_11_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P11,11}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENB_P11_6_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P11, 6}, IfxPort_OutputIdx_alt2};
IfxEray_Txen_Out IfxEray0_TXENB_P14_6_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 6}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENB_P14_9_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 9}, IfxPort_OutputIdx_alt5};


const IfxEray_Rxd_In *IfxEray_Rxd_In_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_RXD_IN_NUM_ITEMS] = {
    {
        {
            &IfxEray0_RXDA0_P14_8_IN,
            &IfxEray0_RXDA1_P11_9_IN,
            &IfxEray0_RXDA2_P02_1_IN,
            &IfxEray0_RXDA3_P14_1_IN
        },
        {
            &IfxEray0_RXDB0_P14_7_IN,
            &IfxEray0_RXDB1_P11_10_IN,
            &IfxEray0_RXDB2_P02_3_IN,
            &IfxEray0_RXDB3_P14_1_IN
        }
    }
};

const IfxEray_Txd_Out *IfxEray_Txd_Out_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_TXD_OUT_NUM_ITEMS] = {
    {
        {
            &IfxEray0_TXDA_P02_0_OUT,
            &IfxEray0_TXDA_P11_3_OUT,
            &IfxEray0_TXDA_P14_0_OUT,
            &IfxEray0_TXDA_P14_10_OUT
        },
        {
            &IfxEray0_TXDB_P02_2_OUT,
            &IfxEray0_TXDB_P11_12_OUT,
            &IfxEray0_TXDB_P14_0_OUT,
            &IfxEray0_TXDB_P14_5_OUT
        }
    }
};

const IfxEray_Txen_Out *IfxEray_Txen_Out_pinTable[IFXERAY_PINMAP_NUM_MODULES][IFXERAY_PINMAP_NUM_NODES][IFXERAY_PINMAP_TXEN_OUT_NUM_ITEMS] = {
    {
        {
            &IfxEray0_TXENA_P02_4_OUT,
            &IfxEray0_TXENA_P11_6_OUT,
            &IfxEray0_TXENA_P14_9_OUT,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEray0_TXENB_P02_5_OUT,
            &IfxEray0_TXENB_P11_6_OUT,
            &IfxEray0_TXENB_P11_11_OUT,
            &IfxEray0_TXENB_P14_6_OUT,
            &IfxEray0_TXENB_P14_9_OUT
        }
    }
};
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
