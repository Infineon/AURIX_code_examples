/**
 * \file IfxCanxl_cfg_TC4Dx.h
 * \brief CANXL on-chip implementation data
 * \ingroup IfxLld_Canxl
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
 * \defgroup IfxLld_Canxl CANXL
 * \ingroup IfxLld
 * \defgroup IfxLld_Canxl_Impl Implementation
 * \ingroup IfxLld_Canxl
 * \defgroup IfxLld_Canxl_Std Standard Driver
 * \ingroup IfxLld_Canxl
 */

#ifndef IFXCANXL_CFG_TC4DX_H
#define IFXCANXL_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxCanxl_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of CANXL modules
 */
#define IFXCANXL_NUM_MODULES            (1)

/** \brief Number of nodes per each CANXL module
 */
#define IFXCANXL_NUM_NODES              (4)

/** \brief Number of Tx Fifo Queues per XCAN node
 */
#define IFXCANXL_NUM_TX_QUEUES          8

/** \brief Number of Rx Fifo Queues per XCAN node
 */
#define IFXCANXL_NUM_RX_QUEUES          8

/** \brief Key 1 of unlock sequence for functional registers
 */
#define IFXCANXL_FUNCTIONAL_UNLOCK_KEY1 0x1234u

/** \brief Key 2 of unlock sequence for functional registers
 */
#define IFXCANXL_FUNCTIONAL_UNLOCK_KEY2 0x4321u

/** \brief Key 1 of unlock sequence for test registers
 */
#define IFXCANXL_TEST_MODE_UNLOCK_KEY1  0x6789u

/** \brief Key 2 of unlock sequence for test registers
 */
#define IFXCANXL_TEST_MODE_UNLOCK_KEY2  0x9876u

/** \brief Default number of max TX descriptors per queue
 */
#ifndef IFXCANXL_MAX_TX_DESCRIPTORS
#define IFXCANXL_MAX_TX_DESCRIPTORS     4u
#endif

/** \brief Default number of max RX descriptors per queue
 */
#ifndef IFXCANXL_MAX_RX_DESCRIPTORS
#define IFXCANXL_MAX_RX_DESCRIPTORS     4u
#endif

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available CANXL Resources
 */
typedef enum
{
    IfxCanxl_Index_none = -1,  /**< \brief Not Selected */
    IfxCanxl_Index_0    = 0    /**< \brief CANXL index 0 */
} IfxCanxl_Index;

/** \brief XCAN Node number
 */
typedef enum
{
    IfxCanxl_NodeId_none = -1,  /**< \brief None of the XCAN Nodes */
    IfxCanxl_NodeId_0    = 0,   /**< \brief Node Id 0 */
    IfxCanxl_NodeId_1    = 1,   /**< \brief Node Id 1 */
    IfxCanxl_NodeId_2    = 2,   /**< \brief Node Id 2 */
    IfxCanxl_NodeId_3    = 3    /**< \brief Node Id 3 */
} IfxCanxl_NodeId;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxCanxl_cfg_indexMap[IFXCANXL_NUM_MODULES];

#endif /* IFXCANXL_CFG_TC4DX_H */
