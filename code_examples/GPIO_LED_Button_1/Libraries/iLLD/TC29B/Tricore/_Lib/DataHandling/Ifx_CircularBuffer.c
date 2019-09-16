/**
 * \file Ifx_CircularBuffer.c
 * \brief Circular buffer functions in C language.
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
