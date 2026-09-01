/**
 * \file IfxAudio_PinMap_TC48x_BGA292_COM.h
 * \brief AUDIO  details
 * \ingroup IfxLld_Audio
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
 * Version: MC_ACE_A3G_PRQ_Package_Pinning/v8.2.1.1.2
 * Document: TC48x_A21_Pin_Assignment_v0.2.6_20251118.xls 
 *
 * \defgroup IfxLld_Audio_Pinmap Audio Pinmap Structure
 * \ingroup IfxLld_Audio
 * \defgroup IfxLld_Audio__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Audio_
 * \defgroup IfxLld_Audio__PinTables PinTables
 * \ingroup IfxLld_Audio_
 */

#ifndef IFXAUDIO_PINMAP_TC48X_BGA292_COM_H
#define IFXAUDIO_PINMAP_TC48X_BGA292_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxAudio_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXAUDIO_PINMAP_NUM_MODULES           1

#define IFXAUDIO_PINMAP_NUM_TDM_INTERFACES    3

#define IFXAUDIO_PINMAP_RXFSYNC_IN_NUM_ITEMS  4

#define IFXAUDIO_PINMAP_RXFSYNC_OUT_NUM_ITEMS 3

#define IFXAUDIO_PINMAP_RXMCK_IN_NUM_ITEMS    4

#define IFXAUDIO_PINMAP_RXMCK_OUT_NUM_ITEMS   3

#define IFXAUDIO_PINMAP_RXSCK_IN_NUM_ITEMS    4

#define IFXAUDIO_PINMAP_RXSCK_OUT_NUM_ITEMS   3

#define IFXAUDIO_PINMAP_RXSD_IN_NUM_ITEMS     4

#define IFXAUDIO_PINMAP_TXFSYNC_IN_NUM_ITEMS  3

#define IFXAUDIO_PINMAP_TXFSYNC_OUT_NUM_ITEMS 3

#define IFXAUDIO_PINMAP_TXMCK_IN_NUM_ITEMS    3

#define IFXAUDIO_PINMAP_TXMCK_OUT_NUM_ITEMS   3

#define IFXAUDIO_PINMAP_TXSCK_IN_NUM_ITEMS    3

#define IFXAUDIO_PINMAP_TXSCK_OUT_NUM_ITEMS   3

#define IFXAUDIO_PINMAP_TXSD_OUT_NUM_ITEMS    3

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_In  IfxAudio0_TDM0_RXFSYNCIA_P14_9_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_In  IfxAudio0_TDM0_RXFSYNCIB_P13_1_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_In  IfxAudio0_TDM0_RXFSYNCIC_P15_3_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_In  IfxAudio0_TDM0_RXFSYNCID_P14_0_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_Out IfxAudio0_TDM0_RXFSYNCO_P13_1_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_Out IfxAudio0_TDM0_RXFSYNCO_P14_9_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_Out IfxAudio0_TDM0_RXFSYNCO_P15_3_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_In    IfxAudio0_TDM0_RXMCKIA_P14_7_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_In    IfxAudio0_TDM0_RXMCKIB_P13_3_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_In    IfxAudio0_TDM0_RXMCKIC_P15_1_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_In    IfxAudio0_TDM0_RXMCKID_P14_6_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_Out   IfxAudio0_TDM0_RXMCKO_P13_3_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_Out   IfxAudio0_TDM0_RXMCKO_P14_7_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_Out   IfxAudio0_TDM0_RXMCKO_P15_1_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_In    IfxAudio0_TDM0_RXSCKIB_P13_2_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_In    IfxAudio0_TDM0_RXSCKIC_P15_4_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_In    IfxAudio0_TDM0_RXSCKID_P14_1_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_Out   IfxAudio0_TDM0_RXSCKO_P13_2_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_Out   IfxAudio0_TDM0_RXSCKO_P15_4_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsd_In     IfxAudio0_TDM0_RXSDIA_P14_5_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsd_In     IfxAudio0_TDM0_RXSDIB_P13_0_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsd_In     IfxAudio0_TDM0_RXSDID_P15_5_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_In  IfxAudio0_TDM0_TXFSYNCIA_P13_1_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_In  IfxAudio0_TDM0_TXFSYNCIB_P15_3_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_In  IfxAudio0_TDM0_TXFSYNCIC_P14_9_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_Out IfxAudio0_TDM0_TXFSYNCO_P13_1_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_Out IfxAudio0_TDM0_TXFSYNCO_P14_9_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_Out IfxAudio0_TDM0_TXFSYNCO_P15_3_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_In    IfxAudio0_TDM0_TXMCKIA_P13_3_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_In    IfxAudio0_TDM0_TXMCKIB_P15_1_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_In    IfxAudio0_TDM0_TXMCKIC_P14_7_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_Out   IfxAudio0_TDM0_TXMCKO_P13_3_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_Out   IfxAudio0_TDM0_TXMCKO_P14_7_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_Out   IfxAudio0_TDM0_TXMCKO_P15_1_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_In    IfxAudio0_TDM0_TXSCKIA_P13_2_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_In    IfxAudio0_TDM0_TXSCKIB_P15_4_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_Out   IfxAudio0_TDM0_TXSCKO_P13_2_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_Out   IfxAudio0_TDM0_TXSCKO_P15_4_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsd_Out    IfxAudio0_TDM0_TXSDOA_P13_0_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsd_Out    IfxAudio0_TDM0_TXSDOC_P14_5_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_In  IfxAudio0_TDM1_RXFSYNCIA_P14_0_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_In  IfxAudio0_TDM1_RXFSYNCIB_P13_1_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_In  IfxAudio0_TDM1_RXFSYNCIC_P14_9_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_In  IfxAudio0_TDM1_RXFSYNCID_P15_6_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_Out IfxAudio0_TDM1_RXFSYNCO_P14_0_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_Out IfxAudio0_TDM1_RXFSYNCO_P15_6_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_In    IfxAudio0_TDM1_RXMCKIA_P14_6_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_In    IfxAudio0_TDM1_RXMCKIB_P13_3_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_In    IfxAudio0_TDM1_RXMCKIC_P14_7_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_In    IfxAudio0_TDM1_RXMCKID_P15_8_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_Out   IfxAudio0_TDM1_RXMCKO_P14_6_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxmck_Out   IfxAudio0_TDM1_RXMCKO_P15_8_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_In    IfxAudio0_TDM1_RXSCKIA_P14_1_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_In    IfxAudio0_TDM1_RXSCKIB_P13_2_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_In    IfxAudio0_TDM1_RXSCKID_P15_7_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_Out   IfxAudio0_TDM1_RXSCKO_P14_1_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_Out   IfxAudio0_TDM1_RXSCKO_P15_7_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsd_In     IfxAudio0_TDM1_RXSDIA_P15_5_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsd_In     IfxAudio0_TDM1_RXSDIB_P13_0_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsd_In     IfxAudio0_TDM1_RXSDIC_P14_5_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsd_In     IfxAudio0_TDM1_RXSDID_P14_10_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_In  IfxAudio0_TDM1_TXFSYNCIA_P14_0_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_In  IfxAudio0_TDM1_TXFSYNCIB_P15_6_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_Out IfxAudio0_TDM1_TXFSYNCO_P14_0_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_Out IfxAudio0_TDM1_TXFSYNCO_P15_6_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_In    IfxAudio0_TDM1_TXMCKIA_P14_6_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_In    IfxAudio0_TDM1_TXMCKIB_P15_8_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_Out   IfxAudio0_TDM1_TXMCKO_P14_6_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txmck_Out   IfxAudio0_TDM1_TXMCKO_P15_8_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_In    IfxAudio0_TDM1_TXSCKIA_P14_1_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_In    IfxAudio0_TDM1_TXSCKIB_P15_7_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_Out   IfxAudio0_TDM1_TXSCKO_P14_1_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_Out   IfxAudio0_TDM1_TXSCKO_P15_7_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsd_Out    IfxAudio0_TDM1_TXSDOA_P15_5_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsd_Out    IfxAudio0_TDM1_TXSDOB_P14_10_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_In  IfxAudio0_TDM2_RXFSYNCIA_P15_2_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxfsync_Out IfxAudio0_TDM2_RXFSYNCO_P15_2_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_In    IfxAudio0_TDM2_RXSCKIC_P14_8_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Rxsck_Out   IfxAudio0_TDM2_RXSCKO_P14_8_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_In  IfxAudio0_TDM2_TXFSYNCIA_P15_2_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txfsync_Out IfxAudio0_TDM2_TXFSYNCO_P15_2_OUT;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_In    IfxAudio0_TDM2_TXSCKIC_P14_8_IN;

