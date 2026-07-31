/**
 * \file IfxEray_cfg_TC4Dx.h
 * \brief ERAY on-chip implementation data
 * \ingroup IfxLld_Eray
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
 * \defgroup IfxLld_Eray ERAY
 * \ingroup IfxLld
 * \defgroup IfxLld_Eray_Impl Implementation
 * \ingroup IfxLld_Eray
 * \defgroup IfxLld_Eray_Std Standard Driver
 * \ingroup IfxLld_Eray
 * \defgroup IfxLld_Eray_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Eray_Impl
 */

#ifndef IFXERAY_CFG_TC4DX_H
#define IFXERAY_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxEray_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Modules
 */
#define IFXERAY_NUM_MODULES  (2)

#define IFXERAY_NUM_SLOTS    (128)

/** \brief Number of Channels
 */
#define IFXERAY_NUM_CHANNELS (4)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Eray_Impl_Enumerations
 * \{ */
/** \brief List of the available Eray resources
 */
typedef enum
{
    IfxEray_Index_none = -1,  /**< \brief Not Selected */
    IfxEray_Index_0    = 0,   /**< \brief ERAY index 0  */
    IfxEray_Index_1           /**< \brief ERAY index 1  */
} IfxEray_Index;

/** \brief Node Id in communication cycle.
 */
typedef enum
{
    IfxEray_NodeId_a    = 0,  /**< \brief Ifx_ERAY Node A */
    IfxEray_NodeId_b    = 1,  /**< \brief Ifx_ERAY Node B */
    IfxEray_NodeId_none = -1  /**< \brief None of the Ifx_ERAY Nodes */
} IfxEray_NodeId;

/** \} */

/** \addtogroup IfxLld_Eray_Impl_Enumerations
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxEray_cfg_indexMap[IFXERAY_NUM_MODULES];

/** \} */

#endif /* IFXERAY_CFG_TC4DX_H */
