/**
 * \file IfxGtm_PinMap.h
 * \brief GTM  details
 * \ingroup IfxLld_Gtm
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
 * \defgroup IfxLld_Gtm_Pinmap Gtm Pinmap Structure
 * \ingroup IfxLld_Gtm
 */

#ifndef IFXGTM_PINMAP_H
#define IFXGTM_PINMAP_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Gtm/Std/IfxGtm_Atom.h"
#include "Gtm/Std/IfxGtm_Tom.h"
#include "Gtm/Std/IfxGtm_Tim.h"
#include "_Impl/IfxGtm_cfg.h"
#include "Ifx_PinMap.h"
#include "IfxGtm_reg.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief CHxSEL register control code
 */
typedef enum
{
    IfxGtm_ChXSel_a = 0,   /**< \brief  */
    IfxGtm_ChXSel_b = 1,   /**< \brief  */
    IfxGtm_ChXSel_c = 2,   /**< \brief  */
    IfxGtm_ChXSel_d = 3,   /**< \brief  */
    IfxGtm_ChXSel_e = 4,   /**< \brief  */
    IfxGtm_ChXSel_f = 5,   /**< \brief  */
    IfxGtm_ChXSel_g = 6,   /**< \brief  */
    IfxGtm_ChXSel_h = 7,   /**< \brief  */
    IfxGtm_ChXSel_i = 8,   /**< \brief  */
    IfxGtm_ChXSel_j = 9,   /**< \brief  */
    IfxGtm_ChXSel_k = 10,  /**< \brief  */
    IfxGtm_ChXSel_l = 11,  /**< \brief  */
    IfxGtm_ChXSel_m = 12,  /**< \brief  */
    IfxGtm_ChXSel_n = 13,  /**< \brief  */
    IfxGtm_ChXSel_o = 14,  /**< \brief  */
    IfxGtm_ChXSel_p = 15   /**< \brief  */
} IfxGtm_ChXSel;

/** \brief TOUTSEL register control code
 */
typedef enum
{
    IfxGtm_ToutSel_0  = 0,   /**< \brief  */
    IfxGtm_ToutSel_1  = 1,   /**< \brief  */
    IfxGtm_ToutSel_2  = 2,   /**< \brief  */
    IfxGtm_ToutSel_3  = 3,   /**< \brief  */
    IfxGtm_ToutSel_4  = 4,   /**< \brief  */
    IfxGtm_ToutSel_5  = 5,   /**< \brief  */
    IfxGtm_ToutSel_6  = 6,   /**< \brief  */
    IfxGtm_ToutSel_7  = 7,   /**< \brief  */
    IfxGtm_ToutSel_8  = 8,   /**< \brief  */
    IfxGtm_ToutSel_9  = 9,   /**< \brief  */
    IfxGtm_ToutSel_10 = 10,  /**< \brief  */
    IfxGtm_ToutSel_11 = 11,  /**< \brief  */
    IfxGtm_ToutSel_12 = 12,  /**< \brief  */
    IfxGtm_ToutSel_13 = 13,  /**< \brief  */
    IfxGtm_ToutSel_14 = 14,  /**< \brief  */
    IfxGtm_ToutSel_15 = 15,  /**< \brief  */
    IfxGtm_ToutSel_16 = 16,  /**< \brief  */
    IfxGtm_ToutSel_17 = 17,  /**< \brief  */
    IfxGtm_ToutSel_18 = 18,  /**< \brief  */
    IfxGtm_ToutSel_19 = 19,  /**< \brief  */
    IfxGtm_ToutSel_20 = 20,  /**< \brief  */
    IfxGtm_ToutSel_21 = 21,  /**< \brief  */
    IfxGtm_ToutSel_22 = 22,  /**< \brief  */
    IfxGtm_ToutSel_23 = 23,  /**< \brief  */
    IfxGtm_ToutSel_24 = 24,  /**< \brief  */
    IfxGtm_ToutSel_25 = 25,  /**< \brief  */
    IfxGtm_ToutSel_26 = 26,  /**< \brief  */
    IfxGtm_ToutSel_27 = 27,  /**< \brief  */
    IfxGtm_ToutSel_28 = 28,  /**< \brief  */
    IfxGtm_ToutSel_29 = 29   /**< \brief  */
} IfxGtm_ToutSel;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief ATOM TOUT pin mapping structure
 */
