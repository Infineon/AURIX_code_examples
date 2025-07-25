/**
 * \file IfxAccen_regdef.h
 * \brief
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 * MAY BE CHANGED BY USER [yes/no]: Yes
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such
 * terms of use are agreed, use of this file is subject to following:
 *
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or
 * organization obtaining a copy of the software and accompanying
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxSfr_Accen_Registers Accen Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Accen_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Accen_Registers
 * 
 * \defgroup IfxSfr_Accen_Registers_union Register unions
 * \ingroup IfxSfr_Accen_Registers
 * 
 * \defgroup IfxSfr_Accen_Registers_struct Memory map
 * \ingroup IfxSfr_Accen_Registers
 */
#ifndef IFXACCEN_REGDEF_H
#define IFXACCEN_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/


/** \addtogroup IfxSfr_Accen_Registers_Bitfields
 * \{  */
/** \brief PRS access enable register */
typedef struct _Ifx_ACCEN_ACCEN_PRS_Bits
{
    Ifx_UReg_32Bit RD00:1;            /**< \brief [0:0] Read access enable for PRS q (rw) */
    Ifx_UReg_32Bit RD01:1;            /**< \brief [1:1] Read access enable for PRS q (rw) */
    Ifx_UReg_32Bit RD02:1;            /**< \brief [2:2] Read access enable for PRS q (rw) */
    Ifx_UReg_32Bit RD03:1;            /**< \brief [3:3] Read access enable for PRS q (rw) */
    Ifx_UReg_32Bit RD04:1;            /**< \brief [4:4] Read access enable for PRS q (rw) */
    Ifx_UReg_32Bit RD05:1;            /**< \brief [5:5] Read access enable for PRS q (rw) */
    Ifx_UReg_32Bit RD06:1;            /**< \brief [6:6] Read access enable for PRS q (rw) */
    Ifx_UReg_32Bit RD07:1;            /**< \brief [7:7] Read access enable for PRS q (rw) */
    Ifx_UReg_32Bit reserved_8:8;      /**< \brief [15:8] \internal Reserved */
    Ifx_UReg_32Bit WR00:1;            /**< \brief [16:16] Write access enable for PRS q (rw) */
    Ifx_UReg_32Bit WR01:1;            /**< \brief [17:17] Write access enable for PRS q (rw) */
    Ifx_UReg_32Bit WR02:1;            /**< \brief [18:18] Write access enable for PRS q (rw) */
    Ifx_UReg_32Bit WR03:1;            /**< \brief [19:19] Write access enable for PRS q (rw) */
    Ifx_UReg_32Bit WR04:1;            /**< \brief [20:20] Write access enable for PRS q (rw) */
    Ifx_UReg_32Bit WR05:1;            /**< \brief [21:21] Write access enable for PRS q (rw) */
    Ifx_UReg_32Bit WR06:1;            /**< \brief [22:22] Write access enable for PRS q (rw) */
    Ifx_UReg_32Bit WR07:1;            /**< \brief [23:23] Write access enable for PRS q (rw) */
    Ifx_UReg_32Bit reserved_24:8;     /**< \brief [31:24] \internal Reserved */
} Ifx_ACCEN_ACCEN_PRS_Bits;

/** \brief Read access enable register A */
typedef struct _Ifx_ACCEN_ACCEN_RDA_Bits
{
    Ifx_UReg_32Bit EN00:1;            /**< \brief [0:0] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN01:1;            /**< \brief [1:1] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN02:1;            /**< \brief [2:2] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN03:1;            /**< \brief [3:3] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN04:1;            /**< \brief [4:4] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN05:1;            /**< \brief [5:5] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN06:1;            /**< \brief [6:6] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN07:1;            /**< \brief [7:7] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN08:1;            /**< \brief [8:8] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN09:1;            /**< \brief [9:9] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN10:1;            /**< \brief [10:10] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN11:1;            /**< \brief [11:11] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN12:1;            /**< \brief [12:12] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN13:1;            /**< \brief [13:13] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN14:1;            /**< \brief [14:14] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN15:1;            /**< \brief [15:15] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN16:1;            /**< \brief [16:16] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN17:1;            /**< \brief [17:17] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN18:1;            /**< \brief [18:18] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN19:1;            /**< \brief [19:19] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN20:1;            /**< \brief [20:20] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN21:1;            /**< \brief [21:21] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN22:1;            /**< \brief [22:22] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN23:1;            /**< \brief [23:23] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN24:1;            /**< \brief [24:24] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN25:1;            /**< \brief [25:25] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN26:1;            /**< \brief [26:26] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN27:1;            /**< \brief [27:27] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN28:1;            /**< \brief [28:28] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN29:1;            /**< \brief [29:29] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN30:1;            /**< \brief [30:30] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN31:1;            /**< \brief [31:31] Read access enable for Master TAG ID q - ENq (rw) */
} Ifx_ACCEN_ACCEN_RDA_Bits;

