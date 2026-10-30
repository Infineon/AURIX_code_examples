/**
 * \file IfxPcie_cfg_TC4Dx.h
 * \brief PCIE on-chip implementation data
 * \ingroup IfxLld_Pcie
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
 * \defgroup IfxLld_Pcie PCIE
 * \ingroup IfxLld
 * \defgroup IfxLld_Pcie_Impl Implementation
 * \ingroup IfxLld_Pcie
 * \defgroup IfxLld_Pcie_Std Standard Driver
 * \ingroup IfxLld_Pcie
 * \defgroup IfxLld_Pcie_Lib Lib Interface Drivers
 * \ingroup IfxLld_Pcie
 * \defgroup IfxLld_Pcie_Impl_Structures Structures
 * \ingroup IfxLld_Pcie_Impl
 * \defgroup IfxLld_Pcie_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Pcie_Impl
 * \defgroup IfxLld_Pcie_Impl_Variables Variables
 * \ingroup IfxLld_Pcie_Impl
 */

#ifndef IFXPCIE_CFG_TC4DX_H
#define IFXPCIE_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxPcie_dsp_reg.h"
#include "IfxPcie_usp_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of PCIE Modules
 */
#define IFXPCIE_CFG_NUM_MODULES                (2)

/** \brief Number of DMA Read Channels
 */
#define IFXPCIE_CFG_NUM_DMA_READ_CHANNELS      ((uint32)4)

/** \brief Number of DMA Write Channels
 */
#define IFXPCIE_CFG_NUM_DMA_WRITE_CHANNELS     ((uint32)4)

/** \brief 4KB space needed for each function config space
 */
#define IFXPCIE_CFG_FUNCTION_CFG_SPACE         ((uint32)(0x1000u))

/** \brief set this to 1 for CADENCE VIP based RTL test
 */
#ifndef IFXPCIE_CFG_RTL_VIP
#define IFXPCIE_CFG_RTL_VIP                    (0)
#endif

/** \brief set this to 0 to disable PHY. for VP
 */
#ifndef IFXPCIE_CFG_ENABLE_PHY
#define IFXPCIE_CFG_ENABLE_PHY                 (1)
#endif

/** \brief Number of Buses
 */
#ifndef IFXPCIE_CFG_MAX_NUM_OF_BUS
#define IFXPCIE_CFG_MAX_NUM_OF_BUS             (6u)
#endif

/** \brief Number of devices
 */
#ifndef IFXPCIE_CFG_MAX_NUM_OF_DEV
#define IFXPCIE_CFG_MAX_NUM_OF_DEV             (3)
#endif

/** \brief Number of functions per device
 */
#ifndef IFXPCIE_CFG_MAX_NUM_OF_FUN
#define IFXPCIE_CFG_MAX_NUM_OF_FUN             (2)
#endif

/** \brief Max number of EP functions supported totally
 */
#ifndef IFXPCIE_CFG_MAX_NUM_EP
#define IFXPCIE_CFG_MAX_NUM_EP                 ((uint32)(IFXPCIE_CFG_MAX_NUM_OF_BUS * IFXPCIE_CFG_MAX_NUM_OF_DEV * IFXPCIE_CFG_MAX_NUM_OF_FUN))
#endif

/** \brief Max number of Bridges
 */
#ifndef IFXPCIE_CFG_MAX_NUM_BRIDGE
#define IFXPCIE_CFG_MAX_NUM_BRIDGE             ((uint32)(IFXPCIE_CFG_MAX_NUM_OF_BUS - 1))
#endif

/** \brief Primary Bus of RC
 */
#ifndef IFXPCIE_CFG_RC_PRIMARY_BUS
#define IFXPCIE_CFG_RC_PRIMARY_BUS             ((uint8)0)
#endif

/** \brief Subordinate bus default value
 */
#ifndef IFXPCIE_CFG_RC_MAX_SUBORDINATE_BUS
#define IFXPCIE_CFG_RC_MAX_SUBORDINATE_BUS     ((uint8)(IFXPCIE_CFG_RC_PRIMARY_BUS + IFXPCIE_CFG_MAX_NUM_OF_BUS))
#endif

/** \brief Total configuration space needed in PCIE DATA memory per device
 */
#ifndef IFXPCIE_CFG_MAX_FUNC_CONFIG_SPACE
#define IFXPCIE_CFG_MAX_FUNC_CONFIG_SPACE      ((uint32)(IFXPCIE_CFG_FUNCTION_CFG_SPACE * IFXPCIE_CFG_MAX_NUM_OF_FUN))
#endif

/** \brief Total configuration space needed in PCIE DATA memory
 */
#ifndef IFXPCIE_CFG_MAX_CONFIG_MEMORY
#define IFXPCIE_CFG_MAX_CONFIG_MEMORY          ((uint32)(IFXPCIE_CFG_RC_MAX_SUBORDINATE_BUS << 20) + ((uint32)((1 << 20) - 1)))
#endif

/** \brief Maximum EP BARS (in EP device)
 */
#ifndef IFXPCIE_CFG_MAX_NUM_EP_BARS
#define IFXPCIE_CFG_MAX_NUM_EP_BARS            ((uint32)(6))
#endif

/** \brief Maximum EP BARS (in EP device)
 */
#ifndef IFXPCIE_CFG_MAX_NUM_BRIDGE_BARS
#define IFXPCIE_CFG_MAX_NUM_BRIDGE_BARS        ((uint32)(2))
#endif

/** \brief Maximum EP User Configurable BARS (in EP device)
 */
