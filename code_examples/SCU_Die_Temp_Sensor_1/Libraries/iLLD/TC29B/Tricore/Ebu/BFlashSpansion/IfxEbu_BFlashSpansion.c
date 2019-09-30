/**
 * \file IfxEbu_BFlashSpansion.c
 * \brief EBU BFLASHSPANSION details
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

#include "IfxEbu_BFlashSpansion.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxEbu_BFlashSpansion_cmdSetBurstConfig(IfxEbu_BFlashSpansion *bflash, IfxEbu_BFlashSpansion_BurstCfg burstCfg)
{
    volatile uint32 *addr1 = (volatile uint32 *)(bflash->baseAddress + (0x555 << 2));
    volatile uint32 *addr2 = (volatile uint32 *)(bflash->baseAddress + (0x2aa << 2));
    uint16           cfg   = bflash->burstCfg.U;

    *addr1 = 0x00aa00aa;
    *addr2 = 0x00550055;
    *addr1 = 0x00d000d0;
    *addr2 = ((uint32)cfg << 16) | cfg;
}


void IfxEbu_BFlashSpansion_eraseBlock(IfxEbu_BFlashSpansion *bflash, uint32 blockAddress)
{
    volatile uint32 *addr1 = (volatile uint32 *)(bflash->baseAddress + 4 * 0x555);
    volatile uint32 *addr2 = (volatile uint32 *)(bflash->baseAddress + 4 * 0x2aa);

    /* Erase Chip Command */
    /* Lower and Upper 16 bit datas are written as we have 2*16bit devices connected */
    *addr1 = 0x00aa00aa;
    *addr2 = 0x00550055;
    *addr1 = 0x00800080;
    *addr1 = 0x00aa00aa;
    *addr2 = 0x00550055;
    *addr1 = 0x00100010;

    IfxEbu_BFlashSpansion_waitForReady(bflash);
}


