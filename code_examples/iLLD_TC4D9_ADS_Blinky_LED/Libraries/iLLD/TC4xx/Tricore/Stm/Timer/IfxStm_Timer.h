/**
 * \file IfxStm_Timer.h
 * \brief STM TIMER details
 * \ingroup IfxLld_Stm
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
 * The timer driver enabled the generation of periodical interrupt based on the STM module.
 *
 *    The driver is initialized with \ref IfxStm_Timer_init(). After initialization, the
 *    timer is started with \ref IfxStm_Timer_run() and stopped with \ref IfxStm_Timer_stop().
 *    Single shot can be set with \ref IfxStm_Timer_setSingleMode(), in case the timer is
 *    already running it will stop after the next event, else the timer event will occur only once.
 *
 *    The timer interrupt must call the \ref IfxStm_Timer_acknowledgeTimerIrq() function which
 *    clears the interrupt flag and set the next compare value.
 *
 *    Changing the period with \ref IfxStm_Timer_setPeriod() or \ref IfxStm_Timer_setFrequency() will
 *    take effect only after the next timer event.
 *
 *
 *    This driver implements a subset of the functionalities defined by \ref library_srvsw_stdif_timer.
 *    If does supports the timer with interrupt but not the trigger signal.
 *
 *    The user is free to use either the driver specific APIs below or to used the \ref library_srvsw_stdif_timer "standard interface APIs".
 *
 *  \section Specific Specific implementation
 *   For a detailed configuration of the microcontroller, see \ref IfxStm_Timer_init().
 *
 *  \section Example Usage example
 *    Initialization and interrupt:
 *  \code
 *  #define ISR_PRIORITY_TIMER_1MS (2)
 *  #define ISR_PROVIDER_TIMER_1MS IfxSrc_Tos_cpu0
 *  #define INTERRUPT_TIMER_1MS    ISR_ASSIGN(ISR_PRIORITY_TIMER_1MS, ISR_PROVIDER_TIMER_1MS)
 *
 *  IfxStm_Timer myTimer;
 *
 *  boolean AppInit_1ms(void)
 *  {
 *      boolean                  result = TRUE;
 *      Ifx_CPU *cpu;
 *      cpu =  IfxCpu_getAddress(IfxCpu_getCoreIndex());
 *      IfxStm_Timer_Config timerConfig;
 *      IfxStm_Timer_initConfig(&timerConfig, cpu);
 *      timerConfig.base.frequency       = 1000;
 *      timerConfig.base.isrPriority     = ISR_PRIORITY(INTERRUPT_TIMER_1MS);
 *      timerConfig.base.isrProvider     = ISR_PROVIDER(INTERRUPT_TIMER_1MS);
 *      timerConfig.base.minResolution   = (1.0f / timerConfig.base.frequency) / 1000;
 *      timerConfig.comparator           = IfxStm_Comparator_0;
 *      result                           = IfxStm_Timer_init(&myTimer, &timerConfig);
 *
 *      return result;
 *  }
 *
 *  IFX_INTERRUPT(ISR_TIMER_1ms, 0, ISR_PRIORITY_TIMER_1MS)
 *  {
 *      __enable();
 *      IfxStm_Timer_acknowledgeTimerIrq(&myTimer);
 *  }
 *  \endcode
 *
 *    During run-time, the timer can be started / stopped as follow:
 *  \code
 *      IfxStm_Timer_run(&myTimer);
 *      IfxStm_Timer_stop(&myTimer);
 *  \endcode
 *
 * \defgroup IfxLld_Stm_Timer STM Timer Interface
 * \ingroup IfxLld_Stm
 * \defgroup IfxLld_Stm_Timer_STMTimerDataStructures STM Timer Data Structures
 * \ingroup IfxLld_Stm_Timer
 * \defgroup IfxLld_Stm_Timer_globalfunction global function
 * \ingroup IfxLld_Stm_Timer
 */

#ifndef IFXSTM_TIMER_H
#define IFXSTM_TIMER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Stm/Std/IfxStm.h"
#include "Ifx_Types.h"
#include "Src/Std/IfxSrc.h"
#include "Port/Std/IfxPort.h"

#ifndef IFXSTM_TIMER_STDIF
#define IFXSTM_TIMER_STDIF 0
#endif

#if IFXSTM_TIMER_STDIF
typedef void *IfxStm_Timer_InterfaceDriver; /**< \brief Pointer to the specific interface driver */
#endif

/******************************************************************************/
/*------------------Types from former IfxStdIf_Timer.h------------------------*/
/******************************************************************************/

