/**
 * \file IfxConvctrl.c
 * \brief CONVCTRL  basic functionality
 *
 * \version iLLD_1_22_0
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxConvctrl.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxConvctrl_resetModule(Ifx_CONVERTER *convctrl)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    convctrl->KRST1.B.RST = 1;      /* Only if both Kernel reset bits are set a reset is executed */
    convctrl->KRST0.B.RST = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);

    while (convctrl->KRST0.B.RSTSTAT == 0)
    {
        /* Wait until reset is executed */
    }

    passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Clear Kernel reset status bit */
    convctrl->KRSTCLR.B.CLR = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}
