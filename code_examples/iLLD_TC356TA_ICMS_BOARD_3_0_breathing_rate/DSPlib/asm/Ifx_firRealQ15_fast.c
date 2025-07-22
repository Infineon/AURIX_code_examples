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
#define     aX          _A4        /* adArg1-a4 Ptr to Input-Buffer */
#define     aR          _A5        /* adArg2-a5 Ptr to Output-Buffer */
#define     aDLY        _A6        /* adArg3-a6 Ptr to Ptr to Circ-Ptr of Delay-Buffer */
#define     lBase       _D4        /* wArg1-d4 Base address - first member of circ */
									/* struct. */
#define     ssSizeIdx   _D5        /* wArg2-d5 Size|Index - second and third */
									/* members of circ struct. */
#define     nX          _D6        /* wArg3-d6 Input data count */
#define     caH         _PA2     /* Circ-Ptr of Coeff-Buffer */
#define     caeH        _A2        /* Even-Reg of Circ-Ptr */
#define     caoH        _A3        /* Odd-Reg of Circ-Ptr */
#define     caDLY       _PA12   /* Circ-Ptr Reg-Pair for Delay-Buffer a12-a13 */
#define     caeDLY      _A12       /* Even-Reg of Circ-Ptr */
#define     caoDLY      _A13       /* Odd-Reg of Circ-Ptr */
#define     aTapCnt     _A15       /* Loop-Cnt-Reg */

#define     ssssX0       _E10       /* Filter internal state */
#define     sseX0        _D10       /* Even-Reg */
#define     ssoX0        _D11       /* Odd-Reg */
#define     ssssH0       _E8        /* Filter Coeff. */
#define     sseH0        _D8        /* Even-Reg */
#define     ssoH0        _D9        /* Odd-Reg */
#define     sseH0_ul     _D8UL      /* Even-Reg */
#define     ssoH0_ul     _D9UL      /* Odd-Reg */


#define     ssssX1       _E2       /* Filter internal state */
#define     sseX1        _D2       /* Even-Reg */
#define     ssoX1        _D3       /* Odd-Reg */

#define     ssssH1       _E0        /* Filter Coeff. */
#define     sseH1        _D0        /* Even-Reg */
#define     ssoH1        _D1        /* Odd-Reg */
#define     sseH1_ul     _D0UL      /* Even-Reg */
#define     ssoH1_ul     _D1UL      /* Odd-Reg */


#define     llAcc       _PD13       /* Filter result */
#define     leAcc       _D12       /* Even-Reg */
#define     loAcc       _D13       /* Odd-Reg */
#define     dTapLoops   _D14       /* Number of taps */
#define     dTmp        _D15       /* Generic temporary Data-Reg */

