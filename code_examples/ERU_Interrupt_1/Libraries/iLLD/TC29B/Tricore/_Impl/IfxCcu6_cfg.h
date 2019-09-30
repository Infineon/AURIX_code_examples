/**
 * \file IfxCcu6_cfg.h
 * \brief CCU6 on-chip implementation data
 * \ingroup IfxLld_Ccu6
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
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

#ifndef IFXCCU6_CFG_H
#define IFXCCU6_CFG_H 1

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

#endif /* IFXCCU6_CFG_H */
