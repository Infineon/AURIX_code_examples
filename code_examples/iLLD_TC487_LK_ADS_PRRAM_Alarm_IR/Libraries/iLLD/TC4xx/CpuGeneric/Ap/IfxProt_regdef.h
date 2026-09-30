/**
 * \file IfxProt_regdef.h
 * \brief
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * MAY BE CHANGED BY USER [yes/no]: Yes
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
 * \defgroup IfxSfr_Prot_Registers Prot Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Prot_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Prot_Registers
 * 
 * \defgroup IfxSfr_Prot_Registers_union Register unions
 * \ingroup IfxSfr_Prot_Registers
 * 
 * \defgroup IfxSfr_Prot_Registers_struct Memory map
 * \ingroup IfxSfr_Prot_Registers
 */
#ifndef IFXPROT_REGDEF_H
#define IFXPROT_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/


/** \addtogroup IfxSfr_Prot_Registers_Bitfields
 * \{  */
/** \brief Resource Protection Register */
typedef struct _Ifx_PROT_PROT_Bits
{
    Ifx_UReg_32Bit STATE:3;           /**< \brief [2:0] Resource protection state (rwh) */
    Ifx_UReg_32Bit SWEN:1;            /**< \brief [3:3] State write enable (w) */
    Ifx_UReg_32Bit reserved_4:4;     /**< \brief [7:4] \internal Reserved */
    Ifx_UReg_32Bit SEL:8;            /**< \brief [8:15] Protection region select */
    Ifx_UReg_32Bit VM:3;              /**< \brief [18:16] Virtual Machine definition for PROT owner (rw) */
    Ifx_UReg_32Bit VMEN:1;            /**< \brief [19:19] Virtual Machine definition Enable for PROT owner (rw) */
    Ifx_UReg_32Bit PRS:3;             /**< \brief [22:20] Protection Set definition for PROT owner (rw) */
    Ifx_UReg_32Bit PRSEN:1;           /**< \brief [23:23] Protection Set definition Enable for PROT owner (rw) */
    Ifx_UReg_32Bit TAGID:6;           /**< \brief [29:24] TAG ID definition for PROT owner (rw) */
    Ifx_UReg_32Bit ODEF:1;            /**< \brief [30:30] Enable for PROT owner definition (rw) */
    Ifx_UReg_32Bit OWEN:1;            /**< \brief [31:31] Owner write enable (w) */
} Ifx_PROT_PROT_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_prot_Registers_union
 * \{   */
/** \brief Resource Protection Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_PROT_PROT_Bits B;             /**< \brief Bitfield access */
} Ifx_PROT_PROT;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_Prot_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief PROT object */
typedef volatile struct _Ifx_PROT
{
       Ifx_PROT_PROT                       PROT;                   /**< \brief 0, Resource Protection Register*/
       Ifx_UReg_8Bit                       reserved_4[252];        /**< \brief 4, \internal Reserved */
} Ifx_PROT;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/
/******************************************************************************/

#endif /* IFXPROT_REGDEF_H */
