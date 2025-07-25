/**********************************************************************************************************************
 * \file IfxClock_init.c
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

#include <Clock/IfxClock_init.h>

void IfxClock_switchTo40MHzClock(void)
{

   /* Reconfigure CCU to use 40MHz clock */
    IfxScuCcu_Config ccuConfig;
    IfxScuCcu_initConfig(&ccuConfig);

    ccuConfig.pllInitialStepConfig.pllsParameters.pllInputClockSelection = IfxScuCcu_PllInputClockSelection_fOsc0; /*fosc0=EXT_CLK*/
    ccuConfig.pllInitialStepConfig.pllsParameters.xtalFrequency = 40000000;
    ccuConfig.pllInitialStepConfig.pllsParameters.sysPllConfig = (IfxScuCcu_SysPllConfig) {1-1, 15-1, 2-1};            /*P, N, K2 */
    ccuConfig.pllInitialStepConfig.pllsParameters.perPllConfig = (IfxScuCcu_PerPllConfig) {1-1, 30-1, 4-1, 2-1, TRUE}; /*P, N, K2, K3, K3bypass*/


    ccuConfig.clockDistribution.ccucon1.mask  |=  (0x3F<<24);  /*mask CLKSELQSPI bitfield*/
    ccuConfig.clockDistribution.ccucon1.value &=~ (0x3F<<24);  /*clear value bitfield*/
    ccuConfig.clockDistribution.ccucon1.value |=  (0x11<<24);  /*CLKSELQSPI=1(fSOURCE1), QSPIDIV=1*/

    IfxScuCcu_init(&ccuConfig);

    IfxStm_waitTicks(&MODULE_STM0, 50000);
}
