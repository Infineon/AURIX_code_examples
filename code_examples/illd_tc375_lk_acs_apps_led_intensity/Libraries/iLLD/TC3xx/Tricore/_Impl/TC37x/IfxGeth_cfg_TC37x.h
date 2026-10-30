/**
 * \file IfxGeth_cfg_TC37x.h
 * \brief GETH on-chip implementation data
 * \ingroup IfxLld_Geth
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 * Implementation layer
 *
 * \defgroup IfxLld_Geth GETH
 * \ingroup IfxLld
 * \defgroup IfxLld_Geth_Impl Implementation
 * \ingroup IfxLld_Geth
 * \defgroup IfxLld_Geth_Std Standard Driver
 * \ingroup IfxLld_Geth
 * \defgroup IfxLld_Geth_Impl_Enum Enumerations
 * \ingroup IfxLld_Geth_Impl
 */

#ifndef IFXGETH_CFG_TC37X_H
#define IFXGETH_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxGeth_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Tx queues in MTL block
 */
#define IFXGETH_NUM_TX_QUEUES     (4)

/** \brief Number of Rx queues in MTL block
 */
#define IFXGETH_NUM_RX_QUEUES     (4)

/** \brief Number of Geth instances
 */
#define IFXGETH_NUM_MODULES       (1)

/** \brief Number of Tx DMA channels of DMA
 */
#define IFXGETH_NUM_TX_CHANNELS   (4)

/** \brief Number of Rx Channels of DMA
 */
#define IFXGETH_NUM_RX_CHANNELS   (4)

/** \brief Maximum timeout value to wait against at
 */
#define IFXGETH_MAX_TIMEOUT_VALUE (1000)

/** \brief Number of DMA channels
 */
#define IFXGETH_NUM_DMA_CHANNELS  (4)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Geth_Impl_Enum
 * \{ */
/** \brief List of the available Geth instances
 */
typedef enum
{
    IfxGeth_Index_none = -1,  /**< \brief Not Selected */
    IfxGeth_Index_0    = 0,   /**< \brief GETH index 0  */
} IfxGeth_Index;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxGeth_cfg_indexMap[IFXGETH_NUM_MODULES];

#endif /* IFXGETH_CFG_TC37X_H */
