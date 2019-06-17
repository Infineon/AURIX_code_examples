/**
 * \file IfxCpu_Cstart2.c
 * \brief This file contains the Core startup sequence for Cpu2.
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
 *
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
 *
 */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Cfg.h"
#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER
#include "Scu/Std/IfxScuWdt.h"
#include "Cpu/Std/IfxCpu.h"
#include "Cpu/CStart/IfxCpu_CStart.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"

/******************************************************************************/
/*                           Macros                                            */
/******************************************************************************/
/** \brief Configuration for cache enable.
 *
 */
#ifndef IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_PCACHE
#   define IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_PCACHE (1)  /**< Program Cache enabled by default*/
#endif
#ifndef IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_DCACHE
#   define IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_DCACHE (1)  /**< Data Cache enabled by default*/
#endif
/*******************************************************************************
**                      Imported Function Declarations                        **
*******************************************************************************/
IFXCOMPILER_COMMON_LINKER_SYMBOLS()
IFXCOMPILER_CORE_LINKER_SYMBOLS(2)

IFX_EXTERN void core2_main(void);
#if defined(__TASKING__)
__asm("\t .extern core2_main");
#endif
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#define IFXCSTART2_PSW_DEFAULT     (0x00000980u)
#define IFXCSTART2_PCX_O_S_DEFAULT (0xfff00000u)

/********************************************************************************
* _start() - startup code
********************************************************************************/
#if defined(__HIGHTEC__)
#pragma GCC optimize ("-O2")
#endif

void _Core2_start(void)
{
    uint32 pcxi;
    uint16 wdtPassword = IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[2]);

    IFX_CFG_CPU_CSTART_PRE_C_INIT_HOOK(2);  /*Test Stack, CSA and Cache */

    /* Load user stack pointer */
    __setareg(sp, __USTACK(2));
    __dsync();

    /* Set the PSW to its reset value in case of a warm start,clear PSW.IS */
    __mtcr(CPU_PSW, IFXCSTART2_PSW_DEFAULT);    /* 0x00000980 */

    /* Set the PCXS and PCXO to its reset value in case of a warm start */
    pcxi  = __mfcr(CPU_PCXI);
    pcxi &= IFXCSTART2_PCX_O_S_DEFAULT; /*0xfff00000; */
    __mtcr(CPU_PCXI, pcxi);

    /*enable program cache */
    IfxCpu_setProgramCache(IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_PCACHE);

    /*enable data cache */
    IfxCpu_setDataCache(IFX_CFG_CPU_CSTART_ENABLE_TRICORE2_DCACHE);

    /* Clear the ENDINIT bit in the Password register, inline funtion */
    IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[2], wdtPassword);

    /* Load Base Address of Trap Vector Table. */
    __mtcr(CPU_BTV, (uint32)__TRAPTAB(2));

    /* Load Base Address of Interrupt Vector Table. we will do this later in the program */
    __mtcr(CPU_BIV, (uint32)__INTTAB(2));

    /* Load interupt stack pointer. */
    __mtcr(CPU_ISP, (uint32)__ISTACK(2));

    IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[2], wdtPassword);

    /* initialize SDA base pointers */
    __setareg(a0, __SDATA1(2));
    __setareg(a1, __SDATA2(2));

    /* These to be un commented if A8 and A9 are required to be initialized */
    __setareg(a8, __SDATA3(2));
    __setareg(a9, __SDATA4(2));
    /* Setup the context save area linked list. */

    IfxCpu_initCSA((uint32 *)__CSA(2), (uint32 *)__CSA_END(2));

    /*Call main function of Cpu0 */
    __non_return_call(core2_main);
}

#if defined(__HIGHTEC__)
#pragma GCC reset_options
#endif
#endif /*#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER */
