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

#ifndef IFXASM_TRICORE_DCC_H_
#define IFXASM_TRICORE_DCC_H_

#define _A0 %a0
#define _A1 %a1
#define _A2 %a2
#define _A3 %a3
#define _A4 %a4
#define _A5 %a5
#define _A6 %a6
#define _A7 %a7
#define _A8 %a8
#define _A9 %a9
#define _A10 %a10
#define _A11 %a11
#define _A12 %a12
#define _A13 %a13
#define _A14 %a14
#define _A15 %a15
#define _D0 %d0
#define _D1 %d1
#define _D2 %d2
#define _D3 %d3
#define _D4 %d4
#define _D5 %d5
#define _D6 %d6
#define _D7 %d7
#define _D8 %d8
#define _D9 %d9
#define _D10 %d10
#define _D11 %d11
#define _D12 %d12
#define _D13 %d13
#define _D14 %d14
#define _D15 %d15
#define _D0U %d0u
#define _D1U %d1u
#define _D2U %d2u
#define _D3U %d3u
#define _D4U %d4u
#define _D5U %d5u
#define _D6U %d6u
#define _D7U %d7u
#define _D8U %d8u
#define _D9U %d9u
#define _D10U %d10u
#define _D11U %d11u
#define _D12U %d12u
#define _D13U %d13u
#define _D14U %d14u
#define _D15U %d15u
#define _D0UL %d0UL
#define _D1UL %d1UL
#define _D2UL %d2UL
#define _D3UL %d3UL
#define _D4UL %d4UL
#define _D5UL %d5UL
#define _D6UL %d6UL
#define _D7UL %d7UL
#define _D8UL %d8UL
#define _D9UL %d9UL
#define _D10UL %d10UL
#define _D11UL %d11UL
#define _D12UL %d12UL
#define _D13UL %d13UL
#define _D14UL %d14UL
#define _D15UL %d15UL
#define _D0LL %d0LL
#define _D1LL %d1LL
#define _D2LL %d2LL
#define _D3LL %d3LL
#define _D4LL %d4LL
#define _D5LL %d5LL
#define _D6LL %d6LL
#define _D7LL %d7LL
#define _D8LL %d8LL
#define _D9LL %d9LL
#define _D10LL %d10LL
#define _D11LL %d11LL
#define _D12LL %d12LL
#define _D13LL %d13LL
#define _D14LL %d14LL
#define _D15LL %d15LL
#define _D0UU %d0UU
#define _D1UU %d1UU
#define _D2UU %d2UU
#define _D3UU %d3UU
#define _D4UU %d4UU
#define _D5UU %d5UU
#define _D6UU %d6UU
#define _D7UU %d7UU
#define _D8UU %d8UU
#define _D9UU %d9UU
#define _D10UU %d10UU
#define _D11UU %d11UU
#define _D12UU %d12UU
#define _D13UU %d13UU
#define _D14UU %d14UU
#define _D15UU %d15UU
#define _E0 %e0
#define _E2 %e2
#define _E4 %e4
#define _E6 %e6
#define _E8 %e8
#define _E10 %e10
#define _E12 %e12
#define _E14 %e14
#define _PA0 %a0
#define _PA2 %a2
#define _PA4 %a4
#define _PA6 %a6
#define _PA8 %a8
#define _PA10 %a10
#define _PA12 %a12
#define _PA14 %a14
#define _PD0 %d0
#define _PD2 %d2
#define _PD4 %d4
#define _PD6 %d6
#define _PD8 %d8
#define _PD10 %d10
#define _PD12 %d12
#define _PD14 %d14

#define _SP %sp

#define __N(number) number
#define _N(number) __N(number)
#define _M(reg,off) [reg]off

#define __HI(symbol) symbol
#define _HI(symbol) __HI(symbol)@ha
#define __LO(symbol) symbol
#define _LO(symbol) __LO(symbol)@l

#define IFXASM_INST1(asmInstruction,Arg1) asm("\t"#asmInstruction " "#Arg1)
#define IFXASM_INST2(asmInstruction,Arg1,Arg2) asm("\t"#asmInstruction " "#Arg1", "#Arg2)
#define IFXASM_INST3(asmInstruction,Arg1,Arg2,Arg3) asm("\t"#asmInstruction " "#Arg1", "#Arg2", "#Arg3)
#define IFXASM_INST4(asmInstruction,Arg1,Arg2,Arg3,Arg4) asm("\t"#asmInstruction " "#Arg1", "#Arg2", "#Arg3", "#Arg4)
#define IFXASM_INST5(asmInstruction,Arg1,Arg2,Arg3,Arg4,Arg5) asm("\t"#asmInstruction " "#Arg1", "#Arg2", "#Arg3", "#Arg4", "#Arg5)

#define IFXASM_ALIGNMENT_2() __asm("\t.align 2")
#define IFXASM_ALIGNMENT_4() __asm("\t.align 4")
#define IFXASM_ALIGNMENT_8() __asm("\t.align 8")
#define IFXASM_ALIGNMENT_16() __asm("\t.align 16")
#define IFXASM_ALIGNMENT_32() __asm("\t.align 32")
#define IFXASM_ALIGNMENT_64() __asm("\t.align 64")

#define _IFXASM_FUNCTION(Name, Scope) asm ("\t.export "#Name"\n"#Name":");
#define IFXASM_FUNCTION(Name, Scope) _IFXASM_FUNCTION(Name, Scope)
#define IFXASM_FUNCTION_END(Name)

#define IFXASM_LABEL(Label) asm (#Label":");

#define _IFXASM_CODE_SECTION(FunctionName,Section,Type)
#define IFXASM_CODE_SECTION(FunctionName,Section,Type) _IFXASM_CODE_SECTION(FunctionName,Section,Type)

#define RET() asm ("\tret")
#define RSTV() asm("\trstv")

#endif /* IFXASM_TRICORE_GNUC_H_ */
