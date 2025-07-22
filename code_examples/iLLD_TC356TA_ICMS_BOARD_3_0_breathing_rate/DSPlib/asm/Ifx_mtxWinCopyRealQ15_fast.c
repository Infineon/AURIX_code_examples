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

#define     aX          _A4       /* Ptr to input matrix 										*/
#define     aR          _A5       /* Ptr to output matrix										*/
#define 	aXaR		_PA4      /* Paired aU aR					 							*/
#define     nColnRowSRC _E4       /* Packed number of Columns and Rows							*/
#define     nRowSRC     _D4       /* Number of rows	in src										*/
#define     nColSRC     _D5       /* Number of columns in src									*/
#define     nColnRowDST _E6       /* Packed number of Columns and Rows							*/
#define     nRowDST     _D6       /* Number of rows in dst										*/
#define     nColDST     _D7       /* Number of columns in src									*/
#define 	offset		_D8		  /* Offset size between 2 dst rows (in src matrix reference) 	*/
#define 	start		_D9		  /* Start output mtx index in input mtx 						*/
#define     nColGroups  _A2       /* Loop-Cnt-Reg on Cols										*/
#define     nRowGroups  _A3       /* Loop-Cnt-Reg on Rows										*/
#define     sseX        _D2       /* Even-Reg													*/
#define     ssoX        _D3       /* Odd-Reg													*/
#define     sseR        _E10      /* Even Result reg (only D11 used)							*/
#define     seR       	_D11      /* Even Result reg 											*/
#define     ssoR        _E12      /* Odd Result reg (only D13 used)								*/
#define     soR       	_D13      /* Odd Result reg 											*/
#define     dTmpCol     _D14      /* Temporary Data-Reg to count upper mtx elements				*/
#define     dTmpRow     _D15      /* Temporary Data-Reg	to count lower mtx element				*/
#define 	dTmp		_D0
#define 	dTmpExt		_E0

#if defined(__GNUC__)
	#pragma section ".cpu0_psram" awx
#elif defined(__TASKING__)
	#pragma section code "cpu0_psram"
#endif

void Ifx_mtxWinCopyRealQ15_fast(struct Ifx_mtxWinCopyRealQ15State * state){
	/* Fetch Inputs
	 *	sint16 * src[n*m]; --> offset 0
	 *	sint16 * dst[u*v]; --> offset 4
	 *	uint32 m;          --> offset 8
	 *	uint32 n;		   --> offset 12
	 *  uint32 u;          --> offset 16
	 *	uint32 v;		   --> offset 20
	 *	uint32 start;	   --> offset 24
	 */
	LD_D(nColnRowDST, [_A4]16);
	LD_D(nColnRowSRC, [_A4]8);
	ADD(dTmpCol, nColDST, _N(-1));     		/* -1 Column loop adjust				*/
	LD_W(start, [_A4]24);
	SUB(offset, nColSRC, nColDST);
	LD_DA(aXaR, [_A4]0);
	ADD(dTmpRow, nRowDST, _N(-1));     		/* -1 Row loop adjust					*/
	MOV_A(nColGroups, dTmpCol);        		/* Transfer count to Col Loop-Counter	*/
	ADDSC_A(aX, aX, start, _N(1));
	MOV_A(nRowGroups, dTmpRow);        		/* Transfer count to Row Loop-Counter	*/
IFXASM_LABEL(memcpy_loop);

	LD_H(dTmp, [aX+]2);
	ST_H([aR+]2, dTmp);
	LOOP(nColGroups, memcpy_loop);
	ADDSC_A(aX, aX, offset, _N(1));
	MOV_A(nColGroups, dTmpCol);
	LOOP(nRowGroups, memcpy_loop);

	RET();

}

