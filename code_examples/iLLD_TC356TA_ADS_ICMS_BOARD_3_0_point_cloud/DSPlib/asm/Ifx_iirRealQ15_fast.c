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




void Ifx_iirRealQ15_fast(sint16 *x,sint16 *y,sint16 *c,sint16 *d,uint32 nBiq,uint32 nX){
	#define     W16         2     /* Size of halfword in bytes */

	#define     aX          _A4    	  /* a4  Ptr to Input-Buffer */
	#define     aR          _A5    	  /* a5  Ptr to Output-Buffer */
	#define     aH0         _A6       /* a6  Ptr to Coeff-Buffer */
	#define     aW0         _A7       /* a7  Ptr to Delay-Buffer */
	#define     nBiq        _D4       /* d4  Stores number of biquads */
	#define     nX          _D5       /* d5  Stores number of Input Data */

	#define     aBiqCnt     _A15      /* Loop-Cnt-Reg */

	#define     aH          _A14      /* Ptr to Coeff-Buffer */
	#define     aW          _A13      /* Ptr to Delay-Buffer */

	#define     sX          _D2       /* Input Data */
	#define     sH          _D3       /* Filter coeff */
	#define     ssssH       _E12  /* Filter coeff					----- */
	#define     sseH        _D12      /* Even-Reg */
	#define     ssoH        _D13      /* Odd-Reg */

	#define     llW         _E8   /* Delay element					----- */
	#define     leW         _D8       /* Even-Reg */
	#define     loW         _D9       /* Odd-Reg */
	#define     ssW         _D14      /* Filter internal state */
	#define		ssW_ul		_D14UL

	#define     llAcc       _E10 /* Filter result					----- */
	#define     leAcc       _D10      /* Even-Reg */
	#define     loAcc       _D11      /* Odd-Reg */
	#define     llTmp       _E6   /* Generic temporary Reg-Pair		----- */
	#define     dTmp        _D15      /* Generic temporary Data-Reg */


	IFXASM_ALIGNMENT_8();

    ADD(nX,nX,_N(-1));
    LD_Q(sX,[aX+]W16);
    ADD(nBiq,nBiq, _N(-1));

IFXASM_LABEL(IirB5_IndataL);
	MOV_AA(aH,aH0);
	MOV_A(aBiqCnt,nBiq);
	MOV_AA(aW,aW0);
	SHA(loAcc,sX,_N(-18));
	LD_H(sH,[aH+]3*W16);
	SHA(leAcc,sX,_N(14));
	LD_W(ssoH,[aH+]-2*W16);
	LD_W(ssW,[aW+]2*W16);

IFXASM_LABEL(IirB5_BiqL);
	MADDM_H(llW,llAcc,ssoH,ssW_ul,_N(0));/* ISSUE - to be fixed */
	ST_H([aW]-W16,ssW);
	DEXTR(dTmp,loW,leW,_N(2));
	LD_W(sseH,[aH+]4*W16);
	SHAS(dTmp,dTmp,_N(16));
	ST_Q([aW]-2*W16,dTmp);
	MUL_Q(llTmp,dTmp,sH,_N(0));/* ISSUE - to be fixed */
	LD_H(sH,[aH+]3*W16);
	MADDM_H(llAcc,llTmp,sseH,ssW_ul,_N(0));/* ISSUE - to be fixed */
	LD_W(ssW,[aW+]2*W16);
	LD_W(ssoH,[aH+]-2*W16);
	LOOP(aBiqCnt,IirB5_BiqL);
	DEXTR(dTmp,loAcc,leAcc,_N(2));
	LD_Q(sX,[aX+]W16);
	SHAS(dTmp,dTmp,_N(16));
	ST_Q([aR+]W16,dTmp);
	JNED(nX,_N(0),IirB5_IndataL);
	RET();

}
