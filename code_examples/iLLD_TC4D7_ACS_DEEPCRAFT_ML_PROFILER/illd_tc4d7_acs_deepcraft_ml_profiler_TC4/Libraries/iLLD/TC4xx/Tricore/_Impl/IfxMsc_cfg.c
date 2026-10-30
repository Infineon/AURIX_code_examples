/**
 * \file IfxMsc_cfg.c
 * \brief MSC on-chip implementation data
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

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC48XAA) && !defined(DEVICE_TC48X) && !defined(DEVICE_TC45X) && !defined(DEVICE_TC44X)

#include "IfxMsc_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap IfxMsc_cfg_indexMap[IFXMSC_NUM_MODULES] = {
    {&MODULE_MSC0, (uint32)IfxMsc_Index_0},
#if (IFXMSC_NUM_MODULES > 1)
    {&MODULE_MSC1, (uint32)IfxMsc_Index_1},
#endif /* #if (IFXMSC_NUM_MODULES > 1) */
#if (IFXMSC_NUM_MODULES > 2)
    {&MODULE_MSC2, (uint32)IfxMsc_Index_2}
#endif /*#if (IFXMSC_NUM_MODULES > 2) */
};

#endif /* #if !defined(DEVICE_TC48XAA) && !defined(DEVICE_TC48X) && !defined(DEVICE_TC45X) && !defined(DEVICE_TC44X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
