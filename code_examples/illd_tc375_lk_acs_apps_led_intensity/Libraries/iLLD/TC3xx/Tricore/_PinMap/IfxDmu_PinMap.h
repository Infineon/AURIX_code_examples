/**
 * \file IfxDmu_PinMap.h
 * \brief DMU I/O map
 * \ingroup IfxLld_Dmu
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
 * \defgroup IfxLld_Dmu_pinmap DMU Pin Mapping
 * \ingroup IfxLld_Dmu
 */

#ifndef IFXDMU_PINMAP_H
#define IFXDMU_PINMAP_H

#include "Ifx_Cfg.h"

#if defined(DEVICE_TC39XB)
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxDmu_PinMap_TC39xB_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxDmu_PinMap_TC39xB_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292_ADAS)
#include "IfxDmu_PinMap_TC39xB_LFBGA292_adas.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA516)
#include "IfxDmu_PinMap_TC39xB_LFBGA516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_TQFP144) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LQFP176) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC38X)
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxDmu_PinMap_TC38x_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxDmu_PinMap_TC38x_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA516)
#include "IfxDmu_PinMap_TC38x_LFBGA516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_LFBGA292_ADAS) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_TQFP144) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LQFP176) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC38EVOX)
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxDmu_PinMap_TC38EVOx_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxDmu_PinMap_TC38EVOx_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_LFBGA292_ADAS) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_TQFP144) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LQFP176) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC37XED)
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxDmu_PinMap_TC37xED_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxDmu_PinMap_TC37xED_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#include "IfxDmu_PinMap_TC37xED_LFBGA292_geth.h"
#elif defined(IFX_PIN_PACKAGE_LQFP144)
#include "IfxDmu_PinMap_TC37xED_LQFP144.h"
#elif defined(IFX_PIN_PACKAGE_LQFP176)
#include "IfxDmu_PinMap_TC37xED_LQFP176.h"
#elif defined(IFX_PIN_PACKAGE_TQFP144)
#include "IfxDmu_PinMap_TC37xED_TQFP144.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_LFBGA292_ADAS) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC37X)
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxDmu_PinMap_TC37x_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxDmu_PinMap_TC37x_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_LQFP176)
#include "IfxDmu_PinMap_TC37x_LQFP176.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_LFBGA292_ADAS) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_TQFP144) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC36X)
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxDmu_PinMap_TC36x_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180)
#include "IfxDmu_PinMap_TC36x_LFBGA180.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxDmu_PinMap_TC36x_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_LQFP144)
#include "IfxDmu_PinMap_TC36x_LQFP144.h"
#elif defined(IFX_PIN_PACKAGE_LQFP176)
#include "IfxDmu_PinMap_TC36x_LQFP176.h"
#elif defined(IFX_PIN_PACKAGE_TQFP144)
#include "IfxDmu_PinMap_TC36x_TQFP144.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_LFBGA292_ADAS) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC35X)
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxDmu_PinMap_TC35x_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180_ADAS)
#include "IfxDmu_PinMap_TC35x_LFBGA180_adas.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292_ADAS)
#include "IfxDmu_PinMap_TC35x_LFBGA292_adas.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA292) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_TQFP144) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LQFP176) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC33X)
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxDmu_PinMap_TC33x_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180)
#include "IfxDmu_PinMap_TC33x_LFBGA180.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292)
#include "IfxDmu_PinMap_TC33x_LFBGA292.h"
#elif defined(IFX_PIN_PACKAGE_TQFP80)
#include "IfxDmu_PinMap_TC33x_TQFP80.h"
#elif defined(IFX_PIN_PACKAGE_TQFP100)
#include "IfxDmu_PinMap_TC33x_TQFP100.h"
#elif defined(IFX_PIN_PACKAGE_TQFP144)
#include "IfxDmu_PinMap_TC33x_TQFP144.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA180_ADAS) || defined(IFX_PIN_PACKAGE_LFBGA292_ADAS) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LQFP176) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#elif defined(DEVICE_TC33XED)
#if defined(IFX_PIN_PACKAGE_516)
#include "IfxDmu_PinMap_TC33xED_516.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180_ADAS)
#include "IfxDmu_PinMap_TC33xED_LFBGA180_adas.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA292_ADAS)
#include "IfxDmu_PinMap_TC33xED_LFBGA292_adas.h"
#elif defined(IFX_PIN_PACKAGE_LFBGA180) || defined(IFX_PIN_PACKAGE_LFBGA516) || defined(IFX_PIN_PACKAGE_LFBGA292) || defined(IFX_PIN_PACKAGE_TQFP80) || defined(IFX_PIN_PACKAGE_TQFP100) || defined(IFX_PIN_PACKAGE_TQFP144) || defined(IFX_PIN_PACKAGE_LQFP144) || defined(IFX_PIN_PACKAGE_LQFP176) || defined(IFX_PIN_PACKAGE_LFBGA292_GETH)
#error "The pin package enabled in Ifx_Cfg.h file is not supported for the selected device"
#endif

#endif  

#endif  /* IFXDMU_PINMAP_H */
