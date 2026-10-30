/**
 * \file IfxPsi5s_Psi5s.c
 * \brief PSI5S PSI5S details
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
#include "IfxPsi5s_Psi5s.h"

/** \addtogroup IfxLld_Psi5s_Psi5s_Utility
 * \{ */

/******************************************************************************/
/*-----------------------Private Function Prototypes--------------------------*/
/******************************************************************************/

/** \brief Get the fracDiv clock frequency
 *
 * \param[in]    psi5s Pointer to the base of PSI5S register space
 * 
 * \retval Returns the configured fracDiv psi5s clock frequency in Hz. Range 20 to 25MHz
 */
IFX_STATIC uint32 IfxPsi5s_Psi5s_getFracDivClock(Ifx_PSI5S *psi5s);

/** \brief Configure the fracDiv clock.
 *
 * \param[inout] psi5s Pointer to the base of PSI5S register space
 * \param[in]    clock Specifies the required clock frequency in Hz. Range 0 to 200MHz
 *
 * \retval Returns the configured clock frequency in Hz. Range 0 to 25MHz
 */
IFX_STATIC uint32 IfxPsi5s_Psi5s_initializeClock(Ifx_PSI5S *psi5s, const IfxPsi5s_Psi5s_Clock *clock);

/** \brief Configure the baudrate at the ASC interface.
 * 
 * \param[inout] psi5s Pointer to the base of PSI5S register space
 * \param[in]    baudrate Frequency Specifies the required baudrate Range: 0 to 12.5MBaud
 * \param[in]    ascConfig pointer to the configuration structure for ASC
 * 
 * \retval Returns the configured baudrate. Range 0 to 12.5MBaud
 */
IFX_STATIC uint32 IfxPsi5s_Psi5s_setBaudrate(Ifx_PSI5S *psi5s, uint32 baudrate, IfxPsi5s_Psi5s_AscConfig *ascConfig);

/** \} */

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPsi5s_Psi5s_deInitModule(IfxPsi5s_Psi5s *psi5s)
{
    Ifx_PSI5S *psi5sSFR = psi5s->psi5s;
    /* Reset PSI5S kernel */
    IfxPsi5s_Psi5s_resetModule(psi5sSFR);
}


void IfxPsi5s_Psi5s_enableModule(Ifx_PSI5S *psi5s)
{
    psi5s->CLC.U = 0x00000000;
}


float32 IfxPsi5s_Psi5s_getBaudrate(Ifx_PSI5S *psi5s, IfxPsi5s_Psi5s_AscConfig *ascConfig)
{
    boolean synchMode = (ascConfig->receiveMode == IfxPsi5s_AscMode_sync) || (ascConfig->transmitMode == IfxPsi5s_AscMode_sync);
    boolean divMode   = (ascConfig->fractionalDividerEnabled == FALSE);
    /* Get the baudrate frequency in HZ*/
    float32 baudrate  = IfxPsi5s_getBaudrate(psi5s, synchMode, divMode, ascConfig->baudrateSelection);
    
    /* Return the baudrate value*/
    return baudrate;
}


IFX_STATIC uint32 IfxPsi5s_Psi5s_getFracDivClock(Ifx_PSI5S *psi5s)
{
    uint32 result;
    /* Retrieves the SPB divider frequency */
    uint32 fPsi5s = IfxScuCcu_getSpbFrequency();

    switch (psi5s->FDR.B.DM)
    {
    case IfxPsi5s_DividerMode_spb:
        result = fPsi5s;
        break;
    case IfxPsi5s_DividerMode_normal:
        result = fPsi5s / (IFXPSI5S_STEP_RANGE - psi5s->FDR.B.STEP);
        break;
    case IfxPsi5s_DividerMode_fractional:
        result = (fPsi5s * IFXPSI5S_STEP_RANGE) / psi5s->FDR.B.STEP;
        break;
    case IfxPsi5s_DividerMode_off:
        result = 0;
        break;
    default:
        result = 0;
    }

    /* Returns the configured fracDiv psi5s clock frequency in Hz */
    return result;
}


