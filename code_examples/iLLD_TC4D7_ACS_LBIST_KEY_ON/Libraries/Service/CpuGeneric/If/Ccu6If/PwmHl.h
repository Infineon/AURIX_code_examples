/**
 * \file PwmHl.h
 * \brief Multi-channels, dual-complementary PWM interface
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
 * \defgroup library_srvsw_if_pwmhl PWM HL interface
 * \ingroup library_srvsw_if
 *
 */

#ifndef PWMHL_H
#define PWMHL_H 1

#include "Ifx_Types.h"

typedef struct PwmHl_s PwmHl;
typedef void         (*PwmHl_Start)(PwmHl *handle);
typedef void         (*PwmHl_Pause)(PwmHl *handle);
typedef void         (*PwmHl_Resume)(PwmHl *handle);
typedef void         (*PwmHl_Stop)(PwmHl *handle);

typedef struct
{
    PwmHl_Start start;
    PwmHl_Stop  stop;
} PwmHl_Functions;

/** \brief Structure of the TPwm interface */
struct PwmHl_s
{
    float32         t12Frequency;   /**< \brief Actual timer12 frequency */
    Ifx_TimerValue  t12Period;      /**< \brief Actual timer 12 period */
    float32         t13Frequency;   /**< \brief Actual timer13 frequency */
    Ifx_TimerValue  t13Period;      /**< \brief Actual timer 13 period */
#if IFX_CFG_USE_STANDARD_INTERFACE
    PwmHl_Functions functions;      /**< \brief Actual timer period */
#endif
};

/** \brief Configuration structure of the TPwm interface */
typedef struct
{
    float32         t12Frequency; /**< \brief Specify expected T12 PWM frequency in Hertz */
    Ifx_TimerValue  t12Period;    /**< \brief Specify expected T12 PWM period in ticks. */
    float32         t13Frequency; /**< \brief Specify expected T13 PWM frequency in Hertz */
    Ifx_TimerValue  t13Period;    /**< \brief Specify expected T13 PWM period in ticks. */
    Ifx_TimerValue  phaseDelay;   /**< \brief Specify the ticks before before updating each ouput hall pattern */
    Ifx_TimerValue  noiseFilter;  /**< \brief Specify hall sensor noise filter */

    Ifx_ActiveState activeState;  /**< \brief Active state select for PWM output. Active high means that the PWM edge is rising at the elapsed of waitingTicks */
} PwmHl_Config;

#if IFX_CFG_USE_STANDARD_INTERFACE
IFX_INLINE void PwmHl_start(PwmHl *handle) {handle->functions.start(handle); }
IFX_INLINE void PwmHl_stop(PwmHl *handle)  {handle->functions.stop(handle); }
#endif

#endif /* TPWM_H_ */
