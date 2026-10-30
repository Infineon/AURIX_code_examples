/**
 * \file IfxSmu_Smu.h
 * \brief SMU SMU details
 * \ingroup IfxLld_Smu
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Smu_Smu_Usage How to use the Smu Interface driver?
 * \ingroup IfxLld_Smu_Smu
 *
 * The SMU is a central component of the safety architecture providing a generic interface to manage the behavior
 * of the microcontroller under the presence of faults. The SMU centralizes all the alarm signals related to the
 * different hardware and software-based safety mechanisms. Each alarm can be individually configured to trigger
 * internal actions and/or notify externally the presence of faults via a fault signaling protocol.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Smu_Smu_Preparation Preparation
 * \subsection IfxLld_Smu_Smu_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Smu/Smu/IfxSmu_Smu.h>
 * #include <IfxSrc.h>
 * #include <IfxSmu_cfg.h>
 * #include <IfxPort.h>
 * \endcode
 *
 * \subsection IfxLld_Smu_Smu_Variables Variables
 *
 * Declare Smu module handle in to your C code:
 * \code
 *    IfxSmu_Smu_Config config;
 * \endcode
 *
 *  Declare global variables in to your C code:
 * \code
 *    uint32 alarmGroupCF2;
 *    uint32 alarmGroupCF1;
 *    uint32 alarmGroupCF0;
 * \endcode
 *
 * \subsection IfxLld_Smu_Smu_Interrupt Interrupt Handler Installation
 *
 * Define priorities for the Interrrupt handler. This is normally done in the Ifx_IntPrioDef.h file:
 * \code
 *  #define ISR_PRIORITY_SMU_INT0   10
 * \endcode
 *
 * The following Macros into your C code:
 * \code
 *  #define LED                     &MODULE_P33,4
 *  #define ALARM_GROUP             (IfxSmu_Alarm_Software_Alarm0 / 32)
 *  #define ALARM_POSITION          (IfxSmu_Alarm_Software_Alarm0 % 32)
 * \endcode
 *
 * Add the interrupt service routines to your C code. They have to call the Smu interrupt handlers by passing the ISR_SMU handle:
 * \code
 * IFX_INTERRUPT(ISR_SMU, 0, ISR_PRIORITY_SMU_INT0);
 * \endcode
 *
 * Add the interrupt service routines to your C code. In case of an alarm, an LED is turned ON inside the Interrupt Service Routine and the port emergency stop is activated.
 * \code
 *    void ISR_SMU(void)
 *    {
 *	    IfxSmu_clearAlarmStatus(IfxSmu_Alarm_Software_Alarm0);
 *	    IfxSmu_clearAlarmExecutedStatus(IfxSmu_AlarmExecutionStatus_irq0);
 *	    IfxPort_setPinState(LED, IfxPort_State_low);
 *    }
 * \endcode
 *
 * \subsection IfxLld_Smu_Smu_Init Module Initialisation
 *
 * Initialize the Smu with following code:
 * \code
 *    IfxPort_setPinState(LED, IfxPort_State_high);
 *    IfxPort_setPinMode(LED, IfxPort_Mode_outputPushPullGeneral);
 *    IfxSmu_Smu_initModuleConfig(&config);
 *    // Set the IGCS0 field of AGC register to 1 to trigger SMU Interrupt Request 0
 *    config.alarmGlobalConfig.igcs0 = 1;
 *    // Enable the SMU Port Emergency Stop and SMU_IGCS0 activates the PES
 *    config.alarmGlobalConfig.portEmergencyStop = 1;
 *    // Alarm action configuration for 3 CFG registers
 *    alarmGroupCF0 = (IfxSmu_InternalAlarmAction_igcs0 & 0x01) << ALARM_POSITION;
 *    alarmGroupCF1 = ((IfxSmu_InternalAlarmAction_igcs0 >> 1) & 0x01) << ALARM_POSITION;
 *    alarmGroupCF2 = ((IfxSmu_InternalAlarmAction_igcs0 >> 2) & 0x01) << ALARM_POSITION;
 *    config.alarmConfigRegister[ALARM_GROUP][0] = alarmGroupCF0;
 *    config.alarmConfigRegister[ALARM_GROUP][1] = alarmGroupCF1;
 *    config.alarmConfigRegister[ALARM_GROUP][2] = alarmGroupCF2;
 *    IfxSmu_Smu_initModule(&config);
 * \endcode
 *
 * The Smu is ready for use now!
 *
 * \subsection IfxLld_IfxSMU_Emergency_Stop  triggers software alarm
 *
 * The Safety Management Unit (SMU) is configured to trigger an interrupt if an internal software alarm occurs.
 * \code
 *    // Get source pointer of SMU Service Request 0 in order to initialize and enable it
 *    volatile Ifx_SRC_SRCR *src = &SRC_SMU0;
 *    IfxSrc_init(src, IfxSrc_Tos_cpu0, ISR_PRIORITY_SMU_INT0);
 *    IfxSrc_enable(src);
 *    IfxSmu_activateRunState();
 *    // This function triggers the Software Alarm 0
 *    IfxSmu_setAlarmStatus(IfxSmu_Alarm_Software_Alarm0);
 * \endcode
 *
 * \defgroup IfxLld_Smu_Smu SMU
 * \ingroup IfxLld_Smu
 * \defgroup IfxLld_Smu_Smu_DataStructures Data Structures
 * \ingroup IfxLld_Smu_Smu
 * \defgroup IfxLld_Smu_Smu_SmuFunctions Smu Functions
 * \ingroup IfxLld_Smu_Smu
 */

