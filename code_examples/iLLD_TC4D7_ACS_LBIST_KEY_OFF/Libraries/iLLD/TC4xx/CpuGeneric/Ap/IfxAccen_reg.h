/**
 * \file IfxAccen_reg.h
 * \brief
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * MAY BE CHANGED BY USER [yes/no]: Yes
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
 * \defgroup IfxSfr_Accen_Registers_Cfg Accen address
 * \ingroup IfxSfr_Accen_Registers
 * 
 * \defgroup IfxSfr_Accen_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Accen_Registers_Cfg
 *
 * \defgroup IfxSfr_Accen_Registers_Cfg_Accen 2-ACCEN
 * \ingroup IfxSfr_Accen_Registers_Cfg
 *
 *
 */
#ifndef IFXACCEN_REG_H
#define IFXACCEN_REG_H 1
/******************************************************************************/
#include "IfxAccen_regdef.h"
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Accen_Registers_Cfg_BaseAddress
 * \{  */

/** \brief ACCEN object */
#define MODULE_ACCEN /*lint --e(923, 9078)*/ ((*(Ifx_ACCEN*)0x0u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Accen_Registers_Cfg_Accen
 * \{  */
/** \brief 0, Write access enable register A */
#define ACCEN_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_ACCEN_ACCEN_WRA*)0x0u)

/** \brief 4, Write access enable register B */
#define ACCEN_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_ACCEN_ACCEN_WRB_SRI*)0x4u)

/** \brief 8, Read access enable register A */
#define ACCEN_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_ACCEN_ACCEN_RDA*)0x8u)

/** \brief C, Read access enable register B */
#define ACCEN_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_ACCEN_ACCEN_RDB_SRI*)0xCu)

/** \brief 10, VM access enable register */
#define ACCEN_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_ACCEN_ACCEN_VM*)0x10u)

/** \brief 14, PRS access enable register */
#define ACCEN_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_ACCEN_ACCEN_PRS*)0x14u)

/** \brief 18, Region lower address register */
#define ACCEN_ACCEN_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_ACCEN_ACCEN_RGNLA*)0x18u)

/** \brief 1C, Region upper address register */
#define ACCEN_ACCEN_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_ACCEN_ACCEN_RGNUA*)0x1Cu)


/** \}  */

/******************************************************************************/
/******************************************************************************/
#endif /* IFXACCEN_REG_H */
