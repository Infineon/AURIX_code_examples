/*****************************************************************************
*
* Copyright (C) 2020 Infineon Technologies AG. All rights reserved.
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

#define     aX          _A4       /* Ptr to first matrix				*/
#define     Scalar      _D6       /* Ptr to second matrix				*/
#define     aR          _A5       /* Ptr to output matrix				*/
#define 	aXaR		_PA4	  /* Paired aY aR						*/
#define     nRow        _D4       /* Number of rows						*/
#define     nCol        _D5       /* Number of columns					*/
#define     nColnRow    _E4       /* Packed number of Columns and Rows	*/
#define     LoopCnt     _A2       /* Loop-Cnt-Reg						*/
#define     ssssX       _E2       /* First matrix entries				*/
#define     sseX        _D2       /*   Even-Reg							*/
#define     ssoX        _D3       /*   Odd-Reg							*/
#define     ssssX2      _E10      /* Next 4 matrix entries				*/
#define     sseX2       _D10      /*   Even-Reg							*/
#define     ssoX2       _D11      /*   Odd-Reg							*/
#define     ssssR       _E8       /* Output matrix values				*/
#define     sseR        _D8       /*   Even-Reg							*/
#define     ssoR        _D9       /*   Odd-Reg							*/
#define     dTmp        _D1       /* Generic temporary Data-Reg			*/

#if defined(__GNUC__)
	#pragma section ".cpu0_psram" awx
#elif defined(__TASKING__)
	#pragma section code "cpu0_psram"
#endif

void Ifx_mtxMulScalarRealQ15_fast(struct Ifx_mtxMulScalarRealQ15State * state){
	/* Fetch Inputs
	 *	sint16 * src;  	  --> offset 0
	 *	sint16 * dest;	  --> offset 4
	 *	uint32 m;         --> offset 8
	 *	uint32 n;		  --> offset 12
	 *	sint16 scalar; 	  --> offset 16
	 */
	LD_D(nColnRow, [_A4]8);
	LD_H(Scalar, [_A4]16);
    MUL(dTmp, nRow, nCol);       	/* dTmp = nRow * nCol						*/
	LD_DA(aXaR,[_A4]);
	INSERT(Scalar, Scalar, Scalar, _N(16), _N(16));

    SH(dTmp, dTmp, _N(-2));      	/* dTmp = nRow * nCol/4						*/
    LD_D(ssssX, [aX+]8);	     	/* ssssX <- First four values of matrix X	*/
    ADD(dTmp, dTmp, _N(-1));     	/* -1 loop adjust							*/
    MOV_A(LoopCnt, dTmp);        	/* Transfer count to Loop-Counter			*/

IFXASM_LABEL(MatLoop);
    MULR_H(sseR, sseX, _D6UL, _N(1));     /* sseR (lo) =  X[j] * Scalar
                                   	   	     sseR (hi) = X[j+1] * Scalar					*/
    MULR_H(ssoR, ssoX, _D6UL, _N(1));     /* ssoR (lo) = X[j+2] * Scalar
                                       	   	 ssoR (hi) = X[j+3] * Scalar					*/
    LD_D(ssssX,[aX+]8);    				  /* ssssX <- next four values of matrix X			*/
    ST_D([aR+]8,ssssR);    				  /* Results of sum of four corresponding
                            		         entries of X and Y stored to R					*/
    LOOP(LoopCnt, MatLoop);

    RET();
}

/* Faster version for cases where nCols*nRows is divisible by 8	*/
void Ifx_mtxMulScalarRealQ15_fast8N(struct Ifx_mtxMulScalarRealQ15State * state){
	/* Fetch Inputs
	 *	sint16 * src;  	  --> offset 0
	 *	sint16 * dest;	  --> offset 4
	 *	uint32 m;         --> offset 8
	 *	uint32 n;		  --> offset 12
	 *	sint16 scalar; 	  --> offset 16
	 */
	LD_D(nColnRow, [_A4]8);
	LD_H(Scalar, [_A4]16);
    MUL(dTmp, nRow, nCol);       	/* dTmp = nRow * nCol						*/
	LD_DA(aXaR,[_A4]);
	INSERT(Scalar, Scalar, Scalar, _N(16), _N(16));

    SH(dTmp, dTmp, _N(-3));      	/* dTmp = nRow * nCol/8						*/
    LD_D(ssssX, [aX+]8);	     	/* ssssX <- First four values of matrix X	*/
    ADD(dTmp, dTmp, _N(-1));     	/* -1 loop adjust							*/
    MOV_A(LoopCnt, dTmp);        	/* Transfer count to Loop-Counter			*/

IFXASM_LABEL(MatLoop8N);
    MULR_H(sseR, sseX, _D6UL, _N(1));     /* sseR (lo) =  X[j] * Scalar
                                   	   	     sseR (hi) = X[j+1] * Scalar				*/
    LD_D(ssssX2,[aX+]8);
    MULR_H(ssoR, ssoX, _D6UL, _N(1));     /* ssoR (lo) = X[j+2] * Scalar
                                       	   	 ssoR (hi) = X[j+3] * Scalar				*/
    ST_D([aR+]8,ssssR);    				  /* Results of sum of four corresponding
                            		   	     entries of X and Y stored to R				*/
    MULR_H(sseR, sseX2, _D6UL, _N(1));    /* sseR (lo) =  X[j+4] * Scalar
                                   	   	     sseR (hi) = X[j+5] * Scalar				*/
    LD_D(ssssX,[aX+]8);
    MULR_H(ssoR, ssoX2, _D6UL, _N(1));     /* ssoR (lo) = X[j+6] * Scalar
                                           	 ssoR (hi) = X[j+7] * Scalar				*/
    ST_D([aR+]8,ssssR);    				  /* Results of sum of four corresponding
                            		   	     entries of X and Y stored to R				*/

    LOOP(LoopCnt, MatLoop8N);

    RET();
}

#if defined(__GNUC__)
	#pragma section
#elif defined(__TASKING__)
	#pragma section code
#endif

#undef     aX
#undef     Scalar
#undef     aR
#undef 	   aXaR
#undef     nRow
#undef     nCol
#undef     nColnRow
#undef     LoopCnt
#undef     ssssX
#undef     sseX
#undef     ssoX
#undef     ssssX2
#undef     sseX2
#undef     ssoX2
#undef     ssssR
#undef     sseR
#undef     ssoR
#undef     dTmp
