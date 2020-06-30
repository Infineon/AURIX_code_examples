/**
 * \file IfxGtm_regdef.h
 * \brief
 * \copyright Copyright (c) 2015 Infineon Technologies AG. All rights reserved.
 *
 * Version: TC23XADAS_UM_V1.1.R0
 * Specification: tc23xadas_um_sfrs_MCSFR.xml (Revision: UM_V1.1)
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Gtm Gtm
 * \ingroup IfxLld
 *
 * \defgroup IfxLld_Gtm_Bitfields Bitfields
 * \ingroup IfxLld_Gtm
 *
 * \defgroup IfxLld_Gtm_union Union
 * \ingroup IfxLld_Gtm
 *
 * \defgroup IfxLld_Gtm_struct Struct
 * \ingroup IfxLld_Gtm
 *
 */
#ifndef IFXGTM_REGDEF_H
#define IFXGTM_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Gtm_Bitfields
 * \{  */

/** \brief  Access Enable Register 0 */
typedef struct _Ifx_GTM_ACCEN0_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_GTM_ACCEN0_Bits;

/** \brief  Access Enable Register 1 */
typedef struct _Ifx_GTM_ACCEN1_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_GTM_ACCEN1_Bits;

/** \brief  ADC Trigger 0 Output Select 0 Register */
typedef struct _Ifx_GTM_ADCTRIG0OUT0_Bits
{
    Ifx_Strict_32Bit SEL0 : 4;                /**< \brief [3:0] Output Selection for ADC0 GTM connection (rw) */
    Ifx_Strict_32Bit SEL1 : 4;                /**< \brief [7:4] Output Selection for ADC1 GTM connection (rw) */
    Ifx_Strict_32Bit SEL2 : 4;                /**< \brief [11:8] Output Selection for ADC2 GTM connection (rw) */
    Ifx_Strict_32Bit SEL3 : 4;                /**< \brief [15:12] Output Selection for ADC3 GTM connection (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_ADCTRIG0OUT0_Bits;

/** \brief  ADC Trigger 1 Output Select 0 Register */
typedef struct _Ifx_GTM_ADCTRIG1OUT0_Bits
{
    Ifx_Strict_32Bit SEL0 : 4;                /**< \brief [3:0] Output Selection for ADC0 GTM connection (rw) */
    Ifx_Strict_32Bit SEL1 : 4;                /**< \brief [7:4] Output Selection for ADC1 GTM connection (rw) */
    Ifx_Strict_32Bit SEL2 : 4;                /**< \brief [11:8] Output Selection for ADC2 GTM connection (rw) */
    Ifx_Strict_32Bit SEL3 : 4;                /**< \brief [15:12] Output Selection for ADC3 GTM connection (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_ADCTRIG1OUT0_Bits;

/** \brief  GTM AEI Timeout Exception Address Register */
typedef struct _Ifx_GTM_AEI_ADDR_XPT_Bits
{
    Ifx_Strict_32Bit TO_ADDR : 20;            /**< \brief [19:0] AEI Timeout address (r) */
    Ifx_Strict_32Bit TO_W1R0 : 1;             /**< \brief [20:20] AEI Timeout Read/Write flag (r) */
    Ifx_Strict_32Bit reserved_21 : 11;        /**< \brief \internal Reserved */
} Ifx_GTM_AEI_ADDR_XPT_Bits;

/** \brief  GTM to SPB BRIDGE MODE */
typedef struct _Ifx_GTM_BRIDGE_MODE_Bits
{
    Ifx_Strict_32Bit BRG_MODE : 1;            /**< \brief [0:0] Defines the operation mode for the AEI bridge (rw) */
    Ifx_Strict_32Bit MSK_WR_RSP : 1;          /**< \brief [1:1] Mask write response (rw) */
    Ifx_Strict_32Bit reserved_2 : 6;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit MODE_UP_PGR : 1;         /**< \brief [8:8] Mode update in progress (r) */
    Ifx_Strict_32Bit BUFF_OVL : 1;            /**< \brief [9:9] Buffer overflow register (rwh) */
    Ifx_Strict_32Bit reserved_10 : 2;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit SYNC_INPUT_REG : 1;      /**< \brief [12:12] Additional Pipeline Stage in Synchronous Bridge Mode (rw) */
    Ifx_Strict_32Bit reserved_13 : 3;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit BRG_RST : 1;             /**< \brief [16:16] Bridge software reset (w) */
    Ifx_Strict_32Bit reserved_17 : 7;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit BUFF_DPT : 8;            /**< \brief [31:24] Buffer depth of AEI bridge (r) */
} Ifx_GTM_BRIDGE_MODE_Bits;

/** \brief  GTM to SPB BRIDGE PTR1 */
typedef struct _Ifx_GTM_BRIDGE_PTR1_Bits
{
    Ifx_Strict_32Bit NEW_TRAN_PTR : 5;        /**< \brief [4:0] New transaction pointer (r) */
    Ifx_Strict_32Bit FIRST_RSP_PTR : 5;       /**< \brief [9:5] First response pointer (r) */
    Ifx_Strict_32Bit TRAN_IN_PGR : 5;         /**< \brief [14:10] Transaction in progress pointer (acquire) (r) */
    Ifx_Strict_32Bit ABT_TRAN_PGR : 5;        /**< \brief [19:15] Aborted transaction in progress pointer (r) */
    Ifx_Strict_32Bit FBC : 6;                 /**< \brief [25:20] Free buffer count (r) */
    Ifx_Strict_32Bit RSP_TRAN_RDY : 6;        /**< \brief [31:26] Response transactions ready (r) */
} Ifx_GTM_BRIDGE_PTR1_Bits;

/** \brief  GTM to SPB BRIDGE PTR2 */
typedef struct _Ifx_GTM_BRIDGE_PTR2_Bits
{
    Ifx_Strict_32Bit TRAN_IN_PGR2 : 5;        /**< \brief [4:0] Transaction in progress pointer (aquire2) (r) */
    Ifx_Strict_32Bit reserved_5 : 27;         /**< \brief \internal Reserved */
} Ifx_GTM_BRIDGE_PTR2_Bits;

/** \brief  Clock Control Register */
typedef struct _Ifx_GTM_CLC_Bits
{
    Ifx_Strict_32Bit DISR : 1;                /**< \brief [0:0] Module Disable Request Bit (rw) */
    Ifx_Strict_32Bit DISS : 1;                /**< \brief [1:1] Module Disable Status Bit (r) */
    Ifx_Strict_32Bit reserved_2 : 1;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit EDIS : 1;                /**< \brief [3:3] Sleep Mode Enable Control (rw) */
    Ifx_Strict_32Bit reserved_4 : 28;         /**< \brief \internal Reserved */
} Ifx_GTM_CLC_Bits;

/** \brief  CMU Control For Clock Source Register */
typedef struct _Ifx_GTM_CMU_CLK0_5_CTRL_Bits
{
    Ifx_Strict_32Bit CLK_CNT : 24;            /**< \brief [23:0] Clock count Defines count value for the clock divider of clock source CMU_CLK[x] (x:0...5) (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_CMU_CLK0_5_CTRL_Bits;

/** \brief  CMU Control For Clock Source 6 Register */
typedef struct _Ifx_GTM_CMU_CLK_6_CTRL_Bits
{
    Ifx_Strict_32Bit CLK_CNT : 24;            /**< \brief [23:0] Clock count. Define count value for the clock divider of clock source CMU_CLK6 (rw) */
    Ifx_Strict_32Bit CLK6_SEL : 1;            /**< \brief [24:24] Clock source selection for CMU_CLK6 (rw) */
    Ifx_Strict_32Bit reserved_25 : 7;         /**< \brief \internal Reserved */
} Ifx_GTM_CMU_CLK_6_CTRL_Bits;

/** \brief  CMU Control For Clock Source 7 Register */
typedef struct _Ifx_GTM_CMU_CLK_7_CTRL_Bits
{
    Ifx_Strict_32Bit CLK_CNT : 24;            /**< \brief [23:0] Clock count. Define count value for the clock divider of clock source CMU_CLK7 (rw) */
    Ifx_Strict_32Bit CLK7_SEL : 1;            /**< \brief [24:24] Clock source selection for CMU_CLK7 (rw) */
    Ifx_Strict_32Bit reserved_25 : 7;         /**< \brief \internal Reserved */
} Ifx_GTM_CMU_CLK_7_CTRL_Bits;

/** \brief  CMU Clock Enable Register */
typedef struct _Ifx_GTM_CMU_CLK_EN_Bits
{
    Ifx_Strict_32Bit EN_CLK0 : 2;             /**< \brief [1:0] Enable clock source 0 (rw) */
    Ifx_Strict_32Bit EN_CLK1 : 2;             /**< \brief [3:2] Enable clock source 1 (rw) */
    Ifx_Strict_32Bit EN_CLK2 : 2;             /**< \brief [5:4] Enable clock source 2 (rw) */
    Ifx_Strict_32Bit EN_CLK3 : 2;             /**< \brief [7:6] Enable clock source 3 (rw) */
    Ifx_Strict_32Bit EN_CLK4 : 2;             /**< \brief [9:8] Enable clock source 4 (rw) */
    Ifx_Strict_32Bit EN_CLK5 : 2;             /**< \brief [11:10] Enable clock source 5 (rw) */
    Ifx_Strict_32Bit EN_CLK6 : 2;             /**< \brief [13:12] Enable clock source 6 (rw) */
    Ifx_Strict_32Bit EN_CLK7 : 2;             /**< \brief [15:14] Enable clock source 7 (rw) */
    Ifx_Strict_32Bit EN_ECLK0 : 2;            /**< \brief [17:16] Enable ECLK 0 generation subunit (rw) */
    Ifx_Strict_32Bit EN_ECLK1 : 2;            /**< \brief [19:18] Enable ECLK 1 generation subunit (rw) */
    Ifx_Strict_32Bit EN_ECLK2 : 2;            /**< \brief [21:20] Enable ECLK 2 generation subunit (rw) */
    Ifx_Strict_32Bit EN_FXCLK : 2;            /**< \brief [23:22] Enable all CMU_FXCLK (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_CMU_CLK_EN_Bits;

/** \brief  CMU External Clock Control Denominator Register */
typedef struct _Ifx_GTM_CMU_ECLK_DEN_Bits
{
    Ifx_Strict_32Bit ECLK_DEN : 24;           /**< \brief [23:0] Denominator for external clock divider (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_CMU_ECLK_DEN_Bits;

/** \brief  CMU External Clock Control Numerator Register */
typedef struct _Ifx_GTM_CMU_ECLK_NUM_Bits
{
    Ifx_Strict_32Bit ECLK_NUM : 24;           /**< \brief [23:0] Numerator for external clock divider (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_CMU_ECLK_NUM_Bits;

/** \brief  CMU FXCLK Control Register */
typedef struct _Ifx_GTM_CMU_FXCLK_CTRL_Bits
{
    Ifx_Strict_32Bit FXCLK_SEL : 4;           /**< \brief [3:0] Input clock selection for EN_FXCLK line (rw) */
    Ifx_Strict_32Bit reserved_4 : 28;         /**< \brief \internal Reserved */
} Ifx_GTM_CMU_FXCLK_CTRL_Bits;

/** \brief  CMU Global Clock Control Denominator Register */
typedef struct _Ifx_GTM_CMU_GCLK_DEN_Bits
{
    Ifx_Strict_32Bit GCLK_DEN : 24;           /**< \brief [23:0] Denominator for global clock divider (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_CMU_GCLK_DEN_Bits;

/** \brief  CMU Global Clock Control Numerator Register */
typedef struct _Ifx_GTM_CMU_GCLK_NUM_Bits
{
    Ifx_Strict_32Bit GCLK_NUM : 24;           /**< \brief [23:0] Numerator for global clock divider (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_CMU_GCLK_NUM_Bits;

/** \brief  GTM Global Control Register */
typedef struct _Ifx_GTM_CTRL_Bits
{
    Ifx_Strict_32Bit RF_PROT : 1;             /**< \brief [0:0] RST and FORCINT protection (rw) */
    Ifx_Strict_32Bit TO_MODE : 1;             /**< \brief [1:1] AEI Timeout mode (rw) */
    Ifx_Strict_32Bit reserved_2 : 2;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TO_VAL : 5;              /**< \brief [8:4] AEI Timeout value (rw) */
    Ifx_Strict_32Bit reserved_9 : 23;         /**< \brief \internal Reserved */
} Ifx_GTM_CTRL_Bits;

/** \brief  DTM Channel Control1 Register */
typedef struct _Ifx_GTM_DTM_CH_CTRL1_Bits
{
    Ifx_Strict_32Bit O1SEL_0 : 1;             /**< \brief [0:0] Output 1 select channel 0 (rw) */
    Ifx_Strict_32Bit reserved_1 : 2;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit SWAP_0 : 1;              /**< \brief [3:3] Swap outputs DTMi_CH[0]_OUT0 and DTMi_CH[0]_OUT1 (rw) */
    Ifx_Strict_32Bit O1F_0 : 2;               /**< \brief [5:4] Output 1 function channel 0 (rw) */
    Ifx_Strict_32Bit reserved_6 : 2;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit O1SEL_1 : 1;             /**< \brief [8:8] Output 1 select channel 1 (rw) */
    Ifx_Strict_32Bit I1SEL_1 : 1;             /**< \brief [9:9] Input 1 select channel 1 (rw) */
    Ifx_Strict_32Bit SH_EN_1 : 1;             /**< \brief [10:10] Shift enable channel 1 (rw) */
    Ifx_Strict_32Bit SWAP_1 : 1;              /**< \brief [11:11] Swap outputs DTMi_CH[1]_OUT0 and DTMi_CH[1]_OUT1 (rw) */
    Ifx_Strict_32Bit O1F_1 : 2;               /**< \brief [13:12] Output 1 function channel 1 (rw) */
    Ifx_Strict_32Bit reserved_14 : 2;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit O1SEL_2 : 1;             /**< \brief [16:16] Output 1 select channel 2 (rw) */
    Ifx_Strict_32Bit I1SEL_2 : 1;             /**< \brief [17:17] Input 1 select channel 2 (rw) */
    Ifx_Strict_32Bit SH_EN_2 : 1;             /**< \brief [18:18] Shift enable channel 2 (rw) */
    Ifx_Strict_32Bit SWAP_2 : 1;              /**< \brief [19:19] Swap outputs DTMi_CH[2]_OUT0 and DTMi_CH[2]_OUT1 (rw) */
    Ifx_Strict_32Bit O1F_2 : 2;               /**< \brief [21:20] Output 1 function channel 2 (rw) */
    Ifx_Strict_32Bit reserved_22 : 2;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit O1SEL_3 : 1;             /**< \brief [24:24] Output 1 select channel 3 (rw) */
    Ifx_Strict_32Bit I1SEL_3 : 1;             /**< \brief [25:25] Input 1 select channel 3 (rw) */
    Ifx_Strict_32Bit SH_EN_3 : 1;             /**< \brief [26:26] Shift enable channel 3 (rw) */
    Ifx_Strict_32Bit SWAP_3 : 1;              /**< \brief [27:27] Swap outputs DTMi_CH[3]_OUT0 and DTMi_CH[3]_OUT1 (rw) */
    Ifx_Strict_32Bit O1F_3 : 2;               /**< \brief [29:28] Output 1 function channel 3 (rw) */
    Ifx_Strict_32Bit reserved_30 : 2;         /**< \brief \internal Reserved */
} Ifx_GTM_DTM_CH_CTRL1_Bits;

/** \brief  DTM Channel Control2 Register */
typedef struct _Ifx_GTM_DTM_CH_CTRL2_Bits
{
    Ifx_Strict_32Bit POL0_0 : 1;              /**< \brief [0:0] Polarity on output 0 channel 0 (rw) */
    Ifx_Strict_32Bit OC0_0 : 1;               /**< \brief [1:1] Output 0 control channel 0 (rw) */
    Ifx_Strict_32Bit SL0_0 : 1;               /**< \brief [2:2] Signal level on output 0 channel 0 (rw) */
    Ifx_Strict_32Bit DT0_0 : 1;               /**< \brief [3:3] Dead time path enable on output 0 channel 0 (rw) */
    Ifx_Strict_32Bit POL1_0 : 1;              /**< \brief [4:4] Polarity on output 1 channel 0 (rw) */
    Ifx_Strict_32Bit OC1_0 : 1;               /**< \brief [5:5] Output 1 control channel 0 (rw) */
    Ifx_Strict_32Bit SL1_0 : 1;               /**< \brief [6:6] Signal level on output 1 channel 0 (rw) */
    Ifx_Strict_32Bit DT1_0 : 1;               /**< \brief [7:7] Dead time path enable on output 1 channel 0 (rw) */
    Ifx_Strict_32Bit POL0_1 : 1;              /**< \brief [8:8] Polarity on output 0 channel 1 (rw) */
    Ifx_Strict_32Bit OC0_1 : 1;               /**< \brief [9:9] Output 0 control channel 1 (rw) */
    Ifx_Strict_32Bit SL0_1 : 1;               /**< \brief [10:10] Signal level on output 0 channel 1 (rw) */
    Ifx_Strict_32Bit DT0_1 : 1;               /**< \brief [11:11] Dead time path enable on output 0 channel 1 (rw) */
    Ifx_Strict_32Bit POL1_1 : 1;              /**< \brief [12:12] Polarity on output 1 channel 1 (rw) */
    Ifx_Strict_32Bit OC1_1 : 1;               /**< \brief [13:13] Output 1 control channel 1 (rw) */
    Ifx_Strict_32Bit SL1_1 : 1;               /**< \brief [14:14] Signal level on output 1 channel 1 (rw) */
    Ifx_Strict_32Bit DT1_1 : 1;               /**< \brief [15:15] Dead time path enable on output 1 channel 1 (rw) */
    Ifx_Strict_32Bit POL0_2 : 1;              /**< \brief [16:16] Polarity on output 0 channel 2 (rw) */
    Ifx_Strict_32Bit OC0_2 : 1;               /**< \brief [17:17] Output 0 control channel 2 (rw) */
    Ifx_Strict_32Bit SL0_2 : 1;               /**< \brief [18:18] Signal level on output 0 channel 2 (rw) */
    Ifx_Strict_32Bit DT0_2 : 1;               /**< \brief [19:19] Dead time path enable on output 0 channel 2 (rw) */
    Ifx_Strict_32Bit POL1_2 : 1;              /**< \brief [20:20] Polarity on output 1 channel 2 (rw) */
    Ifx_Strict_32Bit OC1_2 : 1;               /**< \brief [21:21] Output 1 control channel 2 (rw) */
    Ifx_Strict_32Bit SL1_2 : 1;               /**< \brief [22:22] Signal level on output 1 channel 2 (rw) */
    Ifx_Strict_32Bit DT1_2 : 1;               /**< \brief [23:23] Dead time path enable on output 1 channel 2 (rw) */
    Ifx_Strict_32Bit POL0_3 : 1;              /**< \brief [24:24] Polarity on output 0 channel 3 (rw) */
    Ifx_Strict_32Bit OC0_3 : 1;               /**< \brief [25:25] Output 0 control channel 3 (rw) */
    Ifx_Strict_32Bit SL0_3 : 1;               /**< \brief [26:26] Signal level on output 0 channel 3 (rw) */
    Ifx_Strict_32Bit DT0_3 : 1;               /**< \brief [27:27] Dead time path enable on output 0 channel 3 (rw) */
    Ifx_Strict_32Bit POL1_3 : 1;              /**< \brief [28:28] Polarity on output 1 channel 3 (rw) */
    Ifx_Strict_32Bit OC1_3 : 1;               /**< \brief [29:29] Output 1 control channel 3 (rw) */
    Ifx_Strict_32Bit SL1_3 : 1;               /**< \brief [30:30] Signal level on output 1 channel 3 (rw) */
    Ifx_Strict_32Bit DT1_3 : 1;               /**< \brief [31:31] Dead time path enable on output 1 channel 3 (rw) */
} Ifx_GTM_DTM_CH_CTRL2_Bits;

/** \brief  DTM Channel Control2 Shadow Register */
typedef struct _Ifx_GTM_DTM_CH_CTRL2_SR_Bits
{
    Ifx_Strict_32Bit POL0_0_SR : 1;           /**< \brief [0:0] Polarity on output 0 channel 0 shadow register (rw) */
    Ifx_Strict_32Bit OC0_0_SR : 1;            /**< \brief [1:1] Output 0 control channel 0 shadow register (rw) */
    Ifx_Strict_32Bit SL0_0_SR : 1;            /**< \brief [2:2] Signal level on output 0 channel 0 shadow register (rw) */
    Ifx_Strict_32Bit DT0_0_SR : 1;            /**< \brief [3:3] Dead time path enable on output 0 channel 0 shadow register (rw) */
    Ifx_Strict_32Bit POL1_0_SR : 1;           /**< \brief [4:4] Polarity on output 1 channel 0 shadow register (rw) */
    Ifx_Strict_32Bit OC1_0_SR : 1;            /**< \brief [5:5] Output 1 control channel 0 shadow register (rw) */
    Ifx_Strict_32Bit SL1_0_SR : 1;            /**< \brief [6:6] Signal level on output 1 channel 0 shadow register (rw) */
    Ifx_Strict_32Bit DT1_0_SR : 1;            /**< \brief [7:7] Dead time path enable on output 1 channel 0 shadow register (rw) */
    Ifx_Strict_32Bit POL0_1_SR : 1;           /**< \brief [8:8] Polarity on output 0 channel 1 shadow register (rw) */
    Ifx_Strict_32Bit OC0_1_SR : 1;            /**< \brief [9:9] Output 0 control channel 1 shadow register (rw) */
    Ifx_Strict_32Bit SL0_1_SR : 1;            /**< \brief [10:10] Signal level on output 0 channel 1 shadow register (rw) */
    Ifx_Strict_32Bit DT0_1_SR : 1;            /**< \brief [11:11] Dead time path enable on output 0 channel 1 shadow register (rw) */
    Ifx_Strict_32Bit POL1_1_SR : 1;           /**< \brief [12:12] Polarity on output 1 channel 1 shadow register (rw) */
    Ifx_Strict_32Bit OC1_1_SR : 1;            /**< \brief [13:13] Output 1 control channel 1 shadow register (rw) */
    Ifx_Strict_32Bit SL1_1_SR : 1;            /**< \brief [14:14] Signal level on output 1 channel 1 shadow register (rw) */
    Ifx_Strict_32Bit DT1_1_SR : 1;            /**< \brief [15:15] Dead time path enable on output 1 channel 1 shadow register (rw) */
    Ifx_Strict_32Bit POL0_2_SR : 1;           /**< \brief [16:16] Polarity on output 0 channel 2 shadow register (rw) */
    Ifx_Strict_32Bit OC0_2_SR : 1;            /**< \brief [17:17] Output 0 control channel 2 shadow register (rw) */
    Ifx_Strict_32Bit SL0_2_SR : 1;            /**< \brief [18:18] Signal level on output 0 channel 2 shadow register (rw) */
    Ifx_Strict_32Bit DT0_2_SR : 1;            /**< \brief [19:19] Dead time path enable on output 0 channel 2 shadow register (rw) */
    Ifx_Strict_32Bit POL1_2_SR : 1;           /**< \brief [20:20] Polarity on output 1 channel 2 shadow register (rw) */
    Ifx_Strict_32Bit OC1_2_SR : 1;            /**< \brief [21:21] Output 1 control channel 2 shadow register (rw) */
    Ifx_Strict_32Bit SL1_2_SR : 1;            /**< \brief [22:22] Signal level on output 1 channel 2 shadow register (rw) */
    Ifx_Strict_32Bit DT1_2_SR : 1;            /**< \brief [23:23] Dead time path enable on output 1 channel 2 shadow register (rw) */
    Ifx_Strict_32Bit POL0_3_SR : 1;           /**< \brief [24:24] Polarity on output 0 channel 3 shadow register (rw) */
    Ifx_Strict_32Bit OC0_3_SR : 1;            /**< \brief [25:25] Output 0 control channel 3 shadow register (rw) */
    Ifx_Strict_32Bit SL0_3_SR : 1;            /**< \brief [26:26] Signal level on output 0 channel 3 shadow register (rw) */
    Ifx_Strict_32Bit DT0_3_SR : 1;            /**< \brief [27:27] Dead time path enable on output 0 channel 3 shadow register (rw) */
    Ifx_Strict_32Bit POL1_3_SR : 1;           /**< \brief [28:28] Polarity on output 1 channel 3 shadow register (rw) */
    Ifx_Strict_32Bit OC1_3_SR : 1;            /**< \brief [29:29] Output 1 control channel 3 shadow register (rw) */
    Ifx_Strict_32Bit SL1_3_SR : 1;            /**< \brief [30:30] Signal level on output 1 channel 3 shadow register (rw) */
    Ifx_Strict_32Bit DT1_3_SR : 1;            /**< \brief [31:31] Dead time path enable on output 1 channel 3 shadow register (rw) */
} Ifx_GTM_DTM_CH_CTRL2_SR_Bits;

/** \brief  DTM Control Register */
typedef struct _Ifx_GTM_DTM_CTRL_Bits
{
    Ifx_Strict_32Bit CLK_SEL : 2;             /**< \brief [1:0] Clock source select (rw) */
    Ifx_Strict_32Bit reserved_2 : 2;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit UPD_MODE : 3;            /**< \brief [6:4] update mode (rw) */
    Ifx_Strict_32Bit reserved_7 : 25;         /**< \brief \internal Reserved */
} Ifx_GTM_DTM_CTRL_Bits;

/** \brief  DTM Channel Dead Time Value Register */
typedef struct _Ifx_GTM_DTM_DTV_CH_Bits
{
    Ifx_Strict_32Bit RELRISE : 10;            /**< \brief [9:0] Reload value for rising edge dead time (rw) */
    Ifx_Strict_32Bit reserved_10 : 6;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit RELFALL : 10;            /**< \brief [25:16] Reload value for falling edge dead time (rw) */
    Ifx_Strict_32Bit reserved_26 : 6;         /**< \brief \internal Reserved */
} Ifx_GTM_DTM_DTV_CH_Bits;

/** \brief  DTM Phase Shift Control Register */
typedef struct _Ifx_GTM_DTM_PS_CTRL_Bits
{
    Ifx_Strict_32Bit RELBLK : 10;             /**< \brief [9:0] Reload value blanking window (rw) */
    Ifx_Strict_32Bit reserved_10 : 6;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit PSU_IN_SEL : 1;          /**< \brief [16:16] PSU input select (rw) */
    Ifx_Strict_32Bit IN_POL : 1;              /**< \brief [17:17] Input polarity (rw) */
    Ifx_Strict_32Bit reserved_18 : 2;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit SHIFT_SEL : 2;           /**< \brief [21:20] Shift select (rw) */
    Ifx_Strict_32Bit reserved_22 : 10;        /**< \brief \internal Reserved */
} Ifx_GTM_DTM_PS_CTRL_Bits;

/** \brief  GTM Error Interrupt Enable Register */
typedef struct _Ifx_GTM_EIRQ_EN_Bits
{
    Ifx_Strict_32Bit AEI_TO_XPT_EIRQ_EN : 1;   /**< \brief [0:0] AEI_TO_XPT_EIRQ error interrupt enable (rw) */
    Ifx_Strict_32Bit AEI_USP_ADDR_EIRQ_EN : 1; /**< \brief [1:1] AEI_USP_ADDR_EIRQ error interrupt enable (rw) */
    Ifx_Strict_32Bit AEI_IM_ADDR_EIRQ_EN : 1;  /**< \brief [2:2] AEI_IM_ADDR_EIRQ error interrupt enable (rw) */
    Ifx_Strict_32Bit AEI_USP_BE_EIRQ_EN : 1;   /**< \brief [3:3] AEI_USP_BE_EIRQ error interrupt enable (rw) */
    Ifx_Strict_32Bit reserved_4 : 28;          /**< \brief \internal Reserved */
} Ifx_GTM_EIRQ_EN_Bits;

/** \brief  GTM Hardware Configuration */
typedef struct _Ifx_GTM_HW_CONF_Bits
{
    Ifx_Strict_32Bit GRSTEN : 1;                /**< \brief [0:0] Global Reset Enable (rh) */
    Ifx_Strict_32Bit BRIDGE_MODE_RST : 1;       /**< \brief [1:1] Bridge Mode after Reset (rh) */
    Ifx_Strict_32Bit AEI_IN : 1;                /**< \brief [2:2] Input Register in Bridge (rh) */
    Ifx_Strict_32Bit reserved_3 : 5;            /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TOM_OUT_RST : 1;           /**< \brief [8:8] TOM_OUT Reset Level (rh) */
    Ifx_Strict_32Bit TOM_TRIG_CHAIN : 3;        /**< \brief [11:9] TOM Trigger Chain length without Synchronisation (rh) */
    Ifx_Strict_32Bit reserved_12 : 4;           /**< \brief \internal Reserved */
    Ifx_Strict_32Bit IRQ_MODE_LEVEL : 1;        /**< \brief [16:16] IRQ Mode Level (rh) */
    Ifx_Strict_32Bit IRQ_MODE_PULSE : 1;        /**< \brief [17:17] IRQ Mode Pulse (rh) */
    Ifx_Strict_32Bit IRQ_MODE_PULSE_NOTIFY : 1; /**< \brief [18:18] IRQ Mode Pulse Notify (rh) */
    Ifx_Strict_32Bit IRQ_MODE_SINGLE_PULSE : 1; /**< \brief [19:19] IRQ Mode Single Pulse (rh) */
    Ifx_Strict_32Bit reserved_20 : 12;          /**< \brief \internal Reserved */
} Ifx_GTM_HW_CONF_Bits;

/** \brief  GTM Infrastructure Interrupt Group */
typedef struct _Ifx_GTM_ICM_IRQG_0_Bits
{
    Ifx_Strict_32Bit reserved_0 : 4;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit AEI_IRQ : 1;             /**< \brief [4:4] AEI_IRQ interrupt (rh) */
    Ifx_Strict_32Bit reserved_5 : 27;         /**< \brief \internal Reserved */
} Ifx_GTM_ICM_IRQG_0_Bits;

/** \brief  TIM Interrupt Group 0 */
typedef struct _Ifx_GTM_ICM_IRQG_2_Bits
{
    Ifx_Strict_32Bit TIM0_CH0_IRQ : 1;        /**< \brief [0:0] TIM0 shared interrupt channel 0 (rh) */
    Ifx_Strict_32Bit TIM0_CH1_IRQ : 1;        /**< \brief [1:1] TIM0 shared interrupt channel 1 (rh) */
    Ifx_Strict_32Bit TIM0_CH2_IRQ : 1;        /**< \brief [2:2] TIM0 shared interrupt channel 2 (rh) */
    Ifx_Strict_32Bit TIM0_CH3_IRQ : 1;        /**< \brief [3:3] TIM0 shared interrupt channel 3 (rh) */
    Ifx_Strict_32Bit TIM0_CH4_IRQ : 1;        /**< \brief [4:4] TIM0 shared interrupt channel 4 (rh) */
    Ifx_Strict_32Bit TIM0_CH5_IRQ : 1;        /**< \brief [5:5] TIM0 shared interrupt channel 5 (rh) */
    Ifx_Strict_32Bit TIM0_CH6_IRQ : 1;        /**< \brief [6:6] TIM0 shared interrupt channel 6 (rh) */
    Ifx_Strict_32Bit TIM0_CH7_IRQ : 1;        /**< \brief [7:7] TIM0 shared interrupt channel 7 (rh) */
    Ifx_Strict_32Bit reserved_8 : 24;         /**< \brief \internal Reserved */
} Ifx_GTM_ICM_IRQG_2_Bits;

/** \brief  TOM Interrupt Group 0 */
typedef struct _Ifx_GTM_ICM_IRQG_6_Bits
{
    Ifx_Strict_32Bit TOM0_CH0_IRQ : 1;        /**< \brief [0:0] TOM0 channel 0 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH1_IRQ : 1;        /**< \brief [1:1] TOM0 channel 1 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH2_IRQ : 1;        /**< \brief [2:2] TOM0 channel 2 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH3_IRQ : 1;        /**< \brief [3:3] TOM0 channel 3 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH4_IRQ : 1;        /**< \brief [4:4] TOM0 channel 4 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH5_IRQ : 1;        /**< \brief [5:5] TOM0 channel 5 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH6_IRQ : 1;        /**< \brief [6:6] TOM0 channel 6 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH7_IRQ : 1;        /**< \brief [7:7] TOM0 channel 7 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH8_IRQ : 1;        /**< \brief [8:8] TOM0 channel 8 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH9_IRQ : 1;        /**< \brief [9:9] TOM0 channel 9 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH10_IRQ : 1;       /**< \brief [10:10] TOM0 channel 10 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH11_IRQ : 1;       /**< \brief [11:11] TOM0 channel 11 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH12_IRQ : 1;       /**< \brief [12:12] TOM0 channel 12 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH13_IRQ : 1;       /**< \brief [13:13] TOM0 channel 13 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH14_IRQ : 1;       /**< \brief [14:14] TOM0 channel 14 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM0_CH15_IRQ : 1;       /**< \brief [15:15] TOM0 channel 15 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH0_IRQ : 1;        /**< \brief [16:16] TOM1 channel 0 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH1_IRQ : 1;        /**< \brief [17:17] TOM1 channel 1 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH2_IRQ : 1;        /**< \brief [18:18] TOM1 channel 2 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH3_IRQ : 1;        /**< \brief [19:19] TOM1 channel 3 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH4_IRQ : 1;        /**< \brief [20:20] TOM1 channel 4 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH5_IRQ : 1;        /**< \brief [21:21] TOM1 channel 5 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH6_IRQ : 1;        /**< \brief [22:22] TOM1 channel 6 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH7_IRQ : 1;        /**< \brief [23:23] TOM1 channel 7 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH8_IRQ : 1;        /**< \brief [24:24] TOM1 channel 8 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH9_IRQ : 1;        /**< \brief [25:25] TOM1 channel 9 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH10_IRQ : 1;       /**< \brief [26:26] TOM1 channel 10 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH11_IRQ : 1;       /**< \brief [27:27] TOM1 channel 11 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH12_IRQ : 1;       /**< \brief [28:28] TOM1 channel 12 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH13_IRQ : 1;       /**< \brief [29:29] TOM1 channel 13 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH14_IRQ : 1;       /**< \brief [30:30] TOM1 channel 14 shared interrupt (rh) */
    Ifx_Strict_32Bit TOM1_CH15_IRQ : 1;       /**< \brief [31:31] TOM1 channel 15 shared interrupt (rh) */
} Ifx_GTM_ICM_IRQG_6_Bits;

/** \brief  ICM Channel Error Interrupt 1 Register */
typedef struct _Ifx_GTM_ICM_IRQG_CEI1_Bits
{
    Ifx_Strict_32Bit TIM0_CH0_EIRQ : 1;       /**< \brief [0:0] TIM0 channel 0 error interrupt (rh) */
    Ifx_Strict_32Bit TIM0_CH1_EIRQ : 1;       /**< \brief [1:1] TIM0 channel 1 error interrupt (rh) */
    Ifx_Strict_32Bit TIM0_CH2_EIRQ : 1;       /**< \brief [2:2] TIM0 channel 2 error interrupt (rh) */
    Ifx_Strict_32Bit TIM0_CH3_EIRQ : 1;       /**< \brief [3:3] TIM0 channel 3 error interrupt (rh) */
    Ifx_Strict_32Bit TIM0_CH4_EIRQ : 1;       /**< \brief [4:4] TIM0 channel 4 error interrupt (rh) */
    Ifx_Strict_32Bit TIM0_CH5_EIRQ : 1;       /**< \brief [5:5] TIM0 channel 5 error interrupt (rh) */
    Ifx_Strict_32Bit TIM0_CH6_EIRQ : 1;       /**< \brief [6:6] TIM0 channel 6 error interrupt (rh) */
    Ifx_Strict_32Bit TIM0_CH7_EIRQ : 1;       /**< \brief [7:7] TIM0 channel 7 error interrupt (rh) */
    Ifx_Strict_32Bit reserved_8 : 24;         /**< \brief \internal Reserved */
} Ifx_GTM_ICM_IRQG_CEI1_Bits;

/** \brief  ICM Module Error Interrupt Register */
typedef struct _Ifx_GTM_ICM_IRQG_MEI_Bits
{
    Ifx_Strict_32Bit GTM_EIRQ : 1;            /**< \brief [0:0] GTM Error interrupt request (rh) */
    Ifx_Strict_32Bit reserved_1 : 3;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TIM0_EIRQ : 1;           /**< \brief [4:4] TIM0 error interrupt (rh) */
    Ifx_Strict_32Bit reserved_5 : 27;         /**< \brief \internal Reserved */
} Ifx_GTM_ICM_IRQG_MEI_Bits;

/** \brief  CAN Output Select Register */
typedef struct _Ifx_GTM_INOUTSEL_CAN_OUTSEL_Bits
{
    Ifx_Strict_32Bit SEL0 : 4;                /**< \brief [3:0] Output Selection for CAN GTM connection (rw) */
    Ifx_Strict_32Bit SEL1 : 4;                /**< \brief [7:4] Output Selection for CAN GTM connection (rw) */
    Ifx_Strict_32Bit SEL2 : 4;                /**< \brief [11:8] Output Selection for CAN GTM connection (rw) */
    Ifx_Strict_32Bit SEL3 : 4;                /**< \brief [15:12] Output Selection for CAN GTM connection (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_INOUTSEL_CAN_OUTSEL_Bits;

/** \brief  Timer Output Select Register */
typedef struct _Ifx_GTM_INOUTSEL_T_OUTSEL_Bits
{
    Ifx_Strict_32Bit SEL0 : 2;                /**< \brief [1:0] TOUT(n*16+0) Output Selection (rw) */
    Ifx_Strict_32Bit SEL1 : 2;                /**< \brief [3:2] TOUT(n*16+1) Output Selection (rw) */
    Ifx_Strict_32Bit SEL2 : 2;                /**< \brief [5:4] TOUT(n*16+2) Output Selection (rw) */
    Ifx_Strict_32Bit SEL3 : 2;                /**< \brief [7:6] TOUT(n*16+3) Output Selection (rw) */
    Ifx_Strict_32Bit SEL4 : 2;                /**< \brief [9:8] TOUT(n*16+4) Output Selection (rw) */
    Ifx_Strict_32Bit SEL5 : 2;                /**< \brief [11:10] TOUT(n*16+5) Output Selection (rw) */
    Ifx_Strict_32Bit SEL6 : 2;                /**< \brief [13:12] TOUT(n*16+6) Output Selection (rw) */
    Ifx_Strict_32Bit SEL7 : 2;                /**< \brief [15:14] TOUT(n*16+7) Output Selection (rw) */
    Ifx_Strict_32Bit SEL8 : 2;                /**< \brief [17:16] TOUT(n*16+8) Output Selection (rw) */
    Ifx_Strict_32Bit SEL9 : 2;                /**< \brief [19:18] TOUT(n*16+9) Output Selection (rw) */
    Ifx_Strict_32Bit SEL10 : 2;               /**< \brief [21:20] TOUT(n*16+10) Output Selection (rw) */
    Ifx_Strict_32Bit SEL11 : 2;               /**< \brief [23:22] TOUT(n*16+11) Output Selection (rw) */
    Ifx_Strict_32Bit SEL12 : 2;               /**< \brief [25:24] TOUT(n*16+12) Output Selection (rw) */
    Ifx_Strict_32Bit SEL13 : 2;               /**< \brief [27:26] TOUT(n*16+13) Output Selection (rw) */
    Ifx_Strict_32Bit SEL14 : 2;               /**< \brief [29:28] TOUT(n*16+14) Output Selection (rw) */
    Ifx_Strict_32Bit SEL15 : 2;               /**< \brief [31:30] TOUT(n*16+15) Output Selection (rw) */
} Ifx_GTM_INOUTSEL_T_OUTSEL_Bits;

/** \brief  TIM Input Select Register */
typedef struct _Ifx_GTM_INOUTSEL_TIM_INSEL_Bits
{
    Ifx_Strict_32Bit CH0SEL : 4;              /**< \brief [3:0] TIM Channel 0 Input Selection (rw) */
    Ifx_Strict_32Bit CH1SEL : 4;              /**< \brief [7:4] TIM Channel 1 Input Selection (rw) */
    Ifx_Strict_32Bit CH2SEL : 4;              /**< \brief [11:8] TIM Channel 2 Input Selection (rw) */
    Ifx_Strict_32Bit CH3SEL : 4;              /**< \brief [15:12] TIM Channel 3 Input Selection (rw) */
    Ifx_Strict_32Bit CH4SEL : 4;              /**< \brief [19:16] TIM Channel 4 Input Selection (rw) */
    Ifx_Strict_32Bit CH5SEL : 4;              /**< \brief [23:20] TIM Channel 5 Input Selection (rw) */
    Ifx_Strict_32Bit CH6SEL : 4;              /**< \brief [27:24] TIM Channel 6 Input Selection (rw) */
    Ifx_Strict_32Bit CH7SEL : 4;              /**< \brief [31:28] TIM Channel 7 Input Selection (rw) */
} Ifx_GTM_INOUTSEL_TIM_INSEL_Bits;

/** \brief  GTM Interrupt Enable Register */
typedef struct _Ifx_GTM_IRQ_EN_Bits
{
    Ifx_Strict_32Bit AEI_TO_XPT_IRQ_EN : 1;   /**< \brief [0:0] AEI_TO_XPT_IRQ interrupt enable. (rw) */
    Ifx_Strict_32Bit AEI_USP_ADDR_IRQ_EN : 1; /**< \brief [1:1] AEI_USP_ADDR_IRQ interrupt enable. (rw) */
    Ifx_Strict_32Bit AEI_IM_ADDR_IRQ_EN : 1;  /**< \brief [2:2] AEI_IM_ADDR_IRQ interrupt enable. (rw) */
    Ifx_Strict_32Bit AEI_USP_BE_IRQ_EN : 1;   /**< \brief [3:3] AEI_USP_BE_IRQ interrupt enable. (rw) */
    Ifx_Strict_32Bit reserved_4 : 28;         /**< \brief \internal Reserved */
} Ifx_GTM_IRQ_EN_Bits;

/** \brief  GTM Software Interrupt Generation Register */
typedef struct _Ifx_GTM_IRQ_FORCINT_Bits
{
    Ifx_Strict_32Bit TRG_AEI_TO_XPT : 1;      /**< \brief [0:0] Trigger AEI_TO_XPT_IRQ interrupt by software. (w) */
    Ifx_Strict_32Bit TRG_AEI_USP_ADDR : 1;    /**< \brief [1:1] Trigger AEI_USP_ADDR_IRQ interrupt by software. (w) */
    Ifx_Strict_32Bit TRG_AEI_IM_ADDR : 1;     /**< \brief [2:2] Trigger AEI_IM_ADDR_IRQ interrupt by software. (w) */
    Ifx_Strict_32Bit TRG_AEI_USP_BE : 1;      /**< \brief [3:3] Trigger AEI_USP_BE_IRQ interrupt by software. (w) */
    Ifx_Strict_32Bit reserved_4 : 28;         /**< \brief \internal Reserved */
} Ifx_GTM_IRQ_FORCINT_Bits;

/** \brief  GTM Top Level Interrupts Mode Selection */
typedef struct _Ifx_GTM_IRQ_MODE_Bits
{
    Ifx_Strict_32Bit IRQ_MODE : 2;            /**< \brief [1:0] Interrupt strategy mode selection for the AEI timeout and address monitoring interrupts (rw) */
    Ifx_Strict_32Bit reserved_2 : 30;         /**< \brief \internal Reserved */
} Ifx_GTM_IRQ_MODE_Bits;

/** \brief  GTM Interrupt Notification Register */
typedef struct _Ifx_GTM_IRQ_NOTIFY_Bits
{
    Ifx_Strict_32Bit AEI_TO_XPT : 1;          /**< \brief [0:0] AEI Timeout exception occurred (rwh) */
    Ifx_Strict_32Bit AEI_USP_ADDR : 1;        /**< \brief [1:1] AEI Unsupported address interrupt (rwh) */
    Ifx_Strict_32Bit AEI_IM_ADDR : 1;         /**< \brief [2:2] AEI Illegal Module address interrupt (rwh) */
    Ifx_Strict_32Bit AEI_USP_BE : 1;          /**< \brief [3:3] AEI Unsupported byte enable interrupt (rwh) */
    Ifx_Strict_32Bit reserved_4 : 28;         /**< \brief \internal Reserved */
} Ifx_GTM_IRQ_NOTIFY_Bits;

/** \brief  Kernel Reset Register 0 */
typedef struct _Ifx_GTM_KRST0_Bits
{
    Ifx_Strict_32Bit RST : 1;                 /**< \brief [0:0] Kernel Reset (rwh) */
    Ifx_Strict_32Bit RSTSTAT : 1;             /**< \brief [1:1] Kernel Reset Status (rw) */
    Ifx_Strict_32Bit reserved_2 : 30;         /**< \brief \internal Reserved */
} Ifx_GTM_KRST0_Bits;

/** \brief  Kernel Reset Register 1 */
typedef struct _Ifx_GTM_KRST1_Bits
{
    Ifx_Strict_32Bit RST : 1;                 /**< \brief [0:0] Kernel Reset (rwh) */
    Ifx_Strict_32Bit reserved_1 : 31;         /**< \brief \internal Reserved */
} Ifx_GTM_KRST1_Bits;

/** \brief  Kernel Reset Status Clear Register */
typedef struct _Ifx_GTM_KRSTCLR_Bits
{
    Ifx_Strict_32Bit CLR : 1;                 /**< \brief [0:0] Kernel Reset Status Clear (w) */
    Ifx_Strict_32Bit reserved_1 : 31;         /**< \brief \internal Reserved */
} Ifx_GTM_KRSTCLR_Bits;

/** \brief  OCDS Control and Status */
typedef struct _Ifx_GTM_OCS_Bits
{
    Ifx_Strict_32Bit reserved_0 : 24;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit SUS : 4;                 /**< \brief [27:24] OCDS Suspend Control (rw) */
    Ifx_Strict_32Bit SUS_P : 1;               /**< \brief [28:28] SUS Write Protection (w) */
    Ifx_Strict_32Bit SUSSTA : 1;              /**< \brief [29:29] Suspend State (rh) */
    Ifx_Strict_32Bit reserved_30 : 2;         /**< \brief \internal Reserved */
} Ifx_GTM_OCS_Bits;

/** \brief  OCDS Debug Access Register */
typedef struct _Ifx_GTM_ODA_Bits
{
    Ifx_Strict_32Bit DDREN : 1;               /**< \brief [0:0] Destructive Debug Read Enable (rw) */
    Ifx_Strict_32Bit DREN : 1;                /**< \brief [1:1] Destructive Read Enable (rw) */
    Ifx_Strict_32Bit reserved_2 : 30;         /**< \brief \internal Reserved */
} Ifx_GTM_ODA_Bits;

/** \brief  OCDS TBU0 Trigger Register */
typedef struct _Ifx_GTM_OTBU0T_Bits
{
    Ifx_Strict_32Bit CV : 27;                 /**< \brief [26:0] Compare Value (rw) */
    Ifx_Strict_32Bit reserved_27 : 1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit CM : 2;                  /**< \brief [29:28] Compare Mode (rw) */
    Ifx_Strict_32Bit reserved_30 : 2;         /**< \brief \internal Reserved */
} Ifx_GTM_OTBU0T_Bits;

/** \brief  OCDS TBU1 Trigger Register */
typedef struct _Ifx_GTM_OTBU1T_Bits
{
    Ifx_Strict_32Bit CV : 24;                 /**< \brief [23:0] Compare Value (rw) */
    Ifx_Strict_32Bit reserved_24 : 4;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit EN : 1;                  /**< \brief [28:28] Enable (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_GTM_OTBU1T_Bits;

/** \brief  OCDS TBU2 Trigger Register */
typedef struct _Ifx_GTM_OTBU2T_Bits
{
    Ifx_Strict_32Bit CV : 24;                 /**< \brief [23:0] Compare Value (rw) */
    Ifx_Strict_32Bit reserved_24 : 4;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit EN : 1;                  /**< \brief [28:28] Enable (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_GTM_OTBU2T_Bits;

/** \brief  OCDS Trigger Set Control 0 Register */
typedef struct _Ifx_GTM_OTSC0_Bits
{
    Ifx_Strict_32Bit B0LMT : 3;               /**< \brief [2:0] OTGB0 TS16_IOS Low Byte Module Type (rw) */
    Ifx_Strict_32Bit reserved_3 : 1;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit B0LMI : 4;               /**< \brief [7:4] OTGB0 TS16_IOS Low Byte Module Instance (rw) */
    Ifx_Strict_32Bit B0HMT : 3;               /**< \brief [10:8] OTGB0 TS16_IOS High Byte Module Type (rw) */
    Ifx_Strict_32Bit reserved_11 : 1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit B0HMI : 4;               /**< \brief [15:12] OTGB0 TS16_IOS High Byte Module Instance (rw) */
    Ifx_Strict_32Bit B1LMT : 3;               /**< \brief [18:16] OTGB1 TS16_IOS Low Byte Module Type (rw) */
    Ifx_Strict_32Bit reserved_19 : 1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit B1LMI : 4;               /**< \brief [23:20] OTGB1 TS16_IOS Low Byte Module Instance (rw) */
    Ifx_Strict_32Bit B1HMT : 3;               /**< \brief [26:24] OTGB1 TS16_IOS High Byte Module Type (rw) */
    Ifx_Strict_32Bit reserved_27 : 1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit B1HMI : 4;               /**< \brief [31:28] OTGB1 TS16_IOS High Byte Module Instance (rw) */
} Ifx_GTM_OTSC0_Bits;

/** \brief  OCDS Trigger Set Select Register */
typedef struct _Ifx_GTM_OTSS_Bits
{
    Ifx_Strict_32Bit OTGB0 : 4;               /**< \brief [3:0] Trigger Set for OTGB0 (rw) */
    Ifx_Strict_32Bit reserved_4 : 4;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OTGB1 : 4;               /**< \brief [11:8] Trigger Set for OTGB1 (rw) */
    Ifx_Strict_32Bit reserved_12 : 4;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OTGB2 : 4;               /**< \brief [19:16] Trigger Set for OTGB2 (rw) */
    Ifx_Strict_32Bit reserved_20 : 12;        /**< \brief \internal Reserved */
} Ifx_GTM_OTSS_Bits;

/** \brief  GTM Version Control Register */
typedef struct _Ifx_GTM_REV_Bits
{
    Ifx_Strict_32Bit STEP : 8;                /**< \brief [7:0] Release Step (r) */
    Ifx_Strict_32Bit NO : 4;                  /**< \brief [11:8] Define delivery number of GTM specification (r) */
    Ifx_Strict_32Bit MINOR : 4;               /**< \brief [15:12] Define minor version number of GTM specification (r) */
    Ifx_Strict_32Bit MAJOR : 4;               /**< \brief [19:16] Define major version number of GTM specification (r) */
    Ifx_Strict_32Bit DEV_CODE0 : 4;           /**< \brief [23:20] Device encoding digit 0 (r) */
    Ifx_Strict_32Bit DEV_CODE1 : 4;           /**< \brief [27:24] Device encoding digit 1 (r) */
    Ifx_Strict_32Bit DEV_CODE2 : 4;           /**< \brief [31:28] Device encoding digit 2 (r) */
} Ifx_GTM_REV_Bits;

/** \brief  GTM Global Reset Register */
typedef struct _Ifx_GTM_RST_Bits
{
    Ifx_Strict_32Bit RST : 1;                 /**< \brief [0:0] GTM Reset (w) */
    Ifx_Strict_32Bit reserved_1 : 31;         /**< \brief \internal Reserved */
} Ifx_GTM_RST_Bits;

/** \brief  TBU Channel 0 Base Register */
typedef struct _Ifx_GTM_TBU_CH0_BASE_Bits
{
    Ifx_Strict_32Bit BASE : 27;               /**< \brief [26:0] Time base value for channel 0 (rw) */
    Ifx_Strict_32Bit reserved_27 : 5;         /**< \brief \internal Reserved */
} Ifx_GTM_TBU_CH0_BASE_Bits;

/** \brief  TBU Channel 0 Control Register */
typedef struct _Ifx_GTM_TBU_CH0_CTRL_Bits
{
    Ifx_Strict_32Bit LOW_RES : 1;             /**< \brief [0:0] TBU_CH0_BASE register resolution (rw) */
    Ifx_Strict_32Bit CH_CLK_SRC : 3;          /**< \brief [3:1] Clock source for channel x (x:0...2) time base counter (rw) */
    Ifx_Strict_32Bit reserved_4 : 28;         /**< \brief \internal Reserved */
} Ifx_GTM_TBU_CH0_CTRL_Bits;

/** \brief  TBU Channel 1 Base Register */
typedef struct _Ifx_GTM_TBU_CH1_BASE_Bits
{
    Ifx_Strict_32Bit BASE : 24;               /**< \brief [23:0] Time base value for channel x (x 1, 2) (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_TBU_CH1_BASE_Bits;

/** \brief  TBU Channel 1 Control Register */
typedef struct _Ifx_GTM_TBU_CH1_CTRL_Bits
{
    Ifx_Strict_32Bit CH_MODE : 1;             /**< \brief [0:0] Channel mode (rw) */
    Ifx_Strict_32Bit CH_CLK_SRC : 3;          /**< \brief [3:1] Clock source for channel x (x1...2) time base counter (rw) */
    Ifx_Strict_32Bit reserved_4 : 28;         /**< \brief \internal Reserved */
} Ifx_GTM_TBU_CH1_CTRL_Bits;

/** \brief  TBU Channel 2 Base Register */
typedef struct _Ifx_GTM_TBU_CH2_BASE_Bits
{
    Ifx_Strict_32Bit BASE : 24;               /**< \brief [23:0] Time base value for channel x (x 1, 2) (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_TBU_CH2_BASE_Bits;

/** \brief  TBU Channel 2 Control Register */
typedef struct _Ifx_GTM_TBU_CH2_CTRL_Bits
{
    Ifx_Strict_32Bit CH_MODE : 1;             /**< \brief [0:0] Channel mode (rw) */
    Ifx_Strict_32Bit CH_CLK_SRC : 3;          /**< \brief [3:1] Clock source for channel x (x1...2) time base counter (rw) */
    Ifx_Strict_32Bit reserved_4 : 28;         /**< \brief \internal Reserved */
} Ifx_GTM_TBU_CH2_CTRL_Bits;

/** \brief  TBU Global Channel Enable Register */
typedef struct _Ifx_GTM_TBU_CHEN_Bits
{
    Ifx_Strict_32Bit ENDIS_CH0 : 2;           /**< \brief [1:0] TBU channel 0 enable/disable control (rw) */
    Ifx_Strict_32Bit ENDIS_CH1 : 2;           /**< \brief [3:2] TBU channel 1 enable/disable control (rw) */
    Ifx_Strict_32Bit ENDIS_CH2 : 2;           /**< \brief [5:4] TBU channel 2 enable/disable control (rw) */
    Ifx_Strict_32Bit reserved_6 : 26;         /**< \brief \internal Reserved */
} Ifx_GTM_TBU_CHEN_Bits;

/** \brief  GTM TIM  AUX_IN_SRC */
typedef struct _Ifx_GTM_TIM_AUX_IN_SRC_Bits
{
    Ifx_Strict_32Bit SRC_CH0 : 1;             /**< \brief [0:0] Defines AUX_IN source of TIM0 channel 0 x=0 (rw) */
    Ifx_Strict_32Bit SRC_CH1 : 1;             /**< \brief [1:1] Defines AUX_IN source of TIM0 channel 1 x=1, see bit 0 (rw) */
    Ifx_Strict_32Bit SRC_CH2 : 1;             /**< \brief [2:2] Defines AUX_IN source of TIM0 channel 2 x=2, see bit 0 (rw) */
    Ifx_Strict_32Bit SRC_CH3 : 1;             /**< \brief [3:3] Defines AUX_IN source of TIM0 channel 3 x=3, see bit 0 (rw) */
    Ifx_Strict_32Bit SRC_CH4 : 1;             /**< \brief [4:4] Defines AUX_IN source of TIM0 channel 4 x=4, see bit 0 (rw) */
    Ifx_Strict_32Bit SRC_CH5 : 1;             /**< \brief [5:5] Defines AUX_IN source of TIM0 channel 5 x=5, see bit 0 (rw) */
    Ifx_Strict_32Bit SRC_CH6 : 1;             /**< \brief [6:6] Defines AUX_IN source of TIM0 channel 6 x=6, see bit 0 (rw) */
    Ifx_Strict_32Bit SRC_CH7 : 1;             /**< \brief [7:7] Defines AUX_IN source of TIM0 channel 7 x=7, see bit 0 (rw) */
    Ifx_Strict_32Bit reserved_8 : 24;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_AUX_IN_SRC_Bits;

/** \brief  TIM Channel SMU Counter Register */
typedef struct _Ifx_GTM_TIM_CH_CNT_Bits
{
    Ifx_Strict_32Bit CNT : 24;                /**< \brief [23:0] Actual SMU counter value (r) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_CNT_Bits;

/** \brief  TIM Channel SMU Shadow Counter Register */
typedef struct _Ifx_GTM_TIM_CH_CNTS_Bits
{
    Ifx_Strict_32Bit CNTS : 24;               /**< \brief [23:0] Counter shadow register (rw) */
    Ifx_Strict_32Bit ECNT : 8;                /**< \brief [31:24] Edge counter (r) */
} Ifx_GTM_TIM_CH_CNTS_Bits;

/** \brief  TIM Channel Control Register */
typedef struct _Ifx_GTM_TIM_CH_CTRL_Bits
{
    Ifx_Strict_32Bit TIM_EN : 1;              /**< \brief [0:0] TIM channel x (x:0...7) enable (rwh) */
    Ifx_Strict_32Bit TIM_MODE : 3;            /**< \brief [3:1] TIM channel x (x:0...7) mode (rw) */
    Ifx_Strict_32Bit OSM : 1;                 /**< \brief [4:4] One-shot mode (rw) */
    Ifx_Strict_32Bit reserved_5 : 1;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit CICTRL : 1;              /**< \brief [6:6] Channel Input Control (rw) */
    Ifx_Strict_32Bit TBU0x_SEL : 1;           /**< \brief [7:7] TBU_TS0 bits input select for TIM_CHx_GPRz (x: 0, 1) (rw) */
    Ifx_Strict_32Bit GPR0_SEL : 2;            /**< \brief [9:8] Selection for GPR0 register (rw) */
    Ifx_Strict_32Bit GPR1_SEL : 2;            /**< \brief [11:10] Selection for GPR1 register (rw) */
    Ifx_Strict_32Bit CNTS_SEL : 1;            /**< \brief [12:12] Selection for CNTS register (rw) */
    Ifx_Strict_32Bit DSL : 1;                 /**< \brief [13:13] Signal level control (rw) */
    Ifx_Strict_32Bit ISL : 1;                 /**< \brief [14:14] Ignore signal level (rw) */
    Ifx_Strict_32Bit ECNT_RESET : 1;          /**< \brief [15:15] Enables resetting the ECNT counter in periodic sampling mode (rw) */
    Ifx_Strict_32Bit FLT_EN : 1;              /**< \brief [16:16] Filter enable for channel x (x:0...7) (rw) */
    Ifx_Strict_32Bit FLT_CNT_FRQ : 2;         /**< \brief [18:17] Filter counter frequency select (rw) */
    Ifx_Strict_32Bit EXT_CAP_EN : 1;          /**< \brief [19:19] Enables external capture mode (rw) */
    Ifx_Strict_32Bit FLT_MODE_RE : 1;         /**< \brief [20:20] Filter mode for rising edge (rw) */
    Ifx_Strict_32Bit FLT_CTR_RE : 1;          /**< \brief [21:21] Filter counter mode for rising edge (rw) */
    Ifx_Strict_32Bit FLT_MODE_FE : 1;         /**< \brief [22:22] Filter mode for falling edge (rw) */
    Ifx_Strict_32Bit FLT_CTR_FE : 1;          /**< \brief [23:23] Filter counter mode for falling edge (rw) */
    Ifx_Strict_32Bit CLK_SEL : 3;             /**< \brief [26:24] CMU clock source select for channel (rw) */
    Ifx_Strict_32Bit FR_ECNT_OFL : 1;         /**< \brief [27:27] Extended Edge counter overflow behaviour (rw) */
    Ifx_Strict_32Bit EGPR0_SEL : 1;           /**< \brief [28:28] Extension of GPR0_SEL bit field (rw) */
    Ifx_Strict_32Bit EGPR1_SEL : 1;           /**< \brief [29:29] Extension of GPR1_SEL bit field (rw) */
    Ifx_Strict_32Bit TOCTRL : 2;              /**< \brief [31:30] Timeout control (rw) */
} Ifx_GTM_TIM_CH_CTRL_Bits;

/** \brief  TIM Channel Edge Counter Register */
typedef struct _Ifx_GTM_TIM_CH_ECNT_Bits
{
    Ifx_Strict_32Bit ECNT : 16;               /**< \brief [15:0] Edge counter (rh) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_ECNT_Bits;

/** \brief  TIM Channel External Capture Control Register */
typedef struct _Ifx_GTM_TIM_CH_ECTRL_Bits
{
    Ifx_Strict_32Bit EXT_CAP_SRC : 3;         /**< \brief [2:0] Defines selected source for triggering the EXT_CAPTURE functionality (rw) */
    Ifx_Strict_32Bit reserved_3 : 29;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_ECTRL_Bits;

/** \brief  TIM Channel Error Interrupt Enable Register */
typedef struct _Ifx_GTM_TIM_CH_EIRQ_EN_Bits
{
    Ifx_Strict_32Bit NEWVAL_EIRQ_EN : 1;      /**< \brief [0:0] TIM_NEWVALx_EIRQ error interrupt enable (rw) */
    Ifx_Strict_32Bit ECNTOFL_EIRQ_EN : 1;     /**< \brief [1:1] TIM_ECNTOFLx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit CNTOFL_EIRQ_EN : 1;      /**< \brief [2:2] TIM_CNTOFLx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit GPRzOFL_EIRQ_EN : 1;     /**< \brief [3:3] TIM_GPRzOFL_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit TODET_EIRQ_EN : 1;       /**< \brief [4:4] TIM_TODETx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit GLITCHDET_EIRQ_EN : 1;   /**< \brief [5:5] TIM_GLITCHDETx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit reserved_6 : 26;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_EIRQ_EN_Bits;

/** \brief  TIM Channel Filter Parameter 1 Register */
typedef struct _Ifx_GTM_TIM_CH_FLT_FE_Bits
{
    Ifx_Strict_32Bit FLT_FE : 24;             /**< \brief [23:0] Filter parameter for falling edge (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_FLT_FE_Bits;

/** \brief  GTM_TIM Channel Filter Parameter 0 Register */
typedef struct _Ifx_GTM_TIM_CH_FLT_RE_Bits
{
    Ifx_Strict_32Bit FLT_RE : 24;             /**< \brief [23:0] Filter parameter for rising edge (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_FLT_RE_Bits;

/** \brief  TIM Channel General Purpose 0 Register */
typedef struct _Ifx_GTM_TIM_CH_GPR0_Bits
{
    Ifx_Strict_32Bit GPR0 : 24;               /**< \brief [23:0] Input signal characteristic parameter 0 (r) */
    Ifx_Strict_32Bit ECNT : 8;                /**< \brief [31:24] Edge counter (r) */
} Ifx_GTM_TIM_CH_GPR0_Bits;

/** \brief  TIM Channel General Purpose 1 Register */
typedef struct _Ifx_GTM_TIM_CH_GPR1_Bits
{
    Ifx_Strict_32Bit GPR1 : 24;               /**< \brief [23:0] Input signal characteristic parameter 1 (r) */
    Ifx_Strict_32Bit ECNT : 8;                /**< \brief [31:24] Edge counter (r) */
} Ifx_GTM_TIM_CH_GPR1_Bits;

/** \brief  TIM Channel Interrupt Enable Register */
typedef struct _Ifx_GTM_TIM_CH_IRQ_EN_Bits
{
    Ifx_Strict_32Bit NEWVAL_IRQ_EN : 1;       /**< \brief [0:0] TIM_NEWVALx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit ECNTOFL_IRQ_EN : 1;      /**< \brief [1:1] TIM_ECNTOFLx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit CNTOFL_IRQ_EN : 1;       /**< \brief [2:2] TIM_CNTOFLx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit GPRzOFL_IRQ_EN : 1;      /**< \brief [3:3] TIM_GPRzOFLx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit TODET_IRQ_EN : 1;        /**< \brief [4:4] TIM_TODETx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit GLITCHDET_IRQ_EN : 1;    /**< \brief [5:5] TIM_GLITCHDETx_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit reserved_6 : 26;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_IRQ_EN_Bits;

/** \brief  TIM Channel Software Interrupt Force Register */
typedef struct _Ifx_GTM_TIM_CH_IRQ_FORCINT_Bits
{
    Ifx_Strict_32Bit TRG_NEWVAL : 1;          /**< \brief [0:0] Trigger NEWVAL bit in TIM_CHx_IRQ_NOTIFY register by software (w) */
    Ifx_Strict_32Bit TRG_ECNTOFL : 1;         /**< \brief [1:1] Trigger ECNTOFL bit in TIM_CHx_IRQ_NOTIFY register by software (w) */
    Ifx_Strict_32Bit TRG_CNTOFL : 1;          /**< \brief [2:2] Trigger CNTOFL bit in TIM_CHx_IRQ_NOTIFY register by software (w) */
    Ifx_Strict_32Bit TRG_GPRzOFL : 1;         /**< \brief [3:3] Trigger GPRzOFL bit in TIM_CHx_IRQ_NOTIFY register by software (w) */
    Ifx_Strict_32Bit TRG_TODET : 1;           /**< \brief [4:4] Trigger TODET bit in TIM_CHx_IRQ_NOTIFY register by software (w) */
    Ifx_Strict_32Bit TRG_GLITCHDET : 1;       /**< \brief [5:5] Trigger GLITCHDET bit in TIM_CHx_IRQ_NOTIFY register by software (w) */
    Ifx_Strict_32Bit reserved_6 : 26;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_IRQ_FORCINT_Bits;

/** \brief  TIM IRQ Mode Configuration Register */
typedef struct _Ifx_GTM_TIM_CH_IRQ_MODE_Bits
{
    Ifx_Strict_32Bit IRQ_MODE : 2;            /**< \brief [1:0] IRQ mode selection (rw) */
    Ifx_Strict_32Bit reserved_2 : 30;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_IRQ_MODE_Bits;

/** \brief  TIM Channel Interrupt Notification Register */
typedef struct _Ifx_GTM_TIM_CH_IRQ_NOTIFY_Bits
{
    Ifx_Strict_32Bit NEWVAL : 1;              /**< \brief [0:0] New measurement value detected by in channel x (x:0...7) (rwh) */
    Ifx_Strict_32Bit ECNTOFL : 1;             /**< \brief [1:1] counter overflow of channel x, (x:0...7) (rwh) */
    Ifx_Strict_32Bit CNTOFL : 1;              /**< \brief [2:2] SMU CNT counter overflow of channel x, (x:0...7) (rwh) */
    Ifx_Strict_32Bit GPRzOFL : 1;             /**< \brief [3:3] data overflow, old data not read out before new data has arrived at input pin, (x:0...7) (rwh) */
    Ifx_Strict_32Bit TODET : 1;               /**< \brief [4:4] Timeout reached for input signal of channel x, (x:0...7) (rwh) */
    Ifx_Strict_32Bit GLITCHDET : 1;           /**< \brief [5:5] Glitch detected on channel x, (x:0...7) (rwh) */
    Ifx_Strict_32Bit reserved_6 : 26;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_IRQ_NOTIFY_Bits;

/** \brief  TIM Channel TDUC Register */
typedef struct _Ifx_GTM_TIM_CH_TDUC_Bits
{
    Ifx_Strict_32Bit TO_CNT : 8;              /**< \brief [7:0] Current Timeout value for channel x (rh) */
    Ifx_Strict_32Bit reserved_8 : 24;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_TDUC_Bits;

/** \brief  TIM Channel TDUV Register */
typedef struct _Ifx_GTM_TIM_CH_TDUV_Bits
{
    Ifx_Strict_32Bit TOV : 8;                 /**< \brief [7:0] Time out duration for channel x (rw) */
    Ifx_Strict_32Bit reserved_8 : 20;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TCS : 3;                 /**< \brief [30:28] Timeout Clock selection (rw) */
    Ifx_Strict_32Bit reserved_31 : 1;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_CH_TDUV_Bits;

/** \brief  TIM_IN_SRC Long Name */
typedef struct _Ifx_GTM_TIM_IN_SRC_Bits
{
    Ifx_Strict_32Bit VAL_0 : 2;               /**< \brief [1:0] Value to be fed to Channel 0 (rw) */
    Ifx_Strict_32Bit MODE_0 : 2;              /**< \brief [3:2] Input source to Channel 0 (rw) */
    Ifx_Strict_32Bit VAL_1 : 2;               /**< \brief [5:4] Value to be fed to Channel 1 (rw) */
    Ifx_Strict_32Bit MODE_1 : 2;              /**< \brief [7:6] Input source to Channel 1 (rw) */
    Ifx_Strict_32Bit VAL_2 : 2;               /**< \brief [9:8] Value to be fed to Channel 2 (rw) */
    Ifx_Strict_32Bit MODE_2 : 2;              /**< \brief [11:10] Input source to Channel 2 (rw) */
    Ifx_Strict_32Bit VAL_3 : 2;               /**< \brief [13:12] Value to be fed to Channel 3 (rw) */
    Ifx_Strict_32Bit MODE_3 : 2;              /**< \brief [15:14] Input source to Channel 3 (rw) */
    Ifx_Strict_32Bit VAL_4 : 2;               /**< \brief [17:16] Value to be fed to Channel 4 (rw) */
    Ifx_Strict_32Bit MODE_4 : 2;              /**< \brief [19:18] Input source to Channel 4 (rw) */
    Ifx_Strict_32Bit VAL_5 : 2;               /**< \brief [21:20] Value to be fed to Channel 5 (rw) */
    Ifx_Strict_32Bit MODE_5 : 2;              /**< \brief [23:22] Input source to Channel 5 (rw) */
    Ifx_Strict_32Bit VAL_6 : 2;               /**< \brief [25:24] Value to be fed to Channel 6 (rw) */
    Ifx_Strict_32Bit MODE_6 : 2;              /**< \brief [27:26] Input source to Channel 6 (rw) */
    Ifx_Strict_32Bit VAL_7 : 2;               /**< \brief [29:28] Value to be fed to Channel 7 (rw) */
    Ifx_Strict_32Bit MODE_7 : 2;              /**< \brief [31:30] Input source to Channel 7 (rw) */
} Ifx_GTM_TIM_IN_SRC_Bits;

/** \brief  TIM Input Value Register */
typedef struct _Ifx_GTM_TIM_INP_VAL_Bits
{
    Ifx_Strict_32Bit F_OUT : 8;               /**< \brief [7:0] Signals after TIM filter unit (rw) */
    Ifx_Strict_32Bit F_IN : 8;                /**< \brief [15:8] Signals after TINPSRC selection; before TIM filter unit (rw) */
    Ifx_Strict_32Bit TIM_IN : 8;              /**< \brief [23:16] Signals after TIM input signal synchronisation (rw) */
    Ifx_Strict_32Bit reserved_24 : 8;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_INP_VAL_Bits;

/** \brief  TIM Global Software Reset Register */
typedef struct _Ifx_GTM_TIM_RST_Bits
{
    Ifx_Strict_32Bit RST_CH0 : 1;             /**< \brief [0:0] Software reset of channel 0 (w) */
    Ifx_Strict_32Bit RST_CH1 : 1;             /**< \brief [1:1] Software reset of channel 1 (w) */
    Ifx_Strict_32Bit RST_CH2 : 1;             /**< \brief [2:2] Software reset of channel 2 (w) */
    Ifx_Strict_32Bit RST_CH3 : 1;             /**< \brief [3:3] Software reset of channel 3 (w) */
    Ifx_Strict_32Bit RST_CH4 : 1;             /**< \brief [4:4] Software reset of channel 4 (w) */
    Ifx_Strict_32Bit RST_CH5 : 1;             /**< \brief [5:5] Software reset of channel 5 (w) */
    Ifx_Strict_32Bit RST_CH6 : 1;             /**< \brief [6:6] Software reset of channel 6 (w) */
    Ifx_Strict_32Bit RST_CH7 : 1;             /**< \brief [7:7] Software reset of channel 7 (w) */
    Ifx_Strict_32Bit reserved_8 : 24;         /**< \brief \internal Reserved */
} Ifx_GTM_TIM_RST_Bits;

/** \brief  TOM Channel CCU0 Compare Register */
typedef struct _Ifx_GTM_TOM_CH_CM0_Bits
{
    Ifx_Strict_32Bit CM0 : 16;                /**< \brief [15:0] TOM CCU0 compare register (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_CM0_Bits;

/** \brief  TOM Channel CCU1 Compare Register */
typedef struct _Ifx_GTM_TOM_CH_CM1_Bits
{
    Ifx_Strict_32Bit CM1 : 16;                /**< \brief [15:0] TOM CCU1 compare register (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_CM1_Bits;

/** \brief  TOM Channel CCU0 Counter Register */
typedef struct _Ifx_GTM_TOM_CH_CN0_Bits
{
    Ifx_Strict_32Bit CN0 : 16;                /**< \brief [15:0] TOM CCU0 counter register (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_CN0_Bits;

/** \brief  TOM Channel Control Register’ */
typedef struct _Ifx_GTM_TOM_CH_CTRL_Bits
{
    Ifx_Strict_32Bit reserved_0 : 11;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit SL : 1;                  /**< \brief [11:11] Signal level for duty cycle (rw) */
    Ifx_Strict_32Bit CLK_SRC_SR : 3;          /**< \brief [14:12] Clock source select for channel (rw) */
    Ifx_Strict_32Bit reserved_15 : 5;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit RST_CCU0 : 1;            /**< \brief [20:20] Reset source of CCU0 (rw) */
    Ifx_Strict_32Bit OSM_TRIG : 1;            /**< \brief [21:21] Enable Trigger of one-Shot Pulse by trigger signal OSM_TRIG (rw) */
    Ifx_Strict_32Bit EXT_TRIG : 1;            /**< \brief [22:22] Select TIM_EXT_CAPTURE(x) as Trigger Signal (rw) */
    Ifx_Strict_32Bit EXTTRIGOUT : 1;          /**< \brief [23:23] Select TIM_EXT_CAPTURE(x) as Potential OUTPUT Signal TRIG_[x] (rw) */
    Ifx_Strict_32Bit TRIGOUT : 1;             /**< \brief [24:24] Trigger output selection (output signal TRIG_[x]) of module TOM_CH[x] (rw) */
    Ifx_Strict_32Bit reserved_25 : 1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OSM : 1;                 /**< \brief [26:26] One-shot mode (rw) */
    Ifx_Strict_32Bit BITREV : 1;              /**< \brief [27:27] Bit-reversing of output of counter register CN0 (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_CTRL_Bits;

/** \brief  TOM Channel Interrupt Enable Register */
typedef struct _Ifx_GTM_TOM_CH_IRQ_EN_Bits
{
    Ifx_Strict_32Bit CCU0TC_IRQ_EN : 1;       /**< \brief [0:0] TOM_CCU0TC_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit CCU1TC_IRQ_EN : 1;       /**< \brief [1:1] TOM_CCU1TC_IRQ interrupt enable (rw) */
    Ifx_Strict_32Bit reserved_2 : 30;         /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_IRQ_EN_Bits;

/** \brief  TOM Channel Software Interrupt Generation Register */
typedef struct _Ifx_GTM_TOM_CH_IRQ_FORCINT_Bits
{
    Ifx_Strict_32Bit TRG_CCU0TC0 : 1;         /**< \brief [0:0] Trigger TOM_CCU0TC0_IRQ interrupt by software (w) */
    Ifx_Strict_32Bit TRG_CCU1TC0 : 1;         /**< \brief [1:1] Trigger TOM_CCU1TC0_IRQ interrupt by software (w) */
    Ifx_Strict_32Bit reserved_2 : 30;         /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_IRQ_FORCINT_Bits;

/** \brief  TOM IRQ Mode Configuration Register */
typedef struct _Ifx_GTM_TOM_CH_IRQ_MODE_Bits
{
    Ifx_Strict_32Bit IRQ_MODE : 2;            /**< \brief [1:0] IRQ mode selection (rw) */
    Ifx_Strict_32Bit reserved_2 : 30;         /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_IRQ_MODE_Bits;

/** \brief  TOM Channel Interrupt Notification Register */
typedef struct _Ifx_GTM_TOM_CH_IRQ_NOTIFY_Bits
{
    Ifx_Strict_32Bit CCU0TC : 1;              /**< \brief [0:0] CCU0 Trigger condition interrupt for channel x (rwh) */
    Ifx_Strict_32Bit CCU1TC : 1;              /**< \brief [1:1] CCU1 Trigger condition interrupt for channel x (rwh) */
    Ifx_Strict_32Bit reserved_2 : 30;         /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_IRQ_NOTIFY_Bits;

/** \brief  TOM Channel CCU0 Compare Shadow Register */
typedef struct _Ifx_GTM_TOM_CH_SR0_Bits
{
    Ifx_Strict_32Bit SR0 : 16;                /**< \brief [15:0] TOM channel x shadow register SR0 for update of compare register CM0 (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_SR0_Bits;

/** \brief  TOM Channel CCU1 Compare Shadow Register */
typedef struct _Ifx_GTM_TOM_CH_SR1_Bits
{
    Ifx_Strict_32Bit SR1 : 16;                /**< \brief [15:0] TOM channel x shadow register SR1 for update of compare register CM1 (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_SR1_Bits;

/** \brief  TOM Channel Status Register */
typedef struct _Ifx_GTM_TOM_CH_STAT_Bits
{
    Ifx_Strict_32Bit OL : 1;                  /**< \brief [0:0] Output level of output TOM_OUT(x) (r) */
    Ifx_Strict_32Bit reserved_1 : 31;         /**< \brief \internal Reserved */
} Ifx_GTM_TOM_CH_STAT_Bits;

/** \brief  TOM TGC0 Action Time Base Register */
typedef struct _Ifx_GTM_TOM_TGC0_ACT_TB_Bits
{
    Ifx_Strict_32Bit ACT_TB : 24;             /**< \brief [23:0] Time base value (rw) */
    Ifx_Strict_32Bit TB_TRIG : 1;             /**< \brief [24:24] Set trigger request (rwh) */
    Ifx_Strict_32Bit TBU_SEL : 2;             /**< \brief [26:25] Selection of time base used for comparison (rw) */
    Ifx_Strict_32Bit reserved_27 : 5;         /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC0_ACT_TB_Bits;

/** \brief  TOM TGC0 Enable/Disable Control Register */
typedef struct _Ifx_GTM_TOM_TGC0_ENDIS_CTRL_Bits
{
    Ifx_Strict_32Bit ENDIS_CTRL0 : 2;         /**< \brief [1:0] TOM channel 0 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL1 : 2;         /**< \brief [3:2] TOM channel 1 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL2 : 2;         /**< \brief [5:4] TOM channel 2 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL3 : 2;         /**< \brief [7:6] TOM channel 3 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL4 : 2;         /**< \brief [9:8] TOM channel 4 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL5 : 2;         /**< \brief [11:10] TOM channel 5 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL6 : 2;         /**< \brief [13:12] TOM channel 6 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL7 : 2;         /**< \brief [15:14] TOM channel 7 enable/disable update value (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC0_ENDIS_CTRL_Bits;

/** \brief  TOM TGC0 Enable/Disable Status Register */
typedef struct _Ifx_GTM_TOM_TGC0_ENDIS_STAT_Bits
{
    Ifx_Strict_32Bit ENDIS_STAT0 : 2;         /**< \brief [1:0] TOM channel 0 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT1 : 2;         /**< \brief [3:2] TOM channel 1 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT2 : 2;         /**< \brief [5:4] TOM channel 2 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT3 : 2;         /**< \brief [7:6] TOM channel 3 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT4 : 2;         /**< \brief [9:8] TOM channel 4 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT5 : 2;         /**< \brief [11:10] TOM channel 5 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT6 : 2;         /**< \brief [13:12] TOM channel 6 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT7 : 2;         /**< \brief [15:14] TOM channel 7 enable/disable (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC0_ENDIS_STAT_Bits;

/** \brief  TOM TGC0 Force Update Control Register */
typedef struct _Ifx_GTM_TOM_TGC0_FUPD_CTRL_Bits
{
    Ifx_Strict_32Bit FUPD_CTRL0 : 2;          /**< \brief [1:0] Force update of TOM channel 0 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL1 : 2;          /**< \brief [3:2] Force update of TOM channel 1 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL2 : 2;          /**< \brief [5:4] Force update of TOM channel 2 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL3 : 2;          /**< \brief [7:6] Force update of TOM channel 3 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL4 : 2;          /**< \brief [9:8] Force update of TOM channel 4 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL5 : 2;          /**< \brief [11:10] Force update of TOM channel 5 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL6 : 2;          /**< \brief [13:12] Force update of TOM channel 6 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL7 : 2;          /**< \brief [15:14] Force update of TOM channel 7 operation registers (rw) */
    Ifx_Strict_32Bit RSTCN0_CH0 : 2;          /**< \brief [17:16] Reset CN0 of channel 0 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH1 : 2;          /**< \brief [19:18] Reset CN0 of channel 1 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH2 : 2;          /**< \brief [21:20] Reset CN0 of channel 2 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH3 : 2;          /**< \brief [23:22] Reset CN0 of channel 3 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH4 : 2;          /**< \brief [25:24] Reset CN0 of channel 4 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH5 : 2;          /**< \brief [27:26] Reset CN0 of channel 5 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH6 : 2;          /**< \brief [29:28] Reset CN0 of channel 6 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH7 : 2;          /**< \brief [31:30] Reset CN0 of channel 7 on force update event (rw) */
} Ifx_GTM_TOM_TGC0_FUPD_CTRL_Bits;

/** \brief  TOM TGC0 Global Control Register */
typedef struct _Ifx_GTM_TOM_TGC0_GLB_CTRL_Bits
{
    Ifx_Strict_32Bit HOST_TRIG : 1;           /**< \brief [0:0] Trigger request signal (see TGC0, TGC1) to update the register ENDIS_STAT and OUTEN_STAT (w) */
    Ifx_Strict_32Bit reserved_1 : 7;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit RST_CH0 : 1;             /**< \brief [8:8] Software reset of channel 0 (w) */
    Ifx_Strict_32Bit RST_CH1 : 1;             /**< \brief [9:9] Software reset of channel 1 (w) */
    Ifx_Strict_32Bit RST_CH2 : 1;             /**< \brief [10:10] Software reset of channel 2 (w) */
    Ifx_Strict_32Bit RST_CH3 : 1;             /**< \brief [11:11] Software reset of channel 3 (w) */
    Ifx_Strict_32Bit RST_CH4 : 1;             /**< \brief [12:12] Software reset of channel 4 (w) */
    Ifx_Strict_32Bit RST_CH5 : 1;             /**< \brief [13:13] Software reset of channel 5 (w) */
    Ifx_Strict_32Bit RST_CH6 : 1;             /**< \brief [14:14] Software reset of channel 6 (w) */
    Ifx_Strict_32Bit RST_CH7 : 1;             /**< \brief [15:15] Software reset of channel 7 (w) */
    Ifx_Strict_32Bit UPEN_CTRL0 : 2;          /**< \brief [17:16] TOM channel 0 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
    Ifx_Strict_32Bit UPEN_CTRL1 : 2;          /**< \brief [19:18] TOM channel 1 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL2 : 2;          /**< \brief [21:20] TOM channel 2 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL3 : 2;          /**< \brief [23:22] TOM channel 3 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL4 : 2;          /**< \brief [25:24] TOM channel 4 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL5 : 2;          /**< \brief [27:26] TOM channel 5 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL6 : 2;          /**< \brief [29:28] TOM channel 6 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL7 : 2;          /**< \brief [31:30] TOM channel 7 enable update of register CM0, CM1 and CLK_SRC (rw) */
} Ifx_GTM_TOM_TGC0_GLB_CTRL_Bits;

/** \brief  TOM TGC0 Internal Trigger Control Register */
typedef struct _Ifx_GTM_TOM_TGC0_INT_TRIG_Bits
{
    Ifx_Strict_32Bit INT_TRIG0 : 2;           /**< \brief [1:0] Select input signal TRIG_0 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG1 : 2;           /**< \brief [3:2] Select input signal TRIG_1 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG2 : 2;           /**< \brief [5:4] Select input signal TRIG_2 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG3 : 2;           /**< \brief [7:6] Select input signal TRIG_3 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG4 : 2;           /**< \brief [9:8] Select input signal TRIG_4 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG5 : 2;           /**< \brief [11:10] Select input signal TRIG_5 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG6 : 2;           /**< \brief [13:12] Select input signal TRIG_6 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG7 : 2;           /**< \brief [15:14] Select input signal TRIG_7 as a trigger source (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC0_INT_TRIG_Bits;

/** \brief  TOM TGC0 Output Enable Control Register */
typedef struct _Ifx_GTM_TOM_TGC0_OUTEN_CTRL_Bits
{
    Ifx_Strict_32Bit OUTEN_CTRL0 : 2;         /**< \brief [1:0] Output TOM_OUT(0) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL1 : 2;         /**< \brief [3:2] Output TOM_OUT(1)enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL2 : 2;         /**< \brief [5:4] Output TOM_OUT(2) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL3 : 2;         /**< \brief [7:6] Output TOM_OUT(3) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL4 : 2;         /**< \brief [9:8] Output TOM_OUT(4) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL5 : 2;         /**< \brief [11:10] Output TOM_OUT(5) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL6 : 2;         /**< \brief [13:12] Output TOM_OUT(6) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL7 : 2;         /**< \brief [15:14] Output TOM_OUT(7) enable/disable update value (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC0_OUTEN_CTRL_Bits;

/** \brief  TOM TGC0 Output Enable Status Register */
typedef struct _Ifx_GTM_TOM_TGC0_OUTEN_STAT_Bits
{
    Ifx_Strict_32Bit OUTEN_STAT0 : 2;         /**< \brief [1:0] Control/status of output TOM_OUT(0) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT1 : 2;         /**< \brief [3:2] Control/status of output TOM_OUT(1) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT2 : 2;         /**< \brief [5:4] Control/status of output TOM_OUT(2) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT3 : 2;         /**< \brief [7:6] Control/status of output TOM_OUT(3) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT4 : 2;         /**< \brief [9:8] Control/status of output TOM_OUT(4) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT5 : 2;         /**< \brief [11:10] Control/status of output TOM_OUT(5) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT6 : 2;         /**< \brief [13:12] Control/status of output TOM_OUT(6) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT7 : 2;         /**< \brief [15:14] Control/status of output TOM_OUT(7) (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC0_OUTEN_STAT_Bits;

/** \brief  TOM TGC1 Action Time Base Register */
typedef struct _Ifx_GTM_TOM_TGC1_ACT_TB_Bits
{
    Ifx_Strict_32Bit ACT_TB : 24;             /**< \brief [23:0] Time base value (rw) */
    Ifx_Strict_32Bit TB_TRIG : 1;             /**< \brief [24:24] Set trigger request (rwh) */
    Ifx_Strict_32Bit TBU_SEL : 2;             /**< \brief [26:25] Selection of time base used for comparison (rw) */
    Ifx_Strict_32Bit reserved_27 : 5;         /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC1_ACT_TB_Bits;

/** \brief  TOM TGC1 Enable/Disable Control Register */
typedef struct _Ifx_GTM_TOM_TGC1_ENDIS_CTRL_Bits
{
    Ifx_Strict_32Bit ENDIS_CTRL0 : 2;         /**< \brief [1:0] TOM channel 0 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL1 : 2;         /**< \brief [3:2] TOM channel 1 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL2 : 2;         /**< \brief [5:4] TOM channel 2 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL3 : 2;         /**< \brief [7:6] TOM channel 3 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL4 : 2;         /**< \brief [9:8] TOM channel 4 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL5 : 2;         /**< \brief [11:10] TOM channel 5 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL6 : 2;         /**< \brief [13:12] TOM channel 6 enable/disable update value (rw) */
    Ifx_Strict_32Bit ENDIS_CTRL7 : 2;         /**< \brief [15:14] TOM channel 7 enable/disable update value (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC1_ENDIS_CTRL_Bits;

/** \brief  TOM TGC1 Enable/Disable Status Register */
typedef struct _Ifx_GTM_TOM_TGC1_ENDIS_STAT_Bits
{
    Ifx_Strict_32Bit ENDIS_STAT0 : 2;         /**< \brief [1:0] TOM channel 0 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT1 : 2;         /**< \brief [3:2] TOM channel 1 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT2 : 2;         /**< \brief [5:4] TOM channel 2 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT3 : 2;         /**< \brief [7:6] TOM channel 3 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT4 : 2;         /**< \brief [9:8] TOM channel 4 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT5 : 2;         /**< \brief [11:10] TOM channel 5 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT6 : 2;         /**< \brief [13:12] TOM channel 6 enable/disable (rw) */
    Ifx_Strict_32Bit ENDIS_STAT7 : 2;         /**< \brief [15:14] TOM channel 7 enable/disable (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC1_ENDIS_STAT_Bits;

/** \brief  TOM TGC1 Force Update Control Register */
typedef struct _Ifx_GTM_TOM_TGC1_FUPD_CTRL_Bits
{
    Ifx_Strict_32Bit FUPD_CTRL0 : 2;          /**< \brief [1:0] Force update of TOM channel 0 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL1 : 2;          /**< \brief [3:2] Force update of TOM channel 1 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL2 : 2;          /**< \brief [5:4] Force update of TOM channel 2 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL3 : 2;          /**< \brief [7:6] Force update of TOM channel 3 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL4 : 2;          /**< \brief [9:8] Force update of TOM channel 4 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL5 : 2;          /**< \brief [11:10] Force update of TOM channel 5 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL6 : 2;          /**< \brief [13:12] Force update of TOM channel 6 operation registers (rw) */
    Ifx_Strict_32Bit FUPD_CTRL7 : 2;          /**< \brief [15:14] Force update of TOM channel 7 operation registers (rw) */
    Ifx_Strict_32Bit RSTCN0_CH0 : 2;          /**< \brief [17:16] Reset CN0 of channel 0 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH1 : 2;          /**< \brief [19:18] Reset CN0 of channel 1 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH2 : 2;          /**< \brief [21:20] Reset CN0 of channel 2 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH3 : 2;          /**< \brief [23:22] Reset CN0 of channel 3 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH4 : 2;          /**< \brief [25:24] Reset CN0 of channel 4 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH5 : 2;          /**< \brief [27:26] Reset CN0 of channel 5 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH6 : 2;          /**< \brief [29:28] Reset CN0 of channel 6 on force update event (rw) */
    Ifx_Strict_32Bit RSTCN0_CH7 : 2;          /**< \brief [31:30] Reset CN0 of channel 7 on force update event (rw) */
} Ifx_GTM_TOM_TGC1_FUPD_CTRL_Bits;

/** \brief  TOM TGC1 Global Control Register */
typedef struct _Ifx_GTM_TOM_TGC1_GLB_CTRL_Bits
{
    Ifx_Strict_32Bit HOST_TRIG : 1;           /**< \brief [0:0] Trigger request signal (see TGC0, TGC1) to update the register ENDIS_STAT and OUTEN_STAT (w) */
    Ifx_Strict_32Bit reserved_1 : 7;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit RST_CH0 : 1;             /**< \brief [8:8] Software reset of channel 0 (w) */
    Ifx_Strict_32Bit RST_CH1 : 1;             /**< \brief [9:9] Software reset of channel 1 (w) */
    Ifx_Strict_32Bit RST_CH2 : 1;             /**< \brief [10:10] Software reset of channel 2 (w) */
    Ifx_Strict_32Bit RST_CH3 : 1;             /**< \brief [11:11] Software reset of channel 3 (w) */
    Ifx_Strict_32Bit RST_CH4 : 1;             /**< \brief [12:12] Software reset of channel 4 (w) */
    Ifx_Strict_32Bit RST_CH5 : 1;             /**< \brief [13:13] Software reset of channel 5 (w) */
    Ifx_Strict_32Bit RST_CH6 : 1;             /**< \brief [14:14] Software reset of channel 6 (w) */
    Ifx_Strict_32Bit RST_CH7 : 1;             /**< \brief [15:15] Software reset of channel 7 (w) */
    Ifx_Strict_32Bit UPEN_CTRL0 : 2;          /**< \brief [17:16] TOM channel 0 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
    Ifx_Strict_32Bit UPEN_CTRL1 : 2;          /**< \brief [19:18] TOM channel 1 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL2 : 2;          /**< \brief [21:20] TOM channel 2 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL3 : 2;          /**< \brief [23:22] TOM channel 3 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL4 : 2;          /**< \brief [25:24] TOM channel 4 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL5 : 2;          /**< \brief [27:26] TOM channel 5 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL6 : 2;          /**< \brief [29:28] TOM channel 6 enable update of register CM0, CM1 and CLK_SRC (rw) */
    Ifx_Strict_32Bit UPEN_CTRL7 : 2;          /**< \brief [31:30] TOM channel 7 enable update of register CM0, CM1 and CLK_SRC (rw) */
} Ifx_GTM_TOM_TGC1_GLB_CTRL_Bits;

/** \brief  TOM TGC1 Internal Trigger Control Register */
typedef struct _Ifx_GTM_TOM_TGC1_INT_TRIG_Bits
{
    Ifx_Strict_32Bit INT_TRIG0 : 2;           /**< \brief [1:0] Select input signal TRIG_0 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG1 : 2;           /**< \brief [3:2] Select input signal TRIG_1 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG2 : 2;           /**< \brief [5:4] Select input signal TRIG_2 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG3 : 2;           /**< \brief [7:6] Select input signal TRIG_3 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG4 : 2;           /**< \brief [9:8] Select input signal TRIG_4 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG5 : 2;           /**< \brief [11:10] Select input signal TRIG_5 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG6 : 2;           /**< \brief [13:12] Select input signal TRIG_6 as a trigger source (rw) */
    Ifx_Strict_32Bit INT_TRIG7 : 2;           /**< \brief [15:14] Select input signal TRIG_7 as a trigger source (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC1_INT_TRIG_Bits;

/** \brief  TOM TGC1 Output Enable Control Register */
typedef struct _Ifx_GTM_TOM_TGC1_OUTEN_CTRL_Bits
{
    Ifx_Strict_32Bit OUTEN_CTRL0 : 2;         /**< \brief [1:0] Output TOM_OUT(0) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL1 : 2;         /**< \brief [3:2] Output TOM_OUT(1)enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL2 : 2;         /**< \brief [5:4] Output TOM_OUT(2) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL3 : 2;         /**< \brief [7:6] Output TOM_OUT(3) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL4 : 2;         /**< \brief [9:8] Output TOM_OUT(4) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL5 : 2;         /**< \brief [11:10] Output TOM_OUT(5) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL6 : 2;         /**< \brief [13:12] Output TOM_OUT(6) enable/disable update value (rw) */
    Ifx_Strict_32Bit OUTEN_CTRL7 : 2;         /**< \brief [15:14] Output TOM_OUT(7) enable/disable update value (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC1_OUTEN_CTRL_Bits;

/** \brief  TOM TGC1 Output Enable Status Register */
typedef struct _Ifx_GTM_TOM_TGC1_OUTEN_STAT_Bits
{
    Ifx_Strict_32Bit OUTEN_STAT0 : 2;         /**< \brief [1:0] Control/status of output TOM_OUT(0) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT1 : 2;         /**< \brief [3:2] Control/status of output TOM_OUT(1) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT2 : 2;         /**< \brief [5:4] Control/status of output TOM_OUT(2) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT3 : 2;         /**< \brief [7:6] Control/status of output TOM_OUT(3) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT4 : 2;         /**< \brief [9:8] Control/status of output TOM_OUT(4) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT5 : 2;         /**< \brief [11:10] Control/status of output TOM_OUT(5) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT6 : 2;         /**< \brief [13:12] Control/status of output TOM_OUT(6) (rw) */
    Ifx_Strict_32Bit OUTEN_STAT7 : 2;         /**< \brief [15:14] Control/status of output TOM_OUT(7) (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_GTM_TOM_TGC1_OUTEN_STAT_Bits;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Gtm_union
 * \{  */

/** \brief  Access Enable Register 0 */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_GTM_ACCEN0_Bits B;                  /**< \brief Bitfield access */
} Ifx_GTM_ACCEN0;

/** \brief  Access Enable Register 1 */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_GTM_ACCEN1_Bits B;                  /**< \brief Bitfield access */
} Ifx_GTM_ACCEN1;

/** \brief  ADC Trigger 0 Output Select 0 Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_ADCTRIG0OUT0_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_ADCTRIG0OUT0;

/** \brief  ADC Trigger 1 Output Select 0 Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_ADCTRIG1OUT0_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_ADCTRIG1OUT0;

/** \brief  GTM AEI Timeout Exception Address Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_AEI_ADDR_XPT_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_AEI_ADDR_XPT;

/** \brief  GTM to SPB BRIDGE MODE */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_BRIDGE_MODE_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_BRIDGE_MODE;

/** \brief  GTM to SPB BRIDGE PTR1 */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_BRIDGE_PTR1_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_BRIDGE_PTR1;

/** \brief  GTM to SPB BRIDGE PTR2 */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_BRIDGE_PTR2_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_BRIDGE_PTR2;

/** \brief  Clock Control Register */
typedef union
{
    unsigned int     U;                     /**< \brief Unsigned access */
    signed int       I;                     /**< \brief Signed access */
    Ifx_GTM_CLC_Bits B;                     /**< \brief Bitfield access */
} Ifx_GTM_CLC;

/** \brief  CMU Control For Clock Source Register */
typedef union
{
    unsigned int                 U;         /**< \brief Unsigned access */
    signed int                   I;         /**< \brief Signed access */
    Ifx_GTM_CMU_CLK0_5_CTRL_Bits B;         /**< \brief Bitfield access */
} Ifx_GTM_CMU_CLK0_5_CTRL;

/** \brief  CMU Control For Clock Source 6 Register */
typedef union
{
    unsigned int                U;          /**< \brief Unsigned access */
    signed int                  I;          /**< \brief Signed access */
    Ifx_GTM_CMU_CLK_6_CTRL_Bits B;          /**< \brief Bitfield access */
} Ifx_GTM_CMU_CLK_6_CTRL;

/** \brief  CMU Control For Clock Source 7 Register */
typedef union
{
    unsigned int                U;          /**< \brief Unsigned access */
    signed int                  I;          /**< \brief Signed access */
    Ifx_GTM_CMU_CLK_7_CTRL_Bits B;          /**< \brief Bitfield access */
} Ifx_GTM_CMU_CLK_7_CTRL;

/** \brief  CMU Clock Enable Register */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_CMU_CLK_EN_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_CMU_CLK_EN;

/** \brief  CMU External Clock Control Denominator Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_CMU_ECLK_DEN_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_CMU_ECLK_DEN;

/** \brief  CMU External Clock Control Numerator Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_CMU_ECLK_NUM_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_CMU_ECLK_NUM;

/** \brief  CMU FXCLK Control Register */
typedef union
{
    unsigned int                U;          /**< \brief Unsigned access */
    signed int                  I;          /**< \brief Signed access */
    Ifx_GTM_CMU_FXCLK_CTRL_Bits B;          /**< \brief Bitfield access */
} Ifx_GTM_CMU_FXCLK_CTRL;

/** \brief  CMU Global Clock Control Denominator Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_CMU_GCLK_DEN_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_CMU_GCLK_DEN;

/** \brief  CMU Global Clock Control Numerator Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_CMU_GCLK_NUM_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_CMU_GCLK_NUM;

/** \brief  GTM Global Control Register */
typedef union
{
    unsigned int      U;                    /**< \brief Unsigned access */
    signed int        I;                    /**< \brief Signed access */
    Ifx_GTM_CTRL_Bits B;                    /**< \brief Bitfield access */
} Ifx_GTM_CTRL;

/** \brief  DTM Channel Control1 Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_DTM_CH_CTRL1_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_DTM_CH_CTRL1;

/** \brief  DTM Channel Control2 Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_DTM_CH_CTRL2_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_DTM_CH_CTRL2;

/** \brief  DTM Channel Control2 Shadow Register */
typedef union
{
    unsigned int                 U;         /**< \brief Unsigned access */
    signed int                   I;         /**< \brief Signed access */
    Ifx_GTM_DTM_CH_CTRL2_SR_Bits B;         /**< \brief Bitfield access */
} Ifx_GTM_DTM_CH_CTRL2_SR;

/** \brief  DTM Control Register */
typedef union
{
    unsigned int          U;                /**< \brief Unsigned access */
    signed int            I;                /**< \brief Signed access */
    Ifx_GTM_DTM_CTRL_Bits B;                /**< \brief Bitfield access */
} Ifx_GTM_DTM_CTRL;

/** \brief  DTM Channel Dead Time Value Register */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_DTM_DTV_CH_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_DTM_DTV_CH;

/** \brief  DTM Phase Shift Control Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_DTM_PS_CTRL_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_DTM_PS_CTRL;

/** \brief  GTM Error Interrupt Enable Register */
typedef union
{
    unsigned int         U;                 /**< \brief Unsigned access */
    signed int           I;                 /**< \brief Signed access */
    Ifx_GTM_EIRQ_EN_Bits B;                 /**< \brief Bitfield access */
} Ifx_GTM_EIRQ_EN;

/** \brief  GTM Hardware Configuration */
typedef union
{
    unsigned int         U;                 /**< \brief Unsigned access */
    signed int           I;                 /**< \brief Signed access */
    Ifx_GTM_HW_CONF_Bits B;                 /**< \brief Bitfield access */
} Ifx_GTM_HW_CONF;

/** \brief  GTM Infrastructure Interrupt Group */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_ICM_IRQG_0_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_ICM_IRQG_0;

/** \brief  TIM Interrupt Group 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_ICM_IRQG_2_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_ICM_IRQG_2;

/** \brief  TOM Interrupt Group 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_ICM_IRQG_6_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_ICM_IRQG_6;

/** \brief  ICM Channel Error Interrupt 1 Register */
typedef union
{
    unsigned int               U;           /**< \brief Unsigned access */
    signed int                 I;           /**< \brief Signed access */
    Ifx_GTM_ICM_IRQG_CEI1_Bits B;           /**< \brief Bitfield access */
} Ifx_GTM_ICM_IRQG_CEI1;

/** \brief  ICM Module Error Interrupt Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_ICM_IRQG_MEI_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_ICM_IRQG_MEI;

/** \brief  CAN Output Select Register */
typedef union
{
    unsigned int                     U;     /**< \brief Unsigned access */
    signed int                       I;     /**< \brief Signed access */
    Ifx_GTM_INOUTSEL_CAN_OUTSEL_Bits B;     /**< \brief Bitfield access */
} Ifx_GTM_INOUTSEL_CAN_OUTSEL;

/** \brief  Timer Output Select Register */
typedef union
{
    unsigned int                   U;       /**< \brief Unsigned access */
    signed int                     I;       /**< \brief Signed access */
    Ifx_GTM_INOUTSEL_T_OUTSEL_Bits B;       /**< \brief Bitfield access */
} Ifx_GTM_INOUTSEL_T_OUTSEL;

/** \brief  TIM Input Select Register */
typedef union
{
    unsigned int                    U;      /**< \brief Unsigned access */
    signed int                      I;      /**< \brief Signed access */
    Ifx_GTM_INOUTSEL_TIM_INSEL_Bits B;      /**< \brief Bitfield access */
} Ifx_GTM_INOUTSEL_TIM_INSEL;

/** \brief  GTM Interrupt Enable Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_GTM_IRQ_EN_Bits B;                  /**< \brief Bitfield access */
} Ifx_GTM_IRQ_EN;

/** \brief  GTM Software Interrupt Generation Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_IRQ_FORCINT_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_IRQ_FORCINT;

/** \brief  GTM Top Level Interrupts Mode Selection */
typedef union
{
    unsigned int          U;                /**< \brief Unsigned access */
    signed int            I;                /**< \brief Signed access */
    Ifx_GTM_IRQ_MODE_Bits B;                /**< \brief Bitfield access */
} Ifx_GTM_IRQ_MODE;

/** \brief  GTM Interrupt Notification Register */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_IRQ_NOTIFY_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_IRQ_NOTIFY;

/** \brief  Kernel Reset Register 0 */
typedef union
{
    unsigned int       U;                   /**< \brief Unsigned access */
    signed int         I;                   /**< \brief Signed access */
    Ifx_GTM_KRST0_Bits B;                   /**< \brief Bitfield access */
} Ifx_GTM_KRST0;

/** \brief  Kernel Reset Register 1 */
typedef union
{
    unsigned int       U;                   /**< \brief Unsigned access */
    signed int         I;                   /**< \brief Signed access */
    Ifx_GTM_KRST1_Bits B;                   /**< \brief Bitfield access */
} Ifx_GTM_KRST1;

/** \brief  Kernel Reset Status Clear Register */
typedef union
{
    unsigned int         U;                 /**< \brief Unsigned access */
    signed int           I;                 /**< \brief Signed access */
    Ifx_GTM_KRSTCLR_Bits B;                 /**< \brief Bitfield access */
} Ifx_GTM_KRSTCLR;

/** \brief  OCDS Control and Status */
typedef union
{
    unsigned int     U;                     /**< \brief Unsigned access */
    signed int       I;                     /**< \brief Signed access */
    Ifx_GTM_OCS_Bits B;                     /**< \brief Bitfield access */
} Ifx_GTM_OCS;

/** \brief  OCDS Debug Access Register */
typedef union
{
    unsigned int     U;                     /**< \brief Unsigned access */
    signed int       I;                     /**< \brief Signed access */
    Ifx_GTM_ODA_Bits B;                     /**< \brief Bitfield access */
} Ifx_GTM_ODA;

/** \brief  OCDS TBU0 Trigger Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_GTM_OTBU0T_Bits B;                  /**< \brief Bitfield access */
} Ifx_GTM_OTBU0T;

/** \brief  OCDS TBU1 Trigger Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_GTM_OTBU1T_Bits B;                  /**< \brief Bitfield access */
} Ifx_GTM_OTBU1T;

/** \brief  OCDS TBU2 Trigger Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_GTM_OTBU2T_Bits B;                  /**< \brief Bitfield access */
} Ifx_GTM_OTBU2T;

/** \brief  OCDS Trigger Set Control 0 Register */
typedef union
{
    unsigned int       U;                   /**< \brief Unsigned access */
    signed int         I;                   /**< \brief Signed access */
    Ifx_GTM_OTSC0_Bits B;                   /**< \brief Bitfield access */
} Ifx_GTM_OTSC0;

/** \brief  OCDS Trigger Set Select Register */
typedef union
{
    unsigned int      U;                    /**< \brief Unsigned access */
    signed int        I;                    /**< \brief Signed access */
    Ifx_GTM_OTSS_Bits B;                    /**< \brief Bitfield access */
} Ifx_GTM_OTSS;

/** \brief  GTM Version Control Register */
typedef union
{
    unsigned int     U;                     /**< \brief Unsigned access */
    signed int       I;                     /**< \brief Signed access */
    Ifx_GTM_REV_Bits B;                     /**< \brief Bitfield access */
} Ifx_GTM_REV;

/** \brief  GTM Global Reset Register */
typedef union
{
    unsigned int     U;                     /**< \brief Unsigned access */
    signed int       I;                     /**< \brief Signed access */
    Ifx_GTM_RST_Bits B;                     /**< \brief Bitfield access */
} Ifx_GTM_RST;

/** \brief  TBU Channel 0 Base Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_TBU_CH0_BASE_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_TBU_CH0_BASE;

/** \brief  TBU Channel 0 Control Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_TBU_CH0_CTRL_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_TBU_CH0_CTRL;

/** \brief  TBU Channel 1 Base Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_TBU_CH1_BASE_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_TBU_CH1_BASE;

/** \brief  TBU Channel 1 Control Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_TBU_CH1_CTRL_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_TBU_CH1_CTRL;

/** \brief  TBU Channel 2 Base Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_TBU_CH2_BASE_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_TBU_CH2_BASE;

/** \brief  TBU Channel 2 Control Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_TBU_CH2_CTRL_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_TBU_CH2_CTRL;

/** \brief  TBU Global Channel Enable Register */
typedef union
{
    unsigned int          U;                /**< \brief Unsigned access */
    signed int            I;                /**< \brief Signed access */
    Ifx_GTM_TBU_CHEN_Bits B;                /**< \brief Bitfield access */
} Ifx_GTM_TBU_CHEN;

/** \brief  GTM TIM  AUX_IN_SRC */
typedef union
{
    unsigned int                U;          /**< \brief Unsigned access */
    signed int                  I;          /**< \brief Signed access */
    Ifx_GTM_TIM_AUX_IN_SRC_Bits B;          /**< \brief Bitfield access */
} Ifx_GTM_TIM_AUX_IN_SRC;

/** \brief  TIM Channel SMU Counter Register */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_TIM_CH_CNT_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_CNT;

/** \brief  TIM Channel SMU Shadow Counter Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TIM_CH_CNTS_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_CNTS;

/** \brief  TIM Channel Control Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TIM_CH_CTRL_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_CTRL;

/** \brief  TIM Channel Edge Counter Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TIM_CH_ECNT_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_ECNT;

/** \brief  TIM Channel External Capture Control Register */
typedef union
{
    unsigned int              U;            /**< \brief Unsigned access */
    signed int                I;            /**< \brief Signed access */
    Ifx_GTM_TIM_CH_ECTRL_Bits B;            /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_ECTRL;

/** \brief  TIM Channel Error Interrupt Enable Register */
typedef union
{
    unsigned int                U;          /**< \brief Unsigned access */
    signed int                  I;          /**< \brief Signed access */
    Ifx_GTM_TIM_CH_EIRQ_EN_Bits B;          /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_EIRQ_EN;

/** \brief  TIM Channel Filter Parameter 1 Register */
typedef union
{
    unsigned int               U;           /**< \brief Unsigned access */
    signed int                 I;           /**< \brief Signed access */
    Ifx_GTM_TIM_CH_FLT_FE_Bits B;           /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_FLT_FE;

/** \brief  GTM_TIM Channel Filter Parameter 0 Register */
typedef union
{
    unsigned int               U;           /**< \brief Unsigned access */
    signed int                 I;           /**< \brief Signed access */
    Ifx_GTM_TIM_CH_FLT_RE_Bits B;           /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_FLT_RE;

/** \brief  TIM Channel General Purpose 0 Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TIM_CH_GPR0_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_GPR0;

/** \brief  TIM Channel General Purpose 1 Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TIM_CH_GPR1_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_GPR1;

/** \brief  TIM Channel Interrupt Enable Register */
typedef union
{
    unsigned int               U;           /**< \brief Unsigned access */
    signed int                 I;           /**< \brief Signed access */
    Ifx_GTM_TIM_CH_IRQ_EN_Bits B;           /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_IRQ_EN;

/** \brief  TIM Channel Software Interrupt Force Register */
typedef union
{
    unsigned int                    U;      /**< \brief Unsigned access */
    signed int                      I;      /**< \brief Signed access */
    Ifx_GTM_TIM_CH_IRQ_FORCINT_Bits B;      /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_IRQ_FORCINT;

/** \brief  TIM IRQ Mode Configuration Register */
typedef union
{
    unsigned int                 U;         /**< \brief Unsigned access */
    signed int                   I;         /**< \brief Signed access */
    Ifx_GTM_TIM_CH_IRQ_MODE_Bits B;         /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_IRQ_MODE;

/** \brief  TIM Channel Interrupt Notification Register */
typedef union
{
    unsigned int                   U;       /**< \brief Unsigned access */
    signed int                     I;       /**< \brief Signed access */
    Ifx_GTM_TIM_CH_IRQ_NOTIFY_Bits B;       /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_IRQ_NOTIFY;

/** \brief  TIM Channel TDUC Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TIM_CH_TDUC_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_TDUC;

/** \brief  TIM Channel TDUV Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TIM_CH_TDUV_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TIM_CH_TDUV;

/** \brief  TIM_IN_SRC Long Name */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_TIM_IN_SRC_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_TIM_IN_SRC;

/** \brief  TIM Input Value Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TIM_INP_VAL_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TIM_INP_VAL;

/** \brief  TIM Global Software Reset Register */
typedef union
{
    unsigned int         U;                 /**< \brief Unsigned access */
    signed int           I;                 /**< \brief Signed access */
    Ifx_GTM_TIM_RST_Bits B;                 /**< \brief Bitfield access */
} Ifx_GTM_TIM_RST;

/** \brief  TOM Channel CCU0 Compare Register */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_TOM_CH_CM0_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_CM0;

/** \brief  TOM Channel CCU1 Compare Register */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_TOM_CH_CM1_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_CM1;

/** \brief  TOM Channel CCU0 Counter Register */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_TOM_CH_CN0_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_CN0;

/** \brief  TOM Channel Control Register’ */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TOM_CH_CTRL_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_CTRL;

/** \brief  TOM Channel Interrupt Enable Register */
typedef union
{
    unsigned int               U;           /**< \brief Unsigned access */
    signed int                 I;           /**< \brief Signed access */
    Ifx_GTM_TOM_CH_IRQ_EN_Bits B;           /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_IRQ_EN;

/** \brief  TOM Channel Software Interrupt Generation Register */
typedef union
{
    unsigned int                    U;      /**< \brief Unsigned access */
    signed int                      I;      /**< \brief Signed access */
    Ifx_GTM_TOM_CH_IRQ_FORCINT_Bits B;      /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_IRQ_FORCINT;

/** \brief  TOM IRQ Mode Configuration Register */
typedef union
{
    unsigned int                 U;         /**< \brief Unsigned access */
    signed int                   I;         /**< \brief Signed access */
    Ifx_GTM_TOM_CH_IRQ_MODE_Bits B;         /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_IRQ_MODE;

/** \brief  TOM Channel Interrupt Notification Register */
typedef union
{
    unsigned int                   U;       /**< \brief Unsigned access */
    signed int                     I;       /**< \brief Signed access */
    Ifx_GTM_TOM_CH_IRQ_NOTIFY_Bits B;       /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_IRQ_NOTIFY;

/** \brief  TOM Channel CCU0 Compare Shadow Register */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_TOM_CH_SR0_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_SR0;

/** \brief  TOM Channel CCU1 Compare Shadow Register */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_GTM_TOM_CH_SR1_Bits B;              /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_SR1;

/** \brief  TOM Channel Status Register */
typedef union
{
    unsigned int             U;             /**< \brief Unsigned access */
    signed int               I;             /**< \brief Signed access */
    Ifx_GTM_TOM_CH_STAT_Bits B;             /**< \brief Bitfield access */
} Ifx_GTM_TOM_CH_STAT;

/** \brief  TOM TGC0 Action Time Base Register */
typedef union
{
    unsigned int                 U;         /**< \brief Unsigned access */
    signed int                   I;         /**< \brief Signed access */
    Ifx_GTM_TOM_TGC0_ACT_TB_Bits B;         /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC0_ACT_TB;

/** \brief  TOM TGC0 Enable/Disable Control Register */
typedef union
{
    unsigned int                     U;     /**< \brief Unsigned access */
    signed int                       I;     /**< \brief Signed access */
    Ifx_GTM_TOM_TGC0_ENDIS_CTRL_Bits B;     /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC0_ENDIS_CTRL;

/** \brief  TOM TGC0 Enable/Disable Status Register */
typedef union
{
    unsigned int                     U;     /**< \brief Unsigned access */
    signed int                       I;     /**< \brief Signed access */
    Ifx_GTM_TOM_TGC0_ENDIS_STAT_Bits B;     /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC0_ENDIS_STAT;

/** \brief  TOM TGC0 Force Update Control Register */
typedef union
{
    unsigned int                    U;      /**< \brief Unsigned access */
    signed int                      I;      /**< \brief Signed access */
    Ifx_GTM_TOM_TGC0_FUPD_CTRL_Bits B;      /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC0_FUPD_CTRL;

/** \brief  TOM TGC0 Global Control Register */
typedef union
{
    unsigned int                   U;       /**< \brief Unsigned access */
    signed int                     I;       /**< \brief Signed access */
    Ifx_GTM_TOM_TGC0_GLB_CTRL_Bits B;       /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC0_GLB_CTRL;

/** \brief  TOM TGC0 Internal Trigger Control Register */
typedef union
{
    unsigned int                   U;       /**< \brief Unsigned access */
    signed int                     I;       /**< \brief Signed access */
    Ifx_GTM_TOM_TGC0_INT_TRIG_Bits B;       /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC0_INT_TRIG;

/** \brief  TOM TGC0 Output Enable Control Register */
typedef union
{
    unsigned int                     U;     /**< \brief Unsigned access */
    signed int                       I;     /**< \brief Signed access */
    Ifx_GTM_TOM_TGC0_OUTEN_CTRL_Bits B;     /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC0_OUTEN_CTRL;

/** \brief  TOM TGC0 Output Enable Status Register */
typedef union
{
    unsigned int                     U;     /**< \brief Unsigned access */
    signed int                       I;     /**< \brief Signed access */
    Ifx_GTM_TOM_TGC0_OUTEN_STAT_Bits B;     /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC0_OUTEN_STAT;

/** \brief  TOM TGC1 Action Time Base Register */
typedef union
{
    unsigned int                 U;         /**< \brief Unsigned access */
    signed int                   I;         /**< \brief Signed access */
    Ifx_GTM_TOM_TGC1_ACT_TB_Bits B;         /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC1_ACT_TB;

/** \brief  TOM TGC1 Enable/Disable Control Register */
typedef union
{
    unsigned int                     U;     /**< \brief Unsigned access */
    signed int                       I;     /**< \brief Signed access */
    Ifx_GTM_TOM_TGC1_ENDIS_CTRL_Bits B;     /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC1_ENDIS_CTRL;

/** \brief  TOM TGC1 Enable/Disable Status Register */
typedef union
{
    unsigned int                     U;     /**< \brief Unsigned access */
    signed int                       I;     /**< \brief Signed access */
    Ifx_GTM_TOM_TGC1_ENDIS_STAT_Bits B;     /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC1_ENDIS_STAT;

/** \brief  TOM TGC1 Force Update Control Register */
typedef union
{
    unsigned int                    U;      /**< \brief Unsigned access */
    signed int                      I;      /**< \brief Signed access */
    Ifx_GTM_TOM_TGC1_FUPD_CTRL_Bits B;      /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC1_FUPD_CTRL;

/** \brief  TOM TGC1 Global Control Register */
typedef union
{
    unsigned int                   U;       /**< \brief Unsigned access */
    signed int                     I;       /**< \brief Signed access */
    Ifx_GTM_TOM_TGC1_GLB_CTRL_Bits B;       /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC1_GLB_CTRL;

/** \brief  TOM TGC1 Internal Trigger Control Register */
typedef union
{
    unsigned int                   U;       /**< \brief Unsigned access */
    signed int                     I;       /**< \brief Signed access */
    Ifx_GTM_TOM_TGC1_INT_TRIG_Bits B;       /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC1_INT_TRIG;

/** \brief  TOM TGC1 Output Enable Control Register */
typedef union
{
    unsigned int                     U;     /**< \brief Unsigned access */
    signed int                       I;     /**< \brief Signed access */
    Ifx_GTM_TOM_TGC1_OUTEN_CTRL_Bits B;     /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC1_OUTEN_CTRL;

/** \brief  TOM TGC1 Output Enable Status Register */
typedef union
{
    unsigned int                     U;     /**< \brief Unsigned access */
    signed int                       I;     /**< \brief Signed access */
    Ifx_GTM_TOM_TGC1_OUTEN_STAT_Bits B;     /**< \brief Bitfield access */
} Ifx_GTM_TOM_TGC1_OUTEN_STAT;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Gtm_struct
 * \{  */
/******************************************************************************/
/** \name Object L2
 * \{  */

/** \brief  CLK objects */
typedef volatile struct _Ifx_GTM_CMU_CLK0_5
{
    Ifx_GTM_CMU_CLK0_5_CTRL CTRL;           /**< \brief 0, CMU Control For Clock Source Register */
} Ifx_GTM_CMU_CLK0_5;

/** \brief  CLK objects */
typedef volatile struct _Ifx_GTM_CMU_CLK_6
{
    Ifx_GTM_CMU_CLK_6_CTRL CTRL;            /**< \brief 0, CMU Control For Clock Source 6 Register */
} Ifx_GTM_CMU_CLK_6;

/** \brief  CLK objects */
typedef volatile struct _Ifx_GTM_CMU_CLK_7
{
    Ifx_GTM_CMU_CLK_7_CTRL CTRL;            /**< \brief 0, CMU Control For Clock Source 7 Register */
} Ifx_GTM_CMU_CLK_7;

/** \brief  ECLK objects */
typedef volatile struct _Ifx_GTM_CMU_ECLK
{
    Ifx_GTM_CMU_ECLK_NUM NUM;               /**< \brief 0, CMU External Clock Control Numerator Register */
    Ifx_GTM_CMU_ECLK_DEN DEN;               /**< \brief 4, CMU External Clock Control Denominator Register */
} Ifx_GTM_CMU_ECLK;

/** \brief  FXCLK objects */
typedef volatile struct _Ifx_GTM_CMU_FXCLK
{
    Ifx_GTM_CMU_FXCLK_CTRL CTRL;            /**< \brief 0, CMU FXCLK Control Register */
} Ifx_GTM_CMU_FXCLK;

/** \brief  CAN */
typedef volatile struct _Ifx_GTM_INOUTSEL_CAN
{
    Ifx_GTM_INOUTSEL_CAN_OUTSEL OUTSEL;     /**< \brief 0, CAN Output Select Register */
} Ifx_GTM_INOUTSEL_CAN;

/** \brief  Timer */
typedef volatile struct _Ifx_GTM_INOUTSEL_T
{
    Ifx_GTM_INOUTSEL_T_OUTSEL OUTSEL[8];    /**< \brief 0, Timer Output Select Register */
} Ifx_GTM_INOUTSEL_T;

/** \brief  TIM */
typedef volatile struct _Ifx_GTM_INOUTSEL_TIM
{
    Ifx_GTM_INOUTSEL_TIM_INSEL INSEL;          /**< \brief 0, TIM Input Select Register */
    unsigned char              reserved_4[28]; /**< \brief 4, \internal Reserved */
} Ifx_GTM_INOUTSEL_TIM;

/** \brief  TIM channel objects */
typedef volatile struct _Ifx_GTM_TIM_CH
{
    Ifx_GTM_TIM_CH_GPR0        GPR0;            /**< \brief 0, TIM Channel General Purpose 0 Register */
    Ifx_GTM_TIM_CH_GPR1        GPR1;            /**< \brief 4, TIM Channel General Purpose 1 Register */
    Ifx_GTM_TIM_CH_CNT         CNT;             /**< \brief 8, TIM Channel SMU Counter Register */
    Ifx_GTM_TIM_CH_ECNT        ECNT;            /**< \brief C, TIM Channel Edge Counter Register */
    Ifx_GTM_TIM_CH_CNTS        CNTS;            /**< \brief 10, TIM Channel SMU Shadow Counter Register */
    Ifx_GTM_TIM_CH_TDUC        TDUC;            /**< \brief 14, TIM Channel TDUC Register */
    Ifx_GTM_TIM_CH_TDUV        TDUV;            /**< \brief 18, TIM Channel TDUV Register */
    Ifx_GTM_TIM_CH_FLT_RE      FLT_RE;          /**< \brief 1C, GTM_TIM Channel Filter Parameter 0 Register */
    Ifx_GTM_TIM_CH_FLT_FE      FLT_FE;          /**< \brief 20, TIM Channel Filter Parameter 1 Register */
    Ifx_GTM_TIM_CH_CTRL        CTRL;            /**< \brief 24, TIM Channel Control Register */
    Ifx_GTM_TIM_CH_ECTRL       ECTRL;           /**< \brief 28, TIM Channel External Capture Control Register */
    Ifx_GTM_TIM_CH_IRQ_NOTIFY  IRQ_NOTIFY;      /**< \brief 2C, TIM Channel Interrupt Notification Register */
    Ifx_GTM_TIM_CH_IRQ_EN      IRQ_EN;          /**< \brief 30, TIM Channel Interrupt Enable Register */
    Ifx_GTM_TIM_CH_IRQ_FORCINT IRQ_FORCINT;     /**< \brief 34, TIM Channel Software Interrupt Force Register */
    Ifx_GTM_TIM_CH_IRQ_MODE    IRQ_MODE;        /**< \brief 38, TIM IRQ Mode Configuration Register */
    Ifx_GTM_TIM_CH_EIRQ_EN     EIRQ_EN;         /**< \brief 3C, TIM Channel Error Interrupt Enable Register */
    unsigned char              reserved_40[52]; /**< \brief 40, \internal Reserved */
} Ifx_GTM_TIM_CH;

/** \brief  TOM channel objects */
typedef volatile struct _Ifx_GTM_TOM_CH
{
    Ifx_GTM_TOM_CH_CTRL        CTRL;           /**< \brief 0, TOM Channel Control Register’ */
    Ifx_GTM_TOM_CH_SR0         SR0;            /**< \brief 4, TOM Channel CCU0 Compare Shadow Register */
    Ifx_GTM_TOM_CH_SR1         SR1;            /**< \brief 8, TOM Channel CCU1 Compare Shadow Register */
    Ifx_GTM_TOM_CH_CM0         CM0;            /**< \brief C, TOM Channel CCU0 Compare Register */
    Ifx_GTM_TOM_CH_CM1         CM1;            /**< \brief 10, TOM Channel CCU1 Compare Register */
    Ifx_GTM_TOM_CH_CN0         CN0;            /**< \brief 14, TOM Channel CCU0 Counter Register */
    Ifx_GTM_TOM_CH_STAT        STAT;           /**< \brief 18, TOM Channel Status Register */
    Ifx_GTM_TOM_CH_IRQ_NOTIFY  IRQ_NOTIFY;     /**< \brief 1C, TOM Channel Interrupt Notification Register */
    Ifx_GTM_TOM_CH_IRQ_EN      IRQ_EN;         /**< \brief 20, TOM Channel Interrupt Enable Register */
    Ifx_GTM_TOM_CH_IRQ_FORCINT IRQ_FORCINT;    /**< \brief 24, TOM Channel Software Interrupt Generation Register */
    Ifx_GTM_TOM_CH_IRQ_MODE    IRQ_MODE;       /**< \brief 28, TOM IRQ Mode Configuration Register */
    unsigned char              reserved_2C[4]; /**< \brief 2C, \internal Reserved */
} Ifx_GTM_TOM_CH;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Gtm_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */

/** \brief  BRIDGE object */
typedef volatile struct _Ifx_GTM_BRIDGE
{
    Ifx_GTM_BRIDGE_MODE MODE;               /**< \brief 0, GTM to SPB BRIDGE MODE */
    Ifx_GTM_BRIDGE_PTR1 PTR1;               /**< \brief 4, GTM to SPB BRIDGE PTR1 */
    Ifx_GTM_BRIDGE_PTR2 PTR2;               /**< \brief 8, GTM to SPB BRIDGE PTR2 */
} Ifx_GTM_BRIDGE;

/** \brief  CMU object */
typedef volatile struct _Ifx_GTM_CMU
{
    Ifx_GTM_CMU_CLK_EN   CLK_EN;            /**< \brief 0, CMU Clock Enable Register */
    Ifx_GTM_CMU_GCLK_NUM GCLK_NUM;          /**< \brief 4, CMU Global Clock Control Numerator Register */
    Ifx_GTM_CMU_GCLK_DEN GCLK_DEN;          /**< \brief 8, CMU Global Clock Control Denominator Register */
    Ifx_GTM_CMU_CLK0_5   CLK0_5[6];         /**< \brief C, CLK objects */
    Ifx_GTM_CMU_CLK_6    CLK_6;             /**< \brief 24, CLK objects */
    Ifx_GTM_CMU_CLK_7    CLK_7;             /**< \brief 28, CLK objects */
    Ifx_GTM_CMU_ECLK     ECLK[3];           /**< \brief 2C, ECLK objects */
    Ifx_GTM_CMU_FXCLK    FXCLK;             /**< \brief 44, FXCLK objects */
} Ifx_GTM_CMU;

/** \brief  DTM objects */
typedef volatile struct _Ifx_GTM_DTM
{
    Ifx_GTM_DTM_CTRL        CTRL;           /**< \brief 0, DTM Control Register */
    Ifx_GTM_DTM_CH_CTRL1    CH_CTRL1;       /**< \brief 4, DTM Channel Control1 Register */
    Ifx_GTM_DTM_CH_CTRL2    CH_CTRL2;       /**< \brief 8, DTM Channel Control2 Register */
    Ifx_GTM_DTM_CH_CTRL2_SR CH_CTRL2_SR;    /**< \brief C, DTM Channel Control2 Shadow Register */
    Ifx_GTM_DTM_PS_CTRL     PS_CTRL;        /**< \brief 10, DTM Phase Shift Control Register */
    Ifx_GTM_DTM_DTV_CH      DTV_CH[4];      /**< \brief 14, DTM Channel Dead Time Value Register */
} Ifx_GTM_DTM;

/** \brief  ICM object */
typedef volatile struct _Ifx_GTM_ICM
{
    Ifx_GTM_ICM_IRQG_0    IRQG_0;           /**< \brief 0, GTM Infrastructure Interrupt Group */
    unsigned char         reserved_4[4];    /**< \brief 4, \internal Reserved */
    Ifx_GTM_ICM_IRQG_2    IRQG_2;           /**< \brief 8, TIM Interrupt Group 0 */
    unsigned char         reserved_C[12];   /**< \brief C, \internal Reserved */
    Ifx_GTM_ICM_IRQG_6    IRQG_6;           /**< \brief 18, TOM Interrupt Group 0 */
    unsigned char         reserved_1C[20];  /**< \brief 1C, \internal Reserved */
    Ifx_GTM_ICM_IRQG_MEI  IRQG_MEI;         /**< \brief 30, ICM Module Error Interrupt Register */
    unsigned char         reserved_34[4];   /**< \brief 34, \internal Reserved */
    Ifx_GTM_ICM_IRQG_CEI1 IRQG_CEI1;        /**< \brief 38, ICM Channel Error Interrupt 1 Register */
} Ifx_GTM_ICM;

/** \brief  INSEL / OUTSEL object */
typedef volatile struct _Ifx_GTM_INOUTSEL
{
    Ifx_GTM_INOUTSEL_TIM TIM[1];            /**< \brief 0, TIM */
    Ifx_GTM_INOUTSEL_T   T;                 /**< \brief 20, Timer */
    unsigned char        reserved_40[80];   /**< \brief 40, \internal Reserved */
    Ifx_GTM_INOUTSEL_CAN CAN;               /**< \brief 90, CAN */
} Ifx_GTM_INOUTSEL;

/** \brief  TBU object */
typedef volatile struct _Ifx_GTM_TBU
{
    Ifx_GTM_TBU_CHEN     CHEN;              /**< \brief 0, TBU Global Channel Enable Register */
    Ifx_GTM_TBU_CH0_CTRL CH0_CTRL;          /**< \brief 4, TBU Channel 0 Control Register */
    Ifx_GTM_TBU_CH0_BASE CH0_BASE;          /**< \brief 8, TBU Channel 0 Base Register */
    Ifx_GTM_TBU_CH1_CTRL CH1_CTRL;          /**< \brief C, TBU Channel 1 Control Register */
    Ifx_GTM_TBU_CH1_BASE CH1_BASE;          /**< \brief 10, TBU Channel 1 Base Register */
    Ifx_GTM_TBU_CH2_CTRL CH2_CTRL;          /**< \brief 14, TBU Channel 2 Control Register */
    Ifx_GTM_TBU_CH2_BASE CH2_BASE;          /**< \brief 18, TBU Channel 2 Base Register */
} Ifx_GTM_TBU;

/** \brief  TIM objects */
typedef volatile struct _Ifx_GTM_TIM
{
    Ifx_GTM_TIM_CH      CH0;                /**< \brief 0, TIM channel objects */
    Ifx_GTM_TIM_INP_VAL INP_VAL;            /**< \brief 74, TIM Input Value Register */
    Ifx_GTM_TIM_IN_SRC  IN_SRC;             /**< \brief 78, TIM_IN_SRC Long Name */
    Ifx_GTM_TIM_RST     RST;                /**< \brief 7C, TIM Global Software Reset Register */
    Ifx_GTM_TIM_CH      CH1;                /**< \brief 80, TIM channel objects */
    unsigned char       reserved_F4[12];    /**< \brief F4, \internal Reserved */
    Ifx_GTM_TIM_CH      CH2;                /**< \brief 100, TIM channel objects */
    unsigned char       reserved_174[12];   /**< \brief 174, \internal Reserved */
    Ifx_GTM_TIM_CH      CH3;                /**< \brief 180, TIM channel objects */
    unsigned char       reserved_1F4[12];   /**< \brief 1F4, \internal Reserved */
    Ifx_GTM_TIM_CH      CH4;                /**< \brief 200, TIM channel objects */
    unsigned char       reserved_274[12];   /**< \brief 274, \internal Reserved */
    Ifx_GTM_TIM_CH      CH5;                /**< \brief 280, TIM channel objects */
    unsigned char       reserved_2F4[12];   /**< \brief 2F4, \internal Reserved */
    Ifx_GTM_TIM_CH      CH6;                /**< \brief 300, TIM channel objects */
    unsigned char       reserved_374[12];   /**< \brief 374, \internal Reserved */
    Ifx_GTM_TIM_CH      CH7;                /**< \brief 380, TIM channel objects */
    unsigned char       reserved_3F4[12];   /**< \brief 3F4, \internal Reserved */
} Ifx_GTM_TIM;

/** \brief  TOM objects */
typedef volatile struct _Ifx_GTM_TOM
{
    Ifx_GTM_TOM_CH              CH0;                /**< \brief 0, TOM channel objects */
    Ifx_GTM_TOM_TGC0_GLB_CTRL   TGC0_GLB_CTRL;      /**< \brief 30, TOM TGC0 Global Control Register */
    Ifx_GTM_TOM_TGC0_ACT_TB     TGC0_ACT_TB;        /**< \brief 34, TOM TGC0 Action Time Base Register */
    Ifx_GTM_TOM_TGC0_FUPD_CTRL  TGC0_FUPD_CTRL;     /**< \brief 38, TOM TGC0 Force Update Control Register */
    Ifx_GTM_TOM_TGC0_INT_TRIG   TGC0_INT_TRIG;      /**< \brief 3C, TOM TGC0 Internal Trigger Control Register */
    Ifx_GTM_TOM_CH              CH1;                /**< \brief 40, TOM channel objects */
    Ifx_GTM_TOM_TGC0_ENDIS_CTRL TGC0_ENDIS_CTRL;    /**< \brief 70, TOM TGC0 Enable/Disable Control Register */
    Ifx_GTM_TOM_TGC0_ENDIS_STAT TGC0_ENDIS_STAT;    /**< \brief 74, TOM TGC0 Enable/Disable Status Register */
    Ifx_GTM_TOM_TGC0_OUTEN_CTRL TGC0_OUTEN_CTRL;    /**< \brief 78, TOM TGC0 Output Enable Control Register */
    Ifx_GTM_TOM_TGC0_OUTEN_STAT TGC0_OUTEN_STAT;    /**< \brief 7C, TOM TGC0 Output Enable Status Register */
    Ifx_GTM_TOM_CH              CH2;                /**< \brief 80, TOM channel objects */
    unsigned char               reserved_B0[16];    /**< \brief B0, \internal Reserved */
    Ifx_GTM_TOM_CH              CH3;                /**< \brief C0, TOM channel objects */
    unsigned char               reserved_F0[16];    /**< \brief F0, \internal Reserved */
    Ifx_GTM_TOM_CH              CH4;                /**< \brief 100, TOM channel objects */
    unsigned char               reserved_130[16];   /**< \brief 130, \internal Reserved */
    Ifx_GTM_TOM_CH              CH5;                /**< \brief 140, TOM channel objects */
    unsigned char               reserved_170[16];   /**< \brief 170, \internal Reserved */
    Ifx_GTM_TOM_CH              CH6;                /**< \brief 180, TOM channel objects */
    unsigned char               reserved_1B0[16];   /**< \brief 1B0, \internal Reserved */
    Ifx_GTM_TOM_CH              CH7;                /**< \brief 1C0, TOM channel objects */
    unsigned char               reserved_1F0[16];   /**< \brief 1F0, \internal Reserved */
    Ifx_GTM_TOM_CH              CH8;                /**< \brief 200, TOM channel objects */
    Ifx_GTM_TOM_TGC1_GLB_CTRL   TGC1_GLB_CTRL;      /**< \brief 230, TOM TGC1 Global Control Register */
    Ifx_GTM_TOM_TGC1_ACT_TB     TGC1_ACT_TB;        /**< \brief 234, TOM TGC1 Action Time Base Register */
    Ifx_GTM_TOM_TGC1_FUPD_CTRL  TGC1_FUPD_CTRL;     /**< \brief 238, TOM TGC1 Force Update Control Register */
    Ifx_GTM_TOM_TGC1_INT_TRIG   TGC1_INT_TRIG;      /**< \brief 23C, TOM TGC1 Internal Trigger Control Register */
    Ifx_GTM_TOM_CH              CH9;                /**< \brief 240, TOM channel objects */
    Ifx_GTM_TOM_TGC1_ENDIS_CTRL TGC1_ENDIS_CTRL;    /**< \brief 270, TOM TGC1 Enable/Disable Control Register */
    Ifx_GTM_TOM_TGC1_ENDIS_STAT TGC1_ENDIS_STAT;    /**< \brief 274, TOM TGC1 Enable/Disable Status Register */
    Ifx_GTM_TOM_TGC1_OUTEN_CTRL TGC1_OUTEN_CTRL;    /**< \brief 278, TOM TGC1 Output Enable Control Register */
    Ifx_GTM_TOM_TGC1_OUTEN_STAT TGC1_OUTEN_STAT;    /**< \brief 27C, TOM TGC1 Output Enable Status Register */
    Ifx_GTM_TOM_CH              CH10;               /**< \brief 280, TOM channel objects */
    unsigned char               reserved_2B0[16];   /**< \brief 2B0, \internal Reserved */
    Ifx_GTM_TOM_CH              CH11;               /**< \brief 2C0, TOM channel objects */
    unsigned char               reserved_2F0[16];   /**< \brief 2F0, \internal Reserved */
    Ifx_GTM_TOM_CH              CH12;               /**< \brief 300, TOM channel objects */
    unsigned char               reserved_330[16];   /**< \brief 330, \internal Reserved */
    Ifx_GTM_TOM_CH              CH13;               /**< \brief 340, TOM channel objects */
    unsigned char               reserved_370[16];   /**< \brief 370, \internal Reserved */
    Ifx_GTM_TOM_CH              CH14;               /**< \brief 380, TOM channel objects */
    unsigned char               reserved_3B0[16];   /**< \brief 3B0, \internal Reserved */
    Ifx_GTM_TOM_CH              CH15;               /**< \brief 3C0, TOM channel objects */
    unsigned char               reserved_3F0[1040]; /**< \brief 3F0, \internal Reserved */
} Ifx_GTM_TOM;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Gtm_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief  GTM object */
typedef volatile struct _Ifx_GTM
{
    Ifx_GTM_REV            REV;                    /**< \brief 0, GTM Version Control Register */
    Ifx_GTM_RST            RST;                    /**< \brief 4, GTM Global Reset Register */
    Ifx_GTM_CTRL           CTRL;                   /**< \brief 8, GTM Global Control Register */
    Ifx_GTM_AEI_ADDR_XPT   AEI_ADDR_XPT;           /**< \brief C, GTM AEI Timeout Exception Address Register */
    Ifx_GTM_IRQ_NOTIFY     IRQ_NOTIFY;             /**< \brief 10, GTM Interrupt Notification Register */
    Ifx_GTM_IRQ_EN         IRQ_EN;                 /**< \brief 14, GTM Interrupt Enable Register */
    Ifx_GTM_IRQ_FORCINT    IRQ_FORCINT;            /**< \brief 18, GTM Software Interrupt Generation Register */
    Ifx_GTM_IRQ_MODE       IRQ_MODE;               /**< \brief 1C, GTM Top Level Interrupts Mode Selection */
    Ifx_GTM_EIRQ_EN        EIRQ_EN;                /**< \brief 20, GTM Error Interrupt Enable Register */
    Ifx_GTM_HW_CONF        HW_CONF;                /**< \brief 24, GTM Hardware Configuration */
    unsigned char          reserved_28[8];         /**< \brief 28, \internal Reserved */
    Ifx_GTM_BRIDGE         BRIDGE;                 /**< \brief 30, BRIDGE object */
    unsigned char          reserved_3C[4];         /**< \brief 3C, \internal Reserved */
    Ifx_GTM_TIM_AUX_IN_SRC TIM_AUX_IN_SRC[1];      /**< \brief 40, GTM TIM  AUX_IN_SRC */
    unsigned char          reserved_44[188];       /**< \brief 44, \internal Reserved */
    Ifx_GTM_TBU            TBU;                    /**< \brief 100, TBU object */
    unsigned char          reserved_11C[484];      /**< \brief 11C, \internal Reserved */
    Ifx_GTM_CMU            CMU;                    /**< \brief 300, CMU object */
    unsigned char          reserved_348[696];      /**< \brief 348, \internal Reserved */
    Ifx_GTM_ICM            ICM;                    /**< \brief 600, ICM object */
    unsigned char          reserved_63C[2500];     /**< \brief 63C, \internal Reserved */
    Ifx_GTM_TIM            TIM[1];                 /**< \brief 1000, TIM objects */
    unsigned char          reserved_1400[27648];   /**< \brief 1400, \internal Reserved */
    Ifx_GTM_TOM            TOM[2];                 /**< \brief 8000, TOM objects */
    unsigned char          reserved_9000[41024];   /**< \brief 9000, \internal Reserved */
    Ifx_GTM_DTM            DTM1;                   /**< \brief 13040, DTM objects */
    unsigned char          reserved_13064[220];    /**< \brief 13064, \internal Reserved */
    Ifx_GTM_DTM            DTM5;                   /**< \brief 13140, DTM objects */
    unsigned char          reserved_13164[576412]; /**< \brief 13164, \internal Reserved */
    Ifx_GTM_CLC            CLC;                    /**< \brief 9FD00, Clock Control Register */
    unsigned char          reserved_9FD04[12];     /**< \brief 9FD04, \internal Reserved */
    Ifx_GTM_INOUTSEL       INOUTSEL;               /**< \brief 9FD10, INSEL / OUTSEL object */
    unsigned char          reserved_9FDA4[12];     /**< \brief 9FDA4, \internal Reserved */
    Ifx_GTM_ADCTRIG0OUT0   ADCTRIG0OUT0;           /**< \brief 9FDB0, ADC Trigger 0 Output Select 0 Register */
    unsigned char          reserved_9FDB4[4];      /**< \brief 9FDB4, \internal Reserved */
    Ifx_GTM_ADCTRIG1OUT0   ADCTRIG1OUT0;           /**< \brief 9FDB8, ADC Trigger 1 Output Select 0 Register */
    unsigned char          reserved_9FDBC[8];      /**< \brief 9FDBC, \internal Reserved */
    Ifx_GTM_OTBU0T         OTBU0T;                 /**< \brief 9FDC4, OCDS TBU0 Trigger Register */
    Ifx_GTM_OTBU1T         OTBU1T;                 /**< \brief 9FDC8, OCDS TBU1 Trigger Register */
    Ifx_GTM_OTBU2T         OTBU2T;                 /**< \brief 9FDCC, OCDS TBU2 Trigger Register */
    Ifx_GTM_OTSS           OTSS;                   /**< \brief 9FDD0, OCDS Trigger Set Select Register */
    Ifx_GTM_OTSC0          OTSC0;                  /**< \brief 9FDD4, OCDS Trigger Set Control 0 Register */
    unsigned char          reserved_9FDD8[4];      /**< \brief 9FDD8, \internal Reserved */
    Ifx_GTM_ODA            ODA;                    /**< \brief 9FDDC, OCDS Debug Access Register */
    unsigned char          reserved_9FDE0[8];      /**< \brief 9FDE0, \internal Reserved */
    Ifx_GTM_OCS            OCS;                    /**< \brief 9FDE8, OCDS Control and Status */
    Ifx_GTM_KRSTCLR        KRSTCLR;                /**< \brief 9FDEC, Kernel Reset Status Clear Register */
    Ifx_GTM_KRST1          KRST1;                  /**< \brief 9FDF0, Kernel Reset Register 1 */
    Ifx_GTM_KRST0          KRST0;                  /**< \brief 9FDF4, Kernel Reset Register 0 */
    Ifx_GTM_ACCEN1         ACCEN1;                 /**< \brief 9FDF8, Access Enable Register 1 */
    Ifx_GTM_ACCEN0         ACCEN0;                 /**< \brief 9FDFC, Access Enable Register 0 */
    unsigned char          reserved_9FE00[512];    /**< \brief 9FE00, \internal Reserved */
} Ifx_GTM;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXGTM_REGDEF_H */
