/**
 * \file IfxStdIf_Timer.c
 * \brief Standard interface: Timer
 * \ingroup IfxStdIf
 *
 * \version disabled
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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

#include "IfxStdIf_Timer.h"

void IfxStdIf_Timer_initConfig(IfxStdIf_Timer_Config *config)
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
    config->countDir                   = IfxStdIf_Timer_CountDir_up;
    config->startOffset 					   = 0.0;
}


static float32 IfxStdIf_Timer_nopGetFrequency(IfxStdIf_InterfaceDriver stdif)
{
	return 0.0;
}
static Ifx_TimerValue IfxStdIf_Timer_nopGetPeriod(IfxStdIf_InterfaceDriver stdif)
{
	return 0;
}
static float32 IfxStdIf_Timer_nopGetResolution(IfxStdIf_InterfaceDriver stdif)
{
	return 0.0;
}
static Ifx_TimerValue IfxStdIf_Timer_nopGetTrigger(IfxStdIf_InterfaceDriver stdif)
{
	return 0;
}
static boolean IfxStdIf_Timer_nopSetFrequency(IfxStdIf_InterfaceDriver stdif, float32 frequency)
{
	return FALSE;
}
static void IfxStdIf_Timer_nopUpdateInputFrequency(IfxStdIf_InterfaceDriver stdif)
{
}
static void IfxStdIf_Timer_nopApplyUpdate(IfxStdIf_InterfaceDriver stdif)
{
}
static void IfxStdIf_Timer_nopDisableUpdate(IfxStdIf_InterfaceDriver stdif)
{
}
static float32 IfxStdIf_Timer_nopGetInputFrequency(IfxStdIf_InterfaceDriver stdif)
{
	return 0.0;
}
static void IfxStdIf_Timer_nopRun(IfxStdIf_InterfaceDriver stdif)
{
}
static boolean IfxStdIf_Timer_nopSetPeriod(IfxStdIf_InterfaceDriver stdif, Ifx_TimerValue period)
{
	return FALSE;
}
static void IfxStdIf_Timer_nopSetSingleMode(IfxStdIf_InterfaceDriver stdif, boolean enabled)
{
}
static void IfxStdIf_Timer_nopSetTrigger(IfxStdIf_InterfaceDriver stdif, Ifx_TimerValue triggerPoint)
{
}
static void IfxStdIf_Timer_nopStop(IfxStdIf_InterfaceDriver stdif)
{
}
static boolean IfxStdIf_Timer_nopAckTimerIrq(IfxStdIf_InterfaceDriver stdif)
{
	return FALSE;
}
static boolean IfxStdIf_Timer_nopAckTriggerIrq(IfxStdIf_InterfaceDriver stdif)
{
	return FALSE;
}


void IfxStdIf_Timer_initStdIf(IfxStdIf_Timer *stdIf, IfxStdIf_InterfaceDriver driver)
{
    stdIf->driver               = driver;
    stdIf->getFrequency         =&IfxStdIf_Timer_nopGetFrequency        ;
    stdIf->getPeriod            =&IfxStdIf_Timer_nopGetPeriod           ;
    stdIf->getResolution        =&IfxStdIf_Timer_nopGetResolution       ;
    stdIf->getTrigger           =&IfxStdIf_Timer_nopGetTrigger          ;
    stdIf->setFrequency         =&IfxStdIf_Timer_nopSetFrequency        ;
    stdIf->updateInputFrequency =&IfxStdIf_Timer_nopUpdateInputFrequency;
    stdIf->applyUpdate          =&IfxStdIf_Timer_nopApplyUpdate         ;
    stdIf->disableUpdate        =&IfxStdIf_Timer_nopDisableUpdate       ;
    stdIf->getInputFrequency    =&IfxStdIf_Timer_nopGetInputFrequency   ;
    stdIf->run                  =&IfxStdIf_Timer_nopRun                 ;
    stdIf->setPeriod            =&IfxStdIf_Timer_nopSetPeriod           ;
    stdIf->setSingleMode        =&IfxStdIf_Timer_nopSetSingleMode       ;
    stdIf->setTrigger           =&IfxStdIf_Timer_nopSetTrigger          ;
    stdIf->stop                 =&IfxStdIf_Timer_nopStop                ;
    stdIf->ackTimerIrq          =&IfxStdIf_Timer_nopAckTimerIrq         ;
    stdIf->ackTriggerIrq        =&IfxStdIf_Timer_nopAckTriggerIrq       ;
}
