/**
 * \file Ifx_Ssw_Tc4.c
 * \brief Startup Software for Core4
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
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

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC4ZX)
#include "Ifx_Ssw.h"
#include "Ifx_Ssw_Infra.h"

/******************************************************************************/
/*                          Macros                                            */
/******************************************************************************/

/** \brief Configuration for cache enable.
 *
 */
#ifndef IFX_CFG_SSW_ENABLE_TRICORE4_PCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE4_PCACHE (1U)  /**< Program Cache enabled by default*/
#endif
#ifndef IFX_CFG_SSW_ENABLE_TRICORE4_DCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE4_DCACHE (1U)  /**< Data Cache enabled by default*/
#endif

/*******************************************************************************
**                      Imported Function Declarations                        **
*******************************************************************************/
IFX_SSW_USED IFX_SSW_NOINLINE void Ifx_Ssw_disableVirtualization_Cpu4(void);

IFX_SSW_COMMON_LINKER_SYMBOLS();
IFX_SSW_CORE_LINKER_SYMBOLS(4);

#if defined(__TASKING__)
__asm("\t .extern core4_main");
#endif

/*******************************************************************************
**                      Prototypes & Externals                                **
*******************************************************************************/

IFX_SSW_WEAK void Ifx_Ssw_MultiCore_Sync_Cpu4(void)
{}

/*********************************************************************************
* - startup code
*********************************************************************************/

void __Core4_start(void)
{
    /* By default mapped to empty, skip only if configured */
    IFX_CFG_SSW_SKIP_STARTUP_ROUTINE(4);
    
    #if (IFX_PROT_ENABLED == 1U)
        IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_config);
    #endif
    /* Load Base Address of Trap Vector Table. */
    Ifx_Ssw_MTCR(CPU_BTV, (unsigned int)__TRAPTAB(4));
    #if (IFX_PROT_ENABLED == 1U)
        IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_run);
    #endif

    Ifx_Ssw_MTCR(CPU_FCX, IFX_CFG_SSW_CSA_PTR((unsigned int)__CSA(4)));

    Ifx_Ssw_disableVirtualization_Cpu4();
    
    #if (IFX_PROT_ENABLED == 1U)
        IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_config);
    #endif
    /* Re-Initialize the BTV to the HRA context post disabling virtualization */
    Ifx_Ssw_MTCR(CPU_BTV, (unsigned int)__TRAPTAB(4));
    #if (IFX_PROT_ENABLED == 1U)
        IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_run);
    #endif

    /* Set the PSW to its reset value in case of a warm start,clear PSW.IS */
    Ifx_Ssw_MTCR(CPU_PSW, IFX_CFG_SSW_PSW_DEFAULT);

    {
        Ifx_CPU_PCON0 pcon0;
        pcon0.U       = 0;
        pcon0.B.PCBYP = IFX_CFG_SSW_ENABLE_TRICORE4_PCACHE ? 0 : 1; /*depending on the enable bypass bit is reset/set */
        #if (IFX_PROT_ENABLED == 1U)
            IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_config);
        #endif
        Ifx_Ssw_MTCR(CPU_PCON0, pcon0.U);
        #if (IFX_PROT_ENABLED == 1U)
            IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_run);
        #endif
    }

    {
        Ifx_CPU_DCON0 dcon0;
        dcon0.U       = 0;
        dcon0.B.DCBYP = IFX_CFG_SSW_ENABLE_TRICORE4_DCACHE ? 0 : 1; /*depending on the enable bypass bit is reset/set */
        #if (IFX_PROT_ENABLED == 1U)
            IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_config);
        #endif
        Ifx_Ssw_MTCR(CPU_DCON0, dcon0.U);
        #if (IFX_PROT_ENABLED == 1U)
            IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_run);
        #endif
    }

    #if (IFX_PROT_ENABLED == 1U)
        IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_config);
    #endif

    /* Load Base Address of Interrupt Vector Table. we will do this later in the program */
    Ifx_Ssw_MTCR(CPU_BIV, (unsigned int)__INTTAB(4));

    /* Load interrupt stack pointer. */
    Ifx_Ssw_MTCR(CPU_ISP, (unsigned int)__ISTACK(4));
    #if (IFX_PROT_ENABLED == 1U)
        IfxSswProt_setState((Ifx_PROT_PROT *)&(MODULE_CPU4.PROTSFRE), IfxSswProt_State_run);
    #endif
    Ifx_Ssw_initCSA((unsigned int *)__CSA(4), (unsigned int *)__CSA_END(4));

    /* initialize SDA base pointers */
    Ifx_Ssw_setAddressReg(a0, __SDATA1(4));
    Ifx_Ssw_setAddressReg(a1, __SDATA2(4));
    Ifx_Ssw_setAddressReg(a8, __SDATA3(4));
    Ifx_Ssw_setAddressReg(a9, __SDATA4(4));

    /*Initialize CPU Private Global Variables*/
    volatile unsigned int tempVar = ((unsigned int)&__ENABLE_INDIVIDUAL_C_INIT_CPU4);
    if (tempVar != 0U)
    {
      /* Hook functions to initialize application specific HW extensions */
      hardware_init_hook();

      /* Initialization of C runtime variables and CPP constructors and destructors */
      (void)Ifx_Ssw_doCppInit();
	
      /* Hook functions to initialize application specific SW extensions */
      software_init_hook();	
    }
    /* MultiCore synchronization hooks to execute Safety Library tests */
    Ifx_Ssw_MultiCore_Sync_Cpu4();

    /*Call main function of Cpu4 */
#ifdef IFX_CFG_SSW_RETURN_FROM_MAIN
    {
        extern int core4_main(void);
        int status= core4_main();        /* Call main function of CPU4 */
        volatile unsigned int tempVar = ((unsigned int)&__ENABLE_INDIVIDUAL_C_INIT_CPU4);
        if (tempVar != 0U)
        {
          Ifx_Ssw_doCppExit(status);
        }
        else
        {
          (void)status;	/* Added to avoid "Unused parameter warning" */
        }
    }
#else /* IFX_CFG_SSW_RETURN_FROM_MAIN */
    extern void core4_main(void);
    Ifx_Ssw_jumpToFunction(core4_main);  /* Jump to main function of CPU2 */
#endif /* IFX_CFG_SSW_RETURN_FROM_MAIN */

    /* Go into infinite loop, normally the code shall not reach here */
    Ifx_Ssw_infiniteLoop();
}



#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma GCC optimize ("O0")
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma GCC optimize ("O0")
#endif
void Ifx_Ssw_disableVirtualization_Cpu4(void)
{
    Ifx_Ssw_disableVirtualization()
}
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma GCC reset_options
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma GCC reset_options
#endif

/******************************************************************************
 *                        reset vector address                                *
 *****************************************************************************/

#if defined(__TASKING__)
#pragma protect on
#pragma section code "start_cpu4"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".start_cpu4" x
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".start_cpu4"
void _START4(void);
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".start_cpu4" x
#elif defined(__DCC__)
#pragma section CODE ".start_cpu4" X
#elif defined(__ghs__)
#pragma ghs section text=".start_cpu4"
#endif

IFX_SSW_USED void _START4(void)
{
    Ifx_Ssw_Start(__USTACK4, __Core4_start);
}

/* reset the sections defined above, to normal region */
#if defined(__TASKING__)
#pragma protect restore
#pragma section code restore
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=""
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#elif defined(__DCC__)
#pragma section CODE
#elif defined(__ghs__)
#pragma ghs section text=default
#endif

#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC4ZX)  */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
