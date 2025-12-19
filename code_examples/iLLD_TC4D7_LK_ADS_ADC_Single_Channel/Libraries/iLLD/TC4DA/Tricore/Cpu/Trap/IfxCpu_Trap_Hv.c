/**
 * \file IfxCpu_Trap_Hv.c
 * \brief This file contains the APIs for Trap related functions for Hypervisor.
 *
 *
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
#include "IfxCpu_Trap.h"
#include "IfxCpu_Trap_Hv.h"
#include "Cpu/Std/IfxCpu.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Ifx_Ssw_Infra.h"
#include "IfxCpu_reg.h"
#include "Ifx_Cfg.h"
#ifdef IFX_CFG_EXTEND_HV_TRAP_HOOKS
#include "Ifx_Cfg_Trap_Hv.h"
#endif

/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/
/** \brief Configuration for CpuX enable.
 *
 */
#ifndef IFX_CFG_CPU_TRAP_HVCALL_CPU0_HOOK
#   define IFX_CFG_CPU_TRAP_HVCALL_CPU0_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_HVCALL_CPU1_HOOK
#   define IFX_CFG_CPU_TRAP_HVCALL_CPU1_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_HVCALL_CPU2_HOOK
#   define IFX_CFG_CPU_TRAP_HVCALL_CPU2_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_ISRINT_CPU2_HOOK
#   define IFX_CFG_CPU_TRAP_ISRINT_CPU2_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_ISRINT_CPU1_HOOK
#   define IFX_CFG_CPU_TRAP_ISRINT_CPU1_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_HVCALL_CPU3_HOOK
#   define IFX_CFG_CPU_TRAP_HVCALL_CPU3_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_ISRINT_CPU3_HOOK
#   define IFX_CFG_CPU_TRAP_ISRINT_CPU3_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_HVCALL_CPU4_HOOK
#   define IFX_CFG_CPU_TRAP_HVCALL_CPU4_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_ISRINT_CPU4_HOOK
#   define IFX_CFG_CPU_TRAP_ISRINT_CPU4_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_HVCALL_CPU5_HOOK
#   define IFX_CFG_CPU_TRAP_HVCALL_CPU5_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_ISRINT_CPU5_HOOK
#   define IFX_CFG_CPU_TRAP_ISRINT_CPU5_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_ISRINT_CPU0_HOOK
#   define IFX_CFG_CPU_TRAP_ISRINT_CPU0_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_HVL2MPU_CPU0_HOOK
#   define IFX_CFG_CPU_TRAP_HVL2MPU_CPU0_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_HVCSFR_CPU0_HOOK
#   define IFX_CFG_CPU_TRAP_HVCSFR_CPU0_HOOK() /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_TSR_HOOK
#   define IFX_CFG_CPU_TRAP_VM_TSR_HOOK(trapWatch)                            /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU0_HOOK
#   define IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU0_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU1_HOOK
#   define IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU1_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU2_HOOK
#   define IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU2_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU3_HOOK
#   define IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU3_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU4_HOOK
#   define IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU4_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU5_HOOK
#   define IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU5_HOOK(trapWatch) ((void)trapWatch) /**< By default macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_NMI_HOOK
#   define IFX_CFG_CPU_TRAP_VM_NMI_HOOK(trapWatch)          ((void)trapWatch) /**< By default NMI macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_MME_HOOK
#   define IFX_CFG_CPU_TRAP_VM_MME_HOOK(trapWatch)          ((void)trapWatch) /**< By default memory Management Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_IPE_HOOK
#   define IFX_CFG_CPU_TRAP_VM_IPE_HOOK(trapWatch)          ((void)trapWatch) /**< By default internal Protection Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_IE_HOOK
#   define IFX_CFG_CPU_TRAP_VM_IE_HOOK(trapWatch)           ((void)trapWatch) /**< By default instruction Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_CME_HOOK
#   define IFX_CFG_CPU_TRAP_VM_CME_HOOK(trapWatch)          ((void)trapWatch) /**< By default context Management Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_BE_HOOK
#   define IFX_CFG_CPU_TRAP_VM_BE_HOOK(trapWatch)           ((void)trapWatch) /**< By default bus Error macro is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_VM_ASSERT_HOOK
#   define IFX_CFG_CPU_TRAP_VM_ASSERT_HOOK(trapWatch)       ((void)trapWatch) /**< By default assertion is empty*/
#endif
#ifndef IFX_CFG_CPU_TRAP_DEBUG
 #define IFX_CFG_CPU_TRAP_DEBUG __debug()
