/**
 * \file IfxI2c_PinMap_TC37x_516.c
 * \brief I2C I/O map
 * \ingroup IfxLld_I2c
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
#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if defined DEVICE_TC37X && defined IFX_PIN_PACKAGE_516
#include "IfxI2c_PinMap_TC37x_516.h"

IfxI2c_Scl_InOut IfxI2c0_SCL_P02_5_INOUT = {&MODULE_I2C0, {&MODULE_P02, 5}, Ifx_RxSel_a, IfxPort_OutputIdx_alt5};
IfxI2c_Scl_InOut IfxI2c0_SCL_P13_1_INOUT = {&MODULE_I2C0, {&MODULE_P13, 1}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};
IfxI2c_Scl_InOut IfxI2c0_SCL_P15_4_INOUT = {&MODULE_I2C0, {&MODULE_P15, 4}, Ifx_RxSel_c, IfxPort_OutputIdx_alt6};
IfxI2c_Sda_InOut IfxI2c0_SDA_P02_4_INOUT = {&MODULE_I2C0, {&MODULE_P02, 4}, Ifx_RxSel_a, IfxPort_OutputIdx_alt5};
IfxI2c_Sda_InOut IfxI2c0_SDA_P13_2_INOUT = {&MODULE_I2C0, {&MODULE_P13, 2}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};
IfxI2c_Sda_InOut IfxI2c0_SDA_P15_5_INOUT = {&MODULE_I2C0, {&MODULE_P15, 5}, Ifx_RxSel_c, IfxPort_OutputIdx_alt6};


const IfxI2c_Scl_InOut *IfxI2c_Scl_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS] = {
    {
        &IfxI2c0_SCL_P02_5_INOUT,
        &IfxI2c0_SCL_P13_1_INOUT,
        &IfxI2c0_SCL_P15_4_INOUT
    }
};

const IfxI2c_Sda_InOut *IfxI2c_Sda_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS] = {
    {
        &IfxI2c0_SDA_P02_4_INOUT,
        &IfxI2c0_SDA_P13_2_INOUT,
        &IfxI2c0_SDA_P15_5_INOUT
    }
};
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
