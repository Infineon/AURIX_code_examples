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
 /*\title iLLD_TC375_ADS_LVGL_Code_Example_1
 * \abstract This project is a simple example of how a Thin Film Transistor (TFT) Touch display in combination with the Light and Versatile Graphics Library library (LVGL) can be used in AURIX(TM) projects.
 * \description This project is a simple example of how a TFT Touch display in combination with the LVGL library can be used in AURIX(TM) projects.
 * \name iLLD_TC375_ADS_LVGL_Code_Example_1
 * \version V1.0.3
 * \board AURIX TC375 lite Kit, KIT_A2G_TC375_LITE, TC37xTP_A-Step
 * \keywords STM, AURIX, Interrupt, LVGL, TFT, Touch, Display, Screen, Button
 * \documents See README.md
 * \lastUpdated 2023-02-14
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"

#include "IfxPort.h"
#include "Bsp.h"
#include "STM_Interrupt.h"
#include "lvgl.h"
#include "Tft_lvgl_init.h"
#include "Tft_lvgl_example.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementation-----------------------------------------------*/
/*********************************************************************************************************************/
int core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    
    /* Wait 200 ms*/
    waitTime(20000000);

    /* Init STM */
    init_stm_timer();

    /* Configure - init LVGL */
    tft_lvgl_configure();

    /* Wait 200 ms*/
    waitTime(20000000);

    /* Create LVGL example content */
    tft_lvgl_create_example();


    while (1)
    {
        /* The LVGL library functions are periodically executed */
        if (check_stm_flag())
        {
            touch_periodic();
            lv_task_handler();
            reset_stm_flag();
        }
    }

    return (1);
}
