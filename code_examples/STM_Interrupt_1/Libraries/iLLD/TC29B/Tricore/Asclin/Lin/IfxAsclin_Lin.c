/**
 * \file IfxAsclin_Lin.c
 * \brief ASCLIN LIN details
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

#include "IfxAsclin_Lin.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxAsclin_Lin_checkForReceivedHeaderFlags(IfxAsclin_Lin *asclin)
{
    Ifx_ASCLIN *asclinSFR = asclin->asclin;            /* getting the pointer to ASCLIN registers from module handler*/

    /* check Rx header end acknowledgement */
    if (IfxAsclin_getRxHeaderEndFlagStatus(asclinSFR)) /* RHE flag*/
    {
        IfxAsclin_clearRxHeaderEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.rxHeaderEnd = 1;
    }

    /* check for Rx header error flags */
    if (IfxAsclin_getHeaderTimeoutFlagStatus(asclinSFR))     /* HT flag*/
    {
        IfxAsclin_clearHeaderTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.headerTimeout = 1;
    }

    if (IfxAsclin_getCollisionDetectionErrorFlagStatus(asclinSFR))     /* CE flag*/
    {
        IfxAsclin_clearCollisionDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.collisionDetectionError = 1;
    }

    if (IfxAsclin_getFrameErrorFlagStatus(asclinSFR)) /* FE flag*/
    {
        IfxAsclin_clearFrameErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.frameError = 1;
    }

    if (IfxAsclin_getLinAutoBaudDetectionErrorFlagStatus(asclinSFR))     /* LA flag*/
    {
        IfxAsclin_clearLinAutoBaudDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linAutobaudDetectionError = 1;
    }

    if (IfxAsclin_getLinParityErrorFlagStatus(asclinSFR)) /* LP flag*/
    {
        IfxAsclin_clearLinParityErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linParityError = 1;
    }
}


void IfxAsclin_Lin_checkForReceivedResponseFlags(IfxAsclin_Lin *asclin)
{
    Ifx_ASCLIN *asclinSFR = asclin->asclin; /* getting the pointer to ASCLIN registers from module handler*/

    /* check Rx response end acknowledgement*/
    if (IfxAsclin_getRxResponseEndFlagStatus(asclinSFR))
    {
        IfxAsclin_clearRxResponseEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.rxResponseEnd = 1;
    }

    /* check for Rx response error flags */
    if (IfxAsclin_getRxFifoOverflowFlagStatus(asclinSFR)) /* RFO flag*/
    {
        IfxAsclin_clearRxFifoOverflowFlag(asclinSFR);
        asclin->errorFlagsStatus.rxFifoOverflow = 1;
    }

    if (IfxAsclin_getCollisionDetectionErrorFlagStatus(asclinSFR))     /* CE flag*/
    {
        IfxAsclin_clearCollisionDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.collisionDetectionError = 1;
    }

    if (IfxAsclin_getFrameErrorFlagStatus(asclinSFR)) /* FE flag*/
    {
        IfxAsclin_clearFrameErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.frameError = 1;
    }

    if (IfxAsclin_getLinChecksumErrorFlagStatus(asclinSFR))     /* LC flag*/
    {
        IfxAsclin_clearLinChecksumErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linChecksumError = 1;
    }

    if (IfxAsclin_getResponseTimeoutFlagStatus(asclinSFR))     /* RT flag*/
    {
        IfxAsclin_clearResponseTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.responseTimeout = 1;
    }

    if ((asclin->linMode == IfxAsclin_LinMode_slave) && (IfxAsclin_getBreakDetectedFlagStatus(asclinSFR))) /* BD flag only in slave mode*/
    {
        IfxAsclin_clearBreakDetectedFlag(asclinSFR);
        asclin->errorFlagsStatus.breakDetected = 1;
    }
}


