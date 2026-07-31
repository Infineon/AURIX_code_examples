/**
 * \file IfxAsclin_Lin.c
 * \brief ASCLIN LIN details
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

#include "IfxAsclin_Lin.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxAsclin_Lin_checkForReceivedHeaderFlags(IfxAsclin_Lin *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* check Rx header end acknowledgement */
    if (IfxAsclin_getRxHeaderEndFlagStatus(asclinSFR)) 		 			/* RHE flag */
    {
        IfxAsclin_clearRxHeaderEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.rxHeaderEnd = 1;
    }

    /* check for Rx header error flags */
    if (IfxAsclin_getHeaderTimeoutFlagStatus(asclinSFR))     		    /* HT flag */
    {
        IfxAsclin_clearHeaderTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.headerTimeout = 1;
    }

    if (IfxAsclin_getCollisionDetectionErrorFlagStatus(asclinSFR))      /* CE flag */
    {
        IfxAsclin_clearCollisionDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.collisionDetectionError = 1;
    }

    if (IfxAsclin_getFrameErrorFlagStatus(asclinSFR)) 				    /* FE flag */
    {
        IfxAsclin_clearFrameErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.frameError = 1;
    }

    if (IfxAsclin_getLinAutoBaudDetectionErrorFlagStatus(asclinSFR))	/* LA flag */
    {
        IfxAsclin_clearLinAutoBaudDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linAutobaudDetectionError = 1;
    }

    if (IfxAsclin_getLinParityErrorFlagStatus(asclinSFR)) 				/* LP flag */
    {
        IfxAsclin_clearLinParityErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linParityError = 1;
    }
}


void IfxAsclin_Lin_checkForReceivedResponseFlags(IfxAsclin_Lin *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* check Rx response end acknowledgement */
    if (IfxAsclin_getRxResponseEndFlagStatus(asclinSFR))
    {
        IfxAsclin_clearRxResponseEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.rxResponseEnd = 1;
    }

    /* check for Rx response error flags */
    if (IfxAsclin_getRxFifoOverflowFlagStatus(asclinSFR)) 			/* RFO flag */
    {
        IfxAsclin_clearRxFifoOverflowFlag(asclinSFR);
        asclin->errorFlagsStatus.rxFifoOverflow = 1;
    }

    if (IfxAsclin_getCollisionDetectionErrorFlagStatus(asclinSFR))	/* CE flag */
    {
        IfxAsclin_clearCollisionDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.collisionDetectionError = 1;
    }

    if (IfxAsclin_getFrameErrorFlagStatus(asclinSFR)) 			   /* FE flag */
    {
        IfxAsclin_clearFrameErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.frameError = 1;
    }

    if (IfxAsclin_getLinChecksumErrorFlagStatus(asclinSFR))        /* LC flag */
    {
        IfxAsclin_clearLinChecksumErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linChecksumError = 1;
    }

    if (IfxAsclin_getResponseTimeoutFlagStatus(asclinSFR))     	   /* RT flag*/
    {
        IfxAsclin_clearResponseTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.responseTimeout = 1;
    }

    if ((asclin->linMode == IfxAsclin_LinMode_slave) && (IfxAsclin_getBreakDetectedFlagStatus(asclinSFR))) /* BD flag only in slave mode */
    {
        IfxAsclin_clearBreakDetectedFlag(asclinSFR);
        asclin->errorFlagsStatus.breakDetected = 1;
    }
}


void IfxAsclin_Lin_checkForTransmittedHeaderFlags(IfxAsclin_Lin *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* check Tx header end acknowledgement */
    if (IfxAsclin_getTxHeaderEndFlagStatus(asclinSFR)) 				/* THE flag */
    {
        IfxAsclin_clearTxHeaderEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.txHeaderEnd = 1;
    }

    /* Check for Tx header error flags */
    if (IfxAsclin_getHeaderTimeoutFlagStatus(asclinSFR))    	    /* HT flag */
    {
        IfxAsclin_clearHeaderTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.headerTimeout = 1;
    }

    if (IfxAsclin_getCollisionDetectionErrorFlagStatus(asclinSFR))	/* CE flag */
    {
        IfxAsclin_clearCollisionDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.collisionDetectionError = 1;
    }

    if (IfxAsclin_getFrameErrorFlagStatus(asclinSFR)) 				/* FE flag */
    {
        IfxAsclin_clearFrameErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.frameError = 1;
    }

    if (IfxAsclin_getLinParityErrorFlagStatus(asclinSFR)) 			/* LP flag */
    {
        IfxAsclin_clearLinParityErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linParityError = 1;
    }
}