void IfxEbu_BFlashSpansion_initMemory(IfxEbu_BFlashSpansion *bflash, const IfxEbu_BFlashSpansion_Config *config)
{
    Ifx_EBU *ebu = config->module;
    bflash->ebu         = ebu;
    bflash->chipSelect  = config->chipSelect;
    bflash->baseAddress = config->memoryRegionConfig.baseAddress;

    {
        uint16 password = IfxScuWdt_getCpuWatchdogPassword();
        IfxScuWdt_clearCpuEndinit(password);

        IfxEbu_setExternalClockRatio(ebu, config->externalClockRatio);

        IfxScuWdt_setCpuEndinit(password);
    }

    /* configuring Base and Alternate segment Address for EBU to Access External Memory */
    {
        Ifx_EBU_ADDRSEL addrsel;
        addrsel.U                          = 0;
        addrsel.B.REGENAB                  = config->memoryRegionConfig.regionEnabled;
        addrsel.B.ALTENAB                  = config->memoryRegionConfig.alternateSegmentEnabled;
        addrsel.B.WPROT                    = config->memoryRegionConfig.writeProtection;
        addrsel.B.GLOBALCS                 = config->memoryRegionConfig.combinedChipSelect;
        addrsel.B.MASK                     = config->memoryRegionConfig.addressMask;
        addrsel.B.ALTSEG                   = config->memoryRegionConfig.alternateSegment;
        addrsel.B.BASE                     = (config->memoryRegionConfig.baseAddress >> 12); /* Address bits are only 20 hence we need to shift */

        ebu->ADDRSEL[config->chipSelect].U = addrsel.U;
    }

    /* The Read Register such as BUSRCON, BUSRAP are configured for BFlashSt hence they are dependent on Clock Ratio
     * For Clock Ratio 0 it is in Asynchronous mode for the rest it is in Synchronous Mode */

    if (config->syncReadAccessParameter.externalClock == 0)
    {
        {
            Ifx_EBU_BUSRCON busrcon;
            busrcon.U                           = 0;
            busrcon.B.FETBLEN                   = config->asyncReadConfig.burstLength;
            busrcon.B.BFCMSEL                   = config->asyncReadConfig.burstFlashClockFeedback;
            busrcon.B.PORTW                     = config->asyncReadConfig.deviceInterface;
            busrcon.B.AGEN                      = config->asyncReadConfig.deviceType;
            ebu->BUS[config->chipSelect].RCON.U = busrcon.U;
        }

        {
            Ifx_EBU_BUSRAP busrap;
            busrap.U                           = 0;
            busrap.B.ADDRC                     = config->asyncReadAccessParameter.addressCycle; /* Delays are given wrt to Asynchronous mode */
            busrap.B.AHOLDC                    = config->asyncReadAccessParameter.addressHold;  /* Delays are given wrt to Asynchronous mode */
            busrap.B.CMDDELAY                  = config->asyncReadAccessParameter.commandDelay; /* Delays are given wrt to Asynchronous mode */
            busrap.B.DATAC                     = config->asyncReadAccessParameter.dataHold;
            busrap.B.WAITRDC                   = config->asyncReadAccessParameter.waitState;
            busrap.B.RDRECOVC                  = config->asyncReadAccessParameter.recoveryAccess;
            busrap.B.RDDTACS                   = config->asyncReadAccessParameter.recoveryRegion;

            ebu->BUS[config->chipSelect].RAP.U = busrap.U;
        }
    }
    else
    {
        {
            Ifx_EBU_BUSRCON busrcon;
            busrcon.U                           = 0;
            busrcon.B.FETBLEN                   = config->syncReadConfig.burstLength;
            busrcon.B.FDBKEN                    = config->syncReadConfig.burstFlashClockMode;
            busrcon.B.BFCMSEL                   = config->syncReadConfig.burstFlashClockFeedback;
            busrcon.B.ECSE                      = config->syncReadConfig.earlyChipSelect;
            busrcon.B.EBSE                      = config->syncReadConfig.earlyBurst;
            busrcon.B.PORTW                     = config->syncReadConfig.deviceInterface;
            busrcon.B.AGEN                      = config->syncReadConfig.deviceType;
            ebu->BUS[config->chipSelect].RCON.U = busrcon.U;
        }

        {
            /* Configuration of Read Parameter are dependent on Clock Ratio of BFlashSt itself */
            Ifx_EBU_BUSRAP busrap;
            busrap.U                           = 0;
            busrap.B.ADDRC                     = config->syncReadAccessParameter.addressCycle * (config->syncReadAccessParameter.externalClock + 1);
            busrap.B.AHOLDC                    = config->syncReadAccessParameter.addressHold * (config->syncReadAccessParameter.externalClock + 1);
            busrap.B.CMDDELAY                  = config->syncReadAccessParameter.commandDelay * (config->syncReadAccessParameter.externalClock + 1);
            busrap.B.EXTCLOCK                  = config->syncReadAccessParameter.externalClock;
            busrap.B.DATAC                     = config->syncReadAccessParameter.dataHold * (config->syncReadAccessParameter.externalClock + 1);
            busrap.B.WAITRDC                   = config->syncReadAccessParameter.waitState * (config->syncReadAccessParameter.externalClock + 1);
            busrap.B.RDRECOVC                  = config->syncReadAccessParameter.recoveryAccess * (config->syncReadAccessParameter.externalClock + 1);
            busrap.B.RDDTACS                   = config->syncReadAccessParameter.recoveryRegion * (config->syncReadAccessParameter.externalClock + 1);

            ebu->BUS[config->chipSelect].RAP.U = busrap.U;
        }
    }

    /* Burst Flash is written in ASync mode */
    {
        {
            Ifx_EBU_BUSWCON buswcon;
            buswcon.U                           = 0;
            buswcon.B.FETBLEN                   = config->asyncWriteConfig.burstLength;
            buswcon.B.PORTW                     = config->asyncWriteConfig.deviceInterface;
            buswcon.B.AGEN                      = config->asyncWriteConfig.deviceType;
            ebu->BUS[config->chipSelect].WCON.U = buswcon.U;
        }

        {
            Ifx_EBU_BUSWAP buswap;
            buswap.U                           = 0;
            buswap.B.ADDRC                     = config->asyncWriteAccessParameter.addressCycle;
            buswap.B.AHOLDC                    = config->asyncWriteAccessParameter.addressHold;
            buswap.B.CMDDELAY                  = config->asyncWriteAccessParameter.commandDelay;
            buswap.B.DATAC                     = config->asyncWriteAccessParameter.dataHold;
            buswap.B.WAITWRC                   = config->asyncWriteAccessParameter.waitState;
            buswap.B.WRRECOVC                  = config->asyncWriteAccessParameter.recoveryAccess;
            buswap.B.WRDTACS                   = config->asyncWriteAccessParameter.recoveryRegion;

            ebu->BUS[config->chipSelect].WAP.U = buswap.U;
        }
    }

    /* EBU Mode Configuration */
    {
        Ifx_EBU_MODCON modcon;
        modcon.U             = 0;
        modcon.B.LOCKTIMEOUT = config->moduleConfig.lockTimeout;
        modcon.B.ARBMODE     = config->moduleConfig.arbMode;
        modcon.B.ARBSYNC     = config->moduleConfig.arbSignalSynchronization;
        modcon.B.ALE         = config->moduleConfig.aleMode;
        ebu->MODCON.U        = modcon.U;
    }

    /* read back to ensure that EBU is configured before first external access */
    if (ebu->MODCON.U)
    {}

    /* configure burst mode in external device*/
    IfxEbu_BFlashSpansion_cmdSetBurstConfig(bflash, config->burstCfg);
}


