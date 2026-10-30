/**
 * \file IfxGtm_Atom_Pwm.h
 * \brief GTM PWM details
 * \ingroup IfxLld_Gtm
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
 * \defgroup IfxLld_Gtm_Atom_Pwm_Usage How to use the GTM ATOM PWM Driver
 * \ingroup IfxLld_Gtm_Atom_Pwm
 *
 * This interface allows to generate simple PWM signal on a ATOM out put and can generate interrupts if enabled.
 * this output can also be routed to port pin if required.
 *
 * \section Preparation Preparation
 * \subsection Include Include Files
 *
 * Include following header file into your C code:
 * \code
 *     #include <Gtm/Atom/Pwm/IfxGtm_Atom_Pwm.h>
 * \endcode
 *
 * \subsection Variables Variables
 * define global variables if necessary
 *
 * \code
 * Ifx_GTM *gtm = &MODULE_GTM;
 * #define ATOM0_CH0_PRIO 20
 * \endcode
 *
 * \subsection Interrupts Interrupts
 * define Interrupts if needed
 *
 * \code
 * IFX_INTERRUPT(ATOM0Ch0_ISR, 0, ATOM0_CH0_PRIO)
 * {}
 * \endcode
 *
 * \subsection Initialization Initialization
 *
 * \code
 * // install interrupt handlers
 * IfxCpu_Irq_installInterruptHandler (ATOM0Ch0_ISR, ATOM0_CH0_PRIO);
 *
 * // enable GTM clock
 * {
 *     float32 frequency = IfxGtm_Cmu_getModuleFrequency(gtm);
 *     // Enables the GTM
 *     IfxGtm_enable(gtm);
 *     // Set the global clock frequency to the max
 *     IfxGtm_Cmu_setGclkFrequency(gtm, frequency);
 *     // Set the CMU CLK0
 *     IfxGtm_Cmu_setClkFrequency(gtm, IfxGtm_Cmu_Clk_0, frequency);
 *     // FXCLK: used by TOM and CLK0: used by ATOM
 *     IfxGtm_Cmu_enableClocks(gtm, IFXGTM_CMU_CLKEN_FXCLK | IFXGTM_CMU_CLKEN_CLK0);
 * }
 *
 * // initialise ATOM
 * IfxGtm_Atom_Pwm_Config atomConfig;	\\configuration structure
 * IfxGtm_Atom_Pwm_Driver atomHandle;	\\ handle
 *
 * IfxGtm_Atom_Pwm_initConfig(&atomConfig, gtm);
 *
 * atomConfig.tomChannel  = IfxGtm_Tom_Ch_0;
 * atomConfig.period                   = 20;
 * atomConfig.dutyCycle              = 10;
 * atomConfig.interrupt.ccu0Enabled = TRUE;
 * atomConfig.interrupt.isrPriority = ATOM0_CH0_PRIO;
 * atomConfig.pin.outputPin = &IfxGtm_ATOM0_0_TOUT0_P02_0_OUT;
 *
 * IfxGtm_Atom_Pwm_init(&atomHandle, &atomConfig);
 * \endcode
 *
 * ATOM will be now generating a PWM signal on the selected port pin while generating selected interrupt according to above configured period and duty cycle.
 *
 * \defgroup IfxLld_Gtm_Atom_Pwm ATOM PWM Interface Driver
 * \ingroup IfxLld_Gtm_Atom
 * \defgroup IfxLld_Gtm_Atom_Pwm_DataStructures ATOM PWM DataStructures
 * \ingroup IfxLld_Gtm_Atom_Pwm
 * \defgroup IfxLld_Gtm_Atom_Pwm_Pwm_Functions Pwm Functions
 * \ingroup IfxLld_Gtm_Atom_Pwm
 */

