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

#define	a		_D4
#define x		_D5
#define x2		_D6
#define a_2		_D11
#define lc		_A2
#define c1_5	_D10
#define	t		_D7
#define result	_D2

float32 Ifx_sqrtF32_fast (float32 y){

	IFXASM_ALIGNMENT_8();

	JEQ(a,_N(0),a_0);
	MOV_H(a_2,_N(48896));
	QSEED_F(x,a);
	MUL_F(a_2,a_2,a);
	MUL_F(x2,x,x);
	MOV_H(c1_5,_N(16320));
	MADD_F(t,c1_5,a_2,x2);
	MUL_F(x,x,t);
	MUL_F(x2,x,x);
	MADD_F(t,c1_5,a_2,x2);
	MUL_F(x,x,t);
	MUL_F(result,a,x);
	RET();

IFXASM_LABEL(a_0);
	MOV_H(result,_N(0));
	RET();
}

