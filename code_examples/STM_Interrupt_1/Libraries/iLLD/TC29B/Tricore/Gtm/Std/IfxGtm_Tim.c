/**
 * \file IfxGtm_Tim.c
 * \brief GTM  basic functionality
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

#include "IfxGtm_Tim.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxGtm_Tim_Ch_getCaptureClockFrequency(Ifx_GTM *gtm, Ifx_GTM_TIM_CH *channel)
{
    IfxGtm_Cmu_Clk clock;

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
        clock = IfxGtm_Cmu_Clk_0; // This case never occurs
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

    clock = IfxGtm_Tim_Ch_getTimeoutClockSource(channel);

    return IfxGtm_Cmu_getClkFrequency(gtm, clock, TRUE);
}


IfxGtm_Cmu_Clk IfxGtm_Tim_Ch_getTimeoutClockSource(Ifx_GTM_TIM_CH *channel)
{
    return (IfxGtm_Cmu_Clk)channel->TDUV.B.TCS;
}


void IfxGtm_Tim_Ch_setChannelNotification(Ifx_GTM_TIM_CH *channel, boolean irqOnNewVal, boolean irqOnCntOverflow, boolean irqOnEcntOverflow, boolean irqOnDatalost)
{
    Ifx_GTM_TIM_CH_IRQ_EN en;
    en.U                = channel->IRQ_EN.U;

    en.B.NEWVAL_IRQ_EN  = irqOnNewVal ? 1 : 0;
    en.B.CNTOFL_IRQ_EN  = irqOnCntOverflow ? 1 : 0;
    en.B.ECNTOFL_IRQ_EN = irqOnEcntOverflow ? 1 : 0;
    en.B.GPROFL_IRQ_EN  = irqOnDatalost ? 1 : 0;
    channel->IRQ_EN.U   = en.U;
}


void IfxGtm_Tim_Ch_setClockSource(Ifx_GTM_TIM_CH *channel, IfxGtm_Cmu_Clk clock)
{
    channel->CTRL.B.CLK_SEL = clock;
}


void IfxGtm_Tim_Ch_setFilterNotification(Ifx_GTM_TIM_CH *channel, boolean irqOnGlitch)
{
    Ifx_GTM_TIM_CH_IRQ_EN en;
    en.U                  = channel->IRQ_EN.U;

    en.B.GLITCHDET_IRQ_EN = irqOnGlitch ? 1 : 0;

    channel->IRQ_EN.U     = en.U;
}


void IfxGtm_Tim_Ch_setNotificationMode(Ifx_GTM_TIM_CH *channel, IfxGtm_IrqMode mode)
{
    Ifx_GTM_TIM_CH_IRQ_EN en;
    en.U = channel->IRQ_EN.U;

    /* Disable all interrupts of the interrupt set to change mode */
    channel->IRQ_EN.U            = 0;
    channel->IRQ_MODE.B.IRQ_MODE = mode;
    channel->IRQ_EN.U            = en.U; /* Set the values back */
}


void IfxGtm_Tim_Ch_setTimeoutNotification(Ifx_GTM_TIM_CH *channel, boolean irqOnTimeout)
{
    Ifx_GTM_TIM_CH_IRQ_EN en;
    en.U              = channel->IRQ_EN.U;

    en.B.TODET_IRQ_EN = irqOnTimeout ? 1 : 0;

    channel->IRQ_EN.U = en.U;
}
