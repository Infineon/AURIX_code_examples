/**
 * \file IfxEgtm_PinMap.h
 * \brief EGTM  details
 * \ingroup IfxLld_Egtm
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
 * \defgroup IfxLld_Egtm_Pinmap Egtm Pinmap Structure
 * \ingroup IfxLld_Egtm
 */

#ifndef IFXEGTM_PINMAP_H
#define IFXEGTM_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Egtm/Std/IfxEgtm_Atom.h"
#include "Egtm/Std/IfxEgtm_Tom.h"
#include "Egtm/Std/IfxEgtm_Tim.h"
#include "_Impl/IfxEgtm_cfg.h"
#include "Ifx_PinMap.h"
#include "IfxEgtm_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief CHxSEL register control code
 */
typedef enum
{
    IfxEgtm_ChXSel_a = 0,   /**< \brief  */
    IfxEgtm_ChXSel_b = 1,   /**< \brief  */
    IfxEgtm_ChXSel_c = 2,   /**< \brief  */
    IfxEgtm_ChXSel_d = 3,   /**< \brief  */
    IfxEgtm_ChXSel_e = 4,   /**< \brief  */
    IfxEgtm_ChXSel_f = 5,   /**< \brief  */
    IfxEgtm_ChXSel_g = 6,   /**< \brief  */
    IfxEgtm_ChXSel_h = 7,   /**< \brief  */
    IfxEgtm_ChXSel_i = 8,   /**< \brief  */
    IfxEgtm_ChXSel_j = 9,   /**< \brief  */
    IfxEgtm_ChXSel_k = 10,  /**< \brief  */
    IfxEgtm_ChXSel_l = 11,  /**< \brief  */
    IfxEgtm_ChXSel_m = 12,  /**< \brief  */
    IfxEgtm_ChXSel_n = 13   /**< \brief  */
} IfxEgtm_ChXSel;

/** \brief TOUTSEL register control code
 */
typedef enum
{
    IfxEgtm_ToutSel_0  = 0,   /**< \brief  */
    IfxEgtm_ToutSel_1  = 1,   /**< \brief  */
    IfxEgtm_ToutSel_2  = 2,   /**< \brief  */
    IfxEgtm_ToutSel_3  = 3,   /**< \brief  */
    IfxEgtm_ToutSel_4  = 4,   /**< \brief  */
    IfxEgtm_ToutSel_5  = 5,   /**< \brief  */
    IfxEgtm_ToutSel_6  = 6,   /**< \brief  */
    IfxEgtm_ToutSel_7  = 7,   /**< \brief  */
    IfxEgtm_ToutSel_8  = 8,   /**< \brief  */
    IfxEgtm_ToutSel_9  = 9,   /**< \brief  */
    IfxEgtm_ToutSel_10 = 10,  /**< \brief  */
    IfxEgtm_ToutSel_11 = 11,  /**< \brief  */
    IfxEgtm_ToutSel_12 = 12,  /**< \brief  */
    IfxEgtm_ToutSel_13 = 13,  /**< \brief  */
    IfxEgtm_ToutSel_14 = 14,  /**< \brief  */
    IfxEgtm_ToutSel_15 = 15,  /**< \brief  */
    IfxEgtm_ToutSel_16 = 16,  /**< \brief  */
    IfxEgtm_ToutSel_17 = 17,  /**< \brief  */
    IfxEgtm_ToutSel_18 = 18,  /**< \brief  */
    IfxEgtm_ToutSel_19 = 19,  /**< \brief  */
    IfxEgtm_ToutSel_20 = 20,  /**< \brief  */
    IfxEgtm_ToutSel_21 = 21,  /**< \brief  */
    IfxEgtm_ToutSel_22 = 22,  /**< \brief  */
    IfxEgtm_ToutSel_23 = 23,  /**< \brief  */
    IfxEgtm_ToutSel_24 = 24,  /**< \brief  */
    IfxEgtm_ToutSel_25 = 25,  /**< \brief  */
    IfxEgtm_ToutSel_26 = 26,  /**< \brief  */
    IfxEgtm_ToutSel_27 = 27,  /**< \brief  */
    IfxEgtm_ToutSel_28 = 28,  /**< \brief  */
    IfxEgtm_ToutSel_29 = 29   /**< \brief  */
} IfxEgtm_ToutSel;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief ATOM TOUT pin mapping structure
 */
typedef const struct
{
    IfxPort_Pin       pin;           /**< \brief Port pin */
    IfxPort_OutputIdx select;        /**< \brief Port control code */
#if defined(DEVICE_TC4DX)	
    IfxEgtm_Atom      atom;          /**< \brief ATOM cluster */
#else
    IfxEgtm_Cluster   cluster;       /**< \brief ATOM cluster */
#endif	
    IfxEgtm_Atom_Ch   channel;       /**< \brief ATOM channel index */
    IfxEgtm_ToutSel   toutSel;       /**< \brief TOUTSEL register control code */
    uint16            toutn;         /**< \brief TOUT number */
} IfxEgtm_Atom_ToutMap;

/** \brief CDTM Input mapping structure
 */