void IfxAsclin_Lin_checkForTransmittedResponseFlags(IfxAsclin_Lin *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* check Tx response end acknowledgement */
    if (IfxAsclin_getTxResponseEndFlagStatus(asclinSFR)) 		   /* TRE flag */
    {
        IfxAsclin_clearTxResponseEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.txResponseEnd = 1;
    }

    /* check for Tx response error flags */
    if (IfxAsclin_getTxFifoOverflowFlagStatus(asclinSFR)) 		    /* TFO flag */
    {
        IfxAsclin_clearTxFifoOverflowFlag(asclinSFR);
        asclin->errorFlagsStatus.txFifoOverflow = 1;
    }

    if (IfxAsclin_getCollisionDetectionErrorFlagStatus(asclinSFR))	/* CE flag */
    {
        IfxAsclin_clearCollisionDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.collisionDetectionError = 1;
    }

    if (IfxAsclin_getResponseTimeoutFlagStatus(asclinSFR))     	    /* RT flag */
    {
        IfxAsclin_clearResponseTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.responseTimeout = 1;
    }

    if ((asclin->linMode == IfxAsclin_LinMode_slave) && (IfxAsclin_getBreakDetectedFlagStatus(asclinSFR))) /* BD flag only in slave mode */
    {
        IfxAsclin_clearBreakDetectedFlag(asclinSFR);
        asclin->errorFlagsStatus.breakDetected = 1;
    }
}


void IfxAsclin_Lin_clearFlagsStatus(IfxAsclin_Lin *asclin)
{
    /* clear acknowledgement flags status */
    asclin->acknowledgmentFlags.txHeaderEnd   = 0;
    asclin->acknowledgmentFlags.rxHeaderEnd   = 0;
    asclin->acknowledgmentFlags.txResponseEnd = 0;
    asclin->acknowledgmentFlags.rxResponseEnd = 0;
    asclin->acknowledgmentFlags.txCompleted   = 0;

    /* clear error flags status */
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
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    IfxAsclin_setDisableModuleRequest(asclinSFR);	/* disabling the module */
}


void IfxAsclin_Lin_ignoreHeader(IfxAsclin_Lin *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* disable Rx FIFO */
    IfxAsclin_enableRxFifoInlet(asclinSFR, FALSE);
    /* set header only mode */
    IfxAsclin_setHeaderResponseSelect(asclinSFR, IfxAsclin_HeaderResponseSelect_headerOnly);
    /* clear all flags */
    IfxAsclin_clearAllFlags(asclinSFR);
}


