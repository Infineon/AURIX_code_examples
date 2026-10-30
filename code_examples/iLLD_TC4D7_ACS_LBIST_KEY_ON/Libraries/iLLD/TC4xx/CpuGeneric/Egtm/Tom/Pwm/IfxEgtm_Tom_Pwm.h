/**
 * \file IfxEgtm_Tom_Pwm.h
 * \brief EGTM PWM details
 * \ingroup IfxLld_Egtm
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
 * \defgroup IfxLld_Egtm_Tom_Pwm_Usage How to use the EGTM TOM PWM Driver
 * \ingroup IfxLld_Egtm_Tom_Pwm
 *
 * This interface allows to generate PWM signal using TOM submodule of eGTM. User can configure the required frequency and duty cycle of the signal.
 *
 * Functionalities provided:
 *     -# Users can choose cluster and channel number of TOM
 *     -# Period and duty cycle can be provided in ticks
 *     -# Signal level during duty cycle can be configured
 *     -# Interrupt can be generated at CCU0 (period event) and/or CCU1 (duty event) match
 *     -# PWM can be routed to Pin using TOUT
 *     -# Channel can be connected to MSC
 *     -# CM0/CM1 registers can be updated with SR0/SR1 at end of period (synchronousUpdateEnabled)
 *     -# Users can choose to start PWM at end of init (immediateStartEnabled)
 *
 * \section Preparation Preparation
 * \subsection Include Include Files
 *
 * Include following header file into your C code:
 * \code
 *     #include "Egtm/Tom/Pwm/IfxEgtm_Tom_Pwm.h"
 * \endcode
 *
 * \subsection Variables Variables
 * Define global variables if necessary
 *
 *     \code
 *     // Pointer to SFR
 *     Ifx_EGTM *egtm = &MODULE_EGTM;
 *
 *     // Interrupt priority
 *     #define TOM0_CH0_PRIO 20
 *     \endcode
 *
 * \subsection Interrupts Interrupts
 * Define Interrupts if needed
 *
 * \code
 * IFX_INTERRUPT(TOM0Ch0_ISR, 0, TOM0_CH0_PRIO)
 * {
 *     // user code
 * }
 * \endcode
 *
 * \subsection Initialization Initialization
 *
 *     \code
 *     // 1. [Optional] Install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(TOM0Ch0_ISR, TOM0_CH0_PRIO);
 *
 *     // 2. Enable eGTM clocks
 *     {
 *         float32 frequency = IfxEgtm_Cmu_getModuleFrequency(egtm);
 *
 *         // Enables the EGTM
 *         IfxEgtm_enable(egtm);
 *
 *         // Set the global clock frequency to the max
 *         IfxEgtm_Cmu_setGclkFrequency(egtm, frequency);
 *
 *         // Set the CMU CLK0
 *         IfxEgtm_Cmu_setClkFrequency(egtm, IfxEgtm_Cmu_Clk_0, frequency);
 *
 *         // FXCLK: used by TOM and CLK0: used by TOM
 *         IfxEgtm_Cmu_enableClocks(egtm, IFXEGTM_CMU_CLKEN_FXCLK | IFXEGTM_CMU_CLKEN_CLK0);
 *     }
 *
 *     // 3. Instantiate variables
 *     IfxEgtm_Tom_Pwm_Config tomConfig; // Configuration structure
 *     IfxEgtm_Tom_Pwm_Driver tomHandle; // Handle
 *     IfxEgtm_MscOut           mscOut;     // MSC connection structure
 *
 *     // 4. Initialize with default values
 *     IfxEgtm_Tom_Pwm_initConfig(&tomConfig, egtm);
 *
 *     // 5. Manual Configuration
 *     tomConfig.cluster      = IfxEgtm_Cluster_0;     // TOM Cluster
 *     tomConfig.tomChannel  = IfxEgtm_Tom_Ch_0;       // TOM Channel
 *     tomConfig.period       = 20;                    // Period in ticks
 *     tomConfig.dutyCycle    = 10;                    // Duty cycle in ticks
 *     tomConfig.signalLevel  = Ifx_ActiveState_high;  // Choose signal level during duty
 *     tomConfig.synchronousUpdateEnabled   = TRUE;    // Update CM0/CM1 registers from Shadow at end of period
 *     tomConfig.immediateStartEnabled      = TRUE;    // Start PWM at end of init
 *
 *     // 6. [Optional] Interrupt configuration
 *     tomConfig.interrupt.ccu0Enabled = TRUE;
 *     tomConfig.interrupt.isrPriority = TOM0_CH0_PRIO;
 *
 *     // 7. [Optional] Output Pin connection
 *     tomConfig.pin.outputPin  = &IfxEgtm_TOM0_0_TOUT0_P02_0_OUT;
 *     tomConfig.pin.outputMode = IfxPort_OutputMode_pushPull;
 *     tomConfig.pin.padDriver  = IfxPort_PadDriver_cmosAutomotiveSpeed1;
 *
 *     // 8. [Optional] MSC Connection: Configure the structure mscOut as per the requirement.
 *     // During the Pwm init, Msc connection will be established with the configured channel by API call to IfxGtm_ConnectToMsc.
 *     mscOut.mscSet       = IfxEgtm_Cfg_MscSet_0;
 *     mscOut.mscSetSignal = IfxEgtm_Cfg_MscSetSignal_0;
 *     mscOut.mscModule    = IfxEgtm_Cfg_MscModule_0;
 *     mscOut.mscAltIn     = IfxEgtm_MscAltInput_low;
 *     tomConfig.mscOut   = &mscOut;                  // Attach to config
 *
 *     // 9. Call the init functions
 *     IfxEgtm_Tom_Pwm_init(&tomHandle, &tomConfig);
 *     \endcode
 *
 * TOM will be now generating a PWM signal on the selected port pin while generating selected interrupt according to above configured period and duty cycle.
 *
 * \subsection RunTime Run Time APIs
 *
 * To start the PWM, the following API can be called if channel was not started in init
 *
 *     \code
 *     // Start PWM immediately
 *     IfxEgtm_Tom_Pwm_start(&tomHandle, TRUE);
 *     \endcode
 *
 * To stop the PWM, call this API
 *
 *     \code
 *     // Stop PWM immediately
 *     IfxEgtm_Tom_Pwm_stop(&tomHandle, TRUE);
 *     \endcode
 *
 * \defgroup IfxLld_Egtm_Tom_Pwm Tom PWM Interface Driver
 * \ingroup IfxLld_Egtm_Tom
 * \defgroup IfxLld_Egtm_Tom_Pwm_Structures TOM PWM Structures
 * \ingroup IfxLld_Egtm_Tom_Pwm
 * \defgroup IfxLld_Egtm_Tom_Pwm_Functions TOM Pwm Functions
 * \ingroup IfxLld_Egtm_Tom_Pwm
 */

