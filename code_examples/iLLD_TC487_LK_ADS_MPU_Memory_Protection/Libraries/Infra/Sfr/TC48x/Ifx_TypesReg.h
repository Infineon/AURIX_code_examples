/**
 * \file Ifx_TypesReg.h
 * \brief
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 * Version: IFXREGTYPES_V1.0.R0
 *
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
 *
 * Data type access rules for peripheral space
 * data type                               | Allowed access size   | Alignment of address in memory
 * ----------------------------------------|-----------------------|-----------------------------------
 * Ifx_UReg_8Bit, Ifx_SReg_8Bit            | Byte                  | Byte (1H)                         
 * Ifx_UReg_16Bit, Ifx_SReg_16Bit          | Byte, Half-Word       | 2 bytes (2H)                      
 * Ifx_UReg_32Bit, Ifx_SReg_32Bit          | Byte, Half-Word, Word | 4 bytes (4H)                      
 * Ifx_Strict_16Bit                        | Half-Word             | 2 bytes (2H)                      
 * Ifx_Strict_32Bit                        | Word                  | 4 bytes (4H)                      
 * 
 * 
 * Alignment rules for peripheral space (From TriCoreTM TC1.6.2 core architecture manual, 2.2.1 Alignment Requirements)
 * Access type                             | Access size           | Required alignment of address in memory    
 * ----------------------------------------|-----------------------|-----------------------------------
 * Load, Store Data Register               | Byte (8-bits)         | Byte (1H)                         
 * Load, Store Data Register               | Half-Word (16-bits)   | 2 bytes (2H)                      
 * Load, Store Data Register               | Word (32-bits)        | 4 bytes (4H)                      
 * Load, Store Data Register               | Double-Word (64-bits) | 8 bytes (8H)                      
 * Load, Store Address Register            | Word                  | 4 bytes (4H)                      
 * Load, Store Address Register            | Double-Word           | 8 bytes (8H)                      
 * SWAP.W, LDMST, ST.T                     | Word                  | 4 bytes (4H)                      
 * CMPSWAP.W, SWAPMSK.W                    | Word                  | 4 bytes (4H)                      
 * Context Load / Store / Restore / Save   | 16 x 32-bit registers | Not Permitted                     
 * 
 * 
 * 
 *  Peripheral space : segment F and E (From TriCoreTM TC1.6.2 core architecture manual, 8.3.4 Default Memory types for all segments)
 */

#ifndef IFX_TYPESREG_H
#define IFX_TYPESREG_H 1
/******************************************************************************/
#if defined(__cplusplus)
#define IFX_BITFIELD_VOLATILE
#else
#define IFX_BITFIELD_VOLATILE volatile
#endif

#if defined(__TASKING__)
 #if defined(__CTC__) || defined(__CPTC__)
 #define Ifx_Strict_16Bit unsigned __sfrbit16
 #define Ifx_Strict_32Bit unsigned __sfrbit32
 #define Ifx_Strict_64Bit IFX_BITFIELD_VOLATILE unsigned long long /* compiler support needed */
 typedef unsigned __sfrbit32 Ifx_UReg_32Bit;
 #else
 #define Ifx_Strict_16Bit IFX_BITFIELD_VOLATILE unsigned short
 #define Ifx_Strict_32Bit IFX_BITFIELD_VOLATILE unsigned int
 #define Ifx_Strict_64Bit IFX_BITFIELD_VOLATILE unsigned long long
 typedef unsigned int   Ifx_UReg_32Bit;
 #endif
#elif defined(__GNUC__) && !defined(__CCAC__)
#define Ifx_Strict_16Bit IFX_BITFIELD_VOLATILE unsigned short
#define Ifx_Strict_32Bit IFX_BITFIELD_VOLATILE unsigned int
#define Ifx_Strict_64Bit IFX_BITFIELD_VOLATILE unsigned long long
typedef unsigned int   Ifx_UReg_32Bit;
#elif defined(__DCC__)
#define Ifx_Strict_16Bit unsigned short
#define Ifx_Strict_32Bit unsigned int
#define Ifx_Strict_64Bit IFX_BITFIELD_VOLATILE unsigned long long
typedef unsigned int   Ifx_UReg_32Bit;
#elif defined(__ghs__)
#define Ifx_Strict_16Bit IFX_BITFIELD_VOLATILE unsigned short
#define Ifx_Strict_32Bit IFX_BITFIELD_VOLATILE unsigned int
#define Ifx_Strict_64Bit IFX_BITFIELD_VOLATILE unsigned long long
typedef unsigned int   Ifx_UReg_32Bit;
#elif defined(__CCAC__)
#define Ifx_Strict_16Bit IFX_BITFIELD_VOLATILE unsigned short
#define Ifx_Strict_32Bit IFX_BITFIELD_VOLATILE unsigned int
#define Ifx_Strict_64Bit IFX_BITFIELD_VOLATILE unsigned long long
typedef unsigned int   Ifx_UReg_32Bit;
#endif
typedef unsigned char  Ifx_UReg_8Bit;
typedef unsigned short Ifx_UReg_16Bit;
typedef unsigned long long Ifx_UReg_64Bit;
typedef signed char    Ifx_SReg_8Bit;
typedef signed short   Ifx_SReg_16Bit;
typedef signed int     Ifx_SReg_32Bit;
typedef signed long long Ifx_SReg_64Bit;
 

/* Access types for registers */
#define __I /*!< defines 'read only' permissions */
#define __O /*!< defines 'write only' permissions */
#define __IO /*!< defines 'read / write' permissions */

/******************************************************************************/
#endif /* IFX_TYPESREG_H */

