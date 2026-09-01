/**
 * \file IfxPcieLib_Dma.c
 * \brief PCIE DMA details
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

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC45X)
#include "IfxPcieLib_Dma.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPcieLib_Dma_initModuleConfig(Ifx_PCIE_DSP_DMACAP *dmaCapSFR, IfxPcieLib_Dma_Config *config)
{
    const IfxPcieLib_Dma_Config defaultConfig = {
        .dmaSFR         = NULL_PTR,
        {
            .readDone   = 0x0u,
            .readAbort  = 0x0u,
            .writeDone  = 0x0u,
            .writeAbort = 0x0u
        },
        {
            {
                IfxPcieDma_ChannelArbWeight_4,
                IfxPcieDma_ChannelArbWeight_4,
                IfxPcieDma_ChannelArbWeight_4,
                IfxPcieDma_ChannelArbWeight_4
            },
            {
                IfxPcieDma_ChannelArbWeight_4,
                IfxPcieDma_ChannelArbWeight_4,
                IfxPcieDma_ChannelArbWeight_4,
                IfxPcieDma_ChannelArbWeight_4
            }
        }
    };
    *config        = defaultConfig;
    config->dmaSFR = dmaCapSFR;
}


IfxPcie_Status IfxPcieLib_Dma_initModule(IfxPcieLib_Dma *dma, IfxPcieLib_Dma_Config *config)
{
    IfxPcie_Status status = IfxPcie_Status_failure;
    uint8          channelIndex;

    if (config->dmaSFR != NULL_PTR)
    {
        dma->dmaSFR = config->dmaSFR;

        /* STEP 1: Reset the module engines */
        IfxPcieDma_softReset(dma->dmaSFR, IfxPcieDma_ChannelType_write);
        IfxPcieDma_softReset(dma->dmaSFR, IfxPcieDma_ChannelType_read);

        /* STEP 2: Set the Arbitration weights of channels */
        for (channelIndex = 0; channelIndex < IFXPCIE_CFG_NUM_DMA_WRITE_CHANNELS; channelIndex++)
        {
            IfxPcieDma_setChannelArbWeight(dma->dmaSFR, (IfxPcieDma_Channel)channelIndex, IfxPcieDma_ChannelType_write, config->arbitration.writeChannel[channelIndex]);
        }

        for (channelIndex = 0; channelIndex < IFXPCIE_CFG_NUM_DMA_READ_CHANNELS; channelIndex++)
        {
            IfxPcieDma_setChannelArbWeight(dma->dmaSFR, (IfxPcieDma_Channel)channelIndex, IfxPcieDma_ChannelType_read, config->arbitration.readChannel[channelIndex]);
        }

        /* STEP 3: Update the MSI Write Addresses */
        IfxPcieDma_setMsiAddr(dma->dmaSFR, IfxPcieDma_ChannelType_write, IfxPcieDma_InterruptType_done, config->msiAddress.writeDone);
        IfxPcieDma_setMsiAddr(dma->dmaSFR, IfxPcieDma_ChannelType_write, IfxPcieDma_InterruptType_abort, config->msiAddress.writeAbort);
        IfxPcieDma_setMsiAddr(dma->dmaSFR, IfxPcieDma_ChannelType_read, IfxPcieDma_InterruptType_done, config->msiAddress.readDone);
        IfxPcieDma_setMsiAddr(dma->dmaSFR, IfxPcieDma_ChannelType_read, IfxPcieDma_InterruptType_abort, config->msiAddress.readAbort);

        status = IfxPcie_Status_success;
    }

    return status;
}


void IfxPcieLib_Dma_initChannelConfig(Ifx_PCIE_DSP_DMACAP *dmaCapSFR, IfxPcieLib_Dma_ChannelCfg *dmaChannelCfg)
{
    const IfxPcieLib_Dma_ChannelCfg defaultConfig = {
        .dmaSFR  = NULL_PTR,
        .pcieSFR = NULL_PTR,
        .id      = IfxPcieDma_Channel_0,
        .type    = IfxPcieDma_ChannelType_read,
        .mode    = IfxPcieDma_ChannelMode_contextBased,
        {
            .U                    = 0x0u
        },
        {
            .srcAddr         = 0x0u,
            .destAddr        = 0x0u,
            .size            = 0x0u,
            .enableLocalInt  = FALSE,
            .enableRemoteInt = FALSE,
        },
        {
            .txListPtr            = NULL_PTR,
            .enableRemoteErrorInt = FALSE,
            .enableLocalErrorInt  = FALSE
        },
        {
            {
#if !defined(IFX_ILLD_PPU_USAGE)
                .typeOfService = IfxSrc_Tos_cpu0,
#else
                .typeOfService = IfxSrc_Tos_ppu,
#endif
                .priority      = 0x0u,
                .vmNumber      = IfxSrc_VmId_0,
                .intVector     = IfxPcie_IntVector_none
            },
            .maskLocalDoneInt  = FALSE,
            .maskLocalAbortInt = FALSE,
            .doneIntCallBack   = NULL_PTR,
            .abortIntCallBack  = NULL_PTR,
            .epModeMsiData     = 0x0u
        }
    };
    *dmaChannelCfg        = defaultConfig;
    dmaChannelCfg->dmaSFR = dmaCapSFR;
}


