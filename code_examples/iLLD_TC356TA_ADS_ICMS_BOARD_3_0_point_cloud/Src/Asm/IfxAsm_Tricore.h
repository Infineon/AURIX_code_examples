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

#ifndef IFXASM_TRICORE_H_
#define IFXASM_TRICORE_H_


/** Compiler Specific Instructions **/

#if defined(__DCC__)
#include "IfxAsm_Tricore_Dcc.h"

#elif defined(__GNUC__)
#include "IfxAsm_Tricore_Gnuc.h"
#define JNZ_T(Arg1,Arg2,Arg3)				IFXASM_INST3(jnz.t,Arg1,Arg2,Arg3)
#define INS_T(Arg1,Arg2,Arg3,Arg4,Arg5)		IFXASM_INST5(ins.t,Arg1,Arg2,Arg3,Arg4,Arg5)
#define RSUB(Arg1,Arg2,Arg3)				IFXASM_INST3(rsub,Arg1,Arg2,Arg3)
#define JZ_T(Arg1,Arg2,Arg3) 				IFXASM_INST3(jz.t,Arg1,Arg2,Arg3)
#define INSN_T(Arg1,Arg2,Arg3,Arg4,Arg5)	IFXASM_INST5(insn.t,Arg1,Arg2,Arg3,Arg4,Arg5)
#define LD_D_FFT(Arg1,Arg2,Arg3)			IFXASM_INST2(ld.d,Arg1,Arg2)
#define EXTERN_ASM(Arg)

#elif defined(__TASKING__)
#include "IfxAsm_Tricore_Tasking.h"
#define JNZ_T(Arg1,Arg2,Arg3)				IFXASM_INST2(jnz.t,Arg1:Arg2,Arg3)
#define JZ_T(Arg1,Arg2,Arg3) 				IFXASM_INST2(jz.t,Arg1:Arg2,Arg3)
#define INS_T(Arg1,Arg2,Arg3,Arg4,Arg5)		IFXASM_INST3(ins.t,Arg1,Arg2:Arg3,Arg4:Arg5)
#define RSUB(Arg1,Arg2,Arg3)				IFXASM_INST3(rsub,Arg1,Arg2,Arg3)
#define INSN_T(Arg1,Arg2,Arg3,Arg4,Arg5)	IFXASM_INST3(insn.t,Arg1,Arg2:Arg3,Arg4:Arg5)
#define LD_D_FFT(Arg1,Arg2,Arg3)			IFXASM_INST2(ld.d,Arg1,Arg3)
#define EXTERN_ASM(Arg1)					__asm(".extern "Arg1)

#else
#error Compiler unsupported
#endif


/** General Instructions **/

