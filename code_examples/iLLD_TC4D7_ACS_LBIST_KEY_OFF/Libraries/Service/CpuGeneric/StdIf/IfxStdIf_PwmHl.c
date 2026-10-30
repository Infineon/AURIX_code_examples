/**
 * \file IfxStdIf_PwmHl.c
 * \brief Standard interface: Multi-channels, dual-complementary PWM interface
 * \ingroup IfxStdIf
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
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
