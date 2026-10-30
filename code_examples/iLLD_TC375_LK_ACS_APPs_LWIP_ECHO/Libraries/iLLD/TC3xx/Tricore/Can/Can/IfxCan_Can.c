/**
 * \file IfxCan_Can.c
 * \brief CAN CAN details
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

#include "IfxCan_Can.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxCan_ReadTxEventStatus IfxCan_Can_readTxEvent(IfxCan_Can_Node *node, IfxCan_Can_TransmitEvent *canTxEventFifoElements)
{
    uint8                    txEventFifoIndex;
    IfxCan_ReadTxEventStatus readTxEventStatus = IfxCan_ReadTxEventStatus_elementNotAvailable;

    if (IfxCan_Node_getTxEventFifoFillLevel(node->node) > 0)
    {
        readTxEventStatus = IfxCan_ReadTxEventStatus_readSuccessful;

        txEventFifoIndex  = node->node->TX.EFS.B.EFGI;
        Ifx_CAN_TXEVENT *txEventFifoElement = IfxCan_Node_getTxEventFifoElementAddress(node->messageRAM.baseAddress, node->messageRAM.txEventFifoStartAddress, txEventFifoIndex);

        canTxEventFifoElements->errorStateIndicator       = txEventFifoElement->E0.B.ESI;
        canTxEventFifoElements->extendedID                = txEventFifoElement->E0.B.XTD;
        canTxEventFifoElements->remoteTransmissionRequest = txEventFifoElement->E0.B.RTR;
        canTxEventFifoElements->identifier                = txEventFifoElement->E0.B.ID;

        canTxEventFifoElements->eventType                 = txEventFifoElement->E1.B.ET;
        canTxEventFifoElements->frameFormatType           = (IfxCan_FrameFormatType)txEventFifoElement->E1.B.FDF;
        canTxEventFifoElements->bitRateSwitch             = txEventFifoElement->E1.B.BRS;
        canTxEventFifoElements->dataLengthCode            = txEventFifoElement->E1.B.DLC;
        canTxEventFifoElements->messageMarker             = txEventFifoElement->E1.B.MM;

        IfxCan_Node_setTxEventFifoAcknowledgeIndex(node->node, (IfxCan_TxBufferId)txEventFifoIndex);
    }

    return readTxEventStatus;
}


void IfxCan_Can_initMessage(IfxCan_Message *message)
{
    const IfxCan_Message defaultMessage = {
        .bufferNumber            = 0,
        .messageId               = 0x0,
        .remoteTransmitRequest   = 0,
        .messageIdLength         = IfxCan_MessageIdLength_standard,
        .errorStateIndicator     = 0,
        .dataLengthCode          = IfxCan_DataLengthCode_8,
        .frameMode               = IfxCan_FrameMode_standard,
        .txEventFifoControl      = 0,
        .storeInTxFifoQueue      = FALSE,
        .readFromRxFifo0         = FALSE,
        .readFromRxFifo1         = FALSE,
        .bypassSwTransmitRequest = FALSE
    };

    /* Default Configuration */
    *message = defaultMessage;
}


void IfxCan_Can_initModule(IfxCan_Can *can, const IfxCan_Can_Config *config)
{
    can->can = config->can;

    /* If module is not enabled */
    if (IfxCan_isModuleEnabled(can->can) != TRUE)
    {
        /* Enable module, disregard Sleep Mode request */
        IfxCan_enableModule(can->can);
    }
}


