/**
 * \file IfxCcu6_Timer.c
 * \brief CCU6 TIMER details
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxCcu6_Timer.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxCcu6_Timer_countOneStep(IfxCcu6_Timer *timer)
{
    if (timer->timer == IfxCcu6_TimerId_t13)
    {
        // enable shadow transfer
        IfxCcu6_enableShadowTransfer(timer->ccu6, FALSE, TRUE);

        // enable manual counting mode
        IfxCcu6_setCountingInputMode(timer->ccu6, IfxCcu6_TimerId_t13, IfxCcu6_CountingInputMode_manual);
        IfxCcu6_enableCountEvent(timer->ccu6, FALSE, TRUE);
    }
    else if (timer->timer == IfxCcu6_TimerId_t12)
    {
        // enable shadow transfer
        IfxCcu6_enableShadowTransfer(timer->ccu6, TRUE, FALSE);

        // enable manual counting mode
        IfxCcu6_setCountingInputMode(timer->ccu6, IfxCcu6_TimerId_t12, IfxCcu6_CountingInputMode_manual);
        IfxCcu6_enableCountEvent(timer->ccu6, TRUE, FALSE);
    }
}


void IfxCcu6_Timer_initModule(IfxCcu6_Timer *timer, const IfxCcu6_Timer_Config *config)
{
    Ifx_CCU6 *ccu6SFR = config->ccu6; // pointer to CCU6 registers
    timer->ccu6 = ccu6SFR;            // adding register pointer to module handler

    /* -- hardware module initialisation -- */

    // enable module if it hasn't been enabled by any other interface //
    if (IfxCcu6_isModuleEnabled(ccu6SFR) == FALSE)
    {
        IfxCcu6_enableModule(ccu6SFR);
    }

    /* -- timer initialisation -- */

    // Timer 13 initialisation //

    if ((config->timer == IfxCcu6_TimerId_t13) || (config->synchronousOperation))
    {
        // enable Timer13 if it hasn't been enabled by any other interface //
        if (IfxCcu6_getTimerAvailabilityStatus(ccu6SFR, IfxCcu6_TimerId_t13) == FALSE)
        {
            IfxCcu6_enableTimer(ccu6SFR, IfxCcu6_TimerId_t13);
        }

        // clock initialisation //

        if (config->clock.t13ExtClockEnabled)   // if external source is selected as reference
        {
            // input signal selection
            if (config->clock.t13ExtClockInput != NULL_PTR)
            {
                IfxCcu6_setT13InputSignal(config->ccu6, config->clock.t13ExtClockInput);
            }

            // counting input mode selection
            IfxCcu6_setCountingInputMode(ccu6SFR, IfxCcu6_TimerId_t13, config->clock.t13countingInputMode);

            // period setting
            IfxCcu6_setT13PeriodValue(ccu6SFR, (uint16)config->base.t13Period);
        }
        else    // if internal clock is selected as reference
        {
            IfxCcu6_setT13Frequency(ccu6SFR, config->base.t13Frequency, config->base.t13Period);
        }

        // counter initialisation //

        IfxCcu6_setT13CounterValue(ccu6SFR, config->timer13.counterValue);

        // if Timer 13 start is in sync with Timer 12 //
        if ((config->trigger.t13InSyncWithT12) && (!(config->synchronousOperation)))
        {
            IfxCcu6_setT13TriggerEventMode(ccu6SFR, config->timer13.t12SyncEvent);
            IfxCcu6_setT13TriggerEventDirection(ccu6SFR, config->timer13.t12SyncDirection);
        }
    }
    else
    {}

    // Timer 12 initialisation //

    if ((config->timer == IfxCcu6_TimerId_t12) || (config->trigger.t13InSyncWithT12) || (config->synchronousOperation))
    {
        Ifx_TimerValue period = config->base.t12Period;

        // enable Timer12 if it hasn't been enabled by any other interface //
        if (IfxCcu6_getTimerAvailabilityStatus(ccu6SFR, IfxCcu6_TimerId_t12) == FALSE)
        {
            IfxCcu6_enableTimer(ccu6SFR, IfxCcu6_TimerId_t12);
        }

        // if Timer 13 start is in sync with Timer 12 //
        if ((config->trigger.t13InSyncWithT12) && (!(config->synchronousOperation)) && (config->base.waitingTime != 0))
        {
            // if in sync with T12 period match (only period match is allowed in this interface because T12 is only in counter mode)
            if (config->timer13.t12SyncEvent == IfxCcu6_T13TriggerEvent_onT12Period)
            {
                period = config->base.waitingTime;     // waiting time as period
            }
        }
        else
        {
            // configuration error
        }

        // clock initialisation //

        if (config->clock.t12ExtClockEnabled)   // if external source is selected as reference
        {
            // input signal selection
            if (config->clock.t12ExtClockInput != NULL_PTR)
            {
                IfxCcu6_setT12InputSignal(config->ccu6, config->clock.t12ExtClockInput);
            }

            // counting input mode selection
            IfxCcu6_setCountingInputMode(ccu6SFR, IfxCcu6_TimerId_t12, config->clock.t12countingInputMode);

            // countining mode selection
            IfxCcu6_setT12CountMode(ccu6SFR, config->timer12.countMode);

            // period selection for center aligned mode
            if (config->timer12.countMode == IfxCcu6_T12CountMode_centerAligned)
            {
                period = (period / 2) - 1;
            }

            // period setting
            IfxCcu6_setT12PeriodValue(ccu6SFR, (uint16)period);
        }
        else    // if internal clock is selected as reference
        {
            // in case of in sync with T13, T12 runs at same frequency as T13
            IfxCcu6_setT12Frequency(ccu6SFR, config->base.t12Frequency, period, config->timer12.countMode);
        }

        // counter initialisation //

        IfxCcu6_setT12CounterValue(ccu6SFR, config->timer12.counterValue);
    }

    /* -- Pin mapping -- */

    const IfxCcu6_Timer_Pins *pins = config->pins;

    if (pins != NULL_PTR)
    {
        IfxCcu6_T12hr_In *t12hr = pins->t12hr;

        if (t12hr != NULL_PTR)
        {
            IfxCcu6_initT12hrPin(t12hr, pins->t1xhrInputMode);
        }

        IfxCcu6_T13hr_In *t13hr = pins->t13hr;

        if (t13hr != NULL_PTR)
        {
            IfxCcu6_initT13hrPin(t13hr, pins->t1xhrInputMode);
        }
    }

    /* -- interrupt initialisation -- */

    if (config->interrupt1.priority > 0)
    {
        IfxCcu6_enableInterrupt(config->ccu6, config->interrupt1.source);
        IfxCcu6_routeInterruptNode(config->ccu6, config->interrupt1.source, config->interrupt1.serviceRequest);

        volatile Ifx_SRC_SRCR *src;
        src = IfxCcu6_getSrcAddress(config->ccu6, config->interrupt1.serviceRequest);
        IfxSrc_init(src, config->interrupt1.typeOfService, config->interrupt1.priority);
        IfxSrc_enable(src);
    }

    if (config->interrupt2.priority > 0)
    {
        IfxCcu6_enableInterrupt(config->ccu6, config->interrupt2.source);
        IfxCcu6_routeInterruptNode(config->ccu6, config->interrupt2.source, config->interrupt2.serviceRequest);

        volatile Ifx_SRC_SRCR *src;
        src = IfxCcu6_getSrcAddress(config->ccu6, config->interrupt2.serviceRequest);
        IfxSrc_init(src, config->interrupt2.typeOfService, config->interrupt2.priority);
        IfxSrc_enable(src);
    }

    if (config->interrupt3.priority > 0)
    {
        IfxCcu6_enableInterrupt(config->ccu6, config->interrupt3.source);
        IfxCcu6_routeInterruptNode(config->ccu6, config->interrupt3.source, config->interrupt3.serviceRequest);

        volatile Ifx_SRC_SRCR *src;
        src = IfxCcu6_getSrcAddress(config->ccu6, config->interrupt3.serviceRequest);
        IfxSrc_init(src, config->interrupt3.typeOfService, config->interrupt3.priority);
        IfxSrc_enable(src);
    }

    if (config->interrupt4.priority > 0)
    {
        IfxCcu6_enableInterrupt(config->ccu6, config->interrupt4.source);
        IfxCcu6_routeInterruptNode(config->ccu6, config->interrupt4.source, config->interrupt4.serviceRequest);

        volatile Ifx_SRC_SRCR *src;
        src = IfxCcu6_getSrcAddress(config->ccu6, config->interrupt4.serviceRequest);
        IfxSrc_init(src, config->interrupt4.typeOfService, config->interrupt4.priority);
        IfxSrc_enable(src);
    }

    timer->timer   = config->timer;
    timer->trigger = config->trigger;

