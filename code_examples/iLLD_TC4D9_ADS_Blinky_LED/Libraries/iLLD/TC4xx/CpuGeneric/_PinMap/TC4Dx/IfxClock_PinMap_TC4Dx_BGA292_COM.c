/**
 * \file IfxClock_PinMap_TC4Dx_BGA292_COM.c
 * \brief CLOCK  details
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
#if defined(DEVICE_TC4DX) && defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "IfxClock_PinMap_TC4Dx_BGA292_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxClock_Sysclk_In  IfxClock_CLKA_SYSCLK_P20_0_IN = {&MODULE_CLOCK, {&MODULE_P20, 0}, Ifx_RxSel_a};

IfxClock_Extclk_Out IfxClock_EXTCLK0_P23_1_OUT = {&MODULE_CLOCK, 0, {&MODULE_P23, 1}, IfxPort_OutputIdx_alt6};

IfxClock_Extclk_Out IfxClock_EXTCLK1_P16_14_OUT = {&MODULE_CLOCK, 1, {&MODULE_P16, 14}, IfxPort_OutputIdx_alt6};

IfxClock_Extclk_Out IfxClock_EXTCLK1_P32_4_OUT = {&MODULE_CLOCK, 1, {&MODULE_P32, 4}, IfxPort_OutputIdx_alt6};

/** \addtogroup IfxLld_Clock__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxClock_Extclk_Out *IfxClock_Extclk_Out_pinTable[IFXCLOCK_PINMAP_NUM_MODULES][IFXCLOCK_PINMAP_NUM_EXTCLK_OUTPUTS][IFXCLOCK_PINMAP_EXTCLK_OUT_NUM_ITEMS] = {
    {
        {
            &IfxClock_EXTCLK0_P23_1_OUT,
            NULL_PTR,
            NULL_PTR,
        },
        {
            &IfxClock_EXTCLK1_P16_14_OUT,
            &IfxClock_EXTCLK1_P32_4_OUT,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxClock_Sysclk_In  *IfxClock_Sysclk_In_pinTable[IFXCLOCK_PINMAP_NUM_MODULES][IFXCLOCK_PINMAP_SYSCLK_IN_NUM_ITEMS] = {
    {
        &IfxClock_CLKA_SYSCLK_P20_0_IN,
    },
};

/** \} */

#endif