void IfxAsclin_Lin_checkForTransmittedHeaderFlags(IfxAsclin_Lin *asclin)
{
    Ifx_ASCLIN *asclinSFR = asclin->asclin;            /* getting the pointer to ASCLIN registers from module handler*/

    /* check Tx header end acknowledgement */
    if (IfxAsclin_getTxHeaderEndFlagStatus(asclinSFR)) /* THE flag*/
    {
        IfxAsclin_clearTxHeaderEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.txHeaderEnd = 1;
    }

    /* check for Tx header error flags */
    if (IfxAsclin_getHeaderTimeoutFlagStatus(asclinSFR))     /* HT flag*/
    {
        IfxAsclin_clearHeaderTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.headerTimeout = 1;
    }

    if (IfxAsclin_getCollisionDetectionErrorFlagStatus(asclinSFR))     /* CE flag*/
    {
        IfxAsclin_clearCollisionDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.collisionDetectionError = 1;
    }

    if (IfxAsclin_getFrameErrorFlagStatus(asclinSFR)) /* FE flag*/
    {
        IfxAsclin_clearFrameErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.frameError = 1;
    }

    if (IfxAsclin_getLinParityErrorFlagStatus(asclinSFR)) /* LP flag*/
    {
        IfxAsclin_clearLinParityErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linParityError = 1;
    }
}


void IfxAsclin_Lin_checkForTransmittedResponseFlags(IfxAsclin_Lin *asclin)
{
    Ifx_ASCLIN *asclinSFR = asclin->asclin;              /* getting the pointer to ASCLIN registers from module handler*/

    /* check Tx response end acknowledgement */
    if (IfxAsclin_getTxResponseEndFlagStatus(asclinSFR)) /* TRE flag*/
    {
        IfxAsclin_clearTxResponseEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.txResponseEnd = 1;
    }

    /* check for Tx response error flags */
    if (IfxAsclin_getTxFifoOverflowFlagStatus(asclinSFR)) /* TFO flag*/
    {
        IfxAsclin_clearTxFifoOverflowFlag(asclinSFR);
        asclin->errorFlagsStatus.txFifoOverflow = 1;
    }

    if (IfxAsclin_getCollisionDetectionErrorFlagStatus(asclinSFR))     /* CE flag*/
    {
        IfxAsclin_clearCollisionDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.collisionDetectionError = 1;
    }

    if (IfxAsclin_getResponseTimeoutFlagStatus(asclinSFR))     /* RT flag*/
    {
        IfxAsclin_clearResponseTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.responseTimeout = 1;
    }

    if ((asclin->linMode == IfxAsclin_LinMode_slave) && (IfxAsclin_getBreakDetectedFlagStatus(asclinSFR))) /* BD flag only in slave mode*/
    {
        IfxAsclin_clearBreakDetectedFlag(asclinSFR);
        asclin->errorFlagsStatus.breakDetected = 1;
    }
}


void IfxAsclin_Lin_clearFlagsStatus(IfxAsclin_Lin *asclin)
{
    /*clear acknowledgement flags status */
    asclin->acknowledgmentFlags.txHeaderEnd   = 0;
    asclin->acknowledgmentFlags.rxHeaderEnd   = 0;
    asclin->acknowledgmentFlags.txResponseEnd = 0;
    asclin->acknowledgmentFlags.rxResponseEnd = 0;

    /* clear error flags status*/
    asclin->errorFlagsStatus.headerTimeout             = 0;
    asclin->errorFlagsStatus.collisionDetectionError   = 0;
    asclin->errorFlagsStatus.frameError                = 0;
    asclin->errorFlagsStatus.responseTimeout           = 0;
    asclin->errorFlagsStatus.linParityError            = 0;
    asclin->errorFlagsStatus.breakDetected             = 0;
    asclin->errorFlagsStatus.linAutobaudDetectionError = 0;
    asclin->errorFlagsStatus.linChecksumError          = 0;
    asclin->errorFlagsStatus.txFifoOverflow            = 0;
    asclin->errorFlagsStatus.rxFifoOverflow            = 0;
}


