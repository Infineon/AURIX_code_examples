/**
 * \file IfxGpt12.c
 * \brief GPT12  basic functionality
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
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
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

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
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T2CON.B.T2I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else // FIXME:
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T3_getFrequency(Ifx_GPT12 *gpt12)
{
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

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
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T3CON.B.T3I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else // FIXME:
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T4_getFrequency(Ifx_GPT12 *gpt12)
{
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

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
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T4CON.B.T4I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else // FIXME:
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T5_getFrequency(Ifx_GPT12 *gpt12)
{
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt2BlockPrescaler  bps2 = (IfxGpt12_Gpt2BlockPrescaler)gpt12->T6CON.B.BPS2;

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
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T5CON.B.T5I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else // FIXME:
    {
        freq = freq / 2;
    }

    return freq;
}


float32 IfxGpt12_T6_getFrequency(Ifx_GPT12 *gpt12)
{
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    IfxGpt12_Gpt2BlockPrescaler  bps2 = (IfxGpt12_Gpt2BlockPrescaler)gpt12->T6CON.B.BPS2;

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
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T6CON.B.T6I;

    if ((mode == IfxGpt12_Mode_timer) || (mode == IfxGpt12_Mode_highGatedTimer) || (mode == IfxGpt12_Mode_lowGatedTimer))
    {
        freq = freq / (1 << prescaler);
    }
    else // FIXME:
    {
        freq = freq / 2;
    }

    return freq;
}


void IfxGpt12_disableModule(Ifx_GPT12 *gpt12)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(psw);
    gpt12->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxGpt12_enableModule(Ifx_GPT12 *gpt12)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(psw);
    gpt12->CLC.B.DISR = 0;
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

    IfxScuWdt_clearCpuEndinit(passwd);
    gpt12->KRST0.B.RST = 1;         /* Only if both Kernel reset bits are set a reset is executed */
    gpt12->KRST1.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    while (0 == gpt12->KRST0.B.RSTSTAT)     /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    gpt12->KRSTCLR.B.CLR = 1;           /* Clear Kernel reset status bit */
    IfxScuWdt_setCpuEndinit(passwd);
}
