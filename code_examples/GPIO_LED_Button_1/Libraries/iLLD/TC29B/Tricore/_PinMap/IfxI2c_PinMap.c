/**
 * \file IfxI2c_PinMap.c
 * \brief I2C I/O map
 * \ingroup IfxLld_I2c
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 */

#include "IfxI2c_PinMap.h"

IfxI2c_Scl_InOut IfxI2c0_SCL_P02_5_INOUT = {&MODULE_I2C0, {&MODULE_P02, 5}, Ifx_RxSel_a, IfxPort_OutputIdx_alt5};
IfxI2c_Scl_InOut IfxI2c0_SCL_P13_1_INOUT = {&MODULE_I2C0, {&MODULE_P13, 1}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};
IfxI2c_Scl_InOut IfxI2c0_SCL_P15_4_INOUT = {&MODULE_I2C0, {&MODULE_P15, 4}, Ifx_RxSel_c, IfxPort_OutputIdx_alt6};
IfxI2c_Scl_InOut IfxI2c1_SCL_P11_14_INOUT = {&MODULE_I2C1, {&MODULE_P11,14}, Ifx_RxSel_a, IfxPort_OutputIdx_alt6};
IfxI2c_Scl_InOut IfxI2c1_SCL_P13_9_INOUT = {&MODULE_I2C1, {&MODULE_P13, 9}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};
IfxI2c_Sda_InOut IfxI2c0_SDA_P02_4_INOUT = {&MODULE_I2C0, {&MODULE_P02, 4}, Ifx_RxSel_a, IfxPort_OutputIdx_alt5};
IfxI2c_Sda_InOut IfxI2c0_SDA_P13_2_INOUT = {&MODULE_I2C0, {&MODULE_P13, 2}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};
IfxI2c_Sda_InOut IfxI2c0_SDA_P15_5_INOUT = {&MODULE_I2C0, {&MODULE_P15, 5}, Ifx_RxSel_c, IfxPort_OutputIdx_alt6};
IfxI2c_Sda_InOut IfxI2c1_SDA_P11_13_INOUT = {&MODULE_I2C1, {&MODULE_P11,13}, Ifx_RxSel_a, IfxPort_OutputIdx_alt6};
IfxI2c_Sda_InOut IfxI2c1_SDA_P13_12_INOUT = {&MODULE_I2C1, {&MODULE_P13,12}, Ifx_RxSel_b, IfxPort_OutputIdx_alt6};


const IfxI2c_Scl_InOut *IfxI2c_Scl_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS] = {
    {
        &IfxI2c0_SCL_P02_5_INOUT,
        &IfxI2c0_SCL_P13_1_INOUT,
        &IfxI2c0_SCL_P15_4_INOUT
    },
    {
        &IfxI2c1_SCL_P11_14_INOUT,
        &IfxI2c1_SCL_P13_9_INOUT,
        NULL_PTR
    }
};

const IfxI2c_Sda_InOut *IfxI2c_Sda_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS] = {
    {
        &IfxI2c0_SDA_P02_4_INOUT,
        &IfxI2c0_SDA_P13_2_INOUT,
        &IfxI2c0_SDA_P15_5_INOUT
    },
    {
        &IfxI2c1_SDA_P11_13_INOUT,
        &IfxI2c1_SDA_P13_12_INOUT,
        NULL_PTR
    }
};
