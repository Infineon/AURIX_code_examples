/**
 * \file TPwm.h
 * \brief TPWM interface
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
 * \defgroup library_srvsw_if_tpwm TPWM interface
 * \ingroup library_srvsw_if
 *
 */

#ifndef TPWM_H
#define TPWM_H 1

#include "Ifx_Types.h"

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
