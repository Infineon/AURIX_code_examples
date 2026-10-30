/**
 * \file CompilerGhs.h
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) licenses this file to you under the
 * Infineon Automotive SW Lab License v2025-01 (IFASLL). You may not use
 * this file except in compliance with IFASLL.
 *
 * The full license text is contained in IFASLL202501.pdf delivered with this SW.
 * Unless required by applicable law or agreed to in writing, software distributed
 * under this license is distributed "AS IS" without any warranty or liability of any
 * kind and Infineon hereby expressly disclaims any warranties or representations,
 * whether express, implied, statutory or otherwise, including but not limited to
 * warranties of workmanship, merchantability, fitness for a particular purpose,
 * defects in the licensed items, or non-infringement of third parties'
 * intellectual property rights. See the full license text for the specific
 * language governing permissions and limitations under IFASLL.
 *
 */

#ifndef COMPILERGHS_H
#define COMPILERGHS_H 1

/******************************************************************************/

// #include <stddef.h>

/*Linker definitions which are specific to Ghs */
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

/* MHWS+
#define __SDATA1(cpu)      __A0_MEM
#define __SDATA2(cpu)      __A1_MEM
#define __SDATA3(cpu)      __A8_MEM
#define __SDATA4(cpu)      __A9_MEM
MHWS- */
#endif /*IFX_CFG_USE_COMPILER_DEFAULT_LINKER*/

/******************************************************************************/
#ifndef IFX_INLINE
#define IFX_INLINE         static inline __attribute__ ((always_inline))            /*Makes the function always inlined */
#endif

#define IFX_PACKED         __packed

#define COMPILER_NAME      "GHS"
#define COMPILER_VERSION   __GHS_VERSION_NUMBER

#define COMPILER_REVISION  __GHS_REVISION_VALUE

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

#define IFX_INTERRUPT_INTERNAL(isr, vectabNum, prio) \
__attribute__((section(".intvec_tc"#vectabNum"_"#prio))) IFX_USED void iVecEntry##vectabNum##_##prio(void) \
{ \
	__asm__("movh.a  a14, %hi("#isr") \n" \
			"lea     a14, [a14]%lo("#isr")\n" \
			"ji      a14"); \
} \
__interrupt void isr(void)

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

#endif /* COMPILERGHS_H */
