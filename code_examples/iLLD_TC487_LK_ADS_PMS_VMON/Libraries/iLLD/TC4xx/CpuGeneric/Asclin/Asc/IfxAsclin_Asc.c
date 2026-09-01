/**
 * \file IfxAsclin_Asc.c
 * \brief ASCLIN ASC details
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

#include "IfxAsclin_Asc.h"
#include "string.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

uint8 IfxAsclin_Asc_blockingRead(IfxAsclin_Asc *asclin)
{
    Ifx_SizeT count = 1;
    uint8     data;

    while (IfxAsclin_Asc_read(asclin, &data, &count, TIME_INFINITE) != TRUE)
    {}

    return data;
}


boolean IfxAsclin_Asc_blockingWrite(IfxAsclin_Asc *asclin, uint8 data)
{
    Ifx_SizeT count = 1;

    return IfxAsclin_Asc_write(asclin, &data, &count, TIME_INFINITE);
}


boolean IfxAsclin_Asc_canReadCount(IfxAsclin_Asc *asclin, Ifx_SizeT count, Ifx_TickTime timeout)
{
    return Ifx_Fifo_canReadCount(asclin->rx, count, timeout);
}


boolean IfxAsclin_Asc_canWriteCount(IfxAsclin_Asc *asclin, Ifx_SizeT count, Ifx_TickTime timeout)
{
    return Ifx_Fifo_canWriteCount(asclin->tx, count, timeout);
}


void IfxAsclin_Asc_clearRx(IfxAsclin_Asc *asclin)
{
    IfxAsclin_flushRxFifo(asclin->asclin);
    Ifx_Fifo_clear(asclin->rx);
}


void IfxAsclin_Asc_clearTx(IfxAsclin_Asc *asclin)
{
    Ifx_Fifo_clear(asclin->tx);
    IfxAsclin_flushTxFifo(asclin->asclin);
}


void IfxAsclin_Asc_disableModule(IfxAsclin_Asc *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* disabling the module */
    IfxAsclin_setDisableModuleRequest(asclinSFR);
}


boolean IfxAsclin_Asc_flushTx(IfxAsclin_Asc *asclin, Ifx_TickTime timeout)
{
    Ifx_TickTime deadline = Ifx_getDeadLine(timeout);
    boolean      result;

    /* flush the software FIFO */
    result = Ifx_Fifo_flush(asclin->tx, timeout);

    if (result)
    {
        /* flush the hardware FIFO (wait until all bytes have been transmitted) */
        do
        {
            result = IfxAsclin_getTxFifoFillLevel(asclin->asclin) == 0;
        } while (!result && ! Ifx_isDeadLine(deadline));
    }

    return result;
}


sint32 IfxAsclin_Asc_getReadCount(IfxAsclin_Asc *asclin)
{
    return Ifx_Fifo_readCount(asclin->rx);
}


volatile boolean *IfxAsclin_Asc_getReadEvent(IfxAsclin_Asc *asclin)
{
    return &asclin->rx->eventWriter;
}


uint32 IfxAsclin_Asc_getSendCount(IfxAsclin_Asc *asclin)
{
    return asclin->sendCount;
}


Ifx_TickTime IfxAsclin_Asc_getTxTimeStamp(IfxAsclin_Asc *asclin)
{
    return asclin->txTimestamp;
}


sint32 IfxAsclin_Asc_getWriteCount(IfxAsclin_Asc *asclin)
{
    return Ifx_Fifo_writeCount(asclin->tx);
}


volatile boolean *IfxAsclin_Asc_getWriteEvent(IfxAsclin_Asc *asclin)
{
    return &asclin->tx->eventWriter;
}


