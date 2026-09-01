/**
 * \file IfxTriLbist.c
 * \brief LBIST  basic functionality
 *
 * \version iLLD-TC4-v2.6.0
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxTriLbist.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxTriLbist_ParameterSet IfxTriLbist_keyOnDefaultConfig = {
    .pattern = 0x1388U,
    .scanChainLength[0] = 0xA6U,
    .scanChainLength[1] = 0x4DU,
    .scanChainLength[2] = 0x35U,
    .scanChainLength[3] = 0x84U,
    .scanChainLength[4] = 0x41U,
    .scanChainLength[5] = 0x35U,
    .scanChainLength[6] = 0xA8U,
    .safetyScanChainLength[0] = 0x34U,
    .safetyScanChainLength[1] = 0x33U,
    .safetyScanChainLength[2] = 0x28U,
    .safetyScanChainLength[3] = 0x2EU,
    .safetyScanChainLength[4] = 0x28U,
    .safetyScanChainLength[5] = 0x28U,
    .safetyScanChainLength[6] = 0x32U,
    .signature[0] = 0x0AF297BU,
    .signature[1] = 0x0E616E6U,
    .signature[2] = 0x08D80F1U,
    .signature[3] = 0x0C7C5D7U,
    .signature[4] = 0x0771D59U,
    .signature[5] = 0x0BBFC68U,
    .signature[6] = 0x015E88BU,
    .keyoffEnable = IfxTriLbist_Keyoff_on,
    .freq = IfxTriLbist_Freq_div1,
    .transactionFreq = IfxTriLbist_TransactionFreq_25Mhz,
    .splitShiftSel = IfxTriLbist_SplitShiftSel_twoScanPartitions,
    .domainSelVal = 0x7FU,
    .safetySelEnable = 1U,
    .parallelExeEnable = 1U
};


IFX_CONST IfxTriLbist_ParameterSet IfxTriLbist_keyOffDefaultConfig = {
    .pattern = 0x1388U,
    .scanChainLength[0] = 0xA6U,
    .scanChainLength[1] = 0x4DU,
    .scanChainLength[2] = 0x35U,
    .scanChainLength[3] = 0x84U,
    .scanChainLength[4] = 0x41U,
    .scanChainLength[5] = 0x35U,
    .scanChainLength[6] = 0xA8U,
    .safetyScanChainLength[0] = 0x34U,
    .safetyScanChainLength[1] = 0x33U,
    .safetyScanChainLength[2] = 0x28U,
    .safetyScanChainLength[3] = 0x2EU,
    .safetyScanChainLength[4] = 0x28U,
    .safetyScanChainLength[5] = 0x28U,
    .safetyScanChainLength[6] = 0x32U,
    .signature[0] = 0x02709F2U,
    .signature[1] = 0x02DD51CU,
    .signature[2] = 0x05B1D61U,
    .signature[3] = 0x0C1DEB4U,
    .signature[4] = 0x0E6DE37U,
    .signature[5] = 0x0B5BF18U,
    .signature[6] = 0x08FA6CDU,
    .keyoffEnable = IfxTriLbist_Keyoff_off,
    .freq = IfxTriLbist_Freq_div3,
    .transactionFreq = IfxTriLbist_TransactionFreq_33Mhz,
    .splitShiftSel = IfxTriLbist_SplitShiftSel_twoScanPartitions,
    .domainSelVal = 0x7FU,
    .safetySelEnable = 0U,
    .parallelExeEnable = 0U
};
