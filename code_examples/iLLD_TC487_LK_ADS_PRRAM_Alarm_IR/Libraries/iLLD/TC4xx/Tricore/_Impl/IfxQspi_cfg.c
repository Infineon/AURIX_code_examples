/**
 * \file IfxQspi_cfg.c
 * \brief QSPI on-chip implementation data
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

#include "IfxQspi_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap IfxQspi_cfg_indexMap[IFXQSPI_NUM_MODULES] = {
    {&MODULE_QSPI0, (uint32)IfxQspi_Index_0},
    {&MODULE_QSPI1, (uint32)IfxQspi_Index_1},
    {&MODULE_QSPI2, (uint32)IfxQspi_Index_2},
    {&MODULE_QSPI3, (uint32)IfxQspi_Index_3},
#if (IFXQSPI_NUM_MODULES > 4)
    {&MODULE_QSPI4, (uint32)IfxQspi_Index_4},
    {&MODULE_QSPI5, (uint32)IfxQspi_Index_5},
#endif /* #if (IFXQSPI_NUM_MODULES > 4) */
#if (IFXQSPI_NUM_MODULES > 6)
    {&MODULE_QSPI6, (uint32)IfxQspi_Index_6},
    {&MODULE_QSPI7, (uint32)IfxQspi_Index_7}
#endif /* #if (IFXQSPI_NUM_MODULES > 6) */
};
