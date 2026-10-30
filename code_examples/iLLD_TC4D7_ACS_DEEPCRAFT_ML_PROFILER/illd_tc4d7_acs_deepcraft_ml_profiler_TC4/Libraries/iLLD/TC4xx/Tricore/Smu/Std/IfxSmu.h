/**
 * \file IfxSmu.h
 * \brief SMU  basic functionality 
 * \ingroup IfxLld_Smu 
 *
 * \version iLLD-TC4-v2.6.0
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
 * \defgroup IfxLld_Smu_Std_Data Structures Data Structures  
 * \ingroup IfxLld_Smu_Std
 */

#ifndef IFXSMU_H
#define IFXSMU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxSmu_cfg.h"
#include "IfxSmu_reg.h"
#include "_Utilities/Ifx_Assert.h"
#include "IfxSrc_reg.h"
#include "Ap/Std/IfxApApu.h"
#include "Ap/Std/IfxApProt.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Argument to start Alive test 
 */
#define IFXSMU_START_ALIVE_TEST_ARG (5)

/** \brief Argument to stop Alive test 
 */
#define IFXSMU_STOP_ALIVE_TEST_ARG (0xA)



/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Smu_Std_Enumerations
 * \{ */
/** \brief Alarm Executed Status  
 */
typedef enum
{
    IfxSmu_AlarmExecutionStatus_irq0 = 0,      /**< \brief IRQ0 Request Status - IRQ0STS */
    IfxSmu_AlarmExecutionStatus_irq1 = 1,      /**< \brief IRQ1 Request Status - IRQ1STS */
    IfxSmu_AlarmExecutionStatus_irq2 = 2,      /**< \brief IRQ2 Request Status - IRQ2STS */
    IfxSmu_AlarmExecutionStatus_rst0 = 3,      /**< \brief CPU0 RESET Request Status - C0RSTSTS */
    IfxSmu_AlarmExecutionStatus_rst1 = 4,      /**< \brief CPU1 RESET Request Status - C1RSTSTS */
    IfxSmu_AlarmExecutionStatus_rst2 = 5,      /**< \brief CPU2 RESET Request Status - C2RSTSTS */
    IfxSmu_AlarmExecutionStatus_rst3 = 6,      /**< \brief CPU3 RESET Request Status - C3RSTSTS */
    IfxSmu_AlarmExecutionStatus_rst4 = 7,      /**< \brief CPU4 RESET Request Status - C4RSTSTS */
    IfxSmu_AlarmExecutionStatus_rst5 = 8,      /**< \brief CPU5 RESET Request Status - C5RSTSTS */
    IfxSmu_AlarmExecutionStatus_nmi0 = 9,      /**< \brief NMI0 Request Status - NMI0STS */
    IfxSmu_AlarmExecutionStatus_reset0 = 10,   /**< \brief RESET0 Request Status - RST0STS */
    IfxSmu_AlarmExecutionStatus_ems = 11,      /**< \brief EMS Request Status - EMSSTS */
    IfxSmu_AlarmExecutionStatus_nmi1 = 12,     /**< \brief NMI1 Request Status - NMI1STS */
    IfxSmu_AlarmExecutionStatus_reset1 = 13,   /**< \brief RESET1 Request Status - RST1STS */
    IfxSmu_AlarmExecutionStatus_prst = 14,     /**< \brief PPU RESET Request Status - PRSTSTS */
    IfxSmu_AlarmExecutionStatus_irq0aem = 16,  /**< \brief IRQ0 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_irq1aem = 17,  /**< \brief IRQ1 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_irq2aem = 18,  /**< \brief IRQ2 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst0aem = 19,  /**< \brief RST0 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst1aem = 20,  /**< \brief RST1 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst2aem = 21,  /**< \brief RST2 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst3aem = 22,  /**< \brief RST3 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst4aem = 23,  /**< \brief RST4 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rst5aem = 24,  /**< \brief RST5 AEM Request Status */
    IfxSmu_AlarmExecutionStatus_nmiaem0 = 25,  /**< \brief NMI AEM Request Status */
    IfxSmu_AlarmExecutionStatus_rstaem0 = 26,  /**< \brief RST AEM Request Status */
    IfxSmu_AlarmExecutionStatus_emsaem = 27,   /**< \brief EMS AEM Request Status */
    IfxSmu_AlarmExecutionStatus_nmiaem1 = 28,  /**< \brief NMI AEM Request Status1 */
    IfxSmu_AlarmExecutionStatus_rstaem1 = 26,  /**< \brief RST AEM Request Status1 */
    IfxSmu_AlarmExecutionStatus_prstaem = 30   /**< \brief PPU AEM RESET Request Status */
} IfxSmu_AlarmExecutionStatus;

/** \brief Command interface  
 */
typedef enum
{
    IfxSmu_Command_start = 0,             /**< \brief Forces the SSM to go to the RUN state from the START state */
    IfxSmu_Command_activateFSP = 1,       /**< \brief Activates the Fault Signaling Protocol. */
    IfxSmu_Command_releaseFSP = 2,        /**< \brief Turns the FSP into the inactive fault free state */
    IfxSmu_Command_activatePES = 3,       /**< \brief Triggers the activation of the Port Emergency Stop (PES). */
    IfxSmu_Command_stopRT = 4,            /**< \brief Stop the recovery Timer. */
    IfxSmu_Command_alarmStatusClear = 5,  /**< \brief Alarm Status Clear Enable Command */
    IfxSmu_Command_triggerAlarm = 6,      /**< \brief Triggers a software based alarm */
    IfxSmu_Command_aliveTest = 7          /**< \brief Triggers a SMU alive alarm */
} IfxSmu_Command;

/** \brief Fault Signaling Protocol configuration  
 *   Definition in MODULE_SMU.SAFE[2].FSP[2].CON.B.MODE
 */
typedef enum
{
    IfxSmu_FspMode_BiStableProtocol = 0,      /**< \brief Bi-stable protocol */
    IfxSmu_FspMode_dualRailProtocol = 1,      /**< \brief dualRailProtocol */
    IfxSmu_FspMode_TimeSwitchingProtocol = 2  /**< \brief Time switching protocol */
} IfxSmu_FspMode;

/** \brief Dividing factor to apply to the reference clock fBACK. The divided clock is used as reference to generate the timing of the fault signaling protocol fault state.
 * Definition in FSPSFR0.B.PRE1
 */
typedef enum
{
    IfxSmu_FspPrescalar1_referenceClockDiv2 = 0,    /**< \brief FSMU_FS = reference clock frequency divided by 2 */
    IfxSmu_FspPrescalar1_referenceClockDiv4 = 1,    /**< \brief FSMU_FS = reference clock frequency divided by 4 */
    IfxSmu_FspPrescalar1_referenceClockDiv8 = 2,    /**< \brief FSMU_FS = reference clock frequency divided by 8 */
    IfxSmu_FspPrescalar1_referenceClockDiv16 = 3,   /**< \brief FSMU_FS = reference clock frequency divided by 16 */
    IfxSmu_FspPrescalar1_referenceClockDiv32 = 4,   /**< \brief FSMU_FS = reference clock frequency divided by 32 */
    IfxSmu_FspPrescalar1_referenceClockDiv64 = 5,   /**< \brief FSMU_FS = reference clock frequency divided by 64 */
    IfxSmu_FspPrescalar1_referenceClockDiv128 = 6,  /**< \brief FSMU_FS = reference clock frequency divided by 128 */
    IfxSmu_FspPrescalar1_referenceClockDiv256 = 7   /**< \brief FSMU_FS = reference clock frequency divided by 256 */
} IfxSmu_FspPrescalar1;

/** \brief Dividing factor to apply to the reference clock fBACK in order to generate the timing of the fault free state for the time switching modes of the fault signaling protocol.  
 * Definition in FSPSFR1.B.PRE1
 */
typedef enum
{
    IfxSmu_FspPrescalar2_referenceClockDiv512 = 4,   /**< \brief FSMU_FS = reference clock frequency divided by 512 */
    IfxSmu_FspPrescalar2_referenceClockDiv1024 = 5,  /**< \brief FSMU_FS = reference clock frequency divided by 1024 */
    IfxSmu_FspPrescalar2_referenceClockDiv2048 = 6,  /**< \brief FSMU_FS = reference clock frequency divided by 2048 */
    IfxSmu_FspPrescalar2_referenceClockDiv4096 = 7   /**< \brief FSMU_FS = reference clock frequency divided by 4096 */
} IfxSmu_FspPrescalar2;

/** \brief Alarm Actions for SMU Driver.  
 */
typedef enum
{
    IfxSmu_InternalAlarmAction_disabled = 0,        /**< \brief No Action. Reset value. Alarm disabled. */
    IfxSmu_InternalAlarmAction_igcs0_req = 2,       /**< \brief Sends an interrupt request to the interrupt system according to the
 * Interrupt Generation Configuration Set 0 from the [SxAGC] register. */
    IfxSmu_InternalAlarmAction_igcs1_req = 3,       /**< \brief Sends an interrupt request to the interrupt system according to the
 * Interrupt Generation Configuration Set 1 from the [SxAGC] register. */
    IfxSmu_InternalAlarmAction_igcs2_req = 4,       /**< \brief Sends an interrupt request to the interrupt system according to the
 * Interrupt Generation Configuration Set 2 from the [SxAGC] register. */
    IfxSmu_InternalAlarmAction_nmi0_req = 5,        /**< \brief Sends an NMI0 request to the SCU */
    IfxSmu_InternalAlarmAction_reset0_req = 6,      /**< \brief Sends a RESET0 request to the SCU. The SCU shall be configured to
 * generate an application or system reset. */
    IfxSmu_InternalAlarmAction_cpu_reset0_req = 7,  /**< \brief Triggers a CPU reset request using CPU Reset Configuration Set from
 * the [SxAGC] register. */
    IfxSmu_InternalAlarmAction_ppu_reset = 9,       /**< \brief Triggers a PPU reset request. */
    IfxSmu_InternalAlarmAction_nmi1_req = 13,       /**< \brief Sends an NMI1 request to the SCU. */
    IfxSmu_InternalAlarmAction_reset1_req = 14,     /**< \brief Sends a RESET1 request to the SCU. The SCU shall be configured to
 * generate an application or system reset. */
    IfxSmu_InternalAlarmAction_cpu_reset1_req = 15  /**< \brief Triggers a CPU reset request using CPU Reset Configuration Set from
 * the [SxAGC] register */
} IfxSmu_InternalAlarmAction;

/** \brief Interrupt Generation Configuration
 */
typedef enum
{
    IfxSmu_InterruptGenerationConfiguration_IGC_0 = 0,  /**< \brief Enable Interrupt Generation 0 */
    IfxSmu_InterruptGenerationConfiguration_IGC_1 = 1,  /**< \brief Enable Interrupt Generation 1 */
    IfxSmu_InterruptGenerationConfiguration_IGC_2 = 2   /**< \brief Enable Interrupt Generation 2 */
} IfxSmu_InterruptGenerationConfiguration;

/** \brief Interrupt Request
 */
typedef enum
{
    IfxSmu_InterruptRequest_IR_0 = 0,  /**< \brief BIT0 */
    IfxSmu_InterruptRequest_IR_1 = 1,  /**< \brief BIT1 */
    IfxSmu_InterruptRequest_IR_2 = 2,  /**< \brief BIT2 */
    IfxSmu_InterruptRequest_IR_3 = 3,  
    IfxSmu_InterruptRequest_IR_4 = 4,  
    IfxSmu_InterruptRequest_IR_5 = 5   
} IfxSmu_InterruptRequest;

/** \brief This register controlls the connectivity with the Ports.  
 */
typedef enum
{
    IfxSmu_PortControl_hwdir0 = 0,     /**< \brief Port Direction for FSP[0] */
    IfxSmu_PortControl_hwen0 = 1,      /**< \brief Port Enable for FSP[0]- HWEN */
    IfxSmu_PortControl_gfsts0_en = 3,  /**< \brief Glitch Filter for ErrorPin FSP[0] to register SxSTS.FSP0 enable -
 * GFSTS_EN */
    IfxSmu_PortControl_hwdir1 = 16,    /**< \brief Port Direction for FSP[1] */
    IfxSmu_PortControl_hwen1 = 17,     /**< \brief Port Enable for FSP[1]- HWEN */
    IfxSmu_PortControl_gfsts1_en = 19  /**< \brief Glitch Filter for ErrorPin FSP[1] to register SxSTS.FSP0 enable -
 * GFSTS_EN */
} IfxSmu_PortControl;

/** \brief Alarm Configurations for Security SMU.  
 */
typedef enum
{
    IfxSmu_SecurityAlarmAction_bk_irq = 1,   /**< \brief Sends a request to the CSS for blocking all keys. And sends an
 * interrupt request to IR. */
    IfxSmu_SecurityAlarmAction_bk_nmi = 2,   /**< \brief Sends a request to the CSS for blocking all keys. And Sends an NMI
 * request to the SCU. */
    IfxSmu_SecurityAlarmAction_bdpk = 3,     /**< \brief Sends a request to the CSS for blocking Debug Protected Keys. */
    IfxSmu_SecurityAlarmAction_bdk_irq = 4,  /**< \brief Sends a request to the CSS for blocking Debug Protected Keys. And
 * sends an interrupt request to the interrupt system. */
    IfxSmu_SecurityAlarmAction_nmi = 5,      /**< \brief Sends an NMI request to the SCU. */
    IfxSmu_SecurityAlarmAction_reset = 6,    /**< \brief Sends a RESET request to the SCU. The SCU shall be configured to
 * generate an application or system reset. */
    IfxSmu_SecurityAlarmAction_irq = 7,      /**< \brief Sends an interrupt request to the interrupt system. */
    IfxSmu_SecurityAlarmAction_disabled = 0  /**< \brief No Action. Reset value. Alarm disabled. */
} IfxSmu_SecurityAlarmAction;

/** \brief Security Alarm Executed Status.
 * Definition in MODULE_SMU.CS.AEXCLR.U
 */
typedef enum
{
    IfxSmu_SecurityAlarmExecutedStatus_irq0 = 0,      /**< \brief CS_IRQ Request Status */
    IfxSmu_SecurityAlarmExecutedStatus_nmi = 9,       /**< \brief CS_NMI Request Status */
    IfxSmu_SecurityAlarmExecutedStatus_rst = 10,      /**< \brief CS_RESET Request Status */
    IfxSmu_SecurityAlarmExecutedStatus_bdk = 14,      /**< \brief BLOCK_DBG_PROT_KEYS Request Status */
    IfxSmu_SecurityAlarmExecutedStatus_bk = 15,       /**< \brief BLOCK_ALL_KEYS Request Status */
    IfxSmu_SecurityAlarmExecutedStatus_irq0aem = 16,  /**< \brief CS_IRQ AEM */
    IfxSmu_SecurityAlarmExecutedStatus_nmiaem = 25,   /**< \brief CS_NMI AEM */
    IfxSmu_SecurityAlarmExecutedStatus_rstaem = 26,   /**< \brief CS_RESET AEM */
    IfxSmu_SecurityAlarmExecutedStatus_bdkaem = 30,   /**< \brief BLOCK_DBG_PROT_KEYS AEM */
    IfxSmu_SecurityAlarmExecutedStatus_bkaem = 31     /**< \brief BLOCK_ALL_KEYS AEM */
} IfxSmu_SecurityAlarmExecutedStatus;

/** \brief SMU_CS Control Interface  
 * Definition in MODULE_SMU.CS.CMD.U
 */
typedef enum
{
    IfxSmu_SecurityCommand_start = 0,         /**< \brief Forces the SSM to go to the RUN state from the START state. */
    IfxSmu_SecurityCommand_RTstop = 4,        /**< \brief Stop the recovery Timer. */
    IfxSmu_SecurityCommand_ASCE = 5,          /**< \brief Alarm Status Clear Enable Command. */
    IfxSmu_SecurityCommand_triggerAlarm = 6,  /**< \brief Triggers a software based alarm. */
    IfxSmu_SecurityCommand_aliveTest = 7      /**< \brief Enables the testing of the smu_cs_alive signal. */
} IfxSmu_SecurityCommand;

/** \brief To indicate whether Shared SMU are alarm is used for Safety/Security.
 */
typedef enum
{
    IfxSmu_SharedType_safety = 0,      /**< \brief Safety Alarm */
    IfxSmu_SharedType_security = 1,    /**< \brief Security Alarm */
    IfxSmu_SharedType_unspecified = 2  /**< \brief unspecified alarm */
} IfxSmu_SharedType;

/** \brief SMU_CS State Machine  
 * Definition in MODULE_SMU.CS.DBG.B.SSM
 */
typedef enum
{
    IfxSmu_SmuSecurityState_start = 0,       /**< \brief in started state, Input alarms shall not be processed. */
    IfxSmu_SmuSecurityState_run = 1,         /**< \brief in running state, Input alarm events are processed according to their configuration. */
    IfxSmu_SmuSecurityState_unspecified = 2  /**< \brief unspecified state. */
} IfxSmu_SmuSecurityState;

/** \brief Running state of the SMU State Machine  
 * Definition in MODULE_SMU.DBG.B.SSM
 */
typedef enum
{
    IfxSmu_SmuState_start = 0,       /**< \brief START state */
    IfxSmu_SmuState_run = 1,         /**< \brief RUN State */
    IfxSmu_SmuState_fault = 2,       /**< \brief FAULT State */
    IfxSmu_SmuState_unspecified = 3  /**< \brief unspecified State */
} IfxSmu_SmuState;

/** \brief Controls the sensitivity to the suspend signal coming from the OCDS
 * Definition in Ifx_SMU.OCS.B.SUS
 */
typedef enum
{
    IfxSmu_SuspendMode_none = 0,  /**< \brief Will not suspend */
    IfxSmu_SuspendMode_hard = 1,  /**< \brief Hard suspend. Clock is switched off immediately. */
    IfxSmu_SuspendMode_soft = 2   /**< \brief Soft suspend. */
} IfxSmu_SuspendMode;

/** \brief Actions to Trigger Port Emergency Stop.
 * Definition in MODULE_SMU.SAFE[2].PES.U
 */
typedef enum
{
    IfxSmu_portEmergencyStop_igcs0 = 0,    /**< \brief Enable IGCS0_REQ to trigger port emergency stop. */
    IfxSmu_portEmergencyStop_igcs1 = 1,    /**< \brief Enable IGCS1_REQ to trigger port emergency stop */
    IfxSmu_portEmergencyStop_igcs2 = 2,    /**< \brief Enable IGCS2_REQ to trigger port emergency stop */
    IfxSmu_portEmergencyStop_nmi0 = 3,     /**< \brief Enable NMI0_REQ to trigger port emergency stop */
    IfxSmu_portEmergencyStop_cpurst0 = 4,  /**< \brief Enable CPU_RESET0_REQ to trigger port emergency stop */
    IfxSmu_portEmergencyStop_ppurst0 = 5,  /**< \brief Enable PPU_RESET0_REQ to trigger port emergency stop */
    IfxSmu_portEmergencyStop_nmi1 = 6,     /**< \brief Enable NMI1_REQ to trigger port emergency stop */
    IfxSmu_portEmergencyStop_cpurst1 = 7,  /**< \brief Enable CPU_RESET1_REQ to trigger port emergency stop */
    IfxSmu_portEmergencyStop_fsp0 = 16,    /**< \brief Enable FSP0_REQ to trigger port emergency stop */
    IfxSmu_portEmergencyStop_fsp1 = 17     /**< \brief Enable FSP1_REQ to trigger port emergency stop */
} IfxSmu_portEmergencyStop;

/** \} */ 
 

/** \addtogroup IfxLld_Smu_Std_ModuleFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief This function clears SMU alarm executed status of the requested alarm mechanism.
 *
 * \param[in] smuSafeIndex SMU SAFE ID.
 * \param[in] alarmEx      Alarm Mechanism. Range: \ref IfxSmu_AlarmExecutionStatus.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_clearSafetyAlarmExecutedStatus(boolean smuSafeIndex, IfxSmu_AlarmExecutionStatus alarmEx);

/** \brief Function sets the Port control hardware Enable and direction.
 * 
 * The PCTL register needs to be unlocked by using IfxSmu_unlockConfigRegisters() before calling this function. 
 *
 * \param[in] smuIndex SMU SAFE module ID.
 * \param[in] fspIndex FSP index number.
 * \param[in] status   Set/Clear and Enable/Disable of the Hardware Port Enable & DIR Bits.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_setPortControlHwEnableAndDir(boolean smuIndex, boolean fspIndex, boolean status);

/** \brief Function sets the Register monitor test mode enable Flag.
 * 
 * The RMCTL register needs to be unlocked by using IfxSmu_unlockConfigRegisters() before calling this function. 
 *
 * \param[in] regMonIndex    Register Monitor Index. Range: 0 or 1.
 * \param[in] testModeEnable Test Mode Flag. Range: 0 to 31.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_setRegMonTestModeEnable(uint8 regMonIndex, uint8 testModeEnable);

/** \brief Configure the Module to Hard/Soft suspend mode.
 *
 * Note: The api works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled the OCS suspend control is ineffective.
 *
 * \param[inout] smu  Pointer to SMU module registers.
 * \param[in]    mode Module suspend mode. Range: \ref IfxSmu_SuspendMode.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_setSuspendMode(Ifx_SMU* smu, IfxSmu_SuspendMode mode);

/** \brief This function starts the SMU alive test.
 *
 * \param[in] smuIndex SMU SAFE module ID.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_startSafetyAliveTest(boolean smuIndex);

/** \brief This function Stops the SMU alive test.
 *
 * \param[in] smuIndex SMU SAFE module ID.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_stopSafetyAliveTest(boolean smuIndex);

/** \brief Returns The SRCR pointer for the selected Interrupt.
 *
 * \param[in] intRequest SMU SAFE module ID. Range: \ref IfxSmu_InterruptRequest.
 *
 * \retval Ifx_SRC_SRCR* Pointer to SRCR register.
 */
IFX_INLINE volatile Ifx_SRC_SRCR* IfxSmu_getSrcPointer(IfxSmu_InterruptRequest intRequest);

/** \brief This function clears SMU alarm exected status of the requested alarm mechanism.
 *
 * \param[in] alarmEx Alarm mechanism. Range: \ref IfxSmu_SecurityAlarmExecutedStatus.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_clearSecurityAlarmExecutedStatus(IfxSmu_SecurityAlarmExecutedStatus alarmEx);

/** \brief The function returns the alarm Executed status of requested alarm mechanism.
 *
 * \param[in] alarmEx alarm mechanism. Range: \ref IfxSmu_SecurityAlarmExecutedStatus.
 *
 * \retval Alarm Executed status of requested alarm mechanism.
 */
IFX_INLINE boolean IfxSmu_getSecurityAlarmExecutedStatus(IfxSmu_SecurityAlarmExecutedStatus alarmEx);

/** \brief This function starts the SMU alive test.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_startSecurityAliveTest(void);

/** \brief This function Stops the SMU alive test.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_stopSecurityAliveTest(void);

/** \brief This function waits for SMU alarm to be set and then clears it. 
 *
 * \param[in] alarm Smu alarm group and position. Range: \ref IfxSmu_Alarm.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_waitForSecurityAlarm(IfxSmu_Alarm alarm);

/** \brief Returns The SRCR pointer for the selected Interrupt. 
 *
 * \retval Ifx_SRC_SRCR* Pointer to SRCR register.
 */
IFX_INLINE volatile Ifx_SRC_SRCR* IfxSmu_getSecuritySrcPointer(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief The function sets the alarm action for the desired alarm. 
 *
 * \param[in] alarm          Smu alarm group and position. Range: \ref IfxSmu_Alarm.
 * \param[in] intAlarmAction Internal alarm action. Range: \ref IfxSmu_InternalAlarmAction.
 * \param[in] smuSafeIndex   SMU SAFE ID.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_setSafetyAlarmAction(IfxSmu_Alarm alarm, IfxSmu_InternalAlarmAction intAlarmAction, boolean smuSafeIndex);

/** \brief The API sets the requested alarm.    
 * This function can be used by the user software to trigger SW SMU alarm. During the START state of the SMU, it shall be possible to set any of the alarms.
 * However, during the RUN state, only the SW alarms shall be set.
 *
 * \param[in] alarm                 Smu alarm group and position. Range: \ref IfxSmu_Alarm.
 * \param[in] smuSafeIndex          SMU Safe ID.
 * \param[in] smuSafeStateMachineId State Machine Index.
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_setSafetyAlarmStatus(IfxSmu_Alarm alarm, boolean smuSafeIndex, boolean smuSafeStateMachineId);

/** \brief The function allows to switch the SMU peripheral into the RUN fault-free state as requested by the caller.
 *
 * \param[in] smuSafeIndex          SMU Safe Id.
 * \param[in] smuSafeStateMachineId State Machine Index.
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_smuSafeActivateRunState(boolean smuSafeIndex, boolean smuSafeStateMachineId);

/** \brief This function clears SMU alarm status of the requested alarm. It needs to be called after alarm status is read. 
 *
 * \param[in] alarm        Smu alarm group and position. Range: \ref IfxSmu_Alarm.
 * \param[in] smuSafeIndex SMU Safe ID.
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_smuSafeClearAlarmStatus(IfxSmu_Alarm alarm, boolean smuSafeIndex);

/** \brief The function returns the alarm status of requested alarm. 
 *
 * \param[in] alarm        Smu alarm group and position. Range: \ref IfxSmu_Alarm.
 * \param[in] smuSafeIndex SMU Safe ID.
 *
 * \retval Alarm status of requested alarm.
 */
IFX_EXTERN boolean IfxSmu_smuSafeGetAlarmStatus(IfxSmu_Alarm alarm, boolean smuSafeIndex);

/** \brief The function provides the current state of the SMU. 
 *
 * \param[in] smuSafeIndex          SMU Safe ID
 * \param[in] smuSafeStateMachineId State Machine Index.
 *
 * \retval IfxSmu_SmuState Return the current state of SMU. Range: \ref IfxSmu_SmuState.
 */
IFX_EXTERN IfxSmu_SmuState IfxSmu_getSmuSafeState(boolean smuSafeIndex, boolean smuSafeStateMachineId);

/** \brief This function waits for SMU alarm to be set and then clears it.
 *
 * \param[in] alarm        Smu alarm group and position. Range: \ref IfxSmu_Alarm.
 * \param[in] smuSafeIndex SMU Safe Index.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_smuSafeWaitForAlarm(IfxSmu_Alarm alarm, boolean smuSafeIndex);

/** \brief This function configures the PES feature for internal action.
 * Bit0/1/2/3 - SMU_IGCS0/SMU_IGCS1/SMU_IGCS2/SMU_NMI/SMU_CPU_RESET activates PES correspondingly.
 * 
 * The AGC register needs to be unlocked by using IfxSmu_unlockConfigRegisters() before calling this function. 
 *
 * \param[in] pesAction PES action bit0/1/2/3 - SMU_IGCS0/SMU_IGCS1/SMU_IGCS2/SMU_NMI/SMU_CPU_RESET activates PES correspondingly.
 *                      Range:
 *                      - 0x01(SMU_IGCS0),
 *                      - 0x02(SMU_IGCS1),
 *                      - 0x04(SMU_IGCS2),
 *                      - 0x08(SMU_NMI),
 *                      - 0x10(SMU_CPU_RESET).
 * \param[in] smuSafeIndex SMU Safe ID.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_safetyConfigAlarmActionPES(uint32 pesAction, boolean smuSafeIndex);

/** \brief This function activates the FSP to indicate a FAULT state on the error pin to the safe state switching device. 
 *
 * \param[in] smuSafeIndex          SMU Safe ID.
 * \param[in] smuSafeStateMachineId SSM ID.
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_smu_SafeActivateFSP(boolean smuSafeIndex, boolean smuSafeStateMachineId);

/** \brief The function switches the SMU peripheral from the FAULT state to the RUN state. 
 *
 * \param[in] smuSafeIndex          SMU Safe ID
 * \param[in] smuSafeStateMachineId SMU Safe State Machine ID.
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_smuSafeReleaseFSP(boolean smuSafeIndex, boolean smuSafeStateMachineId);

/** \brief The function locks the SMU configuration registers to prevent any modification to configuration register content.
 *
 * \param[in] smuSafeIndex SMU Safe ID.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_smuSafeLockConfigRegisters(boolean smuSafeIndex);

/** \brief The API stops the requested recovery timer unit. 
 *
 * \param[in] timerNum     Recovery Timer unit to be stopped. Range: 0 to 15.
 * \param[in] smuSafeIndex SMU Safe ID.
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_smuSafeStopRT(uint8 timerNum, boolean smuSafeIndex);

/** \brief The function unlocks the SMU configuration registers for modification. 
 *
 * \param[in] smuSafeIndex SMU Safe ID.
 *
 * \retval Return 0 if SMU configurations is locked permanently and unlock not possible, 1 if unlocked successfully.
 */
IFX_EXTERN boolean IfxSmu_smuSafeUnlockConfigRegisters(boolean smuSafeIndex);

/** \brief The function temporarily locks the SMU configuration registers for modification. 
 *
 * \param[in] smuSafeIndex SMU Safe ID.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_smuSafeTemporaryLockConfigRegisters(boolean smuSafeIndex);

/** \brief The API sets the requested alarm.    
 * This function can be used by the user software to trigger SW SMU alarm. During the START state of the SMU, it shall be possible to set any of the alarms.
 *  However, during the RUN state, only the SW alarms shall be set.
 *
 * \param[in] alarm Input alarm ID. Range: \ref IfxSmu_Alarm.
 *
 * \retval Return Status if pass/fail.
 */
IFX_EXTERN boolean IfxSmu_setSecurityAlaramStatus(IfxSmu_Alarm alarm);

/** \brief The function allows to switch the SMU peripheral into the  RUN fault-free state as requested by the caller. 
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_smuSecurityActivateRunState(void);

/** \brief This function clears SMU alarm status of the requested alarm. It needs to be called after alarm status is read. 
 *
 * \param[in] alarm SMU alarm ID. Range: \ref IfxSmu_Alarm.
 *
 * \retval Return status if pass/fail.
 */
IFX_EXTERN boolean IfxSmu_smuSecurityClearAlarmStatus(IfxSmu_Alarm alarm);

/** \brief The function returns the alarm status of requested alarm. 
 *
 * \param[in] alarm SMU Alarm ID. Range: \ref IfxSmu_Alarm.
 *
 * \retval Return Status if pass/fail.
 */
IFX_EXTERN boolean IfxSmu_smuSecurityGetAlarmStatus(IfxSmu_Alarm alarm);

/** \brief The function provides the current state of the SMU. 
 *
 * \retval IfxSmu_SmuSecurityState return the current state of SMU. Range: \ref IfxSmu_SmuSecurityState.
 */
IFX_EXTERN IfxSmu_SmuSecurityState IfxSmu_getSmuSecurityState(void);

/** \brief This function waits for SMU alarm to be set and then clears it.
 *
 * \param[in] alarm SMU Alarm ID. Range: \ref IfxSmu_Alarm.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_smuSecurityWaitForAlarm(IfxSmu_Alarm alarm);

/** \brief The function locks the SMU configuration registers to prevent any modification to configuration register content.
 *
 * \retval None.
 */
IFX_EXTERN void IfxSmu_smuSecurityLockConfigRegisters(void);

/** \brief The API stops the requested recovery timer unit. 
 *
 * \param[in] timerNum Recovery Timer unit to be stopped. Range: 0 to 15.
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_smuSecurityStopRT(uint8 timerNum);

/** \brief The function unlocks the SMU configuration registers for modification. 
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_smuSecurityUnlockConfigRegisters(void);

/** \brief The function temporarily locks the SMU configuration registers for modification. 
 *
 * \retval None.
 */
IFX_EXTERN void IfxSmu_smuSecurityTemporaryLockConfigRegisters(void);

/** \brief Function clears the Register monitor test mode enable Flag.
 * 
 * The RMCTL register needs to be unlocked by using IfxSmu_unlockConfigRegisters() before calling this function. 
 *
 * \param[in] regMonIndex    Register Monitor Index. Range: 0 or 1.
 * \param[in] testModeEnable Test Mode Flag. Range: 0 to 31.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_clearRegMonTestModeEnable(uint8 regMonIndex, uint8 testModeEnable);

/** \brief Function clears the Register Monitor Error Flag (RMEF.EFz). 
 *
 * \param[in] regMonIndex Register Monitor Index. Range: 0 or 1.
 * \param[in] errorFlag Error Flag. Range: 0 to 31.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_clearRegisterMonitorErrorFlag(uint8 regMonIndex, uint8 errorFlag);

/** \brief Function clears the Register Monitor status register. 
 *
 * \param[in] regMonIndex Register Monitor Index. Range: 0 or 1.
 * \param[in] statusFlag Status Flag. Range: 0 to 31.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_clearRegisterMonitorStatus(uint8 regMonIndex, uint8 statusFlag);

/** \brief This function configures the PES feature for internal action. 
 *
 * \param[in] smuIndex SMU SAFE module ID.
 * \param[in] pesField PES Action to be performed based on the request. Range: \ref IfxSmu_portEmergencyStop.
 * \param[in] Action   Enable or Disable of the required PES ACTION.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_configAlarmActionPES(boolean smuIndex, IfxSmu_portEmergencyStop pesField, boolean Action);

/** \brief The function provides the FSP action currently configured for the requested alarm. 
 *
 * \param[in] alarm          SMU Alarm ID. Range: \ref IfxSmu_Alarm.
 * \param[in] intAlarmAction Internal alarm action. Range: \ref IfxSmu_InternalAlarmAction.
 * \param[in] smuIndex       SMU SAFE module ID.
 *
 * \retval IfxSmu_InternalAlarmAction FSP enabled/disabled for the particular alarm. Range: \ref IfxSmu_InternalAlarmAction.
 */
IFX_EXTERN IfxSmu_InternalAlarmAction IfxSmu_getSafetyAlarmAction(IfxSmu_Alarm alarm, IfxSmu_InternalAlarmAction intAlarmAction, boolean smuIndex);

/** \brief The function returns the alarm Executed status of requested alarm mechanism.
 *
 * \param[in] alarmEx  Alarm mechanism. Range: \ref IfxSmu_AlarmExecutionStatus.
 * \param[in] smuIndex SMU SAFE module ID.
 *
 * \retval Alarm executed status of requested alarm mechanism.
 */
IFX_EXTERN boolean IfxSmu_getSafetyAlarmExecutedStatus(IfxSmu_AlarmExecutionStatus alarmEx, boolean smuIndex);

/** \brief The function provides the alarm group status from the stored debug  registers.
 *
 * \param[in] alarmGroup Smu alarm group. Range: 0 to 16.
 * \param[in] smuIndex   SMU SAFE module ID.
 *
 * \retval uint32 alarm group status from the stored debug registers. Range: 0 to 0xFFFFFFFF.
 */
IFX_EXTERN uint32 IfxSmu_getSafetyAlarmGroupDebugStatus(uint8 alarmGroup, boolean smuIndex);

/** \brief The function returns the alarm status of requested alarm. 
 *
 * \param[in] alarm    Smu alarm group and position. Range: \ref IfxSmu_Alarm.
 * \param[in] smuIndex SMU SAFE module ID.
 *
 * \retval Alarm status of requested alarm.
 */
IFX_EXTERN boolean IfxSmu_getSafetyAlarmStatus(IfxSmu_Alarm alarm, boolean smuIndex);

/** \brief Function returns the Port control hardware direction. 
 *
 * \param[in] smuIndex SMU SAFE module ID.
 * \param[in] fspIndex FSP index number.
 *
 * \retval Port Conrol HW direction.
 */
IFX_EXTERN boolean IfxSmu_getPortControlHwDir(boolean smuIndex, boolean fspIndex);

/** \brief Function returns the Port control hardware enable. 
 *
 * \param[in] smuIndex SMU SAFE module ID.
 * \param[in] fspIndex FSP Index number.
 *
 * \retval Port Control HW enable
 */
IFX_EXTERN boolean IfxSmu_getPortControlHwEnable(boolean smuIndex, boolean fspIndex);

/** \brief The function returns if any alarms requiring the requested recovery timer was SET while the recovery timer was running. 
 *
 * \param[in] smuIndex SMU SAFE module ID.
 * \param[in] timerNum Recovery Timer unit. Range: 0 to 0xFF.
 *
 * \retval Returns status of missed event (0 - no missed event, 1 - missed event)
 */
IFX_EXTERN boolean IfxSmu_getSafetyRTMissedEvent(boolean smuIndex, uint8 timerNum);

/** \brief Function returns the value ofRegister Monitor Error Flags register. 
 *
 * \param[in] regMonIndex Register Monitor Index. Range: 0 or 1.
 *
 * \retval uint32 Returns the Register Monitor Error Flags register value. Range: 0 to 0xFFFFFFFF.
 */
IFX_EXTERN uint32 IfxSmu_getRegisterMonitorErrorFlag(uint8 regMonIndex);

/** \brief Function returns the value of Register Monitor Self Test Status register. 
 *
 * \param[in] regMonIndex Register Monitor Index. Range: 0 or 1.
 *
 * \retval uint32 Returns the Register monitor self Test Status register value. Range: 0 to 0xFFFFFFFF.
 */
IFX_EXTERN uint32 IfxSmu_getRegisterMonitorStatus(uint8 regMonIndex);

/** \brief Returns the module's suspend state.
 *
 * \param[in] smu Pointer to SMU module registers.
 *
 * \retval TRUE :if module is suspended.
 *         FALSE:if module is not yet suspended.
 */
IFX_EXTERN boolean IfxSmu_isModuleSuspended(Ifx_SMU* smu);

/** \brief Configure FSP (fault Signalling Protocol) mode.
 * 
 * The FSP register needs to be unlocked by using IfxSmu_unlockConfigRegisters() before calling this function. 
 *
 * \param[in] smuIndex SMU SAFE module ID.
 * \param[in] fspIndex FSP index number.
 * \param[in] mode FSP Mode. Range: \ref IfxSmu_FspMode.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_setFspMode(boolean smuIndex, boolean fspIndex, IfxSmu_FspMode mode);

/** \brief The API stops the requested recovery timer unit.
 *
 * \param[in] smuIndex SMU SAFE module ID.
 * \param[in] timerNum Recovery Timer unit to be stopped. Range: 0 to 15.
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_stopSafetyRT(boolean smuIndex, uint8 timerNum);

/** \brief Configures The Interrupt Generation.
 *
 * \param[in] config     Configuration Selection. Range: \ref IfxSmu_InterruptGenerationConfiguration.
 * \param[in] smuIndex   SMU SAFE module ID.
 * \param[in] intRequest Interrupt Request. Range: \ref IfxSmu_InterruptRequest.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_safetyConfigureInterruptGeneration(IfxSmu_InterruptGenerationConfiguration config, boolean smuIndex, IfxSmu_InterruptRequest intRequest);

/** \brief The function provides the FSP action currently configured for the requested alarm. 
 *
 * \param[in] alarm Smu alarm group and position. Range: \ref IfxSmu_Alarm.
 *
 * \retval IfxSmu_SecurityAlarmAction Security Alarm Action. Range: \ref IfxSmu_SecurityAlarmAction.
 */
IFX_EXTERN IfxSmu_SecurityAlarmAction IfxSmu_getSecurityAlarmAction(IfxSmu_Alarm alarm);

/** \brief The function provides the alarm group status from the stored debug  registers.
 *
 * \param[in] alarmGroup Smu alarm group. Range: 0 or 1.
 *
 * \retval uint32 Alarm group status from the stored debug registers. Range: 0 to 0xFFFFFFFF.
 */
IFX_EXTERN uint32 IfxSmu_getSecurityAlarmGroupDebugStatus(uint8 alarmGroup);

/** \brief The function returns the alarm status of requested alarm. 
 *
 * \param[in] alarm smu alarm group and position.
 *
 * \retval IfxSmu_Alarm Alarm status of requested alarm. Range: \ref IfxSmu_Alarm.
 */
IFX_EXTERN boolean IfxSmu_getSecurityAlarmStatus(IfxSmu_Alarm alarm);

/** \brief The function returns if any alarms requiring the requested recovery timer was SET while the recovery timer was running. 
 *
 * \retval Returns status of missed event (0 - no missed event, 1 - missed event).
 */
IFX_EXTERN boolean IfxSmu_getSecurityRTMissedEvent(void);

/** \brief The function provides the current state of the security SMU. 
 *
 * \retval IfxSmu_SmuSecurityState Return the current state of security SMU. Range: \ref IfxSmu_SmuSecurityState.
 */
IFX_EXTERN IfxSmu_SmuSecurityState IfxSmu_getSecuritySmuState(void);

/** \brief The API stops the requested recovery timer unit. 
 *
 * \param[in] timerNum Recovery Timer unit to be stopped. Range: 0 to 15.
 *
 * \retval Return 0 if successful and 1 if failed.
 */
IFX_EXTERN boolean IfxSmu_stopSecurityRT(uint8 timerNum);

/** \brief Interface to configure Shared SMU alarms either to Safety/Security SMUs. 
 *
 * \param[in] SharedType Type of SMU to be configured for Shared SMU alarms. Range: \ref IfxSmu_SharedType.
 * \param[in] alarm      SMU Alarm ID. Range: \ref IfxSmu_Alarm.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_configureSharedSelectionRegister(IfxSmu_SharedType SharedType, IfxSmu_Alarm alarm);

/** \brief Interface to get Status of Shared Selection Register either used be Safety/Security SMUs.
 *
 * \param[in] SharedType Type of SMU to be configured for Shared SMU alarms. Range: \ref IfxSmu_SharedType.
 * \param[in] alarm SMU  Alarm ID. Range: \ref IfxSmu_Alarm.
 *
 * \retval Return Status of Shared Selection Register.
 */
IFX_EXTERN boolean IfxSmu_getSharedSelectionStatus(IfxSmu_SharedType SharedType, IfxSmu_Alarm alarm);

/** \brief Initialize the SMU Shared Safety alarm action.
 * Note: Since the shared alarms share the global config w.r.t AGC,RTC please use the IfxSmu_Smu_initSafetyGlobal API to initialize the Global Config.
 * This is to be done only in case the SAFE init is not done. In case the safe init is done, the same global config can be used for the shared alarms mapped to safe instance.
 *
 * \param[in] alarm          SMU alarm. Range: \ref IfxSmu_Alarm.
 * \param[in] intAlarmAction Internal Alarm Action. Range: \ref IfxSmu_InternalAlarmAction.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_setSharedSafetyAlarmAction(IfxSmu_Alarm alarm, IfxSmu_InternalAlarmAction intAlarmAction);

/** \brief Configure the shared Safety Alarm Status.
 *
 * \param[in] alarm                 SMU alarm. Range: \ref IfxSmu_Alarm.
 * \param[in] smuSafeStateMachineId SMU SAFE SSM ID.
 *
 * \retval Return Status
 */
IFX_EXTERN boolean IfxSmu_setSharedSafetyAlarmStatus(IfxSmu_Alarm alarm, boolean smuSafeStateMachineId);

/** \brief Initialize the SMU Shared Secure alarm action.
 * Note: Since the shared alarms share the global config w.r.t AGC,RTC please use the IfxSmu_Smu_initSecureGlobal API to initialize the Global Config. This is to be done only in case the Secure init is not done.
 * In case the secure init is done, the same global config can be used for the shared alarms mapped to secure instance.
 *
 * \param[in] alarm       SMU alarm. Range: \ref IfxSmu_Alarm.
 * \param[in] AlarmAction Security Alarm action. Range: \ref IfxSmu_SecurityAlarmAction.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_setSharedSecurityAlarmAction(IfxSmu_Alarm alarm, IfxSmu_SecurityAlarmAction AlarmAction);

/** \brief Configure the shared secure alarm status.
 *
 * \param[in] Alarm SMU alarm. Range: \ref IfxSmu_Alarm.
 *
 * \retval Return status
 */
IFX_EXTERN boolean IfxSmu_setSharedSecurityAlaramStatus(IfxSmu_Alarm alarm);

/** \brief Return the action configured for shared safety alarms.
 *
 * \param[in] alarm          SMU alarm. Range: \ref IfxSmu_Alarm.
 * \param[in] intAlarmAction Internal Alarm Action. Range: \ref IfxSmu_InternalAlarmAction.
 * \param[in] smuIndex       SMU index.
 *
 * \retval IfxSmu_InternalAlarmAction Internal Alarm Action configured. Range: \ref IfxSmu_InternalAlarmAction.
 */
IFX_EXTERN IfxSmu_InternalAlarmAction IfxSmu_getSharedSafetyAlarmAction(IfxSmu_Alarm alarm, IfxSmu_InternalAlarmAction intAlarmAction, boolean smuIndex);

/** \brief Return the action configured for shared secure alarms.
 *
 * \param[in] alarm SMU alarm. Range: \ref IfxSmu_Alarm.
 *
 * \retval IfxSmu_SecurityAlarmAction Security Alarm Action configured. Range: \ref IfxSmu_SecurityAlarmAction.
 */
IFX_EXTERN IfxSmu_SecurityAlarmAction IfxSmu_getSharedSecurityAlarmAction(IfxSmu_Alarm alarm);

/** \} */  


/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief This function waits for SMU alarm to be set and then clears it.
 *
 * \param[in] alarm smu alarm group and position. Range: \ref IfxSmu_Alarm.
 * \param[in] smuIndex SMU SAFE module ID.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_waitForSafetyAlarm(IfxSmu_Alarm alarm, boolean smuIndex);

/** \brief The API can be used to map/clear the mapping of a shared alarm to safe SMU.
 *
 * \param[in] alarm SMU alarm. Range: \ref IfxSmu_Alarm.
 * \param[in] enable Set to 1 to map the alarm, set to 0 to clear and disable mapping.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_setSharedSafeSelection(IfxSmu_Alarm alarm, boolean enable);

/** \brief The API can be used to map/clear the mapping of a shared alarm to secure SMU.
 *
 * \param[in] alarm  SMU alarm. Range: \ref IfxSmu_Alarm.
 * \param[in] enable Set to 1 to map the alarm, set to 0 to clear and disable mapping.
 *
 * \retval None
 */
IFX_INLINE void IfxSmu_setSharedSecureSelection(IfxSmu_Alarm alarm, boolean enable);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief The function sets the alarm action for the desired alarm. 
 *
 * \param[in] alarm       Smu alarm group and position. Range: \ref IfxSmu_Alarm.
 * \param[in] AlarmAction Security alarm action. Range: \ref IfxSmu_SecurityAlarmAction.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_setSecurityAlarmAction(IfxSmu_Alarm alarm, IfxSmu_SecurityAlarmAction AlarmAction);

/** \brief API to enable Fault to RUN state.
 *
 * \param[in] smuIndex  SMU Safe module ID.
 * \param[in] stateType SSM0 or SSM1.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_enableFaultToRunState(boolean smuIndex, boolean stateType);

/** \brief API returns the shared alarm status.
 *
 * \param[in] SharedType Shared alarm type. Range: \ref IfxSmu_SharedType.
 * \param[in] alarm SMU  Alarm. Range: \ref IfxSmu_Alarm.
 * \param[in] smuIndex   Safe smuIndex.
 *
 * \retval Returns the Alarms Status
 */
IFX_EXTERN boolean IfxSmu_getSharedAlarmStatus(IfxSmu_SharedType SharedType, IfxSmu_Alarm alarm, boolean smuIndex);

/** \brief Lock SMU Shared registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_smuSharedLockConfigRegisters(void);

/** \brief The function unlocks the SMU Shared configuration registers for modification. 
 *
 * \retval Return 0 if SMU Shared configurations is locked permanently and unlock not possible, 1 if unlocked successfully.
 */
IFX_EXTERN boolean IfxSmu_smuSharedUnlockConfigRegisters(void);

/** \brief The function temporarily locks the SMU Shared configuration registers for modification. 
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_smuSharedTemporaryLockConfigRegisters(void);

/** \brief Configures access to all masters to the Global Configuration SMU's in the device.
 *
 * \param[in] apConfig Config pointer to configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_configureAccessToGlobalConfigurationSmu(IfxApApu_ApuConfig* apConfig);

/** \brief Configures access to all masters to the Security SMU's in the device.
 *
 * \param[in] apConfig Config pointer to configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_configureAccessToSecuritySmu(IfxApApu_ApuConfig* apConfig);

/** \brief Configures access to all masters to the Safety SMU's in the device.
 *
 * \param[in] apConfig Config pointer to configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxSmu_configureAccessToSafetySmu(IfxApApu_ApuConfig* apConfig);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/


IFX_INLINE void IfxSmu_clearSafetyAlarmExecutedStatus(boolean smuSafeIndex, IfxSmu_AlarmExecutionStatus alarmEx)
{
    /* Register protected by APU-PSAFEx register set and not PROT */

    /* Write 1 in AEX bit to clear alarm Executed mechanism */
    MODULE_SMU.SAFE[smuSafeIndex].AEXCLR.U = (uint32)((uint32)0x1U << alarmEx);
}


IFX_INLINE void IfxSmu_setPortControlHwEnableAndDir(boolean smuIndex, boolean fspIndex, boolean status)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMU.SAFE[smuIndex].PROTSE, IfxApProt_State_config);
#endif

    if (fspIndex == 0)
    {
        MODULE_SMU.SAFE[smuIndex].PCTL.B.HWDIR0 = status;
        MODULE_SMU.SAFE[smuIndex].PCTL.B.HWEN0  = status;
    }
    else
    {
        MODULE_SMU.SAFE[smuIndex].PCTL.B.HWDIR1 = status;
        MODULE_SMU.SAFE[smuIndex].PCTL.B.HWEN1  = status;
    }

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMU.SAFE[smuIndex].PROTSE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmu_setRegMonTestModeEnable(uint8 regMonIndex, uint8 testModeEnable)
{
    /* disable the write-protection for registers */
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMU.GCC.PROTGE, IfxApProt_State_config);
#endif

    MODULE_SMU.GCC.RM[regMonIndex].CTL.U |= (1U << testModeEnable);

    /* Restore back the write-protection for registers */
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMU.GCC.PROTGE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmu_setSuspendMode(Ifx_SMU* smu, IfxSmu_SuspendMode mode)
{
    Ifx_SMU_OCS ocs;

    /* remove protection and configure the suspend mode. */
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    smu->OCS.U = ocs.U;
}


