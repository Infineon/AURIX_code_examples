/**
 * \file IfxEbu_BFlashSpansion.c
 * \brief EBU BFLASHSPANSION details
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
#ifdef DEVICE_TC39XB
#include "IfxEbu_BFlashSpansion.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxEbu_BFlashSpansion_cmdSetBurstConfig(IfxEbu_BFlashSpansion *bflash, IfxEbu_BFlashSpansion_BurstCfg burstCfg)
{
	/* Suppress unused parameter warning as blockAddress is currently unused */
    IFX_UNUSED_PARAMETER(burstCfg.B.automaticSleepModeDisable);

    /* Calculate the addresses for command cycle operations */
    /* These are based on standard command addresses for Spansion flash memory */
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
	/* Suppress unused parameter warning as blockAddress is currently unused */
    IFX_UNUSED_PARAMETER(blockAddress);

    /* Calculate the addresses for command cycle operations */
    /* These are based on standard command addresses for Spansion flash memory */
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

    /* Waits for the Spansion flash device to signal readiness */
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
        /* Clearing the endinit protection */
        IfxScuWdt_clearCpuEndinit(password);
        /* Set the EBU external clock ratio for synchronous operation */
        IfxEbu_setExternalClockRatio(ebu, config->externalClockRatio);
        /* Setting the endinit protection back on */
        IfxScuWdt_setCpuEndinit(password);
    }

    /* Configuring Base and Alternate segment Address for EBU to Access External Memory */
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
    	/* Asynchronous read configuration */
        {
            Ifx_EBU_BUS_RCON busrcon;
            busrcon.U                           = 0;
            busrcon.B.FETBLEN                   = config->asyncReadConfig.burstLength;
            busrcon.B.BFCMSEL                   = config->asyncReadConfig.burstFlashClockFeedback;
            busrcon.B.PORTW                     = config->asyncReadConfig.deviceInterface;
            busrcon.B.AGEN                      = config->asyncReadConfig.deviceType;
            ebu->BUS[config->chipSelect].RCON.U = busrcon.U;
        }

        {
        	/* Asynchronous read Access parameter */
            Ifx_EBU_BUS_RAP busrap;
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
    	/* Synchronous read configuration */
        {
            Ifx_EBU_BUS_RCON busrcon;
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
            Ifx_EBU_BUS_RAP busrap;
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
            Ifx_EBU_BUS_WCON buswcon;
            buswcon.U                           = 0;
            buswcon.B.FETBLEN                   = config->asyncWriteConfig.burstLength;
            buswcon.B.PORTW                     = config->asyncWriteConfig.deviceInterface;
            buswcon.B.AGEN                      = config->asyncWriteConfig.deviceType;
            ebu->BUS[config->chipSelect].WCON.U = buswcon.U;
        }

        {
        	/* Asynchronous write Access parameter */
            Ifx_EBU_BUS_WAP buswap;
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

    /* Read back to ensure that EBU is configured before first external access */
    if (ebu->MODCON.U)
    {}

    /* Configure burst mode in external device*/
    IfxEbu_BFlashSpansion_cmdSetBurstConfig(bflash, config->burstCfg);
}


void IfxEbu_BFlashSpansion_initMemoryConfig(IfxEbu_BFlashSpansion_Config *config, Ifx_EBU *ebu)
{
    config->module             = ebu;
    config->externalClockRatio = IfxEbu_ExternalClockRatio_3;
    config->chipSelect         = IfxEbu_ChipSelect_0;

    /* Synchronous Read Configuration */
    config->syncReadConfig.burstLength             = IfxEbu_SynchronousBurstLength_8;
    config->syncReadConfig.burstFlashClockFeedback = 1;
    config->syncReadConfig.burstFlashClockMode     = 1;
    config->syncReadConfig.deviceInterface         = IfxEbu_ExternalDeviceInterface_32bitMultiplexed;
    config->syncReadConfig.deviceType              = IfxEbu_DeviceType_demuxedBurstType;
    config->syncReadConfig.earlyBurst              = 1;
    config->syncReadConfig.earlyChipSelect         = 1;

    /* Asynchronous Read Configuration */
    config->asyncReadConfig.burstLength             = IfxEbu_SynchronousBurstLength_1;
    config->asyncReadConfig.burstFlashClockFeedback = 0;
    config->asyncReadConfig.deviceInterface         = IfxEbu_ExternalDeviceInterface_32bitMultiplexed;
    config->asyncReadConfig.deviceType              = IfxEbu_DeviceType_demuxedAsynchronousType;

    /* Asynchronous Write Configuration */
    config->asyncWriteConfig.burstLength     = IfxEbu_SynchronousBurstLength_1;
    config->asyncWriteConfig.deviceInterface = IfxEbu_ExternalDeviceInterface_32bitMultiplexed;
    config->asyncWriteConfig.deviceType      = IfxEbu_DeviceType_demuxedAsynchronousType;

    /* Synchronous Read Access Parameters */
    config->syncReadAccessParameter.addressCycle   = 1;
    config->syncReadAccessParameter.addressHold    = 0;
    config->syncReadAccessParameter.commandDelay   = 1;
    config->syncReadAccessParameter.externalClock  = 3; /* This is commonly used for both Sync and Async configurations as the configurations are dependent on clock ratio */
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
    config->memoryRegionConfig.addressMask             = IfxEbu_MemoryRegionMask_5;
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
	/* Calculate the addresses for command cycle operations */
	/* These are based on standard command addresses for Spansion flash memory */
    volatile uint32 *addr1 = (volatile uint32 *)(bflash->baseAddress + 4 * 0x555);
    volatile uint32 *addr2 = (volatile uint32 *)(bflash->baseAddress + 4 * 0x2aa);
    volatile uint32 *addr3 = (volatile uint32 *)(address);

    /* Lower and Upper 16 bit datas are written as we have 2*16bit devices connected */
    *addr1 = 0x00aa00aa;
    *addr2 = 0x00550055;
    *addr1 = 0x00a000a0;
    *addr3 = data;

    /* Waits for the Spansion flash device to signal readiness */
    IfxEbu_BFlashSpansion_waitForReady(bflash);
}


boolean IfxEbu_BFlashSpansion_waitForReady(IfxEbu_BFlashSpansion *bflash)
{
    volatile uint32 *addr1 = (volatile uint32 *)(bflash->baseAddress);
    uint32           data1, data2;

    /* Ensure that previous write operation is finished before reading */
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
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