boolean IfxPsi5s_Psi5s_initChannel(IfxPsi5s_Psi5s_Channel *channel, const IfxPsi5s_Psi5s_ChannelConfig *config)
{
    boolean       status = TRUE;

    /* Fetch the current password of the CPU Watchdog module*/
    uint16        passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);

    Ifx_PSI5S    *psi5s = config->module->psi5s;
    channel->module    = (IfxPsi5s_Psi5s *)config->module;
    channel->channelId = config->channelId;

    Ifx_PSI5S_PGC tempPGC;
    tempPGC.U        = psi5s->PGC[config->channelId].U;
    tempPGC.B.TXCMD  = config->pulseGeneration.codeforZero;
    tempPGC.B.ATXCMD = config->pulseGeneration.codeforOne;
    tempPGC.B.TBS    = config->pulseGeneration.timeBaseSelect;
    tempPGC.B.ETB    = config->pulseGeneration.externalTimeBaseSelect;
    tempPGC.B.ETS    = config->pulseGeneration.externalTriggerSelect;

    switch (config->pulseGeneration.periodicOrExternal)
    {
    case IfxPsi5s_TriggerType_periodic:
        tempPGC.B.PTE = TRUE;
        tempPGC.B.ETE = FALSE;
        break;

    case IfxPsi5s_TriggerType_external:
        tempPGC.B.PTE = FALSE;
        tempPGC.B.ETE = TRUE;
        break;
    }

    psi5s->PGC[config->channelId].U = tempPGC.U;

    Ifx_PSI5S_CTV tempCTV;
    tempCTV.U                       = psi5s->CTV[config->channelId].U;
    tempCTV.B.CTV                   = config->channelTrigger.channelTriggerValue;
    tempCTV.B.CTC                   = config->channelTrigger.channelTriggerCounter;
    psi5s->CTV[config->channelId].U = tempCTV.U;

    psi5s->WDT[config->channelId].U = config->watchdogTimerLimit;

    Ifx_PSI5S_RCRA tempRCRA;
    tempRCRA.U                       = psi5s->RCRA[config->channelId].U;
    tempRCRA.B.CRC0                  = config->receiveControl.crcOrParity[0];
    tempRCRA.B.CRC1                  = config->receiveControl.crcOrParity[1];
    tempRCRA.B.CRC2                  = config->receiveControl.crcOrParity[2];
    tempRCRA.B.CRC3                  = config->receiveControl.crcOrParity[3];
    tempRCRA.B.CRC4                  = config->receiveControl.crcOrParity[4];
    tempRCRA.B.CRC5                  = config->receiveControl.crcOrParity[5];
    tempRCRA.B.TSEN                  = config->receiveControl.timestampEnabled;
    tempRCRA.B.TSP                   = config->receiveControl.timestampSelect;
    tempRCRA.B.TSTS                  = config->receiveControl.timestampTriggerSelect;
    tempRCRA.B.FIDS                  = config->receiveControl.frameIdSelect;
    tempRCRA.B.WDMS                  = config->receiveControl.watchdogTimerModeSelect;
    tempRCRA.B.UFC0                  = config->receiveControl.uartFrameCount[0];
    tempRCRA.B.UFC1                  = config->receiveControl.uartFrameCount[1];
    tempRCRA.B.UFC2                  = config->receiveControl.uartFrameCount[2];
    tempRCRA.B.UFC3                  = config->receiveControl.uartFrameCount[3];
    tempRCRA.B.UFC4                  = config->receiveControl.uartFrameCount[4];
    tempRCRA.B.UFC5                  = config->receiveControl.uartFrameCount[5];
    psi5s->RCRA[config->channelId].U = tempRCRA.U;

    Ifx_PSI5S_RCRB tempRCRB;
    tempRCRB.U                       = psi5s->RCRB[config->channelId].U;
    tempRCRB.B.PDL0                  = config->receiveControl.payloadLength[0];
    tempRCRB.B.PDL1                  = config->receiveControl.payloadLength[1];
    tempRCRB.B.PDL2                  = config->receiveControl.payloadLength[2];
    tempRCRB.B.PDL3                  = config->receiveControl.payloadLength[3];
    tempRCRB.B.PDL4                  = config->receiveControl.payloadLength[4];
    tempRCRB.B.PDL5                  = config->receiveControl.payloadLength[5];
    psi5s->RCRB[config->channelId].U = tempRCRB.U;

    psi5s->NFC.U                     = (config->receiveControl.numberOfFramesExpected << (config->channelId * 3));

    Ifx_PSI5S_SCR tempSCR;
    tempSCR.U                       = psi5s->SCR[config->channelId].U;
    tempSCR.B.PLL                   = config->sendControl.payloadLength;
    tempSCR.B.EPS                   = config->sendControl.enhancedProtocolSelection;
    tempSCR.B.BSC                   = config->sendControl.bitStuffControl;
    tempSCR.B.CRC                   = config->sendControl.crcGenerationControl;
    tempSCR.B.STA                   = config->sendControl.startSequenceGenerationControl;
    psi5s->SCR[config->channelId].U = tempSCR.U;

    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);

    /* Returns the configuration status*/
    return status;
}


