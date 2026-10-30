/**
 * \file IfxEvadc_cfg_TC37x.h
 * \brief EVADC on-chip implementation data
 * \ingroup IfxLld_Evadc
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
 * \defgroup IfxLld_Evadc EVADC
 * \ingroup IfxLld
 * \defgroup IfxLld_Evadc_Impl Implementation
 * \ingroup IfxLld_Evadc
 * \defgroup IfxLld_Evadc_Std Standard Driver
 * \ingroup IfxLld_Evadc
 */

#ifndef IFXEVADC_CFG_TC37X_H
#define IFXEVADC_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of ADC Groups
 */
#define IFXEVADC_NUM_ADC_GROUPS                         (IFXEVADC_NUM_ADC_PRIMARY_GROUPS + IFXEVADC_NUM_ADC_SECONDARY_GROUPS)

/** \brief Number of calibrated ADC Groups
 */
#define IFXEVADC_NUM_ADC_CAL_GROUPS                     (12)

/** \brief Maximum allowed analog frequency for 5 V supply (GLOBCFG.SUPLEV = 00B or 01B)
 */
#define IFXEVADC_ANALOG_FREQUENCY_MAX_5V                (53333333)

/** \brief Minimum allowed analog frequency for 5 V supply (GLOBCFG.SUPLEV = 00B or 01B)
 */
#define IFXEVADC_ANALOG_FREQUENCY_MIN_5V                (16000000)

/** \brief Maximum allowed analog frequency for 3.3 V supply (GLOBCFG.SUPLEV = 10B)
 */
#define IFXEVADC_ANALOG_FREQUENCY_MAX_3V3               (26666666)

/** \brief Minimum allowed analog frequency for 3.3 V supply (GLOBCFG.SUPLEV = 10B)
 */
#define IFXEVADC_ANALOG_FREQUENCY_MIN_3V3               (16000000)

/** \brief Default analog frequency used in initModuleConfig function
 */
#define IFXEVADC_DEFAULT_ANALOG_FREQ                    (20000000)

/** \brief Number of Conversion request Slots
 */
#define IFXEVADC_NUM_REQUESTSLOTS                       (3)

/** \brief Number of group specific Input Class
 */
#define IFXEVADC_NUM_INPUTCLASSES                       (2)

/** \brief Maximum number of configurable bitfields in ACCPROT0 register
 */
#define IFXEVADC_MAXIMUM_BITFIELDS_IN_ACCPROT0_REGISTER (32)

#define IFXEVADC_QUEUE_REFILL                           (1 << IFX_EVADC_G_Q_QINR_RF_OFF)

/** \brief Number of ADC group input classes.
 */
#define IFXEVADC_NUM_GLOBAL_INPUTCLASSES                (2)

#define IFXEVADC_MAXIMUM_BITFIELDS_IN_ACCPROT1_REGISTER (64)

/** \brief number of  primary Groups
 */
#define IFXEVADC_NUM_ADC_PRIMARY_GROUPS                 (4)

/** \brief Secondary Group
 */
#define IFXEVADC_NUM_ADC_SECONDARY_GROUPS               (4)

/** \brief Fast Compare Channel
 */
#define IFXEVADC_NUM_FAST_COMPARE_CHANNELS              (4)

/** \brief Common Group
 */
#define IFXEVADC_NUM_ADC_COMMON_GROUPS                  (2)

#define IFXEVADC_SAMPLETIME_MIN                         (2)

/** \brief Number of channels in primary group
 */
#define IFXEVADC_NUM_CHAN_PER_PRIM_GROUP                (32)

/** \brief Number of channels in secondary group
 */
#define IFXEVADC_NUM_CHAN_PER_SEC_GROUP                 (64)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief VADC Groups
 */
typedef enum
{
    IfxEvadc_GroupId_0       = 0,   /**< \brief EVADC Group 0(Primary Group 0) */
    IfxEvadc_GroupId_1       = 1,   /**< \brief EVADC Group 1(Primary Group 1) */
    IfxEvadc_GroupId_2       = 2,   /**< \brief EVADC Group 2(Primary Group 2) */
    IfxEvadc_GroupId_3       = 3,   /**< \brief EVADC Group 3(Primary Group 3) */
    IfxEvadc_GroupId_8       = 8,   /**< \brief EVADC Group 8(Secondary Group 0) */
    IfxEvadc_GroupId_9       = 9,   /**< \brief EVADC Group 9(Secondary Group 1) */
    IfxEvadc_GroupId_10      = 10,  /**< \brief EVADC Group 10(Secondary Group 2) */
    IfxEvadc_GroupId_11      = 11,  /**< \brief EVADC Group 11(Secondary Group 3) */
    IfxEvadc_GroupId_12      = 12,  /**< \brief EVADC group 12 (Fast compare channel 0) */
    IfxEvadc_GroupId_13      = 13,  /**< \brief EVADC group 13 (Fast compare channel 1) */
    IfxEvadc_GroupId_14      = 14,  /**< \brief EVADC group 14 (Fast compare channel 2) */
    IfxEvadc_GroupId_15      = 15,  /**< \brief EVADC group 15 (Fast compare channel 3) */
    IfxEvadc_GroupId_global0 = 20,  /**< \brief EVADC group global0 */
    IfxEvadc_GroupId_global1 = 21   /**< \brief EVADC group global1 */
} IfxEvadc_GroupId;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxEvadc_cfg_srcAddresses[(IFXEVADC_NUM_ADC_PRIMARY_GROUPS * 4) + (IFXEVADC_NUM_ADC_SECONDARY_GROUPS * 4) + (IFXEVADC_NUM_FAST_COMPARE_CHANNELS * 4) + (IFXEVADC_NUM_ADC_COMMON_GROUPS * 4)];

#endif /* IFXEVADC_CFG_TC37X_H */
