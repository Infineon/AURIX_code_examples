/**
 * \file IfxStm_Timer.c
 * \brief STM TIMER details
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
	/* Calculates and returns the timer frequency in Hz */
    return 1.0f / IfxStm_Timer_tickToS(driver->base.clockFreq, driver->base.period);
}


float32 IfxStm_Timer_getInputFrequency(IfxStm_Timer *driver)
{
    /* Returns the input clock frequency of the timer */
    return driver->base.clockFreq;
}


Ifx_TimerValue IfxStm_Timer_getPeriod(IfxStm_Timer *driver)
{
    /* Returns the timer period in seconds */
    return driver->base.period;
}


float32 IfxStm_Timer_getResolution(IfxStm_Timer *driver)
{
    /* Calculates and returns the timer resolution in seconds */
    return 1.0f / driver->base.clockFreq;
}


void IfxStm_Timer_run(IfxStm_Timer *driver)
{
    boolean interruptState;
    uint64  timer;

    /* Disables interrupts and save the current state */
    interruptState = IfxCpu_disableInterrupts();
    /* Retrieves the index of a specific STM module */
    timer          = IfxStm_get(driver->stm);
    /* Restores the interrupt state */
    IfxCpu_restoreInterrupts(interruptState);

    driver->comparatorValue = (Ifx_TimerValue)(timer >> driver->comparatorShift) + driver->base.period;

    IfxStm_updateCompare(driver->stm, driver->comparator, driver->comparatorValue);
    IfxStm_enableComparatorInterrupt(driver->stm, driver->comparator);
}


boolean IfxStm_Timer_setFrequency(volatile IfxStm_Timer *driver, float32 frequency)
{
    Ifx_TimerValue period = IfxStm_Timer_sToTick(driver->base.clockFreq, 1.0f / frequency);

    return IfxStm_Timer_setPeriod(driver, period);
}


boolean IfxStm_Timer_setPeriod(volatile IfxStm_Timer *driver, Ifx_TimerValue period)
{
    driver->base.period = period;

    return TRUE;
}


void IfxStm_Timer_setSingleMode(IfxStm_Timer *driver, boolean enabled)
{
    driver->base.singleShot = enabled;
}


#if IFXSTM_TIMER_STDIF
boolean IfxStm_Timer_stdIfTimerInit(IfxStm_Timer_StdIf *stdif, IfxStm_Timer *driver)
{
    IfxStm_Timer_initStdIf(stdif, driver);
    /* Sets the API link */
    stdif->getFrequency         = (IfxStm_Timer_GetFrequency) & IfxStm_Timer_getFrequency;
    stdif->getPeriod            = (IfxStm_Timer_GetPeriod) & IfxStm_Timer_getPeriod;
    stdif->getResolution        = (IfxStm_Timer_GetResolution) & IfxStm_Timer_getResolution;
    /* stdif->getTrigger */
    stdif->setFrequency         = (IfxStm_Timer_SetFrequency) & IfxStm_Timer_setFrequency;
    stdif->updateInputFrequency = (IfxStm_Timer_UpdateInputFrequency) & IfxStm_Timer_updateInputFrequency;
    /* stdif->applyUpdate */
    /* stdif->disableUpdate */
    stdif->getInputFrequency = (IfxStm_Timer_GetInputFrequency) & IfxStm_Timer_getInputFrequency;
    stdif->run               = (IfxStm_Timer_Run) & IfxStm_Timer_run;
    stdif->setPeriod         = (IfxStm_Timer_SetPeriod) & IfxStm_Timer_setPeriod;
    stdif->setSingleMode     = (IfxStm_Timer_SetSingleMode) & IfxStm_Timer_setSingleMode;
    /* stdif->setTrigger */
    stdif->stop              = (IfxStm_Timer_Stop) & IfxStm_Timer_stop;
    stdif->ackTimerIrq       = (IfxStm_Timer_AckTimerIrq) & IfxStm_Timer_acknowledgeTimerIrq;
    /* stdif->ackTriggerIrq */

    return TRUE;
}
#endif /* IFXSTM_TIMER_STDIF */


void IfxStm_Timer_stop(IfxStm_Timer *driver)
{
    IfxStm_disableComparatorInterrupt(driver->stm, driver->comparator);
}


void IfxStm_Timer_updateInputFrequency(volatile IfxStm_Timer *driver)
{
    float32 freqency;
    freqency               = (float32)IfxStm_getFrequency();
    driver->base.clockFreq = freqency / (1 << driver->comparatorShift);
}


boolean IfxStm_Timer_init(volatile IfxStm_Timer *driver, const IfxStm_Timer_Config *config)
{
    boolean                     result = TRUE;
    volatile IfxStm_Timer_Base *base   = &driver->base;
    uint32                      val;

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, config->base.countDir == IfxStm_Timer_CountDir_up); /* Only this mode is supported */

    driver->stm          = config->stm;
    driver->comparator   = config->comparator;

    base->triggerEnabled = config->base.trigger.enabled;
    base->singleShot     = FALSE;

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, config->base.trigger.enabled == FALSE); /* Trigger feature not supported */
    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, config->base.startOffset == 0);         /* Trigger feature not supported */

    /* Initializes the timer part */
    /* STM timer is already running after reset (free running timer) */

    /* Calculates shift */
    driver->comparatorShift = 0;
    val                     = (uint32)(config->base.minResolution * IfxStm_getFrequency());

    if (val != 0)
    {
        driver->comparatorShift = 32 - __clz(val) - 1;
    }

    IfxStm_Timer_updateInputFrequency(driver);

    if ((config->base.minResolution > 0) && ((1.0f / base->clockFreq) > config->base.minResolution))
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
        IfxStm_Index index;
        index = (IfxStm_Index)IfxCpu_getCoreId();
        /* clears the interrupt flag of the selected comparator */
        IfxStm_clearCompareFlag(driver->stm, driver->comparator);

        volatile Ifx_SRC_SRCR *src;
        src = IfxStm_getSrcPointer(index, (IfxStm_ComparatorInterrupt)config->comparator);
        IfxSrc_init(src, config->base.isrProvider, config->base.isrPriority, IfxSrc_VmId_0);
        IfxSrc_enable(src);
    }

    return result;
}


