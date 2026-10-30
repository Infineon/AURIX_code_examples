/**
 * \file IfxEmem_cfg.c
 * \brief EMEM on-chip implementation data
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
#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif 
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif
#if defined(DEVICE_TC33XED) || defined(DEVICE_TC35X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC39XB)
#include "IfxEmem_cfg.h" 

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap IfxEmem_cfg_indexMap[IFXEMEM_NUM_MPU_MODULES] = {
    {&MODULE_EMEMMPU0, (uint32)IfxEmem_MpuIndex_0},
#if IFXEMEM_NUM_MPU_MODULES > 1
    {&MODULE_EMEMMPU1, (uint32)IfxEmem_MpuIndex_1},
#endif
#if IFXEMEM_NUM_MPU_MODULES > 2
    {&MODULE_EMEMMPU2, (uint32)IfxEmem_MpuIndex_2},
#endif
#if IFXEMEM_NUM_MPU_MODULES > 3
    {&MODULE_EMEMMPU3, (uint32)IfxEmem_MpuIndex_3}
#endif
};

#endif /* #if defined(DEVICE_TC33XED) || defined(DEVICE_TC35X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC39XB */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