IfxAsclin_Status IfxAsclin_Asc_initModule(IfxAsclin_Asc *asclin, const IfxAsclin_Asc_Config *config)
{
    Ifx_ASCLIN      *asclinSFR = config->asclin;                        /* pointer to ASCLIN registers */
    IfxAsclin_Status status    = IfxAsclin_Status_noError;

    /* adding register pointer to module handler */
    asclin->asclin = asclinSFR;

    /* enabling the module */
    IfxAsclin_enableModule(asclinSFR);
    /* disabling the clock */
    IfxAsclin_setClockSource(asclinSFR, IfxAsclin_ClockSource_noClock);
    /* setting the module in Initialise mode */
    IfxAsclin_setFrameMode(asclinSFR, IfxAsclin_FrameMode_initialise);
    /* sets the prescaler */
    IfxAsclin_setPrescaler(asclinSFR, config->baudrate.prescaler);
    /* temporary set the clock source for baudrate configuration */
    IfxAsclin_setClockSource(asclinSFR, config->clockSource);
    /* setting the baudrate bit fields to generate the required baudrate */
    status = (IfxAsclin_Status)IfxAsclin_setBitTiming(asclinSFR,
        config->baudrate.baudrate,
        config->baudrate.oversampling,
        config->bitTiming.samplePointPosition,
        config->bitTiming.medianFilter);
    /* disabling the clock again*/
    IfxAsclin_setClockSource(asclinSFR, IfxAsclin_ClockSource_noClock);

    /* selecting the loopback mode */
    IfxAsclin_enableLoopBackMode(asclinSFR, config->loopBack);
    /* setting parity enable */
    IfxAsclin_enableParity(asclinSFR, config->frame.parityBit);
    /* setting parity type (odd/even) */
    IfxAsclin_setParityType(asclinSFR, config->frame.parityType);
    /* setting the stop bit */
    IfxAsclin_setStopBit(asclinSFR, config->frame.stopBit);
    /* setting the shift direction */
    IfxAsclin_setShiftDirection(asclinSFR, config->frame.shiftDir);
    /* setting the data length */
    IfxAsclin_setDataLength(asclinSFR, config->frame.dataLength);
    /* setting Tx FIFO inlet width */
    IfxAsclin_setTxFifoInletWidth(asclinSFR, config->fifo.inWidth);
    /* setting Tx FIFO inlet width */
    IfxAsclin_setRxFifoOutletWidth(asclinSFR, config->fifo.outWidth);
    /* setting Rx FIFO outlet width */
    IfxAsclin_setIdleDelay(asclinSFR, config->frame.idleDelay);
    /* setting idle delay */
    IfxAsclin_setTxFifoInterruptLevel(asclinSFR, config->fifo.txFifoInterruptLevel);
    /* setting Tx FIFO level at which a Tx interrupt will be triggered */
    IfxAsclin_setRxFifoInterruptLevel(asclinSFR, config->fifo.rxFifoInterruptLevel);
    /* setting Rx FIFO interrupt level at which a Rx interrupt will be triggered */
    IfxAsclin_setTxFifoInterruptMode(asclinSFR, config->fifo.txFifoInterruptMode);
    /* setting Tx FIFO interrupt generation mode */
    IfxAsclin_setRxFifoInterruptMode(asclinSFR, config->fifo.rxFifoInterruptMode);
    /* setting the frame mode */
    IfxAsclin_setFrameMode(asclinSFR, config->frame.frameMode);
    /* setting the Trigger Source for the circulation Buffer */
    IfxAsclin_setTriggerSource(asclinSFR, config->triggerSource);

    /* pin mapping */
    const IfxAsclin_Asc_Pins *pins = config->pins;

    if (pins != NULL_PTR)
    {
        IfxAsclin_Cts_In *cts = pins->cts;

        if (cts != NULL_PTR)
        {
            IfxAsclin_initCtsPin(cts, pins->ctsMode, pins->pinDriver);
        }

        IfxAsclin_Rx_In *rx = pins->rx;

        if (rx != NULL_PTR)
        {
            IfxAsclin_initRxPin(rx, pins->rxMode, pins->pinDriver);
        }

        IfxAsclin_Rts_Out *rts = pins->rts;

        if (rts != NULL_PTR)
        {
            IfxAsclin_initRtsPin(rts, pins->rtsMode, pins->pinDriver);
        }

        IfxAsclin_Tx_Out *tx = pins->tx;

        if (tx != NULL_PTR)
        {
            IfxAsclin_initTxPin(tx, pins->txMode, pins->pinDriver);
        }
    }

    /* select the clock source */
    IfxAsclin_setClockSource(asclinSFR, config->clockSource);

    /* disable all flags */
    IfxAsclin_disableAllFlags(asclinSFR);
    /* clear all flags */
    IfxAsclin_clearAllFlags(asclinSFR);

    /* HW error flags */
    asclin->errorFlags.ALL = 0;

    if (config->errorFlags.flags.parityError)
    {
        IfxAsclin_enableParityErrorFlag(asclinSFR, TRUE);
    }

    if (config->errorFlags.flags.frameError)
    {
        IfxAsclin_enableFrameErrorFlag(asclinSFR, TRUE);
    }

    if (config->errorFlags.flags.rxFifoOverflow)
    {
        IfxAsclin_enableRxFifoOverflowFlag(asclinSFR, TRUE);
    }

    if (config->errorFlags.flags.rxFifoUnderflow)
    {
        IfxAsclin_enableRxFifoUnderflowFlag(asclinSFR, TRUE);
    }

    if (config->errorFlags.flags.txFifoOverflow)
    {
        IfxAsclin_enableTxFifoOverflowFlag(asclinSFR, TRUE);
    }

    if (config->errorFlags.flags.txOverloadOfMultipleTriggers)
    {
        IfxAsclin_enableTxOverloadOfMultipleTriggers(asclinSFR, TRUE);
    }

    if (config->errorFlags.flags.txFifoEmpty)
    {
        IfxAsclin_enableTxFifoEmpty(asclinSFR, TRUE);
    }

    /* transmission flags */
    asclin->rxSwFifoOverflow = FALSE;
    asclin->txInProgress     = FALSE;

    /* buffer mode */
    Ifx_SizeT elementSize;
    asclin->dataBufferMode = config->dataBufferMode;
    asclin->txTimestamp    = 0;
    asclin->isrCount       = 0;
    asclin->sendCount      = 0;

    switch (asclin->dataBufferMode)
    {
    case Ifx_DataBufferMode_normal:
        elementSize = 1;
        break;
    case Ifx_DataBufferMode_timeStampSingle:
        elementSize = sizeof(Ifx_DataBufferMode_TimeStampSingle);
        break;
    default:
        elementSize = 0;
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
        break;
    }

    /* SW Fifos */
    if (config->txBuffer != NULL_PTR)
    {
        asclin->tx = Ifx_Fifo_init(config->txBuffer, config->txBufferSize, elementSize);
    }
    else
    {
        /* application has not provided any pointer to a buffer */
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
        /* update the status as configuration failure */
        status = IfxAsclin_Status_configurationError;
    }

    if (config->rxBuffer != NULL_PTR)
    {
        asclin->rx = Ifx_Fifo_init(config->rxBuffer, config->rxBufferSize, elementSize);
    }
    else
    {
        /* application has not provided any pointer to a buffer */
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
        /* Update the status as configuration failure */
        status = IfxAsclin_Status_configurationError;
    }

    /* initialising the interrupts */
    IfxSrc_Tos  tos  = config->interrupt.typeOfService;
    IfxSrc_VmId vmid = config->interrupt.vmId;
#if (IFXDMA_NUM_MODULES > 1U)

    if ((config->interrupt.rxPriority > 0) || (tos == IfxSrc_Tos_dma0) || (tos == IfxSrc_Tos_dma1))
#else

    if ((config->interrupt.rxPriority > 0) || (tos == IfxSrc_Tos_dma0))
#endif
    {
        volatile Ifx_SRC_SRCR *src;
        src = IfxAsclin_getSrcPointerRx(asclinSFR);
        IfxSrc_init(src, tos, config->interrupt.rxPriority, vmid);
        IfxAsclin_enableRxFifoFillLevelFlag(asclinSFR, TRUE);
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

        IfxAsclin_enableTxFifoFillLevelFlag(asclinSFR, TRUE);
        IfxSrc_enable(src);
    }

    if (config->interrupt.erPriority > 0) /* these interrupts are not serviced by dma */
    {
        volatile Ifx_SRC_SRCR *src;
        src = IfxAsclin_getSrcPointerEr(asclinSFR);
        IfxSrc_init(src, tos, config->interrupt.erPriority, vmid);
        IfxAsclin_enableParityErrorFlag(asclinSFR, TRUE);
        IfxSrc_enable(src);
    }

    /* enable transfers */
    /* enabling Rx FIFO for recieving */
    IfxAsclin_enableRxFifoInlet(asclinSFR, TRUE);
    /* enabling Tx FIFO for transmitting */
    IfxAsclin_enableTxFifoOutlet(asclinSFR, TRUE);

    /* flushing Rx FIFO */
    IfxAsclin_flushRxFifo(asclinSFR);
    /* flushing Tx FIFO */
    IfxAsclin_flushTxFifo(asclinSFR);

    return status;
}


