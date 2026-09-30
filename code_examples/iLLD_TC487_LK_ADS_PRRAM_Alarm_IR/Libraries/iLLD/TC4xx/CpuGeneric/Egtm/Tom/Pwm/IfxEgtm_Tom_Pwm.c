/**
 * \file IfxEgtm_Tom_Pwm.c
 * \brief EGTM PWM details
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508 /* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96 /* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC45X)
#include "IfxEgtm_Tom_Pwm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxEgtm_Tom_Pwm_init(IfxEgtm_Tom_Pwm_Driver *driver, const IfxEgtm_Tom_Pwm_Config *config)
{
    boolean           result = TRUE;

    Ifx_EGTM_CLS_TOM *tomSFR = &config->egtm->CLS[config->cluster].TOM;

    /* Copy config data into handle */
    driver->egtm       = config->egtm;
    driver->clsIndex   = config->cluster;
    driver->tom        = tomSFR;
    driver->tomChannel = config->tomChannel;
    driver->synchronousUpdateEnabled = config->synchronousUpdateEnabled;

    if (config->tomChannel <= IfxEgtm_Tom_Ch_7)
    {
        driver->tgc[0] = IfxEgtm_Tom_Ch_getTgcPointer(driver->tom, 0);
        driver->tgc[1] = IfxEgtm_Tom_Ch_getTgcPointer(driver->tom, 1);
    }
    else
    {
        driver->tgc[0] = IfxEgtm_Tom_Ch_getTgcPointer(driver->tom, 1);
        driver->tgc[1] = NULL_PTR; /* NOTE currently no concatenation between TOMs */
    }

    /* Enables update of CM0/1 from shadow registers */
    if (config->synchronousUpdateEnabled == TRUE)
    {
        IfxEgtm_Tom_Tgc_enableChannelUpdate(driver->tgc[0], config->tomChannel, TRUE);
    }

    /* Sets channel to start counter when trigger is received */
    IfxEgtm_Tom_Tgc_enableChannel(driver->tgc[0], config->tomChannel, TRUE, FALSE);

    /* Sets channel to start PWM output when trigger is received */
    IfxEgtm_Tom_Tgc_enableChannelOutput(driver->tgc[0], config->tomChannel, TRUE, FALSE);

    /* Sets TOM channel clock source */
    IfxEgtm_Tom_Ch_setClockSource(tomSFR, config->tomChannel, config->clock);

    /* Sets Signal Polarity value here */
    IfxEgtm_Tom_Ch_setSignalLevel(tomSFR, config->tomChannel, config->signalLevel);

    /* Resets counter to 0 */
    IfxEgtm_Tom_Ch_setCounterValue(tomSFR, driver->tomChannel, 0);

    /* Enables and initialize interrupts if chosen */
    if ((config->interrupt.ccu0Enabled == TRUE) || (config->interrupt.ccu1Enabled == TRUE))
    {
        volatile Ifx_SRC_SRCR *src;
        IfxEgtm_Tom_Ch_setNotification(tomSFR, config->tomChannel, config->interrupt.mode, config->interrupt.ccu0Enabled, config->interrupt.ccu1Enabled);

        src = IfxEgtm_Tom_Ch_getSrcPointer(config->egtm, config->cluster, config->tomChannel);
        IfxSrc_init(src, config->interrupt.isrProvider, config->interrupt.isrPriority, config->interrupt.vmId);
        IfxSrc_enable(src);
    }
    /* Disables interrupt */
    else
    {
        Ifx_EGTM_CLS_TOM_CH *channel = &tomSFR->CH[driver->tomChannel];
        channel->IRQ_EN.U = 0u;
    }

    /* Sets CM0, CM1, SR0, SR1 registers */
    if (config->synchronousUpdateEnabled == TRUE)
    {
        IfxEgtm_Tom_Ch_setCompareZeroShadow(tomSFR, config->tomChannel, config->period);
        IfxEgtm_Tom_Ch_setCompareOneShadow(tomSFR, config->tomChannel, config->dutyCycle);
    }
    else
    {
        IfxEgtm_Tom_Ch_setCompareZero(tomSFR, config->tomChannel, config->period);
        IfxEgtm_Tom_Ch_setCompareOne(tomSFR, config->tomChannel, config->dutyCycle);
    }

    /* Connects output pin to Tom channel */
    if (config->pin.outputPin != NULL_PTR)
    {
        IfxEgtm_PinMap_setTomTout(config->pin.outputPin, config->pin.outputMode, config->pin.padDriver);

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC4ZX) 
	    if (config->pin.outputPin->pin.port == &MODULE_P16)
	    {
	        if ((config->pin.outputPin->pin.pinIndex == 0) || (config->pin.outputPin->pin.pinIndex == 1))
	        {
	            IfxPort_setPinModex(config->pin.outputPin->pin.port, config->pin.outputPin->pin.pinIndex, IfxPort_Modex_gpioMode);
	        }
	    }
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC4ZX) */
    }


    /* Connects Msc to Tom channel */
    if (config->mscOut != NULL_PTR)
    {
        (void)IfxEgtm_ConnectToMsc(config->cluster, IfxEgtm_TrigSource_tom, (IfxEgtm_TrigChannel)config->tomChannel, config->mscOut);
    }

    /* Starts channel by giving a trigger */
    if (config->immediateStartEnabled == TRUE)
    {
        IfxEgtm_Tom_Tgc_trigger(driver->tgc[0]);
    }

    return result;
}


