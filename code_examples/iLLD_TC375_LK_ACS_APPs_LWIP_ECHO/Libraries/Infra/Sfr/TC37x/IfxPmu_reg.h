/**
 * \file IfxPmu_reg.h
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
 * \defgroup IfxSfr_Pmu_Registers_Cfg Pmu address
 * \ingroup IfxSfr_Pmu_Registers
 * 
 * \defgroup IfxSfr_Pmu_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Pmu_Registers_Cfg
 *
 * \defgroup IfxSfr_Pmu_Registers_Cfg_Pmu 2-PMU
 * \ingroup IfxSfr_Pmu_Registers_Cfg
 *
 *
 */
#ifndef IFXPMU_REG_H
#define IFXPMU_REG_H 1
/******************************************************************************/
#include "IfxPmu_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Pmu_Registers_Cfg_BaseAddress
 * \{  */

/** \brief PMU object */
#define MODULE_PMU /*lint --e(923, 9078)*/ ((*(Ifx_PMU*)0xF8038000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Pmu_Registers_Cfg_Pmu
 * \{  */
/** \brief 508, Module Identification Register */
#define PMU_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_PMU_ID*)0xF8038508u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXPMU_REG_H */