IFX_INLINE void IfxSmu_startSafetyAliveTest(boolean smuIndex)
{
    Ifx_SMU_SAFE_CMD cmdSfr;
    cmdSfr.U                            = MODULE_SMU.SAFE[smuIndex].CMD.U;
    cmdSfr.B.CMD                        = IfxSmu_Command_aliveTest;
    cmdSfr.B.ARG                        = IFXSMU_START_ALIVE_TEST_ARG;
    MODULE_SMU.SAFE[smuIndex].CMD.U = cmdSfr.U;
}


IFX_INLINE void IfxSmu_stopSafetyAliveTest(boolean smuIndex)
{
    Ifx_SMU_SAFE_CMD cmdSfr;
    cmdSfr.U                            = MODULE_SMU.SAFE[smuIndex].CMD.U;
    cmdSfr.B.CMD                        = IfxSmu_Command_aliveTest;
    cmdSfr.B.ARG                        = IFXSMU_STOP_ALIVE_TEST_ARG;
    MODULE_SMU.SAFE[smuIndex].CMD.U = cmdSfr.U;
}


IFX_INLINE void IfxSmu_waitForSafetyAlarm(IfxSmu_Alarm alarm, boolean smuIndex)
{
    while(!IfxSmu_getSafetyAlarmStatus(alarm,smuIndex));
IfxSmu_smuSafeClearAlarmStatus(alarm,smuIndex);
}