/** \brief Timer increment direction */
typedef enum
{
    IfxStm_Timer_CountDir_up,                      /**< \brief Timer is counting up */
    IfxStm_Timer_CountDir_upAndDown,               /**< \brief Timer is counting up and down */
    IfxStm_Timer_CountDir_down                     /**< \brief Timer is counting down */
} IfxStm_Timer_CountDir;

/** \brief Trigger configuration */
typedef struct
{
    boolean            enabled;             /**< \brief If true, the trigger functionality is Initialised, else ignored */
    Ifx_TimerValue     triggerPoint;        /**< \brief Trigger point in timer ticks */
    Ifx_Priority       isrPriority;         /**< \brief Interrupt isrPriority of the trigger interrupt, if 0 the interrupt is disable */
    IfxSrc_Tos         isrProvider;         /**< \brief Interrupt service provider for the trigger interrupt */
    IfxPort_OutputMode outputMode;          /**< \brief Output mode */
    IfxPort_PadDriver  outputDriver;        /**< \brief Output pad driver */
    boolean            risingEdgeAtPeriod;  /**< \brief Set the clock signal polarity, if TRUE, the rising edge is at the period, else at the trigger offset. When the timer is stopped, the output is set to high */
    boolean            outputEnabled;       /**< \brief If TRUE, the output pin is enabled, else disabled. In case the output is disabled, the output pin is not initialized. */
} IfxStm_Timer_TrigConfig;

