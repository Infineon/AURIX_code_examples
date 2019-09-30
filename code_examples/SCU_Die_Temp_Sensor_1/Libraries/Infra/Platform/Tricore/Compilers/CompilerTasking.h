/**
 * \file CompilerTasking.h
 *
 * \version iLLD_New
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
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

#define __USTACK(cpu)      __USTACK##cpu
#define __ISTACK(cpu)      __ISTACK##cpu
#define __INTTAB_CPU(cpu)  __INTTAB_CPU##cpu
#define __TRAPTAB_CPU(cpu) __TRAPTAB_CPU##cpu
#define __CSA(cpu)         __CSA##cpu
#define __CSA_END(cpu)     __CSA##cpu##_END

/*Wrapper macros for the tool specific definitions */
#if defined(IFX_USE_SW_MANAGED_INT)
#define __INTTAB(cpu)      ((unsigned int)__INTTAB_CPU##cpu | (unsigned int)0x1FE0)
#else
#define __INTTAB(cpu)      __INTTAB_CPU##cpu
#endif /*defined(IFX_USE_SW_MANAGED_INT) */

#define __TRAPTAB(cpu)     __TRAPTAB_CPU##cpu

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
#define IFX_INTERRUPT_FAST(isr, vectabNum, prio) void __interrupt_fast(prio) __vector_table(vectabNum) isr(void)

#endif /*defined(IFX_USE_SW_MANAGED_INT)*/

#define IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio) void __interrupt(prio) __vector_table(vectabNum) isr(void)

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
