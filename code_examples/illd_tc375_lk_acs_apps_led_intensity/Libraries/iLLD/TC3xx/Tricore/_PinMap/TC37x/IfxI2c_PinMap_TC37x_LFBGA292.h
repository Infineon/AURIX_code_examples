/**
 * \file IfxI2c_PinMap_TC37x_LFBGA292.h
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
 * \defgroup IfxLld_I2c_pinmap I2C Pin Mapping
 * \ingroup IfxLld_I2c
 */

#ifndef IFXI2C_PINMAP_TC37X_LFBGA292_H
#define IFXI2C_PINMAP_TC37X_LFBGA292_H 1

#include <IfxI2c_reg.h>
#include <_Impl/IfxI2c_cfg.h>
#include <Port/Std/IfxPort.h>
#include "Ifx_PinMap.h"

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

IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P02_5_INOUT;  /**< \brief Serial Clock Output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P13_1_INOUT;  /**< \brief Serial Clock Output and input */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P15_4_INOUT;  /**< \brief Serial Clock Output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P02_4_INOUT;  /**< \brief Serial Data Output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P13_2_INOUT;  /**< \brief Serial Data Output and input */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P15_5_INOUT;  /**< \brief Serial Data Output and input */

/** \brief Table dimensions */
#define IFXI2C_PINMAP_NUM_MODULES 1
#define IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS 3
#define IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS 3


/** \brief IfxI2c_Scl_InOut table */
IFX_EXTERN const IfxI2c_Scl_InOut *IfxI2c_Scl_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS];

/** \brief IfxI2c_Sda_InOut table */
IFX_EXTERN const IfxI2c_Sda_InOut *IfxI2c_Sda_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS];

/** \} */

#endif /* IFXI2C_PINMAP_TC37X_LFBGA292_H */