#ifndef IFXGTM_ATOM_PWM_H
#define IFXGTM_ATOM_PWM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_PinMap/IfxGtm_PinMap.h"
#include "Gtm/Std/IfxGtm_Atom.h"
#include "Gtm/Std/IfxGtm_Cmu.h"
#include "Gtm/Std/IfxGtm_Dtm.h"
#include "Cpu/Std/IfxCpu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Atom_Pwm_DataStructures
 * \{ */
/** \brief configuration structure for interrupts
 */
typedef struct
{
    boolean        ccu0Enabled;       /**< \brief Enable/Disable choice for CCU0 trigger interrupt */
    boolean        ccu1Enabled;       /**< \brief Enable/Disable choice for CCU1 trigger interrupt */
    IfxGtm_IrqMode mode;              /**< \brief IRQ mode of interrupt */
    IfxSrc_Tos     isrProvider;       /**< \brief Type of Service for Ccu0/1 interrupt */
    Ifx_Priority   isrPriority;       /**< \brief Priority for Ccu0/1 interrupt. Range 0 to 255 */
} IfxGtm_Atom_Pwm_Interrupt;

/** \brief configuration structure for output pin
 */
typedef struct
{
    IfxGtm_Atom_ToutMap *outputPin;        /**< \brief output pin */
    IfxPort_OutputMode   outputMode;       /**< \brief Output mode */
    IfxPort_PadDriver    padDriver;        /**< \brief Pad driver */
} IfxGtm_Atom_Pwm_pin;

/** \} */

/** \addtogroup IfxLld_Gtm_Atom_Pwm_DataStructures
 * \{ */
/** \brief Configuration structure
 */
typedef struct
{
    Ifx_GTM                  *gtm;                            /**< \brief Pointer to GTM module */
    IfxGtm_Atom               atom;                           /**< \brief Index of the ATOM object used */
    IfxGtm_Atom_Ch            atomChannel;                    /**< \brief ATOM channel used for the timer */
    IfxGtm_Cmu_Clk			  clock;						  /**< \brief Timer input clock */
    IfxGtm_Atom_Mode          mode;                           /**< \brief Atom mode of operation */
    uint32                    period;                         /**< \brief Period. Range: 0 to 0x00FFFFFF */
    uint32                    dutyCycle;                      /**< \brief Duty Cycle. Range: 0 to 0x00FFFFFF */
    Ifx_ActiveState           signalLevel;                    /**< \brief Signal Level */
    boolean                   oneShotModeEnabled;             /**< \brief Enable/Disable the one shot mode */
    IfxGtm_Dtm_ClockSource    dtmClockSource;                 /**< \brief DTM clock source */
    boolean                   synchronousUpdateEnabled;       /**< \brief Synchronous or Asynchronous update */
    boolean                   immediateStartEnabled;          /**< \brief enable immediate start after init */
    IfxGtm_Atom_Pwm_Interrupt interrupt;                      /**< \brief configuration structure for interrupt */
    IfxGtm_Atom_Pwm_pin       pin;                            /**< \brief configuration structure for output pin */
} IfxGtm_Atom_Pwm_Config;

/** \brief Driver Handle
 */
typedef struct
{
    Ifx_GTM          *gtm;               		 /**< \brief Pointer to GTM module */
    IfxGtm_Atom       atomIndex;         		 /**< \brief Index of the ATOM object used */
    IfxGtm_Atom_Ch    atomChannel;       		 /**< \brief ATOM channel used for the timer */
    Ifx_GTM_ATOM     *atom;              		 /**< \brief Pointer to the ATOM object */
    Ifx_GTM_ATOM_AGC *agc;               		 /**< \brief Pointer to the AGC object */
    IfxGtm_Atom_Mode  mode;                      /**< \brief Atom mode of operation */
    boolean           synchronousUpdateEnabled;  /**< \brief Synchronous or Asynchronous update */
} IfxGtm_Atom_Pwm_Driver;

/** \} */

/** \addtogroup IfxLld_Gtm_Atom_Pwm_Pwm_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the GTM ATOM PWM driver object with the specified configuration.
 *
 * This function sets up the PWM timer using the provided driver handle and configuration.
 * It configures the GTM module, ATOM object, and channel according to the parameters
 * specified in the configuration structure.
 *
 * \param[inout] driver Pointer to GTM ATOM PWM driver object to be initialized. This structure contains
 *                      pointers to the GTM module, ATOM object, and channel, along with mode
 *                      information.
 * \param[in]    config Constant pointer to the PWM timer configuration structure. This
 *             		   structure includes parameters such as clock source, mode, period, duty
 *            		   cycle, signal level, and other control flags.
 *
 * \retval TRUE If the initialization was successful.
 *         FALSE If the initialization failed.
 */
IFX_EXTERN boolean IfxGtm_Atom_Pwm_init(IfxGtm_Atom_Pwm_Driver *driver, const IfxGtm_Atom_Pwm_Config *config);

/**
 * \brief Initializes the configuration structure for the GTM ATOM PWM module to default values.
 *
 * This function sets up the provided configuration structure with default values suitable for
 * initializing the GTM ATOM PWM module. The configuration structure includes parameters such as
 * the timer input clock, mode of operation, period, duty cycle, signal level, and other control
 * flags for features like one-shot mode and synchronous updates.
 *
 * \param[inout] config The configuration structure to be initialized. This structure contains
 *                      various fields that define the operational parameters of the GTM ATOM
 *                      PWM module, such as the timer input clock, mode, period, duty cycle, and
 *                      control flags.
 * \param[in]    gtm    Pointer to the GTM module instance to be used for configuration.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Pwm_initConfig(IfxGtm_Atom_Pwm_Config *config, Ifx_GTM *gtm);

/**
 * \brief Starts the PWM generation from the configured channel.
 *
 * This function starts the PWM (Pulse Width Modulation) generation
 * using the provided driver handle. The PWM generation can be started immediately
 * or synchronized based on the 'immediate' parameter.
 *
 * \param[inout] driver    Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    immediate Boolean flag indicating whether to start the PWM generation
 *                         immediately (TRUE) or wait for synchronization (FALSE).
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Pwm_start(IfxGtm_Atom_Pwm_Driver *driver, boolean immediate);

/**
 * \brief Stops the PWM generation from the configured channel.
 *
 * This function halts the PWM (Pulse Width Modulation) signal generation on the specified channel.
 * The 'immediate' parameter determines whether the stop should occur immediately or after the current PWM cycle completes.
 *
 * \param[inout] driver    Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    immediate Boolean flag to specify the stopping behavior.
 *						   Range:	
 * 						   - TRUE: Stop the PWM generation immediately.
 * 						   - FALSE: Stop the PWM generation after the current cycle completes.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Pwm_stop(IfxGtm_Atom_Pwm_Driver *driver, boolean immediate);

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Updates PWM duty cycle.
 *
 * \param[inout] driver      Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    requestDuty Requested duty cycle in percent. Range: 0.0 to 100.0.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Atom_Pwm_setDuty(IfxGtm_Atom_Pwm_Driver *driver, float32 requestDuty);

/** \brief Update PWM frequency.
 *  Duty-cycle count is scaled automatically to preserve existing duty cycle.
 *
 * \param[inout] driver           Pointer to the GTM ATOM PWM driver handle.
 * \param[in]    requestFrequency New frequency in Hz (> 0). (if <= 0, function call returns without updating frequency).
 */
IFX_INLINE void IfxGtm_Atom_Pwm_setFrequency(IfxGtm_Atom_Pwm_Driver *driver, float32 requestFrequency);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Atom_Pwm_setDuty(IfxGtm_Atom_Pwm_Driver *driver, float32 requestDuty)
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
        period = IfxGtm_Atom_getShadowZero(driver->atom, driver->atomChannel);
    }
    else
    {
        period = IfxGtm_Atom_Ch_getCompareZero(driver->atom, driver->atomChannel);
    }

    /* Duty in ticks = period * (requestDuty in percent / 100%) */
    dutyCycle = (uint32)((((float32)period * requestDuty) * 0.01f) + 0.5f);

    /* Clamp to period to avoid overflow caused by rounding */
    dutyCycle = (dutyCycle <= period) ? dutyCycle : period;

    if (driver->synchronousUpdateEnabled == TRUE)
    {
    	IfxGtm_Atom_Agc_enableChannelUpdate(driver->agc, driver->atomChannel, FALSE);
        IfxGtm_Atom_Ch_setCompareOneShadow(driver->atom, driver->atomChannel, dutyCycle);
        IfxGtm_Atom_Agc_enableChannelUpdate(driver->agc, driver->atomChannel, TRUE);
    }
    else
    {
        IfxGtm_Atom_Ch_setCompareOne(driver->atom, driver->atomChannel, dutyCycle);
    }
}


