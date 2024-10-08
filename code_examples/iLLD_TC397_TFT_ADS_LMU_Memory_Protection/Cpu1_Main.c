/**********************************************************************************************************************
 * \file Cpu1_Main.c
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

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "LMU_MPU_Test.h"
#include "SMU_IR_Alarm.h"

extern IfxCpu_syncEvent g_cpuSyncEvent;
extern volatile uint32 g_testIdentifier;

void core1_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG1 IS DISABLED HERE!!
     * Enable the watchdog and service it periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    
#if TEST_CORE_CONFIG == TEST_CORE_1
    /* Initialize the LEDs */
    Test_LED_init();
    SMU_configuration();
#endif

    while(1)
    {
#if TEST_CORE_CONFIG == TEST_CORE_1
        switch (g_testIdentifier)
        {
            case TEST_1:
                Test1_configuration();
                break;
            case TEST_2:
                Test2_configuration();
                break;
            case TEST_3:
                Test3_configuration();
                break;
            case TEST_4:
                Test4_configuration();
                break;
            case TEST_5:
                Test5_configuration();
                break;
            default:
                break;
        }
#endif

        /*---------Synch Configuration ---------*/
        IfxCpu_emitEvent(&g_cpuSyncEvent);
        IfxCpu_waitEvent(&g_cpuSyncEvent, WAIT_TIME * 2);

/*---------Test Execute ---------------*/
#if TEST_CORE_EXECUTE == TEST_CORE_1

        switch (g_testIdentifier)
        {
            case TEST_1:
                Test1_execute();
                break;
            case TEST_2:
                Test2_execute();
                break;
            case TEST_3:
                Test3_execute();
                break;
            case TEST_4:
                Test4_execute();
                break;
            case TEST_5:
                Test5_execute();
                break;
            default:
                break;
        }
#endif
        /*---------Synch Execute ---------*/
        IfxCpu_emitEvent(&g_cpuSyncEvent);
        IfxCpu_waitEvent(&g_cpuSyncEvent, WAIT_TIME * 2);
    }
}
