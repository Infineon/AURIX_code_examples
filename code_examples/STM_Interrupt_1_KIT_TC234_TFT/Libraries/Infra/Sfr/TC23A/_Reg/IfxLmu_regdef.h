/**
 * \file IfxLmu_regdef.h
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
 * \defgroup IfxLld_Lmu Lmu
 * \ingroup IfxLld
 *
 * \defgroup IfxLld_Lmu_Bitfields Bitfields
 * \ingroup IfxLld_Lmu
 *
 * \defgroup IfxLld_Lmu_union Union
 * \ingroup IfxLld_Lmu
 *
 * \defgroup IfxLld_Lmu_struct Struct
 * \ingroup IfxLld_Lmu
 *
 */
#ifndef IFXLMU_REGDEF_H
#define IFXLMU_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Lmu_Bitfields
 * \{  */

/** \brief  LMU Access Enable Register 0 */
typedef struct _Ifx_LMU_ACCEN0_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_LMU_ACCEN0_Bits;

/** \brief  LMU Access Enable Register 1 */
typedef struct _Ifx_LMU_ACCEN1_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_LMU_ACCEN1_Bits;

/** \brief  LMU Buffer Control Register */
typedef struct _Ifx_LMU_BUFCON_Bits
{
    Ifx_Strict_32Bit TAG1 : 6;                /**< \brief [5:0] Master Tag ID 1 (rw) */
    Ifx_Strict_32Bit reserved_6 : 2;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit TAG2 : 6;                /**< \brief [13:8] Master Tag ID 2 (rw) */
    Ifx_Strict_32Bit reserved_14 : 8;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit EREN : 1;                /**< \brief [22:22] EMEM Read Buffer Enable (rw) */
    Ifx_Strict_32Bit EPEN : 1;                /**< \brief [23:23] EMEM Prefetch Enable (rw) */
    Ifx_Strict_32Bit reserved_24 : 6;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [30:30] TAG1 Field Enable (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [31:31] TAG2 Field Enable (rw) */
} Ifx_LMU_BUFCON_Bits;

/** \brief  LMU Clock Control Register */
typedef struct _Ifx_LMU_CLC_Bits
{
    Ifx_Strict_32Bit DISR : 1;                /**< \brief [0:0] Module LMU Disable Request Bit (rw) */
    Ifx_Strict_32Bit DISS : 1;                /**< \brief [1:1] Module LMU Disable Status Bit (rh) */
    Ifx_Strict_32Bit reserved_2 : 30;         /**< \brief \internal Reserved */
} Ifx_LMU_CLC_Bits;

/** \brief  LMU Memory Control Register */
typedef struct _Ifx_LMU_MEMCON_Bits
{
    Ifx_Strict_32Bit OLDAEN : 1;              /**< \brief [0:0] Online Data Acquisition Enabled (rw) */
    Ifx_Strict_32Bit POLDAEN : 1;             /**< \brief [1:1] Protection Bit for OLDAEN (w) */
    Ifx_Strict_32Bit INTERR : 1;              /**< \brief [2:2] Internal ECC Error (rwh) */
    Ifx_Strict_32Bit ERERR : 1;               /**< \brief [3:3] EMEM Read Error (rwh) */
    Ifx_Strict_32Bit RMWERR : 1;              /**< \brief [4:4] Internal Read Modify Write Error (rwh) */
    Ifx_Strict_32Bit EWERR : 1;               /**< \brief [5:5] EMEM Write Error (rwh) */
    Ifx_Strict_32Bit DATAERR : 1;             /**< \brief [6:6] SRI Data Phase ECC Error (rwh) */
    Ifx_Strict_32Bit ADDERR : 1;              /**< \brief [7:7] SRI Address Phase ECC Error (rwh) */
    Ifx_Strict_32Bit PMIC : 1;                /**< \brief [8:8] Protection Bit for Memory Integrity Control Bit (w) */
    Ifx_Strict_32Bit ERRDIS : 1;              /**< \brief [9:9] ECC Error Disable (rw) */
    Ifx_Strict_32Bit FFTPFT : 1;              /**< \brief [10:10] FFT Accelerator Prefetch Disable (rw) */
    Ifx_Strict_32Bit reserved_11 : 1;         /**< \brief \internal Reserved */
    Ifx_Strict_32Bit WSTATES : 4;             /**< \brief [15:12] EMEM Wait States (rw) */
    Ifx_Strict_32Bit reserved_16 : 16;        /**< \brief \internal Reserved */
} Ifx_LMU_MEMCON_Bits;

/** \brief  LMU Module ID Register */
typedef struct _Ifx_LMU_MODID_Bits
{
    Ifx_Strict_32Bit ID_VALUE : 32;           /**< \brief [31:0] Module Identification Value (r) */
} Ifx_LMU_MODID_Bits;

/** \brief  LMU Region Access Enable Register 0 */
typedef struct _Ifx_LMU_RGNACCENA0_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_LMU_RGNACCENA0_Bits;

/** \brief  LMU Region Access Enable Register 0 */
typedef struct _Ifx_LMU_RGNACCENA1_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_LMU_RGNACCENA1_Bits;

/** \brief  LMU Region Access Enable Register 0 */
typedef struct _Ifx_LMU_RGNACCENA2_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_LMU_RGNACCENA2_Bits;

/** \brief  LMU Region Access Enable Register 0 */
typedef struct _Ifx_LMU_RGNACCENA3_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_LMU_RGNACCENA3_Bits;

/** \brief  LMU Region Access Enable Register 0 */
typedef struct _Ifx_LMU_RGNACCENA4_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_LMU_RGNACCENA4_Bits;

/** \brief  LMU Region Access Enable Register 0 */
typedef struct _Ifx_LMU_RGNACCENA5_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_LMU_RGNACCENA5_Bits;

/** \brief  LMU Region Access Enable Register 0 */
typedef struct _Ifx_LMU_RGNACCENA6_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_LMU_RGNACCENA6_Bits;

/** \brief  LMU Region Access Enable Register 0 */
typedef struct _Ifx_LMU_RGNACCENA7_Bits
{
    Ifx_Strict_32Bit EN0 : 1;                 /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
    Ifx_Strict_32Bit EN1 : 1;                 /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
    Ifx_Strict_32Bit EN2 : 1;                 /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
    Ifx_Strict_32Bit EN3 : 1;                 /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
    Ifx_Strict_32Bit EN4 : 1;                 /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
    Ifx_Strict_32Bit EN5 : 1;                 /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
    Ifx_Strict_32Bit EN6 : 1;                 /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
    Ifx_Strict_32Bit EN7 : 1;                 /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
    Ifx_Strict_32Bit EN8 : 1;                 /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
    Ifx_Strict_32Bit EN9 : 1;                 /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
    Ifx_Strict_32Bit EN10 : 1;                /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
    Ifx_Strict_32Bit EN11 : 1;                /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
    Ifx_Strict_32Bit EN12 : 1;                /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
    Ifx_Strict_32Bit EN13 : 1;                /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
    Ifx_Strict_32Bit EN14 : 1;                /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
    Ifx_Strict_32Bit EN15 : 1;                /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
    Ifx_Strict_32Bit EN16 : 1;                /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
    Ifx_Strict_32Bit EN17 : 1;                /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
    Ifx_Strict_32Bit EN18 : 1;                /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
    Ifx_Strict_32Bit EN19 : 1;                /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
    Ifx_Strict_32Bit EN20 : 1;                /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
    Ifx_Strict_32Bit EN21 : 1;                /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
    Ifx_Strict_32Bit EN22 : 1;                /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
    Ifx_Strict_32Bit EN23 : 1;                /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
    Ifx_Strict_32Bit EN24 : 1;                /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
    Ifx_Strict_32Bit EN25 : 1;                /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
    Ifx_Strict_32Bit EN26 : 1;                /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
    Ifx_Strict_32Bit EN27 : 1;                /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
    Ifx_Strict_32Bit EN28 : 1;                /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
    Ifx_Strict_32Bit EN29 : 1;                /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
    Ifx_Strict_32Bit EN30 : 1;                /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
    Ifx_Strict_32Bit EN31 : 1;                /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
} Ifx_LMU_RGNACCENA7_Bits;

/** \brief  LMU Region Access Enable Register 1 */
typedef struct _Ifx_LMU_RGNACCENB0_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNACCENB0_Bits;

/** \brief  LMU Region Access Enable Register 1 */
typedef struct _Ifx_LMU_RGNACCENB1_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNACCENB1_Bits;

/** \brief  LMU Region Access Enable Register 1 */
typedef struct _Ifx_LMU_RGNACCENB2_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNACCENB2_Bits;

/** \brief  LMU Region Access Enable Register 1 */
typedef struct _Ifx_LMU_RGNACCENB3_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNACCENB3_Bits;

/** \brief  LMU Region Access Enable Register 1 */
typedef struct _Ifx_LMU_RGNACCENB4_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNACCENB4_Bits;

/** \brief  LMU Region Access Enable Register 1 */
typedef struct _Ifx_LMU_RGNACCENB5_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNACCENB5_Bits;

/** \brief  LMU Region Access Enable Register 1 */
typedef struct _Ifx_LMU_RGNACCENB6_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNACCENB6_Bits;

/** \brief  LMU Region Access Enable Register 1 */
typedef struct _Ifx_LMU_RGNACCENB7_Bits
{
    Ifx_Strict_32Bit reserved_0 : 32;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNACCENB7_Bits;

/** \brief  LMU Region Lower Address Register */
typedef struct _Ifx_LMU_RGNLA0_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 23;               /**< \brief [27:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNLA0_Bits;

/** \brief  LMU Region Lower Address Register */
typedef struct _Ifx_LMU_RGNLA1_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 23;               /**< \brief [27:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNLA1_Bits;

/** \brief  LMU Region Lower Address Register */
typedef struct _Ifx_LMU_RGNLA2_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 23;               /**< \brief [27:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNLA2_Bits;

/** \brief  LMU Region Lower Address Register */
typedef struct _Ifx_LMU_RGNLA3_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 23;               /**< \brief [27:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNLA3_Bits;

/** \brief  LMU Region Lower Address Register */
typedef struct _Ifx_LMU_RGNLA4_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 23;               /**< \brief [27:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNLA4_Bits;

/** \brief  LMU Region Lower Address Register */
typedef struct _Ifx_LMU_RGNLA5_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 23;               /**< \brief [27:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNLA5_Bits;

/** \brief  LMU Region Lower Address Register */
typedef struct _Ifx_LMU_RGNLA6_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 23;               /**< \brief [27:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNLA6_Bits;

/** \brief  LMU Region Lower Address Register */
typedef struct _Ifx_LMU_RGNLA7_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 23;               /**< \brief [27:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_28 : 4;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNLA7_Bits;

/** \brief  LMU Region Upper Address Register */
typedef struct _Ifx_LMU_RGNUA0_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 24;               /**< \brief [28:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNUA0_Bits;

/** \brief  LMU Region Upper Address Register */
typedef struct _Ifx_LMU_RGNUA1_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 24;               /**< \brief [28:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNUA1_Bits;

/** \brief  LMU Region Upper Address Register */
typedef struct _Ifx_LMU_RGNUA2_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 24;               /**< \brief [28:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNUA2_Bits;

/** \brief  LMU Region Upper Address Register */
typedef struct _Ifx_LMU_RGNUA3_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 24;               /**< \brief [28:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNUA3_Bits;

/** \brief  LMU Region Upper Address Register */
typedef struct _Ifx_LMU_RGNUA4_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 24;               /**< \brief [28:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNUA4_Bits;

/** \brief  LMU Region Upper Address Register */
typedef struct _Ifx_LMU_RGNUA5_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 24;               /**< \brief [28:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNUA5_Bits;

/** \brief  LMU Region Upper Address Register */
typedef struct _Ifx_LMU_RGNUA6_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 24;               /**< \brief [28:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNUA6_Bits;

/** \brief  LMU Region Upper Address Register */
typedef struct _Ifx_LMU_RGNUA7_Bits
{
    Ifx_Strict_32Bit reserved_0 : 5;          /**< \brief \internal Reserved */
    Ifx_Strict_32Bit ADDR : 24;               /**< \brief [28:5] Region Lower Address (rw) */
    Ifx_Strict_32Bit reserved_29 : 3;         /**< \brief \internal Reserved */
} Ifx_LMU_RGNUA7_Bits;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Lmu_union
 * \{  */

/** \brief  LMU Access Enable Register 0 */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_ACCEN0_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_ACCEN0;

/** \brief  LMU Access Enable Register 1 */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_ACCEN1_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_ACCEN1;

/** \brief  LMU Buffer Control Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_BUFCON_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_BUFCON;

/** \brief  LMU Clock Control Register */
typedef union
{
    unsigned int     U;                     /**< \brief Unsigned access */
    signed int       I;                     /**< \brief Signed access */
    Ifx_LMU_CLC_Bits B;                     /**< \brief Bitfield access */
} Ifx_LMU_CLC;

/** \brief  LMU Memory Control Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_MEMCON_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_MEMCON;

/** \brief  LMU Module ID Register */
typedef union
{
    unsigned int       U;                   /**< \brief Unsigned access */
    signed int         I;                   /**< \brief Signed access */
    Ifx_LMU_MODID_Bits B;                   /**< \brief Bitfield access */
} Ifx_LMU_MODID;

/** \brief  LMU Region Access Enable Register 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENA0_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENA0;

/** \brief  LMU Region Access Enable Register 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENA1_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENA1;

/** \brief  LMU Region Access Enable Register 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENA2_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENA2;

/** \brief  LMU Region Access Enable Register 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENA3_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENA3;

/** \brief  LMU Region Access Enable Register 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENA4_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENA4;

/** \brief  LMU Region Access Enable Register 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENA5_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENA5;

/** \brief  LMU Region Access Enable Register 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENA6_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENA6;

/** \brief  LMU Region Access Enable Register 0 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENA7_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENA7;

/** \brief  LMU Region Access Enable Register 1 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENB0_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENB0;

/** \brief  LMU Region Access Enable Register 1 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENB1_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENB1;

/** \brief  LMU Region Access Enable Register 1 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENB2_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENB2;

/** \brief  LMU Region Access Enable Register 1 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENB3_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENB3;

/** \brief  LMU Region Access Enable Register 1 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENB4_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENB4;

/** \brief  LMU Region Access Enable Register 1 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENB5_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENB5;

/** \brief  LMU Region Access Enable Register 1 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENB6_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENB6;

/** \brief  LMU Region Access Enable Register 1 */
typedef union
{
    unsigned int            U;              /**< \brief Unsigned access */
    signed int              I;              /**< \brief Signed access */
    Ifx_LMU_RGNACCENB7_Bits B;              /**< \brief Bitfield access */
} Ifx_LMU_RGNACCENB7;

/** \brief  LMU Region Lower Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNLA0_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNLA0;

/** \brief  LMU Region Lower Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNLA1_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNLA1;

/** \brief  LMU Region Lower Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNLA2_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNLA2;

/** \brief  LMU Region Lower Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNLA3_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNLA3;

/** \brief  LMU Region Lower Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNLA4_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNLA4;

/** \brief  LMU Region Lower Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNLA5_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNLA5;

/** \brief  LMU Region Lower Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNLA6_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNLA6;

/** \brief  LMU Region Lower Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNLA7_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNLA7;

/** \brief  LMU Region Upper Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNUA0_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNUA0;

/** \brief  LMU Region Upper Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNUA1_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNUA1;

/** \brief  LMU Region Upper Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNUA2_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNUA2;

/** \brief  LMU Region Upper Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNUA3_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNUA3;

/** \brief  LMU Region Upper Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNUA4_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNUA4;

/** \brief  LMU Region Upper Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNUA5_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNUA5;

/** \brief  LMU Region Upper Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNUA6_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNUA6;

/** \brief  LMU Region Upper Address Register */
typedef union
{
    unsigned int        U;                  /**< \brief Unsigned access */
    signed int          I;                  /**< \brief Signed access */
    Ifx_LMU_RGNUA7_Bits B;                  /**< \brief Bitfield access */
} Ifx_LMU_RGNUA7;
/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Lmu_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief  LMU object */
typedef volatile struct _Ifx_LMU
{
    Ifx_LMU_CLC        CLC;                 /**< \brief 0, LMU Clock Control Register */
    unsigned char      reserved_4[4];       /**< \brief 4, \internal Reserved */
    Ifx_LMU_MODID      MODID;               /**< \brief 8, LMU Module ID Register */
    unsigned char      reserved_C[4];       /**< \brief C, \internal Reserved */
    Ifx_LMU_ACCEN0     ACCEN0;              /**< \brief 10, LMU Access Enable Register 0 */
    Ifx_LMU_ACCEN1     ACCEN1;              /**< \brief 14, LMU Access Enable Register 1 */
    unsigned char      reserved_18[8];      /**< \brief 18, \internal Reserved */
    Ifx_LMU_MEMCON     MEMCON;              /**< \brief 20, LMU Memory Control Register */
    unsigned char      reserved_24[12];     /**< \brief 24, \internal Reserved */
    Ifx_LMU_BUFCON     BUFCON[3];           /**< \brief 30, LMU Buffer Control Register */
    unsigned char      reserved_3C[20];     /**< \brief 3C, \internal Reserved */
    Ifx_LMU_RGNLA0     RGNLA0;              /**< \brief 50, LMU Region Lower Address Register */
    Ifx_LMU_RGNUA0     RGNUA0;              /**< \brief 54, LMU Region Upper Address Register */
    Ifx_LMU_RGNACCENA0 RGNACCENA0;          /**< \brief 58, LMU Region Access Enable Register 0 */
    Ifx_LMU_RGNACCENB0 RGNACCENB0;          /**< \brief 5C, LMU Region Access Enable Register 1 */
    Ifx_LMU_RGNLA1     RGNLA1;              /**< \brief 60, LMU Region Lower Address Register */
    Ifx_LMU_RGNUA1     RGNUA1;              /**< \brief 64, LMU Region Upper Address Register */
    Ifx_LMU_RGNACCENA1 RGNACCENA1;          /**< \brief 68, LMU Region Access Enable Register 0 */
    Ifx_LMU_RGNACCENB1 RGNACCENB1;          /**< \brief 6C, LMU Region Access Enable Register 1 */
    Ifx_LMU_RGNLA2     RGNLA2;              /**< \brief 70, LMU Region Lower Address Register */
    Ifx_LMU_RGNUA2     RGNUA2;              /**< \brief 74, LMU Region Upper Address Register */
    Ifx_LMU_RGNACCENA2 RGNACCENA2;          /**< \brief 78, LMU Region Access Enable Register 0 */
    Ifx_LMU_RGNACCENB2 RGNACCENB2;          /**< \brief 7C, LMU Region Access Enable Register 1 */
    Ifx_LMU_RGNLA3     RGNLA3;              /**< \brief 80, LMU Region Lower Address Register */
    Ifx_LMU_RGNUA3     RGNUA3;              /**< \brief 84, LMU Region Upper Address Register */
    Ifx_LMU_RGNACCENA3 RGNACCENA3;          /**< \brief 88, LMU Region Access Enable Register 0 */
    Ifx_LMU_RGNACCENB3 RGNACCENB3;          /**< \brief 8C, LMU Region Access Enable Register 1 */
    Ifx_LMU_RGNLA4     RGNLA4;              /**< \brief 90, LMU Region Lower Address Register */
    Ifx_LMU_RGNUA4     RGNUA4;              /**< \brief 94, LMU Region Upper Address Register */
    Ifx_LMU_RGNACCENA4 RGNACCENA4;          /**< \brief 98, LMU Region Access Enable Register 0 */
    Ifx_LMU_RGNACCENB4 RGNACCENB4;          /**< \brief 9C, LMU Region Access Enable Register 1 */
    Ifx_LMU_RGNLA5     RGNLA5;              /**< \brief A0, LMU Region Lower Address Register */
    Ifx_LMU_RGNUA5     RGNUA5;              /**< \brief A4, LMU Region Upper Address Register */
    Ifx_LMU_RGNACCENA5 RGNACCENA5;          /**< \brief A8, LMU Region Access Enable Register 0 */
    Ifx_LMU_RGNACCENB5 RGNACCENB5;          /**< \brief AC, LMU Region Access Enable Register 1 */
    Ifx_LMU_RGNLA6     RGNLA6;              /**< \brief B0, LMU Region Lower Address Register */
    Ifx_LMU_RGNUA6     RGNUA6;              /**< \brief B4, LMU Region Upper Address Register */
    Ifx_LMU_RGNACCENA6 RGNACCENA6;          /**< \brief B8, LMU Region Access Enable Register 0 */
    Ifx_LMU_RGNACCENB6 RGNACCENB6;          /**< \brief BC, LMU Region Access Enable Register 1 */
    Ifx_LMU_RGNLA7     RGNLA7;              /**< \brief C0, LMU Region Lower Address Register */
    Ifx_LMU_RGNUA7     RGNUA7;              /**< \brief C4, LMU Region Upper Address Register */
    Ifx_LMU_RGNACCENA7 RGNACCENA7;          /**< \brief C8, LMU Region Access Enable Register 0 */
    Ifx_LMU_RGNACCENB7 RGNACCENB7;          /**< \brief CC, LMU Region Access Enable Register 1 */
    unsigned char      reserved_D0[48];     /**< \brief D0, \internal Reserved */
} Ifx_LMU;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXLMU_REGDEF_H */