typedef const struct
{
    IfxPort_Pin       pin;           /**< \brief Port pin */
    IfxPort_OutputIdx select;        /**< \brief Port control code */
    IfxGtm_Cluster    cluster;       /**< \brief ATOM cluster */
    IfxGtm_Atom_Ch    channel;       /**< \brief ATOM channel index */
    IfxGtm_ToutSel    toutSel;       /**< \brief TOUTSEL register control code */
    uint16            toutn;         /**< \brief TOUT number */
} IfxGtm_Atom_ToutMap;

/** \brief CDTM Input mapping structure
 */
typedef const struct
{
    IfxPort_Pin pin;          /**< \brief Port pin */
    uint8       select;       /**< \brief MUX sel */
    IfxGtm_Cdtm cdtm;         /**< \brief CDTM index */
    IfxGtm_Dtm  dtm;          /**< \brief DTM index */
} IfxGtm_Cdtm_InputMap;

/** \brief Clock output
 */
typedef const struct
{
    Ifx_GTM          *module;       /**< \brief Base address */
    IfxPort_Pin       pin;          /**< \brief Port pin */
    IfxPort_OutputIdx select;       /**< \brief Port control code */
} IfxGtm_EClk_Out;

/** \brief TIN pin Mapping structure
 */
typedef const struct
{
    IfxPort_Pin   pin;           /**< \brief Port pin */
    IfxGtm_ChXSel select;        /**< \brief Input multiplexer value */
    IfxGtm_Tim    tim;           /**< \brief TIM unit index */
    IfxGtm_Tim_Ch channel;       /**< \brief TIM channel index */
} IfxGtm_Tim_TinMap;

/** \brief TOM TOUT pin mapping structure
 */
typedef const struct
{
    IfxPort_Pin       pin;           /**< \brief Port pin */
    IfxPort_OutputIdx select;        /**< \brief Port control code */
    IfxGtm_Cluster    cluster;       /**< \brief TOM cluster */
    IfxGtm_Tom_Ch     channel;       /**< \brief TOM channel index */
    IfxGtm_ToutSel    toutSel;       /**< \brief TOUTSEL register control code */
    uint16            toutn;         /**< \brief TOUT number */
} IfxGtm_Tom_ToutMap;

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \return None
 */
IFX_EXTERN void IfxGtm_PinMap_setAtomTout(IfxGtm_Atom_ToutMap *config, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/**
 * \return None
 */
IFX_EXTERN void IfxGtm_PinMap_setTomTout(IfxGtm_Tom_ToutMap *config, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/**
 * \return None
 */
IFX_EXTERN void IfxGtm_PinMap_setCdtmPin(IfxGtm_Cdtm_InputMap *config, IfxPort_InputMode inputMode, IfxGtm_DtmAuxInput dtmAuxInput);

/**
 * \return None
 */
IFX_EXTERN void IfxGtm_PinMap_setTimTin(IfxGtm_Tim_TinMap *config, IfxPort_InputMode inputMode);

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC49XN)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC49xN/IfxGtm_PinMap_TC49xN_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC49xN/IfxGtm_PinMap_TC49xN_BGA292_STD.h"
#endif

#elif defined(DEVICE_TC46X)
#if defined(IFX_PIN_PACKAGE_BGA436_STD)
#include "TC46x/IfxGtm_PinMap_TC46x_BGA436_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC46x/IfxGtm_PinMap_TC46x_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC46x/IfxGtm_PinMap_TC46x_BGA224_STD.h"
#endif

#elif defined(DEVICE_TC4EX)
#if defined(IFX_PIN_PACKAGE_BGA292_STD)
#include "TC4Ex/IfxGtm_PinMap_TC4Ex_BGA292_STD.h"
#elif defined(IFX_PIN_PACKAGE_BGA224_STD)
#include "TC4Ex/IfxGtm_PinMap_TC4Ex_BGA224_STD.h"
#endif

#endif /* #if defined(DEVICE_TC49XN) */

#endif /* IFXGTM_PINMAP_H */
