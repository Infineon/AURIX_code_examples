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
"\t.byte -5, 48, -65, -119, 126, -91, 126, -91, -65, -119, -5, 48\n"
"\t.byte 97, 127, 116, -13, -119, 125, 7, -25, 124, 122, -40, -38\n"
"\t.byte -30, 112, -86, -61, 28, 71, -109, -107, -116, 12, -97, -128\n"
"\t.byte 51, 81, 15, -99, 7, -25, 119, -126, 30, -113, -86, -61\n"
"\t.byte 40, 37, -124, -123, -109, -107, -28, -72, 15, -99, 51, 81\n"
"\t.byte 119, 125, 7, -25, 65, 118, 5, -49, 109, 106, -28, -72\n"
"\t.byte 109, 106, -28, -72, -5, 48, -65, -119, 7, -25, 119, -126\n"
"\t.byte 28, 71, -109, -107, 5, -49, -65, -119, 119, -126, 7, -25\n"
"\t.byte -7, 24, 119, -126, -65, -119, 5, -49, -28, -72, 109, 106\n"
"\t.byte 124, 122, -40, -38, 109, 106, -28, -72, 51, 81, 15, -99\n"
"\t.byte -15, 98, -51, -82, -7, 24, 119, -126, -86, -61, 30, -113\n"
"\t.byte 86, 60, 30, -113, -28, -72, -109, -107, -97, -128, -116, 12\n"
"\t.byte -116, 12, -97, -128, 119, -126, 7, -25, -40, -38, 124, 122");

IFXASM_ALIGNMENT_8();
__asm(
"shuffle:\n"
"\t.byte 0, 0, 0, 0, 4, 0, 0, 0, 8, 0, 0, 0\n"
"\t.byte 12, 0, 0, 0, 1, 0, 0, 0, 5, 0, 0, 0\n"
"\t.byte 9, 0, 0, 0, 13, 0, 0, 0, 2, 0, 0, 0\n"
"\t.byte 6, 0, 0, 0, 10, 0, 0, 0, 14, 0, 0, 0\n"
"\t.byte 3, 0, 0, 0, 7, 0, 0, 0, 11, 0, 0, 0\n"
"\t.byte 15, 0, 0, 0");

IFXASM_ALIGNMENT_8();
__asm(
"ptwiddle:\n"	
"\t.byte 0, 64, 0, 0, 0, 64, 0, 0, 0, 64, 0, 0\n"
"\t.byte 32, 59, -126, -25, 65, 45, -65, -46, 126, 24, -32, -60\n"
"\t.byte 65, 45, -65, -46, 0, 0, 1, -64, -65, -46, -65, -46\n"
"\t.byte 126, 24, -32, -60, -65, -46, -65, -46, -32, -60, 126, 24");


