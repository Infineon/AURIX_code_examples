/**
 * \file IfxScrSsc_cfg.h
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
 * \defgroup IfxLld_Scr SCR
 * \ingroup IfxLld_Scr
 */

#ifndef IFXSCRSSC_CFG_H
#define IFXSCRSSC_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h" //For AgenTiX

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief SSC modes - Master and Slave
 *
 * */

#define IfxScrSsc_Mode_slave                     0
#define IfxScrSsc_Mode_master                    1

/** \brief Tx data orientation - MSB first and LSB first
 *
 * */

#define IfxScrSsc_dataOrientation_lsbFirst       0
#define IfxScrSsc_dataOrientation_msbFirst       1

/** \brief SSC clock phase
 *
 * */

#define IfxScrSsc_ClockPhase_latchOnTrailingEdge 0 /* Shift transmit data on the leading
                                                    * clock edge, latch on trailing edge. */
#define IfxScrSsc_ClockPhase_latchOnLeadingEdge  1 /* Latch receive data on leading clock
                                                    * edge, shift on trailing edge */

/** \brief SSC clock phase
 *
 * */

#define IfxScrSsc_ClockPolarity_idleLow          0 /* Idle clock line is low, leading clock edge is low-to-high
                                                    * transition. */
#define IfxScrSsc_ClockPolarity_idleHigh         1 /* Idle clock line is high, leading clock edge is high-to-low
                                                    * transition. */

#endif /* IFXSCRSSC_CFG_H */