void IfxPsi5s_Psi5s_initChannelConfig(IfxPsi5s_Psi5s_ChannelConfig *config, IfxPsi5s_Psi5s *psi5s)
{
    /* Initialise buffer with default channel configuration*/
    IfxPsi5s_Psi5s_ChannelConfig IfxPsi5s_Psi5s_defaultChannelConfig = {
        .channelId       = IfxPsi5s_ChannelId_0,
        .module          = NULL_PTR,
        .pulseGeneration = {
            .codeforZero            = 0,
            .codeforOne             = 1,
            .timeBaseSelect         = IfxPsi5s_TimeBase_internal,
            .externalTimeBaseSelect = IfxPsi5s_Trigger_0,
            .periodicOrExternal     = IfxPsi5s_TriggerType_periodic,
            .externalTriggerSelect  = IfxPsi5s_Trigger_0,
        },
        .channelTrigger                     = {
            .channelTriggerValue   = 0x20,
            .channelTriggerCounter = 0x0
        },
        .watchdogTimerLimit = 0x0,
        .receiveControl     = {
            .crcOrParity[0]          = IfxPsi5s_CrcOrParity_parity,
            .crcOrParity[1]          = IfxPsi5s_CrcOrParity_parity,
            .crcOrParity[2]          = IfxPsi5s_CrcOrParity_parity,
            .crcOrParity[3]          = IfxPsi5s_CrcOrParity_parity,
            .crcOrParity[4]          = IfxPsi5s_CrcOrParity_parity,
            .crcOrParity[5]          = IfxPsi5s_CrcOrParity_parity,
            .timestampEnabled        = FALSE,
            .timestampSelect         = IfxPsi5s_TimestampRegister_a,
            .timestampTriggerSelect  = IfxPsi5s_TimestampTrigger_syncPulse,
            .frameIdSelect           = IfxPsi5s_FrameId_frameHeader,
            .watchdogTimerModeSelect = IfxPsi5s_WatchdogTimerMode_frame,
            .uartFrameCount[0]       = IfxPsi5s_UartFrameCount_3,
            .uartFrameCount[1]       = IfxPsi5s_UartFrameCount_3,
            .uartFrameCount[2]       = IfxPsi5s_UartFrameCount_3,
            .uartFrameCount[3]       = IfxPsi5s_UartFrameCount_3,
            .uartFrameCount[4]       = IfxPsi5s_UartFrameCount_3,
            .uartFrameCount[5]       = IfxPsi5s_UartFrameCount_3,
            .payloadLength[0]        = 0,
            .payloadLength[1]        = 0,
            .payloadLength[2]        = 0,
            .payloadLength[3]        = 0,
            .payloadLength[4]        = 0,
            .payloadLength[5]        = 0,
            .numberOfFramesExpected  = IfxPsi5s_NumberExpectedFrames_1,
        },
        .sendControl                        = {
            .payloadLength                  = 6,
            .enhancedProtocolSelection      = IfxPsi5s_EnhancedProtocol_toothGapMethod,
            .bitStuffControl                = FALSE,
            .crcGenerationControl           = FALSE,
            .startSequenceGenerationControl = FALSE
        }
    };
    *config        = IfxPsi5s_Psi5s_defaultChannelConfig;
    config->module = psi5s;
}


