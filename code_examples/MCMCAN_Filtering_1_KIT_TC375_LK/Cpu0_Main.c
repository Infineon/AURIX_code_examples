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
 /*\title MCMCAN acceptance filtering
 * \abstract The initialization and configuration of several filter modes are used to illustrate different acceptance filtering options.
 * \description The CAN messages are sent from CAN node 0 to CAN node 1 using Loop-Back mode.
 *              Each transmitted CAN message contains a different message ID and based on the filter configuration,
 *              the message is either accepted or rejected by CAN node 1. Messages that passed acceptance filtering
 *              are stored in RX FIFOs 0 and 1 or dedicated RX buffer based on the filter configuration. Upon storing
 *              the messages, the interrupt service routine is called and the content of the received CAN message is
 *              read. Once the content of all the received messages is read, the received data is compared to the
 *              transmitted data. If all messages are received without any error detected, an LED is turned on to
 *              confirm successful message reception.
 *
 * \name MCMCAN_Filtering_1_KIT_TC375_LK
 * \version V1.0.0
 * \board AURIX TC375 lite Kit, KIT_A2G_TC375_LITE, TC37xTP_A-Step
 * \keywords CAN, MCMCAN, AURIX, INTERRUPT, LOOP-BACK, CAN FD, MCMCAN_Filtering_1, Filter
 * \documents https://www.infineon.com/aurix-expert-training/Infineon-AURIX_MCMCAN_Filtering_1_KIT_TC375_LK-TR-v01_00_00-EN.pdf
 * \documents https://www.infineon.com/aurix-expert-training/TC37A_iLLD_UM_1_0_1_12_1.chm
 * \lastUpdated 2021-03-22
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "MCMCAN_Filtering.h"

IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;

void core0_main(void)
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
    
    /* Application code: initialization of MCMCAN, LED, time, transmission and verification of the CAN messages */
    initMCMCAN();
    initLed();
    transmitCanMessage();
    verifyCanMessage();

    /* If there was no error, turn on the LED1 to indicate correctness of the received messages */
    if(g_status == CanCommunicationStatus_Success)
    {
        IfxPort_setPinLow(g_led1.port, g_led1.pinIndex);
    }

    /* If at this point the LED is not turned on, check "g_status" variable */
    while(1)
    {
    }
}