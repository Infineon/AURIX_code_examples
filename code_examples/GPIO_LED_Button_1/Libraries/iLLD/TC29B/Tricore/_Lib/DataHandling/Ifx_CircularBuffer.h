/**
 * \file Ifx_CircularBuffer.h
 * \brief Circular buffer functions.
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
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
 * \defgroup IfxLld_lib_datahandling_circularbuffer Circular buffer
 * This module implements circular buffer functions.
 * \ingroup IfxLld_lib_datahandling
 *
 */

#ifndef IFX_CIRCULARBUFFER_H
#define IFX_CIRCULARBUFFER_H 1

//---------------------------------------------------------------------------
#include "Cpu/Std/IfxCpu_Intrinsics.h"
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
