/**********************************************************************************************************************
 * \file EDSADC_FIFO.c
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
#include <EDSADC_FIFO.h>
#include "Ifx_Types.h"

#include "IfxEdsadc_reg.h"
#include "IfxConverter_reg.h"
#include "IfxStm_reg.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

/* DSADC FIFO stores up to 4 results. In this demo, the result interrupt occurs when FIFO has got 4 results */
/* This array keeps the recent 10 * 4 results collected in the recent 10 ISRs, similar to a circular buffer */
uint32 g_result[10][4];

/* Dummy read variable to force register write */
volatile uint32 dummy_read;

/* Loop variables for g_result reading */
uint8 g_ISR_index, g_FIFO_index;

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

IFX_INTERRUPT(resultISR, 0, 1);
/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

/* Function to initialize the CONVCTRL module to avoid potential cross talks from other EVADC or DSADC channels */
void init_CONVCTRL(void)
{
    /* Initialize CONVCTRL */
    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    /* Enable module CONVCTRL */
    CONVCTRL_CLC.B.DISR = 0;
    dummy_read = CONVCTRL_CLC.U;
    while(CONVCTRL_CLC.B.DISS == 1);

    /* Unlock converter control registers */
    CONVCTRL_CCCTRL.U = 0xB0000000;
    /* fADC=160MHz, fPHSYNC=160MHz/4=40MHz */
    CONVCTRL_PHSCFG.U = 0x00008003;
    /* Lock converter control registers */
    CONVCTRL_CCCTRL.U = 0;
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
}

/* Function to wait until specified us has elapsed */
void wait_micro_second(unsigned int ticks_in_us)
{
    /* fSTM = 100MHz by default */
    unsigned int stmCount = 100 * ticks_in_us;

    unsigned int   stmCountBegin = STM0_TIM0.U;

    while ((unsigned int)(STM0_TIM0.U - stmCountBegin) < stmCount)
    {
        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }

}

/* Function to wait until specified ns has elapsed */
void wait_nano_second(unsigned int ticks_in_ns)
{
    /* fSTM = 100MHz by default */
    if((ticks_in_ns % 10) != 0)
    {
        /* ticks_in_ns must be at least 10ns and integer multiple of 10ns */
        __debug();
    }

    unsigned int stmCount = ticks_in_ns / 10;

    unsigned int   stmCountBegin = STM0_TIM0.U;

    while ((unsigned int)(STM0_TIM0.U - stmCountBegin) < stmCount)
    {
        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }

}

/* Function to initialize DSADC and starts result generation */
void init_EDSADC_FIFO(void)
{
    /* Initialize EDSADC */
    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    EDSADC_CLC.B.DISR = 0;
    dummy_read = EDSADC_CLC.U;
    while(EDSADC_CLC.B.DISS == 1);
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    /* Set EDSADC0 to single ended mode */
    EDSADC_MODCFG0.U = 0x8000800C;

    /* DRM = 0, TSM = 0, FIFO enabled */
    EDSADC_DICFG0.U = 0x80000000;
    /* Calibration decimation rate = 512 */
    EDSADC_GAINCTR0.U = 0x061B1193;

    /* Operation decimation rate = 400 */
    EDSADC_FCFGC0.U = 0x018E018E;

    /* Corresponding setting for decimation rate 400 */
    EDSADC_GAINCORR0.U = 0x001A126E;

    /* Start modulator and demodulator */
    EDSADC_GLOBRC.U = 0x00010001;

    wait_micro_second(20);

    /* Deactivate FIR0/1, trigger calibration, disable result interrupt generation from DSADC side (SRGM = 0) */
    EDSADC_FCFGM0.U = 0x90008000;

    /* No result will be generated during calibration */

    /* Wait until calibration is successfully done */
    while(EDSADC_FCNTC0.B.CAL != 2);

    /* DSADC automatically starts generating results after successful calibration */
}

/* Interrupt Service Routine of the TMADC */
void resultISR(void)
{
    /* Only when none of RDERR or WRERR is set, result in FIFO is valid. See errata EDSADC_TC.H006 */
    if((EDSADC_RFC0.B.RDERR == 0) && (EDSADC_RFC0.B.WRERR == 0))
    {
        /* The first FIFO read after interrupt can be immediately done */
        g_result[g_ISR_index][g_FIFO_index] = EDSADC_RESM0.U;
        g_FIFO_index++;
        /* At least 8 fSPB clock must be inserted for each following read */
        /* fSPB is typically 100MHz, and 8 fSPB = 80ns */
        /* In case of DMA, each move typically takes longer than 80ns */
        /* User SHALL check in his configuration, if wait is still needed between each DMA move */

        wait_nano_second(100);
        g_result[g_ISR_index][g_FIFO_index] = EDSADC_RESM0.U;
        g_FIFO_index++;

        wait_nano_second(100);
        g_result[g_ISR_index][g_FIFO_index] = EDSADC_RESM0.U;
        g_FIFO_index++;

        wait_nano_second(100);
        g_result[g_ISR_index][g_FIFO_index] = EDSADC_RESM0.U;

        /* All 4 results in FIFO have been read */
        /* Update loop counter */
        if(g_ISR_index >= 9)
        {
            g_ISR_index = 0;
        }
        else
        {
            g_ISR_index++;
        }
        g_FIFO_index = 0;
    }
    else
    {
        /* User shall react on error */
        /*__debug();*/
    }
    /* EVFLAG will be automatically cleared after reading */
    return;

}
