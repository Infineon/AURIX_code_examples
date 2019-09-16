/**
 * \file Ifx_IntegralF32.c
 * \brief Discrete integral approximation
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
