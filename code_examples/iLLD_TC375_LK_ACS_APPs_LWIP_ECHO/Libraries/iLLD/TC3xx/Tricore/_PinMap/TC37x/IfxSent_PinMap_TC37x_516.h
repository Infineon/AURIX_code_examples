/**
 * \file IfxSent_PinMap_TC37x_516.h
 * \brief SENT I/O map
 * \ingroup IfxLld_Sent
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
 * \defgroup IfxLld_Sent_pinmap SENT Pin Mapping
 * \ingroup IfxLld_Sent
 */

#ifndef IFXSENT_PINMAP_TC37X_516_H
#define IFXSENT_PINMAP_TC37X_516_H 1

#include <IfxSent_reg.h>
#include <_Impl/IfxSent_cfg.h>
#include <Port/Std/IfxPort.h>
#include "Ifx_PinMap.h"

/** \addtogroup IfxLld_Sent_pinmap
 * \{ */

/** \brief SENT pin mapping structure */
typedef const struct
{
    Ifx_SENT*         module;    /**< \brief Base address */
    IfxSent_ChannelId channelId; /**< \brief Channel ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         select;    /**< \brief Input multiplexer value */
} IfxSent_Sent_In;

/** \brief SPC pin mapping structure */
typedef const struct
{
    Ifx_SENT*         module;    /**< \brief Base address */
    IfxSent_ChannelId channelId; /**< \brief Channel ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxSent_Spc_Out;

IFX_EXTERN IfxSent_Sent_In IfxSent_SENT0A_P40_0_IN;  /**< \brief Receive input channel 0 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT0B_P00_1_IN;  /**< \brief Receive input channel 0 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT0C_P02_8_IN;  /**< \brief Receive input channel 0 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT10A_P40_10_IN;  /**< \brief Receive input channel 10 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT10B_P00_11_IN;  /**< \brief Receive input channel 10 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT10C_P32_5_IN;  /**< \brief Receive input channel 10 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT10D_P15_2_IN;  /**< \brief Receive input channel 10 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT11A_P40_11_IN;  /**< \brief Receive input channel 11 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT11B_P00_12_IN;  /**< \brief Receive input channel 11 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT11C_P32_6_IN;  /**< \brief Receive input channel 11 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT11D_P15_4_IN;  /**< \brief Receive input channel 11 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT12A_P40_12_IN;  /**< \brief Receive input channel 12 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT12B_P02_4_IN;  /**< \brief Receive input channel 12 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT12C_P32_7_IN;  /**< \brief Receive input channel 12 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT13A_P40_13_IN;  /**< \brief Receive input channel 13 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT13B_P02_3_IN;  /**< \brief Receive input channel 13 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT13C_P33_0_IN;  /**< \brief Receive input channel 13 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT14A_P40_14_IN;  /**< \brief Receive input channel 14 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT14B_P02_2_IN;  /**< \brief Receive input channel 14 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT14C_P33_7_IN;  /**< \brief Receive input channel 14 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT1A_P40_1_IN;  /**< \brief Receive input channel 1 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT1B_P00_2_IN;  /**< \brief Receive input channel 1 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT1C_P02_7_IN;  /**< \brief Receive input channel 1 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT2A_P40_2_IN;  /**< \brief Receive input channel 2 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT2B_P00_3_IN;  /**< \brief Receive input channel 2 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT2C_P02_6_IN;  /**< \brief Receive input channel 2 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT3A_P40_3_IN;  /**< \brief Receive input channel 3 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT3B_P00_4_IN;  /**< \brief Receive input channel 3 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT3C_P02_5_IN;  /**< \brief Receive input channel 3 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT4A_P40_4_IN;  /**< \brief Receive input channel 4 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT4B_P00_5_IN;  /**< \brief Receive input channel 4 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT4C_P33_6_IN;  /**< \brief Receive input channel 4 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT5A_P40_5_IN;  /**< \brief Receive input channel 5 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT5B_P00_6_IN;  /**< \brief Receive input channel 5 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT5C_P33_5_IN;  /**< \brief Receive input channel 5 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT6A_P40_6_IN;  /**< \brief Receive input channel 6 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT6B_P00_7_IN;  /**< \brief Receive input channel 6 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT6C_P33_4_IN;  /**< \brief Receive input channel 6 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT7A_P40_7_IN;  /**< \brief Receive input channel 7 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT7B_P00_8_IN;  /**< \brief Receive input channel 7 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT7C_P33_3_IN;  /**< \brief Receive input channel 7 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT8A_P40_8_IN;  /**< \brief Receive input channel 8 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT8B_P00_9_IN;  /**< \brief Receive input channel 8 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT8C_P33_2_IN;  /**< \brief Receive input channel 8 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT9A_P40_9_IN;  /**< \brief Receive input channel 9 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT9B_P00_10_IN;  /**< \brief Receive input channel 9 */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT9C_P33_1_IN;  /**< \brief Receive input channel 9 */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC0_P00_1_OUT;  /**< \brief Transmit output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC1_P02_7_OUT;  /**< \brief Transmit output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC2_P00_3_OUT;  /**< \brief Transmit output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC3_P00_4_OUT;  /**< \brief Transmit output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC4_P00_5_OUT;  /**< \brief Transmit output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC5_P00_6_OUT;  /**< \brief Transmit output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC6_P00_7_OUT;  /**< \brief Transmit output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC7_P00_8_OUT;  /**< \brief Transmit output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC8_P00_9_OUT;  /**< \brief Transmit output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC9_P00_10_OUT;  /**< \brief Transmit output */

/** \brief Table dimensions */
#define IFXSENT_PINMAP_NUM_MODULES 1
#define IFXSENT_PINMAP_NUM_CHANNELS 15
#define IFXSENT_PINMAP_SENT_IN_NUM_ITEMS 4
#define IFXSENT_PINMAP_SPC_OUT_NUM_ITEMS 1


/** \brief IfxSent_Sent_In table */
IFX_EXTERN const IfxSent_Sent_In *IfxSent_Sent_In_pinTable[IFXSENT_PINMAP_NUM_MODULES][IFXSENT_PINMAP_NUM_CHANNELS][IFXSENT_PINMAP_SENT_IN_NUM_ITEMS];

/** \brief IfxSent_Spc_Out table */
IFX_EXTERN const IfxSent_Spc_Out *IfxSent_Spc_Out_pinTable[IFXSENT_PINMAP_NUM_MODULES][IFXSENT_PINMAP_NUM_CHANNELS][IFXSENT_PINMAP_SPC_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXSENT_PINMAP_TC37X_516_H */
