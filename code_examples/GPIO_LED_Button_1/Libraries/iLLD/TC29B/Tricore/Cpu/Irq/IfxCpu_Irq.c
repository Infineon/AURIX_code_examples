/**
 * \file IfxCpu_Irq.c
 * \brief This file contains the APIs for Interrupt related functions.
 *
 *
 * \version iLLD_1_0_1_9_0
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
 *
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Cpu/Irq/IfxCpu_Irq.h"
#include "Tricore/Compilers/Compilers.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxCpu_reg.h"

/*******************************************************************************
**                      Private macros                                        **
*******************************************************************************/

/*******************************************************************************
**                       Global variables/constants                           **
*******************************************************************************/
#if defined(IFX_USE_SW_MANAGED_INT)

typedef void (*Ifx_Isr)(void);

static Ifx_Isr IfxCpu_Irq_swIntVector[256];

#endif /*defined(IFX_USE_SW_MANAGED_INT) */

/*******************************************************************************
**                      Global Function definitions                          **
*******************************************************************************/
#if defined(IFX_USE_SW_MANAGED_INT)

/** \brief API to install the interrupt service routine for Software Managed Interrupts.
 *
 */
void IfxCpu_Irq_installInterruptHandler(void *isrFuncPointer, uint32 serviceReqPrioNumber)
{
    IfxCpu_Irq_swIntVector[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
}


/** SW managed Interrupt vector table
 *
 * This is vector table with single entry for Software Managed Interrupts.
 * This function need to be located at boundary 0xXFE0 where (X=1,3,5 and so on). For the software managed
 * interrupts to work correctly, the BIV must be set to address of this function.
 *
 */
IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable, 0, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    IfxCpu_Irq_swIntVector[icr.B.CCPN]();
}

#endif /*defined(IFX_USE_SW_MANAGED_INT) */
