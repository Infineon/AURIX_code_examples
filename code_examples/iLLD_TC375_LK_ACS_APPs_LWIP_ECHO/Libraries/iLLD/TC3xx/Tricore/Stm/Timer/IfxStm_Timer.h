/**
 * \file IfxStm_Timer.h
 * \brief STM TIMER details
 * \ingroup IfxLld_Stm
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
 *      IfxStm_Timer_Config timerConfig;
 *      IfxStm_Timer_initConfig(&timerConfig, &MODULE_STM0);
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
#include "StdIf/IfxStdIf_Timer.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Stm_Timer_STMTimerDataStructures
 * \{ */
/** \brief Structure for the timer base
 */
typedef struct
{
    Ifx_TimerValue          period;               /**< \brief Timer period in ticks (cached value) */
    boolean                 triggerEnabled;       /**< \brief TRUE if the trigger functionality is Initialized, FALSE if the trigger functionality is not Initialized. */
    float32                 clockFreq;            /**< \brief Timer input clock frequency (cached value) */
    IfxStdIf_Timer_CountDir countDir;             /**< \brief Timer counting mode */
    boolean                 singleShot;           /**< \brief TRUE if the timer will stop after 1st event, FALSE if the timer will not stop after 1st event. */
} IfxStm_Timer_Base;

/** \} */

/** \addtogroup IfxLld_Stm_Timer_STMTimerDataStructures
 * \{ */
/** \brief Timer interface
 */
typedef struct
{
    IfxStm_Timer_Base base;                  /**< \brief Timer interface */
    Ifx_STM          *stm;                   /**< \brief STM module used for the timer functionality */
    IfxStm_Comparator comparator;            /**< \brief Comparator used for the timer functionality */
    uint32            comparatorValue;       /**< \brief Value of the comparator for the next event. Range: 0 to 0xFFFFFFFF. */
    uint8             comparatorShift;       /**< \brief Comparator shift. Range: 0 to 31. */
} IfxStm_Timer;

/** \brief configuration structure for Timer
 */
typedef struct
{
    IfxStdIf_Timer_Config base;             /**< \brief Standard interface timer configuration */
    Ifx_STM              *stm;              /**< \brief STM module used for the timer functionality */
    IfxStm_Comparator     comparator;       /**< \brief Comparator used for the timer functionality */
} IfxStm_Timer_Config;

/** \} */

/** \addtogroup IfxLld_Stm_Timer_globalfunction
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Acknowledges and processes the timer interrupt.
 *
 * \param[inout] driver Pointer to the STM Timer interface handle.
 *
 * \retval TRUE If the timer interrupt was successfully acknowledged.
 *         FALSE If the timer interrupt was not successfully acknowledged.
 *
 */
IFX_EXTERN boolean IfxStm_Timer_acknowledgeTimerIrq(IfxStm_Timer *driver);

/** \brief Retrieves the frequency of the STM timer.
 *
 * \param[in] driver Pointer to the STM Timer interface handle.
 *
 * \retval float32 The frequency of the timer in Hz.
 *
 */
IFX_EXTERN float32 IfxStm_Timer_getFrequency(IfxStm_Timer *driver);

/** \brief Retrieves the input frequency of the specified STM timer.
 *
 * \param[in] driver Pointer to the STM Timer interface handle.
 *
 * \retval float32 Input clock frequency in Hz.
 *
 */
IFX_EXTERN float32 IfxStm_Timer_getInputFrequency(IfxStm_Timer *driver);

/** \brief Retrieves the current period value of the STM timer.
 *
 * \param[in] driver Pointer to the STM Timer interface handle.
 *
 * \retval Ifx_TimerValue The current period value of the timer in microseconds. Range: 0 to 0xFFFFFFFF.
 *
 */
IFX_EXTERN Ifx_TimerValue IfxStm_Timer_getPeriod(IfxStm_Timer *driver);

/** \brief Gets the resolution of the STM timer in seconds.
 *
 * \param[in] driver Pointer to the STM Timer interface handle.
 *
 * \retval float32 The resolution of the timer in seconds, calculated as 1 divided by the clock frequency.
 *
 */
IFX_EXTERN float32 IfxStm_Timer_getResolution(IfxStm_Timer *driver);

/** \brief Runs the timer by updating the comparator value and enabling the comparator interrupt.
 *
 * \param[inout] driver Pointer to the STM Timer interface handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxStm_Timer_run(IfxStm_Timer *driver);

/** \brief Sets the frequency of the specified timer driver.
 *
 * \param[inout] driver    Pointer to the STM Timer interface handle.
 * \param[in]    frequency Desired frequency in Hertz (Hz).
 *
 * \retval TRUE If the frequency was successfully set.
 *         FALSE If the frequency was not successfully set.
 *
 */
IFX_EXTERN boolean IfxStm_Timer_setFrequency(volatile IfxStm_Timer *driver, float32 frequency);

/** \brief Sets the period for the specified STM timer driver.
 *
 * \param[inout] driver Pointer to the STM Timer interface handle.
 * \param[in]    period The new period value to be set for the timer. Range: 0 to 0xFFFFFFFF.
 *
 * \retval TRUE If the frequency was successfully set.
 *         FALSE If the frequency was not successfully set.
 *
 */
IFX_EXTERN boolean IfxStm_Timer_setPeriod(volatile IfxStm_Timer *driver, Ifx_TimerValue period);

/** \brief Enables or disables the single-shot mode of the specified STM timer.
 *
 * \param[inout] driver  Pointer to the STM Timer interface handle.
 * \param[in]    enabled TRUE If enables single-shot mode, FALSE If disables single-shot mode.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxStm_Timer_setSingleMode(IfxStm_Timer *driver, boolean enabled);

/** \brief Initializes the standard interface timer with the STM timer driver.
 *
 * \param[inout] stdif  Pointer to the standard interface timer object to be initialized.
 * \param[in]    driver Pointer to the STM Timer interface handle.
 *
 * \retval TRUE If the initialization is successful.
 *         FALSE If the initialization is unsuccessful.
 */
IFX_EXTERN boolean IfxStm_Timer_stdIfTimerInit(IfxStdIf_Timer *stdif, IfxStm_Timer *driver);

/** \brief Stops the timer by disabling the comparator interrupt.
 *
 * \param[inout] driver Pointer to the STM Timer interface handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxStm_Timer_stop(IfxStm_Timer *driver);

/** \brief Updates the input frequency of the STM timer module based on the current configuration.
 *
 * \param[inout] driver Pointer to the STM Timer interface handle.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxStm_Timer_updateInputFrequency(volatile IfxStm_Timer *driver);

/** \brief Initializes the STM timer with the provided configuration.
 *
 * \param[inout] driver Pointer to the STM Timer interface handle.
 * \param[in]    config Pointer to the configuration structure containing the timer settings.
 *
 * \retval TRUE If the initialization is successful.
 *         FALSE If the initialization is unsuccessful.
 *
 */
IFX_EXTERN boolean IfxStm_Timer_init(volatile IfxStm_Timer *driver, const IfxStm_Timer_Config *config);

/** \brief config Pointer to the STM timer configuration structure to be initialized.
 *
 * \param[inout] config Pointer to the configuration structure for the STM timer.
 * \param[in]    stm    Pointer to the STM module registers.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxStm_Timer_initConfig(IfxStm_Timer_Config *config, Ifx_STM *stm);

/** \} */

#endif /* IFXSTM_TIMER_H */
