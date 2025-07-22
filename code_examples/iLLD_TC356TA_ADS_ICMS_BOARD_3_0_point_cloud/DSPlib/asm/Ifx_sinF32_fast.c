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

#define 	result  	_D2
#define 	x       	_D4
#define 	sign    	_D5
#define 	scale   	_D6
#define 	a       	_D8
#define 	b       	_D9
#define 	ab      	_E8
#define 	idx     	_D7
#define 	M_PI_2  	_D10
#define 	M_PI    	_D11
#define 	M_2PI   	_D12
#define 	N_M_PI_2 	_D13
#define 	consts1 	_E10
#define 	consts2 	_E12
#define 	sinTable 	_A2
#define 	constTable	_A3

/* struct Ifx_sinTableF32_t Ifx_sinTableF32[IFX_SIN_TABLE_N]; */
					
IFXASM_ALIGNMENT_8();
__asm
(
"consts:\n"
"\t.BYTE   219,15,201,63,219,15,73,64\n"
"\t.BYTE   219,15,201,64,131,249,162,66"
);


float32 Ifx_sinF32_fast(float32 xa){

	IFXASM_ALIGNMENT_8();

	MOVH_A(sinTable,_HI(Ifx_sinTableF32));
	LEA(sinTable,[sinTable]_LO(Ifx_sinTableF32));
	MOVH_A(constTable,_HI(consts));
	LEA(constTable,[constTable]_LO(consts));
	LD_D(consts1,[constTable+]8);
	LD_D(consts2,[constTable]);
	MOV_H(sign,_N(16256));
	INS_T(sign,sign,31,x,31);
	INS_T(x,x,31,sign,0);
	MOV(scale,M_2PI);

IFXASM_LABEL(scale_loop);
	CMP_F(_D15,x,scale);
	JZ_T(_D15,2,x_within_scale);
	SUB_F(x,x,scale);
	ADD_F(scale,scale,scale);

IFXASM_LABEL(x_within_scale);
	CMP_F(_D15,x,M_PI);
	JZ_T(_D15,2,x_less_than_m_pi);
	INSN_T(sign,sign,31,sign,31);
	SUB_F(x,x,M_PI);

IFXASM_LABEL(x_less_than_m_pi);
	CMP_F(_D15,x,M_PI_2);
	JNZ_T(_D15,0,x_less_than_m_pi_2);
	JNZ_T(_D15,1,x_m_pi_2);
	SUB_F(x,M_PI,x);


IFXASM_LABEL(x_less_than_m_pi_2);
	MUL_F(idx,x,N_M_PI_2);
	FTOUZ(idx,idx);
	ADDSC_A(sinTable,sinTable,idx,_N(3));
	LD_D(ab,[sinTable]);
	MADD_F(result,b,a,x);
	INS_T(result,result,31,sign,31);
	RET();

IFXASM_LABEL(x_m_pi_2);
	MOV_H(result,_N(0x3F80));
	RET();
}