void Ifx_mtxWinCopyRealQ15_fast2N(struct Ifx_mtxWinCopyRealQ15State * state){
	/* Fetch Inputs
	 *	sint16 * src[n*m]; --> offset 0
	 *	sint16 * dst[u*v]; --> offset 4
	 *	uint32 m;          --> offset 8
	 *	uint32 n;		   --> offset 12
	 *  uint32 u;          --> offset 16
	 *	uint32 v;		   --> offset 20
	 *	uint32 start;	   --> offset 24
	 */
	LD_D(nColnRowDST, [_A4]16);
	LD_D(nColnRowSRC, [_A4]8);
	SH(dTmpCol, nColDST, _N(-1));			/* nCol/2 for dst matrix size divisible by 2 	*/
	LD_W(start, [_A4]24);
	ADD(dTmpCol, dTmpCol, _N(-1));     		/* -1 Column loop adjust						*/
	LD_DA(aXaR, [_A4]0);
	SH(dTmpRow, nRowDST, _N(-1));			/* nRow/2 for dst matrix size divisible by 2 	*/
	MOV_A(nColGroups, dTmpCol);        		/* Transfer count to Col Loop-Counter			*/
	ADD(dTmpRow, dTmpRow, _N(-1));     		/* -1 Row loop adjust							*/
	ADDSC_A(aX, aX, start, _N(1));
	SUB(offset, nColSRC, nColDST);
	MOV_A(nRowGroups, dTmpRow);        		/* Transfer count to Row Loop-Counter			*/
IFXASM_LABEL(memcpy_loop2N);

	LD_W(dTmp, [aX+]4);
	ST_W([aR+]4, dTmp);
	LOOP(nColGroups, memcpy_loop2N);
	ADDSC_A(aX, aX, offset, _N(1));
	MOV_A(nColGroups, dTmpCol);
	LOOP(nRowGroups, memcpy_loop2N);

	RET();

}

void Ifx_mtxWinCopyRealQ15_fast4N(struct Ifx_mtxWinCopyRealQ15State * state){
	/* Fetch Inputs
	 *	sint16 * src[n*m]; --> offset 0
	 *	sint16 * dst[u*v]; --> offset 4
	 *	uint32 m;          --> offset 8
	 *	uint32 n;		   --> offset 12
	 *  uint32 u;          --> offset 16
	 *	uint32 v;		   --> offset 20
	 *	uint32 start;	   --> offset 24
	 */
	LD_D(nColnRowDST, [_A4]16);
	LD_D(nColnRowSRC, [_A4]8);
	SH(dTmpCol, nColDST, _N(-2));			/* nCol/4 for dst matrix size divisible by 4 	*/
	LD_W(start, [_A4]24);
	ADD(dTmpCol, dTmpCol, _N(-1));     		/* -1 Column loop adjust						*/
	LD_DA(aXaR, [_A4]0);
	SH(dTmpRow, nRowDST, _N(-2));			/* nRow/4 for dst matrix size divisible by 4 	*/
	MOV_A(nColGroups, dTmpCol);        		/* Transfer count to Col Loop-Counter			*/
	ADD(dTmpRow, dTmpRow, _N(-1));     		/* -1 Row loop adjust							*/
	ADDSC_A(aX, aX, start, _N(1));
	SUB(offset, nColSRC, nColDST);
	MOV_A(nRowGroups, dTmpRow);        		/* Transfer count to Row Loop-Counter			*/
IFXASM_LABEL(memcpy_loop4N);

	LD_D(dTmpExt, [aX+]8);
	ST_D([aR+]8, dTmpExt);
	LOOP(nColGroups, memcpy_loop4N);
	ADDSC_A(aX, aX, offset, _N(1));
	MOV_A(nColGroups, dTmpCol);
	LOOP(nRowGroups, memcpy_loop4N);

	RET();

}

#if defined(__GNUC__)
	#pragma section
#elif defined(__TASKING__)
	#pragma section code
#endif

#undef     	aX
#undef     	aR
#undef     	nColnRowSRC
#undef     	nRowSRC
#undef     	nColSRC
#undef     	nColnRowDST
#undef     	nRowDST
#undef     	nColDST
#undef		offset
#undef 		start
#undef     	nColGroups
#undef     	nRowGroups
#undef     	sseX
#undef     	ssoX
#undef     	sseR
#undef     	seR
#undef     	ssoR
#undef     	soR
#undef     	dTmpCol
#undef     	dTmpRow
#undef 		dTmp
#undef 		dTmpExt
