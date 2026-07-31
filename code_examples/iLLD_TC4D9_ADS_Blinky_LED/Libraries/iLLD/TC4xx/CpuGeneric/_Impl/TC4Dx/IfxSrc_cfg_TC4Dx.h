/**
 * \file IfxSrc_cfg_TC4Dx.h
 * \brief SRC on-chip implementation data
 * \ingroup IfxLld_Src
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
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
 *
 * \defgroup IfxLld_Src SRC
 * \ingroup IfxLld
 * \defgroup IfxLld_Src_Impl Implementation
 * \ingroup IfxLld_Src
 * \defgroup IfxLld_Src_Std Standard Driver
 * \ingroup IfxLld_Src
 * \defgroup IfxLld_Src_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Src_Impl
 */

#ifndef IFXSRC_CFG_TC4DX_H
#define IFXSRC_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Offset for VEN bit in VCON0 register
 */
#define IFXSRC_VEN_OFF (1U)

/** \brief Number of ICUs
 */
#define IFXSRC_NUM_ICU (10U)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Src_Impl_Enumerations
 * \{ */
/** \brief Identifier of interrupt service provider, which handles the interrupt service request.
 */
typedef enum
{
    IfxSrc_Tos_cpu0 = 0,  /**< \brief CPU0 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_cpu1 = 1,  /**< \brief CPU1 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_cpu2 = 2,  /**< \brief CPU2 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_cpu3 = 3,  /**< \brief CPU3 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_cpu4 = 4,  /**< \brief CPU4 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_cpu5 = 5,  /**< \brief CPU5 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_csrm = 6,  /**< \brief CSRM interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_dma0 = 7,  /**< \brief DMA0 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_dma1 = 8,  /**< \brief DMA1 interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_gtm  = 9,  /**< \brief GTM interrupt service provider, which handles the interrupt service request. */
    IfxSrc_Tos_ppu  = 10  /**< \brief PPU interrupt service provider, which handles the interrupt service request. */
} IfxSrc_Tos;

/** \brief Identifier of Virtual machine interrupt service provider, which handles the interrupt service request.
 */
typedef enum
{
    IfxSrc_VmId_none = -1,  /**< \brief Not Selected */
    IfxSrc_VmId_0    = 0,   /**< \brief VM Index 0  */
    IfxSrc_VmId_1,          /**< \brief VM Index 1  */
    IfxSrc_VmId_2,          /**< \brief VM Index 2  */
    IfxSrc_VmId_3,          /**< \brief VM Index 3  */
    IfxSrc_VmId_4,          /**< \brief VM Index 4  */
    IfxSrc_VmId_5,          /**< \brief VM Index 5  */
    IfxSrc_VmId_6,          /**< \brief VM Index 6  */
    IfxSrc_VmId_7           /**< \brief VM Index 7  */
} IfxSrc_VmId;

/** \} */

/** \brief Identifier of interrupt control unit, which handles the interrupt service request.
 */
typedef enum
{
    IfxSrc_Int_group_0  = 0,   /**< \brief ICU0 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_1  = 1,   /**< \brief ICU1 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_2  = 2,   /**< \brief ICU2 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_3  = 3,   /**< \brief ICU3 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_4  = 4,   /**< \brief ICU4 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_5  = 5,   /**< \brief ICU5 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_6  = 6,   /**< \brief ICU6 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_7  = 7,   /**< \brief ICU7 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_8  = 8,   /**< \brief ICU8 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_9  = 9,   /**< \brief ICU9 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_10 = 10,  /**< \brief ICU10 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_11 = 11,  /**< \brief ICU11 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_12 = 12,  /**< \brief ICU12 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_13 = 13,  /**< \brief ICU13 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_14 = 14,  /**< \brief ICU14 interrupt control unit, which handles the interrupt service request. */
    IfxSrc_Int_group_15 = 15   /**< \brief ICU15 interrupt control unit, which handles the interrupt service request. */
} IfxSrc_Int_group;

#endif /* IFXSRC_CFG_TC4DX_H */
