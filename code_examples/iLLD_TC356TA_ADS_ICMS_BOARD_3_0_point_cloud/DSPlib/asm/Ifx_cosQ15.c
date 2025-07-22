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

IFXASM_CODE_SECTION(DATA,dsplib,data);
IFXASM_ALIGNMENT_4();
/* Coefficients used in polynomial calculation in 1Q31 format */
__asm
(
	"ConstTab:   .word   0x3243F6A9\n"		/* pi/2 in 3Q29 format */
	"			.word   0x28BE60DB\n"		/* 1/pi in 1Q31 format */
	"			.word   0x1CCE0008\n"		/* 1.800293   - H(5) */
	"			.word   0x08B70011\n"		/* 0.5446778  - H(4) */
	"			.word   0xAACBFF48\n"		/* -5.325196  - H(3) */
	"			.word   0x0052FFFF\n"		/* 0.02026367 - H(2) */
	"			.word   0x32400000"			/* 3.140625   - H(1) */
);

IFXASM_CODE_SECTION(CODE,dsplib,text);
#define     W16         2          /* Size of halfword in bytes */
#define     lX          _D4        /* wArg1-d4 Input angle in radians */
#define     lAbs        _D3        /* Stores |pi/2 - X| */
#define     lXbyPi      _D4        /* Input angle scaled down by pi */
#define     aH          _A2        /* Ptr to Coefficients */
#define     lH          _D5        /* Coefficients */
#define     lPi         _D6        /* Stores constant pi */
#define     lPi_2       _D7        /* Stores constant pi/2 */
#define     l1_Pi       _D2        /* Stores constant 1/pi */
#define     lAcc        _D2        /* Result of polynomial calculation */
#define     sR          _D2        /* wRtn-d2 Return register */
#define     lSign       _D14       /* Sign of the input */
#define     dTmp1       _D1        /* Generic temporary Data-Reg */
#define     dTmp2       _D9        /* Generic temporary Data-Reg */



sint16 Ifx_cosQ15(sint32 x){

	IFXASM_ALIGNMENT_8();
	ABS(lAbs,lX);
	MOVH_A(aH,_HI(ConstTab));
	LEA(aH,[aH]_LO(ConstTab));
	LD_W(lPi_2,[aH+]2*W16);
	SUB(dTmp1,lPi_2,lAbs);
	ABS(lAbs,dTmp1);
	LD_W(l1_Pi,[aH+]2*W16);
	NE(lSign,lAbs,dTmp1);
	MUL_Q(lXbyPi,lAbs,l1_Pi,_N(1));
	LD_W(lAcc,[aH+]2*W16);
	SH_2ARGS(lXbyPi,_N(2));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,lXbyPi,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,lXbyPi,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,lXbyPi,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,sR,lXbyPi,_N(1));
	MUL_Q(lAcc,lAcc,lXbyPi,_N(1));
	SHAS(sR,lAcc,_N(3));
	JZ(lSign,Cos_Ret);
	RSUB(sR,sR,_N(0));

IFXASM_LABEL(Cos_Ret);
	SHAS(sR,lAcc,_N(-16));
	RET();

}