/** Arithmetic Instructions **/
#define ABS(Arg1,Arg2)						IFXASM_INST2(abs,Arg1,Arg2)
#define ADD(Arg1,Arg2,Arg3) 				IFXASM_INST3(add,Arg1,Arg2,Arg3)
#define AND(Arg1,Arg2,Arg3) 				IFXASM_INST3(and,Arg1,Arg2,Arg3)
#define MUL(Arg1,Arg2,Arg3) 				IFXASM_INST3(mul,Arg1,Arg2,Arg3)
#define ADDSC_A(Arg1,Arg2,Arg3,Arg4) 		IFXASM_INST4(addsc.a,Arg1,Arg2,Arg3,Arg4)
#define MADD_F(Arg1,Arg2,Arg3,Arg4) 		IFXASM_INST4(madd.f,Arg1,Arg2,Arg3,Arg4)
#define MSUB_F(Arg1,Arg2,Arg3,Arg4) 		IFXASM_INST4(msub.f,Arg1,Arg2,Arg3,Arg4)
#define MADDM_H(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(maddm.h,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MADDMS_H(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(maddms.h,Arg1,Arg2,Arg3,Arg4,Arg5)
#define ABSS(Arg1,Arg2)						IFXASM_INST2(abss,Arg1,Arg2)
#define MIN(Arg1,Arg2,Arg3)					IFXASM_INST3(min,Arg1,Arg2,Arg3)
#define MAX(Arg1,Arg2,Arg3)					IFXASM_INST3(max,Arg1,Arg2,Arg3)
#define MAX_H(Arg1,Arg2,Arg3)				IFXASM_INST3(max.h,Arg1,Arg2,Arg3)
#define DIV(Arg1,Arg2,Arg3)					IFXASM_INST3(div,Arg1,Arg2,Arg3)
#define DIV_F(Arg1,Arg2,Arg3)				IFXASM_INST3(div.f,Arg1,Arg2,Arg3)
#define MADD_Q(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(madd.q,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MUL_Q(Arg1,Arg2,Arg3,Arg4) 			IFXASM_INST4(mul.q,Arg1,Arg2,Arg3,Arg4)
#define MOV_H(Arg1,Arg2) 					IFXASM_INST2(movh,Arg1,Arg2)
#define SUB(Arg1,Arg2,Arg3)					IFXASM_INST3(sub,Arg1,Arg2,Arg3)
#define SEL(Arg1,Arg2,Arg3,Arg4) 			IFXASM_INST4(sel,Arg1,Arg2,Arg3,Arg4)
#define EXTR_U(Arg1,Arg2,Arg3,Arg4) 		IFXASM_INST4(extr.u,Arg1,Arg2,Arg3,Arg4)
#define OR(Arg1,Arg2,Arg3)					IFXASM_INST3(or,Arg1,Arg2,Arg3)
#define CMP_F(Arg1,Arg2,Arg3)				IFXASM_INST3(cmp.f,Arg1,Arg2,Arg3)
#define MUL_F(Arg1,Arg2,Arg3)				IFXASM_INST3(mul.f,Arg1,Arg2,Arg3)
#define FTOIZ(Arg1,Arg2) 					IFXASM_INST2(ftoiz,Arg1,Arg2)
#define ADDI(Arg1,Arg2,Arg3)				IFXASM_INST3(addi,Arg1,Arg2,Arg3)
#define ADD_F(Arg1,Arg2,Arg3)				IFXASM_INST3(add.f,Arg1,Arg2,Arg3)
#define SUB_F(Arg1,Arg2,Arg3)				IFXASM_INST3(sub.f,Arg1,Arg2,Arg3)
#define EXTR(Arg1,Arg2,Arg3,Arg4) 			IFXASM_INST4(extr,Arg1,Arg2,Arg3,Arg4)
#define DVSTEP(Arg1,Arg2,Arg3) 				IFXASM_INST3(dvstep,Arg1,Arg2,Arg3)
#define DEXTR(Arg1,Arg2,Arg3,Arg4) 			IFXASM_INST4(dextr,Arg1,Arg2,Arg3,Arg4)
#define QSEED_F(Arg1,Arg2) 					IFXASM_INST2(qseed.f,Arg1,Arg2)
#define MSUBM_H(Arg1,Arg2,Arg3,Arg4,Arg5)	IFXASM_INST5(msubm.h,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MADD_U(Arg1,Arg2,Arg3,Arg4) 		IFXASM_INST4(madd.u,Arg1,Arg2,Arg3,Arg4)
#define MUL_U(Arg1,Arg2,Arg3) 				IFXASM_INST3(mul.u,Arg1,Arg2,Arg3)
#define MSUB(Arg1,Arg2,Arg3,Arg4) 			IFXASM_INST4(msub,Arg1,Arg2,Arg3,Arg4)
#define MSUB_Q(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(msub.q,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MULM_H(Arg1,Arg2,Arg3,Arg4) 		IFXASM_INST4(mulm.h,Arg1,Arg2,Arg3,Arg4)
#define ADD_A(Arg1,Arg2) 					IFXASM_INST2(add.a,Arg1,Arg2)
#define ADD_A_3ARGS(Arg1,Arg2,Arg3) 		IFXASM_INST3(add.a,Arg1,Arg2,Arg3)
#define CLS(Arg1,Arg2) 						IFXASM_INST2(cls,Arg1,Arg2)
#define MSUBS_Q(Arg1,Arg2,Arg3,Arg4,Arg5)	IFXASM_INST5(msubs.q,Arg1,Arg2,Arg3,Arg4,Arg5)
#define SUBS(Arg1,Arg2,Arg3) 				IFXASM_INST3(subs,Arg1,Arg2,Arg3)
#define SUBS_H(Arg1,Arg2,Arg3) 				IFXASM_INST3(subs.h,Arg1,Arg2,Arg3)
#define ADDS(Arg1,Arg2,Arg3) 				IFXASM_INST3(adds,Arg1,Arg2,Arg3)
#define ADDS_H(Arg1,Arg2,Arg3) 				IFXASM_INST3(adds.h,Arg1,Arg2,Arg3)
#define MADDS_Q(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(madds.q,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MADDS_H(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(madds.h,Arg1,Arg2,Arg3,Arg4,Arg5)
#define ITOF(Arg1,Arg2) 					IFXASM_INST2(itof,Arg1,Arg2)
#define PACK(Arg1,Arg2,Arg3) 				IFXASM_INST3(pack,Arg1,Arg2,Arg3)
#define MULR_H(Arg1,Arg2,Arg3,Arg4) 		IFXASM_INST4(mulr.h,Arg1,Arg2,Arg3,Arg4)
#define MADDR_H(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(maddr.h,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MSUBR_H(Arg1,Arg2,Arg3,Arg4,Arg5)	IFXASM_INST5(msubr.h,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MADDSUR_H(Arg1,Arg2,Arg3,Arg4,Arg5)	IFXASM_INST5(maddsur.h,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MSUBADR_H(Arg1,Arg2,Arg3,Arg4,Arg5)	IFXASM_INST5(msubadr.h,Arg1,Arg2,Arg3,Arg4,Arg5)
#define NOP()								IFXASM_INST0(nop)
#define CSUB(Arg1,Arg2,Arg3,Arg4) 			IFXASM_INST4(csub,Arg1,Arg2,Arg3,Arg4)
#define CMOV(Arg1,Arg2,Arg3) 				IFXASM_INST3(cmov,Arg1,Arg2,Arg3)
#define ADD_2ARGS(Arg1,Arg2) 				IFXASM_INST2(add,Arg1,Arg2)
#define MIN_H(Arg1,Arg2,Arg3) 				IFXASM_INST3(min.h,Arg1,Arg2,Arg3)
#define IXMAX(Arg1,Arg2,Arg3) 				IFXASM_INST3(ixmax,Arg1,Arg2,Arg3)
#define IXMIN(Arg1,Arg2,Arg3) 				IFXASM_INST3(ixmin,Arg1,Arg2,Arg3)
#define FTOUZ(Arg1,Arg2) 					IFXASM_INST2(ftouz,Arg1,Arg2)
#define MULS_U(Arg1,Arg2,Arg3) 				IFXASM_INST3(muls.u,Arg1,Arg2,Arg3)
#define XOR(Arg1,Arg2) 						IFXASM_INST2(xor,Arg1,Arg2)
#define SUB_A(Arg1,Arg2) 					IFXASM_INST2(sub.a,Arg1,Arg2)
#define SUB_2ARGS(Arg1,Arg2) 				IFXASM_INST2(sub,Arg1,Arg2)
#define SUB_A_3ARGS(Arg1,Arg2,Arg3) 		IFXASM_INST3(sub.a,Arg1,Arg2,Arg3)
#define UTOF(Arg1,Arg2) 					IFXASM_INST2(utof,Arg1,Arg2)
#define CLZ(Arg1,Arg2) 						IFXASM_INST2(clz,Arg1,Arg2)
#define CALL(Arg1)	 						IFXASM_INST1(call,Arg1)
#define INSERT(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(insert,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MULR_Q(Arg1,Arg2,Arg3,Arg4) 		IFXASM_INST4(mulr.q,Arg1,Arg2,Arg3,Arg4)
#define MADDR_Q(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(maddr.q,Arg1,Arg2,Arg3,Arg4,Arg5)
#define MADDRS_H(Arg1,Arg2,Arg3,Arg4,Arg5) 	IFXASM_INST5(maddrs.h,Arg1,Arg2,Arg3,Arg4,Arg5)

