/**
 * \file IfxGtm_Tim.c
 * \brief GTM  basic functionality
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
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX)
#include "IfxGtm_Tim.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxGtm_Tim_Ch_getFilterClockFrequency(Ifx_GTM *gtm, Ifx_GTM_CLS_TIM_CH *channel)
{
	/* Tim Filter counter frequency select */
    IfxGtm_Cmu_Tim_Filter_Clk filterClock;
    IfxGtm_Cmu_Clk            clk;

    /* Gets the Filter clock source */
    filterClock = IfxGtm_Tim_Ch_getFilterClockSource(channel);

    switch (filterClock)
    {
    case IfxGtm_Cmu_Tim_Filter_Clk_0:
        clk = IfxGtm_Cmu_Clk_0;
        break;
    case IfxGtm_Cmu_Tim_Filter_Clk_1:
        clk = IfxGtm_Cmu_Clk_1;
        break;
    case IfxGtm_Cmu_Tim_Filter_Clk_6:
        clk = IfxGtm_Cmu_Clk_6;
        break;
    case IfxGtm_Cmu_Tim_Filter_Clk_7:
    default:
        /* This case never occurs */
        clk = IfxGtm_Cmu_Clk_7;
        break;
    }
    /* Gets the GTM configurable clock frequency in Hz*/
    return IfxGtm_Cmu_getClkFrequency(gtm, clk, TRUE);
}


void IfxGtm_Tim_Ch_setControl(Ifx_GTM_CLS_TIM_CH *channel, IfxGtm_Tim_ChannelControl control)
{
	/* Configures the TIM channel Control register */
    Ifx_GTM_CLS_TIM_CH_CTRL ctrl;
    /* Initializes the local control register with the current value from the channel */
    ctrl.U             = channel->CTRL.U;
    ctrl.B.TIM_EN      = control.enable;
    ctrl.B.TIM_MODE    = (uint8)control.mode;
    ctrl.B.OSM         = control.enableOneShotMode;
    ctrl.B.ARU_EN      = control.enableAruRouting;
    ctrl.B.CICTRL      = control.channelInputControl;
    ctrl.B.GPR0_SEL    = (uint8)control.gpr0Sel;
    ctrl.B.GPR1_SEL    = (uint8)control.gpr1Sel;
    ctrl.B.CNTS_SEL    = (uint8)control.cntsSel;
    ctrl.B.DSL         = control.signalLevelControl;
    ctrl.B.ISL         = control.ignoreSignalLevel;
    ctrl.B.ECNT_RESET  = control.enableCounterReset;
    ctrl.B.FLT_EN      = control.enableFilter;
    ctrl.B.FLT_CNT_FRQ = (uint8)control.filterCounterFrequency;
    ctrl.B.EXT_CAP_EN  = control.enableExternalCaptureMode;

    ctrl.B.FLT_MODE_RE = (uint8)control.filterModeRisingEdge;
    ctrl.B.FLT_CTR_RE  = (uint8)control.filterCounterModeRisingEdge;
    ctrl.B.FLT_MODE_FE = (uint8)control.filterModeFallingEdge;
    ctrl.B.FLT_CTR_FE  = (uint8)control.filterCounterModeFallingEdge;
    ctrl.B.CLK_SEL     = (uint8)control.clkSel;

    ctrl.B.FR_ECNT_OFL = control.extendEdgeCounterOverflow;
    ctrl.B.EGPR0_SEL   = control.egpr0Sel;
    ctrl.B.EGPR1_SEL   = control.egpr1Sel;
    ctrl.B.TOCTRL      = (uint8)control.timeoutControl;

    /* Updates the channel's control register with the modified local copy */
    channel->CTRL.U    = ctrl.U;
}

#endif /* #if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif

