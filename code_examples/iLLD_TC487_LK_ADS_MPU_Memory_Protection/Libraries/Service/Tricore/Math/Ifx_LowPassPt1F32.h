/**
 * \file Ifx_LowPassPt1F32.h
 * \brief Low pass filter PT1
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
 * \defgroup library_srvsw_sysse_math_f32_lowpasspt1 Low-pass Filter: Type PT1
 * This module implements a PT1 low pass filter.
 * http://de.wikipedia.org/wiki/PT1-Glied
 *
 * Formula: \n
 * \f$ y_k = y_{k-1} + a * x_k - b * y_{k-1} \f$ \n
 * with \f$(T^* = \frac{T_s}{T+T_s})\f$, \f$(a = K*T^*)\f$, \f$(b = T^*)\f$
 * with \f$(T_s: Sample time)\f$, \f$(K: Gain)\f$, \f$(T = \frac{1}{\omega_0})\f$
 *
 * \ingroup library_srvsw_sysse_math_f32
 *
 */

#ifndef IFX_LOWPASSPT1F32_H
#define IFX_LOWPASSPT1F32_H 1
//------------------------------------------------------------------------------
#include "Ifx_Types.h"
//------------------------------------------------------------------------------

/** \brief PT1 object definition.
 */
typedef struct
{
    float32 a;              /**< \brief a parameter */
    float32 b;              /**< \brief b parameter */
    float32 out;            /**< \brief last output */
} Ifx_LowPassPt1F32;

/** \brief PT1 configuration */
typedef struct
{
    float32 cutOffFrequency; /**< \brief Cut off frequency */
    float32 gain;            /**< \brief Gain */
    float32 samplingTime;    /**< \brief Sampling time */
} Ifx_LowPassPt1F32_Config;

//------------------------------------------------------------------------------

/** \addtogroup  library_srvsw_sysse_math_f32_lowpasspt1
 * \{ */
IFX_EXTERN void    Ifx_LowPassPt1F32_init(Ifx_LowPassPt1F32 *filter, const Ifx_LowPassPt1F32_Config *config);
IFX_INLINE void    Ifx_LowPassPt1F32_reset(Ifx_LowPassPt1F32 *filter);
IFX_EXTERN float32 Ifx_LowPassPt1F32_do(Ifx_LowPassPt1F32 *filter, float32 input);
/** \} */

//------------------------------------------------------------------------------

/** \brief Reset the internal filter variable
 * \param filter Specifies PT1 filter.
 */
IFX_INLINE void Ifx_LowPassPt1F32_reset(Ifx_LowPassPt1F32 *filter)
{
    filter->out = 0.0;
}


//------------------------------------------------------------------------------
#endif
