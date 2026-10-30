/**
 * \file IfxDmu_PinMap_TC4Dx_BGA436_COM.h
 * \brief DMU  details
 * \ingroup IfxLld_Dmu
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
 * Version: MC_ACE_A3G_HWA_Ports/Unknown
 * Document: TC4Dx_Pin_Assignment_v0.45_LETH_patched.xls
 *
 * \defgroup IfxLld_Dmu_
 * \ingroup IfxLld_Dmu
 * \defgroup IfxLld_Dmu__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Dmu_
 * \defgroup IfxLld_Dmu__PinTables PinTables
 * \ingroup IfxLld_Dmu_
 */

#ifndef IFXDMU_PINMAP_TC4DX_BGA436_COM_H
#define IFXDMU_PINMAP_TC4DX_BGA436_COM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxDmu_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXDMU_PINMAP_NUM_MODULES        1

#define IFXDMU_PINMAP_FDEST_IN_NUM_ITEMS 1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief
 */
IFX_EXTERN IfxDmu_Fdest_In IfxDmu_FDEST_P21_0_IN;

/** \addtogroup IfxLld_Dmu__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxDmu_Fdest_In Table
 */
IFX_EXTERN IFX_CONST IfxDmu_Fdest_In *IfxDmu_Fdest_In_pinTable[IFXDMU_PINMAP_NUM_MODULES][IFXDMU_PINMAP_FDEST_IN_NUM_ITEMS];

/** \} */

#endif /* IFXDMU_PINMAP_TC4DX_BGA436_COM_H */
