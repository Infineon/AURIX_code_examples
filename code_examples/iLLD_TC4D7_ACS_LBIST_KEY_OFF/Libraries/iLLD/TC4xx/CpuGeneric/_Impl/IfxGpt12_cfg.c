/**
 * \file IfxGpt12_cfg.c
 * \brief GPT12 on-chip implementation data
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

#if !defined(DEVICE_TC4DX) && !defined(DEVICE_TC4ZX)
#include "IfxGpt12_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap IfxGpt12_cfg_indexMap[IFXGPT12_NUM_MODULES] =
{    {&MODULE_GPT120, (uint32)IfxGpt12_Index_0},
     {&MODULE_GPT121, (uint32)IfxGpt12_Index_1},
#if (IFXGPT12_NUM_MODULES > 2)
     {&MODULE_GPT122, (uint32)IfxGpt12_Index_2},
     {&MODULE_GPT123, (uint32)IfxGpt12_Index_3},
#endif
#if (IFXGPT12_NUM_MODULES > 4)
     {&MODULE_GPT124, (uint32)IfxGpt12_Index_4},
     {&MODULE_GPT125, (uint32)IfxGpt12_Index_5},
     {&MODULE_GPT126, (uint32)IfxGpt12_Index_6},
     {&MODULE_GPT127, (uint32)IfxGpt12_Index_7},
     {&MODULE_GPT128, (uint32)IfxGpt12_Index_8},
     {&MODULE_GPT129, (uint32)IfxGpt12_Index_9},
     {&MODULE_GPT1210,(uint32)IfxGpt12_Index_10},
     {&MODULE_GPT1211,(uint32)IfxGpt12_Index_11}
#endif /* #if (IFXGPT12_NUM_MODULES > 4) */
	 };
	 
#endif /* #if !defined(DEVICE_TC4DX) && !defined(DEVICE_TC4ZX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
