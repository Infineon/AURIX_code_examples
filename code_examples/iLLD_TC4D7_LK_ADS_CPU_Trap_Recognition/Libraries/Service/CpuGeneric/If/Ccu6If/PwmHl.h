/**
 * \file PwmHl.h
 * \brief Multi-channels, dual-complementary PWM interface
 *
 * \version iLLD-TC4-v2.1.1
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such
 * terms of use are agreed, use of this file is subject to following:
 *
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or
 * organization obtaining a copy of the software and accompanying
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
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
 * \defgroup library_srvsw_if_pwmhl PWM HL interface
 * \ingroup library_srvsw_if
 *
 */

#ifndef PWMHL_H
#define PWMHL_H 1

#include "Cpu/Std/Ifx_Types.h"

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
