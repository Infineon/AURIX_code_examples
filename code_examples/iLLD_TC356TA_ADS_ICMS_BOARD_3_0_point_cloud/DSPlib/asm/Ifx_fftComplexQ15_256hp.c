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
"\t.byte -116, 12, -97, -128, 119, -126, 7, -25, -40, -38, 124, 122\n"
"\t.byte -11, 127, -36, -4, -40, 127, -72, -7, -90, 127, -106, -10\n"
"\t.byte 4, 117, 33, -52, -11, 85, 41, -95, 38, 40, 119, -122\n"
"\t.byte 66, 88, 77, -93, -72, -7, 40, -128, 21, -97, 101, -84\n"
"\t.byte 17, 46, -107, -120, 41, -95, 11, -86, -84, -115, -116, 57\n"
"\t.byte 9, 127, 85, -16, 41, 124, -26, -32, 107, 119, -17, -47\n"
"\t.byte 94, 111, -23, -64, -50, 65, 55, -110, 36, 3, 11, -128\n"
"\t.byte -65, 78, 24, -101, -26, -32, -41, -125, -4, -118, 33, -52\n"
"\t.byte 35, 34, -92, -124, 55, -110, 50, -66, 77, -93, 66, 88\n"
"\t.byte -29, 124, -11, -29, -75, 115, 70, -55, -24, 100, 65, -79\n"
"\t.byte -90, 104, 76, -74, 31, 43, 124, -121, -35, -35, -92, -124\n"
"\t.byte 122, 68, -35, -109, 70, -55, 75, -116, -9, -128, 85, -16\n"
"\t.byte -30, 21, -29, -127, 124, -121, -31, -44, -23, -64, 94, 111\n"
"\t.byte -119, 121, -38, -41, -49, 102, -63, -77, -76, 73, 90, -105\n"
"\t.byte -21, 96, 101, -84, -56, 18, 100, -127, -122, -69, -35, -109\n"
"\t.byte -116, 57, -84, -115, -63, -77, 49, -103, -29, -127, -30, 21\n"
"\t.byte 106, 9, 90, -128, 100, -127, 56, -19, -11, -29, -29, 124\n"
"\t.byte -40, 127, -72, -7, 97, 127, 116, -13, -100, 126, 56, -19\n"
"\t.byte -75, 115, 70, -55, 51, 81, 15, -99, 26, 31, -41, -125\n"
"\t.byte -11, 85, 41, -95, 116, -13, -97, -128, 49, -103, -63, -77\n"
"\t.byte 31, 43, 124, -121, 15, -99, -51, -82, 55, -110, -50, 65\n"
"\t.byte -100, 126, 56, -19, 124, 122, -40, -38, -75, 115, 70, -55\n"
"\t.byte -55, 109, 50, -66, 86, 60, 30, -113, -72, -7, 40, -128\n"
"\t.byte 63, 76, 49, -103, -40, -38, -124, -123, 124, -121, -31, -44\n"
"\t.byte 26, 31, -41, -125, 30, -113, -86, -61, 11, -86, -41, 94\n"
"\t.byte 41, 124, -26, -32, -30, 112, -86, -61, -41, 94, 11, -86\n"
"\t.byte -49, 102, -63, -77, 40, 37, -124, -123, -31, -44, 124, -121\n"
"\t.byte -50, 65, 55, -110, -86, -61, 30, -113, 40, -128, -72, -7\n"
"\t.byte -56, 18, 100, -127, -124, -123, -40, -38, 70, -55, -75, 115\n"
"\t.byte -124, 120, -31, -44, -15, 98, -51, -82, -50, 65, 55, -110\n"
"\t.byte -41, 94, 11, -86, -116, 12, -97, -128, -63, -77, 49, -103\n"
"\t.byte -70, 54, 75, -116, -51, -82, 15, -99, -41, -125, 26, 31\n"
"\t.byte 72, 6, 40, -128, -97, -128, 116, -13, 56, -19, -100, 126\n"
"\t.byte -90, 127, -106, -10, -100, 126, 56, -19, -29, 124, -11, -29\n"
"\t.byte 84, 114, 116, -58, 63, 76, 49, -103, -30, 21, -29, -127\n"
"\t.byte -101, 83, 21, -97, 56, -19, 100, -127, -35, -109, -122, -69\n"
"\t.byte 38, 40, 119, -122, 49, -103, -63, -77, 90, -105, -76, 73\n"
"\t.byte 29, 126, 30, -22, -124, 120, -31, -44, 94, 111, -23, -64\n"
"\t.byte 35, 108, -122, -69, -70, 54, 75, -116, 85, -16, -9, -128\n"
"\t.byte -76, 73, 90, -105, -31, -44, 124, -121, -92, -124, -35, -35\n"
"\t.byte 11, 28, 29, -125, 75, -116, 70, -55, 65, -79, -24, 100\n"
"\t.byte 92, 123, -35, -35, -55, 109, 50, -66, 66, 88, 77, -93\n"
"\t.byte -24, 100, 65, -79, 26, 31, -41, -125, 33, -52, -4, -118\n"
"\t.byte 23, 63, -94, -112, 50, -66, 55, -110, 11, -128, 36, 3\n"
"\t.byte -85, 15, -9, -128, -41, -125, -26, -32, -17, -47, 107, 119\n"
"\t.byte  107, 119, -17, -47, -41, 94, 11, -86, -116, 57, -84, -115\n"
"\t.byte -77, 92, -66, -89, 72, 6, 40, -128, 101, -84, 21, -97\n"
"\t.byte  -33, 51, -4, -118, 11, -86, 41, -95, 119, -122, 38, 40\n"
"\t.byte  36, 3, 11, -128, 40, -128, -72, -7, -106, -10, -90, 127");


