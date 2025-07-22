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

#define	   PSW	         0xfe04
#define    FALSE         0 		/* CPU status register adr */
#define    TRUE          2
#define    SAV           27       /* CPU Status Bit - Sticky Advance Overflow */
#define    SIZE_CMPLX_32 8


#define     aTWing      _A3        /* pointer to top wing data */
#define     aBWing      _A2        /* pointer to bottom wing data */

#define     lTFRe       _D0        /* Twiddle factor Imag(sine part) */
#define     lTFIm       _D1        /* Twiddle factor Real(cosine part) */
#define     llTWing     _E10       /* Top wing data */
#define     llBWing     _E2        /* bottom wing data (i/p and res) */
#define     llRTop      _E8        /* calculated data of Top wing */
#define     lRRe        _D10       /* Imag data of top wing (y0') */
#define     lRIm        _D11       /* Real data of top wing (x0') */
#define     lBWRe       _D2        /* Imag data of bottom wing (y1') */
#define     lBWIm       _D3        /* Real data of bottom wing (x1') */
#define     lRTopRe     _D8        /* calculated lower half of lattice */
#define     lRTopIm     _D9        /* calculated upper half of lattice */

#define     NF          _D2        /* -- wRtn-d2 Normalisation Factor */
#define     aTF         _A7        /* -- Circular base address for Twiddle factor */
#define     aBWIdx      _A2        /* -- Current Index of Spectrum w.r.t butterfly */
#define     aTWIdx      _A3        /* -- Current Index of spectrum w.r.t group */
#define     aLPCntr6    _A6        /* -- Iteration counter use reg adArg3 */
#define     aBTfCntr    _A12       /* -- Group counter */
#define     sLPCnt      _D5        /* -- Iteration count in a data reg */
#define     sFFTPt      _D7        /* -- Numbers of points of data also holds the */
							   /* -- normalisation factor */
#define     dTmp6       _D6        /* -- temp reg */
#define     sBTfCnt     _D12       /* -- Butterfly count (no. of butterflies/group) */
#define     dTmp13      _D13       /* -- temp reg */
#define     sTFoff      _D14       /* -- Offset for the TF buffer access */
#define     lStatus     _D15       /* -- Status register that hold the PSW */
#define     llTF        _E0        /* -- aTF factor register holds two pairs */

#define     aLPCntr15   _A15       /* Iteration counter */
#define     aBRBase     _A2        /* copy of the aX and base address of BR reg */
#define     llRBTf0     _E2        /* result of the butterfly ( top wing) */
#define     llRBTf1     _E6        /* result of the butterfly ( bottom wing) */
#define     lRBTf0Im    _D3        /* Real part of Top wing result */
#define     lRBTf0Re    _D2        /* Imag part of Top wing result */
#define     lRBTf1Im    _D7        /* Real part of Bottom wing result */
#define     lRBTf1Re    _D6        /* Imag part of Bottom wing result */
#define     aBRMandI    _A3        /* modifier and index of the bitreversal reg */
#define     llX0        _E8        /* Data reg 0 */
#define     llX1        _E10       /* Data reg 1 */
#define     lX0Re       _D8
#define     lX0Im       _D9
#define     lX1Re       _D10
#define     lX1Im       _D11
#define     lImBTf0     _D2        /* even register of top wing */
#define     lImBTf1     _D7        /* odd register of the bottom wing */
#define     aCpR        _A14       /* Copy of pointer to the Spectrum array */
#define     dTmp0       _D0        /* Temp reg */

#define     aR          _A4        /* -- adArg1-a4 o/p spectrum pointer the first half is */
							   /* -- real part and second half is the imag part */
#define     aX          _A5        /* -- adArg2-a5 i/p real data arranged in RE[0]..RE[N-1] */
							   /* -- IM[0]..IM[N-1] */
#define     NX          _D4        /* -- wArg1-d4 Number of data points of the FFT DIT. */

