/**
 * \file IfxAudio_Audio.c
 * \brief AUDIO AUDIO details
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
#include "IfxAudio_Audio.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxAudio_Audio_initModule(IfxAudio_Audio *audio, IfxAudio_Audio_Config *config)
{
    audio->audioSFR = config->audioSFR;

    if (IfxAudio_isModuleEnabled(audio->audioSFR) != TRUE)
    {
        /*Enable Module*/
        IfxAudio_enableModule(audio->audioSFR);
    }
}


void IfxAudio_Audio_initModuleConfig(IfxAudio_Audio_Config *config, Ifx_AUDIO *audioSFR)
{
    const IfxAudio_Audio_Config defaultConfig = {
        .audioSFR = NULL_PTR,
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* take over module pointer */
    config->audioSFR = audioSFR;
}


void IfxAudio_Audio_initInterruptNode(IfxAudio_Audio_InterruptNodeConfig *config, IfxAudio_ServiceRequest index)
{
    Ifx_SRC_SRCR *srcPtr = (Ifx_SRC_SRCR *)(&MODULE_SRC.AUDIO0.TDM[0].TXDMA);
    srcPtr = (Ifx_SRC_SRCR *)&srcPtr[index];

    if (config->priority > 0u)
    {
        IfxSrc_init(srcPtr, config->typeOfService, config->priority, config->vmId);
        IfxSrc_enable(srcPtr);
    }
}

#endif /* #if defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
