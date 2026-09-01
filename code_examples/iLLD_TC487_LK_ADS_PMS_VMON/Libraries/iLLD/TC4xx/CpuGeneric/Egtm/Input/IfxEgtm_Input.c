/**
 * \file IfxEgtm_Input.c
 * \brief EGTM INPUT details
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508 /* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96 /* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC45X)
#include "IfxEgtm_Input.h"

/******************************************************************************/
/*-----------------------Private Function Prototypes--------------------------*/
/******************************************************************************/

/** \brief Select peripheral signal as input to TIM submodule
 *
 * \param[in] inputEntry    Unique entry for peripheral input to be connected
 *                          Range: 0 to 0xFFFFFFFF
 * \param[in] inputTablePtr Pointer to input table for peripheral to be connected
 *                          Range: 0 to 0xFFFFFFFF
 *
 * \retval TRUE on success. FALSE: Input cannot be connected to specified TIM channel in cluster
 */
IFX_STATIC boolean IfxEgtm_Input_selectPeripheralTimInput(uint32 inputEntry, uint32 *inputTablePtr);

/** \brief Select peripheral signal as input to DTMAUX
 *
 * \param[in] inputEntry    Unique entry for peripheral input to be connected
 *                          Range: 0 to 0xFFFFFFFF
 * \param[in] dtmAuxInput   Connect input signal to DTM_AUX_IN0 or DTM_AUX_IN1
 *                          Range: \ref: IfxEgtm_DtmAuxInput
 * \param[in] inputTablePtr Pointer to input table for peripheral to be connected
 *
 * \retval TRUE on success. FALSE: Input cannot be connected
 */
IFX_STATIC boolean IfxEgtm_Input_selectPeripheralDtmAuxInput(uint32 inputEntry, IfxEgtm_DtmAuxInput dtmAuxInput, uint32 *inputTablePtr);

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxEgtm_Input_selectAdcTimInput(IfxEgtm_AdcTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxEgtm_Input_selectPeripheralTimInput(inputEntry, &IfxEgtm_Cfg_AdcTimInputSel[0]);

    return result;
}


boolean IfxEgtm_Input_selectCanTimInput(IfxEgtm_CanTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxEgtm_Input_selectPeripheralTimInput(inputEntry, &IfxEgtm_Cfg_CanTimInputSel[0]);

    return result;
}


boolean IfxEgtm_Input_selectCanxlTimInput(IfxEgtm_CanxlTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxEgtm_Input_selectPeripheralTimInput(inputEntry, &IfxEgtm_Cfg_CanxlTimInputSel[0]);

    return result;
}


#if defined(IFXEGTM_CFG_NUM_GETH_TIM_INPUT_SIGNALS)
boolean IfxEgtm_Input_selectGethTimInput(IfxEgtm_GethTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxEgtm_Input_selectPeripheralTimInput(inputEntry, &IfxEgtm_Cfg_GethTimInputSel[0]);

    return result;
}
#endif /* #if defined(IFXEGTM_CFG_NUM_GETH_TIM_INPUT_SIGNALS) */


#if defined(IFXEGTM_CFG_NUM_GPT12_TIM_INPUT_SIGNALS)
boolean IfxEgtm_Input_selectGpt12TimInput(IfxEgtm_Gpt12TimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxEgtm_Input_selectPeripheralTimInput(inputEntry, &IfxEgtm_Cfg_Gpt12TimInputSel[0]);

    return result;
}
#endif /* #if defined(IFXEGTM_CFG_NUM_GPT12_TIM_INPUT_SIGNALS) */


boolean IfxEgtm_Input_selectLethTimInput(IfxEgtm_LethTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxEgtm_Input_selectPeripheralTimInput(inputEntry, &IfxEgtm_Cfg_LethTimInputSel[0]);

    return result;
}


boolean IfxEgtm_Input_selectErayTimInput(IfxEgtm_ErayTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxEgtm_Input_selectPeripheralTimInput(inputEntry, &IfxEgtm_Cfg_ErayTimInputSel[0]);

    return result;
}


