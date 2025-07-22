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

#define     ssX         _D4        /* wArg1-d4 X complex data 16-bit */
#define     ssXlu       _D4UL      /* wArg1-d4 X complex data 16-bit (lu variant) */
#define     lR          _D2        /* wRtn-d2 Return register */
#define     dTmp2       _D2        /* generic temp reg */
#define     dTmp3       _D3        /* generic temp reg */
#define     dTmp7       _D7        /* generic temp reg */
#define     llAcc       _E2        /* 64 Accumulated result */
#define     lY          _D6        /* Stores (X - 1)/2 value in poly calculation */
#define     lIndex      _D2        /* Index for the normalisation */
#define     lZero       _D4        /* stores the Zero used in poly accumulation */
#define     lH          _D8        /* Coefficient of the polynomial expansion */
#define     lPoly       _D5        /* polynomial accumulater */
#define     lRootX      _D3        /* Square root result of the i/p */
#define     aIndx       _A2        /* index to hold the address of sqrt array */
#define     aTab        _A3        /* square root table for scaling */
#define     aDataCnt    _A14       /* Vector length */

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
	"           .word   0x05a82799\n"
	"           .word   0x04000000\n"
	"           .word   0x02d413cc\n"
	"           .word   0x02000000\n"
	"           .word   0x016a09e6\n"
	"           .word   0x01000000\n"		
	"			.word   0x00b504f3\n"		
	"			.word   0x00800000\n"
	"           .word   0x005a8279\n"
	"           .word   0x00400000\n"
	"           .word   0x002d413c\n"
	"           .word   0x00200000\n"
	"           .word   0x0016a09e\n"		
	"           .word   0x00100000\n"
	"           .word   0x000b504f\n"
	"           .word   0x00080000\n"
	"           .word   0x0005a827\n"	
	"           .word   0x00040000\n"
	"           .word   0x0002d413\n"
	"           .word   0x00020000\n"
	"           .word   0x00016a09\n"
	"           .word   0x00010000\n"
	"           .word   0x0000b504\n"
	"           .word   0x00008000\n"
	"           .word   0x00000000"
);


void Ifx_cabsQ15(struct Ifx_cabsQ15State * x){


	IFXASM_ALIGNMENT_8();

	LD_W(_D15,[_A4]12);
	LD_A(_A15,[_A4]8);
	LD_A(_A12,[_A4]4);
	MOV_A(aDataCnt,_D15);
	ADD_A(aDataCnt,_N(-1));

IFXASM_LABEL(DataL);
	LD_W(ssX, [_A15+]4);
	SHA_H(ssX,ssX,_N(-1));
	MULM_H(llAcc,ssX,ssXlu,_N(1));
	DEXTR(lY,dTmp3,dTmp2,_N(16));
	MOV(lZero,_N(0));
	AND(lR,lY,lY);
	JEQ(lR,lZero,Cplxexit);
	CLS(lIndex,lY);
	SHA(lY,lY,lIndex);
	MOV_H(lH,_N(0x8000));
	SHAS(lY,lY,_N(-1));
	MOV_H(dTmp3,_N(0x4000));
	SUBS(lY,lY,dTmp3);
	SUBS(dTmp7,lY,lH);
	MSUBS_Q(lPoly,lZero,lY,lY,_N(1));
	SHAS(lRootX,lPoly,_N(-1));
	ADDS(lRootX,lRootX,dTmp7);
	MSUBS_Q(lPoly,lZero,lPoly,lY,_N(1));
	SHAS(dTmp7,lPoly,_N(-1));
	ADDS(lRootX,lRootX,dTmp7);
	MUL_Q(lPoly,lPoly,lY,_N(1));
	MOV_H(lH,_N(0x5000));
	MSUBS_Q(lRootX,lRootX,lH,lPoly,_N(1));
	MUL_Q(lPoly,lPoly,lY,_N(1));
	MOV_H(lH,_N(0x7000));
	MADDS_Q(lRootX,lRootX,lH,lPoly,_N(1));
	MOVH_A(aTab,_HI(SqrtTable));
	LEA(aTab,[aTab]_LO(SqrtTable));
	SHA_2ARGS(lIndex,_N(2));
    MOV_A(aIndx,lIndex);
    ADD_A_3ARGS(aIndx,aTab,aIndx);
    LD_W(lH,[aIndx]);
    MUL_Q(lR,lH,lRootX,_N(1));


IFXASM_LABEL(Cplxexit);
	SH(lR,lR,_N(-16));
	ST_H([_A12+]2, lR);
	LOOP(aDataCnt,DataL);
	RET();

}
