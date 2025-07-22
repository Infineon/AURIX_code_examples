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

_IFXASM_CODE_SECTION(CODE,dsplib,text);
EXTERN_ASM("Ifx_sinF32_fast");
EXTERN_ASM("Ifx_cosF32_fast");

float32 Ifx_tanF32_fast(float32 x){
	IFXASM_ALIGNMENT_8();
	MOV(_D14,_D4);
	CALL(Ifx_sinF32_fast);
	MOV(_D13,_D2);
	MOV(_D4,_D14);
	CALL(Ifx_cosF32_fast);
	DIV_F(_D2,_D13,_D2);
	RET();

}
