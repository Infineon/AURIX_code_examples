/**
 * \file IfxGeth_PinMap_TC48x_BGA224_STD.c
 * \brief GETH  details
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
#if defined(DEVICE_TC48X) && defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "IfxGeth_PinMap_TC48x_BGA224_STD.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/
IfxGeth_P_In IfxGeth0_P1_AUX_P00_1_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P00, 1}, Ifx_RxSel_a};

IfxGeth_Col_In     IfxGeth0_P1_COL_P22_2_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 2}, Ifx_RxSel_a};

IfxGeth_Col_In     IfxGeth0_P1_COL_P22_3_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 3}, Ifx_RxSel_b};

IfxGeth_Crs_In     IfxGeth0_P1_CRSA_P22_0_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 0}, Ifx_RxSel_a};

IfxGeth_Crs_In     IfxGeth0_P1_CRSB_P22_6_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 6}, Ifx_RxSel_b};

IfxGeth_Crsdv_In   IfxGeth0_P1_CRSDVA_P22_6_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 6}, Ifx_RxSel_a};

IfxGeth_Crsdv_In   IfxGeth0_P1_CRSDVB_P22_0_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 0}, Ifx_RxSel_b};

IfxGeth_Mdc_Out    IfxGeth0_P1_MDC_P02_8_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P02, 8}, IfxPort_OutputIdx_alt8};

IfxGeth_Mdc_Out    IfxGeth0_P1_MDC_P21_2_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P21, 2}, IfxPort_OutputIdx_alt7};

IfxGeth_Txd_Out    IfxGeth0_P1_MII_TXD0_P23_5_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 5}, IfxPort_OutputIdx_alt4};

IfxGeth_Txd_Out    IfxGeth0_P1_MII_TXD1_P23_4_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 4}, IfxPort_OutputIdx_alt4};

IfxGeth_Txd_Out    IfxGeth0_P1_MII_TXD2_P23_3_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 3}, IfxPort_OutputIdx_alt10};

IfxGeth_Txd_Out    IfxGeth0_P1_MII_TXD3_P23_2_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 2}, IfxPort_OutputIdx_alt10};

IfxGeth_Txen_Out   IfxGeth0_P1_MII_TXEN_P22_2_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 2}, IfxPort_OutputIdx_alt8};

IfxGeth_Pps_Out IfxGeth0_P1_PPS0_P14_4_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P14, 4}, IfxPort_OutputIdx_alt8};

IfxGeth_Pps_Out IfxGeth0_P1_PPS1_P14_8_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P14, 8}, IfxPort_OutputIdx_alt8};

IfxGeth_Refclk_In  IfxGeth0_P1_REFCLKA_P22_5_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 5}, Ifx_RxSel_a};

IfxGeth_Refclk_In  IfxGeth0_P1_REFCLKB_P22_1_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 1}, Ifx_RxSel_b};

IfxGeth_Refclk_In  IfxGeth0_P1_REFCLKC_P22_3_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 3}, Ifx_RxSel_c};

IfxGeth_Txd_Out    IfxGeth0_P1_RMIIA_TXD0_P23_5_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 5}, IfxPort_OutputIdx_alt7};

IfxGeth_Txd_Out    IfxGeth0_P1_RMIIA_TXD1_P23_4_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 4}, IfxPort_OutputIdx_alt7};

IfxGeth_Txen_Out   IfxGeth0_P1_RMIIA_TXEN_P22_2_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 2}, IfxPort_OutputIdx_alt10};

IfxGeth_Txd_Out    IfxGeth0_P1_RMIIB_TXD0_P23_5_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 5}, IfxPort_OutputIdx_alt10};

IfxGeth_Txd_Out    IfxGeth0_P1_RMIIB_TXD1_P23_4_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 4}, IfxPort_OutputIdx_alt10};

IfxGeth_Txen_Out   IfxGeth0_P1_RMIIB_TXEN_P22_2_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 2}, IfxPort_OutputIdx_alt11};

IfxGeth_Rxclk_In   IfxGeth0_P1_RXCLKA_P22_5_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 5}, Ifx_RxSel_a};

IfxGeth_Rxclk_In   IfxGeth0_P1_RXCLKB_P22_1_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 1}, Ifx_RxSel_b};

IfxGeth_Rxclk_In   IfxGeth0_P1_RXCLKC_P22_3_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 3}, Ifx_RxSel_c};

IfxGeth_Rxd_In     IfxGeth0_P1_RXD0A_P22_4_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 4}, Ifx_RxSel_a};

IfxGeth_Rxd_In     IfxGeth0_P1_RXD0B_P22_3_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 3}, Ifx_RxSel_b};

IfxGeth_Rxd_In     IfxGeth0_P1_RXD0C_P22_4_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 4}, Ifx_RxSel_c};

IfxGeth_Rxd_In     IfxGeth0_P1_RXD1B_P23_1_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 1}, Ifx_RxSel_b};

IfxGeth_Rxd_In     IfxGeth0_P1_RXD3C_P23_5_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 5}, Ifx_RxSel_c};

IfxGeth_Rxdv_In    IfxGeth0_P1_RXDVA_P22_6_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 6}, Ifx_RxSel_a};

IfxGeth_Rxdv_In    IfxGeth0_P1_RXDVB_P22_0_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 0}, Ifx_RxSel_b};

IfxGeth_Rxer_In    IfxGeth0_P1_RXERA_P22_1_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 1}, Ifx_RxSel_a};

IfxGeth_Rxer_In    IfxGeth0_P1_RXERC_P20_0_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P20, 0}, Ifx_RxSel_c};

IfxGeth_Txclk_In   IfxGeth0_P1_TXCLKA_P22_7_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 7}, Ifx_RxSel_a};

IfxGeth_Txclk_In   IfxGeth0_P1_TXCLKB_P22_5_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 5}, Ifx_RxSel_b};

IfxGeth_Txclk_In   IfxGeth0_P1_TXCLKC_P22_7_IN = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P22, 7}, Ifx_RxSel_c};

IfxGeth_Txer_Out   IfxGeth0_P1_TXER_P23_0_OUT = {&MODULE_GETH0, (IfxGeth_PortIndex)1, {&MODULE_P23, 0}, IfxPort_OutputIdx_alt10};

IfxGeth_Mdio_InOut IfxGeth0_PX_MDIO_P00_0_INOUT = {&MODULE_GETH0, {&MODULE_P00, 0}, Ifx_RxSel_a, IfxPort_OutputIdx_general};

IfxGeth_Mdio_InOut IfxGeth0_PX_MDIO_P21_3_INOUT = {&MODULE_GETH0, {&MODULE_P21, 3}, Ifx_RxSel_d, IfxPort_OutputIdx_general};

/** \addtogroup IfxLld_Geth__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxGeth_Col_In     *IfxGeth_Col_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_COL_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_COL_P22_2_IN,
            &IfxGeth0_P1_COL_P22_3_IN,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Crs_In     *IfxGeth_Crs_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_CRS_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_CRSA_P22_0_IN,
            &IfxGeth0_P1_CRSB_P22_6_IN,
        },
    },
};

IFX_CONST IfxGeth_Crsdv_In   *IfxGeth_Crsdv_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_CRSDV_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_CRSDVA_P22_6_IN,
            &IfxGeth0_P1_CRSDVB_P22_0_IN,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Mdc_Out    *IfxGeth_Mdc_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_MDC_OUT_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_MDC_P02_8_OUT,
            &IfxGeth0_P1_MDC_P21_2_OUT,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Mdio_InOut *IfxGeth_Mdio_InOut_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_MDIO_INOUT_NUM_ITEMS] = {
    {
        &IfxGeth0_PX_MDIO_P00_0_INOUT,
        NULL_PTR,
        NULL_PTR,
        &IfxGeth0_PX_MDIO_P21_3_INOUT,
    },
};

IFX_CONST IfxGeth_P_In* IfxGeth_P_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_P_IN_NUM_ITEMS] =     {
	{
		{
			NULL_PTR,
		},
		{
			&IfxGeth0_P1_AUX_P00_1_IN,
		},
	},
};
IFX_CONST IfxGeth_Pps_Out    *IfxGeth_Pps_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_PPS_OUT_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
        },
        {
			&IfxGeth0_P1_PPS0_P14_4_OUT,
			&IfxGeth0_P1_PPS1_P14_8_OUT,
        },
    },
};

IFX_CONST IfxGeth_Refclk_In  *IfxGeth_Refclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_REFCLK_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_REFCLKA_P22_5_IN,
            &IfxGeth0_P1_REFCLKB_P22_1_IN,
            &IfxGeth0_P1_REFCLKC_P22_3_IN,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Rxclk_In   *IfxGeth_Rxclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_RXCLK_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_RXCLKA_P22_5_IN,
            &IfxGeth0_P1_RXCLKB_P22_1_IN,
            &IfxGeth0_P1_RXCLKC_P22_3_IN,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Rxd_In     *IfxGeth_Rxd_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_RXD_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_RXD0A_P22_4_IN,
            &IfxGeth0_P1_RXD0B_P22_3_IN,
            &IfxGeth0_P1_RXD1B_P23_1_IN,
            &IfxGeth0_P1_RXD0C_P22_4_IN,
            &IfxGeth0_P1_RXD3C_P23_5_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Rxdv_In    *IfxGeth_Rxdv_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_RXDV_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_RXDVA_P22_6_IN,
            &IfxGeth0_P1_RXDVB_P22_0_IN,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Rxer_In    *IfxGeth_Rxer_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_RXER_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_RXERA_P22_1_IN,
            NULL_PTR,
            &IfxGeth0_P1_RXERC_P20_0_IN,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Txclk_In   *IfxGeth_Txclk_In_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_TXCLK_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_TXCLKA_P22_7_IN,
            &IfxGeth0_P1_TXCLKB_P22_5_IN,
            &IfxGeth0_P1_TXCLKC_P22_7_IN,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Txd_Out    *IfxGeth_Txd_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_TXD_OUT_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
			NULL_PTR,
			NULL_PTR,
        },
        {
            &IfxGeth0_P1_MII_TXD3_P23_2_OUT,
            &IfxGeth0_P1_MII_TXD2_P23_3_OUT,
            &IfxGeth0_P1_MII_TXD1_P23_4_OUT,
            &IfxGeth0_P1_RMIIA_TXD1_P23_4_OUT,
            &IfxGeth0_P1_RMIIB_TXD1_P23_4_OUT,
            &IfxGeth0_P1_MII_TXD0_P23_5_OUT,
            &IfxGeth0_P1_RMIIA_TXD0_P23_5_OUT,
            &IfxGeth0_P1_RMIIB_TXD0_P23_5_OUT,
			NULL_PTR,
			NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Txen_Out   *IfxGeth_Txen_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_TXEN_OUT_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
			NULL_PTR,
        },
        {
            &IfxGeth0_P1_MII_TXEN_P22_2_OUT,
            &IfxGeth0_P1_RMIIA_TXEN_P22_2_OUT,
            &IfxGeth0_P1_RMIIB_TXEN_P22_2_OUT,
			NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxGeth_Txer_Out   *IfxGeth_Txer_Out_pinTable[IFXGETH_PINMAP_NUM_MODULES][IFXGETH_PINMAP_NUM_PORTS][IFXGETH_PINMAP_TXER_OUT_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxGeth0_P1_TXER_P23_0_OUT,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

/** \} */

#endif
