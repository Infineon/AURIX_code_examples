/**
 * \file IfxStm_cfg_TC4Dx.h
 * \brief STM on-chip implementation data
 * \ingroup IfxLld_Stm
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
 * \defgroup IfxLld_Stm STM
 * \ingroup IfxLld
 * \defgroup IfxLld_Stm_Impl Implementation
 * \ingroup IfxLld_Stm
 * \defgroup IfxLld_Stm_Std Standard Driver
 * \ingroup IfxLld_Stm
 * \defgroup IfxLld_Stm_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Stm_Impl
 * \defgroup IfxLld_Stm_Impl_Variables Global Variables
 * \ingroup IfxLld_Stm_Impl
 */

#ifndef IFXSTM_CFG_TC4DX_H
#define IFXSTM_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxCpu_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief STM count
 */
#define IFXSTM_NUM_MODULES     7

/** \brief No Of Comparators per Stm
 */
#define IFXSTM_NUM_COMPARATORS (2)

/** \brief Availability of STM HV
 */
#ifndef IFXSTM_IS_STMHV_AVAILABLE
#define IFXSTM_IS_STMHV_AVAILABLE (TRUE)
#endif

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Stm_Impl_Enumerations
 * \{ */
/** \brief List of the available STM resources
 */
typedef enum
{
    IfxStm_Index_none = -1,  /**< \brief Not Selected */
    IfxStm_Index_0    = 0,   /**< \brief STM index 0 */
    IfxStm_Index_1    = 1,   /**< \brief STM index 1 */
    IfxStm_Index_2    = 2,   /**< \brief STM index 2 */
    IfxStm_Index_3    = 3,   /**< \brief STM index 3 */
    IfxStm_Index_4    = 4,   /**< \brief STM index 4 */
    IfxStm_Index_5    = 5,   /**< \brief STM index 5 */
    IfxStm_Index_6    = 6    /**< \brief STM index 6 */
} IfxStm_Index;

/** \} */

/** \addtogroup IfxLld_Stm_Impl_Variables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxStm_cfg_indexMap[IFXSTM_NUM_MODULES];

/** \} */

#endif /* IFXSTM_CFG_TC4DX_H */
