/**
 * \file IfxSent_Sent.c
 * \brief SENT SENT details
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
#ifndef DEVICE_TC35X
#include "IfxSent_Sent.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxSent_Sent_deInitModule(IfxSent_Sent *driver)
{
    Ifx_SENT *sentSFR = driver->sent;
    uint16    passwd  = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Reset the SENT module to its default state */
    IfxSent_resetModule(sentSFR);
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


boolean IfxSent_Sent_initChannel(IfxSent_Sent_Channel *channel, const IfxSent_Sent_ChannelConfig *config)
{
    boolean      result = TRUE;

    channel->driver = config->driver;
    Ifx_SENT    *sentSFR = config->driver->sent;
    Ifx_SENT_CH *sentCh  = &sentSFR->CH[config->channelId];
    channel->channel   = sentCh;
    channel->channelId = config->channelId;

    IfxSent_disableChannel(sentSFR, config->channelId);
    IfxSent_initializeChannelUnitTime(sentSFR, config->channelId, config->tUnit);

    Ifx_SENT_CH_WDT tempWDT;
    tempWDT.U     = 0;
    tempWDT.B.WDL = config->watchDogTimerLimit;
    sentCh->WDT.U = tempWDT.U;

    /* Initialize the receive control settings for the channel */
    Ifx_SENT_CH_RCR tempRCR;
    tempRCR.U       = 0;
    tempRCR.B.IEP   = config->receiveControl.endPulseIgnored;
    tempRCR.B.ACE   = config->receiveControl.alternateCrcSelected;
    tempRCR.B.SNI   = config->receiveControl.statusNibbleEnabled;
    tempRCR.B.SDP   = config->receiveControl.serialDataProcessingEnabled;
    tempRCR.B.SCDIS = config->receiveControl.serialDataDisabledCrcDisabled;
    tempRCR.B.CDIS  = config->receiveControl.crcModeDisabled;
    tempRCR.B.CFC   = config->receiveControl.frameCheckMode;
    tempRCR.B.FRL   = config->receiveControl.frameLength;
    tempRCR.B.CRZ   = config->receiveControl.crcMethodDisabled;
    tempRCR.B.ESF   = config->receiveControl.extendedSerialFrameMode;
    tempRCR.B.IDE   = config->receiveControl.driftErrorsDisabled;
    tempRCR.B.SUSEN = config->receiveControl.suspendTriggered;
    tempRCR.B.FDFL  = config->receiveControl.frequencyDriftCheckEnabled;
    sentCh->RCR.U   = tempRCR.U;

    /* Enable the specified SENT channel after configuration */
    IfxSent_enableChannel(sentSFR, config->channelId);

    /* Initialize the nibble control settings for the channel */
    Ifx_SENT_CH_VIEW tempVIEW;
    tempVIEW.U       = 0;
    tempVIEW.B.RDNP0 = config->nibbleControl.nibblePointer0;
    tempVIEW.B.RDNP1 = config->nibbleControl.nibblePointer1;
    tempVIEW.B.RDNP2 = config->nibbleControl.nibblePointer2;
    tempVIEW.B.RDNP3 = config->nibbleControl.nibblePointer3;
    tempVIEW.B.RDNP4 = config->nibbleControl.nibblePointer4;
    tempVIEW.B.RDNP5 = config->nibbleControl.nibblePointer5;
    tempVIEW.B.RDNP6 = config->nibbleControl.nibblePointer6;
    tempVIEW.B.RDNP7 = config->nibbleControl.nibblePointer7;
    sentCh->VIEW.U   = tempVIEW.U;

    /* Initialize the input/output control settings for the channel */
    Ifx_SENT_CH_IOCR tempIOCR;
    tempIOCR.U       = 0;
    tempIOCR.B.DEPTH = config->inputOutputControl.digitalGlitchFilterDepth;
    tempIOCR.B.OIE   = config->inputOutputControl.outputPulsePolarityHigh;
    tempIOCR.B.IIE   = config->inputOutputControl.inputPulsePolarityHigh;
    tempIOCR.B.CEC   = config->inputOutputControl.edgeCounterCleared;
    tempIOCR.B.CREG  = config->inputOutputControl.glitchRisingCleared;
    tempIOCR.B.CFEG  = config->inputOutputControl.glitchFallingCleared;
    tempIOCR.B.ETS   = config->inputOutputControl.externalTrigger;
    tempIOCR.B.CTR   = config->inputOutputControl.triggerMonitorCleared;
    sentCh->IOCR.U   = tempIOCR.U;

    /* Initialize the interrupt node control settings for the channel */
    Ifx_SENT_CH_INP tempINP;
    tempINP.U       = 0;
    tempINP.B.RSI   = config->interuptNodeControl.receiveSuccessInterruptNode;
    tempINP.B.RDI   = config->interuptNodeControl.receiveDataInterruptNode;
    tempINP.B.RBI   = config->interuptNodeControl.receiveBufferOverflowInterruptNode;
    tempINP.B.TDI   = config->interuptNodeControl.transferDataInterruptNode;
    tempINP.B.TBI   = config->interuptNodeControl.transferBufferUnderflowInterruptNode;
    tempINP.B.ERRI  = config->interuptNodeControl.errorInterruptNode;
    tempINP.B.SDI   = config->interuptNodeControl.serialDataReceiveInterruptNode;
    tempINP.B.WDI   = config->interuptNodeControl.watchdogErrorInterruptNode;
    sentCh->INP.U   = tempINP.U;

    /* Enable the specified interrupts for the channel */
    sentCh->INTEN.U = config->enabledInterrupts.ALL;

    if (config->receiveControl.frameLength > 8)
    {
        /* Clear RSI and enable only RDI interrupt */
        sentCh->INTEN.B.RSI = 0;
        sentCh->INTEN.B.RDI = 1;
    }

    /* Check if SPC mode is enabled */
    if (config->spcModeOn == TRUE)
    {
        uint16 timeOut = IFXSENT_CFG_TIMEOUT_VALUE;
        uint8  error   = 0;

        /* Check if Transaction is in progress, before proceeding !!! */
        while ((sentCh->SCR.B.TRQ == 1) && (timeOut > 0))
        {
            /* Wait for Transaction to be completed */
            timeOut--;
        }

        /* Check if the timeout expired */
        if (timeOut == 0U)
        {
            error = 1U;
        }

        if (error == 0U)
        {
            Ifx_SENT_CH_SCR tempSCR;
            tempSCR.U      = 0;
            tempSCR.B.PLEN = config->transmitControl.pulseLength;
            tempSCR.B.TRIG = config->transmitControl.triggerSource;
            tempSCR.B.DEL  = config->transmitControl.pulseDelayLength;
            tempSCR.B.BASE = config->transmitControl.timeBase;
            sentCh->SCR.U  = tempSCR.U;

            if (config->transmitControl.spcMode == IfxSent_SpcMode_bidirectional)
            {
                /* Enable Buffer Underflow interrupt also */
                sentCh->INTEN.B.TBI = 1U;
            }
        }
    }

    const IfxSent_Sent_Pins *pinsConfig = (const IfxSent_Sent_Pins *)config->pins;

    /* Pins initialization */
    if (pinsConfig != NULL_PTR)
    {
        const IfxSent_Sent_In *sentIn = pinsConfig->in;

        if (sentIn != NULL_PTR)
        {
            IfxSent_initSentPin(sentIn, pinsConfig->inMode, pinsConfig->pinDriver);
        }

        const IfxSent_Spc_Out *spcOut = pinsConfig->out;

        if (spcOut != NULL_PTR)
        {
            IfxSent_initSpcPin(spcOut, pinsConfig->outMode, pinsConfig->pinDriver);
        }
    }

    {
        IfxSrc_Tos tos = config->interrupt.isrProvider;

        if ((config->interrupt.priority != 0) || (tos == IfxSrc_Tos_dma))
        {
            volatile Ifx_SRC_SRCR *src = IfxSent_getChannelSrc(config->channelId);
            IfxSrc_init(src, tos, config->interrupt.priority);
            IfxSrc_enable(src);
        }
    }

    return result;
}


