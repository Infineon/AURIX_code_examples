/**
 * \file IfxSmm_reg.h
 * \brief
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: MC_ACE_A3G_HSI_SMM/V13.1.2.1.1
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
 * \defgroup IfxSfr_Smm_Registers_Cfg Smm address
 * \ingroup IfxSfr_Smm_Registers
 * 
 * \defgroup IfxSfr_Smm_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Smm_Registers_Cfg
 *
 * \defgroup IfxSfr_Smm_Registers_Cfg_Smm 2-SMM
 * \ingroup IfxSfr_Smm_Registers_Cfg
 *
 *
 */
#ifndef IFXSMM_REG_H
#define IFXSMM_REG_H 1
/******************************************************************************/
#include "IfxSmm_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Smm_Registers_Cfg_BaseAddress
 * \{  */

/** \brief SMM object */
#define MODULE_SMM /*lint --e(923, 9078)*/ ((*(Ifx_SMM*)0xF0060000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Smm_Registers_Cfg_Smm
 * \{  */
/** \brief 8, Module Identification Register */
#define SMM_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ID*)0xF0060008u)

/** \brief C, PROT Register Endinit */
#define SMM_PROTE /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF006000Cu)

/** \brief 10, PROT Register Safe Endinit */
#define SMM_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF0060010u)

/** \brief 14, PROT Register Cyber-Secure Endinit */
#define SMM_PROTCSE /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF0060014u)

/** \brief 18, Write access enable register A */
#define SMM_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_WRA*)0xF0060018u)

/** \brief 1C, Write access enable register B */
#define SMM_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_WRB_FPI*)0xF006001Cu)

/** \brief 20, Read access enable register A */
#define SMM_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_RDA*)0xF0060020u)

/** \brief 24, Read access enable register B */
#define SMM_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_RDB_FPI*)0xF0060024u)

/** \brief 28, VM access enable register */
#define SMM_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_VM*)0xF0060028u)

/** \brief 2C, PRS access enable register */
#define SMM_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_PRS*)0xF006002Cu)

/** \brief 38, ACCENCS write access enable register A */
#define SMM_ACCENCS_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_WRA*)0xF0060038u)

/** \brief 3C, ACCENCS write access enable register B */
#define SMM_ACCENCS_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_WRB_FPI*)0xF006003Cu)

/** \brief 40, ACCENCS read access enable register A */
#define SMM_ACCENCS_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_RDA*)0xF0060040u)

/** \brief 44, ACCENCS read access enable register B */
#define SMM_ACCENCS_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_RDB_FPI*)0xF0060044u)

/** \brief 48, ACCENCS VM access enable register */
#define SMM_ACCENCS_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_VM*)0xF0060048u)

/** \brief 4C, ACCENCS PRS access enable register */
#define SMM_ACCENCS_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ACCEN_PRS*)0xF006004Cu)

/** \brief 58, PROT Register Cyber-Secure Endinit */
#define SMM_PROTCE /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF0060058u)

/** \brief 5C, PROT Register for PMCSR0 Idle control */
#define SMM_PROTCPU0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF006005Cu)

/** \brief 60, PROT Register for PMCSR1 Idle control */
#define SMM_PROTCPU1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF0060060u)

/** \brief 64, PROT Register for PMCSR2 Idle control */
#define SMM_PROTCPU2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF0060064u)

/** \brief 68, PROT Register for PMCSR3 Idle control */
#define SMM_PROTCPU3 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF0060068u)

/** \brief 6C, PROT Register for PMCSR4 Idle control */
#define SMM_PROTCPU4 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF006006Cu)

/** \brief 70, PROT Register for PMCSR5 Idle control */
#define SMM_PROTCPU5 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROT*)0xF0060070u)

/** \brief 74, Power Management Control and Status Register for CPU0 */
#define SMM_PMCSR0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMCSR*)0xF0060074u)

/** \brief 78, Power Management Control and Status Register for CPU1 */
#define SMM_PMCSR1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMCSR*)0xF0060078u)

/** \brief 7C, Power Management Control and Status Register for CPU2 */
#define SMM_PMCSR2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMCSR*)0xF006007Cu)

/** \brief 80, Power Management Control and Status Register for CPU3 */
#define SMM_PMCSR3 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMCSR*)0xF0060080u)

/** \brief 84, Power Management Control and Status Register for CPU4 */
#define SMM_PMCSR4 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMCSR*)0xF0060084u)

/** \brief 88, Power Management Control and Status Register for CPU5 */
#define SMM_PMCSR5 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMCSR*)0xF0060088u)

/** \brief 8C, Power Management Control and Status Register for CPUcs in CSRM subystem */
#define SMM_PMCSRCS /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMCSRCS*)0xF006008Cu)

/** \brief 94, Standby and Wake-up Control Register 1 */
#define SMM_PMSWCR1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMSWCR1*)0xF0060094u)

/** \brief 98, Power Management Transition Control and Status Register 0 */
#define SMM_PMTRCSR0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMTRCSR0*)0xF0060098u)

/** \brief 9C, Power Management Transition Control and Status Register 1 */
#define SMM_PMTRCSR1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMTRCSR1*)0xF006009Cu)

/** \brief A0, Power Management Transition Control and Status Register 2 */
#define SMM_PMTRCSR2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMTRCSR2*)0xF00600A0u)

/** \brief A4, Power Management Transition Control and Status Register 3 */
#define SMM_PMTRCSR3 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMTRCSR3*)0xF00600A4u)

/** \brief AC, Power Management Status Register 0 */
#define SMM_PMSTAT0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PMSTAT0*)0xF00600ACu)

/** \brief B0, Power Management Droop Control and Status Register */
#define SMM_DRPCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_DRPCTRL*)0xF00600B0u)

/** \brief B4, Start-Up Status Register */
#define SMM_STSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_STSTAT*)0xF00600B4u)

/** \brief B8, System Control Register */
#define SMM_SYSCON /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_SYSCON*)0xF00600B8u)

/** \brief BC, Start-up Configuration Register */
#define SMM_STCON /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_STCON*)0xF00600BCu)

/** \brief C0, Software Reset Control Register */
#define SMM_SWRSTCON /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_SWRSTCON*)0xF00600C0u)

/** \brief C8, Start-up Memory Register 1 */
#define SMM_STMEM1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_STMEM1*)0xF00600C8u)

/** \brief CC, Start-up Memory Register 2 */
#define SMM_STMEM2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_STMEM2*)0xF00600CCu)

/** \brief F4, Shut Down Sequence Control Register D */
#define SMM_SHSEQCTRLD /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_SHSEQCTRLD*)0xF00600F4u)

/** \brief FC, Reset Trigger Status Register for Warm Reset Events  */
#define SMM_WRMRSTTRIG /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_WRMRSTTRIG*)0xF00600FCu)

/** \brief 100, Highest Reset Trigger Status Register for Warm Reset Events  */
#define SMM_WRMRSTTRIGH /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_WRMRSTTRIGH*)0xF0060100u)

/** \brief 104, Reset Type Status Register */
#define SMM_RSTSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_RSTSTAT*)0xF0060104u)

/** \brief 108, Highest Reset Type Status Register */
#define SMM_RSTSTATH /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_RSTSTATH*)0xF0060108u)

/** \brief 110, Reset Status Clear Register */
#define SMM_RSTSTATCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_RSTSTATCLR*)0xF0060110u)

/** \brief 114, Reset Trigger Control Register A */
#define SMM_RSTTRIGCTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_RSTTRIGCTRLA*)0xF0060114u)

/** \brief 118, Reset Trigger Control Register B */
#define SMM_RSTTRIGCTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_RSTTRIGCTRLB*)0xF0060118u)

/** \brief 11C, Reset Trigger Control Register C */
#define SMM_RSTTRIGCTRLC /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_RSTTRIGCTRLC*)0xF006011Cu)

/** \brief 120, Reset Trigger Register for SMU related Trigger */
#define SMM_SMURSTSTATA /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_SMURSTSTATA*)0xF0060120u)

/** \brief 124, Reset Trigger Register for SMU related Trigger */
#define SMM_SMURSTSTATB /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_SMURSTSTATB*)0xF0060124u)

/** \brief 128, User Info Storage Register */
#define SMM_USRINFO /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_USRINFO*)0xF0060128u)

/** \brief 12C, Pad Disable Control Register */
#define SMM_PDISC /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PDISC*)0xF006012Cu)

/** \brief 130, ESR0 Reset Output Configuration Register */
#define SMM_ESR0CFG /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ESR0CFG*)0xF0060130u)

/** \brief 134, ESR0 Input Configuration Register */
#define SMM_ESRCFG0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ESRCFG*)0xF0060134u)

/** \brief 138, ESR1 Input Configuration Register */
#define SMM_ESRCFG1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ESRCFG*)0xF0060138u)

/** \brief 13C, ESR2 Input Configuration Register */
#define SMM_ESRCFG2 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ESRCFG*)0xF006013Cu)

/** \brief 140, ESR0 Reset Counter Control Register */
#define SMM_ESR0CNTCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_ESR0CNTCTRL*)0xF0060140u)

/** \brief 144, ESR0 GPIO Control Register */
#define SMM_GPIOESR0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_GPIOESR0*)0xF0060144u)

/** \brief 148, ESR0 Pad configuration Control Register */
#define SMM_DRVCFGESR0 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_DRVCFGESR0*)0xF0060148u)

/** \brief 14C, ESR1 GPIO Control Register */
#define SMM_GPIOESR1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_GPIOESR1*)0xF006014Cu)

/** \brief 150, ESR1 Pad configuration Control Register */
#define SMM_DRVCFGESR1 /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_DRVCFGESR1*)0xF0060150u)

/** \brief 154, PROT Initialisation Configuration Register */
#define SMM_PROTINIT /*lint --e(923, 9078)*/ (*(volatile Ifx_SMM_PROTINIT*)0xF0060154u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXSMM_REG_H */
