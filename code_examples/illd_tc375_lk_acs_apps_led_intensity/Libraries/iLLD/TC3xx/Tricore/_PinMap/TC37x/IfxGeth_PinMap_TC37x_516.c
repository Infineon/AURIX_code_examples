/**
 * \file IfxGeth_PinMap_TC37x_516.c
 * \brief GETH I/O map
 * \ingroup IfxLld_Geth
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
#include "IfxGeth_PinMap_TC37x_516.h"

IfxGeth_Col_In IfxGeth_COL_P11_15_IN = {&MODULE_GETH, {&MODULE_P11,15}, Ifx_RxSel_a};
IfxGeth_Crs_In IfxGeth_CRSA_P11_14_IN = {&MODULE_GETH, {&MODULE_P11,14}, Ifx_RxSel_a};
IfxGeth_Crs_In IfxGeth_CRSB_P11_11_IN = {&MODULE_GETH, {&MODULE_P11,11}, Ifx_RxSel_b};
IfxGeth_Crsdv_In IfxGeth_CRSDVA_P11_11_IN = {&MODULE_GETH, {&MODULE_P11,11}, Ifx_RxSel_a};
IfxGeth_Crsdv_In IfxGeth_CRSDVB_P11_14_IN = {&MODULE_GETH, {&MODULE_P11,14}, Ifx_RxSel_b};
IfxGeth_Grefclk_In IfxGeth_GREFCLK_P11_5_IN = {&MODULE_GETH, {&MODULE_P11, 5}, Ifx_RxSel_a};
IfxGeth_Mdc_Out IfxGeth_MDC_P02_8_OUT = {&MODULE_GETH, {&MODULE_P02, 8}, IfxPort_OutputIdx_alt6};
IfxGeth_Mdc_Out IfxGeth_MDC_P12_0_OUT = {&MODULE_GETH, {&MODULE_P12, 0}, IfxPort_OutputIdx_alt6};
IfxGeth_Mdc_Out IfxGeth_MDC_P21_2_OUT = {&MODULE_GETH, {&MODULE_P21, 2}, IfxPort_OutputIdx_alt5};
IfxGeth_Mdio_InOut IfxGeth_MDIO_P00_0_INOUT = {&MODULE_GETH, {&MODULE_P00, 0}, Ifx_RxSel_a, IfxPort_OutputIdx_general};
IfxGeth_Mdio_InOut IfxGeth_MDIO_P12_1_INOUT = {&MODULE_GETH, {&MODULE_P12, 1}, Ifx_RxSel_c, IfxPort_OutputIdx_general};
IfxGeth_Mdio_InOut IfxGeth_MDIO_P21_3_INOUT = {&MODULE_GETH, {&MODULE_P21, 3}, Ifx_RxSel_d, IfxPort_OutputIdx_general};
IfxGeth_Pps_Out IfxGeth_PPS_P14_4_OUT = {&MODULE_GETH, {&MODULE_P14, 4}, IfxPort_OutputIdx_alt6};
IfxGeth_Refclk_In IfxGeth_REFCLKA_P11_12_IN = {&MODULE_GETH, {&MODULE_P11,12}, Ifx_RxSel_a};
IfxGeth_Rxclk_In IfxGeth_RXCLKA_P11_12_IN = {&MODULE_GETH, {&MODULE_P11,12}, Ifx_RxSel_a};
IfxGeth_Rxclk_In IfxGeth_RXCLKB_P11_4_IN = {&MODULE_GETH, {&MODULE_P11, 4}, Ifx_RxSel_b};
IfxGeth_Rxclk_In IfxGeth_RXCLKC_P12_0_IN = {&MODULE_GETH, {&MODULE_P12, 0}, Ifx_RxSel_c};
IfxGeth_Rxctl_In IfxGeth_RXCTLA_P11_11_IN = {&MODULE_GETH, {&MODULE_P11,11}, Ifx_RxSel_a};
IfxGeth_Rxd_In IfxGeth_RXD0A_P11_10_IN = {&MODULE_GETH, {&MODULE_P11,10}, Ifx_RxSel_a};
IfxGeth_Rxd_In IfxGeth_RXD1A_P11_9_IN = {&MODULE_GETH, {&MODULE_P11, 9}, Ifx_RxSel_a};
IfxGeth_Rxd_In IfxGeth_RXD2A_P11_8_IN = {&MODULE_GETH, {&MODULE_P11, 8}, Ifx_RxSel_a};
IfxGeth_Rxd_In IfxGeth_RXD3A_P11_7_IN = {&MODULE_GETH, {&MODULE_P11, 7}, Ifx_RxSel_a};
IfxGeth_Rxdv_In IfxGeth_RXDVA_P11_11_IN = {&MODULE_GETH, {&MODULE_P11,11}, Ifx_RxSel_a};
IfxGeth_Rxdv_In IfxGeth_RXDVB_P11_14_IN = {&MODULE_GETH, {&MODULE_P11,14}, Ifx_RxSel_b};
IfxGeth_Rxer_In IfxGeth_RXERA_P11_13_IN = {&MODULE_GETH, {&MODULE_P11,13}, Ifx_RxSel_a};
IfxGeth_Rxer_In IfxGeth_RXERB_P21_7_IN = {&MODULE_GETH, {&MODULE_P21, 7}, Ifx_RxSel_b};
IfxGeth_Rxer_In IfxGeth_RXERC_P10_0_IN = {&MODULE_GETH, {&MODULE_P10, 0}, Ifx_RxSel_c};
IfxGeth_Txclk_In IfxGeth_TXCLKA_P11_5_IN = {&MODULE_GETH, {&MODULE_P11, 5}, Ifx_RxSel_a};
IfxGeth_Txclk_In IfxGeth_TXCLKB_P11_12_IN = {&MODULE_GETH, {&MODULE_P11,12}, Ifx_RxSel_b};
IfxGeth_Txclk_Out IfxGeth_TXCLK_P11_4_OUT = {&MODULE_GETH, {&MODULE_P11, 4}, IfxPort_OutputIdx_alt7};
IfxGeth_Txctl_Out IfxGeth_TXCTL_P11_6_OUT = {&MODULE_GETH, {&MODULE_P11, 6}, IfxPort_OutputIdx_alt6};
IfxGeth_Txd_Out IfxGeth_TXD0_P11_3_OUT = {&MODULE_GETH, {&MODULE_P11, 3}, IfxPort_OutputIdx_alt6};
IfxGeth_Txd_Out IfxGeth_TXD1_P11_2_OUT = {&MODULE_GETH, {&MODULE_P11, 2}, IfxPort_OutputIdx_alt6};
IfxGeth_Txd_Out IfxGeth_TXD2_P11_1_OUT = {&MODULE_GETH, {&MODULE_P11, 1}, IfxPort_OutputIdx_alt6};
IfxGeth_Txd_Out IfxGeth_TXD3_P11_0_OUT = {&MODULE_GETH, {&MODULE_P11, 0}, IfxPort_OutputIdx_alt6};
IfxGeth_Txen_Out IfxGeth_TXEN_P11_6_OUT = {&MODULE_GETH, {&MODULE_P11, 6}, IfxPort_OutputIdx_alt6};
IfxGeth_Txer_Out IfxGeth_TXER_P11_4_OUT = {&MODULE_GETH, {&MODULE_P11, 4}, IfxPort_OutputIdx_alt6};


const IfxGeth_Col_In *IfxGeth_Col_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_COL_IN_NUM_ITEMS] = {
    {
        &IfxGeth_COL_P11_15_IN
    }
};

const IfxGeth_Crs_In *IfxGeth_Crs_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_CRS_IN_NUM_ITEMS] = {
    {
        &IfxGeth_CRSA_P11_14_IN,
        &IfxGeth_CRSB_P11_11_IN
    }
};

const IfxGeth_Crsdv_In *IfxGeth_Crsdv_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_CRSDV_IN_NUM_ITEMS] = {
    {
        &IfxGeth_CRSDVA_P11_11_IN,
        &IfxGeth_CRSDVB_P11_14_IN
    }
};

const IfxGeth_Grefclk_In *IfxGeth_Grefclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_GREFCLK_IN_NUM_ITEMS] = {
    {
        &IfxGeth_GREFCLK_P11_5_IN
    }
};

const IfxGeth_Mdc_Out *IfxGeth_Mdc_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_MDC_OUT_NUM_ITEMS] = {
    {
        &IfxGeth_MDC_P02_8_OUT,
        &IfxGeth_MDC_P12_0_OUT,
        &IfxGeth_MDC_P21_2_OUT
    }
};

const IfxGeth_Mdio_InOut *IfxGeth_Mdio_InOut_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_MDIO_INOUT_NUM_ITEMS] = {
    {
        &IfxGeth_MDIO_P00_0_INOUT,
        &IfxGeth_MDIO_P12_1_INOUT,
        &IfxGeth_MDIO_P21_3_INOUT
    }
};

const IfxGeth_Pps_Out *IfxGeth_Pps_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_PPS_OUT_NUM_ITEMS] = {
    {
        &IfxGeth_PPS_P14_4_OUT
    }
};

const IfxGeth_Refclk_In *IfxGeth_Refclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_REFCLK_IN_NUM_ITEMS] = {
    {
        &IfxGeth_REFCLKA_P11_12_IN
    }
};

const IfxGeth_Rxclk_In *IfxGeth_Rxclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXCLK_IN_NUM_ITEMS] = {
    {
        &IfxGeth_RXCLKA_P11_12_IN,
        &IfxGeth_RXCLKB_P11_4_IN,
        &IfxGeth_RXCLKC_P12_0_IN
    }
};

const IfxGeth_Rxctl_In *IfxGeth_Rxctl_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXCTL_IN_NUM_ITEMS] = {
    {
        &IfxGeth_RXCTLA_P11_11_IN
    }
};

const IfxGeth_Rxd_In *IfxGeth_Rxd_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXD_IN_NUM_ITEMS] = {
    {
        &IfxGeth_RXD3A_P11_7_IN,
        &IfxGeth_RXD1A_P11_9_IN,
        &IfxGeth_RXD2A_P11_8_IN,
        &IfxGeth_RXD0A_P11_10_IN
    }
};

const IfxGeth_Rxdv_In *IfxGeth_Rxdv_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXDV_IN_NUM_ITEMS] = {
    {
        &IfxGeth_RXDVA_P11_11_IN,
        &IfxGeth_RXDVB_P11_14_IN
    }
};

const IfxGeth_Rxer_In *IfxGeth_Rxer_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_RXER_IN_NUM_ITEMS] = {
    {
        &IfxGeth_RXERA_P11_13_IN,
        &IfxGeth_RXERB_P21_7_IN,
        &IfxGeth_RXERC_P10_0_IN
    }
};

const IfxGeth_Txclk_In *IfxGeth_Txclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXCLK_IN_NUM_ITEMS] = {
    {
        &IfxGeth_TXCLKA_P11_5_IN,
        &IfxGeth_TXCLKB_P11_12_IN
    }
};

const IfxGeth_Txclk_Out *IfxGeth_Txclk_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXCLK_OUT_NUM_ITEMS] = {
    {
        &IfxGeth_TXCLK_P11_4_OUT
    }
};

const IfxGeth_Txctl_Out *IfxGeth_Txctl_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXCTL_OUT_NUM_ITEMS] = {
    {
        &IfxGeth_TXCTL_P11_6_OUT
    }
};

const IfxGeth_Txd_Out *IfxGeth_Txd_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXD_OUT_NUM_ITEMS] = {
    {
        &IfxGeth_TXD3_P11_0_OUT,
        &IfxGeth_TXD2_P11_1_OUT,
        &IfxGeth_TXD1_P11_2_OUT,
        &IfxGeth_TXD0_P11_3_OUT
    }
};

const IfxGeth_Txen_Out *IfxGeth_Txen_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXEN_OUT_NUM_ITEMS] = {
    {
        &IfxGeth_TXEN_P11_6_OUT
    }
};

const IfxGeth_Txer_Out *IfxGeth_Txer_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_TXER_OUT_NUM_ITEMS] = {
    {
        &IfxGeth_TXER_P11_4_OUT
    }
};
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
