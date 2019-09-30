/**
 * \file IfxGtm_Tim_In.c
 * \brief GTM IN details
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxGtm_Tim_In.h"
#include "IfxGtm_bf.h"
#include "string.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxGtm_Tim_In_init(IfxGtm_Tim_In *driver, const IfxGtm_Tim_In_Config *config)
{
    boolean             result = TRUE;
    Ifx_GTM_TIM_CH     *channel;

    IfxGtm_Tim_Ch       channelIndex;
    IfxGtm_Tim          timIndex;
    IfxGtm_Tim_In_Input input;

    driver->timIndex     = config->timIndex;
    driver->channelIndex = config->channelIndex;

    if (config->filter.inputPin != NULL_PTR)
    {
        channelIndex = config->filter.inputPin->channel;
        timIndex     = config->filter.inputPin->tim;

        input        = IfxGtm_Tim_In_Input_currentChannel; /* FIXME TIM can also use adjacent channel,
                                                            * but UM does not define it in the Implementation for PORT > check and raise issue*/
    }
    else
    {
        channelIndex = config->channelIndex;
        timIndex     = config->timIndex;
        input        = config->filter.input;
    }

    channel                  = IfxGtm_Tim_getChannel(&config->gtm->TIM[timIndex], channelIndex);
    driver->channel          = channel;
    driver->periodTick       = 0;
    driver->pulseLengthTick  = 0;
    driver->dataCoherent     = FALSE;
    driver->newData          = FALSE;
    driver->dataLost         = FALSE;
    driver->overflowCnt      = FALSE;
    driver->edgeCounterUpper = 0;

    channel->CTRL.B.TIM_MODE = IfxGtm_Tim_Mode_pwmMeasurement;

    IfxGtm_Tim_Ch_setClockSource(channel, config->capture.clock);

    driver->captureClockFrequency = IfxGtm_Tim_Ch_getCaptureClockFrequency(config->gtm, channel);

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, (config->capture.mode == Ifx_Pwm_Mode_leftAligned) || (config->capture.mode == Ifx_Pwm_Mode_rightAligned));

    result                  &= (config->capture.mode == Ifx_Pwm_Mode_leftAligned) || (config->capture.mode == Ifx_Pwm_Mode_rightAligned);
    channel->CTRL.B.DSL      = config->capture.mode == Ifx_Pwm_Mode_leftAligned ? 1 : 0;

    channel->CTRL.B.CNTS_SEL = IfxGtm_Tim_CntsSel_cntReg;
    channel->CTRL.B.GPR0_SEL = IfxGtm_Tim_GprSel_cnts; /* Use CNTS as input for GPR0 */
    channel->CTRL.B.GPR1_SEL = IfxGtm_Tim_GprSel_cnts; /* Use CNT as input for GPR1 */

    /* Interrupt configuration */
    if (config->isrPriority)
    {
        volatile Ifx_SRC_SRCR *src;
        IfxGtm_Tim_Ch_setNotificationMode(channel, config->irqMode);
        IfxGtm_Tim_Ch_setChannelNotification(channel, config->capture.irqOnNewVal,
            config->capture.irqOnCntOverflow, config->capture.irqOnEcntOverflow, config->capture.irqOnDatalost);

        src = IfxGtm_Tim_Ch_getSrcPointer(config->gtm, timIndex, channelIndex);
        IfxSrc_init(src, config->isrProvider, config->isrPriority);
        IfxSrc_enable(src);
    }

    /* Timeout configuration */
    if (config->timeout.timeout > 0)
    {
        float32 clockFrequency;
        sint32  timeout;
        channel->TDUV.B.TCS = config->timeout.clock;
        clockFrequency      = IfxGtm_Tim_Ch_getTimeoutClockFrequency(config->gtm, channel);

        timeout             = (uint32)(config->timeout.timeout * clockFrequency) - 1;

        if (timeout < 0)
        {
            timeout = 0;
        }
        else if (timeout >= (1 << IFX_GTM_TIM_CH_TDUV_TCS_MSK))
        {
            timeout = IFX_GTM_TIM_CH_TDUV_TCS_MSK;
            result  = FALSE;
        }

        channel->CTRL.B.TOCTRL = config->capture.mode == Ifx_Pwm_Mode_leftAligned ? IfxGtm_Tim_Timeout_risingEdge : IfxGtm_Tim_Timeout_fallingEdge;
        channel->TDUV.B.TOV    = timeout;

        IfxGtm_Tim_Ch_setTimeoutNotification(channel, config->timeout.irqOnTimeout);
    }

    /* Input configuration */

    config->gtm->TIM[timIndex].IN_SRC.U = 1 << (IFX_GTM_TIM_IN_SRC_MODE_0_OFF + channelIndex * (IFX_GTM_TIM_IN_SRC_MODE_1_OFF - IFX_GTM_TIM_IN_SRC_MODE_0_OFF)); // MODE 0

    switch (input)
    {
    case IfxGtm_Tim_In_Input_currentChannel:
        config->gtm->TIM[timIndex].IN_SRC.U = 1 << (IFX_GTM_TIM_IN_SRC_VAL_0_OFF + channelIndex * (IFX_GTM_TIM_IN_SRC_VAL_1_OFF - IFX_GTM_TIM_IN_SRC_VAL_0_OFF)); // VAL 0
        channel->CTRL.B.CICTRL              = IfxGtm_Tim_Input_currentChannel;
        break;
    case IfxGtm_Tim_In_Input_adjacentChannel:
        config->gtm->TIM[timIndex].IN_SRC.U = 1 << (IFX_GTM_TIM_IN_SRC_VAL_0_OFF + channelIndex * (IFX_GTM_TIM_IN_SRC_VAL_1_OFF - IFX_GTM_TIM_IN_SRC_VAL_0_OFF)); // VAL 0
        channel->CTRL.B.CICTRL              = IfxGtm_Tim_Input_adjacentChannel;
        break;
    case IfxGtm_Tim_In_Input_aux:
        config->gtm->TIM[timIndex].IN_SRC.U = 2 << (IFX_GTM_TIM_IN_SRC_VAL_0_OFF + channelIndex * (IFX_GTM_TIM_IN_SRC_VAL_1_OFF - IFX_GTM_TIM_IN_SRC_VAL_0_OFF)); // VAL 1
        break;
    }

    if (config->filter.inputPin != NULL_PTR)
    {
        IfxGtm_PinMap_setTimTin(config->filter.inputPin, config->filter.inputPinMode);
    }

    /*Filter configuration */
    if ((config->filter.fallingEdgeMode != IfxGtm_Tim_In_ConfigFilterMode_none)
        || (config->filter.risingEdgeMode != IfxGtm_Tim_In_ConfigFilterMode_none))
    {
        float32 clockFrequency;
        sint32  fallingfilterTime;
        sint32  risingfilterTime;

        channel->CTRL.B.FLT_EN      = 1;
        channel->CTRL.B.FLT_CNT_FRQ = config->filter.clock;

        clockFrequency              = IfxGtm_Tim_Ch_getFilterClockFrequency(config->gtm, channel);

        fallingfilterTime           = (uint32)(config->filter.fallingEdgeFilterTime * clockFrequency) - 1;

        if (fallingfilterTime < 0)
        {
            fallingfilterTime = 0;
        }
        else if (fallingfilterTime > IFX_GTM_TIM_CH_FLT_FE_FLT_FE_MSK)
        {
            fallingfilterTime = IFX_GTM_TIM_CH_FLT_FE_FLT_FE_MSK;
            result            = FALSE;
        }

        channel->FLT_FE.B.FLT_FE = fallingfilterTime;

        risingfilterTime         = (uint32)(config->filter.risingEdgeFilterTime * clockFrequency) - 1;

        if (risingfilterTime < 0)
        {
            risingfilterTime = 0;
        }
        else if (risingfilterTime > IFX_GTM_TIM_CH_FLT_FE_FLT_FE_MSK)
        {
            risingfilterTime = IFX_GTM_TIM_CH_FLT_FE_FLT_FE_MSK;
            result           = FALSE;
        }

        channel->FLT_RE.B.FLT_RE = risingfilterTime;

        if (config->filter.fallingEdgeMode != IfxGtm_Tim_In_ConfigFilterMode_none)
        {
            if (config->filter.fallingEdgeMode == IfxGtm_Tim_In_ConfigFilterMode_immediateEdgePropagation)
            {
                channel->CTRL.B.FLT_MODE_FE = IfxGtm_Tim_FilterMode_immediateEdgePropagation;
            }
            else
            {
                channel->CTRL.B.FLT_MODE_FE = IfxGtm_Tim_FilterMode_individualDeglitchTime;
                channel->CTRL.B.FLT_CTR_FE  = config->filter.fallingEdgeMode == IfxGtm_Tim_In_ConfigFilterMode_individualDeglitchTimeUpDown ? IfxGtm_Tim_FilterCounter_upDown : IfxGtm_Tim_FilterCounter_hold;
            }
        }
        else
        {
            channel->CTRL.B.FLT_MODE_FE = IfxGtm_Tim_FilterMode_immediateEdgePropagation;
            channel->FLT_FE.B.FLT_FE    = 0;
        }

        if (config->filter.risingEdgeMode != IfxGtm_Tim_In_ConfigFilterMode_none)
        {
            if (config->filter.risingEdgeMode == IfxGtm_Tim_In_ConfigFilterMode_immediateEdgePropagation)
            {
                channel->CTRL.B.FLT_MODE_RE = IfxGtm_Tim_FilterMode_immediateEdgePropagation;
            }
            else
            {
                channel->CTRL.B.FLT_MODE_RE = IfxGtm_Tim_FilterMode_individualDeglitchTime;
                channel->CTRL.B.FLT_CTR_RE  = config->filter.risingEdgeMode == IfxGtm_Tim_In_ConfigFilterMode_individualDeglitchTimeUpDown ? IfxGtm_Tim_FilterCounter_upDown : IfxGtm_Tim_FilterCounter_hold;
            }
        }
        else
        {
            channel->CTRL.B.FLT_MODE_RE = IfxGtm_Tim_FilterMode_immediateEdgePropagation;
            channel->FLT_RE.B.FLT_RE    = 0;
        }

        IfxGtm_Tim_Ch_setFilterNotification(channel, config->filter.irqOnGlitch);
    }

    /* Enable TIM channel */
    channel->CTRL.B.TIM_EN = 1;

    return result;
}