#ifndef IFXEGTM_TOM_PWM_H
#define IFXEGTM_TOM_PWM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_PinMap/IfxEgtm_PinMap.h"
#include "Egtm/Std/IfxEgtm_Tom.h"
#include "Egtm/Std/IfxEgtm_Cmu.h"
#include "Egtm/Std/IfxEgtm_Dtm.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Egtm_Tom_Pwm_Structures
 * \{ */
/** \brief configuration structure for interrupts
 */
typedef struct
{
    boolean         ccu0Enabled;       /**< \brief Enable/Disable choice for CCU0 trigger interrupt */
    boolean         ccu1Enabled;       /**< \brief Enable/Disable choice for CCU1 trigger interrupt */
    IfxEgtm_IrqMode mode;              /**< \brief IRQ mode of interrupt */
    IfxSrc_Tos      isrProvider;       /**< \brief Type of Service for Ccu0/1 interrupt */
    Ifx_Priority    isrPriority;       /**< \brief Priority for Ccu0/1 interrupt */
    IfxSrc_VmId     vmId;              /**< \brief Virtual machine interrupt service provider */
} IfxEgtm_Tom_Pwm_Interrupt;

/** \brief configuration structure for output pin
 */
typedef struct
{
    IfxEgtm_Tom_ToutMap *outputPin;        /**< \brief Output pin */
    IfxPort_OutputMode   outputMode;       /**< \brief Output mode */
    IfxPort_PadDriver    padDriver;        /**< \brief Pad driver */
} IfxEgtm_Tom_Pwm_pin;

/** \} */

/** \addtogroup IfxLld_Egtm_Tom_Pwm_Structures
 * \{ */
/** \brief Configuration structure
 */
typedef struct
{
    Ifx_EGTM                 *egtm;                           /**< \brief Pointer to EGTM module */
    IfxEgtm_Cluster           cluster;                        /**< \brief Cluster of TOM channel to be used */
    IfxEgtm_Tom_Ch            tomChannel;                     /**< \brief TOM channel to be used for PWM */
    IfxEgtm_Tom_Ch_ClkSrc     clock;                          /**< \brief Clock source for selected TOM channel */
    Ifx_ActiveState           signalLevel;                    /**< \brief Signal Level when duty is active */
    uint16                    period;                         /**< \brief Period in ticks (TOM only supports 16 bits). Range: 0 to 0xFFFF */
    uint16                    dutyCycle;                      /**< \brief Duty Cycle in ticks (TOM only supports 16 bits). Range: 0 to 0xFFFF */
    IfxEgtm_Tom_Pwm_Interrupt interrupt;                      /**< \brief Configuration structure for interrupt */
    IfxEgtm_Tom_Pwm_pin       pin;                            /**< \brief Configuration structure for output pin */
    IfxEgtm_MscOut           *mscOut;                         /**< \brief MSC configuration */
    IfxEgtm_Dtm_ClockSource   dtmClockSource;                 /**< \brief DTM clock source */
    boolean                   oneShotModeEnabled;             /**< \brief Enable/Disable the one shot mode (Currently, has no effect) */
    boolean                   synchronousUpdateEnabled;       /**< \brief Synchronous or Asynchronous update. TRUE: Update compare registers from shadow at the end of period */
    boolean                   immediateStartEnabled;          /**< \brief Enable/disable immediate start of PWM. TRUE: Start channel at end of init */
} IfxEgtm_Tom_Pwm_Config;

/** \brief Driver Handle
 */
typedef struct
{
    Ifx_EGTM             *egtm;                           /**< \brief Pointer to EGTM module */
    IfxEgtm_Cluster       clsIndex;                       /**< \brief Index of the CLS object used */
    IfxEgtm_Tom_Ch        tomChannel;                     /**< \brief TOM channel used for the timer */
    Ifx_EGTM_CLS_TOM     *tom;                            /**< \brief Pointer to the TOM object */
    Ifx_EGTM_CLS_TOM_TGC *tgc[IFXEGTM_TOM_NUM_TGC];       /**< \brief Pointer to the TGC object */
    boolean               synchronousUpdateEnabled;       /**< \brief Synchronous update enabled/disabled */
} IfxEgtm_Tom_Pwm_Driver;

/** \} */

/** \addtogroup IfxLld_Egtm_Tom_Pwm_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initializes a TOM channel to generate PWM signal
 *
 * \param[inout] driver TOM Handle
 * \param[in]    config Configuration structure for TOM PWM
 *
 * \retval Initialization status: TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxEgtm_Tom_Pwm_init(IfxEgtm_Tom_Pwm_Driver *driver, const IfxEgtm_Tom_Pwm_Config *config);

/** \brief Initializes the configuration structure to default values
 *
 * \param[inout] config This parameter is initialized by the function
 * \param[in]    egtm   Pointer to EGTM module (SFR)
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Tom_Pwm_initConfig(IfxEgtm_Tom_Pwm_Config *config, Ifx_EGTM *egtm);

/** \brief starts the PWM generation from the configured channel
 *
 * \param[inout] driver    Handle for the PWM device
 * \param[in]    immediate Immediate start or not
 *                         Range: TRUE: starts the PWM generation immediately
 *                                FALSE: Starts at the next trigger event
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Tom_Pwm_start(IfxEgtm_Tom_Pwm_Driver *driver, boolean immediate);

/** \brief Stops the PWM generation from the configured channel
 *
 * \param[inout] driver    Handle for the PWM device
 * \param[in]    immediate Immediate start or not.
 *                         Range: TRUE: Stops the PWM generation immediately
 *                                FALSE: Stops at the next trigger event
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Tom_Pwm_stop(IfxEgtm_Tom_Pwm_Driver *driver, boolean immediate);

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Updates PWM duty cycle
 *
 * \param[inout] driver      TOM Handle
 * \param[in]    requestDuty Requested duty in %
 *                           Range: 0.0 to 100.0
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Pwm_setDuty(IfxEgtm_Tom_Pwm_Driver *driver, float32 requestDuty);

/** \brief Update PWM frequency.
 *  Duty-cycle count is scaled automatically to preserve existing duty cycle.
 *
 * \param[inout] driver           TOM Handle.
 * \param[in]    requestFrequency New frequency in Hz (> 0). (if <= 0, function call returns without updating frequency).
 */
IFX_INLINE void IfxEgtm_Tom_Pwm_setFrequency(IfxEgtm_Tom_Pwm_Driver *driver, float32 requestFrequency);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxEgtm_Tom_Pwm_setDuty(IfxEgtm_Tom_Pwm_Driver *driver, float32 requestDuty)
{
    uint16 period;
    uint16 dutyCycle;

    /* Handle non-positive / invalid duty */
    if (requestDuty < 0.0f)
    {
        requestDuty = 0.0f;
    }
    else if (requestDuty > 100.0f)
    {
        requestDuty = 100.0f;
    }

    /* Use configured period value according to selected update mode */
    if (driver->synchronousUpdateEnabled == TRUE)
    {
        period = IfxEgtm_Tom_Ch_getCompareZeroShadow(driver->tom, driver->tomChannel);
    }
    else
    {
        period = IfxEgtm_Tom_Ch_getCompareZero(driver->tom, driver->tomChannel);
    }

    /* Duty in ticks = period * (requestDuty in percent / 100%) */
    dutyCycle = (uint16)(((float32)period * requestDuty * 0.01f) + 0.5f);

    /* Clamp to period to avoid overflow caused by rounding */
    dutyCycle = (dutyCycle <= period) ? dutyCycle : period;

    if (driver->synchronousUpdateEnabled == TRUE)
    {
        IfxEgtm_Tom_Ch_setCompareOneShadow(driver->tom, driver->tomChannel, dutyCycle);
    }
    else
    {
        IfxEgtm_Tom_Ch_setCompareOne(driver->tom, driver->tomChannel, dutyCycle);
    }
}


IFX_INLINE void IfxEgtm_Tom_Pwm_setFrequency(IfxEgtm_Tom_Pwm_Driver *driver, float32 requestFrequency)
{
    uint16 currentPeriod, currentDutyCycle;
    uint16 updatedPeriod, updatedDutyCycle;
    uint32 tempPeriod;
    float32 clkHz;

    /* Handle invalid requestFrequency */
    if (requestFrequency <= 0.0f)
    {
        return;
    }

    /* Use configured period and dutyCycle value according to selected update mode */
    if (driver->synchronousUpdateEnabled == TRUE)
    {
        currentPeriod    = IfxEgtm_Tom_Ch_getCompareZeroShadow(driver->tom, driver->tomChannel);
        currentDutyCycle = IfxEgtm_Tom_Ch_getCompareOneShadow(driver->tom, driver->tomChannel);
    }
    else
    {
        currentPeriod    = (uint16)IfxEgtm_Tom_Ch_getCompareZero(driver->tom, driver->tomChannel);
        currentDutyCycle = (uint16)IfxEgtm_Tom_Ch_getCompareOne(driver->tom, driver->tomChannel);
    }

    /* Invalid stored period ? cannot compute ratio */
    if (currentPeriod == 0u)
    {
        return;
    }

    /* Channel-effective TOM clock frequency */
    clkHz = IfxEgtm_Tom_Ch_getClockFrequency(driver->egtm, driver->tom, driver->tomChannel);

    /* Compute new period using 32-bit arithmetic to avoid overflow */
    tempPeriod = (uint32)((clkHz / requestFrequency) + 0.5f);

    if (tempPeriod == 0u)
    {
        tempPeriod = 1u;
    }
    else if (tempPeriod > 0xFFFFu)
    {
        /* Clamp to 16-bit valid range */
        tempPeriod = 0xFFFFu;
    }

    updatedPeriod = (uint16)tempPeriod;

    /* Preserve existing duty ratio: updatedDutyCycle/updatedPeriod ~= currentDutyCycle/currentPeriod */
    updatedDutyCycle = (uint16)((((uint32)currentDutyCycle * (uint32)updatedPeriod) + ((uint32)currentPeriod / 2)) / (uint32)currentPeriod);

    /* Clamp to period to avoid overflow caused by rounding */
    updatedDutyCycle = (updatedDutyCycle <= updatedPeriod) ? updatedDutyCycle : updatedPeriod;

    /* Apply updated period and duty cycle */
    if (driver->synchronousUpdateEnabled == TRUE)
    {
        IfxEgtm_Tom_Ch_setCompareZeroShadow(driver->tom, driver->tomChannel, updatedPeriod);
        IfxEgtm_Tom_Ch_setCompareOneShadow(driver->tom, driver->tomChannel, updatedDutyCycle);
    }
    else
    {
        IfxEgtm_Tom_Ch_setCompareZero(driver->tom, driver->tomChannel, updatedPeriod);
        IfxEgtm_Tom_Ch_setCompareOne(driver->tom, driver->tomChannel, updatedDutyCycle);
    }
}


#endif /* IFXEGTM_TOM_PWM_H */
