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

#ifndef IFXSCRWCAN_CFG_H
#define IFXSCRWCAN_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h" //For AgenTiX

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief WCAN baudrates
 */

#define IfxScrWcan_Baudrate_1Mbps      0
#define IfxScrWcan_Baudrate_500kbps    1
#define IfxScrWcan_Baudrate_250kbps    2
#define IfxScrWcan_Baudrate_125kbps    3

/** \brief WCAN  version
 */

#define IfxScrWcan_CanVersion_standard 0
#define IfxScrWcan_CanVersion_extended 1

#endif /* IFXSCRWCAN_CFG_H */