void IfxGtm_Tim_In_initConfig(IfxGtm_Tim_In_Config *config, Ifx_GTM *gtm)
{
    memset(config, 0, sizeof(IfxGtm_Tim_In_Config));

    config->gtm                          = gtm;
    config->timIndex                     = IfxGtm_Tim_0;
    config->channelIndex                 = IfxGtm_Tim_Ch_0;
    config->irqMode                      = IfxGtm_IrqMode_pulseNotify;
    config->isrProvider                  = IfxSrc_Tos_cpu0;
    config->isrPriority                  = 0;
    config->capture.irqOnNewVal          = FALSE;
    config->capture.irqOnCntOverflow     = FALSE;
    config->capture.irqOnEcntOverflow    = FALSE;
    config->capture.irqOnDatalost        = FALSE;
    config->capture.clock                = IfxGtm_Cmu_Clk_0;
    config->capture.mode                 = Ifx_Pwm_Mode_leftAligned;
    config->timeout.irqOnTimeout         = FALSE;
    config->timeout.clock                = IfxGtm_Cmu_Clk_0;
    config->timeout.timeout              = 0.0;
    config->filter.input                 = IfxGtm_Tim_In_Input_currentChannel;
    config->filter.inputPin              = NULL_PTR;
    config->filter.inputPinMode          = IfxPort_InputMode_noPullDevice;
    config->filter.risingEdgeMode        = IfxGtm_Tim_In_ConfigFilterMode_none;
    config->filter.fallingEdgeMode       = IfxGtm_Tim_In_ConfigFilterMode_none;
    config->filter.risingEdgeFilterTime  = 0;
    config->filter.fallingEdgeFilterTime = 0;
    config->filter.clock                 = IfxGtm_Cmu_Tim_Filter_Clk_0;
}