void IfxCan_Can_initModuleConfig(IfxCan_Can_Config *config, Ifx_CAN *can)
{
    const IfxCan_Can_Config defaultConfig = {
        .can = NULL_PTR
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* Take over module pointer */
    config->can = can;
}


boolean IfxCan_Can_initNode(IfxCan_Can_Node *node, const IfxCan_Can_NodeConfig *config)
{
    Ifx_CAN   *canSfr  = config->can;
    node->can          = canSfr;
    boolean status     = 0;

    Ifx_CAN_N *nodeSfr = IfxCan_getNodePointer(canSfr, config->nodeId);
    node->node         = nodeSfr;

    IfxCan_Can_initNodeClk(node, config->can, config->nodeId, config->clockSource);
    IfxCan_Can_configureNodeMessageRamHandle(node, &config->messageRAM);
    IfxCan_Can_configureBaudrate(node, &config->baudRate, &config->fastBaudRate, config->calculateBitTimingValues, config->frame.mode);
    IfxCan_Can_configureTx(node, &config->frame, &config->txConfig);
	IfxCan_Can_configureRx(node, &config->frame, &config->rxConfig);
	IfxCan_Can_configureFilter(node, &config->frame, &config->filterConfig);
    status = IfxCan_Can_configurePins(node, config->pins);
    IfxCan_Can_configureLoopbackMode(node, config->busLoopbackEnabled);
    IfxCan_Can_configureInterrupt(node, &config->interruptConfig);

    return status;
}


void IfxCan_Can_initNodeClk(IfxCan_Can_Node *node, Ifx_CAN *can, IfxCan_NodeId nodeId, IfxCan_ClockSource clockSource)
{
    Ifx_CAN *canSfr  = can;
    node->can = canSfr;

    Ifx_CAN_N *nodeSfr = IfxCan_getNodePointer(canSfr, nodeId);
    node->node       = nodeSfr;

    /* Initialize the clock for the selected node */
    IfxCan_ClockSelect clockSelect = (IfxCan_ClockSelect)nodeId;
    IfxCan_setClockSource(canSfr, clockSelect, clockSource);
}


void IfxCan_Can_configureNodeMessageRamHandle(IfxCan_Can_Node *node, const IfxCan_MessageRAM *messageRAM)
{
	node->messageRAM = *messageRAM;
}

void IfxCan_Can_configureBaudrate(IfxCan_Can_Node *node, const IfxCan_Can_BaudRate *baudRate, const IfxCan_Can_FastBaudRate *fastBaudRate, boolean calculateBitTimingValues, IfxCan_FrameMode frameMode)
{
	Ifx_CAN_N *nodeSfr = node->node;

	/* Enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
	IfxCan_Node_enableConfigurationChange(nodeSfr);

	float32 moduleFreq = IfxCan_getModuleFrequency();

	/* Set baud rate */
	if (calculateBitTimingValues)
	{
		IfxCan_Node_setBitTiming(nodeSfr, moduleFreq, baudRate->baudrate, baudRate->samplePoint, baudRate->syncJumpWidth);
	}
	else
	{
		IfxCan_Node_setBitTimingValues(nodeSfr, baudRate->syncJumpWidth, baudRate->timeSegment2, baudRate->timeSegment1, baudRate->prescaler);
	}

	/* For CAN FD frames, set fast baud rate */
	if (frameMode != IfxCan_FrameMode_standard)
	{
		if (calculateBitTimingValues)
		{
			IfxCan_Node_setFastBitTiming(nodeSfr, moduleFreq, fastBaudRate->baudrate, fastBaudRate->samplePoint, fastBaudRate->syncJumpWidth);
		}
		else
		{
			IfxCan_Node_setFastBitTimingValues(nodeSfr, fastBaudRate->syncJumpWidth, fastBaudRate->timeSegment2, fastBaudRate->timeSegment1, fastBaudRate->prescaler);
		}

		/* Set transceiver delay compensation offset */
		if (fastBaudRate->tranceiverDelayOffset != 0)
		{
			IfxCan_Node_setTransceiverDelayCompensationOffset(nodeSfr, fastBaudRate->tranceiverDelayOffset);
		}
	}

	/* Disable configuration change CCCR.CCE = 0 */
	IfxCan_Node_disableConfigurationChange(nodeSfr);
}


void IfxCan_Can_configureTx(IfxCan_Can_Node *node, const IfxCan_Can_Frame *frame, const IfxCan_Can_TxConfig *txConfig)
{
    Ifx_CAN_N *nodeSfr = node->node;

    if ((frame->type == IfxCan_FrameType_transmit) ||
        (frame->type == IfxCan_FrameType_transmitAndReceive) ||
        (frame->type == IfxCan_FrameType_remoteRequest) ||
        (frame->type == IfxCan_FrameType_remoteAnswer))
    {
		IfxCan_Node_enableConfigurationChange(nodeSfr);

		uint32 id; /* Used for enabling transmit interrupts for individual Tx buffers */

		/* Set Tx buffers start address in the Message RAM */
		nodeSfr->TX.BC.B.TBSA = node->messageRAM.txBuffersStartAddress >> 2;
		/* Set Tx element data field size */
		nodeSfr->TX.ESC.B.TBDS = txConfig->txBufferDataFieldSize;

		if ((txConfig->txMode == IfxCan_TxMode_dedicatedBuffers) ||
			(txConfig->txMode == IfxCan_TxMode_sharedFifo) ||
			(txConfig->txMode == IfxCan_TxMode_sharedQueue))
		{
			/* Dedicated TX buffers operation */
			/* Select number of Tx buffers */
			nodeSfr->TX.BC.B.NDTB = txConfig->dedicatedTxBuffersNumber;

			/* Shared operation */
			if ((txConfig->txMode == IfxCan_TxMode_sharedFifo) || (txConfig->txMode == IfxCan_TxMode_sharedQueue))
			{
				if (txConfig->txMode == IfxCan_TxMode_sharedFifo)
				{
					/* Set Tx FIFO mode */
					IfxCan_Node_setTransmitFifoQueueMode(nodeSfr, IfxCan_TxMode_fifo);
				}

				if (txConfig->txMode == IfxCan_TxMode_sharedQueue)
				{
					/* Set Tx Queue mode */
					IfxCan_Node_setTransmitFifoQueueMode(nodeSfr, IfxCan_TxMode_queue);
				}

				/* Select number of Tx buffers(Tx Fifo Queue Size) to be used as Tx FIFO/Queue */
				nodeSfr->TX.BC.B.TFQS = txConfig->txFifoQueueSize;
			}

			/* Enable transmission interrupt on selected buffers */
			for (id = 0; id < (txConfig->dedicatedTxBuffersNumber + txConfig->txFifoQueueSize); ++id)
			{
				nodeSfr->TX.BTIE.U = nodeSfr->TX.BTIE.U | (1U << (IfxCan_TxBufferId)id);
			}
		}

		/* TX FIFO/Queue operation */
		else if ((txConfig->txMode == IfxCan_TxMode_fifo) || (txConfig->txMode == IfxCan_TxMode_queue))
		{
			/* Set Tx FIFO/Queue mode */
			IfxCan_Node_setTransmitFifoQueueMode(nodeSfr, txConfig->txMode);

			/* Select number of Tx buffers to be used as Tx FIFO/Queue */
			nodeSfr->TX.BC.B.TFQS = txConfig->txFifoQueueSize;

			/* Enable transmission interrupt on selected buffers */
			for (id = 0; id < txConfig->txFifoQueueSize; ++id)
			{
				nodeSfr->TX.BTIE.U = nodeSfr->TX.BTIE.U | (1U << (IfxCan_TxBufferId)id);
			}
		}
		/* Wrong selection */
		else
		{
			IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, 0);
		}

		/* Set the Tx event fifo size and start address if selected */
		if ((txConfig->txEventFifoSize > 0) && (txConfig->txEventFifoSize <= 32))
		{
			nodeSfr->TX.EFC.B.EFSA = node->messageRAM.txEventFifoStartAddress >> 2;
			nodeSfr->TX.EFC.B.EFS = txConfig->txEventFifoSize;
		}
		else /* Maximum number of configurable Tx Event FIFO elements is 32 */
		{
			IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, txConfig->txEventFifoSize <= 32);
		}

		/* Enable CAN frame mode of transmission Standard or CAN FD Long or FD Long and Fast frames*/
		IfxCan_Node_setFrameMode(nodeSfr, frame->mode);

		IfxCan_Node_disableConfigurationChange(nodeSfr);
    }
}


