/**
 * \file IfxI2c_PinMap_TC4Dx_BGA292_COM.h
 * \brief I2C  details
 * \ingroup IfxLld_I2c
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
 * Version: MC_ACE_A3G_HWA_Ports/Unknown
 * Document: TC4Dx_Pin_Assignment_v0.45_LETH_patched.xls
 *
 * \defgroup IfxLld_I2c_
 * \ingroup IfxLld_I2c
 * \defgroup IfxLld_I2c__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_I2c_
 * \defgroup IfxLld_I2c__PinTables PinTables
 * \ingroup IfxLld_I2c_
 */

#ifndef IFXI2C_PINMAP_TC4DX_BGA292_COM_H
#define IFXI2C_PINMAP_TC4DX_BGA292_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxI2c_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXI2C_PINMAP_NUM_MODULES         3

#define IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS 6

#define IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS 6

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief Serial Clock Output and Serial Clock Input 0
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P02_5_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 1
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P13_1_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 2
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P15_4_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 4
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P16_9_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 3
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c0_SCL_P32_4_INOUT;

/** \brief Serial Data Output and Serial Data Input 0
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P02_4_INOUT;

/** \brief Serial Data Output and Serial Data Input 1
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P13_2_INOUT;

/** \brief Serial Data Output and Serial Data Input 2
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P15_5_INOUT;

/** \brief Serial Data Output and Serial Data Input 4
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P16_10_INOUT;

/** \brief Serial Data Output and Serial Data Input 3
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c0_SDA_P32_6_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 4
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c1_SCL_P16_14_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 3
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c1_SCL_P34_3_INOUT;

/** \brief Serial Data Output and Serial Data Input 4
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c1_SDA_P16_11_INOUT;

/** \brief Serial Data Output and Serial Data Input 3
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c1_SDA_P34_2_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 0
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c2_SCL_P03_12_INOUT;

/** \brief Serial Clock Output and Serial Clock Input 3
 */
IFX_EXTERN IfxI2c_Scl_InOut IfxI2c2_SCL_P16_13_INOUT;

/** \brief Serial Data Output and Serial Data Input 0
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c2_SDA_P03_11_INOUT;

/** \brief Serial Data Output and Serial Data Input 3
 */
IFX_EXTERN IfxI2c_Sda_InOut IfxI2c2_SDA_P16_12_INOUT;

/** \addtogroup IfxLld_I2c__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxI2c_Scl_InOut Table
 */
IFX_EXTERN IFX_CONST IfxI2c_Scl_InOut *IfxI2c_Scl_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SCL_INOUT_NUM_ITEMS];

/** \brief IfxI2c_Sda_InOut Table
 */
IFX_EXTERN IFX_CONST IfxI2c_Sda_InOut *IfxI2c_Sda_InOut_pinTable[IFXI2C_PINMAP_NUM_MODULES][IFXI2C_PINMAP_SDA_INOUT_NUM_ITEMS];

/** \} */

#endif /* IFXI2C_PINMAP_TC4DX_BGA292_COM_H */
