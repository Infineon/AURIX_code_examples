/**
 * \file IfxLeth_cfg_TC4Dx.h
 * \brief LETH on-chip implementation data
 * \ingroup IfxLld_Leth
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
 * \defgroup IfxLld_Leth LETH
 * \ingroup IfxLld
 * \defgroup IfxLld_Leth_Impl Implementation
 * \ingroup IfxLld_Leth
 * \defgroup IfxLld_Leth_Std Standard Driver
 * \ingroup IfxLld_Leth
 * \defgroup IfxLld_Leth_Impl_Enum Enumerations
 * \ingroup IfxLld_Leth_Impl
 */

#ifndef IFXLETH_CFG_TC4DX_H
#define IFXLETH_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxLeth_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Tx queues in MTL block
 */
#define IFXLETH_NUM_TX_QUEUES     (5)

/** \brief Number of Rx queues in MTL block
 */
#define IFXLETH_NUM_RX_QUEUES     (2)

/** \brief Number of Leth instances
 */
#define IFXLETH_NUM_MODULES       (1)

/** \brief Number of Tx DMA channels of DMA
 */
#define IFXLETH_NUM_TX_CHANNELS   (8)

/** \brief Number of Rx Channels of DMA
 */
#define IFXLETH_NUM_RX_CHANNELS   (8)

/** \brief Maximum timeout value to wait against at
 */
#define IFXLETH_MAX_TIMEOUT_VALUE (1000)

/** \brief MAX wait time for polling the MDIO transfer to complete
 */
#define IFXLETH_MDIO_MAX_TIMEOUT (1000)

/** \brief Number of DMA channels
 */
#define IFXLETH_NUM_DMA_CHANNELS  (8)

/** \brief Number of Ports
 */
#define IFXLETH_NUM_PORTS         (4)

/** \brief Offset for bitfields in Ifx_LETH_BRIDGE_PORT_TX_WRR_WEIGHTS_Bits.TX_WRR_PORTi and Ifx_LETH_BRIDGE_PORT_RX_WRR_WEIGHTS_Bits.RX_WRR_PORTi */
#define IFXLETH_BRIDGE_WRR_WEIGHTS_PORT_OFFSET (8)

/** \brief Multiport support availability
 */
#define IFXLETH_IS_MULTI_PORT_SUPPORT  (FALSE)

/** \brief Receive Buffer size High 13_Y
 */
#define IFXLETH1_RBSZ_13_Y  			(TRUE)

/** \brief Availability of Bridge in Leth
 */
#define IFXLETH_IS_BRIDGE_AVAILABLE  	(TRUE)

/** \brief Availability of EXTPTPTIMESEL
 */
#define IFXLETH_IS_EXTPTPTIMESEL_AVAILABLE (FALSE)

/** \brief Usage of Port Index
 */
#define IFXLETH_USE_PORTINDEX			(FALSE)

/** \brief Availability of Service Request PPS 2
 */
#define IFXLETH_IS_SRVC_RQST_PPS2_AVAILABLE		(TRUE)

/** \brief Availability of Service Request PPS 3
 */
#define IFXLETH_IS_SRVC_RQST_PPS3_AVAILABLE		(TRUE)

/** \brief Availability of Service Request Wake up
 */
#define IFXLETH_IS_SRVC_RQST_WUP_AVAILABLE		(FALSE)

/** \brief Availability of Service Request MCGR0
 */
#define IFXLETH_IS_SRVC_RQST_MCGR0_AVAILABLE	(FALSE)

/** \brief Availability of Service Request MCGR1
 */
#define IFXLETH_IS_SRVC_RQST_MCGR1_AVAILABLE	(FALSE)

/** \brief Availability of Service Request MCGR2
 */
#define IFXLETH_IS_SRVC_RQST_MCGR2_AVAILABLE	(FALSE)

/** \brief Availability of Service Request MCGR3
 */
#define IFXLETH_IS_SRVC_RQST_MCGR3_AVAILABLE	(FALSE)

/** \brief Availability of RXER Disable Control
 */
#define IFXLETH_IS_DISABLE_RXER_AVAILABLE		(FALSE)

/** \brief Enable or disable RXDEN bit of PORTCTRL0
 */
#define IFXLETH_ENABLE_DISABLE_RXDEN			(FALSE)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Leth_Impl_Enum
 * \{ */
/** \brief List of the available Leth instances
 */
typedef enum
{
    IfxLeth_Index_none = -1,  /**< \brief Not Selected */
    IfxLeth_Index_0    = 0,   /**< \brief LETH index 0  */
} IfxLeth_Index;

/** \brief LETH PORT Index
 */
typedef enum
{
    IfxLeth_PortIndex_0 = 0,   /**< \brief Leth Port 0 */
    IfxLeth_PortIndex_1 = 1,   /**< \brief Leth Port 1 */
    IfxLeth_PortIndex_2 = 2,   /**< \brief Leth Port 2 */
    IfxLeth_PortIndex_3 = 3    /**< \brief Leth Port 3 */
} IfxLeth_PortIndex;

/** \brief MTL Rx Queue Index
 */
typedef enum
{
    IfxLeth_RxMtlQueue_0 = 0,  /**< \brief Rx Queue 0 */
    IfxLeth_RxMtlQueue_1 = 1,  /**< \brief Rx Queue 1 */
} IfxLeth_RxMtlQueue;

/** \brief MTL Tx Queue Index
 */
typedef enum
{
    IfxLeth_TxMtlQueue_0 = 0,  /**< \brief Tx Queue 0 */
    IfxLeth_TxMtlQueue_1 = 1,  /**< \brief Tx Queue 1 */
    IfxLeth_TxMtlQueue_2 = 2,  /**< \brief Tx Queue 2 */
    IfxLeth_TxMtlQueue_3 = 3,  /**< \brief Tx Queue 3 */
    IfxLeth_TxMtlQueue_4 = 4,  /**< \brief Tx Queue 4 */
} IfxLeth_TxMtlQueue;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxLeth_cfg_indexMap[IFXLETH_NUM_MODULES];

#endif /* IFXLETH_CFG_TC4DX_H */
