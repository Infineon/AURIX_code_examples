/**
 * \file IfxOvc_regdef.h
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
 * \defgroup IfxLld_Ovc Ovc
 * \ingroup IfxLld
 *
 * \defgroup IfxLld_Ovc_Bitfields Bitfields
 * \ingroup IfxLld_Ovc
 *
 * \defgroup IfxLld_Ovc_union Union
 * \ingroup IfxLld_Ovc
 *
 * \defgroup IfxLld_Ovc_struct Struct
 * \ingroup IfxLld_Ovc
 *
 */
#ifndef IFXOVC_REGDEF_H
#define IFXOVC_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Ovc_Bitfields
 * \{  */

/** \brief  Overlay Mask Register */
typedef struct _Ifx_OVC_BLK_OMASK_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OMASK : 12;              /**< \brief [16:5] Overlay Address Mask (rw) */
    Ifx_Strict_32Bit ONE : 11;                /**< \brief [27:17] Fixed "1" Values (r) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_OVC_BLK_OMASK_Bits;

/** \brief  Overlay Target Address Register */
typedef struct _Ifx_OVC_BLK_OTAR_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TBASE : 23;              /**< \brief [27:5] Target Base (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_OVC_BLK_OTAR_Bits;

/** \brief  Redirected Address Base Register */
typedef struct _Ifx_OVC_BLK_RABR_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OBASE : 17;              /**< \brief [21:5] Overlay Block Base Address (rw) */
    Ifx_Strict_32Bit reserved_22 : 2;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OMEM : 3;                /**< \brief [26:24] Overlay Memory Select (rw) */
    Ifx_Strict_32Bit reserved_27 : 4;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit OVEN : 1;                /**< \brief [31:31] Overlay Enabled (rwh) */
} Ifx_OVC_BLK_RABR_Bits;

/** \brief  Overlay Range Select Register */
typedef struct _Ifx_OVC_OSEL_Bits
{
    Ifx_Strict_32Bit SHOVEN0 : 1;             /**< \brief [0:0] Shadow Overlay Enable 0 (rw) */
    Ifx_Strict_32Bit SHOVEN1 : 1;             /**< \brief [1:1] Shadow Overlay Enable 1 (rw) */
    Ifx_Strict_32Bit SHOVEN2 : 1;             /**< \brief [2:2] Shadow Overlay Enable 2 (rw) */
    Ifx_Strict_32Bit SHOVEN3 : 1;             /**< \brief [3:3] Shadow Overlay Enable 3 (rw) */
    Ifx_Strict_32Bit SHOVEN4 : 1;             /**< \brief [4:4] Shadow Overlay Enable 4 (rw) */
    Ifx_Strict_32Bit SHOVEN5 : 1;             /**< \brief [5:5] Shadow Overlay Enable 5 (rw) */
    Ifx_Strict_32Bit SHOVEN6 : 1;             /**< \brief [6:6] Shadow Overlay Enable 6 (rw) */
    Ifx_Strict_32Bit SHOVEN7 : 1;             /**< \brief [7:7] Shadow Overlay Enable 7 (rw) */
    Ifx_Strict_32Bit reserved_8 : 24;         /**< \brief \internal Reserved */
} Ifx_OVC_OSEL_Bits;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Ovc_union
 * \{  */

/** \brief  Overlay Mask Register */
typedef union
{
    unsigned int           U;               /**< \brief Unsigned access */
    signed int             I;               /**< \brief Signed access */
    Ifx_OVC_BLK_OMASK_Bits B;               /**< \brief Bitfield access */
} Ifx_OVC_BLK_OMASK;

/** \brief  Overlay Target Address Register */
typedef union
{
    unsigned int          U;                /**< \brief Unsigned access */
    signed int            I;                /**< \brief Signed access */
    Ifx_OVC_BLK_OTAR_Bits B;                /**< \brief Bitfield access */
} Ifx_OVC_BLK_OTAR;

/** \brief  Redirected Address Base Register */
typedef union
{
    unsigned int          U;                /**< \brief Unsigned access */
    signed int            I;                /**< \brief Signed access */
    Ifx_OVC_BLK_RABR_Bits B;                /**< \brief Bitfield access */
} Ifx_OVC_BLK_RABR;

/** \brief  Overlay Range Select Register */
typedef union
{
    unsigned int      U;                    /**< \brief Unsigned access */
    signed int        I;                    /**< \brief Signed access */
    Ifx_OVC_OSEL_Bits B;                    /**< \brief Bitfield access */
} Ifx_OVC_OSEL;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Ovc_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */

/** \brief  Overlay blocks objects */
typedef volatile struct _Ifx_OVC_BLK
{
    Ifx_OVC_BLK_RABR  RABR;                 /**< \brief 0, Redirected Address Base Register */
    Ifx_OVC_BLK_OTAR  OTAR;                 /**< \brief 4, Overlay Target Address Register */
    Ifx_OVC_BLK_OMASK OMASK;                /**< \brief 8, Overlay Mask Register */
} Ifx_OVC_BLK;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Ovc_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief  OVC object */
typedef volatile struct _Ifx_OVC
{
    Ifx_OVC_OSEL  OSEL;                     /**< \brief 0, Overlay Range Select Register */
    unsigned char reserved_4[12];           /**< \brief 4, \internal Reserved */
    Ifx_OVC_BLK   BLK[8];                   /**< \brief 10, Overlay blocks objects */
    unsigned char reserved_70[400];         /**< \brief 70, \internal Reserved */
} Ifx_OVC;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXOVC_REGDEF_H */