#ifndef IFXPCIE_CFG_MAX_NUM_EP_USER_BARS
#define IFXPCIE_CFG_MAX_NUM_EP_USER_BARS       ((uint32)(IFXPCIE_CFG_MAX_NUM_EP_BARS - 1))
#endif

/** \brief Default size of BAR0 in EP mode
 */
#ifndef IFXPCIE_CFG_BAR0_DEFAULT_SIZE
#define IFXPCIE_CFG_BAR0_DEFAULT_SIZE          ((uint32)0x4000u)
#endif

/** \brief Default size of BAR1-5 in EP mode
 */
#ifndef IFXPCIE_CFG_BAR_DEFAULT_SIZE
#define IFXPCIE_CFG_BAR_DEFAULT_SIZE           ((uint32)0x10000u)
#endif

/** \brief Maximum number of interrupt vectors for one EP
 * Restricted to 8, as we have 8 MSI Interrupt Lines
 * In case of MSI Interrupt mechanism, only one is possible.
 * To make use of more than 1 Interrupt Vector for one EP, use MSIx
 */
#ifndef IFXPCIE_CFG_MAX_NUM_EP_INTVECTORS
#define IFXPCIE_CFG_MAX_NUM_EP_INTVECTORS      ((uint32)8)
#endif

/** \brief Maximum number of MSIX interrupts (Table Size)
 * as Per AURIX EP UM at the moment
 */
#ifndef IFXPCIE_CFG_MAX_NUM_EP_MSIX_INTERRUPTS
#define IFXPCIE_CFG_MAX_NUM_EP_MSIX_INTERRUPTS ((uint32)64)
#endif

/** \brief Maximum number of interrupt vectors for one EP
 * Restricted to 8, as we have 8 MSI Interrupt Lines
 * In case of MSI Interrupt mechanism, only one is possible.
 * To make use of more than 1 Interrupt Vector for one EP, use MSIx
 */
#ifndef IFXPCIE_CFG_MAX_NUM_EP_TRIGVECTORS
#define IFXPCIE_CFG_MAX_NUM_EP_TRIGVECTORS     ((uint32)8)
#endif

/** \brief Maximum number of interrupt triggers to EP
 */
#ifndef IFXPCIE_CFG_MAX_EP_INTTRIGGERS
#define IFXPCIE_CFG_MAX_EP_INTTRIGGERS         ((uint32)32)
#endif

/** \brief Maximum RC BARS
 */
#ifndef IFXPCIE_CFG_MAX_NUM_RC_BARS
#define IFXPCIE_CFG_MAX_NUM_RC_BARS            ((uint32)(2))
#endif

/** \brief ECAM ATU Outbound Region
 */
#ifndef IFXPCIE_CFG_ECAM_ATU_INDEX
#define IFXPCIE_CFG_ECAM_ATU_INDEX             (0)
#endif

/** \brief Wire Memory Base of PCIE Topology
 */
#ifndef IFXPCIE_CFG_WIRE_MEM_BASE
#define IFXPCIE_CFG_WIRE_MEM_BASE              ((uint32)0x00000000u)
#endif

/** \brief Wire Memory Limit of PCIE Topology
 */
#ifndef IFXPCIE_CFG_WIRE_MEM_LIMIT
#define IFXPCIE_CFG_WIRE_MEM_LIMIT             ((uint32)0xFBFFFFFFu)
#endif

/** \brief MSI Reception Address
 */
#ifndef IFXPCIE_CFG_MSI_RECEPTION_ADDRESS
#define IFXPCIE_CFG_MSI_RECEPTION_ADDRESS      (uint64)(0xFFFFFFFCu)
#endif

/** \brief Pre-fetch Wire Memory Base of PCIE Topology
 */
#ifndef IFXPCIE_CFG_PREFETCH_WIRE_MEM_BASE
#define IFXPCIE_CFG_PREFETCH_WIRE_MEM_BASE     ((uint64)0x0000000100000000u)
#endif

/** \brief Pre-fetch Wire Memory Limit of PCIE Topology
 */
#ifndef IFXPCIE_CFG_PREFETCH_WIRE_MEM_LIMIT
#define IFXPCIE_CFG_PREFETCH_WIRE_MEM_LIMIT    ((uint64)0xFFFBFFFFFFFFFFFFu)
#endif

#ifndef IFXPCIE_CFG_MAX_NUM_VSEC_CAP
#define IFXPCIE_CFG_MAX_NUM_VSEC_CAP           ((uint32)0x04u)
#endif

#ifndef IFXPCIE_CFG_CONFIGWRITE_DELAYCOUNT
#define IFXPCIE_CFG_CONFIGWRITE_DELAYCOUNT     (200u)
#endif

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pcie_Impl_Enumerations
 * \{ */
/** \brief List of PCIe resources
 */
typedef enum
{
    IfxPcie_Index_none = -1,  /**< \brief Not Selected */
    IfxPcie_Index_0    = 0,   /**< \brief PCIE0 */
    IfxPcie_Index_1    = 1    /**< \brief PCIE1 */
} IfxPcie_Index;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pcie_Impl_Structures
 * \{ */
typedef struct
{
    uint32 memoryBase;        /**< \brief base address */
    uint32 memoryLimit;       /**< \brief end address */
} IfxPcie_MemoryLimits;

/** \} */

/** \addtogroup IfxLld_Pcie_Impl_Variables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxPcie_MemoryLimits IfxPcie_cfg_memoryMap[IFXPCIE_CFG_NUM_MODULES];

IFX_EXTERN IFX_CONST IfxModule_IndexMap   IfxPcie_cfg_pcieIndexMap[IFXPCIE_CFG_NUM_MODULES];

/** \} */

#endif /* IFXPCIE_CFG_TC4DX_H */