#endif
/*******************************************************************************
**                      variables                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function definitions                          **
*******************************************************************************/

void IfxCpu_Trap_hvReturnExe(void)
{
    uint32 exeType;
#if defined(__TASKING__)
    __asm("mov %0, d15" : "=d" (exeType));
#elif defined(__DCC__)
    exeType = Ifx__returnd15();
#else
    __asm__ volatile("mov %0, %%d15" : "=d" (exeType));
#endif
    if((exeType & 0x80000000))
    {
        __asm("rfh");
    }
    else
    {
        __asm("rfe");
    }
}

IFX_INLINE IfxCpu_Trap IfxCpu_Trap_vmExtractTrapInfo(uint8 trapClass, uint32 tin)
{
    IfxCpu_Trap trapInfo;
    trapInfo.tAddr  = (unsigned int)__getA11();
    trapInfo.tClass = trapClass;
    trapInfo.tId    = tin;
    trapInfo.tCpu   = IfxCpu_getCoreId();
    return trapInfo;
}

IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_hvCall_Cpu0(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU0_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}

#if IFXCPU_NUM_SAFE_MODULES >= 2
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_hvCall_Cpu1(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU1_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 3
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_hvCall_Cpu2(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU2_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 4
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_hvCall_Cpu3(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU3_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 5
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_hvCall_Cpu4(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU4_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 6
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_hvCall_Cpu5(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU5_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu0(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU0_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}

#if IFXCPU_NUM_SAFE_MODULES >= 2
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu1(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU1_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 3
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu2(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU2_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 4
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu3(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU3_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 5
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu4(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU4_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 6
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu5(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU5_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}
#endif

IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_hvL2Mpu_Cpu0(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVL2MPU_CPU0_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}

IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_hvCsfr_Cpu0(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCSFR_CPU0_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}

/* TRAP HANDLER for VM's */

IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmMemoryManagementError(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_memoryManagement, tin);
    IFX_CFG_CPU_TRAP_VM_MME_HOOK(trapWatch);
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}


IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmInternalProtectionError(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_internalProtection, tin);
    IFX_CFG_CPU_TRAP_VM_IPE_HOOK(trapWatch);
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}


IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmInstructionError(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_instructionErrors, tin);
    IFX_CFG_CPU_TRAP_VM_IE_HOOK(trapWatch);
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}


IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmContextManagementError(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_contextManagement, tin);
    IFX_CFG_CPU_TRAP_VM_CME_HOOK(trapWatch);
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}


IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmBusError(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_bus, tin);
    IFX_CFG_CPU_TRAP_VM_BE_HOOK(trapWatch);
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}


IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmAssertion(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_assertion, tin);
    IFX_CFG_CPU_TRAP_VM_ASSERT_HOOK(trapWatch);
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_HV_RET;
}


IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmSystemCall_Cpu0(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_systemCall, tin);
    IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU0_HOOK(trapWatch);
    IFX_TRAP_HV_RET;
}

#if IFXCPU_NUM_SAFE_MODULES >= 2
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmSystemCall_Cpu1(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_systemCall, tin);
    IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU1_HOOK(trapWatch);
    IFX_TRAP_HV_RET;
}


#endif

#if IFXCPU_NUM_SAFE_MODULES >= 3
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmSystemCall_Cpu2(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_systemCall, tin);
    IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU2_HOOK(trapWatch);
    IFX_TRAP_HV_RET;
}