void IfxAsclin_Asc_initModuleConfig(IfxAsclin_Asc_Config *config, Ifx_ASCLIN *asclin)
{
    config->asclin = asclin;

    /* loop back disabled */
    config->loopBack = FALSE;                                                  /* no loop back */

    /* default values for baudrate */
    config->clockSource           = IfxAsclin_ClockSource_ascFastClock;        /* asclin fast clock, fasclinf */
    config->baudrate.prescaler    = 1;                                         /* default prescaler */
    config->baudrate.baudrate     = 115200;                                    /* default baudrate (the fractional dividier setup will be calculated in initModule */
    config->baudrate.oversampling = IfxAsclin_OversamplingFactor_4;            /* default oversampling factor */

    /* default Values for Bit Timings */
    config->bitTiming.medianFilter        = IfxAsclin_SamplesPerBit_one;       /* one sample per bit */
    config->bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_3;   /* sample point position at 3 */
    /* default Values for Frame Control */
    config->frame.idleDelay               = IfxAsclin_IdleDelay_0;             /* no idle delay */
    config->frame.stopBit                 = IfxAsclin_StopBit_1;               /* one stop bit */
    config->frame.frameMode               = IfxAsclin_FrameMode_asc;           /* ASC mode */
    config->frame.shiftDir                = IfxAsclin_ShiftDirection_lsbFirst; /* shift diection LSB first */
    config->frame.parityBit               = FALSE;                             /* disable parity */
    config->frame.parityType              = IfxAsclin_ParityType_even;         /* even parity (if parity enabled) */
    config->frame.dataLength              = IfxAsclin_DataLength_8;            /* number of bits per transfer 8 */

    /* default Values for Fifo Control */
    config->fifo.inWidth              = IfxAsclin_TxFifoInletWidth_1;          /* 8-bit wide write */
    config->fifo.outWidth             = IfxAsclin_RxFifoOutletWidth_1;         /* 8-bit wide read */
    config->fifo.txFifoInterruptLevel = IfxAsclin_TxFifoInterruptLevel_0;      /* txFifoInterruptLevel = 0. optimised to write upto 16 bytes at a time */
    config->fifo.rxFifoInterruptLevel = IfxAsclin_RxFifoInterruptLevel_1;
    config->fifo.buffMode             = IfxAsclin_ReceiveBufferMode_rxFifo;    /* RxFIFO */
    config->fifo.txFifoInterruptMode  = IfxAsclin_FifoInterruptMode_combined;
    config->fifo.rxFifoInterruptMode  = IfxAsclin_FifoInterruptMode_combined;

    /* default Values for Interrupt Config */
    config->interrupt.rxPriority    = 0;                                /* receive interrupt priority 0 */
    config->interrupt.txPriority    = 0;                                /* transmit interrupt priority 0 */
    config->interrupt.erPriority    = 0;                                /* error interrupt priority 0 */
    config->interrupt.typeOfService = IfxSrc_Tos_cpu0;                  /* type of service CPU0 */
    config->interrupt.vmId          = IfxSrc_VmId_0;
    /* enable error flags */
    config->errorFlags.ALL          = ~0;                               /* all error flags enabled */

    /* init pointers */
    config->pins           = NULL_PTR;                                  /* pins to null pointer */
    config->rxBuffer       = NULL_PTR;                                  /* Rx Fifo buffer */
    config->txBuffer       = NULL_PTR;                                  /* Tx Fifo buffer */

    config->txBufferSize   = 0;                                         /* Rx Fifo buffer size */
    config->rxBufferSize   = 0;                                         /* Rx Fifo buffer size */

    config->dataBufferMode = Ifx_DataBufferMode_normal;

    config->triggerSource  = IfxAsclin_TriggerSource_disabled;  /* Default Trigger Source Disabled */
}


