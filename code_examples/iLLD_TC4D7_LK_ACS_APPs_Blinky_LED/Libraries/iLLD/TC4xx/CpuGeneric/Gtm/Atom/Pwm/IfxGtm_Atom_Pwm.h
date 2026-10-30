/**
 * \file IfxGtm_Atom_Pwm.h
 * \brief GTM PWM details
 * \ingroup IfxLld_Gtm
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
 * \defgroup IfxLld_Gtm_Atom_Pwm_Usage How to use the GTM ATOM PWM Driver
 * \ingroup IfxLld_Gtm_Atom_Pwm
 *
 * This interface allows to generate simple PWM signal on a ATOM output and can generate interrupts if enabled.
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
 * // initialize ATOM
 * IfxGtm_Atom_Pwm_Config atomConfig; \\configuration structure
 * IfxGtm_Atom_Pwm_Driver atomHandle; \\ handle
 * IfxGtm_MscOut mscOut; \\ msc connection structure
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
 * // for connecting to MSC configure the structure mscout as per the requirement.
 * atomConfig.mscout.mscSet = IfxGtm_Cfg_MscSet_0;
 * atomConfig.mscout.mscSetSignal = IfxGtm_Cfg_MscSetSignal_0;
 * atomConfig.mscout.mscModule = IfxGtm_Cfg_MscModule_0;
 * atomConfig.mscout.mscAltIn = IfxGtm_MscAltInput_low;
 * // during the Pwm inti Msc connection will be established with the configured channel by API call IfxGtm_ConnectToMsc.
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
    Ifx_Priority   isrPriority;       /**< \brief Priority for Ccu0/1 interrupt. Range: 0 to 0xFF */
    IfxSrc_VmId    vmId;              /**< \brief Virtual machine interrupt service provider */
} IfxGtm_Atom_Pwm_Interrupt;

/** \brief configuration structure for output pin
 */
typedef struct
{
    IfxGtm_Atom_ToutMap *outputPin;        /**< \brief Output pin */
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
    IfxGtm_Cluster            cluster;                        /**< \brief Cluster of ATOM channel to be used */
    IfxGtm_Atom_Ch            atomChannel;                    /**< \brief ATOM channel to be used for PWM */
    IfxGtm_Atom_Ch_ClkSrc     clock;                          /**< \brief Clock source for selected ATOM channel */
    IfxGtm_Atom_Mode          mode;                           /**< \brief Mode of operation of ATOM channel. Only PWM is supported */
    uint32                    period;                         /**< \brief Period in ticks. Range: 0 to 0xFFFFFF */
    uint32                    dutyCycle;                      /**< \brief Duty Cycle in ticks. Range: 0 to 0xFFFFFF */
    Ifx_ActiveState           signalLevel;                    /**< \brief Signal Level when duty is active */
    IfxGtm_Atom_Pwm_Interrupt interrupt;                      /**< \brief Configuration structure for interrupt */
    IfxGtm_Atom_Pwm_pin       pin;                            /**< \brief Configuration structure for output pin */
    IfxGtm_MscOut            *mscOut;                         /**< \brief MSC Configuration */
    IfxGtm_Dtm_ClockSource    dtmClockSource;                 /**< \brief DTM clock source */
    boolean                   oneShotModeEnabled;             /**< \brief Enable/Disable the one shot mode (Currently, has no effect) */
    boolean                   synchronousUpdateEnabled;       /**< \brief Synchronous or Asynchronous update. TRUE: Update compare registers from shadow at the end of period */
    boolean                   immediateStartEnabled;          /**< \brief enable immediate start after init. TRUE: Start channel at end of init */
} IfxGtm_Atom_Pwm_Config;

/** \brief Driver Handle
 */
typedef struct
{
    Ifx_GTM              *gtm;                            /**< \brief Pointer to GTM module */
    IfxGtm_Cluster        clsIndex;                       /**< \brief Index of the CLS object used */
    IfxGtm_Atom_Ch        atomChannel;                    /**< \brief ATOM channel used for the PWM */
    Ifx_GTM_CLS_ATOM     *atom;                           /**< \brief Pointer to the ATOM object */
    Ifx_GTM_CLS_ATOM_AGC *agc;                            /**< \brief Pointer to the AGC object */
    IfxGtm_Atom_Mode      mode;                           /**< \brief Atom mode of operation */
    Ifx_GTM_CLS_CDTM_DTM *dtm;                            /**< \brief Pointer to DTM module */
    IfxGtm_Dtm_Ch         dtmChannel;                     /**< \brief DTM channel used */
    boolean               synchronousUpdateEnabled;       /**< \brief Synchronous update enabled/disabled */
} IfxGtm_Atom_Pwm_Driver;

