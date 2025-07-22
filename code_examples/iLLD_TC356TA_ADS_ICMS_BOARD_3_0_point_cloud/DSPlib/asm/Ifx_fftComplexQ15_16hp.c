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

IFXASM_ALIGNMENT_8();
__asm(
"etwiddle:\n"
"\t.byte -1, 127, 0, 0, -1, 127, 0, 0, -1, 127, 0, 0\n"
"\t.byte 65, 118, 5, -49, -126, 90, 126, -91, -5, 48, -65, -119\n"
"\t.byte -126, 90, 126, -91, 0, 0, 1, -128, 126, -91, 126, -91\n"
"\t.byte -5, 48, -65, -119, 126, -91, 126, -91, -65, -119, -5, 48");
IFXASM_ALIGNMENT_8();
 __asm(
"shuffle:"
"\t.byte 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0\n"
"\t.byte 3, 0, 0, 0");
IFXASM_ALIGNMENT_8();
__asm(	
"ptwiddle:"
"\t.byte 0, 64, 0, 0, 0, 64, 0, 0, 0, 64, 0, 0");


void Ifx_fftComplexQ15_16hp(csint16 * y,csint16 * x){

	IFXASM_ALIGNMENT_8();

	MOV_H(_D0,_N(0x1000));
	ADDI(_D0,_D0,_N(0x1000));
	MOV_H(_D1,_N(0x8001));
	ADDI(_D1,_D1,_N(-0x8000));
	MOV_AA(_A2,_A5);
	MOV_AA(_A6,_A4);
	MOV_AA(_A3,_A2);
	LD_W(_D2,[_A2+]0x4);
	LD_W(_D4,[_A2]0xc);
	LD_W(_D6,[_A2]0x1c);
	LD_W(_D8,[_A2]0x2c);
	MOV_A(_A7,_N(0x3));


IFXASM_LABEL(df1);
	MULR_H(_D2,_D2,_D0LL,_N(0x1));
	ST_W([_A6],_D3);
	MULR_H(_D4,_D4,_D0LL,_N(0x1));
	ST_W([_A6]0x10,_D5);
	MULR_H(_D6,_D6,_D0UL,_N(0x1));
	ST_W([_A6]0x20,_D7);
	MULR_H(_D8,_D8,_D0UL,_N(0x1));
	ST_W([_A6]0x30,_D9);
	MSUBR_H(_D10,_D2,_D6,_D1UL,_N(0x1));
	MADDR_H(_D11,_D2,_D6,_D1LL,_N(0x1));
	MOV_AA(_A6,_A3);
	MSUBR_H(_D12,_D4,_D8,_D1LL,_N(0x1));
	MOV_AA(_A3,_A2);
	MADDR_H(_D13,_D4,_D8,_D1LL,_N(0x1));
	LD_W(_D2,[_A2+]0x4);
	MSUBR_H(_D3,_D10,_D12,_D1LL,_N(0x1));
	LD_W(_D4,[_A2]0xc);
	MADDSUR_H(_D5,_D11,_D13,_D1UU,_N(0x1));
	LD_W(_D6,[_A2]0x1c);
	MADDR_H(_D7,_D10,_D12,_D1LL,_N(0x1));
	LD_W(_D8,[_A2]0x2c);
	MSUBADR_H(_D9,_D11,_D13,_D1UU,_N(0x1));
	LOOP(_A7,df1);
	ST_W([_A6],_D3);
	ST_W([_A6]0x10,_D5);
	ST_W([_A6]0x20,_D7);
	ST_W([_A6]0x30,_D9);
	SHA_H(_D0,_D0,_N(0x2));
	MOV_AA(_A2,_A5);
	MOV_AA(_A7,_A4);
	MOV_AA(_A6,_A4);
	MOVH_A(_A12,_HI(etwiddle));
	LEA(_A12,[_A12]_LO(etwiddle));
	MOVH_A(_A13,_HI(shuffle));
	LEA(_A13,[_A13]_LO(shuffle));
	MOV_AA(_A3,_A7);
	LD_W(_D2,[_A2+]0x10);
	LD_W(_D4,[_A2]-0xc);
	LD_W(_D6,[_A2]-0x8);
	LD_W(_D8,[_A2]-0x4);
	MOV_A(_A14,_N(0x3));


IFXASM_LABEL(df2);

	MULR_H(_D2,_D2,_D0LL,_N(0x1));
	LD_D(_E10,[_A12+]0xc);
	MULR_H(_D12,_D4,_D10LL,_N(0x0));
	ST_W([_A6],_D3);
	MADDSUR_H(_D4,_D12,_D4,_D10UU,_N(0x0));
	ST_W([_A6]0x10,_D5);
	MULR_H(_D12,_D6,_D11LL,_N(0x0));
	ST_W([_A6]0x20,_D7);
	MADDSUR_H(_D6,_D12,_D6,_D11UU,_N(0x0));
	LD_W(_D13,[_A12]-0x4);
	MULR_H(_D12,_D8,_D13LL,_N(0x0));
	ST_W([_A6]0x30,_D9);
	MADDSUR_H(_D8,_D12,_D8,_D13UU,_N(0x0));
	LD_W(_D10,[_A13+]0x4);
	MSUBR_H(_D11,_D2,_D6,_D1LL,_N(0x1));
	MADDR_H(_D12,_D2,_D6,_D1LL,_N(0x1));
	ADDSC_A(_A6,_A3,_D10,_N(0x2));
	MSUBR_H(_D13,_D4,_D8,_D1LL,_N(0x1));
	MOV_AA(_A3,_A7);
	MADDR_H(_D14,_D4,_D8,_D1LL,_N(0x1));
	LD_W(_D2,[_A2+]0x10);
	MSUBR_H(_D3,_D11,_D13,_D1LL,_N(0x1));
	LD_W(_D4,[_A2]-0xc);
	MADDSUR_H(_D5,_D12,_D14,_D1UU,_N(0x1));
	LD_W(_D6,[_A2]-0x8);
	MADDR_H(_D7,_D11,_D13,_D1LL,_N(0x1));
	LD_W(_D8,[_A2]-0x4);
	MSUBADR_H(_D9,_D12,_D14,_D1UU,_N(0x1));
	LOOP(_A14,df2);

	ST_W([_A6],_D3);
	ST_W([_A6]0x10,_D5);
	ST_W([_A6]0x20,_D7);
	ST_W([_A6]0x30,_D9);
	RET();
}
