/**
 * \file IfxAudio_Tdm.c
 * \brief AUDIO TDM details
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
#include "IfxAudio_Tdm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxAudio_Tdm_startTx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_CTL.B.START = 1;
}


void IfxAudio_Tdm_stopTx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_CTL.B.START = 0;
}


void IfxAudio_Tdm_enableTx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_CTL.B.ENABLED = 1;
}


void IfxAudio_Tdm_disableTx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_CTL.B.ENABLED = 0;
}


void IfxAudio_Tdm_setTestLoopbackMode(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, IfxAudio_Tdm_TestMode mode)
{
    /*Either tx or rx can be used in loopback at a time*/
    /*Pre-condition: TDMi_TX_ROUTE_CTL.MODE must be 0. If MODE is set to 1 or 2, TX_TEST_CTL.ENABLED and RX_TEST_CTL.ENABLED should not be set to 1.*/
    audio->audioSFR->TDM[tdmIndex].TX_ROUTE_CTL.B.MODE = 0;

    if (mode == IfxAudio_Tdm_TestMode_tx)
    {
        audio->audioSFR->TDM[tdmIndex].TX_TEST_CTL.B.ENABLED = 1; /*Test mode (intended to be used with (slave transmitter, master receiver) configuration).*/
        audio->audioSFR->TDM[tdmIndex].RX_TEST_CTL.B.ENABLED = 0; /*Functional mode*/
    }
    else
    {
        audio->audioSFR->TDM[tdmIndex].TX_TEST_CTL.B.ENABLED = 0; /*Functional mode*/
        audio->audioSFR->TDM[tdmIndex].RX_TEST_CTL.B.ENABLED = 1; /*Test mode (intended to be used with (master transmitter, slave receiver) configuration)*/
    }
}


void IfxAudio_Tdm_configureTx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, IfxAudio_Tdm_TxConfig *config)
{
    Ifx_AUDIO_TDM_TX_CTL txControl;
    txControl.U                             = 0;
    audio->audioSFR->TDM[tdmIndex].TX_CTL.U = 0x00010000;                /*Configure to Reset value. Disable and Stop Tx. Master mode selected as per reset value.*/

    txControl.B.MS                          = config->slaveOrMasterMode; /* Select mode as per configuration*/
    txControl.B.FORMAT                      = config->format;
    txControl.B.WORD_SIZE                   = config->wordSize;

    audio->audioSFR->TDM[tdmIndex].TX_CTL.U = txControl.U;

    Ifx_AUDIO_TDM_TX_IF_CTL txInterfaceControl;
    txInterfaceControl.U                               = 0;

    txInterfaceControl.B.CLOCK_DIV                     = config->clockDiv;
    txInterfaceControl.B.MCK_DIV                       = config->mckClockDiv;
    txInterfaceControl.B.CLOCK_SEL                     = config->clockSource;
    txInterfaceControl.B.SCK_POLARITY                  = config->clockPolarity;
    txInterfaceControl.B.FSYNC_POLARITY                = config->channelSyncPolarity;
    txInterfaceControl.B.FSYNC_FORMAT                  = config->channelSyncPulseFormat;
    txInterfaceControl.B.CH_NR                         = config->numChannels;
    txInterfaceControl.B.CH_SIZE                       = config->channelSize;
    txInterfaceControl.B.I2S_MODE                      = config->tdmOrI2sMode;

    audio->audioSFR->TDM[tdmIndex].TX_IF_CTL.U         = txInterfaceControl.U;

    audio->audioSFR->TDM[tdmIndex].TX_CH_CTL.U         = config->enableChannels; /*Enables the required channels*/

    audio->audioSFR->TDM[tdmIndex].TX_ROUTE_CTL.B.MODE = config->txPinsRouteControl;
}


void IfxAudio_Tdm_configureTxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, IfxAudio_Tdm_FifoConfig *config)
{
    audio->audioSFR->TDM[tdmIndex].TX_FIFO_CTL.B.TRIGGER_LEVEL = config->triggerLevel;
    audio->audioSFR->TDM[tdmIndex].TX_FIFO_CTL.B.SDMADONE_SEL  = config->dmaChannelIndex;
}


void IfxAudio_Tdm_muteTxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_FIFO_CTL.B.MUTE = 1;
}


void IfxAudio_Tdm_unMuteTxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_FIFO_CTL.B.MUTE = 0;
}


