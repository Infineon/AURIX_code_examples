/**
 * \file IfxEgtm_Tom_Timer.c
 * \brief EGTM TIMER details
 *
 * \version iLLD-TC4-v2.1.1
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxEgtm_Tom_Timer.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxEgtm_Tom_Timer_acknowledgeTimerIrq(IfxEgtm_Tom_Timer *driver)
{
    boolean event;

    event = IfxEgtm_Tom_Ch_isZeroNotification(driver->tom, driver->timerChannel);

    if (event == TRUE)
    {
        IfxEgtm_Tom_Ch_clearZeroNotification(driver->tom, driver->timerChannel);
    }

    return event;
}


boolean IfxEgtm_Tom_Timer_acknowledgeTriggerIrq(IfxEgtm_Tom_Timer *driver)
{
    boolean event;

    event = IfxEgtm_Tom_Ch_isOneNotification(driver->tom, driver->triggerChannel);

    if (event == TRUE)
    {
        IfxEgtm_Tom_Ch_clearOneNotification(driver->tom, driver->triggerChannel);
    }

    return event;
}


boolean IfxEgtm_Tom_Timer_init(IfxEgtm_Tom_Timer *driver, const IfxEgtm_Tom_Timer_Config *config)
{
    boolean result = TRUE;

    /* Only count direction "up" is supported */
    if (config->countDir == IfxEgtm_Tom_Timer_CountDir_up)
    {
        /* Initialize handle */
        {
            driver->egtm           = config->egtm;
            driver->clsIndex       = config->cluster;
            driver->tom            = &config->egtm->CLS[config->cluster].TOM;
            driver->timerChannel   = config->timerChannel;
            driver->triggerEnabled = config->trigger.enabled;

            /* Get trigger channel */
            if (driver->triggerEnabled == TRUE)
            {
                if (config->triggerOut != NULL_PTR)
                {
                    driver->triggerChannel = config->triggerOut->channel;
                }
                else
                {
                    result = FALSE;
                    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, result); /* triggerOut is required */
                }
            }
            else
            {
                driver->triggerChannel = driver->timerChannel; /* Set to timer channel to disable its use */
            }

            /* Get pointer to TGC and masks */
            if (config->timerChannel <= IfxEgtm_Tom_Ch_7)
            {
                driver->tgc[0] = IfxEgtm_Tom_Ch_getTgcPointer(driver->tom, 0);
                driver->tgc[1] = IfxEgtm_Tom_Ch_getTgcPointer(driver->tom, 1);
            }
            else
            {
                driver->tgc[0] = IfxEgtm_Tom_Ch_getTgcPointer(driver->tom, 1);
                driver->tgc[1] = NULL_PTR; /* NOTE currently no concatenation between TOMs */
            }

            driver->channelsMask[0]                  = 0;
            driver->tgcGlobalControlApplyUpdate[0]   = 0;
            driver->tgcGlobalControlDisableUpdate[0] = 0;

            driver->channelsMask[1]                  = 0;
            driver->tgcGlobalControlApplyUpdate[1]   = 0;
            driver->tgcGlobalControlDisableUpdate[1] = 0;
        }

        /* Initialize the timer part */
        {
            /* Set Tom channel clock source */
            IfxEgtm_Tom_Ch_setClockSource(driver->tom, driver->timerChannel, config->clock);

            /* Store Clock frequency in the driver */
            IfxEgtm_Tom_Timer_updateInputFrequency(driver);

            /* Generate trigger at CMO match (TRIG_CCU0) */
            IfxEgtm_Tom_Ch_setTriggerOutput(driver->tom, driver->timerChannel, IfxEgtm_Tom_Ch_OutputTrigger_generate);

            /* This if block has no effect. TODO: Remove/review */
            if ((config->minResolution > 0.0f) && (driver->clockFreq > 0.0f) && ((1.0f / driver->clockFreq) > config->minResolution))
            {
                result = FALSE;
                IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
            }

            /* Set PWM frequency by setting CM0 register */
            (void)IfxEgtm_Tom_Timer_setFrequency(driver, config->frequency);

            /* Initialize CN0 (counter register) with an initial offset configured by user */
            driver->offset = IfxEgtm_sToTick(driver->clockFreq, (float32)1.0f / config->frequency * config->startOffset);
            IfxEgtm_Tom_Ch_setCounterValue(driver->tom, driver->timerChannel, driver->offset);

            /* Add timer channel to channel mask */
            IfxEgtm_Tom_Timer_addToChannelMask(driver, driver->timerChannel);
        }

        /* Initialize the trigger part */
        if (driver->triggerEnabled == TRUE)
        {
            uint16         maskShift          = (config->timerChannel <= IfxEgtm_Tom_Ch_7) ? (uint16)0 : (uint16)8;
            IfxEgtm_Tom_Ch triggerChannel     = driver->triggerChannel;
            uint16         triggerChannelMask = (uint16)((uint16)1u << ((uint16)triggerChannel - maskShift));
            /* TO DO: enable the trigger to be not in the same TGC group as the timer */

            /* Set channel signal level */
            IfxEgtm_Tom_Ch_setSignalLevel(driver->tom, triggerChannel, (config->trigger.risingEdgeAtPeriod == TRUE) ? Ifx_ActiveState_high : Ifx_ActiveState_low);

            if (triggerChannel != driver->timerChannel)
            {
                /* Reset trigger channel from timer channel */
                IfxEgtm_Tom_Ch_setResetSource(driver->tom, triggerChannel, IfxEgtm_Tom_Ch_ResetEvent_onTrigger);

                /* Set trigger channel clock source */
                IfxEgtm_Tom_Ch_setClockSource(driver->tom, triggerChannel, config->clock);

                /* Don't generate trigger at CM0 match. Instead, accept/forward timer channel's trigger */
                IfxEgtm_Tom_Ch_setTriggerOutput(driver->tom, triggerChannel, IfxEgtm_Tom_Ch_OutputTrigger_forward);

                /* Initialize CN0 (counter register) with an initial offset configured by user */
                IfxEgtm_Tom_Ch_setCounterValue(driver->tom, triggerChannel, driver->offset);

                /* Set channels to start counter when trigger is received TODO: Remove? */
                IfxEgtm_Tom_Tgc_enableChannels(driver->tgc[0], triggerChannelMask, 0, FALSE);

                /* Add trigger channel to channel mask */
                IfxEgtm_Tom_Timer_addToChannelMask(driver, driver->triggerChannel);
            }

            /* Signal must go out of the EGTM even if the port output is not enabled */
            IfxEgtm_Tom_Tgc_enableChannelsOutput(driver->tgc[0], triggerChannelMask, 0, FALSE);

            /* Initialize the port */
            if ((config->trigger.outputEnabled == TRUE) && (config->initPins == TRUE))
            {
                IfxEgtm_PinMap_setTomTout(config->triggerOut, config->trigger.outputMode, config->trigger.outputDriver);
            }

            /* Set CM1 register */
            IfxEgtm_Tom_Timer_setTrigger(driver, config->trigger.triggerPoint);
        }

        /* Interrupt configuration */
        {
            volatile Ifx_SRC_SRCR *src;
            boolean                timerHasIrq   = (config->interrupt.isrPriority > 0) ? TRUE : FALSE;
            boolean                triggerHasIrq = ((config->trigger.interrupt.isrPriority > 0) && (driver->triggerEnabled == TRUE)) ? TRUE : FALSE;

            if (driver->triggerChannel == driver->timerChannel)
            {
                IfxEgtm_Tom_Ch_setNotification(driver->tom, driver->timerChannel, (timerHasIrq == TRUE) ? config->interrupt.irqMode : config->trigger.interrupt.irqMode, timerHasIrq, triggerHasIrq);
                src = IfxEgtm_Tom_Ch_getSrcPointer(driver->egtm, config->cluster, driver->timerChannel);
                IfxSrc_init(src, (timerHasIrq == TRUE) ? config->interrupt.isrProvider : config->trigger.interrupt.isrProvider, (timerHasIrq == TRUE) ? config->interrupt.isrPriority : config->trigger.interrupt.isrPriority, config->interrupt.vmId);
                IfxSrc_enable(src);
            }
            else
            {
                IfxEgtm_IrqMode irqMode = IfxEgtm_IrqMode_pulseNotify;

                if (timerHasIrq == TRUE)
                {
                    IfxEgtm_Tom_Ch_setNotification(driver->tom, driver->timerChannel, irqMode, TRUE, FALSE);
                    src = IfxEgtm_Tom_Ch_getSrcPointer(driver->egtm, config->cluster, driver->timerChannel);
                    IfxSrc_init(src, config->interrupt.isrProvider, config->interrupt.isrPriority, config->interrupt.vmId);
                    IfxSrc_enable(src);
                }

                if (triggerHasIrq == TRUE)
                {
                    IfxEgtm_Tom_Ch_setNotification(driver->tom, driver->triggerChannel, irqMode, FALSE, TRUE);
                    src = IfxEgtm_Tom_Ch_getSrcPointer(driver->egtm, config->cluster, driver->triggerChannel);
                    IfxSrc_init(src, config->trigger.interrupt.isrProvider, config->trigger.interrupt.isrPriority, config->interrupt.vmId);
                    IfxSrc_enable(src);
                }
            }
        }

        /* Transfer values from shadow registers */
        {
            /* Enable force update from shadow of timer/trigger channel */
            IfxEgtm_Tom_Tgc_setChannelsForceUpdate(driver->tgc[0], driver->channelsMask[0], 0, 0, 0);

            /* Give host trigger to start channel(s) */
            IfxEgtm_Tom_Tgc_trigger(driver->tgc[0]);

            /* Disable force update from shadow of timer/trigger channel */
            IfxEgtm_Tom_Tgc_setChannelsForceUpdate(driver->tgc[0], 0, driver->channelsMask[0], 0, 0);
        }
    }
    else
    {
        result = FALSE;
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, config->countDir == IfxEgtm_Tom_Timer_CountDir_up);    /* only this mode is supported */
    }

    return result;
}


