/**
 * \file IfxPort_cfg_TC37x.c
 * \brief PORT on-chip implementation data
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
#if defined DEVICE_TC37X

#include "IfxPort_cfg_TC37x.h" 

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxPort_Esr_Masks  IfxPort_cfg_esrMasks[IFXPORT_NUM_MODULES] = {
    {&MODULE_P00, 0x0000FFFFUL},    // Port 00
    {&MODULE_P01, 0x0000FFFFUL},    // Port 01
    {&MODULE_P02, 0x0000FFFFUL},    // Port 02
    {&MODULE_P10, 0x0000FFFFUL},    // Port 10
    {&MODULE_P11, 0x0000FFFFUL},    // Port 11
    {&MODULE_P12, 0x0000FFFFUL},    // Port 12
    {&MODULE_P13, 0x0000FFFFUL},    // Port 13
    {&MODULE_P14, 0x0000FFFFUL},    // Port 14
    {&MODULE_P15, 0x0000FFFFUL},    // Port 15
    {&MODULE_P20, 0x0000FFFFUL},    // Port 20
    {&MODULE_P21, 0x0000FFFFUL},    // Port 21
    {&MODULE_P22, 0x0000FFFFUL},    // Port 22
    {&MODULE_P23, 0x0000FFFFUL},    // Port 23
    {&MODULE_P32, 0x0000FFFFUL},    // Port 32
    {&MODULE_P33, 0x0000FFFFUL},    // Port 33
    {&MODULE_P34, 0x0000FFFFUL},    // Port 34
    {&MODULE_P40, 0x0000FFFFUL},    // Port 40
};

IFX_CONST IfxModule_IndexMap IfxPort_cfg_indexMap[IFXPORT_NUM_MODULES] = {
    {&MODULE_P00, IfxPort_Index_00},     // Port 00
    {&MODULE_P01, IfxPort_Index_01},     // Port 01
    {&MODULE_P02, IfxPort_Index_02},     // Port 02
    {&MODULE_P10, IfxPort_Index_10},     // Port 10
    {&MODULE_P11, IfxPort_Index_11},     // Port 11
    {&MODULE_P12, IfxPort_Index_12},     // Port 12
    {&MODULE_P13, IfxPort_Index_13},     // Port 13
    {&MODULE_P14, IfxPort_Index_14},     // Port 14
    {&MODULE_P15, IfxPort_Index_15},     // Port 15
    {&MODULE_P20, IfxPort_Index_20},     // Port 20
    {&MODULE_P21, IfxPort_Index_21},     // Port 21
    {&MODULE_P22, IfxPort_Index_22},     // Port 22
    {&MODULE_P23, IfxPort_Index_23},     // Port 23
    {&MODULE_P32, IfxPort_Index_32},     // Port 32
    {&MODULE_P33, IfxPort_Index_33},     // Port 33
    {&MODULE_P34, IfxPort_Index_34},     // Port 34
    {&MODULE_P40, IfxPort_Index_40},     // Port 40
};
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
