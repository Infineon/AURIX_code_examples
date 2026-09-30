/**
 * \file IfxPsi5.c
 * \brief PSI5  basic functionality
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

#if !defined(DEVICE_TC45X) && !defined(DEVICE_TC4EX) && !defined(DEVICE_TC4PX)
#include "IfxPsi5.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPsi5_disableModule(Ifx_PSI5 *psi5)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_config);
#endif
    psi5->CLC.B.DISR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_run);
#endif
}


void IfxPsi5_enableInterrupt(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channel, IfxPsi5_InterruptSource interruptSource, IfxPsi5_InterruptRequest enabled)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_config);
#endif

    if (interruptSource < IfxPsi5_InterruptSource_wsi0)
    {
        psi5->INTENA[channel].U = psi5->INTENA[channel].U | (enabled << interruptSource);
    }
    else
    {
        psi5->INTENB[channel].U = psi5->INTENB[channel].U | (enabled << (interruptSource - IfxPsi5_InterruptSource_wsi0));
    }

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_run);
#endif
}


void IfxPsi5_resetModule(Ifx_PSI5 *psi5)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_config);
#endif

    psi5->RST.CTRLA.B.KRST = 1;          /* Only if both Kernel reset bits are set a reset is executed */
    psi5->RST.CTRLB.B.KRST = 1;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_run);
#endif

    while (0 == psi5->RST.STAT.B.KRST)  /* Wait until reset is executed */
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_config);
#endif
    psi5->RST.CTRLB.B.STATCLR = 1;       /* Clear Kernel reset status bit */

    while (psi5->RST.STAT.B.KRST == 1)   /* Wait until KRST is cleared, only after this reset sequence is completed */
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_run);
#endif
}


void IfxPsi5_enableModule(Ifx_PSI5 *psi5)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_config);
#endif
    psi5->CLC.B.DISR = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTE, IfxApProt_State_run);
#endif

    if (psi5->CLC.U)
    {}
}


void IfxPsi5_initApConfig(IfxPsi5_ApConfig *config)
{
    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);
    IfxApApu_initConfig(&config->apuConfig);
}


void IfxPsi5_initAp(Ifx_PSI5 *psi5, IfxPsi5_ApConfig *config)
{
    /* Initialize the PROTs */
    IfxApProt_init((Ifx_PROT_PROT *)&psi5->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&psi5->PROTSE, &config->protseConfig);

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initialize the APU */
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTSE, IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&psi5->ACCEN, &config->apuConfig);
    IfxApProt_setState((Ifx_PROT_PROT *)&psi5->PROTSE, IfxApProt_State_run);
}


void IfxPsi5_configureAccessToPsi5(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_PSI5.ACCEN, apConfig);
}


void IfxPsi5_enableChannel(Ifx_PSI5 *psi5, IfxPsi5_ChannelId channelId)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_PSI5.PROTE, IfxApProt_State_config);
#endif

    psi5->GCR.U |= (IFXPSI5_ENABLE_CHANNEL << channelId);

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_PSI5.PROTE, IfxApProt_State_run);
#endif
}
#endif /* #if !defined(DEVICE_TC45X) && !defined(DEVICE_TC4EX)*/

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