void IfxCan_Can_configureRx(IfxCan_Can_Node *node, const IfxCan_Can_Frame *frame, const IfxCan_Can_RxConfig *rxConfig)
{
    Ifx_CAN_N *nodeSfr = node->node;

    if ((frame->type == IfxCan_FrameType_receive) ||
        (frame->type == IfxCan_FrameType_transmitAndReceive) ||
        (frame->type == IfxCan_FrameType_remoteAnswer))
    {
		IfxCan_Node_enableConfigurationChange(nodeSfr);

		if ((rxConfig->rxMode == IfxCan_RxMode_dedicatedBuffers) ||
			(rxConfig->rxMode == IfxCan_RxMode_sharedFifo0) ||
			(rxConfig->rxMode == IfxCan_RxMode_sharedFifo1) ||
			(rxConfig->rxMode == IfxCan_RxMode_sharedAll))
		{
			/* Set Rx buffer data length */
			nodeSfr->RX.ESC.B.RBDS = rxConfig->rxBufferDataFieldSize;

			/* Set Rx buffers start address in the Message RAM */
			nodeSfr->RX.BC.B.RBSA = node->messageRAM.rxBuffersStartAddress >> 2;
		}

		if ((rxConfig->rxMode == IfxCan_RxMode_fifo0) ||
			(rxConfig->rxMode == IfxCan_RxMode_sharedFifo0) ||
			(rxConfig->rxMode == IfxCan_RxMode_sharedAll))
		{
			/* Set Rx FIFO 0 data length */
			nodeSfr->RX.ESC.B.F0DS = rxConfig->rxFifo0DataFieldSize;

			/* Set Rx FIFO 0 start address in the Message RAM */
			nodeSfr->RX.F0C.B.F0SA = node->messageRAM.rxFifo0StartAddress >> 2;

			/* Set Rx FIFO 0 size */
			nodeSfr->RX.F0C.B.F0S = rxConfig->rxFifo0Size;

			/* Set Rx FIFO 0 operating mode */
			nodeSfr->RX.F0C.B.F0OM = rxConfig->rxFifo0OperatingMode;

			/* Set Rx FIFO 0 water mark level */
			nodeSfr->RX.F0C.B.F0WM = rxConfig->rxFifo0WatermarkLevel;
		}

		if ((rxConfig->rxMode == IfxCan_RxMode_fifo1) ||
			(rxConfig->rxMode == IfxCan_RxMode_sharedFifo1) ||
			(rxConfig->rxMode == IfxCan_RxMode_sharedAll))
		{
			/* Set Rx FIFO 1 data length */
			nodeSfr->RX.ESC.B.F1DS = rxConfig->rxFifo1DataFieldSize;

			/* Set Rx FIFO 1 start address in the Message RAM */
			nodeSfr->RX.F1C.B.F1SA = node->messageRAM.rxFifo1StartAddress >> 2;

			/* Set Rx FIFO 1 size */
			nodeSfr->RX.F1C.B.F1S = rxConfig->rxFifo1Size;

			/* Set Rx FIFO 1 operating mode */
			nodeSfr->RX.F1C.B.F1OM = rxConfig->rxFifo1OperatingMode;

			/* Set Rx FIFO 1 watermark level */
			nodeSfr->RX.F1C.B.F1WM = rxConfig->rxFifo1WatermarkLevel;
		}

		/* Enable CAN frame mode of transmission */
		IfxCan_Node_setFrameMode(nodeSfr, frame->mode);

		IfxCan_Node_disableConfigurationChange(nodeSfr);
    }
}


