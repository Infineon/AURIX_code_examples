/**
 * \file Ifx_LowPassPt1F32.h
 * \brief Low pass filter PT1
 *
 * \version disabled
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
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

#if !defined(IFX_LOWPASSPT1F32)
#define IFX_LOWPASSPT1F32
//------------------------------------------------------------------------------
#include "Cpu/Std/Ifx_Types.h"
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
