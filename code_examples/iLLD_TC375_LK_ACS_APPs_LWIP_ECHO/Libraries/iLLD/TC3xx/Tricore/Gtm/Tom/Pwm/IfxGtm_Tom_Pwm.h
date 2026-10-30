/**
 * \file IfxGtm_Tom_Pwm.h
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
 * \defgroup IfxLld_Gtm_Tom_Pwm_Usage How to use the GTM TOM PWM Driver
 * \ingroup IfxLld_Gtm_Tom_Pwm
 *
 * This interface allows to generate simple PWM signal on a TOM out put and can generate interrupts if enabled.
 * this output can also be routed to port pin if required.
 *
 * \section Preparation Preparation
 * \subsection Include Include Files
 *
 * Include following header file into your C code:
 * \code
 *     #include <Gtm/Tom/Pwm/IfxGtm_Tom_Pwm.h>
 * \endcode
 *
 * \subsection Variables Variables
 * define global variables if necessary
 *
 * \code
 * Ifx_GTM *gtm = &MODULE_GTM;
 * #define TOM0_CH0_PRIO 10
 * \endcode
 *
 * \subsection Interrupts Interrupts
 * define Interrupts if needed
 *
 * \code
 * IFX_INTERRUPT(TOM0Ch0_ISR, 0, TOM0_CH0_PRIO)
 * {}
 * \endcode
 *
 * \subsection Initialization Initialization
 *
 * \code
 * // install interrupt handlers
 * IfxCpu_Irq_installInterruptHandler (TOM0Ch0_ISR, TOM0_CH0_PRIO);
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
 * // initialise TOM
 * IfxGtm_Tom_Pwm_Config tomConfig;	\\configuration structure
 * IfxGtm_Tom_Pwm_Driver tomHandle;	\\ handle
 *
 * IfxGtm_Tom_Pwm_initConfig(&tomConfig, gtm);
 *
 * tomConfig.tomChannel  = IfxGtm_Tom_Ch_0;
 * tomConfig.period                   = 20;
 * tomConfig.dutyCycle              = 10;
 * tomConfig.interrupt.ccu0Enabled = TRUE;
 * tomConfig.interrupt.isrPriority = TOM0_CH0_PRIO;
 * tomConfig.pin.outputPin = &IfxGtm_TOM0_0_TOUT106_P10_4_OUT;
 *
 * IfxGtm_Tom_Pwm_init(&tomHandle, &tomConfig);
 * \endcode
 *
 * TOM will be now generating a PWM signal on the selected port pin while generating selected interrupt according to above configured period and duty cycle.
 *
 * \defgroup IfxLld_Gtm_Tom_Pwm TOM PWM Interface Driver
 * \ingroup IfxLld_Gtm_Tom
 * \defgroup IfxLld_Gtm_Tom_Pwm_DataStructures TOM PWM DataStructures
 * \ingroup IfxLld_Gtm_Tom_Pwm
 * \defgroup IfxLld_Gtm_Tom_Pwm_Pwm_Functions Pwm Functions
 * \ingroup IfxLld_Gtm_Tom_Pwm
 */

#ifndef IFXGTM_TOM_PWM_H
#define IFXGTM_TOM_PWM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_PinMap/IfxGtm_PinMap.h"
#include "Gtm/Std/IfxGtm_Tom.h"
#include "Gtm/Std/IfxGtm_Cmu.h"
#include "Gtm/Std/IfxGtm_Dtm.h"
#include "Cpu/Std/IfxCpu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Tom_Pwm_DataStructures
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
} IfxGtm_Tom_Pwm_Interrupt;

/** \} */

/** \brief configuration structure for output pin
 */
typedef struct
{
    IfxGtm_Tom_ToutMap *outputPin;        /**< \brief output pin */
    IfxPort_OutputMode  outputMode;       /**< \brief Output mode */
    IfxPort_PadDriver   padDriver;        /**< \brief Pad driver */
} IfxGtm_Tom_Pwm_pin;

/** \addtogroup IfxLld_Gtm_Tom_Pwm_DataStructures
 * \{ */
/** \brief Configuration structure
 */
