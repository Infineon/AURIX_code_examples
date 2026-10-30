/**
 * \file IfxSdmmc_PinMap.h
 * \brief SDMMC I/O map
 * \ingroup IfxLld_Sdmmc
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Sdmmc_pinmap SDMMC Pin Mapping
 * \ingroup IfxLld_Sdmmc
 */

#ifndef IFXSDMMC_PINMAP_H
#define IFXSDMMC_PINMAP_H

#include "Ifx_Cfg.h"

#if defined(DEVICE_TC39XB) 
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxSdmmc_PinMap_TC39xB_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxSdmmc_PinMap_TC39xB_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292_ADAS)
#include "IfxSdmmc_PinMap_TC39xB_LFBGA292_adas.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA516)
#include "IfxSdmmc_PinMap_TC39xB_LFBGA516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_TQFP144) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LQFP176) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"


#endif

#elif defined(DEVICE_TC38EVOX) 
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxSdmmc_PinMap_TC38EVOx_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxSdmmc_PinMap_TC38EVOx_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_LFBGA292_ADAS) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_TQFP144) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LQFP176) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC37XED) 
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxSdmmc_PinMap_TC37xED_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxSdmmc_PinMap_TC37xED_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#include "IfxSdmmc_PinMap_TC37xED_LFBGA292_geth.h"
#elif defined(IFX_PIN_PACKAGE_LQFP144)
#include "IfxSdmmc_PinMap_TC37xED_LQFP144.h"
#elif defined(IFX_PIN_PACKAGE_LQFP176)
#include "IfxSdmmc_PinMap_TC37xED_LQFP176.h"
#elif defined(IFX_PIN_PACKAGE_TQFP144)
#include "IfxSdmmc_PinMap_TC37xED_TQFP144.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_LFBGA292_ADAS) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC33XED) 
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxSdmmc_PinMap_TC33xED_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180_ADAS)
#include "IfxSdmmc_PinMap_TC33xED_LFBGA180_adas.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292_ADAS)
#include "IfxSdmmc_PinMap_TC33xED_LFBGA292_adas.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA292) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_TQFP144) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LQFP176) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#endif

#endif /* IFXSDMMC_PINMAP_H */
