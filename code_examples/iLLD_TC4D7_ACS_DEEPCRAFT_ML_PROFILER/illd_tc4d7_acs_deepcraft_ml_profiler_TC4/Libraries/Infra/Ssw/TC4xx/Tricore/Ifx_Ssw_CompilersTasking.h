/**
 * \file Ifx_Ssw_CompilersTasking.h
 * \brief Startup Software for Tasking compiler options
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *                                 IMPORTANT NOTICE
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
#ifndef IFX_SSW_COMPILERSTASKING_H
#define IFX_SSW_COMPILERSTASKING_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/*Linker definitions which are specific to Tasking */
/* IFX_CFG_USE_COMPILER_DEFAULT_LINKER shall be defined in Ifx_Cfg.h
 * to use the default compiler linker varaibles and startup */
#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER

/*Start: Common definitions ********************************************** */
#define IFX_SSW_COMMON_LINKER_SYMBOLS()                                                               \
    __asm("\t .extern _SMALL_DATA_, _LITERAL_DATA_, _A8_DATA_, _A9_DATA_");                           \
    extern unsigned int __START0[];                              /**< Pointer to the startup code */  \
    extern unsigned int __START1[];                              /**< Pointer to the startup code */  \
    extern unsigned int __START2[];                              /**< Pointer to the startup code */  \
    extern unsigned int __START3[];                              /**< Pointer to the startup code */  \
    extern unsigned int __START4[];                              /**< Pointer to the startup code */  \
    extern unsigned int __START5[];                              /**< Pointer to the startup code */  \
	extern unsigned int __ENABLE_INDIVIDUAL_C_INIT_CPU0;        /**< Enable Individual C init CPU0 */ \
	extern unsigned int __ENABLE_INDIVIDUAL_C_INIT_CPU1;        /**< Enable Individual C init CPU1 */ \
	extern unsigned int __ENABLE_INDIVIDUAL_C_INIT_CPU2;        /**< Enable Individual C init CPU2 */ \
	extern unsigned int __ENABLE_INDIVIDUAL_C_INIT_CPU3;        /**< Enable Individual C init CPU3 */ \
	extern unsigned int __ENABLE_INDIVIDUAL_C_INIT_CPU4;        /**< Enable Individual C init CPU4 */ \
	extern unsigned int __ENABLE_INDIVIDUAL_C_INIT_CPU5         /**< Enable Individual C init CPU5 */

/*End: Common definitions ************************************************ */

/*Start: Core 0 definitions ********************************************** */