void IfxCan_Can_configureFilter(IfxCan_Can_Node *node, const IfxCan_Can_Frame *frame, const IfxCan_Can_FilterConfig *filterConfig)
{
    Ifx_CAN_N *nodeSfr = node->node;

    if ((frame->type == IfxCan_FrameType_receive) ||
        (frame->type == IfxCan_FrameType_transmitAndReceive) ||
        (frame->type == IfxCan_FrameType_remoteAnswer))
    {
		IfxCan_Node_enableConfigurationChange(nodeSfr);

		/* Filter configuration */

		if ((filterConfig->messageIdLength == IfxCan_MessageIdLength_standard) ||
			(filterConfig->messageIdLength == IfxCan_MessageIdLength_both))
		{
			nodeSfr->SIDFC.B.FLSSA = node->messageRAM.standardFilterListStartAddress >> 2;    /* Set Standard Filter List Start Address */
			nodeSfr->SIDFC.B.LSS = filterConfig->standardListSize;                       	  /* Set Standard Filter List Size */
			nodeSfr->GFC.B.ANFS = filterConfig->standardFilterForNonMatchingFrames;      	  /* Configure Standard Filter For Non Matching Frames */

			if (filterConfig->rejectRemoteFramesWithStandardId == 1U)
			{
				nodeSfr->GFC.B.RRFS = 1U;   /* Set Reject Remote Frame with Standard ID */
			}
		}

		if ((filterConfig->messageIdLength == IfxCan_MessageIdLength_extended) ||
			(filterConfig->messageIdLength == IfxCan_MessageIdLength_both))
		{
			nodeSfr->XIDFC.B.FLESA = node->messageRAM.extendedFilterListStartAddress >> 2;    /* Set Extended Filter List Start Address */
			nodeSfr->XIDAM.B.EIDM = filterConfig->extendedIdAndMask;                     	  /* Set Extended ID And Mask */
			nodeSfr->XIDFC.B.LSE = filterConfig->extendedListSize;                       	  /* Set Extended Filter List Size */
			nodeSfr->GFC.B.ANFE = filterConfig->extendedFilterForNonMatchingFrames;      	  /* Configure Extended Filter For Non Matching Frames */

			if (filterConfig->rejectRemoteFramesWithExtendedId == 1U)
			{
				nodeSfr->GFC.B.RRFE = 1U;   /* Set Reject Remote Frame with Extended ID */
			}
		}

		IfxCan_Node_disableConfigurationChange(nodeSfr);
    }
}


boolean IfxCan_Can_configurePins(IfxCan_Can_Node *node, const IfxCan_Can_Pins *pins)
{
	Ifx_CAN_N *nodeSfr = node->node;

	boolean status = 0;

	/* Enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
	IfxCan_Node_enableConfigurationChange(nodeSfr);

	/* Pins initialization */
	if (pins != NULL_PTR)
	{
		if (pins->txPin != NULL_PTR)
		{
			status |= (IfxCan_Node_initTxPin(pins->txPin, pins->txPinMode, pins->padDriver));
		}

		if (pins->rxPin != NULL_PTR)
		{
			status |= (IfxCan_Node_initRxPin(nodeSfr, pins->rxPin, pins->rxPinMode, pins->padDriver));
		}
	}
	/* Disable configuration change CCCR.CCE = 0 */
	IfxCan_Node_disableConfigurationChange(nodeSfr);

	return status;
}


void IfxCan_Can_configureLoopbackMode(IfxCan_Can_Node *node, boolean busLoopbackEnabled)
{
	Ifx_CAN_N *nodeSfr = node->node;

	/* Enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
	IfxCan_Node_enableConfigurationChange(nodeSfr);

	/* Enable internal virtual CAN bus loopback mode if selected */
    if (busLoopbackEnabled)
    {
        nodeSfr->NPCR.B.LBM = 1;
    }

	/* Disable configuration change CCCR.CCE = 0 */
	IfxCan_Node_disableConfigurationChange(nodeSfr);
}


