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

#define     W16         2          /* Size of halfword in bytes */

#define     lX          _D4        /* wArg1-d4 Real input value X */
#define     aH          _A2        /* Ptr to Coeff-Buffer */
#define     sR          _D2        /* wRtn-d2 Return register */
#define     lH          _D5        /* Coefficients */
#define     lAcc        _D12       /* Result of polynomial calculation */
#define     sShCnt      _D6        /* Shift count */
#define     sScale      _D7        /* Scaling factor */
#define     dTmp        _D15       /* Generic temporary Data-Reg */
#define     aSqrt2      _A4        /* Ptr to SqrtTab */
#define     lMult       _D8        /* Multiplying factor */


	IFXASM_ALIGNMENT_4();
	__asm
	(
		"CoeffTab:   .word   0x072D0013\n"
		"			.word   0xDDAA0019\n"
		"			.word   0x46D601FF\n"
		"			.word   0xA9ECFE9B\n"
		"			.word   0x5D1CFFEA\n"
		"			.word   0x0D490024"
	);


	IFXASM_ALIGNMENT_4();
	__asm
	(
		"SqrtTable:  .word   0x7fffffff\n"
		"			.word   0x5a827999\n"
		"			.word   0x40000000\n"
		"           .word   0x2d413ccc\n"
		"           .word   0x20000000\n"
		"           .word   0x16a09e66\n"
		"           .word   0x10000000\n"
		"           .word   0x0b504f33\n"
		"           .word   0x08000000\n"
		"           .word   0x04000000\n"
		"           .word   0x02d413cc\n"
		"           .word   0x02000000\n"
		"           .word   0x016a09e6\n"
		"           .word   0x01000000\n"
		"           .word   0x00b504f3"
	);

sint16 Ifx_sqrtQ15(sint32 x ){
	IFXASM_ALIGNMENT_8();

	CLS(sShCnt,lX);
	MOVH_A(aH,_HI(CoeffTab));
	LEA(aH,[aH]_LO(CoeffTab));
	ADD(sScale,sShCnt,_N(-15));
	LD_W(lAcc,[aH+]2*W16);
	SHA(lX,lX,sShCnt);
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,lX,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,lX,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,lX,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,lX,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,lX,_N(1));
	MOVH_A(aSqrt2,_HI(SqrtTable));
	LEA(aSqrt2,[aSqrt2]_LO(SqrtTable));
	JLTZ(sScale,SqrtGT1);
	ADDSC_A(aSqrt2,aSqrt2,sScale,_N(2));
	LD_W(lMult,[aSqrt2+]);
	MUL_Q(lAcc,lAcc,lMult,_N(1));
	SHA(sR,lAcc,_N(-22));
	RET();

IFXASM_LABEL(SqrtGT1);
	ADDSC_A(aSqrt2,aSqrt2,sShCnt,_N(2));
	LD_W(lMult,[+aSqrt2]2*W16);
	MUL_Q(lAcc,lAcc,lMult,_N(1));
	SHA(sR,lAcc,_N(-14));
	RET();

}