typedef struct
{
    Ifx_GTM                 *gtm;                            /**< \brief Pointer to GTM module */
    IfxGtm_Tom               tom;                            /**< \brief Index of the TOM object used */
    IfxGtm_Tom_Ch            tomChannel;                     /**< \brief TOM channel used for the timer */
    IfxGtm_Tom_Ch_ClkSrc     clock;                          /**< \brief Timer input clock */
    uint16                   period;                         /**< \brief Period in ticks (TOM only supports 16 bits). Range: 0 to 0xFFFF */
    uint16                   dutyCycle;                      /**< \brief Duty Cycle in ticks (TOM only supports 16 bits). Range: 0 to 0xFFFF */
    Ifx_ActiveState          signalLevel;                    /**< \brief Signal Level */
    boolean                  oneShotModeEnabled;             /**< \brief Enable/Disable the one shot mode */
    IfxGtm_Dtm_ClockSource   dtmClockSource;                 /**< \brief DTM clock source */
    boolean                  synchronousUpdateEnabled;       /**< \brief Synchronous or Asynchronous update */
    IfxGtm_Tom_Pwm_Interrupt interrupt;                      /**< \brief configuration structure for interrupt */
    IfxGtm_Tom_Pwm_pin       pin;                            /**< \brief configuration structure for output pin */
    boolean                  immediateStartEnabled;          /**< \brief enable/disable immediate start of PWM */
} IfxGtm_Tom_Pwm_Config;

/** \brief Driver Handle
 */
typedef struct
{
    Ifx_GTM         *gtm;           		   /**< \brief Pointer to GTM module */
    IfxGtm_Tom       tomIndex;       		   /**< \brief Index of the TOM object used */
    IfxGtm_Tom_Ch    tomChannel;     		   /**< \brief TOM channel used for the timer */
    Ifx_GTM_TOM     *tom;              		   /**< \brief Pointer to the TOM object */
    Ifx_GTM_TOM_TGC *tgc;              		   /**< \brief Pointer to the TGC object */
    boolean          synchronousUpdateEnabled; /**< \brief Synchronous or Asynchronous update */
} IfxGtm_Tom_Pwm_Driver;

/** \} */

/** \addtogroup IfxLld_Gtm_Tom_Pwm_Pwm_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the Timer object for PWM functionality.
 *
 * This function configures and initializes the GTM TOM for PWM operations
 * based on the provided configuration. It sets up the necessary module pointers, clock sources,
 * period, duty cycle, and other specified parameters to prepare the timer for operation.
 *
 * \param[inout] driver    Pointer to the GTM TOM PWM driver handle.
 * \param[in]    config    Configuration structure for TOM Timer containing PWM-specific settings such as clock source,
 * 						   period, duty cycle, signal level, and other control parameters.
 *
 * \retval TRUE If initialization was successful.
 *         FALSE If initialization failed.
 */
IFX_EXTERN boolean IfxGtm_Tom_Pwm_init(IfxGtm_Tom_Pwm_Driver *driver, const IfxGtm_Tom_Pwm_Config *config);

/**
 * \brief Initializes the configuration structure to default values.
 *
 * This function sets up the configuration structure for the GTM TOM PWM module with default settings.
 * The configuration structure includes parameters for timer configuration, clock source, period, duty cycle,
 * signal level, and other control options.
 *
 * \param[inout] config Pointer to the configuration structure to be initialized.
 * \param[in]    gtm    Pointer to the GTM module instance.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Tom_Pwm_initConfig(IfxGtm_Tom_Pwm_Config *config, Ifx_GTM *gtm);

/**
 * \brief Starts the PWM generation from the configured channel.
 *
 * \param[inout] driver    Pointer to the GTM TOM PWM driver handle.
 * \param[in]    immediate Boolean flag to specify the start behavior. If true, starts the PWM generation immediately; if false, starts at the next trigger event.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Tom_Pwm_start(IfxGtm_Tom_Pwm_Driver *driver, boolean immediate);

/**
 * \brief Stops the PWM generation on the specified channel.
 *
 * \param[inout] driver    Pointer to the GTM TOM PWM driver handle.
 * \param[in]    immediate Boolean flag to specify the stopping behavior. If true, Stop the PWM generation immediately; if false, Stop after the current cycle.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Tom_Pwm_stop(IfxGtm_Tom_Pwm_Driver *driver, boolean immediate);

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Updates PWM duty cycle.
 *
 * \param[inout] driver      Pointer to the GTM TOM PWM driver handle.
 * \param[in]    requestDuty Requested duty cycle in percent. Range: 0.0 to 100.0.
 *
 * \retval None
 */
