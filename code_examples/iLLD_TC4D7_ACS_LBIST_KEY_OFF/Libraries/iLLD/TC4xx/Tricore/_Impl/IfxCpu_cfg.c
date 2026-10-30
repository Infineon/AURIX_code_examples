/**
 * \file IfxCpu_cfg.c
 * \brief CPU on-chip implementation data
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

#include "IfxCpu_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap IfxCpu_cfg_indexMap[IFXCPU_NUM_MODULES] =
{    {&MODULE_CPU0,  (uint32)IfxCpu_Index_0},
     {&MODULE_CPU1,  (uint32)IfxCpu_Index_1},
#if (IFXCPU_NUM_MODULES > 3)
     {&MODULE_CPU2,  (uint32)IfxCpu_Index_2},
#endif /* #if (IFXCPU_NUM_MODULES > 3) */
#if (IFXCPU_NUM_MODULES > 4)
     {&MODULE_CPU3,  (uint32)IfxCpu_Index_3},
#endif /* #if (IFXCPU_NUM_MODULES > 4) */
#if (IFXCPU_NUM_MODULES > 5)
     {&MODULE_CPU4,  (uint32)IfxCpu_Index_4},
#endif /* #if (IFXCPU_NUM_MODULES > 5) */
#if (IFXCPU_NUM_MODULES > 6)
     {&MODULE_CPU5,  (uint32)IfxCpu_Index_5},
#endif /* #if (IFXCPU_NUM_MODULES > 6) */
     {&MODULE_CPUCS, (uint32)IfxCpu_Index_6}};
