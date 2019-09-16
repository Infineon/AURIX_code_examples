/**
 * \file Ifx_IntegralF32.h
 * \brief Discrete integral approximation
 * \ingroup library_srvsw_sysse_math_f32_integral
 *
 *
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
 * \defgroup library_srvsw_sysse_math_f32_integral Discrete Integral Approximation
 * \ingroup library_srvsw_sysse_math_f32
 *
 */

#ifndef INTEGRAL_H
#define INTEGRAL_H

#include "Ifx_Cf32.h"

/** \brief Integrator object for float32 data type */
typedef struct
{
    float32 uk;
    float32 ik;
    float32 delta;
} Ifx_IntegralF32;

/** \brief Integrator object for cfloat32 data type */
typedef struct
{
    cfloat32 uk;
    cfloat32 ik;
    float32  delta;
} Ifx_ClpxFloat32_Integral;

/** \addtogroup library_srvsw_sysse_math_f32_integral
 * \{ */

/** \brief Initialize the integrator object
 * \param ci Pointer to the integrator object
 * \param gain Integrator gain
 * \param Ts Sampling period */
void Ifx_IntegralF32_init(Ifx_IntegralF32 *ci, float32 gain, float32 Ts);

/** \brief Step function of the integrator object
 * \param ci Pointer to the integrator object
 * \param ik input value
 * \return most actual integrator value */
float32 Ifx_IntegralF32_step(Ifx_IntegralF32 *ci, float32 ik);

/** \brief Reset the integrator object
 * \param ci Pointer to the integrator object */
void Ifx_IntegralF32_reset(Ifx_IntegralF32 *ci);

/** \brief Initialize the integrator object
 * \param ci Pointer to the integrator object
 * \param gain Integrator gain
 * \param Ts Sampling period */
void Ifx_ClpxFloat32_Integral_init(Ifx_ClpxFloat32_Integral *ci, float32 gain, float32 Ts);

/** \brief Step function of the integrator object
 * \param ci Pointer to the integrator object
 * \param ik input value
 * \return most actual integrator value */
cfloat32 Ifx_ClpxFloat32_Integral_step(Ifx_ClpxFloat32_Integral *ci, cfloat32 ik);

/** \brief Reset the integrator object
 * \param ci Pointer to the integrator object */
void Ifx_ClpxFloat32_Integral_reset(Ifx_ClpxFloat32_Integral *ci);

/**\}*/

#endif /* INTEGRAL_H */
