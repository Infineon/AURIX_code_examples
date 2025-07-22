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


float32 Ifx_vecAbsQ15F32_fast(uint16_least n, sint16 *x){

	IFXASM_ALIGNMENT_8();

	MOV(_E12,_N(0));
	MOVH_A(_A2,_HI(table));
	AND(_D7,_D4,_N(7));
	LEA(_A2,[_A2]_LO(table));
	ADDSC_A(_A2,_A2,_D7,_N(2));
	SH(_D15,_D4,_N(-3));
	LD_D(_E8,[_A4+]8);
	ADD_2ARGS(_D15,_N(-1));
	LD_A(_A2,[_A2]);
	JLT_U(_D4,_N(8),skip_loop8);
	MOV_A(_A3,_D15);

IFXASM_LABEL(loop8);
	MADDM_H(_E12,_E12,_D8,_D8UL,_N(0));
	LD_D(_E10,[_A4+]8);
	MADDM_H(_E12,_E12,_D9,_D9UL,_N(0));
	MADDM_H(_E12,_E12,_D10,_D10UL,_N(0));
	LD_D(_E8,[_A4+]8);
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
	MADDM_H(_E12,_E12,_D11,_D11UL,_N(0));

IFXASM_LABEL(rest6);
	MADDM_H(_E12,_E12,_D10,_D10UL,_N(0));

IFXASM_LABEL(rest4);
	MADDM_H(_E12,_E12,_D9,_D9UL,_N(0));

IFXASM_LABEL(rest2);
	MADDM_H(_E12,_E12,_D8,_D8UL,_N(0));

IFXASM_LABEL(rest0);
IFXASM_LABEL(have_sum);
	UTOF(_D12,_D12);
	ITOF(_D13,_D13);
	MOV_H(_D10,_N(10368));
	MUL_F(_D12,_D12,_D10);
	MOV_H(_D11,_N(14464));
	MADD_F(_D4,_D12,_D13,_D11);
	J(Ifx_sqrtF32_fast);

}
