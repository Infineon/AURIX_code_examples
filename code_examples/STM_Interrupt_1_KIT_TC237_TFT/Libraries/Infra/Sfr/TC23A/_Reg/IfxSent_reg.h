/**
 * \file IfxSent_reg.h
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
 * \defgroup IfxLld_Sent_Cfg Sent address
 * \ingroup IfxLld_Sent
 *
 * \defgroup IfxLld_Sent_Cfg_BaseAddress Base address
 * \ingroup IfxLld_Sent_Cfg
 *
 * \defgroup IfxLld_Sent_Cfg_Sent 2-SENT
 * \ingroup IfxLld_Sent_Cfg
 *
 */
#ifndef IFXSENT_REG_H
#define IFXSENT_REG_H 1
/******************************************************************************/
#include "IfxSent_regdef.h"
/******************************************************************************/
/** \addtogroup IfxLld_Sent_Cfg_BaseAddress
 * \{  */

/** \brief  SENT object */
#define MODULE_SENT /*lint --e(923)*/ (*(Ifx_SENT *)0xF0003000u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Sent_Cfg_Sent
 * \{  */

/** \brief  FC, Access Enable Register 0 */
#define SENT_ACCEN0      /*lint --e(923)*/ (*(volatile Ifx_SENT_ACCEN0 *)0xF00030FCu)

/** \brief  F8, Access Enable Register 1 */
#define SENT_ACCEN1      /*lint --e(923)*/ (*(volatile Ifx_SENT_ACCEN1 *)0xF00030F8u)

/** \brief  104, Channel Fractional Divider Register */
#define SENT_CH0_CFDR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_CFDR *)0xF0003104u)

/** Alias (User Manual Name) for SENT_CH0_CFDR.
 * To use register names with standard convension, please use SENT_CH0_CFDR.
 */
#define SENT_CFDR0       (SENT_CH0_CFDR)

/** \brief  100, Channel Pre Divider Register */
#define SENT_CH0_CPDR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_CPDR *)0xF0003100u)

/** Alias (User Manual Name) for SENT_CH0_CPDR.
 * To use register names with standard convension, please use SENT_CH0_CPDR.
 */
#define SENT_CPDR0       (SENT_CH0_CPDR)

/** \brief  130, Interrupt Node Pointer Register */
#define SENT_CH0_INP     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INP *)0xF0003130u)

/** Alias (User Manual Name) for SENT_CH0_INP.
 * To use register names with standard convension, please use SENT_CH0_INP.
 */
#define SENT_INP0        (SENT_CH0_INP)

/** \brief  128, Interrupt Clear Register */
#define SENT_CH0_INTCLR  /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTCLR *)0xF0003128u)

/** Alias (User Manual Name) for SENT_CH0_INTCLR.
 * To use register names with standard convension, please use SENT_CH0_INTCLR.
 */
#define SENT_INTCLR0     (SENT_CH0_INTCLR)

/** \brief  12C, Interrupt Enable Register */
#define SENT_CH0_INTEN   /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTEN *)0xF000312Cu)

/** Alias (User Manual Name) for SENT_CH0_INTEN.
 * To use register names with standard convension, please use SENT_CH0_INTEN.
 */
#define SENT_INTEN0      (SENT_CH0_INTEN)

/** \brief  124, Interrupt Set Register */
#define SENT_CH0_INTSET  /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTSET *)0xF0003124u)

/** Alias (User Manual Name) for SENT_CH0_INTSET.
 * To use register names with standard convension, please use SENT_CH0_INTSET.
 */
#define SENT_INTSET0     (SENT_CH0_INTSET)

/** \brief  120, Interrupt Status Register */
#define SENT_CH0_INTSTAT /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTSTAT *)0xF0003120u)

/** Alias (User Manual Name) for SENT_CH0_INTSTAT.
 * To use register names with standard convension, please use SENT_CH0_INTSTAT.
 */
#define SENT_INTSTAT0    (SENT_CH0_INTSTAT)

/** \brief  114, Input and Output Control Register */
#define SENT_CH0_IOCR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_IOCR *)0xF0003114u)

/** Alias (User Manual Name) for SENT_CH0_IOCR.
 * To use register names with standard convension, please use SENT_CH0_IOCR.
 */
#define SENT_IOCR0       (SENT_CH0_IOCR)

/** \brief  108, Receiver Control Register */
#define SENT_CH0_RCR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_RCR *)0xF0003108u)

/** Alias (User Manual Name) for SENT_CH0_RCR.
 * To use register names with standard convension, please use SENT_CH0_RCR.
 */
#define SENT_RCR0        (SENT_CH0_RCR)

/** \brief  10C, Receive Status Register */
#define SENT_CH0_RSR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_RSR *)0xF000310Cu)

/** Alias (User Manual Name) for SENT_CH0_RSR.
 * To use register names with standard convension, please use SENT_CH0_RSR.
 */
#define SENT_RSR0        (SENT_CH0_RSR)

/** \brief  118, SPC Control Register */
#define SENT_CH0_SCR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_SCR *)0xF0003118u)

/** Alias (User Manual Name) for SENT_CH0_SCR.
 * To use register names with standard convension, please use SENT_CH0_SCR.
 */
#define SENT_SCR0        (SENT_CH0_SCR)

/** \brief  110, Serial Data and Status Register */
#define SENT_CH0_SDS     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_SDS *)0xF0003110u)

/** Alias (User Manual Name) for SENT_CH0_SDS.
 * To use register names with standard convension, please use SENT_CH0_SDS.
 */
#define SENT_SDS0        (SENT_CH0_SDS)

/** \brief  11C, Receive Data View Register */
#define SENT_CH0_VIEW    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_VIEW *)0xF000311Cu)

/** Alias (User Manual Name) for SENT_CH0_VIEW.
 * To use register names with standard convension, please use SENT_CH0_VIEW.
 */
#define SENT_VIEW0       (SENT_CH0_VIEW)

/** \brief  134, Watch Dog Timer Register */
#define SENT_CH0_WDT     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_WDT *)0xF0003134u)

/** Alias (User Manual Name) for SENT_CH0_WDT.
 * To use register names with standard convension, please use SENT_CH0_WDT.
 */
#define SENT_WDT0        (SENT_CH0_WDT)

/** \brief  144, Channel Fractional Divider Register */
#define SENT_CH1_CFDR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_CFDR *)0xF0003144u)

/** Alias (User Manual Name) for SENT_CH1_CFDR.
 * To use register names with standard convension, please use SENT_CH1_CFDR.
 */
#define SENT_CFDR1       (SENT_CH1_CFDR)

/** \brief  140, Channel Pre Divider Register */
#define SENT_CH1_CPDR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_CPDR *)0xF0003140u)

/** Alias (User Manual Name) for SENT_CH1_CPDR.
 * To use register names with standard convension, please use SENT_CH1_CPDR.
 */
#define SENT_CPDR1       (SENT_CH1_CPDR)

/** \brief  170, Interrupt Node Pointer Register */
#define SENT_CH1_INP     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INP *)0xF0003170u)

/** Alias (User Manual Name) for SENT_CH1_INP.
 * To use register names with standard convension, please use SENT_CH1_INP.
 */
#define SENT_INP1        (SENT_CH1_INP)

/** \brief  168, Interrupt Clear Register */
#define SENT_CH1_INTCLR  /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTCLR *)0xF0003168u)

/** Alias (User Manual Name) for SENT_CH1_INTCLR.
 * To use register names with standard convension, please use SENT_CH1_INTCLR.
 */
#define SENT_INTCLR1     (SENT_CH1_INTCLR)

/** \brief  16C, Interrupt Enable Register */
#define SENT_CH1_INTEN   /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTEN *)0xF000316Cu)

/** Alias (User Manual Name) for SENT_CH1_INTEN.
 * To use register names with standard convension, please use SENT_CH1_INTEN.
 */
#define SENT_INTEN1      (SENT_CH1_INTEN)

/** \brief  164, Interrupt Set Register */
#define SENT_CH1_INTSET  /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTSET *)0xF0003164u)

/** Alias (User Manual Name) for SENT_CH1_INTSET.
 * To use register names with standard convension, please use SENT_CH1_INTSET.
 */
#define SENT_INTSET1     (SENT_CH1_INTSET)

/** \brief  160, Interrupt Status Register */
#define SENT_CH1_INTSTAT /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTSTAT *)0xF0003160u)

/** Alias (User Manual Name) for SENT_CH1_INTSTAT.
 * To use register names with standard convension, please use SENT_CH1_INTSTAT.
 */
#define SENT_INTSTAT1    (SENT_CH1_INTSTAT)

/** \brief  154, Input and Output Control Register */
#define SENT_CH1_IOCR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_IOCR *)0xF0003154u)

/** Alias (User Manual Name) for SENT_CH1_IOCR.
 * To use register names with standard convension, please use SENT_CH1_IOCR.
 */
#define SENT_IOCR1       (SENT_CH1_IOCR)

/** \brief  148, Receiver Control Register */
#define SENT_CH1_RCR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_RCR *)0xF0003148u)

/** Alias (User Manual Name) for SENT_CH1_RCR.
 * To use register names with standard convension, please use SENT_CH1_RCR.
 */
#define SENT_RCR1        (SENT_CH1_RCR)

/** \brief  14C, Receive Status Register */
#define SENT_CH1_RSR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_RSR *)0xF000314Cu)

/** Alias (User Manual Name) for SENT_CH1_RSR.
 * To use register names with standard convension, please use SENT_CH1_RSR.
 */
#define SENT_RSR1        (SENT_CH1_RSR)

/** \brief  158, SPC Control Register */
#define SENT_CH1_SCR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_SCR *)0xF0003158u)

/** Alias (User Manual Name) for SENT_CH1_SCR.
 * To use register names with standard convension, please use SENT_CH1_SCR.
 */
#define SENT_SCR1        (SENT_CH1_SCR)

/** \brief  150, Serial Data and Status Register */
#define SENT_CH1_SDS     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_SDS *)0xF0003150u)

/** Alias (User Manual Name) for SENT_CH1_SDS.
 * To use register names with standard convension, please use SENT_CH1_SDS.
 */
#define SENT_SDS1        (SENT_CH1_SDS)

/** \brief  15C, Receive Data View Register */
#define SENT_CH1_VIEW    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_VIEW *)0xF000315Cu)

/** Alias (User Manual Name) for SENT_CH1_VIEW.
 * To use register names with standard convension, please use SENT_CH1_VIEW.
 */
#define SENT_VIEW1       (SENT_CH1_VIEW)

/** \brief  174, Watch Dog Timer Register */
#define SENT_CH1_WDT     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_WDT *)0xF0003174u)

/** Alias (User Manual Name) for SENT_CH1_WDT.
 * To use register names with standard convension, please use SENT_CH1_WDT.
 */
#define SENT_WDT1        (SENT_CH1_WDT)

/** \brief  184, Channel Fractional Divider Register */
#define SENT_CH2_CFDR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_CFDR *)0xF0003184u)

/** Alias (User Manual Name) for SENT_CH2_CFDR.
 * To use register names with standard convension, please use SENT_CH2_CFDR.
 */
#define SENT_CFDR2       (SENT_CH2_CFDR)

/** \brief  180, Channel Pre Divider Register */
#define SENT_CH2_CPDR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_CPDR *)0xF0003180u)

/** Alias (User Manual Name) for SENT_CH2_CPDR.
 * To use register names with standard convension, please use SENT_CH2_CPDR.
 */
#define SENT_CPDR2       (SENT_CH2_CPDR)

/** \brief  1B0, Interrupt Node Pointer Register */
#define SENT_CH2_INP     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INP *)0xF00031B0u)

/** Alias (User Manual Name) for SENT_CH2_INP.
 * To use register names with standard convension, please use SENT_CH2_INP.
 */
#define SENT_INP2        (SENT_CH2_INP)

/** \brief  1A8, Interrupt Clear Register */
#define SENT_CH2_INTCLR  /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTCLR *)0xF00031A8u)

/** Alias (User Manual Name) for SENT_CH2_INTCLR.
 * To use register names with standard convension, please use SENT_CH2_INTCLR.
 */
#define SENT_INTCLR2     (SENT_CH2_INTCLR)

/** \brief  1AC, Interrupt Enable Register */
#define SENT_CH2_INTEN   /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTEN *)0xF00031ACu)

/** Alias (User Manual Name) for SENT_CH2_INTEN.
 * To use register names with standard convension, please use SENT_CH2_INTEN.
 */
#define SENT_INTEN2      (SENT_CH2_INTEN)

/** \brief  1A4, Interrupt Set Register */
#define SENT_CH2_INTSET  /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTSET *)0xF00031A4u)

/** Alias (User Manual Name) for SENT_CH2_INTSET.
 * To use register names with standard convension, please use SENT_CH2_INTSET.
 */
#define SENT_INTSET2     (SENT_CH2_INTSET)

/** \brief  1A0, Interrupt Status Register */
#define SENT_CH2_INTSTAT /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTSTAT *)0xF00031A0u)

/** Alias (User Manual Name) for SENT_CH2_INTSTAT.
 * To use register names with standard convension, please use SENT_CH2_INTSTAT.
 */
#define SENT_INTSTAT2    (SENT_CH2_INTSTAT)

/** \brief  194, Input and Output Control Register */
#define SENT_CH2_IOCR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_IOCR *)0xF0003194u)

/** Alias (User Manual Name) for SENT_CH2_IOCR.
 * To use register names with standard convension, please use SENT_CH2_IOCR.
 */
#define SENT_IOCR2       (SENT_CH2_IOCR)

/** \brief  188, Receiver Control Register */
#define SENT_CH2_RCR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_RCR *)0xF0003188u)

/** Alias (User Manual Name) for SENT_CH2_RCR.
 * To use register names with standard convension, please use SENT_CH2_RCR.
 */
#define SENT_RCR2        (SENT_CH2_RCR)

/** \brief  18C, Receive Status Register */
#define SENT_CH2_RSR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_RSR *)0xF000318Cu)

/** Alias (User Manual Name) for SENT_CH2_RSR.
 * To use register names with standard convension, please use SENT_CH2_RSR.
 */
#define SENT_RSR2        (SENT_CH2_RSR)

/** \brief  198, SPC Control Register */
#define SENT_CH2_SCR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_SCR *)0xF0003198u)

/** Alias (User Manual Name) for SENT_CH2_SCR.
 * To use register names with standard convension, please use SENT_CH2_SCR.
 */
#define SENT_SCR2        (SENT_CH2_SCR)

/** \brief  190, Serial Data and Status Register */
#define SENT_CH2_SDS     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_SDS *)0xF0003190u)

/** Alias (User Manual Name) for SENT_CH2_SDS.
 * To use register names with standard convension, please use SENT_CH2_SDS.
 */
#define SENT_SDS2        (SENT_CH2_SDS)

/** \brief  19C, Receive Data View Register */
#define SENT_CH2_VIEW    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_VIEW *)0xF000319Cu)

/** Alias (User Manual Name) for SENT_CH2_VIEW.
 * To use register names with standard convension, please use SENT_CH2_VIEW.
 */
#define SENT_VIEW2       (SENT_CH2_VIEW)

/** \brief  1B4, Watch Dog Timer Register */
#define SENT_CH2_WDT     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_WDT *)0xF00031B4u)

/** Alias (User Manual Name) for SENT_CH2_WDT.
 * To use register names with standard convension, please use SENT_CH2_WDT.
 */
#define SENT_WDT2        (SENT_CH2_WDT)

/** \brief  1C4, Channel Fractional Divider Register */
#define SENT_CH3_CFDR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_CFDR *)0xF00031C4u)

/** Alias (User Manual Name) for SENT_CH3_CFDR.
 * To use register names with standard convension, please use SENT_CH3_CFDR.
 */
#define SENT_CFDR3       (SENT_CH3_CFDR)

/** \brief  1C0, Channel Pre Divider Register */
#define SENT_CH3_CPDR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_CPDR *)0xF00031C0u)

/** Alias (User Manual Name) for SENT_CH3_CPDR.
 * To use register names with standard convension, please use SENT_CH3_CPDR.
 */
#define SENT_CPDR3       (SENT_CH3_CPDR)

/** \brief  1F0, Interrupt Node Pointer Register */
#define SENT_CH3_INP     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INP *)0xF00031F0u)

/** Alias (User Manual Name) for SENT_CH3_INP.
 * To use register names with standard convension, please use SENT_CH3_INP.
 */
#define SENT_INP3        (SENT_CH3_INP)

/** \brief  1E8, Interrupt Clear Register */
#define SENT_CH3_INTCLR  /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTCLR *)0xF00031E8u)

/** Alias (User Manual Name) for SENT_CH3_INTCLR.
 * To use register names with standard convension, please use SENT_CH3_INTCLR.
 */
#define SENT_INTCLR3     (SENT_CH3_INTCLR)

/** \brief  1EC, Interrupt Enable Register */
#define SENT_CH3_INTEN   /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTEN *)0xF00031ECu)

/** Alias (User Manual Name) for SENT_CH3_INTEN.
 * To use register names with standard convension, please use SENT_CH3_INTEN.
 */
#define SENT_INTEN3      (SENT_CH3_INTEN)

/** \brief  1E4, Interrupt Set Register */
#define SENT_CH3_INTSET  /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTSET *)0xF00031E4u)

/** Alias (User Manual Name) for SENT_CH3_INTSET.
 * To use register names with standard convension, please use SENT_CH3_INTSET.
 */
#define SENT_INTSET3     (SENT_CH3_INTSET)

/** \brief  1E0, Interrupt Status Register */
#define SENT_CH3_INTSTAT /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_INTSTAT *)0xF00031E0u)

/** Alias (User Manual Name) for SENT_CH3_INTSTAT.
 * To use register names with standard convension, please use SENT_CH3_INTSTAT.
 */
#define SENT_INTSTAT3    (SENT_CH3_INTSTAT)

/** \brief  1D4, Input and Output Control Register */
#define SENT_CH3_IOCR    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_IOCR *)0xF00031D4u)

/** Alias (User Manual Name) for SENT_CH3_IOCR.
 * To use register names with standard convension, please use SENT_CH3_IOCR.
 */
#define SENT_IOCR3       (SENT_CH3_IOCR)

/** \brief  1C8, Receiver Control Register */
#define SENT_CH3_RCR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_RCR *)0xF00031C8u)

/** Alias (User Manual Name) for SENT_CH3_RCR.
 * To use register names with standard convension, please use SENT_CH3_RCR.
 */
#define SENT_RCR3        (SENT_CH3_RCR)

/** \brief  1CC, Receive Status Register */
#define SENT_CH3_RSR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_RSR *)0xF00031CCu)

/** Alias (User Manual Name) for SENT_CH3_RSR.
 * To use register names with standard convension, please use SENT_CH3_RSR.
 */
#define SENT_RSR3        (SENT_CH3_RSR)

/** \brief  1D8, SPC Control Register */
#define SENT_CH3_SCR     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_SCR *)0xF00031D8u)

/** Alias (User Manual Name) for SENT_CH3_SCR.
 * To use register names with standard convension, please use SENT_CH3_SCR.
 */
#define SENT_SCR3        (SENT_CH3_SCR)

/** \brief  1D0, Serial Data and Status Register */
#define SENT_CH3_SDS     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_SDS *)0xF00031D0u)

/** Alias (User Manual Name) for SENT_CH3_SDS.
 * To use register names with standard convension, please use SENT_CH3_SDS.
 */
#define SENT_SDS3        (SENT_CH3_SDS)

/** \brief  1DC, Receive Data View Register */
#define SENT_CH3_VIEW    /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_VIEW *)0xF00031DCu)

/** Alias (User Manual Name) for SENT_CH3_VIEW.
 * To use register names with standard convension, please use SENT_CH3_VIEW.
 */
#define SENT_VIEW3       (SENT_CH3_VIEW)

/** \brief  1F4, Watch Dog Timer Register */
#define SENT_CH3_WDT     /*lint --e(923)*/ (*(volatile Ifx_SENT_CH_WDT *)0xF00031F4u)

/** Alias (User Manual Name) for SENT_CH3_WDT.
 * To use register names with standard convension, please use SENT_CH3_WDT.
 */
#define SENT_WDT3        (SENT_CH3_WDT)

/** \brief  0, Clock Control Register */
#define SENT_CLC         /*lint --e(923)*/ (*(volatile Ifx_SENT_CLC *)0xF0003000u)

/** \brief  C, SENT Fractional Divider Register */
#define SENT_FDR         /*lint --e(923)*/ (*(volatile Ifx_SENT_FDR *)0xF000300Cu)

/** \brief  8, Module Identification Register */
#define SENT_ID          /*lint --e(923)*/ (*(volatile Ifx_SENT_ID *)0xF0003008u)

/** \brief  14, Interrupt Overview Register */
#define SENT_INTOV       /*lint --e(923)*/ (*(volatile Ifx_SENT_INTOV *)0xF0003014u)

/** \brief  F4, Kernel Reset Register 0 */
#define SENT_KRST0       /*lint --e(923)*/ (*(volatile Ifx_SENT_KRST0 *)0xF00030F4u)

/** \brief  F0, Kernel Reset Register 1 */
#define SENT_KRST1       /*lint --e(923)*/ (*(volatile Ifx_SENT_KRST1 *)0xF00030F0u)

/** \brief  EC, Kernel Reset Status Clear Register */
#define SENT_KRSTCLR     /*lint --e(923)*/ (*(volatile Ifx_SENT_KRSTCLR *)0xF00030ECu)

/** \brief  E8, OCDS Control and Status */
#define SENT_OCS         /*lint --e(923)*/ (*(volatile Ifx_SENT_OCS *)0xF00030E8u)

/** \brief  80, Receive Data Register */
#define SENT_RDR0        /*lint --e(923)*/ (*(volatile Ifx_SENT_RDR *)0xF0003080u)

/** \brief  84, Receive Data Register */
#define SENT_RDR1        /*lint --e(923)*/ (*(volatile Ifx_SENT_RDR *)0xF0003084u)

/** \brief  88, Receive Data Register */
#define SENT_RDR2        /*lint --e(923)*/ (*(volatile Ifx_SENT_RDR *)0xF0003088u)

/** \brief  8C, Receive Data Register */
#define SENT_RDR3        /*lint --e(923)*/ (*(volatile Ifx_SENT_RDR *)0xF000308Cu)

/** \brief  A80, Receive Time Stamp Register */
#define SENT_RTS0        /*lint --e(923)*/ (*(volatile Ifx_SENT_RTS *)0xF0003A80u)

/** \brief  A84, Receive Time Stamp Register */
#define SENT_RTS1        /*lint --e(923)*/ (*(volatile Ifx_SENT_RTS *)0xF0003A84u)

/** \brief  A88, Receive Time Stamp Register */
#define SENT_RTS2        /*lint --e(923)*/ (*(volatile Ifx_SENT_RTS *)0xF0003A88u)

/** \brief  A8C, Receive Time Stamp Register */
#define SENT_RTS3        /*lint --e(923)*/ (*(volatile Ifx_SENT_RTS *)0xF0003A8Cu)

/** \brief  1C, Time Stamp Predivider Register */
#define SENT_TPD         /*lint --e(923)*/ (*(volatile Ifx_SENT_TPD *)0xF000301Cu)

/** \brief  18, Time Stamp Register */
#define SENT_TSR         /*lint --e(923)*/ (*(volatile Ifx_SENT_TSR *)0xF0003018u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXSENT_REG_H */
