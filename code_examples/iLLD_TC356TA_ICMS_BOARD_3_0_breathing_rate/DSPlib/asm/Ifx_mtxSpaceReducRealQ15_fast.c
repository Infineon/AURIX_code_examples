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

#define     aXU         _A4       /* Ptr to first matrix upper elements				*/
#define     aXL         _A6       /* Ptr to first matrix lower elements				*/
#define     aR          _A5       /* Ptr to output matrix							*/
#define 	aXUaR		_PA4      /* Paired aXU aR		 							*/
#define     nColnRow    _E4       /* Packed number of Columns and Rows				*/
#define     nRow        _D4       /* Number of rows									*/
#define     nCol        _D5       /* Number of columns								*/
#define     nColGroups  _A2       /* Loop-Cnt-Reg on Cols							*/
#define     nRowGroups  _A3       /* Loop-Cnt-Reg on Rows							*/
#define     sseX        _D2       /* Even-Reg										*/
#define     ssoX        _D3       /* Odd-Reg										*/
#define     coeff       _D14      /* coeff=0.25 - to compute average				*/
#define     coeffLL     _D14LL    /* 16-bit effective part of "coeff"				*/
#define     sseR        _E10      /* Even Result reg (only D11 used)				*/
#define     seR       	_D11      /* Even Result reg 								*/
#define     ssoR        _E12      /* Odd Result reg (only D13 used)					*/
#define     soR       	_D13      /* Odd Result reg 								*/
#define     dTmpU       _D6       /* Temporary Data-Reg to count upper mtx elements	*/
#define     dTmpL       _D7       /* Temporary Data-Reg	to count lower mtx element	*/

#if defined(__GNUC__)
	#pragma section ".cpu0_psram" awx
#elif defined(__TASKING__)
	#pragma section code "cpu0_psram"
#endif

void Ifx_mtxSpaceReducRealQ15_fast(struct Ifx_mtxTransRealQ15State * state){
	/* Fetch Inputs
	 *	sint16 * src;  	  --> offset 0
	 *	sint16 * dest;	  --> offset 4
	 *	uint32 m;         --> offset 8
	 *	uint32 n;		  --> offset 12
	 */
	LD_D(nColnRow, [_A4]8);
	LD_DA(aXUaR, [_A4]0);
	SH(dTmpU, nCol, _N(-1));      			/* dTmpU = nCol/2						*/
	SH(dTmpL, nRow, _N(-1));      			/* dTmpL = nRow/2						*/
	ADD(dTmpU, dTmpU, _N(-1));     			/* -1 loop adjust						*/
	ADDSC_A(aXL, aXU, nCol, _N(1));
    ADD(nCol, nCol, _N(-2));
    LD_W(sseX, [aXU+]4);	     			/* sseX <- X[1] X[0]					*/
    ADD(dTmpL, dTmpL, _N(-1));     			/* -1 loop adjust						*/
    LD_W(ssoX, [aXL+]4);		    		/* ssoX <- X[Ncol+1] X[Ncol+0]			*/
    MOV(coeff, _N(0x2000));
    MOV_A(nColGroups, dTmpU);        		/* Transfer count to Loop-Counter		*/
	MOV(seR, _N(0));
    MOV_A(nRowGroups, dTmpL);        		/* Transfer count to Loop-Counter		*/

IFXASM_LABEL(ReducLoop);
	MADDMS_H(sseR, sseR, ssoX, coeffLL, _N(1));
    LD_W(ssoX, [aXL+]4);		   			/* ssoX <- X[Ncol+3] X[Ncol+2]			*/
	MADDMS_H(sseR, sseR, sseX, coeffLL, _N(1));
	LD_W(sseX, [aXU+]4);		    		/* ssoX <- X[3] X[2]					*/
	ST_H([aR+]2, seR);
	MOV(seR, _N(0));

	LOOP(nColGroups, ReducLoop);
	ADDSC_A(aXU, aXU, nCol, _N(1));
	ADDSC_A(aXL, aXL, nCol, _N(1));
	LD_W(sseX, [aXU+]4);		    		/* ssoX <- X[Row1+1] 	  X[Row1]		*/
	LD_W(ssoX, [aXL+]4);					/* ssoX <- X[Row1+nCol+1] X[Row1+nCol]	*/
	MOV_A(nColGroups, dTmpU);        		/* Transfer count to Loop-Counter		*/

	LOOP(nRowGroups, ReducLoop);

    RET();
}

