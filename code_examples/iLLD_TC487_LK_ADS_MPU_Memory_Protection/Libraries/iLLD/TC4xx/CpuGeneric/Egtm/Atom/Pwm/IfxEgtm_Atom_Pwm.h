/**
 * \file IfxEgtm_Atom_Pwm.h
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
 * \defgroup IfxLld_Egtm_Atom_Pwm_Usage How to use the EGTM ATOM PWM Driver
 * \ingroup IfxLld_Egtm_Atom_Pwm
 *
 * This interface allows to generate PWM signal using ATOM submodule of eGTM. User can configure the required frequency and duty cycle of the signal.
 *
 * Functionalities provided:
 *     -# Users can choose cluster and channel number of ATOM
 *     -# Period and duty cycle can be provided in ticks
 *     -# Signal level during duty cycle can be configured
 *     -# Interrupt can be generated at CCU0 (period event) and/or CCU1 (duty event) match
 *     -# PWM can be routed to Pin using TOUT and also to HRPWM (if available)
 *     -# Channel can be connected to MSC
 *     -# High resolution support (midro steps and high resoultion channel) (if available)
 *     -# CM0/CM1 registers can be updated with SR0/SR1 at end of period (synchronousUpdateEnabled)
 *     -# Users can choose to start PWM at end of init (immediateStartEnabled)
 *
 * \section Preparation Preparation
 * \subsection Include Include Files
 *
 * Include following header file into your C code:
 * \code
 *     #include "Egtm/Atom/Pwm/IfxEgtm_Atom_Pwm.h"
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
 *     #define ATOM0_CH0_PRIO 20
 *     \endcode
 *
 * \subsection Interrupts Interrupts
 * Define Interrupts if needed
 *
 * \code
 * IFX_INTERRUPT(ATOM0Ch0_ISR, 0, ATOM0_CH0_PRIO)
 * {
 *     // user code
 * }
 * \endcode
 *
 * \subsection Initialization Initialization
 *
 *     \code
 *     // 1. [Optional] Install interrupt handlers
 *     IfxCpu_Irq_installInterruptHandler(ATOM0Ch0_ISR, ATOM0_CH0_PRIO);
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
 *         // FXCLK: used by TOM and CLK0: used by ATOM
 *         IfxEgtm_Cmu_enableClocks(egtm, IFXEGTM_CMU_CLKEN_FXCLK | IFXEGTM_CMU_CLKEN_CLK0);
 *     }
 *
 *     // 3. Instantiate variables
 *     IfxEgtm_Atom_Pwm_Config atomConfig; // Configuration structure
 *     IfxEgtm_Atom_Pwm_Driver atomHandle; // Handle
 *     IfxEgtm_MscOut           mscOut;     // MSC connection structure
 *
 *     // 4. Initialize with default values
 *     IfxEgtm_Atom_Pwm_initConfig(&atomConfig, egtm);
 *
 *     // 5. Manual Configuration
 *     atomConfig.cluster      = IfxEgtm_Cluster_0;    // ATOM Cluster
 *     atomConfig.atomChannel  = IfxEgtm_Atom_Ch_0;    // ATOM Channel
 *     atomConfig.mode         = IfxEgtm_Atom_Mode_outputPwm;  // Choose PWM mode. Only this mode is supported.
 *     atomConfig.period       = 20;                   // Period in ticks
 *     atomConfig.dutyCycle    = 10;                   // Duty cycle in ticks
 *     atomConfig.signalLevel  = Ifx_ActiveState_high; // Choose signal level during duty
 *     atomConfig.synchronousUpdateEnabled   = TRUE;   // Update CM0/CM1 registers from Shadow at end of period
 *     atomConfig.immediateStartEnabled      = TRUE;   // Start PWM at end of init
 *
 *     // 6. [Optional] Interrupt configuration
 *     atomConfig.interrupt.ccu0Enabled = TRUE;
 *     atomConfig.interrupt.isrPriority = ATOM0_CH0_PRIO;
 *
 *     // 7. [Optional] Output Pin connection
 *     atomConfig.pin.outputPin  = &IfxEgtm_ATOM0_0_TOUT0_P02_0_OUT;
 *     atomConfig.pin.outputMode = IfxPort_OutputMode_pushPull;
 *     atomConfig.pin.padDriver  = IfxPort_PadDriver_cmosAutomotiveSpeed1;
 *
 *     // 8. [Optional] High Res (HRPWM) Configuration. This option may not be present for all derivatives
 *     atomConfig.hrSupport      = TRUE;                               // Enable High res
 *     atomConfig.hrChannel      = IfxEgtm_Hrpwm_Ch_0;                 // Choose high res channel
 *     atomConfig.hrStepsPeriod  = 16;                                 // Choose micro steps
 *     atomConfig.hrStepsDuty    = 1;                                  // Choose micro steps
 *     atomConfig.pin.hrpwmPin   = &IfxEgtm_HRPWM0_CH0_F_P02_0_OUT;    // Connect HRPWM Pin
 *
 *     // 9. [Optional] MSC Connection: Configure the structure mscOut as per the requirement.
 *     // During the Pwm init, Msc connection will be established with the configured channel by API call to IfxGtm_ConnectToMsc.
 *     mscOut.mscSet       = IfxEgtm_Cfg_MscSet_0;
 *     mscOut.mscSetSignal = IfxEgtm_Cfg_MscSetSignal_0;
 *     mscOut.mscModule    = IfxEgtm_Cfg_MscModule_0;
 *     mscOut.mscAltIn     = IfxEgtm_MscAltInput_low;
 *     atomConfig.mscOut   = &mscOut;                  // Attach to config
 *
 *     // 10. Call the init functions
 *     IfxEgtm_Atom_Pwm_init(&atomHandle, &atomConfig);
 *     \endcode
 *
 * ATOM will be now generating a PWM signal on the selected port pin while generating selected interrupt according to above configured period and duty cycle.
 *
 * \subsection RunTime Run Time APIs
 *
 * To start the PWM, the following API can be called if channel was not started in init
 *
 *     \code
 *     // Start PWM immediately
 *     IfxEgtm_Atom_Pwm_start(&atomHandle, TRUE);
 *     \endcode
 *
 * To stop the PWM, call this API
 *
 *     \code
 *     // Stop PWM immediately
 *     IfxEgtm_Atom_Pwm_stop(&atomHandle, TRUE);
 *     \endcode
 *
 * To update micro steps of HRPWM, call this API (if available in derivative)
 *
 *     \code
 *     uint8                       hrSteps     = 10;
 *     IfxEgtm_Atom_Pwm_HrstepType hrstepType  = IfxEgtm_Atom_Pwm_HrstepType_period;
 *
 *     // Call the API
 *     IfxEgtm_Atom_Pwm_updateHrsteps(&atomHandle, hrSteps, hrstepType);
 *     \endcode
 *
 * \defgroup IfxLld_Egtm_Atom_Pwm Atom PWM Interface Driver
 * \ingroup IfxLld_Egtm_Atom
 * \defgroup IfxLld_Egtm_Atom_Pwm_Structures ATOM PWM Structures
 * \ingroup IfxLld_Egtm_Atom_Pwm
 * \defgroup IfxLld_Egtm_Atom_Pwm_Functions ATOM PWM Functions
 * \ingroup IfxLld_Egtm_Atom_Pwm
 * \defgroup IfxLld_Egtm_Atom_Pwm_Enumerations ATOM PWM Enumerations
 * \ingroup IfxLld_Egtm_Atom_Pwm
 */

