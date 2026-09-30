/**
 * \file Timer.h
 * \brief Timer interface
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
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
 * \defgroup library_srvsw_if_timer Timer interface
 * \ingroup library_srvsw_if
 *
 */

#ifndef TIMER_H
#define TIMER_H 1

#include "Ifx_Types.h"

typedef struct Timer_s Timer;
typedef void         (*Timer_Start)(Timer *handle);
typedef void         (*Timer_Stop)(Timer *handle);
typedef void         (*Timer_SynchronousStart)(Timer *handle);
typedef void         (*Timer_SynchronousStop)(Timer *handle);
typedef void         (*Timer_CountOneStep)(Timer *handle);
typedef void         (*Timer_StartSingleShotMode)(Timer *handle);

typedef struct
{
    Timer_Start               start;
    Timer_Stop                stop;
    Timer_SynchronousStart    synchronousStart;
    Timer_SynchronousStop     synchronousStop;
    Timer_CountOneStep        countOneStep;
    Timer_StartSingleShotMode startSingleShotMode;
} Timer_Functions;

/** \brief Structure of the Timer interface */
struct Timer_s
{
    float32         t12Frequency;  /**< \brief Actual timer12 frequency */
    Ifx_TimerValue  t12Period;     /**< \brief Actual timer 12 period */
    float32         t13Frequency;  /**< \brief Actual timer13 frequency */
    Ifx_TimerValue  t13Period;     /**< \brief Actual timer 13 period */
#if IFX_CFG_USE_STANDARD_INTERFACE
    Timer_Functions functions;     /**< \brief  timer functions */
#endif
};

/** \brief Configuration structure of the Timer interface */
typedef struct
{
    float32        t12Frequency;   /**< \brief Specify expected T12 PWM frequency in Hertz */
    Ifx_TimerValue t12Period;      /**< \brief Specify expected T12 PWM period in ticks. */
    float32        t13Frequency;   /**< \brief Specify expected T13 PWM frequency in Hertz */
    Ifx_TimerValue t13Period;      /**< \brief Specify expected T13 PWM period in ticks. */
    Ifx_TimerValue waitingTime;    /**< \brief Specify the expected ticks before timer starts (TWAIT) */
    Ifx_TimerValue activeCount;    /**< \brief Specify active PWM period (TCOUNT) */
} Timer_Config;

#if IFX_CFG_USE_STANDARD_INTERFACE
IFX_INLINE void Timer_start(Timer *handle)               {handle->functions.start(handle); }
IFX_INLINE void Timer_stop(Timer *handle)                {handle->functions.stop(handle); }
IFX_INLINE void Timer_synchronousStart(Timer *handle)    {handle->functions.synchronousStart(handle); }
IFX_INLINE void Timer_synchronousStop(Timer *handle)     {handle->functions.synchronousStop(handle); }
IFX_INLINE void Timer_countOneStep(Timer *handle)        {handle->functions.countOneStep(handle); }
IFX_INLINE void Timer_startSingleShotMode(Timer *handle) {handle->functions.startSingleShotMode(handle); }
#endif

#endif /* TIMER_H_ */
