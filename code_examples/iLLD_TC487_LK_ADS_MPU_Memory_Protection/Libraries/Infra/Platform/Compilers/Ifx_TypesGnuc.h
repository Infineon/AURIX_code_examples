/**
 * \file Ifx_TypesGnuc.h
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
#ifndef IFX_TYPESGNUC_H
#define IFX_TYPESGNUC_H 1
/******************************************************************************/
#define FRACT_MAX 0x7fffffff

#include <machine/cint.h>
#define __interrupt(intno)

typedef long          fract;
typedef short         sfract;
typedef long long     laccum;
typedef long          __packb;   //MSMRK should be struct of four chars
typedef unsigned long __upackb;  //MSMRK should be struct of four unsigned chars
typedef long          __packhw;  //MSMRK should be struct of two shorts
typedef unsigned long __upackhw; //MSMRK should be struct of two unsigned shorts
/******************************************************************************/

#endif /* IFX_TYPESGNUC_H_ */