void IfxAsclin_Lin_disableModule(IfxAsclin_Lin *asclin)
{
    Ifx_ASCLIN *asclinSFR = asclin->asclin;       /* getting the pointer to ASCLIN registers from module handler*/
    uint16      psw       = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(psw);               /* clearing the endinit protection*/
    IfxAsclin_setDisableModuleRequest(asclinSFR); /* disabling the module*/
    IfxScuWdt_setCpuEndinit(psw);                 /* setting the endinit protection back on*/
}


void IfxAsclin_Lin_ignoreHeader(IfxAsclin_Lin *asclin)
{
    Ifx_ASCLIN *asclinSFR = asclin->asclin;                                                  /* getting the pointer to ASCLIN registers from module handler*/
    IfxAsclin_enableRxFifoInlet(asclinSFR, FALSE);                                           /* disable Rx FIFO*/
    IfxAsclin_setHeaderResponseSelect(asclinSFR, IfxAsclin_HeaderResponseSelect_headerOnly); /* set header only mode*/
    IfxAsclin_clearAllFlags(asclinSFR);                                                      /* clear all flags*/
}


IfxAsclin_Status IfxAsclin_Lin_initModule(IfxAsclin_Lin *asclin, const IfxAsclin_Lin_Config *config)
{
    Ifx_ASCLIN      *asclinSFR = config->asclin;                        /* pointer to ASCLIN registers */
    IfxAsclin_Status status    = IfxAsclin_Status_noError;

    asclin->asclin = asclinSFR;                                         /* adding register pointer to module handler*/
    IfxAsclin_enableModule(asclinSFR);                                  /* enabling the module*/

    /* mode initialisation */
    IfxAsclin_setClockSource(asclinSFR, IfxAsclin_ClockSource_noClock); /* disabling the clock*/
    IfxAsclin_setFrameMode(asclinSFR, IfxAsclin_FrameMode_initialise);  /* setting the module in Initialise mode*/
    IfxAsclin_setClockSource(asclinSFR, config->clockSource);           /* setting the clock source*/

    /* lin mode initialisation */
    IfxAsclin_setClockSource(asclinSFR, IfxAsclin_ClockSource_noClock); /* disabling the clock*/
    IfxAsclin_setFrameMode(asclinSFR, config->frameMode);               /* setting the module in Lin mode*/
    IfxAsclin_setLinMode(asclinSFR, config->linMode);                   /* configuring lin mode of operation (master/slave)*/
    IfxAsclin_setRxInput(asclinSFR, config->alti);                      /* selecting the Rx(alternate) input pin*/
    IfxAsclin_setPrescaler(asclinSFR, config->btc.prescaler);           /* setting the prescaler*/
    IfxAsclin_setClockSource(asclinSFR, config->clockSource);           /* setting the clock source*/

    /* baudrate generation in both modes */
    status = (IfxAsclin_Status)IfxAsclin_setBitTiming(asclinSFR, config->brg.baudrate,
        config->btc.oversampling,
        config->bsc.samplePointPosition,
        config->bsc.medianFilter);                                      /* setting the baudrate bit fields to generate the required baudrate*/

    IfxAsclin_setClockSource(asclinSFR, IfxAsclin_ClockSource_noClock); /* disabling the clock again*/

    /* auto baud rate detection in slave mode */
    if (config->linMode == IfxAsclin_LinMode_slave)
    {
        IfxAsclin_enableAutoBaudrateDetection(asclinSFR, config->brd.abd);                 /* setting the auto baudrate detection (enable/disable)*/
        IfxAsclin_setBrdUpperlimt(asclinSFR, config->brd.upperLimit);                      /* setting the upper limit for abd*/
        IfxAsclin_setBrdLowerlimt(asclinSFR, config->brd.lowerLimit);                      /* setting the lower limit for abd*/
    }

    /* frame control initialisation */
    IfxAsclin_enableParity(asclinSFR, config->frame.parityEnable);                         /* setting parity (enable/disable)*/
    IfxAsclin_setParityType(asclinSFR, config->frame.parityType);                          /* setting parity type (odd/even)*/
    IfxAsclin_setStopBit(asclinSFR, config->frame.stopBit);                                /* setting the stop bit*/
    IfxAsclin_enableCollisionDetection(asclinSFR, config->frame.collisionDetectionEnable); /* setting collision detection (enable/disable)*/
    IfxAsclin_setShiftDirection(asclinSFR, config->frame.shiftDir);                        /* setting the shift direction*/

    /* data control initialisation */
    IfxAsclin_setDataLength(asclinSFR, config->data.dataLength);                           /* setting the number of bytes to be transfered*/
    IfxAsclin_setHeaderResponseSelect(asclinSFR, config->data.headerOnly);                 /* setting the header only or header and response mode*/
    IfxAsclin_setLinResponseTimeoutMode(asclinSFR, config->data.responseTimeoutMode);      /* setting the response timeout mode (frame/response)*/
    IfxAsclin_setChecksumMode(asclinSFR, config->data.checksum);                           /* setting the checksum mode (classic/enhanced)*/
    IfxAsclin_setLinResponseTimeoutThreshold(asclinSFR, config->data.responseTimeout);     /* setting the lin response timeout threshold*/

    /* lin control initialisation */
    IfxAsclin_enableHardwareChecksum(asclinSFR, config->lin.csEnable);                     /* setting the hardware checksum (enable/disable)*/
    IfxAsclin_setChecksumInjection(asclinSFR, config->lin.csi);                            /* setting checksum injection*/

    /* master specific initialisation */
    if (config->linMode == IfxAsclin_LinMode_master)
    {
        IfxAsclin_setIdleDelay(asclinSFR, config->frame.idleDelay);          /* setting idle delay for master*/
        IfxAsclin_setLeadDelay(asclinSFR, config->frame.leadDelay);          /* setting lead delay for master mode*/
        IfxAsclin_setLinBreakLength(asclinSFR, config->lin.breakLength);     /* setting the break generation length*/
        IfxAsclin_setLinHeaderTimeout(asclinSFR, config->lin.headerTimeout); /* setting the header timeout value for master*/
        asclin->receiveIdEnable = config->receiveIdEnable;                   /* echoing the selection of receiving Id in its own Rx FIFO*/
    }

    /* slave specific initialisation */
    if (config->linMode == IfxAsclin_LinMode_slave)
    {
        IfxAsclin_setIdleDelay(asclinSFR, config->frame.idleDelay);          /* setting idle delay for slave */
        IfxAsclin_setLeadDelay(asclinSFR, config->frame.leadDelay);          /* setting lead delay for slave mode */
        IfxAsclin_setLinBreakLength(asclinSFR, config->lin.breakLength);     /* setting the break detection length */
        IfxAsclin_setLinHeaderTimeout(asclinSFR, config->lin.headerTimeout); /* setting the header timeout value for slave*/
    }

    /* fifo control initialisation */
    IfxAsclin_setTxFifoInletWidth(asclinSFR, config->fifo.inWidth);   /* setting Tx FIFO inlet width*/
    IfxAsclin_setRxFifoOutletWidth(asclinSFR, config->fifo.outWidth); /* setting Rx FIFO outlet width*/
    IfxAsclin_setRxBufferMode(asclinSFR, config->fifo.buffMode);      /* setting Rx FIFO mode*/
    IfxAsclin_enableTxFifoOutlet(asclinSFR, FALSE);                   /* disabling Rx FIFO for recieving*/
    IfxAsclin_enableRxFifoInlet(asclinSFR, FALSE);                    /* disabling Tx FIFO for transmitting*/
    IfxAsclin_flushRxFifo(asclinSFR);                                 /* flushing Rx FIFO*/
    IfxAsclin_flushTxFifo(asclinSFR);                                 /* flushing Tx FIFO*/

    IfxAsclin_disableAllFlags(asclinSFR);                             /* disable all flags*/
    IfxAsclin_clearAllFlags(asclinSFR);                               /* clear all flags*/

    /* Pin mapping*/
    const IfxAsclin_Lin_Pins *pins = config->pins;

    if (pins != NULL_PTR)
    {
        IfxAsclin_Rx_In *rx = pins->rx;

        if (rx != NULL_PTR)
        {
            IfxAsclin_initRxPin(rx, pins->rxMode, pins->pinDriver);
        }

        IfxAsclin_Tx_Out *tx = pins->tx;

        if (tx != NULL_PTR)
        {
            IfxAsclin_initTxPin(tx, pins->txMode, pins->pinDriver);
        }
    }

    IfxAsclin_setClockSource(asclinSFR, config->clockSource); /* setting the clock source*/

    asclin->linMode = config->linMode;                        /* echoing the mode of operation to module handler*/

    return status;
}


