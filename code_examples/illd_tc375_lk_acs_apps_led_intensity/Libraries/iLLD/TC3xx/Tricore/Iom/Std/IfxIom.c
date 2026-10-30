/**
 * \file IfxIom.c
 * \brief IOM  basic functionality
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
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
#ifndef DEVICE_TC33XED
#include "IfxIom.h"
#include "Scu/Std/IfxScuCcu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxIom_getFrequency(Ifx_IOM *iom)
{
    IFX_UNUSED_PARAMETER(iom)
    float32 fspb;

    fspb = IfxScuCcu_getSpbFrequency();

    return (float32)(fspb / IOM_CLC.B.RMC);
}


void IfxIom_resetModule(Ifx_IOM *iom)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Only if both Kernel reset bits are set a reset is executed */
    iom->KRST1.B.RST = 1;
    iom->KRST0.B.RST = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);

    /* Wait until reset is executed */
    while (iom->KRST0.B.RSTSTAT == 0)
    {}

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Clear Kernel reset status bit */
    iom->KRSTCLR.B.CLR = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
