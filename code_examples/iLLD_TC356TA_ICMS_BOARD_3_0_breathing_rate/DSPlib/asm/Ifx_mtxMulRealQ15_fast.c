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

#define     aX          _A4  	/* a4 Ptr to first input matrix				*/
#define     aY          _A5    	/* a5 Ptr to second input matrix			*/
#define 	aXaY		_PA4	/* Paired aY aY								*/
#define     aR          _A6    	/* a6 Ptr to output matrix					*/
#define     nColnRow    _E4     /* combined d5 d4							*/
#define     nRowX       _D4     /* d4 Number of rows of first matrix		*/
#define     nColX       _D5     /* d5 Number of columns of first matrix		*/
#define     nColY       _D6     /* d6 Number of columns of second matrix	*/
#define     anColX      _A13    /* Loop-Cnt-Reg for outer loop				*/
#define     nColY_2     _D7     /* Loop-Cnt-Reg for middle loop				*/
#define     dColY_2     _D12    /* holds cnt = nColY/2 - 1					*/
#define     nColX_2     _D14    /* Loop-Cnt-Reg for inner loop				*/
#define     dColX_2     _D13    /* holds cnt = dColX/2 - 1					*/
#define     ssY         _D10    /* Two input values of second matrix		*/
#define     ssX         _D11    /* Two input values of first matrix			*/
#define     ssXll       _D11LL
#define     llAcc       _E8     /* Matrix multiplication result				*/
#define     ssAcc       _D8     /* Matrix multiplication result				*/
#define     aX0         _A12    /* Ptr to first matrix						*/
#define     aY0         _A2     /* Ptr to second matrix						*/
#define     aY1         _A3     /* Ptr to second matrix						*/
#define     a2nColY     _A7     /* a2nColY = 2*nColY						*/
#define     dTmp        _D15    /* Generic temporary Data-Reg				*/
#define     dConst0     _D3     /* Constant0=0								*/
#define     dConst0ul   _D3UL

#if defined(__GNUC__)
	#pragma section ".cpu0_psram" awx
#elif defined(__TASKING__)
	#pragma section code "cpu0_psram"
#endif

