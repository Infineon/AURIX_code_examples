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

#define     nCol          	_D4  	/* number of columns M			 	  */
#define     nRow          	_D5  	/* number of rows N				 	  */


#if defined(__GNUC__)
	#pragma section ".cpu0_psram" awx
#elif defined(__TASKING__)
	#pragma section code "cpu0_psram"
#endif

void Ifx_mtxConjComplexF32_fast(uint32 m, uint32 n, cfloat32 * dst, cfloat32 * src){

	
	IFXASM_ALIGNMENT_8();

	SH(nCol,nCol,_N(1));				/* Double nb col because complex matrix */
	MOV_H(_D2,_N(0xBF80));				/* Load -1 in register D2 				*/

	MULS_U(_D12,nCol,nRow);				/* Calculates nb iterations = row*col	*/
	LD_D(_E0,[_A5+]8);					/* Loads first elements: src0 = a0 i.b0	*/
	AND(_D13,_D12,_N(3));

	SH(_D15,_D12,_N(-2));
	LD_D(_E6,[_A5+]8);					/* Loads 2nd elements: src1 = a1 i.b1	*/
	ADD(_D15,_D15,_N(-1));
	ADDSC_A(_A13,_A13,_D13,_N(2));
	JEQ(_D15,_N(-1),leftovers);
	MOV_A(_A12,_D15);

IFXASM_LABEL(loop4);
	MUL_F(_D1,_D1,_D2);					/* imag(dst) = imag(src) * -1			*/
	ST_D([_A4+]8,_E0);					/* stores elements in dst				*/
	MUL_F(_D7,_D7,_D2);
	LD_D(_E0,[_A5+]8);
	ST_D([_A4+]8,_E6);
	LD_D(_E6,[_A5+]8);
	LOOP(_A12,loop4);
	JNE(_D13,_N(0),leftovers);
	RET();

IFXASM_LABEL(leftovers);
	MUL_F(_D1,_D1,_D2);					/* computes last iteration in case M*N is not divisible by 2 */
	ST_D([_A4+]8,_E0);
	RET();

}

#if defined(__GNUC__)
	#pragma section
#elif defined(__TASKING__)
	#pragma section code
#endif

#undef     nCol
#undef     nRow
