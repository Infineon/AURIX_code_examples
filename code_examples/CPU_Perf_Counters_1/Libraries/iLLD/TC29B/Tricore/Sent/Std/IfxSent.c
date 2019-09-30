/**
 * \file IfxSent.c
 * \brief SENT  basic functionality
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxSent.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxSent_getChannelUnitTime(Ifx_SENT *sent, IfxSent_ChannelId channelId)
{
    float32 fFracDiv = IfxSent_getModuleClock(sent);
    float32 fPdiv    = fFracDiv / (float32)(sent->CH[channelId].CPDR.B.PDIV + 1);

    uint32  div      = sent->CH[channelId].CFDR.B.DIV;

    if (div > 0)
    {
        float32 fTick = (fPdiv * 56) / div;
        return 1 / fTick;
    }
    else
    {
        return 0.0;
    }
}


float32 IfxSent_getModuleClock(Ifx_SENT *sent)
{
    float32 fsys = IfxScuCcu_getSpbFrequency();

    uint32  rmc  = sent->CLC.B.RMC;

    if (rmc < 1)
    {
        rmc = 1;
    }

    float32      fclc = fsys / rmc;

    Ifx_SENT_FDR fdr;
    fdr.U = sent->FDR.U;

    float32      kernelFreq = 0.0;

    if (fdr.B.DM == 1)
    {
        kernelFreq = fclc / (1024 - fdr.B.STEP);
    }
    else if (fdr.B.DM == 2)
    {
        kernelFreq = (fclc * fdr.B.STEP) / 1024;
    }

    return kernelFreq;
}


void IfxSent_initializeChannelUnitTime(Ifx_SENT *sent, IfxSent_ChannelId channelId, float32 tUnit)
{
    float32      fFracDiv = IfxSent_getModuleClock(sent);

    /* const uint32 divMin   = 560; */
    const uint32 divMax = 3276;

    uint32       pDiv;
    uint32       fDiv;

    float32      tResult;
    tResult = fFracDiv * 56 * tUnit;
    pDiv    = tResult / divMax;
    fDiv    = tResult / pDiv;

    if (fDiv > divMax)
    {
        pDiv = pDiv + 1;
        fDiv = tResult / pDiv;
    }

    if ((pDiv > 1024) || (pDiv < 1))
    {
        pDiv = 1025;
        fDiv = tResult / 1024;
    }

    IfxSent_setChannelPreDivider(sent, channelId, (uint16)pDiv - 1);
    IfxSent_setChannelFractionalDivider(sent, channelId, (uint16)fDiv);
}


void IfxSent_initializeModuleClock(Ifx_SENT *sent, IfxSent_ClockDividerMode dividerMode, uint16 stepValue)
{
    Ifx_SENT_FDR tempFDR;
    tempFDR.U      = 0;
    tempFDR.B.STEP = stepValue;
    tempFDR.B.DM   = dividerMode;
    sent->FDR.U    = tempFDR.U;
}


void IfxSent_resetModule(Ifx_SENT *sent)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    sent->KRST1.B.RST = 1;      /* Only if both Kernel reset bits are set a reset is executed */
    sent->KRST0.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    while (0 == sent->KRST0.B.RSTSTAT)  /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    sent->KRSTCLR.B.CLR = 1;    /* Clear Kernel reset status bit */
    IfxScuWdt_setCpuEndinit(passwd);
}
