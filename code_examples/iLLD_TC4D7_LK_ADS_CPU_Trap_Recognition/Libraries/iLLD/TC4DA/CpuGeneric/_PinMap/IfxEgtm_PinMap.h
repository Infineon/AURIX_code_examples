/**
 * \file IfxEgtm_PinMap.h
 * \brief EGTM  details
 * \ingroup IfxLld_Egtm
 *
 * \version iLLD-TC4-v2.1.1
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 * Version: MC_ACE_A3G_HWA_Ports/Unknown
 * Document: TC4Dx_Pin_Assignment_v0.45_LETH_patched.xls
 *
 * \defgroup IfxLld_Egtm_
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
    IfxEgtm_Atom      atom;          /**< \brief ATOM cluster */
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
    IfxEgtm_Tom       tom;           /**< \brief TOM cluster */
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

#if defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "IfxEgtm_PinMap_BGA436_COM.h"
#elif defined(IFX_PIN_PACKAGE_BGA292_COM)
#include "IfxEgtm_PinMap_BGA292_COM.h"
#endif

#endif /* IFXEGTM_PINMAP_H */
