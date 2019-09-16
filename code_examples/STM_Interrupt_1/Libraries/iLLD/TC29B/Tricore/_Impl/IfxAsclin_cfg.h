/**
 * \file IfxAsclin_cfg.h
 * \brief ASCLIN on-chip implementation data
 * \ingroup IfxLld_Asclin
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
 * \defgroup IfxLld_Asclin ASCLIN
 * \ingroup IfxLld
 * \defgroup IfxLld_Asclin_Impl Implementation
 * \ingroup IfxLld_Asclin
 * \defgroup IfxLld_Asclin_Std Standard Driver
 * \ingroup IfxLld_Asclin
 * \defgroup IfxLld_Asclin_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Asclin_Impl
 */

#ifndef IFXASCLIN_CFG_H
#define IFXASCLIN_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxAsclin_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXASCLIN_NUM_MODULES (4)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Asclin_Impl_Enumerations
 * \{ */
/** \brief List of the available Asclin resources
 */
typedef enum
{
    IfxAsclin_Index_none = -1,  /**< \brief Not Selected */
    IfxAsclin_Index_0    = 0,   /**< \brief ASCLIN Index 0  */
    IfxAsclin_Index_1,          /**< \brief ASCLIN Index 1  */
    IfxAsclin_Index_2,          /**< \brief ASCLIN Index 2  */
    IfxAsclin_Index_3           /**< \brief ASCLIN Index 3  */
} IfxAsclin_Index;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxAsclin_cfg_indexMap[IFXASCLIN_NUM_MODULES];

#endif /* IFXASCLIN_CFG_H */
