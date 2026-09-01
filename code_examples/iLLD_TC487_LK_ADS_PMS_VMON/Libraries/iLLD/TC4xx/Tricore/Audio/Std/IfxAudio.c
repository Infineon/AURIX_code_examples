/**
 * \file IfxAudio.c
 * \brief AUDIO basic functionality
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
#pragma warning 508			/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96	/* To suppress empty file warning */
#endif

#if defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX)
#include "IfxAudio.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxAudio_initApConfig(IfxAudio_ApConfig *config)
{
    /* Initialize PROT configurations */
    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);

    /* Initialize APU configurations */
    IfxApApu_initConfig(&config->apuGblConfig);
    IfxApApu_initConfig(&config->apuTdm0Config);
    IfxApApu_initConfig(&config->apuTdm1Config);
    IfxApApu_initConfig(&config->apuTdm2Config);
    IfxApApu_initConfig(&config->apuMxrConfig);
}


void IfxAudio_initAp(Ifx_AUDIO *audio, IfxAudio_ApConfig *config)
{
    /* Initialize the PROTs */
    IfxApProt_init((Ifx_PROT_PROT *)&audio->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&audio->PROTSE, &config->protseConfig);

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN
     * All the APUs are protected by PROTSE
     */
    IfxApProt_setState((Ifx_PROT_PROT *)&audio->PROTSE, IfxApProt_State_config);

    /* Initialize the APUs */
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&audio->ACCENGBL, &config->apuGblConfig);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&audio->ACCENTDM[0], &config->apuTdm0Config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&audio->ACCENTDM[1], &config->apuTdm1Config);
#if IFXAUDIO_NUM_INTERFACES > 2
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&audio->ACCENTDM[2], &config->apuTdm2Config);
#endif /* #if IFXAUDIO_NUM_INTERFACES */

    IfxApProt_setState((Ifx_PROT_PROT *)&audio->PROTSE, IfxApProt_State_run);
}


void IfxAudio_disableModule(Ifx_AUDIO *audio)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(audio->PROTE), IfxApProt_State_config);
#endif

    /* Disable module */
    audio->CLC.B.DISR = 1U;

    /* Wait until module is disabled */
    while (IfxAudio_isModuleEnabled(audio) == TRUE)
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(audio->PROTE), IfxApProt_State_run);
#endif
}


void IfxAudio_enableModule(Ifx_AUDIO *audio)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(audio->PROTE), IfxApProt_State_config);
#endif

    /* Enable module, disregard Sleep Mode request */
    audio->CLC.B.DISR = 0U;

    /* Wait until module is enabled */
    while (IfxAudio_isModuleEnabled(audio) == FALSE)
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(audio->PROTE), IfxApProt_State_run);
#endif
}


void IfxAudio_resetModule(Ifx_AUDIO *audio)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(audio->PROTE), IfxApProt_State_config);
#endif
    /* Only if both Kernel reset bits are set, a reset is executed */
    audio->RST.CTRLA.B.KRST = 1U;
    audio->RST.CTRLB.B.KRST = 1U;

    /* Wait until reset is executed */
    while (audio->RST.STAT.B.KRST == 0U)
    {}

    /* Clear Kernel reset status bit */
    audio->RST.CTRLB.B.STATCLR = 1U;

    while (audio->RST.STAT.B.KRST == 1U)   /* Wait until KRST is cleared, only after this reset sequence is completed */
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(audio->PROTE), IfxApProt_State_run);
#endif
}


void IfxAudio_configureAccessToAudioBlocks(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_AUDIO0.ACCENGBL, apConfig);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_AUDIO0.ACCENMXR, apConfig);

    uint8 idx = 0u;

    for (idx = 0u; idx < IFXAUDIO_NUM_INTERFACES; idx++)
    {
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_AUDIO0.ACCENTDM[idx], apConfig);
    }
}


void IfxAudio_configureAccessToGlobalBlock(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_AUDIO0.ACCENGBL, apConfig);
}


void IfxAudio_configureAccessToMixerBlock(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_AUDIO0.ACCENMXR, apConfig);
}


void IfxAudio_configureAccessToTdmBlock(IfxApApu_ApuConfig *apConfig, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_AUDIO0.ACCENTDM[tdmIndex], apConfig);
}

#endif /* #if defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
