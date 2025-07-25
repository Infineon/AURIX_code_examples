/**
 * \file CompilerTasking.h
 *
 * \version iLLD_New
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such
 * terms of use are agreed, use of this file is subject to following:
 *
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or
 * organization obtaining a copy of the software and accompanying
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef COMPILERTASKING_H
#define COMPILERTASKING_H 1

/******************************************************************************/

#include <stddef.h>

/*Linker definitions which are specific to Tasking */
/* IFX_CFG_USE_COMPILER_DEFAULT_LINKER shall be defined in Ifx_Cfg.h
 * to use the default compiler linker varaibles and startup */
#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER

#ifndef __cplusplus
/*Start: Common definitions ********************************************** */
#define IFXCOMPILER_COMMON_LINKER_SYMBOLS() \
    __asm("\t .extern _SMALL_DATA_, _LITERAL_DATA_, _A8_DATA_, _A9_DATA_");

/*End: Common definitions ********************************************** */

/*Start: Core 0 definitions ********************************************** */

#define IFXCOMPILER_CORE_LINKER_SYMBOLS(cpu)                                                                         \
    __asm("\t .extern __USTACK"#cpu);         /**< user stack end is required as asm to be used with setreg macro */ \
    extern unsigned int __ISTACK##cpu[];      /**< interrupt stack end */                                            \
    extern unsigned int __INTTAB_CPU##cpu[];  /**< interrupt vector table */                                         \
    extern unsigned int __TRAPTAB_CPU##cpu[]; /**< trap vector table */                                              \
    extern unsigned int __CSA##cpu[];         /**< context save area begin */                                        \
    extern unsigned int __CSA##cpu##_END[];   /**< context save area end   */
#endif

#define __USTACK(cpu,vm)      __USTACK##cpu##vm
#define __ISTACK(cpu,vm)      __ISTACK##cpu##vm
#define __INTTAB_CPU(cpu,vm)  __INTTAB_CPU##cpu##vm
#define __TRAPTAB_CPU(cpu,vm) __TRAPTAB_CPU##cpu##vm
#define __CSA(cpu,vm)         __CSA##cpu##vm
#define __CSA_END(cpu,vm)     __CSA##cpu##vm##_END
#define __START(cpu,vm)       __START##cpu##vm

/*Wrapper macros for the tool specific definitions */
#if defined(IFX_USE_SW_MANAGED_INT)
#define __INTTAB(cpu)      ((unsigned int)__INTTAB_CPU##cpu | (unsigned int)0x1FE0)
#else
#define __INTTAB(cpu,vm)      __INTTAB_CPU##cpu##vm
#endif /*defined(IFX_USE_SW_MANAGED_INT) */

#define __TRAPTAB(cpu,vm)     __TRAPTAB_CPU##cpu##vm

#define __SDATA1(cpu)      _SMALL_DATA_
#define __SDATA2(cpu)      _LITERAL_DATA_
#define __SDATA3(cpu)      _A8_DATA_
#define __SDATA4(cpu)      _A9_DATA_

#endif /*IFX_CFG_USE_COMPILER_DEFAULT_LINKER*/

/******************************************************************************/
#ifdef __cplusplus
#define IFX_INLINE        static inline
#else
#define IFX_INLINE        inline
#endif

/* FXIME check how to pack structure members */
#define IFX_PACKED

#define COMPILER_NAME     "TASKING"
#define COMPILER_VERSION  __VERSION__

/* Note that __REVISION__ is only available for tasking compiler! */
#define COMPILER_REVISION __REVISION__

/******************************************************************************/

#if defined(IFX_USE_SW_MANAGED_INT)

#ifndef IFX_INTERRUPT
#define IFX_INTERRUPT(isr, vectabNum, prio) void isr(void)
#endif

#else
/* *INDENT-OFF* */
#ifndef IFX_INTERRUPT
#define IFX_INTERRUPT(isr, vectabNum, prio) IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio)
#endif

#endif /*defined(IFX_USE_SW_MANAGED_INT)*/

/* The IFX_INTERRUPT_INTERNAL macro is added as a workaround for the
 * Virtualization enable case since the TC1.8 TASKING compiler doesn't support
 *  more than 5 vector table number entries. This macro can be removed in future
 *  if the TASKING compiler supports the same
 */
#if (0)
#define IFX_INTERRUPT_FAST(isr, vectabNum, prio) void __interrupt_fast(prio) __vector_table(vectabNum) isr(void)
#define IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio) void __interrupt(prio) __vector_table(vectabNum) isr(void)
#else
#ifndef IFX_INTERRUPT_INTERNAL
#define IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio) \
__attribute__((section(".intvec_tc"#vectabNum"_"#prio))) void iVecEntry##vectabNum##_##prio(void) \
{ \
	__asm(\
			"svlcx\n"\
			"    mov.aa a13, a11\n"\
            "    movh.a a14, #@his("#isr"_temp)\n" \
            "    lea a14, [a14]@los("#isr"_temp)\n" \
            "    ji a14\n"\
            :::"a14", "a13"); \
} \
void isr##_temp(void)\
{\
__asm("jli %0" ::"a" (&isr));\
__asm("mov.aa a11, a13");\
__asm("rslcx");\
__asm("rfe");\
}\
void isr(void)
#endif /* IFX_INTERRUPT_INTERNAL */
#endif
/* *INDENT-ON* */

/******************************************************************************/

#define IFX_ALIGN(n)       __attribute__ ((__align(n)))

/******************************************************************************/
/*Memory qualifiers*/
#ifndef IFX_FAR_ABS
#define IFX_FAR_ABS __far
#endif

#ifndef IFX_NEAR_ABS
#define IFX_NEAR_ABS __near
#endif

#ifndef IFX_REL_A0
#define IFX_REL_A0 __a0
#endif

#ifndef IFX_REL_A1
#define IFX_REL_A1 __a1
#endif

#ifndef IFX_REL_A8
#define IFX_REL_A8 __a8
#endif

#ifndef IFX_REL_A9
#define IFX_REL_A9 __a9
#endif
/******************************************************************************/

#endif /* COMPILERTASKING_H */
