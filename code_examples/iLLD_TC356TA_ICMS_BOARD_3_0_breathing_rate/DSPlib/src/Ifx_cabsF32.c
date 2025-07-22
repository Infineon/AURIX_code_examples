/*****************************************************************************
*
* Copyright (C) 2022 Infineon Technologies AG. All rights reserved.
*
* Infineon Technologies AG (INFINEON) is supplying this file for use
* exclusively with Infineon's microcontroller products. This file can be freely
* distributed within development tools and software supporting such microcontroller
* products.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL, 
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
******************************************************************************/
/*! \file Ifx_cabsF32.c
 *
 * \brief calculate the norm of a vector of complex numbers
 *
 * Calculates the norm of complex numbers in a vector. E.g. vector={{3+4i},{5+6i}}
 * which is stored as vector={{3,4},{5,6}}, result={{5},{7.81}}
 *
 */

#include "dsplib-internal.h"

void
Ifx_cabsF32 (struct Ifx_cabsF32State * state)
{
    enum Ifx_mode mode = state->mode;
    float32 * dst = state->dst;
    cfloat32 * src = state->src;
    uint32 n = state->n;
    uint32 i;

    for (i=0; i<n; i++)
        dst[i] = Ifx_sqrtF32 (src[i].real*src[i].real
                              + src[i].imag*src[i].imag,
                              mode);
}
