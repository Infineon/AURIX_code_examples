/**
 * \file IfxPort_cfg.h
 * \brief PORT on-chip implementation data
 * \ingroup IfxLld_Port
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
 *
 * \defgroup IfxLld_Port PORTS
 * \ingroup IfxLld
 * \defgroup IfxLld_Port_Impl Implementation
 * \ingroup IfxLld_Port
 * \defgroup IfxLld_Port_Std Standard Driver
 * \ingroup IfxLld_Port
 */

#ifndef IFXPORT_CFG_H
#define IFXPORT_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxPort_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Port count              \ingroup IfxLld_port_cfg
 */
#define IFXPORT_NUM_MODULES        (21)

#define IFXPORT_OUTOUTFEATURE_NONE (0xFFFFFFFF)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available Port resources
 */
typedef enum
{
    IfxPort_Index_00   = 0,  /**< \brief PORT 00 */
    IfxPort_Index_01   = 1,  /**< \brief PORT 01 */
    IfxPort_Index_02   = 2,  /**< \brief PORT 02 */
    IfxPort_Index_10   = 10, /**< \brief PORT 10 */
    IfxPort_Index_11   = 11, /**< \brief PORT 11 */
    IfxPort_Index_12   = 12, /**< \brief PORT 12 */
    IfxPort_Index_13   = 13, /**< \brief PORT 13 */
    IfxPort_Index_14   = 14, /**< \brief PORT 14 */
    IfxPort_Index_15   = 15, /**< \brief PORT 15 */
    IfxPort_Index_20   = 20, /**< \brief PORT 20 */
    IfxPort_Index_21   = 21, /**< \brief PORT 21 */
    IfxPort_Index_22   = 22, /**< \brief PORT 22 */
    IfxPort_Index_23   = 23, /**< \brief PORT 23 */
    IfxPort_Index_24   = 24, /**< \brief PORT 24 */
    IfxPort_Index_25   = 25, /**< \brief PORT 25 */
    IfxPort_Index_26   = 26, /**< \brief PORT 26 */
    IfxPort_Index_30   = 30, /**< \brief PORT 30 */
    IfxPort_Index_31   = 31, /**< \brief PORT 31 */
    IfxPort_Index_32   = 32, /**< \brief PORT 32 */
    IfxPort_Index_33   = 33, /**< \brief PORT 33 */
    IfxPort_Index_34   = 34, /**< \brief PORT 34 */
    IfxPort_Index_none = -1  /**< \brief none */
} IfxPort_Index;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief used by IfxPort_Esr_Masks table
 */
typedef struct
{
    Ifx_P *port;
    uint16 masks;
} IfxPort_Esr_Masks;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxPort_Esr_Masks  IfxPort_cfg_esrMasks[IFXPORT_NUM_MODULES];

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxPort_cfg_indexMap[IFXPORT_NUM_MODULES];

#endif /* IFXPORT_CFG_H */