void IfxAudio_Tdm_freezeTxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_FIFO_CTL.B.FREEZE = 1;
}


void IfxAudio_Tdm_unFreezeTxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_FIFO_CTL.B.FREEZE = 0;
}


void IfxAudio_Tdm_activateTxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_FIFO_CTL.B.ACTIVE = 1;
}


void IfxAudio_Tdm_deactivateTxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_FIFO_CTL.B.ACTIVE = 0;
}


void IfxAudio_Tdm_enableTxIoSdOutDriveEnablePin(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_IOMUX_CTL.B.SDOUT_DRV_EN = 1; /*exactly one of sd_out_EN_pin0, sd_out_EN_pin1, sd_out_ EN_pin2 and sd_out_EN_pin3 assert according to SDOUT_EN_SEL*/
}


void IfxAudio_Tdm_disableTxIoSdOutDriveEnablePin(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_IOMUX_CTL.B.SDOUT_DRV_EN = 0; /*sd_out_EN_pin0, sd_out_EN_pin1, sd_out_EN_pin2 and sd_out_EN_pin3 always stay at 0*/
}


void IfxAudio_Tdm_setTxSidebandFifoChannelNumber(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint8 channelNumber)
{
    audio->audioSFR->TDM[tdmIndex].TX_SBFIFO_CTL.B.CH_NUM_INSERT = channelNumber;
}


uint8 IfxAudio_Tdm_getTxSidebandFifoUsedStatus(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    return audio->audioSFR->TDM[tdmIndex].TX_SBFIFO_STATUS.B.USED_SB;
}


void IfxAudio_Tdm_enableTxSidebandFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_SBFIFO_CTL.B.SB_ON = 1;
}


void IfxAudio_Tdm_disableTxSidebandFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].TX_SBFIFO_CTL.B.SB_ON = 0;
}


void IfxAudio_Tdm_startRx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].RX_CTL.B.START = 1;
}


void IfxAudio_Tdm_stopRx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].RX_CTL.B.START = 0;
}


void IfxAudio_Tdm_enableRx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].RX_CTL.B.ENABLED = 1;
}


void IfxAudio_Tdm_disableRx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].RX_CTL.B.ENABLED = 0;
}


void IfxAudio_Tdm_configureRx(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, IfxAudio_Tdm_RxConfig *config)
{
    Ifx_AUDIO_TDM_RX_CTL rxControl;
    rxControl.U                             = 0;
    audio->audioSFR->TDM[tdmIndex].RX_CTL.U = 0x10F; /*Disable and Stop Rx, keep default reset values.*/

    rxControl.B.MS                          = config->slaveOrMasterMode;
    rxControl.B.FORMAT                      = config->format;
    rxControl.B.WORD_SIZE                   = config->wordSize;
    rxControl.B.WORD_SIGN_EXTEND            = config->wordSignExtendType;

    audio->audioSFR->TDM[tdmIndex].RX_CTL.U = rxControl.U;

    Ifx_AUDIO_TDM_RX_IF_CTL rxInterfaceControl;
    rxInterfaceControl.U                               = 0;

    rxInterfaceControl.B.CLOCK_DIV                     = config->clockDiv;
    rxInterfaceControl.B.MCK_DIV                       = config->mckClockDiv;
    rxInterfaceControl.B.CLOCK_SEL                     = config->clockSource;
    rxInterfaceControl.B.SCK_POLARITY                  = config->clockPolarity;
    rxInterfaceControl.B.FSYNC_POLARITY                = config->channelSyncPolarity;
    rxInterfaceControl.B.LATE_SAMPLE                   = config->pcmDataSamplingPoint;
    rxInterfaceControl.B.FSYNC_FORMAT                  = config->channelSyncPulseFormat;
    rxInterfaceControl.B.CH_NR                         = config->numChannels;
    rxInterfaceControl.B.CH_SIZE                       = config->channelSize;
    rxInterfaceControl.B.LATE_CAPTURE                  = config->lateCaptureCycles;
    rxInterfaceControl.B.I2S_MODE                      = config->tdmOrI2sMode;

    audio->audioSFR->TDM[tdmIndex].RX_IF_CTL.U         = rxInterfaceControl.U;

    audio->audioSFR->TDM[tdmIndex].RX_CH_CTL.U         = config->enableChannels; /*Enables the required channels*/

    audio->audioSFR->TDM[tdmIndex].RX_ROUTE_CTL.B.MODE = config->rxPinsRouteControl;
}


