/**
 * \file IfxPsi5s.c
 * \brief PSI5S  basic functionality
 *
 * \version iLLD-TC4-v2.6.0
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
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC44X) && !defined(DEVICE_TC45X) && !defined(DEVICE_TC4EX) && !defined(DEVICE_TC4PX)
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
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5s->PROTE, IfxApProt_State_config);
#endif
    psi5s->CLC.B.DISR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5s->PROTE, IfxApProt_State_run);
#endif
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


float32 IfxPsi5s_getBaudrate(Ifx_PSI5S *psi5s, boolean synchMode, boolean divMode, IfxPsi5s_AscBaudratePrescalar baudrateSelection)
{
    float32 baudrate;
    uint32  fInput = 2 * IfxClock_getSpbFrequency();

    if (synchMode)
    {
        baudrate = (float32)fInput / ((baudrateSelection + 2) * 16 * (psi5s->BG.U + 1));
    }
    else if (divMode)
    {
        baudrate = (float32)fInput / ((baudrateSelection + 2) * 16 * (psi5s->BG.U + 1));
    }
    else
    {
        baudrate = (float32)(psi5s->FDV.U / IFXPSI5S_FDV_RANGE) * (fInput / (16 * (psi5s->BG.U + 1)));
    }

    return baudrate;
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
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5s->PROTE, IfxApProt_State_config);
#endif
    psi5s->RST.CTRLA.B.KRST = 1;         /* Only if both Kernel reset bits are set a reset is executed */
    psi5s->RST.CTRLB.B.KRST = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5s->PROTE, IfxApProt_State_run);
#endif

    while (0 == psi5s->RST.STAT.B.KRST)     /* Wait until reset is executed */

    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5s->PROTE, IfxApProt_State_config);
#endif
    psi5s->RST.CTRLB.B.STATCLR = 1;       /* Clear Kernel reset status bit */

    while (psi5s->RST.STAT.B.KRST == 1)   /* Wait until KRST is cleared, only after this reset sequence is completed */
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5s->PROTE, IfxApProt_State_run);
#endif
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
    src = &MODULE_SRC.PSI5S[0].SR[channel];
    return src;
}


void IfxPsi5s_initApConfig(IfxPsi5s_ApConfig *config)
{
    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);
    IfxApApu_initConfig(&config->apuConfig);
}


void IfxPsi5s_initAp(Ifx_PSI5S *psi5s, IfxPsi5s_ApConfig *config)
{
    /* Initialize the PROTs */
    IfxApProt_init((Ifx_PROT_PROT *)&psi5s->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&psi5s->PROTSE, &config->protseConfig);

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initialize the APU */
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5s->PROTSE, IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&psi5s->ACCEN, &config->apuConfig);
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5s->PROTSE, IfxApProt_State_run);
}


void IfxPsi5s_configureAccessToAllPsi5s(IfxApApu_ApuConfig *apConfig)
{
#if (IFXPSI5S_NUM_MODULES == 1)
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_PSI5S0.ACCEN, apConfig);
#else	
    uint8 index;

    for (index = 0; index < IFXPSI5S_NUM_MODULES; index++)
    {
        /* Loop through all the instance */
        Ifx_PSI5S *psi5s = (Ifx_PSI5S *)(((uint32)&MODULE_PSI5S0) + index * ((uint32)&MODULE_PSI5S1 - (uint32)&MODULE_PSI5S0));
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&psi5s->ACCEN, apConfig);
    }
#endif	
}

#endif /* #if !defined(DEVICE_TC44X) && !defined(DEVICE_TC45X) && !defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
