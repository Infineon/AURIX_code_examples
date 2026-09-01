/**
 * \file Ifx_PinMap.h
 * \brief Pinmap configuration file.
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
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
 */

#ifndef IFX_PINAMP_H
#define IFX_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX)
/** \brief Default Pin Package for TC4Dx 
 */
#if !defined(IFX_PIN_PACKAGE_BGA436_COM) && !defined(IFX_PIN_PACKAGE_BGA292_COM)
#define IFX_PIN_PACKAGE_BGA436_COM
#endif

#elif defined(DEVICE_TC49XN)
/** \brief Default Pin Package for TC49xN
 */
#if !defined(IFX_PIN_PACKAGE_BGA292_STD) && !defined(IFX_PIN_PACKAGE_BGA436_STD)
#define IFX_PIN_PACKAGE_BGA436_STD
#endif

#elif defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X)
/** \brief Default Pin Package for TC48x
 */
#if !defined(IFX_PIN_PACKAGE_BGA224_STD) && !defined(IFX_PIN_PACKAGE_BGA292_COM) && !defined(IFX_PIN_PACKAGE_BGA292_STD) && !defined(IFX_PIN_PACKAGE_BGA436_COM)
#define IFX_PIN_PACKAGE_BGA436_COM
#endif

#elif defined(DEVICE_TC46X)
/** \brief Default Pin Package for TC46x
 */
#if !defined(IFX_PIN_PACKAGE_BGA224_STD) && !defined(IFX_PIN_PACKAGE_BGA292_STD) && !defined(IFX_PIN_PACKAGE_BGA436_STD)
#define IFX_PIN_PACKAGE_BGA436_STD
#endif

#elif defined(DEVICE_TC45X)
/** \brief Default Pin Package for TC45x
 */
#if !defined(IFX_PIN_PACKAGE_BGA292_RDR)
#define IFX_PIN_PACKAGE_BGA292_RDR
#endif

#elif defined(DEVICE_TC44X)
/** \brief Default Pin Package for TC44x
 */
#if !defined(IFX_PIN_PACKAGE_BGA188_STD) && !defined(IFX_PIN_PACKAGE_BGA224_STD) && !defined(IFX_PIN_PACKAGE_BGA292_STD) && !defined(IFX_PIN_PACKAGE_BGA292_COM)
#define IFX_PIN_PACKAGE_BGA292_COM
#endif

#elif defined(DEVICE_TC4ZX)
/** \brief Default Pin Package for TC4Zx
 */
#if !defined(IFX_PIN_PACKAGE_BGA436_COM) && !defined(IFX_PIN_PACKAGE_BGA292_COM)
#define IFX_PIN_PACKAGE_BGA436_COM
#endif

#elif defined(DEVICE_TC4EX)
/** \brief Default Pin Package for TC4Ex
 */
#if !defined(IFX_PIN_PACKAGE_BGA292_STD) && !defined(IFX_PIN_PACKAGE_BGA224_STD)
#define IFX_PIN_PACKAGE_BGA292_STD
#endif

#elif defined(DEVICE_TC4PX)
/** \brief Default Pin Package for TC4Px
 */
#if !defined(IFX_PIN_PACKAGE_BGA292_STD) && !defined(IFX_PIN_PACKAGE_BGA224_STD) && !defined(IFX_PIN_PACKAGE_BGA188_STD)
#define IFX_PIN_PACKAGE_BGA292_STD
#endif

#else
#error "TC4xx device configuration is missing or incorrect. Please define a valid TC4xx device macro in Ifx_Cfg.h."
#endif /* #if defined(DEVICE_TC4DX) */

#endif /* IFX_PINMAP_H */