/** \brief Read access enable register B */
typedef struct _Ifx_ACCEN_ACCEN_RDB_SRI_Bits
{
    Ifx_UReg_32Bit EN32:1;            /**< \brief [0:0] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN33:1;            /**< \brief [1:1] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN34:1;            /**< \brief [2:2] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN35:1;            /**< \brief [3:3] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN36:1;            /**< \brief [4:4] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN37:1;            /**< \brief [5:5] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN38:1;            /**< \brief [6:6] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN39:1;            /**< \brief [7:7] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN40:1;            /**< \brief [8:8] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN41:1;            /**< \brief [9:9] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN42:1;            /**< \brief [10:10] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN43:1;            /**< \brief [11:11] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN44:1;            /**< \brief [12:12] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN45:1;            /**< \brief [13:13] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN46:1;            /**< \brief [14:14] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN47:1;            /**< \brief [15:15] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN48:1;            /**< \brief [16:16] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN49:1;            /**< \brief [17:17] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN50:1;            /**< \brief [18:18] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN51:1;            /**< \brief [19:19] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN52:1;            /**< \brief [20:20] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN53:1;            /**< \brief [21:21] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN54:1;            /**< \brief [22:22] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN55:1;            /**< \brief [23:23] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN56:1;            /**< \brief [24:24] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN57:1;            /**< \brief [25:25] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN58:1;            /**< \brief [26:26] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN59:1;            /**< \brief [27:27] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN60:1;            /**< \brief [28:28] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN61:1;            /**< \brief [29:29] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN62:1;            /**< \brief [30:30] Read access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN63:1;            /**< \brief [31:31] Read access enable for Master TAG ID q - ENq (rw) */
} Ifx_ACCEN_ACCEN_RDB_SRI_Bits;

/** \brief Region lower address register */
typedef struct _Ifx_ACCEN_ACCEN_RGNLA_Bits
{
    Ifx_UReg_32Bit reserved_0:6;      /**< \brief [5:0] \internal Reserved */
    Ifx_UReg_32Bit ADDR:26;           /**< \brief [31:6]  (rw) */
} Ifx_ACCEN_ACCEN_RGNLA_Bits;

/** \brief Region upper address register */
typedef struct _Ifx_ACCEN_ACCEN_RGNUA_Bits
{
    Ifx_UReg_32Bit reserved_0:6;      /**< \brief [5:0] \internal Reserved */
    Ifx_UReg_32Bit ADDR:26;           /**< \brief [31:6]  (rw) */
} Ifx_ACCEN_ACCEN_RGNUA_Bits;

