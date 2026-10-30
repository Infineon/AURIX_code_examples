/**
 * \file IfxCcu6_cfg_TC37x.h
 * \brief CCU6 on-chip implementation data
 * \ingroup IfxLld_Ccu6
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
 * \defgroup IfxLld_Ccu6 CCU6
 * \ingroup IfxLld
 * \defgroup IfxLld_Ccu6_Impl Implementation
 * \ingroup IfxLld_Ccu6
 * \defgroup IfxLld_Ccu6_Std Standard Driver
 * \ingroup IfxLld_Ccu6
 * \defgroup IfxLld_Ccu6_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Ccu6_Impl
 */

#ifndef IFXCCU6_CFG_TC37X_H
#define IFXCCU6_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxCcu6_reg.h"
#include "IfxCcu6_bf.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXCCU6_NUM_MODULES          (2)

#define IFXCCU6_NUM_SERVICE_REQUESTS (4)

#define IFXCCU6_NUM_T12_CHANNELS     (3)

#define IFXCCU6_NUM_T13_CHANNELS     (1)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available CCU6 resources
 */
typedef enum
{
    IfxCcu6_Index_none = -1,  /**< \brief Not Selected */
    IfxCcu6_Index_0    = 0,   /**< \brief CCU6 index 0  */
    IfxCcu6_Index_1           /**< \brief CCU6 index 1  */
} IfxCcu6_Index;

typedef enum
{
    IfxCcu6_TrigOut_0 = IFX_CCU6_MOSEL_TRIG0SEL_OFF,  /**< \brief Output Trigger Select for CCU6061 TRIG0 */
    IfxCcu6_TrigOut_1 = IFX_CCU6_MOSEL_TRIG1SEL_OFF,  /**< \brief Output Trigger Select for CCU6061 TRIG1 */
    IfxCcu6_TrigOut_2 = IFX_CCU6_MOSEL_TRIG2SEL_OFF   /**< \brief Output Trigger Select for CCU6061 TRIG2 */
} IfxCcu6_TrigOut;

typedef enum
{
    IfxCcu6_TrigSel_cout63 = 0,
    IfxCcu6_TrigSel_cc60   = 1,
    IfxCcu6_TrigSel_cc61   = 1,
    IfxCcu6_TrigSel_cc62   = 1,
    IfxCcu6_TrigSel_sr1    = 2,
    IfxCcu6_TrigSel_sr3    = 3
} IfxCcu6_TrigSel;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxCcu6_cfg_indexMap[IFXCCU6_NUM_MODULES];

#endif /* IFXCCU6_CFG_TC37X_H */
