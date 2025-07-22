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



#define result  _D2
#define x       _D4
#define x2      _D5
#define F       _D6
#define one     _D7
#define M_PI_2  _D8


float32 Ifx_atanF32_fast (float32 a)
{
	IFXASM_ALIGNMENT_8();

	MOV_H(F,_N(16016));
	MUL_F(x2,x,x);
	MOV_H(one,_N(16256));
	CMP_F(_D15,x2,one);
	JNZ_T(_D15,2,greater_than_one);
	MADD_F(_D15,one,x,_D15);
	DIV_F(result,x,_D15);
	RET();

IFXASM_LABEL(greater_than_one);

	ADD_F(result,x2,F);
	MOV_H(M_PI_2,_N(16329));
	DIV_F(result,x,result);
	ADDI(M_PI_2,M_PI_2,_N(4059));
	INS_T(M_PI_2,M_PI_2,31,x,31);
	SUB_F(result,M_PI_2,result);
	RET();

}