boolean IfxPsi5s_Psi5s_initModule(IfxPsi5s_Psi5s *psi5s, const IfxPsi5s_Psi5s_Config *config)
{
    boolean    status   = TRUE;

    Ifx_PSI5S *psi5sSFR = config->module;
    psi5s->psi5s = psi5sSFR;

    /* Fetch the current password of the CPU Watchdog module*/
    uint16     passwd = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Enable the Psi5s module */
    IfxPsi5s_Psi5s_enableModule(psi5sSFR);

    if (IfxPsi5s_Psi5s_initializeClock(psi5sSFR, &config->fracDiv) == 0)
    {
        /* Clock initialization failed*/
        status = FALSE;
        return status;
    }
    else
    {}

    if (IfxPsi5s_Psi5s_initializeClock(psi5sSFR, &config->timestampClock) == 0)
    {
        /* Clock initialization failed*/
        status = FALSE;
        return status;
    }
    else
    {}

    Ifx_PSI5S_CON tempCON;
    tempCON.U       = psi5sSFR->CON.U;
    tempCON.B.M     = config->ascConfig.receiveMode;
    tempCON.B.STP   = config->ascConfig.stopBits;
    tempCON.B.PEN   = config->ascConfig.parityCheckEnabled;
    tempCON.B.FEN   = config->ascConfig.framingCheckEnabled;
    tempCON.B.OEN   = config->ascConfig.overrunCheckEnabled;
    tempCON.B.FDE   = config->ascConfig.fractionalDividerEnabled;
    tempCON.B.ODD   = config->ascConfig.receiverOddParityEnabled;
    tempCON.B.BRS   = config->ascConfig.baudrateSelection;
    tempCON.B.MTX   = config->ascConfig.transmitMode;
    tempCON.B.ODDTX = config->ascConfig.transmitterOddParityEnabled;
    psi5sSFR->CON.U = tempCON.U;
    IfxPsi5s_setLoopBackMode(psi5sSFR, config->ascConfig.loopbackEnabled);

    if (IfxPsi5s_Psi5s_setBaudrate(psi5sSFR, config->ascConfig.baudrateFrequency, (IfxPsi5s_Psi5s_AscConfig *)&(config->ascConfig))
        == 0)
    {
        status = FALSE;
        return status;
    }
    else
    {}

    if (IfxPsi5s_Psi5s_initializeClock(psi5sSFR, &config->ascConfig.clockOutput) == 0)
    {
        status = FALSE;
        return status;
    }
    else
    {}

    Ifx_PSI5S_TSCNTA tempTSCNTA;
    tempTSCNTA.U       = psi5sSFR->TSCNTA.U;
    tempTSCNTA.B.ETB   = config->timestampCounterA.externalTimeBaseSelect;
    tempTSCNTA.B.TBS   = config->timestampCounterA.timeBaseSelect;
    psi5sSFR->TSCNTA.U = tempTSCNTA.U;

    Ifx_PSI5S_TSCNTB tempTSCNTB;
    tempTSCNTB.U       = psi5sSFR->TSCNTB.U;
    tempTSCNTB.B.ETB   = config->timestampCounterB.externalTimeBaseSelect;
    tempTSCNTB.B.TBS   = config->timestampCounterB.timeBaseSelect;
    psi5sSFR->TSCNTB.U = tempTSCNTB.U;

    Ifx_PSI5S_GCR tempGCR;
    tempGCR.U       = psi5sSFR->GCR.U;
    tempGCR.B.CRCI  = config->globalControlConfig.crcErrorConsideredForRSI;
    tempGCR.B.XCRCI = config->globalControlConfig.xcrcErrorConsideredForRSI;
    tempGCR.B.TEI   = config->globalControlConfig.transmitErrorConsideredForRSI;
    tempGCR.B.PE    = config->globalControlConfig.parityErrorConsideredForRSI;
    tempGCR.B.FE    = config->globalControlConfig.framingErrorConsideredForRSI;
    tempGCR.B.OE    = config->globalControlConfig.overrunErrorConsideredForRSI;
    tempGCR.B.RBI   = config->globalControlConfig.receiveBufferErrorConsideredForRSI;
    tempGCR.B.HDI   = config->globalControlConfig.headerErrorConsideredForRSI;
    tempGCR.B.IDT   = config->globalControlConfig.idleTime;
    tempGCR.B.ASC   = config->globalControlConfig.ascOnlyMode;
    psi5sSFR->GCR.U = tempGCR.U;

    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);

    /* Pin mapping */
    const IfxPsi5s_Psi5s_Pins *pins = config->pins;

    if (pins != NULL_PTR)
    {
        const IfxPsi5s_Rx_In *rx = pins->rx;

        if (rx != NULL_PTR)
        {
            /* Initializes a RX input */
            IfxPsi5s_initRxPin(rx, pins->rxMode, pins->pinDriver);
        }

        const IfxPsi5s_Tx_Out *tx = pins->tx;

        if (tx != NULL_PTR)
        {
            /*  Initializes a TX output */
            IfxPsi5s_initTxPin(tx, pins->txMode, pins->pinDriver);
        }

        const IfxPsi5s_Clk_Out *clk = pins->clk;

        if (clk != NULL_PTR)
        {
            /* Initializes a CLK output */
            IfxPsi5s_initClkPin(clk, pins->clkMode, pins->pinDriver);
        }
    }

    /* Returns the configuration status*/
    return status;
}


