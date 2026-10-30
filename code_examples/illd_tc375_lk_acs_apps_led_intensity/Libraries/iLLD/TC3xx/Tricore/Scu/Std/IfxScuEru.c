/**
 * \file IfxScuEru.c
 * \brief SCU  basic functionality
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxScuEru.h"

/******************************************************************************/
/*----------------------------------Macros------------------------------------*/
/******************************************************************************/

#define IFXSCUERU_CHANNEL_NUMBER_ODD 1

#define IFXSCUERU_TO_REGISTER_BASE   1

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxScuEru_clearAllEventFlags(void)
{
    uint32 mask = (0xFF << 16);
    MODULE_SCU.FMR.U = mask;
}


void IfxScuEru_clearEventFlag(IfxScuEru_InputChannel inputChannel)
{
    uint32 mask = 1 << (inputChannel + 16);
    SCU_FMR.U = mask;
}


void IfxScuEru_clearInputChannelConfiguration(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    uint32 mask     = 0xFFFF;
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)    /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].U = (MODULE_SCU.EICR[index].U & mask);
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        mask                     = (mask << 16);
        MODULE_SCU.EICR[index].U = (MODULE_SCU.EICR[index].U & mask);
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_clearOutputChannelConfiguration(IfxScuEru_OutputChannel outputChannel)
{
    /* Select appropriate IGCRj register for the given output channel Y ( j = 0,1,2,3 and Y = 0 to 7 ) */
    uint32 index    = (outputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    uint32 mask     = 0xFFFF;
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (outputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)    /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.IGCR[index].U = (MODULE_SCU.IGCR[index].U & mask);
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        mask                     = (mask << 16);
        MODULE_SCU.IGCR[index].U = (MODULE_SCU.IGCR[index].U & mask);
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_connectTrigger(IfxScuEru_InputChannel inputChannel, IfxScuEru_InputNodePointer triggerSelect)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)     /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.INP1 = triggerSelect;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.INP0 = triggerSelect;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_disableAutoClear(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)     /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.LDEN1 = FALSE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.LDEN0 = FALSE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_disableFallingEdgeDetection(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)     /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.FEN1 = FALSE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.FEN0 = FALSE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_disablePatternDetectionTrigger(IfxScuEru_OutputChannel outputChannel)
{
    /* Select appropriate IGCRj register for the given output channel Y ( j = 0,1,2,3 and Y = 0 to 7 ) */
    uint32 index    = (outputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (outputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)    /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.IGCR[index].B.GEEN1 = FALSE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.IGCR[index].B.GEEN0 = FALSE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_disableRisingEdgeDetection(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)     /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.REN1 = FALSE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.REN0 = FALSE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_disableTriggerPulse(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)     /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.EIEN1 = FALSE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.EIEN0 = FALSE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_enableAutoClear(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)     /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.LDEN1 = TRUE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.LDEN0 = TRUE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_enableFallingEdgeDetection(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)     /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.FEN1 = TRUE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.FEN0 = TRUE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_enablePatternDetectionTrigger(IfxScuEru_OutputChannel outputChannel)
{
    /* Select appropriate IGCRj register for the given output channel Y ( j = 0,1,2,3 and Y = 0 to 7 ) */
    uint32 index    = (outputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (outputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)    /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.IGCR[index].B.GEEN1 = TRUE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.IGCR[index].B.GEEN0 = TRUE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_enableRisingEdgeDetection(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)     /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.REN1 = TRUE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.REN0 = TRUE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_enableTriggerPulse(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)     /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.EIEN1 = TRUE;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.EIEN0 = TRUE;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


uint32 IfxScuEru_getAllEventFlagsStatus(void)
{
    return MODULE_SCU.EIFR.U;
}


boolean IfxScuEru_getEventFlagStatus(IfxScuEru_InputChannel inputChannel)
{
    uint32 mask = (1U << inputChannel);
    return (MODULE_SCU.EIFR.U & mask) ? TRUE : FALSE;
}


uint32 IfxScuEru_getInputChannelConfiguration(IfxScuEru_InputChannel inputChannel)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    uint32 status, mask = 0xFFFF;

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)    /* for channels 1, 3 ,5 and 7 */
    {
        mask   = (mask << 16);
        status = (MODULE_SCU.EICR[index].U & mask);
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        status = (MODULE_SCU.EICR[index].U & mask);
    }

    return status;
}


uint32 IfxScuEru_getOutputChannelConfiguration(IfxScuEru_OutputChannel outputChannel)
{
    /* Select appropriate IGCRj register for the given output channel Y ( j = 0,1,2,3 and Y = 0 to 7 ) */
    uint32 index = (outputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    uint32 status, mask = 0xFFFF;

    if (outputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)    /* for channels 1, 3 ,5 and 7 */
    {
        mask   = (mask << 16);
        status = (MODULE_SCU.IGCR[index].U & mask);
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        status = (MODULE_SCU.IGCR[index].U & mask);
    }

    return status;
}


boolean IfxScuEru_getPatternDetectionResult(IfxScuEru_OutputChannel outputChannel)
{
    uint32 mask = (1U << outputChannel);
    return (MODULE_SCU.PDRR.U & mask) ? TRUE : FALSE;
}


uint32 IfxScuEru_getWholePatternDetectionResult(void)
{
    return MODULE_SCU.PDRR.U;
}


void IfxScuEru_selectExternalInput(IfxScuEru_InputChannel inputChannel, IfxScuEru_ExternalInputSelection inputSignal)
{
    /* Select appropriate EICRi register for the given input channel X ( i = 0,1,2,3 and X = 0 to 7 ) */
    uint32 index    = (inputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (inputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)    /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.EICR[index].B.EXIS1 = inputSignal;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.EICR[index].B.EXIS0 = inputSignal;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_setEventFlag(IfxScuEru_InputChannel inputChannel)
{
    uint32 mask = 1 << inputChannel;
    SCU_FMR.U = mask;
}


void IfxScuEru_setFlagPatternDetection(IfxScuEru_OutputChannel outputChannel, IfxScuEru_InputChannel inputChannel, boolean state)
{
    uint32 shift, mask;
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (outputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD) /* for channels 1, 3 ,5 and 7 */
    {
        shift = (inputChannel + 16);                  /* offset at location IPEN10 */
        mask  = (1 << shift);
        /* Select appropriate IGCRj register for the given output channel Y ( j = 0,1,2,3 and Y = 0 to 7 ) */
        uint32 index = (outputChannel >> IFXSCUERU_TO_REGISTER_BASE);
        MODULE_SCU.IGCR[index].U = (MODULE_SCU.IGCR[index].U & ~mask) | ((uint32)state << shift);
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        shift = inputChannel;
        mask  = (1 << shift);
        /* Select appropriate IGCRj register for the given output channel Y ( j = 0,1,2,3 and Y = 0 to 7 ) */
        uint32 index = (outputChannel >> IFXSCUERU_TO_REGISTER_BASE);
        MODULE_SCU.IGCR[index].U = (MODULE_SCU.IGCR[index].U & ~mask) | ((uint32)state << shift);
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}


void IfxScuEru_setInterruptGatingPattern(IfxScuEru_OutputChannel outputChannel, IfxScuEru_InterruptGatingPattern gatingPattern)
{
    /* Select appropriate IGCRj register for the given output channel Y ( j = 0,1,2,3 and Y = 0 to 7 ) */
    uint32 index    = (outputChannel >> IFXSCUERU_TO_REGISTER_BASE);
    /* Clear endinit protection */
    uint16 password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    if (outputChannel & IFXSCUERU_CHANNEL_NUMBER_ODD)    /* for channels 1, 3 ,5 and 7 */
    {
        MODULE_SCU.IGCR[index].B.IGP1 = gatingPattern;
    }
    else    /* for channels 0, 2, 4 and 6 */
    {
        MODULE_SCU.IGCR[index].B.IGP0 = gatingPattern;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(password);
}
