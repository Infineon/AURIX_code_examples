/**
 * \file IfxSbcu_reg.h
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
 * \defgroup IfxSfr_Sbcu_Registers_Cfg Sbcu address
 * \ingroup IfxSfr_Sbcu_Registers
 * 
 * \defgroup IfxSfr_Sbcu_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Sbcu_Registers_Cfg
 *
 * \defgroup IfxSfr_Sbcu_Registers_Cfg_Sbcu 2-SBCU
 * \ingroup IfxSfr_Sbcu_Registers_Cfg
 *
 *
 */
#ifndef IFXSBCU_REG_H
#define IFXSBCU_REG_H 1
/******************************************************************************/
#include "IfxSbcu_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Sbcu_Registers_Cfg_BaseAddress
 * \{  */

/** \brief SBCU object */
#define MODULE_SBCU /*lint --e(923, 9078)*/ ((*(Ifx_SBCU*)0xF0030000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Sbcu_Registers_Cfg_Sbcu
 * \{  */
/** \brief 8, Module Identification Register */
#define SBCU_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ID*)0xF0030008u)

/** \brief 10, BCU Control Register */
#define SBCU_CON /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_CON*)0xF0030010u)

/** \brief 14, Arbiter Priority Register High */
#define SBCU_PRIOH /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_PRIOH*)0xF0030014u)

/** \brief 18, Arbiter Priority Register Low */
#define SBCU_PRIOL /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_PRIOL*)0xF0030018u)

/** \brief 20, BCU Error Control Capture Register */
#define SBCU_ECON /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ECON*)0xF0030020u)

/** \brief 24, BCU Error Address Capture Register */
#define SBCU_EADD /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_EADD*)0xF0030024u)

/** \brief 28, BCU Error Data Capture Register */
#define SBCU_EDAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_EDAT*)0xF0030028u)

/** \brief 30, BCU Debug Control Register */
#define SBCU_DBCNTL /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_DBCNTL*)0xF0030030u)

/** \brief 34, SBCU Debug Grant Mask Register */
#define SBCU_DBGRNT /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_DBGRNT*)0xF0030034u)

/** \brief 38, BCU Debug Address 1 Register */
#define SBCU_DBADR1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_DBADR1*)0xF0030038u)

/** \brief 3C, BCU Debug Address 2 Register */
#define SBCU_DBADR2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_DBADR2*)0xF003003Cu)

/** \brief 40, BCU Debug Bus Operation Signals Register */
#define SBCU_DBBOS /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_DBBOS*)0xF0030040u)

/** \brief 44, SBCU Debug Trapped Master Register */
#define SBCU_DBGNTT /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_DBGNTT*)0xF0030044u)

/** \brief 48, BCU Debug Trapped Address Register */
#define SBCU_DBADRT /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_DBADRT*)0xF0030048u)

/** \brief 4C, BCU Debug Trapped Bus Operation Signals Register */
#define SBCU_DBBOST /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_DBBOST*)0xF003004Cu)

/** \brief 50, BCU Debug Data Status Register */
#define SBCU_DBDAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_DBDAT*)0xF0030050u)

/** \brief 60, BCU EDC Alarm Status Register 0 */
#define SBCU_ALSTAT0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ALSTAT*)0xF0030060u)

/** \brief 64, BCU EDC Alarm Status Register 1 */
#define SBCU_ALSTAT1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ALSTAT*)0xF0030064u)

/** \brief 68, BCU EDC Alarm Status Register 2 */
#define SBCU_ALSTAT2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ALSTAT*)0xF0030068u)

/** \brief 6C, BCU EDC Alarm Status Register 3 */
#define SBCU_ALSTAT3 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ALSTAT*)0xF003006Cu)

/** \brief 70, BCU EDC Alarm Clear Register 0 */
#define SBCU_ALCLR0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ALCLR*)0xF0030070u)

/** \brief 74, BCU EDC Alarm Clear Register 1 */
#define SBCU_ALCLR1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ALCLR*)0xF0030074u)

/** \brief 78, BCU EDC Alarm Clear Register 2 */
#define SBCU_ALCLR2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ALCLR*)0xF0030078u)

/** \brief 7C, BCU EDC Alarm Clear Register 3 */
#define SBCU_ALCLR3 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ALCLR*)0xF003007Cu)

/** \brief 80, BCU EDC Alarm Control Register */
#define SBCU_ALCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ALCTRL*)0xF0030080u)

/** \brief 84, FPI Error Generation Control Register */
#define SBCU_FEGEN /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_FEGEN*)0xF0030084u)

/** \brief F8, Access Enable Register 1 */
#define SBCU_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ACCEN1*)0xF00300F8u)

/** \brief FC, Access Enable Register 0 */
#define SBCU_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SBCU_ACCEN0*)0xF00300FCu)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXSBCU_REG_H */
