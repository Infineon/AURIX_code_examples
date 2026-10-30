/**
 * \file IfxGtm_Tim_Timer.c
 * \brief GTM TIMER details
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
#if !defined(DEVICE_TC33XED) && !defined(DEVICE_TC33X) && !defined (DEVICE_TC35X)
#include "IfxGtm_Tim_Timer.h"
#include "_Utilities/Ifx_Assert.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxGtm_Tim_Timer_initChannel(IfxGtm_Tim_Timer *driver, IfxGtm_Tim_Timer_Config *config)
{
    driver->gtm      = &MODULE_GTM;
    driver->timIndex = config->timIndex;

    driver->tim      = &driver->gtm->TIM[config->timIndex];
    driver->channel  = config->channel;

    Ifx_GTM_TIM_CH *channel = IfxGtm_Tim_getChannel(driver->tim, driver->channel);

    IfxGtm_Tim_Ch_setControl(channel, config->channelControl);

    if (config->enableAuxInputSourceSelect)
    {
        IfxGtm_Tim_Ch_setAuxInputSourceSelection(driver->gtm, driver->timIndex, driver->channel);
    }

    IfxGtm_Tim_Ch_setRisingEdgeFilterTime(channel, config->raisingEdgeFilterTime);
    IfxGtm_Tim_Ch_setFallingEdgeFilterTime(channel, config->fallingEdgeFilterTime);
    IfxGtm_Tim_Ch_setInputSourceSelection(driver->tim, driver->channel, config->inputSourceSelect);

    if (config->irqEnable)
    {
        IfxGtm_Tim_Ch_setNotificationMode(channel, config->irqMode);
        IfxGtm_Tim_Ch_setNotification(channel, config->irqType);
    }

    if ((config->channelControl.mode == IfxGtm_Tim_Mode_inputPrescaler) || (config->channelControl.mode == IfxGtm_Tim_Mode_bitCompression))
    {
        IfxGtm_Tim_Ch_setShadowCounter(channel, config->shadowCounter);
    }
}


void IfxGtm_Tim_Timer_initChannelConfig(IfxGtm_Tim_Timer_Config *config, Ifx_GTM *gtm)
{
    IFX_UNUSED_PARAMETER(gtm)
    const IfxGtm_Tim_Timer_Config IfxGtm_Tim_Timer_defaultChannelConfig = {
    	/* Default TIM instance used */
        .timIndex       = IfxGtm_Tim_0,
		/* Default TIM Channel used */
        .channel        = IfxGtm_Tim_Ch_0,
		/* Default values for Control configuration */
        .channelControl = {
            .enable                       = 1,
            .mode                         = IfxGtm_Tim_Mode_pwmMeasurement,
            .enableOneShotMode            = 0,
            .enableAruRouting             = 0,
            .channelInputControl          = 0,
			.tbu0Sel					  = 0,
            .gpr0Sel                      = IfxGtm_Tim_GprSel_tbuTs0,
            .gpr1Sel                      = IfxGtm_Tim_GprSel_tbuTs0,
            .cntsSel                      = IfxGtm_Tim_CntsSel_cntReg,
            .signalLevelControl           = 0,
            .ignoreSignalLevel            = 0,
            .enableCounterReset           = 0,
            .enableFilter                 = 0,
            .filterCounterFrequency       = IfxGtm_Tim_FilterCounterFreqSel_cmuClk0,
            .enableExternalCaptureMode    = 0,
            .filterModeRisingEdge         = IfxGtm_Tim_FilterMode_immediateEdgePropagation,
            .filterCounterModeRisingEdge  = IfxGtm_Tim_FilterCounter_upDown,
            .filterModeFallingEdge        = IfxGtm_Tim_FilterMode_immediateEdgePropagation,
            .filterCounterModeFallingEdge = IfxGtm_Tim_FilterCounter_upDown,
            .clkSel                       = IfxGtm_Cmu_Clk_0,
            .extendEdgeCounterOverflow    = 0,
            .egpr0Sel                     = 0,
            .egpr1Sel                     = 0,
            .timeoutControl               = IfxGtm_Tim_Timeout_disabled,
        },
		/* Default Filter Raising Edge time */
        .raisingEdgeFilterTime = 0,
		/* Default Falling Raising Edge time */
        .fallingEdgeFilterTime = 0,
		/* Default Shadow counter value */
        .shadowCounter         = 0,
		/* Default interrupt configuration */
        .irqEnable             = 0,
        .irqMode               = IfxGtm_IrqMode_level,
        .irqType               = IfxGtm_Tim_IrqType_newVal,
		/* Default input source selection */
        .inputSourceSelect     = {
            .mode  = 0,
            .value = 0,
        },
        .enableAuxInputSourceSelect       = 0,
    };

    *config = IfxGtm_Tim_Timer_defaultChannelConfig;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
