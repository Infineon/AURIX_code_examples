/**
 * \file IfxGpt12_cfg_TC48x.h
 * \brief GPT12 on-chip implementation data
 * \ingroup IfxLld_Gpt12
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
 * \defgroup IfxLld_Gpt12 GPT12
 * \ingroup IfxLld
 * \defgroup IfxLld_Gpt12_Impl Implementation
 * \ingroup IfxLld_Gpt12
 * \defgroup IfxLld_Gpt12_Std Standard Driver
 * \ingroup IfxLld_Gpt12
 */

#ifndef IFXGPT12_CFG_TC48X_H
#define IFXGPT12_CFG_TC48X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxGpt12_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Modules
 */
#define IFXGPT12_NUM_MODULES (4)

/** \brief Timer T3 Incremental Interface Edge Detection Mode select
 */
#define IFXGPT12_TIMER_T3_MODE_EDGE_DETECTION (TRUE)

/** \brief Timer T2 and T4 Interrupt Disable
 */
#define IFXGPT12_TIMER_INTERRUPT_DISABLE (FALSE)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available GPT12 Resources
 */
typedef enum
{
    IfxGpt12_Index_none = -1,  /**< \brief Not Selected */
    IfxGpt12_Index_0    = 0,   /**< \brief GPT12 index 0 */
    IfxGpt12_Index_1    = 1,   /**< \brief GPT12 index 1 */
    IfxGpt12_Index_2    = 2,   /**< \brief GPT12 index 2 */
    IfxGpt12_Index_3    = 3    /**< \brief GPT12 index 3 */
} IfxGpt12_Index;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxGpt12_cfg_indexMap[IFXGPT12_NUM_MODULES];

#endif /* IFXGPT12_CFG_TC48X_H */