IfxAsclin_Status IfxAsclin_Lin_initModule(IfxAsclin_Lin *asclin, const IfxAsclin_Lin_Config *config)
{
    Ifx_ASCLIN      *asclinSFR = config->asclin;                        /* pointer to ASCLIN registers */
    IfxAsclin_Status status    = IfxAsclin_Status_noError;

    asclin->asclin = asclinSFR;                                         /* adding register pointer to module handler */
    IfxAsclin_enableModule(asclinSFR);                                  /* enabling the module */

    /* mode initialisation */
    IfxAsclin_setClockSource(asclinSFR, IfxAsclin_ClockSource_noClock); /* disabling the clock */
    IfxAsclin_setFrameMode(asclinSFR, IfxAsclin_FrameMode_initialise);  /* setting the module in Initialise mode */
    IfxAsclin_setPrescaler(asclinSFR, config->btc.prescaler);           /* setting the prescaler */
    IfxAsclin_setClockSource(asclinSFR, config->clockSource);           /* setting the clock source */

    /* baudrate generation in both modes */
    status = (IfxAsclin_Status)IfxAsclin_setBitTiming(asclinSFR, config->brg.baudrate,
        config->btc.oversampling,
        config->bsc.samplePointPosition,
        config->bsc.medianFilter);                                      /* setting the baudrate bit fields to generate the required baudrate */

    /* lin mode initialisation */
    IfxAsclin_setRxInput(asclinSFR, config->alti);                      /* selecting the Rx(alternate) input pin */
    IfxAsclin_setClockSource(asclinSFR, IfxAsclin_ClockSource_noClock); /* disabling the clock again */

    IfxAsclin_setFrameMode(asclinSFR, config->frameMode);               /* setting the module in Lin mode */
    IfxAsclin_setLinMode(asclinSFR, config->linMode);                   /* configuring lin mode of operation (master/slave) */

    /* auto baud rate detection in slave mode */
    if (config->linMode == IfxAsclin_LinMode_slave)
    {
        IfxAsclin_enableAutoBaudrateDetection(asclinSFR, config->brd.abd);                 /* setting the auto baudrate detection (enable/disable) */
        IfxAsclin_setBrdUpperlimt(asclinSFR, config->brd.upperLimit);                      /* setting the upper limit for abd */
        IfxAsclin_setBrdLowerlimt(asclinSFR, config->brd.lowerLimit);                      /* setting the lower limit for abd */
    }

    /* frame control initialisation */
    IfxAsclin_enableParity(asclinSFR, config->frame.parityEnable);                         /* setting parity (enable/disable) */
    IfxAsclin_setParityType(asclinSFR, config->frame.parityType);                          /* setting parity type (odd/even) */
    IfxAsclin_setStopBit(asclinSFR, config->frame.stopBit);                                /* setting the stop bit */
    IfxAsclin_enableCollisionDetection(asclinSFR, config->frame.collisionDetectionEnable); /* setting collision detection (enable/disable) */
    IfxAsclin_setShiftDirection(asclinSFR, config->frame.shiftDir);                        /* setting the shift direction */

    /* data control initialisation */
    IfxAsclin_setDataLength(asclinSFR, config->data.dataLength);                           /* setting the number of bytes to be transfered */
    IfxAsclin_setHeaderResponseSelect(asclinSFR, config->data.headerOnly);                 /* setting the header only or header and response mode */
    IfxAsclin_setLinResponseTimeoutMode(asclinSFR, config->data.responseTimeoutMode);      /* setting the response timeout mode (frame/response) */
    IfxAsclin_setChecksumMode(asclinSFR, config->data.checksum);                           /* setting the checksum mode (classic/enhanced) */
    IfxAsclin_setLinResponseTimeoutThreshold(asclinSFR, config->data.responseTimeout);     /* setting the lin response timeout threshold */

    /* lin control initialisation */
    IfxAsclin_enableHardwareChecksum(asclinSFR, config->lin.csEnable);                     /* setting the hardware checksum (enable/disable) */
    IfxAsclin_setChecksumInjection(asclinSFR, config->lin.csi);                            /* setting checksum injection */

    /* master specific initialisation */
    if (config->linMode == IfxAsclin_LinMode_master)
    {
        IfxAsclin_setIdleDelay(asclinSFR, config->frame.idleDelay);          /* setting idle delay for master */
        IfxAsclin_setLeadDelay(asclinSFR, config->frame.leadDelay);          /* setting lead delay for master mode */
        IfxAsclin_setLinBreakLength(asclinSFR, config->lin.breakLength);     /* setting the break generation length */
        IfxAsclin_setLinHeaderTimeout(asclinSFR, config->lin.headerTimeout); /* setting the header timeout value for master */
        asclin->receiveIdEnable = config->receiveIdEnable;                   /* echoing the selection of receiving Id in its own Rx FIFO */
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
    IfxAsclin_setTxFifoInletWidth(asclinSFR, config->fifo.inWidth);   /* setting Tx FIFO inlet width */
    IfxAsclin_setRxFifoOutletWidth(asclinSFR, config->fifo.outWidth); /* setting Rx FIFO outlet width */
    IfxAsclin_setRxBufferMode(asclinSFR, config->fifo.buffMode);      /* setting Rx FIFO mode */
    IfxAsclin_enableTxFifoOutlet(asclinSFR, FALSE);                   /* disabling Rx FIFO for recieving */
    IfxAsclin_enableRxFifoInlet(asclinSFR, FALSE);                    /* disabling Tx FIFO for transmitting */
    IfxAsclin_flushRxFifo(asclinSFR);                                 /* flushing Rx FIFO */
    IfxAsclin_flushTxFifo(asclinSFR);                                 /* flushing Tx FIFO */

    IfxAsclin_disableAllFlags(asclinSFR);                             /* disable all flags */
    IfxAsclin_clearAllFlags(asclinSFR);                               /* clear all flags */

    /* initialising the Interrupts */
    asclin->isInterruptMode = config->isInterruptMode;
    IfxSrc_Tos  tos  = config->interrupt.typeOfService;
    IfxSrc_VmId vmid = config->interrupt.vmId;

    if (config->isInterruptMode)
    {
        Ifx_ASCLIN_FLAGSENABLE flagsenable;
        flagsenable.U = 0;

#if (IFXDMA_NUM_MODULES > 1U)

        if ((config->interrupt.rxPriority > 0) || (tos == IfxSrc_Tos_dma0) || (tos == IfxSrc_Tos_dma1))
#else

        if ((config->interrupt.rxPriority > 0) || (tos == IfxSrc_Tos_dma0))
#endif
        {
            volatile Ifx_SRC_SRCR *src;
            src = IfxAsclin_getSrcPointerRx(asclinSFR);

            IfxSrc_init(src, tos, config->interrupt.rxPriority, vmid);

            flagsenable.B.RHE = config->interrupt.enabledInterrupt.rxReceivedHeader;
            flagsenable.B.RRE = config->interrupt.enabledInterrupt.rxReceivedResponse;
            IfxSrc_enable(src);
        }

#if (IFXDMA_NUM_MODULES > 1U)

        if ((config->interrupt.txPriority > 0) || (tos == IfxSrc_Tos_dma0) || (tos == IfxSrc_Tos_dma1))
#else

        if ((config->interrupt.txPriority > 0) || (tos == IfxSrc_Tos_dma0))
#endif
        {
            volatile Ifx_SRC_SRCR *src;
            src = IfxAsclin_getSrcPointerTx(asclinSFR);

            IfxSrc_init(src, tos, config->interrupt.txPriority, vmid);

            flagsenable.B.THE = config->interrupt.enabledInterrupt.txTransmittedHeader;
            flagsenable.B.TRE = config->interrupt.enabledInterrupt.txTransmittedResponse;
            IfxSrc_enable(src);
        }

        if (config->interrupt.exPriority > 0) /* these interrupts are not serviced by dma */
        {
            volatile Ifx_SRC_SRCR *src;
            src = IfxAsclin_getSrcPointerEr(asclinSFR);
            IfxSrc_init(src, tos, config->interrupt.exPriority, vmid);

            flagsenable.B.BDE  = config->interrupt.enabledInterrupt.exBreakDetected;
            flagsenable.B.TCE  = config->interrupt.enabledInterrupt.exTransmissionCompleted;

            flagsenable.B.CEE  = config->interrupt.enabledInterrupt.exCollisionDetectionError;
            flagsenable.B.FEE  = config->interrupt.enabledInterrupt.exFramingError;
            flagsenable.B.HTE  = config->interrupt.enabledInterrupt.exHeaderTimeout;
            flagsenable.B.LAE  = config->interrupt.enabledInterrupt.exLinAutobaudDetectionError;
            flagsenable.B.LCE  = config->interrupt.enabledInterrupt.exLinChecksumError;
            flagsenable.B.LPE  = config->interrupt.enabledInterrupt.exLinParityError;
            flagsenable.B.RFOE = config->interrupt.enabledInterrupt.exReceiveFIFOOverflow;
            flagsenable.B.RTE  = config->interrupt.enabledInterrupt.exResponseTimeout;
            flagsenable.B.TFOE = config->interrupt.enabledInterrupt.exTransmitFIFOOverflow;

            IfxSrc_enable(src);
        }

        /* update FLAGSENABLE register in one shot */
        asclinSFR->FLAGSENABLE.U = flagsenable.U;
    }

    /* pin mapping */
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

    IfxAsclin_setClockSource(asclinSFR, config->clockSource); /* setting the clock source */

    asclin->linMode = config->linMode;                        /* echoing the mode of operation to module handler */

    return status;
}


void IfxAsclin_Lin_initModuleConfig(IfxAsclin_Lin_Config *config, Ifx_ASCLIN *asclin)
{
    config->asclin      = asclin;
    config->frameMode   = IfxAsclin_FrameMode_lin;                                             /* LIN mode */
    config->linMode     = IfxAsclin_LinMode_master;                                            /* Lin Master mode */
    config->clockSource = IfxAsclin_ClockSource_ascFastClock;                                  /* Asclin fast clock, fasclinf */
    config->alti        = IfxAsclin_RxInputSelect_0;                                           /* alternate input 0; */

    /* default values for baudrate */
    config->brg.baudrate                   = 19200.0f;                                         /* default baudrate (the fractional dividier setup will be calculated in initModule) */
    /* default Values for Bit Timings */
    config->btc.prescaler                  = 4;                                                /* default prescaler */
    config->btc.oversampling               = IfxAsclin_OversamplingFactor_16;                  /* default oversampling factor */
    /* default Values for Bit sampling */
    config->bsc.filterDepth                = 24U;                                              /* digital glitch filter depth 24 */
    config->bsc.medianFilter               = IfxAsclin_SamplesPerBit_one;                      /* one sample per bit */
    config->bsc.samplePointPosition        = IfxAsclin_SamplePointPosition_3;                  /* sample point position at 3 */
    /* default Values for Frame Control */
    config->frame.parityEnable             = FALSE;                                            /* disable parity */
    config->frame.parityType               = IfxAsclin_ParityType_even;                        /* even parity (if parity enabled) */
    config->frame.stopBit                  = IfxAsclin_StopBit_1;                              /* one stop bit */
    config->frame.shiftDir                 = IfxAsclin_ShiftDirection_lsbFirst;                /* shift diection LSB first */
    config->frame.collisionDetectionEnable = FALSE;
    /* default Values for Data Control */
    config->data.dataLength                = IfxAsclin_DataLength_8;                           /* number of bytes of the response */
    config->data.headerOnly                = IfxAsclin_HeaderResponseSelect_headerAndResponse; /* header and response */
    config->data.responseTimeoutMode       = IfxAsclin_LinResponseTimeoutMode_frameTimeout;    /* frame timeout */
    config->data.checksum                  = IfxAsclin_Checksum_enhanced;                      /* enhanced checksum */
    config->data.responseTimeout           = 255;
    /* default Values for fifo Control */
    config->fifo.outWidth                  = IfxAsclin_RxFifoOutletWidth_1;                    /* 8-bit wide read */
    config->fifo.inWidth                   = IfxAsclin_TxFifoInletWidth_1;                     /* 8-bit wide write */
    config->fifo.buffMode                  = IfxAsclin_ReceiveBufferMode_rxFifo;               /* RxFIFO */
    /* default Values for Lin Control */
    config->lin.csEnable                   = TRUE;                                             /* checksum enable */
    config->lin.csi                        = IfxAsclin_ChecksumInjection_written;              /* 8-bit wide write */

    /* default Values for Interrupt Config */
    config->interrupt.rxPriority    = 0;                                                       /* receive interrupt priority 0 */
    config->interrupt.txPriority    = 0;                                                       /* transmit interrupt priority 0 */
    config->interrupt.exPriority    = 0;                                                       /* error interrupt priority 0 */
    config->interrupt.typeOfService = IfxSrc_Tos_cpu0;                                         /* type of service CPU0 */
    config->interrupt.vmId          = IfxSrc_VmId_0;
    config->isInterruptMode         = FALSE;                                                   /* default is in polling mode */

    /* configuration for master mode */
    {
        config->receiveIdEnable   = FALSE;                 /* receive Id in Rx Fifo after sending */
        config->frame.idleDelay   = IfxAsclin_IdleDelay_2; /* idle dalay 2 bits */
        config->frame.leadDelay   = IfxAsclin_LeadDelay_1; /* lead delay in master 1 bit */
        /* default Values for Lin Control */
        config->lin.breakLength   = 13;                    /* break generation length 13 */
        config->lin.headerTimeout = 56;                    /* header timeout value in master 56 */
    }

    /* configuration for enabling interrupts */
    {
        config->interrupt.enabledInterrupt.rxReceivedHeader            = FALSE;
        config->interrupt.enabledInterrupt.rxReceivedResponse          = FALSE;
        config->interrupt.enabledInterrupt.txTransmittedHeader         = FALSE;
        config->interrupt.enabledInterrupt.txTransmittedResponse       = FALSE;
        config->interrupt.enabledInterrupt.exBreakDetected             = FALSE;
        config->interrupt.enabledInterrupt.exTransmissionCompleted     = FALSE;
        config->interrupt.enabledInterrupt.exHeaderTimeout             = FALSE;
        config->interrupt.enabledInterrupt.exResponseTimeout           = FALSE;
        config->interrupt.enabledInterrupt.exLinParityError            = FALSE;
        config->interrupt.enabledInterrupt.exLinAutobaudDetectionError = FALSE;
        config->interrupt.enabledInterrupt.exLinChecksumError          = FALSE;
        config->interrupt.enabledInterrupt.exFramingError              = FALSE;
        config->interrupt.enabledInterrupt.exCollisionDetectionError   = FALSE;
        config->interrupt.enabledInterrupt.exReceiveFIFOOverflow       = FALSE;
        config->interrupt.enabledInterrupt.exTransmitFIFOOverflow      = FALSE;
    }

    /* pins to null pointer */
    config->pins = NULL_PTR;
}


void IfxAsclin_Lin_receiveHeader(IfxAsclin_Lin *asclin, uint8 *id)
{
    boolean result = 0;

    /* prepare for header reception */
    IfxAsclin_Lin_prepareHeaderReception(asclin);
    /* wait until receive header end acknowledgemnet */
    result |= IfxAsclin_Lin_waitForReceivedHeader(asclin);

    if (result == 1)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
    else
    {
    	/* read the ID byte */
        IfxAsclin_Lin_readHeader(asclin, id);
    }
}


void IfxAsclin_Lin_receiveResponse(IfxAsclin_Lin *asclin, uint8 *data, uint32 length)
{
    boolean result = 0;

    /* prepare the response reception */
    IfxAsclin_Lin_prepareResponseReception(asclin, length);
    /* wait until receive response end acknowledgemnet or an error is occured */
    result |= IfxAsclin_Lin_waitForReceivedResponse(asclin);

    if (result == 1)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
    else
    {
    	/* read the data bytes */
        IfxAsclin_Lin_readResponse(asclin, data, length);
    }
}


void IfxAsclin_Lin_sendHeader(IfxAsclin_Lin *asclin, uint8 *id)
{
    boolean     result    = 0;

    /* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;
    /* clearing all flags */
    IfxAsclin_clearAllFlags(asclinSFR);

    if (asclin->receiveIdEnable)                       /* if receiving the sent id byte into its own Rx FIFO is selected */
    {
    	/* flushing Rx FIFO */
        IfxAsclin_flushRxFifo(asclinSFR);
        /* enabling Rx FIFO */
        IfxAsclin_enableRxFifoInlet(asclinSFR, TRUE);
    }
    else
    {
    	/* disabling Rx FIFO */
        IfxAsclin_enableRxFifoInlet(asclinSFR, FALSE);
    }

    /* flushing Tx FIFO */
    IfxAsclin_flushTxFifo(asclinSFR);
    /* enabling Tx FIFO for transmitting */
    IfxAsclin_enableTxFifoOutlet(asclinSFR, TRUE);
    /* writing the ID byte */
    IfxAsclin_write8(asclinSFR, id, 1U);
    /* setting THRQS flag */
    IfxAsclin_setTransmitHeaderRequestFlag(asclinSFR);

    if (asclin->isInterruptMode == FALSE)                         /* only for Polling Mode */
    {
    	/* waiting until transmit header end acknowledgemnet */
        result |= IfxAsclin_Lin_waitForTransmittedHeader(asclin);

        if (result == 1)
        {
            IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
        }
    }
    else
    {
        IfxAsclin_Lin_clearFlagsStatus(asclin);
        asclin->linFrameData.flags.txHeaderInProgress    = TRUE;
        asclin->linFrameData.flags.txHeaderErrorOccurred = FALSE;
    }
}


void IfxAsclin_Lin_sendResponse(IfxAsclin_Lin *asclin, uint8 *data, uint32 length)
{
    boolean     result    = 0;

    /* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* set number of bytes to be transfered */
    IfxAsclin_setDataLength(asclinSFR, (IfxAsclin_DataLength)(length - 1));
    /* clear all flags */
    IfxAsclin_clearAllFlags(asclinSFR);
    /* flushing Tx FIFO */
    IfxAsclin_flushTxFifo(asclinSFR);
    /* disable Rx FIFO */
    IfxAsclin_enableRxFifoInlet(asclinSFR, FALSE);
    /* enable Tx FIFO for transmitting */
    IfxAsclin_enableTxFifoOutlet(asclinSFR, TRUE);
    /* write the data bytes; */
    IfxAsclin_write8(asclinSFR, data, length);
    /* set TRRQS flag */
    IfxAsclin_setTransmitResponseRequestFlag(asclinSFR);
    /* wait until transmit response end acknowledgemnet */
    result |= IfxAsclin_Lin_waitForTransmittedResponse(asclin);

    if (result == 1)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


boolean IfxAsclin_Lin_waitForReceivedHeader(IfxAsclin_Lin *asclin)
{
    boolean result = 0;

    /* clear all aknowledgement and error flags status */
    IfxAsclin_Lin_clearFlagsStatus(asclin);

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

    /* clear all aknowledgement and error flags status */
    IfxAsclin_Lin_clearFlagsStatus(asclin);

    /* wait until receive response end acknowledgemnet has been detected */
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

    /* clear all aknowledgement and error flags status */
    IfxAsclin_Lin_clearFlagsStatus(asclin);

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

    /* clear all aknowledgement and error flags status */
    IfxAsclin_Lin_clearFlagsStatus(asclin);

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


void IfxAsclin_Lin_isrError(IfxAsclin_Lin *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* store and clear the flags */
    if (IfxAsclin_getLinParityErrorFlagStatus(asclinSFR))
    {
        IfxAsclin_clearLinParityErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linParityError = 1;
    }

    if (IfxAsclin_getFrameErrorFlagStatus(asclinSFR))
    {
        IfxAsclin_clearFrameErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.frameError = 1;
    }

    if (IfxAsclin_getRxFifoOverflowFlagStatus(asclinSFR))
    {
        IfxAsclin_clearRxFifoOverflowFlag(asclinSFR);
        asclin->errorFlagsStatus.rxFifoOverflow = 1;
    }

    if (IfxAsclin_getTxFifoOverflowFlagStatus(asclinSFR))
    {
        IfxAsclin_clearTxFifoOverflowFlag(asclinSFR);
        asclin->errorFlagsStatus.txFifoOverflow = 1;
    }

    if (IfxAsclin_getHeaderTimeoutFlagStatus(asclinSFR))
    {
        IfxAsclin_clearHeaderTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.headerTimeout = 1;
    }

    if (IfxAsclin_getResponseTimeoutFlagStatus(asclinSFR))
    {
        IfxAsclin_clearResponseTimeoutFlag(asclinSFR);
        asclin->errorFlagsStatus.responseTimeout = 1;
    }

    if (IfxAsclin_getBreakDetectedFlagStatus(asclinSFR))
    {
        IfxAsclin_clearBreakDetectedFlag(asclinSFR);
        asclin->errorFlagsStatus.breakDetected = 1;
    }

    if (IfxAsclin_getLinAutoBaudDetectionErrorFlagStatus(asclinSFR))
    {
        IfxAsclin_clearLinAutoBaudDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linAutobaudDetectionError = 1;
    }

    if (IfxAsclin_getLinChecksumErrorFlagStatus(asclinSFR))
    {
        IfxAsclin_clearLinChecksumErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.linChecksumError = 1;
    }

    if (IfxAsclin_getCollisionDetectionErrorFlagStatus(asclinSFR))
    {
        IfxAsclin_clearCollisionDetectionErrorFlag(asclinSFR);
        asclin->errorFlagsStatus.collisionDetectionError = 1;
    }

    if (IfxAsclin_getTransmissionCompletedFlagStatus(asclinSFR))
    {
        IfxAsclin_clearTransmissionCompletedFlag(asclinSFR);
        asclin->acknowledgmentFlags.txCompleted = 1;
    }

    /* update acknowledgment flags */
    if ((asclin->linFrameData.flags.txHeaderInProgress == 1)
        && ((asclin->errorFlagsStatus.headerTimeout == 1)
            || (asclin->errorFlagsStatus.collisionDetectionError == 1)
            || (asclin->errorFlagsStatus.frameError == 1)
            || (asclin->errorFlagsStatus.linParityError == 1)))
    {
        asclin->linFrameData.flags.txHeaderErrorOccurred = TRUE;
        asclin->acknowledgmentFlags.txHeaderEnd          = 1;
        asclin->linFrameData.flags.txHeaderInProgress    = FALSE;
    }

    if ((asclin->linFrameData.flags.txResponseInProgress == 1)
        && ((asclin->errorFlagsStatus.txFifoOverflow == 1)
            || (asclin->errorFlagsStatus.collisionDetectionError == 1)
            || (asclin->errorFlagsStatus.responseTimeout == 1)
            || (asclin->errorFlagsStatus.breakDetected == 1)))
    {
        asclin->linFrameData.flags.txResponseErrorOccurred = TRUE;
        asclin->acknowledgmentFlags.txResponseEnd          = 1;
        asclin->linFrameData.flags.txResponseInProgress    = FALSE;
    }

    if ((asclin->linFrameData.flags.rxHeaderInProgress == 1)
        && ((asclin->errorFlagsStatus.rxFifoOverflow == 1)
            || (asclin->errorFlagsStatus.headerTimeout == 1)
            || (asclin->errorFlagsStatus.collisionDetectionError == 1)
            || (asclin->errorFlagsStatus.frameError == 1)
            || (asclin->errorFlagsStatus.linAutobaudDetectionError == 1)
            || (asclin->errorFlagsStatus.linParityError == 1)))
    {
        asclin->linFrameData.flags.rxHeaderErrorOccurred = TRUE;
        asclin->acknowledgmentFlags.rxHeaderEnd          = 1;
        asclin->linFrameData.flags.rxHeaderInProgress    = FALSE;
    }

    if ((asclin->linFrameData.flags.rxResponseInProgress == 1)
        && ((asclin->errorFlagsStatus.rxFifoOverflow == 1)
            || (asclin->errorFlagsStatus.collisionDetectionError == 1)
            || (asclin->errorFlagsStatus.frameError == 1)
            || (asclin->errorFlagsStatus.linChecksumError == 1)
            || (asclin->errorFlagsStatus.responseTimeout == 1)
            || (asclin->errorFlagsStatus.breakDetected == 1)))
    {
        asclin->linFrameData.flags.rxResponseErrorOccurred = TRUE;
        asclin->acknowledgmentFlags.rxResponseEnd          = 1;
        asclin->linFrameData.flags.rxResponseInProgress    = FALSE;
    }
}


void IfxAsclin_Lin_isrReceive(IfxAsclin_Lin *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    if (IfxAsclin_getRxHeaderEndFlagStatus(asclinSFR))
    {
        IfxAsclin_clearRxHeaderEndFlag(asclinSFR);
        IfxAsclin_Lin_readHeader(asclin, &(asclin->linFrameData.headerID)); /* read the ID byte */
        asclin->acknowledgmentFlags.rxHeaderEnd       = 1;
        asclin->linFrameData.flags.rxHeaderInProgress = FALSE;
        asclinSFR->TXFIFOCON.B.ENO                    = 0;                  /* TX FIFO Outlet is disabled */
    }

    if (IfxAsclin_getRxResponseEndFlagStatus(asclinSFR))
    {
        IfxAsclin_clearRxResponseEndFlag(asclinSFR);
        IfxAsclin_Lin_readResponse(asclin, &(asclin->linFrameData.rxResponseData[0]), (asclin->linFrameData.rxResponseLength)); /* read the data bytes */
        asclin->acknowledgmentFlags.rxResponseEnd       = 1;
        asclin->linFrameData.flags.rxResponseInProgress = FALSE;
    }
}


void IfxAsclin_Lin_isrTransmit(IfxAsclin_Lin *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* clear H/w Flag and update S/w Flags */
    if (IfxAsclin_getTxHeaderEndFlagStatus(asclinSFR))
    {
        IfxAsclin_clearTxHeaderEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.txHeaderEnd       = 1;
        asclin->linFrameData.flags.txHeaderInProgress = FALSE;
    }

    if (IfxAsclin_getTxResponseEndFlagStatus(asclinSFR))
    {
        IfxAsclin_clearTxResponseEndFlag(asclinSFR);
        asclin->acknowledgmentFlags.txResponseEnd       = 1;
        asclin->linFrameData.flags.txResponseInProgress = FALSE;
    }
}


void IfxAsclin_Lin_sendFrame(IfxAsclin_Lin *asclin, IfxAsclin_Lin_PduType *pduptr)
{
	 /* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;
    /* setting the checksum mode (classic/enhanced) */
    IfxAsclin_setChecksumMode(asclinSFR, pduptr->checksumMode);
    asclin->linFrameData.headerID = pduptr->pid;

    if (pduptr->direction == IfxAsclin_Lin_Direction_TransmitHeader)
    {
        asclin->linFrameData.flags.txSendResponse   = FALSE;
        asclin->linFrameData.txResponseLength       = 0;
        asclin->linFrameData.flags.txSendHeaderOnly = TRUE;

        /* enable Interrupt flags for Header Transmission */
        Ifx_ASCLIN_FLAGSENABLE flagsenable;
        flagsenable.U            = 0;
        flagsenable.B.THE        = 1;
        flagsenable.B.HTE        = 1;
        flagsenable.B.CEE        = 1;
        flagsenable.B.FEE        = 1;
        flagsenable.B.LPE        = 1;
        asclinSFR->FLAGSENABLE.U = flagsenable.U;

        IfxAsclin_Lin_sendHeader(asclin, &(pduptr->pid));
    }

    else if ((pduptr->direction == IfxAsclin_Lin_Direction_TransmitHeaderAndResponse) || (pduptr->direction == IfxAsclin_Lin_Direction_TransmitHeaderAndReceiveResponse))
    {
    	/* set number of bytes to be transfered */
        IfxAsclin_setDataLength(asclinSFR, (IfxAsclin_DataLength)(pduptr->dataLength - 1));

        /* configure RXFIFO */
        Ifx_ASCLIN_RXFIFOCON rxfifocon;
        rxfifocon.U            = asclinSFR->RXFIFOCON.U;

        rxfifocon.B.BUF        = 0; /* RX in FIFO Mode */
        rxfifocon.B.FLUSH      = 1; /* Empty Rx Fifo */
        rxfifocon.B.ENI        = 1; /* RX FIFO Inlet is enabled */

        asclinSFR->RXFIFOCON.U = rxfifocon.U;

        /* configure TXFIFO */
        Ifx_ASCLIN_TXFIFOCON txfifocon;
        txfifocon.U            = asclinSFR->TXFIFOCON.U;

        txfifocon.B.FLUSH      = 1; /* Empty Tx Fifo */
        txfifocon.B.ENO        = 1; /* TX FIFO Outlet is enabled */

        asclinSFR->TXFIFOCON.U = txfifocon.U;

        /* clear interrupt event flags */
        IfxAsclin_clearAllFlags(asclinSFR);	/* clearing all flags */
        IfxAsclin_Lin_clearFlagsStatus(asclin);

        Ifx_ASCLIN_FLAGSENABLE flagsenable;
        flagsenable.U = 0;

        if (pduptr->direction == IfxAsclin_Lin_Direction_TransmitHeaderAndResponse)
        {
            /* enable Tx interrupts */
            flagsenable.B.THE = 1;
            flagsenable.B.TRE = 1;
            flagsenable.B.HTE = 1;

            /* enable Ex interrupts */
            flagsenable.B.TFOE                                 = 1;
            flagsenable.B.CEE                                  = 1;
            flagsenable.B.FEE                                  = 1;
            flagsenable.B.RTE                                  = 1;
            flagsenable.B.LPE                                  = 1;
            flagsenable.B.BDE                                  = 1;

            asclin->linFrameData.flags.txSendResponse          = TRUE;
            asclin->linFrameData.flags.txSendHeaderOnly        = FALSE;
            asclin->linFrameData.txResponseLength              = pduptr->dataLength;

            asclin->linFrameData.flags.txHeaderInProgress      = TRUE;
            asclin->linFrameData.flags.txHeaderErrorOccurred   = FALSE;
            asclin->linFrameData.flags.txResponseInProgress    = TRUE;
            asclin->linFrameData.flags.txResponseErrorOccurred = FALSE;
        }
        else if (pduptr->direction == IfxAsclin_Lin_Direction_TransmitHeaderAndReceiveResponse)
        {
            /* enable Rx interrupts */
            flagsenable.B.RRE = 1;
            flagsenable.B.THE = 1;
            flagsenable.B.RHE = 1;
            flagsenable.B.HTE = 1;

            /* enable Ex interrupts */
            flagsenable.B.RFOE                                 = 1;
            flagsenable.B.CEE                                  = 1;
            flagsenable.B.FEE                                  = 1;
            flagsenable.B.RTE                                  = 1;
            flagsenable.B.LCE                                  = 1;
            flagsenable.B.BDE                                  = 1;

            asclinSFR->RXFIFOCON.B.ENI                         = 1; /* RX FIFO Inlet is enabled */

            asclin->linFrameData.flags.txSendResponse          = TRUE;
            asclin->linFrameData.flags.txSendHeaderOnly        = FALSE;
            asclin->linFrameData.rxResponseLength              = pduptr->dataLength;
            asclin->linFrameData.flags.txHeaderInProgress      = TRUE;
            asclin->linFrameData.flags.txHeaderErrorOccurred   = FALSE;
            asclin->linFrameData.flags.rxResponseInProgress    = TRUE;
            asclin->linFrameData.flags.rxResponseErrorOccurred = FALSE;
        }

        asclinSFR->FLAGSENABLE.U = flagsenable.U;

        IfxAsclin_write8(asclinSFR, &(pduptr->pid), 1U);                            /* writing the ID byte */

        if (pduptr->direction == IfxAsclin_Lin_Direction_TransmitHeaderAndResponse)
        {
            IfxAsclin_write8(asclinSFR, pduptr->dataPtr, pduptr->dataLength);       /* writing data bytes */

            Ifx_ASCLIN_FLAGSSET flagsset;
            flagsset.U            = asclinSFR->FLAGSSET.U;

            flagsset.B.THRQS      = 1;
            flagsset.B.TRRQS      = 1;

            asclinSFR->FLAGSSET.U = flagsset.U;
        }

        else if (pduptr->direction == IfxAsclin_Lin_Direction_TransmitHeaderAndReceiveResponse)
        {
            //asclinSFR->RXFIFOCON.B.ENI = 1; /*RX FIFO Inlet is enabled*/
            asclinSFR->FLAGSSET.B.THRQS = 1;
        }
    }
}
