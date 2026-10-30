/**
 * \file IfxScu_PinMap_TC37x_LFBGA292.c
 * \brief SCU I/O map
 * \ingroup IfxLld_Scu
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

#if defined DEVICE_TC37X && defined IFX_PIN_PACKAGE_LFBGA292
#include "IfxScu_PinMap_TC37x_LFBGA292.h"

IfxScu_Emgstop_In IfxScu_EMGSTOPA_P33_8_IN = {&MODULE_SCU, {&MODULE_P33, 8}, Ifx_RxSel_a};
IfxScu_Emgstop_In IfxScu_EMGSTOPB_P21_2_IN = {&MODULE_SCU, {&MODULE_P21, 2}, Ifx_RxSel_b};
IfxScu_Extclk_Out IfxScu_EXTCLK0_P23_1_OUT = {&MODULE_SCU, {&MODULE_P23, 1}, IfxPort_OutputIdx_alt6};
IfxScu_Extclk_Out IfxScu_EXTCLK1_P11_12_OUT = {&MODULE_SCU, {&MODULE_P11,12}, IfxPort_OutputIdx_alt6};
IfxScu_Extclk_Out IfxScu_EXTCLK1_P32_4_OUT = {&MODULE_SCU, {&MODULE_P32, 4}, IfxPort_OutputIdx_alt6};
IfxScu_Req_In IfxScu_REQ0A_P15_4_IN = {&MODULE_SCU, 0, {&MODULE_P15, 4}, Ifx_RxSel_a};
IfxScu_Req_In IfxScu_REQ0C_P10_7_IN = {&MODULE_SCU, 0, {&MODULE_P10, 7}, Ifx_RxSel_c};
IfxScu_Req_In IfxScu_REQ1A_P14_3_IN = {&MODULE_SCU, 1, {&MODULE_P14, 3}, Ifx_RxSel_a};
IfxScu_Req_In IfxScu_REQ1C_P10_8_IN = {&MODULE_SCU, 1, {&MODULE_P10, 8}, Ifx_RxSel_c};
IfxScu_Req_In IfxScu_REQ2A_P10_2_IN = {&MODULE_SCU, 2, {&MODULE_P10, 2}, Ifx_RxSel_a};
IfxScu_Req_In IfxScu_REQ2B_P02_1_IN = {&MODULE_SCU, 2, {&MODULE_P02, 1}, Ifx_RxSel_b};
IfxScu_Req_In IfxScu_REQ2C_P00_4_IN = {&MODULE_SCU, 2, {&MODULE_P00, 4}, Ifx_RxSel_c};
IfxScu_Req_In IfxScu_REQ3A_P10_3_IN = {&MODULE_SCU, 3, {&MODULE_P10, 3}, Ifx_RxSel_a};
IfxScu_Req_In IfxScu_REQ3B_P14_1_IN = {&MODULE_SCU, 3, {&MODULE_P14, 1}, Ifx_RxSel_b};
IfxScu_Req_In IfxScu_REQ3C_P02_0_IN = {&MODULE_SCU, 3, {&MODULE_P02, 0}, Ifx_RxSel_c};
IfxScu_Req_In IfxScu_REQ4A_P33_7_IN = {&MODULE_SCU, 4, {&MODULE_P33, 7}, Ifx_RxSel_a};
IfxScu_Req_In IfxScu_REQ4D_P15_5_IN = {&MODULE_SCU, 4, {&MODULE_P15, 5}, Ifx_RxSel_d};
IfxScu_Req_In IfxScu_REQ5A_P15_8_IN = {&MODULE_SCU, 5, {&MODULE_P15, 8}, Ifx_RxSel_a};
IfxScu_Req_In IfxScu_REQ6A_P20_0_IN = {&MODULE_SCU, 6, {&MODULE_P20, 0}, Ifx_RxSel_a};
IfxScu_Req_In IfxScu_REQ6D_P11_10_IN = {&MODULE_SCU, 6, {&MODULE_P11,10}, Ifx_RxSel_d};
IfxScu_Req_In IfxScu_REQ7A_P20_9_IN = {&MODULE_SCU, 7, {&MODULE_P20, 9}, Ifx_RxSel_a};
IfxScu_Req_In IfxScu_REQ7C_P15_1_IN = {&MODULE_SCU, 7, {&MODULE_P15, 1}, Ifx_RxSel_c};


const IfxScu_Emgstop_In *IfxScu_Emgstop_In_pinTable[IFXSCU_PINMAP_NUM_MODULES][IFXSCU_PINMAP_EMGSTOP_IN_NUM_ITEMS] = {
    {
        &IfxScu_EMGSTOPA_P33_8_IN,
        &IfxScu_EMGSTOPB_P21_2_IN
    }
};

const IfxScu_Extclk_Out *IfxScu_Extclk_Out_pinTable[IFXSCU_PINMAP_NUM_MODULES][IFXSCU_PINMAP_EXTCLK_OUT_NUM_ITEMS] = {
    {
        &IfxScu_EXTCLK1_P11_12_OUT,
        &IfxScu_EXTCLK0_P23_1_OUT,
        &IfxScu_EXTCLK1_P32_4_OUT
    }
};

const IfxScu_Req_In *IfxScu_Req_In_pinTable[IFXSCU_PINMAP_NUM_MODULES][IFXSCU_PINMAP_NUM_REQUESTS][IFXSCU_PINMAP_REQ_IN_NUM_ITEMS] = {
    {
        {
            &IfxScu_REQ0A_P15_4_IN,
            NULL_PTR,
            &IfxScu_REQ0C_P10_7_IN,
            NULL_PTR
        },
        {
            &IfxScu_REQ1A_P14_3_IN,
            NULL_PTR,
            &IfxScu_REQ1C_P10_8_IN,
            NULL_PTR
        },
        {
            &IfxScu_REQ2A_P10_2_IN,
            &IfxScu_REQ2B_P02_1_IN,
            &IfxScu_REQ2C_P00_4_IN,
            NULL_PTR
        },
        {
            &IfxScu_REQ3A_P10_3_IN,
            &IfxScu_REQ3B_P14_1_IN,
            &IfxScu_REQ3C_P02_0_IN,
            NULL_PTR
        },
        {
            &IfxScu_REQ4A_P33_7_IN,
            NULL_PTR,
            NULL_PTR,
            &IfxScu_REQ4D_P15_5_IN
        },
        {
            &IfxScu_REQ5A_P15_8_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxScu_REQ6A_P20_0_IN,
            NULL_PTR,
            NULL_PTR,
            &IfxScu_REQ6D_P11_10_IN
        },
        {
            &IfxScu_REQ7A_P20_9_IN,
            NULL_PTR,
            &IfxScu_REQ7C_P15_1_IN,
            NULL_PTR
        }
    }
};
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
