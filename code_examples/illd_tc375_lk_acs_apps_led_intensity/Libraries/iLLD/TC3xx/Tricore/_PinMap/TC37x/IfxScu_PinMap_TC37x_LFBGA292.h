/**
 * \file IfxScu_PinMap_TC37x_LFBGA292.h
 * \brief SCU I/O map
 * \ingroup IfxLld_Scu
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
 * \defgroup IfxLld_Scu_pinmap SCU Pin Mapping
 * \ingroup IfxLld_Scu
 */

#ifndef IFXSCU_PINMAP_TC37X_LFBGA292_H
#define IFXSCU_PINMAP_TC37X_LFBGA292_H 1

#include <IfxScu_reg.h>
#include <_Impl/IfxScu_cfg.h>
#include <Port/Std/IfxPort.h>
#include "Ifx_PinMap.h"

/** \addtogroup IfxLld_Scu_pinmap
 * \{ */

/** \brief EVR Wakeup pin mapping structure */
typedef const struct
{
    Ifx_SCU*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         select;    /**< \brief Input multiplexer value */
} IfxScu_Evrwup_In;

/** \brief External Request pin mapping structure */
typedef const struct
{
    Ifx_SCU*          module;    /**< \brief Base address */
    uint8             channelId; /**< \brief ERU Channel ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         select;    /**< \brief Input multiplexer value */
} IfxScu_Req_In;

/** \brief DCDC Sync pin mapping structure */
typedef const struct
{
    Ifx_SCU*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxScu_Dcdcsync_Out;

/** \brief Emergency Stop pin mapping structure */
typedef const struct
{
    Ifx_SCU*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         select;    /**< \brief Input multiplexer value */
} IfxScu_Emgstop_In;

/** \brief Watchdog Timer Lock pin mapping structure */
typedef const struct
{
    Ifx_SCU*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxScu_Wdtlck_Out;

/** \brief External Clock pin mapping structure */
typedef const struct
{
    Ifx_SCU*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxScu_Extclk_Out;

IFX_EXTERN IfxScu_Emgstop_In IfxScu_EMGSTOPA_P33_8_IN;  /**< \brief Emergency stop Port Pin A input request */
IFX_EXTERN IfxScu_Emgstop_In IfxScu_EMGSTOPB_P21_2_IN;  /**< \brief Emergency stop Port Pin B input request */
IFX_EXTERN IfxScu_Extclk_Out IfxScu_EXTCLK0_P23_1_OUT;  /**< \brief External Clock 0 */
IFX_EXTERN IfxScu_Extclk_Out IfxScu_EXTCLK1_P11_12_OUT;  /**< \brief External Clock 1 */
IFX_EXTERN IfxScu_Extclk_Out IfxScu_EXTCLK1_P32_4_OUT;  /**< \brief External Clock 1 */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ0A_P15_4_IN;  /**< \brief ERU Channel 0 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ0C_P10_7_IN;  /**< \brief ERU Channel 0 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ1A_P14_3_IN;  /**< \brief ERU Channel 1 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ1C_P10_8_IN;  /**< \brief ERU Channel 1 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ2A_P10_2_IN;  /**< \brief ERU Channel 2 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ2B_P02_1_IN;  /**< \brief ERU Channel 2 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ2C_P00_4_IN;  /**< \brief ERU Channel 2 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ3A_P10_3_IN;  /**< \brief ERU Channel 3 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ3B_P14_1_IN;  /**< \brief ERU Channel 3 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ3C_P02_0_IN;  /**< \brief ERU Channel 3 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ4A_P33_7_IN;  /**< \brief ERU Channel 4 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ4D_P15_5_IN;  /**< \brief ERU Channel 4 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ5A_P15_8_IN;  /**< \brief ERU Channel 5 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ6A_P20_0_IN;  /**< \brief ERU Channel 6 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ6D_P11_10_IN;  /**< \brief ERU Channel 6 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ7A_P20_9_IN;  /**< \brief ERU Channel 7 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */
IFX_EXTERN IfxScu_Req_In IfxScu_REQ7C_P15_1_IN;  /**< \brief ERU Channel 7 inputs 0 to 5 (0 is the LSB and 5 is the MSB) */

/** \brief Table dimensions */
#define IFXSCU_PINMAP_NUM_MODULES 1
#define IFXSCU_PINMAP_NUM_REQUESTS 8
#define IFXSCU_PINMAP_EMGSTOP_IN_NUM_ITEMS 2
#define IFXSCU_PINMAP_EXTCLK_OUT_NUM_ITEMS 3
#define IFXSCU_PINMAP_REQ_IN_NUM_ITEMS 4


/** \brief IfxScu_Emgstop_In table */
IFX_EXTERN const IfxScu_Emgstop_In *IfxScu_Emgstop_In_pinTable[IFXSCU_PINMAP_NUM_MODULES][IFXSCU_PINMAP_EMGSTOP_IN_NUM_ITEMS];

/** \brief IfxScu_Extclk_Out table */
IFX_EXTERN const IfxScu_Extclk_Out *IfxScu_Extclk_Out_pinTable[IFXSCU_PINMAP_NUM_MODULES][IFXSCU_PINMAP_EXTCLK_OUT_NUM_ITEMS];

/** \brief IfxScu_Req_In table */
IFX_EXTERN const IfxScu_Req_In *IfxScu_Req_In_pinTable[IFXSCU_PINMAP_NUM_MODULES][IFXSCU_PINMAP_NUM_REQUESTS][IFXSCU_PINMAP_REQ_IN_NUM_ITEMS];

/** \} */

#endif /* IFXSCU_PINMAP_TC37X_LFBGA292_H */
