/**
 * \file CompilerMw.h
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
 */

#ifndef COMPILERMW_H
#define COMPILERMW_H 1

/******************************************************************************/

#include <stddef.h>

/*Linker definitions which are specific to Mw */

/******************************************************************************/
#ifndef IFX_INLINE
#define IFX_INLINE         static inline __attribute__ ((always_inline))            /*Makes the function always inlined */
#endif

#define IFX_PACKED         __attribute__ ((packed))

#define COMPILER_NAME      "MW"
#define COMPILER_VERSION   __VERSION__

#define COMPILER_REVISION  0

/******************************************************************************/

#define IFX_ALIGN(n) __attribute__ ((aligned(n)))

/******************************************************************************/
/* Workaround for MW Blunders */
#define IFX_STORE_ECR_VALUE ECR
#undef ECR

#define IFX_STORE_STATUS_VALUE STATUS
#undef STATUS

#endif /* COMPILERMW_H */