/** \brief VM access enable register */
typedef struct _Ifx_ACCEN_ACCEN_VM_Bits
{
    Ifx_UReg_32Bit RD00:1;            /**< \brief [0:0] Read access enable for VM ID q (rw) */
    Ifx_UReg_32Bit RD01:1;            /**< \brief [1:1] Read access enable for VM ID q (rw) */
    Ifx_UReg_32Bit RD02:1;            /**< \brief [2:2] Read access enable for VM ID q (rw) */
    Ifx_UReg_32Bit RD03:1;            /**< \brief [3:3] Read access enable for VM ID q (rw) */
    Ifx_UReg_32Bit RD04:1;            /**< \brief [4:4] Read access enable for VM ID q (rw) */
    Ifx_UReg_32Bit RD05:1;            /**< \brief [5:5] Read access enable for VM ID q (rw) */
    Ifx_UReg_32Bit RD06:1;            /**< \brief [6:6] Read access enable for VM ID q (rw) */
    Ifx_UReg_32Bit RD07:1;            /**< \brief [7:7] Read access enable for VM ID q (rw) */
    Ifx_UReg_32Bit reserved_8:8;      /**< \brief [15:8] \internal Reserved */
    Ifx_UReg_32Bit WR00:1;            /**< \brief [16:16] Write access enable for VM ID q (rw) */
    Ifx_UReg_32Bit WR01:1;            /**< \brief [17:17] Write access enable for VM ID q (rw) */
    Ifx_UReg_32Bit WR02:1;            /**< \brief [18:18] Write access enable for VM ID q (rw) */
    Ifx_UReg_32Bit WR03:1;            /**< \brief [19:19] Write access enable for VM ID q (rw) */
    Ifx_UReg_32Bit WR04:1;            /**< \brief [20:20] Write access enable for VM ID q (rw) */
    Ifx_UReg_32Bit WR05:1;            /**< \brief [21:21] Write access enable for VM ID q (rw) */
    Ifx_UReg_32Bit WR06:1;            /**< \brief [22:22] Write access enable for VM ID q (rw) */
    Ifx_UReg_32Bit WR07:1;            /**< \brief [23:23] Write access enable for VM ID q (rw) */
    Ifx_UReg_32Bit reserved_24:8;     /**< \brief [31:24] \internal Reserved */
} Ifx_ACCEN_ACCEN_VM_Bits;

/** \brief Write access enable register A */
typedef struct _Ifx_ACCEN_ACCEN_WRA_Bits
{
    Ifx_UReg_32Bit EN00:1;            /**< \brief [0:0] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN01:1;            /**< \brief [1:1] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN02:1;            /**< \brief [2:2] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN03:1;            /**< \brief [3:3] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN04:1;            /**< \brief [4:4] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN05:1;            /**< \brief [5:5] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN06:1;            /**< \brief [6:6] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN07:1;            /**< \brief [7:7] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN08:1;            /**< \brief [8:8] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN09:1;            /**< \brief [9:9] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN10:1;            /**< \brief [10:10] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN11:1;            /**< \brief [11:11] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN12:1;            /**< \brief [12:12] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN13:1;            /**< \brief [13:13] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN14:1;            /**< \brief [14:14] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN15:1;            /**< \brief [15:15] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN16:1;            /**< \brief [16:16] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN17:1;            /**< \brief [17:17] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN18:1;            /**< \brief [18:18] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN19:1;            /**< \brief [19:19] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN20:1;            /**< \brief [20:20] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN21:1;            /**< \brief [21:21] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN22:1;            /**< \brief [22:22] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN23:1;            /**< \brief [23:23] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN24:1;            /**< \brief [24:24] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN25:1;            /**< \brief [25:25] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN26:1;            /**< \brief [26:26] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN27:1;            /**< \brief [27:27] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN28:1;            /**< \brief [28:28] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN29:1;            /**< \brief [29:29] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN30:1;            /**< \brief [30:30] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN31:1;            /**< \brief [31:31] Write access enable for Master TAG ID q - ENq (rw) */
} Ifx_ACCEN_ACCEN_WRA_Bits;