IFX_INLINE void IfxGtm_Atom_Pwm_setFrequency(IfxGtm_Atom_Pwm_Driver *driver, float32 requestFrequency)
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
        currentPeriod    = IfxGtm_Atom_getShadowZero(driver->atom, driver->atomChannel);
        currentDutyCycle = IfxGtm_Atom_getShadowOne(driver->atom, driver->atomChannel);
    }
    else
    {
        currentPeriod    = IfxGtm_Atom_Ch_getCompareZero(driver->atom, driver->atomChannel);
        currentDutyCycle = IfxGtm_Atom_Ch_getCompareOne(driver->atom, driver->atomChannel);
    }

    /* Invalid stored period ? cannot compute ratio */
    if (currentPeriod == 0u)
    {
        return;
    }

    /* Channel-effective ATOM clock frequency */
    clkHz = IfxGtm_Atom_Ch_getClockFrequency(driver->gtm, driver->atom, driver->atomChannel);

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
    	IfxGtm_Atom_Agc_enableChannelUpdate(driver->agc, driver->atomChannel, FALSE);
    	IfxGtm_Atom_Ch_setCompareZeroShadow(driver->atom, driver->atomChannel, updatedPeriod);
    	IfxGtm_Atom_Ch_setCompareOneShadow(driver->atom, driver->atomChannel, updatedDutyCycle);
    	IfxGtm_Atom_Agc_enableChannelUpdate(driver->agc, driver->atomChannel, TRUE);
    }
    else
    {
        IfxGtm_Atom_Ch_setCompareZero(driver->atom, driver->atomChannel, updatedPeriod);
        IfxGtm_Atom_Ch_setCompareOne(driver->atom, driver->atomChannel, updatedDutyCycle);
    }
}


#endif /* IFXGTM_ATOM_PWM_H */
