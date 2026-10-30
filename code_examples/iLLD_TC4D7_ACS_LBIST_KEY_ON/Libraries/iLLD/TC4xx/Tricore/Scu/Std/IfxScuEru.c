/**
 * \file IfxScuEru.c
 * \brief SCU  basic functionality
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

#include "IfxScuEru.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxScuEru_connectTrigger(IfxScuEru_InputChannel inputChannel, IfxScuEru_InputNodePointer triggerSelect)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SCU.PROTSE, IfxApProt_State_config);
#endif
    /* select appropriate EICRi register for the given input channel X ( i = 0 to 7 and X = 0 to 7 ) */

    MODULE_SCU.ERU.EICR[inputChannel].B.ONP = triggerSelect;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SCU.PROTSE, IfxApProt_State_run);
#endif
}


void IfxScuEru_enableFallingEdgeDetection(IfxScuEru_InputChannel inputChannel)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SCU.PROTSE, IfxApProt_State_config);
#endif
    /* select appropriate EICRi register for the given input channel X ( i = 0 to 7 and X = 0 to 7 ) */

    MODULE_SCU.ERU.EICR[inputChannel].B.FEN = TRUE;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SCU.PROTSE, IfxApProt_State_run);
#endif
}


void IfxScuEru_enableExternalInput(IfxScuEru_InputChannel inputChannel)
{
    Ifx_SCU_ERU_EICR eicr;
    eicr.U = MODULE_SCU.ERU.EICR[inputChannel].U;

    /* select appropriate EICRi register for the given input channel X ( i = 0 to 7 and X = 0 to 7 ) */
    eicr.B.EIEN   = TRUE;
    eicr.B.EIEN_P = TRUE;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SCU.PROTSE, IfxApProt_State_config);
#endif

    MODULE_SCU.ERU.EICR[inputChannel].U = eicr.U;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SCU.PROTSE, IfxApProt_State_run);
#endif
}
