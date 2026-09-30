/**
 * \file IfxGpt12.c
 * \brief GPT12  basic functionality
 *
 * \version iLLD-TC4-v2.6.0
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

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC4DX) && !defined(DEVICE_TC4ZX)
#include "IfxGpt12.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxGpt12_T2_getFrequency(Ifx_GPT12 *gpt12)
{
	/* Gets the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Gets the GPT1 block prescaler value from the T3CON register */
    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

    /* Calculates the frequency based on the block prescaler value */
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
    /* Gets the input prescaler value for Timer 2 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T2CON.B.T2I;

    /* Calculates the frequency based on the mode and prescaler */
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
	/* Gets the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Gets the GPT1 block prescaler value from the T3CON register */
    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

    /* Calculates the frequency based on the block prescaler value */
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
    /* Gets the input prescaler value for Timer 3 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T3CON.B.T3I;

    /* Calculates the frequency based on the mode and prescaler */
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
	/* Gets the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Gets the GPT1 block prescaler value from the T3CON register */
    IfxGpt12_Gpt1BlockPrescaler  bps1 = (IfxGpt12_Gpt1BlockPrescaler)gpt12->T3CON.B.BPS1;

    /* Calculates the frequency based on the block prescaler value */
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
    /* Gets the input prescaler value for Timer 4 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T4CON.B.T4I;

    /* Calculates the frequency based on the mode and prescaler */
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
	/* Gets the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Gets the GPT2 block prescaler value from the T6CON register */
    IfxGpt12_Gpt2BlockPrescaler  bps2 = (IfxGpt12_Gpt2BlockPrescaler)gpt12->T6CON.B.BPS2;

    /* Calculates the frequency based on the block prescaler value */
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
    /* Gets the input prescaler value for Timer 5 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T5CON.B.T5I;

    /* Calculates the frequency based on the mode and prescaler */
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
	/* Gets the module frequency of GPT12 */
    float32                      freq = IfxGpt12_getModuleFrequency(gpt12);

    IfxGpt12_Mode                mode;
    IfxGpt12_TimerInputPrescaler prescaler;

    /* Gets the GPT2 block prescaler value from the T6CON register */
    IfxGpt12_Gpt2BlockPrescaler  bps2 = (IfxGpt12_Gpt2BlockPrescaler)gpt12->T6CON.B.BPS2;

    /* Calculates the frequency based on the block prescaler value */
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
    /* Gets the input prescaler value for Timer 6 */
    prescaler = (IfxGpt12_TimerInputPrescaler)gpt12->T6CON.B.T6I;

    /* Calculates the frequency based on the mode and prescaler */
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
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_config);
#endif
    /* Disable the GPT12 module by setting the DISR (Disable Request) bit in the CLC register */
    gpt12->CLC.B.DISR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_run);
#endif
}


void IfxGpt12_enableModule(Ifx_GPT12 *gpt12)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_config);
#endif
    /* Enable the GPT12 module by setting the DISR (Disable Request) bit in the CLC register */
    gpt12->CLC.B.DISR = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_run);
#endif
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
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_config);
#endif
    /* Only if both Kernel reset bits are set a reset is executed */
    gpt12->RST.CTRLA.B.KRST = 1;
    gpt12->RST.CTRLB.B.KRST = 1;

    /* Waits until reset is executed */
    while (0 == gpt12->RST.STAT.B.KRST)
    {}

    /* Clears Kernel reset status bit */
    gpt12->RST.CTRLB.B.STATCLR = 1;

    /* Waits until KRST is cleared, only after this reset sequence is completed */
    while (gpt12->RST.STAT.B.KRST == 1)
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTE, IfxApProt_State_run);
#endif
}


IfxGpt12_Index IfxGpt12_getIndex(Ifx_GPT12 *gpt12)
{
    uint32         index;
    IfxGpt12_Index result;

    result = IfxGpt12_Index_none;

    for (index = 0; index < IFXGPT12_NUM_MODULES; index++)
    {
        if (IfxGpt12_cfg_indexMap[index].module == gpt12)
        {
            result = (IfxGpt12_Index)IfxGpt12_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


void IfxGpt12_initApConfig(IfxGpt12_ApConfig *config)
{
    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);
    IfxApApu_initConfig(&config->apuConfig);
}


void IfxGpt12_initAp(Ifx_GPT12 *gpt12, IfxGpt12_ApConfig *config)
{
    /* Initializes the PROTs */
    IfxApProt_init((Ifx_PROT_PROT *)&gpt12->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&gpt12->PROTSE, &config->protseConfig);

    /* Changes the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initializes the APU */
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTSE, IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&gpt12->ACCEN, &config->apuConfig);
    IfxApProt_setState((Ifx_PROT_PROT *)&gpt12->PROTSE, IfxApProt_State_run);
}


void IfxGpt12_configureAccessToGpt12s(IfxApApu_ApuConfig *apConfig)
{
    uint8 index;

    for (index = 0; index < IFXGPT12_NUM_MODULES; index++)
    {
        Ifx_GPT12 *gpt12 = (Ifx_GPT12 *)IfxGpt12_cfg_indexMap[index].module;
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&gpt12->ACCEN, (IfxApApu_ApuConfig *)apConfig);
    }
}

#endif /* #if !defined(DEVICE_TC4DX) && !defined(DEVICE_TC4ZX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