/*C extern defintions */
#define IFX_SSW_CORE_LINKER_SYMBOLS(cpu)                                                                             \
    __asm("\t .extern __USTACK"#cpu);         /**< user stack end is required as asm to be used with setreg macro */ \
    extern unsigned int __ISTACK##cpu[];      /**< interrupt stack end */                                            \
    extern unsigned int __INTTAB_CPU##cpu[];  /**< interrupt vector table */                                         \
    extern unsigned int __TRAPTAB_CPU##cpu[]; /**< trap vector table */                                              \
    extern unsigned int __CSA##cpu[];         /**< context save area begin */                                        \
    extern unsigned int __CSA##cpu##_END[]   /**< context save area end   */                                         \

#define __USTACK(cpu)      __USTACK##cpu
#define __ISTACK(cpu)      __ISTACK##cpu
#define __INTTAB_CPU(cpu)  __INTTAB_CPU##cpu
#define __TRAPTAB_CPU(cpu) __TRAPTAB_CPU##cpu
#define __CSA(cpu)         __CSA##cpu
#define __CSA_END(cpu)     __CSA##cpu##_END
#define __START(cpu)       __START##cpu

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

#define IFX_SSW_INLINE   static inline

#define IFX_SSW_NULL_PTR ((void *)0x0U)

#define IFX_SSW_WEAK     __attribute__ ((weak))
#define IFX_SSW_NOINLINE __attribute__((noinline))
/******************************************************************************/
/*----------------------------   TASKING Intrinsics  -------------------------*/
/******************************************************************************/

/* Assembly function to configure the Stack pointer and jump to core start */
#define Ifx_Ssw_Start(stackPtr, funcPtr) __Ifx_Ssw_Start(stackPtr, funcPtr)

#define __Ifx_Ssw_Start(stackPtr, funcPtr) \
	    __asm("movh.a a10,#@his("#stackPtr")\n" \
	          "\tlea a10,[a10]@los("#stackPtr") \n " \
	          "\tdsync\n" \
			  "\tmovh.a a15,#@his("#funcPtr")\n" \
			  "\tlea a15,[a15]@los("#funcPtr")\n" \
			  "\tji a15");

#define Ifx_Ssw_Barrier() __asm("":::"memory");

#define Ifx_Ssw_debug() __debug();

#define Ifx_Ssw_MTCR(reg, val) __mtcr(reg, val);

#define Ifx_Ssw_MFCR(reg)      __mfcr(reg);

#if defined(__CORE_TC18__)
#define Ifx_Ssw_HVCALL(hvcno) __hvcall(hvcno)
#define Ifx_Ssw_RFH() __asm("rfh " : : : "memory")
#else
#define Ifx_Ssw_HVCALL(hvcno) \
switch (hvcno) \
{ \
case 1: \
{__asm volatile (".word 0x004010AD");}\
break; \
case 2: \
{__asm volatile (".word 0x004020AD");}\
break; \
case 3: \
{__asm volatile (".word 0x004030AD");}\
break; \
case 4: \
{__asm volatile (".word 0x004040AD");}\
break; \
case 5: \
{__asm volatile (".word 0x004050AD");}\
break; \
case 6: \
{__asm volatile (".word 0x004060AD");}\
break; \
case 7: \
{__asm volatile (".word 0x004070AD");}\
break; \
}
#define Ifx_Ssw_RFH() \
__asm volatile (".word 0x05C0000D");
#endif

IFX_SSW_INLINE void Ifx_Ssw_NOP(void)
{
    __nop();
}


IFX_SSW_INLINE void Ifx_Ssw_DSYNC(void)
{
    __dsync();
}


IFX_SSW_INLINE void Ifx_Ssw_ISYNC(void)
{
    __isync();
}


IFX_SSW_INLINE unsigned int Ifx_Ssw_MINU(unsigned int a, unsigned int b)
{
    return __minu(a, b);
}

IFX_SSW_INLINE unsigned int Ifx_Ssw_getD15(void)
{
    unsigned int var;
    __asm(" mov\t %0, d15" : "=d" (var));
    return var;
}

/* Inline function to set return address*/
IFX_SSW_INLINE void Ifx_Ssw_setA11(void *Addr)
{
    __asm("mov.aa a11, %0": : "a" (Addr) :"a11");
}

#define Ifx_Ssw_CLZ(a)                     __clz(a)

#define Ifx_Ssw___setAddressReg(aReg, val) \
    {__asm(" movh.a\t "#aReg ",#@his("#val ")\n lea\t "#aReg ",["#aReg "]@los("#val ")"); }

#define Ifx_Ssw_setAddressReg(regNum, val) Ifx_Ssw___setAddressReg(regNum, val)

IFX_SSW_INLINE void Ifx_Ssw_moveToDataParam0(unsigned int var)
{
    __asm("mov d2, %0" ::"d" (var));
}


IFX_SSW_INLINE unsigned int Ifx_Ssw_getDataParam0(void)
{
    unsigned int var;
    __asm(" mov\t %0, d2" : "=d" (var));
    return var;
}


IFX_SSW_INLINE void Ifx_Ssw_jumpToFunction(void *fun)
{
    __asm("ji %0" ::"a" (fun));
}


IFX_SSW_INLINE void Ifx_Ssw_jumpToFunctionWithLink(void *fun)
{
    __asm("jli %0" ::"a" (fun));
}


IFX_SSW_INLINE void Ifx_Ssw_jumpBackToLink(void)
{
    __asm("ji a11");
}


IFX_SSW_INLINE void Ifx_Ssw_C_InitInline(void)
{
    extern void _c_init(void);
    _c_init();                  /* initialize data */
}

IFX_SSW_INLINE void Ifx_Ssw_infiniteLoop(void)
{
    __asm("1: loopu\t 1p");
}
#endif /* IFX_SSW_COMPILERSTASKING_H */