#ifndef IFXEGTM_ATOM_PWM_H
#define IFXEGTM_ATOM_PWM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_PinMap/IfxEgtm_PinMap.h"
#include "Egtm/Std/IfxEgtm_Atom.h"
#include "Egtm/Std/IfxEgtm_Cmu.h"
#include "Egtm/Std/IfxEgtm_Dtm.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Hrstep Bits length
 */
#define IFXEGTM_ATOM_PWM_HR_STEP_LENGTH (5)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Egtm_Atom_Pwm_Enumerations
 * \{ */
/** \brief Enum for High resolution step
 */
typedef enum
{
    IfxEgtm_Atom_Pwm_HrstepType_period    = 0, /**< \brief Period */
    IfxEgtm_Atom_Pwm_HrstepType_dutyCycle = 1  /**< \brief Duty Cycle */
} IfxEgtm_Atom_Pwm_HrstepType;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Egtm_Atom_Pwm_Structures
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
} IfxEgtm_Atom_Pwm_Interrupt;

/** \brief configuration structure for output pin
 */
typedef struct
{
    IfxEgtm_Atom_ToutMap *outputPin;        /**< \brief Output pin */
    IfxPort_OutputMode    outputMode;       /**< \brief Output mode */
    IfxPort_PadDriver     padDriver;        /**< \brief Pad driver */
#if IFXEGTM_PWM_IS_HIGH_RES_AVAILABLE	
    IfxEgtm_Hrpwm_Out    *hrpwmPin;         /**< \brief HRPWM pin */
#endif	/* #if IFXEGTM_PWM_IS_HIGH_RES_AVAILABLE */	
} IfxEgtm_Atom_Pwm_pin;

