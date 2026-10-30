/**
 * \file IfxCan_cfg.c
 * \brief CAN on-chip implementation data
 *
 * \version iLLD_1_22_0
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

#include "IfxCan_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap IfxCan_cfg_indexMap[IFXCAN_NUM_MODULES] = {
    {&MODULE_CAN0, (uint32)IfxCan_Index_0},    
#if IFXCAN_NUM_MODULES > 1	                    
    {&MODULE_CAN1, (uint32)IfxCan_Index_1},     
#endif
#if IFXCAN_NUM_MODULES > 2                      
    {&MODULE_CAN2, (uint32)IfxCan_Index_2},
#endif
#if IFXCAN_NUM_MODULES > 3	                    
	{&MODULE_CAN3, (uint32)IfxCan_Index_3},
    {&MODULE_CAN4, (uint32)IfxCan_Index_4}
#endif
};
