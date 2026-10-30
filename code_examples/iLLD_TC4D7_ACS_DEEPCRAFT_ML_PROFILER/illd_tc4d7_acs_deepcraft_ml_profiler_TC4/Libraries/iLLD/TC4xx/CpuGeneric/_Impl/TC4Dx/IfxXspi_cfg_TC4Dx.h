/**
 * \file IfxXspi_cfg_TC4Dx.h
 * \brief XSPI on-chip implementation data
 * \ingroup IfxLld_Xspi
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
 * \defgroup IfxLld_Xspi Xspi
 * \ingroup IfxLld
 * \defgroup IfxLld_Xspi_Impl Implementation
 * \ingroup IfxLld_Xspi
 * \defgroup IfxLld_Xspi_Std Standard Driver
 * \ingroup IfxLld_Xspi
 * \defgroup IfxLld_Xspi_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Xspi_Impl
 */

#ifndef IFXXSPI_CFG_TC4DX_H
#define IFXXSPI_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxXspi_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXXSPI_NUM_MODULES         (1)

#ifndef IFXXSPI_WRITE_CMD_VALUE
#define IFXXSPI_WRITE_CMD_VALUE     (0x20000000)
#endif

#ifndef IFXXSPI_WRITE_CMD_MASK
#define IFXXSPI_WRITE_CMD_MASK      (0xFFFFFFF8)
#endif

#ifndef IFXXSPI_WRITE_ADDR_VALUE
#define IFXXSPI_WRITE_ADDR_VALUE    (0x0000)
#endif

#ifndef IFXXSPI_WRITE_ADDR_MASK
#define IFXXSPI_WRITE_ADDR_MASK     (0x00000007)
#endif

#ifndef IFXXSPI_WRITE_SHIFT
#define IFXXSPI_WRITE_SHIFT         (3)
#endif

#ifndef IFXXSPI_READ_CMD_VALUE
#define IFXXSPI_READ_CMD_VALUE      (0xA0000000)
#endif

#ifndef IFXXSPI_READ_CMD_MASK
#define IFXXSPI_READ_CMD_MASK       (0xFFFFFFF8)
#endif

#ifndef IFXXSPI_READ_ADDR_VALUE
#define IFXXSPI_READ_ADDR_VALUE     (0x0000)
#endif

#ifndef IFXXSPI_READ_ADDR_MASK
#define IFXXSPI_READ_ADDR_MASK      (0x00000007)
#endif

#ifndef IFXXSPI_READ_SHIFT
#define IFXXSPI_READ_SHIFT          (3)
#endif

#ifndef IFXXSPI_INTERRUPT_CFG
#define IFXXSPI_INTERRUPT_CFG       (1)
#endif

#ifndef IFXXSPI_UM_RECOMMENDATION
#define IFXXSPI_UM_RECOMMENDATION   (1)
#endif

#ifndef IFXXSPI_COMPUTE_TXSTARTFIFO
#define IFXXSPI_COMPUTE_TXSTARTFIFO (1)
#endif
#ifndef IFXXSPI_XIP_REGION0_LOWER
#define IFXXSPI_XIP_REGION0_LOWER   (0x98000000)
#endif

#ifndef IFXXSPI_XIP_REGION0_UPPER
#define IFXXSPI_XIP_REGION0_UPPER   (0x9FFFFFFF)
#endif

#ifndef IFXXSPI_XIP_REGION1_LOWER   
#define IFXXSPI_XIP_REGION1_LOWER   (0xB8000000)
#endif

#ifndef IFXXSPI_XIP_REGION1_UPPER   
#define IFXXSPI_XIP_REGION1_UPPER   (0xBFFFFFFF)
#endif

/** \brief MAX TX FIFO  LEVEL
 */
#define IFXXSPI_MAX_TXFIFO_LEVEL    (15)

#define IFXXSPI_XIPDATAWRITE_SUPPORT      (FALSE)

#define IFXXSPI_IS_PORT_11_AVAILABLE      (FALSE)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Xspi_Impl_Enumerations
 * \{ */
/** \brief List of the available Xspi resources
 */
typedef enum
{
    IfxXspi_Index_none = -1,  /**< \brief Not Selected */
    IfxXspi_Index_0    = 0,   /**< \brief XSPI Index 0  */
} IfxXspi_Index;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxXspi_cfg_indexMap[IFXXSPI_NUM_MODULES];

#endif /* IFXXSPI_CFG_TC4DX_H */
