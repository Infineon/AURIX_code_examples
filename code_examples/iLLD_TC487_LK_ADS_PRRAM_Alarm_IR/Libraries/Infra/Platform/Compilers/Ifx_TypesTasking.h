/**
 * \file Ifx_TypesTasking.h
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
#ifndef IFX_TYPESTASKING_H
#define IFX_TYPESTASKING_H 1
/******************************************************************************/
#ifdef __CTC__
#define fract   __fract             //  see http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1169.pdf
#define sfract  __sfract            //  see http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1169.pdf
#define laccum  __laccum
#define __asm__ __asm
#endif
/******************************************************************************/

#ifdef __CARC__
#undef fract
#undef sfract
#undef laccum
typedef long          fract;
typedef short         sfract;
typedef long long     laccum;
#define __asm__ __asm
#endif
/******************************************************************************/

#endif /* IFX_TYPESTASKING_H_ */
