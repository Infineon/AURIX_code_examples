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

#define     W16         2         /* Size of halfword in bytes */

#define     lX          _D4        /* wArg1-d4 Real input value X */
#define     lAbs        _D3        /* Stores |X| or 1/|X| */
#define     X1Q31       _D3        /* Stores |X| or 1/|X| in 1Q31 format */
#define     aH          _A2        /* Ptr to Coefficients */
#define     lH          _D6        /* Coefficients */
#define     lAcc        _D2        /* Result of polynomial calculation */
#define     sR          _D2        /* wRtn-d2 Return register */
#define     lNum        _D9        /* Stores 1 in 16Q16 format */
#define     lSign       _D15       /* Sign of the input */
#define     lZero       _D12       /* Stores zero */
#define     llDivRes    _E8        /* Result of division */
#define     lQuo        _D8        /* Quotient */
#define     lRem        _D9        /* Reminder */
#define     lPi         _D13       /* Stores constant pi */
#define     dTmp        _D5        /* Generic temporary Data-Reg */
#define     dTmp1       _D7        /* V1.22 Generic temporary Data-Reg */
#define     llTmp       _E10       /* Generic temporary Data-Reg-Pair */


IFXASM_ALIGNMENT_4();
__asm
(
	"ConstTab:   .word   0xfed3e0bd\n"	/* -0.009159 - H(5) */
	"			.word   0x08c5fbf8\n"	/* 0.068542  - H(4) */
	"			.word   0xef3e681a\n" 	/* -0.130908 - H(3) */
	"			.word   0x006c97d8\n" 	/* 0.003314  - H(2) */
	"			.word   0x28bc83a9\n"	/* 0.318253  - H(1) */
	"			.word   0x6487ED50" 	/* This is the constant pi in 3Q29 form */
);

sint16 Ifx_atanQ15(sint32 x){

	IFXASM_ALIGNMENT_8();

	ABS(lAbs,lX);
	MOVH_A(aH,__HI(ConstTab));
	LEA(aH,[aH]_LO(ConstTab));
	NE(lSign,lX,lAbs);
	EXTR(dTmp,lAbs,_N(16),_N(16));
	MOV_H(lZero,_N(0x0000));
	JEQ(dTmp,lZero,Arctan_Lt1);

	MOV(lQuo,_N(0x0000));
	MOV_H(lRem,_N(0x0001));
	DVSTEP(llTmp,llDivRes,lAbs);
	DVSTEP(llDivRes,llTmp,lAbs);
	DVSTEP(llTmp,llDivRes,lAbs);
	DVSTEP(llDivRes,llTmp,lAbs);
	DEXTR(X1Q31,lZero,lQuo,_N(31));
	J(Arctan_Eqn);

IFXASM_LABEL(Arctan_Lt1);
	SH(X1Q31,lAbs,_N(15));

IFXASM_LABEL(Arctan_Eqn);
	LD_W(lAcc,[aH+]2*W16);
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,X1Q31,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,X1Q31,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,lAcc,X1Q31,_N(1));
	LD_W(lH,[aH+]2*W16);
	MADD_Q(lAcc,lH,sR,X1Q31,_N(1));
	MUL_Q(lAcc,lAcc,X1Q31,_N(1));
	LD_W(lPi,[aH+]2*W16);
	JEQ(dTmp,lZero,Arctan_Mpi);
	MOV_H(dTmp,_N(0x4000));
	SUB(lAcc,dTmp,lAcc);

IFXASM_LABEL(Arctan_Mpi);
	MUL_Q(lAcc,lAcc,lPi,_N(1));
	SH(sR,lAcc,_N(1));
	JEQ(lSign,lZero,Arctan_Ret);
	RSUB(sR,sR,_N(0));

IFXASM_LABEL(Arctan_Ret);
	SHA(sR,sR,_N(-16));
	RET();
}