IFXASM_ALIGNMENT_8(); 
__asm(
"shuffle:\n"
"\t.byte 0, 0, 0, 0, 16, 0, 0, 0, 32, 0, 0, 0\n"
"\t.byte 48, 0, 0, 0, 4, 0, 0, 0, 20, 0, 0, 0\n"
"\t.byte 36, 0, 0, 0, 52, 0, 0, 0, 8, 0, 0, 0\n"
"\t.byte 24, 0, 0, 0, 40, 0, 0, 0, 56, 0, 0, 0\n"
"\t.byte 12, 0, 0, 0, 28, 0, 0, 0, 44, 0, 0, 0\n"
"\t.byte 60, 0, 0, 0, 1, 0, 0, 0, 17, 0, 0, 0\n"
"\t.byte 33, 0, 0, 0, 49, 0, 0, 0, 5, 0, 0, 0\n"
"\t.byte 21, 0, 0, 0, 37, 0, 0, 0, 53, 0, 0, 0\n"
"\t.byte 9, 0, 0, 0, 25, 0, 0, 0, 41, 0, 0, 0\n"
"\t.byte 57, 0, 0, 0, 13, 0, 0, 0, 29, 0, 0, 0\n"
"\t.byte 45, 0, 0, 0, 61, 0, 0, 0, 2, 0, 0, 0\n"
"\t.byte 18, 0, 0, 0, 34, 0, 0, 0, 50, 0, 0, 0\n"
"\t.byte 6, 0, 0, 0, 22, 0, 0, 0, 38, 0, 0, 0\n"
"\t.byte 54, 0, 0, 0, 10, 0, 0, 0, 26, 0, 0, 0\n"
"\t.byte 42, 0, 0, 0, 58, 0, 0, 0, 14, 0, 0, 0\n"
"\t.byte 30, 0, 0, 0, 46, 0, 0, 0, 62, 0, 0, 0\n"
"\t.byte 3, 0, 0, 0, 19, 0, 0, 0, 35, 0, 0, 0\n"
"\t.byte 51, 0, 0, 0, 7, 0, 0, 0, 23, 0, 0, 0\n"
"\t.byte 39, 0, 0, 0, 55, 0, 0, 0, 11, 0, 0, 0\n"
"\t.byte 27, 0, 0, 0, 43, 0, 0, 0, 59, 0, 0, 0\n"
"\t.byte 15, 0, 0, 0, 31, 0, 0, 0, 47, 0, 0, 0\n"
"\t.byte 63, 0, 0, 0");


