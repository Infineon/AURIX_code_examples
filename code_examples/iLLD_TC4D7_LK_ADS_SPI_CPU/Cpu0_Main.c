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
 /*\title SPI communication via QSPI
 * \abstract A QSPI module configured as SPI master sends five bytes to another QSPI module which is configured as SPI slave.
 * \description QSPI0 is configured in master mode and used to send five bytes to QSPI2 configured in slave mode. The received data is read by the CPU and 
 *              compared against the transmitted data. Port pin P03.9, to which an LED is connected, indicates the successful transfer.
 *
 * \name iLLD_TC4D7_LK_ADS_SPI_CPU
 * \version V1.0.0
 * \board AURIX TC4D7 lite Kit, KIT_A3G_TC4D7_LITE, TC4D7XP_A-Step_CC_COM
 * \keywords AURIX, Communication, QSPI, Master, SPI, SPI_CPU_1, Slave
 * \documents See README.md
 * \lastUpdated 2025-05-14
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "Ifx_Cfg.h"
#include "IfxCpu.h"
#include "IfxWtu.h"
#include "SPI_CPU.h"


void core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxWtu_disableCpuWatchdog(IfxWtu_getCpuWatchdogPassword());
    IfxWtu_disableSystemWatchdog(IfxWtu_getSystemWatchdogPassword());

    /* Initialize the QSPI modules and the LED */
    initPeripherals();

    /* Start data transfer via QSPI */
    transferData();
    
    while (1)
    {
    }
}
