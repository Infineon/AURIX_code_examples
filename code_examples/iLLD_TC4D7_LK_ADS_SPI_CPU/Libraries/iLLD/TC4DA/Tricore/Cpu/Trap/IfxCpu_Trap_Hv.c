/**
 * \file IfxCpu_Trap_Hv.c
 * \brief This file contains the APIs for Trap related functions for Hypervisor.
 *
 *
 * \version iLLD-TC4-v2.1.1
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
#ifdef IFX_CFG_EXTEND_HVTRAP_HOOKS
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
#ifndef IFX_CFG_CPU_TRAP_DEBUG
 #define IFX_CFG_CPU_TRAP_DEBUG __debug()
#endif
/*******************************************************************************
**                      variables                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function definitions                          **
*******************************************************************************/

IFX_TRAP_HANDLER
void IfxCpu_Trap_hvCall_Cpu0(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU0_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}

#if IFXCPU_NUM_SAFE_MODULES >= 2
IFX_TRAP_HANDLER
void IfxCpu_Trap_hvCall_Cpu1(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU1_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 3
IFX_TRAP_HANDLER
void IfxCpu_Trap_hvCall_Cpu2(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU2_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 4
IFX_TRAP_HANDLER
void IfxCpu_Trap_hvCall_Cpu3(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU3_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 5
IFX_TRAP_HANDLER
void IfxCpu_Trap_hvCall_Cpu4(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU4_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 6
IFX_TRAP_HANDLER
void IfxCpu_Trap_hvCall_Cpu5(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCALL_CPU5_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

IFX_TRAP_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu0(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU0_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}

#if IFXCPU_NUM_SAFE_MODULES >= 2
IFX_TRAP_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu1(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU1_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 3
IFX_TRAP_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu2(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU2_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 4
IFX_TRAP_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu3(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU3_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 5
IFX_TRAP_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu4(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU4_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 6
IFX_TRAP_HANDLER
void IfxCpu_Trap_isrIntervention_Cpu5(uint32 tin)
{
    IFX_CFG_CPU_TRAP_ISRINT_CPU5_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}
#endif

IFX_TRAP_HANDLER
void IfxCpu_Trap_hvL2Mpu_Cpu0(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVL2MPU_CPU0_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}

IFX_TRAP_HANDLER
void IfxCpu_Trap_hvCsfr_Cpu0(uint32 tin)
{
    IFX_CFG_CPU_TRAP_HVCSFR_CPU0_HOOK();
    IFX_CFG_CPU_TRAP_DEBUG;
    IFX_TRAP_RET;
}


#if defined(__TASKING__)
#pragma protect on
#pragma section code "traptabhv_cpu0"
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#pragma section ".traptabhv_cpu0" awx
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu0"
IFX_USED void IfxCpu_HvTrap_vectorTable0(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu0" awx
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
#pragma section ".traptabhv_cpu1" awx
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu1"
IFX_USED void IfxCpu_HvTrap_vectorTable1(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu1" awx
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
#pragma section ".traptabhv_cpu2" awx
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu2"
IFX_USED void IfxCpu_HvTrap_vectorTable2(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu2" awx
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
#pragma section ".traptabhv_cpu3" awx
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu3"
IFX_USED void IfxCpu_HvTrap_vectorTable3(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu3" awx
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
#pragma section ".traptabhv_cpu4" awx
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu4"
IFX_USED void IfxCpu_HvTrap_vectorTable4(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu4" awx
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
#pragma section ".traptabhv_cpu5" awx
#pragma GCC optimize ("O2")
#elif defined(__HIGHTEC__) && defined(__clang__)
#pragma clang section text=".traptabhv_cpu5"
IFX_USED void IfxCpu_HvTrap_vectorTable5(void) __attribute__((naked,aligned(256)));
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma section
#pragma section ".traptabhv_cpu5" awx
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
