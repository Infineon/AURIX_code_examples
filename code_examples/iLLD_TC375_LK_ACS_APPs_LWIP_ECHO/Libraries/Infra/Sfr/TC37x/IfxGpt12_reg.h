/**
 * \file IfxGpt12_reg.h
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
 * \defgroup IfxSfr_Gpt12_Registers_Cfg Gpt12 address
 * \ingroup IfxSfr_Gpt12_Registers
 * 
 * \defgroup IfxSfr_Gpt12_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Gpt12_Registers_Cfg
 *
 * \defgroup IfxSfr_Gpt12_Registers_Cfg_Gpt120 2-GPT120
 * \ingroup IfxSfr_Gpt12_Registers_Cfg
 *
 *
 */
#ifndef IFXGPT12_REG_H
#define IFXGPT12_REG_H 1
/******************************************************************************/
#include "IfxGpt12_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Gpt12_Registers_Cfg_BaseAddress
 * \{  */

/** \brief GPT12 object */
#define MODULE_GPT120 /*lint --e(923, 9078)*/ ((*(Ifx_GPT12*)0xF0001800u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Gpt12_Registers_Cfg_Gpt120
 * \{  */
/** \brief 0, Clock Control Register */
#define GPT120_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_CLC*)0xF0001800u)

/** \brief 4, Port Input Select Register */
#define GPT120_PISEL /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_PISEL*)0xF0001804u)

/** \brief 8, Identification Register */
#define GPT120_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_ID*)0xF0001808u)

/** \brief 10, Timer T2 Control Register */
#define GPT120_T2CON /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T2CON*)0xF0001810u)

/** \brief 14, Timer T3 Control Register */
#define GPT120_T3CON /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T3CON*)0xF0001814u)

/** \brief 18, Timer T4 Control Register */
#define GPT120_T4CON /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T4CON*)0xF0001818u)

/** \brief 1C, Timer T5 Control Register */
#define GPT120_T5CON /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T5CON*)0xF000181Cu)

/** \brief 20, Timer T6 Control Register */
#define GPT120_T6CON /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T6CON*)0xF0001820u)

/** \brief 30, Capture and Reload Register */
#define GPT120_CAPREL /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_CAPREL*)0xF0001830u)

/** \brief 34, Timer T2 Register */
#define GPT120_T2 /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T2*)0xF0001834u)

/** \brief 38, Timer T3 Register */
#define GPT120_T3 /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T3*)0xF0001838u)

/** \brief 3C, Timer T4 Register */
#define GPT120_T4 /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T4*)0xF000183Cu)

/** \brief 40, Timer T5 Register */
#define GPT120_T5 /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T5*)0xF0001840u)

/** \brief 44, Timer T6 Register */
#define GPT120_T6 /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_T6*)0xF0001844u)

/** \brief E8, OCDS Control and Status Register */
#define GPT120_OCS /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_OCS*)0xF00018E8u)

/** \brief EC, Kernel Reset Status Clear Register */
#define GPT120_KRSTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_KRSTCLR*)0xF00018ECu)

/** \brief F0, Kernel Reset Register 1 */
#define GPT120_KRST1 /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_KRST1*)0xF00018F0u)

/** \brief F4, Kernel Reset Register 0 */
#define GPT120_KRST0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_KRST0*)0xF00018F4u)

/** \brief FC, Access Enable Register 0 */
#define GPT120_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GPT12_ACCEN0*)0xF00018FCu)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXGPT12_REG_H */
