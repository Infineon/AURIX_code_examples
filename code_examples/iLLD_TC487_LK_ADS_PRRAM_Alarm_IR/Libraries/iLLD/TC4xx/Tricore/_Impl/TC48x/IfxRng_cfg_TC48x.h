/**
 * \file IfxRng_cfg_TC48x.h
 * \brief RNG on-chip implementation data
 * \ingroup IfxLld_Rng
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
 * \defgroup IfxLld_Rng RNG
 * \ingroup IfxLld
 * \defgroup IfxLld_Rng_Impl Implementation
 * \ingroup IfxLld_Rng
 * \defgroup IfxLld_Rng_Std Standard Driver
 * \ingroup IfxLld_Rng
 */

#ifndef IFXRNG_CFG_TC48X_H
#define IFXRNG_CFG_TC48X_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief COunter for timeout
 */
#define IFXRNG_TIMEOUT_COUNT ((uint32)2000)

/** \brief Initialize the PROT and APU of RNG Module
 */
#define IFXRNG_INIT_AP    (TRUE)

#endif /* IFXRNG_CFG_TC48X_H */
