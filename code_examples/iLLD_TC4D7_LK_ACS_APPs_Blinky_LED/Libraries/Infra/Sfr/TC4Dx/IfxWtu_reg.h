/**
 * \file IfxWtu_reg.h
 * \brief
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: MC_ACE_A3G_HSI_WTU/V0.2.2.0.1
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
 * \defgroup IfxSfr_Wtu_Registers_Cfg Wtu address
 * \ingroup IfxSfr_Wtu_Registers
 * 
 * \defgroup IfxSfr_Wtu_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Wtu_Registers_Cfg
 *
 * \defgroup IfxSfr_Wtu_Registers_Cfg_Wtu 2-WTU
 * \ingroup IfxSfr_Wtu_Registers_Cfg
 *
 *
 */
#ifndef IFXWTU_REG_H
#define IFXWTU_REG_H 1
/******************************************************************************/
#include "IfxWtu_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Wtu_Registers_Cfg_BaseAddress
 * \{  */

/** \brief WTU object */
#define MODULE_WTU /*lint --e(923, 9078)*/ ((*(Ifx_WTU*)0xF0000000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Wtu_Registers_Cfg_Wtu
 * \{  */
/** \brief 8, Module identification register */
#define WTU_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ID*)0xF0000008u)

/** \brief 18, CPU0 WDT PROT register safe endinit - SE0 */
#define WTU_WDTCPU0_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_PROT*)0xF0000018u)

/** \brief 1C, CPU0 WDT write access enable register A  */
#define WTU_WDTCPU0_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRA_CPU*)0xF000001Cu)

/** \brief 20, CPU0 WDT write access enable register B */
#define WTU_WDTCPU0_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRB_NONE*)0xF0000020u)

/** \brief 24, CPU0 WDT read access enable register A */
#define WTU_WDTCPU0_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDA*)0xF0000024u)

/** \brief 28, CPU0 WDT read access enable register B */
#define WTU_WDTCPU0_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDB_FPI*)0xF0000028u)

/** \brief 2C, CPU0 WDT VM access enable register */
#define WTU_WDTCPU0_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_VM*)0xF000002Cu)

/** \brief 30, CPU0 WDT PRS access enable register */
#define WTU_WDTCPU0_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_PRS*)0xF0000030u)

/** \brief 38, CPU0 WDT SMU partitions register */
#define WTU_WDTCPU0_SMUFSP /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_SMUFSP*)0xF0000038u)

/** \brief 3C, CPU0 WDT control register A */
#define WTU_WDTCPU0_CTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLA*)0xF000003Cu)

/** \brief 40, CPU0 WDT control register B */
#define WTU_WDTCPU0_CTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLB*)0xF0000040u)

/** \brief 44, CPU0 WDT status register */
#define WTU_WDTCPU0_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_STAT*)0xF0000044u)

/** \brief 48, CPU1 WDT PROT register safe endinit - SE1 */
#define WTU_WDTCPU1_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_PROT*)0xF0000048u)

/** \brief 4C, CPU1 WDT write access enable register A  */
#define WTU_WDTCPU1_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRA_CPU*)0xF000004Cu)

/** \brief 50, CPU1 WDT write access enable register B */
#define WTU_WDTCPU1_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRB_NONE*)0xF0000050u)

/** \brief 54, CPU1 WDT read access enable register A */
#define WTU_WDTCPU1_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDA*)0xF0000054u)

/** \brief 58, CPU1 WDT read access enable register B */
#define WTU_WDTCPU1_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDB_FPI*)0xF0000058u)

/** \brief 5C, CPU1 WDT VM access enable register */
#define WTU_WDTCPU1_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_VM*)0xF000005Cu)

/** \brief 60, CPU1 WDT PRS access enable register */
#define WTU_WDTCPU1_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_PRS*)0xF0000060u)

/** \brief 68, CPU1 WDT SMU partitions register */
#define WTU_WDTCPU1_SMUFSP /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_SMUFSP*)0xF0000068u)

/** \brief 6C, CPU1 WDT control register A */
#define WTU_WDTCPU1_CTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLA*)0xF000006Cu)

/** \brief 70, CPU1 WDT control register B */
#define WTU_WDTCPU1_CTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLB*)0xF0000070u)

/** \brief 74, CPU1 WDT status register */
#define WTU_WDTCPU1_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_STAT*)0xF0000074u)

/** \brief 78, CPU2 WDT PROT register safe endinit - SE2 */
#define WTU_WDTCPU2_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_PROT*)0xF0000078u)

/** \brief 7C, CPU2 WDT write access enable register A  */
#define WTU_WDTCPU2_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRA_CPU*)0xF000007Cu)

/** \brief 80, CPU2 WDT write access enable register B */
#define WTU_WDTCPU2_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRB_NONE*)0xF0000080u)

/** \brief 84, CPU2 WDT read access enable register A */
#define WTU_WDTCPU2_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDA*)0xF0000084u)

/** \brief 88, CPU2 WDT read access enable register B */
#define WTU_WDTCPU2_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDB_FPI*)0xF0000088u)

/** \brief 8C, CPU2 WDT VM access enable register */
#define WTU_WDTCPU2_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_VM*)0xF000008Cu)

/** \brief 90, CPU2 WDT PRS access enable register */
#define WTU_WDTCPU2_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_PRS*)0xF0000090u)

/** \brief 98, CPU2 WDT SMU partitions register */
#define WTU_WDTCPU2_SMUFSP /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_SMUFSP*)0xF0000098u)

/** \brief 9C, CPU2 WDT control register A */
#define WTU_WDTCPU2_CTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLA*)0xF000009Cu)

/** \brief A0, CPU2 WDT control register B */
#define WTU_WDTCPU2_CTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLB*)0xF00000A0u)

/** \brief A4, CPU2 WDT status register */
#define WTU_WDTCPU2_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_STAT*)0xF00000A4u)

/** \brief A8, CPU3 WDT PROT register safe endinit - SE3 */
#define WTU_WDTCPU3_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_PROT*)0xF00000A8u)

/** \brief AC, CPU3 WDT write access enable register A  */
#define WTU_WDTCPU3_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRA_CPU*)0xF00000ACu)

/** \brief B0, CPU3 WDT write access enable register B */
#define WTU_WDTCPU3_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRB_NONE*)0xF00000B0u)

/** \brief B4, CPU3 WDT read access enable register A */
#define WTU_WDTCPU3_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDA*)0xF00000B4u)

/** \brief B8, CPU3 WDT read access enable register B */
#define WTU_WDTCPU3_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDB_FPI*)0xF00000B8u)

/** \brief BC, CPU3 WDT VM access enable register */
#define WTU_WDTCPU3_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_VM*)0xF00000BCu)

/** \brief C0, CPU3 WDT PRS access enable register */
#define WTU_WDTCPU3_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_PRS*)0xF00000C0u)

/** \brief C8, CPU3 WDT SMU partitions register */
#define WTU_WDTCPU3_SMUFSP /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_SMUFSP*)0xF00000C8u)

/** \brief CC, CPU3 WDT control register A */
#define WTU_WDTCPU3_CTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLA*)0xF00000CCu)

/** \brief D0, CPU3 WDT control register B */
#define WTU_WDTCPU3_CTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLB*)0xF00000D0u)

/** \brief D4, CPU3 WDT status register */
#define WTU_WDTCPU3_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_STAT*)0xF00000D4u)

/** \brief D8, CPU4 WDT PROT register safe endinit - SE4 */
#define WTU_WDTCPU4_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_PROT*)0xF00000D8u)

/** \brief DC, CPU4 WDT write access enable register A  */
#define WTU_WDTCPU4_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRA_CPU*)0xF00000DCu)

/** \brief E0, CPU4 WDT write access enable register B */
#define WTU_WDTCPU4_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRB_NONE*)0xF00000E0u)

/** \brief E4, CPU4 WDT read access enable register A */
#define WTU_WDTCPU4_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDA*)0xF00000E4u)

/** \brief E8, CPU4 WDT read access enable register B */
#define WTU_WDTCPU4_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDB_FPI*)0xF00000E8u)

/** \brief EC, CPU4 WDT VM access enable register */
#define WTU_WDTCPU4_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_VM*)0xF00000ECu)

/** \brief F0, CPU4 WDT PRS access enable register */
#define WTU_WDTCPU4_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_PRS*)0xF00000F0u)

/** \brief F8, CPU4 WDT SMU partitions register */
#define WTU_WDTCPU4_SMUFSP /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_SMUFSP*)0xF00000F8u)

/** \brief FC, CPU4 WDT control register A */
#define WTU_WDTCPU4_CTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLA*)0xF00000FCu)

/** \brief 100, CPU4 WDT control register B */
#define WTU_WDTCPU4_CTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLB*)0xF0000100u)

/** \brief 104, CPU4 WDT status register */
#define WTU_WDTCPU4_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_STAT*)0xF0000104u)

/** \brief 108, CPU5 WDT PROT register safe endinit - SE5 */
#define WTU_WDTCPU5_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_PROT*)0xF0000108u)

/** \brief 10C, CPU5 WDT write access enable register A  */
#define WTU_WDTCPU5_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRA_CPU*)0xF000010Cu)

/** \brief 110, CPU5 WDT write access enable register B */
#define WTU_WDTCPU5_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRB_NONE*)0xF0000110u)

/** \brief 114, CPU5 WDT read access enable register A */
#define WTU_WDTCPU5_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDA*)0xF0000114u)

/** \brief 118, CPU5 WDT read access enable register B */
#define WTU_WDTCPU5_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDB_FPI*)0xF0000118u)

/** \brief 11C, CPU5 WDT VM access enable register */
#define WTU_WDTCPU5_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_VM*)0xF000011Cu)

/** \brief 120, CPU5 WDT PRS access enable register */
#define WTU_WDTCPU5_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_PRS*)0xF0000120u)

/** \brief 128, CPU5 WDT SMU partitions register */
#define WTU_WDTCPU5_SMUFSP /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_SMUFSP*)0xF0000128u)

/** \brief 12C, CPU5 WDT control register A */
#define WTU_WDTCPU5_CTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLA*)0xF000012Cu)

/** \brief 130, CPU5 WDT control register B */
#define WTU_WDTCPU5_CTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLB*)0xF0000130u)

/** \brief 134, CPU5 WDT status register */
#define WTU_WDTCPU5_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_STAT*)0xF0000134u)

/** \brief 150, Security WDT PROT register cyber-secure endinit - CSE */
#define WTU_WDTSEC_PROTCSE /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_PROT*)0xF0000150u)

/** \brief 154, Security WDT write access enable register A  */
#define WTU_WDTSEC_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRA_CS*)0xF0000154u)

/** \brief 158, Security WDT write access enable register B */
#define WTU_WDTSEC_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRB_NONE*)0xF0000158u)

/** \brief 15C, Security WDT read access enable register A */
#define WTU_WDTSEC_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDA*)0xF000015Cu)

/** \brief 160, Security WDT read access enable register B */
#define WTU_WDTSEC_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDB_FPI*)0xF0000160u)

/** \brief 164, Security WDT VM access enable register */
#define WTU_WDTSEC_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_VM*)0xF0000164u)

/** \brief 168, Security WDT PRS access enable register */
#define WTU_WDTSEC_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_PRS*)0xF0000168u)

/** \brief 170, Security WDT SMU partitions register */
#define WTU_WDTSEC_SMUFSP /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_SMUFSP*)0xF0000170u)

/** \brief 174, Security WDT control register A */
#define WTU_WDTSEC_CTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLA*)0xF0000174u)

/** \brief 178, Security WDT control register B */
#define WTU_WDTSEC_CTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLB*)0xF0000178u)

/** \brief 17C, Security WDT status register */
#define WTU_WDTSEC_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_STAT*)0xF000017Cu)

/** \brief 184, System WDT PROT register safe endinit - SSE */
#define WTU_WDTSYS_PROTSE /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_PROT*)0xF0000184u)

/** \brief 188, System WDT write access enable register A  */
#define WTU_WDTSYS_ACCEN_WRA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRA*)0xF0000188u)

/** \brief 18C, System WDT write access enable register B */
#define WTU_WDTSYS_ACCEN_WRB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_WRB_FPI*)0xF000018Cu)

/** \brief 190, System WDT read access enable register A */
#define WTU_WDTSYS_ACCEN_RDA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDA*)0xF0000190u)

/** \brief 194, System WDT read access enable register B */
#define WTU_WDTSYS_ACCEN_RDB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_RDB_FPI*)0xF0000194u)

/** \brief 198, System WDT VM access enable register */
#define WTU_WDTSYS_ACCEN_VM /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_VM*)0xF0000198u)

/** \brief 19C, System WDT PRS access enable register */
#define WTU_WDTSYS_ACCEN_PRS /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_ACCEN_PRS*)0xF000019Cu)

/** \brief 1A4, System WDT SMU partitions register */
#define WTU_WDTSYS_SMUFSP /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_SMUFSP*)0xF00001A4u)

/** \brief 1A8, System WDT control register A */
#define WTU_WDTSYS_CTRLA /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLA*)0xF00001A8u)

/** \brief 1AC, System WDT control register B */
#define WTU_WDTSYS_CTRLB /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_CTRLB*)0xF00001ACu)

/** \brief 1B0, System WDT status register */
#define WTU_WDTSYS_STAT /*lint --e(923, 9078)*/ (*(volatile Ifx_WTU_STAT*)0xF00001B0u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXWTU_REG_H */