IFX_INLINE volatile Ifx_SRC_SRCR* IfxSmu_getSrcPointer(IfxSmu_InterruptRequest intRequest)
{
    return &MODULE_SRC.SMU.IRQ[intRequest];
}


IFX_INLINE void IfxSmu_clearSecurityAlarmExecutedStatus(IfxSmu_SecurityAlarmExecutedStatus alarmEx)
{
    /* Write 1 in AEX bit to clear alarm Executed mechanism */
    MODULE_SMU.CS.AEXCLR.U = (uint32)((uint32)0x1U << alarmEx);
}


IFX_INLINE boolean IfxSmu_getSecurityAlarmExecutedStatus(IfxSmu_SecurityAlarmExecutedStatus alarmEx)
{
    boolean alarmExecuteStatus = (boolean)((MODULE_SMU.CS.AEX.U >> alarmEx) & 0x1);
    return alarmExecuteStatus;
}


IFX_INLINE void IfxSmu_startSecurityAliveTest(void)
{
    Ifx_SMU_CS_CMD cmdSfr;
    cmdSfr.U           = MODULE_SMU.CS.CMD.U;
    cmdSfr.B.CMD       = IfxSmu_Command_aliveTest;
    cmdSfr.B.ARG       = IFXSMU_START_ALIVE_TEST_ARG;
    MODULE_SMU.CS.CMD.U = cmdSfr.U;
}


