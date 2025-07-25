/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
 /*\title EGTM PWM input capturing via TIM
 * \abstract A timer is used to capture an external PWM signal and calculate the PWM signal frequency and duty cycle.
 * \description The Timer Input Module (TIM) of the Enhanced Generic Timer Module (EGTM) is used in capture mode.
 *              The data from the captured PWM signal is used to calculate the PWM signal frequency and duty cycle in software.
 *              The frequency and the duty cycle are then stored in variables.
 *
 * \name iLLD_TC4D7_LK_ADS_EGTM_TIM_Capture
 * \version V1.0.0
 * \board AURIX TC4D7 lite Kit, KIT_A3G_TC4D7_LITE, TC4D7XP_A-Step_CC_COM
 * \keywords AURIX, EGTM, EGTM_TIM_Capture_1, Enhanced Generic Timer Module, PWM, TIM, capture, xEV
 * \documents See README.md
 * \lastUpdated 2025-05-16
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "Ifx_Cfg.h"
#include "IfxCpu.h"
#include "IfxWtu.h"
#include "EGTM_TIM_Capture.h"
#include "Bsp.h"
/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define WAIT_TIME   100         /* Number of milliseconds to wait                                                    */


void core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxWtu_disableCpuWatchdog(IfxWtu_getCpuWatchdogPassword());
    IfxWtu_disableSystemWatchdog(IfxWtu_getSystemWatchdogPassword());
    
    /* Initialize a time variable */
    Ifx_TickTime ticksFor100ms = IfxStm_getTicksFromMilliseconds(WAIT_TIME);

    initEgtmTim();                 /* Call the initialization function of the TIM                                    */
    initEgtmTomPwm();              /* Call the function which generates a PWM signal                                 */
    waitTime(ticksFor100ms);       /* Wait 100 ms                                                                    */

    while(1)
    {
        measurePwm();              /* Measure PWM signal frequency and duty cycle                                    */
    }
}
