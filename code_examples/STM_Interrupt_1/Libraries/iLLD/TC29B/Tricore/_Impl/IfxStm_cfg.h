/**
 * \file IfxStm_cfg.h
 * \brief STM on-chip implementation data
 * \ingroup IfxLld_Stm
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
 * \defgroup IfxLld_Stm STM
 * \ingroup IfxLld
 * \defgroup IfxLld_Stm_Impl Implementation
 * \ingroup IfxLld_Stm
 * \defgroup IfxLld_Stm_Std Standard Driver
 * \ingroup IfxLld_Stm
 * \defgroup IfxLld_Stm_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Stm_Impl
 * \defgroup IfxLld_Stm_Impl_Variables Global Variables
 * \ingroup IfxLld_Stm_Impl
 */

#ifndef IFXSTM_CFG_H
#define IFXSTM_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxStm_reg.h"
#include "Cpu/Std/Ifx_Types.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief STM count
 */
#define IFXSTM_NUM_MODULES     3

/** \brief No Of Comparators per Stm
 */
#define IFXSTM_NUM_COMPARATORS (2)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Stm_Impl_Enumerations
 * \{ */
/** \brief List of the available STM resources
 */
typedef enum
{
    IfxStm_Index_none = -1,  /**< \brief Not Selected */
    IfxStm_Index_0    = 0,   /**< \brief STM index 0  */
    IfxStm_Index_1,          /**< \brief STM index 1  */
    IfxStm_Index_2           /**< \brief STM index 2  */
} IfxStm_Index;

/** \} */

/** \addtogroup IfxLld_Stm_Impl_Variables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxStm_cfg_indexMap[IFXSTM_NUM_MODULES];

/** \} */

#endif /* IFXSTM_CFG_H */