void Ifx_fftComplexQ31a (struct Ifx_fftComplexQ31aState * state){



	SUB_A(_SP,_N(8));
	LD_W(_D0,[_A4]12);
	ST_W([_SP],_D0);
	ST_A([_SP]4,_A4);
	LD_A(aX,[_A4]8);
	LD_W(NX,[_A4]16);
	LD_A(aR,[_A4]4);
	CLZ(sLPCnt,NX);
	RSUB(sLPCnt,sLPCnt,_N(29));
	MOV_A(aLPCntr6,sLPCnt);
	MOV(sBTfCnt,_N(2));
	MOV(dTmp13,_N(1));
	SH(sTFoff,NX,_N(-2));
	RSTV();

IFXASM_LABEL(FirstPass);
	MOV_AA(aBRBase,aX);
	SH(dTmp0,NX,_N(18));	/* enlever anti/ */
	MOV_A(aBRMandI,dTmp0);
	SH(dTmp0,NX,_N(-1));
	LD_D_FFT(llX0,[aBRBase+r],[aBRBase/aBRMandI+r]);
	ADD_2ARGS(dTmp0,_N(-1));		/* 2 args */
	MOV_A(aLPCntr15,dTmp0);
	MOV_AA(aCpR,aR);

IFXASM_LABEL(FFTFp);
	SHA(lX0Re,lX0Re,_N(-1));
	SHA(lX0Im,lX0Im,_N(-1));
	LD_D_FFT(llX1,[aBRBase+r],[aBRBase/aBRMandI+r]);
	SHA(lX1Re,lX1Re,_N(-1));
	SHA(lX1Im,lX1Im,_N(-1));
	ADD(lRBTf0Im,lX0Im,lX1Im);
	ADD(lRBTf0Re,lX0Re,lX1Re);
	ST_D([aCpR+]SIZE_CMPLX_32,llRBTf0);
	SUB(lRBTf1Im,lX0Im,lX1Im);
	SUB(lRBTf1Re,lX0Re,lX1Re);
	LD_D_FFT(llX0,[aBRBase+r],[aBRBase/aBRMandI+r]);
	ST_D([aCpR+]SIZE_CMPLX_32,llRBTf1);
	LOOP(aLPCntr15,FFTFp);

	MOV(sFFTPt,_N(2));

IFXASM_LABEL(FFT_StageLoop_FS);
	MFCR(lStatus,_N(PSW));
	JZ_T(lStatus,SAV,FFT_NoShift_F);
	SH_2ARGS(sFFTPt,_N(1));
	RSTV();
	MOV(sLPCnt,_N(0));


IFXASM_LABEL(FFT_GrpLoop_FS);
	ADDSC_A(aTWIdx,aR,sLPCnt,_N(3));
	ADDSC_A(aBWIdx,aR,sBTfCnt,_N(3));
	ADDSC_A(aBWIdx,aBWIdx,sLPCnt,_N(3));
	ADD(dTmp6,sBTfCnt,_N(-1));
	LD_A(aTF,[_SP]);
	MOV_A(aBTfCntr,dTmp6);

IFXASM_LABEL(FFT_BTfLoop_FS);
	LD_D(llTF,[aTF]);

IFXASM_LABEL(ButterFly2_TRUE);	/* path: shift==TRUE */
	LD_D(llBWing,[aBWing]);
	MUL_Q(lRRe,lTFRe,lBWRe,_N(0));
	MUL_Q(lRIm,lTFRe,lBWIm,_N(0));
	MSUB_Q(lRTopRe,lRRe,lTFIm,lBWIm,_N(0));
	MADD_Q(lRTopIm,lRIm,lTFIm,lBWRe,_N(0));
	LD_D(llTWing,[aTWing]);
	SHA(lRIm,lRIm,_N(-1));
	SHA(lRRe,lRRe,_N(-1));
	SUB(lBWRe,lRRe,lRTopRe);
	SUB(lBWIm,lRIm,lRTopIm);
	ADD(lRTopRe,lRRe,lRTopRe);
	ST_D([aBWing],llBWing);
	ADD(lRTopIm,lRIm,lRTopIm);
	ST_D([aTWing],llRTop);

	ADDSC_A(aTWIdx,aTWIdx,dTmp13,_N(3));
	ADDSC_A(aBWIdx,aBWIdx,dTmp13,_N(3));
	ADD_2ARGS(sLPCnt,_N(2));
	ADDSC_A(aTF,aTF,sTFoff,_N(3));
	LOOP(aBTfCntr,FFT_BTfLoop_FS);
	JLT(sLPCnt,NX,FFT_GrpLoop_FS);
	SH(sBTfCnt,sBTfCnt,_N(1));
	SH(sTFoff,sTFoff,_N(-1));
	LOOP(aLPCntr6,FFT_StageLoop_FS);
	J(FFT_PostProcessF);

IFXASM_LABEL(FFT_NoShift_F);
	MOV(sLPCnt,_N(0));

IFXASM_LABEL(FFT_GrpLoop_F);
	ADDSC_A(aTWIdx,aR,sLPCnt,_N(3));
	ADDSC_A(aBWIdx,aR,sBTfCnt,_N(3));
	ADDSC_A(aBWIdx,aBWIdx,sLPCnt,_N(3));
	ADD(dTmp6,sBTfCnt,_N(-1));
	LD_A(aTF,[_SP]);
	MOV_A(aBTfCntr,dTmp6);

IFXASM_LABEL(FFT_BTfLoop_F);
	LD_D(llTF,[aTF]);

IFXASM_LABEL(ButterFly2_FALSE);	/* path: shift==FALSE */
	LD_D(llBWing,[aBWing]);
	MUL_Q(lRRe,lTFRe,lBWRe,_N(1));
	MUL_Q(lRIm,lTFRe,lBWIm,_N(1));
	MSUB_Q(lRTopRe,lRRe,lTFIm,lBWIm,_N(1));
	MADD_Q(lRTopIm,lRIm,lTFIm,lBWRe,_N(1));
	LD_D(llTWing,[aTWing]);
	SUB(lBWRe,lRRe,lRTopRe);
	SUB(lBWIm,lRIm,lRTopIm);
	ADD(lRTopRe,lRRe,lRTopRe);
	ST_D([aBWing],llBWing);
	ADD(lRTopIm,lRIm,lRTopIm);
	ST_D([aTWing],llRTop);


	ADDSC_A(aTWIdx,aTWIdx,dTmp13,_N(3));
	ADDSC_A(aBWIdx,aBWIdx,dTmp13,_N(3));
	ADD_2ARGS(sLPCnt,_N(2));
	ADDSC_A(aTF,aTF,sTFoff,_N(3));
	LOOP(aBTfCntr,FFT_BTfLoop_F);
	JLT(sLPCnt,NX,FFT_GrpLoop_F);
	SH(sBTfCnt,sBTfCnt,_N(1));
	SH(sTFoff,sTFoff,_N(-1));
	LOOP(aLPCntr6,FFT_StageLoop_FS);

IFXASM_LABEL(FFT_PostProcessF);
	LD_A(_A15,[_SP]4);
	ST_W([_A15]20,sFFTPt);
	RET();

}
