/**********************************************************************************************************************
 * \file STM_Interrupt.c
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
#include "STM_Interrupt.h"
#include "Bsp.h"
#include "IfxPort.h"
#include "IfxStm.h"
#include "pin.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define ISR_PRIORITY_STM        40                              /* Priority for interrupt ISR                       */
#define TIMER_INT_TIME          500                             /* Time between interrupts in ms                    */

#define LED                     LED_1                           /* LED toggled in Interrupt Service Routine (ISR)   */
#define STM                     &MODULE_CPU0                    /* CPU0 STM is used in this example                 */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IfxStm_CompareConfig g_STMConf;                                 /* STM configuration structure                      */
Ifx_TickTime g_ticksFor500ms;                                   /* Variable to store the number of ticks to wait    */

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initLED(void);
void initSTM(void);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Macro to define Interrupt Service Routine.
 * This macro makes following definitions:
 * 1) Define linker section as .intvec_tc<vector number>_<interrupt priority>.
 * 2) define compiler specific attribute for the interrupt functions.
 * 3) define the Interrupt service routine as ISR function.
 *
 * IFX_INTERRUPT(isr, vectabNum, priority)
 *  - isr: Name of the ISR function.
 *  - vectabNum: Vector table number.
 *  - priority: Interrupt priority. Refer Usage of Interrupt Macro for more details.
 */
IFX_INTERRUPT(isrSTM, 0, ISR_PRIORITY_STM);

void isrSTM(void)
{
    /* Update the compare register value that will trigger the next interrupt and toggle the LED */
    IfxStm_increaseCompare(STM, g_STMConf.comparator, (uint32)g_ticksFor500ms);
    IfxPort_setPinState(LED.port, LED.pinIndex, IfxPort_State_toggled);
}

/* Function to initialize the LED */
void initLED(void)
{
    IfxPort_setPinMode(LED.port, LED.pinIndex, IfxPort_Mode_outputPushPullGeneral);    /* Initialize LED port pin                      */
    IfxPort_setPinState(LED.port, LED.pinIndex, IfxPort_State_high);                   /* Turn off LED (LED is low-level active)       */
}

/* Function to initialize the STM */
void initSTM(void)
{
    IfxStm_initCompareConfig(&g_STMConf);           /* Initialize the configuration structure with default values   */

    g_STMConf.triggerPriority = ISR_PRIORITY_STM;   /* Set the priority of the interrupt                            */
    g_STMConf.typeOfService = IfxSrc_Tos_cpu0;      /* Set the service provider for the interrupts                  */
    g_STMConf.ticks = (uint32)g_ticksFor500ms;      /* Set the number of ticks after which the timer triggers an
                                                     * interrupt for the first time                                 */

    IfxStm_initCompare(STM, &g_STMConf);            /* Initialize the STM with the user configuration               */
}

/* Function to initialize all the peripherals and variables used */
void initPeripherals(void)
{
    /* Initialize time constant */
    g_ticksFor500ms = IfxStm_getTicksFromMilliseconds(TIMER_INT_TIME);

    initLED();                                      /* Initialize the port pin to which the LED is connected        */
    initSTM();                                      /* Configure the STM module                                     */
}
