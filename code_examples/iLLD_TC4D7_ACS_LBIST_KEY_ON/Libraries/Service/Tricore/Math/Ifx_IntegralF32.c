/**
 * \file Ifx_IntegralF32.c
 * \brief Discrete integral approximation
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
 */
#include "Ifx_IntegralF32.h"

void Ifx_IntegralF32_reset(Ifx_IntegralF32 *ci)
{
    ci->uk = 0;
    ci->ik = 0;
}


void Ifx_IntegralF32_init(Ifx_IntegralF32 *ci, float32 gain, float32 Ts)
{
    ci->delta = gain * Ts / 2;
}


float32 Ifx_IntegralF32_step(Ifx_IntegralF32 *ci, float32 ik)
{
    ci->uk = ci->uk + (ik + ci->ik) * ci->delta;
    ci->ik = ik;

    return ci->uk;
}


void Ifx_ClpxFloat32_Integral_reset(Ifx_ClpxFloat32_Integral *ci)
{
    ci->uk.real = 0;
    ci->uk.imag = 0;
    ci->ik.real = 0;
    ci->ik.imag = 0;
}


void Ifx_ClpxFloat32_Integral_init(Ifx_ClpxFloat32_Integral *ci, float32 gain, float32 Ts)
{
    Ifx_ClpxFloat32_Integral_reset(ci);
    ci->delta = gain * Ts / 2;
}


cfloat32 Ifx_ClpxFloat32_Integral_step(Ifx_ClpxFloat32_Integral *ci, cfloat32 ik)
{
    ci->uk.real = ci->uk.real + (ik.real + ci->ik.real) * ci->delta;
    ci->uk.imag = ci->uk.imag + (ik.imag + ci->ik.imag) * ci->delta;
    ci->ik      = ik;

    return ci->uk;
}