IFXASM_ALIGNMENT_8(); 
__asm(
"ptwiddle:\n"
"\t.byte 0, 64, 0, 0, 0, 64, 0, 0, 0, 64, 0, 0\n"
"\t.byte 32, 59, -126, -25, 65, 45, -65, -46, 126, 24, -32, -60\n"
"\t.byte 65, 45, -65, -46, 0, 0, 1, -64, -65, -46, -65, -46\n"
"\t.byte 126, 24, -32, -60, -65, -46, -65, -46, -32, -60, 126, 24\n"
"\t.byte -79, 63, -70, -7, -59, 62, -124, -13, 62, 61, 108, -19\n"
"\t.byte 113, 56, -43, -31, -114, 35, -54, -54, 70, 6, 79, -64\n"
"\t.byte -102, 40, -121, -50, -124, -13, 59, -63, -113, -57, -43, -31\n"
"\t.byte -108, 18, -62, -62, -54, -54, 114, -36, -121, -50, -102, 40\n"
"\t.byte -59, 62, -124, -13, 32, 59, -126, -25, 54, 53, 114, -36\n"
"\t.byte 54, 53, 114, -36, 126, 24, -32, -60, -124, -13, 59, -63\n"
"\t.byte -114, 35, -54, -54, -126, -25, -32, -60, 59, -63, -124, -13\n"
"\t.byte 124, 12, 59, -63, -32, -60, -126, -25, 114, -36, 54, 53\n"
"\t.byte 62, 61, 108, -19, 54, 53, 114, -36, -102, 40, -121, -50\n"
"\t.byte 121, 49, 102, -41, 124, 12, 59, -63, -43, -31, -113, -57\n"
"\t.byte 43, 30, -113, -57, 114, -36, -54, -54, 79, -64, 70, 6\n"
"\t.byte 70, 6, 79, -64, 59, -63, -124, -13, 108, -19, 62, 61");


