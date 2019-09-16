/**
 * \file IfxEbu.c
 * \brief EBU  basic functionality
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

#include "IfxEbu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxEbu_setExternalClockRatio(Ifx_EBU *ebu, IfxEbu_ExternalClockRatio ratio)
{
    Ifx_EBU_CLC clc;
    clc.U = ebu->CLC.U;

    switch (ratio)
    {
    case IfxEbu_ExternalClockRatio_1:
        clc.B.EBUDIV = 0;
        clc.B.DIV2   = 0;
        break;
    case IfxEbu_ExternalClockRatio_2:
        clc.B.EBUDIV = 1;
        clc.B.DIV2   = 0;
        break;
    case IfxEbu_ExternalClockRatio_3:
        clc.B.EBUDIV = 2;
        clc.B.DIV2   = 0;
        break;
    case IfxEbu_ExternalClockRatio_4:
        clc.B.EBUDIV = 3;
        clc.B.DIV2   = 0;
        break;
    case IfxEbu_ExternalClockRatio_6:
        clc.B.EBUDIV = 2;
        clc.B.DIV2   = 1;
        break;
    case IfxEbu_ExternalClockRatio_8:
        clc.B.EBUDIV = 3;
        clc.B.DIV2   = 1;
        break;
    }

    ebu->CLC.U = clc.U;
}


void IfxEbu_setByteControlEnable(Ifx_EBU *ebu, IfxEbu_ByteControlEnable byteControlEnable)
{
    ebu->USERCON.B.RES = byteControlEnable;
}


void IfxEbu_disableModule(Ifx_EBU *ebu)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(psw); /* clears the endinit protection*/
    ebu->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(psw);   /* sets the endinit protection back on*/
}
