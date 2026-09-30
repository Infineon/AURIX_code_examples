/**
 * \file IfxDmur_PinMap_TC48x_BGA436_COM.h
 * \brief DMUR  details
 * \ingroup IfxLld_Dmur
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
 * Version: MC_ACE_A3G_PRQ_Package_Pinning/V8.1.3.1.0
 * Document: TC48x_Pin_Assignment_v0.62.xls
 *
 * \defgroup IfxLld_Dmur_Pinmap Dmur Pinmap Structure
 * \ingroup IfxLld_Dmur
 * \defgroup IfxLld_Dmur__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Dmur_
 * \defgroup IfxLld_Dmur__PinTables PinTables
 * \ingroup IfxLld_Dmur_
 */

#ifndef IFXDMUR_PINMAP_TC48X_BGA436_COM_H
#define IFXDMUR_PINMAP_TC48X_BGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxDmur_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXDMUR_PINMAP_NUM_MODULES        1

#define IFXDMUR_PINMAP_FDEST_IN_NUM_ITEMS 1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief
 */
IFX_EXTERN IfxDmur_Fdest_In IfxDmur_FDEST_P21_0_IN;

/** \addtogroup IfxLld_Dmur__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxDmur_Fdest_In Table
 */
IFX_EXTERN IFX_CONST IfxDmur_Fdest_In *IfxDmur_Fdest_In_pinTable[IFXDMUR_PINMAP_NUM_MODULES][IFXDMUR_PINMAP_FDEST_IN_NUM_ITEMS];

/** \} */

#endif /* IFXDMUR_PINMAP_TC48X_BGA436_COM_H */
