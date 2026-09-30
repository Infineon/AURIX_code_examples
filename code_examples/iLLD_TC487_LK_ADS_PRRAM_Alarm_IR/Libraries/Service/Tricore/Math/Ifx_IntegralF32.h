/**
 * \file Ifx_IntegralF32.h
 * \brief Discrete integral approximation
 * \ingroup library_srvsw_sysse_math_f32_integral
 *
 *
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
 * \defgroup library_srvsw_sysse_math_f32_integral Discrete Integral Approximation
 * \ingroup library_srvsw_sysse_math_f32
 *
 */

#ifndef IFX_INTEGRALF32_H
#define IFX_INTEGRALF32_H 1

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