void IfxCan_Can_configureInterrupt(IfxCan_Can_Node *node, const IfxCan_Can_InterruptConfig *interruptConfig)
{
	Ifx_CAN_N *nodeSfr = node->node;

	/* Enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
	IfxCan_Node_enableConfigurationChange(nodeSfr);

    /* Interrupt groups configuration */
    volatile Ifx_SRC_SRCR *srcPointer;

    if ((interruptConfig->tefifo.priority > 0) || (interruptConfig->tefifo.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_tefifo, interruptConfig->tefifo.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->tefifo.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->tefifo.typeOfService, interruptConfig->tefifo.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->hpe.priority > 0) || (interruptConfig->hpe.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_hpe, interruptConfig->hpe.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->hpe.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->hpe.typeOfService, interruptConfig->hpe.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->wati.priority > 0) || (interruptConfig->wati.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_wati, interruptConfig->wati.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->wati.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->wati.typeOfService, interruptConfig->wati.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->alrt.priority > 0) || (interruptConfig->alrt.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_alrt, interruptConfig->alrt.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->alrt.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->alrt.typeOfService, interruptConfig->alrt.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->moer.priority > 0) || (interruptConfig->moer.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_moer, interruptConfig->moer.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->moer.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->moer.typeOfService, interruptConfig->moer.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->safe.priority > 0) || (interruptConfig->safe.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_safe, interruptConfig->safe.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->safe.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->safe.typeOfService, interruptConfig->safe.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->boff.priority > 0) || (interruptConfig->boff.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_boff, interruptConfig->boff.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->boff.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->boff.typeOfService, interruptConfig->boff.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->loi.priority > 0) || (interruptConfig->loi.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_loi, interruptConfig->loi.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->loi.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->loi.typeOfService, interruptConfig->loi.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->reint.priority > 0) || (interruptConfig->reint.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_reint, interruptConfig->reint.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->reint.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->reint.typeOfService, interruptConfig->reint.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->rxf1f.priority > 0) || (interruptConfig->rxf1f.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_rxf1f, interruptConfig->rxf1f.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->rxf1f.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->rxf1f.typeOfService, interruptConfig->rxf1f.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->rxf0f.priority > 0) || (interruptConfig->rxf0f.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_rxf0f, interruptConfig->rxf0f.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->rxf0f.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->rxf0f.typeOfService, interruptConfig->rxf0f.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->rxf1n.priority > 0) || (interruptConfig->rxf1f.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_rxf1n, interruptConfig->rxf1n.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->rxf1n.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->rxf1n.typeOfService, interruptConfig->rxf1n.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->rxf0n.priority > 0) || (interruptConfig->rxf0n.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_rxf0n, interruptConfig->rxf0n.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->rxf0n.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->rxf0n.typeOfService, interruptConfig->rxf0n.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->reti.priority > 0) || (interruptConfig->reti.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_reti, interruptConfig->reti.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->reti.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->reti.typeOfService, interruptConfig->reti.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->traq.priority > 0) || (interruptConfig->traq.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_traq, interruptConfig->traq.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->traq.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->traq.typeOfService, interruptConfig->traq.priority);
        IfxSrc_enable(srcPointer);
    }

    if ((interruptConfig->traco.priority > 0) || (interruptConfig->traco.typeOfService == IfxSrc_Tos_dma))
    {
        IfxCan_Node_setGroupInterruptLine(nodeSfr, IfxCan_InterruptGroup_traco, interruptConfig->traco.interruptLine);
        srcPointer = IfxCan_getSrcPointer(node->can, interruptConfig->traco.interruptLine);
        IfxSrc_init(srcPointer, interruptConfig->traco.typeOfService, interruptConfig->traco.priority);
        IfxSrc_enable(srcPointer);
    }

    /* Enable the selected interrupts */
    if (interruptConfig->rxFifo0NewMessageEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_rxFifo0NewMessage);
    }

    if (interruptConfig->rxFifo0WatermarkEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_rxFifo0WatermarkReached);
    }

    if (interruptConfig->rxFifo0FullEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_rxFifo0Full);
    }

    if (interruptConfig->rxFifo0MessageLostEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_rxFifo0MessageLost);
    }

    if (interruptConfig->rxFifo1NewMessageEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_rxFifo1NewMessage);
    }

    if (interruptConfig->rxFifo1WatermarkEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_rxFifo1WatermarkReached);
    }

    if (interruptConfig->rxFifo1FullEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_rxFifo1Full);
    }

    if (interruptConfig->rxFifo1MessageLostEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_rxFifo1MessageLost);
    }

    if (interruptConfig->highPriorityMessageEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_highPriorityMessage);
    }

    if (interruptConfig->transmissionCompletedEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_transmissionCompleted);
    }

    if (interruptConfig->transmissionCancellationFinishedEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_transmissionCancellationFinished);
    }

    if (interruptConfig->txFifoEmptyEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_txFifoEmpty);
    }

    if (interruptConfig->txEventFifoNewEntryEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_txEventFifoNewEntry);
    }

    if (interruptConfig->txEventFifoWatermarkEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_txEventFifoWatermarkReached);
    }

    if (interruptConfig->txEventFifoFullEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_txEventFifoFull);
    }

    if (interruptConfig->txEventFifoEventLostEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_txEventFifoEventLost);
    }

    if (interruptConfig->timestampWraparoundEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_timestampWraparound);
    }

    if (interruptConfig->messageRAMAccessFailureEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_messageRAMAccessFailure);
    }

    if (interruptConfig->timeoutOccurredEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_timeoutOccurred);
    }

    if (interruptConfig->messageStoredToDedicatedRxBufferEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_messageStoredToDedicatedRxBuffer);
    }

    if (interruptConfig->errorLoggingOverflowEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_errorLoggingOverflow);
    }

    if (interruptConfig->errorPassiveEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_errorPassive);
    }

    if (interruptConfig->warningStatusEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_warningStatus);
    }

    if (interruptConfig->busOffStatusEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_busOffStatus);
    }

    if (interruptConfig->watchdogEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_watchdog);
    }

    if (interruptConfig->protocolErrorArbitrationEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_protocolErrorArbitration);
    }

    if (interruptConfig->protocolErrorDataEnabled)
    {
        IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_protocolErrorData);
    }

    /* Disable configuration change CCCR.CCE = 0 */
	IfxCan_Node_disableConfigurationChange(nodeSfr);
}


