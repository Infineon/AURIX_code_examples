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
/*! \file Ifx_sqrtRealF32.c
 *
 * \brief floating point square root
 *
 * Computes square root of elements of a 2D table or of a list (1D table)
 * Example: power of a signal
 * param[out] dst values, where the result is to be written
 * param[in] src values, of which the square-root are to be taken
 * param[in] n number of elements in the array
 */

#include "dsplib-internal.h"

void
Ifx_sqrtRealF32 (struct Ifx_sqrtRealF32State * state)
{
    float32 * dst = state->dst;
    float32 * src = state->src;
    uint32 n = state->n;
    enum Ifx_mode mode = state->mode;
    uint32 i;

    for(i=0; i<n; i++)
        dst[i] = Ifx_sqrtF32(src[i], mode);
}
