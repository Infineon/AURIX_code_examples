/**
 * \file IfxPmu_regdef.h
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
 * \defgroup IfxSfr_Pmu_Registers Pmu Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Pmu_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Pmu_Registers
 * 
 * \defgroup IfxSfr_Pmu_Registers_union Register unions
 * \ingroup IfxSfr_Pmu_Registers
 * 
 * \defgroup IfxSfr_Pmu_Registers_struct Memory map
 * \ingroup IfxSfr_Pmu_Registers
 */
#ifndef IFXPMU_REGDEF_H
#define IFXPMU_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Pmu_Registers_Bitfields
 * \{  */
/** \brief Module Identification Register */
typedef struct _Ifx_PMU_ID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision Number - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_TYPE:8;        /**< \brief [15:8] Module Type - MOD_TYPE (r) */
    Ifx_UReg_32Bit MOD_NUMBER:16;     /**< \brief [31:16] Module Number Value - MOD_NUMBER (r) */
} Ifx_PMU_ID_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_pmu_Registers_union
 * \{   */
/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_PMU_ID_Bits B;                /**< \brief Bitfield access */
} Ifx_PMU_ID;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_Pmu_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief PMU object */
typedef volatile struct _Ifx_PMU
{
       Ifx_UReg_8Bit                       reserved_0[1288];       /**< \brief 0, \internal Reserved */
       Ifx_PMU_ID                          ID;                     /**< \brief 508, Module Identification Register*/
       Ifx_UReg_8Bit                       reserved_50C[31476];    /**< \brief 50C, \internal Reserved */
} Ifx_PMU;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXPMU_REGDEF_H */