/** \} */

/** \addtogroup IfxLld_Gtm_Atom_Pwm_Pwm_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initializes the Timer object.
 *
 * \param[inout] driver ATOM Handle.
 * \param[in]    config Configuration structure for ATOM.
 *
 * \retval TRUE on success else FALSE.
 */
IFX_EXTERN boolean IfxGtm_Atom_Pwm_init(IfxGtm_Atom_Pwm_Driver *driver, const IfxGtm_Atom_Pwm_Config *config);

/** \brief Initializes the configuration structure to default.
 *
 * \param[inout] config This parameter is initialized by the function.
 * \param[in]    gtm    Pointer to GTM module.
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Pwm_initConfig(IfxGtm_Atom_Pwm_Config *config, Ifx_GTM *gtm);

/** \brief Starts the PWM generation from the configured channel.
 *
 * \param[inout] driver    Handle for the PWM device.
 * \param[in]    immediate Boolean flag indicating whether to start the PWM generation
 *                         immediately (TRUE) or wait for synchronization (FALSE).
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Pwm_start(IfxGtm_Atom_Pwm_Driver *driver, boolean immediate);

/** \brief Stops the PWM generation from the configured channel.
 *
 * \param[inout] driver    Handle for the PWM device
 * \param[in]    immediate Immediate start or not.
 *                         TRUE: Stop the PWM generation immediately.
 * 						   FALSE: Stop the PWM generation after the current cycle completes
 *
 * \retval None
 */
IFX_EXTERN void IfxGtm_Atom_Pwm_stop(IfxGtm_Atom_Pwm_Driver *driver, boolean immediate);

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
IFX_INLINE void IfxGtm_Atom_Pwm_setDuty(IfxGtm_Atom_Pwm_Driver *driver, float32 requestDuty);

/** \brief Update PWM frequency.
 *  Duty-cycle count is scaled automatically to preserve existing duty cycle.
 *
 * \param[inout] driver           ATOM Handle.
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
        period = IfxGtm_Atom_Ch_getCompareZeroShadow(driver->atom, driver->atomChannel);
    }
    else
    {
        period = IfxGtm_Atom_Ch_getCompareZero(driver->atom, driver->atomChannel);
    }

    /* Duty in ticks = period * (requestDuty in percent / 100%) */
    dutyCycle = (uint32)(((float32)period * requestDuty * 0.01f) + 0.5f);

    /* Clamp to period to avoid overflow caused by rounding */
    dutyCycle = (dutyCycle <= period) ? dutyCycle : period;

    if (driver->synchronousUpdateEnabled == TRUE)
    {
        IfxGtm_Atom_Ch_setCompareOneShadow(driver->atom, driver->atomChannel, dutyCycle);
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
        currentPeriod     = IfxGtm_Atom_Ch_getCompareZeroShadow(driver->atom, driver->atomChannel);
        currentDutyCycle  = IfxGtm_Atom_Ch_getCompareOneShadow(driver->atom, driver->atomChannel);
    }
    else
    {
        currentPeriod     = IfxGtm_Atom_Ch_getCompareZero(driver->atom, driver->atomChannel);
        currentDutyCycle  = IfxGtm_Atom_Ch_getCompareOne(driver->atom, driver->atomChannel);
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
        IfxGtm_Atom_Ch_setCompareZeroShadow(driver->atom, driver->atomChannel, updatedPeriod);
        IfxGtm_Atom_Ch_setCompareOneShadow(driver->atom, driver->atomChannel, updatedDutyCycle);
    }
    else
    {
        IfxGtm_Atom_Ch_setCompareZero(driver->atom, driver->atomChannel, updatedPeriod);
        IfxGtm_Atom_Ch_setCompareOne(driver->atom, driver->atomChannel, updatedDutyCycle);
    }
}


#endif /* IFXGTM_ATOM_PWM_H */
