/**
 * \file IfxPpu_IntrinsicsMw.h
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
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
 * \defgroup IfxLld_Cpu_Intrinsics_HighTec Intrinsics for HighTec compiler
 * \ingroup IfxLld_Cpu_Intrinsics
 *
 */

#ifndef IFXPPU_INTRINSICSMW_H
#define IFXPPU_INTRINSICSMW_H 1

/******************************************************************************/
#include "Ifx_Types.h"

#define __minu(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define __maxu(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define __absf(X)                       ( ((X) < 0.0) ? -(X) : (X) )
#define __min(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define __max(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )

#define __roundf(X)                     ((((X) - (sint32)(X)) > 0.5) ? (1 + (sint32)(X)) : ((sint32)(X)))
#define Ifx__abs(X)                       ( ((X) < 0) ? -(X) : (X) )
#define __nop() 						_nop() 

#endif /* IFXPPU_INTRINSICSMW_H */
