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

#define     aX          _A4        /* adArg1-a4  Ptr to First Vector */
#define     nX          _D4        /* wArg1-d4  Dimension of vectors */

#define     aLPCntr     _A2        /* loop counter */
#define     ssCmpReg0   _D2        /* compare register 0 */
#define     ssCmpReg1   _D3        /* compare register 1 */
#define     ssCmpReg    _E2        /* compare register 0/1 */
#define     ssLastVal   _D6        /* Last odd value of an odd boundary array */
#define     dTmp        _D15       /* Generic temporary Data-Reg */

sint16 Ifx_minRealQ15(sint16* x,uint32 n){

	IFXASM_ALIGNMENT_8();

	SH(dTmp,nX,_N(-0x1));
	ADD(dTmp,dTmp,_N(-0x2));
	LD_D(ssCmpReg,[aX+]2*W16);/* ISSUE - to be fixed */
	MOV_A(aLPCntr,dTmp);

IFXASM_LABEL(VecloopMnv_1);
	MIN_H(ssCmpReg0,ssCmpReg0,ssCmpReg1);
	LD_W(ssCmpReg1,[+aX]2*W16);
	LOOP(aLPCntr,VecloopMnv_1);
	SH(ssLastVal,ssCmpReg1,_N(16));
	DEXTR(ssCmpReg1,ssCmpReg0,ssCmpReg0,_N(16));
	MIN_H(ssCmpReg0,ssCmpReg0,ssCmpReg1);
	SH(ssCmpReg0,ssCmpReg0,_N(16));
	AND(dTmp,nX,_N(1));
	JNZ(dTmp,Vecmnv_odd);
	SHA(ssCmpReg0,ssCmpReg0,_N(-16));
	RET();

IFXASM_LABEL(Vecmnv_odd);
	LT(dTmp,ssLastVal,ssCmpReg0);
	CMOV(ssCmpReg0,dTmp,ssLastVal);
	SHA(ssCmpReg0,ssCmpReg0,_N(-16));
	RET();
}
