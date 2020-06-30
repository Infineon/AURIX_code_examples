/**
 * \file IfxLmu_reg.h
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
 * \defgroup IfxLld_Lmu_Cfg Lmu address
 * \ingroup IfxLld_Lmu
 *
 * \defgroup IfxLld_Lmu_Cfg_BaseAddress Base address
 * \ingroup IfxLld_Lmu_Cfg
 *
 * \defgroup IfxLld_Lmu_Cfg_Lmu 2-LMU
 * \ingroup IfxLld_Lmu_Cfg
 *
 */
#ifndef IFXLMU_REG_H
#define IFXLMU_REG_H 1
/******************************************************************************/
#include "IfxLmu_regdef.h"
/******************************************************************************/
/** \addtogroup IfxLld_Lmu_Cfg_BaseAddress
 * \{  */

/** \brief  LMU object */
#define MODULE_LMU /*lint --e(923)*/ (*(Ifx_LMU *)0xF8700800u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Lmu_Cfg_Lmu
 * \{  */

/** \brief  10, LMU Access Enable Register 0 */
#define LMU_ACCEN0     /*lint --e(923)*/ (*(volatile Ifx_LMU_ACCEN0 *)0xF8700810u)

/** \brief  14, LMU Access Enable Register 1 */
#define LMU_ACCEN1     /*lint --e(923)*/ (*(volatile Ifx_LMU_ACCEN1 *)0xF8700814u)

/** \brief  30, LMU Buffer Control Register */
#define LMU_BUFCON0    /*lint --e(923)*/ (*(volatile Ifx_LMU_BUFCON *)0xF8700830u)

/** \brief  34, LMU Buffer Control Register */
#define LMU_BUFCON1    /*lint --e(923)*/ (*(volatile Ifx_LMU_BUFCON *)0xF8700834u)

/** \brief  38, LMU Buffer Control Register */
#define LMU_BUFCON2    /*lint --e(923)*/ (*(volatile Ifx_LMU_BUFCON *)0xF8700838u)

/** \brief  0, LMU Clock Control Register */
#define LMU_CLC        /*lint --e(923)*/ (*(volatile Ifx_LMU_CLC *)0xF8700800u)

/** \brief  20, LMU Memory Control Register */
#define LMU_MEMCON     /*lint --e(923)*/ (*(volatile Ifx_LMU_MEMCON *)0xF8700820u)

/** \brief  8, LMU Module ID Register */
#define LMU_MODID      /*lint --e(923)*/ (*(volatile Ifx_LMU_MODID *)0xF8700808u)

/** \brief  58, LMU Region Access Enable Register 0 */
#define LMU_RGNACCENA0 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENA0 *)0xF8700858u)

/** \brief  68, LMU Region Access Enable Register 0 */
#define LMU_RGNACCENA1 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENA1 *)0xF8700868u)

/** \brief  78, LMU Region Access Enable Register 0 */
#define LMU_RGNACCENA2 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENA2 *)0xF8700878u)

/** \brief  88, LMU Region Access Enable Register 0 */
#define LMU_RGNACCENA3 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENA3 *)0xF8700888u)

/** \brief  98, LMU Region Access Enable Register 0 */
#define LMU_RGNACCENA4 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENA4 *)0xF8700898u)

/** \brief  A8, LMU Region Access Enable Register 0 */
#define LMU_RGNACCENA5 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENA5 *)0xF87008A8u)

/** \brief  B8, LMU Region Access Enable Register 0 */
#define LMU_RGNACCENA6 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENA6 *)0xF87008B8u)

/** \brief  C8, LMU Region Access Enable Register 0 */
#define LMU_RGNACCENA7 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENA7 *)0xF87008C8u)

/** \brief  5C, LMU Region Access Enable Register 1 */
#define LMU_RGNACCENB0 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENB0 *)0xF870085Cu)

/** \brief  6C, LMU Region Access Enable Register 1 */
#define LMU_RGNACCENB1 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENB1 *)0xF870086Cu)

/** \brief  7C, LMU Region Access Enable Register 1 */
#define LMU_RGNACCENB2 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENB2 *)0xF870087Cu)

/** \brief  8C, LMU Region Access Enable Register 1 */
#define LMU_RGNACCENB3 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENB3 *)0xF870088Cu)

/** \brief  9C, LMU Region Access Enable Register 1 */
#define LMU_RGNACCENB4 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENB4 *)0xF870089Cu)

/** \brief  AC, LMU Region Access Enable Register 1 */
#define LMU_RGNACCENB5 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENB5 *)0xF87008ACu)

/** \brief  BC, LMU Region Access Enable Register 1 */
#define LMU_RGNACCENB6 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENB6 *)0xF87008BCu)

/** \brief  CC, LMU Region Access Enable Register 1 */
#define LMU_RGNACCENB7 /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNACCENB7 *)0xF87008CCu)

/** \brief  50, LMU Region Lower Address Register */
#define LMU_RGNLA0     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNLA0 *)0xF8700850u)

/** \brief  60, LMU Region Lower Address Register */
#define LMU_RGNLA1     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNLA1 *)0xF8700860u)

/** \brief  70, LMU Region Lower Address Register */
#define LMU_RGNLA2     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNLA2 *)0xF8700870u)

/** \brief  80, LMU Region Lower Address Register */
#define LMU_RGNLA3     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNLA3 *)0xF8700880u)

/** \brief  90, LMU Region Lower Address Register */
#define LMU_RGNLA4     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNLA4 *)0xF8700890u)

/** \brief  A0, LMU Region Lower Address Register */
#define LMU_RGNLA5     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNLA5 *)0xF87008A0u)

/** \brief  B0, LMU Region Lower Address Register */
#define LMU_RGNLA6     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNLA6 *)0xF87008B0u)

/** \brief  C0, LMU Region Lower Address Register */
#define LMU_RGNLA7     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNLA7 *)0xF87008C0u)

/** \brief  54, LMU Region Upper Address Register */
#define LMU_RGNUA0     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNUA0 *)0xF8700854u)

/** \brief  64, LMU Region Upper Address Register */
#define LMU_RGNUA1     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNUA1 *)0xF8700864u)

/** \brief  74, LMU Region Upper Address Register */
#define LMU_RGNUA2     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNUA2 *)0xF8700874u)

/** \brief  84, LMU Region Upper Address Register */
#define LMU_RGNUA3     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNUA3 *)0xF8700884u)

/** \brief  94, LMU Region Upper Address Register */
#define LMU_RGNUA4     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNUA4 *)0xF8700894u)

/** \brief  A4, LMU Region Upper Address Register */
#define LMU_RGNUA5     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNUA5 *)0xF87008A4u)

/** \brief  B4, LMU Region Upper Address Register */
#define LMU_RGNUA6     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNUA6 *)0xF87008B4u)

/** \brief  C4, LMU Region Upper Address Register */
#define LMU_RGNUA7     /*lint --e(923)*/ (*(volatile Ifx_LMU_RGNUA7 *)0xF87008C4u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXLMU_REG_H */