void IfxSent_Sent_initChannelConfig(IfxSent_Sent_ChannelConfig *config, IfxSent_Sent *driver)
{
	/* Define the default configuration for the SENT channel */
    const IfxSent_Sent_ChannelConfig defaultChannelConfig = {
        .driver             = NULL_PTR,
        .channelId          = IfxSent_ChannelId_none,
        .tUnit              = 3E-6,  /* 3 uS */

        .watchDogTimerLimit = 0,

		 /* Initialize the default receive control settings */
        .receiveControl     = {
            .endPulseIgnored               = FALSE,
            .alternateCrcSelected          = FALSE,
            .statusNibbleEnabled           = FALSE,
            .serialDataProcessingEnabled   = FALSE,
            .serialDataDisabledCrcDisabled = FALSE,
            .crcModeDisabled               = FALSE,
            .frameCheckMode                = IfxSent_FrameCheckMode_pastSyncPulse,
            .frameLength                   = 6,
            .crcMethodDisabled             = FALSE,
            .extendedSerialFrameMode       = IfxSent_ExtendedSerialFrameMode_standard,
            .driftErrorsDisabled           = FALSE,
            .suspendTriggered              = FALSE,
            .frequencyDriftCheckEnabled    = FALSE,
        },

		 /* Initialize the default nibble control settings */
        .nibbleControl                            = {
            .nibblePointer0 = IfxSent_Nibble_0,
            .nibblePointer1 = IfxSent_Nibble_1,
            .nibblePointer2 = IfxSent_Nibble_2,
            .nibblePointer3 = IfxSent_Nibble_3,
            .nibblePointer4 = IfxSent_Nibble_4,
            .nibblePointer5 = IfxSent_Nibble_5,
            .nibblePointer6 = IfxSent_Nibble_6,
            .nibblePointer7 = IfxSent_Nibble_7,
        },

		 /* Initialize the default inputoutput control settings */
        .inputOutputControl                       = {
            .digitalGlitchFilterDepth = IfxSent_DigitalGlitchesLength_2,
            .outputPulsePolarityHigh  = FALSE,
            .inputPulsePolarityHigh   = FALSE,
            .edgeCounterCleared       = TRUE,
            .glitchRisingCleared      = TRUE,
            .glitchFallingCleared     = TRUE,
            .externalTrigger          = IfxSent_ExternalTrigger_0,
            .triggerMonitorCleared    = FALSE,
        },

		 /* Enable default interrupts for the channel */
        .enabledInterrupts.ALL = IFXSENT_CFG_CHANNEL_INTEN,
		 /* Initialize the default interrupt node control settings */
        .interuptNodeControl   = {
            .receiveDataInterruptNode             = IfxSent_InterruptNodePointer_trigo0,
            .receiveSuccessInterruptNode          = IfxSent_InterruptNodePointer_trigo0,
            .receiveBufferOverflowInterruptNode   = IfxSent_InterruptNodePointer_trigo0,
            .transferDataInterruptNode            = IfxSent_InterruptNodePointer_trigo0,
            .transferBufferUnderflowInterruptNode = IfxSent_InterruptNodePointer_trigo0,
            .errorInterruptNode                   = IfxSent_InterruptNodePointer_trigo0,
            .serialDataReceiveInterruptNode       = IfxSent_InterruptNodePointer_trigo0,
            .watchdogErrorInterruptNode           = IfxSent_InterruptNodePointer_trigo0,
        },

        .pins                                     = NULL_PTR,

        /* SPC mode enable/disable */
        .spcModeOn                                = FALSE,
    };
    *config        = defaultChannelConfig;
    config->driver = driver;
}


