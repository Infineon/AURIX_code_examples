/**
 * \file CompilerGnuc.h
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

#ifndef COMPILERGNUC_H
#define COMPILERGNUC_H 1

/******************************************************************************/

#include <stddef.h>

/*Linker definitions which are specific to Gnuc */
/* IFX_CFG_USE_COMPILER_DEFAULT_LINKER shall be defined in Ifx_Cfg.h
 * to use the default compiler linker varaibles and startup */
#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER

/*Start: Common definitions ********************************************** */
#define IFXCOMPILER_COMMON_LINKER_SYMBOLS()                                   \
    extern unsigned int __A0_MEM[];     /**< center of A0 addressable area */ \
    extern unsigned int __A1_MEM[];     /**< center of A1 addressable area */ \
    extern unsigned int __A8_MEM[];     /**< center of A8 addressable area */ \
    extern unsigned int __A9_MEM[];     /**< center of A9 addressable area */

/*End: Common definitions ************************************************ */

/*Start: Core 0 definitions ********************************************** */

/*C extern defintions */
#define IFXCOMPILER_CORE_LINKER_SYMBOLS(cpu)                                    \
    extern unsigned int __USTACK##cpu[];      /**< user stack end */            \
    extern unsigned int __ISTACK##cpu[];      /**< interrupt stack end */       \
    extern unsigned int __INTTAB_CPU##cpu[];  /**< Interrupt vector table */    \
    extern unsigned int __TRAPTAB_CPU##cpu[]; /**< trap table */                \
    extern unsigned int __CSA##cpu[];         /**< context save area 1 begin */ \
    extern unsigned int __CSA##cpu##_END[];   /**< context save area 1 begin */

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

#define __SDATA1(cpu)      __A0_MEM
#define __SDATA2(cpu)      __A1_MEM
#define __SDATA3(cpu)      __A8_MEM
#define __SDATA4(cpu)      __A9_MEM

#endif /*IFX_CFG_USE_COMPILER_DEFAULT_LINKER*/

/******************************************************************************/
#ifndef IFX_INLINE
#define IFX_INLINE         static inline __attribute__ ((always_inline))            /*Makes the function always inlined */
#endif

#define IFX_PACKED         __attribute__ ((packed))

#define COMPILER_NAME      "GNUC"
#define COMPILER_VERSION   __VERSION__

#define COMPILER_REVISION  0

#define IFX_INTERRUPT_FAST IFX_INTERRUPT

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

#ifndef IFX_INTERRUPT_INTERNAL
#define IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio) \
__asm__ (".ifndef .intr.entry.include                        \n"\
		".altmacro                                           \n"\
		".macro .int_entry.2 intEntryLabel, name # define the section and inttab entry code \n"\
        "	.pushsection .\\intEntryLabel,\"ax\",@progbits   \n"\
        "	__\\intEntryLabel :                              \n"\
        "		svlcx                                        \n"\
        "		movh.a  %a14, hi:\\name                      \n"\
        "		lea     %a14, [%a14]lo:\\name                \n"\
        "		ji      %a14                                 \n"\
        "	.popsection                                      \n"\
		".endm                                               \n"\
		".macro .int_entry.1 prio,vectabNum,u,name           \n"\
			".int_entry.2 intvec_tc\\vectabNum\\u\\prio,(name) # build the unique name \n"\
		".endm                                               \n"\
        "                                                    \n"\
		".macro .intr.entry name,vectabNum,prio              \n"\
			".int_entry.1 %(prio),%(vectabNum),_,name # evaluate the priority and the cpu number \n"\
		".endm                                               \n"\
		".intr.entry.include:                                \n"\
		".endif                                              \n"\
        ".intr.entry "#isr","#vectabNum","#prio               );\
IFX_EXTERN void __attribute__ ((interrupt_handler)) isr(); \
void isr (void)
#endif /* IFX_INTERRUPT_INTERNAL */

/* *INDENT-ON* */

/******************************************************************************/

#define IFX_ALIGN(n) __attribute__ ((aligned(n)))

/******************************************************************************/
/*Memory qualifiers*/
#ifndef IFX_FAR_ABS
#define IFX_FAR_ABS __attribute__((fardata))
#endif

#ifndef IFX_NEAR_ABS
#define IFX_NEAR_ABS
#endif

#ifndef IFX_REL_A0
#define IFX_REL_A0
#endif

#ifndef IFX_REL_A1
#define IFX_REL_A1
#endif

#ifndef IFX_REL_A8
#define IFX_REL_A8
#endif

#ifndef IFX_REL_A9
#define IFX_REL_A9
#endif
/******************************************************************************/

#endif /* COMPILERGNUC_H */
