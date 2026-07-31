/**
 * \file IfxI2c_cfg_TC4Dx.h
 * \brief I2C on-chip implementation data
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
 * \defgroup IfxLld_I2c I2C
 * \ingroup IfxLld
 * \defgroup IfxLld_I2c_Impl Implementation
 * \ingroup IfxLld_I2c
 * \defgroup IfxLld_I2c_Std Standard Driver
 * \ingroup IfxLld_I2c
 * \defgroup IfxLld_I2c_Impl_Enumerations Enumerations
 * \ingroup IfxLld_I2c_Impl
 */

#ifndef IFXI2C_CFG_TC4DX_H
#define IFXI2C_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxI2c_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Modules
 */
#define IFXI2C_NUM_MODULES (3)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_I2c_Impl_Enumerations
 * \{ */
/** \brief List of the available I2c interfaces
 */
typedef enum
{
    IfxI2c_Index_none = -1,  /**< \brief Not Selected */
    IfxI2c_Index_0    = 0,   /**< \brief I2C Index 0  */
    IfxI2c_Index_1,          /**< \brief I2C Index 1  */
    IfxI2c_Index_2           /**< \brief I2C Index 2  */
} IfxI2c_Index;

/** \} */

/** \addtogroup IfxLld_I2c_Impl_Enumerations
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxI2c_cfg_indexMap[IFXI2C_NUM_MODULES];

/** \} */

#endif /* IFXI2C_CFG_TC4DX_H */
