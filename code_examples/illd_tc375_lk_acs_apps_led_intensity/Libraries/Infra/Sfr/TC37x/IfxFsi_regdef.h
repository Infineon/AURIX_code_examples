/**
 * \file IfxFsi_regdef.h
 * \brief
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC37xPD_UM_V2.0.0.R0
 * Specification: TC3xx User Manual V2.0.0
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
/** \brief Communication Register 1 */
typedef struct _Ifx_FSI_COMM_1_Bits
{
    Ifx_UReg_8Bit COMM1:8;            /**< \brief [7:0] FSI Communication 1 - COMM1 (rw) */
} Ifx_FSI_COMM_1_Bits;

/** \brief Communication Register 2 */
typedef struct _Ifx_FSI_COMM_2_Bits
{
    Ifx_UReg_8Bit COMM2:8;            /**< \brief [7:0] FSI Communication 2 - COMM2 (rw) */
} Ifx_FSI_COMM_2_Bits;

/** \brief HSM Communication Register 1 */
typedef struct _Ifx_FSI_HSMCOMM_1_Bits
{
    Ifx_UReg_8Bit HSMCOMM1:8;         /**< \brief [7:0] HSM FSI Communication 1 - HSMCOMM1 (rw) */
} Ifx_FSI_HSMCOMM_1_Bits;

/** \brief HSM Communication Register 2 */
typedef struct _Ifx_FSI_HSMCOMM_2_Bits
{
    Ifx_UReg_8Bit HSMCOMM2:8;         /**< \brief [7:0] HSM FSI Communication 2 - HSMCOMM2 (rw) */
} Ifx_FSI_HSMCOMM_2_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_fsi_Registers_union
 * \{   */
/** \brief Communication Register 1   */
typedef union
{
    Ifx_UReg_8Bit U;                  /**< \brief Unsigned access */
    Ifx_SReg_8Bit I;                  /**< \brief Signed access */
    Ifx_FSI_COMM_1_Bits B;            /**< \brief Bitfield access */
} Ifx_FSI_COMM_1;

/** \brief Communication Register 2   */
typedef union
{
    Ifx_UReg_8Bit U;                  /**< \brief Unsigned access */
    Ifx_SReg_8Bit I;                  /**< \brief Signed access */
    Ifx_FSI_COMM_2_Bits B;            /**< \brief Bitfield access */
} Ifx_FSI_COMM_2;

/** \brief HSM Communication Register 1   */
typedef union
{
    Ifx_UReg_8Bit U;                  /**< \brief Unsigned access */
    Ifx_SReg_8Bit I;                  /**< \brief Signed access */
    Ifx_FSI_HSMCOMM_1_Bits B;         /**< \brief Bitfield access */
} Ifx_FSI_HSMCOMM_1;

/** \brief HSM Communication Register 2   */
typedef union
{
    Ifx_UReg_8Bit U;                  /**< \brief Unsigned access */
    Ifx_SReg_8Bit I;                  /**< \brief Signed access */
    Ifx_FSI_HSMCOMM_2_Bits B;         /**< \brief Bitfield access */
} Ifx_FSI_HSMCOMM_2;

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
       Ifx_UReg_8Bit                       reserved_0[4];          /**< \brief 0, \internal Reserved */
       Ifx_FSI_COMM_1                      COMM_1;                 /**< \brief 4, Communication Register 1*/
       Ifx_FSI_COMM_2                      COMM_2;                 /**< \brief 5, Communication Register 2*/
       Ifx_FSI_HSMCOMM_1                   HSMCOMM_1;              /**< \brief 6, HSM Communication Register 1*/
       Ifx_FSI_HSMCOMM_2                   HSMCOMM_2;              /**< \brief 7, HSM Communication Register 2*/
       Ifx_UReg_8Bit                       reserved_8[248];        /**< \brief 8, \internal Reserved */
} Ifx_FSI;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXFSI_REGDEF_H */
