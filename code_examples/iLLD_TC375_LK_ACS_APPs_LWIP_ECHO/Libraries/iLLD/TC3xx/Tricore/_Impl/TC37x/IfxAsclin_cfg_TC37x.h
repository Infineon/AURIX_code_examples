/**
 * \file IfxAsclin_cfg_TC37x.h
 * \brief ASCLIN on-chip implementation data
 * \ingroup IfxLld_Asclin
 *
 * \version iLLD_1_22_0
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
 * \defgroup IfxLld_Asclin ASCLIN
 * \ingroup IfxLld
 * \defgroup IfxLld_Asclin_Impl Implementation
 * \ingroup IfxLld_Asclin
 * \defgroup IfxLld_Asclin_Std Standard Driver
 * \ingroup IfxLld_Asclin
 * \defgroup IfxLld_Asclin_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Asclin_Impl
 */

#ifndef IFXASCLIN_CFG_TC37X_H
#define IFXASCLIN_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxAsclin_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXASCLIN_NUM_MODULES (12)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Asclin_Impl_Enumerations
 * \{ */
/** \brief List of the available Asclin resources
 */
typedef enum
{
    IfxAsclin_Index_none = -1,  /**< \brief Not Selected */
    IfxAsclin_Index_0    = 0,   /**< \brief ASCLIN Index 0  */
    IfxAsclin_Index_1,          /**< \brief ASCLIN Index 1  */
    IfxAsclin_Index_2,          /**< \brief ASCLIN Index 2  */
    IfxAsclin_Index_3,          /**< \brief ASCLIN Index 3  */
    IfxAsclin_Index_4,          /**< \brief ASCLIN Index 4  */
    IfxAsclin_Index_5,          /**< \brief ASCLIN Index 5  */
    IfxAsclin_Index_6,          /**< \brief ASCLIN Index 6  */
    IfxAsclin_Index_7,          /**< \brief ASCLIN Index 7  */
    IfxAsclin_Index_8,          /**< \brief ASCLIN Index 8  */
    IfxAsclin_Index_9,          /**< \brief ASCLIN Index 9  */
    IfxAsclin_Index_10,         /**< \brief ASCLIN Index 10  */
    IfxAsclin_Index_11          /**< \brief ASCLIN Index 11  */
} IfxAsclin_Index;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxAsclin_cfg_indexMap[IFXASCLIN_NUM_MODULES];

#endif /* IFXASCLIN_CFG_TC37X_H */
