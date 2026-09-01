/**
 * \file Ifx_Ssw_Compilers.h
 * \brief Startup Software for compiler options
 *
 * \version iLLD-TC4-v2.6.0
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
 */

#ifndef IFX_SSW_COMPILERS_H
#define IFX_SSW_COMPILERS_H 1

/*Macro definition to show HighTec macros with the editor*/
#if ((!defined(__ghs__)) && (!defined(__DCC__)) && (!defined(__TASKING__)) && (!defined(__GNUC__)))
#define __HIGHTEC__
#define __clang__
#endif

/*Include files for each compiler*/
#if defined(__TASKING__)
#include "Ifx_Ssw_CompilersTasking.h"

#elif defined(__DCC__)
#include "Ifx_Ssw_CompilersWindriver.h"

#elif defined(__HIGHTEC__) && !defined(__clang__)
#include "Ifx_Ssw_CompilersGnuc.h"

#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#include "Ifx_Ssw_CompilersGcc.h"

#elif defined(__HIGHTEC__) && defined(__clang__)
#include "Ifx_Ssw_CompilersHighTec.h"

#elif defined(__ghs__)
#include "Ifx_Ssw_CompilersGhs.h"
#endif

#define IFX_SSW_USED __attribute__((used))

#ifndef NULL_PTR
#ifdef __cplusplus
#define NULL_PTR        (0)
#else /*#ifdef __cplusplus */
#define NULL_PTR        ((void *)0)
#endif /*#ifdef __cplusplus */
#endif /*#ifndef NULL_PTR */

#endif /* IFX_SSW_COMPILERS_H */
