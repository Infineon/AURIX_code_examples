/**
 * \file IfxVtmon_reg.h
 * \brief
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: MC_ACE_A3G_HSI_VTMON/V5.1.1.1.0
 * Specification: latest @ 2025-12-10 instance sheet @ MC_A3G_HWDDSOC_FUNCTIONAL_INSTANCE_SHEET/V8.2.1.2.1
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
 * \defgroup IfxSfr_Vtmon_Registers_Cfg Vtmon address
 * \ingroup IfxSfr_Vtmon_Registers
 * 
 * \defgroup IfxSfr_Vtmon_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Vtmon_Registers_Cfg
 *
 * \defgroup IfxSfr_Vtmon_Registers_Cfg_Vtmon 2-VTMON
 * \ingroup IfxSfr_Vtmon_Registers_Cfg
 *
 *
 */
#ifndef IFXVTMON_REG_H
#define IFXVTMON_REG_H 1
/******************************************************************************/
#include "IfxVtmon_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Vtmon_Registers_Cfg_BaseAddress
 * \{  */

/** \brief VTMON object */
#define MODULE_VTMON /*lint --e(923, 9078)*/ ((*(Ifx_VTMON*)0xF006C000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Vtmon_Registers_Cfg_Vtmon
 * \{  */
/** \brief 0, Clock Control Register */
#define VTMON_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_CLC*)0xF006C000u)

/** \brief 4, OCDS Control and Status Register */
#define VTMON_OCS /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_OCS*)0xF006C004u)

/** \brief 8, Module Identification Register */
#define VTMON_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_ID*)0xF006C008u)

/** \brief C, Reset Control Register A */
#define VTMON_RST_CTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_RST_CTRLA*)0xF006C00Cu)

/** \brief 10, Reset Control Register B */
#define VTMON_RST_CTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_RST_CTRLB*)0xF006C010u)

/** \brief 14, Reset Status Register */
#define VTMON_RST_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_RST_STAT*)0xF006C014u)

/** \brief 20, PROT Register Endinit */
#define VTMON_PROTE /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_PROT*)0xF006C020u)

/** \brief 24, PROT Register Safe Endinit */
#define VTMON_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_PROT*)0xF006C024u)

/** \brief 40, Write access enable register A */
#define VTMON_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_ACCEN_WRA*)0xF006C040u)

/** \brief 44, Write access enable register B */
#define VTMON_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_ACCEN_WRB_FPI*)0xF006C044u)

/** \brief 48, Read access enable register A */
#define VTMON_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_ACCEN_RDA*)0xF006C048u)

/** \brief 4C, Read access enable register B */
#define VTMON_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_ACCEN_RDB_FPI*)0xF006C04Cu)

/** \brief 50, VM access enable register */
#define VTMON_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_ACCEN_VM*)0xF006C050u)

/** \brief 54, PRS access enable register */
#define VTMON_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_ACCEN_PRS*)0xF006C054u)

/** \brief 60, Die Temperature Sensor 0 Control Register */
#define VTMON_DTS0_CON /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_DTS_CON*)0xF006C060u)

/** \brief 64, Die Temperature Sensor 0 Limit Register 1  */
#define VTMON_DTS0_LIM1 /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_DTS_LIM1*)0xF006C064u)

/** \brief 68, Die Temperature Sensor 0 Limit Register 2 */
#define VTMON_DTS0_LIM2 /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_DTS_LIM2*)0xF006C068u)

/** \brief 6C, Die Temperature Sensor 0 Data Register */
#define VTMON_DTS0_DATA /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_DTS_DATA*)0xF006C06Cu)

/** \brief 70, Die Temperature Sensor 0 Status Register */
#define VTMON_DTS0_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_VTMON_DTS_STAT*)0xF006C070u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXVTMON_REG_H */
