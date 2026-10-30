/**
 * \file IfxFce_Crc.c
 * \brief FCE CRC details
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

#include "IfxFce_Crc.h"

/******************************************************************************/
/*----------------------------------Macros------------------------------------*/
/******************************************************************************/

/** \brief As per UM, Before being able to configure a new value into the register of a CRC kernel,
 * software must first write the 0xFACECAFE value to CHECK and LENGTH registers
 */
#define IFXFCE_CRC_DEFAULT_LENGTH   (0xFACECAFEU)

/** \brief Write this value to clear the Error flag
 */
#define IFXFCE_CRC_CLEAR_ERROR_FLAG (0x00000000U)

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxFce_Crc_calculateCrcWithDma(IfxFce_Crc_Crc *fce, const uint32 *crcData, uint16 crcDataLength)
{
    Ifx_FCE                    *fceSFR    = fce->fce;
    volatile Ifx_FCE_IN_IR     *InputData = &fceSFR->IN[fce->crcChannel].IR;

    IfxDma_ChannelIncrementStep dmaIncrementStep;
    IfxDma_ChannelMoveSize      dmaChannelsize;

    if ((fce->crcKernel == IfxFce_CrcKernel_0) || (fce->crcKernel == IfxFce_CrcKernel_1))
    {
        dmaIncrementStep = IfxDma_ChannelIncrementStep_1;
        dmaChannelsize   = IfxDma_ChannelMoveSize_32bit;
    }
    else if (fce->crcKernel == IfxFce_CrcKernel_2)
    {
        dmaIncrementStep = IfxDma_ChannelIncrementStep_2;
        dmaChannelsize   = IfxDma_ChannelMoveSize_16bit;
    }
    else
    {
        dmaIncrementStep = IfxDma_ChannelIncrementStep_4;
        dmaChannelsize   = IfxDma_ChannelMoveSize_8bit;
    }

    IfxDma_setChannelSourceAddress(fce->fceDmaChannel.dma, fce->fceDmaChannel.channelId, (void *)IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreIndex(), crcData));
    IfxDma_setChannelDestinationAddress(fce->fceDmaChannel.dma, fce->fceDmaChannel.channelId, (void *)&InputData->U);
    IfxDma_setChannelTransferCount(fce->fceDmaChannel.dma, fce->fceDmaChannel.channelId, crcDataLength);
    IfxDma_setChannelMoveSize(fce->fceDmaChannel.dma, fce->fceDmaChannel.channelId, dmaChannelsize);
    IfxDma_setChannelDestinationIncrementStep(fce->fceDmaChannel.dma, fce->fceDmaChannel.channelId, dmaIncrementStep,
        IfxDma_ChannelIncrementDirection_positive, IfxDma_ChannelIncrementCircular_4);

    IfxDma_Dma_startChannelTransaction(&fce->fceDmaChannel);

    while (IfxDma_Dma_isChannelTransactionPending(&fce->fceDmaChannel) == TRUE)
    {}
}


uint32 IfxFce_Crc_calculateCrc(IfxFce_Crc_Crc *fce, const uint32 *crcData, uint16 crcDataLength, uint32 crcStartValue)
{
    Ifx_FCE          *fceSFR     = fce->fce;
    IfxFce_CrcChannel crcChannel = fce->crcChannel;
    uint32            inputDataCounter;
    uint32            crcResultValue;
    uint32           *dataPtr = (uint32 *)crcData;

    /* Set the Length */
    /* IfxFce_setChannelCrcLength: Replaced definition for the code optimization */
    /* As per the UM, write the dafault value 0xFACECAFE to the register before writing requested value */
    fce->fce->IN[crcChannel].LENGTH.U = IFXFCE_CRC_DEFAULT_LENGTH;
    fce->fce->IN[crcChannel].LENGTH.U = crcDataLength;

    /* Set the expected CRC */
    /* IfxFce_setExpectedCrc: Replaced definition for the code optimization */
    /* As per the UM, write the dafault value 0xFACECAFE to the register before writing requested value */
    fce->fce->IN[crcChannel].CHECK.U = IFXFCE_CRC_DEFAULT_LENGTH;
    fce->fce->IN[crcChannel].CHECK.U = fce->expectedCrc;

    /* Configure CRC register */
    /* IfxFce_setCrcstartValue: Replaced definition for the code optimization */
    fce->fce->IN[crcChannel].CRC.U = crcStartValue;

    volatile Ifx_FCE_IN_IR *InputData = &fceSFR->IN[fce->crcChannel].IR;

    if (fce->useDma == TRUE)
    {
        IfxFce_Crc_calculateCrcWithDma(fce, crcData, crcDataLength);
    }
    else
    {
        /* Input in INIT register */
        for (inputDataCounter = 0; inputDataCounter < crcDataLength; ++inputDataCounter)
        {
            InputData->U = *(dataPtr++);
        }
    }

    /* A delay of 2 clock cycles is needed after the write into IR register
     * Hence another Dummy read is added */
    crcResultValue = fceSFR->IN[fce->crcChannel].RES.U;
    /* Dummy read to ensure previous write is complete */
    crcResultValue = fceSFR->IN[fce->crcChannel].RES.U;

    return crcResultValue;
}


void IfxFce_Crc_clearErrorFlags(IfxFce_Crc_Crc *fce)
{
    /* IfxFce_clearCrcErrorFlags: Replaced definition for the code optimization */
    fce->fce->IN[fce->crcChannel].STS.U = IFXFCE_CRC_CLEAR_ERROR_FLAG;
}


void IfxFce_Crc_deInitModule(IfxFce_Crc_Crc *fce)
{
	/* Reset the FCE hardware module */
    IfxFce_resetModule(fce->fce);
}


