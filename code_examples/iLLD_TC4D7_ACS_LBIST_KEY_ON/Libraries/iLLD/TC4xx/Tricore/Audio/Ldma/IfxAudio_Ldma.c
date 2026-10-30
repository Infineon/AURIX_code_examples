/**
 * \file IfxAudio_Ldma.c
 * \brief AUDIO LDMA details
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
#include "IfxAudio_Ldma.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxAudio_Ldma_initLdma(IfxAudio_Audio *audio, IfxAudio_Ldma_Config *config)
{
    Ifx_AUDIO_LDMA *ldmaSFR = (Ifx_AUDIO_LDMA *)&(audio->audioSFR->LDMA);

    ldmaSFR->CTL.U     = 0;   /*Ldma Off*/

    ldmaSFR->SRCADDR.U = IFXAUDIO_LDMA_MIXER_DST_FIFO_ADDR;

    switch (config->destinationFifoSelect)
    {
    case IfxAudio_Ldma_DestFifo_tdm0:
    {
        ldmaSFR->DSTADDR.U = IFXAUDIO_LDMA_TDM0_SBFIFO_ADDR;
        break;
    }
    case IfxAudio_Ldma_DestFifo_tdm1:
    {
        ldmaSFR->DSTADDR.U = IFXAUDIO_LDMA_TDM1_SBFIFO_ADDR;
        break;
    }
#if (IFXAUDIO_NUM_INTERFACES > 2)
    case IfxAudio_Ldma_DestFifo_tdm2:
    {
        ldmaSFR->DSTADDR.U = IFXAUDIO_LDMA_TDM2_SBFIFO_ADDR;
        break;
    }
#endif
    }

    ldmaSFR->CTL.B.DSTFIFOSEL = config->destinationFifoSelect;
    ldmaSFR->INTR_MASK.U      = config->interruptMask;

    ldmaSFR->CTL.U           |= 1; /*Ldma On*/
}


uint32 IfxAudio_Ldma_isDestinationSpaceAvailable(IfxAudio_Audio *audio)
{
    return audio->audioSFR->LDMA.STATUS.B.DSTSPACEAVAIL;
}


boolean IfxAudio_Ldma_isSourceDataAvailable(IfxAudio_Audio *audio)
{
    return audio->audioSFR->LDMA.STATUS.B.SRCDATAAVAIL;
}


uint32 IfxAudio_Ldma_getMaskedInterruptStatus(IfxAudio_Audio *audio)
{
    return audio->audioSFR->LDMA.INTR_MASKED.U;
}

#endif /* #if defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