void Ifx_mtxSpaceReducRealQ15_fast8N(struct Ifx_mtxTransRealQ15State * state){
	/* Fetch Inputs
	 *	sint16 * src;  	  --> offset 0
	 *	sint16 * dest;	  --> offset 4
	 *	uint32 m;         --> offset 8
	 *	uint32 n;		  --> offset 12
	 */
	LD_D(nColnRow, [_A4]8);
	LD_DA(aXUaR, [_A4]0);
	SH(dTmpU, nCol, _N(-2));      		/* dTmpU = nCol/4						*/
	SH(dTmpL, nRow, _N(-1));      		/* dTmpL = nRow/2						*/
	ADD(dTmpU, dTmpU, _N(-1));     		/* -1 loop adjust						*/
	ADDSC_A(aXL, aXU, nCol, _N(1));
    ADD(nCol, nCol, _N(-2));
    LD_W(sseX, [aXU+]4);	     		/* sseX <- X[1] X[0]					*/
    ADD(dTmpL, dTmpL, _N(-1));     		/* -1 loop adjust						*/
    LD_W(ssoX, [aXL+]4);		    	/* ssoX <- X[Ncol+1] X[Ncol+0]			*/
    MOV(coeff, _N(0x2000));
    MOV_A(nColGroups, dTmpU);        	/* Transfer count to Loop-Counter		*/
	MOV(seR, _N(0));
    MOV_A(nRowGroups, dTmpL);        	/* Transfer count to Loop-Counter		*/

IFXASM_LABEL(ReducLoop2N);
	MADDMS_H(sseR, sseR, ssoX, coeffLL, _N(1));
    LD_W(ssoX, [aXL+]4);		   			/* ssoX <- X[Ncol+3] X[Ncol+2]			*/
	MADDMS_H(sseR, sseR, sseX, coeffLL, _N(1));
	LD_W(sseX, [aXU+]4);		    		/* ssoX <- X[3] X[2]					*/
	MOV(soR, _N(0));
	ST_H([aR+]2, seR);

	MADDMS_H(ssoR, ssoR, ssoX, coeffLL, _N(1));
    LD_W(ssoX, [aXL+]4);		    		/* ssoX <- X[Ncol+3] X[Ncol+2]			*/
	MADDMS_H(ssoR, ssoR, sseX, coeffLL, _N(1));
	LD_W(sseX, [aXU+]4);		    		/* ssoX <- X[3] X[2]					*/
	MOV(seR, _N(0));
	ST_H([aR+]2, soR);

	LOOP(nColGroups, ReducLoop2N);
	ADDSC_A(aXU, aXU, nCol, _N(1));
	ADDSC_A(aXL, aXL, nCol, _N(1));
	LD_W(sseX, [aXU+]4);		    		/* ssoX <- X[Row1+1] 	  X[Row1]		*/
	LD_W(ssoX, [aXL+]4);					/* ssoX <- X[Row1+nCol+1] X[Row1+nCol]	*/
	MOV_A(nColGroups, dTmpU);        		/* Transfer count to Loop-Counter		*/

	LOOP(nRowGroups, ReducLoop2N);

    RET();
}

#if defined(__GNUC__)
	#pragma section
#elif defined(__TASKING__)
	#pragma section code
#endif

#undef     aXU
#undef     aXL
#undef     aR
#undef 	   aXUaR
#undef     nColnRow
#undef     nRow
#undef     nCol
#undef     nColGroups
#undef     nRowGroups
#undef     sseX
#undef     ssoX
#undef     coeff
#undef     coeffLL
#undef     sseR
#undef     seR
#undef     ssoR
#undef     soR
#undef     dTmpU
#undef     dTmpL
