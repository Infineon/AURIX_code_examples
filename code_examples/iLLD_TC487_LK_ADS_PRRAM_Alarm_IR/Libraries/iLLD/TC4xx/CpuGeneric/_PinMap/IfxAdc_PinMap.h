/**
 * \file IfxAdc_PinMap.h
 * \brief ADC  details
 * \ingroup IfxLld_Adc
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
 * \defgroup IfxLld_Adc_Pinmap Adc Pinmap Structure
 * \ingroup IfxLld_Adc
 */

#ifndef IFXADC_PINMAP_H
#define IFXADC_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_PinMap.h"
#include "IfxAdc_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX)
/** \brief   
*/
typedef const struct
{
    Ifx_ADC*        module;   /**< \brief Base address */
    IfxPort_Pin     pin;      /**< \brief Port pin */
    Ifx_RxSel       select;   /**< \brief Input multiplexer value */
} IfxAdc_Clkin_In;
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC44X)  || defined(DEVICE_TC4EX) */

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX)
/** \brief
 */
typedef const struct
{
    Ifx_ADC          *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxAdc_Bfl_Out;

/** \brief
 */
typedef const struct
{
    Ifx_ADC          *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxAdc_Clkout_Out;

/** \brief
 */
typedef const struct
{
    Ifx_ADC    *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxAdc_Data_In;
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX)  || defined(DEVICE_TC4PX)
/** \brief
 */
typedef const struct
{
    Ifx_ADC    *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxAdc_Dsadcn_In;

/** \brief
 */
typedef const struct
{
    Ifx_ADC    *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxAdc_Dsadcp_In;
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

/** \brief
 */
typedef const struct
{
    Ifx_ADC          *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxAdc_Emuxctrl_Out;

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX)
/** \brief
 */
typedef const struct
{
    Ifx_ADC    *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxAdc_Fcc_In;
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX)
/** \brief
 */
typedef const struct
{
    Ifx_ADC          *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxAdc_Pwm_Out;
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if !defined(DEVICE_TC45X) || !defined(DEVICE_TC4ZX) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX)
/** \brief
 */
typedef const struct
{
    Ifx_ADC    *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxAdc_Sign_In;
#endif /* #if !defined(DEVICE_TC45X) || !defined(DEVICE_TC4ZX) || defined(DEVICE_TC4EX) */

/** \brief
 */
typedef const struct
{
    Ifx_ADC    *module;               /**< \brief Base address */
    uint8       tmadcModuleId;        /**< \brief TMADC Module ID */
    uint8       tmadcChannelId;       /**< \brief TMADC Channel ID */
    IfxPort_Pin pin;                  /**< \brief Port pin */
    Ifx_RxSel   select;               /**< \brief Input multiplexer value */
} IfxAdc_TmadcCh_In;

/** \brief
 */
typedef const struct
{
    Ifx_ADC    *module;       /**< \brief Base address */
    IfxPort_Pin pin;          /**< \brief Port pin */
    Ifx_RxSel   select;       /**< \brief Input multiplexer value */
} IfxAdc_Trig_In;

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Dx/IfxAdc_PinMap_TC4Dx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Dx/IfxAdc_PinMap_TC4Dx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC49XN)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC49xN/IfxAdc_PinMap_TC49xN_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC49xN/IfxAdc_PinMap_TC49xN_BGA292_STD.h"
#endif

#elif defined(DEVICE_TC48XAA)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48xAA/IfxAdc_PinMap_TC48xAA_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48xAA/IfxAdc_PinMap_TC48xAA_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48xAA/IfxAdc_PinMap_TC48xAA_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48xAA/IfxAdc_PinMap_TC48xAA_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC48X)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48x/IfxAdc_PinMap_TC48x_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48x/IfxAdc_PinMap_TC48x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48x/IfxAdc_PinMap_TC48x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48x/IfxAdc_PinMap_TC48x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC46X)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC46x/IfxAdc_PinMap_TC46x_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC46x/IfxAdc_PinMap_TC46x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC46x/IfxAdc_PinMap_TC46x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC45X)
#if defined(IFX_PIN_PACKAGE_BGA292_RDR)
#include "TC45x/IfxAdc_PinMap_TC45x_BGA292_RDR.h"
#endif

#elif defined(DEVICE_TC44X)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC44x/IfxAdc_PinMap_TC44x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC44x/IfxAdc_PinMap_TC44x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC44x/IfxAdc_PinMap_TC44x_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC44x/IfxAdc_PinMap_TC44x_BGA188_STD.h"
#endif

#elif defined(DEVICE_TC4ZX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Zx/IfxAdc_PinMap_TC4Zx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Zx/IfxAdc_PinMap_TC4Zx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC4EX)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC4Ex/IfxAdc_PinMap_TC4Ex_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC4Ex/IfxAdc_PinMap_TC4Ex_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC4PX)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC4Px/IfxAdc_PinMap_TC4Px_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC4Px/IfxAdc_PinMap_TC4Px_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC4Px/IfxAdc_PinMap_TC4Px_BGA188_STD.h"
#endif

#endif /* #if defined(DEVICE_TC4DX) */

#endif /* IFXADC_PINMAP_H */
