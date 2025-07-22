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


#define factor 		_D6		/* Scaling factor */

#if defined(__GNUC__)
	#pragma section ".cpu0_psram" awx
#elif defined(__TASKING__)
	#pragma section code "cpu0_psram"
#endif

IFXASM_ALIGNMENT_4();
__asm
(
"table:\n"
"\t.WORD   left0\n"
"\t.WORD   left1\n"
"\t.WORD   left2\n"
"\t.WORD   left3"
);

void Ifx_mtxScalingComplexF32_fast(uint32 m, uint32 n, float32 scale, cfloat32 * dst, cfloat32 * src){
	
	IFXASM_ALIGNMENT_8();

	SH(_D4,_D4,_N(1));
	MULS_U(_D12,_D4,_D5);
	MOVH_A(_A13,_HI(table));
	LD_D(_E0,[_A5+]8);
	LEA(_A13,[_A13]_LO(table));
	AND(_D13,_D12,_N(3));

	SH(_D15,_D12,_N(-2));
	LD_D(_E2,[_A5+]8);
	ADD(_D15,_D15,_N(-1));
	ADDSC_A(_A13,_A13,_D13,_N(2));
	JEQ(_D15,_N(-1),leftovers);
	MOV_A(_A12,_D15);

IFXASM_LABEL(loop4);
	MUL_F(_D4,_D0,factor);
	MUL_F(_D5,_D1,factor);
	ST_D([_A4+]8,_E4);
	MUL_F(_D10,_D2,factor);
	LD_D(_E0,[_A5+]8);
	MUL_F(_D11,_D3,factor);
	ST_D([_A4+]8,_E10);
	LD_D(_E2,[_A5+]8);
	LOOP(_A12,loop4);
	JNE(_D13,_N(0),leftovers);
	RET();

IFXASM_LABEL(leftovers);
	LD_A(_A13,[_A13]);
	JI(_A13);

IFXASM_LABEL(left3);
	MUL_F(_D10,_D2,factor);
	ST_W([_A4]8,_D10);

IFXASM_LABEL(left2);
	MUL_F(_D5,_D1,factor);
	ST_W([_A4]4,_D5);

IFXASM_LABEL(left1);
	MUL_F(_D4,_D0,factor);
	ST_W([_A4]0,_D4);

IFXASM_LABEL(left0);
	RET();
}

#if defined(__GNUC__)
	#pragma section
#elif defined(__TASKING__)
	#pragma section code
#endif

#undef factor