/** \brief Timer base configuration (formerly IfxStdIf_Timer_Config) */
typedef struct
{
    float32                 frequency;     /**< \brief PWM frequency in Hz */
    Ifx_Priority            isrPriority;   /**< \brief Interrupt isrPriority of the timer interrupt, if 0 the interrupt is disable */
    IfxSrc_Tos              isrProvider;   /**< \brief Interrupt service provider for the timer interrupt */
    float32                 minResolution; /**< \brief Minimum resolution of the timer in seconds. if 0, this parameter is ignored */
    IfxStm_Timer_TrigConfig trigger;       /**< \brief Trigger configuration */
    IfxStm_Timer_CountDir   countDir;      /**< \brief Timer counting mode */
    float32                 startOffset;   /**< \brief Timer initial offset in % of the period */
} IfxStm_Timer_Config_Base;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Stm_Timer_STMTimerDataStructures
 * \{ */
/** \brief Structure for the timer base
 */
typedef struct
{
    Ifx_TimerValue          period;               /**< \brief Timer period in ticks (cached value). Range 0 to OxFFFFFFFF. */
    boolean                 triggerEnabled;       /**< \brief If TRUE, the trigger functionality is Initialized, FALSE if the trigger functionality is not Initialized. */
    float32                 clockFreq;            /**< \brief Timer input clock frequency (cached value) */
    IfxStm_Timer_CountDir countDir;             /**< \brief Timer counting mode */
    boolean                 singleShot;           /**< \brief If TRUE, the timer will stop after 1st event, FALSE if the timer will not stop after 1st event. */
} IfxStm_Timer_Base;

/** \} */

/** \addtogroup IfxLld_Stm_Timer_STMTimerDataStructures
 * \{ */
/** \brief Timer interface
 */
typedef struct
{
    IfxStm_Timer_Base base;                  /**< \brief Timer interface */
    Ifx_CPU          *stm;                   /**< \brief STM module used for the timer functionality */
    IfxStm_Comparator comparator;            /**< \brief Comparator used for the timer functionality */
    uint32            comparatorValue;       /**< \brief Value of the comparator for the next event. Range: 0 to 0xFFFFFFFF. */
    uint8             comparatorShift;       /**< \brief Comparator shift. Range: 0 to 31.  */
} IfxStm_Timer;

/** \brief configuration structure for Timer
 */
typedef struct
{
    IfxStm_Timer_Config_Base base;              /**< \brief Base timer configuration */
    Ifx_CPU              *stm;              /**< \brief STM module used for the timer functionality */
    IfxStm_Comparator     comparator;       /**< \brief Comparator used for the timer functionality */
} IfxStm_Timer_Config;

/** \} */

/** \addtogroup IfxLld_Stm_Timer_globalfunction
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the timer event.
 * see IfxStdIf_Timer_AckTimerIrq.
 *
 * \param[inout] driver STM Timer interface Handle.
 *
 * \retval TRUE If the timer interrupt was successfully acknowledged.
 *         FALSE If the timer interrupt was not successfully acknowledged.
 */
IFX_EXTERN boolean IfxStm_Timer_acknowledgeTimerIrq(IfxStm_Timer *driver);

/** \brief Returns the frequency.
 * see IfxStdIf_Timer_GetFrequency.
 *
 * \param[in] driver STM Timer interface Handle.
 *
 * \retval float32 Frequency.
 */
IFX_EXTERN float32 IfxStm_Timer_getFrequency(IfxStm_Timer *driver);

/** \brief Returns the input frequency.
 * see IfxStdIf_Timer_GetInputFrequency.
 *
 * \param[in] driver STM Timer interface Handle.
 *
 * \retval float32 Frequency.
 */
IFX_EXTERN float32 IfxStm_Timer_getInputFrequency(IfxStm_Timer *driver);

/** \brief Returns the period of the timer.
 * see IfxStdIf_Timer_GetPeriod.
 *
 * \param[in] driver STM Timer interface Handle.
 *
 * \retval Ifx_TimerValue Period. Range: 0 to 0xFFFFFFFF.
 */
IFX_EXTERN Ifx_TimerValue IfxStm_Timer_getPeriod(IfxStm_Timer *driver);

/** \brief Return the resolution of the Timer counters.
 * see IfxStdIf_Timer_GetResolution.
 *
 * \param[in] driver STM Timer interface handle.
 *
 * \retval float32 Resolution.
 */
IFX_EXTERN float32 IfxStm_Timer_getResolution(IfxStm_Timer *driver);

/** \brief Runs the timer.
 * see IfxStdIf_Timer_Run.
 *
 * \param[inout] driver STM Timer interface Handle.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_Timer_run(IfxStm_Timer *driver);

/** \brief Sets the Frequency.
 * see IfxStdIf_Timer_SetFrequency.
 *
 * \param[inout] driver    STM Timer interface Handle.
 * \param[in]    frequency Frequency.
 *
 * \retval TRUE If the frequency was successfully set.
 *         FALSE If the frequency was not successfully set.
 */
IFX_EXTERN boolean IfxStm_Timer_setFrequency(volatile IfxStm_Timer *driver, float32 frequency);

/** \brief Sets the period for the timer.
 * see IfxStdIf_Timer_SetPeriod.
 *
 * \param[inout] driver STM Timer interface handle.
 * \param[in]    period Period value. Range: 0 to 0xFFFFFFFF.
 *
 * \retval TRUE If the period was successfully set.
 *         FALSE If the period was not successfully set.
 */
IFX_EXTERN boolean IfxStm_Timer_setPeriod(volatile IfxStm_Timer *driver, Ifx_TimerValue period);

/** \brief Sets the single shot mode of the timer.
 * see IfxStdIf_Timer_SetSingleMode.
 *
 * \param[inout] driver  STM Timer interface Handle.
 * \param[in]    enabled TRUE If enables single-shot mode, FALSE If disables single-shot mode.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_Timer_setSingleMode(IfxStm_Timer *driver, boolean enabled);

#if IFXSTM_TIMER_STDIF
/** \brief Initializes the standard interface timer.
 *
 * \param[inout] stdif  Standard interface object, will be initialized by the function.
 * \param[in]    driver Driver Interface driver to be used by the standard interface. must be initialised separately.
 *
 * \retval TRUE If the initialization is successful.
 *         FALSE If the initialization is unsuccessful.
 */
IFX_EXTERN boolean IfxStm_Timer_stdIfTimerInit(IfxStm_Timer_StdIf *stdif, IfxStm_Timer *driver);
#endif /* IFXSTM_TIMER_STDIF */

/** \brief Stops the timer.
 * see IfxStdIf_Timer_Stop.
 *
 * \param[inout] driver STM Timer interface Handle.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_Timer_stop(IfxStm_Timer *driver);

/** \brief Updates the input frequency.
 * see IfxStdIf_Timer_UpdateInputFrequency.
 *
 * \param[inout] driver STM Timer interface Handle.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_Timer_updateInputFrequency(volatile IfxStm_Timer *driver);

/** \brief Initialises the timer object.
 *
 * \param[inout] driver STM Timer interface Handle.
 * \param[in]    config Configuration structure for STM Timer.
 *
 * \retval TRUE If the initialization is successful.
 *         FALSE If the initialization is unsuccessful.
 */
IFX_EXTERN boolean IfxStm_Timer_init(volatile IfxStm_Timer *driver, const IfxStm_Timer_Config *config);

/** \brief Initializes the configuration structure to default.
 *
 * \param[inout] config Configuration structure for STM Timer.
 * \param[in]    cpu    Pointer to STM module.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_Timer_initConfig(IfxStm_Timer_Config *config, Ifx_CPU *cpu);

/** \} */

/******************************************************************************/
/*-------------------Utility Inline Functions---------------------------------*/
/******************************************************************************/

/** \brief Convert timer ticks to seconds
 * \param  clockFreq Timer clock frequency
 * \param  ticks time value in ticks to be converted
 * \return Return the converted time in s
 */
IFX_INLINE float32 IfxStm_Timer_tickToS(float32 clockFreq, Ifx_TimerValue ticks)
{
    return ticks / clockFreq;
}


/** \brief Convert seconds to timer ticks
 * \param  clockFreq Timer clock frequency
 * \param  seconds time value in seconds to be converted
 * \return Return the converted time in timer ticks
 */
IFX_INLINE Ifx_TimerValue IfxStm_Timer_sToTick(float32 clockFreq, float32 seconds)
{
    return seconds * clockFreq;
}


/** \brief Initializes the base configuration structure to default.
 *
 * \param[inout] config Base configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxStm_Timer_initConfig_Base(IfxStm_Timer_Config_Base *config);


/******************************************************************************/
/*-----------Standard Interface (gated by IFXSTM_TIMER_STDIF)-----------------*/
/******************************************************************************/

#if IFXSTM_TIMER_STDIF

/** \brief Output event enable / disable */
typedef enum
{
    IfxStm_Timer_Output_disabled,              /**< \brief Timer output is set to the inactive, no change in the output */
    IfxStm_Timer_Output_enabled                /**< \brief In case the trigger is enabled,
                                                *          the output is set to active between time 0 to the trigger point,
                                                *          and is set to inactive between the trigger point and the period.
                                                */
} IfxStm_Timer_OutputEvent;

/** \brief Forward declaration */
typedef struct IfxStm_Timer_StdIf_ IfxStm_Timer_StdIf;

/** \brief Return the timer frequency in Hz */
typedef float32 (*IfxStm_Timer_GetFrequency)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Return the timer period in ticks */
typedef Ifx_TimerValue (*IfxStm_Timer_GetPeriod)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Return the timer resolution in seconds */
typedef float32 (*IfxStm_Timer_GetResolution)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Return the timer trigger point */
typedef Ifx_TimerValue (*IfxStm_Timer_GetTrigger)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Set the timer frequency in Hz */
typedef boolean (*IfxStm_Timer_SetFrequency)(IfxStm_Timer_InterfaceDriver stdIf, float32 frequency);

/** \brief Indicates that the input frequency has changed */
typedef void (*IfxStm_Timer_UpdateInputFrequency)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Apply requested updates */
typedef void (*IfxStm_Timer_ApplyUpdate)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Disable updates */
typedef void (*IfxStm_Timer_DisableUpdate)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Return the timer input frequency in Hz */
typedef float32 (*IfxStm_Timer_GetInputFrequency)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Immediately start the timer */
typedef void (*IfxStm_Timer_Run)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Set the timer period */
typedef boolean (*IfxStm_Timer_SetPeriod)(IfxStm_Timer_InterfaceDriver stdIf, Ifx_TimerValue period);

/** \brief Stop timer at the end of the period */
typedef void (*IfxStm_Timer_SetSingleMode)(IfxStm_Timer_InterfaceDriver stdIf, boolean enabled);

/** \brief Set trigger point */
typedef void (*IfxStm_Timer_SetTrigger)(IfxStm_Timer_InterfaceDriver stdIf, Ifx_TimerValue triggerPoint);

/** \brief Immediately stops the timer */
typedef void (*IfxStm_Timer_Stop)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Return the timer interrupt flag and reset it */
typedef boolean (*IfxStm_Timer_AckTimerIrq)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Return the trigger interrupt flag and reset it */
typedef boolean (*IfxStm_Timer_AckTriggerIrq)(IfxStm_Timer_InterfaceDriver stdIf);

/** \brief Standard interface object */
struct IfxStm_Timer_StdIf_
{
    IfxStm_Timer_InterfaceDriver            driver;                  /**< \brief Interface driver object                  */
    IfxStm_Timer_GetFrequency           getFrequency;            /**< \brief \see IfxStm_Timer_GetFrequency           */
    IfxStm_Timer_GetPeriod              getPeriod;               /**< \brief \see IfxStm_Timer_GetPeriod              */
    IfxStm_Timer_GetResolution          getResolution;           /**< \brief \see IfxStm_Timer_GetResolution          */
    IfxStm_Timer_GetTrigger             getTrigger;              /**< \brief \see IfxStm_Timer_GetTrigger             */
    IfxStm_Timer_SetFrequency           setFrequency;            /**< \brief \see IfxStm_Timer_SetFrequency           */
    IfxStm_Timer_UpdateInputFrequency   updateInputFrequency;    /**< \brief \see IfxStm_Timer_UpdateInputFrequency   */
    IfxStm_Timer_ApplyUpdate            applyUpdate;             /**< \brief \see IfxStm_Timer_ApplyUpdate            */
    IfxStm_Timer_DisableUpdate          disableUpdate;           /**< \brief \see IfxStm_Timer_DisableUpdate          */
    IfxStm_Timer_GetInputFrequency      getInputFrequency;       /**< \brief \see IfxStm_Timer_GetInputFrequency      */
    IfxStm_Timer_Run                    run;                     /**< \brief \see IfxStm_Timer_Run                    */
    IfxStm_Timer_SetPeriod              setPeriod;               /**< \brief \see IfxStm_Timer_SetPeriod              */
    IfxStm_Timer_SetSingleMode          setSingleMode;           /**< \brief \see IfxStm_Timer_SetSingleMode          */
    IfxStm_Timer_SetTrigger             setTrigger;              /**< \brief \see IfxStm_Timer_SetTrigger             */
    IfxStm_Timer_Stop                   stop;                    /**< \brief \see IfxStm_Timer_Stop                   */
    IfxStm_Timer_AckTimerIrq            ackTimerIrq;             /**< \brief \see IfxStm_Timer_AckTimerIrq            */
    IfxStm_Timer_AckTriggerIrq          ackTriggerIrq;           /**< \brief \see IfxStm_Timer_AckTriggerIrq          */
};

/** Inline wrapper functions (dispatch through function pointers) */

IFX_INLINE float32 IfxStm_Timer_getFrequency_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    return stdIf->getFrequency(stdIf->driver);
}

