/**
 * \file IfxIom.c
 * \brief IOM  basic functionality
 *
 * \version iLLD_1_0_1_9_0
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxIom.h"
#include "Scu/Std/IfxScuCcu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxIom_getFrequency(Ifx_IOM *iom)
{
    float32 fspb;
    float32 fgtm;

    fspb = IfxScuCcu_getSpbFrequency();
    fgtm = IfxScuCcu_getGtmFrequency();

    return fspb > fgtm ? fspb : fgtm;
}


void IfxIom_resetModule(Ifx_IOM *iom)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    iom->KRST1.B.RST = 1;      /* Only if both Kernel reset bits are set a reset is executed */
    iom->KRST0.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    while (iom->KRST0.B.RSTSTAT == 0)  /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    iom->KRSTCLR.B.CLR = 1;    /* Clear Kernel reset status bit */
    IfxScuWdt_setCpuEndinit(passwd);
}
