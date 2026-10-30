/**
 * \file IfxEbu_Sram.c
 * \brief EBU SRAM details
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
#include "IfxEbu_Sram.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxEbu_Sram_initMemory(IfxEbu_Sram *sram, const IfxEbu_Sram_Config *config)
{
	/* Get pointer to EBU module from config */
    Ifx_EBU *ebu = config->module;

    /* Store key config info in SRAM object */
    sram->ebu         = ebu;
    sram->chipSelect  = config->chipSelect;
    sram->baseAddress = config->memoryRegionConfig.baseAddress;

    {
    	/* Fetch current password of CPU Watchdog module */
        uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
        /* Clearing the endinit protection */
        IfxScuWdt_clearCpuEndinit(passwd);
        /* Set the EBU external clock ratio for synchronous operation */
        IfxEbu_setExternalClockRatio(ebu, config->externalClockRatio);
        /* Setting the endinit protection back on */
        IfxScuWdt_setCpuEndinit(passwd);
    }

    /* Agen Settings based on Device type */
    IfxEbu_DeviceType deviceType;

    if (config->device == IfxEbu_Sram_Device_deMuxedAsynchronousType)
    {
        deviceType = IfxEbu_DeviceType_demuxedAsynchronousType;
    }
    else
    {
        deviceType = IfxEbu_DeviceType_muxedAsynchronousType;
    }

    /* Port Initialization for Ebu */
    {
        /* Address Lines [20:23] */
        IfxPort_setPinMode(&MODULE_P25, 8, IfxPort_Mode_outputPushPullAlt5);
        IfxPort_setPinMode(&MODULE_P25, 9, IfxPort_Mode_outputPushPullAlt5);
        IfxPort_setPinMode(&MODULE_P25, 10, IfxPort_Mode_outputPushPullAlt5);
        IfxPort_setPinMode(&MODULE_P25, 11, IfxPort_Mode_outputPushPullAlt5);
        /* BAA */
        IfxPort_setPinMode(&MODULE_P25, 3, IfxPort_Mode_outputPushPullAlt7);
    }

    /* Configuring Ebu Registers for SRAM */
    /* Configuring the Parameters for Asynchronous and Synchronous Mode*/
    if ((config->device == IfxEbu_Sram_Device_deMuxedAsynchronousType) || (config->device == IfxEbu_Sram_Device_muxedAsynchronousType) || (config->syncReadAccessParameter.externalClock == 0))
    {
    	/* Configuring Access Parameters for Read Access */
        Ifx_EBU_BUS_RAP busrap;
        busrap.U                           = 0;
        busrap.B.ADDRC                     = config->readAccessParameter.addressCycle;
        busrap.B.AHOLDC                    = config->readAccessParameter.addressHold;
        busrap.B.CMDDELAY                  = config->readAccessParameter.commandDelay;
        busrap.B.EXTDATA                   = config->readAccessParameter.extendedData;
        busrap.B.EXTCLOCK                  = config->readAccessParameter.externalClock;
        busrap.B.DATAC                     = config->readAccessParameter.dataHold;
        busrap.B.WAITRDC                   = config->readAccessParameter.waitState;
        busrap.B.RDRECOVC                  = config->readAccessParameter.recoveryAccess;
        busrap.B.RDDTACS                   = config->readAccessParameter.recoveryRegion;

        ebu->BUS[config->chipSelect].RAP.U = busrap.U;
    }
    else
    {
    	/* Configuring Access Parameters for Read Access for Synchronous devices */
        Ifx_EBU_BUS_RAP busrap;
        busrap.U                           = 0;
        busrap.B.ADDRC                     = (config->syncReadAccessParameter.addressCycle * config->syncReadAccessParameter.externalClock);
        busrap.B.AHOLDC                    = (config->syncReadAccessParameter.addressHold * config->syncReadAccessParameter.externalClock);
        busrap.B.CMDDELAY                  = (config->syncReadAccessParameter.commandDelay * config->syncReadAccessParameter.externalClock);
        busrap.B.EXTDATA                   = config->syncReadAccessParameter.extendedData;
        busrap.B.EXTCLOCK                  = config->syncReadAccessParameter.externalClock;
        busrap.B.DATAC                     = config->syncReadAccessParameter.dataHold;
        busrap.B.WAITRDC                   = (config->syncReadAccessParameter.waitState * config->syncReadAccessParameter.externalClock);
        busrap.B.RDRECOVC                  = config->syncReadAccessParameter.recoveryAccess;
        busrap.B.RDDTACS                   = config->syncReadAccessParameter.recoveryRegion;

        ebu->BUS[config->chipSelect].RAP.U = busrap.U;
    }

    /* Configuring the Parameters for Asynchronous and Synchronous Mode*/
    if ((config->device == IfxEbu_Sram_Device_deMuxedAsynchronousType) || (config->device == IfxEbu_Sram_Device_muxedAsynchronousType) || (config->syncWriteAccessParameter.externalClock == 0))
    {
    	/* Configuring Access Parameters for Write Access */
        Ifx_EBU_BUS_WAP buswap;
        buswap.U                           = 0;
        buswap.B.ADDRC                     = config->writeAccessParameter.addressCycle;
        buswap.B.AHOLDC                    = config->writeAccessParameter.addressHold;
        buswap.B.CMDDELAY                  = config->writeAccessParameter.commandDelay;
        buswap.B.EXTDATA                   = config->writeAccessParameter.extendedData;
        buswap.B.EXTCLOCK                  = config->writeAccessParameter.externalClock;
        buswap.B.DATAC                     = config->writeAccessParameter.dataHold;
        buswap.B.WAITWRC                   = config->writeAccessParameter.waitState;
        buswap.B.WRRECOVC                  = config->writeAccessParameter.recoveryAccess;
        buswap.B.WRDTACS                   = config->writeAccessParameter.recoveryRegion;

        ebu->BUS[config->chipSelect].WAP.U = buswap.U;
    }
    else
    {
    	/* Configuring Access Parameters for Read Access for Synchronous devices */
        Ifx_EBU_BUS_WAP buswap;
        buswap.U                           = 0;
        buswap.B.ADDRC                     = (config->syncWriteAccessParameter.addressCycle * config->syncWriteAccessParameter.externalClock);
        buswap.B.AHOLDC                    = (config->syncWriteAccessParameter.addressHold * config->syncWriteAccessParameter.externalClock);
        buswap.B.CMDDELAY                  = (config->syncWriteAccessParameter.commandDelay * config->syncWriteAccessParameter.externalClock);
        buswap.B.EXTDATA                   = config->syncWriteAccessParameter.extendedData;
        buswap.B.EXTCLOCK                  = config->syncWriteAccessParameter.externalClock;
        buswap.B.DATAC                     = config->syncWriteAccessParameter.dataHold;
        buswap.B.WAITWRC                   = config->syncWriteAccessParameter.waitState;
        buswap.B.WRRECOVC                  = config->syncWriteAccessParameter.recoveryAccess;
        buswap.B.WRDTACS                   = config->syncWriteAccessParameter.recoveryRegion;

        ebu->BUS[config->chipSelect].WAP.U = buswap.U;
    }

    /* For Synchronous mode we configure the feedback clock */
    if ((config->device == IfxEbu_Sram_Device_deMuxedAsynchronousType) || (config->device == IfxEbu_Sram_Device_muxedAsynchronousType) || (config->syncWriteAccessParameter.externalClock == 0))
    {
    	/* Configuring EBU for Read access */
        Ifx_EBU_BUS_RCON busrcon;
        busrcon.U                           = 0;
        busrcon.B.AGEN                      = deviceType; /* config->readConfig.deviceType; */
        busrcon.B.WAIT                      = config->readConfig.waitControl;
        busrcon.B.WAITINV                   = config->readConfig.polarityWait;
        busrcon.B.EBSE                      = config->readConfig.earlyBurst;
        busrcon.B.ECSE                      = config->readConfig.earlyChipSelect;
        busrcon.B.PORTW                     = config->readConfig.deviceInterface;
        busrcon.B.BCGEN                     = config->readConfig.byteControl;
        busrcon.B.BFCMSEL                   = config->readConfig.burstFlashClockMode;

        ebu->BUS[config->chipSelect].RCON.U = busrcon.U;
    }
    else
    {
    	/* Synchronous Read Configuration */
        Ifx_EBU_BUS_RCON busrcon;
        busrcon.U                           = 0;
        busrcon.B.AGEN                      = config->syncReadConfig.deviceType;
        busrcon.B.PORTW                     = config->syncReadConfig.deviceInterface;
        busrcon.B.BFCMSEL                   = config->syncReadConfig.burstFlashClockMode;
        busrcon.B.FDBKEN                    = config->syncReadConfig.burstFlashClockFeedback;
        busrcon.B.FETBLEN                   = config->syncReadConfig.burstLength;
        busrcon.B.EBSE                      = config->syncReadConfig.earlyBurst;
        busrcon.B.ECSE                      = config->syncReadConfig.earlyChipSelect;
        busrcon.B.BCGEN                     = config->syncReadConfig.byteControl;
        busrcon.B.WAIT                      = config->syncReadConfig.waitControl;
        busrcon.B.WAITINV                   = config->syncReadConfig.polarityWait;

        ebu->BUS[config->chipSelect].RCON.U = busrcon.U;
    }

    /* For Synchronous mode we configure the feedback clock */
    if ((config->device == IfxEbu_Sram_Device_deMuxedAsynchronousType) || (config->device == IfxEbu_Sram_Device_muxedAsynchronousType) || (config->syncWriteAccessParameter.externalClock == 0))
    {
    	/* Configuring EBU for Write access */
        Ifx_EBU_BUS_WCON buswcon;
        buswcon.U                           = 0;
        buswcon.B.AGEN                      = deviceType;  /* config->writeConfig.deviceType; */
        buswcon.B.WAIT                      = config->writeConfig.waitControl;
        buswcon.B.WAITINV                   = config->writeConfig.polarityWait;
        buswcon.B.EBSE                      = config->writeConfig.earlyBurst;
        buswcon.B.ECSE                      = config->writeConfig.earlyChipSelect;
        buswcon.B.PORTW                     = config->writeConfig.deviceInterface;
        buswcon.B.BCGEN                     = config->writeConfig.byteControl;

        ebu->BUS[config->chipSelect].WCON.U = buswcon.U;
    }
    else
    {
    	/* Synchronous Write Configuration */
        Ifx_EBU_BUS_WCON buswcon;
        buswcon.U                           = 0;
        buswcon.B.AGEN                      = config->syncWriteConfig.deviceType;
        buswcon.B.PORTW                     = config->syncWriteConfig.deviceInterface;
        buswcon.B.FETBLEN                   = config->syncWriteConfig.burstLength;
        buswcon.B.EBSE                      = config->syncWriteConfig.earlyBurst;
        buswcon.B.ECSE                      = config->syncWriteConfig.earlyChipSelect;
        buswcon.B.BCGEN                     = config->syncWriteConfig.byteControl;
        buswcon.B.WAIT                      = config->syncWriteConfig.waitControl;
        buswcon.B.WAITINV                   = config->syncWriteConfig.polarityWait;

        ebu->BUS[config->chipSelect].WCON.U = buswcon.U;
    }

    {
    	/* Memory Region configuration */
        Ifx_EBU_ADDRSEL addrsel;
        addrsel.U                          = 0;
        addrsel.B.REGENAB                  = config->memoryRegionConfig.regionEnabled;
        addrsel.B.ALTENAB                  = config->memoryRegionConfig.alternateSegmentEnabled;
        addrsel.B.WPROT                    = config->memoryRegionConfig.writeProtection;
        addrsel.B.GLOBALCS                 = config->memoryRegionConfig.combinedChipSelect;
        addrsel.B.MASK                     = config->memoryRegionConfig.addressMask;
        addrsel.B.ALTSEG                   = config->memoryRegionConfig.alternateSegment;
        addrsel.B.BASE                     = (config->memoryRegionConfig.baseAddress >> 12);  /* Only 20 bits of Address are written */

        ebu->ADDRSEL[config->chipSelect].U = addrsel.U;
    }

    {
    	/* Module Configuration */
        Ifx_EBU_MODCON modcon;
        modcon.U             = 0;
        modcon.B.LOCKTIMEOUT = config->moduleConfig.lockTimeout;
        modcon.B.ARBMODE     = config->moduleConfig.arbMode;
        modcon.B.ARBSYNC     = config->moduleConfig.arbSignalSynchronization;

        if ((config->device == IfxEbu_Sram_Device_deMuxedAsynchronousType) || (config->device == IfxEbu_Sram_Device_muxedAsynchronousType))
        {
        	/* Output is ADV */
            modcon.B.ALE = 1;
        }
        else
        {
        	/* Output is ALE */
            modcon.B.ALE = 0;
        }

        ebu->MODCON.U = modcon.U;

        /* Read back to ensure that EBU is configured before first external access */
        if (ebu->MODCON.U)
        {}
    }
}