typedef const struct
{
    IfxPort_Pin  pin;          /**< \brief Port pin */
    uint8        select;       /**< \brief MUX sel */
    IfxEgtm_Cdtm cdtm;         /**< \brief CDTM index */
    IfxEgtm_Dtm  dtm;          /**< \brief DTM index */
} IfxEgtm_Cdtm_InputMap;

/** \brief Clock output
 */
typedef const struct
{
    Ifx_EGTM         *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxEgtm_EClk_Out;

/** \brief HRPWM Channel mapping structure
 */
typedef const struct
{
    IfxEgtm_Hrpwm     hrpwm;         /**< \brief HRPWM index */
    IfxEgtm_Hrpwm_Ch  channel;       /**< \brief Channel index */
    IfxPort_Pin       pin;           /**< \brief Port pin */
    IfxPort_OutputIdx select;        /**< \brief Port control code */
} IfxEgtm_Hrpwm_Out;

/** \brief TIN pin Mapping structure
 */
typedef const struct
{
    IfxPort_Pin    pin;           /**< \brief Port pin */
    IfxEgtm_ChXSel select;        /**< \brief Input multiplexer value */
    IfxEgtm_Tim    tim;           /**< \brief TIM unit index */
    IfxEgtm_Tim_Ch channel;       /**< \brief TIM channel index */
} IfxEgtm_Tim_TinMap;

/** \brief TOM TOUT pin mapping structure
 */
typedef const struct
{
    IfxPort_Pin       pin;           /**< \brief Port pin */
    IfxPort_OutputIdx select;        /**< \brief Port control code */
#if defined(DEVICE_TC4DX)	
    IfxEgtm_Tom       tom;           /**< \brief TOM cluster */
#else
    IfxEgtm_Cluster   cluster;       /**< \brief TOM cluster */
#endif		
    IfxEgtm_Tom_Ch    channel;       /**< \brief TOM channel index */
    IfxEgtm_ToutSel   toutSel;       /**< \brief TOUTSEL register control code */
    uint16            toutn;         /**< \brief TOUT number */
} IfxEgtm_Tom_ToutMap;

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \return None
 */
IFX_EXTERN void IfxEgtm_PinMap_setAtomTout(IfxEgtm_Atom_ToutMap *config, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/**
 * \return None
 */
IFX_EXTERN void IfxEgtm_PinMap_setTomTout(IfxEgtm_Tom_ToutMap *config, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/**
 * \return None
 */
IFX_EXTERN void IfxEgtm_PinMap_setCdtmPin(IfxEgtm_Cdtm_InputMap *config, IfxPort_InputMode inputMode, IfxEgtm_DtmAuxInput dtmAuxInput);

/**
 * \return None
 */
IFX_EXTERN void IfxEgtm_PinMap_setTimTin(IfxEgtm_Tim_TinMap *config, IfxPort_InputMode inputMode);

/**
 * \return None
 */
IFX_EXTERN void IfxEgtm_PinMap_setHrpwmOut(IfxEgtm_Hrpwm_Out *config, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Dx/IfxEgtm_PinMap_TC4Dx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Dx/IfxEgtm_PinMap_TC4Dx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC49XN)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC49xN/IfxEgtm_PinMap_TC49xN_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC49xN/IfxEgtm_PinMap_TC49xN_BGA292_STD.h"
#endif

#elif defined(DEVICE_TC48XAA)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48xAA/IfxEgtm_PinMap_TC48xAA_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48xAA/IfxEgtm_PinMap_TC48xAA_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48xAA/IfxEgtm_PinMap_TC48xAA_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48xAA/IfxEgtm_PinMap_TC48xAA_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC48X)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC48x/IfxEgtm_PinMap_TC48x_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC48x/IfxEgtm_PinMap_TC48x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC48x/IfxEgtm_PinMap_TC48x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC48x/IfxEgtm_PinMap_TC48x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC46X)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC46x/IfxEgtm_PinMap_TC46x_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC46x/IfxEgtm_PinMap_TC46x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC46x/IfxEgtm_PinMap_TC46x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC44X)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC44x/IfxEgtm_PinMap_TC44x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC44x/IfxEgtm_PinMap_TC44x_BGA292_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC44x/IfxEgtm_PinMap_TC44x_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC44x/IfxEgtm_PinMap_TC44x_BGA188_STD.h"
#endif

#elif defined(DEVICE_TC4ZX)
#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "TC4Zx/IfxEgtm_PinMap_TC4Zx_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "TC4Zx/IfxEgtm_PinMap_TC4Zx_BGA292_COM.h"
#endif

#elif defined(DEVICE_TC4EX)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC4Ex/IfxEgtm_PinMap_TC4Ex_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC4Ex/IfxEgtm_PinMap_TC4Ex_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC4PX)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC4Px/IfxEgtm_PinMap_TC4Px_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC4Px/IfxEgtm_PinMap_TC4Px_BGA224_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA188_STD)
#include "TC4Px/IfxEgtm_PinMap_TC4Px_BGA188_STD.h"
#endif

#endif /* #if defined(DEVICE_TC4DX) */

#endif /* IFXEGTM_PINMAP_H */
