/**
 * \file IfxAudio_PinMap_TC48x_BGA224_STD.c
 * \brief AUDIO  details
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
#include "IfxAudio_PinMap_TC48x_BGA224_STD.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxAudio_Rxfsync_In  IfxAudio0_TDM0_RXFSYNCIB_P13_1_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 1}, IfxAudio_PinSel_b};

IfxAudio_Rxfsync_In  IfxAudio0_TDM0_RXFSYNCIC_P15_3_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 3}, IfxAudio_PinSel_c};

IfxAudio_Rxfsync_In  IfxAudio0_TDM0_RXFSYNCID_P14_0_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P14, 0}, IfxAudio_PinSel_d};

IfxAudio_Rxfsync_Out IfxAudio0_TDM0_RXFSYNCO_P13_1_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 1}, IfxPort_OutputIdx_alt14};

IfxAudio_Rxfsync_Out IfxAudio0_TDM0_RXFSYNCO_P15_3_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 3}, IfxPort_OutputIdx_alt13};

IfxAudio_Rxmck_In    IfxAudio0_TDM0_RXMCKIA_P14_7_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P14, 7}, IfxAudio_PinSel_a};

IfxAudio_Rxmck_In    IfxAudio0_TDM0_RXMCKIB_P13_3_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 3}, IfxAudio_PinSel_b};

IfxAudio_Rxmck_In    IfxAudio0_TDM0_RXMCKIC_P15_1_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 1}, IfxAudio_PinSel_c};

IfxAudio_Rxmck_In    IfxAudio0_TDM0_RXMCKID_P14_6_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P14, 6}, IfxAudio_PinSel_d};

IfxAudio_Rxmck_Out   IfxAudio0_TDM0_RXMCKO_P13_3_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 3}, IfxPort_OutputIdx_alt14};

IfxAudio_Rxmck_Out   IfxAudio0_TDM0_RXMCKO_P14_7_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P14, 7}, IfxPort_OutputIdx_alt10};

IfxAudio_Rxmck_Out   IfxAudio0_TDM0_RXMCKO_P15_1_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 1}, IfxPort_OutputIdx_alt13};

IfxAudio_Rxsck_In    IfxAudio0_TDM0_RXSCKIB_P13_2_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 2}, IfxAudio_PinSel_b};

IfxAudio_Rxsck_In    IfxAudio0_TDM0_RXSCKIC_P15_4_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 4}, IfxAudio_PinSel_c};

IfxAudio_Rxsck_In    IfxAudio0_TDM0_RXSCKID_P14_1_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P14, 1}, IfxAudio_PinSel_d};

IfxAudio_Rxsck_Out   IfxAudio0_TDM0_RXSCKO_P13_2_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 2}, IfxPort_OutputIdx_alt14};

IfxAudio_Rxsck_Out   IfxAudio0_TDM0_RXSCKO_P15_4_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 4}, IfxPort_OutputIdx_alt5};

IfxAudio_Rxsd_In     IfxAudio0_TDM0_RXSDIA_P14_5_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P14, 5}, IfxAudio_PinSel_a};

IfxAudio_Rxsd_In     IfxAudio0_TDM0_RXSDIB_P13_0_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 0}, IfxAudio_PinSel_b};

IfxAudio_Rxsd_In     IfxAudio0_TDM0_RXSDID_P15_5_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 5}, IfxAudio_PinSel_d};

IfxAudio_Txfsync_In  IfxAudio0_TDM0_TXFSYNCIA_P13_1_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 1}, IfxAudio_PinSel_a};

IfxAudio_Txfsync_In  IfxAudio0_TDM0_TXFSYNCIB_P15_3_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 3}, IfxAudio_PinSel_b};

IfxAudio_Txfsync_Out IfxAudio0_TDM0_TXFSYNCO_P13_1_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 1}, IfxPort_OutputIdx_alt15};

IfxAudio_Txfsync_Out IfxAudio0_TDM0_TXFSYNCO_P15_3_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 3}, IfxPort_OutputIdx_alt14};

IfxAudio_Txmck_In    IfxAudio0_TDM0_TXMCKIA_P13_3_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 3}, IfxAudio_PinSel_a};

IfxAudio_Txmck_In    IfxAudio0_TDM0_TXMCKIB_P15_1_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 1}, IfxAudio_PinSel_b};

IfxAudio_Txmck_In    IfxAudio0_TDM0_TXMCKIC_P14_7_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P14, 7}, IfxAudio_PinSel_c};

IfxAudio_Txmck_Out   IfxAudio0_TDM0_TXMCKO_P13_3_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 3}, IfxPort_OutputIdx_alt15};

IfxAudio_Txmck_Out   IfxAudio0_TDM0_TXMCKO_P14_7_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P14, 7}, IfxPort_OutputIdx_alt14};

IfxAudio_Txmck_Out   IfxAudio0_TDM0_TXMCKO_P15_1_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 1}, IfxPort_OutputIdx_alt14};

IfxAudio_Txsck_In    IfxAudio0_TDM0_TXSCKIA_P13_2_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 2}, IfxAudio_PinSel_a};

IfxAudio_Txsck_In    IfxAudio0_TDM0_TXSCKIB_P15_4_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 4}, IfxAudio_PinSel_b};

IfxAudio_Txsck_Out   IfxAudio0_TDM0_TXSCKO_P13_2_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 2}, IfxPort_OutputIdx_alt15};

IfxAudio_Txsck_Out   IfxAudio0_TDM0_TXSCKO_P15_4_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P15, 4}, IfxPort_OutputIdx_alt14};

IfxAudio_Txsd_Out    IfxAudio0_TDM0_TXSDOA_P13_0_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P13, 0}, IfxAudio_PinSel_a};

IfxAudio_Txsd_Out    IfxAudio0_TDM0_TXSDOC_P14_5_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)0, {&MODULE_P14, 5}, IfxAudio_PinSel_c};

IfxAudio_Rxfsync_In  IfxAudio0_TDM1_RXFSYNCIA_P14_0_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 0}, IfxAudio_PinSel_a};

IfxAudio_Rxfsync_In  IfxAudio0_TDM1_RXFSYNCIB_P13_1_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P13, 1}, IfxAudio_PinSel_b};

IfxAudio_Rxfsync_In  IfxAudio0_TDM1_RXFSYNCID_P15_6_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 6}, IfxAudio_PinSel_d};

IfxAudio_Rxfsync_Out IfxAudio0_TDM1_RXFSYNCO_P14_0_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 0}, IfxPort_OutputIdx_alt7};

IfxAudio_Rxfsync_Out IfxAudio0_TDM1_RXFSYNCO_P15_6_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 6}, IfxPort_OutputIdx_alt13};

IfxAudio_Rxmck_In    IfxAudio0_TDM1_RXMCKIA_P14_6_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 6}, IfxAudio_PinSel_a};

IfxAudio_Rxmck_In    IfxAudio0_TDM1_RXMCKIB_P13_3_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P13, 3}, IfxAudio_PinSel_b};

IfxAudio_Rxmck_In    IfxAudio0_TDM1_RXMCKIC_P14_7_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 7}, IfxAudio_PinSel_c};

IfxAudio_Rxmck_In    IfxAudio0_TDM1_RXMCKID_P15_8_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 8}, IfxAudio_PinSel_d};

IfxAudio_Rxmck_Out   IfxAudio0_TDM1_RXMCKO_P14_6_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 6}, IfxPort_OutputIdx_alt10};

IfxAudio_Rxmck_Out   IfxAudio0_TDM1_RXMCKO_P15_8_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 8}, IfxPort_OutputIdx_alt13};

IfxAudio_Rxsck_In    IfxAudio0_TDM1_RXSCKIA_P14_1_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 1}, IfxAudio_PinSel_a};

IfxAudio_Rxsck_In    IfxAudio0_TDM1_RXSCKIB_P13_2_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P13, 2}, IfxAudio_PinSel_b};

IfxAudio_Rxsck_In    IfxAudio0_TDM1_RXSCKID_P15_7_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 7}, IfxAudio_PinSel_d};

IfxAudio_Rxsck_Out   IfxAudio0_TDM1_RXSCKO_P14_1_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 1}, IfxPort_OutputIdx_alt11};

IfxAudio_Rxsck_Out   IfxAudio0_TDM1_RXSCKO_P15_7_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 7}, IfxPort_OutputIdx_alt8};

IfxAudio_Rxsd_In     IfxAudio0_TDM1_RXSDIA_P15_5_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 5}, IfxAudio_PinSel_a};

IfxAudio_Rxsd_In     IfxAudio0_TDM1_RXSDIB_P13_0_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P13, 0}, IfxAudio_PinSel_b};

IfxAudio_Rxsd_In     IfxAudio0_TDM1_RXSDIC_P14_5_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 5}, IfxAudio_PinSel_c};

IfxAudio_Rxsd_In     IfxAudio0_TDM1_RXSDID_P14_10_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 10}, IfxAudio_PinSel_d};

IfxAudio_Txfsync_In  IfxAudio0_TDM1_TXFSYNCIA_P14_0_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 0}, IfxAudio_PinSel_a};

IfxAudio_Txfsync_In  IfxAudio0_TDM1_TXFSYNCIB_P15_6_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 6}, IfxAudio_PinSel_b};

IfxAudio_Txfsync_Out IfxAudio0_TDM1_TXFSYNCO_P14_0_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 0}, IfxPort_OutputIdx_alt8};

IfxAudio_Txfsync_Out IfxAudio0_TDM1_TXFSYNCO_P15_6_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 6}, IfxPort_OutputIdx_alt14};

IfxAudio_Txmck_In    IfxAudio0_TDM1_TXMCKIA_P14_6_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 6}, IfxAudio_PinSel_a};

IfxAudio_Txmck_In    IfxAudio0_TDM1_TXMCKIB_P15_8_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 8}, IfxAudio_PinSel_b};

IfxAudio_Txmck_Out   IfxAudio0_TDM1_TXMCKO_P14_6_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 6}, IfxPort_OutputIdx_alt11};

IfxAudio_Txmck_Out   IfxAudio0_TDM1_TXMCKO_P15_8_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 8}, IfxPort_OutputIdx_alt14};

IfxAudio_Txsck_In    IfxAudio0_TDM1_TXSCKIA_P14_1_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 1}, IfxAudio_PinSel_a};

IfxAudio_Txsck_In    IfxAudio0_TDM1_TXSCKIB_P15_7_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 7}, IfxAudio_PinSel_b};

IfxAudio_Txsck_Out   IfxAudio0_TDM1_TXSCKO_P14_1_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 1}, IfxPort_OutputIdx_alt12};

IfxAudio_Txsck_Out   IfxAudio0_TDM1_TXSCKO_P15_7_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 7}, IfxPort_OutputIdx_alt14};

IfxAudio_Txsd_Out    IfxAudio0_TDM1_TXSDOA_P15_5_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P15, 5}, IfxAudio_PinSel_a};

IfxAudio_Txsd_Out    IfxAudio0_TDM1_TXSDOB_P14_10_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)1, {&MODULE_P14, 10}, IfxAudio_PinSel_b};

IfxAudio_Rxfsync_In  IfxAudio0_TDM2_RXFSYNCIA_P15_2_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)2, {&MODULE_P15, 2}, IfxAudio_PinSel_a};

IfxAudio_Rxfsync_Out IfxAudio0_TDM2_RXFSYNCO_P15_2_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)2, {&MODULE_P15, 2}, IfxPort_OutputIdx_alt13};

IfxAudio_Rxsck_In    IfxAudio0_TDM2_RXSCKIC_P14_8_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)2, {&MODULE_P14, 8}, IfxAudio_PinSel_c};

IfxAudio_Rxsck_Out   IfxAudio0_TDM2_RXSCKO_P14_8_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)2, {&MODULE_P14, 8}, IfxPort_OutputIdx_alt11};

IfxAudio_Txfsync_In  IfxAudio0_TDM2_TXFSYNCIA_P15_2_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)2, {&MODULE_P15, 2}, IfxAudio_PinSel_a};

IfxAudio_Txfsync_Out IfxAudio0_TDM2_TXFSYNCO_P15_2_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)2, {&MODULE_P15, 2}, IfxPort_OutputIdx_alt14};

IfxAudio_Txsck_In    IfxAudio0_TDM2_TXSCKIC_P14_8_IN = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)2, {&MODULE_P14, 8}, IfxAudio_PinSel_c};

IfxAudio_Txsck_Out   IfxAudio0_TDM2_TXSCKO_P14_8_OUT = {&MODULE_AUDIO0, (IfxAudio_TdmInterfaceIndex)2, {&MODULE_P14, 8}, IfxPort_OutputIdx_alt12};

/** \addtogroup IfxLld_Audio__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxAudio_Rxfsync_In  *IfxAudio_Rxfsync_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXFSYNC_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            &IfxAudio0_TDM0_RXFSYNCIB_P13_1_IN,
            &IfxAudio0_TDM0_RXFSYNCIC_P15_3_IN,
            &IfxAudio0_TDM0_RXFSYNCID_P14_0_IN,
        },
        {
            &IfxAudio0_TDM1_RXFSYNCIA_P14_0_IN,
            &IfxAudio0_TDM1_RXFSYNCIB_P13_1_IN,
            NULL_PTR,
            &IfxAudio0_TDM1_RXFSYNCID_P15_6_IN,
        },
        {
            &IfxAudio0_TDM2_RXFSYNCIA_P15_2_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Rxfsync_Out *IfxAudio_Rxfsync_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXFSYNC_OUT_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_RXFSYNCO_P13_1_OUT,
            &IfxAudio0_TDM0_RXFSYNCO_P15_3_OUT,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM1_RXFSYNCO_P14_0_OUT,
            &IfxAudio0_TDM1_RXFSYNCO_P15_6_OUT,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM2_RXFSYNCO_P15_2_OUT,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Rxmck_In    *IfxAudio_Rxmck_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXMCK_IN_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_RXMCKIA_P14_7_IN,
            &IfxAudio0_TDM0_RXMCKIB_P13_3_IN,
            &IfxAudio0_TDM0_RXMCKIC_P15_1_IN,
            &IfxAudio0_TDM0_RXMCKID_P14_6_IN,
        },
        {
            &IfxAudio0_TDM1_RXMCKIA_P14_6_IN,
            &IfxAudio0_TDM1_RXMCKIB_P13_3_IN,
            &IfxAudio0_TDM1_RXMCKIC_P14_7_IN,
            &IfxAudio0_TDM1_RXMCKID_P15_8_IN,
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Rxmck_Out   *IfxAudio_Rxmck_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXMCK_OUT_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_RXMCKO_P13_3_OUT,
            &IfxAudio0_TDM0_RXMCKO_P14_7_OUT,
            &IfxAudio0_TDM0_RXMCKO_P15_1_OUT,
        },
        {
            &IfxAudio0_TDM1_RXMCKO_P14_6_OUT,
            &IfxAudio0_TDM1_RXMCKO_P15_8_OUT,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Rxsck_In    *IfxAudio_Rxsck_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXSCK_IN_NUM_ITEMS] = {
    {
        {
            NULL_PTR,
            &IfxAudio0_TDM0_RXSCKIB_P13_2_IN,
            &IfxAudio0_TDM0_RXSCKIC_P15_4_IN,
            &IfxAudio0_TDM0_RXSCKID_P14_1_IN,
        },
        {
            &IfxAudio0_TDM1_RXSCKIA_P14_1_IN,
            &IfxAudio0_TDM1_RXSCKIB_P13_2_IN,
            NULL_PTR,
            &IfxAudio0_TDM1_RXSCKID_P15_7_IN,
        },
        {
            NULL_PTR,
            NULL_PTR,
            &IfxAudio0_TDM2_RXSCKIC_P14_8_IN,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Rxsck_Out   *IfxAudio_Rxsck_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXSCK_OUT_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_RXSCKO_P13_2_OUT,
            &IfxAudio0_TDM0_RXSCKO_P15_4_OUT,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM1_RXSCKO_P14_1_OUT,
            &IfxAudio0_TDM1_RXSCKO_P15_7_OUT,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM2_RXSCKO_P14_8_OUT,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Rxsd_In     *IfxAudio_Rxsd_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXSD_IN_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_RXSDIA_P14_5_IN,
            &IfxAudio0_TDM0_RXSDIB_P13_0_IN,
            NULL_PTR,
            &IfxAudio0_TDM0_RXSDID_P15_5_IN,
        },
        {
            &IfxAudio0_TDM1_RXSDIA_P15_5_IN,
            &IfxAudio0_TDM1_RXSDIB_P13_0_IN,
            &IfxAudio0_TDM1_RXSDIC_P14_5_IN,
            &IfxAudio0_TDM1_RXSDID_P14_10_IN,
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Txfsync_In  *IfxAudio_Txfsync_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXFSYNC_IN_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_TXFSYNCIA_P13_1_IN,
            &IfxAudio0_TDM0_TXFSYNCIB_P15_3_IN,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM1_TXFSYNCIA_P14_0_IN,
            &IfxAudio0_TDM1_TXFSYNCIB_P15_6_IN,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM2_TXFSYNCIA_P15_2_IN,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Txfsync_Out *IfxAudio_Txfsync_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXFSYNC_OUT_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_TXFSYNCO_P13_1_OUT,
            &IfxAudio0_TDM0_TXFSYNCO_P15_3_OUT,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM1_TXFSYNCO_P14_0_OUT,
            &IfxAudio0_TDM1_TXFSYNCO_P15_6_OUT,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM2_TXFSYNCO_P15_2_OUT,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Txmck_In    *IfxAudio_Txmck_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXMCK_IN_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_TXMCKIA_P13_3_IN,
            &IfxAudio0_TDM0_TXMCKIB_P15_1_IN,
            &IfxAudio0_TDM0_TXMCKIC_P14_7_IN,
        },
        {
            &IfxAudio0_TDM1_TXMCKIA_P14_6_IN,
            &IfxAudio0_TDM1_TXMCKIB_P15_8_IN,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Txmck_Out   *IfxAudio_Txmck_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXMCK_OUT_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_TXMCKO_P13_3_OUT,
            &IfxAudio0_TDM0_TXMCKO_P14_7_OUT,
            &IfxAudio0_TDM0_TXMCKO_P15_1_OUT,
        },
        {
            &IfxAudio0_TDM1_TXMCKO_P14_6_OUT,
            &IfxAudio0_TDM1_TXMCKO_P15_8_OUT,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Txsck_In    *IfxAudio_Txsck_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXSCK_IN_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_TXSCKIA_P13_2_IN,
            &IfxAudio0_TDM0_TXSCKIB_P15_4_IN,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM1_TXSCKIA_P14_1_IN,
            &IfxAudio0_TDM1_TXSCKIB_P15_7_IN,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
            &IfxAudio0_TDM2_TXSCKIC_P14_8_IN,
        },
    },
};

IFX_CONST IfxAudio_Txsck_Out   *IfxAudio_Txsck_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXSCK_OUT_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_TXSCKO_P13_2_OUT,
            &IfxAudio0_TDM0_TXSCKO_P15_4_OUT,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM1_TXSCKO_P14_1_OUT,
            &IfxAudio0_TDM1_TXSCKO_P15_7_OUT,
            NULL_PTR,
        },
        {
            &IfxAudio0_TDM2_TXSCKO_P14_8_OUT,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxAudio_Txsd_Out    *IfxAudio_Txsd_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXSD_OUT_NUM_ITEMS] = {
    {
        {
            &IfxAudio0_TDM0_TXSDOA_P13_0_OUT,
            NULL_PTR,
            &IfxAudio0_TDM0_TXSDOC_P14_5_OUT,
        },
        {
            &IfxAudio0_TDM1_TXSDOA_P15_5_OUT,
            &IfxAudio0_TDM1_TXSDOB_P14_10_OUT,
            NULL_PTR,
        },
        {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
        },
    },
};

/** \} */

#endif
