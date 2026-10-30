/**
 * \file IfxHssl_cfg_TC37x.h
 * \brief HSSL on-chip implementation data
 * \ingroup IfxLld_Hssl
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
 * \defgroup IfxLld_Hssl HSSL
 * \ingroup IfxLld
 * \defgroup IfxLld_Hssl_Impl Implementation
 * \ingroup IfxLld_Hssl
 * \defgroup IfxLld_Hssl_Std Standard Driver
 * \ingroup IfxLld_Hssl
 * \defgroup IfxLld_Hssl_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Hssl_Impl
 */

#ifndef IFXHSSL_CFG_TC37X_H
#define IFXHSSL_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxHssl_reg.h"
#include "IfxHsct_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXHSSL_NUM_CHANNELS    4

#define IFXHSSL_NUM_MODULES     1

#define IFXHSSL_JTAG_ID_ADDRESS (0xF0000464u)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Hssl_Impl_Enumerations
 * \{ */
/** \brief List of the available Hsct resources
 */
typedef enum
{
    IfxHssl_hsctIndex_none = -1,  /**< \brief Not Selected */
    IfxHssl_hsctIndex_0    = 0   /**< \brief HSCT index 0  */
} IfxHssl_hsctIndex;

/** \brief List of the available Hssl resources
 */
typedef enum
{
    IfxHssl_hsslIndex_none = -1,  /**< \brief Not Selected */
    IfxHssl_hsslIndex_0    = 0   /**< \brief HSSL index 0  */
} IfxHssl_hsslIndex;

/** \} */

/** \addtogroup IfxLld_Hssl_Impl_Enumerations
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxHssl_cfg_hsctIndexMap[IFXHSSL_NUM_MODULES];

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxHssl_cfg_hsslIndexMap[IFXHSSL_NUM_MODULES];

/** \} */

#endif /* IFXHSSL_CFG_TC37X_H */
