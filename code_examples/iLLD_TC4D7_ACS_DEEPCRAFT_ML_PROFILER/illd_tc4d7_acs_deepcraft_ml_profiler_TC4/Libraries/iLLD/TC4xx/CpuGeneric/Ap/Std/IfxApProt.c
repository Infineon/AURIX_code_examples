/**
 * \file IfxApProt.c
 * \brief AP  basic functionality
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

#include "IfxApProt.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxApProt_Status IfxApProt_init(volatile Ifx_PROT_PROT *protReg, IfxApProt_ProtConfig *config)
{
    IfxApProt_Status status = IfxApProt_Status_success;
    Ifx_PROT_PROT    prot;

    /* TODO Owner check to be implemented */

    if (IfxApProt_getState(protReg) == IfxApProt_State_init)
    {
        prot.B.TAGID = config->protOwner.tagId;
        prot.B.PRSEN = config->protOwner.protectionSetEnable;
        prot.B.VMEN  = config->protOwner.vmEnable;

        if (config->protOwner.protectionSetEnable == 1U)
        {
            prot.B.PRS = config->protOwner.protectionSet;
        }

        if (config->protOwner.vmEnable == 1U)
        {
            prot.B.VM = config->protOwner.vmId;
        }

        prot.B.OWEN = 1U;

        prot.B.ODEF = config->protOwner.ownerDefined;

        if (config->protState != IfxApProt_State_config)
        {
            prot.B.SWEN  = 1U;
            prot.B.STATE = config->protState;
            protReg->U   = prot.U;
            status       = IfxApProt_Status_success;
        }
        else
        {
            status = IfxApProt_Status_inValidStateTransition;
        }
    }
    else
    {
        status = IfxApProt_Status_nonInitState;
    }

    return status;
}


void IfxApProt_initConfig(IfxApProt_ProtConfig *config)
{
    const IfxApProt_ProtConfig defaultConfig = {
        {
            .tagId               = IfxApProt_TagId_cpu0d,
            .ownerDefined        = FALSE,
            .protectionSet       = IfxApProt_PrsId_0,
            .protectionSetEnable = FALSE,
            .vmId                = IfxApProt_VmId_0,
            .vmEnable            = FALSE,
        },
        .protState = IfxApProt_State_init
    };

    *config = defaultConfig;
}


IfxApProt_Status IfxApProt_setState(volatile Ifx_PROT_PROT *protReg, IfxApProt_State state)
{
    IfxApProt_Status status       = IfxApProt_Status_success;
    IfxApProt_State  currentState = IfxApProt_getState(protReg);
    Ifx_PROT_PROT    prot;
    prot.U = protReg->U;

    /* TODO Owner check to be implemented */
    switch (currentState)
    {
    case IfxApProt_State_init:

        if (((state == IfxApProt_State_run) || (state == IfxApProt_State_runLock)) && !(protReg->B.ODEF))
        {
            status = IfxApProt_Status_initState;
        }
        else if ((state == IfxApProt_State_config) || (state == IfxApProt_State_configSec) || (state == IfxApProt_State_checkSec))
        {
            status = IfxApProt_Status_inValidStateTransition;
        }

        break;
    case IfxApProt_State_config:

        if (state != IfxApProt_State_run)
        {
            status = IfxApProt_Status_inValidStateTransition;
        }

        break;
    case IfxApProt_State_configSec:

        if (state != IfxApProt_State_checkSec)
        {
            status = IfxApProt_Status_inValidStateTransition;
        }

        break;
    case IfxApProt_State_checkSec:
        status = IfxApProt_Status_inValidStateTransition;
        break;
    case IfxApProt_State_run:

        if ((state != IfxApProt_State_config) && (state != IfxApProt_State_runLock))
        {
            status = IfxApProt_Status_inValidStateTransition;
        }

        break;
    case IfxApProt_State_runSec:

        if ((state != IfxApProt_State_configSec) && (state != IfxApProt_State_runLock))
        {
            status = IfxApProt_Status_inValidStateTransition;
        }

        break;
    case IfxApProt_State_runLock:
        status = IfxApProt_Status_inValidStateTransition;
        break;
    case IfxApProt_State_runLockAlias:
        status = IfxApProt_Status_inValidStateTransition;
        break;
    default:
        status = IfxApProt_Status_inValidStateTransition;
        break;
    }

    if (status != IfxApProt_Status_inValidStateTransition)
    {
        prot.B.SWEN  = 1U;
        prot.B.STATE = state;
        protReg->U   = prot.U;
        status       = IfxApProt_Status_success;
    }

    return status;
}


IfxApProt_Status IfxApProt_setOwner(volatile Ifx_PROT_PROT *protReg, IfxApProt_Owner *owner)
{
    IfxApProt_Status status = IfxApProt_Status_success;
    Ifx_PROT_PROT    prot;

    /* TODO Owner check to be implemented */

    prot.U       = protReg->U;
    prot.B.OWEN  = 1U;

    prot.B.TAGID = owner->tagId;
    prot.B.PRSEN = owner->protectionSetEnable;
    prot.B.VMEN  = owner->vmEnable;

    if (owner->protectionSetEnable == 1U)
    {
        prot.B.PRS = owner->protectionSet;
    }

    if (owner->vmEnable == 1U)
    {
        prot.B.VM = owner->vmId;
    }

    prot.B.ODEF = owner->ownerDefined;

    protReg->U  = prot.U;

    status      = IfxApProt_Status_success;

    return status;
}
