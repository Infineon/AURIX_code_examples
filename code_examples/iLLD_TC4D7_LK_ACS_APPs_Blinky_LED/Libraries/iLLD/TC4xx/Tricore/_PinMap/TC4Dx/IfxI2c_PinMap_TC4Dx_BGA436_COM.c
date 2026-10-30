/**
 * \file IfxI2c_PinMap_TC4Dx_BGA436_COM.c
 * \brief I2C  details
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

#if defined(__TASKING__)
#pragma warning 508
#endif

#if defined(__ghs__)
#pragma ghs nowarning 96
#endif
#include "Ifx_PinMap.h"
#if defined(DEVICE_TC4DX) && defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "IfxI2c_PinMap_TC4Dx_BGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxI2c_Scl_InOut IfxI2c0_SCL_P02_5_INOUT = {&MODULE_I2C0, {&MODULE_P02, 5}, Ifx_RxSel_a, IfxPort_OutputIdx_alt5};

IfxI2c_Scl_InOut IfxI2c0_SCL_P13_1_INOUT = {&MODULE_I2C0, {&MODULE_P13, 1}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};

IfxI2c_Scl_InOut IfxI2c0_SCL_P13_4_INOUT = {&MODULE_I2C0, {&MODULE_P13, 4}, Ifx_RxSel_f, IfxPort_OutputIdx_alt6};

IfxI2c_Scl_InOut IfxI2c0_SCL_P15_4_INOUT = {&MODULE_I2C0, {&MODULE_P15, 4}, Ifx_RxSel_c, IfxPort_OutputIdx_alt6};

IfxI2c_Scl_InOut IfxI2c0_SCL_P16_9_INOUT = {&MODULE_I2C0, {&MODULE_P16, 9}, Ifx_RxSel_e, IfxPort_OutputIdx_alt14};

IfxI2c_Scl_InOut IfxI2c0_SCL_P32_4_INOUT = {&MODULE_I2C0, {&MODULE_P32, 4}, Ifx_RxSel_d, IfxPort_OutputIdx_alt8};

IfxI2c_Sda_InOut IfxI2c0_SDA_P02_4_INOUT = {&MODULE_I2C0, {&MODULE_P02, 4}, Ifx_RxSel_a, IfxPort_OutputIdx_alt5};

IfxI2c_Sda_InOut IfxI2c0_SDA_P13_2_INOUT = {&MODULE_I2C0, {&MODULE_P13, 2}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};

IfxI2c_Sda_InOut IfxI2c0_SDA_P13_5_INOUT = {&MODULE_I2C0, {&MODULE_P13, 5}, Ifx_RxSel_f, IfxPort_OutputIdx_alt6};

IfxI2c_Sda_InOut IfxI2c0_SDA_P15_5_INOUT = {&MODULE_I2C0, {&MODULE_P15, 5}, Ifx_RxSel_c, IfxPort_OutputIdx_alt6};

IfxI2c_Sda_InOut IfxI2c0_SDA_P16_10_INOUT = {&MODULE_I2C0, {&MODULE_P16, 10}, Ifx_RxSel_e, IfxPort_OutputIdx_alt14};

IfxI2c_Sda_InOut IfxI2c0_SDA_P32_6_INOUT = {&MODULE_I2C0, {&MODULE_P32, 6}, Ifx_RxSel_d, IfxPort_OutputIdx_alt8};

IfxI2c_Scl_InOut IfxI2c1_SCL_P13_13_INOUT = {&MODULE_I2C1, {&MODULE_P13, 13}, Ifx_RxSel_f, IfxPort_OutputIdx_alt8};

IfxI2c_Scl_InOut IfxI2c1_SCL_P13_9_INOUT = {&MODULE_I2C1, {&MODULE_P13, 9}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};

IfxI2c_Scl_InOut IfxI2c1_SCL_P15_11_INOUT = {&MODULE_I2C1, {&MODULE_P15, 11}, Ifx_RxSel_c, IfxPort_OutputIdx_alt6};

IfxI2c_Scl_InOut IfxI2c1_SCL_P16_14_INOUT = {&MODULE_I2C1, {&MODULE_P16, 14}, Ifx_RxSel_e, IfxPort_OutputIdx_alt14};

IfxI2c_Scl_InOut IfxI2c1_SCL_P34_3_INOUT = {&MODULE_I2C1, {&MODULE_P34, 3}, Ifx_RxSel_d, IfxPort_OutputIdx_alt8};

IfxI2c_Sda_InOut IfxI2c1_SDAF_P13_12_INOUT = {&MODULE_I2C1, {&MODULE_P13, 12}, Ifx_RxSel_f, IfxPort_OutputIdx_alt8};

IfxI2c_Sda_InOut IfxI2c1_SDA_P13_12_INOUT = {&MODULE_I2C1, {&MODULE_P13, 12}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};

IfxI2c_Sda_InOut IfxI2c1_SDA_P15_10_INOUT = {&MODULE_I2C1, {&MODULE_P15, 10}, Ifx_RxSel_c, IfxPort_OutputIdx_alt6};

IfxI2c_Sda_InOut IfxI2c1_SDA_P16_11_INOUT = {&MODULE_I2C1, {&MODULE_P16, 11}, Ifx_RxSel_e, IfxPort_OutputIdx_alt14};

IfxI2c_Sda_InOut IfxI2c1_SDA_P34_2_INOUT = {&MODULE_I2C1, {&MODULE_P34, 2}, Ifx_RxSel_d, IfxPort_OutputIdx_alt8};

IfxI2c_Scl_InOut IfxI2c2_SCL_P03_12_INOUT = {&MODULE_I2C2, {&MODULE_P03, 12}, Ifx_RxSel_a, IfxPort_OutputIdx_alt2};

IfxI2c_Scl_InOut IfxI2c2_SCL_P04_5_INOUT = {&MODULE_I2C2, {&MODULE_P04, 5}, Ifx_RxSel_b, IfxPort_OutputIdx_alt8};

IfxI2c_Scl_InOut IfxI2c2_SCL_P04_9_INOUT = {&MODULE_I2C2, {&MODULE_P04, 9}, Ifx_RxSel_c, IfxPort_OutputIdx_alt8};

IfxI2c_Scl_InOut IfxI2c2_SCL_P16_13_INOUT = {&MODULE_I2C2, {&MODULE_P16, 13}, Ifx_RxSel_d, IfxPort_OutputIdx_alt14};

IfxI2c_Scl_InOut IfxI2c2_SCL_P35_4_INOUT = {&MODULE_I2C2, {&MODULE_P35, 4}, Ifx_RxSel_e, IfxPort_OutputIdx_alt2};

IfxI2c_Sda_InOut IfxI2c2_SDA_P03_11_INOUT = {&MODULE_I2C2, {&MODULE_P03, 11}, Ifx_RxSel_a, IfxPort_OutputIdx_alt2};

IfxI2c_Sda_InOut IfxI2c2_SDA_P04_4_INOUT = {&MODULE_I2C2, {&MODULE_P04, 4}, Ifx_RxSel_b, IfxPort_OutputIdx_alt8};

IfxI2c_Sda_InOut IfxI2c2_SDA_P04_8_INOUT = {&MODULE_I2C2, {&MODULE_P04, 8}, Ifx_RxSel_c, IfxPort_OutputIdx_alt8};

IfxI2c_Sda_InOut IfxI2c2_SDA_P16_12_INOUT = {&MODULE_I2C2, {&MODULE_P16, 12}, Ifx_RxSel_d, IfxPort_OutputIdx_alt14};

IfxI2c_Sda_InOut IfxI2c2_SDA_P35_2_INOUT = {&MODULE_I2C2, {&MODULE_P35, 2}, Ifx_RxSel_e, IfxPort_OutputIdx_alt2};

/** \addtogroup IfxLld_I2c__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxI2c_Scl_InOut *IfxI2c_Scl_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS] = {
    {
        &IfxI2c0_SCL_P02_5_INOUT,
        &IfxI2c0_SCL_P13_1_INOUT,
        &IfxI2c0_SCL_P15_4_INOUT,
        &IfxI2c0_SCL_P32_4_INOUT,
        &IfxI2c0_SCL_P16_9_INOUT,
        &IfxI2c0_SCL_P13_4_INOUT,
    },
    {
        NULL_PTR,
        &IfxI2c1_SCL_P13_9_INOUT,
        &IfxI2c1_SCL_P15_11_INOUT,
        &IfxI2c1_SCL_P34_3_INOUT,
        &IfxI2c1_SCL_P16_14_INOUT,
        &IfxI2c1_SCL_P13_13_INOUT,
    },
    {
        &IfxI2c2_SCL_P03_12_INOUT,
        &IfxI2c2_SCL_P04_5_INOUT,
        &IfxI2c2_SCL_P04_9_INOUT,
        &IfxI2c2_SCL_P16_13_INOUT,
        &IfxI2c2_SCL_P35_4_INOUT,
        NULL_PTR,
    },
};

IFX_CONST IfxI2c_Sda_InOut *IfxI2c_Sda_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS] = {
    {
        &IfxI2c0_SDA_P02_4_INOUT,
        &IfxI2c0_SDA_P13_2_INOUT,
        &IfxI2c0_SDA_P15_5_INOUT,
        &IfxI2c0_SDA_P32_6_INOUT,
        &IfxI2c0_SDA_P16_10_INOUT,
        &IfxI2c0_SDA_P13_5_INOUT,
    },
    {
        NULL_PTR,
        &IfxI2c1_SDA_P13_12_INOUT,
        &IfxI2c1_SDA_P15_10_INOUT,
        &IfxI2c1_SDA_P34_2_INOUT,
        &IfxI2c1_SDA_P16_11_INOUT,
        &IfxI2c1_SDAF_P13_12_INOUT,
    },
    {
        &IfxI2c2_SDA_P03_11_INOUT,
        &IfxI2c2_SDA_P04_4_INOUT,
        &IfxI2c2_SDA_P04_8_INOUT,
        &IfxI2c2_SDA_P16_12_INOUT,
        &IfxI2c2_SDA_P35_2_INOUT,
        NULL_PTR,
    },
};

/** \} */

#endif