IfxPcie_Status IfxPcieLib_Dma_initChannel(IfxPcieLib_Dma_Channel *dmaChannel, IfxPcieLib_Dma_ChannelCfg *dmaChannelCfg)
{
    IfxPcie_Status       status = IfxPcie_Status_failure;
    Ifx_PCIE_DSP_DMACAP *dmaSFR = dmaChannelCfg->dmaSFR;
    dmaChannel->state = IfxPcieLib_Dma_State_configError;

    if ((IfxPcieDma_getChannelStatus(dmaSFR, dmaChannelCfg->id, dmaChannelCfg->type) != IfxPcieDma_ChannelStatus_running)       /* Check that Channel is not already running */
        && (IfxPcieDma_isEngineEnabled(dmaSFR, dmaChannelCfg->type) == TRUE))                                                   /* DMA Engine is enabled */
    {
        /* STEP 1: Update all Handle Parameters, State */
        dmaChannel->dmaSFR      = dmaSFR;
        dmaChannel->pcieSFR     = dmaChannelCfg->pcieSFR;
        dmaChannel->id          = dmaChannelCfg->id;
        dmaChannel->type        = dmaChannelCfg->type;
        dmaChannel->mode        = dmaChannelCfg->mode;
        dmaChannel->errorStatus = IfxPcieDma_Error_none;

        /* STEP 2: Configure Operation context */
        if (dmaChannel->mode == IfxPcieDma_ChannelMode_contextBased)                                                            /* Context Based Operation */
        {
            IfxPcieLib_Dma_ChannelContext *context = &(dmaChannel->context);
            context->srcAddr  = dmaChannelCfg->context.srcAddr;
            context->destAddr = dmaChannelCfg->context.destAddr;
            context->size     = dmaChannelCfg->context.size;

            if ((context->srcAddr != 0x0u)                                                                                  /* Valid Parameters for context */
                && (context->destAddr != 0x0u)
                && (context->size != 0u))
            {
                IfxPcieDma_setChannelSrcAddr(dmaSFR, dmaChannel->id, dmaChannel->type, context->srcAddr);
                IfxPcieDma_setChannelDestAddr(dmaSFR, dmaChannel->id, dmaChannel->type, context->destAddr);
                IfxPcieDma_setChannelTransferSize(dmaSFR, dmaChannel->id, dmaChannel->type, context->size);
                IfxPcieDma_disableChannelTxListOperation(dmaSFR, dmaChannel->id, dmaChannel->type);
                IfxPcieDma_enableChannelInterrupts(dmaSFR, dmaChannel->id, dmaChannel->type, dmaChannelCfg->context.enableLocalInt, dmaChannelCfg->context.enableRemoteInt);
            }
        }
        else                                                                                                                    /* Transfer List Based Operation */
        {
            if (dmaChannelCfg->transferList.txListPtr != NULL_PTR)
            {
                IfxPcieLib_Dma_TxList *txList = &(dmaChannel->transferList);
                txList->txListPtr           = dmaChannelCfg->transferList.txListPtr;
                txList->currentTxElementPtr = txList->txListPtr;
                IfxPcieDma_setChannelTxListPtr(dmaSFR, dmaChannel->id, dmaChannel->type, txList->txListPtr);
                IfxPcieDma_enableChannelTxListErrorInt(dmaSFR, dmaChannel->id, dmaChannel->type, dmaChannelCfg->transferList.enableLocalErrorInt, dmaChannelCfg->transferList.enableRemoteErrorInt);
                IfxPcieDma_enableChannelTxListOperation(dmaSFR, dmaChannel->id, dmaChannel->type);
            }
        }

        /* STEP 3: Configure the TLP Parameters */
        if (dmaChannelCfg->tlpParams.U != 0u)
        {
            IfxPcieDma_setChannelTlpParams(dmaSFR, dmaChannel->id, dmaChannel->type, dmaChannelCfg->tlpParams.U);
        }

        /* STEP 4: Configure the Interrupt Nodes and other settings */
        if ((dmaChannel->pcieSFR != NULL_PTR)                                                                                   /* local configuration */
            && (dmaChannelCfg->interrupt.localIntNode.priority != 0u))                                                          /* There exists a local Interrupt node */
        {
            IfxPcieLib_Device_initSrcNode(dmaChannelCfg->pcieSFR, dmaChannelCfg->pcieIndex, &(dmaChannelCfg->interrupt.localIntNode));
            IfxPcieDma_maskChannelInterrupts(dmaSFR, dmaChannel->id, dmaChannel->type, dmaChannelCfg->interrupt.maskLocalDoneInt, dmaChannelCfg->interrupt.maskLocalAbortInt);
            dmaChannel->doneIntCallBack  = dmaChannelCfg->interrupt.doneIntCallBack;
            dmaChannel->abortIntCallBack = dmaChannelCfg->interrupt.abortIntCallBack;
        }

        IfxPcieDma_setChannelMsiData(dmaSFR, dmaChannel->id, dmaChannel->type, dmaChannelCfg->interrupt.epModeMsiData);
        status            = IfxPcie_Status_success;
        dmaChannel->state = IfxPcieLib_Dma_State_initialized;
    }

    return status;
}


