/**
 * \file Ifx_CircularBuffer.h
 * \brief Circular buffer functions.
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
 * \defgroup IfxLld_lib_datahandling_circularbuffer Circular buffer
 * This module implements circular buffer functions.
 * \ingroup IfxLld_lib_datahandling
 *
 */

#ifndef IFX_CIRCULARBUFFER_H
#define IFX_CIRCULARBUFFER_H 1

//---------------------------------------------------------------------------
#if !defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif
#if defined(IFX_ILLD_PPU_USAGE)
#include "Ppu/Std/IfxPpu_Intrinsics.h"
#endif
//---------------------------------------------------------------------------

#ifndef IFX_CFG_CIRCULARBUFFER_C
#define IFX_CFG_CIRCULARBUFFER_C (1)
#endif

/** \addtogroup IfxLld_lib_datahandling_circularbuffer
 * \{
 */
/** \brief Return the circular buffer 16 bit value, and post-increment the circular buffer pointer
 *
 * \param buffer Specifies circular buffer.
 *
 * \return Return the next circular buffer value.
 */
uint16 Ifx_CircularBuffer_get16(Ifx_CircularBuffer *buffer);

/** \brief Return the circular buffer 32 bit value, and post-increment the circular buffer pointer
 *
 * \param buffer Specifies circular buffer.
 *
 * \return Return the next circular buffer value.
 */
uint32 Ifx_CircularBuffer_get32(Ifx_CircularBuffer *buffer);

/** \brief Copy count bytes from the circular buffer to the data array
 *
 * \param buffer Specifies circular buffer.
 * \param data Specifies destination pointer.
 * \param count Specifies number of bytes to be copied. count MUST be >= 1.
 *
 * \return Returns the updated data pointer data = ((uint8*)data) + count
 */
void *Ifx_CircularBuffer_read8(Ifx_CircularBuffer *buffer, void *data, Ifx_SizeT count);

/** \brief Copy count 32 bit words from the circular buffer to the data array
 *
 * \param buffer Specifies circular buffer.
 * \param data Specifies destination pointer.
 * \param count Specifies number of 32 bit words to be copied. count MUST be >= 1.
 *
 * \return Returns the updated data pointer data = ((uint32*)data) + count
 */
void *Ifx_CircularBuffer_read32(Ifx_CircularBuffer *buffer, void *data, Ifx_SizeT count);

/** \brief Copy count bytes from the data array to the circular buffer
 *
 * \param buffer Specifies circular buffer.
 * \param data Specifies source pointer.
 * \param count Specifies number of bytes to be copied. count MUST be >= 1.
 *
 * \return Returns the updated data pointer data = ((uint8*)data) + count
 */
const void *Ifx_CircularBuffer_write8(Ifx_CircularBuffer *buffer, const void *data, Ifx_SizeT count);

/** \brief Copy count 32 bit words from the data array to the circular buffer
 *
 * \param buffer Specifies circular buffer.
 * \param data Specifies source pointer.
 * \param count Specifies number of 32 bit words to be copied. count MUST be >= 1.
 *
 * \return Returns the updated data pointer data = ((uint32*)data) + count
 */
const void *Ifx_CircularBuffer_write32(Ifx_CircularBuffer *buffer, const void *data, Ifx_SizeT count);

/** \} */
//---------------------------------------------------------------------------
#endif
