/**
 * \file IfxPmsPm.h
 * \brief PMS  basic functionality
 * \ingroup IfxLld_Pms
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
 * \defgroup IfxLld_Pms_Std_Pm How to use the PMS PM driver?
 * \ingroup IfxLld_Pms_Std
 *
 * The PMS Power Management driver provides APIs to configure, control, and monitor the device's power modes, including sleep and standby.
 * It enables flexible management of system and CPU power states, wakeup sources, voltage droop and load jump handling, and supply monitoring for robust low-power operation.
 * The driver supports initialization of power mode configurations, entry and exit sequences for sleep/standby, and fine-grained control over wakeup and voltage supervision features.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Pms_Std_Pm_Preparation Preparation
 * \subsection IfxLld_Pms_Std_Pm_Include Include Files
 *
 * Include following header file into your C code:
 *
 * \code
 * #include <Pms/Std/IfxPmsPm.h>
 * \endcode
 *
 * Pms Sleep Mode Example:
 *
 * \subsection IfxLld_Pms_Std_Pm_ISR Interrupt Service Routine
 *
 * // Macro to define the Interrupt Service Routine
 * \code
 * IFX_INTERRUPT(stmIsr, 0, ISR_PRIORITY_STM);
 * \endcode
 *
 * // STM ISR to switch between run mode and sleep mode every two seconds
 * // Clear the timer event
 * \code
 * IfxStm_Timer_acknowledgeTimerIrq(&stmTimer);
 * \endcode
 *
 * \subsection IfxLld_Pms_Std_Pm_Application API Usage Examples
 *
 * // Initialise PMS sleep configuration
 * \code
 * {
 * 	   // Initialize the Sleep Configuration
 *     IfxPmsPm_SleepConfig sleepConfig;
 *	   IfxPmsPm_initSleepConfig(&sleepConfig);
 *	   sleepConfig.masterCpu = IfxCpu_Index_0;  				// Set CPU0 as master
 *	   sleepConfig.stmEnabled = TRUE;           				// Enable System Timer (STM)
 *
 *	   // STM configuration for Sleep wake-up
 *     IfxStm_Timer_Config timerConfig;                         // Timer configuration structure
 *     IfxStm_Timer_initConfig(&timerConfig, &MODULE_STM0);		// Initialize it with default values
 *     timerConfig.base.frequency = 10.0f;                		// Interrupt every 0.1 seconds
 *     timerConfig.base.isrPriority = ISR_PRIORITY_STM;         // Interrupt priority
 *     timerConfig.base.isrProvider = IfxSrc_Tos_cpu0;          // CPU0 to trigger the interrupt
 *     timerConfig.comparator = IfxStm_Comparator_0;            // Comparator 0 register is used
 *
 *     IfxStm_Timer stmTimer;       				            // STM driver handle
 *     IfxStm_Timer_init(&stmTimer, &timerConfig);              // Use timerConfig to initialize the STM
 *     IfxStm_Timer_run(&stmTimer);                             // Run the STM and set the compare Value
 *
 *     boolean interruptState = IfxCpu_disableInterrupts();
 *     IfxCpu_Irq_installInterruptHandler(&stmIsr, ISR_PRIORITY_STM);
 *     // enable interrupts again
 *     IfxCpu_restoreInterrupts(interruptState);
 *
 *     // Clear safety EndInit protection
 *     // Clear Cpu EndInit protection
 *
 *     STM0_CLC.B.EDIS 	= BLOCK_SLEEP_MODE;         			// Prohibit STM to go into sleep mode
 *     ASCLIN0_CLC.B.EDIS 	= BLOCK_SLEEP_MODE;					// Prohibit ASCLIN0 to go into sleep mode
 *     SCU_PMSWCR1.B.CPUSEL = PMSWCR1_CPUSEL;      			    // Set the CPU0 as CPU master to trigger a power down mode
 *
 *     // Set safety EndInit protection
 *     // Set EndInit protection
 *
 * 	   // Sleep entry mode
 *     IfxPmsPm_WakeupConfig wakeupConfig;					    // Instance to the Wake-up configure structure
 *     wakeupConfig.wakeup 		  = IfxPmsPm_WakeupOn_timer;
 *     wakeupConfig.filter 		  = IfxPmsPm_DigitalFilter_used;
 *     wakeupConfig.trigger 	  = IfxPmsPm_EdgeDetectionControl_always;
 *     wakeupConfig.standbyRam 	  = IfxPmsPm_StandbyRamSupply_cpu0Block0;
 *     wakeupConfig.mode		  = IfxPmsPm_WakeupTimerMode_autoReload;
 *     wakeupConfig.reloadCounter = 0x200E68;
 *
 *     IfxPmsPm_setStandbyMode(&MODULE_PMS, &wakeupConfig, IfxPmsPm_RequestPowerMode_sleep); // Request Sleep Mode
 *
 *     // The system will now enter Sleep Mode and wake up on STM Timer interrupt.
 *
 *     IfxStm_Timer_stop(&stmTimer);
 * }
 * \endcode
 *
 * Pms Standby Mode Example:
 *
 * \code
 * {
 *     // Initialise the Standby Configuration
 *     IfxPmsPm_initStandbyConfig(&standbyConfig);
 *     standbyConfig.trigger 			         = IfxPmsPm_StandbyTriggerMode_software;		// Software Entry
 *     standbyConfig.pinBTriggerEvent 			 = IfxPmsPm_PinEdgeTriggerEvent_fallingEdge;    // As the SWITCH Input Port mode is configured as PullUp.
 *     standbyConfig.wutReloadValue   			 = 0x200E68;								    // Wake-up timer reload value.
 *     standbyConfig.masterCpu 					 = IfxCpu_ResourceCpu_0;
 *     standbyConfig.enableStandbyOnVextRampDown = TRUE;
 *     standbyConfig.enableStandbyOnVddRampDown  = TRUE;
 *     standbyConfig.enableWakeupOnTimer   		 = TRUE;
 *
 *     IfxPmsPm_startStandbySequenceInFlash(&standbyConfig, &IfxScuCcu_defaultClockConfig);
 *
 *     IfxScuRcu_clearColdResetStatus();	 										            // Clear Cold Reset status
 *
 *     // Enter Standby Mode
 *     IfxPmsPm_WakeupConfig wakeupConfig; 												        // Instance to the Wake-up configure structure
 *     wakeupConfig.wakeup 		  = IfxPmsPm_WakeupOn_timer;
 *     wakeupConfig.filter 		  = IfxPmsPm_DigitalFilter_used;
 *     wakeupConfig.trigger 	  = IfxPmsPm_EdgeDetectionControl_always;
 *     wakeupConfig.standbyRam 	  = IfxPmsPm_StandbyRamSupply_cpu0Block0;
 *     wakeupConfig.mode		  = IfxPmsPm_WakeupTimerMode_autoReload;
 *     wakeupConfig.reloadCounter = 0x200E68;
 *
 *     IfxPmsPm_setStandbyMode(&MODULE_PMS, &wakeupConfig, IfxPmsPm_RequestPowerMode_standby);  // Request Standby Mode
 *
 *     // The system will now enter Standby Mode for a few seconds and then bring back to normal run mode with the help of Wake-up timer.
 * }
 * \endcode
 *
 * \defgroup IfxLld_Pms_Std_Pm PM
 * \ingroup IfxLld_Pms_Std
 * \defgroup IfxLld_Pms_Std_Pm_Enumerations Enumerations
 * \ingroup IfxLld_Pms_Std_Pm
 * \defgroup IfxLld_Pms_Std_Pm_DataStructures Data Structures
 * \ingroup IfxLld_Pms_Std_Pm
 * \defgroup IfxLld_Pms_Std_Pm_SystemModes System Modes
 * \ingroup IfxLld_Pms_Std_Pm
 * \defgroup IfxLld_Pms_Std_Pm_CpuModes Cpu Modes
 * \ingroup IfxLld_Pms_Std_Pm
 * \defgroup IfxLld_Pms_Std_Pm_WakeupModes WakeupModes
 * \ingroup IfxLld_Pms_Std_Pm
 */

