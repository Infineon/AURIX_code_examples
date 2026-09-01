/**
 * \file IfxDmur_PinMap_TC48x_BGA292_STD.c
 * \brief DMUR  details
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
#if defined(DEVICE_TC48X) && defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "IfxDmur_PinMap_TC48x_BGA292_STD.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxDmur_Fdest_In IfxDmur_FDEST_P21_0_IN = {&MODULE_DMUR0, {&MODULE_P21, 0}, Ifx_RxSel_a};

/** \addtogroup IfxLld_Dmur__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxDmur_Fdest_In *IfxDmur_Fdest_In_pinTable[IFXDMUR_PINMAP_NUM_MODULES][IFXDMUR_PINMAP_FDEST_IN_NUM_ITEMS] = {
    {
        &IfxDmur_FDEST_P21_0_IN,
    },
};

/** \} */

#endif
