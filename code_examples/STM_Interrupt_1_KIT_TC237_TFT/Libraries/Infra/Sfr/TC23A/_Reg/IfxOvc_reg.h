/**
 * \file IfxOvc_reg.h
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
 * \defgroup IfxLld_Ovc_Cfg Ovc address
 * \ingroup IfxLld_Ovc
 *
 * \defgroup IfxLld_Ovc_Cfg_BaseAddress Base address
 * \ingroup IfxLld_Ovc_Cfg
 *
 * \defgroup IfxLld_Ovc_Cfg_Ovc0 2-OVC0
 * \ingroup IfxLld_Ovc_Cfg
 *
 */
#ifndef IFXOVC_REG_H
#define IFXOVC_REG_H 1
/******************************************************************************/
#include "IfxOvc_regdef.h"
/******************************************************************************/
/** \addtogroup IfxLld_Ovc_Cfg_BaseAddress
 * \{  */

/** \brief  OVC object */
#define MODULE_OVC0 /*lint --e(923)*/ (*(Ifx_OVC *)0xF880FB00u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Ovc_Cfg_Ovc0
 * \{  */

/** \brief  18, Overlay Mask Register */
#define OVC0_BLK0_OMASK /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OMASK *)0xF880FB18u)

/** Alias (User Manual Name) for OVC0_BLK0_OMASK.
 * To use register names with standard convension, please use OVC0_BLK0_OMASK.
 */
#define OVC0_OMASK0     (OVC0_BLK0_OMASK)

/** \brief  14, Overlay Target Address Register */
#define OVC0_BLK0_OTAR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OTAR *)0xF880FB14u)

/** Alias (User Manual Name) for OVC0_BLK0_OTAR.
 * To use register names with standard convension, please use OVC0_BLK0_OTAR.
 */
#define OVC0_OTAR0      (OVC0_BLK0_OTAR)

/** \brief  10, Redirected Address Base Register */
#define OVC0_BLK0_RABR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_RABR *)0xF880FB10u)

/** Alias (User Manual Name) for OVC0_BLK0_RABR.
 * To use register names with standard convension, please use OVC0_BLK0_RABR.
 */
#define OVC0_RABR0      (OVC0_BLK0_RABR)

/** \brief  24, Overlay Mask Register */
#define OVC0_BLK1_OMASK /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OMASK *)0xF880FB24u)

/** Alias (User Manual Name) for OVC0_BLK1_OMASK.
 * To use register names with standard convension, please use OVC0_BLK1_OMASK.
 */
#define OVC0_OMASK1     (OVC0_BLK1_OMASK)

/** \brief  20, Overlay Target Address Register */
#define OVC0_BLK1_OTAR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OTAR *)0xF880FB20u)

/** Alias (User Manual Name) for OVC0_BLK1_OTAR.
 * To use register names with standard convension, please use OVC0_BLK1_OTAR.
 */
#define OVC0_OTAR1      (OVC0_BLK1_OTAR)

/** \brief  1C, Redirected Address Base Register */
#define OVC0_BLK1_RABR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_RABR *)0xF880FB1Cu)

/** Alias (User Manual Name) for OVC0_BLK1_RABR.
 * To use register names with standard convension, please use OVC0_BLK1_RABR.
 */
#define OVC0_RABR1      (OVC0_BLK1_RABR)

/** \brief  30, Overlay Mask Register */
#define OVC0_BLK2_OMASK /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OMASK *)0xF880FB30u)

/** Alias (User Manual Name) for OVC0_BLK2_OMASK.
 * To use register names with standard convension, please use OVC0_BLK2_OMASK.
 */
#define OVC0_OMASK2     (OVC0_BLK2_OMASK)

/** \brief  2C, Overlay Target Address Register */
#define OVC0_BLK2_OTAR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OTAR *)0xF880FB2Cu)

/** Alias (User Manual Name) for OVC0_BLK2_OTAR.
 * To use register names with standard convension, please use OVC0_BLK2_OTAR.
 */
#define OVC0_OTAR2      (OVC0_BLK2_OTAR)

/** \brief  28, Redirected Address Base Register */
#define OVC0_BLK2_RABR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_RABR *)0xF880FB28u)

/** Alias (User Manual Name) for OVC0_BLK2_RABR.
 * To use register names with standard convension, please use OVC0_BLK2_RABR.
 */
#define OVC0_RABR2      (OVC0_BLK2_RABR)

/** \brief  3C, Overlay Mask Register */
#define OVC0_BLK3_OMASK /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OMASK *)0xF880FB3Cu)

/** Alias (User Manual Name) for OVC0_BLK3_OMASK.
 * To use register names with standard convension, please use OVC0_BLK3_OMASK.
 */
#define OVC0_OMASK3     (OVC0_BLK3_OMASK)

/** \brief  38, Overlay Target Address Register */
#define OVC0_BLK3_OTAR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OTAR *)0xF880FB38u)

/** Alias (User Manual Name) for OVC0_BLK3_OTAR.
 * To use register names with standard convension, please use OVC0_BLK3_OTAR.
 */
#define OVC0_OTAR3      (OVC0_BLK3_OTAR)

/** \brief  34, Redirected Address Base Register */
#define OVC0_BLK3_RABR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_RABR *)0xF880FB34u)

/** Alias (User Manual Name) for OVC0_BLK3_RABR.
 * To use register names with standard convension, please use OVC0_BLK3_RABR.
 */
#define OVC0_RABR3      (OVC0_BLK3_RABR)

/** \brief  48, Overlay Mask Register */
#define OVC0_BLK4_OMASK /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OMASK *)0xF880FB48u)

/** Alias (User Manual Name) for OVC0_BLK4_OMASK.
 * To use register names with standard convension, please use OVC0_BLK4_OMASK.
 */
#define OVC0_OMASK4     (OVC0_BLK4_OMASK)

/** \brief  44, Overlay Target Address Register */
#define OVC0_BLK4_OTAR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OTAR *)0xF880FB44u)

/** Alias (User Manual Name) for OVC0_BLK4_OTAR.
 * To use register names with standard convension, please use OVC0_BLK4_OTAR.
 */
#define OVC0_OTAR4      (OVC0_BLK4_OTAR)

/** \brief  40, Redirected Address Base Register */
#define OVC0_BLK4_RABR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_RABR *)0xF880FB40u)

/** Alias (User Manual Name) for OVC0_BLK4_RABR.
 * To use register names with standard convension, please use OVC0_BLK4_RABR.
 */
#define OVC0_RABR4      (OVC0_BLK4_RABR)

/** \brief  54, Overlay Mask Register */
#define OVC0_BLK5_OMASK /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OMASK *)0xF880FB54u)

/** Alias (User Manual Name) for OVC0_BLK5_OMASK.
 * To use register names with standard convension, please use OVC0_BLK5_OMASK.
 */
#define OVC0_OMASK5     (OVC0_BLK5_OMASK)

/** \brief  50, Overlay Target Address Register */
#define OVC0_BLK5_OTAR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OTAR *)0xF880FB50u)

/** Alias (User Manual Name) for OVC0_BLK5_OTAR.
 * To use register names with standard convension, please use OVC0_BLK5_OTAR.
 */
#define OVC0_OTAR5      (OVC0_BLK5_OTAR)

/** \brief  4C, Redirected Address Base Register */
#define OVC0_BLK5_RABR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_RABR *)0xF880FB4Cu)

/** Alias (User Manual Name) for OVC0_BLK5_RABR.
 * To use register names with standard convension, please use OVC0_BLK5_RABR.
 */
#define OVC0_RABR5      (OVC0_BLK5_RABR)

/** \brief  60, Overlay Mask Register */
#define OVC0_BLK6_OMASK /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OMASK *)0xF880FB60u)

/** Alias (User Manual Name) for OVC0_BLK6_OMASK.
 * To use register names with standard convension, please use OVC0_BLK6_OMASK.
 */
#define OVC0_OMASK6     (OVC0_BLK6_OMASK)

/** \brief  5C, Overlay Target Address Register */
#define OVC0_BLK6_OTAR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OTAR *)0xF880FB5Cu)

/** Alias (User Manual Name) for OVC0_BLK6_OTAR.
 * To use register names with standard convension, please use OVC0_BLK6_OTAR.
 */
#define OVC0_OTAR6      (OVC0_BLK6_OTAR)

/** \brief  58, Redirected Address Base Register */
#define OVC0_BLK6_RABR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_RABR *)0xF880FB58u)

/** Alias (User Manual Name) for OVC0_BLK6_RABR.
 * To use register names with standard convension, please use OVC0_BLK6_RABR.
 */
#define OVC0_RABR6      (OVC0_BLK6_RABR)

/** \brief  6C, Overlay Mask Register */
#define OVC0_BLK7_OMASK /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OMASK *)0xF880FB6Cu)

/** Alias (User Manual Name) for OVC0_BLK7_OMASK.
 * To use register names with standard convension, please use OVC0_BLK7_OMASK.
 */
#define OVC0_OMASK7     (OVC0_BLK7_OMASK)

/** \brief  68, Overlay Target Address Register */
#define OVC0_BLK7_OTAR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_OTAR *)0xF880FB68u)

/** Alias (User Manual Name) for OVC0_BLK7_OTAR.
 * To use register names with standard convension, please use OVC0_BLK7_OTAR.
 */
#define OVC0_OTAR7      (OVC0_BLK7_OTAR)

/** \brief  64, Redirected Address Base Register */
#define OVC0_BLK7_RABR  /*lint --e(923)*/ (*(volatile Ifx_OVC_BLK_RABR *)0xF880FB64u)

/** Alias (User Manual Name) for OVC0_BLK7_RABR.
 * To use register names with standard convension, please use OVC0_BLK7_RABR.
 */
#define OVC0_RABR7      (OVC0_BLK7_RABR)

/** \brief  0, Overlay Range Select Register */
#define OVC0_OSEL       /*lint --e(923)*/ (*(volatile Ifx_OVC_OSEL *)0xF880FB00u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXOVC_REG_H */
