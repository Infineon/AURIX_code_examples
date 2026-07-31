/**
 * \file IfxPsi5_cfg_TC4Dx.h
 * \brief PSI5 on-chip implementation data
 * \ingroup IfxLld_Psi5
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
 * \defgroup IfxLld_Psi5 PSI5
 * \ingroup IfxLld
 * \defgroup IfxLld_Psi5_Impl Implementation
 * \ingroup IfxLld_Psi5
 * \defgroup IfxLld_Psi5_Std Standard Driver
 * \ingroup IfxLld_Psi5
 * \defgroup IfxLld_Psi5_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Psi5_Impl
 */

#ifndef IFXPSI5_CFG_TC4DX_H
#define IFXPSI5_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxPsi5_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPSI5_STEP_RANGE             1024

#define IFXPSI5_NUM_WDTS               7

#define IFXPSI5_NUM_SLOTS              6

#define IFXPSI5_ENABLE_CHANNELTRIGGER  (1 << 8)

#define IFXPSI5_ENABLE_CHANNEL         (1 << 16)

#define IFXPSI5_DEFAULT_SLOWCLOCK_FREQ 4000000

#define IFXPSI5_DEFAULT_FASTCLOCK_FREQ 6000000

#define IFXPSI5_DEFAULT_TIMESTAMP_FREQ 1000000

#define IFXPSI5_NUM_CHANNELS           2

#define IFXPSI5_NUM_MODULES            (1)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Channel Id
 */
typedef enum
{
    IfxPsi5_ChannelId_none = -1,  /**< \brief None of the Ifx_PSI5 Channels */
    IfxPsi5_ChannelId_0    = 0,   /**< \brief Specifies PSI5 channel 0  */
    IfxPsi5_ChannelId_1           /**< \brief Specifies PSI5 channel 1  */
} IfxPsi5_ChannelId;

/** \brief List of the available Psi5 resources
 */
typedef enum
{
    IfxPsi5_Index_none = -1,  /**< \brief Not Selected */
    IfxPsi5_Index_0    = 0    /**< \brief Psi5 index 0 */
} IfxPsi5_Index;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxPsi5_cfg_indexMap[IFXPSI5_NUM_MODULES];

#endif /* IFXPSI5_CFG_TC4DX_H */
