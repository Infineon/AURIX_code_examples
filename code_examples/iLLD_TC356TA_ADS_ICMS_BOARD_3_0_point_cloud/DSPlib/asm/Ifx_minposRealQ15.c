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

#define     aX          _A4        /* adArg1-a4  Ptr to First Vector */
#define     nX          _D4        /* wArg1-d4  Dimension of vectors */

#define     aLPCntr     _A2        /* loop counter */
#define     ssCmpReg  	_E2        /* compare register */
#define     ssCmpReg0   _D2        /* compare register 0 */
#define     ssCmpReg1   _D3        /* compare register 1 */
#define     ssResReg    _E6        /* result register */
#define     ssResReg0   _D6        /* result register 0 */
#define     ssResReg1   _D7        /* result register 1 */
#define     ssCmpVal	_D8        /* Compare Values */
#define     dTmp        _D15       /* Generic temporary Data-Reg */


sint16 Ifx_minposRealQ15 (sint16 *Xa, uint16 nXa, uint16 *posa){

	IFXASM_ALIGNMENT_8();

	LD_H(ssCmpReg1,[aX]);
	MOV_H(ssCmpReg0, _N(0x0));
	SH(dTmp,nX,_N(-0x1));
	ADD_2ARGS(dTmp,_N(-0x2));
	LD_W(ssCmpVal,[aX+]2*W16);
	MOV_A(aLPCntr,dTmp);

IFXASM_LABEL(VecloopMnv_1);
	IXMIN(ssResReg, ssCmpReg, ssCmpVal);
	MOV_3ARGS(ssCmpReg, ssResReg1, ssResReg0);
	LD_W(ssCmpVal,[aX+]2*W16);
	LOOP(aLPCntr,VecloopMnv_1);
	IXMIN(ssResReg, ssCmpReg, ssCmpVal);
	SH(ssResReg0,ssResReg0,_N(-16));
	AND(dTmp,nX,_N(1));
	JNZ(dTmp,Vecmnv_odd);
	ST_H([_A5],ssResReg0);
	MOV(ssCmpReg0, ssResReg1);
	RET();

IFXASM_LABEL(Vecmnv_odd);
	LD_H(ssCmpVal,[aX]);
	SH(ssCmpVal,ssCmpVal,_N(16));
	SH(ssCmpVal,ssCmpVal,_N(-16));
	LT_H(dTmp,ssCmpVal,ssResReg1);
	ADD_2ARGS(nX,_N(-0x1));
	CMOV(ssResReg0,dTmp,nX);
	ST_H([_A5],ssResReg0);
	MOV(ssCmpReg0, ssResReg1);
	CMOV(ssCmpReg0,dTmp,ssCmpVal);
	RET();

}
