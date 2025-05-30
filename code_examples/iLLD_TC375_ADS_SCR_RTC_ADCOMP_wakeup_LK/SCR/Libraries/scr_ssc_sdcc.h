/**********************************************************************************************************************
 * \file scr_ssc_sdcc.h
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

#ifndef SCR_SSC_SDCC_H_
#define SCR_SSC_SDCC_H_ 1

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "scr_generic_defs.h"

/*********************************************************************************************************************/
/*---------------------------------------------------SSC Registers---------------------------------------------------*/
/*********************************************************************************************************************/
__sfr __at(ADDR_SCR_SSC_CONPL)              SCR_SSC_CONPL;
__sfr __at(ADDR_SCR_SSC_CONOL)              SCR_SSC_CONOL;
__sfr __at(ADDR_SCR_SSC_CONPH)              SCR_SSC_CONPH;
__sfr __at(ADDR_SCR_SSC_CONOH)              SCR_SSC_CONOH;
__sfr __at(ADDR_SCR_SSC_BRL)                SCR_SSC_BRL;
__sfr __at(ADDR_SCR_SSC_BRH)                SCR_SSC_BRH;
__sfr __at(ADDR_SCR_SSC_TBL)                SCR_SSC_TBL;
__sfr __at(ADDR_SCR_SSC_RBL)                SCR_SSC_RBL;

/*********************************************************************************************************************/
/*--------------------------------------------------Data Structures--------------------------------------------------*/
/*********************************************************************************************************************/

/** \addtogroup Scr_SSC_Registers_Bitfields
 * \{  */

/** \brief Control Register Low [Programming Mode] */
typedef struct
{
    Scr_UReg_8Bit BM:3;             /**< \brief [2:0] Data Width Selection (rw) */
    Scr_UReg_8Bit reserved_0:1;     /**< \brief [3:3] \internal Reserved */
    Scr_UReg_8Bit HB:1;             /**< \brief [4:4] Heading Control (rw) */
    Scr_UReg_8Bit PH:1;             /**< \brief [5:5] Clock Phase Control (rw) */
    Scr_UReg_8Bit PO:1;             /**< \brief [6:6] Clock Polarity Control (rw) */
    Scr_UReg_8Bit LB:1;             /**< \brief [7:7] Loop Back Control (rw) */
} Scr_SSC_CONPL_Bits;

/** \brief Control Register Low [Operation Mode] */
typedef struct
{
    Scr_UReg_8Bit BC:4;             /**< \brief [3:0] Bit Count Field (rh) */
    Scr_UReg_8Bit R4:4;             /**< \brief [7:3] \internal Reserved */
} Scr_SSC_CONOL_Bits;

/** \brief Control Register High [Programming Mode] */
typedef struct
{
    Scr_UReg_8Bit TEN:1;            /**< \brief [0:0] Transmit Error Enable (rw) */
    Scr_UReg_8Bit REN:1;            /**< \brief [1:1] Receive Error Enable (rw) */
    Scr_UReg_8Bit reserved_0:1;     /**< \brief [2:2] \internal Reserved */
    Scr_UReg_8Bit BEN:1;            /**< \brief [3:3] Baudrate Error Enable (rw) */
    Scr_UReg_8Bit reserved_1:2;     /**< \brief [5:4] \internal Reserved */
    Scr_UReg_8Bit MS:1;             /**< \brief [6:6] Master Select (rw) */
    Scr_UReg_8Bit EN:1;             /**< \brief [7:7] Enable Bit = 0 (needed for programming mode) (rw) */
} Scr_SSC_CONPH_Bits;

/** \brief Control Register High [Operation Mode] */
typedef struct
{
    Scr_UReg_8Bit TE:1;             /**< \brief [0:0] Transmit Error Flag (rwh) */
    Scr_UReg_8Bit RE:1;             /**< \brief [1:1] Receive Error Flag (rwh) */
    Scr_UReg_8Bit RFE:1;            /**< \brief [2:2] Receive FIFO Buffer Empty Flag (rh) */
    Scr_UReg_8Bit BE:1;             /**< \brief [3:3] Baudrate Error Flag (rwh) */
    Scr_UReg_8Bit BSY:1;            /**< \brief [4:4] Busy Flag (rh) */
    Scr_UReg_8Bit RFF:1;            /**< \brief [5:5] Receive FIFO Buffer Full Flag (rh) */
    Scr_UReg_8Bit MS:1;             /**< \brief [6:6] Master Select (rw) */
    Scr_UReg_8Bit EN:1;             /**< \brief [7:7] Enable Bit = 1 (needed for operating mode) (rw) */
} Scr_SSC_CONOH_Bits;