void IfxEbu_Sram_initMemoryConfig(IfxEbu_Sram_Config *config, Ifx_EBU *ebu)
{
	/* Initializing default configuration */

    config->module             = ebu;
    /* Configuring external clock ratio */
    config->externalClockRatio = IfxEbu_ExternalClockRatio_3;
    /* Configuring chip Select */
    config->chipSelect         = IfxEbu_ChipSelect_0;

    /* Configuring Access Parameters for Read Access */
    config->readAccessParameter.addressHold     = 1;
    config->readAccessParameter.addressCycle    = 0;
    config->readAccessParameter.commandDelay    = 0;
    config->readAccessParameter.extendedData    = IfxEbu_ExtendedData_0;
    config->readAccessParameter.externalClock   = 3;
    config->readAccessParameter.dataHold        = 0;
    config->readAccessParameter.waitState       = 5;
    config->readAccessParameter.recoveryAccess  = 0;
    config->readAccessParameter.recoveryRegion  = 1;

    /* Configuring Access Parameters for Write Access */
    config->writeAccessParameter.addressHold    = 1;
    config->writeAccessParameter.addressCycle   = 0;
    config->writeAccessParameter.commandDelay   = 0;
    config->writeAccessParameter.extendedData   = IfxEbu_ExtendedData_0;
    config->writeAccessParameter.externalClock  = 3;
    config->writeAccessParameter.dataHold       = 2;
    config->writeAccessParameter.waitState      = 5;
    config->writeAccessParameter.recoveryAccess = 0;
    config->writeAccessParameter.recoveryRegion = 1;

    /* Configuring EBU for Read access */
    config->readConfig.deviceType       = IfxEbu_DeviceType_demuxedAsynchronousType;
    config->readConfig.polarityWait     = 0;
    config->readConfig.byteControl      = 0;
    config->readConfig.earlyBurst       = 1;
    config->readConfig.earlyChipSelect  = 1;
    config->readConfig.deviceInterface  = IfxEbu_ExternalDeviceInterface_32bitMultiplexed;
    config->readConfig.waitControl      = IfxEbu_WaitControl_off;

    /* Configuring EBU for Write access */
    config->writeConfig.deviceType      = IfxEbu_DeviceType_demuxedAsynchronousType;
    config->writeConfig.polarityWait    = 0;
    config->writeConfig.byteControl     = 0;
    config->writeConfig.earlyBurst      = 1;
    config->writeConfig.earlyChipSelect = 1;
    config->writeConfig.deviceInterface = IfxEbu_ExternalDeviceInterface_32bitMultiplexed;
    config->writeConfig.waitControl     = IfxEbu_WaitControl_off;

    /* Configuring Access Parameters for Read Access for Synchronous devices */
    config->syncReadAccessParameter.addressHold     = 1;
    config->syncReadAccessParameter.addressCycle    = 0;
    config->syncReadAccessParameter.commandDelay    = 1;
    config->syncReadAccessParameter.extendedData    = IfxEbu_ExtendedData_0;
    config->syncReadAccessParameter.externalClock   = 3;
    config->syncReadAccessParameter.dataHold        = 0;
    config->syncReadAccessParameter.waitState       = 1;
    config->syncReadAccessParameter.recoveryAccess  = 2;
    config->syncReadAccessParameter.recoveryRegion  = 0;

    /* Configuring Access Parameters for Write Access for Synchronous devices */
    config->syncWriteAccessParameter.addressHold    = 1;
    config->syncWriteAccessParameter.addressCycle   = 1;
    config->syncWriteAccessParameter.commandDelay   = 1;
    config->syncWriteAccessParameter.extendedData   = IfxEbu_ExtendedData_0;
    config->syncWriteAccessParameter.externalClock  = 3;
    config->syncWriteAccessParameter.dataHold       = 4;
    config->syncWriteAccessParameter.waitState      = 8;
    config->syncWriteAccessParameter.recoveryAccess = 2;
    config->syncWriteAccessParameter.recoveryRegion = 1;

    /* Synchronous Read Configuration */
    config->syncReadConfig.deviceType                  = IfxEbu_DeviceType_demuxedBurstType;
    config->syncReadConfig.polarityWait                = 0;
    config->syncReadConfig.byteControl                 = 0;
    config->syncReadConfig.deviceInterface             = IfxEbu_ExternalDeviceInterface_32bitMultiplexed;
    config->syncReadConfig.burstFlashClockMode         = 1;
    config->syncReadConfig.burstFlashClockFeedback     = 1;
    config->syncReadConfig.burstLength                 = IfxEbu_SynchronousBurstLength_4;

    /* Synchronous write Configuration */
    config->syncWriteConfig.deviceType                 = IfxEbu_DeviceType_demuxedBurstType;
    config->syncWriteConfig.polarityWait               = 0;
    config->syncWriteConfig.byteControl                = 0;
    config->syncWriteConfig.deviceInterface            = IfxEbu_ExternalDeviceInterface_32bitMultiplexed;
    config->syncWriteConfig.burstLength                = IfxEbu_SynchronousBurstLength_1;

    /* Memory Region configuration */
    config->memoryRegionConfig.regionEnabled           = TRUE;
    config->memoryRegionConfig.alternateSegmentEnabled = TRUE;
    config->memoryRegionConfig.writeProtection         = FALSE;
    config->memoryRegionConfig.combinedChipSelect      = FALSE;
    config->memoryRegionConfig.addressMask             = IfxEbu_MemoryRegionMask_5;
    config->memoryRegionConfig.alternateSegment        = 0x8;
    config->memoryRegionConfig.baseAddress             = 0xA4000000;

    /* Module Configuration */
    config->moduleConfig.aleMode                       = 1;
    config->moduleConfig.arbMode                       = IfxEbu_ExternalBusMode_soleMaster;
    config->moduleConfig.lockTimeout                   = 0xff;
    config->moduleConfig.arbSignalSynchronization      = IfxEbu_ArbitrationSignalSynchronization_asynchronous;

    config->device                                     = IfxEbu_Sram_Device_deMuxedAsynchronousType;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
