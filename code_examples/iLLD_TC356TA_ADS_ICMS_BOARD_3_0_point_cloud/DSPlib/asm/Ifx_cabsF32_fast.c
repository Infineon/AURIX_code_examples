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

#include "dsplib.h"
#include "IfxAsm_Tricore.h"
#include "dsplib-internal.h"

#define     aY          	_A4  	/* a4 Ptr to input vector			 	  */
#define     aX          	_A5    	/* a5 Ptr to output vector				  */
#define     nElements		_D4     /* number of elements in vector 		  */
#define 	resSqrt			_D2		/* registers needed for sqrt computations */
#define		a				_D5		/* needed variables for sqrt computations */
#define 	x				_D6		/* -									  */
#define 	x2				_D8		/* -									  */
#define 	a_2				_D11	/* -									  */
#define 	lc				_A2		/* -									  */
#define 	c1_5			_D10	/* -									  */
#define		t				_D7		/* -									  */

#if defined(__GNUC__)
	#pragma section ".cpu0_psram" awx
#elif defined(__TASKING__)
	#pragma section code "cpu0_psram"
#endif

void Ifx_cabsF32_fast (struct Ifx_cabsF32State * state){
	/* Fetch inputs
	 * 		float32 * dst		--> offset 4
	 * 		cfloat32 * src		--> offset 8
	 * 		uint32 n			--> offset 12
	 */

IFXASM_ALIGNMENT_8();

	LD_W(nElements, [_A4]12);
	LD_A(aX,[_A4]8);
	LD_A(aY,[_A4]4);
	LD_D(_E0,[aX+]8);					/* Load X = a0 + j.b0 	*/
	ADD(nElements,nElements,_N(-1));
	MOV_A(_A12,nElements);

IFXASM_LABEL(loop4);
	MUL_F(_D0,_D0,_D0);					/* a0^2 				*/
	MUL_F(_D1,_D1,_D1);					/* b0^2					*/
	ADD_F(a,_D1,_D0);					/* a0^2 + b0^2 			*/
	JEQ(a,_N(0),a_0);		

/* compute SQRT */
	MOV_H(a_2,_N(48896));
	QSEED_F(x,a);
	MUL_F(a_2,a_2,a);
	MUL_F(x2,x,x);
	MOV_H(c1_5,_N(16320));
	MADD_F(t,c1_5,a_2,x2);
	MUL_F(x,x,t);
	MUL_F(x2,x,x);
	MADD_F(t,c1_5,a_2,x2);
	LD_D(_E0,[_A5+]8);					/* Load next X = ai + j.bi 	*/
	MUL_F(x,x,t);
	MUL_F(resSqrt,a,x);
	ST_W([aY+]4,resSqrt);
	LOOP(_A12,loop4);
	RET();

/* case 0 */
IFXASM_LABEL(a_0);
	LD_D(_E0,[_A5+]8);					/* Load next X = ai + j.bi 	*/
	MOV_H(resSqrt,_N(0));
	ST_W([aY+]4,resSqrt);
	LOOP(_A12,loop4);
	RET();

}


#if defined(__GNUC__)
	#pragma section
#elif defined(__TASKING__)
	#pragma section code
#endif

#undef  aX
#undef  aY
#undef  nElements
#undef 	resSqrt
#undef	a
#undef 	x
#undef 	x2
#undef 	a_2
#undef 	lc
#undef 	c1_5
#undef	t