/** \brief
 */
IFX_EXTERN IfxAudio_Txsck_Out   IfxAudio0_TDM2_TXSCKO_P14_8_OUT;

/** \addtogroup IfxLld_Audio__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxAudio_Rxfsync_In Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Rxfsync_In  *IfxAudio_Rxfsync_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXFSYNC_IN_NUM_ITEMS];

/** \brief IfxAudio_Rxfsync_Out Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Rxfsync_Out *IfxAudio_Rxfsync_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXFSYNC_OUT_NUM_ITEMS];

/** \brief IfxAudio_Rxmck_In Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Rxmck_In    *IfxAudio_Rxmck_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXMCK_IN_NUM_ITEMS];

/** \brief IfxAudio_Rxmck_Out Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Rxmck_Out   *IfxAudio_Rxmck_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXMCK_OUT_NUM_ITEMS];

/** \brief IfxAudio_Rxsck_In Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Rxsck_In    *IfxAudio_Rxsck_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXSCK_IN_NUM_ITEMS];

/** \brief IfxAudio_Rxsck_Out Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Rxsck_Out   *IfxAudio_Rxsck_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXSCK_OUT_NUM_ITEMS];

/** \brief IfxAudio_Rxsd_In Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Rxsd_In     *IfxAudio_Rxsd_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_RXSD_IN_NUM_ITEMS];

/** \brief IfxAudio_Txfsync_In Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Txfsync_In  *IfxAudio_Txfsync_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXFSYNC_IN_NUM_ITEMS];

/** \brief IfxAudio_Txfsync_Out Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Txfsync_Out *IfxAudio_Txfsync_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXFSYNC_OUT_NUM_ITEMS];

/** \brief IfxAudio_Txmck_In Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Txmck_In    *IfxAudio_Txmck_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXMCK_IN_NUM_ITEMS];

/** \brief IfxAudio_Txmck_Out Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Txmck_Out   *IfxAudio_Txmck_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXMCK_OUT_NUM_ITEMS];

/** \brief IfxAudio_Txsck_In Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Txsck_In    *IfxAudio_Txsck_In_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXSCK_IN_NUM_ITEMS];

/** \brief IfxAudio_Txsck_Out Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Txsck_Out   *IfxAudio_Txsck_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXSCK_OUT_NUM_ITEMS];

/** \brief IfxAudio_Txsd_Out Table
 */
IFX_EXTERN IFX_CONST IfxAudio_Txsd_Out    *IfxAudio_Txsd_Out_pinTable[IFXAUDIO_PINMAP_NUM_MODULES][IFXAUDIO_PINMAP_NUM_TDM_INTERFACES][IFXAUDIO_PINMAP_TXSD_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXAUDIO_PINMAP_TC48X_BGA292_COM_H */