void Ifx_mtxMulRealQ15_fast(struct Ifx_mtxMulRealQ15State * state){
	/* Fetch inputs
	*	  sint16 * sr1;   	  --> offset 0
	*	  sint16 * sr2;  	  --> offset 4
	*	  sint16 * dest; 	  --> offset 8
	*	  uint32 m;       	  --> offset 12
	*	  uint32 n;			  --> offset 16
	*	  uint32 k;			  --> offset 20
	*/

	LD_D(nColnRow, [_A4]12);
	LD_W(nColY, [_A4]20);
	LD_A(aR,[_A4]8);
	LD_DA(aXaY,[_A4]);

    ADD(nRowX, nRowX, _N(-1));     				/* -1 loop adjust for outer loop 			*/
    MOV_AA(aY0, aY);			              	/* Store Ptr to second input matrix in aY0	*/
    SH(nColY_2, nColY, _N(-1));   				/* nColY_2 = nColY/2						*/
    MOV_AA(aY1, aY);              				/* Store Ptr to second input matrix in aY1	*/
    ADD(nColY_2, nColY_2, _N(-1)); 				/* -1 loop adjust for middle loop			*/
    MOV_A(a2nColY, _N(0));          			/* Clear reg.								*/
    ADDSC_A(a2nColY, a2nColY, nColY, _N(1));	/* Used for incrementing the address ptr of
    											   second matrix to point to next row		*/
    SH(nColX_2, nColX, _N(-1));   				/* nColX_2 = nColX/2						*/
    ADD(dColX_2, nColX_2, _N(-1)); 				/* -1 loop adjust for inner loop			*/
    MOV(dColY_2, nColY_2);     					/* Store loop count of middle loop			*/
    MOV_AA(aX0, aX);              				/* Store Ptr to First input matrix in aX0	*/
    MOV_A(anColX, dColX_2);      				/* Store loop count of inner loop			*/
    MOV(dConst0, _N(0));          				/* Clear									*/

/* Outer Loop:
 * The index i,j of X[i][j] in the comments are valid only for the first iteration of outer loop.
 * For each next loop i should be incremented by 1 and j is always zero
 */
IFXASM_LABEL(MatM_RowXL);

/* Middle Loop:
 * The index i,j of X[i][j] in the comments are valid only for the first iteration of middle loop.
 * For each next loop i remains the same as outer loop and j is always zero
 * The index i,j of Y[i][j] in the comment is valid only for the first iteration of middle loop.
 * For each next loop i is always zero and j should be incremented by 2
 */
IFXASM_LABEL(MatM_ColY_2L);
    MOV_AA(aX, aX0);              				/* aX points X[i][0]						*/
    MOV(llAcc, _N(0));

/* Inner Loop:
 * The index i,j of X[i][j] in the comments are valid only for the first iteration of inner loop.
 * For each next loop i remains the same and j should be incremented by 2
 * The index i,j of Y[i][j] in the comments are valid only for the first iteration of inner loop.
 * For each next loop i should be incremented by 1 and j remains the same
 */
IFXASM_LABEL(MatM_ColX_2L);
    LD_W(ssY,[aY+]0);          					/* ssY <- Y[0][j], Y[0][j+1]				*/
    ADDSC_A(aY, aY, nColY, _N(1));      		/* aY points to Y[1][0]						*/
    LD_W(ssX,[aX+]4);      						/* ssX <- X[i][0], X[i][1]					*/
    MADDS_H(llAcc, llAcc, ssY, ssXll, _N(1));	/* llAcc += Y[0][j]*X[i][0]
     	 	 	 	 	 	 	 	 	 	 	   	   	   	Y[0][j+1]*X[i][0]				*/
    LD_W(ssY, [aY+]0);          				/* ssY <- Y[1][j], Y[1][j+1]				*/
    SH(ssX, ssX, _N(-16));        				/* >>16 bring X[j][1] to lower 16-bits		*/
    ADD_A_3ARGS(aY, aY, a2nColY);       		/* aY points to Y[2][0]						*/
    MADDS_H(llAcc, llAcc, ssY, ssXll, _N(1));	/* llAcc += Y[1][j]  *X[i][1]
    								         	            Y[1][j+1]*X[i][1]				*/
    LOOP(anColX, MatM_ColX_2L);
/* End of Inner Loop																		*/

    ADD_A(aY0, _N(4));             			 	/* aY0 points to Y[0][j+2]					*/
    MADDRS_H(ssAcc, llAcc, dConst0, dConst0ul, _N(1));  /* V1.21->Rnd(32||32) -> 16||16		*/
    ST_W([aR+]4, ssAcc);    					/* V1.21->[aR] <- 16||16					*/
    MOV_AA(aY, aY0);              				/* Transfer aY0 to aY						*/
    MOV_A( anColX, dColX_2);      				/* Transfer inner loop count to Loop-Counter */
/* End of Middle Loop																		*/

    JNED(nColY_2, _N(0), MatM_ColY_2L);
    ADDSC_A(aX0, aX0, nColX,_N(1));    			/* aX0 points to X[i+1][0]					*/
    MOV(nColY_2,dColY_2);	     				/* Transfer middle loop-cnt to Loop-Counter	*/
    MOV_AA(aY, aY1);              				/* Initialize the pointer aY to Y[0][0]		*/
    MOV_AA(aY0, aY1);             				/* Initialize the pointer aY to Y[0][0]		*/
    JNED(nRowX, _N(0), MatM_RowXL);

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
#undef     nColnRow
#undef     nRowX
#undef     nColX
#undef     nColY
#undef     anColX
#undef     nColY_2
#undef     dColY_2
#undef     nColX_2
#undef     dColX_2
#undef     ssY
#undef     ssX
#undef     ssXll
#undef     llAcc
#undef     ssAcc
#undef     aX0
#undef     aY0
#undef     aY1
#undef     a2nColY
#undef     dTmp
#undef     dConst0
#undef     dConst0ul
