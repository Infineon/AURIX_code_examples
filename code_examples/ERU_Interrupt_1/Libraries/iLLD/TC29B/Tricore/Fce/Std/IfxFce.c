/**
 * \file IfxFce.c
 * \brief FCE  basic functionality
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxFce.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

Ifx_FCE_STS IfxFce_getCrc16InterruptStatus(Ifx_FCE *fce)
{
    Ifx_FCE_STS interruptStatus;
    interruptStatus.U = fce->IN2.STS.U;
    return interruptStatus;
}


Ifx_FCE_STS IfxFce_getCrc32InterruptStatus(Ifx_FCE *fce, IfxFce_Crc32Kernel crc32Kernel)
{
    Ifx_FCE_STS interruptStatus;

    if (crc32Kernel == IfxFce_Crc32Kernel_0)
    {
        interruptStatus.U = fce->IN0.STS.U;
    }
    else
    {
        interruptStatus.U = fce->IN1.STS.U;
    }

    return interruptStatus;
}


Ifx_FCE_STS IfxFce_getCrc8InterruptStatus(Ifx_FCE *fce)
{
    Ifx_FCE_STS interruptStatus;
    interruptStatus.U = fce->IN3.STS.U;
    return interruptStatus;
}


uint32 IfxFce_reflectCrc32(uint32 crcStartValue, uint8 crcLength)
{
    uint32 ReversedData = 0x0U;
    uint8  inputDataCounter;

    for (inputDataCounter = 0; inputDataCounter < crcLength; ++inputDataCounter)
    {
        if (crcStartValue & 0x01)
        {
            ReversedData |= (uint32)((uint32)1 << ((crcLength - 1) - inputDataCounter));
        }

        crcStartValue = (uint32)((uint32)crcStartValue >> (uint32)1);
    }

    return ReversedData;
}


void IfxFce_resetModule(Ifx_FCE *fce)
{
    uint16 password = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(password);
    fce->KRST1.B.RST = 1;  /* Only if both Kernel reset bits are set a reset is executed */
    fce->KRST0.B.RST = 1;
    IfxScuWdt_setCpuEndinit(password);

    while (0 == fce->KRST0.B.RSTSTAT)  /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(password);
    fce->KRSTCLR.B.CLR = 1;     /* Clear Kernel reset status bit */
    IfxScuWdt_setCpuEndinit(password);
}
