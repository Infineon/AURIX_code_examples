/**
 * \file IfxSmu_PinMap_TC37x_LFBGA292.c
 * \brief SMU I/O map
 * \ingroup IfxLld_Smu
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
#include "IfxSmu_PinMap_TC37x_LFBGA292.h"

IfxSmu_Fsp_Out IfxSmu_FSP0_P33_8_OUT = {&MODULE_SMU, {&MODULE_P33, 8}, IfxPort_OutputIdx_general};
IfxSmu_Fsp_Out IfxSmu_FSP1_P33_10_OUT = {&MODULE_SMU, {&MODULE_P33,10}, IfxPort_OutputIdx_general};


const IfxSmu_Fsp_Out *IfxSmu_Fsp_Out_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_FSP_OUT_NUM_ITEMS] = {
    {
        &IfxSmu_FSP0_P33_8_OUT,
        &IfxSmu_FSP1_P33_10_OUT
    }
};
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