#if IFX_CFG_USE_STANDARD_INTERFACE
    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, (uint32)timer == ((uint32)&timer->base));
    timer->base.functions.start               = (Timer_Start) & IfxCcu6_Timer_start;
    timer->base.functions.stop                = (Timer_Stop) & IfxCcu6_Timer_stop;
    timer->base.functions.synchronousStart    = (Timer_SynchronousStart) & IfxCcu6_Timer_synchronousStart;
    timer->base.functions.synchronousStop     = (Timer_SynchronousStop) & IfxCcu6_Timer_synchronousStop;
    timer->base.functions.countOneStep        = (Timer_CountOneStep) & IfxCcu6_Timer_countOneStep;
    timer->base.functions.startSingleShotMode = (Timer_StartSingleShotMode) & IfxCcu6_Timer_startSingleShotMode;
#endif
}


void IfxCcu6_Timer_initModuleConfig(IfxCcu6_Timer_Config *config, Ifx_CCU6 *ccu6)
{
    const IfxCcu6_Timer_Config defaultConfig = {
        .ccu6                 = NULL_PTR, // will be initialized below

        .base.t12Frequency    = 400000,
        .base.t13Frequency    = 400000,
        .base.t12Period       = 100,
        .base.t13Period       = 100,
        .base.waitingTime     = 20,

        .timer                = IfxCcu6_TimerId_t13,
        .synchronousOperation = FALSE,

        .pins                 = NULL_PTR,

        .clock                = {
            .t12ExtClockEnabled   = FALSE,
            .t12ExtClockInput     = NULL_PTR,
            .t12countingInputMode = IfxCcu6_CountingInputMode_internal,

            .t13ExtClockEnabled   = FALSE,
            .t13ExtClockInput     = NULL_PTR,
            .t13countingInputMode = IfxCcu6_CountingInputMode_internal,
        },

        .timer12                  = {
            .countMode    = IfxCcu6_T12CountMode_edgeAligned,
            .counterValue = 0,
        },

        .timer13                  = {
            .counterValue     = 0,
            .t12SyncEvent     = IfxCcu6_T13TriggerEvent_onCC60RCompare,
            .t12SyncDirection = IfxCcu6_T13TriggerDirection_onT12CountingUp,
        },

        .interrupt1               = {
            .source         = IfxCcu6_InterruptSource_t12PeriodMatch,
            .serviceRequest = IfxCcu6_ServiceRequest_0,
            .priority       = 0,                // interrupt priority 0
            .typeOfService  = IfxSrc_Tos_cpu0,  // type of service CPU0
        },

        .interrupt2               = {
            .source         = IfxCcu6_InterruptSource_t13PeriodMatch,
            .serviceRequest = IfxCcu6_ServiceRequest_1,
            .priority       = 0,                // interrupt priority 0
            .typeOfService  = IfxSrc_Tos_cpu0,  // type of service CPU0
        },

        .interrupt3               = {
            .source         = IfxCcu6_InterruptSource_t12OneMatch,
            .serviceRequest = IfxCcu6_ServiceRequest_2,
            .priority       = 0,                // interrupt priority 0
            .typeOfService  = IfxSrc_Tos_cpu0,  // type of service CPU0
        },

        .interrupt4               = {
            .source         = IfxCcu6_InterruptSource_trap,
            .serviceRequest = IfxCcu6_ServiceRequest_3,
            .priority       = 0,                // interrupt priority 0
            .typeOfService  = IfxSrc_Tos_cpu0,  // type of service CPU0
        },

        .trigger                  = {
            .t12ExtInputTrigger  = NULL_PTR,
            .t13ExtInputTrigger  = NULL_PTR,
            .extInputTriggerMode = IfxCcu6_ExternalTriggerMode_risingEdge,
            .t13InSyncWithT12    = TRUE,
        },
    };

    /* Default Configuration */
    *config = defaultConfig;

    /* take over module pointer */
    config->ccu6 = ccu6;
}


