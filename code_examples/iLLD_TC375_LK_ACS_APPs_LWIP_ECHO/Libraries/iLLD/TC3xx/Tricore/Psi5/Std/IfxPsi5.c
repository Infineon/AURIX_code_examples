/**
 * \file IfxPsi5.c
 * \brief PSI5  basic functionality
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508				/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif
#if !defined(DEVICE_TC33XED) && !defined(DEVICE_TC33X) && !defined (DEVICE_TC35X)

#include "IfxPsi5.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPsi5_disableModule(Ifx_PSI5 *psi5)
{
    /* Fetch the current password of the CPU Watchdog module*/
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Disable the module*/
    psi5->CLC.B.DISR = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPsi5_enableInterrupt(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptSource interruptSource, IfxPsi5_InterruptRequest enabled)
{
    /* Fetch the current password of the CPU Watchdog module*/
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);

    if (interruptSource < IfxPsi5_InterruptSource_wsi0)
    {
        /* Enable the interrupt for the specified source in the A register */
        psi5->INTENA[channel].U = psi5->INTENA[channel].U | (enabled << interruptSource);
    }
    else
    {
        /* Enable the interrupt for the specified source in the B register */
        psi5->INTENB[channel].U = psi5->INTENB[channel].U | (enabled << (interruptSource - IfxPsi5_InterruptSource_wsi0));
    }

    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPsi5_resetModule(Ifx_PSI5 *psi5)
{
    /* Fetch the current password of the CPU Watchdog module*/
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);

    /* Only if both Kernel reset bits are set a reset is executed */
    psi5->KRST0.B.RST = 1;          
    psi5->KRST1.B.RST = 1;

    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);

    /* Wait until reset is executed */
    while (0 == psi5->KRST0.B.RSTSTAT)  
    {}

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);

    /* Clear Kernel reset status bit */
    psi5->KRSTCLR.B.CLR = 1;      
    
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPsi5_enableModule(Ifx_PSI5 *psi5)
{
    /* Fetch the current password of the CPU Watchdog module*/
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Enable the module */
    psi5->CLC.B.DISR = 0;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);

    if (psi5->CLC.U)
    {}
}


void IfxPsi5_enableChannel(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channelId)
{
    /* Fetch the current password of the CPU Watchdog module*/
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);

    /* Enable the specified channel*/
    psi5->GCR.U |= (IFXPSI5_ENABLE_CHANNEL << channelId);

    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