IFX_INLINE void IfxGtm_Tom_Pwm_setDuty(IfxGtm_Tom_Pwm_Driver *driver, float32 requestDuty);

/** \brief Update PWM frequency.
 *  Duty-cycle count is scaled automatically to preserve existing duty cycle.
 *
 * \param[inout] driver           Pointer to the GTM TOM PWM driver handle.
 * \param[in]    requestFrequency New frequency in Hz (> 0). (if <= 0, function call returns without updating frequency).
 */
IFX_INLINE void IfxGtm_Tom_Pwm_setFrequency(IfxGtm_Tom_Pwm_Driver *driver, float32 requestFrequency);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Tom_Pwm_setDuty(IfxGtm_Tom_Pwm_Driver *driver, float32 requestDuty)
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
        period = IfxGtm_Tom_getShadowZero(driver->tom, driver->tomChannel);
    }
    else
    {
        period = (uint16)IfxGtm_Tom_Ch_getCompareZero(driver->tom, driver->tomChannel);
    }

    /* Duty in ticks = period * (requestDuty in percent / 100%) */
    dutyCycle = (uint16)((((float32)period * requestDuty) * 0.01f) + 0.5f);

    /* Clamp to period to avoid overflow caused by rounding */
    dutyCycle = (dutyCycle <= period) ? dutyCycle : period;

    if (driver->synchronousUpdateEnabled == TRUE)
    {
        IfxGtm_Tom_Tgc_enableChannelUpdate(driver->tgc, driver->tomChannel, FALSE);
        IfxGtm_Tom_Ch_setCompareOneShadow(driver->tom, driver->tomChannel, dutyCycle);
        IfxGtm_Tom_Tgc_enableChannelUpdate(driver->tgc, driver->tomChannel, TRUE);
    }
    else
    {
        IfxGtm_Tom_Ch_setCompareOne(driver->tom, driver->tomChannel, dutyCycle);
    }
}


IFX_INLINE void IfxGtm_Tom_Pwm_setFrequency(IfxGtm_Tom_Pwm_Driver *driver, float32 requestFrequency)
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
        currentPeriod    =  IfxGtm_Tom_getShadowZero(driver->tom, driver->tomChannel);
        currentDutyCycle =  IfxGtm_Tom_getShadowOne(driver->tom, driver->tomChannel);
    }
    else
    {
        currentPeriod     = (uint16)IfxGtm_Tom_Ch_getCompareZero(driver->tom, driver->tomChannel);
        currentDutyCycle  = (uint16)IfxGtm_Tom_Ch_getCompareOne(driver->tom, driver->tomChannel);
    }

    /* Invalid stored period ? cannot compute ratio */
    if (currentPeriod == 0u)
    {
        return;
    }

    /* Channel-effective TOM clock frequency */
    clkHz = IfxGtm_Tom_Ch_getClockFrequency(driver->gtm, driver->tom, driver->tomChannel);

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
    	IfxGtm_Tom_Tgc_enableChannelUpdate(driver->tgc, driver->tomChannel, FALSE);
    	IfxGtm_Tom_Ch_setCompareZeroShadow(driver->tom, driver->tomChannel, updatedPeriod);
    	IfxGtm_Tom_Ch_setCompareOneShadow(driver->tom, driver->tomChannel, updatedDutyCycle);
    	IfxGtm_Tom_Tgc_enableChannelUpdate(driver->tgc, driver->tomChannel, TRUE);
    }
    else
    {
        IfxGtm_Tom_Ch_setCompareZero(driver->tom, driver->tomChannel, updatedPeriod);
        IfxGtm_Tom_Ch_setCompareOne(driver->tom, driver->tomChannel, updatedDutyCycle);
    }
}


#endif /* IFXGTM_TOM_PWM_H */
