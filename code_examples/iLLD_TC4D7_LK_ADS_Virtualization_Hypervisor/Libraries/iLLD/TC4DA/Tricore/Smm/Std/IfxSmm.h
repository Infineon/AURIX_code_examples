/**
 * \file IfxSmm.h
 * \brief SMM  basic functionality
 * \ingroup IfxLld_Smm
 *
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2024 Infineon Technologies AG. All rights reserved.
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
 * Standard layer for SMM
 *
 * \defgroup IfxLld_Smm_Std_Enumerations Enumerations
 * \ingroup IfxLld_Smm_Std
 * \defgroup IfxLld_Smm_Std_DataStructures Data Structures
 * \ingroup IfxLld_Smm_Std
 * \defgroup IfxLld_Smm_Std_ModuleFunctions Module Functions
 * \ingroup IfxLld_Smm_Std
 */

#ifndef IFXSMM_H
#define IFXSMM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxSmm_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxSmm_reg.h"
#include "IfxSmm_bf.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"
#include "_Utilities/Ifx_Assert.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Smm_Std_Enumerations
 * \{ */
/** \brief List of different statuses related to Load Jump.
 * This is reflected in LJTRUN
 */
typedef enum
{
    IfxSmm_LoadJumpStatus_inactive                 = 0,  /**< \brief Load Jump and Load Jump Timer inactive */
    IfxSmm_LoadJumpStatus_swTriggeredRequestActive = 1,  /**< \brief A SW triggered Load Jump active and Load Jump Timer active */
    IfxSmm_LoadJumpStatus_hwTriggeredRequestActive = 2   /**< \brief A HW triggered Load Jump active and Load Jump Timer active */
} IfxSmm_LoadJumpStatus;

/** \brief Direction of Voltage Droop(positive and negative)
 * To be specified in VDROOPREQ
 */
typedef enum
{
    IfxSmm_VoltageDroopRequest_inactive = 0,  /**< \brief Voltage droop inactive */
    IfxSmm_VoltageDroopRequest_positive = 1,  /**< \brief A Positive Voltage Droop Request made and taken. Voltage Droop Timer activated. */
    IfxSmm_VoltageDroopRequest_negative = 2   /**< \brief A Negative Voltage Droop Request made and taken. Voltage Droop Timer activated. */
} IfxSmm_VoltageDroopRequest;

/** \brief Lists out voltage droop steps
 */
typedef enum
{
    IfxSmm_VoltageDroopStep_0mV  = 0,    /**< \brief Voltage  Droop request of 0 mV */
    IfxSmm_VoltageDroopStep_5mV  = 1U,   /**< \brief Voltage  Droop request of 5 mV */
    IfxSmm_VoltageDroopStep_10mV = 2U,   /**< \brief Voltage  Droop request of 10 mV */
    IfxSmm_VoltageDroopStep_15mV = 3U,   /**< \brief Voltage  Droop request of 15 mV */
    IfxSmm_VoltageDroopStep_20mV = 4U,   /**< \brief Voltage  Droop request of 20 mV */
    IfxSmm_VoltageDroopStep_25mV = 5U,   /**< \brief Voltage  Droop request of 25 mV */
    IfxSmm_VoltageDroopStep_30mV = 6U,   /**< \brief Voltage  Droop request of 30 mV */
    IfxSmm_VoltageDroopStep_35mV = 7U,   /**< \brief Voltage  Droop request of 35 mV */
    IfxSmm_VoltageDroopStep_40mV = 8U,   /**< \brief Voltage  Droop request of 40 mV */
    IfxSmm_VoltageDroopStep_45mV = 9U,   /**< \brief Voltage  Droop request of 45 mV */
    IfxSmm_VoltageDroopStep_50mV = 10U,  /**< \brief Voltage  Droop request of 50 mV */
    IfxSmm_VoltageDroopStep_55mV = 11U,  /**< \brief Voltage  Droop request of 55 mV */
    IfxSmm_VoltageDroopStep_60mV = 12U,  /**< \brief Voltage  Droop request of 60 mV */
    IfxSmm_VoltageDroopStep_65mV = 13U,  /**< \brief Voltage  Droop request of 65 mV */
    IfxSmm_VoltageDroopStep_70mV = 14U,  /**< \brief Voltage  Droop request of 70 mV */
    IfxSmm_VoltageDroopStep_75mV = 15U   /**< \brief Voltage  Droop request of 75 mV */
} IfxSmm_VoltageDroopStep;

/** \} */

/** \brief ESR Port mode configuration
 */
typedef enum
{
    IfxSmm_PortMode_inputNoPullDevice      = ((0U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 0U),  /**< \brief Input, No pull device connected. */
    IfxSmm_PortMode_inputPullDown          = ((1U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 0U),  /**< \brief Input, pull-down device connected. */
    IfxSmm_PortMode_inputPullUp            = ((2U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 0U),  /**< \brief Input, pull-up device connected. */
    IfxSmm_PortMode_outputPushPullGeneral  = ((0U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Push-pull, General-purpose output */
    IfxSmm_PortMode_outputPushPullAlt1     = ((1U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Push-pull, Alternate output function 1. */
    IfxSmm_PortMode_outputPushPullAlt2     = ((2U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Push-pull, Alternate output function 2. */
    IfxSmm_PortMode_outputPushPullAlt3     = ((3U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Push-pull, Alternate output function 3. */
    IfxSmm_PortMode_outputPushPullAlt7     = ((7U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Push-pull, Alternate output function 7. */
    IfxSmm_PortMode_outputPushPullAlt8     = ((8U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Push-pull, Alternate output function 8. */
    IfxSmm_PortMode_outputPushPullAlt9     = ((9U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (0U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Push-pull, Alternate output function 9. */
    IfxSmm_PortMode_outputOpenDrainGeneral = ((0U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (1U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Open-drain, General-purpose output */
    IfxSmm_PortMode_outputOpenDrainAlt1    = ((1U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (1U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Open-drain, Alternate output function 1. */
    IfxSmm_PortMode_outputOpenDrainAlt2    = ((2U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (1U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Open-drain, Alternate output function 2. */
    IfxSmm_PortMode_outputOpenDrainAlt3    = ((3U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (1U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Open-drain, Alternate output function 3. */
    IfxSmm_PortMode_outputOpenDrainAlt7    = ((7U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (1U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Open-drain, Alternate output function 7. */
    IfxSmm_PortMode_outputOpenDrainAlt8    = ((8U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (1U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U),  /**< \brief Open-drain, Alternate output function 8. */
    IfxSmm_PortMode_outputOpenDrainAlt9    = ((9U << IFX_SMM_DRVCFGESR0_MODE_OFF) | (1U << IFX_SMM_DRVCFGESR0_OD_OFF) | 1U)   /**< \brief Open-drain, Alternate output function 9. */
} IfxSmm_PortMode;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Smm_Std_DataStructures
 * \{ */
/** \brief Load Jump Configuration
 */
typedef struct
{
    boolean enableLoadJumpTimer;                        /**< \brief Enable or disable Load Jump Timer */
    boolean enableLoadJumpTimerOverflowFlag;            /**< \brief Enable or disable update of Load Jump Timer Overflow Flag */
    boolean enableLoadJumpTimerOverflowInterrupt;       /**< \brief Enable or disable Load Jump Timer Overflow Interrupt */
    uint16  loadjumpTimerCompareValue;                  /**< \brief Load jump timer compare value */
} IfxSmm_LoadJumpConfig;

/** \brief Droop control configuration for load jump sequencing unit B
 */
typedef struct
{
    IfxSmm_VoltageDroopStep steps;          /**< \brief Target number of steps to raise or lower voltage level */
    boolean                 dir;            /**< \brief Direction of the voltage rising/falling. FALSE -->Rising, TRUE --> Falling */
    boolean                 droopReq;       /**< \brief Request to trigger new voltage droop compensation activity */
    uint8                   dwellCnt;       /**< \brief Timer counts to keep the voltage level at compensation level */
} IfxSmm_VoltageDroopConfig;

/** \brief Voltage Droop Configuration of load jump sequence unit A
 */
typedef struct
{
    boolean                    enableVoltageDroopTimer;                        /**< \brief Enable or disable usage of Voltage Droop Timer */
    boolean                    enableVoltageDroopTimerOverflowFlag;            /**< \brief Enable or disable usage of Voltage Droop Timer Overflow Flag */
    boolean                    enableVoltageDroopTimerOverflowInterrupt;       /**< \brief Enable or disable usage of Voltage Droop Interrupt */
    IfxSmm_VoltageDroopRequest droopRequestType;                               /**< \brief Type of Voltage Droop Request */
    uint16                     droopTimerCompareValue;                         /**< \brief Voltage droop compare value */
} IfxSmm_VoltageDroopLegacyConfig;

/** \} */

/** \addtogroup IfxLld_Smm_Std_ModuleFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enables the usage of load jump sequence A timer
 * \return None
 */
IFX_INLINE void IfxSmm_enableLoadJumpTimer(void);

/** \brief Disables the usage of load jump sequence A timer
 * \return None
 */
IFX_INLINE void IfxSmm_disableLoadJumpTimer(void);

/** \brief Enables the update of LJTOV status bit on timer overflow or timeout of load jump sequence unit A.
 * \return None
 */
IFX_INLINE void IfxSmm_enableLoadJumpTimerOverflowFlag(void);

/** \brief Disables the update of LJTOV status bit on timer overflow or timeout of load jump sequence unit A.
 * \return None
 */
IFX_INLINE void IfxSmm_disableLoadJumpTimerOverflowFlag(void);

/** \brief Enables the activation of interrupt on timer overflow or timeout of load jump sequence unit A.
 * \return None
 */
IFX_INLINE void IfxSmm_enableLoadJumpTimerOverflowInterrupt(void);

/** \brief Disables the activation of interrupt on timer overflow or timeout of load jump sequence unit A.
 * \return None
 */
IFX_INLINE void IfxSmm_disableLoadJumpTimerOverflowInterrupt(void);

/** \brief Starts Load jump sequence unit A timer. The LJTSTRT bitfield remains set on a write and is cleared when LJTOV bit is set if .LJTOVEN bit is enabled(Update of Load Jump Timer Overflow Flag LJTOV is enabled ).
 * \return None
 */
IFX_INLINE void IfxSmm_startLoadJumpTimer(void);

/** \brief This stops the Load jump sequence unit A timer. The Load Jump Timer stops counter at the current value and timer re-starts from that value when LJTSTP is cleared and LJTSTRT is set.
 * \return None
 */
IFX_INLINE void IfxSmm_stopLoadJumpTimer(void);

/** \brief Clears the Load Jump sequence unit A timer count
 * \return None
 */
IFX_INLINE void IfxSmm_clearLoadJumpTimer(void);

/** \brief Clears Load Jump sequence unit A Timer Overflow Flag (SCU_PMTRCSR2.B.LJTOV) and sets PMTRCSR3.B.VDROOPREQ and PMTRCSR2.B.LDJMPREQ to 0 if Load Jump Timer Overflow Flag bit is enabled
 * \return None
 */
IFX_INLINE void IfxSmm_clearLoadJumpTimerOverflowFlag(void);

/** \brief Returns status of Load Jump Timer Overflow condition.
 * \return Status of Load Jump Timer Overflow condition
 */
IFX_INLINE boolean IfxSmm_hasLoadJumpTimerOverflowOccured(void);

/** \brief Loads the compare value for Load Jump sequence unit A Timer in LJTCV. When the Timer count reaches this value, overflow condition occurs and the respective flag and interrupt occurs, if enabled
 * \param compareValue Compare value for Load Jump Timer
 * \return None
 */
IFX_INLINE void IfxSmm_setLoadJumpTimerCompareValue(uint16 compareValue);

/** \brief Reads the Load Jump sequence unit A Timer Compare value
 * \return Load Jump Timer compare value
 */
IFX_INLINE uint16 IfxSmm_getLoadJumpTimerCompareValue(void);

/** \brief Returns the Load Jump sequence unit A Timer count value
 * \return Load Jump Timer count value
 */
IFX_INLINE uint16 IfxSmm_getLoadJumpTimerCountValue(void);

/** \brief Issues a Load Jump sequence unit A request
 * \return None
 */
IFX_INLINE void IfxSmm_requestLoadJump(void);

/** \brief Returns the status of Load Jump sequence unit A request
 * \return Load Jump request status
 */
IFX_INLINE IfxSmm_LoadJumpStatus IfxSmm_getLoadJumpStatus(void);

/** \brief Enables the usage of Voltage Droop Timer of load jump sequence unit A.
 * \return None
 */
IFX_INLINE void IfxSmm_enableVoltageDroopLegacyTimer(void);

/** \brief Disables the usage of Voltage Droop Timer of load jump sequence unit A.
 * \return None
 */
IFX_INLINE void IfxSmm_disableVoltageDroopLegacyTimer(void);

/** \brief Enables the update of Voltage Droop Timer Overflow Flag on timer overflow or timeout of load jump sequence unit A.
 * \return None
 */
IFX_INLINE void IfxSmm_enableVoltageDroopLegacyTimerOverflowFlag(void);

/** \brief Enables the activation of interrupt on timer overflow or timeout of load jump sequence unit A..
 * \return None
 */
IFX_INLINE void IfxSmm_enableVoltageDroopLegacyTimerOverflowInterrupt(void);

/** \brief Disables the update of Voltage Droop Timer Overflow Flag on timer overflow or timeout of load jump sequence unit A..
 * \return None
 */
IFX_INLINE void IfxSmm_disableVoltageDroopLegacyTimerOverflowFlag(void);

/** \brief Disables the activation of interrupt on timer overflow or timeout of load jump sequence unit A..
 * \return None
 */
IFX_INLINE void IfxSmm_disableVoltageDroopLegacyTimerOverflowInterrupt(void);

/** \brief Starts Voltage Droop timer of load jump sequence unit A.
 * \return None
 */
IFX_INLINE void IfxSmm_startVoltageDroopLegacyTimer(void);

/** \brief Stops Voltage Droop timer of load jump sequence unit A..
 * \return None
 */
IFX_INLINE void IfxSmm_stopVoltageDroopLegacyTimer(void);

/** \brief Clear Voltage Droop timer count of load jump sequence unit A. Resets the Voltage Droop Timer and clears VDTRUN if usage of Voltage Droop Timer is enabled.
 * \return None
 */
IFX_INLINE void IfxSmm_clearVoltageDroopLegacyTimer(void);

/** \brief Clears Voltage Droop Timer Overflow Flag of load jump sequence unit A if Overflow Flag is enabled
 * \return None
 */
IFX_INLINE void IfxSmm_clearVoltageDroopLegacyTimerOverflowFlag(void);

/** \brief Returns Status of Voltage Droop Time overflow condition of load jump sequence unit A.
 * \return Status of Voltage Droop Time overflow
 */
IFX_INLINE boolean IfxSmm_hasVoltageDroopLegacyTimerOverflowOccured(void);

/** \brief Loads the compare value for Voltage Droop Timer of load jump sequence unit A in VDTCV.When the Timer count reaches this value, overflow condition occurs and the respective flag and interrupt occurs, if enabled
 * \param compareValue Voltage Droop Timer Compare Value
 * \return None
 */
IFX_INLINE void IfxSmm_setVoltageDroopLegacyTimerCompareValue(uint16 compareValue);

/** \brief Reads the Load Jump Timer Compare value of load jump sequence unit A.
 * \return Voltage Droop Timer Compare Value
 */
IFX_INLINE uint16 IfxSmm_getVoltageDroopLegacyTimerCompareValue(void);

/** \brief Gives Voltage Droop Timer count value of load jump sequence unit A.
 * \return Voltage Droop Timer Count Value
 */
IFX_INLINE uint16 IfxSmm_readVoltageDroopLegacyTimerCountValue(void);

/** \brief Issue a voltage droop request of load jump sequence unit A.
 * \param droopRequest Type of Voltage Droop Request
 * \return None
 */
IFX_INLINE void IfxSmm_requestLegacyVoltageDroop(IfxSmm_VoltageDroopRequest droopRequest);

/** \brief Returns the status of Voltage droop timer of load jump sequence unit A.
 * \return Load Jump request status
 */
IFX_INLINE IfxSmm_LoadJumpStatus IfxSmm_getVoltageDroopLegacyStatus(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function to initialize Voltage droop configuration structure with default values
 * \param voltageDroopConfig Voltage droop configuration pointer
 * \return None
 *
 * \code
 * //Create a global variable
 * IfxSmm_VoltageDroopLegacyConfig droopConfig;
 * IfxSmm_initVoltageDroopLegacyConfig(&droopConfig);
 *
 * //Modify the configuration as per application need
 * droopConfig.droopStep = IfxSmm_VoltageDroopStep_20mV;
 *
 * //Initialize and Request Voltage droop
 * IfxSmm_initAndRequestLegacyVoltageDroop(&droopConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxSmm_initVoltageDroopLegacyConfig(IfxSmm_VoltageDroopLegacyConfig *voltageDroopConfig);

/** \brief Function initialize and request voltage droop for load jump sequence unit A.
 * \param voltageDroopConfig Voltage Droop configuration pointer
 * \return 0 --> Voltage droop requested
 * 1 --> Voltage droop timer already running
 *
 * \code
 *   //Initialize and Request Voltage droop
 *   IfxSmm_initAndRequestLegacyVoltageDroop(&droopConfig);
 * \endcode
 *
 * \see IfxSmm_initVoltageDroopLegacyConfig()
 *
 */
IFX_EXTERN boolean IfxSmm_initAndRequestLegacyVoltageDroop(IfxSmm_VoltageDroopLegacyConfig *voltageDroopConfig);

/** \brief Function to initialize load jump configuration structure with default values.
 * \param loadJumpConfig Load jump configuration pointer
 * \return None
 *
 * \code
 * //Create a global variable
 * IfxSmm_LoadJumpConfig loadJumpConfig;
 * IfxSmm_initLoadJumpConfig(&loadJumpConfig);
 *
 * //Modify the configuration as per application need
 * loadJumpConfig.loadjumpTimerCompareValue = 0x135;
 *
 * //Initialize and Request load jump
 * IfxSmm_initLoadJumpConfig(&loadJumpConfig);
 * \endcode
 *
 */
IFX_EXTERN void IfxSmm_initLoadJumpConfig(IfxSmm_LoadJumpConfig *loadJumpConfig);

/** \brief Function to initialize and request load jump.
 * \param loadJumpConfig Load jump configuration pointer
 * \return 0 --> Load jump requested.
 * 1 --> Load Jump timer already running
 *
 * \code
 * //Initialize and Request load jump
 * IfxSmm_initLoadJumpConfig(&loadJumpConfig);
 * \endcode
 *
 * \see IfxSmm_initAndRequestLoadJump()
 *
 */
IFX_EXTERN boolean IfxSmm_initAndRequestLoadJump(IfxSmm_LoadJumpConfig *loadJumpConfig);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function to set target number of steps to raise or lower voltage level.
 * \param step Target number of steps
 * \return None
 */
IFX_INLINE void IfxSmm_setVoltageDroopStep(IfxSmm_VoltageDroopStep step);

/** \brief Function to abort voltage compensation activity
 * \return None
 */
IFX_INLINE void IfxSmm_abortVoltageCompensation(void);

/** \brief Function to trigger new voltage droop compensation activity.
 * \return 0 --> Voltage droop request is taken.
 * 1 --> Voltage droop request cannot be taken.
 */
IFX_INLINE boolean IfxSmm_requestVoltageDroop(void);

/** \brief Function returns error status, occurred during voltage compensation activity.
 * \return Error status
 * 0 --> No Error
 * 1 --> Error
 */
IFX_INLINE boolean IfxSmm_getErrorStatusDuringVoltCompensation(void);

/** \brief Function returns current voltage status w.r.t nominal supply level
 * \return Voltage nominal level status
 * 0 --> Current voltage not at nominal supply level
 * 1 --> Current voltage is at nominal supply level.
 */
IFX_INLINE boolean IfxSmm_getCurrentVoltageNominalStatus(void);

/** \brief Function returns current voltage set point status.
 * \return Voltage set point status
 * 0 --> Current voltage is not at voltage set point.
 * 1 --> Current voltage is at voltage set point
 */
IFX_INLINE boolean IfxSmm_getCurrentVoltageSetpointStatus(void);

/** \brief Function returns droop compensation activity status.
 * \return Droop compensation activity status
 * 0 --> No droop compensation activity currently running.
 * 1 --> Droop compensation activity is on-going
 */
IFX_INLINE boolean IfxSmm_getDroopCompActivityStatus(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function initializes the voltage droop configuration for sequence B
 * \param voltageDroopConfig Voltage droop configuration pointer
 * \return None
 */
IFX_EXTERN void IfxSmm_initVoltageDroopConfig(IfxSmm_VoltageDroopConfig *voltageDroopConfig);

/** \brief Function to initialize and request voltage droop.
 * \param voltageDroopConfig Voltage Droop configuration pointer
 * \return 0 --> Voltage droop request is triggered
 * 1 --> Voltage droop request not issued. Busy bit set
 */
IFX_EXTERN boolean IfxSmm_initAndRequestVoltageDroop(IfxSmm_VoltageDroopConfig *voltageDroopConfig);

/** \brief Configures access to all masters to all the SMM in the device
 * \param apConfig pointer to configuration structure
 * \return None
 */
IFX_EXTERN void IfxSmm_configureAccessToSmm(IfxApApu_ApuConfig *apConfig);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxSmm_enableLoadJumpTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.LJTEN = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_disableLoadJumpTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.LJTEN = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_enableLoadJumpTimerOverflowFlag(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.LJTOVEN = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_disableLoadJumpTimerOverflowFlag(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.LJTOVEN = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_enableLoadJumpTimerOverflowInterrupt(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.LJTOVIEN = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_disableLoadJumpTimerOverflowInterrupt(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.LJTOVIEN = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_startLoadJumpTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.LJTSTRT = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_stopLoadJumpTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.LJTSTP = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_clearLoadJumpTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.LJTCLR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_clearLoadJumpTimerOverflowFlag(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR2.B.LJTOVCLR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE boolean IfxSmm_hasLoadJumpTimerOverflowOccured(void)
{
    return (boolean)SMM_PMTRCSR2.B.LJTOV;
}


IFX_INLINE void IfxSmm_setLoadJumpTimerCompareValue(uint16 compareValue)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR1.B.LJTCV = compareValue;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE uint16 IfxSmm_getLoadJumpTimerCompareValue(void)
{
    return (uint16)SMM_PMTRCSR1.B.LJTCV;
}


IFX_INLINE uint16 IfxSmm_getLoadJumpTimerCountValue(void)
{
    return (uint16)SMM_PMTRCSR2.B.LJTCNT;
}


IFX_INLINE void IfxSmm_requestLoadJump(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR2.B.LDJMPREQ = 1U;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE IfxSmm_LoadJumpStatus IfxSmm_getLoadJumpStatus(void)
{
    return (IfxSmm_LoadJumpStatus)SMM_PMTRCSR2.B.LJTRUN;
}


IFX_INLINE void IfxSmm_enableVoltageDroopLegacyTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.VDTEN = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_disableVoltageDroopLegacyTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.VDTEN = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_enableVoltageDroopLegacyTimerOverflowFlag(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.VDTOVEN = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_enableVoltageDroopLegacyTimerOverflowInterrupt(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.VDTOVIEN = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_disableVoltageDroopLegacyTimerOverflowFlag(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.VDTOVEN = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_disableVoltageDroopLegacyTimerOverflowInterrupt(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.VDTOVIEN = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_startVoltageDroopLegacyTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.VDTSTRT = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_stopVoltageDroopLegacyTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.VDTSTP = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_clearVoltageDroopLegacyTimer(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR0.B.VDTCLR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_clearVoltageDroopLegacyTimerOverflowFlag(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR3.B.VDTOVCLR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE boolean IfxSmm_hasVoltageDroopLegacyTimerOverflowOccured(void)
{
    return (boolean)SMM_PMTRCSR3.B.VDTOV;
}


IFX_INLINE void IfxSmm_setVoltageDroopLegacyTimerCompareValue(uint16 compareValue)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR1.B.VDTCV = compareValue;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE uint16 IfxSmm_getVoltageDroopLegacyTimerCompareValue(void)
{
    return (uint16)SMM_PMTRCSR1.B.VDTCV;
}


IFX_INLINE uint16 IfxSmm_readVoltageDroopLegacyTimerCountValue(void)
{
    return (uint16)SMM_PMTRCSR3.B.VDTCNT;
}


IFX_INLINE void IfxSmm_requestLegacyVoltageDroop(IfxSmm_VoltageDroopRequest droopRequest)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_PMTRCSR3.B.VDROOPREQ = droopRequest;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE IfxSmm_LoadJumpStatus IfxSmm_getVoltageDroopLegacyStatus(void)
{
    return (IfxSmm_LoadJumpStatus)SMM_PMTRCSR3.B.VDTRUN;
}


IFX_INLINE void IfxSmm_setVoltageDroopStep(IfxSmm_VoltageDroopStep step)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_DRPCTRL.B.STEPS = step;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxSmm_abortVoltageCompensation(void)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
    SMM_DRPCTRL.B.ABORT = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE boolean IfxSmm_requestVoltageDroop(void)
{
    boolean request = 0;

    if (!SMM_DRPCTRL.B.BUSY)
    {
#if (IFX_PROT_ENABLED == 1U)
        IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
        SMM_DRPCTRL.B.REQ = 1;
        request           = 1;
#if (IFX_PROT_ENABLED == 1U)
        IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
    }

    return request;
}


IFX_INLINE boolean IfxSmm_getErrorStatusDuringVoltCompensation(void)
{
    return (boolean)(SMM_DRPCTRL.B.ERR);
}


IFX_INLINE boolean IfxSmm_getCurrentVoltageNominalStatus(void)
{
    return (boolean)(SMM_DRPCTRL.B.V_NOM);
}


IFX_INLINE boolean IfxSmm_getCurrentVoltageSetpointStatus(void)
{
    return (boolean)(SMM_DRPCTRL.B.V_SP);
}


IFX_INLINE boolean IfxSmm_getDroopCompActivityStatus(void)
{
    return (boolean)(SMM_DRPCTRL.B.BUSY);
}


#endif /* IFXSMM_H */