/** \} */

/** \addtogroup IfxLld_Egtm_Atom_Pwm_Structures
 * \{ */
/** \brief Configuration structure
 */
typedef struct
{
    Ifx_EGTM                  *egtm;                           /**< \brief Pointer to EGTM module */
    IfxEgtm_Cluster            cluster;                        /**< \brief Cluster of ATOM channel to be used */
    IfxEgtm_Atom_Ch            atomChannel;                    /**< \brief ATOM channel to be used for PWM */
    IfxEgtm_Atom_Ch_ClkSrc     clock;                          /**< \brief Clock source for selected ATOM channel */
    IfxEgtm_Atom_Mode          mode;                           /**< \brief Mode of operation of ATOM channel. Only PWM is supported */
    uint32                     period;                         /**< \brief Period in ticks. Range: 0 to 0x00FFFFFF */
    uint32                     dutyCycle;                      /**< \brief Duty Cycle in ticks. Range: 0 to 0x00FFFFFF */
    Ifx_ActiveState            signalLevel;                    /**< \brief Signal Level when duty is active */
    IfxEgtm_Atom_Pwm_Interrupt interrupt;                      /**< \brief Configuration structure for interrupt */
    IfxEgtm_Atom_Pwm_pin       pin;                            /**< \brief Configuration structure for output pin */
    IfxEgtm_MscOut            *mscOut;                         /**< \brief MSC configuration */
    IfxEgtm_Dtm_ClockSource    dtmClockSource;                 /**< \brief DTM clock source */
    boolean                    oneShotModeEnabled;             /**< \brief Enable/Disable the one shot mode (Currently, has no effect) */
    boolean                    synchronousUpdateEnabled;       /**< \brief Synchronous or Asynchronous update. TRUE: Update compare registers from shadow at the end of period */
    boolean                    immediateStartEnabled;          /**< \brief Enable immediate start after init. TRUE: Start channel at end of init */
#if IFXEGTM_PWM_IS_HIGH_RES_AVAILABLE	
    boolean                    hrSupport;                      /**< \brief Enable/Disable the High resolution support for ATOM */
    IfxEgtm_Hrpwm_Ch           hrChannel;                      /**< \brief HRPWM channel used */
    uint8                      hrStepsPeriod;                  /**< \brief HRPWM micro step Period. Range: 0 to 0x20 */
    uint8                      hrStepsDuty;                    /**< \brief HRPWM micro step Duty CycleRange. Range: 0 to 0x20 */
#endif	
} IfxEgtm_Atom_Pwm_Config;

/** \brief Driver Handle
 */
