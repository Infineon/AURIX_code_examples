/**
 * \file IfxStm_Timer.c
 * \brief STM TIMER details
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
<<<<<<< HEAD
=======
>>>>>>> 367889a195a35e2b74e8e49983b151f4d00dfb0a
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

#include "IfxStm_Timer.h"
#include "_Utilities/Ifx_Assert.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxStm_Timer_acknowledgeTimerIrq(IfxStm_Timer *driver)
{
    boolean event;
    event = IfxStm_isCompareFlagSet(driver->stm, driver->comparator);

    if (event)
    {
        IfxStm_clearCompareFlag(driver->stm, driver->comparator);

        if (!driver->base.singleShot)
        {
            driver->comparatorValue += driver->base.period;
            IfxStm_updateCompare(driver->stm, driver->comparator, driver->comparatorValue);
        }
        else
        {
            IfxStm_disableComparatorInterrupt(driver->stm, driver->comparator);
        }
    }
    else
    {}

    return event;
}


float32 IfxStm_Timer_getFrequency(IfxStm_Timer *driver)
{
    return 1.0 / IfxStdIf_Timer_tickToS(driver->base.clockFreq, driver->base.period);
}


float32 IfxStm_Timer_getInputFrequency(IfxStm_Timer *driver)
{
    return driver->base.clockFreq;
}


Ifx_TimerValue IfxStm_Timer_getPeriod(IfxStm_Timer *driver)
{
    return driver->base.period;
}


float32 IfxStm_Timer_getResolution(IfxStm_Timer *driver)
{
    return 1.0 / driver->base.clockFreq;
}


void IfxStm_Timer_run(IfxStm_Timer *driver)
{
    boolean interruptState;
    uint64  timer;

    interruptState = IfxCpu_disableInterrupts();
    timer          = IfxStm_get(driver->stm);
    IfxCpu_restoreInterrupts(interruptState);

    driver->comparatorValue = (Ifx_TimerValue)(timer >> driver->comparatorShift) + driver->base.period;

    IfxStm_updateCompare(driver->stm, driver->comparator, driver->comparatorValue);
    IfxStm_enableComparatorInterrupt(driver->stm, driver->comparator);
}


boolean IfxStm_Timer_setFrequency(IfxStm_Timer *driver, float32 frequency)
{
    Ifx_TimerValue period = IfxStdIf_Timer_sToTick(driver->base.clockFreq, 1.0 / frequency);

    return IfxStm_Timer_setPeriod(driver, period);
}


boolean IfxStm_Timer_setPeriod(IfxStm_Timer *driver, Ifx_TimerValue period)
{
    driver->base.period = period;

    return TRUE;
}


void IfxStm_Timer_setSingleMode(IfxStm_Timer *driver, boolean enabled)
{
    driver->base.singleShot = enabled;
}


boolean IfxStm_Timer_stdIfTimerInit(IfxStdIf_Timer *stdif, IfxStm_Timer *driver)
{
    IfxStdIf_Timer_initStdIf(stdif, driver);
    /* Set the API link */
    stdif->getFrequency         = (IfxStdIf_Timer_GetFrequency) & IfxStm_Timer_getFrequency;
    stdif->getPeriod            = (IfxStdIf_Timer_GetPeriod) & IfxStm_Timer_getPeriod;
    stdif->getResolution        = (IfxStdIf_Timer_GetResolution) & IfxStm_Timer_getResolution;
    //stdif->getTrigger
    stdif->setFrequency         = (IfxStdIf_Timer_SetFrequency) & IfxStm_Timer_setFrequency;
    stdif->updateInputFrequency = (IfxStdIf_Timer_UpdateInputFrequency) & IfxStm_Timer_updateInputFrequency;
    //stdif->applyUpdate
    //stdif->disableUpdate
    stdif->getInputFrequency = (IfxStdIf_Timer_GetInputFrequency) & IfxStm_Timer_getInputFrequency;
    stdif->run               = (IfxStdIf_Timer_Run) & IfxStm_Timer_run;
    stdif->setPeriod         = (IfxStdIf_Timer_SetPeriod) & IfxStm_Timer_setPeriod;
    stdif->setSingleMode     = (IfxStdIf_Timer_SetSingleMode) & IfxStm_Timer_setSingleMode;
    //stdif->setTrigger
    stdif->stop              = (IfxStdIf_Timer_Stop) & IfxStm_Timer_stop;
    stdif->ackTimerIrq       = (IfxStdIf_Timer_AckTimerIrq) & IfxStm_Timer_acknowledgeTimerIrq;
    //stdif->ackTriggerIrq

    return TRUE;
}


void IfxStm_Timer_stop(IfxStm_Timer *driver)
{
    IfxStm_disableComparatorInterrupt(driver->stm, driver->comparator);
}


void IfxStm_Timer_updateInputFrequency(IfxStm_Timer *driver)
{
    float32 freqency;
    freqency               = IfxStm_getFrequency(driver->stm);
    driver->base.clockFreq = freqency / (1 << driver->comparatorShift);
}


boolean IfxStm_Timer_init(IfxStm_Timer *driver, const IfxStm_Timer_Config *config)
{
    boolean            result = TRUE;
    IfxStm_Timer_Base *base   = &driver->base;

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, config->base.countDir == IfxStdIf_Timer_CountDir_up); /* only this mode is supported */

    driver->stm          = config->stm;
    driver->comparator   = config->comparator;

    base->triggerEnabled = config->base.trigger.enabled;
    base->singleShot     = FALSE;

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, config->base.trigger.enabled == FALSE); /* Trigger feature not supported */
    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, config->base.startOffset == 0);         /* Trigger feature not supported */

    /* Initialize the timer part */
    // STM timer is already running after reset (free running timer)

    // Calculate shift
    driver->comparatorShift = 32 - __clz((uint32)(config->base.minResolution * IfxStm_getFrequency(driver->stm)));

    if (driver->comparatorShift > 0)
    {
        driver->comparatorShift--;
    }

    IfxStm_Timer_updateInputFrequency(driver);

    if ((config->base.minResolution > 0) && ((1.0 / base->clockFreq) > config->base.minResolution))
    {
        result = FALSE;
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
    else
    {}

    IfxStm_Timer_setFrequency(driver, config->base.frequency);

    IfxStm_setCompareControl(driver->stm, driver->comparator,
        (IfxStm_ComparatorOffset)driver->comparatorShift,
        IfxStm_ComparatorSize_32Bits,
        driver->comparator == IfxStm_Comparator_0 ? IfxStm_ComparatorInterrupt_ir0 : IfxStm_ComparatorInterrupt_ir1);

    /* Interrupt configuration */
    if (config->base.isrPriority > 0)
    {
        /* clear the interrupt flag of the selected comparator */
        IfxStm_clearCompareFlag(driver->stm, driver->comparator);

        volatile Ifx_SRC_SRCR *src;
        src = IfxStm_getSrcPointer(driver->stm, config->comparator);
        IfxSrc_init(src, config->base.isrProvider, config->base.isrPriority);
        IfxSrc_enable(src);
    }

    return result;
}


void IfxStm_Timer_initConfig(IfxStm_Timer_Config *config, Ifx_STM *stm)
{
    IfxStdIf_Timer_initConfig(&config->base);
    config->stm        = stm;
    config->comparator = IfxStm_Comparator_0;
}
