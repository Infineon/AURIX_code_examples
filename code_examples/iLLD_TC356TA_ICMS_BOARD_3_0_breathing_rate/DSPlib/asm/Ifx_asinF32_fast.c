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


Ifx_asinTableF32_t Ifx_asinTableF32_2[IFX_ASIN_TABLE_N];

float32 Ifx_asinF32_fast (float32 a)
{
	IFXASM_ALIGNMENT_8();

	MOV_H(_D15,_N(16256));
	INS_T(_D3,_D4,31,_D15,0);
	CMP_F(_D15,_D3,_D15);
	JZ_T(_D15,0,result_is_nan);
	MOV_H(_D15,_N(17152));
	MUL_F(_D5,_D3,_D15);
	MOVH_A(_A2,__HI(Ifx_asinTableF32));
	LEA(_A2,[_A2]__LO(Ifx_asinTableF32));
    //MOVH_A(_A2,#@HIS(Ifx_asinTableF32));
    //LEA(_A2,[_A2]@LOS(Ifx_asinTableF32));
	FTOIZ(_D5,_D5);
	ADDSC_A(_A2,_A2,_D5,_N(3));
	LD_D(_E8,[_A2]);
	INSN_T(_D9,_D9,31,_D4,31);
	MADD_F(_D2,_D9,_D4,_D8);
	RET();

IFXASM_LABEL(result_is_nan);
	MOV_H(_D2,_N(32768));
	ADD(_D2,_D2,_N(-1));
	RET();

}
