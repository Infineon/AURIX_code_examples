/**
 * \file IfxCan_cfg_TC4Dx.h
 * \brief CAN on-chip implementation data
 * \ingroup IfxLld_Can
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
 * \defgroup IfxLld_Can CAN
 * \ingroup IfxLld
 * \defgroup IfxLld_Can_Impl Implementation Interface
 * \ingroup IfxLld_Can
 * \defgroup IfxLld_Can_Std Standard Driver
 * \ingroup IfxLld_Can
 * \defgroup IfxLld_Can_Impl_Enum Enumerations
 * \ingroup IfxLld_Can_Impl
 */

#ifndef IFXCAN_CFG_TC4DX_H
#define IFXCAN_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxCan_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of CAN modules
 */
#define IFXCAN_NUM_MODULES         (5)

/** \brief Number of nodes per each CAN module
 */
#define IFXCAN_NUM_NODES           4

/** \brief Address Spacing in words between two Cre Rx Fifo structures
 */
#define IFXCAN_CRE_RXFIFO_SPACING  24

/** \brief Address Spacing in words between two Cre THBUF structures
 */
#define IFXCAN_CRE_THBUF_SIZE      20

/** \brief CRE IR CLEAR VALUE
 */
#define IFXCAN_CRE_IR_CLEAR        0xFFFF

/** \brief CRE TABLE Word Size, including reserved space
 */
#define IFXCAN_CRE_TABLE_SIZE      8

/** \brief Number of CRE RX FIFO Buffers
 */
#define IFXCAN_NUM_CRE_RX_FIFO     2

/** \brief CAN IR CLEAR VALUE
 */
#define IFXCAN_IR_CLEAR            0x1FCFFFFF

/** \brief CAN Extended ID and Mask Kernel Reset Value
 */
#define IFXCAN_EIDM_DEFAULT        0x1FFFFFFF

/** \brief CRE RAM Start Address for CRE_CONFIGADR.SA. Must be 32 bit word aligned. The value (IFXCAN_CRE_SA >> 2) is assigned to CRE_CONFIGADR.SA.
 */
#define IFXCAN_CRE_SA              0

/** \brief CRE Standard Routing Table Start Address. Must be 32 bit word aligned. The value (IFXCAN_CRE_STD_RT_SA >> 2) is assigned to STD_RT_PARAM.B.SA.
 */
#define IFXCAN_CRE_STD_RT_SA       0

/** \brief CRE Extended Routing Table Start Address. Must be 32 bit word aligned. The value (IFXCAN_CRE_XTD_RT_SA >> 2) is assigned to XTD_RT_PARAM.B.SA.
 */
#define IFXCAN_CRE_XTD_RT_SA       0

/** \brief CRE Standard Frame Rate Table Start Address. Must be 32 bit word aligned. The value (IFXCAN_CRE_STD_FRT_SA >> 2) is assigned to STD_FRT_PARAM.B.SA.
 */
#define IFXCAN_CRE_STD_FRT_SA      0

/** \brief CRE Extended Frame Rate Table Start Address. Must be 32 bit word aligned. The value (IFXCAN_CRE_XTD_FRT_SA >> 2) is assigned to XTD_FRT_PARAM.B.SA.
 */
#define IFXCAN_CRE_XTD_FRT_SA      0

/** \brief CRE Standard Time Stamp Database Start Address. Must be 32 bit word aligned. The value (IFXCAN_CRE_STD_TSD_SA >> 2) is assigned to STD_TSD_PARAM.B.SA.
 */
#define IFXCAN_CRE_STD_TSD_SA      0

/** \brief CRE Extended Time Stamp Database Start Address. Must be 32 bit word aligned. The value (IFXCAN_CRE_XTD_TSD_SA >> 2) is assigned to XTD_TSD_PARAM.B.SA.
 */
#define IFXCAN_CRE_XTD_TSD_SA      0

/** \brief CAN MODULE Address Mask. Used to get the module base (RAM) Address from Node Ram Address
 */
#define IFXCAN_MODULE_ADDRESS_MASK 0xFFFF0000

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
    IfxCan_Index_1,          /**< \brief CAN index 1  */
    IfxCan_Index_2,          /**< \brief CAN index 2  */
    IfxCan_Index_3,          /**< \brief CAN index 3  */
    IfxCan_Index_4           /**< \brief CAN index 4  */
} IfxCan_Index;

/** \brief CAN Node number
 */
typedef enum
{
    IfxCan_NodeId_none = -1,  /**< \brief None of the CAN Nodes */
    IfxCan_NodeId_0    = 0,   /**< \brief Node Id 0  */
    IfxCan_NodeId_1,          /**< \brief Node Id 1  */
    IfxCan_NodeId_2,          /**< \brief Node Id 2  */
    IfxCan_NodeId_3           /**< \brief Node Id 3  */
} IfxCan_NodeId;

/** \} */

/** \addtogroup IfxLld_Can_Impl_Enum
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST volatile void *IfxCan_ramAddress[IFXCAN_NUM_MODULES];

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxCan_cfg_indexMap[IFXCAN_NUM_MODULES];

#endif /* IFXCAN_CFG_TC4DX_H */
