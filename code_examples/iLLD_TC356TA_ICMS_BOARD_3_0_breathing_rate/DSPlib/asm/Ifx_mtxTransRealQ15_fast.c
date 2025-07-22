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

#define     aX          _A4    /* a4 Ptr to input matrix		*/
#define     aR          _A5    /* a5 Ptr to output matrix		*/
#define 	aXaR		_PA4   /* Paired aY aR					*/
#define     nColnRow    _E4    /* d4 Number of rows				*/
#define     nRow        _D4    /* d4 Number of rows				*/
#define     nCol        _D5    /* d5 Number of columns			*/
#define     aXRow       _A7    /* Ptr to matrix element			*/
#define     sXRn        _D7    /* matrix element				*/
#define     sXRn1       _D8    /* matrix element				*/
#define     anRow_2     _A12   /* LOOP( Count					*/
#define     dCol        _D10   /* LOOP( Count for column LOOP(	*/
#define     dRowCnt     _D12   /* LOOP( count for row LOOP(		*/
#define     aXR1        _A13   /* Ptr to elements in first row	*/
#define     dTmp        _D11   /* Generic temporary Data-Reg	*/

#if defined(__GNUC__)
	#pragma section ".cpu0_psram" awx
#elif defined(__TASKING__)
	#pragma section code "cpu0_psram"
#endif

void Ifx_mtxTransRealQ15_fast(struct Ifx_mtxTransRealQ15State * state){
	/* Fetch inputs
	*	  sint16 * src;   --> offset 0
	*	  sint16 * dest;  --> offset 4
	*	  uint32 m;       --> offset 8
	*	  uint32 n;		  --> offset 12
	*/
	LD_D(nColnRow, [_A4]8);
	LD_DA(aXaR,[_A4]);
	ADD(dCol, nCol, _N(-1));       		/* -1 LOOP( adjust for Column LOOP(					*/

    SHA(dTmp, nRow,_N(-1));       		/* >>1 2 elements of matrix/LOOP( will be stored 	*/
    ADD(dRowCnt, dTmp, _N(-1));    		/* -1 LOOP( adjust for row LOOP(					*/
    MOV_AA(aXR1, aX);             		/* aXR1 is ptr to X[0][0]							*/

IFXASM_LABEL(MatTrans_ColL);
    MOV_A(anRow_2, dRowCnt);     		/* Transfer of count to LOOP(-Counter				*/
    ADDSC_A(aXRow, aX, nCol, _N(1));    /* aXRow is ptr to X[i+1][0]						*/

IFXASM_LABEL(MatTrans_RowL);
    LD_HU(sXRn,[aX]);           		/* sXRn <- X[i][j]									*/
    ADDSC_A(aX, aX, nCol, _N(2));       /* aX is ptr to X[i+2][j]							*/
    LD_Q(sXRn1, [aXRow]);       		/* sXRn1 <- X[i+1][j]								*/
    OR(sXRn, sXRn1, sXRn);     			/* Two elements of input matrix packed togther 		*/
    ST_W([aR+]4, sXRn);     			/* Store the packed input into output array			*/
    ADDSC_A(aXRow, aXRow, nCol, _N(2)); /* aXRow is ptr to X[i+3][j]						*/
    LOOP(anRow_2, MatTrans_RowL);

    LD_H(dTmp, [aXR1+]2);			    /* Dummy load to increment the ptr to point next column */
    MOV_AA(aX, aXR1);             		/* aX is ptr to X[i][j+1]							*/
    JNED(dCol, _N(0), MatTrans_ColL);

    RET();
}

#if defined(__GNUC__)
	#pragma section
#elif defined(__TASKING__)
	#pragma section code
#endif

#undef     aX
#undef     aR
#undef 	   aXaR
#undef     nColnRow
#undef     nRow
#undef     nCol
#undef     aXRow
#undef     sXRn
#undef     sXRn1
#undef     anRow_2
#undef     dCol
#undef     dRowCnt
#undef     aXR1
#undef     dTmp