void IfxEgtm_Tom_Pwm_initConfig(IfxEgtm_Tom_Pwm_Config *config, Ifx_EGTM *egtm)
{
    const IfxEgtm_Tom_Pwm_Config defaultConfig = {
        .egtm        = NULL_PTR,
        .cluster     = IfxEgtm_Cluster_0,
        .tomChannel  = IfxEgtm_Tom_Ch_0,
        .clock       = IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk0,
        .signalLevel = Ifx_ActiveState_high,
        .period      = 20,
        .dutyCycle   = 10,
        .interrupt   = {
            .ccu0Enabled = FALSE,
            .ccu1Enabled = FALSE,
            .mode        = IfxEgtm_IrqMode_pulseNotify,
            .isrProvider = IfxSrc_Tos_cpu0,
            .isrPriority = 0,
            .vmId        = IfxSrc_VmId_0,
        },
        .pin                      = {
            .outputPin  = NULL_PTR,
            .outputMode = IfxPort_OutputMode_pushPull,
            .padDriver  = IfxPort_PadDriver_cmosAutomotiveSpeed1,
        },
        .mscOut                   = NULL_PTR,
        .dtmClockSource           = IfxEgtm_Dtm_ClockSource_cmuClock0,
        .oneShotModeEnabled       = FALSE,
        .synchronousUpdateEnabled = FALSE,
        .immediateStartEnabled    = TRUE,
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* Copy SFR */
    config->egtm = egtm;
}


void IfxEgtm_Tom_Pwm_start(IfxEgtm_Tom_Pwm_Driver *driver, boolean immediate)
{
    /* Enables channel if not enabled already */
    IfxEgtm_Tom_Tgc_enableChannel(driver->tgc[0], driver->tomChannel, TRUE, immediate);
    IfxEgtm_Tom_Tgc_enableChannelOutput(driver->tgc[0], driver->tomChannel, TRUE, immediate);

    /* Triggers the start now */
    IfxEgtm_Tom_Tgc_trigger(driver->tgc[0]);
}


void IfxEgtm_Tom_Pwm_stop(IfxEgtm_Tom_Pwm_Driver *driver, boolean immediate)
{
    /* Disable channels */
    IfxEgtm_Tom_Tgc_enableChannel(driver->tgc[0], driver->tomChannel, FALSE, immediate);
    IfxEgtm_Tom_Tgc_enableChannelOutput(driver->tgc[0], driver->tomChannel, FALSE, immediate);

    /* Trigger the stop now */
    IfxEgtm_Tom_Tgc_trigger(driver->tgc[0]);
}

#endif /* !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
