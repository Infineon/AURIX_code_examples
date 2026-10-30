/**
 * \file IfxMsc_cfg_TC4Dx.h
 * \brief MSC on-chip implementation data
 * \ingroup IfxLld_Msc
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
 * \defgroup IfxLld_Msc MSC
 * \ingroup IfxLld
 * \defgroup IfxLld_Msc_Impl Implementation
 * \ingroup IfxLld_Msc
 * \defgroup IfxLld_Msc_Std Standard Driver
 * \ingroup IfxLld_Msc
 * \defgroup IfxLld_Msc_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Msc_Impl
 */

#ifndef IFXMSC_CFG_TC4DX_H
#define IFXMSC_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxMsc_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Modules
 */
#define IFXMSC_NUM_MODULES             (1)

#define IFXMSC_NUM_ENABLE_SELECT_LINES (4)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Msc_Impl_Enumerations
 * \{ */
/** \brief List of the available MSC resources
 */
typedef enum
{
    IfxMsc_Index_none = -1,  /**< \brief Not Selected */
    IfxMsc_Index_0    = 0,   /**< \brief MSC index 0  */
} IfxMsc_Index;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxMsc_cfg_indexMap[IFXMSC_NUM_MODULES];

#endif /* IFXMSC_CFG_TC4DX_H */