void IfxCan_Can_initNodeConfig(IfxCan_Can_NodeConfig *config, IfxCan_Can *can)
{
    const IfxCan_Can_NodeConfig defaultConfig = {
        .can         = NULL_PTR,
        .nodeId      = IfxCan_NodeId_0,
        .clockSource = IfxCan_ClockSource_both,
        .frame       = {
            .type = IfxCan_FrameType_receive,
            .mode = IfxCan_FrameMode_standard
        },
        .baudRate                                    = {
            .baudrate      = 500000,
            .samplePoint   = 8000,
            .syncJumpWidth = 3,
            .prescaler     = 0,
            .timeSegment1  = 3,
            .timeSegment2  = 10
        },
        .fastBaudRate                                = {
            .baudrate              = 1000000,
            .samplePoint           = 8000,
            .syncJumpWidth         = 3,
            .prescaler             = 1,
            .timeSegment1          = 3,
            .timeSegment2          = 10,
            .tranceiverDelayOffset = 0
        },
        .txConfig                                    = {
            .txMode                   = IfxCan_TxMode_dedicatedBuffers,
            .dedicatedTxBuffersNumber = 2,
            .txFifoQueueSize          = 0,
            .txBufferDataFieldSize    = IfxCan_DataFieldSize_8,
            .txEventFifoSize          = 0
        },
        .filterConfig                                = {
            .messageIdLength                    = IfxCan_MessageIdLength_standard,
            .standardListSize                   = 2,
            .extendedListSize                   = 0,
            .extendedIdAndMask                  = IFXCAN_EIDM_DEFAULT,
            .rejectRemoteFramesWithStandardId   = 0,
            .rejectRemoteFramesWithExtendedId   = 0,
            .standardFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_acceptToRxFifo0,
            .extendedFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_acceptToRxFifo0
        },
        .rxConfig                                    = {
            .rxMode                = IfxCan_RxMode_dedicatedBuffers,
            .rxBufferDataFieldSize = IfxCan_DataFieldSize_8,
            .rxFifo0DataFieldSize  = IfxCan_DataFieldSize_8,
            .rxFifo1DataFieldSize  = IfxCan_DataFieldSize_8,
            .rxFifo0OperatingMode  = IfxCan_RxFifoMode_blocking,
            .rxFifo1OperatingMode  = IfxCan_RxFifoMode_blocking,
            .rxFifo0WatermarkLevel = 0,
            .rxFifo1WatermarkLevel = 0,
            .rxFifo0Size           = 0,
            .rxFifo1Size           = 0
        },
        .messageRAM                                  = {
            .baseAddress                    = (uint32)(can->can),
            .standardFilterListStartAddress = 0x0,
            .extendedFilterListStartAddress = 0x80,
            .rxFifo0StartAddress            = 0x100,
            .rxFifo1StartAddress            = 0x200,
            .rxBuffersStartAddress          = 0x300,
            .txEventFifoStartAddress        = 0x400,
            .txBuffersStartAddress          = 0x440
        },
        .interruptConfig                             = {
            .rxFifo0NewMessageEnabled                = FALSE,
            .rxFifo0WatermarkEnabled                 = FALSE,
            .rxFifo0FullEnabled                      = FALSE,
            .rxFifo0MessageLostEnabled               = FALSE,
            .rxFifo1NewMessageEnabled                = FALSE,
            .rxFifo1WatermarkEnabled                 = FALSE,
            .rxFifo1FullEnabled                      = FALSE,
            .rxFifo1MessageLostEnabled               = FALSE,
            .highPriorityMessageEnabled              = FALSE,
            .transmissionCompletedEnabled            = FALSE,
            .transmissionCancellationFinishedEnabled = FALSE,
            .txFifoEmptyEnabled                      = FALSE,
            .txEventFifoNewEntryEnabled              = FALSE,
            .txEventFifoWatermarkEnabled             = FALSE,
            .txEventFifoFullEnabled                  = FALSE,
            .txEventFifoEventLostEnabled             = FALSE,
            .timestampWraparoundEnabled              = FALSE,
            .messageRAMAccessFailureEnabled          = FALSE,
            .timeoutOccurredEnabled                  = FALSE,
            .messageStoredToDedicatedRxBufferEnabled = FALSE,
            .errorLoggingOverflowEnabled             = FALSE,
            .errorPassiveEnabled                     = FALSE,
            .warningStatusEnabled                    = FALSE,
            .busOffStatusEnabled                     = FALSE,
            .watchdogEnabled                         = FALSE,
            .protocolErrorArbitrationEnabled         = FALSE,
            .protocolErrorDataEnabled                = FALSE,
            .tefifo                                  = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .hpe                                     = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .wati                                    = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .alrt                                    = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .moer                                    = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .safe                                    = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .boff                                    = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .loi                                     = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .reint                                   = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .rxf1f                                   = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .rxf0f                                   = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .rxf1n                                   = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .rxf0n                                   = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .reti                                    = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .traq                                    = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            },
            .traco                                   = {
                .interruptLine = IfxCan_InterruptLine_0,
                .priority      = 0,
                .typeOfService = IfxSrc_Tos_cpu0
            }
        },
        .pins                     = NULL_PTR,
        .busLoopbackEnabled       = FALSE,
        .calculateBitTimingValues = TRUE
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* Take over module pointer */
    config->can = can->can;
}