#ifndef IFXPMSPM_H
#define IFXPMSPM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxPms_cfg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Pms/Std/IfxPmsEvr.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
#include "Scu/Std/IfxScuCcu.h"
#include "IfxCpu_bf.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Cpu/Std/IfxCpu.h"
#include "IfxDmu_reg.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pms_Std_Pm_Enumerations
 * \{ */
/** \brief Exposes the options for minimum duration between standby entry and Wakeup.If any wakeup request comes up before this time is elapsed after standby entry, then it's ignored.Configured in PMS_PMSWCR.B.BLNKFIL
 */
typedef enum
{
    IfxPmsPm_BlankingFilterDelay_0ms     = 0,   /**< \brief No blanking filter delay */
    IfxPmsPm_BlankingFilterDelay_2_5ms   = 1,   /**< \brief Blanking delay on 2.5ms */
    IfxPmsPm_BlankingFilterDelay_5ms     = 2,   /**< \brief Blanking delay on 5ms */
    IfxPmsPm_BlankingFilterDelay_10ms    = 3,   /**< \brief Blanking delay on 10ms */
    IfxPmsPm_BlankingFilterDelay_20ms    = 4,   /**< \brief Blanking delay on 20ms */
    IfxPmsPm_BlankingFilterDelay_40ms    = 5,   /**< \brief Blanking delay on 40ms */
    IfxPmsPm_BlankingFilterDelay_80ms    = 6,   /**< \brief Blanking delay on 80ms */
    IfxPmsPm_BlankingFilterDelay_160ms   = 7,   /**< \brief Blanking delay on 160ms */
    IfxPmsPm_BlankingFilterDelay_320ms   = 8,   /**< \brief Blanking delay on 320ms */
    IfxPmsPm_BlankingFilterDelay_640ms   = 9,   /**< \brief Blanking delay on 640ms */
    IfxPmsPm_BlankingFilterDelay_1280ms  = 0xA, /**< \brief Blanking delay on 1280ms */
    IfxPmsPm_BlankingFilterDelay_2560ms  = 0xB, /**< \brief Blanking delay on 2560ms */
    IfxPmsPm_BlankingFilterDelay_5120ms  = 0xC, /**< \brief Blanking delay on 5120ms */
    IfxPmsPm_BlankingFilterDelay_10240ms = 0xD  /**< \brief Blanking delay on 1024ms */
} IfxPmsPm_BlankingFilterDelay;

/** \brief The Digital filter enable/disabled
 * As defined in Ifx_PMS.PMSW.CR0.B.ESRxDFEN and Ifx_PMS.PMSW.CR0.B.PINxDFEN
 */
typedef enum
{
    IfxPmsPm_DigitalFilter_bypassed = 0,  /**< \brief The Filter is Bypassed */
    IfxPmsPm_DigitalFilter_used     = 1   /**< \brief The Filter is Used */
} IfxPmsPm_DigitalFilter;

/** \brief Edge detection control mode for ESR and PINA/PINB
 * As defined in Ifx_PMS.PMSW.CR0.B.ESRxEDCON  and Ifx_PMS.PMSW.CR0.B.PINxEDCON
 */
typedef enum
{
    IfxPmsPm_EdgeDetectionControl_never         = 0,  /**< \brief No Trigger is Generated */
    IfxPmsPm_EdgeDetectionControl_onRisingEdge  = 1,  /**< \brief Trigger is generated upon a Rising edge */
    IfxPmsPm_EdgeDetectionControl_onFallingEdge = 2,  /**< \brief Triggerr is generated upon a falling edge */
    IfxPmsPm_EdgeDetectionControl_always        = 3   /**< \brief A trigger is generated upon a either edges */
} IfxPmsPm_EdgeDetectionControl;

/** \brief Request to set ESR0 pin pads to either input with weak pullup or tristate.Configured in PMS_PMSWCR5.B.ESR0TRIST
 */
typedef enum
{
    IfxPmsPm_Esr0PinStateRequest_resetOutput = 0,
    IfxPmsPm_Esr0PinStateRequest_tristate    = 1   /**< \brief Set the ESR0 pin pad to tristate */
} IfxPmsPm_Esr0PinStateRequest;

/** \brief List of different statuses related to Load Jump
 * This is reflected in SCU_PMTRCSR2.B.LJTRUN
 */
typedef enum
{
    IfxPmsPm_LoadJumpStatus_inactive                 = 0,  /**< \brief Load Jump and Load Jump Timer inactive */
    IfxPmsPm_LoadJumpStatus_swTriggeredRequestActive = 1,  /**< \brief A SW triggered Load Jump active and Load Jump Timer active */
    IfxPmsPm_LoadJumpStatus_hwTriggeredRequestActive = 2   /**< \brief A HW triggered Load Jump active and Load Jump Timer active */
} IfxPmsPm_LoadJumpStatus;

/** \brief Request to set pads to either input with weak pullup or tristate.Configured in PMS_PMSWCR5.B.TRISTREQ
 */
typedef enum
{
    IfxPmsPm_PadStateRequest_inputWithWeakPullUp = 0,  /**< \brief Set pads to input with weak pullup */
    IfxPmsPm_PadStateRequest_tristate            = 1   /**< \brief Set pads to tristate */
} IfxPmsPm_PadStateRequest;

/** \brief Defines which signal edge(s) will generate a pin trigger event.
 * Definition in Ifx_PMS_PMSWCR0.B.ESR0EDCON, Ifx_PMS_PMSWCR0.B.ESR1EDCON, Ifx_PMS_PMSWCR0.B.PINAEDCON and Ifx_PMS_PMSWCR0.B.PINBEDCON
 */
typedef enum
{
    IfxPmsPm_PinEdgeTriggerEvent_none                     = 0, /**< \brief None of the edges will trigger anything */
    IfxPmsPm_PinEdgeTriggerEvent_risingEdge               = 1, /**< \brief Trigger is generated upon a rising edge */
    IfxPmsPm_PinEdgeTriggerEvent_fallingEdge              = 2, /**< \brief Trigger is generated upon a falling edge */
    IfxPmsPm_PinEdgeTriggerEvent_bothRisingAndFallingEdge = 3  /**< \brief A trigger is generated upon a rising OR falling edge */
} IfxPmsPm_PinEdgeTriggerEvent;

/** \brief Different options for when event triggering is desired(See EVRMONCTRL).
 */
typedef enum
{
    IfxPmsPm_RampingMode_none = 0,  /**< \brief Monitoring inactive. This results in a complete reset
                                     * of the comparator unit, status bits and filter values and alarm is
                                     * deasserted. */
    IfxPmsPm_RampingMode_up   = 1,  /**< \brief Event is triggered when the threshold is crossed in
                                     * a lower to higher voltage transition. Greater than or equal compare
                                     * is used. */
    IfxPmsPm_RampingMode_down = 2,  /**< \brief Event is triggered when the threshold is crossed in
                                     * a higher to lower voltage transition. Less than or equal compare is
                                     * used. */
    IfxPmsPm_RampingMode_both = 3   /**< \brief Event is triggered when the threshold is crossed in
                                     * either direction. Greater than or equal compare is used. */
} IfxPmsPm_RampingMode;

/** \brief System power mode
 * As defined in Ifx_SCU.PMCSR[x].B.REQSLP
 */
typedef enum
{
    IfxPmsPm_RequestPowerMode_run     = 0, /**< \brief Request CPU Run Mode */
    IfxPmsPm_RequestPowerMode_idle    = 1, /**< \brief Request CPU Idle Mode */
    IfxPmsPm_RequestPowerMode_sleep   = 2, /**< \brief Request CPU Sleep Mode */
    IfxPmsPm_RequestPowerMode_standby = 3  /**< \brief Request CPU Standby Mode */
} IfxPmsPm_RequestPowerMode;

/** \brief Defines Clocking options for SCR in PMS_PMSWCR4.B.SCRCLKSEL
 */
typedef enum
{
    IfxPmsPm_ScrClocking_100mhzOptional    = 0, /**< \brief 100MHz oscillator can be enabled or disabled based on request
                                                 * from Standby Controller. By default 100 MHz Oscillator is
                                                 * requested by SCR in Standby Mode. */
    IfxPmsPm_ScrClocking_bothClocksActiive = 1  /**< \brief 100MHz oscillator is always active irrespective of SCR requests.
                                                 * Thus both 70 KHz Oscillator and 100 MHz oscillator are active in
                                                 * Standby Mode. */
} IfxPmsPm_ScrClocking;

/** \brief The RAM being used in Standby mode
 * As defined in Ifx_PMS.PMSW.CR0.B.STBYRAMSEL
 */
typedef enum
{
    IfxPmsPm_StandbyRamSupply_never       = 0,  /**< \brief Standby RAM is not supplied */
    IfxPmsPm_StandbyRamSupply_cpu0Block0  = 1,  /**< \brief Standby RAM (CPU0 dLMU RAM Block 0) is supplied */
    IfxPmsPm_StandbyRamSupply_cpu0Block01 = 2,  /**< \brief Standby RAM (CPU0 dLMU RAM Block0 + Block1) is supplied */
    IfxPmsPm_StandbyRamSupply_cpu1Block01 = 4,  /**< \brief Standby RAM (CPU1 dLMU RAM Block0 + Block1) is supplied */
    IfxPmsPm_StandbyRamSupply_cpu0Cpu1    = 7   /**< \brief Standby RAM (CPU0 dLMU RAM Block0 + Block1) &  (CPU1 dLMU RAM Block0 + Block1)  is supplied */
} IfxPmsPm_StandbyRamSupply;

/** \brief Defines events to trigger entry to Standby mode.
 */
typedef enum
{
    IfxPmsPm_StandbyTriggerMode_software              = 0,  /**< \brief Standby request using MODULE_SCU.PMCSRx.B.REQSLP */
    IfxPmsPm_StandbyTriggerMode_hardware_undervoltage = 1,  /**< \brief Standby trigger arising from VEXT/VDD undervoltage */
    IfxPmsPm_StandbyTriggerMode_hardware_nmi          = 4   /**< \brief Standby request arising from any NMI/ESR1 pin assertion */
} IfxPmsPm_StandbyTriggerMode;

/** \brief types of event
 */
typedef enum
{
    IfxPmsPm_ThresholdEvent_overvoltage  = 0, /**< \brief Voltage is greater than the higher threshold */
    IfxPmsPm_ThresholdEvent_undervoltage = 4  /**< \brief Voltage is lesser than the lower threshold */
} IfxPmsPm_ThresholdEvent;

/** \brief Direction of Voltage Droop(positive and negative)
 * To be specified in SCU_PMTRCSR3.B.VDROOPREQ
 */
typedef enum
{
    IfxPmsPm_VoltageDroopRequest_positive = 1,  /**< \brief A Positive Voltage Droop Request made and taken. Voltage Droop
                                                 * Timer activated. */
    IfxPmsPm_VoltageDroopRequest_negative = 2   /**< \brief A Negative Voltage Droop Request made and taken. Voltage Droop
                                                 * Timer activated. */
} IfxPmsPm_VoltageDroopRequest;

/** \brief List of different statuses related to Load Jump
 * This is reflected in SCU_PMTRCSR3.B.VDTRUN
 */
typedef enum
{
    IfxPmsPm_VoltageDroopStatus_inactive                 = 0,  /**< \brief Voltage Droop and Voltage Droop Timer inactive */
    IfxPmsPm_VoltageDroopStatus_swTriggeredRequestActive = 1,  /**< \brief A SW triggered Voltage Droop active and Voltage Droop Timer
                                                                * active */
    IfxPmsPm_VoltageDroopStatus_hwTriggeredRequestActive = 2   /**< \brief A HW triggered Voltage Droop active and Voltage Droop Timer
                                                                * active */
} IfxPmsPm_VoltageDroopStatus;

/** \brief Lists out volatge droop steps
 * Definition in SCU_PMTRCSR0.B.SDSTEP
 */
typedef enum
{
    IfxPmsPm_VoltageDroopStep_0mV  = 0,    /**< \brief Voltage  Droop request of 0 mV */
    IfxPmsPm_VoltageDroopStep_5mV  = 1U,   /**< \brief Voltage  Droop request of 5 mV */
    IfxPmsPm_VoltageDroopStep_10mV = 2U,   /**< \brief Voltage  Droop request of 10 mV */
    IfxPmsPm_VoltageDroopStep_15mV = 3U,   /**< \brief Voltage  Droop request of 15 mV */
    IfxPmsPm_VoltageDroopStep_20mV = 4U,   /**< \brief Voltage  Droop request of 20 mV */
    IfxPmsPm_VoltageDroopStep_25mV = 5U,   /**< \brief Voltage  Droop request of 25 mV */
    IfxPmsPm_VoltageDroopStep_30mV = 6U,   /**< \brief Voltage  Droop request of 30 mV */
    IfxPmsPm_VoltageDroopStep_35mV = 7U,   /**< \brief Voltage  Droop request of 35 mV */
    IfxPmsPm_VoltageDroopStep_40mV = 8U,   /**< \brief Voltage  Droop request of 40 mV */
    IfxPmsPm_VoltageDroopStep_45mV = 9U,   /**< \brief Voltage  Droop request of 45 mV */
    IfxPmsPm_VoltageDroopStep_50mV = 10U,  /**< \brief Voltage  Droop request of 50 mV */
    IfxPmsPm_VoltageDroopStep_55mV = 11U,  /**< \brief Voltage  Droop request of 55 mV */
    IfxPmsPm_VoltageDroopStep_60mV = 12U,  /**< \brief Voltage  Droop request of 60 mV */
    IfxPmsPm_VoltageDroopStep_65mV = 13U,  /**< \brief Voltage  Droop request of 65 mV */
    IfxPmsPm_VoltageDroopStep_70mV = 14U,  /**< \brief Voltage  Droop request of 70 mV */
    IfxPmsPm_VoltageDroopStep_75mV = 15U   /**< \brief Voltage  Droop request of 75 mV */
} IfxPmsPm_VoltageDroopStep;

/** \brief Different voltage sources externally supplied to/inside AURIX2G
 */
typedef enum
{
    IfxPmsPm_VoltageSource_vdd    = 0,  /**< \brief 1.25V VDD voltage source(either from EVRC/supplied externally) */
    IfxPmsPm_VoltageSource_vddpd  = 2,  /**< \brief 1.25V VDDPD Pre-Regulator Voltage */
    IfxPmsPm_VoltageSource_vddp3  = 8,  /**< \brief 3.3V VDDP3(either generated by EVR33 or externally provided) */
    IfxPmsPm_VoltageSource_vddm   = 10, /**< \brief VDDM - Analog supply for ADCs */
    IfxPmsPm_VoltageSource_vext   = 16, /**< \brief VEXT(3.3V or 5V) external supply */
    IfxPmsPm_VoltageSource_vevrsb = 18  /**< \brief VEVRSB(3.3V or 5V) - Standby Domain Supply */
} IfxPmsPm_VoltageSource;

/** \brief Wake up configuration defined in Ifx_PMS.PMSW.CR0.B.ESRxWKEN,Ifx_PMS.PMSW.CR0.B.PINxWKEN
 * and Ifx_PMS.PMSW.CR0.B.PORSTWKEN
 */
typedef enum
{
    IfxPmsPm_WakeupOn_esr0  = 0,  /**< \brief ESR0 Wake-up enable from Standby */
    IfxPmsPm_WakeupOn_esr1  = 1,  /**< \brief ESR1 Wake-up enable from Standby */
    IfxPmsPm_WakeupOn_pinA  = 2,  /**< \brief PINA Wake-up enable from Standby */
    IfxPmsPm_WakeupOn_pinB  = 3,  /**< \brief PINB Wake-up enable from Standby */
    IfxPmsPm_WakeupOn_porst = 4,  /**< \brief PORST Wake-up enable from Standby */
    IfxPmsPm_WakeupOn_timer = 5,  /**< \brief WUT Wake-up enable from Standby */
    IfxPmsPm_WakeupOn_power = 6,  /**< \brief Power Wake-up enable  Standby */
    IfxPmsPm_WakeupOn_scr   = 7   /**< \brief SCR Wake-up enable from Standby */
} IfxPmsPm_WakeupOn;

/** \brief Select wakeup timer operation mode
 * As defined in Ifx_PMS.PMSW.CR3.B.WUTMODE
 */
typedef enum
{
    IfxPmsPm_WakeupTimerMode_autoReload = 0,  /**< \brief WUT auto reload mode selected */
    IfxPmsPm_WakeupTimerMode_autoStop   = 1   /**< \brief WUT auto stop mode selected */
} IfxPmsPm_WakeupTimerMode;

/** \brief Clock for WUT
 */
typedef enum
{
    IfxPmsPm_WutClock_70kHz = 0,  /**< \brief WUT has a 70 kHz clock input */
    IfxPmsPm_WutClock_68Hz  = 1   /**< \brief Clock to WUT passes through a divider of 10 */
} IfxPmsPm_WutClock;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pms_Std_Pm_DataStructures
 * \{ */
/** \brief Options for Load Jump
 */
typedef struct
{
    boolean enableLoadJumpTimer;                        /**< \brief Enable or disable Load Jump Timer, Range: TRUE  Load Jump Timer active, FALSE Load Jump Timer inactive. */
    boolean enableLoadJumpTimerOverflowFlag;            /**< \brief Enable or disable update of Load Jump Timer Overflow Flag.
    													 * Range: TRUE LJTOV bit is updated on a Load Jump Timer overflow, FALSE LJTOV bit is not updated on a Load Jump Timer overflow. */
    boolean enableLoadJumpTimerOverflowInterrupt;       /**< \brief Enable or disable Load Jump Timer Overflow Interrupt.
    													 * Range: TRUE LJTOV interrupt is activated on a Load Jump Timer overflow, FALSE LJTOV interrupt is inactive. */
} IfxPmsPm_LoadJumpConfig;

/** \brief Configurable options for sleep mode
 */
typedef struct
{
    boolean           mcanEnabled;              /**< \brief Whether MCAN will be enabled or disabled during sleep mode.
     	 	 	 	 	 	 	 	 	 	 	 * Range: TRUE Mcan will be enabled during sleep mode, FALSE Mcan will be disabled during sleep mode. */
    IfxScuCcu_Fsource mcanClockSource;          /**< \brief Clock Source for MCAN
                                                 * IfxScuCcu_Fsource_1 is f_source1 from K2 divider of Peripheral PLL
                                                 * IfxScuCcu_Fsource_2 is Oscillator clock bypassing the Peripheral PLL */
    boolean           asclinEnabled;            /**< \brief Whether ASCLIN will be enabled or disabled during sleep mode.
     	 	 	 	 	 	 	 	 	 	 	 * Range: TRUE Asclin will be enabled during sleep mode, FALSE Asclin will be disabled during sleep mode. */
    IfxScuCcu_Fsource asclinClockSource;        /**< \brief Clock Source for ASCLIN.
                                                 * IfxScuCcu_Fsource_1 is f_source1 from K2 divider of Peripheral PLL
                                                 * IfxScuCcu_Fsource_2 is Oscillator clock bypassing the Peripheral PLL */
    boolean           gpt12Enabled;             /**< \brief Whether GPT12 will be enabled or disabled during sleep mode.
     	 	 	 	 	 	 	 	 	 	 	 * Range: TRUE Gpt12 will be enabled during sleep mode, FALSE Gpt12 will be disabled during sleep mode. */
    boolean           ccu6Enabled;              /**< \brief Whether CCU6 will be enabled or disabled during sleep mode.
     	 	 	 	 	 	 	 	 	 	 	 * Range: TRUE Ccu6 will be enabled during sleep mode, FALSE Ccu6 will be disabled during sleep mode. */
    boolean           qspiEnabled;              /**< \brief Whether QSPI will be enabled or disabled during sleep mode.
     	 	 	 	 	 	 	 	 	 	 	 * Range: TRUE Qspi will be enabled during sleep mode, FALSE Qspi will be disabled during sleep mode. */
    IfxScuCcu_Fsource qspiClockSource;          /**< \brief Clock Source for MCAN.
                                                 * IfxScuCcu_Fsource_1 is f_source1 from K2 divider of Peripheral PLL
                                                 * IfxScuCcu_Fsource_2 is f_source2 from K3 divider of Peripheral PLL */
    boolean            gethEnabled;             /**< \brief Whether GETH will be enabled or disabled during sleep mode.
     	 	 	 	 	 	 	 	 	 	 	 * Range: TRUE Geth will be enabled during sleep mode, FALSE Geth will be disabled during sleep mode. */
    boolean            i2cEnabled;              /**< \brief Whether I2C will be enabled or disabled during sleep mode.
     	 	 	 	 	 	 	 	 	 	 	 * Range: TRUE I2c will be enabled during sleep mode, FALSE I2c will be disabled during sleep mode. */
    boolean            gtmEnabled;              /**< \brief Whether GTM will be enabled or disabled during sleep mode.
     	 	 	 	 	 	 	 	 	 	 	 * Range: TRUE Gtm will be enabled during sleep mode, FALSE Gtm will be disabled during sleep mode. */
    boolean            stmEnabled;              /**< \brief Whether STM will be enabled or disabled during sleep mode.
     	 	 	 	 	 	 	 	 	 	 	 * Range: TRUE Stm will be enabled during sleep mode, FALSE Stm will be disabled during sleep mode. */
    IfxCpu_ResourceCpu masterCpu;               /**< \brief Core index of the master CPU */
} IfxPmsPm_SleepConfig;

/** \brief Configurable Standby options
 */
typedef struct
{
    IfxPmsPm_StandbyTriggerMode  trigger;                              /**< \brief Events which'll trigger Standby mode. */
    IfxPmsPm_StandbyRamSupply    standbyRamBlock;                      /**< \brief Options for which part of the DLMU can be provided supply during standby. */
    boolean                      enableScr;                            /**< \brief Whether to enable SCR or not. */
    IfxPmsPm_ScrClocking         scrClockSupply;                       /**< \brief Options for SCR clock supply. */
    IfxPmsPm_BlankingFilterDelay minDelayBeforeWakeUp;                 /**< \brief Selecting the duration, starting from Standby entry, after which wake-up triggers are effective. */
    IfxPmsPm_PadStateRequest     padStateRequest;                      /**< \brief Request to remain in input with weak pull-up or get into tristate. */
    IfxPmsPm_Esr0PinStateRequest esr0PinStateRequest;                  /**< \brief Request to remain in input with weak pull-up or get into tristate. */
    boolean                      enableStandbyOnVextRampDown;          /**< \brief Enable Standby On VEXT Ramp Down. Range: TRUE Standby Entry triggered on a VEXT Supply under voltage event (SWDUV). Blanking filter active on Standby mode entry, FALSE Standby Entry on VEXT supply ramp-down is disabled. */
    boolean                      enableStandbyOnVddRampDown;           /**< \brief Enable Standby On VDD Ramp Down. Range: TRUE Standby Entry triggered on a VDD Supply under voltage event (VDDUV). Blanking filter active on Standby mode entry, FALSE Standby Entry on VDD supply ramp-down is disabled. */
    float32                      vextUnderVoltageThresholdLevel;       /**< \brief Under voltage threshold for VEXT. */
    float32                      vddUnderVoltageThresholdLevel;        /**< \brief Under voltage threshold for VDD. */
    boolean                      enableWakeupOnEsr0;                   /**< \brief Enable wake-up on ESR0. Range: TRUE System wake-up is enabled via ESR0 pin, FALSE System wake-up via ESR0 pin is disabled. */
    boolean                      enableWakeupOnEsr1;                   /**< \brief Enable wake-up on ESR1. Range: TRUE System wake-up is enabled via ESR1 pin, FALSE System wake-up via ESR1 pin is disabled.*/
    boolean                      enableWakeupOnPinA;                   /**< \brief Enable wake-up on PINA. Range: TRUE System wake-up is enabled via Pin A, FALSE System wake-up via Pin A is disabled. */
    boolean                      enableWakeupOnPinB;                   /**< \brief Enable wake-up on PINB. Range: TRUE System wake-up is enabled via Pin B, FALSE System wake-up via Pin B is disabled. */
    boolean                      enableWakeupOnTimer;                  /**< \brief Enable wake-up on Wake Up Timer(WUT). Range: TRUE System wake-up is enabled via Wake-up Timer, FALSE System wake-up via Wake-up Timer is disabled. */
    boolean                      enableWakeupOnPorst;                  /**< \brief Enable wake-up on PORST pin assertion. Range: TRUE System wake-up via PORST pin is enabled,  FALSE System wake-up via PORST pin is disabled. */
    boolean                      enableWakeupOnScr;                    /**< \brief Enable wake-up on request from SCR. Range: TRUE System wake-up is enabled via 8 bit Standby Controller, FALSE System wake-up via 8 bit Standby Controller is disabled. */
    uint8                        enableWakeupOnPower;                  /**< \brief Enable wake-up on VEXT ramp up. Range: TRUE Wake-up from standby on VEXT supply ramp-up is enabled after blanking filter time expiry, FALSE Wake-up on VEXT supply ramp-down is disabled. Blanking filter configuration has no effect. */
    boolean                      useWutStandbyAutoStopMode;            /**< \brief Use the Auto Stop mode in WUT. Range: TRUE Use the auto stop mode in WUT, FALSE Auto stop mode is not used in WUT. */
    uint32                       wutReloadValue;                       /**< \brief The value from which the WUT will start downward count upon entering Standby. Range: 0 to 0xFFFFFF */
    IfxPmsPm_WutClock            wutClock;                             /**< \brief Clock select for WUT. */
    IfxPmsPm_DigitalFilter       esr0DigitalFilterUsage;               /**< \brief Whether to use digital filer with interpreting the pulse on ESR0 pin. */
    IfxPmsPm_DigitalFilter       pinADigitalFilterUsage;               /**< \brief Whether to use digital filer with interpreting the pulse on PINA pin. */
    IfxPmsPm_DigitalFilter       esr1DigitalFilterUsage;               /**< \brief Whether to use digital filer with interpreting the pulse on ESR1 pin. */
    IfxPmsPm_DigitalFilter       pinBDigitalFilterUsage;               /**< \brief Whether to use digital filer with interpreting the pulse on PINB pin. */
    IfxPmsPm_PinEdgeTriggerEvent esr0TriggerEvent;                     /**< \brief Trigger will be generated on which pulse edge of a pulse on ESR0 pin. */
    IfxPmsPm_PinEdgeTriggerEvent esr1TriggerEvent;                     /**< \brief Trigger will be generated on which pulse edge of a pulse on ESR1 pin. */
    IfxPmsPm_PinEdgeTriggerEvent pinATriggerEvent;                     /**< \brief Trigger will be generated on which pulse edge of a pulse on PINA pin. */
    IfxPmsPm_PinEdgeTriggerEvent pinBTriggerEvent;                     /**< \brief Trigger will be generated on which pulse edge of a pulse on PINB pin. */
    IfxCpu_ResourceCpu           masterCpu;                            /**< \brief CPU which can call power down modes.In IfxPmsPm_startStandbySequenceInFlash(),this value is being filled to reflect the core in which standby sequence is running as we're explicitly making it as the master CPU. */
} IfxPmsPm_StandbyConfig;

/** \brief Volatge Droop Configuration
 */
typedef struct
{
    boolean                      enableVoltageDroopTimer;                        /**< \brief Enable or disable usage of Voltage Droop Timer. Range: TRUE Voltage Droop Timer active, FALSE Voltage Droop Timer inactive. */
    boolean                      enableVoltageDroopTimerOverflowFlag;            /**< \brief Enable or disable usage of Voltage Droop Timer Overflow Flag. Range: TRUE VDTOV bit is updated on a Voltage Droop Timer overflow, FALSE VDTOV bit is not updated on a Voltage Droop Timer overflow. */
    boolean                      enableVoltageDroopTimerOverflowInterrupt;       /**< \brief Enable or disable usage of Voltage Droop Interrupt. Range: TRUE VDTOV interrupt is activated on a Voltage Droop Timer overflow, FALSE VDTOV interrupt is inactive. */
    IfxPmsPm_VoltageDroopRequest droopRequestType;                               /**< \brief Type of Voltage Droop Request */
    IfxPmsPm_VoltageDroopStep    droopStep;                                      /**< \brief Value by which voltage change must happen */
} IfxPmsPm_VoltageDroopConfig;

/** \brief Configure Wakeup in standby mode
 */
typedef struct
{
    IfxPmsPm_WakeupOn             wakeup;              /**< \brief wake-up configuration */
    IfxPmsPm_DigitalFilter        filter;              /**< \brief bypass/use digital filter */
    IfxPmsPm_EdgeDetectionControl trigger;             /**< \brief Enable Wake-up on rising or falling edge */
    IfxPmsPm_StandbyRamSupply     standbyRam;          /**< \brief RAM being supply during standby mode */
    IfxPmsPm_WakeupTimerMode      mode;                /**< \brief wake-up timer mode */
    uint32                        reloadCounter;       /**< \brief reload count from where value starts counting down used in case of WUT configuration. Range: 0 to 0xFFFFFFFF */
} IfxPmsPm_WakeupConfig;

/** \} */

/** \addtogroup IfxLld_Pms_Std_Pm_SystemModes
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the system into a specified sleep mode.
 *
 * \param[in] powerMode The requested power mode to set the system into.
 * 						Range: \ref IfxPmsPm_RequestPowerMode
 *
 * \retval None
 *
 * \code
 * IfxPmsPm_setSleepMode(IfxPmsPm_RequestPowerMode_idle);
 * \endcode
 */
IFX_INLINE void IfxPmsPm_setSleepMode(IfxPmsPm_RequestPowerMode powerMode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Configures the system to enter standby mode.
 * 
 * \note In this API Alarm has been disabled. Enable of SMU alarm has to be taken care separately at application level
 * 
 * \param[inout] pms       Pointer to the base address of PMS registers.
 * \param[in]    config    Pointer to the wakeup configuration instance.
 * \param[in]    powerMode The requested power mode to set the system into.
 * 						   Range: \ref IfxPmsPm_RequestPowerMode
 * 
 * \retval None
 * 
 * \code
 * IfxPmsPm_WakeupConfig config;
 * config.wakeup =IfxPmsPm_WakeupOn_esr1;                           //Wakeup using ESR1
 * config.filter      = IfxPmsPm_DigitalFilter_used;                //Digital Filter is used
 * config.trigger     = IfxPmsPm_EdgeDetectionControl_onRisingEdge; //Trigger is generated upon rising edge
 * config.standbyRam  = IfxPmsPm_StandbyRamSupply_cpu0Block0;       //Standby RAM (CPU0 dLMU RAM Block 0) is supplied
 * IfxPmsPm_setStandbyMode(&MODULE_PMS,&config, IfxPmsPm_RequestPowerMode_standby);
 * \endcode
 */
IFX_EXTERN void IfxPmsPm_setStandbyMode(Ifx_PMS *pms, IfxPmsPm_WakeupConfig *config, IfxPmsPm_RequestPowerMode powerMode);

/**
 * \brief This function initializes the standby configuration structure with default values.
 *
 * \note 1. Default values of vextUnderVoltageThresholdLevel and vddUnderVoltageThresholdLevel in the StandbyConfig structure are set to 0.
 *          Set it to appropriate levels(depending on application) before calling IfxPmsPm_startStandbySequenceInFlash().
 *
 * \param[inout] standbyConfig Pointer to the standby configuration structure to be initialized.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_initStandbyConfig(IfxPmsPm_StandbyConfig *standbyConfig);

/**
 * \brief Starts the standby sequence in flash memory with the specified configurations.
 *
 * \param[inout] standbyConfig Pointer to the standby configuration structure.
 * \param[in]    clockConfig   Pointer to the clock configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_startStandbySequenceInFlash(IfxPmsPm_StandbyConfig *standbyConfig, const IfxScuCcu_Config *clockConfig);

/**
 * \brief Continues the standby sequence in RAM, configuring the system according to the provided standby and clock settings.
 *
 * \param[in] standbyConfig Pointer to the standby configuration structure.
 * \param[in] clockConfig   Pointer to the clock configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_continueStandbySequenceInRAM(IfxPmsPm_StandbyConfig *standbyConfig, const IfxScuCcu_Config *clockConfig);

/**
 * \brief Initializes the sleep configuration structure with default values.
 *
 * \param[inout] sleepConfig Pointer to the sleep configuration structure that will be initialized.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_initSleepConfig(IfxPmsPm_SleepConfig *sleepConfig);

/**
 * \brief Starts a sleep sequence in Flash memory, configuring the system to enter a low-power state.
 *
 * \param[inout] sleepConfig Pointer to the sleep configuration structure.
 * \param[in]    clockConfig Pointer to the clock configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_startSleepSequenceinFlash(IfxPmsPm_SleepConfig *sleepConfig, IfxScuCcu_Config *clockConfig);

/**
 * \brief Continues the sleep sequence in RAM for the master CPU, configuring peripherals according to the provided sleep configuration.
 *
 * \param[in] sleepConfig Pointer to the sleep configuration structure that specifies the enabled peripherals and their clock sources during sleep mode.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_continueSleepSequenceInRAM(IfxPmsPm_SleepConfig *sleepConfig);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Pm_CpuModes
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets a specified CPU as the Master CPU, enabling it to control and trigger power down modes.
 *
 * \param[in] cpuIndex Index identifying the CPU core to be set as Master CPU.
 *                     Range: \ref IfxCpu_ResourceCpu
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_setMasterCpu(IfxCpu_ResourceCpu cpuIndex);

/**
 * \brief Retrieves the resource identifier of the master CPU.
 *
 * \retval IfxCpu_ResourceCpu The resource identifier of the master CPU.
 * 							  Range: \ref IfxCpu_ResourceCpu
 */
IFX_INLINE IfxCpu_ResourceCpu IfxPmsPm_getMasterCpu(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the core mode of the specified CPU.
 *
 * \param[in] cpuIndex The index of the CPU to be configured.
 * \param[in] mode     Select mode to be set to put CPU into other state.
 * 					   Range: \ref IfxCpu_CoreMode
 * 
 * \retval Boolean TRUE  The CPU core mode was successfully set.
 * 				   FALSE The CPU core mode setting failed.
 *
 * \code
 * IfxPmsPm_setCoreMode(MODULE_CPU0, IfxCpu_CoreMode_idle);
 * \endcode
 */
IFX_EXTERN boolean IfxPmsPm_setCoreMode(IfxCpu_ResourceCpu cpuIndex, IfxCpu_CoreMode mode);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Pm_WakeupModes
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables the wakeup functionality from standby mode using the specified configuration.
 *
 * \param[inout] pms    Pointer to the base address of PMS registers.
 * \param[in]    wakeup Pointer to the wakeup configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_enableWakeup(Ifx_PMS *pms, IfxPmsPm_WakeupConfig *wakeup);

/**
 * \brief Configures the wake-up settings for the power management standby mode based on the provided configuration.
 *
 * \param[in] standbyConfig Pointer to the standby configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_configureWakeup(IfxPmsPm_StandbyConfig *standbyConfig);

/**
 * \brief Initiates the wakeup process for power management using the provided clock configuration.
 *
 * \param[in] clockConfig Pointer to the configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_initiateWakeup(IfxScuCcu_Config *clockConfig);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables the usage of the load jump timer for power management.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_enableLoadJumpTimer(void);

/**
 * \brief Disables the usage of the load jump timer in the power management system.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_disableLoadJumpTimer(void);

/**
 * \brief Enables the update of SCU_PMTRCSR2.B.LJTOV status bit on timer overflow or timeout.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_enableLoadJumpTimerOverflowFlag(void);

/**
 * \brief Disables the update of SCU_PMTRCSR2.B.LJTOV status bit on timer overflow or timeout.
 * 
 * \retval None
 */
IFX_INLINE void IfxPmsPm_disableLoadJumpTimerOverflowFlag(void);

/**
 * \brief Enables the activation of interrupt on timer overflow or timeout events.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_enableLoadJumpTimerOverflowInterrupt(void);

/**
 * \brief Disables the activation of interrupt on timer overflow or timeout events.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_disableLoadJumpTimerOverflowInterrupt(void);

/**
 * \brief Starts Load jump timer. The SCU_PMTRCSR0.B.LJTSTRT bitfield remains set on a write and is cleared when SCU_PMTRCSR2.B.LJTOV bit is set
 * 		  if SCU_PMTRCSR0.B.LJTOVEN bit is enabled(Update of Load Jump Timer Overflow Flag SCU_PMTRCSR2.B.LJTOV is enabled ).
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_startLoadJumpTimer(void);

/**
 * \brief This stops the Load jump timer. The Load Jump Timer stops counter at the current value and timer
 * 		  re-starts from that value when LJTSTP is cleared and LJTSTRT is set.
 * 
 * \retval None
 */
IFX_INLINE void IfxPmsPm_stopLoadJumpTimer(void);

/**
 * \brief Clears the Load Jump timer count
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_clearLoadJumpTimer(void);

/**
 * \brief Clears the Load Jump Timer Overflow Flag (SCU_PMTRCSR2.B.LJTOV) and sets PMTRCSR3.B.VDROOPREQ and PMTRCSR2.B.LDJMPREQ
 * 		  to 0 if the Load Jump Timer Overflow Flag bit is enabled.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_clearLoadJumpTimerOverflowFlag(void);

/**
 * \brief Checks if the Load Jump Timer has overflowed
 * 
 * \retval boolean TRUE  If the Load Jump Timer compare overflow has happened.
 * 		   		   FALSE If the Load Jump Timer compare overflow has not happened.
 */
IFX_INLINE boolean IfxPmsPm_hasLoadJumpTimerOverflowOccured(void);

/**
 * \brief Sets the compare value for the Load Jump Timer in SCU_PMTRCSR1.B.LJTCV
 * 
 * When the Timer count reaches this value, an overflow condition occurs, triggering
 * the respective flag and interrupt (if enabled).
 *
 * \param[in] compareValue The compare value for the Load Jump Timer. 
 *                         Range: 0 to FFFF
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_setLoadJumpTimerCompareValue(uint16 compareValue);

/**
 * \brief Retrieves the current Load Jump Timer compare value from the hardware module.
 *
 * \retval uint16 The current compare value of the Load Jump Timer.
 * 				  Range: 0 to FFFF
 */
IFX_INLINE uint16 IfxPmsPm_getLoadJumpTimerCompareValue(void);

/**
 * \brief Returns the current count value of the Load Jump Timer.
 *
 * \retval uint16 The current count value of the Load Jump Timer.
 * 				  Range: 0 to FFFF
 */
IFX_INLINE uint16 IfxPmsPm_getLoadJumpTimerCountValue(void);

/**
 * \brief Issues a Load Jump request to transition the system to a different power mode.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_requestLoadJump(void);

/**
 * \brief Returns the current status of the Load Jump request.
 *
 * \retval IfxPmsPm_LoadJumpStatus The status of the Load Jump request.
 * 								   Range: \ref IfxPmsPm_LoadJumpStatus
 */
IFX_INLINE IfxPmsPm_LoadJumpStatus IfxPmsPm_getLoadJumpStatus(void);

/**
 * \brief Enables the usage of Voltage Droop Timer
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_enableVoltageDroopTimer(void);

/**
 * \brief Enables the update of the Voltage Droop Timer Overflow Flag when a timer overflow or timeout occurs.
 * 
 * \retval None
 */
IFX_INLINE void IfxPmsPm_enableVoltageDroopTimerOverflowFlag(void);

/**
 * \brief Enables the activation of interrupt on timer overflow or timeout.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_enableVoltageDroopTimerOverflowInterrupt(void);

/**
 * \brief Disables the usage of the Voltage Droop Timer in the PMU.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_disableVoltageDroopTimer(void);

/**
 * \brief Disables the Voltage Droop Timer Overflow Flag when a timer overflow or timeout occurs.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_disableVoltageDroopTimerOverflowFlag(void);

/**
 * \brief Disables the interrupt activation on timer overflow or timeout events.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_disableVoltageDroopTimerOverflowInterrupt(void);

/**
 * \brief Starts the voltage droop timer to monitor and manage voltage levels.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_startVoltageDroopTimer(void);

/**
 * \brief Stops the Voltage Droop timer and cancels the associated SCU droop request.
 * 
 * \retval None
 */
IFX_INLINE void IfxPmsPm_stopVoltageDroopTimer(void);

/**
 * \brief Clear Voltage Droop timer count. Resets the Voltage Droop Timer and clears VDTRUN if usage of Voltage Droop Timer is enabled.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_clearVoltageDroopTimer(void);

/**
 * \brief Clears the Voltage Droop Timer Overflow Flag if the Overflow Flag is enabled.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_clearVoltageDroopTimerOverflowFlag(void);

/**
 * \brief Checks if a voltage droop timer overflow has occurred.
 *
 * \retval boolean TRUE  Voltage Droop Timer compare overflow has not happened.
 * 				   FALSE Voltage Droop Timer compare overflow has happened.
 */
IFX_INLINE boolean IfxPmsPm_hasVoltageDroopTimerOverflowOccured(void);

/**
 * \brief Sets the compare value for the Voltage Droop Timer in the SCU_PMTRCSR1.B.VDTCV register.
 *
 * When the Timer count reaches this value, an overflow condition occurs, triggering the respective flag and interrupt (if enabled).
 *
 * \param[in] compareValue Voltage Droop Timer Compare Value to be loaded into the register.
 * 						   Range: 0 to 0x3FF
 * \retval None
 */
IFX_INLINE void IfxPmsPm_setVoltageDroopTimerCompareValue(uint16 compareValue);

/**
 * \brief Reads and returns the Voltage Droop Timer Compare Value.
 *
 * \retval uint16 The current Voltage Droop Timer Compare Value.
 */
IFX_INLINE uint16 IfxPmsPm_getVoltageDroopTimerCompareValue(void);

/**
 * \brief Reads the current count value of the Voltage Droop Timer.
 *
 * \retval uint16 The current count value of the Voltage Droop Timer.
 */
IFX_INLINE uint16 IfxPmsPm_readVoltageDroopTimerCountValue(void);

/**
 * \brief Issues a voltage droop request with a specified direction.
 *
 * \param[in] droopRequest The type of voltage droop request.
 * 						   Range: \ref IfxPmsPm_VoltageDroopRequest
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_requestVoltageDroop(IfxPmsPm_VoltageDroopRequest droopRequest);

/**
 * \brief Retrieves the current status of the voltage droop request.
 *
 * \retval IfxPmsPm_VoltageDroopStatus The voltage droop status
 * 									   Range: \ref IfxPmsPm_VoltageDroopStatus
 */
IFX_INLINE IfxPmsPm_VoltageDroopStatus IfxPmsPm_getVoltageDroopStatus(void);

/**
 * \brief Sets the voltage droop step for power management.
 *
 * \param [in] droopStep The voltage droop step to be set.
 *                       Range: \ref IfxPmsPm_VoltageDroopStep
 *
 * \retval None
 */
IFX_INLINE void IfxPmsPm_setVoltageDroopStep(IfxPmsPm_VoltageDroopStep droopStep);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Configures supply monitoring for a specified voltage source with event and ramping mode settings.
 *
 * \param[inout] pms    Pointer to the base address of PMS registers.
 * \param[in]    source Voltage source to be monitored.
 * 						Range: \ref IfxPmsPm_VoltageSource
 * \param[in]    event  Type of event to monitor.
 * 						Range: \ref IfxPmsPm_ThresholdEvent
 * \param[in]    mode   Ramping direction for event detection.
 * 						Range: \ref IfxPmsPm_RampingMode
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_configureSupplyMonitoring(Ifx_PMS *pms, IfxPmsPm_VoltageSource source, IfxPmsPm_ThresholdEvent event, IfxPmsPm_RampingMode mode);

/**
 * \brief Initializes the Load Jump configuration structure with default values.
 * 
 * \param[inout] loadJumpConfig Pointer to the Load Jump configuration structure to be initialized.
 * 
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_initLoadJumpConfig(IfxPmsPm_LoadJumpConfig *loadJumpConfig);

/**
 * \brief Initializes the Load Jump feature and requests a load jump based on the provided configuration.
 *
 * \param[in] loadJumpConfig Pointer to the IfxPmsPm_LoadJumpConfig structure containing options for enabling the load jump timer, its overflow flag, and interrupt.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_initAndRequestLoadJump(IfxPmsPm_LoadJumpConfig *loadJumpConfig);

/**
 * \brief Initializes the voltage droop configuration structure with default values.
 *
 * \param[inout] voltageDroopConfig A pointer to the voltage droop configuration structure to be initialized.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_initVoltageDroopConfig(IfxPmsPm_VoltageDroopConfig *voltageDroopConfig);

/**
 * \brief Initializes the voltage droop feature and requests a voltage change based on the provided configuration.
 *
 * \param[in] voltageDroopConfig A pointer to the voltage droop configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_initAndRequestVoltageDroop(IfxPmsPm_VoltageDroopConfig *voltageDroopConfig);

/**
 * \brief Copies dataSize bytes of data to standby RAM starting at dataPointer and appends the CRC over the copied data to it.
 *
 * \param[in] dataPointer Pointer to the beginning of the region containing the data to be copied. This is located in standby RAM.
 * \param[in] dataSize    Total size of the data to be copied.
 * 					      Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsPm_handleStandbyRam(uint32 *dataPointer, uint8 dataSize);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxPmsPm_setSleepMode(IfxPmsPm_RequestPowerMode powerMode)
{
    uint16 cpuWdtPw = IfxScuWdt_getCpuWatchdogPassword();
#ifndef DEVICE_TC33X
    uint8  index    = IfxCpu_getCoreIndex();
    IfxScuWdt_clearCpuEndinit(cpuWdtPw);

    switch (index)
    {
    case 0:
        MODULE_SCU.PMCSR0.B.REQSLP = powerMode;
        break;
#if IFXCPU_NUM_MODULES > 1
    case 1:
        MODULE_SCU.PMCSR1.B.REQSLP = powerMode;
        break;
#endif  /*IFXCPU_NUM_MODULES > 1*/
#if IFXCPU_NUM_MODULES > 2
    case 2:
        MODULE_SCU.PMCSR2.B.REQSLP = powerMode;
        break;
#endif /*IFXCPU_NUM_MODULES > 2*/
#if IFXCPU_NUM_MODULES > 3
    case 3:
        MODULE_SCU.PMCSR3.B.REQSLP = powerMode;
        break;
#endif /*IFXCPU_NUM_MODULES > 3*/
#if IFXCPU_NUM_MODULES > 4
    case 4:
        MODULE_SCU.PMCSR4.B.REQSLP = powerMode;
        break;
#endif /*IFXCPU_NUM_MODULES > 4*/
#if IFXCPU_NUM_MODULES > 5
    case 5:
        MODULE_SCU.PMCSR5.B.REQSLP = powerMode;
        break;
#endif /*IFXCPU_NUM_MODULES > 5*/
    }
#else
    IfxScuWdt_clearCpuEndinit(cpuWdtPw);
    MODULE_SCU.PMCSR0.B.REQSLP = powerMode;
#endif /*#ifndef DEVICE_TC33X*/
    IfxScuWdt_setCpuEndinit(cpuWdtPw);
}


IFX_INLINE void IfxPmsPm_setMasterCpu(IfxCpu_ResourceCpu cpuIndex)
{
    uint16 endinitSfty_pw;
    /*get the watch-dog passwords for usage with this function*/
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();
    /* Reset Safety ENDINIT, SCU_CCUCON registers are protected*/
    IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);
    MODULE_SCU.PMSWCR1.B.CPUSEL = cpuIndex + 1; //check if it's xENDINIT protected
    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);
}


