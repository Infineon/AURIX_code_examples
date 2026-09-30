/**
 * \file IfxDmu_PinMap.h
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
 * \defgroup IfxLld_Dmu_Pinmap Dmu Pinmap Structure
 * \ingroup IfxLld_Dmu
 */

#ifndef IFXDMU_PINMAP_H
#define IFXDMU_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_PinMap.h"
#include "IfxDmu_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief
 */
typedef const struct
{
    Ifx_DMU    *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxDmu_Fdest_In;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Dx/IfxDmu_PinMap_TC4Dx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Dx/IfxDmu_PinMap_TC4Dx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC49XN)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC49xN/IfxDmu_PinMap_TC49xN_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC49xN/IfxDmu_PinMap_TC49xN_BGA292_STD.h"
#endif

#endif /* #if defined(DEVICE_TC4DX) */

#endif /* IFXDMU_PINMAP_H */
