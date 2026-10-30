/**
 * \file IfxGtm_Tim.c
 * \brief GTM  basic functionality
 *
 * \version iLLD_1_22_0
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
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif
#if !defined(DEVICE_TC33XED) && !defined (DEVICE_TC35X)
#include "IfxGtm_Tim.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxGtm_Tim_Ch_getCaptureClockFrequency(Ifx_GTM *gtm, Ifx_GTM_TIM_CH *channel)
{
    IfxGtm_Cmu_Clk clock;

    /* Get capture clock source */
    clock = IfxGtm_Tim_Ch_getCaptureClockSource(channel);

    return IfxGtm_Cmu_getClkFrequency(gtm, clock, TRUE);
}


IfxGtm_Cmu_Clk IfxGtm_Tim_Ch_getCaptureClockSource(Ifx_GTM_TIM_CH *channel)
{
    return (IfxGtm_Cmu_Clk)channel->CTRL.B.CLK_SEL;
}


float32 IfxGtm_Tim_Ch_getFilterClockFrequency(Ifx_GTM *gtm, Ifx_GTM_TIM_CH *channel)
{
    IfxGtm_Cmu_Tim_Filter_Clk filterClock;
    IfxGtm_Cmu_Clk            clock;

    /* Get Filter clock source */
    filterClock = IfxGtm_Tim_Ch_getFilterClockSource(channel);

    switch (filterClock)
    {
    case IfxGtm_Cmu_Tim_Filter_Clk_0:
        clock = IfxGtm_Cmu_Clk_0;
        break;
    case IfxGtm_Cmu_Tim_Filter_Clk_1:
        clock = IfxGtm_Cmu_Clk_1;
        break;
    case IfxGtm_Cmu_Tim_Filter_Clk_6:
        clock = IfxGtm_Cmu_Clk_6;
        break;
    case IfxGtm_Cmu_Tim_Filter_Clk_7:
        clock = IfxGtm_Cmu_Clk_7;
        break;
    default:
    	/* This case never occurs */
        clock = IfxGtm_Cmu_Clk_0;
        break;
    }

    return IfxGtm_Cmu_getClkFrequency(gtm, clock, TRUE);
}


IfxGtm_Cmu_Tim_Filter_Clk IfxGtm_Tim_Ch_getFilterClockSource(Ifx_GTM_TIM_CH *channel)
{
    return (IfxGtm_Cmu_Tim_Filter_Clk)channel->CTRL.B.FLT_CNT_FRQ;
}


float32 IfxGtm_Tim_Ch_getTimeoutClockFrequency(Ifx_GTM *gtm, Ifx_GTM_TIM_CH *channel)
{
    IfxGtm_Cmu_Clk clock;

    /* Get the Timeout clock source */
    clock = IfxGtm_Tim_Ch_getTimeoutClockSource(channel);

    return IfxGtm_Cmu_getClkFrequency(gtm, clock, TRUE);
}


IfxGtm_Cmu_Clk IfxGtm_Tim_Ch_getTimeoutClockSource(Ifx_GTM_TIM_CH *channel)
{
	/* Return Timeout Clock selection */
    return (IfxGtm_Cmu_Clk)channel->TDUV.B.TCS;
}


void IfxGtm_Tim_Ch_setChannelNotification(Ifx_GTM_TIM_CH *channel, boolean irqOnNewVal, boolean irqOnCntOverflow, boolean irqOnEcntOverflow, boolean irqOnDatalost)
{
    Ifx_GTM_TIM_CH_IRQ_EN en;
    en.U                = channel->IRQ.EN.U;

    /* Update the interrupt enable for new value detection event */
    en.B.NEWVAL_IRQ_EN  = irqOnNewVal ? 1 : 0;
    /* Update the interrupt enable for counter overflow event */
    en.B.CNTOFL_IRQ_EN  = irqOnCntOverflow ? 1 : 0;
    /* Update the interrupt enable for event counter overflow event */
    en.B.ECNTOFL_IRQ_EN = irqOnEcntOverflow ? 1 : 0;
    /* Update the interrupt enable for data lost event*/
    en.B.GPROFL_IRQ_EN  = irqOnDatalost ? 1 : 0;
    channel->IRQ.EN.U   = en.U;
}


