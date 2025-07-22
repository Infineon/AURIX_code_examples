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


void Ifx_mtxHrmComplexF32_fast (uint32 m, uint32 n, cfloat32 * hrm, cfloat32 * mtx){

	IFXASM_ALIGNMENT_8();

	JEQ(_D4,_N(0),done);
	JEQ(_D5,_N(0),done);
	MUL(_D11,_D4,_D5);
	ADD(_D14,_D4,_N(-1));
	ADD(_D15,_D5,_N(-1));
	MOV_A(_A2,_D14);
	SH(_D12,_D4,_N(3));
	RSUB(_D11,_D11,_N(1));
	SH(_D11,_D11,_N(3));
	MOV_A(_A7,_D12);
	MOV_H(_D13,_N(32768));
	MOV_A(_A6,_D11);
	LD_D(_E0,[_A5+]8);


IFXASM_LABEL(loop1);
	MOV_A(_A3,_D15);

IFXASM_LABEL(loop2);
	XOR(_D1,_D13);
	ST_D([_A4],_E0);
	LD_D(_E0,[_A5+]8);
	ADD_A_3ARGS(_A4,_A4,_A7);
	LOOP(_A3,loop2);
	ADD_A_3ARGS(_A4,_A4,_A6);
	LOOP(_A2,loop1);

IFXASM_LABEL(done);
	RET();

}
