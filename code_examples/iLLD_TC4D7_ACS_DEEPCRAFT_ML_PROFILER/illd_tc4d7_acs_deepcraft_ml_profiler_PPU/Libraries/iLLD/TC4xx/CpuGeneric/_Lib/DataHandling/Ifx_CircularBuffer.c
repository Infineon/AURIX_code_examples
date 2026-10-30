/**
 * \file Ifx_CircularBuffer.c
 * \brief Circular buffer functions in C language.
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
 */

#include "Ifx_CircularBuffer.h"

#if (IFX_CFG_CIRCULARBUFFER_C)

uint32 Ifx_CircularBuffer_get32(Ifx_CircularBuffer *buffer)
{
    uint32 data = ((uint32 *)buffer->base)[buffer->index];

    buffer->index += 4;

    if (buffer->index >= buffer->length)
    {
        buffer->index = 0;
    }

    return data;
}


uint16 Ifx_CircularBuffer_get16(Ifx_CircularBuffer *buffer)
{
    uint16 data = ((uint16 *)buffer->base)[buffer->index];

    buffer->index += 2;

    if (buffer->index >= buffer->length)
    {
        buffer->index = 0;
    }

    return data;
}


/** \brief Add a 32 bit value to the circular buffer, and post-increment the circular buffer pointer
 *
 * \param buffer Specifies circular buffer.
 * \param data Specifies value to be added to the buffer.
 *
 * \return None.
 */
void Ifx_CircularBuffer_addDataIncr(Ifx_CircularBuffer *buffer, uint32 data)
{
    ((uint32 *)buffer->base)[buffer->index] = data;
    buffer->index                          += 4;

    if (buffer->index >= buffer->length)
    {
        buffer->index = 0;
    }
}


void *Ifx_CircularBuffer_read8(Ifx_CircularBuffer *buffer, void *data, Ifx_SizeT count)
{
    uint8 *Dest = (uint8 *)data;

    do
    {
        count--;
        *Dest = ((uint8 *)buffer->base)[buffer->index];
        Dest  = &Dest[1];
        buffer->index++;

        if (buffer->index >= buffer->length)
        {
            buffer->index = 0;
        }
    } while (count > 0);

    return Dest;
}


void *Ifx_CircularBuffer_read32(Ifx_CircularBuffer *buffer, void *data, Ifx_SizeT count)
{
    uint32 *Dest = (uint32 *)data;
    uint8  *base = buffer->base;

    do
    {
        *Dest         = *((uint32 *)(&base[buffer->index]));
        Dest          = &Dest[1];
        buffer->index = buffer->index + 4;

        if (buffer->index >= buffer->length)
        {
            buffer->index = 0;
        }

        count--;
    } while (count > 0);

    return Dest;
}


const void *Ifx_CircularBuffer_write8(Ifx_CircularBuffer *buffer, const void *data, Ifx_SizeT count)
{
    const uint8 *source = (const uint8 *)data;

    do
    {
        count--;
        ((uint8 *)buffer->base)[buffer->index] = *source;
        source                                 = &source[1];
        buffer->index++;

        if (buffer->index >= buffer->length)
        {
            buffer->index = 0;
        }
    } while (count > 0);

    return source;
}


const void *Ifx_CircularBuffer_write32(Ifx_CircularBuffer *buffer, const void *data, Ifx_SizeT count)
{
    const uint32 *source = (const uint32 *)data;
    uint8        *base   = buffer->base;

    do
    {
        *((uint32 *)(&base[buffer->index])) = *source;
        source                              = &source[1];
        buffer->index                       = buffer->index + 4;

        if (buffer->index >= buffer->length)
        {
            buffer->index = 0;
        }

        count--;
    } while (count > 0);

    return source;
}


#endif