void IfxAsclin_Asc_initiateTransmission(IfxAsclin_Asc *asclin)
{
    if (asclin->txInProgress == FALSE)     /* send first byte: send init */
    {
        if (Ifx_Fifo_isEmpty(asclin->tx) == FALSE)
        {
            uint8 data;
            asclin->txInProgress = TRUE;

            switch (asclin->dataBufferMode)
            {
            case Ifx_DataBufferMode_normal:
            {
                Ifx_Fifo_read(asclin->tx, &data, 1, TIME_NULL);
            }
            break;
            case Ifx_DataBufferMode_timeStampSingle:
            {
                Ifx_DataBufferMode_TimeStampSingle packedData;
                Ifx_Fifo_read(asclin->tx, &packedData, sizeof(packedData), TIME_NULL);
                data = packedData.data;
            }
            break;
            }

            IfxAsclin_write8(asclin->asclin, &data, 1);
            asclin->sendCount++;
        }
    }
}


void IfxAsclin_Asc_isrError(IfxAsclin_Asc *asclin)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN *asclinSFR = asclin->asclin;

    /* store all the flags in the variable */
    if (IfxAsclin_getParityErrorFlagStatus(asclinSFR))
    {
        IfxAsclin_clearParityErrorFlag(asclinSFR);
        asclin->errorFlags.flags.parityError = 1;
    }

    if (IfxAsclin_getFrameErrorFlagStatus(asclinSFR))
    {
        IfxAsclin_clearFrameErrorFlag(asclinSFR);
        asclin->errorFlags.flags.frameError = 1;
    }

    if (IfxAsclin_getRxFifoOverflowFlagStatus(asclinSFR))
    {
        IfxAsclin_clearRxFifoOverflowFlag(asclinSFR);
        asclin->errorFlags.flags.rxFifoOverflow = 1;
    }

    if (IfxAsclin_getRxFifoUnderflowFlagStatus(asclinSFR))
    {
        IfxAsclin_clearRxFifoUnderflowFlag(asclinSFR);
        asclin->errorFlags.flags.rxFifoUnderflow = 1;
    }

    if (IfxAsclin_getTxFifoOverflowFlagStatus(asclinSFR))
    {
        IfxAsclin_clearTxFifoOverflowFlag(asclinSFR);
        asclin->errorFlags.flags.txFifoOverflow = 1;
    }

    if (IfxAsclin_getTxOverloadOfMultipleTriggersStatus(asclinSFR))
    {
        IfxAsclin_clearTxOverloadOfMultipleTriggersFlag(asclinSFR);
        asclin->errorFlags.flags.txOverloadOfMultipleTriggers = 1;
    }

    if (IfxAsclin_getTxFifoEmptyStatus(asclinSFR))
    {
        IfxAsclin_clearTxFifoEmptyFlag(asclinSFR);
        asclin->errorFlags.flags.txFifoEmpty = 1;
    }
}