/** Move Instructions **/
#define MOV(Arg1,Arg2) 						IFXASM_INST2(mov,Arg1,Arg2)
#define MOV_A(Arg1,Arg2) 					IFXASM_INST2(mov.a,Arg1,Arg2)
#define MOV_AA(Arg1,Arg2) 					IFXASM_INST2(mov.aa,Arg1,Arg2)
#define MOVH_A(Arg1,Arg2) 					IFXASM_INST2(movh.a,Arg1,Arg2)
#define MOV_D(Arg1,Arg2) 					IFXASM_INST2(mov.d,Arg1,Arg2)
#define SH(Arg1,Arg2,Arg3) 					IFXASM_INST3(sh,Arg1,Arg2,Arg3)
#define SH_H(Arg1,Arg2,Arg3) 				IFXASM_INST3(sh.h,Arg1,Arg2,Arg3)
#define SHAS(Arg1,Arg2,Arg3) 				IFXASM_INST3(shas,Arg1,Arg2,Arg3)
#define SH_2ARGS(Arg1,Arg2) 				IFXASM_INST2(sh,Arg1,Arg2)
#define SHA(Arg1,Arg2,Arg3) 				IFXASM_INST3(sha,Arg1,Arg2,Arg3)
#define SHA_2ARGS(Arg1,Arg2) 				IFXASM_INST2(sha,Arg1,Arg2)
#define SHA_H(Arg1,Arg2,Arg3) 				IFXASM_INST3(sha.h,Arg1,Arg2,Arg3)
#define MOV_3ARGS(Arg1,Arg2,Arg3) 			IFXASM_INST3(mov,Arg1,Arg2,Arg3)
#define SH_LT(Arg1,Arg2,Arg3) 				IFXASM_INST3(sh.lt,Arg1,Arg2,Arg3)
#define SH_EQ(Arg1,Arg2,Arg3) 				IFXASM_INST3(sh.eq,Arg1,Arg2,Arg3)
#define MOV_U(Arg1,Arg2) 					IFXASM_INST2(mov.u,Arg1,Arg2)