boolean IfxSent_Sent_initModule(IfxSent_Sent *driver, const IfxSent_Sent_Config *config)
{
    boolean   result  = TRUE;
    Ifx_SENT *sentSFR = config->module;
    driver->sent = sentSFR;

    uint16    passwd = IfxScuWdt_getCpuWatchdogPassword();

    if (IfxSent_isModuleEnabled(sentSFR) == FALSE)
    {
        IfxSent_enableModule(sentSFR);
    }

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Set the sleep mode enable/disable based on the configuration */
    sentSFR->CLC.B.EDIS = (config->sleepModeEnabled != FALSE) ? 0 : 1;

    IfxSent_initializeModuleClock(sentSFR, IfxSent_ClockDividerMode_normal, 1023); /* Fractional divider not required, pass 1:1*/
    IfxSent_setTimeStampPredivider(sentSFR, config->timeStampPreDivider);

    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);

    return result;
}


void IfxSent_Sent_initModuleConfig(IfxSent_Sent_Config *config, Ifx_SENT *sent)
{
    /* Default module initialization */
    const IfxSent_Sent_Config defaultModuleConfig = {
        .module              = NULL_PTR,
        .sleepModeEnabled    = TRUE,
        .timeStampPreDivider = 0,
    };
    *config        = defaultModuleConfig;
    config->module = sent;
}


boolean IfxSent_Sent_readChannelSerialDataFrame(IfxSent_Sent_Channel *channel, IfxSent_Sent_Frame *frame)
{
    boolean           result  = TRUE;

    Ifx_SENT         *sentSFR = channel->driver->sent;
    IfxSent_ChannelId ChanIdx = channel->channelId;
    frame->data         = sentSFR->RDR[ChanIdx].U;
    frame->timeStamp    = sentSFR->RTS[ChanIdx].U;
    frame->statusNibble = channel->channel->RSR.B.SCN;

    return result;
}


boolean IfxSent_Sent_readChannelSerialMessageFrame(IfxSent_Sent_Channel *channel, IfxSent_Sent_SerialMessageFrame *message)
{
    boolean         result = TRUE;

    Ifx_SENT_CH    *sentCh = channel->channel;
    Ifx_SENT_CH_SDS sds;

    sds.U               = sentCh->SDS.U;

    message->serialData = sds.B.SD;
    message->messageId  = sds.B.MID;
    message->configBit  = (IfxSent_ConfigBit)sds.B.CON;
    message->crc        = sds.B.SCRC;

    return result;
}


void IfxSent_Sent_spcPulseUpdate(IfxSent_Sent_Channel *channel, uint8 pulseLength, uint8 delay)
{
    Ifx_SENT_CH_SCR regSCR;

    regSCR.U      = channel->channel->SCR.U;
    regSCR.B.DEL  = delay;
    regSCR.B.PLEN = pulseLength;

    /* For IfxSent_TriggerSource_immediate mode */
    if (regSCR.B.TRIG == IfxSent_TriggerSource_immediate)
    {
        regSCR.B.TRIG = IfxSent_TriggerSource_off;
    }

    channel->channel->SCR.U = regSCR.U;
}


void IfxSent_Sent_spcPulseTrigger(IfxSent_Sent_Channel *channel)
{
    channel->channel->SCR.B.TRIG = IfxSent_TriggerSource_immediate;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