void Ifx_fftComplexQ15_256hp(csint16 * y,csint16 * x){

	IFXASM_ALIGNMENT_8();

	MOV_H(_D0,_N(0x1000));
	ADDI(_D0,_D0,_N(0x1000));
	MOV_H(_D1,_N(0x8001));
	ADDI(_D1,_D1,_N(-0x8000));
	MOV_AA(_A2,_A5);
	MOV_AA(_A6,_A4);
	MOV_AA(_A3,_A2);
	LD_W(_D2,[_A2+]0x4);
	LD_W(_D4,[_A2]0xfc);
	LD_W(_D6,[_A2]0x1fc);
	LD_W(_D8,[_A2]0x2fc);
	LEA(_A7,0x3f);

IFXASM_LABEL(df1);
	MULR_H(_D2,_D2,_D0LL,_N(0x1));
	ST_W([_A6],_D3);
	MULR_H(_D4,_D4,_D0LL,_N(0x1));
	ST_W([_A6]0x100,_D5);
	MULR_H(_D6,_D6,_D0LL,_N(0x1));
	ST_W([_A6]0x200,_D7);
	MULR_H(_D8,_D8,_D0LL,_N(0x1));
	ST_W([_A6]0x300,_D9);
	MSUBR_H(_D10,_D2,_D6,_D1LL,_N(0x1));
	MADDR_H(_D11,_D2,_D6,_D1LL,_N(0x1));
	MOV_AA(_A6,_A3);
	MSUBR_H(_D12,_D4,_D8,_D1LL,_N(0x1));
	MOV_AA(_A3,_A2);
	MADDR_H(_D13,_D4,_D8,_D1LL,_N(0x1));
	LD_W(_D2,[_A2+]0x4);
	MSUBR_H(_D3,_D10,_D12,_D1LL,_N(0x1));
	LD_W(_D4,[_A2]0xfc);
	MADDSUR_H(_D5,_D11,_D13,_D1UU,_N(0x1));
	LD_W(_D6,[_A2]0x1fc);
	MADDR_H(_D7,_D10,_D12,_D1LL,_N(0x1));
	LD_W(_D8,[_A2]0x2fc);
	MSUBADR_H(_D9,_D11,_D13,_D1UU,_N(0x1));
	LOOP(_A7,df1);
	ST_W([_A6],_D3);
	ST_W([_A6]0x100,_D5);
	ST_W([_A6]0x200,_D7);
	ST_W([_A6]0x300,_D9);
	SHA_H(_D0,_D0,_N(0x1));
	MOV_AA(_A2,_A5);
	MOV_AA(_A6,_A4);
	MOV_AA(_A3,_A2);
	LD_W(_D2,[_A2+]0x4);
	LD_W(_D4,[_A2]0x3c);
	LD_W(_D6,[_A2]0x7c);
	LD_W(_D8,[_A2]0xbc);
	MOV_A(_A7,_N(0xe));

IFXASM_LABEL(df2_notwiddle);
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
	LOOP(_A7,df2_notwiddle);
	MOVH_A(_A7,_HI(ptwiddle));
	LEA(_A7,[_A7]_LO(ptwiddle));
	LEA(_A7,[_A7]0xc);
	MULR_H(_D2,_D2,_D0LL,_N(0x1));
	ST_W([_A6],_D3);
	MULR_H(_D4,_D4,_D0LL,_N(0x1));
	ST_W([_A6]0x40,_D5);
	MULR_H(_D6,_D6,_D0LL,_N(0x1));
	ST_W([_A6]0x80,_D7);
	MULR_H(_D8,_D8,_D0LL,_N(0x1));
	ST_W([_A6]0xc0,_D9);
	MSUBR_H(_D10,_D2,_D6,_D1LL,_N(0x1));
	LEA(_A2,[_A2]0xc0);
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
	MOV_A(_A12,_N(0x2));

IFXASM_LABEL(df2_twiddle_outer);
	MOV_A(_A13,_N(0xe));

IFXASM_LABEL(df2_twiddle_inner);
	MULR_H(_D2,_D2,_D0LL,_N(0x1));
	LD_D(_E10,[_A7]0x0);
	MULR_H(_D12,_D4,_D10LL,_N(0x0));
	ST_W([_A6],_D3);
	MADDSUR_H(_D4,_D12,_D4,_D10UU,_N(0x0));
	ST_W([_A6]0x40,_D5);
	MULR_H(_D12,_D6,_D11LL,_N(0x0));
	ST_W([_A6]0x80,_D7);
	MADDSUR_H(_D6,_D12,_D6,_D11UU,_N(0x0));
	LD_W(_D13,[_A7]0x8);
	MULR_H(_D12,_D8,_D13LL,_N(0x0));
	ST_W([_A6]0xc0,_D9);
	MADDSUR_H(_D8,_D12,_D8,_D13UU,_N(0x0));
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
	LOOP(_A13,df2_twiddle_inner);
	MULR_H(_D2,_D2,_D0LL,_N(0x1));
	LD_D(_E10,[_A7+]0xc);
	MULR_H(_D12,_D4,_D10LL,_N(0x0));
	ST_W([_A6],_D3);
	MADDSUR_H(_D4,_D12,_D4,_D10UU,_N(0x0));
	ST_W([_A6]0x40,_D5);
	MULR_H(_D12,_D6,_D11LL,_N(0x0));
	ST_W([_A6]0x80,_D7);
	MADDSUR_H(_D6,_D12,_D6,_D11UU,_N(0x0));
	LD_W(_D13,[_A7]-0x4);
	MULR_H(_D12,_D8,_D13LL,_N(0x0));
	ST_W([_A6]0xc0,_D9);
	MADDSUR_H(_D8,_D12,_D8,_D13UU,_N(0x0));
	MSUBR_H(_D10,_D2,_D6,_D1LL,_N(0x1));
	LEA(_A2,[_A2]0xc0);
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
	LOOP(_A12,df2_twiddle_outer);
	ST_W([_A6],_D3);
	ST_W([_A6]0x40,_D5);
	ST_W([_A6]0x80,_D7);
	ST_W([_A6]0xc0,_D9);
	MOV_AA(_A2,_A5);
	MOV_AA(_A6,_A4);
	MOV_AA(_A3,_A2);
	LD_W(_D2,[_A2+]0x4);
	LD_W(_D4,[_A2]0xc);
	LD_W(_D6,[_A2]0x1c);
	LD_W(_D8,[_A2]0x2c);
	MOV_A(_A7,_N(0x2));

IFXASM_LABEL(df3_notwiddle);
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
	LOOP(_A7,df3_notwiddle);
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
	MOV_A(_A12,_N(0xe));

IFXASM_LABEL(df3_twiddle_outer);
	MOV_A(_A13,_N(0x2));

IFXASM_LABEL(df3_twiddle_inner);
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
	LOOP(_A13,df3_twiddle_inner);
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
	LOOP(_A12,df3_twiddle_outer);
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
	LEA(_A14,0x3f);

IFXASM_LABEL(df4);
	MULR_H(_D2,_D2,_D0LL,_N(0x1));
	LD_D(_E10,[_A12+]0xc);
	MULR_H(_D12,_D4,_D10LL,_N(0x0));
	ST_W([_A6],_D3);
	MADDSUR_H(_D4,_D12,_D4,_D10UU,_N(0x0));
	ST_W([_A6]0x100,_D5);
	MULR_H(_D12,_D6,_D11LL,_N(0x0));
	ST_W([_A6]0x200,_D7);
	MADDSUR_H(_D6,_D12,_D6,_D11UU,_N(0x0));
	LD_W(_D13,[_A12]-0x4);
	MULR_H(_D12,_D8,_D13LL,_N(0x0));
	ST_W([_A6]0x300,_D9);
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
	LOOP(_A14,df4);
	ST_W([_A6],_D3);
	ST_W([_A6]0x100,_D5);
	ST_W([_A6]0x200,_D7);
	ST_W([_A6]0x300,_D9);
	RET();
}
