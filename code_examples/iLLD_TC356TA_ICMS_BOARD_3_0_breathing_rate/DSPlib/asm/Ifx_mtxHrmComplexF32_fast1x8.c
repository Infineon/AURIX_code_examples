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


void Ifx_mtxHrmComplexF32_fast1x8 (cfloat32 * hrm, cfloat32 * mtx){

	IFXASM_ALIGNMENT_8();

	LD_D(_E0,[_A5+]8);
	MOV_H(_D15,_N(32768));
	LD_D(_E2,[_A5+]8);
	XOR(_D1,_D15);
	LD_D(_E4,[_A5+]8);
	XOR(_D3,_D15);
	LD_D(_E6,[_A5+]8);
	XOR(_D5,_D15);
	ST_D([_A4+]8,_E0);
	XOR(_D7,_D15);
	ST_D([_A4+]8,_E2);
	ST_D([_A4+]8,_E4);
	ST_D([_A4+]8,_E6);
	RET();
}