typedef struct
{
    Ifx_EGTM              *egtm;                           /**< \brief Pointer to EGTM module */
    IfxEgtm_Cluster        clsIndex;                       /**< \brief Index of the CLS object used */
    IfxEgtm_Atom_Ch        atomChannel;                    /**< \brief ATOM channel used for the PWM */
    Ifx_EGTM_CLS_ATOM     *atom;                           /**< \brief Pointer to the ATOM object */
    Ifx_EGTM_CLS_ATOM_AGC *agc;                            /**< \brief Pointer to the AGC object */
    IfxEgtm_Atom_Mode      mode;                           /**< \brief Atom mode of operation */
    Ifx_EGTM_CLS_CDTM_DTM *dtm;                            /**< \brief Pointer to DTM module */
    IfxEgtm_Dtm_Ch         dtmChannel;                     /**< \brief DTM channel used for HRPWM */
    boolean                synchronousUpdateEnabled;       /**< \brief Synchronous update enabled/disabled */
#if IFXEGTM_PWM_IS_HIGH_RES_AVAILABLE	
    boolean                hrSupport;                      /**< \brief Enable/Disable the High resolution support for ATOM */
    IfxEgtm_Hrpwm_Ch       hrChannel;                      /**< \brief HRPWM channel used */
#endif	/* #if IFXEGTM_PWM_IS_HIGH_RES_AVAILABLE */
} IfxEgtm_Atom_Pwm_Driver;

/** \} */

/** \addtogroup IfxLld_Egtm_Atom_Pwm_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief initializes the Timer object
 *
 * \param[inout] driver ATOM Handle
 * \param[in]    config Configuration structure for ATOM
 *
 * \retval TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxEgtm_Atom_Pwm_init(IfxEgtm_Atom_Pwm_Driver *driver, const IfxEgtm_Atom_Pwm_Config *config);

/** \brief Initializes the configuration structure to default
 *
 * \param[inout] config This parameter is initialized by the function
 * \param[in]    egtm   Pointer to EGTM module
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Atom_Pwm_initConfig(IfxEgtm_Atom_Pwm_Config *config, Ifx_EGTM *egtm);

/** \brief Starts the PWM generation from the configured channel.
 *
 * \param[inout] driver    Handle for the PWM device.
 * \param[in]    immediate Immediate start or not.
 *                         Range: TRUE: Immediate start FALSE: No Immediate start
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Atom_Pwm_start(IfxEgtm_Atom_Pwm_Driver *driver, boolean immediate);

/** \brief Stops the PWM generation from the configured channel
 *
 * \param[inout] driver    Handle for the PWM device
 * \param[in]    immediate Immediate start or not.
 *                         Range: TRUE: Immediate start FALSE: No Immediate start
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Atom_Pwm_stop(IfxEgtm_Atom_Pwm_Driver *driver, boolean immediate);

#if IFXEGTM_PWM_IS_HIGH_RES_AVAILABLE
/** \brief This API updates the micro steps of period/duty during run time
 *
 * \param[inout] driver     ATOM Handle
 * \param[in]    hrSteps    High resolution step value
 *                          Range: 0 to 0xF.
 * \param[in]    hrStepType High resolution step is for Period/Duytcycle
 *                          Range: \ref: IfxEgtm_Atom_Pwm_HrstepType
 *
 * \retval None
 */
IFX_EXTERN void IfxEgtm_Atom_Pwm_updateHrsteps(IfxEgtm_Atom_Pwm_Driver *driver, uint8 hrSteps, IfxEgtm_Atom_Pwm_HrstepType hrStepType);
#endif	/* #if IFXEGTM_PWM_IS_HIGH_RES_AVAILABLE */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Updates PWM duty cycle
 *
 * \param[inout] driver      ATOM Handle
 * \param[in]    requestDuty Requested duty in %
 *                           Range: 0.0 to 100.0
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Atom_Pwm_setDuty(IfxEgtm_Atom_Pwm_Driver *driver, float32 requestDuty);

/** \brief Update PWM frequency.
 *  Duty-cycle count is scaled automatically to preserve existing duty cycle.
 *
 * \param[inout] driver           ATOM Handle.
 * \param[in]    requestFrequency New frequency in Hz (> 0). (if <= 0, function call returns without updating frequency).
 */
