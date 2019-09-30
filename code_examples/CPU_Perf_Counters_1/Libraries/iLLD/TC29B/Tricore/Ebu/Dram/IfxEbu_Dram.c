/**
 * \file IfxEbu_Dram.c
 * \brief EBU DRAM details
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

#include "IfxEbu_Dram.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxEbu_Dram_initMemory(IfxEbu_Dram *dram, const IfxEbu_Dram_Config *config)
{
    Ifx_EBU *ebu = config->module;
    dram->ebu         = ebu;
    dram->chipSelect  = config->chipSelect;
    dram->baseAddress = config->memoryRegionConfig.baseAddress;

/* Array for selecting Bank Address and Awidth depending on the size of memory */
    const uint8 deviceAddressSelection[IfxEbu_Dram_SDRAMDevice_4Mx32 + 1][2] = {
        {6, 3},
        {5, 3},
        {4, 2},
        {3, 2},
        {2, 1},
        {1, 1},
        {6, 3},
        {5, 2},
        {4, 2},
        {3, 1}
    };

    {
        uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
        IfxScuWdt_clearCpuEndinit(passwd);

        IfxEbu_setExternalClockRatio(ebu, config->externalClockRatio);

        IfxScuWdt_setCpuEndinit(passwd);
    }

    /* Port Initialization for Dram */
    {
        /* Sdram Address Lines */
        uint8 pin;

        for (pin = 2; pin < 16; ++pin)
        {
            if (pin < 8)
            {
                IfxPort_setPinMode(&MODULE_P21, pin, IfxPort_OutputIdx_alt6);
            }
            else
            {
                IfxPort_setPinMode(&MODULE_P25, pin, IfxPort_OutputIdx_alt6);
            }
        }

        /* Lines for BA0 & BA1 */
        IfxPort_setPinMode(&MODULE_P21, 0, IfxPort_OutputIdx_alt7);
        IfxPort_setPinMode(&MODULE_P21, 1, IfxPort_OutputIdx_alt7);
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

    /* Configuring Module Configuration Register */
    {
        Ifx_EBU_MODCON modcon;
        modcon.U             = 0;
        modcon.B.LOCKTIMEOUT = config->moduleConfig.lockTimeout;
        modcon.B.ARBMODE     = config->moduleConfig.arbMode;
        modcon.B.ARBSYNC     = config->moduleConfig.arbSignalSynchronization;
        modcon.B.CLK_COMB    = config->moduleConfig.clockComb;
        ebu->MODCON.U        = modcon.U;
    }

    /* The Read Register such as BUSRCON, BUSRAP are configured for DRAM hence they are dependent on Clock Ratio
     * For Clock Ratio 0 it is in Asynchronous mode for the rest it is in Synchronous Mode */
    uint32 deviceInterface = 1;

    if ((config->sdramDevice == IfxEbu_Dram_SDRAMDevice_32Mx32) || (config->sdramDevice == IfxEbu_Dram_SDRAMDevice_16Mx32) || (config->sdramDevice == IfxEbu_Dram_SDRAMDevice_8Mx32) || (config->sdramDevice == IfxEbu_Dram_SDRAMDevice_4Mx32))
    {
        deviceInterface = 3;
    }

    if (config->syncReadAccessParameter.externalClock == 0)
    {
        Ifx_EBU_BUSRCON busrcon;
        busrcon.U                           = 0;
        busrcon.B.PORTW                     = deviceInterface; // config->asyncReadConfig.deviceInterface;
        busrcon.B.AGEN                      = config->asyncReadConfig.deviceType;
        busrcon.B.FETBLEN                   = config->asyncReadConfig.burstLength;
        ebu->BUS[config->chipSelect].RCON.U = busrcon.U;
    }
    else
    {
        Ifx_EBU_BUSRCON busrcon;
        busrcon.U                           = 0;
        busrcon.B.PORTW                     = deviceInterface; // config->syncReadConfig.deviceInterface;
        busrcon.B.AGEN                      = config->syncReadConfig.deviceType;
        busrcon.B.FETBLEN                   = config->syncReadConfig.burstLength;
        ebu->BUS[config->chipSelect].RCON.U = busrcon.U;
    }

    if (config->syncWriteAccessParameter.externalClock == 0)
    {
        Ifx_EBU_BUSWCON buswcon;
        buswcon.U                           = 0;
        buswcon.B.PORTW                     = deviceInterface; // config->asyncWriteConfig.deviceInterface;
        buswcon.B.AGEN                      = config->asyncWriteConfig.deviceType;
        buswcon.B.FETBLEN                   = config->asyncWriteConfig.burstLength;
        ebu->BUS[config->chipSelect].WCON.U = buswcon.U;
    }
    else
    {
        Ifx_EBU_BUSWCON buswcon;
        buswcon.U                           = 0;
        buswcon.B.PORTW                     = deviceInterface; // config->syncWriteConfig.deviceInterface;
        buswcon.B.AGEN                      = config->syncWriteConfig.deviceType;
        buswcon.B.FETBLEN                   = config->syncWriteConfig.burstLength;
        ebu->BUS[config->chipSelect].WCON.U = buswcon.U;
    }

    /* SDRAM s in Asynchronous mode when Clock ratio is equal to '0' */
    if (config->syncReadAccessParameter.externalClock == 0)
    {
        Ifx_EBU_BUSRAP busrap;
        busrap.U                           = 0;
        busrap.B.EXTCLOCK                  = config->syncReadAccessParameter.externalClock;
        busrap.B.WAITRDC                   = config->asyncReadAccessParameter.waitState;
        busrap.B.RDRECOVC                  = config->asyncReadAccessParameter.recoveryAccess;
        busrap.B.RDDTACS                   = config->asyncReadAccessParameter.recoveryRegion;

        ebu->BUS[config->chipSelect].RAP.U = busrap.U;
    }
    else
    {
        /* SDRAM is in Synchronous mode  */
        Ifx_EBU_BUSRAP busrap;
        busrap.U                           = 0;
        busrap.B.EXTCLOCK                  = config->syncReadAccessParameter.externalClock;
        busrap.B.CMDDELAY                  = config->syncReadAccessParameter.commandDelay;
        busrap.B.RDRECOVC                  = config->syncReadAccessParameter.recoveryAccess;
        busrap.B.RDDTACS                   = config->syncReadAccessParameter.recoveryRegion;

        ebu->BUS[config->chipSelect].RAP.U = busrap.U;
    }

    /* SDRAM s in Asynchronous mode when Clock ratio is equal to '0' */
    if (config->syncWriteAccessParameter.externalClock == 0)
    {
        Ifx_EBU_BUSWAP buswap;
        buswap.U                           = 0;
        buswap.B.EXTCLOCK                  = config->asyncWriteAccessParameter.externalClock;
        buswap.B.WAITWRC                   = config->asyncWriteAccessParameter.waitState;
        buswap.B.WRRECOVC                  = config->asyncWriteAccessParameter.recoveryAccess;
        buswap.B.WRDTACS                   = config->asyncWriteAccessParameter.recoveryRegion;

        ebu->BUS[config->chipSelect].WAP.U = buswap.U;
    }
    else
    {
        /* SDRAM is in Synchronous mode  */
        Ifx_EBU_BUSWAP buswap;
        buswap.U                           = 0;
        buswap.B.EXTCLOCK                  = config->syncWriteAccessParameter.externalClock;
        buswap.B.CMDDELAY                  = config->syncWriteAccessParameter.commandDelay;
        buswap.B.WRRECOVC                  = config->syncWriteAccessParameter.recoveryAccess;
        buswap.B.WRDTACS                   = config->syncWriteAccessParameter.recoveryRegion;

        ebu->BUS[config->chipSelect].WAP.U = buswap.U;
    }

    /* configuring SDRAM Registers */
    /* SDRAM is configured for Warm Start */
    /* SDRAM setting are dependent on the size of memory for example 4Mx16bit SDRAM
     * Asri[22:21] is BANKM, Asri[20:9] is Row Address and Asri[8:1] is Column Address */
    uint32 maskForBankTag     = deviceAddressSelection[config->sdramDevice][0];
    uint32 columnAddressWidth = deviceAddressSelection[config->sdramDevice][1];

    /* The Model requires us to wait for 20us before Transactions can be started, we have modified
     * the model for 2us */
    /* The Sequence of writes to SDRAM Registers depends on Warm or Cold Start */
    wait(21000);

    {
        Ifx_EBU_SDR_CON sdrmcon;
        sdrmcon.U          = 0;
        sdrmcon.B.SDCMSEL  = config->sdramControlConfig.clockModeSelect;
        sdrmcon.B.PWR_MODE = config->sdramControlConfig.powerSaveMode;
        sdrmcon.B.CLKDIS   = config->sdramControlConfig.disableClockOutput;
        sdrmcon.B.BANKM    = maskForBankTag;     // config->sdramControlConfig.maskForBankTag;
        sdrmcon.B.CRC      = config->sdramControlConfig.refreshCycleTime;
        sdrmcon.B.CRCD     = config->sdramControlConfig.rowToColumnDelay;
        sdrmcon.B.AWIDTH   = columnAddressWidth; // config->sdramControlConfig.columnAddressWidth;
        sdrmcon.B.CRP      = config->sdramControlConfig.rowPrechargeTime;
        sdrmcon.B.CRSC     = config->sdramControlConfig.modeRegSetupTime;
        sdrmcon.B.CRFSH    = config->sdramControlConfig.initializationRefreshCommand;
        sdrmcon.B.CRAS     = config->sdramControlConfig.rowToPrechargeDelay;

        ebu->SDR.CON.U     = sdrmcon.U;
    }
    {
        Ifx_EBU_SDR_MOD sdrmmod;
        sdrmmod.U           = 0;
        sdrmmod.B.XBA       = config->sdramModConfig.extendedBankSelect;
        sdrmmod.B.XOPM      = config->sdramModConfig.extendedOperationMode;
        sdrmmod.B.COLDSTART = config->sdramModConfig.coldStart;
        sdrmmod.B.OPMODE    = config->sdramModConfig.opmode;
        sdrmmod.B.CASLAT    = config->sdramModConfig.casLatency;
        sdrmmod.B.BURSTL    = config->sdramModConfig.burstLength;
        ebu->SDR.MOD.U      = sdrmmod.U;
    }
    {
        Ifx_EBU_SDR_REF sdrmref;

        sdrmref.U             = 0;
        sdrmref.B.RES_DLY     = config->sdramRefreshConfig.delayOnPowerDownExit;
        sdrmref.B.ARFSH       = config->sdramRefreshConfig.autoRefresh;
        sdrmref.B.SELFREX_DLY = config->sdramRefreshConfig.selfRefreshExitDelay;
        sdrmref.B.ERFSHC      = config->sdramRefreshConfig.extendedRefresh;
        sdrmref.B.AUTOSELFR   = config->sdramRefreshConfig.automaticSelfRefresh;
        sdrmref.B.SELFREN     = config->sdramRefreshConfig.selfRefreshEntry;
        sdrmref.B.SELFREX     = config->sdramRefreshConfig.selfRefreshExit;
        sdrmref.B.REFRESHR    = config->sdramRefreshConfig.refreshCommands;
        sdrmref.B.REFRESHC    = config->sdramRefreshConfig.refreshPeriod;

        ebu->SDR.REF.U        = sdrmref.U;

        /* read back to ensure that EBU is configured before first external access */
        if (ebu->SDR.REF.U)
        {}
    }
}


