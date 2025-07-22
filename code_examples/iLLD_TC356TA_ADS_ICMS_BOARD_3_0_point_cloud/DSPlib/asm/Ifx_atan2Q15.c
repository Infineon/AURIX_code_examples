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

#define     sY          _D4       /* Y = wArg1 complex data */
#define     sX          _D5       /* X = wArg2 complex data */
#define     lR          _D2       /* wRtn result data */
#define     dTmp6       _D6       /* generic temp data */
#define     dTmp7       _D7       /* generic temp data */

#define     aIndx       _A2       /* ptr to Index */
#define     aTab        _A3       /* ptr to the coeff table */

#define     lNum        _D8       /* numerator reg */
#define     lDen        _D9       /* denominator reg */
#define     sFlag       _D3       /* flag to indicate the max (real, imag) */
#define     sCplxSign   _D10      /* stores the sign of RE:IM */
#define     llDivRes    _E6       /* stores the division result 64 bit */
#define     lDivRes     _D6       /* stores the division result 32 bit */
#define     lIndex      _D2       /* Index for normalisation */
#define     lPoly       _D15      /* polynominal accumulator */
#define     lH          _D9       /* coefficient for the taylor series */
#define     lImag       _D6       /* holds the real part of i/p data */
#define     lReal       _D7       /* holds the imag part of i/p data */

IFXASM_ALIGNMENT_4();
__asm
(
	"CoeffTab:   .word   0xfed3e0bd\n"	/* -0.009159 - H(5) */
	"			.word   0x08c5fbf8\n"	/* 0.068542  - H(4) */
	"			.word   0xef3e681a\n"	/* -0.130908 - H(3) */
	"			.word   0x006c97d8\n"	/* 0.003314  - H(2) */
	"			.word   0x28bc83a9\n"	/* 0.318253  - H(1) */
	"			.word   0x6487ED50"		/* This is the constant pi in 3Q29 form */
);

sint16 Ifx_atan2Q15(sint16 y,sint16 x){

	/* _IFXASM_CODE_SECTION(Ifx_atan2Q15,".global"),; */
	IFXASM_ALIGNMENT_8();

    /* If  sX and sY  are 0 ret 0 */
	JNZ(sX,Nzz);

	JNZ(sY,Nzz);

    /*  Both x y are 0 then ret 0 */
	MOV(lR,_N(0));

	RET();

IFXASM_LABEL(Nzz);
	ABSS(lReal,sX);

	ABSS(lImag,sY);

	MIN(lNum,lImag,lReal);  /* numerator = min(real, imag) */

	MAX(lDen,lImag,lReal);  /* denominator = max(real, imag) */

	GE(sFlag,lImag,lReal);	/* set flag if real <= imag */

    /* Special case2 abs(sX) = abs(sY) */
	MOV(lPoly,_N(0x1921));

	JEQ(lReal,lImag,DivEq);

	SH(lNum,lNum,_N(16));

	DIV(llDivRes,lNum,lDen);

	SH(lDivRes,lDivRes,_N(15));

	SH(lNum,lNum,_N(-16));

	MOVH_A(aTab,__HI(CoeffTab));

	LEA(aTab,[aTab]__LO(CoeffTab));

	LD_W(lPoly,[aTab+]4); /* lPoly = coeff5 */

	LD_W(lH,[aTab+]4); /* lH = coeff4 */

	MADD_Q(lPoly,lH,lPoly,lDivRes,_N(1));

    /* polynomial calculation */
    /* k5*Z + k4 */
	LD_W(lH,[aTab+]4); /* lH = coeff3 || */

	MADD_Q(lPoly,lH,lPoly,lDivRes,_N(1));

    /* polynomial calculation */
    /* (k5*Z + k4)Z + k3 */
	LD_W(lH,[aTab+]4); /* lH = coeff2 || */

	MADD_Q(lPoly,lH,lPoly,lDivRes,_N(1));

	/* polynomial calculation */
	/* ((k5*Z + k4)z + k3)z + k2 */
	LD_W(lH,[aTab+]4); /* lH = coeff1 || */

	MADD_Q(lPoly,lH,lPoly,lDivRes,_N(1));

    /* polynomial calculation */
    /* (((k5*Z + k4)z + k3)z + k2)z + k1 */
	MUL_Q(lPoly,lPoly,lDivRes,_N(1));

	MOV_H(lH,_N(0x4000)); /* lH = 0.5 */

	SUB(lH,lH,lPoly);

	SEL(lPoly,sFlag,lH,lPoly);
    /* if real<=imag arctan(x) = 0.5 -arctan(1/x) */
    /* lPoly = (sFlag !=0)?lH-lPoly : lPoly */

	MOV(lH,_N(0x6489));

	MUL_Q(lPoly,lPoly,lH,_N(1));

IFXASM_LABEL(DivEq);
	EXTR_U(sCplxSign,sX,_N(15),_N(1)); /* extract the sign of real */
	SH_2ARGS(sCplxSign,_N(1)); /* move the sign of real to left */
	EXTR_U(dTmp7,sY,_N(15),_N(1)); /* extract the sign */

	OR(sCplxSign,dTmp7,sCplxSign);

	JEQ(sCplxSign,_N(3),CplxIIIQuad);
    /* branch to 3rd quadrant */
	JEQ(sCplxSign,_N(2),CplxIIQuad);
    /* branch to 2nd quadrant */
	JEQ(sCplxSign,_N(1),CplxIVQuad);
    /* branch to 4rd quadrant */

IFXASM_LABEL(CplxIQuad);
	MOV(lR,lPoly); /* arctan(x) is +ve in I quadrant */
	RET();

IFXASM_LABEL(CplxIVQuad);
	MOV(lH,_N(0));
	SUB(lR,lH,lPoly);
	RET();

IFXASM_LABEL(CplxIIQuad);
	MOV(lH,_N(0x6489)); /* arctan(x) = pi/2 -res */
	SUB(lR,lH,lPoly);
	RET();

IFXASM_LABEL(CplxIIIQuad);
	MOV(lH,_N(0x6489)); /* arctan(x) = res - pi/2 */
	SUB(lR,lPoly,lH);
	RET();

}