boolean IfxEgtm_Input_selectPmsTimInput(IfxEgtm_PmsTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxEgtm_Input_selectPeripheralTimInput(inputEntry, &IfxEgtm_Cfg_PmsTimInputSel[0]);

    return result;
}


boolean IfxEgtm_Input_selectScuTimInput(IfxEgtm_ScuTimInput input, IfxEgtm_Tim cluster, IfxEgtm_Tim_Ch channel)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cluster, channel, input, 0u);

    result = IfxEgtm_Input_selectPeripheralTimInput(inputEntry, &IfxEgtm_Cfg_ScuTimInputSel[0]);

    return result;
}


boolean IfxEgtm_Input_selectAdcDtmAuxInput(IfxEgtm_AdcDtmAuxInput input, IfxEgtm_Cdtm cdtm, IfxEgtm_Dtm dtm, IfxEgtm_DtmAuxInput dtmAuxInput)
{
    boolean result;
    uint32  inputEntry = IFXEGTM_CFG_GETINPUTENTRY(cdtm, dtm, input, 0u);

    result = IfxEgtm_Input_selectPeripheralDtmAuxInput(inputEntry, dtmAuxInput, &IfxEgtm_Cfg_AdcDtmAuxInputSel[0]);

    return result;
}


IFX_STATIC boolean IfxEgtm_Input_selectPeripheralTimInput(uint32 inputEntry, uint32 *inputTablePtr)
{
    boolean result = FALSE;
    uint16  idx    = 0u;

    /* Loop through all table elements */
    for (idx = 1u; idx <= inputTablePtr[0]; idx++)
    {
        /* Check if combination is present in table */
        if ((inputTablePtr[idx] & 0xFFFFFF00u) == inputEntry)
        {
            result = TRUE;
            break;
        }
    }

    if (result == TRUE)
    {
        /* Extracts cluster, channel number, and chxsel values */
        uint32 cluster = (inputEntry >> 24u) & 0xFu;
        uint32 channel = (inputEntry >> 16u) & 0xFu;
        uint32 chxsel  = inputTablePtr[idx] & IFX_EGTM_TIMINSEL_CH0SEL_MSK;

        /* Calculate value and mask */
        uint32 shift = channel * IFX_EGTM_TIMINSEL_CH0SEL_LEN;
        uint32 value = chxsel << shift;
        uint32 mask  = (uint32)IFX_EGTM_TIMINSEL_CH0SEL_MSK << shift;

        /* Writes to register */
        Ifx__ldmst(&MODULE_EGTM.TIMINSEL[cluster].U, mask, value);
    }

    return result;
}


IFX_STATIC boolean IfxEgtm_Input_selectPeripheralDtmAuxInput(uint32 inputEntry, IfxEgtm_DtmAuxInput dtmAuxInput, uint32 *inputTablePtr)
{
    boolean result = FALSE;
    uint16  idx    = 0u;

    /* Loop through all table elements */
    for (idx = 1u; idx <= inputTablePtr[0]; idx++)
    {
        /* Checks if combination is present in table */
        if ((inputTablePtr[idx] & 0xFFFFFF00u) == inputEntry)
        {
            result = TRUE;
            break;
        }
    }

    if (result == TRUE)
    {
        /* Extracts CDTM, DTM number, and selx values */
        uint32 cdtm = (inputEntry >> 24u) & 0xFu;
        uint32 dtm  = (inputEntry >> 16u) & 0xFu;
        uint32 selx = inputTablePtr[idx] & IFX_EGTM_DTMAUX_IN_SEL0_MSK;

        /* Calculates value and mask */
        uint32 shift = dtm * (IFX_EGTM_DTMAUX_IN_SEL0_LEN + 1u);
        uint32 value = selx << shift;
        uint32 mask  = (uint32)IFX_EGTM_DTMAUX_IN_SEL0_MSK << shift;

        /* Writes to register */
        Ifx__ldmst(&MODULE_EGTM.DTMAUX[cdtm].IN[dtmAuxInput].U, mask, value);
    }

    return result;
}

#endif /* !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
