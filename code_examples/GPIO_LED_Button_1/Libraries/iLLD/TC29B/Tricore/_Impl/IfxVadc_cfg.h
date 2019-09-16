/**
 * \file IfxVadc_cfg.h
 * \brief VADC on-chip implementation data 
 * \ingroup IfxLld_Vadc 
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Vadc VADC
 * \ingroup IfxLld
 * \defgroup IfxLld_Vadc_Impl Implementation
 * \ingroup IfxLld_Vadc
 * \defgroup IfxLld_Vadc_Std Standard Driver
 * \ingroup IfxLld_Vadc
 */

#ifndef IFXVADC_CFG_H
#define IFXVADC_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of ADC Groups 
 */
#define IFXVADC_NUM_ADC_GROUPS (11)
                
/** \brief Number of calibrated ADC Groups 
 */
#define IFXVADC_NUM_ADC_CAL_GROUPS (11)
                
/** \brief Maximum allowed analog frequency 
 */
#define IFXVADC_ANALOG_FREQUENCY_MAX (20000000)
                
/** \brief Minimum allowed analog frequency 
 */
#define IFXVADC_ANALOG_FREQUENCY_MIN (500000)
                
/** \brief Default analog frequency used in initModuleConfig function 
 */
#define IFXVADC_DEFAULT_ANALOG_FREQ (20000000)
                
/** \brief Number of Conversion request Slots 
 */
#define IFXVADC_NUM_REQUESTSLOTS (3)
                
/** \brief Number of group specific Input Class 
 */
#define IFXVADC_NUM_INPUTCLASSES (2)
                
/** \brief Maximum number of configurable bitfields in ACCPROT0 register 
 */
#define IFXVADC_MAXIMUM_BITFIELDS_IN_ACCPROT0_REGISTER (32)
                
#define IFXVADC_QUEUE_REFILL (1 << IFX_VADC_G_QBUR0_RF_OFF)
                
/** \brief Number of ADC group input classes. 
 */
#define IFXVADC_NUM_GLOBAL_INPUTCLASSES (2)
                
#define IFXVADC_NUM_ADC_COMMON_GROUPS (2)
                
#define IFXVADC_SAMPLETIME_MIN (2)
                
#define IFXVADC_NUM_EMUX_INTERFACE (2)
                
#define IFXVADC_NUM_MODULES (1)
                


/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief VADC Groups  
 */
typedef enum
{
    IfxVadc_GroupId_0,           /**< \brief VADC group 0  */
    IfxVadc_GroupId_1,           /**< \brief VADC group 1  */
    IfxVadc_GroupId_2,           /**< \brief VADC group 2  */
    IfxVadc_GroupId_3,           /**< \brief VADC group 3  */
    IfxVadc_GroupId_4,           /**< \brief VADC group 4  */
    IfxVadc_GroupId_5,           /**< \brief VADC group 5  */
    IfxVadc_GroupId_6,           /**< \brief VADC group 6  */
    IfxVadc_GroupId_7,           /**< \brief VADC group 7  */
    IfxVadc_GroupId_8,           /**< \brief VADC group 8  */
    IfxVadc_GroupId_9,           /**< \brief VADC group 9  */
    IfxVadc_GroupId_10,          /**< \brief VADC group 10  */
    IfxVadc_GroupId_global0,     /**< \brief VADC group global0  */
    IfxVadc_GroupId_global1      /**< \brief VADC group global1  */
} IfxVadc_GroupId;


/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST uint32 IfxVadc_cfg_srcAddresses[(IFXVADC_NUM_ADC_GROUPS *4) + (IFXVADC_NUM_ADC_COMMON_GROUPS * 4) ];


#endif /* IFXVADC_CFG_H */
