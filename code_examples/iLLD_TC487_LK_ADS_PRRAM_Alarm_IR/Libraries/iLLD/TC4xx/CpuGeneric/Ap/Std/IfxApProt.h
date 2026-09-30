/**
 * \file IfxApProt.h
 * \brief AP basic functionality
 * \ingroup IfxLld_Ap
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
 * \defgroup IfxLld_Ap_Std_Prot Prot Basic Functionality
 * \ingroup IfxLld_Ap_Std
 * \defgroup IfxLld_Ap_Std_Prot_Default Enumerations
 * \ingroup IfxLld_Ap_Std_Prot
 * \defgroup IfxLld_Ap_Std_Prot_Default Functions
 * \ingroup IfxLld_Ap_Std_Prot
 * \defgroup IfxLld_Ap_Std_Prot_Default Structure
 * \ingroup IfxLld_Ap_Std_Prot
 */

#ifndef IFXAPPROT_H
#define IFXAPPROT_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxAp_cfg.h"
#include "IfxProt_bf.h"
#include "IfxProt_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXAPPROT_SEL_OFFSET (8U)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ap_Std_Prot_Default
 * \{ */
/** \brief PRS ( Protection set definition ) of the owner
 */
typedef enum
{
    IfxApProt_PrsId_0 = 0,
    IfxApProt_PrsId_1,
    IfxApProt_PrsId_2,
    IfxApProt_PrsId_3,
    IfxApProt_PrsId_4,
    IfxApProt_PrsId_5,
    IfxApProt_PrsId_6,
    IfxApProt_PrsId_7
} IfxApProt_PrsId;

/** \brief PROT state definition
 */
typedef enum
{
    IfxApProt_State_init = 0,
    IfxApProt_State_config,
    IfxApProt_State_configSec,
    IfxApProt_State_checkSec,
    IfxApProt_State_run,
    IfxApProt_State_runSec,
    IfxApProt_State_runLock,
    IfxApProt_State_runLockAlias
} IfxApProt_State;

/** \brief PROT status definitions
 */
typedef enum
{
    IfxApProt_Status_success = 0,
    IfxApProt_Status_inValidStateTransition,
    IfxApProt_Status_nonInitState,
    IfxApProt_Status_initState,
    IfxApProt_Status_notOwner
} IfxApProt_Status;

/** \brief PROT Virtual Machine Id definition
 */
typedef enum
{
    IfxApProt_VmId_0 = 0,
    IfxApProt_VmId_1,
    IfxApProt_VmId_2,
    IfxApProt_VmId_3,
    IfxApProt_VmId_4,
    IfxApProt_VmId_5,
    IfxApProt_VmId_6,
    IfxApProt_VmId_7
} IfxApProt_VmId;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Ap_Std_Prot_Default
 * \{ */
/** \brief Configuration data structure of the owner
 */
typedef struct
{
    IfxApProt_TagId tagId;
    IfxApProt_VmId  vmId;
    IfxApProt_PrsId protectionSet;
    unsigned char   protectionSetEnable;
    unsigned char   ownerDefined;
    unsigned char   vmEnable;
} IfxApProt_Owner;

/** \} */

/** \addtogroup IfxLld_Ap_Std_Prot_Default
 * \{ */
/** \brief Configuration data structure of the PROT
 */
typedef struct
{
    IfxApProt_Owner protOwner;
    IfxApProt_State protState;
} IfxApProt_ProtConfig;

/** \} */

/** \addtogroup IfxLld_Ap_Std_Prot_Default
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the current state of the respective PROT module
 * \param protReg pointer to the PROT register
 * \return the state of the respective PROT
 */
IFX_INLINE IfxApProt_State IfxApProt_getState(volatile Ifx_PROT_PROT *protReg);

/** \brief Returns the current owner of the respective PROT module
 * \param protReg pointer to the PROT register
 * \param owner Configuration structure of owner
 * \return None
 */
IFX_INLINE void IfxApProt_getOwner(volatile Ifx_PROT_PROT *protReg, IfxApProt_Owner *owner);

/** \brief Configures the set of region protected registers to be written from shadow set
 * \param protReg pointer to the PROT register
 * \param selVal which set of registers should be written
 * \return None
 */
IFX_INLINE void IfxApProt_setProtectionRegionSelect(volatile Ifx_PROT_PROT *protReg, unsigned char selVal);

/** \brief Transitions the state without any valid state checks
 * \param protReg pointer to the PROT register
 * \param state the state to be transitioned into for the respective PROT
 * \return None
 */
IFX_INLINE void IfxApProt_transitionState(volatile Ifx_PROT_PROT *protReg, IfxApProt_State state);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initializes the Owner for the corresponding PROT and transitions the state to RUN or RUNLOCK
 * This API will return status as not owner in case the wrong owner is trying to modify the state
 * This API will return status as invalid Transition in case it is not a valid transition
 * This API will return status as success in case it was successful
 * \param protReg pointer to the PROT register
 * \param config config pointer to the default Prot configuration structure. This includes the owner details and the state to be transitioned into
 * \return the status of the PROT initialization
 */
IFX_EXTERN IfxApProt_Status IfxApProt_init(volatile Ifx_PROT_PROT *protReg, IfxApProt_ProtConfig *config);

/** \brief Initializes the default configuration for the PROT
 * \param config config pointer to the default Prot configuration structure. This includes the owner details and the state to be transitioned into
 * \return None
 */
IFX_EXTERN void IfxApProt_initConfig(IfxApProt_ProtConfig *config);

/** \brief Configure the state for the corresponding PROT. If the PROT is in Init state, then this API will return the status as init without doing any state transition.
 * This API will return status as not owner in case the wrong owner is trying to modify the state
 * This API will return status as invalid Transition in case it is not a valid transition
 * This API will return status as success in case it was successful
 * \param protReg pointer to the PROT register
 * \param state the state to be transitioned into for the respective PROT
 * \return The status of the PROT set state API
 */
IFX_EXTERN IfxApProt_Status IfxApProt_setState(volatile Ifx_PROT_PROT *protReg, IfxApProt_State state);

/** \brief Configure the owner for the corresponding PROT. This API will not transition the state of the PROT
 * This API will return status as not owner in case the wrong owner is trying to modify the state
 * This API will return status as success in case it was successful
 * \param protReg pointer to the PROT register
 * \param owner pointer to the owner to be configured for the respective PROT
 * \return The status of the PROT set state API
 */
IFX_EXTERN IfxApProt_Status IfxApProt_setOwner(volatile Ifx_PROT_PROT *protReg, IfxApProt_Owner *owner);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE IfxApProt_State IfxApProt_getState(volatile Ifx_PROT_PROT *protReg)
{
    return (IfxApProt_State)(protReg->B.STATE);
}


IFX_INLINE void IfxApProt_getOwner(volatile Ifx_PROT_PROT *protReg, IfxApProt_Owner *owner)
{
    uint32 value;

    value                      = protReg->U;
    owner->tagId               = (IfxApProt_TagId)((value >> IFX_PROT_PROT_TAGID_OFF) & IFX_PROT_PROT_TAGID_MSK);
    owner->ownerDefined        = ((value >> IFX_PROT_PROT_ODEF_OFF) & IFX_PROT_PROT_ODEF_MSK);
    owner->protectionSet       = (IfxApProt_PrsId)((value >> IFX_PROT_PROT_PRS_OFF) & IFX_PROT_PROT_PRS_MSK);
    owner->protectionSetEnable = ((value >> IFX_PROT_PROT_PRSEN_OFF) & IFX_PROT_PROT_PRSEN_MSK);
    owner->vmId                = (IfxApProt_VmId)((value >> IFX_PROT_PROT_VM_OFF) & IFX_PROT_PROT_VM_MSK);
    owner->vmEnable            = ((value >> IFX_PROT_PROT_VMEN_OFF) & IFX_PROT_PROT_VMEN_MSK);
}


IFX_INLINE void IfxApProt_setProtectionRegionSelect(volatile Ifx_PROT_PROT *protReg, unsigned char selVal)
{
    protReg->U = selVal << IFXAPPROT_SEL_OFFSET;
}


IFX_INLINE void IfxApProt_transitionState(volatile Ifx_PROT_PROT *protReg, IfxApProt_State state)
{
    Ifx_PROT_PROT prot;
    prot.U       = protReg->U;

    prot.B.SWEN  = 1U;
    prot.B.STATE = state;

    protReg->U   = prot.U;
}


#endif /* IFXAPPROT_H */
