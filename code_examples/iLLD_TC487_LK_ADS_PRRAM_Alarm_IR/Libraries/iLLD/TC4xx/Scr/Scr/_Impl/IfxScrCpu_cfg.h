/**
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 * \ingroup IfxLld_Scr
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
 * \defgroup IfxLld_Scr SCR
 * \ingroup IfxLld_Scr
 */

#ifndef IFXSCRCPU_CFG_H
#define IFXSCRCPU_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h" //For AgenTiX

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

# define IFX_SCR_NMI                   14
# define IFX_SCR_TIMER_0               1
# define IFX_SCR_TIMER_1               3
# define IFX_SCR_UART                  4
# define IFX_SCR_T2CCU                 5
# define IFX_SCR_LIN                   5
# define IFX_SCR_WCAN                  6
# define IFX_SCR_ADC                   7
# define IFX_SCR_SSC                   7
# define IFX_SCR_RTC                   13
# define IFX_SCR_EXTERNAL_INTERRUPT_0  0
# define IFX_SCR_EXTERNAL_INTERRUPT_1  2
# define IFX_SCR_EXTERNAL_INTERRUPT_2  8
# define IFX_SCR_EXTERNAL_INTERRUPT_3  9
# define IFX_SCR_EXTERNAL_INTERRUPT_4  9
# define IFX_SCR_EXTERNAL_INTERRUPT_5  9
# define IFX_SCR_EXTERNAL_INTERRUPT_6  9
# define IFX_SCR_EXTERNAL_INTERRUPT_7  10
# define IFX_SCR_EXTERNAL_INTERRUPT_8  10
# define IFX_SCR_EXTERNAL_INTERRUPT_9  10
# define IFX_SCR_EXTERNAL_INTERRUPT_10 11
# define IFX_SCR_EXTERNAL_INTERRUPT_11 11
# define IFX_SCR_EXTERNAL_INTERRUPT_12 11
# define IFX_SCR_EXTERNAL_INTERRUPT_13 12
# define IFX_SCR_EXTERNAL_INTERRUPT_14 12
# define IFX_SCR_EXTERNAL_INTERRUPT_15 12

#endif /* IFXSCRCPU_CFG_H */
