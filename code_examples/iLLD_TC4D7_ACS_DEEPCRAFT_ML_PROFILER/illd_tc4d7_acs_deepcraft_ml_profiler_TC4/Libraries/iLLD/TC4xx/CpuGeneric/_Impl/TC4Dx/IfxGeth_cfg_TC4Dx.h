/**
 * \file IfxGeth_cfg_TC4Dx.h
 * \brief GETH on-chip implementation data
 * \ingroup IfxLld_Geth
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
 * \defgroup IfxLld_Geth GETH
 * \ingroup IfxLld
 * \defgroup IfxLld_Geth_Impl Implementation
 * \ingroup IfxLld_Geth
 * \defgroup IfxLld_Geth_Std Standard Driver
 * \ingroup IfxLld_Geth
 */

#ifndef IFXGETH_CFG_TC4DX_H
#define IFXGETH_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxGeth_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Modules
 */
#define IFXGETH_NUM_MODULES                (1)

/** \brief Number of transmit queues
 */
#define IFXGETH_NUM_TX_QUEUES              (8)

/** \brief Number of Rx queues in MTL block
 */
#define IFXGETH_NUM_RX_QUEUES              (8)

/** \brief Number of Tx DMA channels of DMA
 */
#define IFXGETH_NUM_TX_CHANNELS            (8)

/** \brief Number of Rx Channels of DMA
 */
#define IFXGETH_NUM_RX_CHANNELS            (8)

/** \brief Maximum timeout value to wait against at
 */
#ifndef IFXGETH_MAX_TIMEOUT_VALUE
#define IFXGETH_MAX_TIMEOUT_VALUE          (1000)
#endif

/** \brief MAX wait time for polling the MDIO transfer to complete
 */
#ifndef IFXGETH_MDIO_MAX_TIMEOUT
#define IFXGETH_MDIO_MAX_TIMEOUT           (2000)
#endif

/** \brief Value to clear the LPI status bits
 */
#define IFXGETH_LPI_STATUS_CLEAR           (0x030F)

/** \brief Value to clear the PMT status bits
 */
#define IFXGETH_PMT_STATUS_CLEAR           (0x0060)

/** \brief Value to clear the DMA status bits
 */
#define IFXGETH_DMA_INTERRUPT_STATUS_CLEAR (0xF3C7)

/** \brief Number of remote wakeup filter block's
 */
#define IFXGETH_NUM_RWKUP_FILTER_BLOCK     (1)

/** \brief Number of remote wakeup filter's in each block
 */
#define IFXGETH_NUM_RWKUP_FILTER           (4)

/** \brief MAX wait time for polling the LPI mode entry/exit status
 */
#ifndef IFXGETH_LPI_MAX_TIMEOUT
#define IFXGETH_LPI_MAX_TIMEOUT            (1000)
#endif

/** \brief MAX wait time for polling the pointer to remote wakeup filter
 */
#ifndef IFXGETH_RWKFLTRPTR_MAX_TIMEOUT
#define IFXGETH_RWKFLTRPTR_MAX_TIMEOUT     (1000)
#endif

/** \brief MAX wait time for polling the L3/L4 register read/write transfer to complete
 */
#ifndef IFXGETH_L3L4FILTER_MAX_TIMEOUT
#define IFXGETH_L3L4FILTER_MAX_TIMEOUT     (1000)
#endif

/** \brief Number of DMA channels
 */
#define IFXGETH_NUM_DMA_CHANNELS           (8)

/** \brief Number of Ports in Family
 */
#define IFXGETH_NUM_PORTS                  (2)

/** \brief Enables Advanced Prototype APIs. (Temporary hack to protect SoCV testing and enable test development for PSV).
 */
#define IFXGETH_ADVANCED

/** \brief Number of Tx traffic classes in MTL block
 */
#define IFXGETH_NUM_TX_TRAFFIC_CLASSES     (8)

/** \brief Number of Ports in Geth
 */
#define IFXGETH_NUM_PORTS_IN_DEVICE        (2)

/** \brief Geth Port 0 availability
 */
#define IFXGETH_IS_PORT0_AVAILABLE         (TRUE)

/** \brief Geth Port 1 availability
 */
#define IFXGETH_IS_PORT1_AVAILABLE         (TRUE)

/** \brief Availability of Bridge in Geth 0
 */
#define IFXGETH_IS_BRIDGE_AVAILABLE        (TRUE)

/** \brief External Phy Interface maximum Speed support i.e XGMII mode with speed of 5000M
 */
#define IFXGETH_IS_XGMII_SPEED_5000M      (TRUE)

/** \brief Availability of PROTE Config
 */
#define IFXGETH_IS_PROTE_AVAILABLE        (FALSE)

/** \brief Availability of MAC0 APU Config
 */
#define IFXGETH_IS_MAC0APU_AVAILABLE      (TRUE)

/** \brief Availability of Ethernet Bridge Interrupt Status
 */
#define IFXGETH_IS_ETHBRIS_AVAILABLE      (FALSE)
/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available Geth instances
 */
typedef enum
{
    IfxGeth_Index_none = -1,  /**< \brief Not Selected */
    IfxGeth_Index_0    = 0    /**< \brief GETH index 0 */
} IfxGeth_Index;

/** \brief Tx Traffic Class Index
 */
typedef enum
{
    IfxGeth_TxTrafficClass_0 = 0,  /**< \brief Traffic Class 0 */
    IfxGeth_TxTrafficClass_1 = 1,  /**< \brief Traffic Class 1 */
    IfxGeth_TxTrafficClass_2 = 2,  /**< \brief Traffic Class 2 */
    IfxGeth_TxTrafficClass_3 = 3,  /**< \brief Traffic Class 3 */
    IfxGeth_TxTrafficClass_4 = 4,  /**< \brief Traffic Class 4 */
    IfxGeth_TxTrafficClass_5 = 5,  /**< \brief Traffic Class 5 */
    IfxGeth_TxTrafficClass_6 = 6,  /**< \brief Traffic Class 6 */
    IfxGeth_TxTrafficClass_7 = 7   /**< \brief Traffic Class 7 */
} IfxGeth_TxTrafficClass;

/** \brief Tx Traffic Class Type
 */
typedef enum
{
    IfxGeth_TxTrafficClassType_0 = 0,  /**< \brief Traffic Class Type 0 with minimum features supported by H/w */
    IfxGeth_TxTrafficClassType_1 = 1   /**< \brief Traffic Class Type 1 with maximum features supported by H/w */
} IfxGeth_TxTrafficClassType;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
    volatile void             *trafficClassAddress;       /**< \brief Traffic Class Register Group Address */
    IfxGeth_TxTrafficClass     index;                     /**< \brief Traffic Class Index */
    IfxGeth_TxTrafficClassType type;                      /**< \brief Traffic Class Type */
} IfxGeth_TxTrafficClassMap;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap        IfxGeth_cfg_indexMap[IFXGETH_NUM_MODULES];

IFX_EXTERN IFX_CONST IfxGeth_TxTrafficClassMap IfxGeth_cfg_trafficClassMap[IFXGETH_NUM_PORTS][IFXGETH_NUM_TX_TRAFFIC_CLASSES];

#endif /* IFXGETH_CFG_TC4DX_H */
