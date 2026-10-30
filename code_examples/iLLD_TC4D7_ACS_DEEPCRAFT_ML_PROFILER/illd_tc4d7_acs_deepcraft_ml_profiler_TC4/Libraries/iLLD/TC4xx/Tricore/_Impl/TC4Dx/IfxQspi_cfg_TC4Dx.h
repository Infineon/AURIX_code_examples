/**
 * \file IfxQspi_cfg_TC4Dx.h
 * \brief QSPI on-chip implementation data
 * \ingroup IfxLld_Qspi
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
 * \defgroup IfxLld_Qspi QSPI
 * \ingroup IfxLld
 * \defgroup IfxLld_Qspi_Impl Implementation
 * \ingroup IfxLld_Qspi
 * \defgroup IfxLld_Qspi_Std Standard Driver
 * \ingroup IfxLld_Qspi
 * \defgroup IfxLld_Qspi_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Qspi_Impl
 */

#ifndef IFXQSPI_CFG_TC4DX_H
#define IFXQSPI_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxQspi_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Depth of the HW FIFO
 */
#define IFXQSPI_HWFIFO_DEPTH (8)

/** \brief Number of Modules
 */
#define IFXQSPI_NUM_MODULES  (8)

/** \brief Number of channels
 */
#define IFXQSPI_NUM_CHANNELS (16)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available QSPI resources
 */
typedef enum
{
    IfxQspi_Index_none = -1,  /**< \brief Not Selected */
    IfxQspi_Index_0    = 0,   /**< \brief QSPI index 0 */
    IfxQspi_Index_1    = 1,   /**< \brief QSPI index 1 */
    IfxQspi_Index_2    = 2,   /**< \brief QSPI index 2 */
    IfxQspi_Index_3    = 3,   /**< \brief QSPI index 3 */
    IfxQspi_Index_4    = 4,   /**< \brief QSPI index 4 */
    IfxQspi_Index_5    = 5,   /**< \brief QSPI index 5 */
    IfxQspi_Index_6    = 6,   /**< \brief QSPI index 6 */
    IfxQspi_Index_7    = 7    /**< \brief QSPI index 7 */
} IfxQspi_Index;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxQspi_cfg_indexMap[IFXQSPI_NUM_MODULES];

#endif /* IFXQSPI_CFG_TC4DX_H */
