/**
 * \file IfxHsct_reg.h
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
 * \defgroup IfxSfr_Hsct_Registers_Cfg Hsct address
 * \ingroup IfxSfr_Hsct_Registers
 * 
 * \defgroup IfxSfr_Hsct_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Hsct_Registers_Cfg
 *
 * \defgroup IfxSfr_Hsct_Registers_Cfg_Hsct0 2-HSCT0
 * \ingroup IfxSfr_Hsct_Registers_Cfg
 *
 *
 */
#ifndef IFXHSCT_REG_H
#define IFXHSCT_REG_H 1
/******************************************************************************/
#include "IfxHsct_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Hsct_Registers_Cfg_BaseAddress
 * \{  */

/** \brief HSCT object */
#define MODULE_HSCT0 /*lint --e(923, 9078)*/ ((*(Ifx_HSCT*)0xF0090000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Hsct_Registers_Cfg_Hsct0
 * \{  */
/** \brief 0, Clock Control Register */
#define HSCT0_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_CLC*)0xF0090000u)

/** \brief 8, Module Identification Register */
#define HSCT0_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_ID*)0xF0090008u)

/** \brief 10, Initialization Register */
#define HSCT0_INIT /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_INIT*)0xF0090010u)

/** \brief 14, Interface Control Register */
#define HSCT0_IFCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_IFCTRL*)0xF0090014u)

/** \brief 18, Sleep Control Register */
#define HSCT0_SLEEPCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_SLEEPCTRL*)0xF0090018u)

/** \brief 1C, Clear To Send Control Register */
#define HSCT0_CTSCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_CTSCTRL*)0xF009001Cu)

/** \brief 20, Transmission Disable Register */
#define HSCT0_DISABLE /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_DISABLE*)0xF0090020u)

/** \brief 24, Status Register */
#define HSCT0_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_STAT*)0xF0090024u)

/** \brief 28, Interface Status Register */
#define HSCT0_IFSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_IFSTAT*)0xF0090028u)

/** \brief 30, Configuration Physical Layer Register */
#define HSCT0_CONFIGPHY /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_CONFIGPHY*)0xF0090030u)

/** \brief 34, STATPHY */
#define HSCT0_STATPHY /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_STATPHY*)0xF0090034u)

/** \brief 40, Interrupt register */
#define HSCT0_IRQ /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_IRQ*)0xF0090040u)

/** \brief 44, Interrupt Enable Register */
#define HSCT0_IRQEN /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_IRQEN*)0xF0090044u)

/** \brief 48, Interrupt Clear Register */
#define HSCT0_IRQCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_IRQCLR*)0xF0090048u)

/** \brief 50, Unsolicited Status Message Received */
#define HSCT0_USMR /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_USMR*)0xF0090050u)

/** \brief 54, Unsolicited Status Message Send */
#define HSCT0_USMS /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_USMS*)0xF0090054u)

/** \brief 60, Test Control Register */
#define HSCT0_TESTCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_TESTCTRL*)0xF0090060u)

/** \brief FFE8, OCDS Control and Status */
#define HSCT0_OCS /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_OCS*)0xF009FFE8u)

/** \brief FFEC, Reset Status Clear Register */
#define HSCT0_KRSTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_KRSTCLR*)0xF009FFECu)

/** \brief FFF0, Reset Register 1 */
#define HSCT0_KRST1 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_KRST1*)0xF009FFF0u)

/** \brief FFF4, Reset Register 0 */
#define HSCT0_KRST0 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_KRST0*)0xF009FFF4u)

/** \brief FFF8, Access Enable Register 1 */
#define HSCT0_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_ACCEN1*)0xF009FFF8u)

/** \brief FFFC, Access Enable Register 0 */
#define HSCT0_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_HSCT_ACCEN0*)0xF009FFFCu)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXHSCT_REG_H */