void IfxAudio_Tdm_configureRxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, IfxAudio_Tdm_FifoConfig *config)
{
    audio->audioSFR->TDM[tdmIndex].RX_FIFO_CTL.B.TRIGGER_LEVEL = config->triggerLevel;
    audio->audioSFR->TDM[tdmIndex].RX_FIFO_CTL.B.SDMADONE_SEL  = config->dmaChannelIndex;
}


void IfxAudio_Tdm_freezeRxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].RX_FIFO_CTL.B.FREEZE = 1;
}


void IfxAudio_Tdm_unFreezeRxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].RX_FIFO_CTL.B.FREEZE = 0;
}


void IfxAudio_Tdm_activateRxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].RX_FIFO_CTL.B.ACTIVE = 1;
}


void IfxAudio_Tdm_deactivateRxFifo(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    audio->audioSFR->TDM[tdmIndex].RX_FIFO_CTL.B.ACTIVE = 0;
}


void IfxAudio_Tdm_configureTxInterruptMask(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint32 maskValue)
{
    audio->audioSFR->TDM[tdmIndex].INTR_TX_MASK.U = maskValue;
}


void IfxAudio_Tdm_configureRxInterruptMask(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint32 maskValue)
{
    audio->audioSFR->TDM[tdmIndex].INTR_RX_MASK.U = maskValue;
}


void IfxAudio_Tdm_setTxIoMckPinMuxSelect(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint8 muxSelect)
{
    audio->audioSFR->TDM[tdmIndex].TX_IOMUX_CTL.B.MCK_MUX_SEL = muxSelect;
}


void IfxAudio_Tdm_setTxIoSckPinMuxSelect(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint8 muxSelect)
{
    audio->audioSFR->TDM[tdmIndex].TX_IOMUX_CTL.B.SCK_MUX_SEL = muxSelect;
}


void IfxAudio_Tdm_setTxIoFsyncPinMuxSelect(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint8 muxSelect)
{
    audio->audioSFR->TDM[tdmIndex].TX_IOMUX_CTL.B.FSYNC_MUX_SEL = muxSelect;
}


void IfxAudio_Tdm_setTxIoSdOutEnSelPinSelect(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint8 select)
{
    audio->audioSFR->TDM[tdmIndex].TX_IOMUX_CTL.B.SDOUT_EN_SEL = select;
}


void IfxAudio_Tdm_setRxIoMckPinMuxSelect(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint8 muxSelect)
{
    audio->audioSFR->TDM[tdmIndex].RX_IOMUX_CTL.B.MCK_MUX_SEL = muxSelect;
}


void IfxAudio_Tdm_setRxIoSckPinMuxSelect(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint8 muxSelect)
{
    audio->audioSFR->TDM[tdmIndex].RX_IOMUX_CTL.B.SCK_MUX_SEL = muxSelect;
}


void IfxAudio_Tdm_setRxIoFsyncPinMuxSelect(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint8 muxSelect)
{
    audio->audioSFR->TDM[tdmIndex].RX_IOMUX_CTL.B.FSYNC_MUX_SEL = muxSelect;
}


void IfxAudio_Tdm_setRxIoSdInPinMuxSelect(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint8 muxSelect)
{
    audio->audioSFR->TDM[tdmIndex].RX_IOMUX_CTL.B.SD_MUX_SEL = muxSelect;
}


void IfxAudio_Tdm_txPtpMatchSource(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, IfxAudio_PtpMatchSource source)
{
    audio->audioSFR->TDM[tdmIndex].TX_PTP_MATCH.B.MATCH_SRC = source;
}


void IfxAudio_Tdm_rxPtpMatchSource(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, IfxAudio_PtpMatchSource source)
{
    audio->audioSFR->TDM[tdmIndex].RX_PTP_MATCH.B.MATCH_SRC = source;
}


void IfxAudio_Tdm_txPtpMatchType(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, boolean turnOnType)
{
    audio->audioSFR->TDM[tdmIndex].TX_PTP_MATCH.B.MATCH_WAIT = turnOnType;
}


void IfxAudio_Tdm_rxPtpMatchType(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, boolean turnOnType)
{
    audio->audioSFR->TDM[tdmIndex].RX_PTP_MATCH.B.MATCH_WAIT = turnOnType;
}


