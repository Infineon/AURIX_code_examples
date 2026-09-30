/**
 * \file IfxProt_reg.h
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
 * \defgroup IfxSfr_Prot_Registers_Cfg Prot address
 * \ingroup IfxSfr_Prot_Registers
 * 
 * \defgroup IfxSfr_Prot_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Prot_Registers_Cfg
 *
 * \defgroup IfxSfr_Prot_Registers_Cfg_Prot 2-PROT
 * \ingroup IfxSfr_Prot_Registers_Cfg
 *
 *
 */
#ifndef IFXPROT_REG_H
#define IFXPROT_REG_H 1
/******************************************************************************/
#include "IfxProt_regdef.h"
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Prot_Registers_Cfg_BaseAddress
 * \{  */

/** \brief PROT object */
#define MODULE_PROT /*lint --e(923, 9078)*/ ((*(Ifx_PROT*)0x0u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Prot_Registers_Cfg_Prot
 * \{  */
/** \brief 0, Resource Protection Register */
#define PROT_PROT /*lint --e(923, 9078)*/ (*(volatile Ifx_PROT_PROT*)0x0u)


/** \}  */

/******************************************************************************/
/******************************************************************************/
#endif /* IFXPROT_REG_H */
