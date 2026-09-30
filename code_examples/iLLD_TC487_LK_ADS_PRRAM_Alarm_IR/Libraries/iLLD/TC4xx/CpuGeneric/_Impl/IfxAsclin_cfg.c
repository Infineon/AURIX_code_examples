/**
 * \file IfxAsclin_cfg.c
 * \brief ASCLIN on-chip implementation data
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

#include "IfxAsclin_cfg.h"
/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxModule_IndexMap IfxAsclin_cfg_indexMap[IFXASCLIN_NUM_MODULES] = {
    {&MODULE_ASCLIN0, (uint32)IfxAsclin_Index_0},
    {&MODULE_ASCLIN1, (uint32)IfxAsclin_Index_1},
#if (IFXASCLIN_NUM_MODULES > 2)
    {&MODULE_ASCLIN2, (uint32)IfxAsclin_Index_2},
    {&MODULE_ASCLIN3, (uint32)IfxAsclin_Index_3},
    {&MODULE_ASCLIN4, (uint32)IfxAsclin_Index_4},
    {&MODULE_ASCLIN5, (uint32)IfxAsclin_Index_5},
    {&MODULE_ASCLIN6, (uint32)IfxAsclin_Index_6},
    {&MODULE_ASCLIN7, (uint32)IfxAsclin_Index_7},
#endif
#if (IFXASCLIN_NUM_MODULES > 8)
    {&MODULE_ASCLIN8, (uint32)IfxAsclin_Index_8},
    {&MODULE_ASCLIN9, (uint32)IfxAsclin_Index_9},
    {&MODULE_ASCLIN10,(uint32)IfxAsclin_Index_10},
    {&MODULE_ASCLIN11,(uint32)IfxAsclin_Index_11},
    {&MODULE_ASCLIN12,(uint32)IfxAsclin_Index_12},
    {&MODULE_ASCLIN13,(uint32)IfxAsclin_Index_13},
    {&MODULE_ASCLIN14,(uint32)IfxAsclin_Index_14},
    {&MODULE_ASCLIN15,(uint32)IfxAsclin_Index_15},
    {&MODULE_ASCLIN16,(uint32)IfxAsclin_Index_16},
    {&MODULE_ASCLIN17,(uint32)IfxAsclin_Index_17},
    {&MODULE_ASCLIN18,(uint32)IfxAsclin_Index_18},
    {&MODULE_ASCLIN19,(uint32)IfxAsclin_Index_19},
#endif
#if (IFXASCLIN_NUM_MODULES > 20)
    {&MODULE_ASCLIN20,(uint32)IfxAsclin_Index_20},
    {&MODULE_ASCLIN21,(uint32)IfxAsclin_Index_21},
    {&MODULE_ASCLIN22,(uint32)IfxAsclin_Index_22},
    {&MODULE_ASCLIN23,(uint32)IfxAsclin_Index_23},
#endif
#if (IFXASCLIN_NUM_MODULES > 24)
    {&MODULE_ASCLIN24,(uint32)IfxAsclin_Index_24},
    {&MODULE_ASCLIN25,(uint32)IfxAsclin_Index_25},
    {&MODULE_ASCLIN26,(uint32)IfxAsclin_Index_26},
    {&MODULE_ASCLIN27,(uint32)IfxAsclin_Index_27}
#endif
};
