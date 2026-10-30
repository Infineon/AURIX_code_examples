/**
 * \file IfxFsi_regdef.h
 * \brief
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: MC_ACE_A3G_HSI_NVM_FSI/V0.2.2.1.1
 * Specification: latest @ 2024-03-02 instance sheet @ MC_A3G_HWDDSOC_FUNCTIONAL_INSTANCE_SHEET/V13.2.1.1.0
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
 * \defgroup IfxSfr_Fsi_Registers Fsi Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Fsi_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Fsi_Registers
 * 
 * \defgroup IfxSfr_Fsi_Registers_union Register unions
 * \ingroup IfxSfr_Fsi_Registers
 * 
 * \defgroup IfxSfr_Fsi_Registers_struct Memory map
 * \ingroup IfxSfr_Fsi_Registers
 */
#ifndef IFXFSI_REGDEF_H
#define IFXFSI_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Fsi_Registers_Bitfields
 * \{  */
/** \brief Communication register 0 */
typedef struct _Ifx_FSI_COMM0_Bits
{
    __IO Ifx_UReg_8Bit COMM0:8;            /**< \brief [7:0] Communication register 0 (rwh) */
} Ifx_FSI_COMM0_Bits;

/** \brief Communication register 1 */
typedef struct _Ifx_FSI_COMM1_Bits
{
    __IO Ifx_UReg_8Bit COMM1:8;            /**< \brief [7:0] Communication register 1 (rwh) */
} Ifx_FSI_COMM1_Bits;

/** \brief Communication register 2 */
typedef struct _Ifx_FSI_COMM2_Bits
{
    __IO Ifx_UReg_8Bit COMM2:8;            /**< \brief [7:0] Communication register 2 (rwh) */
} Ifx_FSI_COMM2_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_fsi_Registers_union
 * \{   */
/** \brief Communication register 0   */
typedef union
{
    __IO Ifx_UReg_8Bit U;                  /**< \brief Unsigned access */
    __IO Ifx_SReg_8Bit I;                  /**< \brief Signed access */
    Ifx_FSI_COMM0_Bits B;                  /**< \brief Bitfield access */
} Ifx_FSI_COMM0;

/** \brief Communication register 1   */
typedef union
{
    __IO Ifx_UReg_8Bit U;                  /**< \brief Unsigned access */
    __IO Ifx_SReg_8Bit I;                  /**< \brief Signed access */
    Ifx_FSI_COMM1_Bits B;                  /**< \brief Bitfield access */
} Ifx_FSI_COMM1;

/** \brief Communication register 2   */
typedef union
{
    __IO Ifx_UReg_8Bit U;                  /**< \brief Unsigned access */
    __IO Ifx_SReg_8Bit I;                  /**< \brief Signed access */
    Ifx_FSI_COMM2_Bits B;                  /**< \brief Bitfield access */
} Ifx_FSI_COMM2;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_Fsi_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief FSI object */
typedef volatile struct _Ifx_FSI
{
       __IO Ifx_FSI_COMM0                       COMM0;                  /**< \brief 0, Communication register 0*/
       __IO Ifx_FSI_COMM1                       COMM1;                  /**< \brief 1, Communication register 1*/
       __IO Ifx_FSI_COMM2                       COMM2;                  /**< \brief 2, Communication register 2*/
       __I  Ifx_UReg_8Bit                       reserved_3[253];        /**< \brief 3, \internal Reserved */
} Ifx_FSI;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXFSI_REGDEF_H */
