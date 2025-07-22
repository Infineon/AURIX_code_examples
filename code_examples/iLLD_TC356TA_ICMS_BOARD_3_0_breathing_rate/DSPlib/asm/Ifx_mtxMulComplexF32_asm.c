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

#define     W32         4

#define     aY00        _A3
#define		dC8			_D7	/* Const add of 8 */

/* dReg matrix sizes */
#define     nRowX       _D4
#define     nColX       _D5
#define     nColY       _D6

/* dReg matrix data */
#define		llXri       _E0
#define		lXr         _D0
#define		lXi         _D1

#define		llYri       _E2
#define		lYr         _D2
#define		lYi         _D3

#define		llRri       _E8
#define		lRr         _D8
#define		lRi         _D9

/* aReg ptr to matrix data */
#define     aX0         _A12      /* Ptr to first matrix (saved) */
#define     aX          _A4       /* Ptr to first input matrix src1 */
#define     aY0         _A2       /* Ptr to second matrix (saved) */
#define     aY          _A5       /* Ptr to second input matrix src2 */
#define     aR          _A6       /* Ptr to output matrix dst */

/* loop cntr, loop values */
#define     anColX      _A13
#define     dColX_1     _D14

#define     anColY      _A14
#define     dColY_1     _D15

void Ifx_mtxMulComplexF32_asm (struct Ifx_mtxMulComplexF32State * state)
{
	/**
	  	enum Ifx_mode mode;   --> offset 0
		cfloat32 * dst;  	  --> offset 4
		cfloat32 * src1; 	  --> offset 8
		cfloat32 * src2; 	  --> offset 12
		uint32 m;       	  --> offset 16
		uint32 n;			  --> offset 20
		uint32 l;			  --> offset 24
	 */

	LD_W(nRowX, [_A4]16);
	LD_W(nColY, [_A4]20);
	LD_W(nColX, [_A4]24);

	LD_A(aY,[_A4]12);
	LD_A(aR,[_A4]4);
	LD_A(aX,[_A4]8);

	MOV_AA(aX0, aX);
	MOV_AA(aY0, aY);
	MOV_AA(aY00, aY);

	ADD(dColX_1, nColX, _N(-1));
	ADD(dColY_1, nColY, _N(-1));
	ADD(nRowX, nRowX, _N(-1));

	MOV(dC8, _N(8));

	/* ---------------------------------------
	* Outer Loop Calculate All-Rows of output (M) = Complete Matrix */
IFXASM_LABEL(M);
	MOV_AA(aY0, aY00);			/* aY points */
	MOV_AA(aY, aY00);
	MOV_A(anColY, dColY_1);		/* Middle loop counter */

	/* ---------------------------------------
	* Mid Loop Calculate One-Row of output (N) */
IFXASM_LABEL(N);
	MUL(llRri, _D0, _N(0));			/* Clear llRri registers */
	MOV_AA(aX, aX0);			/* aX points X[i][0] */
	MOV_A(anColX, dColX_1);		/* Inner loop counter (M) */

	/*  Repeat nColX times (L) */
    /* -----kernel Calculate One-Value of output */
IFXASM_LABEL(L);
	LD_D(llXri, [aX+]2*W32);
	LD_D(llYri, [aY+]0);
	ADDSC_A(aY, aY, nColY, _N(3));

	MADD_F(lRr, lRr, lXr, lYr);		/*  lRr = lRr + lXr*lYr */
	MADD_F(lRi, lRi, lXr, lYi);		/*  lRi = lRi + lXr*lYi */
	MSUB_F(lRr, lRr, lXi, lYi);		/*  lRr = lRr + lXr*lYr - lXi*lYi */
	MADD_F(lRi, lRi, lXi, lYr);  	/*  lRi = lRr + lXr*lYr + lXi*lYr */
	LOOP(anColX, L);

	/* ===================================
	* Mid Loop */

	ST_D([aR+]2*W32, llRri);
	ADDSC_A(aY0, aY0, dC8, _N(0));
	MOV_AA(aY, aY0);				 /* Transfer aY0 to aY */
	LOOP(anColY, N);

	/* ------------------- Outer loop ends ------------------------------------------ */
	/* Outer Loop M */
	ADDSC_A(aX0, aX0, nColX, _N(3));
	JNED(nRowX, _N(0), M);

	RET();
}
