/**
 * \file IfxI2c_cfg.h
 * \brief I2C on-chip implementation data
 * \ingroup IfxLld_I2c
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_I2c I2C
 * \ingroup IfxLld
 * \defgroup IfxLld_I2c_Impl Implementation
 * \ingroup IfxLld_I2c
 * \defgroup IfxLld_I2c_Std Standard Driver
 * \ingroup IfxLld_I2c
 * \defgroup IfxLld_I2c_Impl_Enumerations Enumerations
 * \ingroup IfxLld_I2c_Impl
 */

#ifndef IFXI2C_CFG_H
#define IFXI2C_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxI2c_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXI2C_NUM_MODULES (2)

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
    IfxI2c_Index_1           /**< \brief I2C Index 1  */
} IfxI2c_Index;

/** \} */

/** \addtogroup IfxLld_I2c_Impl_Enumerations
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxI2c_cfg_indexMap[IFXI2C_NUM_MODULES];

/** \} */

#endif /* IFXI2C_CFG_H */
