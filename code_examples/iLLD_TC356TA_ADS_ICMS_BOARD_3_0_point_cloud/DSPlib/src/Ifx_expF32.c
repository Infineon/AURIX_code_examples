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
/*! \file Ifx_expF32.c
 *
 * \brief calculates exponential function.
 *
 * Calculates e^x
 *
 */

#include "dsplib-internal.h"

static float32
Ifx_expF32_ref (float32 x)
{
	 return (expf(x));
}

 float32  Ifx_expF32_optimizedC(float32 x) {
	 float32 exp1=0;
	 int k=0, check=0;
	 union{
		 float f;
		 unsigned u;
	 }exp2;
	 exp2.f = 1.0;

	 //Absolute value for x<0
		if (x<0){
			x= fabsf(x);
			check=1;
		}

	 // if x> ln2
	 if(x>0.693147){
		 k = (int)(x*1.442695416f);
		 x = x-k*0.693147;
		 if(k>255)
			 k=255; //infinite
	 }

	 // 2^k
	 exp2.u = (exp2.u & 0x007FFFFF) | (k + 127) << 23;


	 exp1 = 1+x+x*x*(0.5+x*0.1666667f+x*x*0.041666667f);

	 if(check==1)
		 return 1/(exp1*exp2.f);
	 return exp1*exp2.f;

 }


float32
Ifx_expF32 (float32 x, enum Ifx_mode mode)
{
    switch (mode) {
#if IFX_TRICORE_TARGET
    case IFX_MODE_OPTIMIZED_ASM:
           return Ifx_expF32_fast (x);
#endif /* IFX_TRICORE_TARGET  */
    case IFX_MODE_OPTIMIZED_C:
    		return Ifx_expF32_optimizedC (x);
# if HAVE_LIBM
    case IFX_MODE_EXTERNAL_LIBRARY:
        return expf (x);
# endif /* HAVE_LIBM */
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        return Ifx_expF32_ref (x);
    default:
        Ifx_warnAboutUnimplementedMode (mode, "expF32");
        return Ifx_expF32_ref (x);
    }
}
