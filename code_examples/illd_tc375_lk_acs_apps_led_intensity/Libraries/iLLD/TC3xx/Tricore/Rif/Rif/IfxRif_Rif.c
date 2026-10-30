/**
 * \file IfxRif_Rif.c
 * \brief RIF RIF details
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
#if defined(DEVICE_TC33XED) || defined(DEVICE_TC39XB) || defined(DEVICE_TC35X)
#include "IfxRif_Rif.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxRif_Rif_initModule(IfxRif_Rif *rif, IfxRif_Rif_Config *config)
{
    Ifx_RIF *rifSFR = config->rif; /* Pointer to RIF registers */
    rif->rif           = rifSFR;   /* Take over register pointer to module handler */

    rif->numOfChannels = config->numOfChannels;

    /* enable module if it hasn't been enabled already */
    if (IfxRif_isModuleEnabled(rifSFR) == FALSE)
    {
    	/* Enable the module  */
        IfxRif_enableModule(rifSFR);
    }

    /* --- Deserializer configuration if the external ADC are used --- */

    if (config->connectedAdc == IfxRif_Adc_external)
    {
        IfxRif_setClockPolarity(rifSFR, config->deserializer.clockPolarity);
        IfxRif_setFramePolarity(rifSFR, config->deserializer.framePolarity);
        IfxRif_setDataPolarity0(rifSFR, config->deserializer.dataPolarity0);
        IfxRif_setDataPolarity1(rifSFR, config->deserializer.dataPolarity1);
        IfxRif_setDataPolarity2(rifSFR, config->deserializer.dataPolarity2);
        IfxRif_setDataPolarity3(rifSFR, config->deserializer.dataPolarity3);

        IfxRif_setDataLength(rifSFR, config->data.length);
        IfxRif_setDataFormat(rifSFR, config->data.format);
        IfxRif_setShiftDirection(rifSFR, config->data.shiftDirection);

        if (config->deserializer.calibrationEnable != FALSE)
        {
        	/* Enable the Calibration  */
            IfxRif_enableCalibration(rifSFR);
        }
    }

    /* --- FIFO and Lane Management configuration --- */

    IfxRif_enableFifos(rifSFR, config->numOfChannels);

    IfxRif_setFlmMode(rifSFR, config->data.flmMode);
    IfxRif_setFullSwapMode(rifSFR, config->data.fullSwapMode);

    /* CRC enable / disable for both internal and external ADC */
    if (config->data.crcEnable != FALSE)
    {
        IfxRif_enableCrc(rifSFR);
    }

    /* --- Radar State Machine Configuration --- */

    if (config->connectedAdc == IfxRif_Adc_external)
    {     /* If External ADCs are selected */
        /*   --- [RIF_TC.004] External ramp feature not reliable ---   */
        IfxRif_enableExternalAdc(rifSFR);
        IfxRif_setValidDataSamplesNumber(rifSFR, config->rsm.numOfValidSamples);

        if (config->fwdg.threshold > 0)
        {
            IfxRif_setFrameWatchdogThreshold(rifSFR, config->fwdg.threshold);
        }
    }
    else
    {    /* If Internal ADCs are selected */
        IfxRif_enableInternalAdc(rifSFR);
        /*   --- Ramp1 only applicable for External ADC ---   */

        IfxRif_setValidDataSamplesNumber(rifSFR, config->rsm.numOfValidSamples);

        if (config->fwdg.threshold > 0)
        {
            IfxRif_setFrameWatchdogThreshold(rifSFR, config->fwdg.threshold);
        }
    }

    IfxRif_setChirpLength(rifSFR, config->rsm.rampsPerChirp);

    /* --- DMI configuration --- */

    IfxRif_setDataAlignment(rifSFR, config->data.alignment);

    /* --- LVDS configuration --- */

    IfxRif_setFrameLvdsPadControl(rifSFR, config->lvds.frameControl);
    IfxRif_setClockLvdsPadControl(rifSFR, config->lvds.clockControl);
    IfxRif_setData0LvdsPadControl(rifSFR, config->lvds.data0Control);
    IfxRif_setData1LvdsPadControl(rifSFR, config->lvds.data1Control);
    IfxRif_setData2LvdsPadControl(rifSFR, config->lvds.data2Control);
    IfxRif_setData3LvdsPadControl(rifSFR, config->lvds.data3Control);
    IfxRif_setCommonLvdsPadControl(rifSFR, config->lvds.commonControl);
    IfxRif_setRtermTrimmingValue(rifSFR, config->lvds.rtermTrimmingValue);
    IfxRif_setLvdsBiasDistributorPowerDownMode(rifSFR, config->lvds.biasDistributorPowerDownMode);
    IfxRif_setLvdsBiasDistributor5VMode(rifSFR, config->lvds.biasDistributor5VMode);

    /* --- Interrupt configuration --- */

    if ((config->interrupt.intPriority > 0) || (config->interrupt.typeOfService == IfxSrc_Tos_dma))
    {
        volatile Ifx_SRC_SRCR *src;
        src = IfxRif_getSrcPointerInt(rifSFR);
        IfxSrc_init(src, config->interrupt.typeOfService, config->interrupt.intPriority);

        if (config->interrupt.calibrationEndEnable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_calibrationEnd);
        }

        if (config->interrupt.frameWatchdogOverflowEnable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_frameWatchdogOverflow);
        }

        if (config->interrupt.rampEndEnable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_rampEnd);
        }

        if (config->interrupt.chirpEndEnable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_chirpEnd);
        }

        if (config->interrupt.ramp1StartEnable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_ramp1Start);
        }

        IfxSrc_enable(src);
    }

    if ((config->interrupt.errPriority > 0) || (config->interrupt.typeOfService == IfxSrc_Tos_dma))
    {
        volatile Ifx_SRC_SRCR *src;
        src = IfxRif_getSrcPointerErr(rifSFR);
        IfxSrc_init(src, config->interrupt.typeOfService, config->interrupt.errPriority);

        if (config->interrupt.crcErrorOnLine0Enable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_crcErrorOnLine0);
        }

        if (config->interrupt.crcErrorOnLine1Enable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_crcErrorOnLine1);
        }

        if (config->interrupt.crcErrorOnLine2Enable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_crcErrorOnLine2);
        }

        if (config->interrupt.crcErrorOnLine3Enable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_crcErrorOnLine3);
        }

        if (config->interrupt.ramp1ErrorEnable)
        {
        	/* Enable the interrupt */
            IfxRif_enableInterrupt(rifSFR, IfxRif_Interrupt_ramp1Error);
        }

        IfxSrc_enable(src);
    }

    /* Lockstep enable /disable */
    IfxRif_enableLockstep(rifSFR, config->rsm.lockstepEnable);
}


