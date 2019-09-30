/**
 * \file IfxEray_PinMap.c
 * \brief ERAY I/O map
 * \ingroup IfxLld_Eray
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

#include "IfxEray_PinMap.h"

IfxEray_Rxd_In IfxEray0_RXDA0_P14_8_IN = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14, 8}, Ifx_RxSel_a};
IfxEray_Rxd_In IfxEray0_RXDA1_P11_9_IN = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P11, 9}, Ifx_RxSel_b};
IfxEray_Rxd_In IfxEray0_RXDA2_P02_1_IN = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P02, 1}, Ifx_RxSel_c};
IfxEray_Rxd_In IfxEray0_RXDA3_P14_1_IN = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14, 1}, Ifx_RxSel_d};
IfxEray_Rxd_In IfxEray0_RXDB0_P14_7_IN = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 7}, Ifx_RxSel_a};
IfxEray_Rxd_In IfxEray0_RXDB1_P11_10_IN = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P11,10}, Ifx_RxSel_b};
IfxEray_Rxd_In IfxEray0_RXDB2_P02_3_IN = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P02, 3}, Ifx_RxSel_c};
IfxEray_Rxd_In IfxEray0_RXDB3_P14_1_IN = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 1}, Ifx_RxSel_d};
IfxEray_Rxd_In IfxEray1_RXDA0_P14_8_IN = {&MODULE_ERAY1, IfxEray_NodeId_a, {&MODULE_P14, 8}, Ifx_RxSel_a};
IfxEray_Rxd_In IfxEray1_RXDA1_P01_1_IN = {&MODULE_ERAY1, IfxEray_NodeId_a, {&MODULE_P01, 1}, Ifx_RxSel_b};
IfxEray_Rxd_In IfxEray1_RXDB0_P14_7_IN = {&MODULE_ERAY1, IfxEray_NodeId_b, {&MODULE_P14, 7}, Ifx_RxSel_a};
IfxEray_Rxd_In IfxEray1_RXDB1_P01_8_IN = {&MODULE_ERAY1, IfxEray_NodeId_b, {&MODULE_P01, 8}, Ifx_RxSel_b};
IfxEray_Txd_Out IfxEray0_TXDA_P02_0_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P02, 0}, IfxPort_OutputIdx_alt6};
IfxEray_Txd_Out IfxEray0_TXDA_P11_3_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P11, 3}, IfxPort_OutputIdx_alt4};
IfxEray_Txd_Out IfxEray0_TXDA_P14_0_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14, 0}, IfxPort_OutputIdx_alt3};
IfxEray_Txd_Out IfxEray0_TXDA_P14_10_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14,10}, IfxPort_OutputIdx_alt6};
IfxEray_Txd_Out IfxEray0_TXDB_P02_2_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P02, 2}, IfxPort_OutputIdx_alt6};
IfxEray_Txd_Out IfxEray0_TXDB_P11_12_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P11,12}, IfxPort_OutputIdx_alt4};
IfxEray_Txd_Out IfxEray0_TXDB_P14_0_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 0}, IfxPort_OutputIdx_alt4};
IfxEray_Txd_Out IfxEray0_TXDB_P14_5_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 5}, IfxPort_OutputIdx_alt6};
IfxEray_Txd_Out IfxEray1_TXDA_P01_12_OUT = {&MODULE_ERAY1, IfxEray_NodeId_a, {&MODULE_P01,12}, IfxPort_OutputIdx_alt6};
IfxEray_Txd_Out IfxEray1_TXDA_P14_10_OUT = {&MODULE_ERAY1, IfxEray_NodeId_a, {&MODULE_P14,10}, IfxPort_OutputIdx_alt7};
IfxEray_Txd_Out IfxEray1_TXDB_P01_13_OUT = {&MODULE_ERAY1, IfxEray_NodeId_b, {&MODULE_P01,13}, IfxPort_OutputIdx_alt6};
IfxEray_Txd_Out IfxEray1_TXDB_P14_5_OUT = {&MODULE_ERAY1, IfxEray_NodeId_b, {&MODULE_P14, 5}, IfxPort_OutputIdx_alt7};
IfxEray_Txen_Out IfxEray0_TXENA_P02_4_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P02, 4}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENA_P11_6_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P11, 6}, IfxPort_OutputIdx_alt4};
IfxEray_Txen_Out IfxEray0_TXENA_P14_9_OUT = {&MODULE_ERAY0, IfxEray_NodeId_a, {&MODULE_P14, 9}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENB_P02_5_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P02, 5}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENB_P11_11_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P11,11}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENB_P11_6_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P11, 6}, IfxPort_OutputIdx_alt2};
IfxEray_Txen_Out IfxEray0_TXENB_P14_6_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 6}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray0_TXENB_P14_9_OUT = {&MODULE_ERAY0, IfxEray_NodeId_b, {&MODULE_P14, 9}, IfxPort_OutputIdx_alt5};
IfxEray_Txen_Out IfxEray1_TXENA_P01_14_OUT = {&MODULE_ERAY1, IfxEray_NodeId_a, {&MODULE_P01,14}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray1_TXENA_P14_9_OUT = {&MODULE_ERAY1, IfxEray_NodeId_a, {&MODULE_P14, 9}, IfxPort_OutputIdx_alt7};
IfxEray_Txen_Out IfxEray1_TXENB_P02_15_OUT = {&MODULE_ERAY1, IfxEray_NodeId_b, {&MODULE_P02,15}, IfxPort_OutputIdx_alt6};
IfxEray_Txen_Out IfxEray1_TXENB_P14_6_OUT = {&MODULE_ERAY1, IfxEray_NodeId_b, {&MODULE_P14, 6}, IfxPort_OutputIdx_alt7};


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
    },
    {
        {
            &IfxEray1_RXDA0_P14_8_IN,
            &IfxEray1_RXDA1_P01_1_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEray1_RXDB0_P14_7_IN,
            &IfxEray1_RXDB1_P01_8_IN,
            NULL_PTR,
            NULL_PTR
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
    },
    {
        {
            &IfxEray1_TXDA_P01_12_OUT,
            &IfxEray1_TXDA_P14_10_OUT,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEray1_TXDB_P01_13_OUT,
            &IfxEray1_TXDB_P14_5_OUT,
            NULL_PTR,
            NULL_PTR
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
    },
    {
        {
            &IfxEray1_TXENA_P01_14_OUT,
            &IfxEray1_TXENA_P14_9_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxEray1_TXENB_P02_15_OUT,
            &IfxEray1_TXENB_P14_6_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        }
    }
};
