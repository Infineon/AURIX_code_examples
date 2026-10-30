/**
 * \file IfxSmu.h
 * \brief SMU  basic functionality
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
 * \defgroup IfxLld_Smu_Std_Enumerations Enumerations
 * \ingroup IfxLld_Smu_Std
 * \defgroup IfxLld_Smu_Std_ModuleFunctions Module Functions
 * \ingroup IfxLld_Smu_Std
 */

#ifndef IFXSMU_H
#define IFXSMU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxSmu_cfg.h"
#include "IfxSmu_reg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "_Utilities/Ifx_Assert.h"
#include "IfxSrc_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Argument to start Alive test
 */
#define IFXSMU_START_ALIVE_TEST_ARG (5)

/** \brief Argument to stop Alive test
 */
#define IFXSMU_STOP_ALIVE_TEST_ARG  (0xA)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Smu_Std_Enumerations
 * \{ */
/** \brief Command interface
 */
typedef enum
{
    IfxSmu_Command_start            = 0,  /**< \brief Forces the SSM to go to the RUN state from the START state */
    IfxSmu_Command_activateFSP      = 1,  /**< \brief Activates the Fault Signaling Protocol. */
    IfxSmu_Command_releaseFSP       = 2,  /**< \brief Turns the FSP into the inactive fault free state */
    IfxSmu_Command_activatePES      = 3,  /**< \brief Triggers the activation of the Port Emergency Stop (PES). */
    IfxSmu_Command_stopRT           = 4,  /**< \brief Stop the recovery Timer. */
    IfxSmu_Command_alarmStatusClear = 5,  /**< \brief Alarm Status Clear Enable Command */
    IfxSmu_Command_triggerAlarm     = 6,  /**< \brief Triggers a software based alarm */
    IfxSmu_Command_aliveTest        = 7   /**< \brief Triggers a SMU alive alarm */
} IfxSmu_Command;

/** \brief Fault Signaling Protocol configuration
 * Definition in MODULE_SMU.FSP.B.MODE
 */
typedef enum
{
    IfxSmu_FspMode_BiStableProtocol      = 0, /**< \brief Bi-stable protocol */
    IfxSmu_FspMode_dualRailProtocol      = 1, /**< \brief dualRailProtocol */
    IfxSmu_FspMode_TimeSwitchingProtocol = 2  /**< \brief Time switching protocol */
} IfxSmu_FspMode;

/** \brief Dividing factor to apply to the reference clock fBACK. The divided clock is used as reference to generate the timing of the fault signaling protocol fault state.
 * Definition in MODULE_SMU.FSP.B.PRE1
 */
typedef enum
{
    IfxSmu_FspPrescalar1_referenceClockDiv2   = 0,  /**< \brief FSMU_FS = reference clock frequency divided by 2 */
    IfxSmu_FspPrescalar1_referenceClockDiv4   = 1,  /**< \brief FSMU_FS = reference clock frequency divided by 4 */
    IfxSmu_FspPrescalar1_referenceClockDiv8   = 2,  /**< \brief FSMU_FS = reference clock frequency divided by 8 */
    IfxSmu_FspPrescalar1_referenceClockDiv16  = 3,  /**< \brief FSMU_FS = reference clock frequency divided by 16 */
    IfxSmu_FspPrescalar1_referenceClockDiv32  = 4,  /**< \brief FSMU_FS = reference clock frequency divided by 32 */
    IfxSmu_FspPrescalar1_referenceClockDiv64  = 5,  /**< \brief FSMU_FS = reference clock frequency divided by 64 */
    IfxSmu_FspPrescalar1_referenceClockDiv128 = 6,  /**< \brief FSMU_FS = reference clock frequency divided by 128 */
    IfxSmu_FspPrescalar1_referenceClockDiv256 = 7   /**< \brief FSMU_FS = reference clock frequency divided by 256 */
} IfxSmu_FspPrescalar1;

/** \brief Dividing factor to apply to the reference clock fBACK in order to generate the timing of the fault free state for the time switching modes of the fault signaling protocol.
 * Definition in MODULE_SMU.FSP.B.PRE2
 */
typedef enum
{
    IfxSmu_FspPrescalar2_referenceClockDiv512  = 0,  /**< \brief FSMU_FS = reference clock frequency divided by 512 */
    IfxSmu_FspPrescalar2_referenceClockDiv1024 = 1,  /**< \brief FSMU_FS = reference clock frequency divided by 1024 */
    IfxSmu_FspPrescalar2_referenceClockDiv2048 = 2,  /**< \brief FSMU_FS = reference clock frequency divided by 2048 */
    IfxSmu_FspPrescalar2_referenceClockDiv4096 = 3   /**< \brief FSMU_FS = reference clock frequency divided by 4096 */
} IfxSmu_FspPrescalar2;

/** \brief Internal alarm Configuration
 */
typedef enum
{
    IfxSmu_InternalAlarmAction_disabled = 0,  /**< \brief Alarm disabled. */
    IfxSmu_InternalAlarmAction_igcs0    = 2,  /**< \brief Sends an interrupt request to the interrupt system according to the IGCS0 */
    IfxSmu_InternalAlarmAction_igcs1    = 3,  /**< \brief Sends an interrupt request to the interrupt system according to the IGCS1 */
    IfxSmu_InternalAlarmAction_igcs2    = 4,  /**< \brief Sends an interrupt request to the interrupt system according to the IGCS2 */
    IfxSmu_InternalAlarmAction_nmi      = 5,  /**< \brief Sends an NMI request to the SCU */
    IfxSmu_InternalAlarmAction_reset    = 6,  /**< \brief Sends a reset request to the SCU. */
    IfxSmu_InternalAlarmAction_cpureset = 7   /**< \brief Triggers a CPU reset request using CPU Reset Configuration Set */
} IfxSmu_InternalAlarmAction;

/** \brief Interrupt Generation Configuration
 */
typedef enum
{
    IfxSmu_InterruptGenerationConfiguration_0 = 0,      /**< \brief Interrupt Generation Configuration 0  */
    IfxSmu_InterruptGenerationConfiguration_1,          /**< \brief Interrupt Generation Configuration 1  */
    IfxSmu_InterruptGenerationConfiguration_2           /**< \brief Interrupt Generation Configuration 2  */
} IfxSmu_InterruptGenerationConfiguration;

/** \brief Interrupt Request
 */
typedef enum
{
    IfxSmu_InterruptRequest_0 = 0,      /**< \brief Interrupt Request 0  */
    IfxSmu_InterruptRequest_1,          /**< \brief Interrupt Request 1  */
    IfxSmu_InterruptRequest_2           /**< \brief Interrupt Request 2  */
} IfxSmu_InterruptRequest;

/** \brief Enum for the FSP_DIR output port control direction
 * Definition in MODULE_SMU.PCTL.B.HWDIR
 */
typedef enum
{
    IfxSmu_PortControlHwDir_fsp0AndFsp1Input       = 0,  /**< \brief fsp0InputAndFsp1Input */
    IfxSmu_PortControlHwDir_fsp0OutputAndFsp1Input = 1,  /**< \brief fsp0OutputAndFsp1Input */
    IfxSmu_PortControlHwDir_fsp0AndFsp1Output      = 3   /**< \brief fsp0OutputAndFsp1Input */
} IfxSmu_PortControlHwDir;

/** \brief Enum for the FSP_DIR output port control enable
 * Definition in MODULE_SMU.PCTL.B.HWEN
 */
typedef enum
{
    IfxSmu_PortControlHwEnable_fsp0AndFsp1Disabled        = 0,  /**< \brief fsp0AndFsp1Disabled */
    IfxSmu_PortControlHwEnable_fsp0EnabledAndFsp1Disabled = 1,  /**< \brief fsp0EnabledAndFsp1Disabled */
    IfxSmu_PortControlHwEnable_fsp0AndFsp1Enabled         = 3   /**< \brief fsp0AndFsp1Enabled */
} IfxSmu_PortControlHwEnable;

/** \brief Running state of the SMU State Machine
 * Definition in MODULE_SMU.DBG.B.SSM
 */
typedef enum
{
    IfxSmu_SmuState_start       = 0, /**< \brief START state */
    IfxSmu_SmuState_run         = 1, /**< \brief RUN State */
    IfxSmu_SmuState_fault       = 2, /**< \brief FAULT State */
    IfxSmu_SmuState_unspecified = 3  /**< \brief unspecified State */
} IfxSmu_SmuState;

/** \brief OCDS Suspend Control (OCDS.SUS)
 * Definition in Ifx_SMU.OCS.B.SUS
 */
typedef enum
{
    IfxSmu_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxSmu_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxSmu_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxSmu_SuspendMode;

/** \} */

/** \brief Alarm Executed Status
 * Definition in MODULE_SMU.AEXCLR.U
 */
typedef enum
{
    IfxSmu_AlarmExecutionStatus_irq0    = 0,   /**< \brief IRQ0 Request Status */
    IfxSmu_AlarmExecutionStatus_irq1    = 1,   /**< \brief IRQ1 Request Status */
    IfxSmu_AlarmExecutionStatus_irq2    = 2,   /**< \brief IRQ2 Request Status */
    IfxSmu_AlarmExecutionStatus_rst0    = 3,   /**< \brief RST0 Request Status */
    IfxSmu_AlarmExecutionStatus_rst1    = 4,   /**< \brief RST1 Request Status */
    IfxSmu_AlarmExecutionStatus_rst2    = 5,   /**< \brief RST2 Request Status */
    IfxSmu_AlarmExecutionStatus_rst3    = 6,   /**< \brief RST3 Request Status */
    IfxSmu_AlarmExecutionStatus_rst4    = 7,   /**< \brief RST4 Request Status */
    IfxSmu_AlarmExecutionStatus_rst5    = 8,   /**< \brief RST5 Request Status */
    IfxSmu_AlarmExecutionStatus_nmi     = 9,   /**< \brief NMI Request Status */
    IfxSmu_AlarmExecutionStatus_rst     = 10,  /**< \brief RST Request Status */
    IfxSmu_AlarmExecutionStatus_ems     = 11,  /**< \brief EMS Request Status */
    IfxSmu_AlarmExecutionStatus_irq0aem = 16,  /**< \brief IRQ0 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_irq1aem = 17,  /**< \brief IRQ1 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_irq2aem = 18,  /**< \brief IRQ2 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst0aem = 19,  /**< \brief RST0 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst1aem = 20,  /**< \brief RST1 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst2aem = 21,  /**< \brief RST2 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst3aem = 22,  /**< \brief RST3 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst4aem = 23,  /**< \brief RST4 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst5aem = 24,  /**< \brief RST5 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_nmiaem  = 25,  /**< \brief NMI AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rstaem  = 26,  /**< \brief RST AEM Request Status */
    IfxSmu_AlarmExecutionStatus_emsaem  = 27   /**< \brief EMS AEM Request Status */
} IfxSmu_AlarmExecutionStatus;

/** \addtogroup IfxLld_Smu_Std_ModuleFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the executed status of a specified SMU alarm mechanism.
 *
 * \param[in] alarmEx The alarm mechanism whose executed status is to be cleared. Range: \ref IfxSmu_AlarmExecutionStatus.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSmu_clearAlarmExecutedStatus(IfxSmu_AlarmExecutionStatus alarmEx);

/**
 * \brief Clears the Register Monitor test mode enable flag.
 * The RMCTL register needs to be unlocked by using IfxSmu_unlockConfigRegisters() before calling this function.
 *
 * \param[in] testModeEnable Test Mode Enable flag value to be cleared. Range: 0 to 31.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSmu_clearRegMonTestModeEnable(uint8 testModeEnable);

/**
 * \brief Clears the specified Register Monitor Error Flag (RMEF.EFz).
 *
 * \param[in] errorFlag Error flag to be cleared. Range: 0 to 31.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSmu_clearRegisterMonitorErrorFlag(uint8 errorFlag);

/**
 * \brief Clears the specified status flag in the Register Monitor status register.
 *
 * \param[in] statusFlag The status flag to be cleared. The value of this parameter determines
 *                       which status flag in the Register Monitor status register will be reset. Range: 0 to 31.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxSmu_clearRegisterMonitorStatus(uint8 statusFlag);

/**
 * \brief The function returns the executed status of a requested alarm mechanism.
 *
 * \param[in] alarmEx The alarm mechanism for which the execution status is requested. Range: \ref IfxSmu_AlarmExecutionStatus.
 *
 * \retval TRUE The alarm mechanism has been executed.
 *         FALSE The alarm mechanism has not been executed.
 *
 */
IFX_INLINE boolean IfxSmu_getAlarmExecutedStatus(IfxSmu_AlarmExecutionStatus alarmEx);

/**
 * \brief Retrieves the current hardware direction of the port control.
 *
 * \retval The hardware direction state of the port control. Range: \ref IfxSmu_PortControlHwDir.
 *
 */
IFX_INLINE IfxSmu_PortControlHwDir IfxSmu_getPortControlHwDir(void);

/**
 * \brief Function returns the Port control hardware enable.
 *
 * \retval port Control HW enable. Range: \ref IfxSmu_PortControlHwEnable.
 *
 */
IFX_INLINE IfxSmu_PortControlHwEnable IfxSmu_getPortControlHwEnable(void);

/**
 * \brief Retrieves the current value of the Register Monitor Error Flags register.
 *
 * \retval uint32 A 32-bit unsigned integer representing the current value of the Register Monitor Error Flags register. Range: 0 to 0x07FF.
 *
 */
IFX_INLINE uint32 IfxSmu_getRegisterMonitorErrorFlag(void);

/**
 * \brief Retrieves the current status of the Register Monitor Self Test.
 *
 * \retval uint32 The current value of the Register Monitor Self Test Status register. Range: 0 to 0x07FF.
 *
 */
IFX_INLINE uint32 IfxSmu_getRegisterMonitorStatus(void);

/**
 * \brief Checks if the SMU module is in a suspended state.
 *
 * \param[in] smu Pointer to the SMU module registers.
 *
 * \retval TRUE Module is suspended.
 *         FALSE Module is not suspended.
 *
 */
IFX_INLINE boolean IfxSmu_isModuleSuspended(Ifx_SMU *smu);

/**
 * \brief Sets the Port control hardware Enable and direction.
 * The PCTL register needs to be unlocked by using IfxSmu_unlockConfigRegisters() before calling this function.
 *
 * \param[in] portEnable The port enable configuration. Range: \ref IfxSmu_PortControlHwEnable.
 * \param[in] hwDir      The hardware direction configuration. Range: \ref IfxSmu_PortControlHwDir.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSmu_setPortControlHwEnableAndDir(IfxSmu_PortControlHwEnable portEnable, IfxSmu_PortControlHwDir hwDir);

/**
 * \brief Enables or disables the Register Monitor test mode.
 * The RMCTL register must be unlocked using IfxSmu_unlockConfigRegisters() before calling this function.
 *
 * \param[in] testModeEnable Test mode enable flag. Range: 0 to 31.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSmu_setRegMonTestModeEnable(uint8 testModeEnable);

/**
 * \brief Configures the SMU module to the specified suspend mode (Hard, Soft, or None).
 *
 * \param[inout] smu  Pointer to the SMU module registers.
 * \param[in]    mode The suspend mode to configure. Range: \ref IfxSmu_SuspendMode.
 *
 * \retval None
 *
 * \note This API works only when OCDS is enabled and the system is in Supervisor Mode. If OCDS is disabled, the suspend control will be ineffective.
 *
 */
IFX_INLINE void IfxSmu_setSuspendMode(Ifx_SMU *smu, IfxSmu_SuspendMode mode);

/**
 * \brief This function starts the SMU alive test.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSmu_startAliveTest(void);

/**
 * \brief This function Stops the SMU alive test.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSmu_stopAliveTest(void);

/**
 * \brief Waits for the specified SMU alarm to be set and then clears it.
 *
 * \param[in] alarm The SMU alarm group and position to wait for and clear. Range: \ref IfxSmu_Alarm.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxSmu_waitForAlarm(IfxSmu_Alarm alarm);

/**
 * \brief Returns the SRCR (Source Control Register) pointer for the specified interrupt request.
 *
 * \param[in] intRequest The interrupt request for which to retrieve the SRCR pointer. Range: \ref IfxSmu_InterruptRequest.
 *
 * \retval Ifx_SRC_SRCR* A pointer to the SRCR register for the specified interrupt request.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxSmu_getSrcPointer(IfxSmu_InterruptRequest intRequest);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Activates the FSP to indicate a FAULT state on the error pin to the safe state switching device.
 * 
 * \retval TRUE If FSP activation failed.
 *         FALSE If FSP was successfully activated.
 *
 */
IFX_EXTERN boolean IfxSmu_activateFSP(void);

/**
 * \brief Activates the RUN fault-free state of the SMU peripheral as required.
 * 
 * \retval TRUE The activation of the RUN fault-free state failed.
 *         FALSE The SMU peripheral was successfully switched to the RUN fault-free state.
 *
 */
IFX_EXTERN boolean IfxSmu_activateRunState(void);

/**
 * \brief Clears the SMU alarm status for the specified alarm.
 * 
 * \param[in] alarm The SMU alarm group and position to clear. This parameter is of type IfxSmu_Alarm,
 *                  which defines the specific alarm to be cleared. Range: \ref IfxSmu_Alarm.
 *
 * \retval TRUE The operation failed to clear the alarm status.
 *         FALSE The alarm status was successfully cleared.
 *
 */
IFX_EXTERN boolean IfxSmu_clearAlarmStatus(IfxSmu_Alarm alarm);

/**
 * \brief Configures the PES feature for internal actions based on the specified action bits.
 * Bit0/1/2/3 - SMU_IGCS0/SMU_IGCS1/SMU_IGCS2/SMU_NMI/SMU_CPU_RESET activates PES correspondingly.
 *
 * \param[in] pesAction An 8-bit value where each bit corresponds to a specific action.
 *                      Range:
 *                      - 0x01(SMU_IGCS0),
 *                      - 0x02(SMU_IGCS1),
 *                      - 0x04(SMU_IGCS2),
 *                      - 0x08(SMU_NMI),
 *                      - 0x10(SMU_CPU_RESET).
 *
 * \retval None
 *
 * \note The AGC register must be unlocked using \ref IfxSmu_unlockConfigRegisters before calling this function.
 *
 */
IFX_EXTERN void IfxSmu_configAlarmActionPES(uint8 pesAction);

/**
 * \brief Enable or disable the FAULT to RUN state transition.
 * The AGC register needs to be unlocked by using IfxSmu_unlockConfigRegisters() before calling this function.
 * 
 * \param[in] enable  Enable / Disable Fault to Run Transition (True - Enable, False - Disable)
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxSmu_enableFaultToRunState(boolean enable);

/**
 * \brief Configure FSP (Fault Signaling Protocol) Port Emergency Stop.
 * The FSP register needs to be unlocked by using IfxSmu_unlockConfigRegisters() before calling this function.
 * 
 * \param[in] enable Enable or disable the PES feature.
 *                   - True: Enable PES.
 *                   - False: Disable PES.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxSmu_enablePortEmergencyStop(boolean enable);

/**
 * \brief Retrieves the FSP action configured for the specified alarm.
 *
 * \param[in]    alarm          The SMU alarm group and position to query. Range: \ref IfxSmu_Alarm.
 * \param[inout] intAlarmAction Pointer to the internal alarm action structure that will store the retrieved FSP action details.
 *                              Range: \ref IfxSmu_InternalAlarmAction.
 *
 * \retval TRUE If FSP is enabled for the specified alarm.
 *         FALSE If FSP is disabled for the specified alarm.
 *
 */
IFX_EXTERN boolean IfxSmu_getAlarmAction(IfxSmu_Alarm alarm, IfxSmu_InternalAlarmAction *intAlarmAction);

/**
 * \brief Retrieves the debug status of a specified SMU alarm group from the stored debug registers.
 *
 * \param[in] alarmGroup The SMU alarm group for which to retrieve the debug status. Range: 0 to 11.
 *
 * \retval uint32 The debug status of the specified alarm group stored in the debug registers. Range: 0 to 0xFFFF FFFF.
 *
 */
IFX_EXTERN uint32 IfxSmu_getAlarmGroupDebugStatus(uint8 alarmGroup);

/**
 * \brief Retrieves the status of a requested alarm.
 *
 * \param[in] alarm The identifier of the alarm to check. Range: \ref IfxSmu_Alarm.
 *
 * \retval TRUE The alarm is active.
 *         FALSE The alarm is not active.
 * 
 */
IFX_EXTERN boolean IfxSmu_getAlarmStatus(IfxSmu_Alarm alarm);

/**
 * \brief Checks if any alarms requiring the requested recovery timer were set while the recovery timer was running.
 *
 * \param[in] timerNum Recovery Timer unit to check for missed events. Range: 0 or 1.
 *
 * \retval TRUE A missed event occurred.
 *         FALSE No missed event occurred.
 * 
 */
IFX_EXTERN boolean IfxSmu_getRTMissedEvent(uint8 timerNum);

/**
 * \brief The function provides the current state of the SMU.
 *
 * \retval return the current state of SMU. Range: \ref IfxSmu_SmuState.
 *
 */
IFX_EXTERN IfxSmu_SmuState IfxSmu_getSmuState(void);

/**
 * \brief Locks the SMU configuration registers to make them read-only and prevent any modification.
 * This function ensures that the configuration registers of the SMU cannot be altered once locked.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxSmu_lockConfigRegisters(void);

/**
 * \brief Switches the SMU peripheral from the FAULT state to the RUN state.
 * 
 * \retval TRUE The SMU peripheral could not be switched to the RUN state.
 *         FALSE The SMU peripheral was successfully switched to the RUN state.
 *
 */
IFX_EXTERN boolean IfxSmu_releaseFSP(void);

/**
 * \brief Sets the internal alarm action for the specified alarm.
 *
 * \param[in] alarm          The SMU alarm group and position to configure. Range: \ref IfxSmu_Alarm.
 * \param[in] intAlarmAction The internal action to associate with the alarm. This is of type IfxSmu_InternalAlarmAction.
 *                           Range: \ref IfxSmu_InternalAlarmAction.
 * \retval None
 * 
 */
IFX_EXTERN void IfxSmu_setAlarmAction(IfxSmu_Alarm alarm, IfxSmu_InternalAlarmAction intAlarmAction);

/**
 * \brief Sets the status of a specified SMU alarm.
 * This function allows user software to trigger a SW SMU alarm. During the START state of the SMU,
 * any alarm can be set. However, during the RUN state, only SW alarms can be set.
 *
 * \param[in] alarm The SMU alarm to be set. Range: \ref IfxSmu_Alarm.
 *
 * \retval TRUE The alarm setting failed.
 *         FALSE The alarm was successfully set.
 *
 */
IFX_EXTERN boolean IfxSmu_setAlarmStatus(IfxSmu_Alarm alarm);

/**
 * \brief Configures the Fault Signaling Protocol (FSP) mode.
 *
 * \param[in] mode The FSP mode to be configured. Range: \ref IfxSmu_FspMode.
 *
 * \note The FSP register must be unlocked using IfxSmu_unlockConfigRegisters() before calling this function.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSmu_setFspMode(IfxSmu_FspMode mode);

/**
 * \brief Stops the requested recovery timer unit.
 *
 * \param[in] timerNum The recovery timer unit to be stopped. Range: 0 to 15.
 *
 * \retval TRUE Failure.
 *         FALSE Success.
 *
 */
IFX_EXTERN boolean IfxSmu_stopRT(uint8 timerNum);

/**
 * \brief Unlocks the SMU configuration registers for modification.
 *
 * \retval TRUE SMU configuration registers are unlocked successfully.
 *         FALSE SMU configuration is locked permanently; unlock not possible.
 *
 */
IFX_EXTERN boolean IfxSmu_unlockConfigRegisters(void);

/**
 * \brief Configures the interrupt generation settings for the SMU module.
 *
 * \param[in] config     The configuration settings for interrupt generation. Range: \ref IfxSmu_InterruptGenerationConfiguration.
 * \param[in] intRequest The interrupt request to be configured. Range: \ref IfxSmu_InterruptRequest.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxSmu_ConfigureInterruptGeneration(IfxSmu_InterruptGenerationConfiguration config, IfxSmu_InterruptRequest intRequest);

/**
 * \brief Temporarily locks the SMU configuration registers to prevent unintended modifications.
 * 
 * \retval None
 * 
 */
IFX_EXTERN void IfxSmu_temporaryLockConfigRegisters(void);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxSmu_clearAlarmExecutedStatus(IfxSmu_AlarmExecutionStatus alarmEx)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    /* Write 1 in AEX bit to clear alarm Executed mechanism */
    MODULE_SMU.AEXCLR.U = (uint32)((uint32)0x1U << alarmEx);

    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxSmu_clearRegMonTestModeEnable(uint8 testModeEnable)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    MODULE_SMU.RMCTL.U &= ~(1U << testModeEnable);
    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxSmu_clearRegisterMonitorErrorFlag(uint8 errorFlag)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    MODULE_SMU.RMEF.U &= ~(1U << errorFlag);

    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxSmu_clearRegisterMonitorStatus(uint8 statusFlag)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    MODULE_SMU.RMSTS.U &= ~(1U << statusFlag);

    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE boolean IfxSmu_getAlarmExecutedStatus(IfxSmu_AlarmExecutionStatus alarmEx)
{
    boolean alarmExecuteStatus = (boolean)((MODULE_SMU.AEX.U >> alarmEx) & 0x1);
    return alarmExecuteStatus;
}


IFX_INLINE IfxSmu_PortControlHwDir IfxSmu_getPortControlHwDir(void)
{
    return (IfxSmu_PortControlHwDir)MODULE_SMU.PCTL.B.HWDIR;
}


IFX_INLINE IfxSmu_PortControlHwEnable IfxSmu_getPortControlHwEnable(void)
{
    return (IfxSmu_PortControlHwEnable)MODULE_SMU.PCTL.B.HWEN;
}


IFX_INLINE uint32 IfxSmu_getRegisterMonitorErrorFlag(void)
{
    uint32 errorFlags = 0;
    errorFlags = MODULE_SMU.RMEF.U;
    return errorFlags;
}


IFX_INLINE uint32 IfxSmu_getRegisterMonitorStatus(void)
{
    uint32 selfTestStatus = 0;
    selfTestStatus = MODULE_SMU.RMSTS.U;
    return selfTestStatus;
}


IFX_INLINE boolean IfxSmu_isModuleSuspended(Ifx_SMU *smu)
{
    Ifx_SMU_OCS ocs;

    /* Read the status */
    ocs.U = smu->OCS.U;

    /* Return the status */
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxSmu_setPortControlHwEnableAndDir(IfxSmu_PortControlHwEnable portEnable, IfxSmu_PortControlHwDir hwDir)
{
    uint16       passwd = IfxScuWdt_getSafetyWatchdogPassword();
    Ifx_SMU_PCTL pctl;
    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    pctl.U            = MODULE_SMU.PCTL.U;
    pctl.B.HWEN       = portEnable;
    pctl.B.HWDIR      = hwDir;
    pctl.B.PCS        = 1;
    MODULE_SMU.PCTL.U = pctl.U;

    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxSmu_setRegMonTestModeEnable(uint8 testModeEnable)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    MODULE_SMU.RMCTL.U |= (1U << testModeEnable);
    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxSmu_setSuspendMode(Ifx_SMU *smu, IfxSmu_SuspendMode mode)
{
    Ifx_SMU_OCS ocs;

    /* Remove protection and configure the suspend mode */
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    smu->OCS.U  = ocs.U;
}


IFX_INLINE void IfxSmu_startAliveTest(void)
{
    Ifx_SMU_CMD cmdSfr;
    cmdSfr.U         = MODULE_SMU.CMD.U;
    cmdSfr.B.CMD     = IfxSmu_Command_aliveTest;
    cmdSfr.B.ARG     = IFXSMU_START_ALIVE_TEST_ARG;
    MODULE_SMU.CMD.U = cmdSfr.U;
}


IFX_INLINE void IfxSmu_stopAliveTest(void)
{
    Ifx_SMU_CMD cmdSfr;
    cmdSfr.U         = MODULE_SMU.CMD.U;
    cmdSfr.B.CMD     = IfxSmu_Command_aliveTest;
    cmdSfr.B.ARG     = IFXSMU_STOP_ALIVE_TEST_ARG;
    MODULE_SMU.CMD.U = cmdSfr.U;
}


IFX_INLINE void IfxSmu_waitForAlarm(IfxSmu_Alarm alarm)
{
    while (!IfxSmu_getAlarmStatus(alarm))
    {}

    IfxSmu_clearAlarmStatus(alarm);
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxSmu_getSrcPointer(IfxSmu_InterruptRequest intRequest)
{
    return &MODULE_SRC.SMU.SMU[0].SR[intRequest];
}


#endif /* IFXSMU_H */
