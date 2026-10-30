/**
 * \file IfxDmu_PinMap_TC37x_516.h
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

#ifndef IFXDMU_PINMAP_TC37X_516_H
#define IFXDMU_PINMAP_TC37X_516_H 1

#include <IfxDmu_reg.h>
#include <Port/Std/IfxPort.h>
#include "Ifx_PinMap.h"

/** \addtogroup IfxLld_Dmu_pinmap
 * \{ */

/** \brief DMU FDEST pin mapping structure */
typedef const struct
{
    Ifx_DMU*         module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         select;    /**< \brief Input multiplexer value */
} IfxDmu_Fdest_In;


IFX_EXTERN IfxDmu_Fdest_In IfxDmu_FDEST_P21_0_IN;  /**< \brief Enter destructive debug mode */

/** \brief Table dimensions */
#define IFXDMU_PINMAP_NUM_MODULES 1
#define IFXDMU_PINMAP_NUM_0S 1
#define IFXDMU_PINMAP_FDEST_IN_NUM_ITEMS 1


/** \brief IfxDmu_Fdest_In table */
IFX_EXTERN const IfxDmu_Fdest_In *IfxDmu_Fdest_In_pinTable[IFXDMU_PINMAP_NUM_MODULES][IFXDMU_PINMAP_NUM_0S][IFXDMU_PINMAP_FDEST_IN_NUM_ITEMS];

/** \} */

#endif /* IFXDMU_PINMAP_TC37X_516_H */
