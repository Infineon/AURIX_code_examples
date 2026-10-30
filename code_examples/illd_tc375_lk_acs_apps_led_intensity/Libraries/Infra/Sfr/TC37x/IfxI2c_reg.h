/**
 * \file IfxI2c_reg.h
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
 * \defgroup IfxSfr_I2c_Registers_Cfg I2c address
 * \ingroup IfxSfr_I2c_Registers
 * 
 * \defgroup IfxSfr_I2c_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_I2c_Registers_Cfg
 *
 * \defgroup IfxSfr_I2c_Registers_Cfg_I2c0 2-I2C0
 * \ingroup IfxSfr_I2c_Registers_Cfg
 *
 *
 */
#ifndef IFXI2C_REG_H
#define IFXI2C_REG_H 1
/******************************************************************************/
#include "IfxI2c_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_I2c_Registers_Cfg_BaseAddress
 * \{  */

/** \brief I2C object */
#define MODULE_I2C0 /*lint --e(923, 9078)*/ ((*(Ifx_I2C*)0xF00C0000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_I2c_Registers_Cfg_I2c0
 * \{  */
/** \brief 0, Clock Control 1 Register */
#define I2C0_CLC1 /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_CLC1*)0xF00C0000u)

/** \brief 8, Module Identification Register */
#define I2C0_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ID*)0xF00C0008u)

/** \brief 10, RUN Control Register */
#define I2C0_RUNCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_RUNCTRL*)0xF00C0010u)

/** \brief 14, End Data Control Register */
#define I2C0_ENDDCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ENDDCTRL*)0xF00C0014u)

/** \brief 18, Fractional Divider Configuration Register */
#define I2C0_FDIVCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_FDIVCFG*)0xF00C0018u)

/** \brief 1C, Fractional Divider High-speed Mode Configuration Register */
#define I2C0_FDIVHIGHCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_FDIVHIGHCFG*)0xF00C001Cu)

/** \brief 20, Address Configuration Register */
#define I2C0_ADDRCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ADDRCFG*)0xF00C0020u)

/** \brief 24, Bus Status Register */
#define I2C0_BUSSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_BUSSTAT*)0xF00C0024u)

/** \brief 28, FIFO Configuration Register */
#define I2C0_FIFOCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_FIFOCFG*)0xF00C0028u)

/** \brief 2C, Maximum Received Packet Size Control Register */
#define I2C0_MRPSCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_MRPSCTRL*)0xF00C002Cu)

/** \brief 30, Received Packet Size Status Register */
#define I2C0_RPSSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_RPSSTAT*)0xF00C0030u)

/** \brief 34, Transmit Packet Size Control Register */
#define I2C0_TPSCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_TPSCTRL*)0xF00C0034u)

/** \brief 38, Filled FIFO Stages Status Register */
#define I2C0_FFSSTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_FFSSTAT*)0xF00C0038u)

/** \brief 40, Timing Configuration Register */
#define I2C0_TIMCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_TIMCFG*)0xF00C0040u)

/** \brief 60, Error Interrupt Request Source Mask Register */
#define I2C0_ERRIRQSM /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ERRIRQSM*)0xF00C0060u)

/** \brief 64, Error Interrupt Request Source Status Register */
#define I2C0_ERRIRQSS /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ERRIRQSS*)0xF00C0064u)

/** \brief 68, Error Interrupt Request Source Clear Register */
#define I2C0_ERRIRQSC /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ERRIRQSC*)0xF00C0068u)

/** \brief 70, Protocol Interrupt Request Source Mask Register */
#define I2C0_PIRQSM /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_PIRQSM*)0xF00C0070u)

/** \brief 74, Protocol Interrupt Request Source Status Register */
#define I2C0_PIRQSS /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_PIRQSS*)0xF00C0074u)

/** \brief 78, Protocol Interrupt Request Source Clear Register */
#define I2C0_PIRQSC /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_PIRQSC*)0xF00C0078u)

/** \brief 80, Raw Interrupt Status Register */
#define I2C0_RIS /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_RIS*)0xF00C0080u)

/** \brief 84, Interrupt Mask Control Register */
#define I2C0_IMSC /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_IMSC*)0xF00C0084u)

/** \brief 88, Masked Interrupt Status Register */
#define I2C0_MIS /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_MIS*)0xF00C0088u)

/** \brief 8C, Interrupt Clear Register */
#define I2C0_ICR /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ICR*)0xF00C008Cu)

/** \brief 90, Interrupt Set Register */
#define I2C0_ISR /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ISR*)0xF00C0090u)

/** \brief 8000, Transmission Data Register */
#define I2C0_TXD /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_TXD*)0xF00C8000u)

/** \brief C000, Reception Data Register */
#define I2C0_RXD /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_RXD*)0xF00CC000u)

/** \brief 0, Clock Control Register */
#define I2C0_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_CLC*)0xF00D0000u)

/** \brief 4, Module Identification Register */
#define I2C0_MODID /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_MODID*)0xF00D0004u)

/** \brief 8, General Purpose Control Register */
#define I2C0_GPCTL /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_GPCTL*)0xF00D0008u)

/** \brief C, Access Enable Register 0 */
#define I2C0_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ACCEN0*)0xF00D000Cu)

/** \brief 10, Access Enable Register 1 */
#define I2C0_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_ACCEN1*)0xF00D0010u)

/** \brief 14, Kernel Reset Register 0 */
#define I2C0_KRST0 /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_KRST0*)0xF00D0014u)

/** \brief 18, Kernel Reset Register 1 */
#define I2C0_KRST1 /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_KRST1*)0xF00D0018u)

/** \brief 1C, Kernel Reset Status Clear Register */
#define I2C0_KRSTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_I2C_KRSTCLR*)0xF00D001Cu)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXI2C_REG_H */