/** Load-Store Instructions **/
#define ST_Q(Arg1,Arg2) 					IFXASM_INST2(st.q,Arg1,Arg2)
#define ST_D(Arg1,Arg2) 					IFXASM_INST2(st.d,Arg1,Arg2)
#define ST_DA(Arg1,Arg2) 					IFXASM_INST2(st.da,Arg1,Arg2)
#define LD_D(Arg1,Arg2) 					IFXASM_INST2(ld.d,Arg1,Arg2)
#define LD_A(Arg1,Arg2) 					IFXASM_INST2(ld.a,Arg1,Arg2)
#define LD_DA(Arg1,Arg2) 					IFXASM_INST2(ld.da,Arg1,Arg2)
#define LD_W(Arg1,Arg2) 					IFXASM_INST2(ld.w,Arg1,Arg2)
#define ST_A(Arg1,Arg2) 					IFXASM_INST2(st.a,Arg1,Arg2)
#define ST_H(Arg1,Arg2) 					IFXASM_INST2(st.h,Arg1,Arg2)
#define LD_D(Arg1,Arg2) 					IFXASM_INST2(ld.d,Arg1,Arg2)
#define ST_W(Arg1,Arg2) 					IFXASM_INST2(st.w,Arg1,Arg2)
#define LD_Q(Arg1,Arg2) 					IFXASM_INST2(ld.q,Arg1,Arg2)
#define LD_H(Arg1,Arg2) 					IFXASM_INST2(ld.h,Arg1,Arg2)
#define LD_HU(Arg1,Arg2) 					IFXASM_INST2(ld.hu,Arg1,Arg2)

/** Branch Instructions **/
#define LEA(Arg1,Arg2) 						IFXASM_INST2(lea,Arg1,Arg2)
#define LOOP(Arg1,Arg2) 					IFXASM_INST2(loop,Arg1,Arg2)
#define JNED(Arg1,Arg2,Arg3) 				IFXASM_INST3(jned,Arg1,Arg2,Arg3)
#define MFCR(Arg1,Arg2) 					IFXASM_INST2(mfcr,Arg1,Arg2)
#define JNZ(Arg1,Arg2)						IFXASM_INST2(jnz,Arg1,Arg2)
#define GE(Arg1,Arg2,Arg3)					IFXASM_INST3(ge,Arg1,Arg2,Arg3)
#define JEQ(Arg1,Arg2,Arg3)					IFXASM_INST3(jeq,Arg1,Arg2,Arg3)
#define NE(Arg1,Arg2,Arg3) 					IFXASM_INST3(ne,Arg1,Arg2,Arg3)
#define J(Arg1) 							IFXASM_INST1(j,Arg1)
#define JZ(Arg1,Arg2) 						IFXASM_INST2(jz,Arg1,Arg2)
#define JLT(Arg1,Arg2,Arg3) 				IFXASM_INST3(jlt,Arg1,Arg2,Arg3)
#define LT(Arg1,Arg2,Arg3) 					IFXASM_INST3(lt,Arg1,Arg2,Arg3)
#define LT_H(Arg1,Arg2,Arg3) 				IFXASM_INST3(lt.h,Arg1,Arg2,Arg3)
#define JI(Arg1) 							IFXASM_INST1(ji,Arg1)
#define JNE(Arg1,Arg2,Arg3) 				IFXASM_INST3(jne,Arg1,Arg2,Arg3)
#define JLTZ(Arg1,Arg2) 					IFXASM_INST2(jltz,Arg1,Arg2)
#define JLT_U(Arg1,Arg2,Arg3) 				IFXASM_INST3(jlt.u,Arg1,Arg2,Arg3)



#endif
