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
/*! \file Ifx_convertRealQ15F32.c
 *
 * \brief converts 16-bit fixed-point numbers to 32-bit float numbers
 *
 * converts 16-bit fixed-point numbers to 32-bit float numbers
 */

#include "dsplib-internal.h"

void
Ifx_convertRealQ15F32 (struct Ifx_convertRealQ15F32State * state)
{
    sint16 * x = state->x;
    float32 * y = state->y;
    uint32 n = state->n;
    uint32 i;

    for (i=0; i<n; i++)
        y[i] = (float32) (x[i]*IFX_Q15_EPSILON);
}
