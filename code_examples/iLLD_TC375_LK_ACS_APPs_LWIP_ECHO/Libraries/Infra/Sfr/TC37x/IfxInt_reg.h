/**
 * \file IfxInt_reg.h
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
 * \defgroup IfxSfr_Int_Registers_Cfg Int address
 * \ingroup IfxSfr_Int_Registers
 * 
 * \defgroup IfxSfr_Int_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Int_Registers_Cfg
 *
 * \defgroup IfxSfr_Int_Registers_Cfg_Int 2-INT
 * \ingroup IfxSfr_Int_Registers_Cfg
 *
 *
 */
#ifndef IFXINT_REG_H
#define IFXINT_REG_H 1
/******************************************************************************/
#include "IfxInt_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Int_Registers_Cfg_BaseAddress
 * \{  */

/** \brief INT object */
#define MODULE_INT /*lint --e(923, 9078)*/ ((*(Ifx_INT*)0xF0037000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Int_Registers_Cfg_Int
 * \{  */
/** \brief 8, Module Identification Register */
#define INT_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ID*)0xF0037008u)

/** \brief 10, Service Request Broadcast Register 0 */
#define INT_SRB0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_SRB*)0xF0037010u)

/** \brief 14, Service Request Broadcast Register 1 */
#define INT_SRB1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_SRB*)0xF0037014u)

/** \brief 18, Service Request Broadcast Register 2 */
#define INT_SRB2 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_SRB*)0xF0037018u)

/** \brief 80, OTGM OTGB0/1 Status */
#define INT_OOBS /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_OOBS*)0xF0037080u)

/** \brief 84, OTGM SSI Control */
#define INT_OSSIC /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_OSSIC*)0xF0037084u)

/** \brief 88, OTGM IRQ MUX Trigger Set Select */
#define INT_OIXTS /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_OIXTS*)0xF0037088u)

/** \brief 8C, OTGM IRQ MUX Missed IRQ Select */
#define INT_OIXMS /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_OIXMS*)0xF003708Cu)

/** \brief 90, OTGM IRQ MUX Select 0 */
#define INT_OIXS0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_OIXS0*)0xF0037090u)

/** \brief 94, OTGM IRQ MUX Select 1 */
#define INT_OIXS1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_OIXS1*)0xF0037094u)

/** \brief A0, OTGM IRQ Trace */
#define INT_OIT /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_OIT*)0xF00370A0u)

/** \brief A4, OTGM MCDS I/F Sensitivity Posedge */
#define INT_OMISP /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_OMISP*)0xF00370A4u)

/** \brief A8, OTGM MCDS I/F Sensitivity Negedge */
#define INT_OMISN /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_OMISN*)0xF00370A8u)

/** \brief F0, Access Enable covering all INT_ECRx and all SRCy[15:0], Register 0 */
#define INT_ACCEN_CONFIG0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_CONFIG0*)0xF00370F0u)

/** \brief F4, Access Enable covering all INT_ECRx and all SRCy[15:0], Register 1 */
#define INT_ACCEN_CONFIG1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_CONFIG1*)0xF00370F4u)

/** \brief 100, Access Enable covering SRB0, Register 0 */
#define INT_ACCEN0_SRB0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRB0*)0xF0037100u)
/** Alias (User Manual Name) for INT_ACCEN0_SRB0.
* To use register names with standard convension, please use INT_ACCEN0_SRB0.
*/
#define INT_ACCEN_SRB00 (INT_ACCEN0_SRB0)

/** \brief 104, Access Enable covering SRB0, Register 1 */
#define INT_ACCEN0_SRB1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRB1*)0xF0037104u)
/** Alias (User Manual Name) for INT_ACCEN0_SRB1.
* To use register names with standard convension, please use INT_ACCEN0_SRB1.
*/
#define INT_ACCEN_SRB01 (INT_ACCEN0_SRB1)

/** \brief 108, Access Enable covering SRB1, Register 0 */
#define INT_ACCEN1_SRB0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRB0*)0xF0037108u)
/** Alias (User Manual Name) for INT_ACCEN1_SRB0.
* To use register names with standard convension, please use INT_ACCEN1_SRB0.
*/
#define INT_ACCEN_SRB10 (INT_ACCEN1_SRB0)

/** \brief 10C, Access Enable covering SRB1, Register 1 */
#define INT_ACCEN1_SRB1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRB1*)0xF003710Cu)
/** Alias (User Manual Name) for INT_ACCEN1_SRB1.
* To use register names with standard convension, please use INT_ACCEN1_SRB1.
*/
#define INT_ACCEN_SRB11 (INT_ACCEN1_SRB1)

/** \brief 110, Access Enable covering SRB2, Register 0 */
#define INT_ACCEN2_SRB0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRB0*)0xF0037110u)
/** Alias (User Manual Name) for INT_ACCEN2_SRB0.
* To use register names with standard convension, please use INT_ACCEN2_SRB0.
*/
#define INT_ACCEN_SRB20 (INT_ACCEN2_SRB0)

/** \brief 114, Access Enable covering SRB2, Register 1 */
#define INT_ACCEN2_SRB1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRB1*)0xF0037114u)
/** Alias (User Manual Name) for INT_ACCEN2_SRB1.
* To use register names with standard convension, please use INT_ACCEN2_SRB1.
*/
#define INT_ACCEN_SRB21 (INT_ACCEN2_SRB1)

/** \brief 180, Access Enable covering all SRCx[31:16] mapped to ICU0, Register 0 */
#define INT_ACCEN_SRC0_TOS0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRC_TOS0*)0xF0037180u)
/** Alias (User Manual Name) for INT_ACCEN_SRC0_TOS0.
* To use register names with standard convension, please use INT_ACCEN_SRC0_TOS0.
*/
#define INT_ACCEN_SRC_TOS00 (INT_ACCEN_SRC0_TOS0)

/** \brief 184, Access Enable covering all SRCx[31:16] mapped to ICU0, Register 1 */
#define INT_ACCEN_SRC0_TOS1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRC_TOS1*)0xF0037184u)
/** Alias (User Manual Name) for INT_ACCEN_SRC0_TOS1.
* To use register names with standard convension, please use INT_ACCEN_SRC0_TOS1.
*/
#define INT_ACCEN_SRC_TOS01 (INT_ACCEN_SRC0_TOS1)

/** \brief 188, Access Enable covering all SRCx[31:16] mapped to ICU1, Register 0 */
#define INT_ACCEN_SRC1_TOS0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRC_TOS0*)0xF0037188u)
/** Alias (User Manual Name) for INT_ACCEN_SRC1_TOS0.
* To use register names with standard convension, please use INT_ACCEN_SRC1_TOS0.
*/
#define INT_ACCEN_SRC_TOS10 (INT_ACCEN_SRC1_TOS0)

/** \brief 18C, Access Enable covering all SRCx[31:16] mapped to ICU1, Register 1 */
#define INT_ACCEN_SRC1_TOS1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRC_TOS1*)0xF003718Cu)
/** Alias (User Manual Name) for INT_ACCEN_SRC1_TOS1.
* To use register names with standard convension, please use INT_ACCEN_SRC1_TOS1.
*/
#define INT_ACCEN_SRC_TOS11 (INT_ACCEN_SRC1_TOS1)

/** \brief 190, Access Enable covering all SRCx[31:16] mapped to ICU2, Register 0 */
#define INT_ACCEN_SRC2_TOS0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRC_TOS0*)0xF0037190u)
/** Alias (User Manual Name) for INT_ACCEN_SRC2_TOS0.
* To use register names with standard convension, please use INT_ACCEN_SRC2_TOS0.
*/
#define INT_ACCEN_SRC_TOS20 (INT_ACCEN_SRC2_TOS0)

/** \brief 194, Access Enable covering all SRCx[31:16] mapped to ICU2, Register 1 */
#define INT_ACCEN_SRC2_TOS1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRC_TOS1*)0xF0037194u)
/** Alias (User Manual Name) for INT_ACCEN_SRC2_TOS1.
* To use register names with standard convension, please use INT_ACCEN_SRC2_TOS1.
*/
#define INT_ACCEN_SRC_TOS21 (INT_ACCEN_SRC2_TOS1)

/** \brief 198, Access Enable covering all SRCx[31:16] mapped to ICU3, Register 0 */
#define INT_ACCEN_SRC3_TOS0 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRC_TOS0*)0xF0037198u)
/** Alias (User Manual Name) for INT_ACCEN_SRC3_TOS0.
* To use register names with standard convension, please use INT_ACCEN_SRC3_TOS0.
*/
#define INT_ACCEN_SRC_TOS30 (INT_ACCEN_SRC3_TOS0)

/** \brief 19C, Access Enable covering all SRCx[31:16] mapped to ICU3, Register 1 */
#define INT_ACCEN_SRC3_TOS1 /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_ACCEN_SRC_TOS1*)0xF003719Cu)
/** Alias (User Manual Name) for INT_ACCEN_SRC3_TOS1.
* To use register names with standard convension, please use INT_ACCEN_SRC3_TOS1.
*/
#define INT_ACCEN_SRC_TOS31 (INT_ACCEN_SRC3_TOS1)

/** \brief 200, Latest Winning Service Request Register 0, related to ICU0 */
#define INT_CH0_LWSR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_LWSR*)0xF0037200u)
/** Alias (User Manual Name) for INT_CH0_LWSR.
* To use register names with standard convension, please use INT_CH0_LWSR.
*/
#define INT_LWSR0 (INT_CH0_LWSR)

/** \brief 204, Last Acknowledged Service Request Register 0, related to ICU0 */
#define INT_CH0_LASR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_LASR*)0xF0037204u)
/** Alias (User Manual Name) for INT_CH0_LASR.
* To use register names with standard convension, please use INT_CH0_LASR.
*/
#define INT_LASR0 (INT_CH0_LASR)

/** \brief 208, Error Capture Register 0, related to ICU0 */
#define INT_CH0_ECR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_ECR*)0xF0037208u)
/** Alias (User Manual Name) for INT_CH0_ECR.
* To use register names with standard convension, please use INT_CH0_ECR.
*/
#define INT_ECR0 (INT_CH0_ECR)

/** \brief 210, Latest Winning Service Request Register 1, related to ICU1 */
#define INT_CH1_LWSR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_LWSR*)0xF0037210u)
/** Alias (User Manual Name) for INT_CH1_LWSR.
* To use register names with standard convension, please use INT_CH1_LWSR.
*/
#define INT_LWSR1 (INT_CH1_LWSR)

/** \brief 214, Last Acknowledged Service Request Register 1, related to ICU1 */
#define INT_CH1_LASR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_LASR*)0xF0037214u)
/** Alias (User Manual Name) for INT_CH1_LASR.
* To use register names with standard convension, please use INT_CH1_LASR.
*/
#define INT_LASR1 (INT_CH1_LASR)

/** \brief 218, Error Capture Register 1, related to ICU1 */
#define INT_CH1_ECR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_ECR*)0xF0037218u)
/** Alias (User Manual Name) for INT_CH1_ECR.
* To use register names with standard convension, please use INT_CH1_ECR.
*/
#define INT_ECR1 (INT_CH1_ECR)

/** \brief 220, Latest Winning Service Request Register 2, related to ICU2 */
#define INT_CH2_LWSR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_LWSR*)0xF0037220u)
/** Alias (User Manual Name) for INT_CH2_LWSR.
* To use register names with standard convension, please use INT_CH2_LWSR.
*/
#define INT_LWSR2 (INT_CH2_LWSR)

/** \brief 224, Last Acknowledged Service Request Register 2, related to ICU2 */
#define INT_CH2_LASR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_LASR*)0xF0037224u)
/** Alias (User Manual Name) for INT_CH2_LASR.
* To use register names with standard convension, please use INT_CH2_LASR.
*/
#define INT_LASR2 (INT_CH2_LASR)

/** \brief 228, Error Capture Register 2, related to ICU2 */
#define INT_CH2_ECR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_ECR*)0xF0037228u)
/** Alias (User Manual Name) for INT_CH2_ECR.
* To use register names with standard convension, please use INT_CH2_ECR.
*/
#define INT_ECR2 (INT_CH2_ECR)

/** \brief 230, Latest Winning Service Request Register 3, related to ICU3 */
#define INT_CH3_LWSR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_LWSR*)0xF0037230u)
/** Alias (User Manual Name) for INT_CH3_LWSR.
* To use register names with standard convension, please use INT_CH3_LWSR.
*/
#define INT_LWSR3 (INT_CH3_LWSR)

/** \brief 234, Last Acknowledged Service Request Register 3, related to ICU3 */
#define INT_CH3_LASR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_LASR*)0xF0037234u)
/** Alias (User Manual Name) for INT_CH3_LASR.
* To use register names with standard convension, please use INT_CH3_LASR.
*/
#define INT_LASR3 (INT_CH3_LASR)

/** \brief 238, Error Capture Register 3, related to ICU3 */
#define INT_CH3_ECR /*lint --e(923, 9078)*/ (*(volatile Ifx_INT_CH_ECR*)0xF0037238u)
/** Alias (User Manual Name) for INT_CH3_ECR.
* To use register names with standard convension, please use INT_CH3_ECR.
*/
#define INT_ECR3 (INT_CH3_ECR)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXINT_REG_H */
