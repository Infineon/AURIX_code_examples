/**
 * \file IfxMsc_PinMap_TC4Dx_BGA436_COM.h
 * \brief MSC  details
 * \ingroup IfxLld_Msc
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
 * Version: MC_ACE_A3G_HWA_Ports/Unknown
 * Document: TC4Dx_Pin_Assignment_v0.45_LETH_patched.xls
 *
 * \defgroup IfxLld_Msc_
 * \ingroup IfxLld_Msc
 * \defgroup IfxLld_Msc__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Msc_
 * \defgroup IfxLld_Msc__PinTables PinTables
 * \ingroup IfxLld_Msc_
 */

#ifndef IFXMSC_PINMAP_TC4DX_BGA436_COM_H
#define IFXMSC_PINMAP_TC4DX_BGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxMsc_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXMSC_PINMAP_NUM_MODULES        1

#define IFXMSC_PINMAP_FCLN_OUT_NUM_ITEMS 1

#define IFXMSC_PINMAP_FCLP_OUT_NUM_ITEMS 2

#define IFXMSC_PINMAP_INJ_IN_NUM_ITEMS   2

#define IFXMSC_PINMAP_SDI_IN_NUM_ITEMS   7

#define IFXMSC_PINMAP_SON_OUT_NUM_ITEMS  1

#define IFXMSC_PINMAP_SOP_OUT_NUM_ITEMS  1

#define IFXMSC_PINMAP_NUM_TARGETS        2

#define IFXMSC_PINMAP_EN_OUT_NUM_ITEMS   7

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN0_P10_10_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN0_P10_2_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN0_P10_3_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN0_P10_4_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN0_P14_10_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN0_P14_14_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN0_P15_5_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN1_P10_1_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN1_P10_9_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN1_P13_0_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN1_P14_13_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN1_P14_9_OUT;

/** \brief Chip Select
 */
IFX_EXTERN IfxMsc_En_Out   IfxMsc0_EN1_P15_3_OUT;

/** \brief Shift-clock inverted part of the differential signal
 */
IFX_EXTERN IfxMsc_Fcln_Out IfxMsc0_FCLN_P13_0_OUT;

/** \brief Shift-clock direct part of the differential signal
 */
IFX_EXTERN IfxMsc_Fclp_Out IfxMsc0_FCLP_P13_1_OUT;

/** \brief Shift-clock direct part of the differential signal
 */
IFX_EXTERN IfxMsc_Fclp_Out IfxMsc0_FCLP_P13_2_OUT;

/** \brief Injection signal from port
 */
IFX_EXTERN IfxMsc_Inj_In   IfxMsc0_INJ0_P00_0_IN;

/** \brief Injection signal from port
 */
IFX_EXTERN IfxMsc_Inj_In   IfxMsc0_INJ1_P10_5_IN;

/** \brief Upstream assynchronous input signal
 */
IFX_EXTERN IfxMsc_Sdi_In   IfxMsc0_SDI1_P10_2_IN;

/** \brief Upstream assynchronous input signal
 */
IFX_EXTERN IfxMsc_Sdi_In   IfxMsc0_SDI2_P14_3_IN;

/** \brief Upstream assynchronous input signal
 */
IFX_EXTERN IfxMsc_Sdi_In   IfxMsc0_SDI4_P14_11_IN;

/** \brief Upstream assynchronous input signal
 */
IFX_EXTERN IfxMsc_Sdi_In   IfxMsc0_SDI5_P10_3_IN;

/** \brief Upstream assynchronous input signal
 */
IFX_EXTERN IfxMsc_Sdi_In   IfxMsc0_SDI6_P10_14_IN;

/** \brief Data output - inverted part of the differential signal
 */
IFX_EXTERN IfxMsc_Son_Out  IfxMsc0_SON_P13_2_OUT;

/** \brief Data output - direct part of the differential signal
 */
IFX_EXTERN IfxMsc_Sop_Out  IfxMsc0_SOP_P13_3_OUT;

/** \addtogroup IfxLld_Msc__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxMsc_En_Out Table
 */
IFX_EXTERN IFX_CONST IfxMsc_En_Out   *IfxMsc_En_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_NUM_TARGETS][IFXMSC_PINMAP_EN_OUT_NUM_ITEMS];

/** \brief IfxMsc_Fcln_Out Table
 */
IFX_EXTERN IFX_CONST IfxMsc_Fcln_Out *IfxMsc_Fcln_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_FCLN_OUT_NUM_ITEMS];

/** \brief IfxMsc_Fclp_Out Table
 */
IFX_EXTERN IFX_CONST IfxMsc_Fclp_Out *IfxMsc_Fclp_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_FCLP_OUT_NUM_ITEMS];

/** \brief IfxMsc_Inj_In Table
 */
IFX_EXTERN IFX_CONST IfxMsc_Inj_In   *IfxMsc_Inj_In_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_INJ_IN_NUM_ITEMS];

/** \brief IfxMsc_Sdi_In Table
 */
IFX_EXTERN IFX_CONST IfxMsc_Sdi_In   *IfxMsc_Sdi_In_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_SDI_IN_NUM_ITEMS];

/** \brief IfxMsc_Son_Out Table
 */
IFX_EXTERN IFX_CONST IfxMsc_Son_Out  *IfxMsc_Son_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_SON_OUT_NUM_ITEMS];

/** \brief IfxMsc_Sop_Out Table
 */
IFX_EXTERN IFX_CONST IfxMsc_Sop_Out  *IfxMsc_Sop_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_SOP_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXMSC_PINMAP_TC4DX_BGA436_COM_H */
