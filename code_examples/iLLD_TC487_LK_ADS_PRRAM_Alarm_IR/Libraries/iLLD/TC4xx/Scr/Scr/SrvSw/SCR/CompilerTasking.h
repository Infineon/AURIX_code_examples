/**
 * \file CompilerTasking.h
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

#ifndef COMPILERTASKING_H
#define COMPILERTASKING_H 1

/******************************************************************************/
//#define IFX_INLINE static	//Added for debug purpose

#ifndef IFX_INLINE
//#define IFX_INLINE _inline //for AgenTiX Tasking
#define IFX_INLINE    static inline
#endif

#ifndef IFX_REENTRANT
#define IFX_REENTRANT __reentrant
#endif

/******************************************************************************/
//for v6.2r1 it's the vectorAddress that has to be put instead of vectorNumber
#ifndef IFX_INTERRUPT
#define IFX_INTERRUPT(isr, vectorNumber) _interrupt(vectorNumber) void isr()
#endif

/******************************************************************************/

#endif /* COMPILERTASKING_H */
