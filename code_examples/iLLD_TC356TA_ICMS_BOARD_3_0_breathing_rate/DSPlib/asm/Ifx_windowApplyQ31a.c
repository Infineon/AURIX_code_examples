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

#define     W32         4          /* Size of word in bytes */

#define     aInB        _A2        /* Ptr InData B */
#define     aOutB       _A5        /* Ptr OutData B */
#define     llReImB     _E2        /* Data Re|Im */
#define     lReB        _D2        /* Data Re */
#define     lImB        _D3        /* Data Im */
#define     aInT        _A15       /* Ptr InData T */
#define     aOutT       _A6        /* Ptr OutData T */
#define     llReImT     _E8        /* Data Re|Im */
#define     lReT        _D8        /* Data Re */
#define     lImT        _D9        /* Data Im */
#define     aInWin      _A4        /* Ptr In Data W ? adr */
#define     lWin        _D10       /* Data Re only */
#define     aLoopCnt    _A7        /* Half of in vectorsize (in = 2*loopCnt) */
#define     lTmp1       _D0

void Ifx_windowApplyQ31a (struct Ifx_windowApplyQ31State * state){

	IFXASM_ALIGNMENT_8();

	LD_A(aInB,[_A4]4);
	LD_A(aOutB,[_A4]8);
	LD_W(lTmp1,[_A4]16);
	LD_A(aInWin,[_A4]12);
	ADD(_D15,_D0,_N(-1));
	ADDSC_A(aInT,aInB,_D15,_N(3));
	ADDSC_A(aOutT,aOutB,_D15,_N(3));
	SHA_2ARGS(lTmp1,_N(-1));
	MOV_A(aLoopCnt,lTmp1);
	ADD_A(aLoopCnt,_N(-1));

IFXASM_LABEL(loop1);
	LD_D(llReImB, [aInB+]2*W32);
	LD_D(llReImT, [aInT+]-2*W32);
	LD_W(lWin, [aInWin+]W32);
	MUL_Q(lReB,lReB,lWin,_N(1));
	MUL_Q(lImB,lImB,lWin,_N(1));
	MUL_Q(lReT,lReT,lWin,_N(1));
	MUL_Q(lImT,lImT,lWin,_N(1));
	ST_D([aOutB+]2*W32 ,llReImB);
	ST_D([aOutT+]-2*W32 ,llReImT);
	LOOP(aLoopCnt, loop1);
	RET();
}
