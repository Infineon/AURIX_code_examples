/**
 * \file IfxEgtm_Tim_Timer.c
 * \brief EGTM TIMER details
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
#include "IfxEgtm_Tim_Timer.h"
#include "_Utilities/Ifx_Assert.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxEgtm_Tim_Timer_initChannel(IfxEgtm_Tim_Timer *driver, IfxEgtm_Tim_Timer_Config *config)
{
    driver->egtm     = &MODULE_EGTM;
    driver->clsIndex = config->clsIndex;
    driver->tim      = &driver->egtm->CLS[config->clsIndex].TIM;
    driver->channel  = config->channel;

    Ifx_EGTM_CLS_TIM_CH *channel = IfxEgtm_Tim_getChannel(driver->tim, driver->channel);

    /* Sets the TIM channel Control register */
    IfxEgtm_Tim_Ch_setControl(channel, config->channelControl);

    if (config->enableAuxInputSourceSelect == TRUE)
    {
    	/* Sets the Auxiliary input source */
        IfxEgtm_Tim_Ch_setAuxInputSourceSelection(driver->egtm, driver->clsIndex, driver->channel);
    }

    /* Sets the raising edge Filter Parameter */
    IfxEgtm_Tim_Ch_setRisingEdgeFilterTime(channel, config->raisingEdgeFilterTime);
    /* Set the Falling edge Filter Parameter */
    IfxEgtm_Tim_Ch_setFallingEdgeFilterTime(channel, config->fallingEdgeFilterTime);
    /* Sets the Input source */
    IfxEgtm_Tim_Ch_setInputSourceSelection(driver->tim, driver->channel, config->inputSourceSelect);

    if (config->irqEnable == TRUE)
    {
    	/* Sets the TIM channel IRQ mode */
        IfxEgtm_Tim_Ch_setNotificationMode(channel, config->irqMode);
        /* Sets the Interrupt Notification */
        IfxEgtm_Tim_Ch_setNotification(channel, config->irqType);
    }

    if ((config->channelControl.mode == IfxEgtm_Tim_Mode_inputPrescaler) || (config->channelControl.mode == IfxEgtm_Tim_Mode_bitCompression))
    {
        IfxEgtm_Tim_Ch_setShadowCounter(channel, config->shadowCounter);
    }
}


void IfxEgtm_Tim_Timer_initChannelConfig(IfxEgtm_Tim_Timer_Config *config, Ifx_EGTM *egtm)
{
    IFX_UNUSED_PARAMETER(egtm)
    const IfxEgtm_Tim_Timer_Config IfxEgtm_Tim_Timer_defaultChannelConfig = {
        .clsIndex       = IfxEgtm_Cluster_0,
        .channel        = IfxEgtm_Tim_Ch_0,
        .channelControl = {        //
            .enable                       = 1,
            .mode                         = IfxEgtm_Tim_Mode_pwmMeasurement,
            .enableOneShotMode            = 0,
            .channelInputControl          = 0,
            .gpr0Sel                      = IfxEgtm_Tim_GprSel_tbuTs0,
            .gpr1Sel                      = IfxEgtm_Tim_GprSel_tbuTs0,
            .cntsSel                      = IfxEgtm_Tim_CntsSel_cntReg,
            .signalLevelControl           = 0,
            .ignoreSignalLevel            = 0,
            .enableCounterReset           = 0,
            .enableFilter                 = 0,
            .filterCounterFrequency       = IfxEgtm_Tim_FilterCounterFreqSel_cmuClk0,
            .enableExternalCaptureMode    = 0,
            .filterModeRisingEdge         = IfxEgtm_Tim_FilterMode_immediateEdgePropagation,
            .filterCounterModeRisingEdge  = IfxEgtm_Tim_FilterCounter_upDown,
            .filterModeFallingEdge        = IfxEgtm_Tim_FilterMode_immediateEdgePropagation,
            .filterCounterModeFallingEdge = IfxEgtm_Tim_FilterCounter_upDown,
            .clkSel                       = IfxEgtm_Cmu_Clk_0,
            .extendEdgeCounterOverflow    = 0,
            .egpr0Sel                     = 0,
            .egpr1Sel                     = 0,
            .timeoutControl               = IfxEgtm_Tim_Timeout_disabled,
        },
        .raisingEdgeFilterTime = 0,
        .fallingEdgeFilterTime = 0,
        .shadowCounter         = 0,
        .irqEnable             = 0,
        .irqMode               = IfxEgtm_IrqMode_level,
        .irqType               = IfxEgtm_Tim_IrqType_newVal,
        .inputSourceSelect     = {
            .mode  = 0,
            .value = 0,
        },
        .enableAuxInputSourceSelect       = 0,
    };

    /* Default Configuration */
    *config = IfxEgtm_Tim_Timer_defaultChannelConfig;
}

#endif /* !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
