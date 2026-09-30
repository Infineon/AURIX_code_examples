/**
 * \file IfxLeth_cfg.c
 * \brief LETH on-chip implementation data
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
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

#include "IfxLeth_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap IfxLeth_cfg_indexMap[IFXLETH_NUM_MODULES] = {
#ifndef DEVICE_TC45X
    {&MODULE_LETH0, (uint32)IfxLeth_Index_0},
#endif /* #ifndef DEVICE_TC45X */
#if (IFXLETH_NUM_MODULES > 1) || defined(DEVICE_TC45X)
	{&MODULE_LETH1, (uint32)IfxLeth_Index_1}
#endif /* #if (IFXLETH_NUM_MODULES > 1) || defined(DEVICE_TC45X) */
};

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
