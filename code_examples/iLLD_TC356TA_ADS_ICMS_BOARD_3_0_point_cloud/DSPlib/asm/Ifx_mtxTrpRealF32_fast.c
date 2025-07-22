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


void Ifx_mtxTrpRealF32_fast (uint32 m, uint32 n, float32 * trp, float32 * mtx){

	IFXASM_ALIGNMENT_8();

	SUB_A(_A10,_N(16));
	ADDSC_A(_A6,_A5,_D5,_N(2));
	SH(_D15,_D5,_N(-3));
	ADD_2ARGS(_D15,_N(-1));
	ST_W([_A10]0,_D15);
	AND(_D15,_D5,_N(7));
	ADD_2ARGS(_D15,_N(-1));
	ST_W([_A10]4,_D15);
	SH(_D15,_D4,_N(-3));
	ADD_2ARGS(_D15,_N(-1));
	ST_W([_A10]8,_D15);
	AND(_D15,_D4,_N(7));
	ADD_2ARGS(_D15,_N(-1));
	ST_W([_A10]12,_D15);
	MOV(_D14,_N(0));
	SH_LT(_D14,_D4,_N(8));
	SH_LT(_D14,_D5,_N(8));
	AND(_D15,_D5,_N(7));
	SH_EQ(_D14,_D15,_N(0));
	AND(_D15,_D4,_N(7));
	SH_EQ(_D14,_D15,_N(0));
	SH(_D15,_D4,_N(2));
	MOV_A(_A7,_D15);
	SH(_D15,_D5,_N(3));
	ADD(_D15,_D15,_N(-32));
	MOV_A(_A2,_D15);
	SH(_D15,_D4,_N(3));
	SUB_2ARGS(_D15,_D4);
	ADD_2ARGS(_D15,_N(-2));
	SH_2ARGS(_D15,_N(2));
	MOV_A(_A3,_D15);
	SH(_D6,_D5,_N(3));
	RSUB(_D6,_D6,_N(8));
	SH(_D7,_D4,_N(3));
	ADD(_D7,_D7,_N(-8));
	MUL(_D8,_D4,_D5);
	JNZ_T(_D14,3,skip_loop1);
	LD_A(_A12,[_A10]8);

IFXASM_LABEL(loop1);
	JNZ_T(_D14,2,skip_loop2);
	LD_A(_A13,[_A10]0);

IFXASM_LABEL(loop2);
	MOV_A(_A14,_N(3));

IFXASM_LABEL(loop3);
	LD_D(_E0,[_A5+]8);
	LD_D(_E10,[_A6+]8);
	LD_D(_E2,[_A5+]8);
	XOR(_D10,_D1);
	LD_D(_E12,[_A6+]8);
	XOR(_D1,_D10);
	ST_D([_A4],_E0);
	XOR(_D10,_D1);
	ADD_A(_A4,_A7);
	ST_D([_A4],_E10);
	XOR(_D12,_D3);
	ADD_A(_A4,_A7);
	XOR(_D3,_D12);
	LD_D(_E0,[_A5+]8);
	XOR(_D12,_D3);
	LD_D(_E10,[_A6+]8);
	ST_D([_A4],_E2);
	ADD_A(_A4,_A7);
	ST_D([_A4],_E12);
	XOR(_D10,_D1);
	ADD_A(_A4,_A7);
	XOR(_D1,_D10);
	LD_D(_E2,[_A5+]8);
	XOR(_D10,_D1);
	LD_D(_E12,[_A6+]8);
	ST_D([_A4],_E0);
	ADD_A(_A4,_A7);
	ST_D([_A4],_E10);
	XOR(_D12,_D3);
	ADD_A(_A4,_A7);
	XOR(_D3,_D12);
	ADD_A(_A5,_A2);
	XOR(_D12,_D3);
	ST_D([_A4],_E2);
	ADD_A(_A4,_A7);
	ST_D([_A4],_E12);
	SUB_A_3ARGS(_A4,_A4,_A3);
	ADD_A(_A6,_A2);
	LOOP(_A14,loop3);
	ADDSC_A(_A5,_A5,_D6,_N(2));
	ADDSC_A(_A6,_A6,_D6,_N(2));
	ADDSC_A(_A4,_A4,_D7,_N(2));
	LOOP(_A13,loop2);

IFXASM_LABEL(skip_loop2);
	JNZ_T(_D14,1,skip_loop4);
	LD_A(_A13,[_A10]4);

IFXASM_LABEL(loop4);
	MOV_A(_A14,_N(3));

IFXASM_LABEL(loop5);
	LD_W(_D0,[_A5+]32);
	ADD_A(_A5,_A2);
	LD_W(_D1,[_A6+]32);
	ADD_A(_A6,_A2);
	ST_D([_A4+]8,_E0);
	LOOP(_A14,loop5);
	SH(_D15,_D5,_N(3));
	RSUB(_D15,_D15,_N(1));
	ADD(_D9,_D4,_N(-8));
	ADDSC_A(_A5,_A5,_D15,_N(2));
	ADDSC_A(_A6,_A6,_D15,_N(2));
	ADDSC_A(_A4,_A4,_D9,_N(2));
	LOOP(_A13,loop4);

IFXASM_LABEL(skip_loop4);
	SH(_D15,_D5,_N(3));
	SUB(_D15,_D15,_D5);
	RSUB(_D9,_D8,_N(8));
	ADDSC_A(_A5,_A5,_D15,_N(2));
	ADDSC_A(_A6,_A6,_D15,_N(2));
	ADDSC_A(_A4,_A4,_D9,_N(2));
	LOOP(_A12,loop1);

IFXASM_LABEL(skip_loop1);
	JNZ_T(_D14,0,skip_loop6);
	LD_A(_A12,[_A10]12);

IFXASM_LABEL(loop6);
	JNZ_T(_D14,2,skip_loop7);
	LD_A(_A13,[_A10]0);

IFXASM_LABEL(loop7);
	MOV_A(_A14,_N(3));

IFXASM_LABEL(loop8);
	LD_D(_E0,[_A5+]8);
	ST_W([_A4],_D0);
	ADD_A(_A4,_A7);
	ST_W([_A4],_D1);
	ADD_A(_A4,_A7);
	LOOP(_A14,loop8);
	LOOP(_A13,loop7);

IFXASM_LABEL(skip_loop7);
	JNZ_T(_D14,1,skip_loop9);
	LD_A(_A13,[_A10]4);

IFXASM_LABEL(loop9);
	LD_W(_D0,[_A5+]4);
	ST_W([_A4],_D0);
	ADD_A(_A4,_A7);
	LOOP(_A13,loop9);

IFXASM_LABEL(skip_loop9);
	RSUB(_D15,_D8,_N(1));
	ADDSC_A(_A4,_A4,_D15,_N(2));
	LOOP(_A12,loop6);

IFXASM_LABEL(skip_loop6);
	RET();


}