void IfxCan_Can_readMessage(IfxCan_Can_Node *node, IfxCan_Message *message, uint32 *data)
{
    IfxCan_RxBufferId bufferId = IfxCan_RxBufferId_0;
    Ifx_CAN_RXMSG    *rxBufferElement;

    if ((message->readFromRxFifo0) || (message->readFromRxFifo1))
    {
        if (message->readFromRxFifo0)
        {
            /* Get the Tx FIFO 0 ELement address */
            bufferId        = IfxCan_Node_getRxFifo0GetIndex(node->node);
            rxBufferElement = IfxCan_Node_getRxFifo0ElementAddress(node->node, node->messageRAM.baseAddress, node->messageRAM.rxFifo0StartAddress, bufferId);
        }
        else
        {
            /* Get the Tx FIFO 1 ELement address */
            bufferId        = IfxCan_Node_getRxFifo1GetIndex(node->node);
            rxBufferElement = IfxCan_Node_getRxFifo1ElementAddress(node->node, node->messageRAM.baseAddress, node->messageRAM.rxFifo1StartAddress, bufferId);
        }
    }
    else
    {
        /* Get the Rx Buffer ELement address */
        bufferId        = (IfxCan_RxBufferId)message->bufferNumber;
        rxBufferElement = IfxCan_Node_getRxBufferElementAddress(node->node, node->messageRAM.baseAddress, node->messageRAM.rxBuffersStartAddress, bufferId);
    }

    /* Get message ID */
    message->messageId = IfxCan_Node_getMesssageId(rxBufferElement);

    /* Get message ID length */
    message->messageIdLength = (IfxCan_MessageIdLength)rxBufferElement->R0.B.XTD;

    /* Get data length code*/
    message->dataLengthCode = (IfxCan_DataLengthCode)rxBufferElement->R1.B.DLC;

    /* Get CAN frame mode of operation */
    message->frameMode = IfxCan_Node_getFrameMode(rxBufferElement);

    /* Get message bufferNumber*/
    message->bufferNumber = bufferId;

    /* Read data */
    IfxCan_Node_readData(rxBufferElement, message->dataLengthCode, data);

    /* Write acknowledgment index incase of FIFO */
    if (message->readFromRxFifo0)
    {
        node->node->RX.F0A.B.F0AI = bufferId;
    }
    else if (message->readFromRxFifo1)
    {
        node->node->RX.F1A.B.F1AI = bufferId;
    }

    /* Clear newdata flag after reading */
    IfxCan_Node_clearRxBufferNewDataFlag(node->node, bufferId);
}


