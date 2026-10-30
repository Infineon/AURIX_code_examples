/**
 * \file IfxFsi_reg.h
 * \brief
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: MC_ACE_A3G_HSI_NVM_FSI/V0.2.2.1.1
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
 * \defgroup IfxSfr_Fsi_Registers_Cfg Fsi address
 * \ingroup IfxSfr_Fsi_Registers
 * 
 * \defgroup IfxSfr_Fsi_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 * \defgroup IfxSfr_Fsi_Registers_Cfg_Fsi_csrm 2-FSI_CSRM
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 * \defgroup IfxSfr_Fsi_Registers_Cfg_Fsi_host 2-FSI_HOST
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 *
 */
#ifndef IFXFSI_REG_H
#define IFXFSI_REG_H 1
/******************************************************************************/
#include "IfxFsi_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Fsi_Registers_Cfg_BaseAddress
 * \{  */

/** \brief FSI object */
#define MODULE_FSI_CSRM /*lint --e(923, 9078)*/ ((*(Ifx_FSI*)0xF8028000u))
#define MODULE_FSI_HOST /*lint --e(923, 9078)*/ ((*(Ifx_FSI*)0xF8008000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Fsi_Registers_Cfg_Fsi_csrm
 * \{  */
/** \brief 0, Communication register 0 */
#define FSI_CSRM_COMM0 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM0*)0xF8028000u)

/** \brief 1, Communication register 1 */
#define FSI_CSRM_COMM1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM1*)0xF8028001u)

/** \brief 2, Communication register 2 */
#define FSI_CSRM_COMM2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM2*)0xF8028002u)

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Fsi_Registers_Cfg_Fsi_host
 * \{  */
/** \brief 0, Communication register 0 */
#define FSI_HOST_COMM0 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM0*)0xF8008000u)

/** \brief 1, Communication register 1 */
#define FSI_HOST_COMM1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM1*)0xF8008001u)

/** \brief 2, Communication register 2 */
#define FSI_HOST_COMM2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM2*)0xF8008002u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXFSI_REG_H */