void IfxAsclin_Lin_initModuleConfig(IfxAsclin_Lin_Config *config, Ifx_ASCLIN *asclin)
{
    config->asclin      = asclin;
    config->frameMode   = IfxAsclin_FrameMode_lin;                                             /* LIN mode*/
    config->linMode     = IfxAsclin_LinMode_master;                                            /* Lin Master mode*/
    config->clockSource = IfxAsclin_ClockSource_kernelClock;                                   /* kernel clock, fclc*/
    config->alti        = IfxAsclin_RxInputSelect_0;                                           /* alternate input 0;*/

    /* Default values for baudrate */
    config->brg.baudrate                   = 19200.0;                                          /* default baudrate (the fractional dividier setup will be calculated in initModule)*/
    /* Default Values for Bit Timings */
    config->btc.prescaler                  = 4;                                                /* default prescaler*/
    config->btc.oversampling               = IfxAsclin_OversamplingFactor_16;                  /* default oversampling factor*/
    /* Default Values for Bit sampling */
    config->bsc.filterDepth                = 24U;                                              /* digital glitch filter depth 24*/
    config->bsc.medianFilter               = IfxAsclin_SamplesPerBit_one;                      /* one sample per bit*/
    config->bsc.samplePointPosition        = IfxAsclin_SamplePointPosition_3;                  /* sample point position at 3*/
    /* Default Values for Frame Control */
    config->frame.parityEnable             = FALSE;                                            /* disable parity*/
    config->frame.parityType               = IfxAsclin_ParityType_even;                        /* even parity (if parity enabled) */
    config->frame.stopBit                  = IfxAsclin_StopBit_1;                              /* one stop bit */
    config->frame.shiftDir                 = IfxAsclin_ShiftDirection_lsbFirst;                /* shift diection LSB first */
    config->frame.collisionDetectionEnable = FALSE;
    /* Default Values for Data Control */
    config->data.dataLength                = IfxAsclin_DataLength_8;                           /* number of bytes of the response */
    config->data.headerOnly                = IfxAsclin_HeaderResponseSelect_headerAndResponse; /* header and response */
    config->data.responseTimeoutMode       = IfxAsclin_LinResponseTimeoutMode_frameTimeout;    /* frame timeout */
    config->data.checksum                  = IfxAsclin_Checksum_enhanced;                      /* enhanced checksum */
    config->data.responseTimeout           = 255;
    /* Default Values for fifo Control */
    config->fifo.outWidth                  = IfxAsclin_RxFifoOutletWidth_1;                    /* 8-bit wide read */
    config->fifo.inWidth                   = IfxAsclin_TxFifoInletWidth_1;                     /* 8-bit wide write */
    config->fifo.buffMode                  = IfxAsclin_ReceiveBufferMode_rxFifo;               /* RxFIFO */
    /* Default Values for Lin Control */
    config->lin.csEnable                   = TRUE;                                             /* checksum enable */
    config->lin.csi                        = IfxAsclin_ChecksumInjection_written;              /* 8-bit wide write */

    /* configuration for master mode */
    {
        config->receiveIdEnable   = FALSE;                 /* receive Id in Rx Fifo after sending */
        config->frame.idleDelay   = IfxAsclin_IdleDelay_2; /* idle dalay 2 bits */
        config->frame.leadDelay   = IfxAsclin_LeadDelay_1; /*lead delay in master 1 bit */
        /* Default Values for Lin Control */
        config->lin.breakLength   = 13;                    /* break generation length 13 */
        config->lin.headerTimeout = 56;                    /* header timeout value in master 56 */
    }

    config->pins = NULL_PTR;                               /* pins to null pointer*/
}