void IfxStm_Timer_initConfig(IfxStm_Timer_Config *config, Ifx_CPU *cpu)
{
    IfxStm_Timer_initConfig_Base(&config->base);
    config->stm        = cpu;
    config->comparator = IfxStm_Comparator_0;
}


void IfxStm_Timer_initConfig_Base(IfxStm_Timer_Config_Base *config)
{
    config->frequency                  = 1000;
    config->isrPriority                = 0;
    config->isrProvider                = IfxSrc_Tos_cpu0;
    config->minResolution              = 0;
    config->trigger.outputMode         = IfxPort_OutputMode_pushPull;
    config->trigger.outputDriver       = IfxPort_PadDriver_cmosAutomotiveSpeed1;
    config->trigger.risingEdgeAtPeriod = FALSE;
    config->trigger.outputEnabled      = FALSE;
    config->trigger.enabled            = FALSE;
    config->trigger.triggerPoint       = 0;
    config->trigger.isrPriority        = 0;
    config->trigger.isrProvider        = IfxSrc_Tos_cpu0;
    config->countDir                   = IfxStm_Timer_CountDir_up;
    config->startOffset                = 0.0;
}


#if IFXSTM_TIMER_STDIF

static float32 IfxStm_Timer_nopGetFrequency(IfxStm_Timer_InterfaceDriver stdif)
{
	return 0.0;
}
static Ifx_TimerValue IfxStm_Timer_nopGetPeriod(IfxStm_Timer_InterfaceDriver stdif)
{
	return 0;
}
static float32 IfxStm_Timer_nopGetResolution(IfxStm_Timer_InterfaceDriver stdif)
{
	return 0.0;
}
static Ifx_TimerValue IfxStm_Timer_nopGetTrigger(IfxStm_Timer_InterfaceDriver stdif)
{
	return 0;
}
static boolean IfxStm_Timer_nopSetFrequency(IfxStm_Timer_InterfaceDriver stdif, float32 frequency)
{
	return FALSE;
}
static void IfxStm_Timer_nopUpdateInputFrequency(IfxStm_Timer_InterfaceDriver stdif)
{
}
static void IfxStm_Timer_nopApplyUpdate(IfxStm_Timer_InterfaceDriver stdif)
{
}
static void IfxStm_Timer_nopDisableUpdate(IfxStm_Timer_InterfaceDriver stdif)
{
}
static float32 IfxStm_Timer_nopGetInputFrequency(IfxStm_Timer_InterfaceDriver stdif)
{
	return 0.0;
}
static void IfxStm_Timer_nopRun(IfxStm_Timer_InterfaceDriver stdif)
{
}
static boolean IfxStm_Timer_nopSetPeriod(IfxStm_Timer_InterfaceDriver stdif, Ifx_TimerValue period)
{
	return FALSE;
}
static void IfxStm_Timer_nopSetSingleMode(IfxStm_Timer_InterfaceDriver stdif, boolean enabled)
{
}
static void IfxStm_Timer_nopSetTrigger(IfxStm_Timer_InterfaceDriver stdif, Ifx_TimerValue triggerPoint)
{
}
static void IfxStm_Timer_nopStop(IfxStm_Timer_InterfaceDriver stdif)
{
}
static boolean IfxStm_Timer_nopAckTimerIrq(IfxStm_Timer_InterfaceDriver stdif)
{
	return FALSE;
}
static boolean IfxStm_Timer_nopAckTriggerIrq(IfxStm_Timer_InterfaceDriver stdif)
{
	return FALSE;
}


void IfxStm_Timer_initStdIf(IfxStm_Timer_StdIf *stdIf, IfxStm_Timer_InterfaceDriver driver)
{
    stdIf->driver               = driver;
    stdIf->getFrequency         =&IfxStm_Timer_nopGetFrequency        ;
    stdIf->getPeriod            =&IfxStm_Timer_nopGetPeriod           ;
    stdIf->getResolution        =&IfxStm_Timer_nopGetResolution       ;
    stdIf->getTrigger           =&IfxStm_Timer_nopGetTrigger          ;
    stdIf->setFrequency         =&IfxStm_Timer_nopSetFrequency        ;
    stdIf->updateInputFrequency =&IfxStm_Timer_nopUpdateInputFrequency;
    stdIf->applyUpdate          =&IfxStm_Timer_nopApplyUpdate         ;
    stdIf->disableUpdate        =&IfxStm_Timer_nopDisableUpdate       ;
    stdIf->getInputFrequency    =&IfxStm_Timer_nopGetInputFrequency   ;
    stdIf->run                  =&IfxStm_Timer_nopRun                 ;
    stdIf->setPeriod            =&IfxStm_Timer_nopSetPeriod           ;
    stdIf->setSingleMode        =&IfxStm_Timer_nopSetSingleMode       ;
    stdIf->setTrigger           =&IfxStm_Timer_nopSetTrigger          ;
    stdIf->stop                 =&IfxStm_Timer_nopStop                ;
    stdIf->ackTimerIrq          =&IfxStm_Timer_nopAckTimerIrq         ;
    stdIf->ackTriggerIrq        =&IfxStm_Timer_nopAckTriggerIrq       ;
}

#endif /* IFXSTM_TIMER_STDIF */
