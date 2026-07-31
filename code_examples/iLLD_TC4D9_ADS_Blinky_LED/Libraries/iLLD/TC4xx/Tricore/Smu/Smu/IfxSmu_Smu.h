/**
 * \file IfxSmu_Smu.h
 * \brief SMU SMU details
 * \ingroup IfxLld_Smu
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

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Smu_Smu_DataStructures
 * \{ */
/** \brief Alarm Global Configuration
 */
typedef struct
{
    uint8   igcs0;                             /**< \brief AGC.B.IGCS0. Range: 0 to 7. */
    uint8   igcs1;                             /**< \brief AGC.B.IGCS1. Range: 0 to 7. */
    uint8   igcs2;                             /**< \brief AGC.B.IGCS2. Range: 0 to 7. */
    uint8   resetConfigSet0;                   /**< \brief AGC.B.RCS0. Range: 0 to 31. */
    uint8   resetConfigSet1;                   /**< \brief AGC.B.RCS1. Range: 0 to 31. */
    boolean enableFaultToRunTransition0;       /**< \brief AGC.B.EFRST0. Range: TRUE if FAULT to RUN State Transition0 enabled, FALSE if FAULT to RUN State Transition0 disabled. */
    boolean enableFaultToRunTransition1;       /**< \brief AGC.B.EFRST1. Range: TRUE if FAULT to RUN State Transition1 enabled, FALSE if FAULT to RUN State Transition1 disabled. */
    boolean enableStartToRunState;             /**< \brief AGC.B.ESSM1. Range: TRUE if FAULT to RUN State Transition enabled, FALSE if FAULT to RUN State Transition disabled. */
} IfxSmu_Smu_AlarmGlobalConfiguration;

/** \brief Recovery Timer/s Alarm Configuration
 */
typedef struct
{
    uint8 groupIndex0;    /**< \brief Group Index 0. Range: 0 to 15. */
    uint8 alarmId0;       /**< \brief Alarm Identifier 0. Range: 0 to 31. */
    uint8 groupIndex1;    /**< \brief Group Index 0. Range: 0 to 15. */
    uint8 alarmId1;       /**< \brief Alarm Identifier 0. Range: 0 to 31. */
    uint8 groupIndex2;    /**< \brief Group Index 0. Range: 0 to 15. */
    uint8 alarmId2;       /**< \brief Alarm Identifier 0. Range: 0 to 31. */
    uint8 groupIndex3;    /**< \brief Group Index 0. Range: 0 to 15. */
    uint8 alarmId3;       /**< \brief Alarm Identifier 0. Range: 0 to 31. */
} IfxSmu_Smu_RecoveryTimerAlarmConfiguration;

/** \brief This register controls the timing duration of the recovery timer.
 */
typedef struct
{
    boolean enableRecoveryTimer0;              /**< \brief RT0 Enable Bit. Range: TRUE if Recovery timer 0 is enabled, FALSE if Recovery Timer 0 is disabled. */
    boolean enableRecoveryTimer1;              /**< \brief RT1 Enable Bit. Range: TRUE if Recovery timer 1 is enabled, FALSE if Recovery Timer 1 is disabled. */
    uint8   PrescalarRecoveryTimerClock;       /**< \brief Prescalar For Recovery Timer Clock. Range: 0 to 7. */
    uint32  recoveryTimerDuration;             /**< \brief Recovery Timer Duration. Range: 0 to 0xFFFFFF. */
} IfxSmu_Smu_SafetyRecoveryTimerConfig;

/** \} */

/** \brief This register controls the timing duration of the recovery timer.
 */
typedef struct
{
    boolean enableRecoveryTimer0;              /**< \brief RT0 Enable Bit. Range: TRUE if Recovery timer 0 is enabled, FALSE if Recovery Timer 0 is disabled. */
    uint8   PrescalarRecoveryTimerClock;       /**< \brief Prescalar For Recovery Timer Clock. Range: 0 to 7. */
    uint32  recoveryTimerDuration;             /**< \brief Recovery Timer Duration. Range: 0 to 0xFFFFFF. */
} IfxSmu_Smu_SecurityRecoveryTimerConfig;

/** \addtogroup IfxLld_Smu_Smu_DataStructures
 * \{ */
/** \brief FSP configuration
 */
typedef struct
{
    IfxSmu_FspPrescalar1 prescalar1;                   /**< \brief FSP.B.PRE1 */
    IfxSmu_FspPrescalar2 prescalar2;                   /**< \brief FSP.B.PRE2 */
    IfxSmu_FspMode       mode;                         /**< \brief MODULE_SMU.SAFE[2].FSP[2].CON.B.MODE */
    uint16               faultStateDurationHigh;       /**< \brief FSP.B.TFSP_HIGH. Range: 0 to 0x3FF. */
    uint16               faultStateDurationLow;        /**< \brief FSP.B.TFSP_LOW. Range: 0 to 0x3FFF. */
} IfxSmu_Smu_FaultSignalingProtocol;

/** \} */

/** \brief The global configurations related to AGC, and timers
 */
typedef struct
{
    IfxSmu_Smu_AlarmGlobalConfiguration        alarmGlobalConfig;                 /**< \brief AGC configurations */
    IfxSmu_Smu_SafetyRecoveryTimerConfig       safetyRecoveryTimerConfig;         /**< \brief Safe RTC config */
    IfxSmu_Smu_RecoveryTimerAlarmConfiguration recoveryTimerAlarmConfig[2];       /**< \brief RTC Alarm Configurations */
} IfxSmu_Smu_SafetyGlobalConfig;

