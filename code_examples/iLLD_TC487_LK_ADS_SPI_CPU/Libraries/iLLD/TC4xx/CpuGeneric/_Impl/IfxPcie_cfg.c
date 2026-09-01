/**
 * \file IfxPcie_cfg.c
 * \brief PCIE on-chip implementation data
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

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC45X)
#include "IfxPcie_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

#ifdef IFXPCIE_CFG_MAX_NUM_MODULES
IFX_CONST IfxPcie_MemoryLimits IfxPcie_cfg_memoryMap[IFXPCIE_CFG_MAX_NUM_MODULES] = {
    {            },
    {0xEC000000u, 0xEFFFFFFFu}
};

#else
IFX_CONST IfxPcie_MemoryLimits IfxPcie_cfg_memoryMap[IFXPCIE_CFG_NUM_MODULES] = {
    {0xFC000000u, 0xFFFFFFFFu},
    {0xEC000000u, 0xEFFFFFFFu},
};
#endif /* #ifdef IFXPCIE_CFG_MAX_NUM_MODULES */

IFX_CONST IfxModule_IndexMap   IfxPcie_cfg_pcieIndexMap[IFXPCIE_CFG_NUM_MODULES] = {
#ifndef DEVICE_TC45X
    {&MODULE_PCIE0_DSP, (uint32)IfxPcie_Index_0},
#endif /* #ifndef DEVICE_TC45X */
    {&MODULE_PCIE1_DSP, (uint32)IfxPcie_Index_1},
};

#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif

