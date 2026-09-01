/**
 * \file IfxAdc_PinMap_TC48x_BGA292_STD.h
 * \brief ADC  details
 * \ingroup IfxLld_Adc
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
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
 *
 * Version: MC_ACE_A3G_PRQ_Package_Pinning/v8.2.1.1.2
 * Document: TC48x_A21_Pin_Assignment_v0.2.6_20251118.xls 
 *
 * \defgroup IfxLld_Adc_Pinmap Adc Pinmap Structure
 * \ingroup IfxLld_Adc
 * \defgroup IfxLld_Adc__Pinmap Variables Pinmap Variables
 * \ingroup IfxLld_Adc_
 * \defgroup IfxLld_Adc__PinTables PinTables
 * \ingroup IfxLld_Adc_
 */

#ifndef IFXADC_PINMAP_TC48X_BGA292_STD_H
#define IFXADC_PINMAP_TC48X_BGA292_STD_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxAdc_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXADC_PINMAP_NUM_MODULES            1

#define IFXADC_PINMAP_DSADCN_IN_NUM_ITEMS    6

#define IFXADC_PINMAP_DSADCP_IN_NUM_ITEMS    6

#define IFXADC_PINMAP_EMUXCTRL_OUT_NUM_ITEMS 24

#define IFXADC_PINMAP_PWM_OUT_NUM_ITEMS      6

#define IFXADC_PINMAP_SIGN_IN_NUM_ITEMS      2

#define IFXADC_PINMAP_TRIG_IN_NUM_ITEMS 7

#define IFXADC_TMADC_PINMAP_NUM_MODULES      5

#define IFXADC_TMADC_PINMAP_NUM_CHANNELS     16

#define IFXADC_PINMAP_TMADCCH_IN_NUM_ITEMS   1

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN1_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN21_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN3_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_AN13_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_AN15_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_P40_1_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN0_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN20_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN2_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_AN12_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_AN14_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_P40_0_IN;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL00_P02_6_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL00_P33_3_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL01_P02_7_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL01_P33_2_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL02_P02_8_OUT;

/** \brief EMUX0 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL02_P33_1_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL03_P02_9_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL03_P33_0_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL10_P00_6_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL10_P33_6_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL11_P00_7_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL11_P33_5_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL12_P00_8_OUT;

/** \brief EMUX1 Control from TMADC to PORTS
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL12_P33_4_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL13_P00_9_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL13_P33_7_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL20_P01_5_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL21_P01_4_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL22_P01_7_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL30_P00_12_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM0_P00_6_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM0_P02_1_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM0_P33_12_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM1_P00_5_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM1_P02_0_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Pwm_Out      IfxAdc_PWM1_P33_11_OUT;

/** \brief
 */
IFX_EXTERN IfxAdc_Sign_In      IfxAdc_SIGN0_P32_7_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Sign_In      IfxAdc_SIGN1_P33_13_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG56_P02_0_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG57_P02_1_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG58_P02_7_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG59_P02_8_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG60_P33_7_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG61_P23_1_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_Trig_In      IfxAdc_TRIG62_P20_9_IN;

