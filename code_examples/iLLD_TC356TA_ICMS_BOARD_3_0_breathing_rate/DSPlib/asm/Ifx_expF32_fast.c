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

IFXASM_CODE_SECTION(CODE,dsplib,text);

float32 Ifx_expF32_fast(float32 x){

	IFXASM_ALIGNMENT_8();

	MOV_H(_D15,_N(16313));
	MOVH_A(_A2,_HI(.table));
	ADDI(_D15,_D15,_N(-21957));
	LEA(_A2,[_A2]_LO(.table));
	INS_T(_D5,_D4,31,_D15,31);
	LD_D(_E8,[_A2+]8);
	MUL_F(_D5,_D15,_D5);
	LD_D(_E10,[_A2+]8);
	FTOIZ(_D3,_D5);
	LD_D(_E12,[_A2+]8);
	MOV_H(_D2,_N(32768));
	ITOF(_D15,_D3);
	ADD(_D3,_D3,_N(-1));
	SUB_F(_D5,_D5,_D15);
	PACK(_D3,_E2,_D5);
	MUL_F(_D2,_D5,_D5);
	MADD_F(_D1,_D10,_D8,_D2);
	MADD_F(_D0,_D11,_D9,_D2);
	MADD_F(_D1,_D12,_D1,_D2);
	MADD_F(_D0,_D13,_D0,_D2);
	MADD_F(_D2,_D0,_D1,_D5);
	MOV_H(_D15,_N(16256));
	MUL_F(_D2,_D2,_D3);
	JLT(_D4,_N(0),.divide);
	RET();

IFXASM_LABEL(.divide);
	DIV_F(_D2,_D15,_D2);
	RET();
	
IFXASM_ALIGNMENT_8();
__asm
(
	".table:\n"
	"			.word   0x3af84ccc\n"
	"			.word   0x3c127b80\n"
	"			.word   0x3d64ded4\n"
	"			.word   0x3e75e514\n"
	"			.word   0x3f3172b9\n"
	"			.word   0x3f7ffffc"
);

}
