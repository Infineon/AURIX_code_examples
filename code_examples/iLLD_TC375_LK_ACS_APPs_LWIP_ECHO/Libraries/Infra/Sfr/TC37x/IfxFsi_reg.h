/**
 * \file IfxFsi_reg.h
 * \brief
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC37xPD_UM_V2.0.0.R0
 * Specification: TC3xx User Manual V2.0.0
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
 * \defgroup IfxSfr_Fsi_Registers_Cfg_Fsi 2-FSI
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
#define MODULE_FSI /*lint --e(923, 9078)*/ ((*(Ifx_FSI*)0xF8030000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Fsi_Registers_Cfg_Fsi
 * \{  */
/** \brief 4, Communication Register 1 */
#define FSI_COMM_1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM_1*)0xF8030004u)

/** \brief 5, Communication Register 2 */
#define FSI_COMM_2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM_2*)0xF8030005u)

/** \brief 6, HSM Communication Register 1 */
#define FSI_HSMCOMM_1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_HSMCOMM_1*)0xF8030006u)

/** \brief 7, HSM Communication Register 2 */
#define FSI_HSMCOMM_2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_HSMCOMM_2*)0xF8030007u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXFSI_REG_H */