void IfxPsi5s_Psi5s_initModuleConfig(IfxPsi5s_Psi5s_Config *config, Ifx_PSI5S *psi5s)
{
    /* Retrieves the SPB divider frequency */
    uint32 spbFrequency = IfxScuCcu_getSpbFrequency();

    /* Initialise buffer with default PSI5S configuration */
    config->module                                                 = psi5s;
    config->fracDiv.frequency                                      = spbFrequency;
    config->fracDiv.mode                                           = IfxPsi5s_DividerMode_normal;
    config->fracDiv.type                                           = IfxPsi5s_ClockType_fracDiv;
    config->timestampClock.frequency                               = spbFrequency;
    config->timestampClock.mode                                    = IfxPsi5s_DividerMode_normal;
    config->timestampClock.type                                    = IfxPsi5s_ClockType_timeStamp;
    config->timestampCounterA.externalTimeBaseSelect               = IfxPsi5s_Trigger_0;
    config->timestampCounterA.timeBaseSelect                       = IfxPsi5s_TimeBase_internal;
    config->timestampCounterB.externalTimeBaseSelect               = IfxPsi5s_Trigger_0;
    config->timestampCounterB.timeBaseSelect                       = IfxPsi5s_TimeBase_internal;
    config->ascConfig.baudrateFrequency                            = IFXPSI5S_BAUDRATE_1562500;
    config->ascConfig.clockOutput.frequency                        = spbFrequency;
    config->ascConfig.clockOutput.mode                             = IfxPsi5s_DividerMode_normal;
    config->ascConfig.clockOutput.type                             = IfxPsi5s_ClockType_ascOutput;
    config->ascConfig.receiveMode                                  = IfxPsi5s_AscMode_sync;
    config->ascConfig.stopBits                                     = IfxPsi5s_AscStopBits_1;
    config->ascConfig.parityCheckEnabled                           = FALSE;
    config->ascConfig.framingCheckEnabled                          = FALSE;
    config->ascConfig.overrunCheckEnabled                          = FALSE;
    config->ascConfig.fractionalDividerEnabled                     = FALSE;
    config->ascConfig.receiverOddParityEnabled                     = FALSE;
    config->ascConfig.baudrateSelection                            = IfxPsi5s_AscBaudratePrescalar_divideBy2;
    config->ascConfig.loopbackEnabled                              = IfxPsi5s_LoopBackMode_disable;
    config->ascConfig.transmitMode                                 = IfxPsi5s_AscMode_sync;
    config->ascConfig.transmitterOddParityEnabled                  = FALSE;
    config->globalControlConfig.crcErrorConsideredForRSI           = TRUE;
    config->globalControlConfig.xcrcErrorConsideredForRSI          = TRUE;
    config->globalControlConfig.transmitErrorConsideredForRSI      = TRUE;
    config->globalControlConfig.parityErrorConsideredForRSI        = TRUE;
    config->globalControlConfig.framingErrorConsideredForRSI       = TRUE;
    config->globalControlConfig.overrunErrorConsideredForRSI       = FALSE;
    config->globalControlConfig.receiveBufferErrorConsideredForRSI = FALSE;
    config->globalControlConfig.headerErrorConsideredForRSI        = FALSE;
    config->globalControlConfig.idleTime                           = IfxPsi5s_IdleTime_1;
    config->globalControlConfig.ascOnlyMode                        = FALSE;
    config->pins                                                   = NULL_PTR;
}