IFX_INLINE void IfxEgtm_Atom_Pwm_setFrequency(IfxEgtm_Atom_Pwm_Driver *driver, float32 requestFrequency);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxEgtm_Atom_Pwm_setDuty(IfxEgtm_Atom_Pwm_Driver *driver, float32 requestDuty)
{
    uint32 period;
    uint32 dutyCycle;

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
    	period = IfxEgtm_Atom_Ch_getCompareZeroShadow(driver->atom, driver->atomChannel);
    }
    else
    {
        period = IfxEgtm_Atom_Ch_getCompareZero(driver->atom, driver->atomChannel);
    }

    /* Duty in ticks = period * (requestDuty in percent / 100%) */
    dutyCycle = (uint32)(((float32)period * requestDuty * 0.01f) + 0.5f);

    /* Clamp to period to avoid overflow caused by rounding */
    dutyCycle = (dutyCycle <= period) ? dutyCycle : period;

    if (driver->synchronousUpdateEnabled == TRUE)
    {
        IfxEgtm_Atom_Ch_setCompareOneShadow(driver->atom, driver->atomChannel, dutyCycle);
    }
    else
    {
        IfxEgtm_Atom_Ch_setCompareOne(driver->atom, driver->atomChannel, dutyCycle);
    }
}


IFX_INLINE void IfxEgtm_Atom_Pwm_setFrequency(IfxEgtm_Atom_Pwm_Driver *driver, float32 requestFrequency)
{
    uint32 currentPeriod, currentDutyCycle;
    uint32 updatedPeriod, updatedDutyCycle;
    float32 clkHz;

    /* Handle invalid requestFrequency */
    if (requestFrequency <= 0.0f)
    {
        return;
    }

    /* Use configured period and dutyCycle value according to selected update mode */
    if (driver->synchronousUpdateEnabled == TRUE)
    {
        currentPeriod    = IfxEgtm_Atom_Ch_getCompareZeroShadow(driver->atom, driver->atomChannel);
        currentDutyCycle = IfxEgtm_Atom_Ch_getCompareOneShadow(driver->atom, driver->atomChannel);
    }
    else
    {
        currentPeriod    = IfxEgtm_Atom_Ch_getCompareZero(driver->atom, driver->atomChannel);
        currentDutyCycle = IfxEgtm_Atom_Ch_getCompareOne(driver->atom, driver->atomChannel);
    }

    /* Invalid stored period ? cannot compute ratio */
    if (currentPeriod == 0u)
    {
        return;
    }

    /* Channel-effective ATOM clock frequency */
    clkHz = IfxEgtm_Atom_Ch_getClockFrequency(driver->egtm, driver->atom, driver->atomChannel);

    /* Recompute new period from requested frequency */
    updatedPeriod = (uint32)((clkHz / requestFrequency) + 0.5f);

    if (updatedPeriod == 0u)
    {
        updatedPeriod = 1u;
    }
    else if (updatedPeriod > 0x00FFFFFFu)
    {
    	/* Clamp to 24-bit ATOM register range */
        updatedPeriod = 0x00FFFFFFu;
    }

    /* Preserve existing duty ratio: updatedDutyCycle/updatedPeriod ~= currentDutyCycle/currentPeriod */
    updatedDutyCycle = (uint32)((((uint64)currentDutyCycle * (uint64)updatedPeriod) + ((uint64)currentPeriod / 2)) / (uint64)currentPeriod);

    /* Clamp to period to avoid overflow caused by rounding */
    updatedDutyCycle = (updatedDutyCycle <= updatedPeriod) ? updatedDutyCycle : updatedPeriod;

    /* Apply updated period and duty cycle */
    if (driver->synchronousUpdateEnabled == TRUE)
    {
        IfxEgtm_Atom_Ch_setCompareZeroShadow(driver->atom, driver->atomChannel, updatedPeriod);
        IfxEgtm_Atom_Ch_setCompareOneShadow(driver->atom, driver->atomChannel, updatedDutyCycle);
    }
    else
    {
        IfxEgtm_Atom_Ch_setCompareZero(driver->atom, driver->atomChannel, updatedPeriod);
        IfxEgtm_Atom_Ch_setCompareOne(driver->atom, driver->atomChannel, updatedDutyCycle);
    }
}


#endif /* IFXEGTM_ATOM_PWM_H */