#endif

#if IFXCPU_NUM_SAFE_MODULES >= 4
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmSystemCall_Cpu3(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_systemCall, tin);
    IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU3_HOOK(trapWatch);
    IFX_TRAP_HV_RET;
}


#endif

#if IFXCPU_NUM_SAFE_MODULES >= 5
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmSystemCall_Cpu4(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_systemCall, tin);
    IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU4_HOOK(trapWatch);
    IFX_TRAP_HV_RET;
}


#endif

#if IFXCPU_NUM_SAFE_MODULES >= 6
IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmSystemCall_Cpu5(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_systemCall, tin);
    IFX_CFG_CPU_TRAP_VM_SYSCALL_CPU5_HOOK(trapWatch);
    IFX_TRAP_HV_RET;
}


#endif

IFX_TRAP_HV_HANDLER
void IfxCpu_Trap_vmNonMaskableInterrupt(uint32 tin)
{
    volatile IfxCpu_Trap trapWatch;
    trapWatch = IfxCpu_Trap_vmExtractTrapInfo(IfxCpu_Trap_Class_nonMaskableInterrupt, tin);
    IFX_CFG_CPU_TRAP_VM_NMI_HOOK(trapWatch);
    IFX_TRAP_HV_RET;
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptabhv_cpu0"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptabhv_cpu0" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu0"
IFX_USED void IfxCpu_HvTrap_vectorTable0(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu0" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptabhv_cpu0" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptabhv_cpu0"
#endif

IFX_USED void IfxCpu_HvTrap_vectorTable0(void)
{
	/*HVCALL trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCall_Cpu0);
	/* Trap for High Prio ISR on non-active VM */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_isrIntervention_Cpu0);
	/*MPU protection related */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
    /*Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	/*CSFR trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCsfr_Cpu0);
	/* Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
}

#if IFXCPU_NUM_SAFE_MODULES >= 2
#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptabhv_cpu1"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptabhv_cpu1" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu1"
IFX_USED void IfxCpu_HvTrap_vectorTable1(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu1" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptabhv_cpu1" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptabhv_cpu1"
#endif

IFX_USED void IfxCpu_HvTrap_vectorTable1(void)
{
	/*HVCALL trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCall_Cpu1);
	/* Trap for High Prio ISR on non-active VM */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_isrIntervention_Cpu1);
	/*MPU protection related */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
    /*Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	/*CSFR trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCsfr_Cpu0);
	/* Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
}

#endif

#if IFXCPU_NUM_SAFE_MODULES >= 3
#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptabhv_cpu2"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptabhv_cpu2" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu2"
IFX_USED void IfxCpu_HvTrap_vectorTable2(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu2" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptabhv_cpu2" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptabhv_cpu2"
#endif

IFX_USED void IfxCpu_HvTrap_vectorTable2(void)
{
	/*HVCALL trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCall_Cpu2);
	/* Trap for High Prio ISR on non-active VM */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_isrIntervention_Cpu2);
	/*MPU protection related */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
    /*Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	/*CSFR trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCsfr_Cpu0);
	/* Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
}

#endif

#if IFXCPU_NUM_SAFE_MODULES >= 4
#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptabhv_cpu3"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptabhv_cpu3" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu3"
IFX_USED void IfxCpu_HvTrap_vectorTable3(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu3" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptabhv_cpu3" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptabhv_cpu3"
#endif

IFX_USED void IfxCpu_HvTrap_vectorTable3(void)
{
	/*HVCALL trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCall_Cpu3);
	/* Trap for High Prio ISR on non-active VM */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_isrIntervention_Cpu3);
	/*MPU protection related */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
    /*Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	/*CSFR trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCsfr_Cpu0);
	/* Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
}

#endif

#if IFXCPU_NUM_SAFE_MODULES >= 5
#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptabhv_cpu4"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptabhv_cpu4" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu4"
IFX_USED void IfxCpu_HvTrap_vectorTable4(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu4" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptabhv_cpu4" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptabhv_cpu4"
#endif

IFX_USED void IfxCpu_HvTrap_vectorTable4(void)
{
	/*HVCALL trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCall_Cpu4);
	/* Trap for High Prio ISR on non-active VM */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_isrIntervention_Cpu4);
	/*MPU protection related */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
    /*Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	/*CSFR trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCsfr_Cpu0);
	/* Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
}

#endif

#if IFXCPU_NUM_SAFE_MODULES >= 6
#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptabhv_cpu5"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptabhv_cpu5" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu5"
IFX_USED void IfxCpu_HvTrap_vectorTable5(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu5" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptabhv_cpu5" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptabhv_cpu5"
#endif

IFX_USED void IfxCpu_HvTrap_vectorTable5(void)
{
	/*HVCALL trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCall_Cpu5);
	/* Trap for High Prio ISR on non-active VM */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_isrIntervention_Cpu5);
	/*MPU protection related */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
    /*Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	/*CSFR trap */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvCsfr_Cpu0);
	/* Just a placeholder for the moment */
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
	IfxCpu_Tsr_CallTSR(IfxCpu_Trap_hvL2Mpu_Cpu0);
}