void IfxAsclin_Lin_receiveHeader(IfxAsclin_Lin *asclin, uint8 *id)
{
    boolean result = 0;
    IfxAsclin_Lin_prepareHeaderReception(asclin);          /* prepare for header reception */
    result |= IfxAsclin_Lin_waitForReceivedHeader(asclin); /* wait until receive header end acknowledgemnet*/

    if (result == 1)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
    else
    {
        IfxAsclin_Lin_readHeader(asclin, id);           /*read the ID byte*/
    }
}


void IfxAsclin_Lin_receiveResponse(IfxAsclin_Lin *asclin, uint8 *data, uint32 length)
{
    boolean result = 0;
    IfxAsclin_Lin_prepareResponseReception(asclin, length);  /* prepare the response reception */
    result |= IfxAsclin_Lin_waitForReceivedResponse(asclin); /* wait until receive response end acknowledgemnet or an error is occured*/

    if (result == 1)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
    else
    {
        IfxAsclin_Lin_readResponse(asclin, data, length); /* read the data bytes */
    }
}


void IfxAsclin_Lin_sendHeader(IfxAsclin_Lin *asclin, uint8 *id)
{
    boolean     result    = 0;
    Ifx_ASCLIN *asclinSFR = asclin->asclin;            /* getting the pointer to ASCLIN registers from module handler*/
    IfxAsclin_clearAllFlags(asclinSFR);                /* clearing all flags*/

    if (asclin->receiveIdEnable)                       /* if receiving the sent id byte into its own Rx FIFO is selected*/
    {
        IfxAsclin_flushRxFifo(asclinSFR);              /* flushing Rx FIFO*/
        IfxAsclin_enableRxFifoInlet(asclinSFR, TRUE);  /* enabling Rx FIFO */
    }
    else
    {
        IfxAsclin_enableRxFifoInlet(asclinSFR, FALSE);        /* disabling Rx FIFO */
    }

    IfxAsclin_flushTxFifo(asclinSFR);                         /* flushing Tx FIFO */
    IfxAsclin_enableTxFifoOutlet(asclinSFR, TRUE);            /* enabling Tx FIFO for transmitting*/
    IfxAsclin_write8(asclinSFR, id, 1U);                      /* writing the ID byte */
    IfxAsclin_setTransmitHeaderRequestFlag(asclinSFR);        /* setting THRQS flag */
    result |= IfxAsclin_Lin_waitForTransmittedHeader(asclin); /* waiting until transmit header end acknowledgemnet */

    if (result == 1)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


void IfxAsclin_Lin_sendResponse(IfxAsclin_Lin *asclin, uint8 *data, uint32 length)
{
    boolean     result    = 0;
    Ifx_ASCLIN *asclinSFR = asclin->asclin;                                 /* getting the pointer to ASCLIN registers from module handler*/
    IfxAsclin_setDataLength(asclinSFR, (IfxAsclin_DataLength)(length - 1)); /* set number of bytes to be transfered */
    IfxAsclin_clearAllFlags(asclinSFR);                                     /* clear all flags */
    IfxAsclin_flushTxFifo(asclinSFR);                                       /* flushing Tx FIFO */
    IfxAsclin_enableRxFifoInlet(asclinSFR, FALSE);                          /* disable Rx FIFO */
    IfxAsclin_enableTxFifoOutlet(asclinSFR, TRUE);                          /* enable Tx FIFO for transmitting */
    IfxAsclin_write8(asclinSFR, data, length);                              /* write the data bytes; */
    IfxAsclin_setTransmitResponseRequestFlag(asclinSFR);                    /* set TRRQS flag */
    result |= IfxAsclin_Lin_waitForTransmittedResponse(asclin);             /* wait until transmit response end acknowledgemnet */

    if (result == 1)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


boolean IfxAsclin_Lin_waitForReceivedHeader(IfxAsclin_Lin *asclin)
{
    boolean result = 0;
    IfxAsclin_Lin_clearFlagsStatus(asclin);     /* clear all aknowledgement and error flags status */

    /* wait until receive header end acknowledgemnet has been detected  */
    while (asclin->acknowledgmentFlags.rxHeaderEnd != 1)
    {
        IfxAsclin_Lin_checkForReceivedHeaderFlags(asclin);

        if ((asclin->errorFlagsStatus.headerTimeout == 1)
            || (asclin->errorFlagsStatus.collisionDetectionError == 1)
            || (asclin->errorFlagsStatus.frameError == 1)
            || (asclin->errorFlagsStatus.linAutobaudDetectionError == 1)
            || (asclin->errorFlagsStatus.linParityError == 1))
        {
            result = 1;
            break;
        }
    }

    return result;
}


boolean IfxAsclin_Lin_waitForReceivedResponse(IfxAsclin_Lin *asclin)
{
    boolean result = 0;
    IfxAsclin_Lin_clearFlagsStatus(asclin);     /* clear all aknowledgement and error flags status */

    /* wait until receive response end acknowledgemnet has been detected  */
    while (asclin->acknowledgmentFlags.rxResponseEnd != 1)
    {
        IfxAsclin_Lin_checkForReceivedResponseFlags(asclin);

        if ((asclin->errorFlagsStatus.rxFifoOverflow == 1)
            || (asclin->errorFlagsStatus.collisionDetectionError == 1)
            || (asclin->errorFlagsStatus.frameError == 1)
            || (asclin->errorFlagsStatus.linChecksumError == 1)
            || (asclin->errorFlagsStatus.responseTimeout == 1)
            || (asclin->errorFlagsStatus.breakDetected == 1))
        {
            result = 1;
            break;
        }
    }

    return result;
}


boolean IfxAsclin_Lin_waitForTransmittedHeader(IfxAsclin_Lin *asclin)
{
    boolean result = 0;
    IfxAsclin_Lin_clearFlagsStatus(asclin);     /* clear all aknowledgement and error flags status */

    /* wait until transmit header end acknowledgemnet has been detected */
    while (asclin->acknowledgmentFlags.txHeaderEnd != 1)
    {
        IfxAsclin_Lin_checkForTransmittedHeaderFlags(asclin);

        if ((asclin->errorFlagsStatus.headerTimeout == 1)
            || (asclin->errorFlagsStatus.collisionDetectionError == 1)
            || (asclin->errorFlagsStatus.frameError == 1)
            || (asclin->errorFlagsStatus.linParityError == 1))
        {
            result = 1;
            break;
        }
    }

    return result;
}


boolean IfxAsclin_Lin_waitForTransmittedResponse(IfxAsclin_Lin *asclin)
{
    boolean result = 0;
    IfxAsclin_Lin_clearFlagsStatus(asclin);     /* clear all aknowledgement and error flags status */

    /* wait until transmit response end acknowledgemnet has been detected */
    while (asclin->acknowledgmentFlags.txResponseEnd != 1)
    {
        IfxAsclin_Lin_checkForTransmittedResponseFlags(asclin);

        if ((asclin->errorFlagsStatus.txFifoOverflow == 1)
            || (asclin->errorFlagsStatus.collisionDetectionError == 1)
            || (asclin->errorFlagsStatus.responseTimeout == 1)
            || (asclin->errorFlagsStatus.breakDetected == 1))
        {
            result = 1;
            break;
        }
    }

    return result;
}