IFX_STATIC uint32 IfxPsi5s_Psi5s_initializeClock(Ifx_PSI5S *psi5s, const IfxPsi5s_Psi5s_Clock *clock)
{
    uint64               step           = 0;
    uint32               stepRange      = IFXPSI5S_STEP_RANGE;
    uint32               result         = 0;
    IfxPsi5s_DividerMode divMode        = clock->mode;
    IfxPsi5s_ClockType   clockType      = clock->type;
    uint32               clockFrequency = clock->frequency;
    uint32               fInput;
    Ifx_PSI5S_FDR        tempFDR;
    Ifx_PSI5S_FDRT       tempFDRT;
    Ifx_PSI5S_FDO        tempFDO;

    if (clockType == IfxPsi5s_ClockType_fracDiv)
    {
        /* Retrieves the SPB divider frequency */
        fInput = IfxScuCcu_getSpbFrequency();
    }
    else if (clockType == IfxPsi5s_ClockType_ascOutput)
    {
        /* Assumption here is that fBaud2 is equal to fSPB */
        fInput    = IfxScuCcu_getSpbFrequency(); 
        stepRange = 2 * IFXPSI5S_STEP_RANGE;
    }
    else
    {
        /* Get the fracDiv clock frequency */
        fInput = IfxPsi5s_Psi5s_getFracDivClock(psi5s);

        if (fInput == 0)
        {
            result = 0;
            return result;
        }
        else
        {}
    }

    switch (divMode)
    {
    case IfxPsi5s_DividerMode_normal:
        step = stepRange - (fInput / clockFrequency);

        if (step > (stepRange - 1))
        {
            step = stepRange - 1;
        }
        else
        {
            /* Do nothing */
        }

        result = (uint32)(fInput / (stepRange - step));
        break;

    case IfxPsi5s_DividerMode_fractional:
        step = (uint64)((uint64)clockFrequency * stepRange) / fInput;

        if (step > (stepRange - 1))
        {
            step = stepRange - 1;
        }
        else
        {
            /* Do nothing */
        }

        result = (uint32)((uint64)((uint64)fInput * step)) / stepRange;
        break;

    case IfxPsi5s_DividerMode_off:
    default:
        step   = 0;
        result = 0;
        break;
    }

    if (result != 0)
    {
        switch (clockType)
        {
        case IfxPsi5s_ClockType_fracDiv:
            tempFDR.U      = 0;
            tempFDR.B.DM   = divMode;
            tempFDR.B.STEP = (uint32)step;
            psi5s->FDR.U   = tempFDR.U;
            break;

        case IfxPsi5s_ClockType_timeStamp:
            tempFDRT.U      = 0;
            tempFDRT.B.DM   = divMode;
            tempFDRT.B.STEP = (uint32)step;
            psi5s->FDRT.U   = tempFDRT.U;
            break;

        case IfxPsi5s_ClockType_ascOutput:
            tempFDO.U      = 0;
            tempFDO.B.DM   = divMode;
            tempFDO.B.STEP = (uint32)step;
            psi5s->FDO.U   = tempFDO.U;
            break;
        default:
            break;
        }
    }

    /* Returns the configured clock frequency in Hz */
    return result;
}


void IfxPsi5s_Psi5s_readFrame(IfxPsi5s_Psi5s_Channel *channel, IfxPsi5s_Psi5s_Frame *frame)
{
    /* Store the received data to the buffer */
    frame->data.rdr                                       = channel->module->psi5s->RDR.U;
    /* Store the received data stsus to the buffer */
    frame->status.rds                                     = channel->module->psi5s->RDS.U;
    /* Store the received data time stamp to the buffer */
    frame->timestamp.tsm                                  = channel->module->psi5s->TSM.U;

    /* Clear the RSI and RDI Interrupts */
    channel->module->psi5s->INTCLR[channel->channelId].U |= (IFX_PSI5S_INTCLR_RDI_MSK << IFX_PSI5S_INTCLR_RDI_OFF) | (IFX_PSI5S_INTCLR_RSI_MSK << IFX_PSI5S_INTCLR_RSI_OFF);
}


