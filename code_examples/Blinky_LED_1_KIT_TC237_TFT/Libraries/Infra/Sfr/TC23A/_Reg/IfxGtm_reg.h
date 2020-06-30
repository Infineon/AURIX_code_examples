/**
 * \file IfxGtm_reg.h
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
 * \defgroup IfxLld_Gtm_Cfg Gtm address
 * \ingroup IfxLld_Gtm
 *
 * \defgroup IfxLld_Gtm_Cfg_BaseAddress Base address
 * \ingroup IfxLld_Gtm_Cfg
 *
 * \defgroup IfxLld_Gtm_Cfg_Gtm 2-GTM
 * \ingroup IfxLld_Gtm_Cfg
 *
 */
#ifndef IFXGTM_REG_H
#define IFXGTM_REG_H 1
/******************************************************************************/
#include "IfxGtm_regdef.h"
/******************************************************************************/
/** \addtogroup IfxLld_Gtm_Cfg_BaseAddress
 * \{  */

/** \brief  GTM object */
#define MODULE_GTM /*lint --e(923)*/ (*(Ifx_GTM *)0xF0100000u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Gtm_Cfg_Gtm
 * \{  */

/** \brief  9FDFC, Access Enable Register 0 */
#define GTM_ACCEN0                /*lint --e(923)*/ (*(volatile Ifx_GTM_ACCEN0 *)0xF019FDFCu)

/** \brief  9FDF8, Access Enable Register 1 */
#define GTM_ACCEN1                /*lint --e(923)*/ (*(volatile Ifx_GTM_ACCEN1 *)0xF019FDF8u)

/** \brief  9FDB0, ADC Trigger 0 Output Select 0 Register */
#define GTM_ADCTRIG0OUT0          /*lint --e(923)*/ (*(volatile Ifx_GTM_ADCTRIG0OUT0 *)0xF019FDB0u)

/** \brief  9FDB8, ADC Trigger 1 Output Select 0 Register */
#define GTM_ADCTRIG1OUT0          /*lint --e(923)*/ (*(volatile Ifx_GTM_ADCTRIG1OUT0 *)0xF019FDB8u)

/** \brief  C, GTM AEI Timeout Exception Address Register */
#define GTM_AEI_ADDR_XPT          /*lint --e(923)*/ (*(volatile Ifx_GTM_AEI_ADDR_XPT *)0xF010000Cu)

/** \brief  30, GTM to SPB BRIDGE MODE */
#define GTM_BRIDGE_MODE           /*lint --e(923)*/ (*(volatile Ifx_GTM_BRIDGE_MODE *)0xF0100030u)

/** \brief  34, GTM to SPB BRIDGE PTR1 */
#define GTM_BRIDGE_PTR1           /*lint --e(923)*/ (*(volatile Ifx_GTM_BRIDGE_PTR1 *)0xF0100034u)

/** \brief  38, GTM to SPB BRIDGE PTR2 */
#define GTM_BRIDGE_PTR2           /*lint --e(923)*/ (*(volatile Ifx_GTM_BRIDGE_PTR2 *)0xF0100038u)

/** \brief  9FD00, Clock Control Register */
#define GTM_CLC                   /*lint --e(923)*/ (*(volatile Ifx_GTM_CLC *)0xF019FD00u)

/** \brief  30C, CMU Control For Clock Source Register */
#define GTM_CMU_CLK0_50_CTRL      /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_CLK0_5_CTRL *)0xF010030Cu)

/** Alias (User Manual Name) for GTM_CMU_CLK0_50_CTRL.
 * To use register names with standard convension, please use GTM_CMU_CLK0_50_CTRL.
 */
#define GTM_CMU_CLK_0_CTRL        (GTM_CMU_CLK0_50_CTRL)

/** \brief  310, CMU Control For Clock Source Register */
#define GTM_CMU_CLK0_51_CTRL      /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_CLK0_5_CTRL *)0xF0100310u)

/** Alias (User Manual Name) for GTM_CMU_CLK0_51_CTRL.
 * To use register names with standard convension, please use GTM_CMU_CLK0_51_CTRL.
 */
#define GTM_CMU_CLK_1_CTRL        (GTM_CMU_CLK0_51_CTRL)

/** \brief  314, CMU Control For Clock Source Register */
#define GTM_CMU_CLK0_52_CTRL      /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_CLK0_5_CTRL *)0xF0100314u)

/** Alias (User Manual Name) for GTM_CMU_CLK0_52_CTRL.
 * To use register names with standard convension, please use GTM_CMU_CLK0_52_CTRL.
 */
#define GTM_CMU_CLK_2_CTRL        (GTM_CMU_CLK0_52_CTRL)

/** \brief  318, CMU Control For Clock Source Register */
#define GTM_CMU_CLK0_53_CTRL      /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_CLK0_5_CTRL *)0xF0100318u)

/** Alias (User Manual Name) for GTM_CMU_CLK0_53_CTRL.
 * To use register names with standard convension, please use GTM_CMU_CLK0_53_CTRL.
 */
#define GTM_CMU_CLK_3_CTRL        (GTM_CMU_CLK0_53_CTRL)

/** \brief  31C, CMU Control For Clock Source Register */
#define GTM_CMU_CLK0_54_CTRL      /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_CLK0_5_CTRL *)0xF010031Cu)

/** Alias (User Manual Name) for GTM_CMU_CLK0_54_CTRL.
 * To use register names with standard convension, please use GTM_CMU_CLK0_54_CTRL.
 */
#define GTM_CMU_CLK_4_CTRL        (GTM_CMU_CLK0_54_CTRL)

/** \brief  320, CMU Control For Clock Source Register */
#define GTM_CMU_CLK0_55_CTRL      /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_CLK0_5_CTRL *)0xF0100320u)

/** Alias (User Manual Name) for GTM_CMU_CLK0_55_CTRL.
 * To use register names with standard convension, please use GTM_CMU_CLK0_55_CTRL.
 */
#define GTM_CMU_CLK_5_CTRL        (GTM_CMU_CLK0_55_CTRL)

/** \brief  324, CMU Control For Clock Source 6 Register */
#define GTM_CMU_CLK_6_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_CLK_6_CTRL *)0xF0100324u)

/** \brief  328, CMU Control For Clock Source 7 Register */
#define GTM_CMU_CLK_7_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_CLK_7_CTRL *)0xF0100328u)

/** \brief  300, CMU Clock Enable Register */
#define GTM_CMU_CLK_EN            /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_CLK_EN *)0xF0100300u)

/** \brief  330, CMU External Clock Control Denominator Register */
#define GTM_CMU_ECLK0_DEN         /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_ECLK_DEN *)0xF0100330u)

/** Alias (User Manual Name) for GTM_CMU_ECLK0_DEN.
 * To use register names with standard convension, please use GTM_CMU_ECLK0_DEN.
 */
#define GTM_CMU_ECLK_0_DEN        (GTM_CMU_ECLK0_DEN)

/** \brief  32C, CMU External Clock Control Numerator Register */
#define GTM_CMU_ECLK0_NUM         /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_ECLK_NUM *)0xF010032Cu)

/** Alias (User Manual Name) for GTM_CMU_ECLK0_NUM.
 * To use register names with standard convension, please use GTM_CMU_ECLK0_NUM.
 */
#define GTM_CMU_ECLK_0_NUM        (GTM_CMU_ECLK0_NUM)

/** \brief  338, CMU External Clock Control Denominator Register */
#define GTM_CMU_ECLK1_DEN         /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_ECLK_DEN *)0xF0100338u)

/** Alias (User Manual Name) for GTM_CMU_ECLK1_DEN.
 * To use register names with standard convension, please use GTM_CMU_ECLK1_DEN.
 */
#define GTM_CMU_ECLK_1_DEN        (GTM_CMU_ECLK1_DEN)

/** \brief  334, CMU External Clock Control Numerator Register */
#define GTM_CMU_ECLK1_NUM         /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_ECLK_NUM *)0xF0100334u)

/** Alias (User Manual Name) for GTM_CMU_ECLK1_NUM.
 * To use register names with standard convension, please use GTM_CMU_ECLK1_NUM.
 */
#define GTM_CMU_ECLK_1_NUM        (GTM_CMU_ECLK1_NUM)

/** \brief  340, CMU External Clock Control Denominator Register */
#define GTM_CMU_ECLK2_DEN         /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_ECLK_DEN *)0xF0100340u)

/** Alias (User Manual Name) for GTM_CMU_ECLK2_DEN.
 * To use register names with standard convension, please use GTM_CMU_ECLK2_DEN.
 */
#define GTM_CMU_ECLK_2_DEN        (GTM_CMU_ECLK2_DEN)

/** \brief  33C, CMU External Clock Control Numerator Register */
#define GTM_CMU_ECLK2_NUM         /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_ECLK_NUM *)0xF010033Cu)

/** Alias (User Manual Name) for GTM_CMU_ECLK2_NUM.
 * To use register names with standard convension, please use GTM_CMU_ECLK2_NUM.
 */
#define GTM_CMU_ECLK_2_NUM        (GTM_CMU_ECLK2_NUM)

/** \brief  344, CMU FXCLK Control Register */
#define GTM_CMU_FXCLK_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_FXCLK_CTRL *)0xF0100344u)

/** \brief  308, CMU Global Clock Control Denominator Register */
#define GTM_CMU_GCLK_DEN          /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_GCLK_DEN *)0xF0100308u)

/** \brief  304, CMU Global Clock Control Numerator Register */
#define GTM_CMU_GCLK_NUM          /*lint --e(923)*/ (*(volatile Ifx_GTM_CMU_GCLK_NUM *)0xF0100304u)

/** \brief  8, GTM Global Control Register */
#define GTM_CTRL                  /*lint --e(923)*/ (*(volatile Ifx_GTM_CTRL *)0xF0100008u)

/** \brief  13044, DTM Channel Control1 Register */
#define GTM_DTM1_CH_CTRL1         /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_CH_CTRL1 *)0xF0113044u)

/** \brief  13048, DTM Channel Control2 Register */
#define GTM_DTM1_CH_CTRL2         /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_CH_CTRL2 *)0xF0113048u)

/** \brief  1304C, DTM Channel Control2 Shadow Register */
#define GTM_DTM1_CH_CTRL2_SR      /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_CH_CTRL2_SR *)0xF011304Cu)

/** \brief  13040, DTM Control Register */
#define GTM_DTM1_CTRL             /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_CTRL *)0xF0113040u)

/** \brief  13054, DTM Channel Dead Time Value Register */
#define GTM_DTM1_DTV_CH0          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_DTV_CH *)0xF0113054u)

/** Alias (User Manual Name) for GTM_DTM1_DTV_CH0.
 * To use register names with standard convension, please use GTM_DTM1_DTV_CH0.
 */
#define GTM_DTM1_CH0_DTV          (GTM_DTM1_DTV_CH0)

/** \brief  13058, DTM Channel Dead Time Value Register */
#define GTM_DTM1_DTV_CH1          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_DTV_CH *)0xF0113058u)

/** Alias (User Manual Name) for GTM_DTM1_DTV_CH1.
 * To use register names with standard convension, please use GTM_DTM1_DTV_CH1.
 */
#define GTM_DTM1_CH1_DTV          (GTM_DTM1_DTV_CH1)

/** \brief  1305C, DTM Channel Dead Time Value Register */
#define GTM_DTM1_DTV_CH2          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_DTV_CH *)0xF011305Cu)

/** Alias (User Manual Name) for GTM_DTM1_DTV_CH2.
 * To use register names with standard convension, please use GTM_DTM1_DTV_CH2.
 */
#define GTM_DTM1_CH2_DTV          (GTM_DTM1_DTV_CH2)

/** \brief  13060, DTM Channel Dead Time Value Register */
#define GTM_DTM1_DTV_CH3          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_DTV_CH *)0xF0113060u)

/** Alias (User Manual Name) for GTM_DTM1_DTV_CH3.
 * To use register names with standard convension, please use GTM_DTM1_DTV_CH3.
 */
#define GTM_DTM1_CH3_DTV          (GTM_DTM1_DTV_CH3)

/** \brief  13050, DTM Phase Shift Control Register */
#define GTM_DTM1_PS_CTRL          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_PS_CTRL *)0xF0113050u)

/** \brief  13144, DTM Channel Control1 Register */
#define GTM_DTM5_CH_CTRL1         /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_CH_CTRL1 *)0xF0113144u)

/** \brief  13148, DTM Channel Control2 Register */
#define GTM_DTM5_CH_CTRL2         /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_CH_CTRL2 *)0xF0113148u)

/** \brief  1314C, DTM Channel Control2 Shadow Register */
#define GTM_DTM5_CH_CTRL2_SR      /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_CH_CTRL2_SR *)0xF011314Cu)

/** \brief  13140, DTM Control Register */
#define GTM_DTM5_CTRL             /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_CTRL *)0xF0113140u)

/** \brief  13154, DTM Channel Dead Time Value Register */
#define GTM_DTM5_DTV_CH0          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_DTV_CH *)0xF0113154u)

/** Alias (User Manual Name) for GTM_DTM5_DTV_CH0.
 * To use register names with standard convension, please use GTM_DTM5_DTV_CH0.
 */
#define GTM_DTM5_CH0_DTV          (GTM_DTM5_DTV_CH0)

/** \brief  13158, DTM Channel Dead Time Value Register */
#define GTM_DTM5_DTV_CH1          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_DTV_CH *)0xF0113158u)

/** Alias (User Manual Name) for GTM_DTM5_DTV_CH1.
 * To use register names with standard convension, please use GTM_DTM5_DTV_CH1.
 */
#define GTM_DTM5_CH1_DTV          (GTM_DTM5_DTV_CH1)

/** \brief  1315C, DTM Channel Dead Time Value Register */
#define GTM_DTM5_DTV_CH2          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_DTV_CH *)0xF011315Cu)

/** Alias (User Manual Name) for GTM_DTM5_DTV_CH2.
 * To use register names with standard convension, please use GTM_DTM5_DTV_CH2.
 */
#define GTM_DTM5_CH2_DTV          (GTM_DTM5_DTV_CH2)

/** \brief  13160, DTM Channel Dead Time Value Register */
#define GTM_DTM5_DTV_CH3          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_DTV_CH *)0xF0113160u)

/** Alias (User Manual Name) for GTM_DTM5_DTV_CH3.
 * To use register names with standard convension, please use GTM_DTM5_DTV_CH3.
 */
#define GTM_DTM5_CH3_DTV          (GTM_DTM5_DTV_CH3)

/** \brief  13150, DTM Phase Shift Control Register */
#define GTM_DTM5_PS_CTRL          /*lint --e(923)*/ (*(volatile Ifx_GTM_DTM_PS_CTRL *)0xF0113150u)

/** \brief  20, GTM Error Interrupt Enable Register */
#define GTM_EIRQ_EN               /*lint --e(923)*/ (*(volatile Ifx_GTM_EIRQ_EN *)0xF0100020u)

/** \brief  24, GTM Hardware Configuration */
#define GTM_HW_CONF               /*lint --e(923)*/ (*(volatile Ifx_GTM_HW_CONF *)0xF0100024u)

/** \brief  600, GTM Infrastructure Interrupt Group */
#define GTM_ICM_IRQG_0            /*lint --e(923)*/ (*(volatile Ifx_GTM_ICM_IRQG_0 *)0xF0100600u)

/** \brief  608, TIM Interrupt Group 0 */
#define GTM_ICM_IRQG_2            /*lint --e(923)*/ (*(volatile Ifx_GTM_ICM_IRQG_2 *)0xF0100608u)

/** \brief  618, TOM Interrupt Group 0 */
#define GTM_ICM_IRQG_6            /*lint --e(923)*/ (*(volatile Ifx_GTM_ICM_IRQG_6 *)0xF0100618u)

/** \brief  638, ICM Channel Error Interrupt 1 Register */
#define GTM_ICM_IRQG_CEI1         /*lint --e(923)*/ (*(volatile Ifx_GTM_ICM_IRQG_CEI1 *)0xF0100638u)

/** \brief  630, ICM Module Error Interrupt Register */
#define GTM_ICM_IRQG_MEI          /*lint --e(923)*/ (*(volatile Ifx_GTM_ICM_IRQG_MEI *)0xF0100630u)

/** \brief  9FDA0, CAN Output Select Register */
#define GTM_INOUTSEL_CAN_OUTSEL   /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_CAN_OUTSEL *)0xF019FDA0u)

/** Alias (User Manual Name) for GTM_INOUTSEL_CAN_OUTSEL.
 * To use register names with standard convension, please use GTM_INOUTSEL_CAN_OUTSEL.
 */
#define GTM_CANOUTSEL             (GTM_INOUTSEL_CAN_OUTSEL)

/** \brief  9FD30, Timer Output Select Register */
#define GTM_INOUTSEL_T_OUTSEL0    /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_T_OUTSEL *)0xF019FD30u)

/** Alias (User Manual Name) for GTM_INOUTSEL_T_OUTSEL0.
 * To use register names with standard convension, please use GTM_INOUTSEL_T_OUTSEL0.
 */
#define GTM_TOUTSEL0              (GTM_INOUTSEL_T_OUTSEL0)

/** \brief  9FD34, Timer Output Select Register */
#define GTM_INOUTSEL_T_OUTSEL1    /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_T_OUTSEL *)0xF019FD34u)

/** Alias (User Manual Name) for GTM_INOUTSEL_T_OUTSEL1.
 * To use register names with standard convension, please use GTM_INOUTSEL_T_OUTSEL1.
 */
#define GTM_TOUTSEL1              (GTM_INOUTSEL_T_OUTSEL1)

/** \brief  9FD38, Timer Output Select Register */
#define GTM_INOUTSEL_T_OUTSEL2    /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_T_OUTSEL *)0xF019FD38u)

/** Alias (User Manual Name) for GTM_INOUTSEL_T_OUTSEL2.
 * To use register names with standard convension, please use GTM_INOUTSEL_T_OUTSEL2.
 */
#define GTM_TOUTSEL2              (GTM_INOUTSEL_T_OUTSEL2)

/** \brief  9FD3C, Timer Output Select Register */
#define GTM_INOUTSEL_T_OUTSEL3    /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_T_OUTSEL *)0xF019FD3Cu)

/** Alias (User Manual Name) for GTM_INOUTSEL_T_OUTSEL3.
 * To use register names with standard convension, please use GTM_INOUTSEL_T_OUTSEL3.
 */
#define GTM_TOUTSEL3              (GTM_INOUTSEL_T_OUTSEL3)

/** \brief  9FD40, Timer Output Select Register */
#define GTM_INOUTSEL_T_OUTSEL4    /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_T_OUTSEL *)0xF019FD40u)

/** Alias (User Manual Name) for GTM_INOUTSEL_T_OUTSEL4.
 * To use register names with standard convension, please use GTM_INOUTSEL_T_OUTSEL4.
 */
#define GTM_TOUTSEL4              (GTM_INOUTSEL_T_OUTSEL4)

/** \brief  9FD44, Timer Output Select Register */
#define GTM_INOUTSEL_T_OUTSEL5    /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_T_OUTSEL *)0xF019FD44u)

/** Alias (User Manual Name) for GTM_INOUTSEL_T_OUTSEL5.
 * To use register names with standard convension, please use GTM_INOUTSEL_T_OUTSEL5.
 */
#define GTM_TOUTSEL5              (GTM_INOUTSEL_T_OUTSEL5)

/** \brief  9FD48, Timer Output Select Register */
#define GTM_INOUTSEL_T_OUTSEL6    /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_T_OUTSEL *)0xF019FD48u)

/** Alias (User Manual Name) for GTM_INOUTSEL_T_OUTSEL6.
 * To use register names with standard convension, please use GTM_INOUTSEL_T_OUTSEL6.
 */
#define GTM_TOUTSEL6              (GTM_INOUTSEL_T_OUTSEL6)

/** \brief  9FD4C, Timer Output Select Register */
#define GTM_INOUTSEL_T_OUTSEL7    /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_T_OUTSEL *)0xF019FD4Cu)

/** Alias (User Manual Name) for GTM_INOUTSEL_T_OUTSEL7.
 * To use register names with standard convension, please use GTM_INOUTSEL_T_OUTSEL7.
 */
#define GTM_TOUTSEL7              (GTM_INOUTSEL_T_OUTSEL7)

/** \brief  9FD10, TIM Input Select Register */
#define GTM_INOUTSEL_TIM0_INSEL   /*lint --e(923)*/ (*(volatile Ifx_GTM_INOUTSEL_TIM_INSEL *)0xF019FD10u)

/** Alias (User Manual Name) for GTM_INOUTSEL_TIM0_INSEL.
 * To use register names with standard convension, please use GTM_INOUTSEL_TIM0_INSEL.
 */
#define GTM_TIM0INSEL             (GTM_INOUTSEL_TIM0_INSEL)

/** \brief  14, GTM Interrupt Enable Register */
#define GTM_IRQ_EN                /*lint --e(923)*/ (*(volatile Ifx_GTM_IRQ_EN *)0xF0100014u)

/** \brief  18, GTM Software Interrupt Generation Register */
#define GTM_IRQ_FORCINT           /*lint --e(923)*/ (*(volatile Ifx_GTM_IRQ_FORCINT *)0xF0100018u)

/** \brief  1C, GTM Top Level Interrupts Mode Selection */
#define GTM_IRQ_MODE              /*lint --e(923)*/ (*(volatile Ifx_GTM_IRQ_MODE *)0xF010001Cu)

/** \brief  10, GTM Interrupt Notification Register */
#define GTM_IRQ_NOTIFY            /*lint --e(923)*/ (*(volatile Ifx_GTM_IRQ_NOTIFY *)0xF0100010u)

/** \brief  9FDF4, Kernel Reset Register 0 */
#define GTM_KRST0                 /*lint --e(923)*/ (*(volatile Ifx_GTM_KRST0 *)0xF019FDF4u)

/** \brief  9FDF0, Kernel Reset Register 1 */
#define GTM_KRST1                 /*lint --e(923)*/ (*(volatile Ifx_GTM_KRST1 *)0xF019FDF0u)

/** \brief  9FDEC, Kernel Reset Status Clear Register */
#define GTM_KRSTCLR               /*lint --e(923)*/ (*(volatile Ifx_GTM_KRSTCLR *)0xF019FDECu)

/** \brief  9FDE8, OCDS Control and Status */
#define GTM_OCS                   /*lint --e(923)*/ (*(volatile Ifx_GTM_OCS *)0xF019FDE8u)

/** \brief  9FDDC, OCDS Debug Access Register */
#define GTM_ODA                   /*lint --e(923)*/ (*(volatile Ifx_GTM_ODA *)0xF019FDDCu)

/** \brief  9FDC4, OCDS TBU0 Trigger Register */
#define GTM_OTBU0T                /*lint --e(923)*/ (*(volatile Ifx_GTM_OTBU0T *)0xF019FDC4u)

/** \brief  9FDC8, OCDS TBU1 Trigger Register */
#define GTM_OTBU1T                /*lint --e(923)*/ (*(volatile Ifx_GTM_OTBU1T *)0xF019FDC8u)

/** \brief  9FDCC, OCDS TBU2 Trigger Register */
#define GTM_OTBU2T                /*lint --e(923)*/ (*(volatile Ifx_GTM_OTBU2T *)0xF019FDCCu)

/** \brief  9FDD4, OCDS Trigger Set Control 0 Register */
#define GTM_OTSC0                 /*lint --e(923)*/ (*(volatile Ifx_GTM_OTSC0 *)0xF019FDD4u)

/** \brief  9FDD0, OCDS Trigger Set Select Register */
#define GTM_OTSS                  /*lint --e(923)*/ (*(volatile Ifx_GTM_OTSS *)0xF019FDD0u)

/** \brief  0, GTM Version Control Register */
#define GTM_REV                   /*lint --e(923)*/ (*(volatile Ifx_GTM_REV *)0xF0100000u)

/** \brief  4, GTM Global Reset Register */
#define GTM_RST                   /*lint --e(923)*/ (*(volatile Ifx_GTM_RST *)0xF0100004u)

/** \brief  108, TBU Channel 0 Base Register */
#define GTM_TBU_CH0_BASE          /*lint --e(923)*/ (*(volatile Ifx_GTM_TBU_CH0_BASE *)0xF0100108u)

/** \brief  104, TBU Channel 0 Control Register */
#define GTM_TBU_CH0_CTRL          /*lint --e(923)*/ (*(volatile Ifx_GTM_TBU_CH0_CTRL *)0xF0100104u)

/** \brief  110, TBU Channel 1 Base Register */
#define GTM_TBU_CH1_BASE          /*lint --e(923)*/ (*(volatile Ifx_GTM_TBU_CH1_BASE *)0xF0100110u)

/** \brief  10C, TBU Channel 1 Control Register */
#define GTM_TBU_CH1_CTRL          /*lint --e(923)*/ (*(volatile Ifx_GTM_TBU_CH1_CTRL *)0xF010010Cu)

/** \brief  118, TBU Channel 2 Base Register */
#define GTM_TBU_CH2_BASE          /*lint --e(923)*/ (*(volatile Ifx_GTM_TBU_CH2_BASE *)0xF0100118u)

/** \brief  114, TBU Channel 2 Control Register */
#define GTM_TBU_CH2_CTRL          /*lint --e(923)*/ (*(volatile Ifx_GTM_TBU_CH2_CTRL *)0xF0100114u)

/** \brief  100, TBU Global Channel Enable Register */
#define GTM_TBU_CHEN              /*lint --e(923)*/ (*(volatile Ifx_GTM_TBU_CHEN *)0xF0100100u)

/** \brief  1008, TIM Channel SMU Counter Register */
#define GTM_TIM0_CH0_CNT          /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNT *)0xF0101008u)

/** \brief  1010, TIM Channel SMU Shadow Counter Register */
#define GTM_TIM0_CH0_CNTS         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNTS *)0xF0101010u)

/** \brief  1024, TIM Channel Control Register */
#define GTM_TIM0_CH0_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CTRL *)0xF0101024u)

/** \brief  100C, TIM Channel Edge Counter Register */
#define GTM_TIM0_CH0_ECNT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECNT *)0xF010100Cu)

/** \brief  1028, TIM Channel External Capture Control Register */
#define GTM_TIM0_CH0_ECTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECTRL *)0xF0101028u)

/** \brief  103C, TIM Channel Error Interrupt Enable Register */
#define GTM_TIM0_CH0_EIRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_EIRQ_EN *)0xF010103Cu)

/** \brief  1020, TIM Channel Filter Parameter 1 Register */
#define GTM_TIM0_CH0_FLT_FE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_FE *)0xF0101020u)

/** \brief  101C, GTM_TIM Channel Filter Parameter 0 Register */
#define GTM_TIM0_CH0_FLT_RE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_RE *)0xF010101Cu)

/** \brief  1000, TIM Channel General Purpose 0 Register */
#define GTM_TIM0_CH0_GPR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR0 *)0xF0101000u)

/** \brief  1004, TIM Channel General Purpose 1 Register */
#define GTM_TIM0_CH0_GPR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR1 *)0xF0101004u)

/** \brief  1030, TIM Channel Interrupt Enable Register */
#define GTM_TIM0_CH0_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_EN *)0xF0101030u)

/** \brief  1034, TIM Channel Software Interrupt Force Register */
#define GTM_TIM0_CH0_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_FORCINT *)0xF0101034u)

/** \brief  1038, TIM IRQ Mode Configuration Register */
#define GTM_TIM0_CH0_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_MODE *)0xF0101038u)

/** \brief  102C, TIM Channel Interrupt Notification Register */
#define GTM_TIM0_CH0_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_NOTIFY *)0xF010102Cu)

/** \brief  1014, TIM Channel TDUC Register */
#define GTM_TIM0_CH0_TDUC         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUC *)0xF0101014u)

/** \brief  1018, TIM Channel TDUV Register */
#define GTM_TIM0_CH0_TDUV         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUV *)0xF0101018u)

/** \brief  1088, TIM Channel SMU Counter Register */
#define GTM_TIM0_CH1_CNT          /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNT *)0xF0101088u)

/** \brief  1090, TIM Channel SMU Shadow Counter Register */
#define GTM_TIM0_CH1_CNTS         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNTS *)0xF0101090u)

/** \brief  10A4, TIM Channel Control Register */
#define GTM_TIM0_CH1_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CTRL *)0xF01010A4u)

/** \brief  108C, TIM Channel Edge Counter Register */
#define GTM_TIM0_CH1_ECNT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECNT *)0xF010108Cu)

/** \brief  10A8, TIM Channel External Capture Control Register */
#define GTM_TIM0_CH1_ECTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECTRL *)0xF01010A8u)

/** \brief  10BC, TIM Channel Error Interrupt Enable Register */
#define GTM_TIM0_CH1_EIRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_EIRQ_EN *)0xF01010BCu)

/** \brief  10A0, TIM Channel Filter Parameter 1 Register */
#define GTM_TIM0_CH1_FLT_FE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_FE *)0xF01010A0u)

/** \brief  109C, GTM_TIM Channel Filter Parameter 0 Register */
#define GTM_TIM0_CH1_FLT_RE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_RE *)0xF010109Cu)

/** \brief  1080, TIM Channel General Purpose 0 Register */
#define GTM_TIM0_CH1_GPR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR0 *)0xF0101080u)

/** \brief  1084, TIM Channel General Purpose 1 Register */
#define GTM_TIM0_CH1_GPR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR1 *)0xF0101084u)

/** \brief  10B0, TIM Channel Interrupt Enable Register */
#define GTM_TIM0_CH1_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_EN *)0xF01010B0u)

/** \brief  10B4, TIM Channel Software Interrupt Force Register */
#define GTM_TIM0_CH1_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_FORCINT *)0xF01010B4u)

/** \brief  10B8, TIM IRQ Mode Configuration Register */
#define GTM_TIM0_CH1_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_MODE *)0xF01010B8u)

/** \brief  10AC, TIM Channel Interrupt Notification Register */
#define GTM_TIM0_CH1_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_NOTIFY *)0xF01010ACu)

/** \brief  1094, TIM Channel TDUC Register */
#define GTM_TIM0_CH1_TDUC         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUC *)0xF0101094u)

/** \brief  1098, TIM Channel TDUV Register */
#define GTM_TIM0_CH1_TDUV         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUV *)0xF0101098u)

/** \brief  1108, TIM Channel SMU Counter Register */
#define GTM_TIM0_CH2_CNT          /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNT *)0xF0101108u)

/** \brief  1110, TIM Channel SMU Shadow Counter Register */
#define GTM_TIM0_CH2_CNTS         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNTS *)0xF0101110u)

/** \brief  1124, TIM Channel Control Register */
#define GTM_TIM0_CH2_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CTRL *)0xF0101124u)

/** \brief  110C, TIM Channel Edge Counter Register */
#define GTM_TIM0_CH2_ECNT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECNT *)0xF010110Cu)

/** \brief  1128, TIM Channel External Capture Control Register */
#define GTM_TIM0_CH2_ECTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECTRL *)0xF0101128u)

/** \brief  113C, TIM Channel Error Interrupt Enable Register */
#define GTM_TIM0_CH2_EIRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_EIRQ_EN *)0xF010113Cu)

/** \brief  1120, TIM Channel Filter Parameter 1 Register */
#define GTM_TIM0_CH2_FLT_FE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_FE *)0xF0101120u)

/** \brief  111C, GTM_TIM Channel Filter Parameter 0 Register */
#define GTM_TIM0_CH2_FLT_RE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_RE *)0xF010111Cu)

/** \brief  1100, TIM Channel General Purpose 0 Register */
#define GTM_TIM0_CH2_GPR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR0 *)0xF0101100u)

/** \brief  1104, TIM Channel General Purpose 1 Register */
#define GTM_TIM0_CH2_GPR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR1 *)0xF0101104u)

/** \brief  1130, TIM Channel Interrupt Enable Register */
#define GTM_TIM0_CH2_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_EN *)0xF0101130u)

/** \brief  1134, TIM Channel Software Interrupt Force Register */
#define GTM_TIM0_CH2_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_FORCINT *)0xF0101134u)

/** \brief  1138, TIM IRQ Mode Configuration Register */
#define GTM_TIM0_CH2_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_MODE *)0xF0101138u)

/** \brief  112C, TIM Channel Interrupt Notification Register */
#define GTM_TIM0_CH2_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_NOTIFY *)0xF010112Cu)

/** \brief  1114, TIM Channel TDUC Register */
#define GTM_TIM0_CH2_TDUC         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUC *)0xF0101114u)

/** \brief  1118, TIM Channel TDUV Register */
#define GTM_TIM0_CH2_TDUV         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUV *)0xF0101118u)

/** \brief  1188, TIM Channel SMU Counter Register */
#define GTM_TIM0_CH3_CNT          /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNT *)0xF0101188u)

/** \brief  1190, TIM Channel SMU Shadow Counter Register */
#define GTM_TIM0_CH3_CNTS         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNTS *)0xF0101190u)

/** \brief  11A4, TIM Channel Control Register */
#define GTM_TIM0_CH3_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CTRL *)0xF01011A4u)

/** \brief  118C, TIM Channel Edge Counter Register */
#define GTM_TIM0_CH3_ECNT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECNT *)0xF010118Cu)

/** \brief  11A8, TIM Channel External Capture Control Register */
#define GTM_TIM0_CH3_ECTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECTRL *)0xF01011A8u)

/** \brief  11BC, TIM Channel Error Interrupt Enable Register */
#define GTM_TIM0_CH3_EIRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_EIRQ_EN *)0xF01011BCu)

/** \brief  11A0, TIM Channel Filter Parameter 1 Register */
#define GTM_TIM0_CH3_FLT_FE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_FE *)0xF01011A0u)

/** \brief  119C, GTM_TIM Channel Filter Parameter 0 Register */
#define GTM_TIM0_CH3_FLT_RE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_RE *)0xF010119Cu)

/** \brief  1180, TIM Channel General Purpose 0 Register */
#define GTM_TIM0_CH3_GPR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR0 *)0xF0101180u)

/** \brief  1184, TIM Channel General Purpose 1 Register */
#define GTM_TIM0_CH3_GPR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR1 *)0xF0101184u)

/** \brief  11B0, TIM Channel Interrupt Enable Register */
#define GTM_TIM0_CH3_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_EN *)0xF01011B0u)

/** \brief  11B4, TIM Channel Software Interrupt Force Register */
#define GTM_TIM0_CH3_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_FORCINT *)0xF01011B4u)

/** \brief  11B8, TIM IRQ Mode Configuration Register */
#define GTM_TIM0_CH3_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_MODE *)0xF01011B8u)

/** \brief  11AC, TIM Channel Interrupt Notification Register */
#define GTM_TIM0_CH3_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_NOTIFY *)0xF01011ACu)

/** \brief  1194, TIM Channel TDUC Register */
#define GTM_TIM0_CH3_TDUC         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUC *)0xF0101194u)

/** \brief  1198, TIM Channel TDUV Register */
#define GTM_TIM0_CH3_TDUV         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUV *)0xF0101198u)

/** \brief  1208, TIM Channel SMU Counter Register */
#define GTM_TIM0_CH4_CNT          /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNT *)0xF0101208u)

/** \brief  1210, TIM Channel SMU Shadow Counter Register */
#define GTM_TIM0_CH4_CNTS         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNTS *)0xF0101210u)

/** \brief  1224, TIM Channel Control Register */
#define GTM_TIM0_CH4_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CTRL *)0xF0101224u)

/** \brief  120C, TIM Channel Edge Counter Register */
#define GTM_TIM0_CH4_ECNT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECNT *)0xF010120Cu)

/** \brief  1228, TIM Channel External Capture Control Register */
#define GTM_TIM0_CH4_ECTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECTRL *)0xF0101228u)

/** \brief  123C, TIM Channel Error Interrupt Enable Register */
#define GTM_TIM0_CH4_EIRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_EIRQ_EN *)0xF010123Cu)

/** \brief  1220, TIM Channel Filter Parameter 1 Register */
#define GTM_TIM0_CH4_FLT_FE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_FE *)0xF0101220u)

/** \brief  121C, GTM_TIM Channel Filter Parameter 0 Register */
#define GTM_TIM0_CH4_FLT_RE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_RE *)0xF010121Cu)

/** \brief  1200, TIM Channel General Purpose 0 Register */
#define GTM_TIM0_CH4_GPR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR0 *)0xF0101200u)

/** \brief  1204, TIM Channel General Purpose 1 Register */
#define GTM_TIM0_CH4_GPR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR1 *)0xF0101204u)

/** \brief  1230, TIM Channel Interrupt Enable Register */
#define GTM_TIM0_CH4_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_EN *)0xF0101230u)

/** \brief  1234, TIM Channel Software Interrupt Force Register */
#define GTM_TIM0_CH4_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_FORCINT *)0xF0101234u)

/** \brief  1238, TIM IRQ Mode Configuration Register */
#define GTM_TIM0_CH4_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_MODE *)0xF0101238u)

/** \brief  122C, TIM Channel Interrupt Notification Register */
#define GTM_TIM0_CH4_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_NOTIFY *)0xF010122Cu)

/** \brief  1214, TIM Channel TDUC Register */
#define GTM_TIM0_CH4_TDUC         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUC *)0xF0101214u)

/** \brief  1218, TIM Channel TDUV Register */
#define GTM_TIM0_CH4_TDUV         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUV *)0xF0101218u)

/** \brief  1288, TIM Channel SMU Counter Register */
#define GTM_TIM0_CH5_CNT          /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNT *)0xF0101288u)

/** \brief  1290, TIM Channel SMU Shadow Counter Register */
#define GTM_TIM0_CH5_CNTS         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNTS *)0xF0101290u)

/** \brief  12A4, TIM Channel Control Register */
#define GTM_TIM0_CH5_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CTRL *)0xF01012A4u)

/** \brief  128C, TIM Channel Edge Counter Register */
#define GTM_TIM0_CH5_ECNT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECNT *)0xF010128Cu)

/** \brief  12A8, TIM Channel External Capture Control Register */
#define GTM_TIM0_CH5_ECTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECTRL *)0xF01012A8u)

/** \brief  12BC, TIM Channel Error Interrupt Enable Register */
#define GTM_TIM0_CH5_EIRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_EIRQ_EN *)0xF01012BCu)

/** \brief  12A0, TIM Channel Filter Parameter 1 Register */
#define GTM_TIM0_CH5_FLT_FE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_FE *)0xF01012A0u)

/** \brief  129C, GTM_TIM Channel Filter Parameter 0 Register */
#define GTM_TIM0_CH5_FLT_RE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_RE *)0xF010129Cu)

/** \brief  1280, TIM Channel General Purpose 0 Register */
#define GTM_TIM0_CH5_GPR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR0 *)0xF0101280u)

/** \brief  1284, TIM Channel General Purpose 1 Register */
#define GTM_TIM0_CH5_GPR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR1 *)0xF0101284u)

/** \brief  12B0, TIM Channel Interrupt Enable Register */
#define GTM_TIM0_CH5_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_EN *)0xF01012B0u)

/** \brief  12B4, TIM Channel Software Interrupt Force Register */
#define GTM_TIM0_CH5_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_FORCINT *)0xF01012B4u)

/** \brief  12B8, TIM IRQ Mode Configuration Register */
#define GTM_TIM0_CH5_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_MODE *)0xF01012B8u)

/** \brief  12AC, TIM Channel Interrupt Notification Register */
#define GTM_TIM0_CH5_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_NOTIFY *)0xF01012ACu)

/** \brief  1294, TIM Channel TDUC Register */
#define GTM_TIM0_CH5_TDUC         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUC *)0xF0101294u)

/** \brief  1298, TIM Channel TDUV Register */
#define GTM_TIM0_CH5_TDUV         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUV *)0xF0101298u)

/** \brief  1308, TIM Channel SMU Counter Register */
#define GTM_TIM0_CH6_CNT          /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNT *)0xF0101308u)

/** \brief  1310, TIM Channel SMU Shadow Counter Register */
#define GTM_TIM0_CH6_CNTS         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNTS *)0xF0101310u)

/** \brief  1324, TIM Channel Control Register */
#define GTM_TIM0_CH6_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CTRL *)0xF0101324u)

/** \brief  130C, TIM Channel Edge Counter Register */
#define GTM_TIM0_CH6_ECNT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECNT *)0xF010130Cu)

/** \brief  1328, TIM Channel External Capture Control Register */
#define GTM_TIM0_CH6_ECTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECTRL *)0xF0101328u)

/** \brief  133C, TIM Channel Error Interrupt Enable Register */
#define GTM_TIM0_CH6_EIRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_EIRQ_EN *)0xF010133Cu)

/** \brief  1320, TIM Channel Filter Parameter 1 Register */
#define GTM_TIM0_CH6_FLT_FE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_FE *)0xF0101320u)

/** \brief  131C, GTM_TIM Channel Filter Parameter 0 Register */
#define GTM_TIM0_CH6_FLT_RE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_RE *)0xF010131Cu)

/** \brief  1300, TIM Channel General Purpose 0 Register */
#define GTM_TIM0_CH6_GPR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR0 *)0xF0101300u)

/** \brief  1304, TIM Channel General Purpose 1 Register */
#define GTM_TIM0_CH6_GPR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR1 *)0xF0101304u)

/** \brief  1330, TIM Channel Interrupt Enable Register */
#define GTM_TIM0_CH6_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_EN *)0xF0101330u)

/** \brief  1334, TIM Channel Software Interrupt Force Register */
#define GTM_TIM0_CH6_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_FORCINT *)0xF0101334u)

/** \brief  1338, TIM IRQ Mode Configuration Register */
#define GTM_TIM0_CH6_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_MODE *)0xF0101338u)

/** \brief  132C, TIM Channel Interrupt Notification Register */
#define GTM_TIM0_CH6_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_NOTIFY *)0xF010132Cu)

/** \brief  1314, TIM Channel TDUC Register */
#define GTM_TIM0_CH6_TDUC         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUC *)0xF0101314u)

/** \brief  1318, TIM Channel TDUV Register */
#define GTM_TIM0_CH6_TDUV         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUV *)0xF0101318u)

/** \brief  1388, TIM Channel SMU Counter Register */
#define GTM_TIM0_CH7_CNT          /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNT *)0xF0101388u)

/** \brief  1390, TIM Channel SMU Shadow Counter Register */
#define GTM_TIM0_CH7_CNTS         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CNTS *)0xF0101390u)

/** \brief  13A4, TIM Channel Control Register */
#define GTM_TIM0_CH7_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_CTRL *)0xF01013A4u)

/** \brief  138C, TIM Channel Edge Counter Register */
#define GTM_TIM0_CH7_ECNT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECNT *)0xF010138Cu)

/** \brief  13A8, TIM Channel External Capture Control Register */
#define GTM_TIM0_CH7_ECTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_ECTRL *)0xF01013A8u)

/** \brief  13BC, TIM Channel Error Interrupt Enable Register */
#define GTM_TIM0_CH7_EIRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_EIRQ_EN *)0xF01013BCu)

/** \brief  13A0, TIM Channel Filter Parameter 1 Register */
#define GTM_TIM0_CH7_FLT_FE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_FE *)0xF01013A0u)

/** \brief  139C, GTM_TIM Channel Filter Parameter 0 Register */
#define GTM_TIM0_CH7_FLT_RE       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_FLT_RE *)0xF010139Cu)

/** \brief  1380, TIM Channel General Purpose 0 Register */
#define GTM_TIM0_CH7_GPR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR0 *)0xF0101380u)

/** \brief  1384, TIM Channel General Purpose 1 Register */
#define GTM_TIM0_CH7_GPR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_GPR1 *)0xF0101384u)

/** \brief  13B0, TIM Channel Interrupt Enable Register */
#define GTM_TIM0_CH7_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_EN *)0xF01013B0u)

/** \brief  13B4, TIM Channel Software Interrupt Force Register */
#define GTM_TIM0_CH7_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_FORCINT *)0xF01013B4u)

/** \brief  13B8, TIM IRQ Mode Configuration Register */
#define GTM_TIM0_CH7_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_MODE *)0xF01013B8u)

/** \brief  13AC, TIM Channel Interrupt Notification Register */
#define GTM_TIM0_CH7_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_IRQ_NOTIFY *)0xF01013ACu)

/** \brief  1394, TIM Channel TDUC Register */
#define GTM_TIM0_CH7_TDUC         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUC *)0xF0101394u)

/** \brief  1398, TIM Channel TDUV Register */
#define GTM_TIM0_CH7_TDUV         /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_CH_TDUV *)0xF0101398u)

/** \brief  1078, TIM_IN_SRC Long Name */
#define GTM_TIM0_IN_SRC           /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_IN_SRC *)0xF0101078u)

/** \brief  1074, TIM Input Value Register */
#define GTM_TIM0_INP_VAL          /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_INP_VAL *)0xF0101074u)

/** \brief  107C, TIM Global Software Reset Register */
#define GTM_TIM0_RST              /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_RST *)0xF010107Cu)

/** \brief  40, GTM TIM  AUX_IN_SRC */
#define GTM_TIM_AUX_IN_SRC0       /*lint --e(923)*/ (*(volatile Ifx_GTM_TIM_AUX_IN_SRC *)0xF0100040u)

/** Alias (User Manual Name) for GTM_TIM_AUX_IN_SRC0.
 * To use register names with standard convension, please use GTM_TIM_AUX_IN_SRC0.
 */
#define GTM_TIM0_AUX_IN_SRC       (GTM_TIM_AUX_IN_SRC0)

/** \brief  800C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH0_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010800Cu)

/** \brief  8010, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH0_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108010u)

/** \brief  8014, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH0_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108014u)

/** \brief  8000, TOM Channel Control Register’ */
#define GTM_TOM0_CH0_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108000u)

/** \brief  8020, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH0_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108020u)

/** \brief  8024, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH0_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108024u)

/** \brief  8028, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH0_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108028u)

/** \brief  801C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH0_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010801Cu)

/** \brief  8004, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH0_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108004u)

/** \brief  8008, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH0_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108008u)

/** \brief  8018, TOM Channel Status Register */
#define GTM_TOM0_CH0_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108018u)

/** \brief  828C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH10_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010828Cu)

/** \brief  8290, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH10_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108290u)

/** \brief  8294, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH10_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108294u)

/** \brief  8280, TOM Channel Control Register’ */
#define GTM_TOM0_CH10_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108280u)

/** \brief  82A0, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH10_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01082A0u)

/** \brief  82A4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH10_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01082A4u)

/** \brief  82A8, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH10_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01082A8u)

/** \brief  829C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH10_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010829Cu)

/** \brief  8284, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH10_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108284u)

/** \brief  8288, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH10_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108288u)

/** \brief  8298, TOM Channel Status Register */
#define GTM_TOM0_CH10_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108298u)

/** \brief  82CC, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH11_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF01082CCu)

/** \brief  82D0, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH11_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF01082D0u)

/** \brief  82D4, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH11_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF01082D4u)

/** \brief  82C0, TOM Channel Control Register’ */
#define GTM_TOM0_CH11_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF01082C0u)

/** \brief  82E0, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH11_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01082E0u)

/** \brief  82E4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH11_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01082E4u)

/** \brief  82E8, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH11_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01082E8u)

/** \brief  82DC, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH11_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF01082DCu)

/** \brief  82C4, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH11_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF01082C4u)

/** \brief  82C8, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH11_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF01082C8u)

/** \brief  82D8, TOM Channel Status Register */
#define GTM_TOM0_CH11_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF01082D8u)

/** \brief  830C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH12_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010830Cu)

/** \brief  8310, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH12_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108310u)

/** \brief  8314, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH12_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108314u)

/** \brief  8300, TOM Channel Control Register’ */
#define GTM_TOM0_CH12_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108300u)

/** \brief  8320, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH12_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108320u)

/** \brief  8324, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH12_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108324u)

/** \brief  8328, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH12_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108328u)

/** \brief  831C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH12_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010831Cu)

/** \brief  8304, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH12_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108304u)

/** \brief  8308, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH12_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108308u)

/** \brief  8318, TOM Channel Status Register */
#define GTM_TOM0_CH12_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108318u)

/** \brief  834C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH13_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010834Cu)

/** \brief  8350, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH13_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108350u)

/** \brief  8354, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH13_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108354u)

/** \brief  8340, TOM Channel Control Register’ */
#define GTM_TOM0_CH13_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108340u)

/** \brief  8360, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH13_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108360u)

/** \brief  8364, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH13_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108364u)

/** \brief  8368, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH13_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108368u)

/** \brief  835C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH13_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010835Cu)

/** \brief  8344, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH13_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108344u)

/** \brief  8348, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH13_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108348u)

/** \brief  8358, TOM Channel Status Register */
#define GTM_TOM0_CH13_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108358u)

/** \brief  838C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH14_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010838Cu)

/** \brief  8390, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH14_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108390u)

/** \brief  8394, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH14_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108394u)

/** \brief  8380, TOM Channel Control Register’ */
#define GTM_TOM0_CH14_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108380u)

/** \brief  83A0, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH14_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01083A0u)

/** \brief  83A4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH14_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01083A4u)

/** \brief  83A8, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH14_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01083A8u)

/** \brief  839C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH14_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010839Cu)

/** \brief  8384, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH14_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108384u)

/** \brief  8388, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH14_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108388u)

/** \brief  8398, TOM Channel Status Register */
#define GTM_TOM0_CH14_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108398u)

/** \brief  83CC, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH15_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF01083CCu)

/** \brief  83D0, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH15_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF01083D0u)

/** \brief  83D4, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH15_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF01083D4u)

/** \brief  83C0, TOM Channel Control Register’ */
#define GTM_TOM0_CH15_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF01083C0u)

/** \brief  83E0, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH15_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01083E0u)

/** \brief  83E4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH15_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01083E4u)

/** \brief  83E8, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH15_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01083E8u)

/** \brief  83DC, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH15_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF01083DCu)

/** \brief  83C4, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH15_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF01083C4u)

/** \brief  83C8, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH15_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF01083C8u)

/** \brief  83D8, TOM Channel Status Register */
#define GTM_TOM0_CH15_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF01083D8u)

/** \brief  804C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH1_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010804Cu)

/** \brief  8050, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH1_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108050u)

/** \brief  8054, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH1_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108054u)

/** \brief  8040, TOM Channel Control Register’ */
#define GTM_TOM0_CH1_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108040u)

/** \brief  8060, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH1_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108060u)

/** \brief  8064, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH1_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108064u)

/** \brief  8068, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH1_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108068u)

/** \brief  805C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH1_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010805Cu)

/** \brief  8044, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH1_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108044u)

/** \brief  8048, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH1_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108048u)

/** \brief  8058, TOM Channel Status Register */
#define GTM_TOM0_CH1_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108058u)

/** \brief  808C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH2_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010808Cu)

/** \brief  8090, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH2_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108090u)

/** \brief  8094, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH2_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108094u)

/** \brief  8080, TOM Channel Control Register’ */
#define GTM_TOM0_CH2_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108080u)

/** \brief  80A0, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH2_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01080A0u)

/** \brief  80A4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH2_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01080A4u)

/** \brief  80A8, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH2_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01080A8u)

/** \brief  809C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH2_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010809Cu)

/** \brief  8084, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH2_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108084u)

/** \brief  8088, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH2_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108088u)

/** \brief  8098, TOM Channel Status Register */
#define GTM_TOM0_CH2_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108098u)

/** \brief  80CC, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH3_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF01080CCu)

/** \brief  80D0, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH3_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF01080D0u)

/** \brief  80D4, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH3_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF01080D4u)

/** \brief  80C0, TOM Channel Control Register’ */
#define GTM_TOM0_CH3_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF01080C0u)

/** \brief  80E0, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH3_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01080E0u)

/** \brief  80E4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH3_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01080E4u)

/** \brief  80E8, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH3_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01080E8u)

/** \brief  80DC, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH3_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF01080DCu)

/** \brief  80C4, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH3_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF01080C4u)

/** \brief  80C8, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH3_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF01080C8u)

/** \brief  80D8, TOM Channel Status Register */
#define GTM_TOM0_CH3_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF01080D8u)

/** \brief  810C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH4_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010810Cu)

/** \brief  8110, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH4_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108110u)

/** \brief  8114, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH4_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108114u)

/** \brief  8100, TOM Channel Control Register’ */
#define GTM_TOM0_CH4_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108100u)

/** \brief  8120, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH4_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108120u)

/** \brief  8124, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH4_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108124u)

/** \brief  8128, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH4_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108128u)

/** \brief  811C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH4_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010811Cu)

/** \brief  8104, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH4_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108104u)

/** \brief  8108, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH4_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108108u)

/** \brief  8118, TOM Channel Status Register */
#define GTM_TOM0_CH4_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108118u)

/** \brief  814C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH5_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010814Cu)

/** \brief  8150, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH5_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108150u)

/** \brief  8154, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH5_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108154u)

/** \brief  8140, TOM Channel Control Register’ */
#define GTM_TOM0_CH5_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108140u)

/** \brief  8160, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH5_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108160u)

/** \brief  8164, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH5_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108164u)

/** \brief  8168, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH5_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108168u)

/** \brief  815C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH5_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010815Cu)

/** \brief  8144, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH5_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108144u)

/** \brief  8148, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH5_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108148u)

/** \brief  8158, TOM Channel Status Register */
#define GTM_TOM0_CH5_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108158u)

/** \brief  818C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH6_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010818Cu)

/** \brief  8190, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH6_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108190u)

/** \brief  8194, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH6_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108194u)

/** \brief  8180, TOM Channel Control Register’ */
#define GTM_TOM0_CH6_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108180u)

/** \brief  81A0, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH6_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01081A0u)

/** \brief  81A4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH6_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01081A4u)

/** \brief  81A8, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH6_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01081A8u)

/** \brief  819C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH6_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010819Cu)

/** \brief  8184, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH6_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108184u)

/** \brief  8188, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH6_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108188u)

/** \brief  8198, TOM Channel Status Register */
#define GTM_TOM0_CH6_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108198u)

/** \brief  81CC, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH7_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF01081CCu)

/** \brief  81D0, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH7_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF01081D0u)

/** \brief  81D4, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH7_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF01081D4u)

/** \brief  81C0, TOM Channel Control Register’ */
#define GTM_TOM0_CH7_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF01081C0u)

/** \brief  81E0, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH7_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01081E0u)

/** \brief  81E4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH7_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01081E4u)

/** \brief  81E8, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH7_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01081E8u)

/** \brief  81DC, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH7_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF01081DCu)

/** \brief  81C4, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH7_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF01081C4u)

/** \brief  81C8, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH7_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF01081C8u)

/** \brief  81D8, TOM Channel Status Register */
#define GTM_TOM0_CH7_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF01081D8u)

/** \brief  820C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH8_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010820Cu)

/** \brief  8210, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH8_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108210u)

/** \brief  8214, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH8_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108214u)

/** \brief  8200, TOM Channel Control Register’ */
#define GTM_TOM0_CH8_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108200u)

/** \brief  8220, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH8_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108220u)

/** \brief  8224, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH8_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108224u)

/** \brief  8228, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH8_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108228u)

/** \brief  821C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH8_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010821Cu)

/** \brief  8204, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH8_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108204u)

/** \brief  8208, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH8_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108208u)

/** \brief  8218, TOM Channel Status Register */
#define GTM_TOM0_CH8_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108218u)

/** \brief  824C, TOM Channel CCU0 Compare Register */
#define GTM_TOM0_CH9_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010824Cu)

/** \brief  8250, TOM Channel CCU1 Compare Register */
#define GTM_TOM0_CH9_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108250u)

/** \brief  8254, TOM Channel CCU0 Counter Register */
#define GTM_TOM0_CH9_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108254u)

/** \brief  8240, TOM Channel Control Register’ */
#define GTM_TOM0_CH9_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108240u)

/** \brief  8260, TOM Channel Interrupt Enable Register */
#define GTM_TOM0_CH9_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108260u)

/** \brief  8264, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM0_CH9_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108264u)

/** \brief  8268, TOM IRQ Mode Configuration Register */
#define GTM_TOM0_CH9_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108268u)

/** \brief  825C, TOM Channel Interrupt Notification Register */
#define GTM_TOM0_CH9_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010825Cu)

/** \brief  8244, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM0_CH9_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108244u)

/** \brief  8248, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM0_CH9_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108248u)

/** \brief  8258, TOM Channel Status Register */
#define GTM_TOM0_CH9_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108258u)

/** \brief  8034, TOM TGC0 Action Time Base Register */
#define GTM_TOM0_TGC0_ACT_TB      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_ACT_TB *)0xF0108034u)

/** \brief  8070, TOM TGC0 Enable/Disable Control Register */
#define GTM_TOM0_TGC0_ENDIS_CTRL  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_ENDIS_CTRL *)0xF0108070u)

/** \brief  8074, TOM TGC0 Enable/Disable Status Register */
#define GTM_TOM0_TGC0_ENDIS_STAT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_ENDIS_STAT *)0xF0108074u)

/** \brief  8038, TOM TGC0 Force Update Control Register */
#define GTM_TOM0_TGC0_FUPD_CTRL   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_FUPD_CTRL *)0xF0108038u)

/** \brief  8030, TOM TGC0 Global Control Register */
#define GTM_TOM0_TGC0_GLB_CTRL    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_GLB_CTRL *)0xF0108030u)

/** \brief  803C, TOM TGC0 Internal Trigger Control Register */
#define GTM_TOM0_TGC0_INT_TRIG    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_INT_TRIG *)0xF010803Cu)

/** \brief  8078, TOM TGC0 Output Enable Control Register */
#define GTM_TOM0_TGC0_OUTEN_CTRL  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_OUTEN_CTRL *)0xF0108078u)

/** \brief  807C, TOM TGC0 Output Enable Status Register */
#define GTM_TOM0_TGC0_OUTEN_STAT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_OUTEN_STAT *)0xF010807Cu)

/** \brief  8234, TOM TGC1 Action Time Base Register */
#define GTM_TOM0_TGC1_ACT_TB      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_ACT_TB *)0xF0108234u)

/** \brief  8270, TOM TGC1 Enable/Disable Control Register */
#define GTM_TOM0_TGC1_ENDIS_CTRL  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_ENDIS_CTRL *)0xF0108270u)

/** \brief  8274, TOM TGC1 Enable/Disable Status Register */
#define GTM_TOM0_TGC1_ENDIS_STAT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_ENDIS_STAT *)0xF0108274u)

/** \brief  8238, TOM TGC1 Force Update Control Register */
#define GTM_TOM0_TGC1_FUPD_CTRL   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_FUPD_CTRL *)0xF0108238u)

/** \brief  8230, TOM TGC1 Global Control Register */
#define GTM_TOM0_TGC1_GLB_CTRL    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_GLB_CTRL *)0xF0108230u)

/** \brief  823C, TOM TGC1 Internal Trigger Control Register */
#define GTM_TOM0_TGC1_INT_TRIG    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_INT_TRIG *)0xF010823Cu)

/** \brief  8278, TOM TGC1 Output Enable Control Register */
#define GTM_TOM0_TGC1_OUTEN_CTRL  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_OUTEN_CTRL *)0xF0108278u)

/** \brief  827C, TOM TGC1 Output Enable Status Register */
#define GTM_TOM0_TGC1_OUTEN_STAT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_OUTEN_STAT *)0xF010827Cu)

/** \brief  880C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH0_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010880Cu)

/** \brief  8810, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH0_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108810u)

/** \brief  8814, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH0_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108814u)

/** \brief  8800, TOM Channel Control Register’ */
#define GTM_TOM1_CH0_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108800u)

/** \brief  8820, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH0_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108820u)

/** \brief  8824, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH0_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108824u)

/** \brief  8828, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH0_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108828u)

/** \brief  881C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH0_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010881Cu)

/** \brief  8804, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH0_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108804u)

/** \brief  8808, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH0_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108808u)

/** \brief  8818, TOM Channel Status Register */
#define GTM_TOM1_CH0_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108818u)

/** \brief  8A8C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH10_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF0108A8Cu)

/** \brief  8A90, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH10_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108A90u)

/** \brief  8A94, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH10_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108A94u)

/** \brief  8A80, TOM Channel Control Register’ */
#define GTM_TOM1_CH10_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108A80u)

/** \brief  8AA0, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH10_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108AA0u)

/** \brief  8AA4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH10_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108AA4u)

/** \brief  8AA8, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH10_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108AA8u)

/** \brief  8A9C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH10_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF0108A9Cu)

/** \brief  8A84, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH10_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108A84u)

/** \brief  8A88, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH10_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108A88u)

/** \brief  8A98, TOM Channel Status Register */
#define GTM_TOM1_CH10_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108A98u)

/** \brief  8ACC, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH11_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF0108ACCu)

/** \brief  8AD0, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH11_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108AD0u)

/** \brief  8AD4, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH11_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108AD4u)

/** \brief  8AC0, TOM Channel Control Register’ */
#define GTM_TOM1_CH11_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108AC0u)

/** \brief  8AE0, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH11_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108AE0u)

/** \brief  8AE4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH11_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108AE4u)

/** \brief  8AE8, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH11_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108AE8u)

/** \brief  8ADC, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH11_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF0108ADCu)

/** \brief  8AC4, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH11_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108AC4u)

/** \brief  8AC8, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH11_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108AC8u)

/** \brief  8AD8, TOM Channel Status Register */
#define GTM_TOM1_CH11_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108AD8u)

/** \brief  8B0C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH12_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF0108B0Cu)

/** \brief  8B10, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH12_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108B10u)

/** \brief  8B14, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH12_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108B14u)

/** \brief  8B00, TOM Channel Control Register’ */
#define GTM_TOM1_CH12_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108B00u)

/** \brief  8B20, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH12_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108B20u)

/** \brief  8B24, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH12_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108B24u)

/** \brief  8B28, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH12_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108B28u)

/** \brief  8B1C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH12_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF0108B1Cu)

/** \brief  8B04, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH12_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108B04u)

/** \brief  8B08, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH12_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108B08u)

/** \brief  8B18, TOM Channel Status Register */
#define GTM_TOM1_CH12_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108B18u)

/** \brief  8B4C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH13_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF0108B4Cu)

/** \brief  8B50, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH13_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108B50u)

/** \brief  8B54, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH13_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108B54u)

/** \brief  8B40, TOM Channel Control Register’ */
#define GTM_TOM1_CH13_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108B40u)

/** \brief  8B60, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH13_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108B60u)

/** \brief  8B64, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH13_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108B64u)

/** \brief  8B68, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH13_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108B68u)

/** \brief  8B5C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH13_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF0108B5Cu)

/** \brief  8B44, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH13_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108B44u)

/** \brief  8B48, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH13_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108B48u)

/** \brief  8B58, TOM Channel Status Register */
#define GTM_TOM1_CH13_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108B58u)

/** \brief  8B8C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH14_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF0108B8Cu)

/** \brief  8B90, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH14_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108B90u)

/** \brief  8B94, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH14_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108B94u)

/** \brief  8B80, TOM Channel Control Register’ */
#define GTM_TOM1_CH14_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108B80u)

/** \brief  8BA0, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH14_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108BA0u)

/** \brief  8BA4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH14_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108BA4u)

/** \brief  8BA8, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH14_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108BA8u)

/** \brief  8B9C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH14_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF0108B9Cu)

/** \brief  8B84, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH14_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108B84u)

/** \brief  8B88, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH14_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108B88u)

/** \brief  8B98, TOM Channel Status Register */
#define GTM_TOM1_CH14_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108B98u)

/** \brief  8BCC, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH15_CM0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF0108BCCu)

/** \brief  8BD0, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH15_CM1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108BD0u)

/** \brief  8BD4, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH15_CN0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108BD4u)

/** \brief  8BC0, TOM Channel Control Register’ */
#define GTM_TOM1_CH15_CTRL        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108BC0u)

/** \brief  8BE0, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH15_IRQ_EN      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108BE0u)

/** \brief  8BE4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH15_IRQ_FORCINT /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108BE4u)

/** \brief  8BE8, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH15_IRQ_MODE    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108BE8u)

/** \brief  8BDC, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH15_IRQ_NOTIFY  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF0108BDCu)

/** \brief  8BC4, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH15_SR0         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108BC4u)

/** \brief  8BC8, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH15_SR1         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108BC8u)

/** \brief  8BD8, TOM Channel Status Register */
#define GTM_TOM1_CH15_STAT        /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108BD8u)

/** \brief  884C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH1_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010884Cu)

/** \brief  8850, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH1_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108850u)

/** \brief  8854, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH1_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108854u)

/** \brief  8840, TOM Channel Control Register’ */
#define GTM_TOM1_CH1_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108840u)

/** \brief  8860, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH1_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108860u)

/** \brief  8864, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH1_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108864u)

/** \brief  8868, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH1_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108868u)

/** \brief  885C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH1_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010885Cu)

/** \brief  8844, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH1_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108844u)

/** \brief  8848, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH1_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108848u)

/** \brief  8858, TOM Channel Status Register */
#define GTM_TOM1_CH1_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108858u)

/** \brief  888C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH2_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010888Cu)

/** \brief  8890, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH2_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108890u)

/** \brief  8894, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH2_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108894u)

/** \brief  8880, TOM Channel Control Register’ */
#define GTM_TOM1_CH2_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108880u)

/** \brief  88A0, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH2_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01088A0u)

/** \brief  88A4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH2_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01088A4u)

/** \brief  88A8, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH2_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01088A8u)

/** \brief  889C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH2_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010889Cu)

/** \brief  8884, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH2_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108884u)

/** \brief  8888, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH2_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108888u)

/** \brief  8898, TOM Channel Status Register */
#define GTM_TOM1_CH2_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108898u)

/** \brief  88CC, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH3_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF01088CCu)

/** \brief  88D0, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH3_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF01088D0u)

/** \brief  88D4, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH3_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF01088D4u)

/** \brief  88C0, TOM Channel Control Register’ */
#define GTM_TOM1_CH3_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF01088C0u)

/** \brief  88E0, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH3_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01088E0u)

/** \brief  88E4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH3_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01088E4u)

/** \brief  88E8, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH3_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01088E8u)

/** \brief  88DC, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH3_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF01088DCu)

/** \brief  88C4, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH3_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF01088C4u)

/** \brief  88C8, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH3_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF01088C8u)

/** \brief  88D8, TOM Channel Status Register */
#define GTM_TOM1_CH3_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF01088D8u)

/** \brief  890C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH4_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010890Cu)

/** \brief  8910, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH4_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108910u)

/** \brief  8914, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH4_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108914u)

/** \brief  8900, TOM Channel Control Register’ */
#define GTM_TOM1_CH4_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108900u)

/** \brief  8920, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH4_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108920u)

/** \brief  8924, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH4_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108924u)

/** \brief  8928, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH4_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108928u)

/** \brief  891C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH4_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010891Cu)

/** \brief  8904, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH4_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108904u)

/** \brief  8908, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH4_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108908u)

/** \brief  8918, TOM Channel Status Register */
#define GTM_TOM1_CH4_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108918u)

/** \brief  894C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH5_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010894Cu)

/** \brief  8950, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH5_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108950u)

/** \brief  8954, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH5_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108954u)

/** \brief  8940, TOM Channel Control Register’ */
#define GTM_TOM1_CH5_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108940u)

/** \brief  8960, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH5_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108960u)

/** \brief  8964, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH5_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108964u)

/** \brief  8968, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH5_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108968u)

/** \brief  895C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH5_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010895Cu)

/** \brief  8944, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH5_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108944u)

/** \brief  8948, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH5_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108948u)

/** \brief  8958, TOM Channel Status Register */
#define GTM_TOM1_CH5_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108958u)

/** \brief  898C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH6_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF010898Cu)

/** \brief  8990, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH6_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108990u)

/** \brief  8994, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH6_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108994u)

/** \brief  8980, TOM Channel Control Register’ */
#define GTM_TOM1_CH6_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108980u)

/** \brief  89A0, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH6_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01089A0u)

/** \brief  89A4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH6_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01089A4u)

/** \brief  89A8, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH6_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01089A8u)

/** \brief  899C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH6_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF010899Cu)

/** \brief  8984, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH6_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108984u)

/** \brief  8988, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH6_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108988u)

/** \brief  8998, TOM Channel Status Register */
#define GTM_TOM1_CH6_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108998u)

/** \brief  89CC, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH7_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF01089CCu)

/** \brief  89D0, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH7_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF01089D0u)

/** \brief  89D4, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH7_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF01089D4u)

/** \brief  89C0, TOM Channel Control Register’ */
#define GTM_TOM1_CH7_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF01089C0u)

/** \brief  89E0, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH7_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF01089E0u)

/** \brief  89E4, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH7_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF01089E4u)

/** \brief  89E8, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH7_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF01089E8u)

/** \brief  89DC, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH7_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF01089DCu)

/** \brief  89C4, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH7_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF01089C4u)

/** \brief  89C8, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH7_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF01089C8u)

/** \brief  89D8, TOM Channel Status Register */
#define GTM_TOM1_CH7_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF01089D8u)

/** \brief  8A0C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH8_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF0108A0Cu)

/** \brief  8A10, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH8_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108A10u)

/** \brief  8A14, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH8_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108A14u)

/** \brief  8A00, TOM Channel Control Register’ */
#define GTM_TOM1_CH8_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108A00u)

/** \brief  8A20, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH8_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108A20u)

/** \brief  8A24, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH8_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108A24u)

/** \brief  8A28, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH8_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108A28u)

/** \brief  8A1C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH8_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF0108A1Cu)

/** \brief  8A04, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH8_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108A04u)

/** \brief  8A08, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH8_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108A08u)

/** \brief  8A18, TOM Channel Status Register */
#define GTM_TOM1_CH8_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108A18u)

/** \brief  8A4C, TOM Channel CCU0 Compare Register */
#define GTM_TOM1_CH9_CM0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM0 *)0xF0108A4Cu)

/** \brief  8A50, TOM Channel CCU1 Compare Register */
#define GTM_TOM1_CH9_CM1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CM1 *)0xF0108A50u)

/** \brief  8A54, TOM Channel CCU0 Counter Register */
#define GTM_TOM1_CH9_CN0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CN0 *)0xF0108A54u)

/** \brief  8A40, TOM Channel Control Register’ */
#define GTM_TOM1_CH9_CTRL         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_CTRL *)0xF0108A40u)

/** \brief  8A60, TOM Channel Interrupt Enable Register */
#define GTM_TOM1_CH9_IRQ_EN       /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_EN *)0xF0108A60u)

/** \brief  8A64, TOM Channel Software Interrupt Generation Register */
#define GTM_TOM1_CH9_IRQ_FORCINT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_FORCINT *)0xF0108A64u)

/** \brief  8A68, TOM IRQ Mode Configuration Register */
#define GTM_TOM1_CH9_IRQ_MODE     /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_MODE *)0xF0108A68u)

/** \brief  8A5C, TOM Channel Interrupt Notification Register */
#define GTM_TOM1_CH9_IRQ_NOTIFY   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_IRQ_NOTIFY *)0xF0108A5Cu)

/** \brief  8A44, TOM Channel CCU0 Compare Shadow Register */
#define GTM_TOM1_CH9_SR0          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR0 *)0xF0108A44u)

/** \brief  8A48, TOM Channel CCU1 Compare Shadow Register */
#define GTM_TOM1_CH9_SR1          /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_SR1 *)0xF0108A48u)

/** \brief  8A58, TOM Channel Status Register */
#define GTM_TOM1_CH9_STAT         /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_CH_STAT *)0xF0108A58u)

/** \brief  8834, TOM TGC0 Action Time Base Register */
#define GTM_TOM1_TGC0_ACT_TB      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_ACT_TB *)0xF0108834u)

/** \brief  8870, TOM TGC0 Enable/Disable Control Register */
#define GTM_TOM1_TGC0_ENDIS_CTRL  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_ENDIS_CTRL *)0xF0108870u)

/** \brief  8874, TOM TGC0 Enable/Disable Status Register */
#define GTM_TOM1_TGC0_ENDIS_STAT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_ENDIS_STAT *)0xF0108874u)

/** \brief  8838, TOM TGC0 Force Update Control Register */
#define GTM_TOM1_TGC0_FUPD_CTRL   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_FUPD_CTRL *)0xF0108838u)

/** \brief  8830, TOM TGC0 Global Control Register */
#define GTM_TOM1_TGC0_GLB_CTRL    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_GLB_CTRL *)0xF0108830u)

/** \brief  883C, TOM TGC0 Internal Trigger Control Register */
#define GTM_TOM1_TGC0_INT_TRIG    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_INT_TRIG *)0xF010883Cu)

/** \brief  8878, TOM TGC0 Output Enable Control Register */
#define GTM_TOM1_TGC0_OUTEN_CTRL  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_OUTEN_CTRL *)0xF0108878u)

/** \brief  887C, TOM TGC0 Output Enable Status Register */
#define GTM_TOM1_TGC0_OUTEN_STAT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC0_OUTEN_STAT *)0xF010887Cu)

/** \brief  8A34, TOM TGC1 Action Time Base Register */
#define GTM_TOM1_TGC1_ACT_TB      /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_ACT_TB *)0xF0108A34u)

/** \brief  8A70, TOM TGC1 Enable/Disable Control Register */
#define GTM_TOM1_TGC1_ENDIS_CTRL  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_ENDIS_CTRL *)0xF0108A70u)

/** \brief  8A74, TOM TGC1 Enable/Disable Status Register */
#define GTM_TOM1_TGC1_ENDIS_STAT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_ENDIS_STAT *)0xF0108A74u)

/** \brief  8A38, TOM TGC1 Force Update Control Register */
#define GTM_TOM1_TGC1_FUPD_CTRL   /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_FUPD_CTRL *)0xF0108A38u)

/** \brief  8A30, TOM TGC1 Global Control Register */
#define GTM_TOM1_TGC1_GLB_CTRL    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_GLB_CTRL *)0xF0108A30u)

/** \brief  8A3C, TOM TGC1 Internal Trigger Control Register */
#define GTM_TOM1_TGC1_INT_TRIG    /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_INT_TRIG *)0xF0108A3Cu)

/** \brief  8A78, TOM TGC1 Output Enable Control Register */
#define GTM_TOM1_TGC1_OUTEN_CTRL  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_OUTEN_CTRL *)0xF0108A78u)

/** \brief  8A7C, TOM TGC1 Output Enable Status Register */
#define GTM_TOM1_TGC1_OUTEN_STAT  /*lint --e(923)*/ (*(volatile Ifx_GTM_TOM_TGC1_OUTEN_STAT *)0xF0108A7Cu)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXGTM_REG_H */
