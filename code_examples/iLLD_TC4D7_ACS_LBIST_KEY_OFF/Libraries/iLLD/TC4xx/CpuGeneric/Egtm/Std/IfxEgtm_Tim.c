/**
 * \file IfxEgtm_Tim.c
 * \brief EGTM  basic functionality
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
#include "IfxEgtm_Tim.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxEgtm_Tim_Ch_getFilterClockFrequency(Ifx_EGTM *egtm, Ifx_EGTM_CLS_TIM_CH *channel)
{
    IfxEgtm_Cmu_Tim_Filter_Clk filterClock;
    IfxEgtm_Cmu_Clk            clk;

    /* Gets the filter clock source for the timer channel */
    filterClock = IfxEgtm_Tim_Ch_getFilterClockSource(channel);

    switch (filterClock)
    {
    case IfxEgtm_Cmu_Tim_Filter_Clk_0:
    	/* Filters clock source 0 corresponds to CMU clock 0 */
        clk = IfxEgtm_Cmu_Clk_0;
        break;
    case IfxEgtm_Cmu_Tim_Filter_Clk_1:
    	/* Filtesr clock source 1 corresponds to CMU clock 1 */
        clk = IfxEgtm_Cmu_Clk_1;
        break;
    case IfxEgtm_Cmu_Tim_Filter_Clk_6:
    	/* Filters clock source 6 corresponds to CMU clock 6 */
        clk = IfxEgtm_Cmu_Clk_6;
        break;
    case IfxEgtm_Cmu_Tim_Filter_Clk_7:
    default:
    	/* Filters clock source 7 (or any other value) corresponds to CMU clock 7 */
        clk = IfxEgtm_Cmu_Clk_7;
        break;
    }

    /* Get the frequency of the mapped CMU clock */
    return IfxEgtm_Cmu_getClkFrequency(egtm, clk, TRUE);
}


void IfxEgtm_Tim_Ch_setControl(Ifx_EGTM_CLS_TIM_CH *channel, IfxEgtm_Tim_ChannelControl control)
{
    Ifx_EGTM_CLS_TIM_CH_CTRL ctrl;
    ctrl.U             = channel->CTRL.U;
    ctrl.B.TIM_EN      = control.enable;
    ctrl.B.TIM_MODE    = (uint8)control.mode;
    ctrl.B.OSM         = control.enableOneShotMode;
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

    /* Updates the control register with the new configuration */
    channel->CTRL.U    = ctrl.U;
}

#endif /* !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
