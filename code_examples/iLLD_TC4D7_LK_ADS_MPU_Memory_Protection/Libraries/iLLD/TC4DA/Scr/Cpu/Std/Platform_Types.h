/*
 */
/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Platform_Types.h $                                         **
**                                                                           **
**  $CC VERSION :  $                                                  **
**                                                                           **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : File holding the definition of all the Platform types      **
**                as defined by Autosar                                      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*
 * File version information
 */
// #define PLATFORM_MAJOR_VERSION
// #define PLATFORM_MINOR_VERSION
// #define PLATFORM_PATCH_VERSION

/*
 * CPU register type width
 */
#define CPU_TYPE_8      8
#define CPU_TYPE_16     16
#define CPU_TYPE_32     32

/*
 * Bit order definition
 */
#define MSB_FIRST       0                   /* Big endian bit ordering        */
#define LSB_FIRST       1                   /* Little endian bit ordering     */

/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST 0                   /* Big endian byte ordering       */
#define LOW_BYTE_FIRST  1                   /* Little endian byte ordering    */

/*
 * Word order definition
 */
#define HIGH_WORD_FIRST 0                   /* Big endian word ordering       */
#define LOW_WORD_FIRST  1                   /* Little endian word ordering    */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*
 * AUTOSAR integer data types
 */
typedef signed char    sint8;               /*        -128 .. +127            */
typedef unsigned char  uint8;               /*           0 .. 255             */
typedef signed short   sint16;              /*      -32768 .. +32767          */
typedef unsigned short uint16;              /*           0 .. 65535           */
typedef signed long    sint32;              /* -2147483648 .. +2147483647     */
typedef unsigned long  uint32;              /*           0 .. 4294967295      */
typedef float          float32;
typedef double         float64;

typedef unsigned long  uint8_least;         /* At least 8 bit                 */
typedef unsigned long  uint16_least;        /* At least 16 bit                */
typedef unsigned long  uint32_least;        /* At least 32 bit                */
typedef signed long    sint8_least;         /* At least 7 bit + 1 bit sign    */
typedef signed long    sint16_least;        /* At least 15 bit + 1 bit sign   */
typedef signed long    sint32_least;        /* At least 31 bit + 1 bit sign   */

typedef unsigned char  boolean;             /* for use with TRUE/FALSE        */

#ifndef TRUE                                /* conditional check */
#define TRUE  1
#endif

#ifndef FALSE                                            /* conditional check */
#define FALSE 0
#endif

/* posix conform: osdSuppressPosixTypes of Operating system */
#ifdef osdSuppressPosixTypes
typedef          char  int8;                  /*        -128 .. +127            */
typedef          short int16;                 /*      -32768 .. +32767          */
typedef          long  int32;                 /* -2147483648 .. +2147483647     */
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* PLATFORM_TYPES_H */
