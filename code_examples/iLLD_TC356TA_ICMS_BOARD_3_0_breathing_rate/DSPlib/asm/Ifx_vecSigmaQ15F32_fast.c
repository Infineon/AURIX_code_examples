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

IFXASM_ALIGNMENT_4();
__asm
(
"table:\n"
"\t.WORD   rest0\n"
"\t.WORD   rest1\n"
"\t.WORD   rest2\n"
"\t.WORD   rest3\n"
"\t.WORD   rest4\n"
"\t.WORD   rest5\n"
"\t.WORD   rest6\n"
"\t.WORD   rest7"
);


float32 Ifx_vecSigmaQ15F32_fast(uint16_least n, sint16 *v, uint16_least adj, float32 * pAvg){

	IFXASM_ALIGNMENT_8();
	MOV(_E12,_N(0));
	MOV(_E0,_N(0));
	MOVH_A(_A2,_HI(table));
	AND(_D7,_D4,_N(7));
	LEA(_A2,[_A2]_LO(table));
	MOV_U(_D3,_N(0x8000));
	ADDSC_A(_A2,_A2,_D7,_N(2));
	SH(_D15,_D4,_N(-3));
	LD_D(_E8,[_A4+]8);
	ADD_2ARGS(_D15,_N(-1));
	LD_A(_A2,[_A2]);
	JLT_U(_D4,_N(8),skip_loop8);
	MOV_A(_A3,_D15);

IFXASM_LABEL(loop8);
	MSUBM_H(_E0,_E0,_D8,_D3LL,_N(1));
	MADDM_H(_E12,_E12,_D8,_D8UL,_N(0));
	LD_D(_E10,[_A4+]8);
	MSUBM_H(_E0,_E0,_D9,_D3LL,_N(1));
	MADDM_H(_E12,_E12,_D9,_D9UL,_N(0));
	MSUBM_H(_E0,_E0,_D10,_D3LL,_N(1));
	MADDM_H(_E12,_E12,_D10,_D10UL,_N(0));
	LD_D(_E8,[_A4+]8);
	MSUBM_H(_E0,_E0,_D11,_D3LL,_N(1));
	MADDM_H(_E12,_E12,_D11,_D11UL,_N(0));
	LOOP(_A3,loop8);


IFXASM_LABEL(skip_loop8);
	JEQ(_D7,_N(0),have_sum);
	LD_D(_E10,[_A4+]8);
	JI(_A2);

IFXASM_LABEL(rest7);
	EXTR_U(_D11,_D11,_N(0),_N(16));
	J(rest8);

IFXASM_LABEL(rest5);
	EXTR_U(_D10,_D10,_N(0),_N(16));
	J(rest6);

IFXASM_LABEL(rest3);
	EXTR_U(_D9,_D9,_N(0),_N(16));
	J(rest4);

IFXASM_LABEL(rest1);
	EXTR_U(_D8,_D8,_N(0),_N(16));
	J(rest2);

IFXASM_LABEL(rest8);
	MSUBM_H(_E0,_E0,_D11,_D3LL,_N(1));
	MADDM_H(_E12,_E12,_D11,_D11UL,_N(0));

IFXASM_LABEL(rest6);
	MSUBM_H(_E0,_E0,_D10,_D3LL,_N(1));
	MADDM_H(_E12,_E12,_D10,_D10UL,_N(0));

IFXASM_LABEL(rest4);
	MSUBM_H(_E0,_E0,_D9,_D3LL,_N(1));
	MADDM_H(_E12,_E12,_D9,_D9UL,_N(0));

IFXASM_LABEL(rest2);
	MSUBM_H(_E0,_E0,_D8,_D3LL,_N(1));
	MADDM_H(_E12,_E12,_D8,_D8UL,_N(0));

IFXASM_LABEL(rest0);

IFXASM_LABEL(have_sum);
	SH(_D6,_D4,_N(16));
	MUL_U(_E10,_D12,_D6);
	SUB(_D7,_D4,_D5);
	MUL(_D7,_D4,_D7);
	MOV(_D10,_D11);
	MOV(_D11,_N(0));
	MADD_U(_E10,_E10,_D13,_D6);
	MSUB(_E10,_E10,_D1,_D1);
	MOV_H(_D14,_N(16000));
	UTOF(_D7,_D7);
	UTOF(_D10,_D10);
	UTOF(_D11,_D11);
	MOV_H(_D15,_N(12160));
	MADD_F(_D2,_D11,_D10,_D15);
	MUL_F(_D7,_D7,_D14);
	SH(_D8,_D4,_N(15));
	ITOF(_D3,_D1);
	UTOF(_D8,_D8);
	DIV_F(_D4,_D2,_D7);
	DIV_F(_D3,_D3,_D8);
	ST_W([_A5],_D3); 			
	J(Ifx_sqrtF32_fast);

}