/** \brief Write access enable register B */
typedef struct _Ifx_ACCEN_ACCEN_WRB_SRI_Bits
{
    Ifx_UReg_32Bit EN32:1;            /**< \brief [0:0] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN33:1;            /**< \brief [1:1] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN34:1;            /**< \brief [2:2] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN35:1;            /**< \brief [3:3] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN36:1;            /**< \brief [4:4] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN37:1;            /**< \brief [5:5] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN38:1;            /**< \brief [6:6] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN39:1;            /**< \brief [7:7] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN40:1;            /**< \brief [8:8] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN41:1;            /**< \brief [9:9] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN42:1;            /**< \brief [10:10] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN43:1;            /**< \brief [11:11] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN44:1;            /**< \brief [12:12] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN45:1;            /**< \brief [13:13] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN46:1;            /**< \brief [14:14] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN47:1;            /**< \brief [15:15] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN48:1;            /**< \brief [16:16] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN49:1;            /**< \brief [17:17] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN50:1;            /**< \brief [18:18] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN51:1;            /**< \brief [19:19] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN52:1;            /**< \brief [20:20] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN53:1;            /**< \brief [21:21] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN54:1;            /**< \brief [22:22] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN55:1;            /**< \brief [23:23] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN56:1;            /**< \brief [24:24] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN57:1;            /**< \brief [25:25] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN58:1;            /**< \brief [26:26] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN59:1;            /**< \brief [27:27] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN60:1;            /**< \brief [28:28] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN61:1;            /**< \brief [29:29] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN62:1;            /**< \brief [30:30] Write access enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN63:1;            /**< \brief [31:31] Write access enable for Master TAG ID q - ENq (rw) */
} Ifx_ACCEN_ACCEN_WRB_SRI_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_accen_Registers_union
 * \{   */
/** \brief PRS access enable register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ACCEN_ACCEN_PRS_Bits B;       /**< \brief Bitfield access */
} Ifx_ACCEN_ACCEN_PRS;

/** \brief Read access enable register A   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ACCEN_ACCEN_RDA_Bits B;       /**< \brief Bitfield access */
} Ifx_ACCEN_ACCEN_RDA;

/** \brief Read access enable register B   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ACCEN_ACCEN_RDB_SRI_Bits B;    /**< \brief Bitfield access */
} Ifx_ACCEN_ACCEN_RDB_SRI;

/** \brief Region lower address register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ACCEN_ACCEN_RGNLA_Bits B;     /**< \brief Bitfield access */
} Ifx_ACCEN_ACCEN_RGNLA;

/** \brief Region upper address register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ACCEN_ACCEN_RGNUA_Bits B;     /**< \brief Bitfield access */
} Ifx_ACCEN_ACCEN_RGNUA;

/** \brief VM access enable register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ACCEN_ACCEN_VM_Bits B;        /**< \brief Bitfield access */
} Ifx_ACCEN_ACCEN_VM;

/** \brief Write access enable register A   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ACCEN_ACCEN_WRA_Bits B;       /**< \brief Bitfield access */
} Ifx_ACCEN_ACCEN_WRA;

/** \brief Write access enable register B   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_ACCEN_ACCEN_WRB_SRI_Bits B;    /**< \brief Bitfield access */
} Ifx_ACCEN_ACCEN_WRB_SRI;

/** \}  */

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Accen_ACCEN_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */
/** \brief ACCEN object */
typedef volatile struct _Ifx_ACCEN_ACCEN
{
       Ifx_ACCEN_ACCEN_WRA                 WRA;                    /**< \brief 0, Write access enable register A*/
       Ifx_ACCEN_ACCEN_WRB_SRI             WRB;                    /**< \brief 4, Write access enable register B*/
       Ifx_ACCEN_ACCEN_RDA                 RDA;                    /**< \brief 8, Read access enable register A*/
       Ifx_ACCEN_ACCEN_RDB_SRI             RDB;                    /**< \brief C, Read access enable register B*/
       Ifx_ACCEN_ACCEN_VM                  VM;                     /**< \brief 10, VM access enable register*/
       Ifx_ACCEN_ACCEN_PRS                 PRS;                    /**< \brief 14, PRS access enable register*/
       Ifx_ACCEN_ACCEN_RGNLA               RGNLA;                  /**< \brief 18, Region lower address register*/
       Ifx_ACCEN_ACCEN_RGNUA               RGNUA;                  /**< \brief 1C, Region upper address register*/
} Ifx_ACCEN_ACCEN;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/** \addtogroup IfxSfr_Accen_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief ACCEN object */
typedef volatile struct _Ifx_ACCEN
{
       Ifx_ACCEN_ACCEN                     ACCEN;                  /**< \brief 0, Region upper address register*/
       Ifx_UReg_8Bit                       reserved_20[224];       /**< \brief 20, \internal Reserved */
} Ifx_ACCEN;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/
/******************************************************************************/

#endif /* IFXACCEN_REGDEF_H */