IFX_INLINE void IfxSmu_stopSecurityAliveTest(void)
{
    Ifx_SMU_CS_CMD cmdSfr;
    cmdSfr.U           = MODULE_SMU.CS.CMD.U;
    cmdSfr.B.CMD       = IfxSmu_Command_aliveTest;
    cmdSfr.B.ARG       = IFXSMU_STOP_ALIVE_TEST_ARG;
    MODULE_SMU.CS.CMD.U = cmdSfr.U;
}


IFX_INLINE void IfxSmu_waitForSecurityAlarm(IfxSmu_Alarm alarm)
{
    while(!IfxSmu_getSecurityAlarmStatus(alarm));
    IfxSmu_smuSecurityClearAlarmStatus(alarm);
}


IFX_INLINE volatile Ifx_SRC_SRCR* IfxSmu_getSecuritySrcPointer(void)
{
    return &MODULE_SRC.SMU.CSIRQ;
}


IFX_INLINE void IfxSmu_setSharedSafeSelection(IfxSmu_Alarm alarm, boolean enable)
{
    Ifx_SMU_GCC_AGSH_SEL selReg;
    uint16  alarmGroup = ((int)alarm >> 5);
    uint8   alarmPos   = (int)alarm & 0x1F;

    selReg.U = MODULE_SMU.GCC.AGSH[alarmGroup].SEL.U;

    selReg.U  = (selReg.U & (~(1 << alarmPos))) | (uint32)(enable << alarmPos);

    MODULE_SMU.GCC.AGSH[alarmGroup].SEL.U = selReg.U;
}


IFX_INLINE void IfxSmu_setSharedSecureSelection(IfxSmu_Alarm alarm, boolean enable)
{
    Ifx_SMU_CS_AGSH_SEL selReg;
    uint16  alarmGroup = ((int)alarm >> 5);
    uint8   alarmPos   = (int)alarm & 0x1F;

    selReg.U = MODULE_SMU.CS.AGSH[alarmGroup].SEL.U;

    selReg.U  = (selReg.U & (~(1 << alarmPos))) | (uint32)(enable << alarmPos);

    MODULE_SMU.CS.AGSH[alarmGroup].SEL.U = selReg.U;
}

#endif /* IFXSMU_H */