void IfxGtm_Tim_Ch_setClockSource(Ifx_GTM_TIM_CH *channel, IfxGtm_Cmu_Clk clock)
{
	/* Select CMU clock source for channel */
    channel->CTRL.B.CLK_SEL = clock;
}


void IfxGtm_Tim_Ch_setControl(Ifx_GTM_TIM_CH *channel, IfxGtm_Tim_ChannelControl control)
{
    Ifx_GTM_TIM_CH_CTRL ctrl;
    ctrl.U             = channel->CTRL.U;
    ctrl.B.TIM_EN      = control.enable;
    ctrl.B.TIM_MODE    = control.mode;
    ctrl.B.OSM         = control.enableOneShotMode;
    ctrl.B.ARU_EN      = control.enableAruRouting;
    ctrl.B.CICTRL      = control.channelInputControl;
    ctrl.B.TBU0_SEL    = control.tbu0Sel;
    ctrl.B.GPR0_SEL    = control.gpr0Sel;
    ctrl.B.GPR1_SEL    = control.gpr1Sel;
    ctrl.B.CNTS_SEL    = control.cntsSel;
    ctrl.B.DSL         = control.signalLevelControl;
    ctrl.B.ISL         = control.ignoreSignalLevel;
    ctrl.B.ECNT_RESET  = control.enableCounterReset;
    ctrl.B.FLT_EN      = control.enableFilter;
    ctrl.B.FLT_CNT_FRQ = control.filterCounterFrequency;
    ctrl.B.EXT_CAP_EN  = control.enableExternalCaptureMode;

    ctrl.B.FLT_MODE_RE = control.filterModeRisingEdge;
    ctrl.B.FLT_CTR_RE  = control.filterCounterModeRisingEdge;
    ctrl.B.FLT_MODE_FE = control.filterModeFallingEdge;
    ctrl.B.FLT_CTR_FE  = control.filterCounterModeFallingEdge;
    ctrl.B.CLK_SEL     = control.clkSel;

    ctrl.B.FR_ECNT_OFL = control.extendEdgeCounterOverflow;
    ctrl.B.EGPR0_SEL   = control.egpr0Sel;
    ctrl.B.EGPR1_SEL   = control.egpr1Sel;
    ctrl.B.TOCTRL      = control.timeoutControl;

    channel->CTRL.U    = ctrl.U;
}


void IfxGtm_Tim_Ch_setFilterNotification(Ifx_GTM_TIM_CH *channel, boolean irqOnGlitch)
{
    Ifx_GTM_TIM_CH_IRQ_EN en;
    en.U                  = channel->IRQ.EN.U;

    /* Update the interrupt enable for glitch detection */
    en.B.GLITCHDET_IRQ_EN = irqOnGlitch ? 1 : 0;

    channel->IRQ.EN.U     = en.U;
}


void IfxGtm_Tim_Ch_setNotificationMode(Ifx_GTM_TIM_CH *channel, IfxGtm_IrqMode mode)
{
    Ifx_GTM_TIM_CH_IRQ_EN en;
    en.U = channel->IRQ.EN.U;

    /* Disable all interrupts of the interrupt set to change mode */
    channel->IRQ.EN.U            = 0;
    channel->IRQ.MODE.B.IRQ_MODE = mode;
    /* Set the values back */
    channel->IRQ.EN.U            = en.U;
}


void IfxGtm_Tim_Ch_setTimeoutNotification(Ifx_GTM_TIM_CH *channel, boolean irqOnTimeout)
{
    Ifx_GTM_TIM_CH_IRQ_EN en;
    en.U              = channel->IRQ.EN.U;

    /* Update the interrupt enable for timeout */
    en.B.TODET_IRQ_EN = irqOnTimeout ? 1 : 0;

    channel->IRQ.EN.U = en.U;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
