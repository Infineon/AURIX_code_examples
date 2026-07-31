/**
 * \file IfxPort_cfg_TC4Dx.h
 * \brief PORT on-chip implementation data
 * \ingroup IfxLld_Port
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
 *
 * \defgroup IfxLld_Port PORTS
 * \ingroup IfxLld
 * \defgroup IfxLld_Port_Impl Implementation
 * \ingroup IfxLld_Port
 * \defgroup IfxLld_Port_Std Standard Driver
 * \ingroup IfxLld_Port
 */

#ifndef IFXPORT_CFG_TC4DX_H
#define IFXPORT_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxPort_reg.h"
#include "IfxPort_bf.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Port count              \ingroup IfxLld_port_cfg
 */
#define IFXPORT_NUM_MODULES (22)

/** \brief Number of APUs per PORT
 */
#define IFXPORT_NUM_APU     (16)

/** \brief Number of pins/Slices in each PORT
 */
#define IFXPORT_NUM_PINS    (16)

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
    IfxPort_Index_03   = 3,  /**< \brief PORT 03 */
    IfxPort_Index_04   = 04, /**< \brief PORT 04 */
    IfxPort_Index_10   = 10, /**< \brief PORT 10 */
    IfxPort_Index_13   = 13, /**< \brief PORT 13 */
    IfxPort_Index_14   = 14, /**< \brief PORT 14 */
    IfxPort_Index_15   = 15, /**< \brief PORT 15 */
    IfxPort_Index_16   = 16, /**< \brief PORT 16 */
    IfxPort_Index_20   = 20, /**< \brief PORT 20 */
    IfxPort_Index_21   = 21, /**< \brief PORT 21 */
    IfxPort_Index_22   = 22, /**< \brief PORT 22 */
    IfxPort_Index_23   = 23, /**< \brief PORT 23 */
    IfxPort_Index_25   = 25, /**< \brief PORT 25 */
    IfxPort_Index_30   = 30, /**< \brief PORT 30 */
    IfxPort_Index_31   = 31, /**< \brief PORT 31 */
    IfxPort_Index_32   = 32, /**< \brief PORT 32 */
    IfxPort_Index_33   = 33, /**< \brief PORT 33 */
    IfxPort_Index_34   = 34, /**< \brief PORT 34 */
    IfxPort_Index_35   = 35, /**< \brief port 35 */
    IfxPort_Index_40   = 40, /**< \brief PORT 40 */
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

#endif /* IFXPORT_CFG_TC4DX_H */
