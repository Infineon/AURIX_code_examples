/**
 * \file TPwm.h
 * \brief TPWM interface
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
 * \defgroup library_srvsw_if_tpwm TPWM interface
 * \ingroup library_srvsw_if
 *
 */

#ifndef TPWM_H_
#define TPWM_H_ 1

#include "Cpu/Std/Ifx_Types.h"

typedef struct TPwm_s TPwm;
typedef void        (*TPwm_Start)(TPwm *handle);
typedef void        (*TPwm_Pause)(TPwm *handle);
typedef void        (*TPwm_Resume)(TPwm *handle);
typedef void        (*TPwm_Stop)(TPwm *handle);

typedef struct
{
    TPwm_Start  start;
    TPwm_Pause  pause;
    TPwm_Resume resume;
    TPwm_Stop   stop;
} TPwm_Functions;

/** \brief Structure of the TPwm interface */
struct TPwm_s
{
    float32        frequency;      /**< \brief Actual frequency */
    Ifx_TimerValue period;         /**< \brief Actual timer period */
#if IFX_CFG_USE_STANDARD_INTERFACE
    TPwm_Functions functions;      /**< \brief Actual timer period */
#endif
};

/** \brief Configuration structure of the TPwm interface */
typedef struct
{
    float32         frequency;     /**< \brief Specify expected PWM frequency in Hertz */
    Ifx_TimerValue  waitingTime;   /**< \brief Specify the expected ticks before timer starts (TWAIT) */
    Ifx_TimerValue  activeCount;   /**< \brief Specify active PWM period (TCOUNT) */
    Ifx_TimerValue  period;        /**< \brief Specify expected PWM period in ticks. */
    Ifx_ActiveState activeState;   /**< \brief Active state select for PWM output. Active high means that the PWM edge is rising at the elapsed of waitingTicks */
} TPwm_Config;

#if IFX_CFG_USE_STANDARD_INTERFACE
IFX_INLINE void TPwm_start(TPwm *handle)  {handle->functions.start(handle); }
IFX_INLINE void TPwm_pause(TPwm *handle)  {handle->functions.pause(handle); }
IFX_INLINE void TPwm_resume(TPwm *handle) {handle->functions.resume(handle); }
IFX_INLINE void TPwm_stop(TPwm *handle)   {handle->functions.stop(handle); }
#endif

#endif /* TPWM_H_ */
