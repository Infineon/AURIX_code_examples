/**
 * \file IfxScuLbist.c
 * \brief SCU  basic functionality
 *
 * \version iLLD_1_22_0
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxScuLbist.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxScuLbist_ParameterSet IfxScuLbist_defaultConfig = {
#ifndef IFX_CFG_LBIST_BODY_ENABLED
#ifndef IFX_CFG_LBIST_CFG_B_ENABLED
    .application     = IfxScuLbist_Application_pt,
    .freq            = IfxScuLbist_Freq_div6,
    .splitShiftSel   = IfxScuLbist_SplitShiftSel_fourScanPartitions,
    .seed            = IFXSCULBIST_CFG_SEED,
    .pattern         = IFXSCULBIST_CFG_PATTERN_A,
    .scanChainLength = IFXSCULBIST_CFG_SCANCHAINLENGTH,
    .signature       = IFXSCULBIST_CFG_SIGNATURE_A,
#else
    .application     = IfxScuLbist_Application_pt,
    .freq            = IfxScuLbist_Freq_div6,
    .splitShiftSel   = IfxScuLbist_SplitShiftSel_fourScanPartitions,
    .seed            = IFXSCULBIST_CFG_SEED,
    .pattern         = IFXSCULBIST_CFG_PATTERN_B,
    .scanChainLength = IFXSCULBIST_CFG_SCANCHAINLENGTH,
    .signature       = IFXSCULBIST_CFG_SIGNATURE_B,
#endif
#else
#ifndef IFX_CFG_LBIST_CFG_B_ENABLED
    .application     = IfxScuLbist_Application_body,
    .freq            = IfxScuLbist_Freq_div6,
    .splitShiftSel   = IfxScuLbist_SplitShiftSel_fourScanPartitions,
    .seed            = IFXSCULBIST_CFG_SEED,
    .pattern         = IFXSCULBIST_CFG_PATTERN_A,
    .scanChainLength = IFXSCULBIST_CFG_SCANCHAINLENGTH,
    .signature       = IFXSCULBIST_CFG_SIGNATURE_A,
#else
    .application     = IfxScuLbist_Application_body,
    .freq            = IfxScuLbist_Freq_div6,
    .splitShiftSel   = IfxScuLbist_SplitShiftSel_fourScanPartitions,
    .seed            = IFXSCULBIST_CFG_SEED,
    .pattern         = IFXSCULBIST_CFG_PATTERN_B,
    .scanChainLength = IFXSCULBIST_CFG_SCANCHAINLENGTH,
    .signature       = IFXSCULBIST_CFG_SIGNATURE_B,
#endif
#endif /* #ifndef IFX_CFG_LBIST_BODY_ENABLED */
};