void IfxCcu6_Timer_start(IfxCcu6_Timer *timer)
{
    // Timer 13 start //

    if (timer->timer == IfxCcu6_TimerId_t13)
    {
        // enable shadow transfer
        IfxCcu6_enableShadowTransfer(timer->ccu6, FALSE, TRUE);

        // start Timer 13 when not in sync with timer12
        if (!(timer->trigger.t13InSyncWithT12))
        {
            if (timer->trigger.t13ExtInputTrigger != NULL_PTR)
            {
                // external start
                IfxCcu6_setExternalRunMode(timer->ccu6, IfxCcu6_TimerId_t13, timer->trigger.extInputTriggerMode);
                IfxCcu6_setT13InputSignal(timer->ccu6, timer->trigger.t13ExtInputTrigger);
            }
            else
            {
                // internal start
                IfxCcu6_startTimer(timer->ccu6, FALSE, TRUE);
            }
        }
        else
        {}
    }
    else
    {}

    // Timer 12 start alone or when in sync with Timer 13 //

    if ((timer->timer == IfxCcu6_TimerId_t12) || (timer->trigger.t13InSyncWithT12))
    {
        // enable shadow transfer
        IfxCcu6_enableShadowTransfer(timer->ccu6, TRUE, FALSE);

        //start Timer 12
        if (timer->trigger.t12ExtInputTrigger != NULL_PTR)
        {
            // external start
            IfxCcu6_setExternalRunMode(timer->ccu6, IfxCcu6_TimerId_t12, timer->trigger.extInputTriggerMode);
            IfxCcu6_setT12InputSignal(timer->ccu6, timer->trigger.t12ExtInputTrigger);
        }
        else
        {
            // internal start
            IfxCcu6_startTimer(timer->ccu6, TRUE, FALSE);
        }
    }
    else
    {}
}