#ifndef IFXSMU_SMU_H
#define IFXSMU_SMU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Smu/Std/IfxSmu.h"
#include "_Impl/IfxSmu_cfg.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Smu_Smu_DataStructures
 * \{ */
/** \brief Alarm Global Configuration
 */
typedef struct
{
    uint8   igcs0;                            /**< \brief AGC.B.IGCS0. Range: 0 to 7. */
    uint8   igcs1;                            /**< \brief AGC.B.IGCS1. Range: 0 to 7. */
    uint8   igcs2;                            /**< \brief AGC.B.IGCS2. Range: 0 to 7. */
    uint8   resetConfigSet;                   /**< \brief AGC.B.RCS. Range: 0 to 63. */
    uint8   portEmergencyStop;                /**< \brief AGC.B.PES. Range: 0 to 31. */
    boolean enableFaultToRunTransition;       /**< \brief AGC.B.EFRST. Range: TRUE if FAULT to RUN State Transition enabled, FALSE if FAULT to RUN State Transition disabled. */
} IfxSmu_Smu_AlarmGlobalConfiguration;

/** \brief FSP configuration
 */
typedef struct
{
    IfxSmu_FspPrescalar1 prescalar1;                   /**< \brief FSP.B.PRE1 */
    IfxSmu_FspPrescalar2 prescalar2;                   /**< \brief FSP.B.PRE2 */
    IfxSmu_FspMode       mode;                         /**< \brief Fault signaling protocol modes configuration */
    boolean              portEmergencyStop;            /**< \brief FSP.B.PES. Range: TRUE port emergency Stop enabled, FALSE port emergency stop disabled. */
    uint16               faultStateDurationHigh;       /**< \brief FSP.B.TFSP_HIGH. Range: 0 t0 0x3FF. */
    uint16               faultStateDurationLow;        /**< \brief FSP.B.TFSP_LOW.  Range: 0 t0 0x3FFF. */
} IfxSmu_Smu_FaultSignalingProtocol;

/** \brief Recovery Timer/s Alarm Configuration
 */
typedef struct
{
    uint8 groupIndex0;  /**< \brief Group Index 0. Range: 0 to 15. */
    uint8 alarmId0;     /**< \brief Alarm Identifier 0. Range: 0 to 31. */
    uint8 groupIndex1;  /**< \brief Group Index 1. Range: 0 to 15. */
    uint8 alarmId1;     /**< \brief Alarm Identifier 1. Range: 0 to 31. */
    uint8 groupIndex2;  /**< \brief Group Index 2. Range: 0 to 15. */
    uint8 alarmId2;     /**< \brief Alarm Identifier 2. Range: 0 to 31. */
    uint8 groupIndex3;  /**< \brief Group Index 3. Range: 0 to 15. */
    uint8 alarmId3;     /**< \brief Alarm Identifier 3. Range: 0 to 31. */
} IfxSmu_Smu_RecoveryTimerAlarmConfiguration;

/** \brief Recovery Timer Configuration
 */
typedef struct
{
    boolean enableRecoveryTimer0;        /**< \brief RTC.B.RT0E. Range: TRUE if Recovery timer 0 is enabled, FALSE if Recovery Timer 0 is disabled. */
    boolean enableRecoveryTimer1;        /**< \brief RTC.B.RT1E. Range: TRUE if Recovery timer 1 is enabled, FALSE if Recovery Timer 1 is disabled. */
    uint32  recoveryTimerDuration;       /**< \brief RTC.B.RTD. Range: 0 to 0xFFFFFF. */
} IfxSmu_Smu_RecoveryTimerConfig;

/** \} */

/** \addtogroup IfxLld_Smu_Smu_DataStructures
 * \{ */
/** \brief SMU configuration structure
 */
typedef struct
{
    IfxSmu_Smu_FaultSignalingProtocol          fsp;                                                   /**< \brief FSP configuration */
    IfxSmu_Smu_AlarmGlobalConfiguration        alarmGlobalConfig;                                     /**< \brief Alarm Global Configuration */
    IfxSmu_Smu_RecoveryTimerConfig             recoveryTimerConfig;                                   /**< \brief Recovery Timer Configuration */
    IfxSmu_Smu_RecoveryTimerAlarmConfiguration recoveryTimerAlarmConfig[2];                           /**< \brief recovery Timer Alarm 0/1 configuration */
    uint32                                     alarmConfigRegister[IFXSMU_NUM_ALARM_GROUPS][3];       /**< \brief AGCF. Range: 0 to 0xFFFFFFFF. */
    uint32                                     fspConfigRegister[IFXSMU_NUM_ALARM_GROUPS];            /**< \brief AGFSP. Range: 0 to 0xFFFFFFFF. */
} IfxSmu_Smu_Config;

/** \} */

/** \addtogroup IfxLld_Smu_Smu_SmuFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the SMU Module configuration structure with default values.
 *
 * \param[inout] config Pointer to SMU configuration structure.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSmu_Smu_initModuleConfig(IfxSmu_Smu_Config *config);

/**
 * \brief Initializes the SMU (Safety Management Unit) module with the provided configuration.
 *
 * \param[in] config Pointer to SMU configuration structure.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSmu_Smu_initModule(IfxSmu_Smu_Config *config);

/**
 * \brief Checks if any alarm is currently triggered.
 * 
 * \retval TRUE If any alarm is currently active.
 *         FALSE If no alarms are active.
 * 
 */
IFX_EXTERN boolean IfxSmu_Smu_isAlarmTriggered(void);

/** \} */

#endif /* IFXSMU_SMU_H */
