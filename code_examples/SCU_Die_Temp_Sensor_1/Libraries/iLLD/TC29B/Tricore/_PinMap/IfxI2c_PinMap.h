/**
 * \file IfxI2c_PinMap.h
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
 * \defgroup IfxLld_I2c_pinmap I2C Pin Mapping
 * \ingroup IfxLld_I2c
 */

#ifndef IFXI2C_PINMAP_H
#define IFXI2C_PINMAP_H

#include <IfxI2c_reg.h>
#include <_Impl/IfxI2c_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_I2c_pinmap
 * \{ */

/** \brief SCL input mapping structure */
typedef const struct
{
    Ifx_I2C*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         inSelect;  /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect; /**< \brief Port control code */
} IfxI2c_Scl_InOut;

/** \brief SDA input mapping structure */
typedef const struct
{
    Ifx_I2C*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         inSelect;  /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect; /**< \brief Port control code */
} IfxI2c_Sda_InOut;

IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P02_5_INOUT;  /**< \brief I2C0_SCL: I2C0 output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P13_1_INOUT;  /**< \brief I2C0_SCL: I2C0 output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P15_4_INOUT;  /**< \brief I2C0_SCL: I2C0 output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c1_SCL_P11_14_INOUT;  /**< \brief I2C1_SCL: I2C1 output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c1_SCL_P13_9_INOUT;  /**< \brief I2C1_SCL: I2C1 output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P02_4_INOUT;  /**< \brief I2C0_SDA: I2C0 output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P13_2_INOUT;  /**< \brief I2C0_SDA: I2C0 output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P15_5_INOUT;  /**< \brief I2C0_SDA: I2C0 output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c1_SDA_P11_13_INOUT;  /**< \brief I2C1_SDA: I2C1 output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c1_SDA_P13_12_INOUT;  /**< \brief I2C1_SDA: I2C1 output and input */

/** \brief Table dimensions */
#define IFXI2C_PINMAP_NUM_MODULES 2
#define IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS 3
#define IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS 3


/** \brief IfxI2c_Scl_InOut table */
IFX_EXTERN const IfxI2c_Scl_InOut *IfxI2c_Scl_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS];

/** \brief IfxI2c_Sda_InOut table */
IFX_EXTERN const IfxI2c_Sda_InOut *IfxI2c_Sda_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS];

/** \} */

#endif /* IFXI2C_PINMAP_H */