void IfxCcu6_Timer_startSingleShotMode(IfxCcu6_Timer *timer)
{
    // Timer 13 start //

    if (timer->timer == IfxCcu6_TimerId_t13)
    {
        // enable shadow transfer
        IfxCcu6_enableShadowTransfer(timer->ccu6, FALSE, TRUE);

        //enable single shot mode
        IfxCcu6_enableSingleShotMode(timer->ccu6, IfxCcu6_TimerId_t13);

        // start Timer 13 when not in sync with timer12
        if (!(timer->trigger.t13InSyncWithT12))
        {
            if (timer->trigger.t13ExtInputTrigger != NULL_PTR)
            {
                // external start
                IfxCcu6_setExternalRunMode(timer->ccu6, IfxCcu6_TimerId_t13, timer->trigger.extInputTriggerMode);
                IfxCcu6_setT13InputSignal(timer->ccu6, timer->trigger.t13ExtInputTrigger);
            }
            else
            {
                // internal start
                IfxCcu6_startTimer(timer->ccu6, FALSE, TRUE);
            }
        }
        else
        {}
    }
    else
    {}

    // Timer 12 start alone or when in sync with Timer 13 //

    if ((timer->timer == IfxCcu6_TimerId_t12) || (timer->trigger.t13InSyncWithT12))
    {
        // enable shadow transfer
        IfxCcu6_enableShadowTransfer(timer->ccu6, TRUE, FALSE);

        //enable single shot mode
        IfxCcu6_enableSingleShotMode(timer->ccu6, IfxCcu6_TimerId_t12);

        if (timer->trigger.t12ExtInputTrigger != NULL_PTR)
        {
            // external start
            IfxCcu6_setExternalRunMode(timer->ccu6, IfxCcu6_TimerId_t12, timer->trigger.extInputTriggerMode);
            IfxCcu6_setT12InputSignal(timer->ccu6, timer->trigger.t12ExtInputTrigger);
        }
        else
        {
            // internal start
            IfxCcu6_startTimer(timer->ccu6, TRUE, FALSE);
        }
    }
    else
    {}
}


void IfxCcu6_Timer_stop(IfxCcu6_Timer *timer)
{
    // Timer 13 stop //

    if ((timer->timer == IfxCcu6_TimerId_t13) || (timer->trigger.t13InSyncWithT12))
    {
        // disable shadow transfer
        IfxCcu6_disableShadowTransfer(timer->ccu6, FALSE, TRUE);

        // remove external input trigger if any
        if (timer->trigger.t13ExtInputTrigger != NULL_PTR)
        {
            IfxCcu6_setExternalRunMode(timer->ccu6, IfxCcu6_TimerId_t13, IfxCcu6_ExternalTriggerMode_disable);
        }

        // remove the sync with Timer 12
        if (timer->trigger.t13InSyncWithT12)
        {
            IfxCcu6_setT13TriggerEventMode(timer->ccu6, IfxCcu6_T13TriggerEvent_noAction);
            IfxCcu6_setT13TriggerEventDirection(timer->ccu6, IfxCcu6_T13TriggerDirection_noAction);
        }

        // stop Timer 13
        IfxCcu6_stopTimer(timer->ccu6, FALSE, TRUE);
    }

    // Timer 12 stop //

    else
    {
        // disable shadow transfer
        IfxCcu6_disableShadowTransfer(timer->ccu6, TRUE, FALSE);

        // remove external input trigger if any
        if (timer->trigger.t12ExtInputTrigger != NULL_PTR)
        {
            IfxCcu6_setExternalRunMode(timer->ccu6, IfxCcu6_TimerId_t12, IfxCcu6_ExternalTriggerMode_disable);
        }

        // stop Timer 12
        IfxCcu6_stopTimer(timer->ccu6, TRUE, FALSE);
    }
}


void IfxCcu6_Timer_synchronousStart(IfxCcu6_Timer *timer)
{
    // enable shadow transfer
    IfxCcu6_enableShadowTransfer(timer->ccu6, TRUE, TRUE);

    // only internal synchronous start is possible
    IfxCcu6_startTimer(timer->ccu6, TRUE, TRUE);
}


void IfxCcu6_Timer_synchronousStop(IfxCcu6_Timer *timer)
{
    // disable shadow transfer
    IfxCcu6_disableShadowTransfer(timer->ccu6, TRUE, TRUE);

    // only internal synchronous stop is possible
    IfxCcu6_stopTimer(timer->ccu6, TRUE, TRUE);
}
