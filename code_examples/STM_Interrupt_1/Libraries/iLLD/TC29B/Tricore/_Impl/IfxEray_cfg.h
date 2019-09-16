/**
 * \file IfxEray_cfg.h
 * \brief ERAY on-chip implementation data
 * \ingroup IfxLld_Eray
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
 * \defgroup IfxLld_Eray ERAY
 * \ingroup IfxLld
 * \defgroup IfxLld_Eray_Impl Implementation
 * \ingroup IfxLld_Eray
 * \defgroup IfxLld_Eray_Std Standard Driver
 * \ingroup IfxLld_Eray
 * \defgroup IfxLld_Eray_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Eray_Impl
 */

#ifndef IFXERAY_CFG_H
#define IFXERAY_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxEray_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXERAY_NUM_MODULES  (2)

#define IFXERAY_NUM_SLOTS    (128)

#define IFXERAY_NUM_CHANNELS (4)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Eray_Impl_Enumerations
 * \{ */
/** \brief List of the available Eray resources
 */
typedef enum
{
    IfxEray_Index_none = -1,  /**< \brief Not Selected */
    IfxEray_Index_0    = 0,   /**< \brief ERAY index 0  */
    IfxEray_Index_1           /**< \brief ERAY index 1  */
} IfxEray_Index;

/** \brief Node Id in communication cycle.
 */
typedef enum
{
    IfxEray_NodeId_a    = 0,  /**< \brief Ifx_ERAY Node A */
    IfxEray_NodeId_b    = 1,  /**< \brief Ifx_ERAY Node B */
    IfxEray_NodeId_none = -1  /**< \brief None of the Ifx_ERAY Nodes */
} IfxEray_NodeId;

/** \} */

/** \addtogroup IfxLld_Eray_Impl_Enumerations
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxEray_cfg_indexMap[IFXERAY_NUM_MODULES];

/** \} */

#endif /* IFXERAY_CFG_H */
