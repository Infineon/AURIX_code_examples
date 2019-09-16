/**
 * \file IfxStdIf_PwmHl.c
 * \brief Standard interface: Multi-channels, dual-complementary PWM interface
 * \ingroup IfxStdIf
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:24 GMT$
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

#include "IfxStdIf_PwmHl.h"

void IfxStdIf_PwmHl_initConfig(IfxStdIf_PwmHl_Config *config)
{
    config->deadtime         = 0;
    config->minPulse         = 0;
    config->channelCount     = 0;
    config->emergencyEnabled = FALSE;
    config->outputMode       = IfxPort_OutputMode_pushPull;
    config->outputDriver     = IfxPort_PadDriver_cmosAutomotiveSpeed1;
    config->ccxActiveState   = Ifx_ActiveState_high;
    config->coutxActiveState = Ifx_ActiveState_high;
}