Ifx_FCE_IN_STS IfxFce_Crc_getInterruptStatus(IfxFce_Crc_Crc *fce)
{
    /* IfxFce_getCrcInterruptStatus: Replaced definition for the code optimization */
    Ifx_FCE_IN_STS interruptStatus;
    interruptStatus.U = fce->fce->IN[fce->crcChannel].STS.U;

    return interruptStatus;
}


void IfxFce_Crc_initCrcWithDma(IfxFce_Crc_Crc *fceCrc, const IfxFce_Crc_CrcConfig *crcConfig)
{
    Ifx_DMA                 *dmaSFR = &MODULE_DMA;
    IfxDma_Dma               dma;
    IfxDma_Dma_createModuleHandle(&dma, dmaSFR);

    IfxDma_Dma_ChannelConfig dmaChannelCfg;
    IfxDma_Dma_initChannelConfig(&dmaChannelCfg, &dma);

    dmaChannelCfg.channelId                        = crcConfig->fceChannelId;
    dmaChannelCfg.requestMode                      = IfxDma_ChannelRequestMode_completeTransactionPerRequest;
    dmaChannelCfg.operationMode                    = IfxDma_ChannelOperationMode_continuous;
    dmaChannelCfg.destinationAddressCircularRange  = IfxDma_ChannelIncrementCircular_4,
    dmaChannelCfg.destinationCircularBufferEnabled = TRUE,
    IfxDma_Dma_initChannel(&fceCrc->fceDmaChannel, &dmaChannelCfg);
}


void IfxFce_Crc_initCrc(IfxFce_Crc_Crc *fceCrc, const IfxFce_Crc_CrcConfig *crcConfig)
{
    fceCrc->fce = crcConfig->fce;
    Ifx_FCE *fceSFR = crcConfig->fce;

    fceCrc->expectedCrc = crcConfig->expectedCrc;
    fceCrc->crcChannel  = crcConfig->crcChannel;
    fceCrc->crcKernel   = crcConfig->crcKernel;

    uint16 password = IfxScuWdt_getCpuWatchdogPassword();
    /* Clear Cpu endinit protection to allow register modification */
    IfxScuWdt_clearCpuEndinit(password);

    Ifx_FCE_IN_CFG tempCFG;

    tempCFG.U                               = 0;
    tempCFG.B.CMI                           = crcConfig->enabledInterrupts.crcMismatch;
    tempCFG.B.CEI                           = crcConfig->enabledInterrupts.configError;
    tempCFG.B.LEI                           = crcConfig->enabledInterrupts.lengthError;
    tempCFG.B.BEI                           = crcConfig->enabledInterrupts.busError;
    tempCFG.B.CCE                           = crcConfig->crcCheckCompared;
    tempCFG.B.ALR                           = crcConfig->automaticLengthReload;
    tempCFG.B.REFIN                         = crcConfig->dataByteReflectionEnabled;
    tempCFG.B.REFOUT                        = crcConfig->crc32BitReflectionEnabled;
    tempCFG.B.XSEL                          = crcConfig->crcResultInverted;
    tempCFG.B.BYTESWAP                      = crcConfig->swapOrderOfBytes;
    tempCFG.B.KERNEL                        = crcConfig->crcKernel;

    /* Write configuration to FCE channel configuration register */
    fceSFR->IN[crcConfig->crcChannel].CFG.U = tempCFG.U;

    /* Set Cpu endinit protection after register modification */
    IfxScuWdt_setCpuEndinit(password);

    /* Initialize DMA for CRC if enabled in configuration */
    if (crcConfig->useDma == TRUE)
    {
        IfxFce_Crc_initCrcWithDma(fceCrc, crcConfig);
    }
}


void IfxFce_Crc_initCrcConfig(IfxFce_Crc_CrcConfig *crcConfig, IfxFce_Crc *fce)
{
    crcConfig->fce                           = fce->fce;
    crcConfig->crcKernel                     = IfxFce_CrcKernel_0;
    crcConfig->crcChannel                    = IfxFce_CrcChannel_0;
    crcConfig->crcCheckCompared              = TRUE;
    crcConfig->automaticLengthReload         = FALSE;
    crcConfig->dataByteReflectionEnabled     = TRUE;
    crcConfig->crc32BitReflectionEnabled     = TRUE;
    crcConfig->swapOrderOfBytes              = FALSE;
    crcConfig->crcResultInverted             = TRUE;
    crcConfig->enabledInterrupts.crcMismatch = FALSE; /* Enable if CRC is already known */
    crcConfig->enabledInterrupts.configError = TRUE;
    crcConfig->enabledInterrupts.lengthError = TRUE;
    crcConfig->enabledInterrupts.busError    = TRUE;
    crcConfig->useDma                        = FALSE;
    crcConfig->fceChannelId                  = IfxDma_ChannelId_none;
}


void IfxFce_Crc_initModule(IfxFce_Crc *fce, const IfxFce_Crc_Config *config)
{
    fce->fce = config->fce;
    Ifx_FCE *fceSFR = config->fce;

    /* Enable the FCE hardware module */
    IfxFce_enableModule(fceSFR);

    /* IfxFce_getSrcPointer: Replaced definition for the code optimization */
    volatile Ifx_SRC_SRCR *src = &SRC_FCE0;
    /* Initialize interrupt source with configured type of service and priority */
    IfxSrc_init(src, config->isrTypeOfService, config->isrPriority);
    /* Enable the interrupt source */
    IfxSrc_enable(src);
}


void IfxFce_Crc_initModuleConfig(IfxFce_Crc_Config *config, Ifx_FCE *fce)
{
    config->fce              = fce;
    config->isrPriority      = 0;
    config->isrTypeOfService = IfxSrc_Tos_cpu0;
}