void Ifx_fftComplexQ15_64hp(csint16 * y,csint16 * x){

	IFXASM_ALIGNMENT_8();

		MOV_H(_D0,_N(0x1000));
		ADDI(_D0,_D0,_N(0x1000));
		MOV_H(_D1,_N(0x8001));
		ADDI(_D1,_D1,_N(-0x8000));
		MOV_AA(_A2,_A5);
		MOV_AA(_A6,_A4);
		MOV_AA(_A3,_A2);
		LD_W(_D2,[_A2+]0x4);
		LD_W(_D4,[_A2]0x3c);
		LD_W(_D6,[_A2]0x7c);
		LD_W(_D8,[_A2]0xbc);
		MOV_A(_A7,_N(0xf));

	IFXASM_LABEL(df1);
		MULR_H(_D2,_D2,_D0LL,_N(0x1));
		ST_W([_A6],_D3);
		MULR_H(_D4,_D4,_D0LL,_N(0x1));
		ST_W([_A6]0x40,_D5);
		MULR_H(_D6,_D6,_D0LL,_N(0x1));
		ST_W([_A6]0x80,_D7);
		MULR_H(_D8,_D8,_D0LL,_N(0x1));
		ST_W([_A6]0xc0,_D9);
		MSUBR_H(_D10,_D2,_D6,_D1LL,_N(0x1));
		MADDR_H(_D11,_D2,_D6,_D1LL,_N(0x1));
		MOV_AA(_A6,_A3);
		MSUBR_H(_D12,_D4,_D8,_D1LL,_N(0x1));
		MOV_AA(_A3,_A2);
		MADDR_H(_D13,_D4,_D8,_D1LL,_N(0x1));
		LD_W(_D2,[_A2+]0x4);
		MSUBR_H(_D3,_D10,_D12,_D1LL,_N(0x1));
		LD_W(_D4,[_A2]0x3c);
		MADDSUR_H(_D5,_D11,_D13,_D1UU,_N(0x1));
		LD_W(_D6,[_A2]0x7c);
		MADDR_H(_D7,_D10,_D12,_D1LL,_N(0x1));
		LD_W(_D8,[_A2]0xbc);
		MSUBADR_H(_D9,_D11,_D13,_D1UU,_N(0x1));
		LOOP(_A7,df1);
		ST_W([_A6],_D3);
		ST_W([_A6]0x40,_D5);
		ST_W([_A6]0x80,_D7);
		ST_W([_A6]0xc0,_D9);
		SHA_H(_D0,_D0,_N(0x1));
		MOV_AA(_A2,_A5);
		MOV_AA(_A6,_A4);
		MOV_AA(_A3,_A2);
		LD_W(_D2,[_A2+]0x4);
		LD_W(_D4,[_A2]0xc);
		LD_W(_D6,[_A2]0x1c);
		LD_W(_D8,[_A2]0x2c);
		MOV_A(_A7,_N(0x2));

	IFXASM_LABEL(df2_notwiddle);
		MULR_H(_D2,_D2,_D0LL,_N(0x1));
		ST_W([_A6],_D3);
		MULR_H(_D4,_D4,_D0LL,_N(0x1));
		ST_W([_A6]0x10,_D5);
		MULR_H(_D6,_D6,_D0LL,_N(0x1));
		ST_W([_A6]0x20,_D7);
		MULR_H(_D8,_D8,_D0LL,_N(0x1));
		ST_W([_A6]0x30,_D9);
		MSUBR_H(_D10,_D2,_D6,_D1LL,_N(0x1));
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
		LOOP(_A7,df2_notwiddle);
		MOVH_A(_A7,_HI(ptwiddle));
		LEA(_A7,[_A7]_LO(ptwiddle));
		LEA(_A7,[_A7]0xc);
		MULR_H(_D2,_D2,_D0LL,_N(0x1));
		ST_W([_A6],_D3);
		MULR_H(_D4,_D4,_D0LL,_N(0x1));
		ST_W([_A6]0x10,_D5);
		MULR_H(_D6,_D6,_D0LL,_N(0x1));
		ST_W([_A6]0x20,_D7);
		MULR_H(_D8,_D8,_D0LL,_N(0x1));
		ST_W([_A6]0x30,_D9);
		MSUBR_H(_D10,_D2,_D6,_D1LL,_N(0x1));
		LEA(_A2,[_A2]0x30);
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
		MOV_A(_A12,_N(0x2));

	IFXASM_LABEL(df2_twiddle_outer);
		MOV_A(_A13,_N(0x2));

	IFXASM_LABEL(df2_twiddle_inner);
		MULR_H(_D2,_D2,_D0LL,_N(0x1));
		LD_D(_E10,[_A7]0x0);
		MULR_H(_D12,_D4,_D10LL,_N(0x0));
		ST_W([_A6],_D3);
		MADDSUR_H(_D4,_D12,_D4,_D10UU,_N(0x0));
		ST_W([_A6]0x10,_D5);
		MULR_H(_D12,_D6,_D11LL,_N(0x0));
		ST_W([_A6]0x20,_D7);
		MADDSUR_H(_D6,_D12,_D6,_D11UU,_N(0x0));
		LD_W(_D13,[_A7]0x8);
		MULR_H(_D12,_D8,_D13LL,_N(0x0));
		ST_W([_A6]0x30,_D9);
		MADDSUR_H(_D8,_D12,_D8,_D13UU,_N(0x0));
		MSUBR_H(_D10,_D2,_D6,_D1LL,_N(0x1));
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
		LOOP(_A13,df2_twiddle_inner);
		MULR_H(_D2,_D2,_D0LL,_N(0x1));
		LD_D(_E10,[_A7+]0xc);
		MULR_H(_D12,_D4,_D10LL,_N(0x0));
		ST_W([_A6],_D3);
		MADDSUR_H(_D4,_D12,_D4,_D10UU,_N(0x0));
		ST_W([_A6]0x10,_D5);
		MULR_H(_D12,_D6,_D11LL,_N(0x0));
		ST_W([_A6]0x20,_D7);
		MADDSUR_H(_D6,_D12,_D6,_D11UU,_N(0x0));
		LD_W(_D13,[_A7]-0x4);
		MULR_H(_D12,_D8,_D13LL,_N(0x0));
		ST_W([_A6]0x30,_D9);
		MADDSUR_H(_D8,_D12,_D8,_D13UU,_N(0x0));
		MSUBR_H(_D10,_D2,_D6,_D1LL,_N(0x1));
		LEA(_A2,[_A2]0x30);
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
		LOOP(_A12,df2_twiddle_outer);
		ST_W([_A6],_D3);
		ST_W([_A6]0x10,_D5);
		ST_W([_A6]0x20,_D7);
		ST_W([_A6]0x30,_D9);
		SHA_H(_D0,_D0,_N(0x1));
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
		MOV_A(_A14,_N(0xf));

	IFXASM_LABEL(df3);
		MULR_H(_D2,_D2,_D0LL,_N(0x1));
		LD_D(_E10,[_A12+]0xc);
		MULR_H(_D12,_D4,_D10LL,_N(0x0));
		ST_W([_A6],_D3);
		MADDSUR_H(_D4,_D12,_D4,_D10UU,_N(0x0));
		ST_W([_A6]0x40,_D5);
		MULR_H(_D12,_D6,_D11LL,_N(0x0));
		ST_W([_A6]0x80,_D7);
		MADDSUR_H(_D6,_D12,_D6,_D11UU,_N(0x0));
		LD_W(_D13,[_A12]-0x4);
		MULR_H(_D12,_D8,_D13LL,_N(0x0));
		ST_W([_A6]0xc0,_D9);
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
		LOOP(_A14,df3);
		ST_W([_A6],_D3);
		ST_W([_A6]0x40,_D5);
		ST_W([_A6]0x80,_D7);
		ST_W([_A6]0xc0,_D9);
		RET();
}
