/**
 * \file IfxSrc_cfg_TC37x.h
 * \brief SRC on-chip implementation data
 * \ingroup IfxLld_Src
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
 * \defgroup IfxLld_Src SRC
 * \ingroup IfxLld
 * \defgroup IfxLld_Src_Impl Implementation
 * \ingroup IfxLld_Src
 * \defgroup IfxLld_Src_Std Standard Driver
 * \ingroup IfxLld_Src
 * \defgroup IfxLld_Src_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Src_Impl
 */

#ifndef IFXSRC_CFG_TC37X_H
#define IFXSRC_CFG_TC37X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Src_Impl_Enumerations
 * \{ */
/** \brief Identifier of interrupt service provider, which handles the interrupt service request.
 */
typedef enum
{
    IfxSrc_Tos_cpu0 = 0,  /**< \brief CPU0 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_dma  = 1,  /**< \brief DMA interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_cpu1 = 2,  /**< \brief CPU1 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_cpu2 = 3  /**< \brief CPU2 interrupt service provider, which handles the interrupt service request. */
} IfxSrc_Tos;

/** \} */

#endif /* IFXSRC_CFG_TC37X_H */
