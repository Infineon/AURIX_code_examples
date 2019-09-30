/**
 * \file IfxDma_Dma.c
 * \brief DMA DMA details
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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

#include "IfxDma_Dma.h"

/******************************************************************************/
/*-----------------------Private Function Prototypes--------------------------*/
/******************************************************************************/

/** \brief local function to copy a transaction set into DMA channel SFRs or memory location (for linked lists)
 * \param channel Specifies the pointer to DMA channel registers
 * \param config pointer to the DMA default channel configuration structure
 * \return None
 */
IFX_STATIC void IfxDma_Dma_configureTransactionSet(Ifx_DMA_CH *channel, const IfxDma_Dma_ChannelConfig *config);

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IFX_STATIC void IfxDma_Dma_configureTransactionSet(Ifx_DMA_CH *channel, const IfxDma_Dma_ChannelConfig *config)
{
    /* shadow address shall be 32-Byte Aligned */
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, ((config->shadowAddress & 0x1F) == 0U));
    }

    {
        Ifx_DMA_CH_CHCFGR chcfgr;
        chcfgr.U          = 0;
        chcfgr.B.TREL     = config->transferCount;
        chcfgr.B.BLKM     = config->blockMode;
        chcfgr.B.RROAT    = config->requestMode;
        chcfgr.B.CHMODE   = config->operationMode;
        chcfgr.B.CHDW     = config->moveSize;
        chcfgr.B.PRSEL    = config->requestSource;
        chcfgr.B.PATSEL   = config->pattern;

        channel->CHCFGR.U = chcfgr.U;
    }

    {
        Ifx_DMA_CH_ADICR adicr;
        adicr.U       = 0;
        adicr.B.SMF   = config->sourceAddressIncrementStep;
        adicr.B.INCS  = config->sourceAddressIncrementDirection;
        adicr.B.CBLS  = config->sourceAddressCircularRange;
        adicr.B.SCBE  = config->sourceCircularBufferEnabled;
        adicr.B.DMF   = config->destinationAddressIncrementStep;
        adicr.B.INCD  = config->destinationAddressIncrementDirection;
        adicr.B.CBLD  = config->destinationAddressCircularRange;
        adicr.B.DCBE  = config->destinationCircularBufferEnabled;
        adicr.B.SHCT  = config->shadowControl;
        adicr.B.STAMP = config->timestampEnabled;
        adicr.B.WRPSE = config->wrapSourceInterruptEnabled;
        adicr.B.WRPDE = config->wrapDestinationInterruptEnabled;
        adicr.B.INTCT = (config->channelInterruptEnabled ? 2 : 0) | (config->channelInterruptControl ? 1 : 0);
        adicr.B.IRDV  = config->interruptRaiseThreshold;
        adicr.B.ETRL  = config->transactionRequestLostInterruptEnabled;
        //enter also the circular buffer enable bits

        channel->ADICR.U = adicr.U;
    }
    channel->SADR.U   = config->sourceAddress;
    channel->DADR.U   = config->destinationAddress;
    channel->SDCRCR.U = config->sourceDestinationAddressCrc;
    channel->RDCRCR.U = config->readDataCrc;

    // write not allowed if SHCT=1 or SHCT=2
    if ((config->shadowControl != IfxDma_ChannelShadow_none) &&
        (config->shadowControl != IfxDma_ChannelShadow_src) &&
        (config->shadowControl != IfxDma_ChannelShadow_dst))
    {
        channel->SHADR.U = config->shadowAddress;
    }
}


void IfxDma_Dma_createModuleHandle(IfxDma_Dma *dmaHandle, Ifx_DMA *dma)
{
    dmaHandle->dma = dma;
}


void IfxDma_Dma_deInitModule(IfxDma_Dma *dma)
{
    //TODO
}