void IfxPsi5s_Psi5s_resetModule(Ifx_PSI5S *psi5s)
{
    /* Fetch the current password of the CPU Watchdog module*/
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearSafetyEndinit(passwd);
    
    /* Only if both Kernel reset bits are set a reset is executed */
    psi5s->KRST1.B.RST = 1;     
    psi5s->KRST0.B.RST = 1;

    while (psi5s->KRST0.B.RSTSTAT == 0)
    {
        /* Wait until reset is executed */
    }

    /* Clear Kernel reset status bit */
    psi5s->KRSTCLR.B.CLR = 1;   

    /* Setting the endinit protection back on */
    IfxScuWdt_setSafetyEndinit(passwd);
}


boolean IfxPsi5s_Psi5s_sendChannelData(IfxPsi5s_Psi5s_Channel *channel, uint32 data)
{
    /* Load to data to the SDR register*/
    channel->module->psi5s->SDR[channel->channelId].U = data & 0x00FFFFFF;

    if (channel->module->psi5s->INTSTAT[channel->channelId].B.TPOI)
    {
        /* The Data didn't send successfully */
        return FALSE;
    }
    else
    {
        /* The Data send successfully */
        return TRUE;
    }
}


IFX_STATIC uint32 IfxPsi5s_Psi5s_setBaudrate(Ifx_PSI5S *psi5s, uint32 baudrate, IfxPsi5s_Psi5s_AscConfig *ascConfig)
{
    uint32 bgValue = 0;
    uint32 fdValue = 0;
    uint32 result  = 0;
    uint32 fInput;

    if (ascConfig->receiveMode == IfxPsi5s_AscMode_sync)
    {
        if (ascConfig->transmitMode != IfxPsi5s_AscMode_sync)
        {
            /* Sync modes must be set for both receive and transmit */
        }

        /* Retrieves the SPB divider frequency */
        fInput  = 2 * IfxScuCcu_getSpbFrequency();
        bgValue = (uint32)(fInput / ((ascConfig->baudrateSelection + 2) * 4 * (uint64)baudrate) - 1);

        if (bgValue > (IFXPSI5S_BG_RANGE - 1))
        {
            bgValue = IFXPSI5S_BG_RANGE - 1;
        }
        else
        {
            /* Do nothing */
        }

        result = fInput / ((ascConfig->baudrateSelection + 2) * 4 * (bgValue + 1));
    }
    else if (ascConfig->fractionalDividerEnabled == FALSE)
    {
        /* Retrieves the SPB divider frequency */
        fInput  = 2 * IfxScuCcu_getSpbFrequency();
        bgValue = (uint32)(fInput / ((ascConfig->baudrateSelection + 2) * 16 * (uint64)baudrate) - 1);

        if (bgValue > (IFXPSI5S_BG_RANGE - 1))
        {
            bgValue = IFXPSI5S_BG_RANGE - 1;
        }
        else
        {
            /* Do nothing */
        }

        result = fInput / ((ascConfig->baudrateSelection + 2) * 16 * (bgValue + 1));
    }
    else
    {
        /* Retrieves the SPB divider frequency */
        fInput  = 2 * IfxScuCcu_getSpbFrequency();
        fdValue = (((uint64)baudrate * IFXPSI5S_FDV_RANGE * 16)) / (float)fInput;

        if (fdValue > (IFXPSI5S_FDV_RANGE - 1))
        {
            fdValue = IFXPSI5S_FDV_RANGE - 1;
            bgValue = ((float)fdValue / IFXPSI5S_FDV_RANGE) * (fInput / (16 * baudrate)) - 1;

            if (bgValue > (IFXPSI5S_BG_RANGE - 1))
            {
                bgValue = IFXPSI5S_BG_RANGE - 1;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            bgValue = 0;
        }

        result = ((float)fdValue / IFXPSI5S_FDV_RANGE) * (fInput / (16 * (bgValue + 1)));
    }

    /* Load the fractional divider value to FDV register */
    psi5s->FDV.U = fdValue;
    /* Load the Baudrate value to the BG Register */
    psi5s->BG.U  = bgValue;

    /* Returns the configured baudrate frequency in Hz */
    return result;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
