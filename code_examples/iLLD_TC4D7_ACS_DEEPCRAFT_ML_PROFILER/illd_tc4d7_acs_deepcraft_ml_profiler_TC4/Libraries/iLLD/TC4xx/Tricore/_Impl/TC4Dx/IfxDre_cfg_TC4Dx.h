/**
 * \file IfxDre_cfg_TC4Dx.h
 * \brief DRE on-chip implementation data
 * \ingroup IfxLld_Dre
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
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
 * \defgroup IfxLld_Dre DRE
 * \ingroup IfxLld
 * \defgroup IfxLld_Dre_Impl Implementation Interface
 * \ingroup IfxLld_Dre
 * \defgroup IfxLld_Dre_Std Standard Interface
 * \ingroup IfxLld_Dre
 * \defgroup IfxLld_Dre_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Dre_Impl
 */

#ifndef IFXDRE_CFG_TC4DX_H
#define IFXDRE_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxDre_reg.h"
#include "IfxDre_bf.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of DRE modules
 */
#define IFXDRE_NUM_MODULES           (1)

/** \brief Number of Destination Memory
 */
#define IFXDRE_NUM_DMEM              (28)

/** \brief Number of Stream Id Filters
 */
#define IFXDRE_NUM_STREAM_ID_FILTERS (8)

/** \brief CAD Element Offset
 */
#define IFXDRE_CAD_CAN_OFFSET        (8)

/** \brief DMEM Parameter Element Offset
 */
#define IFXDRE_DMEM_PARAM_OFFSET     (16)

/** \brief Number of EIBUF Buffers
 */
#define IFXDRE_NUM_EIBUF_BUFFERS     (6)

/** \brief Number of EOBUF Buffers
 */
#define IFXDRE_NUM_EOBUF_BUFFERS     (6)

/** \brief Offset of Routing Table Start Address from DRE Module Address (DRE RAM Start Address (0x8000) + RT Offset (0x1AE0) in RAM)
 */
#define IFXDRE_RT_START_OFFSET       (0x9AE0)

/** \brief Offset of DMEM Parameter Table Start Address from DRE Module Address (DRE RAM Start Address (0x8000) + DMEM Parameter Table Offset (0x7A40) in RAM)
 */
#define IFXDRE_DMEM_PARAM_TABLE_START_OFFSET       (0x0FA40)

/** \brief Offset of Ethernet Address Database Start Address from DRE Module Address (DRE RAM Start Address (0x8000) + Ethernet Address Database Offset (0x2AE0) in RAM)
 */
#define IFXDRE_EAD_START_OFFSET      (0x0AAE0)

/** \brief Offset of Ethernet Forwarding Table Start Address from DRE Module Address (DRE RAM Start Address (0x8000) + Ethernet Forwarding Table Offset (0x7640) in RAM)
 */
#define IFXDRE_FT_START_OFFSET       (0xF640)

/** \brief Value to clear DMEM Status register
 */
#define IFXDRE_DMEM_STATUS_CLEAR     (0x170001)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Dre_Impl_Enumerations
 * \{ */
/** \brief List of the available Dre resources
 */
typedef enum
{
    IfxDre_Index_none = -1,  /**< \brief Not Selected */
    IfxDre_Index_0    = 0    /**< \brief DRE index 0 */
} IfxDre_Index;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxDre_cfg_indexMap[IFXDRE_NUM_MODULES];

#endif /* IFXDRE_CFG_TC4DX_H */
