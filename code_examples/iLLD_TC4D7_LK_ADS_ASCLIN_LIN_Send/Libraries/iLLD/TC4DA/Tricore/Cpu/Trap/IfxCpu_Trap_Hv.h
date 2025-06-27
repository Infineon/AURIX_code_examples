/**
 * \file IfxCpu_Trap.h
 * \brief This file contains the APIs for Trap related functions for hypervisor.
 *
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Cpu_Trap Trap Functions
 * \ingroup IfxLld_Cpu
 *
 * \defgroup IfxLld_Cpu_Trap_Hooks Trap Function Hooks
 * \ingroup IfxLld_Cpu_Trap
 *
 * \defgroup IfxLld_Cpu_Trap_Usage How to use the Trap Function Hooks?
 * \ingroup IfxLld_Cpu_Trap
 *
 */

#ifndef IFXCPU_TRAP_HV_H
#define IFXCPU_TRAP_HV_H 1

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Cpu/Std/Ifx_Types.h"

/*******************************************************************************
**                      Type definitions                                     **
*******************************************************************************/
/** \addtogroup IfxLld_Cpu_Trap_Hooks
 * \{ */

/** \brief Enum for available Trap classes.
 *
 */
typedef enum
{
    IfxCpu_HvTrap_Class_hypervisorCall        = 0U,
    IfxCpu_HvTrap_Class_interruptIntervention = 1U,
    IfxCpu_HvTrap_Class_memoryProtectionL2rw  = 3U,
    IfxCpu_HvTrap_Class_memoryProtectionL2x   = 4U,
    IfxCpu_HvTrap_Class_nmiHypervisor         = 5U,
    IfxCpu_HvTrap_Class_csfrInstructionError  = 6U
} IfxCpu_HvTrap_Class;

/*******************************************************************************
**         Global Exported macros/inlines/function ptototypes                 **
*******************************************************************************/
/*
* Function specifies the return from exception or hypervisor. 
*/
IFX_EXTERN void IfxCpu_Trap_hvReturnExe(void);

#if defined(__HIGHTEC__) && defined(__clang__)
#define IFX_TRAP_HV_HANDLER __attribute__((interrupt_handler))
#define IFX_TRAP_HV_RET
#else
#define IFX_TRAP_HV_HANDLER
/* Restore lower context before returning. lower context was stored in the trap vector */
#define IFX_TRAP_HV_RET \
	    __asm("rslcx"); \
	    IfxCpu_Trap_hvReturnExe();

#endif

#endif /* IFXCPU_TRAPS_H_ */
