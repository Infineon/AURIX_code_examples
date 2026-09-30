/**
 * \file IfxCpu_Irq.c
 * \brief CPU  basic functionality
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxCpu_Irq.h"
#include "Compilers.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxCpu_reg.h"
#include "_Impl/IfxCpu_cfg.h"
#include "_Impl/IfxDma_cfg.h"

/*******************************************************************************
**                      Private macros                                        **
*******************************************************************************/

/*******************************************************************************
**                       Global variables/constants                           **
*******************************************************************************/
#if defined(IFX_USE_SW_MANAGED_INT)

typedef void (*Ifx_Isr)(void);

BEGIN_DATA_SECTION(.bss_cpu0)
static Ifx_Isr IfxCpu_Irq_swIntVector0[256];
END_DATA_SECTION
#if IFXCPU_NUM_SAFE_MODULES >= 2
BEGIN_DATA_SECTION(.bss_cpu1)
static Ifx_Isr IfxCpu_Irq_swIntVector1[256];
END_DATA_SECTION
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 3
BEGIN_DATA_SECTION(.bss_cpu2)
static Ifx_Isr IfxCpu_Irq_swIntVector2[256];
END_DATA_SECTION
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 4
BEGIN_DATA_SECTION(.bss_cpu3)
static Ifx_Isr IfxCpu_Irq_swIntVector3[256];
END_DATA_SECTION
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 5
BEGIN_DATA_SECTION(.bss_cpu4)
static Ifx_Isr IfxCpu_Irq_swIntVector4[256];
END_DATA_SECTION
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 6
BEGIN_DATA_SECTION(.bss_cpu5)
static Ifx_Isr IfxCpu_Irq_swIntVector5[256];
END_DATA_SECTION
#endif

#ifndef IFX_CFG_CPU_IRQ_DEBUG
#define IFX_CFG_CPU_IRQ_DEBUG __debug()
#endif

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
    switch (IfxCpu_Irq_getTos(IfxCpu_getCoreIndex()))
    {
    case IfxSrc_Tos_cpu0:
        IfxCpu_Irq_swIntVector0[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
#if IFXCPU_NUM_SAFE_MODULES >= 2
    case IfxSrc_Tos_cpu1:
        IfxCpu_Irq_swIntVector1[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 3
    case IfxSrc_Tos_cpu2:
        IfxCpu_Irq_swIntVector2[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 4
    case IfxSrc_Tos_cpu3:
        IfxCpu_Irq_swIntVector3[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 5
    case IfxSrc_Tos_cpu4:
        IfxCpu_Irq_swIntVector4[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 6
    case IfxSrc_Tos_cpu5:
        IfxCpu_Irq_swIntVector5[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
#endif
    case IfxSrc_Tos_dma0:
        break;
#if IFXDMA_NUM_MODULES == 2
    case IfxSrc_Tos_dma1:
        break;
#endif
    default:
        break;
    }
}


/** SW managed Interrupt vector tables
 *
 * These are vector tables with single entry for Software Managed Interrupts defined for each core.
 * This function need to be located at boundary 0xXFE0 where (X=1,3,5 and so on). For the software managed
 * interrupts to work correctly, the BIV must be set to address of this function.
 *
 */
IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable0, 0, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if (IfxCpu_Irq_swIntVector0[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector0[icr.B.CCPN]();
    }
    else
    {
        IFX_CFG_CPU_IRQ_DEBUG;
    }
}

#if IFXCPU_NUM_SAFE_MODULES >= 2
IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable1, 1, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if (IfxCpu_Irq_swIntVector1[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector1[icr.B.CCPN]();
    }
    else
    {
        IFX_CFG_CPU_IRQ_DEBUG;
    }
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 3
IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable2, 2, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if (IfxCpu_Irq_swIntVector2[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector2[icr.B.CCPN]();
    }
    else
    {
        IFX_CFG_CPU_IRQ_DEBUG;
    }
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 4
IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable3, 3, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if (IfxCpu_Irq_swIntVector3[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector3[icr.B.CCPN]();
    }
    else
    {
        IFX_CFG_CPU_IRQ_DEBUG;
    }
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 5
IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable4, 4, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if (IfxCpu_Irq_swIntVector4[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector4[icr.B.CCPN]();
    }
    else
    {
        IFX_CFG_CPU_IRQ_DEBUG;
    }
}
#endif

#if IFXCPU_NUM_SAFE_MODULES >= 6
IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable5, 5, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if (IfxCpu_Irq_swIntVector5[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector5[icr.B.CCPN]();
    }
    else
    {
        IFX_CFG_CPU_IRQ_DEBUG;
    }
}
#endif

#endif /*defined(IFX_USE_SW_MANAGED_INT) */

/** \brief API to get type of service of the caller CPU.
 *
 */
IfxSrc_Tos IfxCpu_Irq_getTos(IfxCpu_ResourceCpu coreId)
{
    const IfxSrc_Tos tos[IFXCPU_NUM_SAFE_MODULES] = {
        IfxSrc_Tos_cpu0,
#if IFXCPU_NUM_SAFE_MODULES >= 2
        IfxSrc_Tos_cpu1,
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 3
        IfxSrc_Tos_cpu2,
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 4
        IfxSrc_Tos_cpu3,
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 5
        IfxSrc_Tos_cpu4,
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 6
        IfxSrc_Tos_cpu5,
#endif
    };

    if(coreId == 6)
    {
    	return IfxSrc_Tos_csrm;
    }
    else
    {
    	return tos[coreId];
    }
}