void IfxRif_Rif_initModuleConfig(IfxRif_Rif_Config *config, Ifx_RIF *rif)
{
    const IfxRif_Rif_Config defaultConfig = {
        .connectedAdc  = IfxRif_Adc_internal,
        .numOfChannels = 4,
		/* Default values for deserializer */
        .deserializer  = {
            .clockPolarity     = IfxRif_ClockPolarity_default,
            .framePolarity     = IfxRif_FramePolarity_default,
            .dataPolarity0     = IfxRif_DataPolarity_default,
            .dataPolarity1     = IfxRif_DataPolarity_default,
            .dataPolarity2     = IfxRif_DataPolarity_default,
            .dataPolarity3     = IfxRif_DataPolarity_default,
            .calibrationEnable = FALSE
        },
		/* Default values for data formating unit */
        .data                             = {
            .length         = IfxRif_DataLength_16bit,
            .format         = IfxRif_DataFormat_unsigned,
            .shiftDirection = IfxRif_ShiftDirection_lsbFirst,
            .alignment      = IfxRif_DataAlignment_left,
            .flmMode        = IfxRif_FlmMode_direct,
            .fullSwapMode   = IfxRif_FullSwapMode_direct,
            .crcEnable      = FALSE
        },
		/* Default values for frame watchdog */
        .fwdg                             = {
            .threshold                    = 0
        },
		/* Default values for radar state machine */
        .rsm                              = {
            .ramp1SignalEnable   = FALSE,
            .ramp1SignalInput    = IfxRif_Ramp1SignalInput_0,
            .ramp1SignalPolarity = IfxRif_Ramp1SignalPolarity_lowActive,
            .rampsPerChirp       = 128,
            .numOfValidSamples   = 128,
            .lockstepEnable      = FALSE
        },
		/* Default values for LVDS PAD control */
        .lvds                             = {
            .frameControl                 = IfxRif_LvdsPadControl_frameClock | IfxRif_LvdsPadControl_rterm,
            .clockControl                 = IfxRif_LvdsPadControl_frameClock | IfxRif_LvdsPadControl_rterm,
            .data0Control                 = IfxRif_LvdsPadControl_frameClock | IfxRif_LvdsPadControl_rterm,
            .data1Control                 = IfxRif_LvdsPadControl_frameClock | IfxRif_LvdsPadControl_rterm,
            .data2Control                 = IfxRif_LvdsPadControl_frameClock | IfxRif_LvdsPadControl_rterm,
            .data3Control                 = IfxRif_LvdsPadControl_frameClock | IfxRif_LvdsPadControl_rterm,
            .commonControl                = IfxRif_CommonLvdsPadControl_5vMode,
            .rtermTrimmingValue           = 0x3,
            .biasDistributorPowerDownMode = IfxRif_LvdsBiasDistributorMode_active,
            .biasDistributor5VMode        = TRUE
        },
		/* Default values for interrupt */
        .interrupt                        = {
            .calibrationEndEnable        = FALSE,
            .frameWatchdogOverflowEnable = FALSE,
            .rampEndEnable               = FALSE,
            .chirpEndEnable              = FALSE,
            .crcErrorOnLine0Enable       = FALSE,
            .crcErrorOnLine1Enable       = FALSE,
            .crcErrorOnLine2Enable       = FALSE,
            .crcErrorOnLine3Enable       = FALSE,
            .ramp1ErrorEnable            = FALSE,
            .chirp1ErrorEnable           = FALSE,
            .ramp1StartEnable            = FALSE,
            .intPriority                 = 0,
            .errPriority                 = 0,
            .typeOfService               = IfxSrc_Tos_cpu0
        }
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* Take over module pointer */
    config->rif = rif;
}


void IfxRif_Rif_isrError(IfxRif_Rif *rif)
{
    Ifx_RIF *rifSFR = rif->rif;

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_crcErrorOnLine0))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_crcErrorOnLine0);
        rif->status.crcErrorOnLine0 = 1;
        rif->status.crcNoError      = 0;
    }

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_crcErrorOnLine1))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_crcErrorOnLine1);
        rif->status.crcErrorOnLine1 = 1;
        rif->status.crcNoError      = 0;
    }

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_crcErrorOnLine2))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_crcErrorOnLine2);
        rif->status.crcErrorOnLine2 = 1;
        rif->status.crcNoError      = 0;
    }

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_crcErrorOnLine3))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_crcErrorOnLine3);
        rif->status.crcErrorOnLine3 = 1;
        rif->status.crcNoError      = 0;
    }

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_ramp1Error))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_ramp1Error);
        rif->status.ramp1Error = 1;
    }

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_chirp1Error))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_chirp1Error);
        rif->status.chirp1Error = 1;
    }
}


