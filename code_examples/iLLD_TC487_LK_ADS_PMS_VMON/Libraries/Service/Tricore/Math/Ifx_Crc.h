/**
 * \file Ifx_Crc.h
 * \brief CRC algorithm
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
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
 * \defgroup library_srvsw_sysse_math_crc CRC
 * This module implements CRC algorithm
 * \ingroup library_srvsw_sysse_math
 *
 */

#ifndef IFX_CRC_H
#define IFX_CRC_H 1
//---------------------------------------------------------------------------
#include "Ifx_Types.h"

#ifndef CRC_ENABLE_DPIPE
#define CRC_ENABLE_DPIPE 0
#endif

#if CRC_ENABLE_DPIPE
#include "IfxStdIf_DPipe.h"
#endif
//---------------------------------------------------------------------------
typedef struct
{
    sint32 order;
    uint32 polynom;
    sint32 refin;
    uint32 crchighbit;
    uint32 crcmask;
}Ifc_Crc_Table;
typedef struct
{
    Ifc_Crc_Table data;        /**< \brief CRC data, must be 1st member of the struct */
    uint8         crctab[256]; /**< \brief CRC Table, must be 2st member of the struct */
}Ifc_Crc_Table8;

typedef struct
{
    Ifc_Crc_Table data;        /**< \brief CRC data, must be 1st member of the struct */
    uint16        crctab[256]; /**< \brief CRC Table, must be 2st member of the struct */
}Ifc_Crc_Table16;

typedef struct
{
    Ifc_Crc_Table data;        /**< \brief CRC data, must be 1st member of the struct */
    uint32        crctab[256]; /**< \brief CRC Table, must be 2st member of the struct */
}Ifc_Crc_Table32;

typedef struct
{
    uint32               crcxor;
    sint32               refout;

    uint32               crcinit_direct;
    uint32               crcinit_nondirect;
    const Ifc_Crc_Table *table;
}Ifc_Crc;

/** \addtogroup library_srvsw_sysse_math_crc
 * \{ */
/**
 * \param direct [0,1] specifies the kind of algorithm: 1=direct, no augmented zero bits
 * \param driver pointer to the crc driver
 * \param table pointer to crc table
 * \param direct direct
 * \param crcinit is the initial CRC value belonging to that algorithm
 * \param crcxor is the final XOR value
 * \param refout [0,1] specifies if the CRC will be reflected before XOR
 * \param table pointer to the table: Ifc_Crc_Table8, Ifc_Crc_Table16, Ifc_Crc_Table32
 */
boolean Ifx_Crc_init(Ifc_Crc *driver, const Ifc_Crc_Table *table, sint32 direct, sint32 refout, uint32 crcinit, uint32 crcxor);
/**
 * \param table pointer to the crc table
 * \param order [1..32] is the CRC polynom order, counted without the leading '1' bit
 * \param polynom is the CRC polynom without leading '1' bit
 * \param refin [0,1] specifies if a data byte is reflected before processing (UART) or not
 */
boolean Ifx_Crc_createTable(Ifc_Crc_Table *table, sint32 order, uint32 polynom, sint32 refin);

#if CRC_ENABLE_DPIPE
boolean Ifx_Crc_Test(Ifc_Crc *driver, uint8 *string, uint32 length, IfxStdIf_DPipe *io);
void    Ifx_Crc_printTable(Ifc_Crc_Table *table, IfxStdIf_DPipe *io);
#endif
uint32 Ifx_Crc_tableFast(Ifc_Crc *driver, uint8 *p, uint32 len);
uint32 Ifx_Crc_table(Ifc_Crc *driver, uint8 *p, uint32 len);
uint32 Ifx_Crc_bitByBit(Ifc_Crc *driver, uint8 *p, uint32 len);
uint32 Ifx_Crc_bitByBitFast(Ifc_Crc *driver, uint8 *p, uint32 len);
/** \} */

//---------------------------------------------------------------------------
#endif  // IFX_CRC_H