void IfxGtm_Tim_In_onIsr(IfxGtm_Tim_In *driver)
{
    IfxGtm_Tim_In_update(driver);
}


void IfxGtm_Tim_In_update(IfxGtm_Tim_In *driver)
{
    driver->dataLost = IfxGtm_Tim_Ch_isDataLostEvent(driver->channel);

    if (driver->dataLost)
    {
        IfxGtm_Tim_Ch_clearDataLostEvent(driver->channel);
    }

    driver->glitch = IfxGtm_Tim_Ch_isGlitchEvent(driver->channel);

    if (driver->glitch)
    {
        IfxGtm_Tim_Ch_clearGlitchEvent(driver->channel);
    }

    driver->newData = IfxGtm_Tim_Ch_isNewValueEvent(driver->channel);

    if (driver->newData)
    {
        Ifx_GTM_TIM_CH_GPR0 gpr0;
        Ifx_GTM_TIM_CH_GPR1 gpr1;

        gpr0.U                  = driver->channel->GPR0.U;
        gpr1.U                  = driver->channel->GPR1.U;
        driver->periodTick      = gpr1.B.GPR1;
        driver->pulseLengthTick = gpr0.B.GPR0;
        driver->dataCoherent    = gpr0.B.ECNT == gpr1.B.ECNT;

        // read the edge counter
        driver->edgeCount = driver->channel->ECNT.B.ECNT;

        if (IfxGtm_Tim_Ch_isEcntOverflowEvent(driver->channel))
        {
            driver->edgeCounterUpper++;
            IfxGtm_Tim_Ch_clearEcntOverflowEvent(driver->channel);
        }

        driver->overflowCnt = IfxGtm_Tim_Ch_isCntOverflowEvent(driver->channel);

        if (driver->overflowCnt)
        {
            driver->newData = FALSE;
            IfxGtm_Tim_Ch_clearCntOverflowEvent(driver->channel);
        }

        IfxGtm_Tim_Ch_clearNewValueEvent(driver->channel);
    }
}
