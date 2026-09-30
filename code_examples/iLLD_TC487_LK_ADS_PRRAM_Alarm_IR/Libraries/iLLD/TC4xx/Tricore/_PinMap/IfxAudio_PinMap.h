/**
 * \file IfxAudio_PinMap.h
 * \brief AUDIO  details
 * \ingroup IfxLld_Audio
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
 * \defgroup IfxLld_Audio_Pinmap Audio Pinmap Structure
 * \ingroup IfxLld_Audio
 */

#ifndef IFXAUDIO_PINMAP_H
#define IFXAUDIO_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxAudio_cfg.h"
#include "Ifx_PinMap.h"
#include "IfxAudio_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief IOMUX selection
 */
typedef enum
{
    IfxAudio_PinSel_a = 0,  /**< \brief  */
    IfxAudio_PinSel_b = 1,  /**< \brief  */
    IfxAudio_PinSel_c = 2,  /**< \brief  */
    IfxAudio_PinSel_d = 3   /**< \brief  */
} IfxAudio_PinSel;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxAudio_PinSel            select;                  /**< \brief Input multiplexer value */
} IfxAudio_Rxfsync_In;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxPort_OutputIdx          select;                  /**< \brief Port control code */
} IfxAudio_Rxfsync_Out;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxAudio_PinSel            select;                  /**< \brief Input multiplexer value */
} IfxAudio_Rxmck_In;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxPort_OutputIdx          select;                  /**< \brief Port control code */
} IfxAudio_Rxmck_Out;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxAudio_PinSel            select;                  /**< \brief Input multiplexer value */
} IfxAudio_Rxsck_In;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxPort_OutputIdx          select;                  /**< \brief Port control code */
} IfxAudio_Rxsck_Out;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxAudio_PinSel            select;                  /**< \brief Input multiplexer value */
} IfxAudio_Rxsd_In;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxAudio_PinSel            select;                  /**< \brief Input multiplexer value */
} IfxAudio_Txfsync_In;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxPort_OutputIdx          select;                  /**< \brief Port control code */
} IfxAudio_Txfsync_Out;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxAudio_PinSel            select;                  /**< \brief Input multiplexer value */
} IfxAudio_Txmck_In;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxPort_OutputIdx          select;                  /**< \brief Port control code */
} IfxAudio_Txmck_Out;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxAudio_PinSel            select;                  /**< \brief Input multiplexer value */
} IfxAudio_Txsck_In;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxPort_OutputIdx          select;                  /**< \brief Port control code */
} IfxAudio_Txsck_Out;

/** \brief
 */
typedef const struct
{
    Ifx_AUDIO                 *module;                  /**< \brief Base address */
    IfxAudio_TdmInterfaceIndex tdmInterfaceIndex;       /**< \brief TDM Interface Index */
    IfxPort_Pin                pin;                     /**< \brief Port pin */
    IfxAudio_PinSel            select;                  /**< \brief Input multiplexer value */
} IfxAudio_Txsd_Out;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC48XAA)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48xAA/IfxAudio_PinMap_TC48xAA_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48xAA/IfxAudio_PinMap_TC48xAA_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48xAA/IfxAudio_PinMap_TC48xAA_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48xAA/IfxAudio_PinMap_TC48xAA_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC48X)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48x/IfxAudio_PinMap_TC48x_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48x/IfxAudio_PinMap_TC48x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48x/IfxAudio_PinMap_TC48x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48x/IfxAudio_PinMap_TC48x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC44X)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC44x/IfxAudio_PinMap_TC44x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC44x/IfxAudio_PinMap_TC44x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC44x/IfxAudio_PinMap_TC44x_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC44x/IfxAudio_PinMap_TC44x_BGA188_STD.h"
#endif

#elif defined(DEVICE_TC4ZX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Zx/IfxAudio_PinMap_TC4Zx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Zx/IfxAudio_PinMap_TC4Zx_BGA292_COM.h"
#endif

#endif /* if defined(DEVICE_TC48XAA) */

#endif /* IFXAUDIO_PINMAP_H */
