/**
 * \file IfxPms_PinMap_TC4Dx_BGA292_COM.c
 * \brief PMS  details
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
#include "IfxPms_PinMap_TC4Dx_BGA292_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_2_OUT = {&MODULE_PMS, {&MODULE_P32, 2}, IfxPort_OutputIdx_alt6};

IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_4_OUT = {&MODULE_PMS, {&MODULE_P32, 4}, IfxPort_OutputIdx_general};

IfxPms_Pms_In       IfxPms_PMS_TESTMUX_PAD_P02_1_IN = {&MODULE_PMS, {&MODULE_P02, 1}, Ifx_RxSel_a};

IfxPms_Rtcout_Out   IfxPms_RTCOUT_P33_11_OUT = {&MODULE_PMS, {&MODULE_P33, 11}, IfxPort_OutputIdx_alt12};

/** \addtogroup IfxLld_Pms__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxPms_Dcdcsync_Out *IfxPms_Dcdcsync_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_DCDCSYNC_OUT_NUM_ITEMS] = {
    {
        &IfxPms_DCDCSYNC_P32_2_OUT,
        &IfxPms_DCDCSYNC_P32_4_OUT,
    },
};

IFX_CONST IfxPms_Pms_In       *IfxPms_Pms_In_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_PMS_IN_NUM_ITEMS] = {
    {
        &IfxPms_PMS_TESTMUX_PAD_P02_1_IN,
    },
};

IFX_CONST IfxPms_Rtcout_Out   *IfxPms_Rtcout_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_RTCOUT_OUT_NUM_ITEMS] = {
    {
        &IfxPms_RTCOUT_P33_11_OUT,
    },
};

/** \} */

#endif
