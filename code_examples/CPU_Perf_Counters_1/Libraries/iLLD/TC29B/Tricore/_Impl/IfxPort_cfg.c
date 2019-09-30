/**
 * \file IfxPort_cfg.c
 * \brief PORT on-chip implementation data
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPort_cfg.h"

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
    {&MODULE_P24, 0x0000FFFFUL},    // Port 24
    {&MODULE_P25, 0x0000FFFFUL},    // Port 25
    {&MODULE_P26, 0x0000FFFFUL},    // Port 26
    {&MODULE_P30, 0x0000FFFFUL},    // Port 30
    {&MODULE_P31, 0x0000FFFFUL},    // Port 31
    {&MODULE_P32, 0x0000FFFFUL},    // Port 32
    {&MODULE_P33, 0x0000FFFFUL},    // Port 33
    {&MODULE_P34, 0x0000FFFFUL}     // Port 34
    //{&MODULE_P40, 0x0000FFFFUL}   // Port 40
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
    {&MODULE_P24, IfxPort_Index_24},     // Port 24
    {&MODULE_P25, IfxPort_Index_25},     // Port 25
    {&MODULE_P26, IfxPort_Index_26},     // Port 26
    {&MODULE_P30, IfxPort_Index_30},     // Port 30
    {&MODULE_P31, IfxPort_Index_31},     // Port 31
    {&MODULE_P32, IfxPort_Index_32},     // Port 32
    {&MODULE_P33, IfxPort_Index_33},     // Port 33
    {&MODULE_P34, IfxPort_Index_34}      // Port 34
    //{&MODULE_P40, 40}    // Port 40
};
