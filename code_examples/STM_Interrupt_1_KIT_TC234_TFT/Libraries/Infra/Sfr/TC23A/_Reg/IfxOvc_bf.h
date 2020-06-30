/**
 * \file IfxOvc_bf.h
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
 * \defgroup IfxLld_Ovc_BitfieldsMask Bitfields mask and offset
 * \ingroup IfxLld_Ovc
 *
 */
#ifndef IFXOVC_BF_H
#define IFXOVC_BF_H                 1
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Ovc_BitfieldsMask
 * \{  */

/** \brief  Length for Ifx_OVC_BLK_OMASK_Bits.OMASK */
#define IFX_OVC_BLK_OMASK_OMASK_LEN (12u)

/** \brief  Mask for Ifx_OVC_BLK_OMASK_Bits.OMASK */
#define IFX_OVC_BLK_OMASK_OMASK_MSK (0xfffu)

/** \brief  Offset for Ifx_OVC_BLK_OMASK_Bits.OMASK */
#define IFX_OVC_BLK_OMASK_OMASK_OFF (5u)

/** \brief  Length for Ifx_OVC_BLK_OMASK_Bits.ONE */
#define IFX_OVC_BLK_OMASK_ONE_LEN   (11u)

/** \brief  Mask for Ifx_OVC_BLK_OMASK_Bits.ONE */
#define IFX_OVC_BLK_OMASK_ONE_MSK   (0x7ffu)

/** \brief  Offset for Ifx_OVC_BLK_OMASK_Bits.ONE */
#define IFX_OVC_BLK_OMASK_ONE_OFF   (17u)

/** \brief  Length for Ifx_OVC_BLK_OTAR_Bits.TBASE */
#define IFX_OVC_BLK_OTAR_TBASE_LEN  (23u)

/** \brief  Mask for Ifx_OVC_BLK_OTAR_Bits.TBASE */
#define IFX_OVC_BLK_OTAR_TBASE_MSK  (0x7fffffu)

/** \brief  Offset for Ifx_OVC_BLK_OTAR_Bits.TBASE */
#define IFX_OVC_BLK_OTAR_TBASE_OFF  (5u)

/** \brief  Length for Ifx_OVC_BLK_RABR_Bits.OBASE */
#define IFX_OVC_BLK_RABR_OBASE_LEN  (17u)

/** \brief  Mask for Ifx_OVC_BLK_RABR_Bits.OBASE */
#define IFX_OVC_BLK_RABR_OBASE_MSK  (0x1ffffu)

/** \brief  Offset for Ifx_OVC_BLK_RABR_Bits.OBASE */
#define IFX_OVC_BLK_RABR_OBASE_OFF  (5u)

/** \brief  Length for Ifx_OVC_BLK_RABR_Bits.OMEM */
#define IFX_OVC_BLK_RABR_OMEM_LEN   (3u)

/** \brief  Mask for Ifx_OVC_BLK_RABR_Bits.OMEM */
#define IFX_OVC_BLK_RABR_OMEM_MSK   (0x7u)

/** \brief  Offset for Ifx_OVC_BLK_RABR_Bits.OMEM */
#define IFX_OVC_BLK_RABR_OMEM_OFF   (24u)

/** \brief  Length for Ifx_OVC_BLK_RABR_Bits.OVEN */
#define IFX_OVC_BLK_RABR_OVEN_LEN   (1u)

/** \brief  Mask for Ifx_OVC_BLK_RABR_Bits.OVEN */
#define IFX_OVC_BLK_RABR_OVEN_MSK   (0x1u)

/** \brief  Offset for Ifx_OVC_BLK_RABR_Bits.OVEN */
#define IFX_OVC_BLK_RABR_OVEN_OFF   (31u)

/** \brief  Length for Ifx_OVC_OSEL_Bits.SHOVEN0 */
#define IFX_OVC_OSEL_SHOVEN0_LEN    (1u)

/** \brief  Mask for Ifx_OVC_OSEL_Bits.SHOVEN0 */
#define IFX_OVC_OSEL_SHOVEN0_MSK    (0x1u)

/** \brief  Offset for Ifx_OVC_OSEL_Bits.SHOVEN0 */
#define IFX_OVC_OSEL_SHOVEN0_OFF    (0u)

/** \brief  Length for Ifx_OVC_OSEL_Bits.SHOVEN1 */
#define IFX_OVC_OSEL_SHOVEN1_LEN    (1u)

/** \brief  Mask for Ifx_OVC_OSEL_Bits.SHOVEN1 */
#define IFX_OVC_OSEL_SHOVEN1_MSK    (0x1u)

/** \brief  Offset for Ifx_OVC_OSEL_Bits.SHOVEN1 */
#define IFX_OVC_OSEL_SHOVEN1_OFF    (1u)

/** \brief  Length for Ifx_OVC_OSEL_Bits.SHOVEN2 */
#define IFX_OVC_OSEL_SHOVEN2_LEN    (1u)

/** \brief  Mask for Ifx_OVC_OSEL_Bits.SHOVEN2 */
#define IFX_OVC_OSEL_SHOVEN2_MSK    (0x1u)

/** \brief  Offset for Ifx_OVC_OSEL_Bits.SHOVEN2 */
#define IFX_OVC_OSEL_SHOVEN2_OFF    (2u)

/** \brief  Length for Ifx_OVC_OSEL_Bits.SHOVEN3 */
#define IFX_OVC_OSEL_SHOVEN3_LEN    (1u)

/** \brief  Mask for Ifx_OVC_OSEL_Bits.SHOVEN3 */
#define IFX_OVC_OSEL_SHOVEN3_MSK    (0x1u)

/** \brief  Offset for Ifx_OVC_OSEL_Bits.SHOVEN3 */
#define IFX_OVC_OSEL_SHOVEN3_OFF    (3u)

/** \brief  Length for Ifx_OVC_OSEL_Bits.SHOVEN4 */
#define IFX_OVC_OSEL_SHOVEN4_LEN    (1u)

/** \brief  Mask for Ifx_OVC_OSEL_Bits.SHOVEN4 */
#define IFX_OVC_OSEL_SHOVEN4_MSK    (0x1u)

/** \brief  Offset for Ifx_OVC_OSEL_Bits.SHOVEN4 */
#define IFX_OVC_OSEL_SHOVEN4_OFF    (4u)

/** \brief  Length for Ifx_OVC_OSEL_Bits.SHOVEN5 */
#define IFX_OVC_OSEL_SHOVEN5_LEN    (1u)

/** \brief  Mask for Ifx_OVC_OSEL_Bits.SHOVEN5 */
#define IFX_OVC_OSEL_SHOVEN5_MSK    (0x1u)

/** \brief  Offset for Ifx_OVC_OSEL_Bits.SHOVEN5 */
#define IFX_OVC_OSEL_SHOVEN5_OFF    (5u)

/** \brief  Length for Ifx_OVC_OSEL_Bits.SHOVEN6 */
#define IFX_OVC_OSEL_SHOVEN6_LEN    (1u)

/** \brief  Mask for Ifx_OVC_OSEL_Bits.SHOVEN6 */
#define IFX_OVC_OSEL_SHOVEN6_MSK    (0x1u)

/** \brief  Offset for Ifx_OVC_OSEL_Bits.SHOVEN6 */
#define IFX_OVC_OSEL_SHOVEN6_OFF    (6u)

/** \brief  Length for Ifx_OVC_OSEL_Bits.SHOVEN7 */
#define IFX_OVC_OSEL_SHOVEN7_LEN    (1u)

/** \brief  Mask for Ifx_OVC_OSEL_Bits.SHOVEN7 */
#define IFX_OVC_OSEL_SHOVEN7_MSK    (0x1u)

/** \brief  Offset for Ifx_OVC_OSEL_Bits.SHOVEN7 */
#define IFX_OVC_OSEL_SHOVEN7_OFF    (7u)
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXOVC_BF_H */
