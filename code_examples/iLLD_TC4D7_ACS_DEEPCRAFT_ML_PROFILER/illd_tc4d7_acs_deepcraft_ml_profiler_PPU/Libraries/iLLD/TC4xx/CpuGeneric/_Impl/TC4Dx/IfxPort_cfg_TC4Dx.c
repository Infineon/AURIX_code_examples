/**
 * \file IfxPort_cfg_TC4Dx.c
 * \brief PORT on-chip implementation data
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508
#endif
#if defined(__ghs__)
#pragma ghs nowarning 96
#endif

#if defined(DEVICE_TC4DX)
#include "_Impl/IfxPort_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxPort_Esr_Masks  IfxPort_cfg_esrMasks[IFXPORT_NUM_MODULES] = {
    {&MODULE_P00, 0x0000FFFFUL},    // Port 00
    {&MODULE_P01, 0x0000FFFFUL},    // Port 01
    {&MODULE_P02, 0x0000FFFFUL},    // Port 02
    {&MODULE_P03, 0x0000FFFFUL},    // Port 03
    {&MODULE_P04, 0x0000FFFFUL},    // Port 04
    {&MODULE_P10, 0x0000FFFFUL},    // Port 10
    {&MODULE_P13, 0x0000FFFFUL},    // Port 13
    {&MODULE_P14, 0x0000FFFFUL},    // Port 14
    {&MODULE_P15, 0x0000FFFFUL},    // Port 15
    {&MODULE_P16, 0x0000FFFFUL},    // Port 16
    {&MODULE_P20, 0x0000FFFFUL},    // Port 20
    {&MODULE_P21, 0x0000FFFFUL},    // Port 21
    {&MODULE_P22, 0x0000FFFFUL},    // Port 22
    {&MODULE_P23, 0x0000FFFFUL},    // Port 23
    {&MODULE_P25, 0x0000FFFFUL},    // Port 25
    {&MODULE_P30, 0x0000FFFFUL},    // Port 30
    {&MODULE_P31, 0x0000FFFFUL},    // Port 31
    {&MODULE_P32, 0x0000FFFFUL},    // Port 32
    {&MODULE_P33, 0x0000FFFFUL},    // Port 33
    {&MODULE_P34, 0x0000FFFFUL},    // Port 34
    {&MODULE_P35, 0x0000FFFFUL},    // Port 35
    {&MODULE_P40, 0x0000FFFFUL},    // Port 40
};

IFX_CONST IfxModule_IndexMap IfxPort_cfg_indexMap[IFXPORT_NUM_MODULES] = {
    {&MODULE_P00, IfxPort_Index_00},     // Port 00
    {&MODULE_P01, IfxPort_Index_01},     // Port 01
    {&MODULE_P02, IfxPort_Index_02},     // Port 02
    {&MODULE_P03, IfxPort_Index_03},     // Port 03
    {&MODULE_P04, IfxPort_Index_04},     // Port 04
    {&MODULE_P10, IfxPort_Index_10},     // Port 10
    {&MODULE_P13, IfxPort_Index_13},     // Port 13
    {&MODULE_P14, IfxPort_Index_14},     // Port 14
    {&MODULE_P15, IfxPort_Index_15},     // Port 15
    {&MODULE_P16, IfxPort_Index_16},     // Port 16
    {&MODULE_P20, IfxPort_Index_20},     // Port 20
    {&MODULE_P21, IfxPort_Index_21},     // Port 21
    {&MODULE_P22, IfxPort_Index_22},     // Port 22
    {&MODULE_P23, IfxPort_Index_23},     // Port 23
    {&MODULE_P25, IfxPort_Index_25},     // Port 25
    {&MODULE_P30, IfxPort_Index_30},     // Port 30
    {&MODULE_P31, IfxPort_Index_31},     // Port 31
    {&MODULE_P32, IfxPort_Index_32},     // Port 32
    {&MODULE_P33, IfxPort_Index_33},     // Port 33
    {&MODULE_P34, IfxPort_Index_34},     // Port 34
    {&MODULE_P35, IfxPort_Index_35},     // Port 35
    {&MODULE_P40, IfxPort_Index_40},     // Port 40
};
#endif /* #if defined(DEVICE_TC4DX) */
