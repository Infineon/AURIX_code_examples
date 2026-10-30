/**
 * \file IfxLli_reg.h
 * \brief
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: MC_ACE_A3G_HSI_LLI/V0.2.1.1.5
 * Specification: latest @ 2024-03-02 instance sheet @ MC_A3G_HWDDSOC_FUNCTIONAL_INSTANCE_SHEET/V13.2.1.1.0
 * MAY BE CHANGED BY USER [yes/no]: No
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
 * \defgroup IfxSfr_Lli_Registers_Cfg Lli address
 * \ingroup IfxSfr_Lli_Registers
 * 
 * \defgroup IfxSfr_Lli_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Lli_Registers_Cfg
 *
 * \defgroup IfxSfr_Lli_Registers_Cfg_Lli0 2-LLI0
 * \ingroup IfxSfr_Lli_Registers_Cfg
 *
 *
 */
#ifndef IFXLLI_REG_H
#define IFXLLI_REG_H 1
/******************************************************************************/
#include "IfxLli_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Lli_Registers_Cfg_BaseAddress
 * \{  */

/** \brief LLI object */
#define MODULE_LLI0 /*lint --e(923, 9078)*/ ((*(Ifx_LLI*)0xF9900000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Lli_Registers_Cfg_Lli0
 * \{  */
/** \brief 8, Identification register */
#define LLI0_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_ID*)0xF9900008u)

/** \brief C, Alarm event */
#define LLI0_ALEV /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_ALEV*)0xF990000Cu)

/** \brief 10, Alarm clear */
#define LLI0_ALCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_ALCLR*)0xF9900010u)

/** \brief 14, Error injection from S2L master interface */
#define LLI0_MEGEN /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_MEGEN*)0xF9900014u)

/** \brief 18, Error injection from PPU.SFR slave interface */
#define LLI0_SEGEN /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_SEGEN*)0xF9900018u)

/** \brief 1C, Resource protection register */
#define LLI0_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_PROT*)0xF990001Cu)

/** \brief 20, Write access enable register A */
#define LLI0_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_ACCEN_WRA*)0xF9900020u)

/** \brief 24, Write access enable register B */
#define LLI0_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_ACCEN_WRB*)0xF9900024u)

/** \brief 28, Read access enable register A */
#define LLI0_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_ACCEN_RDA*)0xF9900028u)

/** \brief 2C, Read access enable register B */
#define LLI0_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_ACCEN_RDB*)0xF990002Cu)

/** \brief 30, VM access enable register */
#define LLI0_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_ACCEN_VM*)0xF9900030u)

/** \brief 34, PRS access enable register */
#define LLI0_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_LLI_ACCEN_PRS*)0xF9900034u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXLLI_REG_H */