/** \brief Baud Rate Timer Reload Register Low */
typedef struct
{
    Scr_UReg_8Bit BR_VALUE;         /**< \brief [7:0] Baud Rate Timer Reload Register Value, low byte [7:0] (rw) */
} Scr_SSC_BRL_Bits;

/** \brief Baud Rate Timer Reload Register High */
typedef struct
{
    Scr_UReg_8Bit BR_VALUE;         /**< \brief [7:0] Baud Rate Timer Reload Register Value, high byte [15:8] (rw) */
} Scr_SSC_BRH_Bits;

/** \brief Transmitter Buffer Register */
typedef struct
{
    Scr_UReg_8Bit TB_VALUE;         /**< \brief [7:0] Transmit Data Register Value (rw) */
} Scr_SSC_TBL_Bits;

/** \brief Receiver Buffer Register */
typedef struct
{
    Scr_UReg_8Bit RB_VALUE;         /**< \brief [7:0] Receive Data Register Value (rh) */
} Scr_SSC_RBL_Bits;

/** \}  */

/** \addtogroup Scr_SSC_Registers_union
 * \{   */

/** \brief Control Register Low [Programming Mode] */
typedef union
{
    Scr_UReg_8Bit U;                /**< \brief Unsigned access */
    Scr_SReg_8Bit I;                /**< \brief Signed access */
    Scr_SSC_CONPL_Bits B;           /**< \brief Bitfield access */
} Scr_SSC_CONPL;

/** \brief Control Register Low [Operation Mode] */
typedef union
{
    Scr_UReg_8Bit U;                /**< \brief Unsigned access */
    Scr_SReg_8Bit I;                /**< \brief Signed access */
    Scr_SSC_CONOL_Bits B;           /**< \brief Bitfield access */
} Scr_SSC_CONOL;

/** \brief Control Register High [Programming Mode] */
typedef union
{
    Scr_UReg_8Bit U;                /**< \brief Unsigned access */
    Scr_SReg_8Bit I;                /**< \brief Signed access */
    Scr_SSC_CONPH_Bits B;           /**< \brief Bitfield access */
} Scr_SSC_CONPH;

/** \brief Control Register High [Operation Mode] */
typedef union
{
    Scr_UReg_8Bit U;                /**< \brief Unsigned access */
    Scr_SReg_8Bit I;                /**< \brief Signed access */
    Scr_SSC_CONOH_Bits B;           /**< \brief Bitfield access */
} Scr_SSC_CONOH;

/** \brief Baud Rate Timer Reload Register Low */
typedef union
{
    Scr_UReg_8Bit U;                /**< \brief Unsigned access */
    Scr_SReg_8Bit I;                /**< \brief Signed access */
    Scr_SSC_BRL_Bits B;             /**< \brief Bitfield access */
} Scr_SSC_BRL;

/** \brief Baud Rate Timer Reload Register High */
typedef union
{
    Scr_UReg_8Bit U;                /**< \brief Unsigned access */
    Scr_SReg_8Bit I;                /**< \brief Signed access */
    Scr_SSC_BRH_Bits B;             /**< \brief Bitfield access */
} Scr_SSC_BRH;

/** \brief Transmitter Buffer Register */
typedef union
{
    Scr_UReg_8Bit U;                /**< \brief Unsigned access */
    Scr_SReg_8Bit I;                /**< \brief Signed access */
    Scr_SSC_TBL_Bits B;             /**< \brief Bitfield access */
} Scr_SSC_TBL;

/** \brief Receiver Buffer Register */
typedef union
{
    Scr_UReg_8Bit U;                /**< \brief Unsigned access */
    Scr_SReg_8Bit I;                /**< \brief Signed access */
    Scr_SSC_RBL_Bits B;             /**< \brief Bitfield access */
} Scr_SSC_RBL;

/** \}  */

/*********************************************************************************************************************/
/*-------------------------------------------------Inline Functions--------------------------------------------------*/
/*********************************************************************************************************************/

#endif /* SCR_SSC_SDCC_H_ */