void IfxAudio_Tdm_ptpCaptureTriggerEnable(IfxAudio_Audio *audio, uint16 value)
{
    audio->audioSFR->PTPCAP_EN.B.AUXPTPCAPTRIG_EN = value;
}


void IfxAudio_Tdm_ptpCaptureTriggerSourceSelect(IfxAudio_Audio *audio, uint16 value)
{
    audio->audioSFR->PTPCAP_SRC.B.AUXPTPCAPTRIG_SRC = value;
}


void IfxAudio_Tdm_tsnPhantomTdmConfig(IfxAudio_Audio *audio, IfxAudio_Tdm_TsnPhantomTdmConfig *config)
{
    audio->audioSFR->TSN_PH_TDM.B.CLOCK_DIVPH   = config->divider;
    audio->audioSFR->TSN_PH_TDM.B.PH_MATCH_SRC  = config->matchTriggerSource;
    audio->audioSFR->TSN_PH_TDM.B.PH_MATCH_WAIT = config->matchType;
}


void IfxAudio_Tdm_tsnPhantomTdmStart(IfxAudio_Audio *audio)
{
    audio->audioSFR->TSN_PH_TDM.B.PH_START = 1;
}


void IfxAudio_Tdm_tsnPhantomTdmStop(IfxAudio_Audio *audio)
{
    audio->audioSFR->TSN_PH_TDM.B.PH_START = 0;
}


void IfxAudio_Tdm_tsnCaptureTrigger1GeneratorConfig(IfxAudio_Audio *audio, IfxAudio_Tdm_TsnTriggerGenConfig *config)
{
    audio->audioSFR->TSN_TRG1_GEN.B.SAMPLE_DIV1  = config->divider;
    audio->audioSFR->TSN_TRG1_GEN.B.CAPTRIG1_SRC = config->triggerSource;
}


void IfxAudio_Tdm_tsnTrigger1GeneratorOn(IfxAudio_Audio *audio)
{
    audio->audioSFR->TSN_TRG1_GEN.B.TRIG1GEN_ON = 1;
}


void IfxAudio_Tdm_tsnTrigger1GeneratorOff(IfxAudio_Audio *audio)
{
    audio->audioSFR->TSN_TRG1_GEN.B.TRIG1GEN_ON = 0;
}


void IfxAudio_Tdm_tsnCaptureTrigger2GeneratorConfig(IfxAudio_Audio *audio, IfxAudio_Tdm_TsnTriggerGenConfig *config)
{
    audio->audioSFR->TSN_TRG2_GEN.B.SAMPLE_DIV2  = config->divider;
    audio->audioSFR->TSN_TRG2_GEN.B.CAPTRIG2_SRC = config->triggerSource;
}


void IfxAudio_Tdm_tsnTrigger2GeneratorOn(IfxAudio_Audio *audio)
{
    audio->audioSFR->TSN_TRG2_GEN.B.TRIG2GEN_ON = 1;
}


void IfxAudio_Tdm_tsnTrigger2GeneratorOff(IfxAudio_Audio *audio)
{
    audio->audioSFR->TSN_TRG2_GEN.B.TRIG2GEN_ON = 0;
}


void IfxAudio_Tdm_txFifoWrite(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint32 data)
{
    audio->audioSFR->TDM[tdmIndex].TX_FIFO_WR.U = data;
}


void IfxAudio_Tdm_txSideBandFifoWrite(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex, uint32 data)
{
    audio->audioSFR->TDM[tdmIndex].TX_SBFIFO_WR.U = data;
}


uint32 IfxAudio_Tdm_rxFifoRead(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    return (uint32)(audio->audioSFR->TDM[tdmIndex].RX_FIFO_RD.U);
}


uint32 IfxAudio_Tdm_rxFifoSilentRead(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    return (uint32)(audio->audioSFR->TDM[tdmIndex].RX_FIFO_RD_SILENT.U);
}


uint32 IfxAudio_Tdm_getTxFifoUsedStatus(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    return (uint32)(audio->audioSFR->TDM[tdmIndex].TX_FIFO_STATUS.B.USED);
}


uint32 IfxAudio_Tdm_getRxFifoUsedStatus(IfxAudio_Audio *audio, IfxAudio_TdmInterfaceIndex tdmIndex)
{
    return (uint32)(audio->audioSFR->TDM[tdmIndex].RX_FIFO_STATUS.B.USED);
}

#endif /* #if defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