IFX_INLINE Ifx_TimerValue IfxStm_Timer_getPeriod_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    return stdIf->getPeriod(stdIf->driver);
}

IFX_INLINE Ifx_TimerValue IfxStm_Timer_getTrigger_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    return stdIf->getTrigger(stdIf->driver);
}

IFX_INLINE float32 IfxStm_Timer_getResolution_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    return stdIf->getResolution(stdIf->driver);
}

IFX_INLINE boolean IfxStm_Timer_setFrequency_StdIf(IfxStm_Timer_StdIf *stdIf, float32 frequency)
{
    return stdIf->setFrequency(stdIf->driver, frequency);
}

IFX_INLINE void IfxStm_Timer_updateInputFrequency_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    stdIf->updateInputFrequency(stdIf->driver);
}

IFX_INLINE void IfxStm_Timer_applyUpdate_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    stdIf->applyUpdate(stdIf->driver);
}

IFX_INLINE void IfxStm_Timer_disableUpdate_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    stdIf->disableUpdate(stdIf->driver);
}

IFX_INLINE float32 IfxStm_Timer_getInputFrequency_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    return stdIf->getInputFrequency(stdIf->driver);
}

IFX_INLINE void IfxStm_Timer_run_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    stdIf->run(stdIf->driver);
}