IfxCan_Status IfxCan_Can_sendMessage(IfxCan_Can_Node *node, IfxCan_Message *message, uint32 *data)
{
    IfxCan_Status     status   = IfxCan_Status_ok;

    IfxCan_TxBufferId bufferId = IfxCan_TxBufferId_0;

    if (!message->storeInTxFifoQueue)
    {
        bufferId = (IfxCan_TxBufferId)message->bufferNumber;
    }
    else
    {
        bufferId = (IfxCan_TxBufferId)node->node->TX.FQS.B.TFQPI;	/* Get Tx Fifo Queue Put Index */
    }

    if (IfxCan_Can_isTxBufferRequestPending(node, bufferId) == 1)
    {                       /* Previous message was not transferred, e.g. due to busy bus, BUS-OFF or others */
        status = IfxCan_Status_notSentBusy;
    }
    else
    {
        /* Get the Tx Bufer ELement address */
        Ifx_CAN_TXMSG *txBufferElement = IfxCan_Node_getTxBufferElementAddress(node->node, node->messageRAM.baseAddress, node->messageRAM.txBuffersStartAddress, bufferId);

        /* Set message Id (ID and XTD) */
        IfxCan_Node_setMsgId(txBufferElement, message->messageId, message->messageIdLength);

        /* Set TX FIFO Event control (EFC) and Message Marker (MM) if Tx Event Fifo is chosen */
        if (message->txEventFifoControl == TRUE)
        {
        	txBufferElement->T1.B.EFC = message->txEventFifoControl;
            txBufferElement->T1.B.MM = bufferId;
        }

        /* Set Remote Transmit request if selected (RTR)*/
        txBufferElement->T0.B.RTR = message->remoteTransmitRequest;

        /* Set Error State Indicator if selected (ESI)*/
        if ((message->frameMode == IfxCan_FrameMode_fdLong) || (message->frameMode == IfxCan_FrameMode_fdLongAndFast))
        {
            txBufferElement->T0.B.ESI = message->errorStateIndicator;
        }

        /* Set data length code (DLC) */
        txBufferElement->T1.B.DLC = message->dataLengthCode;

        /* Write data (DBx) */
        IfxCan_Node_writeTxBufData(txBufferElement, message->dataLengthCode, data);

        /* Set CAN frame mode request (FDF and BRS) */
        IfxCan_Node_setFrameModeReq(txBufferElement, message->frameMode);

        if (message->bypassSwTransmitRequest == FALSE)
        {   /* Set transmit request */
        	node->node->TX.BAR.U = (node->node->TX.BAR.U) | (1U << bufferId);
        }
    }

    return status;
}


void IfxCan_Can_setExtendedFilter(IfxCan_Can_Node *node, IfxCan_Filter *filter)
{
    /* Get the Extended filter element address */
    Ifx_CAN_EXTMSG *extendedFilterElement = IfxCan_Node_getExtendedFilterElementAddress(node->messageRAM.baseAddress, node->messageRAM.extendedFilterListStartAddress, filter->number);

    /* Enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
    IfxCan_Node_enableConfigurationChange(node->node);

    /* Set Extended Filter ID2 */
    if (filter->elementConfiguration != IfxCan_FilterElementConfiguration_storeInRxBuffer)
    {
        extendedFilterElement->F1.B.EFID2 = filter->id2;
    }
    else
    {
        extendedFilterElement->F1.B.EFID2 = filter->rxBufferOffset;
    }

    extendedFilterElement->F0.B.EFID1 = filter->id1;					/* Set Extended Filter ID1 */
    extendedFilterElement->F0.B.EFEC = filter->elementConfiguration;	/* Set Extended Filter Configuration */
    extendedFilterElement->F1.B.EFT = filter->type;						/* Set Extended Filter Type */

    /* Disable configuration change CCCR.CCE = 0, CCCR.INIT = 0 */
    IfxCan_Node_disableConfigurationChange(node->node);
}


void IfxCan_Can_setStandardFilter(IfxCan_Can_Node *node, IfxCan_Filter *filter)
{
    /* Get the standard filter element address */
    Ifx_CAN_STDMSG *standardFilterElement = IfxCan_Node_getStandardFilterElementAddress(node->messageRAM.baseAddress, node->messageRAM.standardFilterListStartAddress, filter->number);

    /* Enable configuration change CCCR.CCE = 1, CCCR.INIT = 1 */
    IfxCan_Node_enableConfigurationChange(node->node);

	/* Set Standard Filter ID2 */
    if (filter->elementConfiguration != IfxCan_FilterElementConfiguration_storeInRxBuffer)
    {
        standardFilterElement->S0.B.SFID2 = filter->id2;
    }
    else
    {
        standardFilterElement->S0.B.SFID2 = (uint8)filter->rxBufferOffset;
    }

    standardFilterElement->S0.B.SFID1 = filter->id1;					/* Set Standard Filter ID1 */
    standardFilterElement->S0.B.SFEC = filter->elementConfiguration;	/* Set Standard Filter Configuration */
    standardFilterElement->S0.B.SFT = filter->type;						/* Set Standard Filter Type */

    /* Disable configuration change CCCR.CCE = 0, CCCR.INIT = 0 */
    IfxCan_Node_disableConfigurationChange(node->node);
}