/** \brief The global configurations related to AGC, and timers
 */
typedef struct
{
    IfxSmu_Smu_SecurityRecoveryTimerConfig     securityRecoveryTimerConfig;       /**< \brief Secure RTC Config */
    IfxSmu_Smu_RecoveryTimerAlarmConfiguration recoveryTimerAlarmConfig;          /**< \brief Secure RTC Alarm Config */
} IfxSmu_Smu_SecurityGlobalConfig;

/** \addtogroup IfxLld_Smu_Smu_DataStructures
 * \{ */
typedef struct
{
    IfxSmu_Smu_FaultSignalingProtocol fsp[2];                                                          /**< \brief FSP configuration */
    IfxSmu_Smu_SafetyGlobalConfig     globalConfig;                                                    /**< \brief SMU global configuration */
    uint32                            alarmConfigRegister[IFXSMU_NUM_OF_SAFETY_ALARM_GROUPS][4];       /**< \brief SAGC. Range: 0 to 0xFFFFFFFF. */
    uint32                            fspConfigRegister[IFXSMU_NUM_OF_SAFETY_ALARM_GROUPS][2];         /**< \brief AGF. Range: 0 to 0xFFFFFFFF. */
} IfxSmu_Smu_SafetyConfig;

typedef struct
{
    IfxSmu_Smu_SecurityGlobalConfig globalConfig;                                                      /**< \brief Secure Global Config */
    uint32                          alarmConfigRegister[IFXSMU_NUM_OF_SECURITY_ALARM_GROUPS][3];       /**< \brief Secure SAGC. Range: 0 to 0xFFFFFFFF. */
} IfxSmu_Smu_SecurityConfig;

/** \} */

/** \addtogroup IfxLld_Smu_Smu_DataStructures
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Fills the configuration structure of the Security SMU Module with default values.
 *
 * \param[inout] config Configuration structure of the Security module.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_Smu_initSecurityModuleConfig(IfxSmu_Smu_SecurityConfig *config);

/** \} */

/** \addtogroup IfxLld_Smu_Smu_SmuFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Fills the configuration stucture of the Safety SMU Module with default values.
 *
 * \param[inout] config Configuration structure of the module.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_Smu_initSafetyModuleConfig(IfxSmu_Smu_SafetyConfig *config);

/** \brief Initializes the SMU Safety Module.
 *
 * \param[in] config       Configuration structure of the module.
 * \param[in] smuSafeIndex SMU Safe Module ID.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_Smu_initSafetyModule(IfxSmu_Smu_SafetyConfig *config, boolean smuSafeIndex);

/** \brief Check if any alarm is Triggered.
 *
 * \param[in] smuSafeIndex Index number to repersent the Safety SMU module used.
 * \param[in] groupNo      Safety SMU Alarm Group Index. Range: 0 to 16.
 *
 * \retval Returns True if any alarm is set.
 */
IFX_EXTERN boolean IfxSmu_Smu_isSafetyAlarmTriggered(boolean smuSafeIndex, uint8 groupNo);

/** \brief Initializes the Security SMU Module.
 *
 * \param[in] config Configuration structure of the Security module.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_Smu_initSecurityModule(IfxSmu_Smu_SecurityConfig *config);

/** \brief Check if any Security alarm is Triggered.
 *
 * \param[in] groupNo Security SMU Alarma Group number. Range: 0 or 1;
 *
 * \retval Returns True if any alarm is set.
 */
IFX_EXTERN boolean IfxSmu_Smu_isSecurityAlarmTriggered(uint8 groupNo);

/** \brief Check if any alarm is Triggered.
 *
 * \param[in] SharedType   To indicate alarms either configured to security/safety SMU. Range: \ref IfxSmu_SharedType.
 * \param[in] smuSafeIndex SMU safe ID.
 * \param[in] groupNo      SMU Alarm Group. Range: 0 to 16.
 *
 * \retval Return Status Value 0 or 1.
 */
IFX_EXTERN boolean IfxSmu_Smu_isSharedAlarmTriggered(IfxSmu_SharedType SharedType, boolean smuSafeIndex, uint8 groupNo);

/** \brief Initialize the SAFE SMU Global configurations.
 *
 * \param[in] config       SAFE Global config pointer.
 * \param[in] smuSafeIndex SMU SAFE index.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_Smu_initSafetyGlobal(IfxSmu_Smu_SafetyGlobalConfig *config, boolean smuSafeIndex);

/** \brief Initialize the Secure Global configurations.
 *
 * \param[in] config SECURE Global configurations.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_Smu_initSecurityGlobal(IfxSmu_Smu_SecurityGlobalConfig *config);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to configure Shared SMU alarms either to Safety/Security SMUs.
 * If an alarm is already mapped to safety, the user can re-configure it to safety.
 *
 * \param[in] SharedType Type of SMU to be configured for Shared SMU alarms. Range: \ref IfxSmu_SharedType.
 * \param[in] alarm      SMU Alarm ID. Range: \ref IfxSmu_Alarm.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_Smu_setSharedSelectionRegister(IfxSmu_SharedType SharedType, IfxSmu_Alarm alarm);
#endif /* IFXSMU_SMU_H */