void IfxEbu_Dram_initMemoryConfig(IfxEbu_Dram_Config *config, Ifx_EBU *ebu)
{
    config->module             = ebu;
    config->externalClockRatio = IfxEbu_ExternalClockRatio_4;
    config->chipSelect         = IfxEbu_ChipSelect_0;

    /* Synchronous Read Configuration */

    config->syncReadConfig.deviceType      = 8;
    config->syncReadConfig.deviceInterface = 1;
    config->syncReadConfig.burstLength     = 3;

    /* Asynchronous Read Configuration */
    config->asyncReadConfig.deviceType      = 4;
    config->asyncReadConfig.deviceInterface = 1;
    config->asyncReadConfig.burstLength     = 0;

    /* Synchronous Write Configuration */

    config->syncWriteConfig.deviceType      = 8;
    config->syncWriteConfig.deviceInterface = 1;
    config->syncWriteConfig.burstLength     = 3;

    /* Asynchronous Write Configuration */
    config->asyncWriteConfig.deviceType      = 4;
    config->asyncWriteConfig.deviceInterface = 1;
    config->asyncWriteConfig.burstLength     = 0;

    /* Synchronous Read Access Parameters */
    config->syncReadAccessParameter.commandDelay   = 3;
    config->syncReadAccessParameter.externalClock  = 2;
    config->syncReadAccessParameter.recoveryAccess = 3;
    config->syncReadAccessParameter.recoveryRegion = 3;

    /* Asynchronous Read Access Parameters */
    config->asyncReadAccessParameter.waitState      = 10;
    config->asyncReadAccessParameter.recoveryAccess = 0;
    config->asyncReadAccessParameter.recoveryRegion = 1;

    /* Synchronous Write Access Parameters */
    config->syncWriteAccessParameter.commandDelay   = 3;
    config->syncWriteAccessParameter.externalClock  = 2;
    config->syncWriteAccessParameter.recoveryAccess = 3;
    config->syncWriteAccessParameter.recoveryRegion = 3;

    /* Asynchronous Write Access Parameters */
    config->asyncWriteAccessParameter.waitState      = 10;
    config->asyncWriteAccessParameter.recoveryAccess = 0;
    config->asyncWriteAccessParameter.recoveryRegion = 1;

    /* Memory Region configuration */
    config->memoryRegionConfig.regionEnabled           = TRUE;
    config->memoryRegionConfig.alternateSegmentEnabled = TRUE;
    config->memoryRegionConfig.writeProtection         = FALSE;
    config->memoryRegionConfig.combinedChipSelect      = FALSE;
    config->memoryRegionConfig.addressMask             = 5;
    config->memoryRegionConfig.alternateSegment        = 0x8;
    config->memoryRegionConfig.baseAddress             = 0xA4000000;

    /* EBU Configuration parameters */
    config->moduleConfig.arbMode                  = IfxEbu_ExternalBusMode_soleMaster;
    config->moduleConfig.lockTimeout              = 0xff;
    config->moduleConfig.arbSignalSynchronization = IfxEbu_ArbitrationSignalSynchronization_asynchronous;
    config->moduleConfig.clockComb                = 1;

    /* Sdram Control Parameters */
    config->sdramControlConfig.rowToPrechargeDelay          = 0xa;
    /* The Values can be optimized for SDRAM, currently it is set for the maximum value */
    config->sdramControlConfig.initializationRefreshCommand = 0xf;                         /* This value can be optimized it is currently set to max to suite all SDRAMs */
    config->sdramControlConfig.modeRegSetupTime             = 2;
    config->sdramControlConfig.rowPrechargeTime             = 3;
    config->sdramControlConfig.columnAddressWidth           = IfxEbu_ColumnAddressWidth_1; /* This is device Size Specific */
    config->sdramControlConfig.rowToColumnDelay             = 3;
    config->sdramControlConfig.refreshCycleTime             = 0x13;
    config->sdramControlConfig.maskForBankTag               = IfxEbu_MaskForBankTag_4;     /* This is device size Specific */
    config->sdramControlConfig.disableClockOutput           = 0;
    config->sdramControlConfig.powerSaveMode                = 0;
    config->sdramControlConfig.clockModeSelect              = 0;

    /* SDRAM Mod Register is mainly for Mobile SDRAM */
    config->sdramModConfig.extendedBankSelect    = 0; /* Applicable for Mobile SDRAM */
    config->sdramModConfig.extendedOperationMode = 0; /* Applicable for Mobile SDRAM */
    /* We are selecting Warm Start */
    config->sdramModConfig.coldStart             = 0;
    config->sdramModConfig.opmode                = 0;
    config->sdramModConfig.casLatency            = 3;
    config->sdramModConfig.burstLength           = 3;

    /* Values for Refresh Register */
    config->sdramRefreshConfig.delayOnPowerDownExit = 2;
    config->sdramRefreshConfig.autoRefresh          = 1;
    config->sdramRefreshConfig.selfRefreshExitDelay = 2;
    config->sdramRefreshConfig.extendedRefresh      = 0;
    config->sdramRefreshConfig.automaticSelfRefresh = 1;
    config->sdramRefreshConfig.selfRefreshEntry     = 0;
    config->sdramRefreshConfig.selfRefreshExit      = 0;
    config->sdramRefreshConfig.refreshCommands      = 7;
    config->sdramRefreshConfig.refreshPeriod        = 63;
    config->sdramDevice                             = IfxEbu_Dram_SDRAMDevice_4Mx16;
}
