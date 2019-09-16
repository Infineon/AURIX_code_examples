/**
 * \file PwmHl.h
 * \brief Multi-channels, dual-complementary PWM interface
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:18 GMT$
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup library_srvsw_if_pwmhl PWM HL interface
 * \ingroup library_srvsw_if
 *
 */

#ifndef PWMHL_H_
#define PWMHL_H_ 1

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
