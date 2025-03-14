/**********************************************************************************************************************
 * \file scr_generic_defs.h
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

#ifndef SCR_GENERIC_DEFS_H_
#define SCR_GENERIC_DEFS_H_ 1

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "registers.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define SCR_INLINE      static inline

/*********************************************************************************************************************/
/*--------------------------------------------------Data Structures--------------------------------------------------*/
/*********************************************************************************************************************/
typedef signed char     sint8;      /*        -128 .. +127          */
typedef unsigned char   uint8;      /*           0 .. 255           */
typedef signed short    sint16;     /*      -32768 .. +32767        */
typedef unsigned short  uint16;     /*           0 .. 65535         */
typedef signed long     sint32;     /* -2147483648 .. +2147483647   */
typedef unsigned long   uint32;     /*           0 .. 4294967295    */
typedef long long       uint64;     /*           0 .. 4294967295    */
typedef float           float32;

typedef unsigned char   boolean;    /* for use with TRUE/FALSE */

typedef unsigned char   Scr_UReg_8Bit;
typedef signed char     Scr_SReg_8Bit;

typedef enum
{
    MOD_PAGE_0 = 0, /* 000b - PAGE0 is selected. */
    MOD_PAGE_1 = 1, /* 001b - PAGE1 is selected. */
    MOD_PAGE_2 = 2, /* 010b - PAGE2 is selected. */
    MOD_PAGE_3 = 3, /* 011b - PAGE3 is selected. */
    MOD_PAGE_4 = 4, /* 100b - PAGE4 is selected. */
    MOD_PAGE_5 = 5, /* 101b - PAGE5 is selected. */
    MOD_PAGE_6 = 6, /* 110b - PAGE6 is selected. */
    MOD_PAGE_7 = 7, /* 111b - PAGE7 is selected. */
    MOD_PAGE_MASK = 0x07
} ModPage;

typedef enum
{
    MOD_STNR_0 = (0 << 4), /* 00b - MOD_ST0 is selected. */
    MOD_STNR_1 = (1 << 4), /* 01b - MOD_ST1 is selected. */
    MOD_STNR_2 = (2 << 4), /* 10b - MOD_ST2 is selected. */
    MOD_STNR_3 = (3 << 4), /* 11b - MOD_ST3 is selected. */
    MOD_STNR_MASK = 0x30
} ModStnr;

typedef enum
{
    MOD_OP_MAN     = (0 << 6), /* 0Xb - Manual page mode. The value of STNR is ignored and PAGE is directly written. */
    MOD_OP_SAVE    = (2 << 6), /* 10b - New page programming with automatic page saving. The value written to the bit
                                        positions of PAGE is stored. In parallel, the previous contents of PAGE are saved
                                        in the storage bit field STx indicated by STNR. */
    MOD_OP_RESTORE = (3 << 6), /* 11b - Automatic restore page action. The value written to the bit positions PAGE is
                                        ignored and instead, PAGE is overwritten by the contents of the storage bit field
                                        STx indicated by STNR. */
    MOD_OP_MASK    = 0xC0
} ModOp;

#endif /* SCR_GENERIC_DEFS_H_ */
