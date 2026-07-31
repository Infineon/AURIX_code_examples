/**
 * \file IfxAsclin_cfg_TC4Dx.h
 * \brief ASCLIN on-chip implementation data
 * \ingroup IfxLld_Asclin
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
 * \defgroup IfxLld_Asclin ASCLIN
 * \ingroup IfxLld
 * \defgroup IfxLld_Asclin_Impl Implementation
 * \ingroup IfxLld_Asclin
 * \defgroup IfxLld_Asclin_Std Standard Driver
 * \ingroup IfxLld_Asclin
 * \defgroup IfxLld_Asclin_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Asclin_Impl
 */

#ifndef IFXASCLIN_CFG_TC4DX_H
#define IFXASCLIN_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxAsclin_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Modules
 */
#define IFXASCLIN_NUM_MODULES (28)

/** \brief Availability of ASCLIN SPI Data Width 32 bits
 */
#define IFXASCLIN_SPI_IS_DATAWIDTH32_AVAILABLE  (FALSE)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Asclin_Impl_Enumerations
 * \{ */
/** \brief List of the available Asclin resources
 */
typedef enum
{
    IfxAsclin_Index_none = -1,  /**< \brief Not Selected */
    IfxAsclin_Index_0    = 0,   /**< \brief ASCLIN Index 0  */
    IfxAsclin_Index_1,          /**< \brief ASCLIN Index 1  */
    IfxAsclin_Index_2,          /**< \brief ASCLIN Index 2  */
    IfxAsclin_Index_3,          /**< \brief ASCLIN Index 3  */
    IfxAsclin_Index_4,          /**< \brief ASCLIN Index 4  */
    IfxAsclin_Index_5,          /**< \brief ASCLIN Index 5  */
    IfxAsclin_Index_6,          /**< \brief ASCLIN Index 6  */
    IfxAsclin_Index_7,          /**< \brief ASCLIN Index 7  */
    IfxAsclin_Index_8,          /**< \brief ASCLIN Index 8  */
    IfxAsclin_Index_9,          /**< \brief ASCLIN Index 9  */
    IfxAsclin_Index_10,         /**< \brief ASCLIN Index 10  */
    IfxAsclin_Index_11,         /**< \brief ASCLIN Index 11  */
    IfxAsclin_Index_12,         /**< \brief ASCLIN Index 12  */
    IfxAsclin_Index_13,         /**< \brief ASCLIN Index 13  */
    IfxAsclin_Index_14,         /**< \brief ASCLIN Index 14  */
    IfxAsclin_Index_15,         /**< \brief ASCLIN Index 15  */
    IfxAsclin_Index_16,         /**< \brief ASCLIN Index 16  */
    IfxAsclin_Index_17,         /**< \brief ASCLIN Index 17  */
    IfxAsclin_Index_18,         /**< \brief ASCLIN Index 18  */
    IfxAsclin_Index_19,         /**< \brief ASCLIN Index 19  */
    IfxAsclin_Index_20,         /**< \brief ASCLIN Index 20  */
    IfxAsclin_Index_21,         /**< \brief ASCLIN Index 21  */
    IfxAsclin_Index_22,         /**< \brief ASCLIN Index 22  */
    IfxAsclin_Index_23,         /**< \brief ASCLIN Index 23  */
    IfxAsclin_Index_24,         /**< \brief ASCLIN Index 24  */
    IfxAsclin_Index_25,         /**< \brief ASCLIN Index 25  */
    IfxAsclin_Index_26,         /**< \brief ASCLIN Index 26  */
    IfxAsclin_Index_27          /**< \brief ASCLIN Index 27  */
} IfxAsclin_Index;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxAsclin_cfg_indexMap[IFXASCLIN_NUM_MODULES];
/******************************************************************************/

#endif /* IFXASCLIN_CFG_TC4DX_H */
