/**
 * \file IfxGtm_Tbu.c
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

#include "IfxGtm_Tbu.h"
#include "IfxGtm_Cmu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxGtm_Tbu_getClockFrequency(Ifx_GTM *gtm, IfxGtm_Tbu_Ts channel)
{
    float32 result = 0.0F;

    if (channel == IfxGtm_Tbu_Ts_0)
    {
        result = IfxGtm_Cmu_getClkFrequency(gtm, (IfxGtm_Cmu_Clk)gtm->TBU.CH0_CTRL.B.CH_CLK_SRC, TRUE);
    }
    else if (channel == IfxGtm_Tbu_Ts_1)
    {
        result = IfxGtm_Cmu_getClkFrequency(gtm, (IfxGtm_Cmu_Clk)gtm->TBU.CH1_CTRL.B.CH_CLK_SRC, TRUE);
    }
    else if (channel == IfxGtm_Tbu_Ts_2)
    {
        result = IfxGtm_Cmu_getClkFrequency(gtm, (IfxGtm_Cmu_Clk)gtm->TBU.CH2_CTRL.B.CH_CLK_SRC, TRUE);
    }

    return result;
}
