/**
 * \file IfxScrTimer01_cfg.h
 * \brief PORT on-chip implementation data
 * \ingroup IfxLld_Scr
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
 * \defgroup IfxLld_ScrTimer01 SCRTIMER01
 * \ingroup IfxLld_Scr
 */

#ifndef IFXSCRTIMER01_CFG_H
#define IFXSCRTIMER01_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h" //For AgenTiX

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Clock sources for Timer 0 and Timer 1
 */

#define IfxScrTimer01_ClockSource_pclk  0U /* Clock source is derived from PCLK */
#define IfxScrTimer01_ClockSource_t0    1U /* Clock source is T0 pin*/
#define IfxScrTimer01_ClockSource_t1    1U /* Clock source is T1 pin*/

/** \brief Run Control for Timer 0 and Timer 1
 */

#define IfxScrTimer01_RunControl_swOnly 0U /* Run control(start and stop) from TMOD.TRx bitfield only */
#define IfxScrTimer01_RunControl_hw     1U /* Run control(start and stop) from EXINTx pin with TMOD.TRx = 1 */

#endif /* IFXSCRTIMER01_CFG_H */
