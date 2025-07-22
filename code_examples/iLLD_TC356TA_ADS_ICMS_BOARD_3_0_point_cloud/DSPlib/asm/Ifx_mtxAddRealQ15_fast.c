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
#define     aY          _A5       /* Ptr to second matrix				*/
#define 	aXaY		_PA4	  /* Paired aY aY						*/
#define     aR          _A6       /* Ptr to output matrix				*/
#define     nRow        _D4       /* Number of rows						*/
#define     nCol        _D5       /* Number of columns					*/
#define     nColnRow    _E4       /* Packed number of Columns and Rows	*/
#define     MAddCnt     _A2       /* Loop-Cnt-Reg						*/
#define     ssssX       _E2       /* First matrix entries				*/
#define     sseX        _D2       /* Even-Reg							*/
#define     ssoX        _D3       /* Odd-Reg							*/
#define     ssssY       _E6       /* Second matrix entries				*/
#define     sseY        _D6       /* Even-Reg							*/
#define     ssoY        _D7       /* Odd-Reg							*/
#define     ssssR       _E8       /* Output matrix values				*/
#define     sseR        _D8       /* Even-Reg							*/
#define     ssoR        _D9       /* Odd-Reg							*/
#define     dTmp        _D1       /* Generic temporary Data-Reg			*/

#if defined(__GNUC__)
	#pragma section ".cpu0_psram" awx
#elif defined(__TASKING__)
	#pragma section code "cpu0_psram"
#endif

void Ifx_mtxAddRealQ15_fast(struct Ifx_mtxRealQ15State * state){
	/* Fetch Inputs
	 *	sint16 * sr1;  	  --> offset 0
	 *	sint16 * sr2; 	  --> offset 4
	 *	sint16 * dest;	  --> offset 8
	 *	uint32 m;         --> offset 12
	 *	uint32 n;		  --> offset 16
	 */
	LD_D(nColnRow, [_A4]12);
	LD_A(aR,[_A4]8);
    MUL(dTmp, nRow, nCol);       	/* dTmp = nRow * nCol						*/
	LD_DA(aXaY,[_A4]0);

    LD_D(ssssX, [aX+]8);	     	/* ssssX <- First four values of matrix X	*/
    SH(dTmp, dTmp, _N(-2));      	/* dTmp = nRow * nCol/4						*/
    LD_W(ssoY, [aY+]4);		     	/* ssoY <- First two values of matrix Y		*/
    ADD(dTmp, dTmp, _N(-1));     	/* -1 loop adjust							*/
    MOV_A(MAddCnt, dTmp);        	/* Transfer count to Loop-Counter			*/

IFXASM_LABEL(MatAdd_AddL);
    ADDS_H(sseR, sseX, ssoY);      	/* sseR (lo) =  X[j] + Y[j]
                                   	   sseR (hi) = X[j+1] + Y[j+1]					*/
    LD_D(ssssY,[aY+]8);		    	/* ssssY <- next four values of matrix Y		*/
    ADDS_H(ssoR, ssoX, sseY);       /* ssoR (lo) =  X[j+2] + Y[j+2]
                                       ssoR (hi) = X[j+3] + Y[j+3]					*/
    LD_D(ssssX,[aX+]8);    			/* ssssX <- next four values of matrix X		*/
    ST_D([aR+]8,ssssR);    			/* Results of sum of four corresponding
                            		   entries of X and Y stored to R				*/
    LOOP(MAddCnt, MatAdd_AddL);

    RET();
}

/* Faster version for cases where nCols*nRows is divisible by 4	*/
void Ifx_mtxAddRealQ15_fast4N(struct Ifx_mtxRealQ15State * state){
	/* Fetch Inputs
	 *	sint16 * sr1;  	  --> offset 0
	 *	sint16 * sr2; 	  --> offset 4
	 *	sint16 * dest;	  --> offset 8
	 *	uint32 m;         --> offset 12
	 *	uint32 n;		  --> offset 16
	 */
	LD_D(nColnRow, [_A4]12);
	LD_A(aR,[_A4]8);
    MUL(dTmp, nRow, nCol);       	/* dTmp = nRow * nCol 							*/
	LD_DA(aXaY,[_A4]0);

    LD_D(ssssX, [aX+]8);	     	/* ssssX <- First four values of matrix X		*/
    SH(dTmp, dTmp, _N(-3));      	/* dTmp = nRow * nCol/8							*/
    LD_D(ssssY, [aY+]8);		   	/* ssssY	 <- First four values of matrix Y	*/
    ADD(dTmp, dTmp, _N(-1));     	/* -1 loop adjust								*/
    MOV_A(MAddCnt, dTmp);        	/* Transfer count to Loop-Counter				*/

IFXASM_LABEL(MatAdd_AddL4N);
    ADDS_H(_D8, _D2, _D6);      	/* D8 (lo) =  X[j] + Y[j]
                                   	   D8 (hi) = X[j+1] + Y[j+1]				*/
    LD_D(_E10,[aX+]8);		    	/* E10 <- next four values of matrix Y		*/
    ADDS_H(_D9, _D3, _D7);       	/* D9 (lo) =  X[j+2] + Y[j+2]
                                       D9 (hi) = X[j+3] + Y[j+3] 				*/
    LD_D(_E12,[aY+]8);    			/* E12 <- next four values of matrix Y		*/
    ST_D([aR+]8,_E8);    			/* Results of sum of four corresponding
                            		   entries of X and Y stored to R			*/
    ADDS_H(_D8, _D10, _D12);      	/* D8 (lo) =  X[j+4] + Y[j+4]
                                   	   D8 (hi) = X[j+5] + Y[j+5]				*/
    LD_D(_E2,[aX+]8);		    	/* E2 <- next four values of matrix Y		*/
    ADDS_H(_D9, _D11, _D13);        /* D9 (lo) =  X[j+6] + Y[j+6]
                                       D9 (hi) = X[j+7] + Y[j+7] 				*/
    LD_D(_E6,[aY+]8);    			/* E6 <- next four values of matrix Y		*/
    ST_D([aR+]8,_E8);    			/* Results of sum of four corresponding		*/

    LOOP(MAddCnt, MatAdd_AddL4N);

    RET();
}
#if defined(__GNUC__)
	#pragma section
#elif defined(__TASKING__)
	#pragma section code
#endif

#undef     aX
#undef     aY
#undef 	   aXaY
#undef     aR
#undef     nRow
#undef     nCol
#undef     nColnRow
#undef     MAddCnt
#undef     ssssX
#undef     sseX
#undef     ssoX
#undef     ssssY
#undef     sseY
#undef     ssoY
#undef     ssssR
#undef     sseR
#undef     ssoR
#undef     dTmp
