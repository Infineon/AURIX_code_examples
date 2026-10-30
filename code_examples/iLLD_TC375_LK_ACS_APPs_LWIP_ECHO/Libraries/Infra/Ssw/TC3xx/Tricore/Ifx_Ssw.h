/**
 * \file Ifx_Ssw.h
 * \brief Startup Software configuration. Can configure which core to be enabled.
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 */

#ifndef IFX_SSW_H_
#define IFX_SSW_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Ssw_Compilers.h"
#include "Ifx_Ssw_LegacySwCfg.h"

/******************************************************************************/
/*                          Macros                                            */
/******************************************************************************/  

#ifndef IFX_CFG_SSW_ENABLE_TRICORE0
#define IFX_CFG_SSW_ENABLE_TRICORE0 (1U)
#endif

#if defined(DEVICE_TC39XB) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC37X) || defined(DEVICE_TC36X) || defined(DEVICE_TC35X) || defined(DEVICE_TC33XED)
#ifndef IFX_CFG_SSW_ENABLE_TRICORE1
#define IFX_CFG_SSW_ENABLE_TRICORE1 (1U)
#endif
#endif /* #if defined(DEVICE_TC39XB) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC37X) || defined(DEVICE_TC36X) || defined(DEVICE_TC35X) || defined(DEVICE_TC33XED) */

#if defined(DEVICE_TC39XB) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC37X) || defined(DEVICE_TC35X)
#ifndef IFX_CFG_SSW_ENABLE_TRICORE2
#define IFX_CFG_SSW_ENABLE_TRICORE2 (1U)
#endif
#endif /* #if defined(DEVICE_TC39XB) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC37X) || defined(DEVICE_TC35X) */

#if defined(DEVICE_TC39XB) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X)
#ifndef IFX_CFG_SSW_ENABLE_TRICORE3
#define IFX_CFG_SSW_ENABLE_TRICORE3 (1U)
#endif
#endif /* #if defined(DEVICE_TC39XB) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) */

#if defined(DEVICE_TC39XB)
#ifndef IFX_CFG_SSW_ENABLE_TRICORE4
#define IFX_CFG_SSW_ENABLE_TRICORE4 (1U)
#endif

#ifndef IFX_CFG_SSW_ENABLE_TRICORE5
#define IFX_CFG_SSW_ENABLE_TRICORE5 (1U)
#endif
#endif /* #if defined(DEVICE_TC39XB) */

#ifndef IFX_CFG_SSW_PSW_DEFAULT
#define IFX_CFG_SSW_PSW_DEFAULT     (0x00000980u)
#endif

#ifndef IFX_CFG_SSW_ENABLE_INDIVIDUAL_C_INIT
#define IFX_CFG_SSW_ENABLE_INDIVIDUAL_C_INIT (0U)
#endif

/******************************************************************************/
/*                          Typedefs                                          */
/******************************************************************************/
/** \brief Structure definition for the BMHD
 * Based on BMI and start address respective CRC and Inverted CRC values has to be calculated and updated.
 * CRC-32 polynomial as defined in the IEEE 802.3 standard is used to generate the CRC value. The CRC algorithm
 * treats input data as a stream of bits.
 *
 * Eg. To calculate the CRC data has to given in big-endian order.
 * for the below values:
 *    bmi    = 0x00FE
 *    bmhdid = 0xB359
 *    stad   = 0xA00A0000
 * CRC calculation:
 *    Input        = 0xB35900FEA00A0000
 *    CRC value    = 0x3CEED0A6
 *    CRC Inverted = 0xC3112F59
 */
typedef struct
{
    unsigned short bmi;             /**< \brief 0x000: Boot Mode Index (BMI)*/
    unsigned short bmhdid;          /**< \brief 0x002: Boot Mode Header ID (CODE) = B359H*/
    unsigned int   stad;            /**< \brief 0x004: User Code start address*/
    unsigned int   crc;             /**< \brief 0x008: Check Result for the BMI Header (offset 000H - 007H)*/
    unsigned int   crcInv;          /**< \brief 0x00C: Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    unsigned int   reserved0[60];   /**< \brief 0x010: Reserved area (60 words) till the offset 0x100*/
    unsigned int   pw[8];           /**< \brief 0x100: Password protection (8 words) till the offset 0x120 */
    unsigned int   reserved1[52];   /**< \brief 0x120: Reserved area (52 words) till the offset 0x1F0*/
    unsigned int   confirmation;    /**< \brief 0x1F0: 32-bit CODE, (always same)*/
} Ifx_Ssw_Bmhd;

/******************************************************************************/
/*                         Exported prototypes                                */
/******************************************************************************/

#if defined(DEVICE_TC39XB) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC37X) || defined(DEVICE_TC36X) || defined(DEVICE_TC35X) || defined(DEVICE_TC33XED)
void __Core1_start(void);
#endif

#if defined(DEVICE_TC39XB) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC37X) || defined(DEVICE_TC35X)
void __Core2_start(void);
#endif

#if defined(DEVICE_TC39XB) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X)
void __Core3_start(void);
#endif

#if defined(DEVICE_TC39XB)
void __Core4_start(void);
void __Core5_start(void);
#endif

#endif /* IFX_SSW_H_ */