void IfxAsclin_Asc_isrReceive(IfxAsclin_Asc *asclin)
{
    uint8 ascData[16]; /* FIFO size is 16 bytes */

    switch (asclin->dataBufferMode)
    {
    case Ifx_DataBufferMode_normal:
    {
        uint8 count;
        count = IfxAsclin_getRxFifoFillLevel(asclin->asclin);
        IfxAsclin_read8(asclin->asclin, &ascData[0], count);

        if (Ifx_Fifo_write(asclin->rx, &ascData[0], count, TIME_NULL) != 0)
        {
            /* receive buffer is full, data is discard */
            asclin->rxSwFifoOverflow = TRUE;
        }

        break;
    }
    case Ifx_DataBufferMode_timeStampSingle:
    {
        Ifx_DataBufferMode_TimeStampSingle packedData;

        while (IfxAsclin_getRxFifoFillLevel(asclin->asclin) > 0)
        {
            packedData.timestamp = Ifx_now();
            IfxAsclin_read8(asclin->asclin, &ascData[0], 1);
            packedData.data      = ascData[0];

            if (Ifx_Fifo_write(asclin->rx, &packedData, sizeof(packedData), TIME_NULL) != 0)
            {
                /* receive buffer is full, data is discard */
                asclin->rxSwFifoOverflow = TRUE;
            }
        }
    }
    break;
    }
}


