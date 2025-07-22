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
/*! \file Ifx_maxRealF32.c
 *
 * \brief maximum of F32 vector
 *
 * Finds the minimal vector value
 */

#include "dsplib-internal.h"

static void Ifx_maxRealF32_ref (struct Ifx_maxRealF32State * state)
{
    float32 * x = state->x;  /*!< IN  vector[n] input*/
    uint32  n = state->n;    /*!< IN  number of samples in vector */

	uint32 i;
	float32 ma = -IFX_INFINITY;

	for(i=0; i<n; i++)
      if ( x[i]> ma ) ma = x[i];
	state->y = ma;
}

void Ifx_maxRealF32 (struct Ifx_maxRealF32State * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    default:
        Ifx_warnAboutUnimplementedMode (mode, "maxRealF32");
    	Ifx_maxRealF32_ref (state);
        break;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
    	Ifx_maxRealF32_ref (state);
        break;
    }
}




