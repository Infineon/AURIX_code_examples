/**********************************************************************************************************************
 * \file Interrupt_Prio.c
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
#include "Interrupt_Prio.h"
#include "Bsp.h"
#include "IfxPort.h"
#include "IfxStm.h"
#include "pin.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define ISR_PRIORITY_STM_INT0        40                              /* Priority for interrupt ISR                   */
#define ISR_PRIORITY_STM_INT1        50                              /* Priority for interrupt ISR                   */
#define ISR_PRIORITY_STM_INT2        100                              /* Priority for interrupt ISR                   */
#define TIMER_INT_TIME_0             50                             /* Time between interrupts in ms                */
#define TIMER_INT_TIME_1             20                             /* Time between interrupts in ms                */
#define TIMER_INT_TIME_2             5                             /* Time between interrupts in ms                */
#define TIMER_INT_WAIT_TIME_0        30                             /* Time between interrupts in ms                */
#define TIMER_INT_WAIT_TIME_1        10                             /* Time between interrupts in ms                */
#define TIMER_INT_WAIT_TIME_2        2                             /* Time between interrupts in ms                */

#define LED1                       LED_1                           /* LED toggled in Interrupt Service Routine (ISR)   */
#define LED2                       LED_2                           /* LED toggled in Interrupt Service Routine (ISR)   */
#define STM_0                     &MODULE_CPU0                    /* CPU0 STM is used in this example                 */
#define STM_1                     &MODULE_CPU1                    /* CPU0 STM is used in this example                 */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IfxStm_CompareConfig g_Core0_STMConf;                                 /* STM configuration structure                      */
IfxStm_CompareConfig g_Core1_STMConf;                                 /* STM configuration structure                      */
Ifx_TickTime g_ticksFor50ms;                                   /* Variable to store the number of ticks to wait    */
Ifx_TickTime g_ticksFor30ms;                                   /* Variable to store the number of ticks to wait    */
Ifx_TickTime g_ticksFor20ms;                                   /* Variable to store the number of ticks to wait    */
Ifx_TickTime g_ticksFor10ms;                                   /* Variable to store the number of ticks to wait    */
Ifx_TickTime g_ticksFor5ms;                                   /* Variable to store the number of ticks to wait    */
Ifx_TickTime g_ticksFor2ms;                                   /* Variable to store the number of ticks to wait    */

volatile unsigned int isystemTrace = 0;
volatile unsigned int g_cpu0StmIsrCounter0;
volatile unsigned int g_cpu0StmIsrCounter1;
volatile unsigned int g_cpu1StmIsrCounter;
/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initLED(void);
void initSTM_Core0(void);
void initSTM_Core1(void);

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
IFX_INTERRUPT(isrSTM_Core0_50ms, 0, ISR_PRIORITY_STM_INT0);
IFX_INTERRUPT(isrSTM_Core0_20ms, 0, ISR_PRIORITY_STM_INT1);
IFX_INTERRUPT(isrSTM_Core1_5ms, 0, ISR_PRIORITY_STM_INT2);

void isrSTM_Core0_50ms(void)
{
    isystemTrace = 1;
    IfxCpu_enableInterrupts();
    /* Update the compare register value that will trigger the next interrupt and toggle the LED */
    IfxStm_increaseCompare(STM_0, IfxStm_Comparator_0, (uint32)g_ticksFor50ms);
    IfxPort_setPinState(LED1.port, LED1.pinIndex, IfxPort_State_toggled);
    g_cpu0StmIsrCounter0++;
    wait(g_ticksFor30ms);
    isystemTrace = 0;
}

void isrSTM_Core0_20ms(void)
{
    isystemTrace = 2;
    IfxCpu_enableInterrupts();
    /* Update the compare register value that will trigger the next interrupt and toggle the LED */
    IfxStm_increaseCompare(STM_0, IfxStm_Comparator_1, (uint32)g_ticksFor20ms);
    IfxPort_setPinState(LED2.port, LED2.pinIndex, IfxPort_State_toggled);
    g_cpu0StmIsrCounter1++;
    wait(g_ticksFor10ms);
    isystemTrace = 0;
}

void isrSTM_Core1_5ms(void)
{
    isystemTrace = 3;
    IfxCpu_enableInterrupts();
    /* Update the compare register value that will trigger the next interrupt and toggle the LED */
    IfxStm_increaseCompare(STM_1, IfxStm_Comparator_0,  (uint32)g_ticksFor5ms);
    g_cpu1StmIsrCounter++;
    wait(g_ticksFor2ms);
    isystemTrace =0;
}