#endif

#if defined(__TASKING__)
#pragma endprotect
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=""
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#elif defined(__DCC__)
#pragma section
#elif defined(__DCC__)
#pragma interrupt IfxInterruptEx
#elif defined(__ghs__)
#pragma ghs section
#endif

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu01"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu01" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu01"
IFX_USED void IfxCpu_Trap_vectorTable01(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu01" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu01" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu01"
#endif
IFX_USED void IfxCpu_Trap_vectorTable01(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu0);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);;
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu02"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu02" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu02"
IFX_USED void IfxCpu_Trap_vectorTable02(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu02" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu02" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu02"
#endif
IFX_USED void IfxCpu_Trap_vectorTable02(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu0);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu03"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu03" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu03"
IFX_USED void IfxCpu_Trap_vectorTable03(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu03" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu03" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu03"
#endif
IFX_USED void IfxCpu_Trap_vectorTable03(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu0);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu04"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu04" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu04"
IFX_USED void IfxCpu_Trap_vectorTable04(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu04" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu04" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu04"
#endif
IFX_USED void IfxCpu_Trap_vectorTable04(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu0);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu05"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu05" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu05"
IFX_USED void IfxCpu_Trap_vectorTable05(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu05" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu05" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu05"
#endif
IFX_USED void IfxCpu_Trap_vectorTable05(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu0);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu06"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu06" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu06"
IFX_USED void IfxCpu_Trap_vectorTable06(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu06" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu06" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu06"
#endif
IFX_USED void IfxCpu_Trap_vectorTable06(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu0);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu07"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu07" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu07"
IFX_USED void IfxCpu_Trap_vectorTable07(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu07" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu07" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu07"
#endif
IFX_USED void IfxCpu_Trap_vectorTable07(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu0);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}



#if IFXCPU_NUM_SAFE_MODULES >= 2

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu11"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu11" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu11"
IFX_USED void IfxCpu_Trap_vectorTable11(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu11" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu11" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu11"
#endif
IFX_USED void IfxCpu_Trap_vectorTable11(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu1);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu12"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu12" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu12"
IFX_USED void IfxCpu_Trap_vectorTable12(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu12" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu12" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu12"
#endif
IFX_USED void IfxCpu_Trap_vectorTable12(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu1);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu13"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu13" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu13"
IFX_USED void IfxCpu_Trap_vectorTable13(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu13" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu13" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu13"
#endif
IFX_USED void IfxCpu_Trap_vectorTable13(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu1);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu14"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu14" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu14"
IFX_USED void IfxCpu_Trap_vectorTable14(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu14" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu14" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu14"
#endif
IFX_USED void IfxCpu_Trap_vectorTable14(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu1);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu15"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu15" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu15"
IFX_USED void IfxCpu_Trap_vectorTable15(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu15" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu15" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu15"
#endif
IFX_USED void IfxCpu_Trap_vectorTable15(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu1);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu16"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu16" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu16"
IFX_USED void IfxCpu_Trap_vectorTable16(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu16" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu16" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu16"
#endif
IFX_USED void IfxCpu_Trap_vectorTable16(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu1);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu17"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu17" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu17"
IFX_USED void IfxCpu_Trap_vectorTable17(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu17" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu17" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu17"
#endif
IFX_USED void IfxCpu_Trap_vectorTable17(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu1);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#endif

#if IFXCPU_NUM_SAFE_MODULES >= 3

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu21"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu21" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu21"
IFX_USED void IfxCpu_Trap_vectorTable21(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu21" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu21" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu21"
#endif
IFX_USED void IfxCpu_Trap_vectorTable21(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu2);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu22"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu22" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu22"
IFX_USED void IfxCpu_Trap_vectorTable22(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu22" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu22" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu22"
#endif
IFX_USED void IfxCpu_Trap_vectorTable22(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu2);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu23"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu23" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu23"
IFX_USED void IfxCpu_Trap_vectorTable23(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu23" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu23" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu23"
#endif
IFX_USED void IfxCpu_Trap_vectorTable23(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu2);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu24"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu24" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu24"
IFX_USED void IfxCpu_Trap_vectorTable24(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu24" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu24" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu24"
#endif
IFX_USED void IfxCpu_Trap_vectorTable24(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu2);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu25"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu25" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu25"
IFX_USED void IfxCpu_Trap_vectorTable25(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu25" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu25" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu25"
#endif
IFX_USED void IfxCpu_Trap_vectorTable25(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu2);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu26"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu26" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu26"
IFX_USED void IfxCpu_Trap_vectorTable26(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu26" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu26" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu26"
#endif
IFX_USED void IfxCpu_Trap_vectorTable26(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu2);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu27"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu27" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu27"
IFX_USED void IfxCpu_Trap_vectorTable27(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu27" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu27" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu27"
#endif
IFX_USED void IfxCpu_Trap_vectorTable27(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu2);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#endif

#if IFXCPU_NUM_SAFE_MODULES >= 4

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu31"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu31" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu31"
IFX_USED void IfxCpu_Trap_vectorTable31(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu31" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu31" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu31"
#endif
IFX_USED void IfxCpu_Trap_vectorTable31(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu3);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu32"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu32" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu32"
IFX_USED void IfxCpu_Trap_vectorTable32(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu32" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu32" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu32"
#endif
IFX_USED void IfxCpu_Trap_vectorTable32(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu3);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu33"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu33" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu33"
IFX_USED void IfxCpu_Trap_vectorTable33(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu33" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu33" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu33"
#endif
IFX_USED void IfxCpu_Trap_vectorTable33(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu3);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu34"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu34" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu34"
IFX_USED void IfxCpu_Trap_vectorTable34(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu34" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu34" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu34"
#endif
IFX_USED void IfxCpu_Trap_vectorTable34(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu3);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu35"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu35" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu35"
IFX_USED void IfxCpu_Trap_vectorTable35(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu35" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu35" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu35"
#endif
IFX_USED void IfxCpu_Trap_vectorTable35(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu3);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu36"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu36" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu36"
IFX_USED void IfxCpu_Trap_vectorTable36(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu36" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu36" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu36"
#endif
IFX_USED void IfxCpu_Trap_vectorTable36(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu3);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu37"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu37" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu37"
IFX_USED void IfxCpu_Trap_vectorTable37(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu37" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu37" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu37"
#endif
IFX_USED void IfxCpu_Trap_vectorTable37(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu3);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#endif

#if IFXCPU_NUM_SAFE_MODULES >= 5

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu41"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu41" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu41"
IFX_USED void IfxCpu_Trap_vectorTable41(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu41" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu41" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu41"
#endif
IFX_USED void IfxCpu_Trap_vectorTable41(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu4);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu42"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu42" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu42"
IFX_USED void IfxCpu_Trap_vectorTable42(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu42" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu42" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu42"
#endif
IFX_USED void IfxCpu_Trap_vectorTable42(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu4);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu43"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu43" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu43"
IFX_USED void IfxCpu_Trap_vectorTable43(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu43" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu43" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu43"
#endif
IFX_USED void IfxCpu_Trap_vectorTable43(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu4);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu44"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu44" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu44"
IFX_USED void IfxCpu_Trap_vectorTable44(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu44" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu44" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu44"
#endif
IFX_USED void IfxCpu_Trap_vectorTable44(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu4);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu45"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu45" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu45"
IFX_USED void IfxCpu_Trap_vectorTable45(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu45" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu45" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu45"
#endif
IFX_USED void IfxCpu_Trap_vectorTable45(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu4);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu46"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu46" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu46"
IFX_USED void IfxCpu_Trap_vectorTable46(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu46" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu46" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu46"
#endif
IFX_USED void IfxCpu_Trap_vectorTable46(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu4);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu47"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu47" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu47"
IFX_USED void IfxCpu_Trap_vectorTable47(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu47" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu47" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu47"
#endif
IFX_USED void IfxCpu_Trap_vectorTable47(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu4);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#endif

#if IFXCPU_NUM_SAFE_MODULES >= 6

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu51"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu51" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu51"
IFX_USED void IfxCpu_Trap_vectorTable51(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu51" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu51" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu51"
#endif
IFX_USED void IfxCpu_Trap_vectorTable51(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu5);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu52"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu52" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu52"
IFX_USED void IfxCpu_Trap_vectorTable52(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu52" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu52" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu52"
#endif
IFX_USED void IfxCpu_Trap_vectorTable52(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu5);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu53"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu53" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu53"
IFX_USED void IfxCpu_Trap_vectorTable53(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu53" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu53" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu53"
#endif
IFX_USED void IfxCpu_Trap_vectorTable53(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu5);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu54"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu54" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu54"
IFX_USED void IfxCpu_Trap_vectorTable54(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu54" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu54" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu54"
#endif
IFX_USED void IfxCpu_Trap_vectorTable54(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu5);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu55"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu55" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu55"
IFX_USED void IfxCpu_Trap_vectorTable55(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu55" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu55" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu55"
#endif
IFX_USED void IfxCpu_Trap_vectorTable55(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu5);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu56"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu56" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu56"
IFX_USED void IfxCpu_Trap_vectorTable56(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu56" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu56" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu56"
#endif
IFX_USED void IfxCpu_Trap_vectorTable56(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu5);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptab_cpu57"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptab_cpu57" ax
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptab_cpu57"
IFX_USED void IfxCpu_Trap_vectorTable57(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptab_cpu57" ax
#pragma GCC optimize ("O2")
#elif defined(__DCC__)
#pragma section
#pragma section CODE ".traptab_cpu57" X
#elif defined(__ghs__)
#pragma ghs section
#pragma ghs section text=".traptab_cpu57"
#endif
IFX_USED void IfxCpu_Trap_vectorTable57(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmMemoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInternalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmInstructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmContextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmBusError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmAssertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmSystemCall_Cpu5);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_vmNonMaskableInterrupt);
}

#endif

#if defined(__TASKING__)
#pragma endprotect
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=""
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#elif defined(__DCC__)
#pragma section
#elif defined(__DCC__)
#pragma interrupt IfxInterruptEx
#elif defined(__ghs__)
#pragma ghs section
#endif
