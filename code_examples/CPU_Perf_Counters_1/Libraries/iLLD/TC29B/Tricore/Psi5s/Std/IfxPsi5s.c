/**
 * \file IfxPsi5s.c
 * \brief PSI5S  basic functionality
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

#include "IfxPsi5s.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPsi5s_disableAscReceiver(Ifx_PSI5S *psi5s)
{
    psi5s->WHBCON.B.CLRREN = 1;
}


void IfxPsi5s_disableModule(Ifx_PSI5S *psi5s)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    psi5s->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPsi5s_enableAscReceiver(Ifx_PSI5S *psi5s)
{
    psi5s->WHBCON.B.SETREN = 1;
}


void IfxPsi5s_enableDisableChannelTriggerCounters(Ifx_PSI5S *psi5s, uint32 channels, uint32 mask)
{
    uint32 enableChannels = ((((psi5s->GCR.U >> IFX_PSI5S_GCR_ETC0_OFF) & ~mask) | channels) << IFX_PSI5S_GCR_ETC0_OFF);

    psi5s->GCR.U = (psi5s->GCR.U & ~(IFXPSI5S_GCR_CHANNEL_TRIGGER_COUNTERS_ENABLE_MASK)) | enableChannels;
}


void IfxPsi5s_enableDisableChannels(Ifx_PSI5S *psi5s, uint32 channels, uint32 mask)
{
    uint32 enableChannels = ((((psi5s->GCR.U >> IFX_PSI5S_GCR_CEN0_OFF) & ~mask) | channels) << IFX_PSI5S_GCR_CEN0_OFF);

    psi5s->GCR.U = (psi5s->GCR.U & ~(IFXPSI5S_GCR_CHANNELS_ENABLE_MASK)) | enableChannels;
}


boolean IfxPsi5s_getReadFrameStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channelId)
{
    return psi5s->INTSTAT[channelId].B.RDI;
}


boolean IfxPsi5s_getSuccessfullyReceivedFrameStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channelId)
{
    return psi5s->INTSTAT[channelId].B.RSI;
}


void IfxPsi5s_resetModule(Ifx_PSI5S *psi5s)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    psi5s->KRST0.B.RST = 1;         /* Only if both Kernel reset bits are set a reset is executed */
    psi5s->KRST1.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    while (0 == psi5s->KRST0.B.RSTSTAT)     /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    psi5s->KRSTCLR.B.CLR = 1;           /* Clear Kernel reset status bit */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPsi5s_startAscTransactions(Ifx_PSI5S *psi5s)
{
    psi5s->CON.B.R = 1;
}


void IfxPsi5s_stopAscTransactions(Ifx_PSI5S *psi5s)
{
    psi5s->CON.B.R = 0;
}