IfxPcie_Status IfxPcieLib_Dma_updateChannelContext(IfxPcieLib_Dma_Channel *dmaChannel, uint64 srcAddr, uint64 destAddr, uint32 size)
{
    IfxPcie_Status status = IfxPcie_Status_failure;

    if (IfxPcieDma_getChannelStatus(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type) != IfxPcieDma_ChannelStatus_running)  /* Channel isn't running */
    {
        if (dmaChannel->mode == IfxPcieDma_ChannelMode_contextBased)                                                            /* Channel is context based */
        {
            if ((srcAddr != 0x0u)                                                                                               /* Valid Parameters for context */
                && (destAddr != 0x0u)
                && (size != 0u))
            {
                IfxPcieDma_setChannelSrcAddr(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type, srcAddr);
                IfxPcieDma_setChannelDestAddr(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type, destAddr);
                IfxPcieDma_setChannelTransferSize(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type, size);

                IfxPcieLib_Dma_ChannelContext *context = &(dmaChannel->context);
                context->srcAddr  = srcAddr;
                context->destAddr = destAddr;
                context->size     = size;

                dmaChannel->state = IfxPcieLib_Dma_State_initialized;
                status            = IfxPcie_Status_success;
            }
        }
    }

    return status;
}


IfxPcie_Status IfxPcieLib_Dma_updateChannelTxListPtr(IfxPcieLib_Dma_Channel *dmaChannel, uint32 *txListPtr)
{
    IfxPcie_Status status = IfxPcie_Status_failure;

    if (IfxPcieDma_getChannelStatus(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type) != IfxPcieDma_ChannelStatus_running)  /* Channel isn't running */
    {
        if (dmaChannel->mode == IfxPcieDma_ChannelMode_txList)                                                                  /* Channel is TX List based */
        {
            if (txListPtr != NULL_PTR)                                                                                          /* Valid TX List address */
            {
                IfxPcieLib_Dma_TxList *txList = &(dmaChannel->transferList);
                txList->txListPtr           = txListPtr;
                txList->currentTxElementPtr = txListPtr;
                IfxPcieDma_setChannelTxListPtr(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type, txListPtr);
            }
        }
    }

    return status;
}


void IfxPcieLib_Dma_interruptHandler(IfxPcieLib_Dma_Channel *dmaChannel)
{
    IfxPcieDma_InterruptType intType = IfxPcieDma_getChannelPendingInterrupt(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type);

    if (intType == IfxPcieDma_InterruptType_done)
    {
        if (dmaChannel->doneIntCallBack != NULL_PTR)
        {
            (dmaChannel->doneIntCallBack)();
        }
    }
    else if (intType == IfxPcieDma_InterruptType_abort)
    {
        dmaChannel->state = IfxPcieLib_Dma_State_halted;
        IfxPcieDma_Error errorType = IfxPcieDma_getChannelError(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type);

        if (errorType != IfxPcieDma_Error_none)
        {
            dmaChannel->errorStatus = errorType;
        }

        if (dmaChannel->abortIntCallBack != NULL_PTR)
        {
            (dmaChannel->abortIntCallBack)();
        }
    }

    IfxPcieDma_clearChannelInterrupts(dmaChannel->dmaSFR, dmaChannel->id, dmaChannel->type, TRUE, TRUE);
}

#endif /* defined(DEVICE_TC4DX) || defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
