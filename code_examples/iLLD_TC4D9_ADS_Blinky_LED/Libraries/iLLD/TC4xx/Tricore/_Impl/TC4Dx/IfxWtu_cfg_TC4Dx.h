/**
 * \file IfxWtu_cfg_TC4Dx.h
 * \brief WTU on-chip implementation data
 * \ingroup IfxLld_Wtu
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
 * \defgroup IfxLld_Wtu WTU
 * \ingroup IfxLld
 * \defgroup IfxLld_Wtu_Impl Implementation
 * \ingroup IfxLld_Wtu
 * \defgroup IfxLld_Wtu_Std Standard Driver
 * \ingroup IfxLld_Wtu
 */

#ifndef IFXWTU_CFG_TC4DX_H
#define IFXWTU_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Input frequency request control
 */
typedef enum
{
    IfxWtu_IFSR_divBy16384 = 0,  /**< \brief frequency is System Peripheral Bus frequency divide by 16384 */
    IfxWtu_IFSR_divBy256   = 1,  /**< \brief frequency is System Peripheral Bus frequency divide by 256 */
    IfxWtu_IFSR_divBy64    = 2   /**< \brief frequency is System Peripheral Bus frequency divide by 64 */
} IfxWtu_IFSR;

#endif /* IFXWTU_CFG_TC4DX_H */
