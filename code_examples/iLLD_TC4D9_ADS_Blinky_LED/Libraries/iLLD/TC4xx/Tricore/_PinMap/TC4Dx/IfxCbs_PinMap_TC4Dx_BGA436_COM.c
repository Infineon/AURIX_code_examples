/**
 * \file IfxCbs_PinMap_TC4Dx_BGA436_COM.c
 * \brief CBS  details
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
#if defined(DEVICE_TC4DX) && defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "IfxCbs_PinMap_TC4Dx_BGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxCbs_Tgi_In  IfxCbs_TGI0_P20_0_IN = {&MODULE_CBS, (IfxCbs_TriggerPin)0, {&MODULE_P20, 0}, Ifx_RxSel_a};

IfxCbs_Tgi_In  IfxCbs_TGI1_P20_1_IN = {&MODULE_CBS, (IfxCbs_TriggerPin)1, {&MODULE_P20, 1}, Ifx_RxSel_a};

IfxCbs_Tgi_In  IfxCbs_TGI2_P21_6_IN = {&MODULE_CBS, (IfxCbs_TriggerPin)2, {&MODULE_P21, 6}, Ifx_RxSel_a};

IfxCbs_Tgi_In  IfxCbs_TGI3_P21_7_IN = {&MODULE_CBS, (IfxCbs_TriggerPin)3, {&MODULE_P21, 7}, Ifx_RxSel_a};

IfxCbs_Tgi_In  IfxCbs_TGI4_P32_6_IN = {&MODULE_CBS, (IfxCbs_TriggerPin)4, {&MODULE_P32, 6}, Ifx_RxSel_a};

IfxCbs_Tgi_In  IfxCbs_TGI5_P32_7_IN = {&MODULE_CBS, (IfxCbs_TriggerPin)5, {&MODULE_P32, 7}, Ifx_RxSel_a};

IfxCbs_Tgi_In  IfxCbs_TGI6_P33_14_IN = {&MODULE_CBS, (IfxCbs_TriggerPin)6, {&MODULE_P33, 14}, Ifx_RxSel_a};

IfxCbs_Tgi_In  IfxCbs_TGI7_P33_15_IN = {&MODULE_CBS, (IfxCbs_TriggerPin)7, {&MODULE_P33, 15}, Ifx_RxSel_a};

IfxCbs_Tgo_Out IfxCbs_TGO0_P20_0_OUT = {&MODULE_CBS, (IfxCbs_TriggerPin)0, {&MODULE_P20, 0}, IfxPort_OutputIdx_general};

IfxCbs_Tgo_Out IfxCbs_TGO1_P20_1_OUT = {&MODULE_CBS, (IfxCbs_TriggerPin)1, {&MODULE_P20, 1}, IfxPort_OutputIdx_general};

IfxCbs_Tgo_Out IfxCbs_TGO2_P21_6_OUT = {&MODULE_CBS, (IfxCbs_TriggerPin)2, {&MODULE_P21, 6}, IfxPort_OutputIdx_general};

IfxCbs_Tgo_Out IfxCbs_TGO3_P21_7_OUT = {&MODULE_CBS, (IfxCbs_TriggerPin)3, {&MODULE_P21, 7}, IfxPort_OutputIdx_general};

IfxCbs_Tgo_Out IfxCbs_TGO4_P32_6_OUT = {&MODULE_CBS, (IfxCbs_TriggerPin)4, {&MODULE_P32, 6}, IfxPort_OutputIdx_general};

IfxCbs_Tgo_Out IfxCbs_TGO5_P32_7_OUT = {&MODULE_CBS, (IfxCbs_TriggerPin)5, {&MODULE_P32, 7}, IfxPort_OutputIdx_general};

IfxCbs_Tgo_Out IfxCbs_TGO6_P33_14_OUT = {&MODULE_CBS, (IfxCbs_TriggerPin)6, {&MODULE_P33, 14}, IfxPort_OutputIdx_general};

IfxCbs_Tgo_Out IfxCbs_TGO7_P33_15_OUT = {&MODULE_CBS, (IfxCbs_TriggerPin)7, {&MODULE_P33, 15}, IfxPort_OutputIdx_general};

/** \addtogroup IfxLld_Cbs__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxCbs_Tgi_In  *IfxCbs_Tgi_In_pinTable[IFXCBS_PINMAP_NUM_MODULES][IFXCBS_PINMAP_NUM_CHANNELS][IFXCBS_PINMAP_TGI_IN_NUM_ITEMS] = {
    {
        {
            &IfxCbs_TGI0_P20_0_IN,
        },
        {
            &IfxCbs_TGI1_P20_1_IN,
        },
        {
            &IfxCbs_TGI2_P21_6_IN,
        },
        {
            &IfxCbs_TGI3_P21_7_IN,
        },
        {
            &IfxCbs_TGI4_P32_6_IN,
        },
        {
            &IfxCbs_TGI5_P32_7_IN,
        },
        {
            &IfxCbs_TGI6_P33_14_IN,
        },
        {
            &IfxCbs_TGI7_P33_15_IN,
        },
    },
};

IFX_CONST IfxCbs_Tgo_Out *IfxCbs_Tgo_Out_pinTable[IFXCBS_PINMAP_NUM_MODULES][IFXCBS_PINMAP_NUM_CHANNELS][IFXCBS_PINMAP_TGO_OUT_NUM_ITEMS] = {
    {
        {
            &IfxCbs_TGO0_P20_0_OUT,
        },
        {
            &IfxCbs_TGO1_P20_1_OUT,
        },
        {
            &IfxCbs_TGO2_P21_6_OUT,
        },
        {
            &IfxCbs_TGO3_P21_7_OUT,
        },
        {
            &IfxCbs_TGO4_P32_6_OUT,
        },
        {
            &IfxCbs_TGO5_P32_7_OUT,
        },
        {
            &IfxCbs_TGO6_P33_14_OUT,
        },
        {
            &IfxCbs_TGO7_P33_15_OUT,
        },
    },
};

/** \} */

#endif