void IfxAsclin_Asc_isrTransmit(IfxAsclin_Asc *asclin)
{
    asclin->txTimestamp = Ifx_now();
    asclin->isrCount++;

    if (asclin->asclin->TXFIFOCON.B.FM != IfxAsclin_FifoInterruptMode_circular)
    {
        if (Ifx_Fifo_isEmpty(asclin->tx) == FALSE)
        {
            switch (asclin->dataBufferMode)
            {
            case Ifx_DataBufferMode_normal:
            {
                uint8          ascData[16];
                uint16         count            = 0, i_count = 0;
                volatile uint8 hw_tx_fill_level = 0;

                count            = Ifx_Fifo_readCount(asclin->tx); /*SW FIFO fill level*/

                hw_tx_fill_level = IfxAsclin_getTxFifoFillLevel(asclin->asclin);

                i_count          = (16 - hw_tx_fill_level);

                if (i_count > count)
                {
                    i_count = count;
                }

                Ifx_Fifo_read(asclin->tx, &ascData[0], i_count, TIME_NULL);
                IfxAsclin_write8(asclin->asclin, &ascData[0], i_count);
                asclin->sendCount += i_count;
            }
            break;

            case Ifx_DataBufferMode_timeStampSingle:
            {
                Ifx_DataBufferMode_TimeStampSingle packedData;
                uint8                              ascData;

                Ifx_Fifo_read(asclin->tx, &packedData, sizeof(packedData), TIME_NULL);

                ascData = packedData.data;
                IfxAsclin_write8(asclin->asclin, &ascData, 1);
                asclin->sendCount++;
            }
            break;
            }
        }
        else
        {
            /* transmit buffer is empty */
            asclin->txInProgress = FALSE;
        }
    }
    else /* in circulation case, we get 1 interrupt per complete circulation, sendCount is updated only per circulation */
    {
        asclin->sendCount += asclin->asclin->TXFIFOCON.B.CIRCLEVEL;
    }
}


boolean IfxAsclin_Asc_read(IfxAsclin_Asc *asclin, void *data, Ifx_SizeT *count, Ifx_TickTime timeout)
{
    Ifx_SizeT left = Ifx_Fifo_read(asclin->rx, data, *count, timeout);

    *count -= left;

    return left == 0;
}


void IfxAsclin_Asc_resetSendCount(IfxAsclin_Asc *asclin)
{
    asclin->sendCount = 0;
}


boolean IfxAsclin_Asc_write(IfxAsclin_Asc *asclin, const void *data, Ifx_SizeT *count, Ifx_TickTime timeout)
{
    Ifx_SizeT left;
    boolean   result       = TRUE;
    boolean   tx_status    = asclin->txInProgress;
    uint16    tx_fifo_size = (uint16)asclin->tx->size;

    if (*count != 0)
    {
        if ((!tx_status) && (*count > tx_fifo_size))                 /* transmission not initialised and data size is greater than S/W FIFO */
        {
            Ifx_Fifo_write(asclin->tx, data, tx_fifo_size, timeout); /*Fill upto the S/W FIFO size and initiate transmission*/
            IfxAsclin_Asc_initiateTransmission(asclin);

            left = Ifx_Fifo_write(asclin->tx, (((const uint8 *)data) + tx_fifo_size), (*count) - tx_fifo_size, timeout);
            IfxAsclin_Asc_initiateTransmission(asclin); /* will initiate transmission only if txInProgress is False, otherwise interrupts will continue to push data to H/W FIFO */
        }

        else
        {
            left = Ifx_Fifo_write(asclin->tx, data, *count, timeout);
            IfxAsclin_Asc_initiateTransmission(asclin);
        }

        *count -= left;
        result  = left == 0;
    }

    return result;
}


void IfxAsclin_Asc_transmitCircularData(IfxAsclin_Asc *asclin, uint8 *data, IfxAsclin_FifoCirculationLevel size, IfxAsclin_TriggerSource triggerSource)
{
	/* getting the pointer to ASCLIN registers from module handler */
    Ifx_ASCLIN                    *asclinSFR = asclin->asclin;
    IfxAsclin_FifoCirculationLevel lSize     = size;

    IfxAsclin_flushTxFifo(asclinSFR);                          /* flush the Tx FIFO */

    IfxAsclin_setTriggerSource(asclinSFR, triggerSource);      /* selecting the Trigger Source for the circulation Buffer */

    Ifx_ASCLIN_TXDATA *txData = (Ifx_ASCLIN_TXDATA *)&asclin->asclin->TXDATA[0].U;

    while ((lSize > 0))
    {
        txData->U = *data++;
        lSize--;
    }

    IfxAsclin_setCircularFifoLevel(asclinSFR, size);                                   /* set Circular FIFO Level*/
    IfxAsclin_setTxFifoInterruptMode(asclinSFR, IfxAsclin_FifoInterruptMode_circular); /* setting Tx FIFO interrupt generation mode */
}


uint32 IfxAsclin_Asc_getIsrCount(IfxAsclin_Asc *asclin)
{
    return asclin->isrCount;
}


void IfxAsclin_Asc_resetIsrCount(IfxAsclin_Asc *asclin)
{
    asclin->isrCount = 0;
}