void IfxEgtm_Tom_Timer_initConfig(IfxEgtm_Tom_Timer_Config *config, Ifx_EGTM *egtm)
{
    const IfxEgtm_Tom_Timer_Config defaultConfig = {
        .egtm           = NULL_PTR,
        .cluster        = IfxEgtm_Cluster_0,
        .timerChannel   = IfxEgtm_Tom_Ch_0,
        .triggerOut     = NULL_PTR,
        .clock          = IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk0,
        .dtmClockSource = IfxEgtm_Dtm_ClockSource_cmuClock0,
        .frequency      = 1000.0f,
        .minResolution  = 0.0f,
        .startOffset    = 0.0f,
        .countDir       = IfxEgtm_Tom_Timer_CountDir_up,
        .interrupt      = {
            .isrPriority = 0u,
            .isrProvider = IfxSrc_Tos_cpu0,
            .irqMode     = IfxEgtm_IrqMode_level,
            .vmId        = IfxSrc_VmId_0,
        },
        .trigger                = {
            .enabled            = FALSE,
            .triggerPoint       = 0u,
            .outputMode         = IfxPort_OutputMode_pushPull,
            .outputDriver       = IfxPort_PadDriver_cmosAutomotiveSpeed1,
            .risingEdgeAtPeriod = FALSE,
            .outputEnabled      = FALSE,
            .interrupt          = {
                .isrPriority = 0u,
                .isrProvider = IfxSrc_Tos_cpu0,
                .irqMode     = IfxEgtm_IrqMode_level,
                .vmId        = IfxSrc_VmId_0,
            },
        },
        .initPins               = TRUE,
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* Copy SFR */
    config->egtm = egtm;
}


void IfxEgtm_Tom_Timer_run(IfxEgtm_Tom_Timer *driver)
{
    /* Enable all concerned channels */
    IfxEgtm_Tom_Tgc_enableChannels(driver->tgc[0], driver->channelsMask[0], 0, TRUE);

    if (driver->tgc[1] != NULL_PTR)
    {
        IfxEgtm_Tom_Tgc_enableChannels(driver->tgc[1], driver->channelsMask[1], 0, TRUE); /* Note: Write of 0 value has no effect */
    }
}


void IfxEgtm_Tom_Timer_stop(IfxEgtm_Tom_Timer *driver)
{
    /* Disable all concerned channels */
    IfxEgtm_Tom_Tgc_enableChannels(driver->tgc[0], 0, driver->channelsMask[0], TRUE);

    if (driver->tgc[1] != NULL_PTR)
    {
        IfxEgtm_Tom_Tgc_enableChannels(driver->tgc[1], 0, driver->channelsMask[1], TRUE); /* Note: Write of 0 value has no effect */
    }
}
