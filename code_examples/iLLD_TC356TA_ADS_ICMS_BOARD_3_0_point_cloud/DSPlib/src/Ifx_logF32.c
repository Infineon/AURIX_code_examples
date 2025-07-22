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
/*! \file Ifx_logF32.c
 *
 *	\brief Calculates the natural logarithm of an F32 number
 *
 *	Algorithm: ln(1+x) = x-x^2/2+x^3/3-x^4/4+x^5/5-x^6/6
 */

#include "dsplib-internal.h"


float32
Ifx_logF32_ref (float32 x)
{
	 return (logf(x));
}

 float32 Ifx_logF32_optimizedC(float32 x) {
	 const float32 c1 = 0.5;
	 const float32 c2 = 0.333333333f;
	 const float32 c3 = 0.25;
	 const float32 c4 = 0.2;
	 const float32 c5 = 0.166666667f;

	 float32 result=0, k=0;
	 union{
		 float f;
		 unsigned u;
	 }input;
	 input.f = x;
	 int exp=0;
	 int k_int=0;

	 if(x<0){
		 input.u = 2143289344; /* NaN Not a number */
		 return input.f;
	 }
	 else{
	 exp = ((input.u & 0x7F800000) >> 23) - 127; /* read exponent */
	 k_int = -1 - exp; /* calculate new exponent */
	 input.u = (input.u & 0x007FFFFF) | (exp + k_int + 127) << 23;
	 k = k_int*0.693;

	 /* calculate result */
	 input.f = input.f - 1;
	 result = (input.f-input.f*input.f*(c1-input.f*c2+input.f*input.f*(c3-input.f*c4+input.f*input.f*c5)))-k; // ln(1+x)

	 return result;
	 }
 }


float32
Ifx_logF32 (float32 x, enum Ifx_mode mode)
{
    switch (mode) {
    case IFX_MODE_OPTIMIZED_C:
    		return Ifx_logF32_optimizedC (x);
# if HAVE_LIBM
    case IFX_MODE_EXTERNAL_LIBRARY:
        return logf (x);
# endif /* HAVE_LIBM */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        return Ifx_logF32_ref (x);
    default:
        Ifx_warnAboutUnimplementedMode (mode, "logF32");
        return Ifx_logF32_ref (x);
    }
}
