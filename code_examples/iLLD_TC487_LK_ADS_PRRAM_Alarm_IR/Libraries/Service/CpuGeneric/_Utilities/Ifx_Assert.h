/**
 * \file Ifx_Assert.h
 * \brief Assert functions.
 * \ingroup library_srvsw_utilities_assert
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
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
 * \defgroup library_srvsw_utilities_assert Assertion
 * This module implements assertion functions.
 * \ingroup library_srvsw_utilities
 *
 */

#ifndef IFX_ASSERT_H
#define IFX_ASSERT_H 1

#include "Ifx_Cfg.h"                           /* Do not remove this include */
#include "Ifx_Types.h"                 /* Do not remove this include */

/** \addtogroup library_srvsw_utilities_assert
 * \{ */

#define IFX_VERBOSE_LEVEL_OFF              (0) /**< \brief Assertion level off, assertion is disabled */
#define IFX_VERBOSE_LEVEL_FAILURE          (1) /**< \brief Assertion level failure, a debug instruction is inserted if enabled */
#define IFX_VERBOSE_LEVEL_ERROR            (2) /**< \brief Assertion level error, a debug instruction is inserted if enabled */
#define IFX_VERBOSE_LEVEL_WARNING          (3) /**< \brief Assertion level warning */
#define IFX_VERBOSE_LEVEL_INFO             (4) /**< \brief Assertion level info */
#define IFX_VERBOSE_LEVEL_DEBUG            (5) /**< \brief Assertion level debug */

/** \brief Constant to be used to indicate  not implemented feature */
#define IFX_ASSERT_FEATURE_NOT_IMPLEMENTED (FALSE)
/** \brief Feature is not available on the selected hardware */
#define IFX_ASSERT_FEATURE_NOT_AVAILABLE   (FALSE)

#ifndef IFX_ASSERT
#    define IFX_ASSERT(level, expr)   ((void)0)
#endif

#ifndef IFX_VALIDATE
#    define IFX_VALIDATE(level, expr) (expr)
#endif

#ifdef IFX_CFG_ASSERT_INCLUDE
/** Configuration switch: IFX_CFG_ASSERT_INCLUDE
 * This switch is used to enable user defined assertion implementation.
 * A usage exmaple is given below:
 *
 * \code
 * // File "Ifx_Cfg.h"
 * #define IFX_CFG_ASSERT_INCLUDE  "SysSe/Bsp/Assert.h"
 * \endcode
 */
#include IFX_CFG_ASSERT_INCLUDE
#endif
/** \} */

#endif