void IfxEbu_BFlashSpansion_initMemoryConfig(IfxEbu_BFlashSpansion_Config *config, Ifx_EBU *ebu)
{
    config->module             = ebu;
    config->externalClockRatio = IfxEbu_ExternalClockRatio_3;
    config->chipSelect         = IfxEbu_ChipSelect_0;

    /* Synchronous Read Configuration */
    config->syncReadConfig.burstLength             = 3;
    config->syncReadConfig.burstFlashClockFeedback = 1;
    config->syncReadConfig.burstFlashClockMode     = 1;
    config->syncReadConfig.deviceInterface         = 3;
    config->syncReadConfig.deviceType              = IfxEbu_DeviceType_demuxedBurstType;
    config->syncReadConfig.earlyBurst              = 1;
    config->syncReadConfig.earlyChipSelect         = 1;

    /* Asynchronous Read Configuration */
    config->asyncReadConfig.burstLength             = 0;
    config->asyncReadConfig.burstFlashClockFeedback = 0;
    config->asyncReadConfig.deviceInterface         = 3;
    config->asyncReadConfig.deviceType              = IfxEbu_DeviceType_demuxedAsynchronousType;

    /* Asynchronous Write Configuration */
    config->asyncWriteConfig.burstLength     = 0;
    config->asyncWriteConfig.deviceInterface = 3;
    config->asyncWriteConfig.deviceType      = IfxEbu_DeviceType_demuxedAsynchronousType;

    /* Synchronous Read Access Parameters */
    config->syncReadAccessParameter.addressCycle   = 1;
    config->syncReadAccessParameter.addressHold    = 0;
    config->syncReadAccessParameter.commandDelay   = 1;
    config->syncReadAccessParameter.externalClock  = 3; // This is commonly used for both Sync and Async configurations as the configurations are dependent on clock ratio //
    config->syncReadAccessParameter.dataHold       = 0;
    config->syncReadAccessParameter.waitState      = 2;
    config->syncReadAccessParameter.recoveryAccess = 1;
    config->syncReadAccessParameter.recoveryRegion = 1;

    /* Asynchronous Read Access Parameters */
    config->asyncReadAccessParameter.addressCycle   = 6;
    config->asyncReadAccessParameter.addressHold    = 6;
    config->asyncReadAccessParameter.commandDelay   = 6;
    config->asyncReadAccessParameter.dataHold       = 3;
    config->asyncReadAccessParameter.waitState      = 11;
    config->asyncReadAccessParameter.recoveryAccess = 3;
    config->asyncReadAccessParameter.recoveryRegion = 3;

    /* Asynchronous Write Access Parameters */
    config->asyncWriteAccessParameter.addressCycle   = 8;
    config->asyncWriteAccessParameter.addressHold    = 8;
    config->asyncWriteAccessParameter.commandDelay   = 8;
    config->asyncWriteAccessParameter.dataHold       = 8;
    config->asyncWriteAccessParameter.waitState      = 8;
    config->asyncWriteAccessParameter.recoveryAccess = 4;
    config->asyncWriteAccessParameter.recoveryRegion = 4;

    /* Module Configuration */
    config->moduleConfig.aleMode                  = 0;
    config->moduleConfig.arbMode                  = IfxEbu_ExternalBusMode_soleMaster;
    config->moduleConfig.lockTimeout              = 0xff;
    config->moduleConfig.arbSignalSynchronization = IfxEbu_ArbitrationSignalSynchronization_asynchronous;

    /* Memory Region configuration */
    config->memoryRegionConfig.regionEnabled           = TRUE;
    config->memoryRegionConfig.alternateSegmentEnabled = TRUE;
    config->memoryRegionConfig.writeProtection         = FALSE;
    config->memoryRegionConfig.combinedChipSelect      = FALSE;
    config->memoryRegionConfig.addressMask             = 5;
    config->memoryRegionConfig.alternateSegment        = 0x8;
    config->memoryRegionConfig.baseAddress             = 0xA4000000;

    /* S29CD032G specific burst configuration */
    config->burstCfg.B.readMode                  = 0;
    config->burstCfg.B.automaticSleepModeDisable = 2;
    config->burstCfg.B.dataOutputConfiguration   = 0;
    config->burstCfg.B.waitConfiguration         = 1;
    config->burstCfg.B.burstSequence             = 1;
    config->burstCfg.B.clockConfiguration        = 1;
    config->burstCfg.B.burstLength               = 3;
}


void IfxEbu_BFlashSpansion_programWord(IfxEbu_BFlashSpansion *bflash, uint32 address, uint32 data)
{
    volatile uint32 *addr1 = (volatile uint32 *)(bflash->baseAddress + 4 * 0x555);
    volatile uint32 *addr2 = (volatile uint32 *)(bflash->baseAddress + 4 * 0x2aa);
    volatile uint32 *addr3 = (volatile uint32 *)(address);

    /* Lower and Upper 16 bit datas are written as we have 2*16bit devices connected */
    *addr1 = 0x00aa00aa;
    *addr2 = 0x00550055;
    *addr1 = 0x00a000a0;
    *addr3 = data;

    IfxEbu_BFlashSpansion_waitForReady(bflash);
}


boolean IfxEbu_BFlashSpansion_waitForReady(IfxEbu_BFlashSpansion *bflash)
{
    volatile uint32 *addr1 = (volatile uint32 *)(bflash->baseAddress);
    uint32           data1, data2;

    /* ensure that previous write operation is finished before reading */
    __dsync();

    /* When erase or program command is issued Spansion flash indicates the status of busy by toggling the data on bit 6 */
    /* TODO: should we add a timeout mechanism? */
    do
    {
        data1 = *addr1;
        data2 = *addr1;
    } while (data1 != data2);

    return TRUE;
}