void IfxRif_Rif_isrInterrupt(IfxRif_Rif *rif)
{
    Ifx_RIF *rifSFR = rif->rif;

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_calibrationEnd))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_calibrationEnd);
        rif->status.calibrationEnd = 1;
    }

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_frameWatchdogOverflow))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_frameWatchdogOverflow);
        rif->status.numOfRamps++;
    }

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_rampEnd))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_rampEnd);
        rif->status.numOfRamps++;
    }

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_chirpEnd))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_chirpEnd);
        rif->status.chirpEnd = 1;
        rif->status.numOfChirps++;
    }

    if (IfxRif_getInterruptFlagStatus(rifSFR, IfxRif_Interrupt_ramp1Start))
    {
        IfxRif_clearInterruptFlag(rifSFR, IfxRif_Interrupt_ramp1Start);
    }
}


void IfxRif_Rif_startDeserializers(IfxRif_Rif *rif)
{
    Ifx_RIF *rifSFR = rif->rif;

    switch (rif->numOfChannels)
    {
    case 1:
        IfxRif_enableDeserializer(rifSFR, IfxRif_DeserializerId_0);
        break;
    case 2:
        IfxRif_enableDeserializer(rifSFR, IfxRif_DeserializerId_0);
        IfxRif_enableDeserializer(rifSFR, IfxRif_DeserializerId_1);
        break;
    case 3:
    case 4:
        IfxRif_enableDeserializer(rifSFR, IfxRif_DeserializerId_0);
        IfxRif_enableDeserializer(rifSFR, IfxRif_DeserializerId_1);
        IfxRif_enableDeserializer(rifSFR, IfxRif_DeserializerId_2);
        IfxRif_enableDeserializer(rifSFR, IfxRif_DeserializerId_3);
        break;
    default:
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE); /* Wrong selection  */
        break;
    }
}


void IfxRif_Rif_stopDeserializers(IfxRif_Rif *rif)
{
    Ifx_RIF *rifSFR = rif->rif;

    switch (rif->numOfChannels)
    {
    case 1:
        IfxRif_disableDeserializer(rifSFR, IfxRif_DeserializerId_0);
        break;
    case 2:
        IfxRif_disableDeserializer(rifSFR, IfxRif_DeserializerId_0);
        IfxRif_disableDeserializer(rifSFR, IfxRif_DeserializerId_1);
        break;
    case 3:
    case 4:
        IfxRif_disableDeserializer(rifSFR, IfxRif_DeserializerId_0);
        IfxRif_disableDeserializer(rifSFR, IfxRif_DeserializerId_1);
        IfxRif_disableDeserializer(rifSFR, IfxRif_DeserializerId_2);
        IfxRif_disableDeserializer(rifSFR, IfxRif_DeserializerId_3);
        break;
    default:
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE); /* Wrong selection  */
        break;
    }
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
