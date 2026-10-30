/**
 * \file IfxPsi5s.c
 * \brief PSI5S  basic functionality
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
#include "IfxPsi5s.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPsi5s_disableAscReceiver(Ifx_PSI5S *psi5s)
{
    /* Clear Receiver Enable Bit in WHBCON Register*/
    psi5s->WHBCON.B.CLRREN = 1;
}


void IfxPsi5s_disableModule(Ifx_PSI5S *psi5s)
{
    /* Fetch the current password of the CPU Watchdog module*/
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Disable the module */
    psi5s->CLC.B.DISR = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPsi5s_enableAscReceiver(Ifx_PSI5S *psi5s)
{
    /* Set Receiver Enable Bit */
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


float32 IfxPsi5s_getBaudrate(Ifx_PSI5S *psi5s, boolean synchMode, boolean divMode, IfxPsi5s_AscBaudratePrescalar baudrateSelection)
{
    float32 baudrate;
    float32 fInput = 2 * IfxScuCcu_getSpbFrequency();

    if (synchMode)
    {
        baudrate = fInput / ((baudrateSelection + 2) * 16 * (psi5s->BG.U + 1));
    }
    else if (divMode)
    {
        baudrate = fInput / ((baudrateSelection + 2) * 16 * (psi5s->BG.U + 1));
    }
    else
    {
        baudrate = (psi5s->FDV.U / IFXPSI5S_FDV_RANGE) * (fInput / (16 * (psi5s->BG.U + 1)));
    }

    return baudrate;
}


boolean IfxPsi5s_getReadFrameStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channelId)
{
    /* Return the status of Receive Data Interrupt Request Flag*/
    return psi5s->INTSTAT[channelId].B.RDI;
}


boolean IfxPsi5s_getSuccessfullyReceivedFrameStatus(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channelId)
{
    /* Return the status of Receive Success Interrupt Request Flag*/
    return psi5s->INTSTAT[channelId].B.RSI;
}


void IfxPsi5s_resetModule(Ifx_PSI5S *psi5s)
{
    /* Fetch the current password of the CPU Watchdog module*/
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);

    /* Only if both Kernel reset bits are set a reset is executed */
    psi5s->KRST0.B.RST = 1;         
    psi5s->KRST1.B.RST = 1;

    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);

    /* Wait until reset is executed */
    while (0 == psi5s->KRST0.B.RSTSTAT)     

    {}

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);

    /* Clear Kernel reset status bit */
    psi5s->KRSTCLR.B.CLR = 1;   
    
    /* Setting the endinit protection back on */        
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


volatile Ifx_SRC_SRCR *IfxPsi5s_getSrcAddress(Ifx_PSI5S *psi5s, IfxPsi5s_ChannelId channel)
{
    IFX_UNUSED_PARAMETER(psi5s);
    volatile Ifx_SRC_SRCR *src;
    src = &MODULE_SRC.PSI5S.PSI5S[0].SR[channel];
    return src;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
