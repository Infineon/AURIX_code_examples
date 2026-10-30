/**
 * \file IfxDmu_PinMap_TC37x_516.c
 * \brief DMU I/O map
 * \ingroup IfxLld_Dmu
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
#include "IfxDmu_PinMap_TC37x_516.h"

IfxDmu_Fdest_In IfxDmu_FDEST_P21_0_IN = {&MODULE_DMU, {&MODULE_P21, 0}, Ifx_RxSel_a};


const IfxDmu_Fdest_In *IfxDmu_Fdest_In_pinTable[IFXDMU_PINMAP_NUM_MODULES][IFXDMU_PINMAP_NUM_0S][IFXDMU_PINMAP_FDEST_IN_NUM_ITEMS] = {
    {
        {
            &IfxDmu_FDEST_P21_0_IN
        }
    }
};
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