/** \brief Analog Input for TMADC0 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH0_AN0_IN;

/** \brief Analog Input for TMADC0 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH10_AN10_IN;

/** \brief Analog Input for TMADC0 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH11_AN11_IN;

/** \brief Analog Input for TMADC0 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH12_AN12_IN;

/** \brief Analog Input for TMADC0 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH13_AN13_IN;

/** \brief Analog Input for TMADC0 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH14_AN14_IN;

/** \brief Analog Input for TMADC0 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH15_AN15_IN;

/** \brief Analog Input for TMADC0 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH1_AN1_IN;

/** \brief Analog Input for TMADC0 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH2_AN2_IN;

/** \brief Analog Input for TMADC0 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH3_AN3_IN;

/** \brief Analog Input for TMADC0 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH4_AN4_IN;

/** \brief Analog Input for TMADC0 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH5_AN5_IN;

/** \brief Analog Input for TMADC0 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH6_AN6_IN;

/** \brief Analog Input for TMADC0 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH7_AN7_IN;

/** \brief Analog Input for TMADC0 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH8_AN8_IN;

/** \brief Analog Input for TMADC0 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH9_AN9_IN;

/** \brief Analog Input for TMADC1 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH0_AN4_IN;

/** \brief Analog Input for TMADC1 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH10_AN22_IN;

/** \brief Analog Input for TMADC1 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH11_AN23_IN;

/** \brief Analog Input for TMADC1 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH12_P40_0_IN;

/** \brief Analog Input for TMADC1 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH13_P40_1_IN;

/** \brief Analog Input for TMADC1 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH14_P40_2_IN;

/** \brief Analog Input for TMADC1 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH15_P40_3_IN;

/** \brief Analog Input for TMADC1 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH1_AN5_IN;

/** \brief Analog Input for TMADC1 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH2_AN6_IN;

/** \brief Analog Input for TMADC1 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH3_AN7_IN;

/** \brief Analog Input for TMADC1 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH4_AN16_IN;

/** \brief Analog Input for TMADC1 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH5_P40_10_IN;

/** \brief Analog Input for TMADC1 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH6_P40_11_IN;

/** \brief Analog Input for TMADC1 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH7_P40_12_IN;

/** \brief Analog Input for TMADC1 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH8_AN20_IN;

/** \brief Analog Input for TMADC1 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH9_AN21_IN;

/** \brief Analog Input for TMADC2 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH0_P00_12_IN;

/** \brief Analog Input for TMADC2 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH10_P00_2_IN;

/** \brief Analog Input for TMADC2 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH11_P00_1_IN;

/** \brief Analog Input for TMADC2 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH12_P01_5_IN;

/** \brief Analog Input for TMADC2 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH13_P01_4_IN;

/** \brief Analog Input for TMADC2 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH14_P01_3_IN;

/** \brief Analog Input for TMADC2 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH15_P02_11_IN;

/** \brief Analog Input for TMADC2 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH1_P00_11_IN;

/** \brief Analog Input for TMADC2 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH2_P00_10_IN;

/** \brief Analog Input for TMADC2 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH3_P00_9_IN;

/** \brief Analog Input for TMADC2 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH4_P00_8_IN;

/** \brief Analog Input for TMADC2 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH5_P00_7_IN;

/** \brief Analog Input for TMADC2 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH6_P00_6_IN;

/** \brief Analog Input for TMADC2 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH7_P00_5_IN;

/** \brief Analog Input for TMADC2 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH8_P00_4_IN;

/** \brief Analog Input for TMADC2 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH9_P00_3_IN;

/** \brief Analog Input for TMADC3 Channel 0
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH0_P40_13_IN;

/** \brief Analog Input for TMADC3 Channel 10
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH10_P40_8_IN;

/** \brief Analog Input for TMADC3 Channel 11
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH11_P40_9_IN;

/** \brief Analog Input for TMADC3 Channel 12
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH12_AN40_IN;

/** \brief Analog Input for TMADC3 Channel 13
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH13_AN41_IN;

/** \brief Analog Input for TMADC3 Channel 14
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH14_AN42_IN;

/** \brief Analog Input for TMADC3 Channel 15
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH15_AN43_IN;

/** \brief Analog Input for TMADC3 Channel 1
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH1_P40_14_IN;

/** \brief Analog Input for TMADC3 Channel 2
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH2_AN30_IN;

/** \brief Analog Input for TMADC3 Channel 3
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH3_AN31_IN;

/** \brief Analog Input for TMADC3 Channel 4
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH4_P40_4_IN;

/** \brief Analog Input for TMADC3 Channel 5
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH5_P40_5_IN;

/** \brief Analog Input for TMADC3 Channel 6
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH6_AN34_IN;

/** \brief Analog Input for TMADC3 Channel 7
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH7_AN35_IN;

/** \brief Analog Input for TMADC3 Channel 8
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH8_P40_6_IN;

/** \brief Analog Input for TMADC3 Channel 9
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH9_P40_7_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH0_P02_0_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH10_P02_9_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH11_P02_10_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH1_P02_1_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH2_P02_3_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH3_P02_4_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH4_P02_5_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH5_P02_6_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH6_P02_7_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH7_P02_8_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH8_P01_6_IN;

/** \brief
 */
IFX_EXTERN IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH9_P01_7_IN;

/** \addtogroup IfxLld_Adc__PinTables
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
/** \brief IfxAdc_Dsadcn_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Dsadcn_In    *IfxAdc_Dsadcn_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_DSADCN_IN_NUM_ITEMS];

/** \brief IfxAdc_Dsadcp_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Dsadcp_In    *IfxAdc_Dsadcp_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_DSADCP_IN_NUM_ITEMS];

/** \brief IfxAdc_Emuxctrl_Out Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Emuxctrl_Out *IfxAdc_Emuxctrl_Out_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_EMUXCTRL_OUT_NUM_ITEMS];

/** \brief IfxAdc_Pwm_Out Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Pwm_Out      *IfxAdc_Pwm_Out_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_PWM_OUT_NUM_ITEMS];

/** \brief IfxAdc_Sign_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Sign_In      *IfxAdc_Sign_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_SIGN_IN_NUM_ITEMS];

/** \brief IfxAdc_TmadcCh_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_TmadcCh_In   *IfxAdc_TmadcCh_In_pinTable[IFXADC_TMADC_PINMAP_NUM_MODULES][IFXADC_TMADC_PINMAP_NUM_CHANNELS][IFXADC_PINMAP_TMADCCH_IN_NUM_ITEMS];

/** \brief IfxAdc_Trig_In Table
 */
IFX_EXTERN IFX_CONST IfxAdc_Trig_In      *IfxAdc_Trig_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_TRIG_IN_NUM_ITEMS];

/** \} */

#endif /* IFXADC_PINMAP_TC48X_BGA292_STD_H */