void IfxDma_Dma_initChannel(IfxDma_Dma_Channel *channel, const IfxDma_Dma_ChannelConfig *config)
{
    Ifx_DMA *dma = config->module->dma;

    channel->dma       = dma;
    channel->channelId = config->channelId;
    channel->channel   = &dma->CH[config->channelId];

    IfxDma_Dma_configureTransactionSet(channel->channel, config);

    {
        Ifx_DMA_TSR tsr;
        tsr.U = 0;

        if (config->hardwareRequestEnabled)
        {
            tsr.B.ECH = 1;
        }
        else
        {
            tsr.B.DCH = 1;
        }

        dma->TSR[channel->channelId].U = tsr.U;
    }

    if (config->channelInterruptPriority > 0)
    {
        volatile Ifx_SRC_SRCR *src = IfxDma_getSrcPointer(channel->dma, channel->channelId);
        IfxSrc_init(src, config->channelInterruptTypeOfService, config->channelInterruptPriority);
        IfxSrc_enable(src);
    }
}


void IfxDma_Dma_initChannelConfig(IfxDma_Dma_ChannelConfig *config, IfxDma_Dma *dma)
{
    const IfxDma_Dma_ChannelConfig defaultConfig = {
        .module                                 = NULL_PTR,
        .channelId                              = IfxDma_ChannelId_0,
        .sourceAddress                          = 0,
        .destinationAddress                     = 0,
        .shadowAddress                          = 0,
        .readDataCrc                            = 0,
        .sourceDestinationAddressCrc            = 0,
        .transferCount                          = 0,
        .blockMode                              = IfxDma_ChannelMove_1,
        .requestMode                            = IfxDma_ChannelRequestMode_oneTransferPerRequest,
        .operationMode                          = IfxDma_ChannelOperationMode_single,
        .moveSize                               = IfxDma_ChannelMoveSize_8bit,
        .pattern                                = IfxDma_ChannelPattern_0_disable,
        .requestSource                          = IfxDma_ChannelRequestSource_peripheral,
        .busPriority                            = IfxDma_ChannelBusPriority_medium,
        .hardwareRequestEnabled                 = FALSE,
        .sourceAddressIncrementStep             = IfxDma_ChannelIncrementStep_1,
        .sourceAddressIncrementDirection        = IfxDma_ChannelIncrementDirection_positive,
        .sourceAddressCircularRange             = IfxDma_ChannelIncrementCircular_32768,
        .destinationAddressIncrementStep        = IfxDma_ChannelIncrementStep_1,
        .destinationAddressIncrementDirection   = IfxDma_ChannelIncrementDirection_positive,
        .destinationAddressCircularRange        = IfxDma_ChannelIncrementCircular_32768,
        .shadowControl                          = IfxDma_ChannelShadow_none,
        .sourceCircularBufferEnabled            = FALSE,
        .destinationCircularBufferEnabled       = FALSE,
        .timestampEnabled                       = FALSE,
        .wrapSourceInterruptEnabled             = FALSE,
        .wrapDestinationInterruptEnabled        = FALSE,
        .channelInterruptEnabled                = FALSE,
        .channelInterruptControl                = IfxDma_ChannelInterruptControl_thresholdLimitMatch,
        .interruptRaiseThreshold                = 0,
        .transactionRequestLostInterruptEnabled = FALSE,
        .channelInterruptPriority               = 0,
        .channelInterruptTypeOfService          = IfxSrc_Tos_cpu0
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* take over module pointer */
    config->module = dma;
}


void IfxDma_Dma_initLinkedListEntry(void *ptrToAddress, const IfxDma_Dma_ChannelConfig *config)
{
    IfxDma_Dma_configureTransactionSet((Ifx_DMA_CH *)ptrToAddress, config);
}


void IfxDma_Dma_initModule(IfxDma_Dma *dma, const IfxDma_Dma_Config *config)
{
    dma->dma = config->dma;
}


void IfxDma_Dma_initModuleConfig(IfxDma_Dma_Config *config, Ifx_DMA *dma)
{
    config->dma = dma;
}
