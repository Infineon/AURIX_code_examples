/**
 * \file Ifx_Assert.h
 * \brief Assert functions.
 * \ingroup library_srvsw_utilities_assert
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-28 14:15:42 GMT$
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup library_srvsw_utilities_assert Assertion
 * This module implements assertion functions.
 * \ingroup library_srvsw_utilities
 *
 */

#ifndef IFX_ASSERT_H
#define IFX_ASSERT_H 1

#include "Ifx_Cfg.h"                           /* Do not remove this include */
#include "Cpu/Std/Ifx_Types.h"                 /* Do not remove this include */

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
