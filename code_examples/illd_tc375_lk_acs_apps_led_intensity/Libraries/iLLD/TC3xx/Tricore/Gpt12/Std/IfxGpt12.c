/**
 * \file IfxGpt12.c
 * \brief GPT12  basic functionality
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxGpt12.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxGpt12_T2_getFrequency(Ifx_GPT12 *gpt12)
{
	/* Get the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Get the GPT1 block prescaler value from the T3CON register */
    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

    /* Calculate the frequency based on the block prescaler value */
    switch (bps1)
    {
    case IfxGpt12_Gpt1BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_8:
        freq = freq / 8;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_16:
        freq = freq / 16;
        break;
    default: /* case IfxGpt12_Gpt1BlockPrescaler_32: */
        freq = freq / 32;
        break;
    }

    mode      = IfxGpt12_T2_getMode(gpt12);
    /* Get the input prescaler value for Timer 2 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T2CON.B.T2I;

    /* Calculate the frequency based on the mode and prescaler */
    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T3_getFrequency(Ifx_GPT12 *gpt12)
{
	/* Get the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Get the GPT1 block prescaler value from the T3CON register */
    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

    /* Calculate the frequency based on the block prescaler value */
    switch (bps1)
    {
    case IfxGpt12_Gpt1BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_8:
        freq = freq / 8;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_16:
        freq = freq / 16;
        break;
    default: /* case IfxGpt12_Gpt1BlockPrescaler_32: */
        freq = freq / 32;
        break;
    }

    mode      = (IfxGpt12_Mode)gpt12->T3CON.B.T3M;
    /* Get the input prescaler value for Timer 3 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T3CON.B.T3I;

    /* Calculate the frequency based on the mode and prescaler */
    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T4_getFrequency(Ifx_GPT12 *gpt12)
{
	/* Get the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Get the GPT1 block prescaler value from the T3CON register */
    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

    /* Calculate the frequency based on the block prescaler value */
    switch (bps1)
    {
    case IfxGpt12_Gpt1BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_8:
        freq = freq / 8;
        break;
    case IfxGpt12_Gpt1BlockPrescaler_16:
        freq = freq / 16;
        break;
    default: /* case IfxGpt12_Gpt1BlockPrescaler_32: */
        freq = freq / 32;
        break;
    }

    mode      = (IfxGpt12_Mode)gpt12->T4CON.B.T4M;
    /* Get the input prescaler value for Timer 4 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T4CON.B.T4I;

    /* Calculate the frequency based on the mode and prescaler */
    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T5_getFrequency(Ifx_GPT12 *gpt12)
{
	/* Get the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Get the GPT2 block prescaler value from the T6CON register */
    IfxGpt12_Gpt2BlockPrescaler  bps2 = (IfxGpt12_Gpt2BlockPrescaler)gpt12->T6CON.B.BPS2;

    /* Calculate the frequency based on the block prescaler value */
    switch (bps2)
    {
    case IfxGpt12_Gpt2BlockPrescaler_2:
        freq = freq / 2;
        break;
    case IfxGpt12_Gpt2BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt2BlockPrescaler_8:
        freq = freq / 8;
        break;
    default: /* case IfxGpt12_Gpt2BlockPrescaler_16: */
        freq = freq / 16;
        break;
    }

    mode      = (IfxGpt12_Mode)gpt12->T5CON.B.T5M;
    /* Get the input prescaler value for Timer 5 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T5CON.B.T5I;

    /* Calculate the frequency based on the mode and prescaler */
    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T6_getFrequency(Ifx_GPT12 *gpt12)
{
	/* Get the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Get the GPT2 block prescaler value from the T6CON register */
    IfxGpt12_Gpt2BlockPrescaler  bps2 = (IfxGpt12_Gpt2BlockPrescaler)gpt12->T6CON.B.BPS2;

    /* Calculate the frequency based on the block prescaler value */
    switch (bps2)
    {
    case IfxGpt12_Gpt2BlockPrescaler_2:
        freq = freq / 2;
        break;
    case IfxGpt12_Gpt2BlockPrescaler_4:
        freq = freq / 4;
        break;
    case IfxGpt12_Gpt2BlockPrescaler_8:
        freq = freq / 8;
        break;
    default: /* case IfxGpt12_Gpt2BlockPrescaler_16: */
        freq = freq / 16;
        break;
    }

    mode      = (IfxGpt12_Mode)gpt12->T6CON.B.T6M;
    /* Get the input prescaler value for Timer 6 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T6CON.B.T6I;

    /* Calculate the frequency based on the mode and prescaler */
    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else
    {
        freq = freq / 2;
    }

    return freq;
}


void IfxGpt12_disableModule(Ifx_GPT12 *gpt12)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Disable the GPT12 module by setting the DISR (Disable Request) bit in the CLC register */
    gpt12->CLC.B.DISR = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxGpt12_enableModule(Ifx_GPT12 *gpt12)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Enable the GPT12 module by clearing the DISR (Disable Request) bit in the CLC register */
    gpt12->CLC.B.DISR = 0;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxGpt12_initTxEudInPin(const IfxGpt12_TxEud_In *txEudIn, IfxPort_InputMode inputMode)
{
    IfxPort_setPinModeInput(txEudIn->pin.port, txEudIn->pin.pinIndex, inputMode);

    switch (txEudIn->timer)
    {
    case 2:
        IfxGpt12_T2_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 3:
        IfxGpt12_T3_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 4:
        IfxGpt12_T4_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 5:
        IfxGpt12_T5_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 6:
        IfxGpt12_T6_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    default:
        break;
    }
}


void IfxGpt12_initTxEudInPinWithPadLevel(const IfxGpt12_TxEud_In *txEudIn, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeInput(txEudIn->pin.port, txEudIn->pin.pinIndex, inputMode);
    IfxPort_setPinPadDriver(txEudIn->pin.port, txEudIn->pin.pinIndex, padDriver);

    switch (txEudIn->timer)
    {
    case 2:
        IfxGpt12_T2_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 3:
        IfxGpt12_T3_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 4:
        IfxGpt12_T4_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 5:
        IfxGpt12_T5_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    case 6:
        IfxGpt12_T6_setEudInput(txEudIn->module, (IfxGpt12_EudInput)txEudIn->select);
        break;
    default:
        break;
    }
}


void IfxGpt12_initTxInPin(const IfxGpt12_TxIn_In *txIn, IfxPort_InputMode inputMode)
{
    IfxPort_setPinModeInput(txIn->pin.port, txIn->pin.pinIndex, inputMode);

    switch (txIn->timer)
    {
    case 2:
        IfxGpt12_T2_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 3:
        IfxGpt12_T3_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 4:
        IfxGpt12_T4_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 5:
        IfxGpt12_T5_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 6:
        IfxGpt12_T6_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    default:
        break;
    }
}


void IfxGpt12_initTxInPinWithPadLevel(const IfxGpt12_TxIn_In *txIn, IfxPort_InputMode inputMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeInput(txIn->pin.port, txIn->pin.pinIndex, inputMode);
    IfxPort_setPinPadDriver(txIn->pin.port, txIn->pin.pinIndex, padDriver);

    switch (txIn->timer)
    {
    case 2:
        IfxGpt12_T2_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 3:
        IfxGpt12_T3_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 4:
        IfxGpt12_T4_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 5:
        IfxGpt12_T5_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    case 6:
        IfxGpt12_T6_setInput(txIn->module, (IfxGpt12_Input)txIn->select);
        break;
    default:
        break;
    }
}


void IfxGpt12_resetModule(Ifx_GPT12 *gpt12)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    gpt12->KRST0.B.RST = 1;         /* Only if both Kernel reset bits are set a reset is executed */
    gpt12->KRST1.B.RST = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
    /* Wait until reset is executed */
    while (0 == gpt12->KRST0.B.RSTSTAT)

    {}
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Clear Kernel reset status bit */
    gpt12->KRSTCLR.B.CLR = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}
