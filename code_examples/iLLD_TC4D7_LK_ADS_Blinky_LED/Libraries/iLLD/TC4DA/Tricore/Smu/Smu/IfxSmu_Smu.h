/**
 * \file IfxSmu_Smu.h
 * \brief SMU SMU details
 * \ingroup IfxLld_Smu
 *
 * \version iLLD-TC4-v2.1.1
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
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
    uint8   igcs0;                             /**< \brief AGC.B.IGCS0 */
    uint8   igcs1;                             /**< \brief AGC.B.IGCS1 */
    uint8   igcs2;                             /**< \brief AGC.B.IGCS2 */
    uint8   resetConfigSet0;                   /**< \brief AGC.B.RCS0 */
    uint8   resetConfigSet1;                   /**< \brief AGC.B.RCS1 */
    boolean enableFaultToRunTransition0;       /**< \brief AGC.B.EFRST0 */
    boolean enableFaultToRunTransition1;       /**< \brief AGC.B.EFRST1 */
    boolean enableStartToRunState;             /**< \brief AGC.B.ESSM1 */
} IfxSmu_Smu_AlarmGlobalConfiguration;

/** \brief Recovery Timer/s Alarm Configuration
 */
typedef struct
{
    uint8 groupIndex0;
    uint8 alarmId0;
    uint8 groupIndex1;
    uint8 alarmId1;
    uint8 groupIndex2;
    uint8 alarmId2;
    uint8 groupIndex3;
    uint8 alarmId3;
} IfxSmu_Smu_RecoveryTimerAlarmConfiguration;

/** \brief This register controls the timing duration of the recovery timer.
 */
typedef struct
{
    boolean enableRecoveryTimer0;              /**< \brief RT0 Enable Bit */
    boolean enableRecoveryTimer1;              /**< \brief RT1 Enable Bit */
    uint8   PrescalarRecoveryTimerClock;       /**< \brief Prescalar For Recovery Timer Clock */
    uint32  recoveryTimerDuration;             /**< \brief Recovery Timer Duration */
} IfxSmu_Smu_SafetyRecoveryTimerConfig;

/** \} */

/** \brief This register controls the timing duration of the recovery timer.
 */
typedef struct
{
    boolean enableRecoveryTimer0;              /**< \brief RT0 Enable Bit */
    uint8   PrescalarRecoveryTimerClock;       /**< \brief Prescalar For Recovery Timer Clock */
    uint32  recoveryTimerDuration;             /**< \brief Recovery Timer Duration */
} IfxSmu_Smu_SecurityRecoveryTimerConfig;

/** \addtogroup IfxLld_Smu_Smu_DataStructures
 * \{ */
/** \brief FSP configuration
 */
typedef struct
{
    IfxSmu_FspPrescalar1 prescalar1;                   /**< \brief FSP.B.PRE1 */
    IfxSmu_FspPrescalar2 prescalar2;                   /**< \brief FSP.B.PRE2 */
    IfxSmu_FspMode       mode;
    uint16               faultStateDurationHigh;       /**< \brief FSP.B.TFSP_HIGH */
    uint16               faultStateDurationLow;        /**< \brief FSP.B.TFSP_LOW */
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
    IfxSmu_Smu_FaultSignalingProtocol fsp[2];
    IfxSmu_Smu_SafetyGlobalConfig     globalConfig;                                                    /**< \brief SMU global configuration */
    uint32                            alarmConfigRegister[IFXSMU_NUM_OF_SAFETY_ALARM_GROUPS][4];       /**< \brief SAGC */
    uint32                            fspConfigRegister[IFXSMU_NUM_OF_SAFETY_ALARM_GROUPS][2];         /**< \brief AGF */
} IfxSmu_Smu_SafetyConfig;

typedef struct
{
    IfxSmu_Smu_SecurityGlobalConfig globalConfig;                                                      /**< \brief Secure Global Config */
    uint32                          alarmConfigRegister[IFXSMU_NUM_OF_SECURITY_ALARM_GROUPS][3];
} IfxSmu_Smu_SecurityConfig;

/** \} */

/** \addtogroup IfxLld_Smu_Smu_DataStructures
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Fills the configuration stucture of the Security SMU Module with default values.
 * \param config configuration structure of the Security module.
 * \return None
 */
IFX_EXTERN void IfxSmu_Smu_initSecurityModuleConfig(IfxSmu_Smu_SecurityConfig *config);

/** \} */

/** \addtogroup IfxLld_Smu_Smu_SmuFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Fills the configuration stucture of the Safety SMU Module with default values
 * \param config configuration structure of the module
 * \return None
 */
IFX_EXTERN void IfxSmu_Smu_initSafetyModuleConfig(IfxSmu_Smu_SafetyConfig *config);

/** \brief Initialises the SMU Safety Module
 * \param config configuration structure of the module
 * \param smuSafeIndex SMU Safe Module ID
 * \return None
 */
IFX_EXTERN void IfxSmu_Smu_initSafetyModule(IfxSmu_Smu_SafetyConfig *config, boolean smuSafeIndex);

/** \brief Check if any alarm is Triggered.
 * \param smuSafeIndex Index number to repersent the Safety SMU module used.
 * \param groupNo Safety SMU Alarm Group Index.
 * \return Returns True if any alarm is set
 */
IFX_EXTERN boolean IfxSmu_Smu_isSafetyAlarmTriggered(boolean smuSafeIndex, uint8 groupNo);

/** \brief Initialises the Security SMU Module
 * \param config configuration structure of the Security module
 * \return None
 */
IFX_EXTERN void IfxSmu_Smu_initSecurityModule(IfxSmu_Smu_SecurityConfig *config);

/** \brief Check if any Security alarm is Triggered.
 * \param groupNo Security SMU Alarma Group number.
 * \return Returns True if any alarm is set
 */
IFX_EXTERN boolean IfxSmu_Smu_isSecurityAlarmTriggered(uint8 groupNo);

/** \brief Check if any alarm is Triggered.
 * \param SharedType To indicate alarms either configured to security/safety SMU.
 * \param smuSafeIndex SMU safe ID.
 * \param groupNo SMU Alarm Group.
 * \return Return Status Value 0 or 1.
 */
IFX_EXTERN boolean IfxSmu_Smu_isSharedAlarmTriggered(IfxSmu_SharedType SharedType, boolean smuSafeIndex, uint8 groupNo);

/** \brief Initialize the SAFE SMU Global configurations
 * \param config SAFE Global config pointer
 * \param smuSafeIndex SMU SAFE index
 * \return None
 */
IFX_EXTERN void IfxSmu_Smu_initSafetyGlobal(IfxSmu_Smu_SafetyGlobalConfig *config, boolean smuSafeIndex);

/** \brief Initialize the Secure Global configurations
 * \param config SECURE Global configurations
 * \return None
 */
IFX_EXTERN void IfxSmu_Smu_initSecurityGlobal(IfxSmu_Smu_SecurityGlobalConfig *config);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to configure Shared SMU alarms either to Safety/Security SMUs.
 * If an alarm is already mapped to safety, the user can re-configure it to safety.
 * \param SharedType Type of SMU to be configured for Shared SMU alarms.
 * \param alarm SMU Alarm ID.
 * \return None
 */
IFX_EXTERN void IfxSmu_Smu_setSharedSelectionRegister(IfxSmu_SharedType SharedType, IfxSmu_Alarm alarm);
#endif /* IFXSMU_SMU_H */
