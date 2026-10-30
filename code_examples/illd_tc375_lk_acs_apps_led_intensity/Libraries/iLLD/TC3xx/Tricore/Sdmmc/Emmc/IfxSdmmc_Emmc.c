/**
 * \file IfxSdmmc_Emmc.c
 * \brief SDMMC EMMC details
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
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif
#if defined(DEVICE_TC33XED) || defined(DEVICE_TC37XED) ||  defined(DEVICE_TC38EVOX) || defined(DEVICE_TC39XB)
#include "IfxSdmmc_Emmc.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxSdmmc_Status IfxSdmmc_Emmc_initCard(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_CardConfig *cardConfig)
{
    IfxSdmmc_Status   status = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    
    /* Local pointer for emmc->sdmmcSFR*/
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR;

    /* Set up the SD card interface, power up the card */
    /* Power on bus */
    emmcPtr->PWR_CTRL.B.SD_BUS_PWR_VDD1 = 1;

    /* Enable the SD clock */
    emmcPtr->CLK_CTRL.B.SD_CLK_EN = 1;

    /* According to SD Card spec we've to wait for 74 cycles with CMD and DAT high */
    {
        uint32 loopCount = (IFXSDMMC_DELAY_74CYCLE_US * IFXSDMMC_1KMULTIPLIER) / IFXSDMMC_1KLOOPDELAY_US;
        uint32 index;

        for (index = 0; index < loopCount; ++index)
        {
            //do nothing
            __nop();
        }
    }

    status = IfxSdmmc_Emmc_identifyCard(emmc, cardConfig);

    if (status == IfxSdmmc_Status_success)
    {
        status = IfxSdmmc_Emmc_configureSpeedAndBusWidth(emmc, cardConfig);
    }

    if (status == IfxSdmmc_Status_success)
    {
        /* Explicitly set block size as 512 */
        status = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_setBlockLength, IFXSDMMC_BLOCKSIZE_512, IfxSdmmc_ResponseType_r1, &response);
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_identifyCard(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_CardConfig *cardConfig)
{
    IfxSdmmc_Status status = IfxSdmmc_Status_cardNotInitialised;

    /* Local pointer for emmc->sdmmcSFR*/
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* Initialize and identify the eMMC card */

    /* Reset the card (CMD0) */
    status = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_goIdleState, IFXSDMMC_ARG_NONE, IfxSdmmc_ResponseType_none, NULL_PTR);

    if (status == IfxSdmmc_Status_success)
    {
        /* Validate Access Mode (MMC_CMD1) */
        status = IfxSdmmc_Emmc_validateAccessMode(emmc);
    }

    if (status == IfxSdmmc_Status_success)
    {
        /* Read CID, CMD2 */
        status = IfxSdmmc_Emmc_readCid(emmc);

        if (status == IfxSdmmc_Status_success)
        {
            /* Set RCA, CMD3 */
            status = IfxSdmmc_Emmc_setRca(emmc, IFXSDMMC_RCACMD3);

            if (status == IfxSdmmc_Status_success)
            {
                /* Read CSD, CMD9 */
                status = IfxSdmmc_Emmc_readCsd(emmc);
            }
        }
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_configureSpeedAndBusWidth(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_CardConfig *cardConfig)
{
    IfxSdmmc_Status status = IfxSdmmc_Status_success;

    /* Local pointer for emmc->sdmmcSFR*/
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* Switch speed and bus width */
    /* Switch to transfer state (CMD7) */
    status = IfxSdmmc_Emmc_switchToTransferState(emmc);

    if (status == IfxSdmmc_Status_success)
    {
        /* Switch Bus Width if selected */
        if (cardConfig->dataWidth > IfxSdmmc_EmmcDataTransferWidth_1Bit)
        {
            status = IfxSdmmc_Emmc_switchBusWidth(emmc, cardConfig->dataWidth);
        }

        /* Switch Speed if selected */
        if (cardConfig->speedMode == IfxSdmmc_EmmcSpeedMode_highSpeedSdr)
        {
            status = IfxSdmmc_Emmc_switchToHighSpeed(emmc);

            if (status == IfxSdmmc_Status_success)
            {
                /* Configure clock parameters to 50MHz */
                IfxSdmmc_configureClock(emmcPtr, IFXSDMMC_FREQUENCY_50MHZ);
            }
        }
        else
        {
            /* Configure clock parameters to 26 MHz */
            IfxSdmmc_configureClock(emmcPtr, emmc->userFrequency);
        }
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_initHostController(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_HostConfig *hostConfig)
{
    IfxSdmmc_Status status = IfxSdmmc_Status_success;

    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* Set the bus voltage */
    emmcPtr->PWR_CTRL.B.SD_BUS_VOL_VDD1 = IFXSDMMC_BUS_VOLTAGE_SELECT_VDD;

    /* Set the data line timeout value */
    emmcPtr->TOUT_CTRL.B.TOUT_CNT = hostConfig->timeoutValue;

    /* Set card type as eMMC */
    emmcPtr->EMMC_CTRL.B.CARD_IS_EMMC = 1;

    /* Configure clock parameters */
    /* Set up clock for 400KHz now; we will change later */
    IfxSdmmc_configureClock(emmcPtr, IFXSDMMC_INIT_FREQUENCY);
    emmc->userFrequency = hostConfig->frequency;

    /* Enable internal clock */
    status = IfxSdmmc_setUpInternalClock(emmcPtr);

    /* Enable Host version 4 */
    IfxSdmmc_enableHostControllerVersion4(emmcPtr);
    emmcPtr->HOST_CTRL2.B.HOST_VER4_ENABLE = 1;

    /* Update ADMA2 length mode to 26 bits (supported) */
    emmcPtr->HOST_CTRL2.B.ADMA2_LEN_MODE = IfxSdmmc_Adma2LengthMode_26Bit;

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_initModule(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_Config *config)
{
    IfxSdmmc_Status status   = IfxSdmmc_Status_success;

    Ifx_SDMMC      *sdmmcSFR = config->sdmmcSFR;
    emmc->sdmmcSFR = sdmmcSFR;
    emmc->dmaUsed  = config->useDma;
    emmc->dmaType  = config->dmaConfig.dmaType;

    /* Enable module */
    IfxSdmmc_enableModule(config->sdmmcSFR);

    config->sdmmcSFR->SW_RST.U |= 1;

    /* Initialize the host controller for the card type */
    IfxSdmmc_Emmc_initHostController(emmc, &config->hostConfig);

    /* Set DMA type if DMA is used for transfers */
    if (config->useDma)
    {
        emmc->sdmmcSFR->HOST_CTRL1.B.DMA_SEL = config->dmaConfig.dmaType;
    }

    IfxSdmmc_Emmc_configureInterrupt(emmc, &config->interruptConfig);

    /* Setup pins */
    if (config->pins != NULL_PTR)
    {
        IfxSdmmc_Emmc_setupPins(emmc, config->pins);
    }

    /* Set up, initialize and identify the card  */
    status = IfxSdmmc_Emmc_initCard(emmc, &config->cardConfig);

    return status;
}


void IfxSdmmc_Emmc_configureInterrupt(IfxSdmmc_Emmc *emmc, IfxSdmmc_InterruptConfig *interruptConfig)
{
    Ifx_SDMMC *sdmmcSFR = emmc->sdmmcSFR;

    /* Enable the necessary normal interrupt status flags */
    IfxSdmmc_enableNormalInterruptStatus(sdmmcSFR, IfxSdmmc_NormalInterrupt_commandComplete);
    IfxSdmmc_enableNormalInterruptStatus(sdmmcSFR, IfxSdmmc_NormalInterrupt_transferComplete);
    IfxSdmmc_enableNormalInterruptStatus(sdmmcSFR, IfxSdmmc_NormalInterrupt_dma);
    IfxSdmmc_enableNormalInterruptStatus(sdmmcSFR, IfxSdmmc_NormalInterrupt_bufferWriteReady);
    IfxSdmmc_enableNormalInterruptStatus(sdmmcSFR, IfxSdmmc_NormalInterrupt_bufferReadReady);
    /* Enable all the error interrupt status flags */
    IfxSdmmc_enableAllErrorInterruptStatus(sdmmcSFR);

    /* Initialize the normal interrupts */
    if (interruptConfig->priority > 0)
    {
        if (interruptConfig->commandCompleteInterruptEnable)
        {
            IfxSdmmc_enableNormalInterrupt(sdmmcSFR, IfxSdmmc_NormalInterrupt_commandComplete);
        }

        if (interruptConfig->transferCompleteInterruptEnable)
        {
            IfxSdmmc_enableNormalInterrupt(sdmmcSFR, IfxSdmmc_NormalInterrupt_transferComplete);
        }

        if (interruptConfig->dmaInterruptEnable)
        {
            IfxSdmmc_enableNormalInterrupt(sdmmcSFR, IfxSdmmc_NormalInterrupt_dma);
        }

        if (interruptConfig->commandTimeoutInterruptEnable)
        {
            IfxSdmmc_enableErrorInterrupt(sdmmcSFR, IfxSdmmc_ErrorInterrupt_commandTimeout);
        }

        if (interruptConfig->dataTimeoutInterruptEnable)
        {
            IfxSdmmc_enableErrorInterrupt(sdmmcSFR, IfxSdmmc_ErrorInterrupt_dataTimeout);
        }

        /* Initialize service request node */
        volatile Ifx_SRC_SRCR *srcSFR;
        srcSFR = IfxSdmmc_getSrcPointer(sdmmcSFR, IfxSdmmc_InterruptType_normal);
        IfxSrc_init(srcSFR, interruptConfig->provider, interruptConfig->priority);
        IfxSrc_enable(srcSFR);
    }
}


void IfxSdmmc_Emmc_initModuleConfig(IfxSdmmc_Emmc_Config *config, Ifx_SDMMC *sdmmcSFR)
{
    const IfxSdmmc_Emmc_Config defaultConfig = {
        .sdmmcSFR   = NULL_PTR,
        .hostConfig = {
            .timeoutValue    = IfxSdmmc_DataLineTimeout_2Power27,
            .usePresetValues = TRUE,
            .frequency       = IFXSDMMC_FREQUENCY_26MHZ
        },
        .interruptConfig                     = {
            .commandCompleteInterruptEnable  = FALSE,
            .transferCompleteInterruptEnable = FALSE,
            .dmaInterruptEnable              = FALSE,
            .commandTimeoutInterruptEnable   = FALSE,
            .dataTimeoutInterruptEnable      = FALSE,
            .priority                        = 0,
            .provider                        = IfxSrc_Tos_cpu0
        },
        .pins       = NULL_PTR,
        .cardConfig = {
            .dataWidth = IfxSdmmc_EmmcDataTransferWidth_1Bit,
            .speedMode = IfxSdmmc_EmmcSpeedMode_legacy
        },
        .useDma    = FALSE,
        .dmaConfig = {
            .dmaType                         = IfxSdmmc_DmaType_sdma
        }
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* Take over module pointer */
    config->sdmmcSFR = sdmmcSFR;
}


IfxSdmmc_Status IfxSdmmc_Emmc_readBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data)
{
    IfxSdmmc_Status status  = IfxSdmmc_Status_success;
    uint32          timeout = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* If the card is not initialized */
    if ((emmc->cardState & (uint8)IfxSdmmc_CardState_notInitialised) != 0U)
    {
        status = IfxSdmmc_Status_cardNotInitialised;
    }
    else
    {

        /* If byte Addressing, then multiply by 512 bytes */
        if ((uint32)emmc->cardCapacity == (uint32)IfxSdmmc_EmmcCardCapacity_byteAddressing)
        {
            address = (uint32)(address * IFXSDMMC_BLOCK_SIZE_DEFAULT);
        }

        if (emmc->dmaUsed == TRUE)
        {
            if (emmc->dmaType == IfxSdmmc_DmaType_adma2)
            {
                status = IfxSdmmc_Emmc_singleBlockAdma2Transfer(emmc, IfxSdmmc_Command_readSingleBlock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, data, IfxSdmmc_TransferDirection_read);
            }
            else
            {
                status = IfxSdmmc_Emmc_singleBlockDmaTransfer(emmc, IfxSdmmc_Command_readSingleBlock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, data, IfxSdmmc_TransferDirection_read);
            }
        }
        else
        {
            /* Single block transfer function */
            status = IfxSdmmc_Emmc_singleBlockTransfer(emmc, IfxSdmmc_Command_readSingleBlock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, data, IfxSdmmc_TransferDirection_read);
        }
    }

    /* Wait for until the command OR data lines aren't busy */
    /* Check if command and data lines are free */
    timeout = IFXSDMMC_TIMEOUT_1E6;

    while ((emmcPtr->PSTATE_REG.B.CMD_INHIBIT_DAT || emmcPtr->PSTATE_REG.B.CMD_INHIBIT) && (timeout > 0))
    {
        timeout--;
    }

    if (timeout == 0)
    {
        status = IfxSdmmc_Status_timeout;
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_readCid(IfxSdmmc_Emmc *emmc)
{
    IfxSdmmc_Status   status = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    
    /* Local pointer for emmc->sdmmcSFR*/
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    status                = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_allSendCID, IFXSDMMC_ARG_NONE, IfxSdmmc_ResponseType_r2, &response);
    emmc->cardInfo.cid[0] = response.resp01;
    emmc->cardInfo.cid[1] = response.resp23;
    emmc->cardInfo.cid[2] = response.resp45;
    emmc->cardInfo.cid[3] = response.resp67;

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_readCsd(IfxSdmmc_Emmc *emmc)
{
    IfxSdmmc_Status   status   = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    uint32            argument = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    argument              = (uint32)(emmc->cardInfo.rca << IFXSDMMC_BITSHIFT_POS16);
    status                = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_sendCSD, argument, IfxSdmmc_ResponseType_r2, &response);
    emmc->cardInfo.csd[0] = response.resp01;
    emmc->cardInfo.csd[1] = response.resp23;
    emmc->cardInfo.csd[2] = response.resp45;
    emmc->cardInfo.csd[3] = response.resp67;
    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_setRca(IfxSdmmc_Emmc *emmc, uint16 rca)
{
    IfxSdmmc_Status   status   = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    uint32            argument = (IFXSDMMC_ARG_NONE | (uint32)(rca << IFXSDMMC_BITSHIFT_POS16));
    status = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_mmcSetRelativeAddress, argument, IfxSdmmc_ResponseType_r1, &response);

    if (status == IfxSdmmc_Status_success)
    {
        emmc->cardInfo.rca = rca;
    }
    else
    {
        emmc->cardInfo.rca = IFXSDMMC_RCA_NONE;
    }

    return status;
}


void IfxSdmmc_Emmc_setupPins(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_Pins *pins)
{
    IFX_UNUSED_PARAMETER(emmc)
    IfxPort_InputMode inMode = pins->inputMode;
    IfxPort_PadDriver    speedGrade = pins->pinDriver;

    IfxSdmmc_Clk_Out    *clk        = pins->clk;
    IfxSdmmc_Cmd_InOut  *cmd        = pins->cmd;
    IfxSdmmc_Dat0_InOut *dat0       = pins->dat0;
    IfxSdmmc_Dat1_InOut *dat1       = pins->dat1;
    IfxSdmmc_Dat2_InOut *dat2       = pins->dat2;
    IfxSdmmc_Dat3_InOut *dat3       = pins->dat3;
    IfxSdmmc_Dat4_InOut *dat4       = pins->dat4;
    IfxSdmmc_Dat5_InOut *dat5       = pins->dat5;
    IfxSdmmc_Dat6_InOut *dat6       = pins->dat6;
    IfxSdmmc_Dat7_InOut *dat7       = pins->dat7;

    if (clk != NULL_PTR)
    {
        IfxPort_setPinModeOutput(clk->pin.port, clk->pin.pinIndex, IfxPort_OutputMode_pushPull, clk->outSelect);
        IfxPort_setPinPadDriver(clk->pin.port, clk->pin.pinIndex, speedGrade);
    }

    if (cmd != NULL_PTR)
    {
        IfxPort_setPinModeInput(cmd->pin.port, cmd->pin.pinIndex, inMode);
        IfxPort_setPinPadDriver(cmd->pin.port, cmd->pin.pinIndex, speedGrade);
    }

    if (dat0 != NULL_PTR)
    {
        IfxPort_setPinModeInput(dat0->pin.port, dat0->pin.pinIndex, inMode);
        IfxPort_setPinPadDriver(dat0->pin.port, dat0->pin.pinIndex, speedGrade);
    }

    if (dat1 != NULL_PTR)
    {
        IfxPort_setPinModeInput(dat1->pin.port, dat1->pin.pinIndex, inMode);
        IfxPort_setPinPadDriver(dat1->pin.port, dat1->pin.pinIndex, speedGrade);
    }

    if (dat2 != NULL_PTR)
    {
        IfxPort_setPinModeInput(dat2->pin.port, dat2->pin.pinIndex, inMode);
        IfxPort_setPinPadDriver(dat2->pin.port, dat2->pin.pinIndex, speedGrade);
    }

    if (dat3 != NULL_PTR)
    {
        IfxPort_setPinModeInput(dat3->pin.port, dat3->pin.pinIndex, inMode);
        IfxPort_setPinPadDriver(dat3->pin.port, dat3->pin.pinIndex, speedGrade);
    }

    if (dat4 != NULL_PTR)
    {
        IfxPort_setPinModeInput(dat4->pin.port, dat4->pin.pinIndex, inMode);
        IfxPort_setPinPadDriver(dat4->pin.port, dat4->pin.pinIndex, speedGrade);
    }

    if (dat5 != NULL_PTR)
    {
        IfxPort_setPinModeInput(dat5->pin.port, dat5->pin.pinIndex, inMode);
        IfxPort_setPinPadDriver(dat5->pin.port, dat5->pin.pinIndex, speedGrade);
    }

    if (dat6 != NULL_PTR)
    {
        IfxPort_setPinModeInput(dat6->pin.port, dat6->pin.pinIndex, inMode);
        IfxPort_setPinPadDriver(dat6->pin.port, dat6->pin.pinIndex, speedGrade);
    }

    if (dat7 != NULL_PTR)
    {
        IfxPort_setPinModeInput(dat7->pin.port, dat7->pin.pinIndex, inMode);
        IfxPort_setPinPadDriver(dat7->pin.port, dat7->pin.pinIndex, speedGrade);
    }
}


IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockAdma2Transfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *descrAddress, IfxSdmmc_TransferDirection direction)
{
    IfxSdmmc_Status   status  = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    uint32            timeout = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* Set the system address */
    IfxSdmmc_setSystemAddressForDma(emmcPtr, (uint32)descrAddress);

    emmcPtr->BLOCKSIZE.B.XFER_BLOCK_SIZE = blockSize;
	
    emmcPtr->XFER_MODE.B.MULTI_BLK_SEL = FALSE;

    /* Disable block count in transfer mode */
    emmcPtr->XFER_MODE.B.BLOCK_COUNT_ENABLE = 0;

    /* Enable DMA transfers */
    emmcPtr->XFER_MODE.B.DMA_ENABLE = 1;

    /* Set transfer direction in host controller */
    emmcPtr->XFER_MODE.B.DATA_XFER_DIR = direction;

    status = IfxSdmmc_sendCommand(emmcPtr, command, address, IfxSdmmc_ResponseType_r1, &response);

    if (status == IfxSdmmc_Status_success)
    {
        timeout = IFXSDMMC_TIMEOUT_1E5; 

        /* Wait until transfer complete or ADMA error flags are set */
        while ((IfxSdmmc_isNormalInterruptOccured(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete) == 0)
               && (IfxSdmmc_isErrorInterruptOccured(emmcPtr, IfxSdmmc_ErrorInterrupt_adma) == 0)
               && (timeout > 0))
        {
            timeout--;
        }

        if ((timeout == 0) || (IfxSdmmc_isErrorInterruptOccured(emmcPtr, IfxSdmmc_ErrorInterrupt_adma) != 0))
        {
            status = IfxSdmmc_Status_dataError;

            if (IfxSdmmc_isErrorInterruptOccured(emmcPtr, IfxSdmmc_ErrorInterrupt_adma) != 0)
            {
                IfxSdmmc_clearErrorInterrupt(emmcPtr, IfxSdmmc_ErrorInterrupt_adma);
            }

        }
        else
        {
            IfxSdmmc_clearNormalInterrupt(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete);
        }
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockDmaTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction)
{
    IfxSdmmc_Status   status  = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    uint32            timeout = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* Set the system address */
    IfxSdmmc_setSystemAddressForDma(emmcPtr, (uint32)data);

    emmcPtr->BLOCKSIZE.B.XFER_BLOCK_SIZE = blockSize;
	
    emmcPtr->XFER_MODE.B.MULTI_BLK_SEL = FALSE;

    /* Disable block count in transfer mode */
    IfxSdmmc_disableBlockCount(emmcPtr);
    emmcPtr->XFER_MODE.B.BLOCK_COUNT_ENABLE = 0;

    /* Enable DMA transfers */
    emmcPtr->XFER_MODE.B.DMA_ENABLE = 1;

    /* Set transfer direction in host controller */
    emmcPtr->XFER_MODE.B.DATA_XFER_DIR = direction;

    status = IfxSdmmc_sendCommand(emmcPtr, command, address, IfxSdmmc_ResponseType_r1, &response);

    if (status == IfxSdmmc_Status_success)
    {
        timeout = IFXSDMMC_TIMEOUT_1E6; 

        /* Wait until transfer complete flag is set */
        while ((IfxSdmmc_isNormalInterruptOccured(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete) == 0) && (timeout > 0))
        {
            timeout--;
        }

        if (timeout == 0)
        {
            status = IfxSdmmc_Status_dataError;
            /* FIME: implement abort command process */
        }
        else
        {
            IfxSdmmc_clearNormalInterrupt(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete);
        }
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction)
{
    IfxSdmmc_Status       status       = IfxSdmmc_Status_success;
    IfxSdmmc_Response     response;
    IfxSdmmc_ResponseType responseType = IfxSdmmc_ResponseType_r1;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    uint32                loopIndex    = 0;
    uint32                timeout      = 0;
    uint32                numWords     = (uint32)((blockSize + 3) >> IFXSDMMC_BITSHIFT_POS2);

    emmcPtr->BLOCKSIZE.B.XFER_BLOCK_SIZE = blockSize;
	
    emmcPtr->XFER_MODE.B.MULTI_BLK_SEL = FALSE;

    /* Disable block count in transfer mode */
    emmcPtr->XFER_MODE.B.BLOCK_COUNT_ENABLE = 0;

    /* Set transfer direction in host controller */
    emmcPtr->XFER_MODE.B.DATA_XFER_DIR = direction;

    status = IfxSdmmc_sendCommand(emmcPtr, command, address, responseType, &response);

    if (status == IfxSdmmc_Status_success)
    {
        if (direction == IfxSdmmc_TransferDirection_read)
        {
            timeout = IFXSDMMC_TIMEOUT_1E6; 

            /* Wait until Read ready flag is set */
            while ((IfxSdmmc_isNormalInterruptOccured(emmcPtr, IfxSdmmc_NormalInterrupt_bufferReadReady) == 0) && (timeout > 0))
            {
                timeout--;
            }

            if (timeout == 0)
            {
                status = IfxSdmmc_Status_dataError;
            }
            else
            {
                IfxSdmmc_clearNormalInterrupt(emmcPtr, IfxSdmmc_NormalInterrupt_bufferReadReady);
            }
        }
    }

    if (status == IfxSdmmc_Status_success)
    {
        /* Perform data transfer */
        /* 4 bytes data transmission in each iteration */
        for (loopIndex = 0U; loopIndex < numWords; loopIndex++)
        {
            if (direction == IfxSdmmc_TransferDirection_read)
            {
                *data = (uint32)emmcPtr->BUF_DATA.U;
            }

            if (direction == IfxSdmmc_TransferDirection_write)
            {
                emmcPtr->BUF_DATA.U = *data;
            }

            data++;
        }

        timeout = IFXSDMMC_TIMEOUT_1E6; 

        /* Wait until transfer complete flag is set */
        while ((IfxSdmmc_isNormalInterruptOccured(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete) == 0) && (timeout > 0))
        {
            timeout--;
        }

        if (timeout == 0)
        {
            status = IfxSdmmc_Status_dataError;
        }
        else
        {
            IfxSdmmc_clearNormalInterrupt(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete);
        }
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_switchBusWidth(IfxSdmmc_Emmc *emmc, IfxSdmmc_EmmcDataTransferWidth busWidth)
{
    IfxSdmmc_Status   status   = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    uint32            argument = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    if (busWidth == IfxSdmmc_EmmcDataTransferWidth_4Bit)
    {
        argument = IFXSDMMC_ARG_MMC_BUSWIDTH_4;
    }

    else if (busWidth == IfxSdmmc_EmmcDataTransferWidth_8Bit)
    {
        argument = IFXSDMMC_ARG_MMC_BUSWIDTH_8;
    }

    /* Set the bus width on the host controller */
    IfxSdmmc_setEmmcDataTransferWidth(emmcPtr, busWidth);

    /* Switch card to desired bus width (CMD6) */
    status = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_mmcSwitchFunction, argument, IfxSdmmc_ResponseType_r1b, &response);

    /* If switch failed, change the bus width back to 1 bit */
    if (status != IfxSdmmc_Status_success)
    {
        IfxSdmmc_setEmmcDataTransferWidth(emmcPtr, IfxSdmmc_EmmcDataTransferWidth_1Bit);
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_switchToHighSpeed(IfxSdmmc_Emmc *emmc)
{
    IfxSdmmc_Status   status = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* Switch card to high speed (CMD6) */
    status = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_mmcSwitchFunction, IFXSDMMC_ARG_MMC_HIGHSPEED, IfxSdmmc_ResponseType_r1b, &response);

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_switchToTransferState(IfxSdmmc_Emmc *emmc)
{
    IfxSdmmc_Status   status   = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    uint32            argument = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    argument |= (uint32)(emmc->cardInfo.rca << IFXSDMMC_BITSHIFT_POS16);

    /* Read card status CMD13 */
    status = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_sendStatus, argument, IfxSdmmc_ResponseType_r1, &response);

    if (status == IfxSdmmc_Status_success)
    {
        /* If the card is not in transfer state already Switch to transfer state (CMD7) */
        if (response.cardStatus.B.currentState != 4)
        {
            status = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_selectDeselectCard, argument, IfxSdmmc_ResponseType_r1b, &response);
        }
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_validateAccessMode(IfxSdmmc_Emmc *emmc)
{
    IfxSdmmc_Status   status  = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    uint32            timeout = (uint32)0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    timeout = (uint32)IFXSDMMC_TIMEOUT_1E6; 

    /* Validate access mode (MMC_CMD1) */
    do
    {
        status = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_mmcSendOpCond, IFXSDMMC_ARG_MMCCMD1, IfxSdmmc_ResponseType_r3, &response);
        timeout--;
    } while (((response.resp01 >> IFXSDMMC_BITSHIFT_POS31) & 0x1) != 1 && (timeout > (uint32)0));

    if (status == IfxSdmmc_Status_success)
    {
        /* Check if pattern matches in both the argument and response */
        if (response.resp01 == IFXSDMMC_CARDCAPACITY_BYTEADDRESSING_PATTERN)
        {
            emmc->cardCapacity = (uint8)IfxSdmmc_EmmcCardCapacity_byteAddressing;
        }
        else if (response.resp01 == IFXSDMMC_CARDCAPACITY_SECTORADDRESSING_PATTERN)
        {
            emmc->cardCapacity = (uint8)IfxSdmmc_EmmcCardCapacity_sectorAddressing;
        }
        else /* ((response.resp01 != 0x80FF8080) && (response.resp01 != 0xC0FF8080)) */
        {
            status = IfxSdmmc_Status_badResponse; /* Device is not compliant */
            emmcPtr->PWR_CTRL.B.SD_BUS_PWR_VDD1 = 0; /* Set bus power off */
            /* Update card initialization status */
            emmc->cardState &= (uint8)~((uint8)IfxSdmmc_CardState_notInitialised | (uint8)IfxSdmmc_CardState_noCard);
        }
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_writeBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data)
{
    IfxSdmmc_Status status  = IfxSdmmc_Status_success;
    uint32          timeout = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* If the card is not initialized */
    if ((emmc->cardState & (uint8)IfxSdmmc_CardState_notInitialised) != 0U)
    {
        status = IfxSdmmc_Status_cardNotInitialised;
    }
    else
    {

        /* If byte addressing, then multiply by 512 bytes */
        if ((uint32)emmc->cardCapacity == (uint32)IfxSdmmc_EmmcCardCapacity_byteAddressing)
        {
            address = (uint32)(address * IFXSDMMC_BLOCK_SIZE_DEFAULT);
        }

        if (emmc->dmaUsed == TRUE)
        {
            if (emmc->dmaType == IfxSdmmc_DmaType_adma2)
            {
                status = IfxSdmmc_Emmc_singleBlockAdma2Transfer(emmc, IfxSdmmc_Command_writeBlock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, data, IfxSdmmc_TransferDirection_write);
            }
            else
            {
                status = IfxSdmmc_Emmc_singleBlockDmaTransfer(emmc, IfxSdmmc_Command_writeBlock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, data, IfxSdmmc_TransferDirection_write);
            }
        }
        else
        {
            /* Single block transfer function */
            status = IfxSdmmc_Emmc_singleBlockTransfer(emmc, IfxSdmmc_Command_writeBlock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, data, IfxSdmmc_TransferDirection_write);
        }

        if ((status == IfxSdmmc_Status_success) || (status == IfxSdmmc_Status_bufferReady))
        {
            status = IfxSdmmc_Status_success;
        }
        else
        {
            status = IfxSdmmc_Status_failure;
        }
    }

    /* Wait for until the command OR data lines aren't busy */
    /* Check if command and data lines are free */
    timeout = IFXSDMMC_TIMEOUT_1E6; 

    while ((emmcPtr->PSTATE_REG.B.CMD_INHIBIT_DAT || emmcPtr->PSTATE_REG.B.CMD_INHIBIT) && (timeout > 0))
    {
        timeout--;
    }

    if (timeout == 0)
    {
        status = IfxSdmmc_Status_timeout;
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_eraseBlocks(IfxSdmmc_Emmc *emmc, uint32 startAddress, uint32 endAddress)
{
    IfxSdmmc_Status   status   = IfxSdmmc_Status_success;
    uint32            argument = (uint32)0;
    IfxSdmmc_Response response;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* If the card is not initialized */
    if ((emmc->cardState & (uint8)IfxSdmmc_CardState_notInitialised) != 0U)
    {
        status = IfxSdmmc_Status_cardNotInitialised;
    }
    else
    {

        /* If byte addressing, then multiply by 512 bytes */
        if ((uint32)emmc->cardCapacity == (uint32)IfxSdmmc_EmmcCardCapacity_byteAddressing)
        {
            startAddress = (uint32)(startAddress * IFXSDMMC_BLOCK_SIZE_DEFAULT);
            endAddress   = (uint32)(endAddress * IFXSDMMC_BLOCK_SIZE_DEFAULT);
        }

        /* Set the Start Address */
        argument = startAddress;
        status   = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_mmcEraseGroupStart, argument, IfxSdmmc_ResponseType_r1, &response);

        if (status == IfxSdmmc_Status_success)
        {
            /* Set the end Address */
            argument = endAddress;
            status   = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_mmcEraseGroupEnd, argument, IfxSdmmc_ResponseType_r1, &response);

            if (status == IfxSdmmc_Status_success)
            {
                /* Send the TRIM command to erase */
                argument = IFXSDMMC_ARG_CMD38_TRIM;
                status   = IfxSdmmc_sendCommand(emmcPtr, IfxSdmmc_Command_erase, argument, IfxSdmmc_ResponseType_r1b, &response);
            }
        }
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_readMultiBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data, uint32 numBlocks)
{
    IfxSdmmc_Status status  = IfxSdmmc_Status_success;
    uint32          timeout = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* If the card is not initialized */
    if ((emmc->cardState & (uint8)IfxSdmmc_CardState_notInitialised) != 0U)
    {
        status = IfxSdmmc_Status_cardNotInitialised;
    }
    else
    {
        /* If byte Addressing, then multiply by 512 bytes */
        if ((uint32)emmc->cardCapacity == (uint32)IfxSdmmc_EmmcCardCapacity_byteAddressing)
        {
            address = (uint32)(address * IFXSDMMC_BLOCK_SIZE_DEFAULT);
        }

        if (emmc->dmaUsed == TRUE)
        {
            if (emmc->dmaType == IfxSdmmc_DmaType_adma2)
            {
                status = IfxSdmmc_Emmc_multiBlockAdma2Transfer(emmc, IfxSdmmc_Command_readMultipleBLock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, (uint16)numBlocks, data, IfxSdmmc_TransferDirection_read);
            }
            else
            {
                status = IfxSdmmc_Status_failure;  /* Only ADMA2 support currently */
            }
        }
        else
        {
            /* Single block transfer function */
            status = IfxSdmmc_Emmc_multiBlockTransfer(emmc, IfxSdmmc_Command_readMultipleBLock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, (uint16)numBlocks, data, IfxSdmmc_TransferDirection_read);
        }
    }

    /* Wait for until the command OR data lines aren't busy */
    /* Check if command and data lines are free */
    timeout = IFXSDMMC_TIMEOUT_1E6; 

    while ((emmcPtr->PSTATE_REG.B.CMD_INHIBIT_DAT || emmcPtr->PSTATE_REG.B.CMD_INHIBIT) && (timeout > 0))
    {
        timeout--;
    }

    if (timeout == 0)
    {
        status = IfxSdmmc_Status_timeout;
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_writeMultiBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data, uint32 numBlocks)
{
    IfxSdmmc_Status status  = IfxSdmmc_Status_success;
    uint32          timeout = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* If the card is not initialized */
    if ((emmc->cardState & (uint8)IfxSdmmc_CardState_notInitialised) != 0U)
    {
        status = IfxSdmmc_Status_cardNotInitialised;
    }
    else
    {
        /* If byte addressing, then multiply by 512 bytes */
        if ((uint32)emmc->cardCapacity == (uint32)IfxSdmmc_EmmcCardCapacity_byteAddressing)
        {
            address = (uint32)(address * IFXSDMMC_BLOCK_SIZE_DEFAULT);
        }

        if (emmc->dmaUsed == TRUE)
        {
            if (emmc->dmaType == IfxSdmmc_DmaType_adma2)
            {
                status = IfxSdmmc_Emmc_multiBlockAdma2Transfer(emmc, IfxSdmmc_Command_writeMultipleBlock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, (uint16)numBlocks, data, IfxSdmmc_TransferDirection_write);
            }
            else
            {
                status = IfxSdmmc_Status_failure;  /* Only ADMA2 support currently */
            }
        }
        else
        {
            /* Single block transfer function */
            status = IfxSdmmc_Emmc_multiBlockTransfer(emmc, IfxSdmmc_Command_writeMultipleBlock, address, IFXSDMMC_BLOCK_SIZE_DEFAULT, (uint16)numBlocks, data, IfxSdmmc_TransferDirection_write);
        }

        if ((status == IfxSdmmc_Status_success) || (status == IfxSdmmc_Status_bufferReady))
        {
            status = IfxSdmmc_Status_success;
        }
        else
        {
            status = IfxSdmmc_Status_failure;
        }
    }

    /* Wait for until the command OR data lines aren't busy */
    /* Check if command and data lines are free */
    timeout = IFXSDMMC_TIMEOUT_1E6; 

    while ((emmcPtr->PSTATE_REG.B.CMD_INHIBIT_DAT || emmcPtr->PSTATE_REG.B.CMD_INHIBIT) && (timeout > 0))
    {
        timeout--;
    }

    if (timeout == 0)
    {
        status = IfxSdmmc_Status_timeout;
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_multiBlockTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint16 numBlocks, uint32 *data, IfxSdmmc_TransferDirection direction)
{
    IfxSdmmc_Status       status       = IfxSdmmc_Status_success;
    IfxSdmmc_Response     response;
    IfxSdmmc_ResponseType responseType = IfxSdmmc_ResponseType_r1;

    uint32                loopIndex    = 0;
    uint32                timeout      = 0;
    uint32                numWords     = (uint32)((blockSize + 3) >> IFXSDMMC_BITSHIFT_POS2);
    uint32                blockIndex   = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    emmcPtr->BLOCKSIZE.B.XFER_BLOCK_SIZE = blockSize;

    if (numBlocks > 1)
    {
        IfxSdmmc_setBlockCount(emmcPtr, numBlocks);
        emmcPtr->XFER_MODE.B.MULTI_BLK_SEL = TRUE;   /* Set multi-block select */
        emmcPtr->XFER_MODE.B.BLOCK_COUNT_ENABLE = 1; /* Enable block count */
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE); /* Use Single block API!! */
    }

    /* Set transfer direction in host controller */
    emmcPtr->XFER_MODE.B.DATA_XFER_DIR = direction;

    emmcPtr->XFER_MODE.B.AUTO_CMD_ENABLE = IfxSdmmc_AutoCmdSelect_cmd23; /* Set auto command enable */

    status = IfxSdmmc_sendCommand(emmcPtr, command, address, responseType, &response);

    if (status == IfxSdmmc_Status_success)
    {
        switch (direction)
        {
        case IfxSdmmc_TransferDirection_read:
        {
            /* Read each block as buffer gets ready */
            for (blockIndex = 0; blockIndex < numBlocks; blockIndex++)
            {
                timeout = IFXSDMMC_TIMEOUT_1E6;

                /* Wait until Read ready flag is set */
                while ((IfxSdmmc_isNormalInterruptOccured(emmcPtr, IfxSdmmc_NormalInterrupt_bufferReadReady) == 0) && (timeout > 0))
                {
                    timeout--;
                }

                if (timeout == 0)
                {
                    status = IfxSdmmc_Status_dataError;
                    break;
                }
                else
                {
                    /* Read buffer is ready. Clear the interrupt first */
                    IfxSdmmc_clearNormalInterrupt(emmcPtr, IfxSdmmc_NormalInterrupt_bufferReadReady);

                    /* Now read one block from buffer */
                    for (loopIndex = 0U; loopIndex < numWords; loopIndex++)
                    {
                        *data = (uint32)IfxSdmmc_readBufferData(emmcPtr);
                        data++;
                    }
                }
            }

            break;
        }
        case IfxSdmmc_TransferDirection_write:
        {
            {
                /* Write each block as buffer gets ready */
                for (blockIndex = 0; blockIndex < numBlocks; blockIndex++)
                {
                    timeout = IFXSDMMC_TIMEOUT_1E6; 

                    /* Wait until Read ready flag is set */
                    while ((IfxSdmmc_isNormalInterruptOccured(emmcPtr, IfxSdmmc_NormalInterrupt_bufferWriteReady) == 0) && (timeout > 0))
                    {
                        timeout--;
                    }

                    if (timeout == 0)
                    {
                        status = IfxSdmmc_Status_dataError;
                        break;
                    }
                    else
                    {
                        /* Write buffer is ready. Clear the interrupt first */
                        IfxSdmmc_clearNormalInterrupt(emmcPtr, IfxSdmmc_NormalInterrupt_bufferWriteReady);

                        /* Now read one block from buffer */
                        for (loopIndex = 0U; loopIndex < numWords; loopIndex++)
                        {
                            IfxSdmmc_writeBufferData(emmcPtr, data);
                            data++;
                        }
                    }
                }

                break;
            }
        }
        default:
        {
            break;
        }
        }
    }

    if (status == IfxSdmmc_Status_success)
    {
        timeout = IFXSDMMC_TIMEOUT_1E6;

        /* Wait until transfer complete flag is set */
        while ((IfxSdmmc_isNormalInterruptOccured(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete) == 0) && (timeout > 0))
        {
            timeout--;
        }

        if (timeout == 0)
        {
            status = IfxSdmmc_Status_dataError;
            /* FIME: implement abort command process */
        }
        else
        {
            IfxSdmmc_clearNormalInterrupt(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete);
        }
    }

    return status;
}


IfxSdmmc_Status IfxSdmmc_Emmc_multiBlockAdma2Transfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint16 numBlocks, uint32 *descrAddress, IfxSdmmc_TransferDirection direction)
{
    IfxSdmmc_Status   status  = IfxSdmmc_Status_success;
    IfxSdmmc_Response response;
    uint32            timeout = 0;
    
    /* Local pointer for emmc->sdmmcSFR */
    Ifx_SDMMC *emmcPtr = emmc->sdmmcSFR; 

    /* Set the system address */
    IfxSdmmc_setSystemAddressForDma(emmcPtr, (uint32)descrAddress);

    emmcPtr->BLOCKSIZE.B.XFER_BLOCK_SIZE = blockSize;

    if (numBlocks > 1)
    {
        IfxSdmmc_setBlockCount(emmcPtr, numBlocks);
        emmcPtr->XFER_MODE.B.MULTI_BLK_SEL = TRUE; /* Set multi-block select */
        emmcPtr->XFER_MODE.B.BLOCK_COUNT_ENABLE = 1; /* Enable block count */
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE); /* Use Single block API!! */
    }

    emmcPtr->XFER_MODE.B.DMA_ENABLE = 1; /* Enable DMA transfers */

    /* Set transfer direction in host controller */
    emmcPtr->XFER_MODE.B.DATA_XFER_DIR = direction;

    emmcPtr->XFER_MODE.B.AUTO_CMD_ENABLE = IfxSdmmc_AutoCmdSelect_cmd23; /* Set auto command enable */

    status = IfxSdmmc_sendCommand(emmcPtr, command, address, IfxSdmmc_ResponseType_r1, &response);

    if (status == IfxSdmmc_Status_success)
    {
        timeout = IFXSDMMC_TIMEOUT_1E5;

        /* Wait until transfer complete or adma error flags are set */
        while ((IfxSdmmc_isNormalInterruptOccured(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete) == 0)
               && (IfxSdmmc_isErrorInterruptOccured(emmcPtr, IfxSdmmc_ErrorInterrupt_adma) == 0)
               && (timeout > 0))
        {
            timeout--;
        }

        if ((timeout == 0) || (IfxSdmmc_isErrorInterruptOccured(emmcPtr, IfxSdmmc_ErrorInterrupt_adma) != 0))
        {
            status = IfxSdmmc_Status_dataError;

            if (IfxSdmmc_isErrorInterruptOccured(emmcPtr, IfxSdmmc_ErrorInterrupt_adma) != 0)
            {
                IfxSdmmc_clearErrorInterrupt(emmcPtr, IfxSdmmc_ErrorInterrupt_adma);
            }

        }
        else
        {
            IfxSdmmc_clearNormalInterrupt(emmcPtr, IfxSdmmc_NormalInterrupt_transferComplete);
        }
    }

    return status;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
