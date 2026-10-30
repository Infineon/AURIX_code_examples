/**
 * \file IfxCpu_cfg.c
 * \brief CPU on-chip implementation data
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxCpu_cfg.h" 

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap IfxCpu_cfg_indexMap[IFXCPU_NUM_MODULES] = {
    {&MODULE_CPU0, (uint32)IfxCpu_ResourceCpu_0},
#if IFXCPU_NUM_MODULES > 1
    {&MODULE_CPU1, (uint32)IfxCpu_ResourceCpu_1},
#endif
#if IFXCPU_NUM_MODULES > 2
    {&MODULE_CPU2, (uint32)IfxCpu_ResourceCpu_2},
#endif
#if IFXCPU_NUM_MODULES > 3
    {&MODULE_CPU3, (uint32)IfxCpu_ResourceCpu_3},
#endif
#if IFXCPU_NUM_MODULES > 4
    {&MODULE_CPU4, (uint32)IfxCpu_ResourceCpu_4},
    {&MODULE_CPU5, (uint32)IfxCpu_ResourceCpu_5}
#endif
};
