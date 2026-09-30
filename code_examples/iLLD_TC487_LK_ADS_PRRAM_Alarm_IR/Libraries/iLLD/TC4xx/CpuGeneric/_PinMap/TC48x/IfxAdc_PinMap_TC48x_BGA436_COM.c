/**
 * \file IfxAdc_PinMap_TC48x_BGA436_COM.c
 * \brief ADC  details
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#if defined(__TASKING__)
#pragma warning 508
#endif

#if defined(__ghs__)
#pragma ghs nowarning 96
#endif
#include "Ifx_PinMap.h"
#if defined(DEVICE_TC48X) && defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "IfxAdc_PinMap_TC48x_BGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN1_IN = {&MODULE_ADC, {NULL_PTR, 1}, Ifx_RxSel_a};

IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN21_IN = {&MODULE_ADC, {NULL_PTR, 21}, Ifx_RxSel_a};

IfxAdc_Dsadcn_In    IfxAdc_DSADCNA_AN3_IN = {&MODULE_ADC, {NULL_PTR, 3}, Ifx_RxSel_a};

IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_AN13_IN = {&MODULE_ADC, {NULL_PTR, 13}, Ifx_RxSel_b};

IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_AN15_IN = {&MODULE_ADC, {NULL_PTR, 15}, Ifx_RxSel_b};

IfxAdc_Dsadcn_In    IfxAdc_DSADCNB_P40_1_IN = {&MODULE_ADC, {&MODULE_P40, 1}, Ifx_RxSel_b};

IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN0_IN = {&MODULE_ADC, {NULL_PTR, 0}, Ifx_RxSel_a};

IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN20_IN = {&MODULE_ADC, {NULL_PTR, 20}, Ifx_RxSel_a};

IfxAdc_Dsadcp_In    IfxAdc_DSADCPA_AN2_IN = {&MODULE_ADC, {NULL_PTR, 2}, Ifx_RxSel_a};

IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_AN12_IN = {&MODULE_ADC, {NULL_PTR, 12}, Ifx_RxSel_b};

IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_AN14_IN = {&MODULE_ADC, {NULL_PTR, 14}, Ifx_RxSel_b};

IfxAdc_Dsadcp_In    IfxAdc_DSADCPB_P40_0_IN = {&MODULE_ADC, {&MODULE_P40, 0}, Ifx_RxSel_b};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL00_P02_6_OUT = {&MODULE_ADC, {&MODULE_P02, 6}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL00_P33_3_OUT = {&MODULE_ADC, {&MODULE_P33, 3}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL01_P02_7_OUT = {&MODULE_ADC, {&MODULE_P02, 7}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL01_P33_2_OUT = {&MODULE_ADC, {&MODULE_P33, 2}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL02_P02_8_OUT = {&MODULE_ADC, {&MODULE_P02, 8}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL02_P33_1_OUT = {&MODULE_ADC, {&MODULE_P33, 1}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL03_P02_9_OUT = {&MODULE_ADC, {&MODULE_P02, 9}, IfxPort_OutputIdx_alt7};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL03_P33_0_OUT = {&MODULE_ADC, {&MODULE_P33, 0}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL10_P00_6_OUT = {&MODULE_ADC, {&MODULE_P00, 6}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL10_P33_6_OUT = {&MODULE_ADC, {&MODULE_P33, 6}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL11_P00_7_OUT = {&MODULE_ADC, {&MODULE_P00, 7}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL11_P33_5_OUT = {&MODULE_ADC, {&MODULE_P33, 5}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL12_P00_8_OUT = {&MODULE_ADC, {&MODULE_P00, 8}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL12_P33_4_OUT = {&MODULE_ADC, {&MODULE_P33, 4}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL13_P00_9_OUT = {&MODULE_ADC, {&MODULE_P00, 9}, IfxPort_OutputIdx_alt4};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL13_P33_7_OUT = {&MODULE_ADC, {&MODULE_P33, 7}, IfxPort_OutputIdx_alt5};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL20_P01_5_OUT = {&MODULE_ADC, {&MODULE_P01, 5}, IfxPort_OutputIdx_alt2};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL21_P01_4_OUT = {&MODULE_ADC, {&MODULE_P01, 4}, IfxPort_OutputIdx_alt2};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL22_P01_7_OUT = {&MODULE_ADC, {&MODULE_P01, 7}, IfxPort_OutputIdx_alt2};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL23_P01_1_OUT = {&MODULE_ADC, {&MODULE_P01, 1}, IfxPort_OutputIdx_alt2};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL30_P00_12_OUT = {&MODULE_ADC, {&MODULE_P00, 12}, IfxPort_OutputIdx_alt2};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL31_P00_13_OUT = {&MODULE_ADC, {&MODULE_P00, 13}, IfxPort_OutputIdx_alt2};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL32_P00_14_OUT = {&MODULE_ADC, {&MODULE_P00, 14}, IfxPort_OutputIdx_alt2};

IfxAdc_Emuxctrl_Out IfxAdc_EMUXCTRL33_P00_15_OUT = {&MODULE_ADC, {&MODULE_P00, 15}, IfxPort_OutputIdx_alt2};

IfxAdc_Pwm_Out      IfxAdc_PWM0_P00_6_OUT = {&MODULE_ADC, {&MODULE_P00, 6}, IfxPort_OutputIdx_alt2};

IfxAdc_Pwm_Out      IfxAdc_PWM0_P02_1_OUT = {&MODULE_ADC, {&MODULE_P02, 1}, IfxPort_OutputIdx_alt4};

IfxAdc_Pwm_Out      IfxAdc_PWM0_P33_12_OUT = {&MODULE_ADC, {&MODULE_P33, 12}, IfxPort_OutputIdx_alt6};

IfxAdc_Pwm_Out      IfxAdc_PWM1_P00_5_OUT = {&MODULE_ADC, {&MODULE_P00, 5}, IfxPort_OutputIdx_alt2};

IfxAdc_Pwm_Out      IfxAdc_PWM1_P02_0_OUT = {&MODULE_ADC, {&MODULE_P02, 0}, IfxPort_OutputIdx_alt4};

IfxAdc_Pwm_Out      IfxAdc_PWM1_P33_11_OUT = {&MODULE_ADC, {&MODULE_P33, 11}, IfxPort_OutputIdx_alt6};

IfxAdc_Sign_In      IfxAdc_SIGN0_P32_7_IN = {&MODULE_ADC, {&MODULE_P32, 7}, Ifx_RxSel_a};

IfxAdc_Sign_In      IfxAdc_SIGN1_P33_13_IN = {&MODULE_ADC, {&MODULE_P33, 13}, Ifx_RxSel_a};



IfxAdc_Trig_In      IfxAdc_TRIG56_P02_0_IN = {&MODULE_ADC, {&MODULE_P02, 0}, Ifx_RxSel_a};

IfxAdc_Trig_In      IfxAdc_TRIG57_P02_1_IN = {&MODULE_ADC, {&MODULE_P02, 1}, Ifx_RxSel_a};

IfxAdc_Trig_In      IfxAdc_TRIG58_P02_7_IN = {&MODULE_ADC, {&MODULE_P02, 7}, Ifx_RxSel_a};

IfxAdc_Trig_In      IfxAdc_TRIG59_P02_8_IN = {&MODULE_ADC, {&MODULE_P02, 8}, Ifx_RxSel_a};

IfxAdc_Trig_In      IfxAdc_TRIG60_P33_7_IN = {&MODULE_ADC, {&MODULE_P33, 7}, Ifx_RxSel_a};

IfxAdc_Trig_In      IfxAdc_TRIG61_P23_1_IN = {&MODULE_ADC, {&MODULE_P23, 1}, Ifx_RxSel_a};

IfxAdc_Trig_In      IfxAdc_TRIG62_P20_9_IN = {&MODULE_ADC, {&MODULE_P20, 9}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH0_AN0_IN = {&MODULE_ADC, 0, 0, {NULL_PTR, 0}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH10_AN10_IN = {&MODULE_ADC, 0, 10, {NULL_PTR, 10}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH11_AN11_IN = {&MODULE_ADC, 0, 11, {NULL_PTR, 11}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH12_AN12_IN = {&MODULE_ADC, 0, 12, {NULL_PTR, 12}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH13_AN13_IN = {&MODULE_ADC, 0, 13, {NULL_PTR, 13}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH14_AN14_IN = {&MODULE_ADC, 0, 14, {NULL_PTR, 14}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH15_AN15_IN = {&MODULE_ADC, 0, 15, {NULL_PTR, 15}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH1_AN1_IN = {&MODULE_ADC, 0, 1, {NULL_PTR, 1}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH2_AN2_IN = {&MODULE_ADC, 0, 2, {NULL_PTR, 2}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH3_AN3_IN = {&MODULE_ADC, 0, 3, {NULL_PTR, 3}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH4_AN4_IN = {&MODULE_ADC, 0, 4, {NULL_PTR, 4}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH5_AN5_IN = {&MODULE_ADC, 0, 5, {NULL_PTR, 5}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH6_AN6_IN = {&MODULE_ADC, 0, 6, {NULL_PTR, 6}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH7_AN7_IN = {&MODULE_ADC, 0, 7, {NULL_PTR, 7}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH8_AN8_IN = {&MODULE_ADC, 0, 8, {NULL_PTR, 8}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC0CH9_AN9_IN = {&MODULE_ADC, 0, 9, {NULL_PTR, 9}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH0_AN4_IN = {&MODULE_ADC, 1, 0, {NULL_PTR, 4}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH10_AN22_IN = {&MODULE_ADC, 1, 10, {NULL_PTR, 22}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH11_AN23_IN = {&MODULE_ADC, 1, 11, {NULL_PTR, 23}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH12_P40_0_IN = {&MODULE_ADC, 1, 12, {&MODULE_P40, 0}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH13_P40_1_IN = {&MODULE_ADC, 1, 13, {&MODULE_P40, 1}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH14_P40_2_IN = {&MODULE_ADC, 1, 14, {&MODULE_P40, 2}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH15_P40_3_IN = {&MODULE_ADC, 1, 15, {&MODULE_P40, 3}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH1_AN5_IN = {&MODULE_ADC, 1, 1, {NULL_PTR, 5}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH2_AN6_IN = {&MODULE_ADC, 1, 2, {NULL_PTR, 6}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH3_AN7_IN = {&MODULE_ADC, 1, 3, {NULL_PTR, 7}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH4_AN16_IN = {&MODULE_ADC, 1, 4, {NULL_PTR, 16}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH5_P40_10_IN = {&MODULE_ADC, 1, 5, {&MODULE_P40, 10}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH6_P40_11_IN = {&MODULE_ADC, 1, 6, {&MODULE_P40, 11}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH7_P40_12_IN = {&MODULE_ADC, 1, 7, {&MODULE_P40, 12}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH8_AN20_IN = {&MODULE_ADC, 1, 8, {NULL_PTR, 20}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC1CH9_AN21_IN = {&MODULE_ADC, 1, 9, {NULL_PTR, 21}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH0_P00_12_IN = {&MODULE_ADC, 2, 0, {&MODULE_P00, 12}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH10_P00_2_IN = {&MODULE_ADC, 2, 10, {&MODULE_P00, 2}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH11_P00_1_IN = {&MODULE_ADC, 2, 11, {&MODULE_P00, 1}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH12_P01_5_IN = {&MODULE_ADC, 2, 12, {&MODULE_P01, 5}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH13_P01_4_IN = {&MODULE_ADC, 2, 13, {&MODULE_P01, 4}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH14_P01_3_IN = {&MODULE_ADC, 2, 14, {&MODULE_P01, 3}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH15_P02_11_IN = {&MODULE_ADC, 2, 15, {&MODULE_P02, 11}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH1_P00_11_IN = {&MODULE_ADC, 2, 1, {&MODULE_P00, 11}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH2_P00_10_IN = {&MODULE_ADC, 2, 2, {&MODULE_P00, 10}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH3_P00_9_IN = {&MODULE_ADC, 2, 3, {&MODULE_P00, 9}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH4_P00_8_IN = {&MODULE_ADC, 2, 4, {&MODULE_P00, 8}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH5_P00_7_IN = {&MODULE_ADC, 2, 5, {&MODULE_P00, 7}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH6_P00_6_IN = {&MODULE_ADC, 2, 6, {&MODULE_P00, 6}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH7_P00_5_IN = {&MODULE_ADC, 2, 7, {&MODULE_P00, 5}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH8_P00_4_IN = {&MODULE_ADC, 2, 8, {&MODULE_P00, 4}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC2CH9_P00_3_IN = {&MODULE_ADC, 2, 9, {&MODULE_P00, 3}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH0_P40_13_IN = {&MODULE_ADC, 3, 0, {&MODULE_P40, 13}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH10_P40_8_IN = {&MODULE_ADC, 3, 10, {&MODULE_P40, 8}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH11_P40_9_IN = {&MODULE_ADC, 3, 11, {&MODULE_P40, 9}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH12_AN40_IN = {&MODULE_ADC, 3, 12, {NULL_PTR, 40}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH13_AN41_IN = {&MODULE_ADC, 3, 13, {NULL_PTR, 41}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH14_AN42_IN = {&MODULE_ADC, 3, 14, {NULL_PTR, 42}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH15_AN43_IN = {&MODULE_ADC, 3, 15, {NULL_PTR, 43}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH1_P40_14_IN = {&MODULE_ADC, 3, 1, {&MODULE_P40, 14}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH2_AN30_IN = {&MODULE_ADC, 3, 2, {NULL_PTR, 30}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH3_AN31_IN = {&MODULE_ADC, 3, 3, {NULL_PTR, 31}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH4_P40_4_IN = {&MODULE_ADC, 3, 4, {&MODULE_P40, 4}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH5_P40_5_IN = {&MODULE_ADC, 3, 5, {&MODULE_P40, 5}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH6_AN34_IN = {&MODULE_ADC, 3, 6, {NULL_PTR, 34}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH7_AN35_IN = {&MODULE_ADC, 3, 7, {NULL_PTR, 35}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH8_P40_6_IN = {&MODULE_ADC, 3, 8, {&MODULE_P40, 6}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC3CH9_P40_7_IN = {&MODULE_ADC, 3, 9, {&MODULE_P40, 7}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH0_P02_0_IN = {&MODULE_ADC, 4, 0, {&MODULE_P02, 0}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH10_P02_9_IN = {&MODULE_ADC, 4, 10, {&MODULE_P02, 9}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH11_P02_10_IN = {&MODULE_ADC, 4, 11, {&MODULE_P02, 10}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH12_P02_12_IN = {&MODULE_ADC, 4, 12, {&MODULE_P02, 12}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH13_P02_13_IN = {&MODULE_ADC, 4, 13, {&MODULE_P02, 13}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH14_P02_14_IN = {&MODULE_ADC, 4, 14, {&MODULE_P02, 14}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH15_P02_15_IN = {&MODULE_ADC, 4, 15, {&MODULE_P02, 15}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH1_P02_1_IN = {&MODULE_ADC, 4, 1, {&MODULE_P02, 1}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH2_P02_3_IN = {&MODULE_ADC, 4, 2, {&MODULE_P02, 3}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH3_P02_4_IN = {&MODULE_ADC, 4, 3, {&MODULE_P02, 4}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH4_P02_5_IN = {&MODULE_ADC, 4, 4, {&MODULE_P02, 5}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH5_P02_6_IN = {&MODULE_ADC, 4, 5, {&MODULE_P02, 6}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH6_P02_7_IN = {&MODULE_ADC, 4, 6, {&MODULE_P02, 7}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH7_P02_8_IN = {&MODULE_ADC, 4, 7, {&MODULE_P02, 8}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH8_P01_6_IN = {&MODULE_ADC, 4, 8, {&MODULE_P01, 6}, Ifx_RxSel_a};

IfxAdc_TmadcCh_In   IfxAdc_Tmadc_TMADC4CH9_P01_7_IN = {&MODULE_ADC, 4, 9, {&MODULE_P01, 7}, Ifx_RxSel_a};

/** \addtogroup IfxLld_Adc__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxAdc_Dsadcn_In    *IfxAdc_Dsadcn_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_DSADCN_IN_NUM_ITEMS] = {
    {
        &IfxAdc_DSADCNA_AN1_IN,
        &IfxAdc_DSADCNA_AN3_IN,
        &IfxAdc_DSADCNA_AN21_IN,
        &IfxAdc_DSADCNB_AN13_IN,
        &IfxAdc_DSADCNB_AN15_IN,
        &IfxAdc_DSADCNB_P40_1_IN,
    },
};

IFX_CONST IfxAdc_Dsadcp_In    *IfxAdc_Dsadcp_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_DSADCP_IN_NUM_ITEMS] = {
    {
        &IfxAdc_DSADCPA_AN0_IN,
        &IfxAdc_DSADCPA_AN2_IN,
        &IfxAdc_DSADCPA_AN20_IN,
        &IfxAdc_DSADCPB_AN12_IN,
        &IfxAdc_DSADCPB_AN14_IN,
        &IfxAdc_DSADCPB_P40_0_IN,
    },
};

IFX_CONST IfxAdc_Emuxctrl_Out *IfxAdc_Emuxctrl_Out_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_EMUXCTRL_OUT_NUM_ITEMS] = {
    {
        &IfxAdc_EMUXCTRL10_P00_6_OUT,
        &IfxAdc_EMUXCTRL11_P00_7_OUT,
        &IfxAdc_EMUXCTRL12_P00_8_OUT,
        &IfxAdc_EMUXCTRL13_P00_9_OUT,
        &IfxAdc_EMUXCTRL30_P00_12_OUT,
        &IfxAdc_EMUXCTRL31_P00_13_OUT,
        &IfxAdc_EMUXCTRL32_P00_14_OUT,
        &IfxAdc_EMUXCTRL33_P00_15_OUT,
        &IfxAdc_EMUXCTRL23_P01_1_OUT,
        &IfxAdc_EMUXCTRL21_P01_4_OUT,
        &IfxAdc_EMUXCTRL20_P01_5_OUT,
        &IfxAdc_EMUXCTRL22_P01_7_OUT,
        &IfxAdc_EMUXCTRL00_P02_6_OUT,
        &IfxAdc_EMUXCTRL01_P02_7_OUT,
        &IfxAdc_EMUXCTRL02_P02_8_OUT,
        &IfxAdc_EMUXCTRL03_P02_9_OUT,
        &IfxAdc_EMUXCTRL03_P33_0_OUT,
        &IfxAdc_EMUXCTRL02_P33_1_OUT,
        &IfxAdc_EMUXCTRL01_P33_2_OUT,
        &IfxAdc_EMUXCTRL00_P33_3_OUT,
        &IfxAdc_EMUXCTRL12_P33_4_OUT,
        &IfxAdc_EMUXCTRL11_P33_5_OUT,
        &IfxAdc_EMUXCTRL10_P33_6_OUT,
        &IfxAdc_EMUXCTRL13_P33_7_OUT,
    },
};

IFX_CONST IfxAdc_Pwm_Out      *IfxAdc_Pwm_Out_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_PWM_OUT_NUM_ITEMS] = {
    {
        &IfxAdc_PWM1_P00_5_OUT,
        &IfxAdc_PWM0_P00_6_OUT,
        &IfxAdc_PWM1_P02_0_OUT,
        &IfxAdc_PWM0_P02_1_OUT,
        &IfxAdc_PWM1_P33_11_OUT,
        &IfxAdc_PWM0_P33_12_OUT,
    },
};

IFX_CONST IfxAdc_Sign_In      *IfxAdc_Sign_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_SIGN_IN_NUM_ITEMS] = {
    {
        &IfxAdc_SIGN0_P32_7_IN,
        &IfxAdc_SIGN1_P33_13_IN,
    },
};

IFX_CONST IfxAdc_TmadcCh_In   *IfxAdc_TmadcCh_In_pinTable[IFXADC_TMADC_PINMAP_NUM_MODULES][IFXADC_TMADC_PINMAP_NUM_CHANNELS][IFXADC_PINMAP_TMADCCH_IN_NUM_ITEMS] = {
    {
        {
            &IfxAdc_Tmadc_TMADC0CH0_AN0_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH1_AN1_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH2_AN2_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH3_AN3_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH4_AN4_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH5_AN5_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH6_AN6_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH7_AN7_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH8_AN8_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH9_AN9_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH10_AN10_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH11_AN11_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH12_AN12_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH13_AN13_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH14_AN14_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC0CH15_AN15_IN,
        },
    },
    {
        {
            &IfxAdc_Tmadc_TMADC1CH0_AN4_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH1_AN5_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH2_AN6_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH3_AN7_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH4_AN16_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH5_P40_10_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH6_P40_11_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH7_P40_12_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH8_AN20_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH9_AN21_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH10_AN22_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH11_AN23_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH12_P40_0_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH13_P40_1_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH14_P40_2_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC1CH15_P40_3_IN,
        },
    },
    {
        {
            &IfxAdc_Tmadc_TMADC2CH0_P00_12_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH1_P00_11_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH2_P00_10_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH3_P00_9_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH4_P00_8_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH5_P00_7_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH6_P00_6_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH7_P00_5_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH8_P00_4_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH9_P00_3_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH10_P00_2_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH11_P00_1_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH12_P01_5_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH13_P01_4_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH14_P01_3_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC2CH15_P02_11_IN,
        },
    },
    {
        {
            &IfxAdc_Tmadc_TMADC3CH0_P40_13_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH1_P40_14_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH2_AN30_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH3_AN31_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH4_P40_4_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH5_P40_5_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH6_AN34_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH7_AN35_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH8_P40_6_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH9_P40_7_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH10_P40_8_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH11_P40_9_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH12_AN40_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH13_AN41_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH14_AN42_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC3CH15_AN43_IN,
        },
    },
    {
        {
            &IfxAdc_Tmadc_TMADC4CH0_P02_0_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH1_P02_1_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH2_P02_3_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH3_P02_4_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH4_P02_5_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH5_P02_6_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH6_P02_7_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH7_P02_8_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH8_P01_6_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH9_P01_7_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH10_P02_9_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH11_P02_10_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH12_P02_12_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH13_P02_13_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH14_P02_14_IN,
        },
        {
            &IfxAdc_Tmadc_TMADC4CH15_P02_15_IN,
        },
    },
};

IFX_CONST IfxAdc_Trig_In      *IfxAdc_Trig_In_pinTable[IFXADC_PINMAP_NUM_MODULES][IFXADC_PINMAP_TRIG_IN_NUM_ITEMS] = {
    {
        &IfxAdc_TRIG56_P02_0_IN,
        &IfxAdc_TRIG57_P02_1_IN,
        &IfxAdc_TRIG58_P02_7_IN,
        &IfxAdc_TRIG59_P02_8_IN,
        &IfxAdc_TRIG62_P20_9_IN,
        &IfxAdc_TRIG61_P23_1_IN,
        &IfxAdc_TRIG60_P33_7_IN,
    },
};

/** \} */

#endif
