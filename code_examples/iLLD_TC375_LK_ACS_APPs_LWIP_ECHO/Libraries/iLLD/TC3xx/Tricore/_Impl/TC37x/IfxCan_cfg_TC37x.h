/**
 * \file IfxCan_cfg_TC37x.h
 * \brief CAN on-chip implementation data
 * \ingroup IfxLld_Can
 *
 * \version iLLD_1_22_0
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
 *
 * \defgroup IfxLld_Can CAN
 * \ingroup IfxLld
 * \defgroup IfxLld_Can_Impl Implementation Interface
 * \ingroup IfxLld_Can
 * \defgroup IfxLld_Can_Std Standard Interface
 * \ingroup IfxLld_Can
 * \defgroup IfxLld_Can_Impl_Enum Enumerations
 * \ingroup IfxLld_Can_Impl
 */

#ifndef IFXCAN_CFG_TC37X_H
#define IFXCAN_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxCan_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of CAN modules
 */
#define IFXCAN_NUM_MODULES  (2)

/** \brief Number of nodes per each CAN module
 */
#define IFXCAN_NUM_NODES    4

#define IFXCAN_EIDM_DEFAULT (0x1FFFFFFF)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Can_Impl_Enum
 * \{ */
/** \brief List of the available can resources
 */
typedef enum
{
    IfxCan_Index_none = -1,  /**< \brief Not Selected */
    IfxCan_Index_0    = 0,   /**< \brief CAN index 0  */
    IfxCan_Index_1          /**< \brief CAN index 1  */
} IfxCan_Index;

/** \brief CAN Node number
 */
typedef enum
{
    IfxCan_NodeId_none = -1, /**< \brief None of the CAN Nodes */
    IfxCan_NodeId_0,         /**< \brief Node Id 0  */
    IfxCan_NodeId_1,         /**< \brief Node Id 1  */
    IfxCan_NodeId_2,         /**< \brief Node Id 2  */
    IfxCan_NodeId_3          /**< \brief Node Id 3  */
} IfxCan_NodeId;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxCan_cfg_indexMap[IFXCAN_NUM_MODULES];

#endif /* IFXCAN_CFG_TC37X_H */