void Ifx_firRealQ15_fast(sint16 *x,sint16 *y,Ifx_CircularBuffer c,Ifx_CircularBuffer *s,uint32 n){

	IFXASM_ALIGNMENT_8();

	ADD(nX,nX,_N(-1));
	MOV_A(caeH,lBase);
	MOV_A(caoH,ssSizeIdx);
	MOV_D(dTmp,caoH);
	SH(dTapLoops, dTmp,_N(-(16+1+3)));
	ADD(dTapLoops, dTapLoops, _N(-(1+1)));
	#if defined(__GNUC__)
		LD_DA(caeDLY,[aDLY]);
	#endif /* __GNUC__ */
	#if defined(__TASKING__)
		LD_DA(caDLY,[aDLY]);
	#endif /* TASKING */
	LD_Q(dTmp, [aX+]W16);
	MOV_A(aTapCnt, dTapLoops);
	#if defined(__GNUC__)
		LD_W(ssoH0, [caeH+c]2*W16);
	#endif /* __GNUC__ */
	#if defined(__TASKING__)
		LD_W(ssoH0, [caH+c]2*W16);
	#endif /* TASKING */


IFXASM_LABEL(FirB4_InDataL);
	#if defined(__GNUC__)
		ST_Q([caeDLY+c]0, dTmp);
		MOV(leAcc,_N(0));
		LD_D(ssssX0, [caeDLY+c]4*W16);
		MOV(loAcc,_N(0));
		LD_D(ssssH1, [caeH+c]4*W16);
	#endif /* __GNUC__ */
	#if defined(__TASKING__)
		ST_Q([caDLY+c]0, dTmp);
		MOV(leAcc,_N(0));
		LD_D(ssssX0, [caDLY+c]4*W16);
		MOV(loAcc,_N(0));
		LD_D(ssssH1, [caH+c]4*W16);
	#endif /* TASKING */


IFXASM_LABEL(FirB4_TapL);

	#if defined(__GNUC__)
		MADDM_H(llAcc,llAcc,sseX0,ssoH0_ul,_N(1));
		LD_D(ssssX1, [caeDLY+c]4*W16);
		MADDM_H(llAcc,llAcc,ssoX0,sseH1_ul,_N(1));
		LD_D(ssssH0, [caeH+c]4*W16);
		MADDM_H(llAcc,llAcc,sseX1,ssoH1_ul,_N(1));
		LD_D(ssssX0, [caeDLY+c]4*W16);
		MADDM_H(llAcc,llAcc,ssoX1,sseH0_ul,_N(1));
		LD_D(ssssH1, [caeH+c]4*W16);
		LOOP(aTapCnt, FirB4_TapL);
		MADDM_H(llAcc,llAcc,sseX0,ssoH0_ul,_N(1));
		LD_D(ssssX1, [caeDLY+c]3*W16);
		MADDM_H(llAcc,llAcc,ssoX0,sseH1_ul,_N(1));
		LD_W(sseH0, [caeH+c]2*W16);
		MADDM_H(llAcc,llAcc,sseX1,ssoH1_ul,_N(1));
		LD_W(ssoH0, [caeH+c]2*W16);
		MADDM_H(llAcc,llAcc,ssoX1,sseH0_ul,_N(1));
		LD_Q(dTmp, [aX+]W16);
		MOV_A(aTapCnt, dTapLoops);
		SHAS(loAcc, loAcc, _N(16));
		ST_Q([aR+]W16, loAcc);
		JNED(nX, _N(0), FirB4_InDataL);
		ST_DA([aDLY],caeDLY);
		RET();
	#endif /* __GNUC__ */
	#if defined(__TASKING__)
		MADDM_H(llAcc,llAcc,sseX0,ssoH0_ul,_N(1));
		LD_D(ssssX1, [caDLY+c]4*W16);
		MADDM_H(llAcc,llAcc,ssoX0,sseH1_ul,_N(1));
		LD_D(ssssH0, [caH+c]4*W16);
		MADDM_H(llAcc,llAcc,sseX1,ssoH1_ul,_N(1));
		LD_D(ssssX0, [caDLY+c]4*W16);
		MADDM_H(llAcc,llAcc,ssoX1,sseH0_ul,_N(1));
		LD_D(ssssH1, [caH+c]4*W16);
		LOOP(aTapCnt, FirB4_TapL);
		MADDM_H(llAcc,llAcc,sseX0,ssoH0_ul,_N(1));
		LD_D(ssssX1, [caDLY+c]3*W16);
		MADDM_H(llAcc,llAcc,ssoX0,sseH1_ul,_N(1));
		LD_W(sseH0, [caH+c]2*W16);
		MADDM_H(llAcc,llAcc,sseX1,ssoH1_ul,_N(1));
		LD_W(ssoH0, [caH+c]2*W16);
		MADDM_H(llAcc,llAcc,ssoX1,sseH0_ul,_N(1));
		LD_Q(dTmp, [aX+]W16);
		MOV_A(aTapCnt, dTapLoops);
		SHAS(loAcc, loAcc, _N(16));
		ST_Q([aR+]W16, loAcc);
		JNED(nX, _N(0), FirB4_InDataL);
		ST_DA([aDLY],caDLY);
		RET();
	#endif /* __TASKING__ */


}