IFX_INLINE boolean IfxStm_Timer_setPeriod_StdIf(IfxStm_Timer_StdIf *stdIf, Ifx_TimerValue period)
{
    return stdIf->setPeriod(stdIf->driver, period);
}

IFX_INLINE void IfxStm_Timer_setSingleMode_StdIf(IfxStm_Timer_StdIf *stdIf, boolean enabled)
{
    stdIf->setSingleMode(stdIf->driver, enabled);
}

IFX_INLINE void IfxStm_Timer_setTrigger_StdIf(IfxStm_Timer_StdIf *stdIf, Ifx_TimerValue triggerPoint)
{
    stdIf->setTrigger(stdIf->driver, triggerPoint);
}

IFX_INLINE void IfxStm_Timer_stop_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    stdIf->stop(stdIf->driver);
}

IFX_INLINE boolean IfxStm_Timer_ackTimerIrq_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    return stdIf->ackTimerIrq(stdIf->driver);
}

IFX_INLINE boolean IfxStm_Timer_ackTriggerIrq_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    return stdIf->ackTriggerIrq(stdIf->driver);
}

IFX_INLINE float32 IfxStm_Timer_getPeriodSecond_StdIf(IfxStm_Timer_StdIf *stdIf)
{
    return IfxStm_Timer_tickToS(IfxStm_Timer_getInputFrequency_StdIf(stdIf), stdIf->getPeriod(stdIf->driver));
}

IFX_EXTERN void IfxStm_Timer_initStdIf(IfxStm_Timer_StdIf *stdIf, IfxStm_Timer_InterfaceDriver driver);

#endif /* IFXSTM_TIMER_STDIF */

#endif /* IFXSTM_TIMER_H */