IFX_INLINE IfxCpu_ResourceCpu IfxPmsPm_getMasterCpu(void)
{
    return (IfxCpu_ResourceCpu)(MODULE_SCU.PMSWCR1.B.CPUSEL - 1);
}


IFX_INLINE void IfxPmsPm_enableLoadJumpTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.LJTEN = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_disableLoadJumpTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.LJTEN = 0;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_enableLoadJumpTimerOverflowFlag(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.LJTOVEN = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_disableLoadJumpTimerOverflowFlag(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.LJTOVEN = 0;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_enableLoadJumpTimerOverflowInterrupt(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.LJTOVIEN = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_disableLoadJumpTimerOverflowInterrupt(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.LJTOVIEN = 0;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_startLoadJumpTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.LJTSTRT = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_stopLoadJumpTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.LJTSTP = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_clearLoadJumpTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.LJTCLR = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_clearLoadJumpTimerOverflowFlag(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR2.B.LJTOVCLR = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE boolean IfxPmsPm_hasLoadJumpTimerOverflowOccured(void)
{
    return (boolean)SCU_PMTRCSR2.B.LJTOV;
}


IFX_INLINE void IfxPmsPm_setLoadJumpTimerCompareValue(uint16 compareValue)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR1.B.LJTCV = compareValue;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE uint16 IfxPmsPm_getLoadJumpTimerCompareValue(void)
{
    return (uint16)SCU_PMTRCSR1.B.LJTCV;
}


IFX_INLINE uint16 IfxPmsPm_getLoadJumpTimerCountValue(void)
{
    return (uint16)SCU_PMTRCSR2.B.LJTCNT;
}


IFX_INLINE void IfxPmsPm_requestLoadJump(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR2.B.LDJMPREQ = 1U;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE IfxPmsPm_LoadJumpStatus IfxPmsPm_getLoadJumpStatus(void)
{
    return (IfxPmsPm_LoadJumpStatus)SCU_PMTRCSR2.B.LJTRUN;
}


IFX_INLINE void IfxPmsPm_enableVoltageDroopTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.VDTEN = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_enableVoltageDroopTimerOverflowFlag(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.VDTOVEN = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_enableVoltageDroopTimerOverflowInterrupt(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.VDTOVIEN = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_disableVoltageDroopTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.VDTEN = 0;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_disableVoltageDroopTimerOverflowFlag(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.VDTOVEN = 0;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_disableVoltageDroopTimerOverflowInterrupt(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.VDTOVIEN = 0;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_startVoltageDroopTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.VDTSTRT = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_stopVoltageDroopTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.VDTSTP = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_clearVoltageDroopTimer(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.VDTCLR = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE void IfxPmsPm_clearVoltageDroopTimerOverflowFlag(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR3.B.VDTOVCLR = 1;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE boolean IfxPmsPm_hasVoltageDroopTimerOverflowOccured(void)
{
    return (boolean)SCU_PMTRCSR3.B.VDTOV;
}


IFX_INLINE void IfxPmsPm_setVoltageDroopTimerCompareValue(uint16 compareValue)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR1.B.VDTCV = compareValue;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE uint16 IfxPmsPm_getVoltageDroopTimerCompareValue(void)
{
    return (uint16)SCU_PMTRCSR1.B.VDTCV;
}


IFX_INLINE uint16 IfxPmsPm_readVoltageDroopTimerCountValue(void)
{
    return (uint16)SCU_PMTRCSR3.B.VDTCNT;
}


IFX_INLINE void IfxPmsPm_requestVoltageDroop(IfxPmsPm_VoltageDroopRequest droopRequest)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR3.B.VDROOPREQ = droopRequest;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IFX_INLINE IfxPmsPm_VoltageDroopStatus IfxPmsPm_getVoltageDroopStatus(void)
{
    return (IfxPmsPm_VoltageDroopStatus)SCU_PMTRCSR3.B.VDTRUN;
}


IFX_INLINE void IfxPmsPm_setVoltageDroopStep(IfxPmsPm_VoltageDroopStep droopStep)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    SCU_PMTRCSR0.B.SDSTEP = droopStep;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


#endif /* IFXPMSPM_H */