/* Function to initialize the LED */
void initLED(void)
{
    IfxPort_setPinMode(LED1.port, LED1.pinIndex, IfxPort_Mode_outputPushPullGeneral);    /* Initialize LED port pin                      */
    IfxPort_setPinState(LED1.port, LED1.pinIndex, IfxPort_State_high);                   /* Turn off LED (LED is low-level active)       */
    IfxPort_setPinMode(LED2.port, LED2.pinIndex, IfxPort_Mode_outputPushPullGeneral);    /* Initialize LED port pin                      */
    IfxPort_setPinState(LED2.port, LED2.pinIndex, IfxPort_State_high);                   /* Turn off LED (LED is low-level active)       */
}

/* Function to initialize the STM */
void initSTM_Core0(void)
{
    IfxStm_initCompareConfig(&g_Core0_STMConf);                       /* Initialize the configuration structure with default values   */

    g_Core0_STMConf.triggerPriority = ISR_PRIORITY_STM_INT0;          /* Set the priority of the interrupt                            */
    g_Core0_STMConf.typeOfService = IfxSrc_Tos_cpu0;                  /* Set the service provider for the interrupts                  */
    g_Core0_STMConf.ticks = (uint32)g_ticksFor50ms;                  /* Set the number of ticks after which the timer triggers an
                                                                      * interrupt for the first time                                 */
    g_Core0_STMConf.comparator = IfxStm_Comparator_0;
    g_Core0_STMConf.comparatorInterrupt = IfxStm_ComparatorInterrupt_ir0;
    IfxStm_initCompare(STM_0, &g_Core0_STMConf);                      /* Initialize the STM with the user configuration               */

    g_Core0_STMConf.triggerPriority = ISR_PRIORITY_STM_INT1;          /* Set the priority of the interrupt                            */
    g_Core0_STMConf.typeOfService = IfxSrc_Tos_cpu0;                  /* Set the service provider for the interrupts                  */
    g_Core0_STMConf.ticks = (uint32)g_ticksFor20ms;                   /* Set the number of ticks after which the timer triggers an
                                                                       * interrupt for the first time                                 */
    g_Core0_STMConf.comparator = IfxStm_Comparator_1;
    g_Core0_STMConf.comparatorInterrupt = IfxStm_ComparatorInterrupt_ir1;

    IfxStm_initCompare(STM_0, &g_Core0_STMConf);                      /* Initialize the STM with the user configuration               */
}

void initSTM_Core1(void)
{
    IfxStm_initCompareConfig(&g_Core1_STMConf);                      /* Initialize the configuration structure with default values   */

    g_Core1_STMConf.triggerPriority = ISR_PRIORITY_STM_INT2;         /* Set the priority of the interrupt                            */
    g_Core1_STMConf.typeOfService = IfxSrc_Tos_cpu0;                 /* Set the service provider for the interrupts                  */
    g_Core1_STMConf.ticks = (uint32)g_ticksFor5ms;                   /* Set the number of ticks after which the timer triggers an interrupt for the first time*/
    g_Core1_STMConf.comparator = IfxStm_Comparator_0;
    g_Core1_STMConf.comparatorInterrupt = IfxStm_ComparatorInterrupt_ir0;

    IfxStm_initCompare(STM_1, &g_Core1_STMConf);                     /* Initialize the STM with the user configuration               */
}

/* Function to initialize all the peripherals and variables used */
void initPeripherals_core0(void)
{
    g_cpu0StmIsrCounter0 = 0;
    g_cpu0StmIsrCounter1 = 0;
    /* Initialize time constant */
    g_ticksFor30ms = IfxStm_getTicksFromMilliseconds(TIMER_INT_WAIT_TIME_0);
    g_ticksFor50ms = IfxStm_getTicksFromMilliseconds(TIMER_INT_TIME_0);
    g_ticksFor20ms = IfxStm_getTicksFromMilliseconds(TIMER_INT_TIME_1);
    g_ticksFor10ms = IfxStm_getTicksFromMilliseconds(TIMER_INT_WAIT_TIME_1);

    initLED();                                                      /* Initialize the port pin to which the LED is connected        */
    initSTM_Core0();                                                /* Configure the STM module                                     */
}

void initPeripherals_core1(void)
{
    g_cpu1StmIsrCounter = 0;
    /* Initialize time constant */
    g_ticksFor5ms = IfxStm_getTicksFromMilliseconds(TIMER_INT_TIME_2);
    g_ticksFor2ms = IfxStm_getTicksFromMilliseconds(TIMER_INT_WAIT_TIME_2);

    initSTM_Core1();                                                /* Configure the STM module                                     */
}
