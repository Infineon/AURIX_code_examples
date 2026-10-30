/**
 * \file Ifx_CircularBuffer.asm.c
 * \brief Circular buffer functions (assembler implementation).
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

#if !(IFX_CFG_CIRCULARBUFFER_C)

uint32 Ifx_CircularBuffer_get32(Ifx_CircularBuffer *buffer)
{
    uint32 data;

    __asm("	ld.da\ta14/a15,[%1]\n"      /* Get circular buffer state */
        "	ld.w\t%0,[a14/a15+c]\n"     /* Get the value from the buffer, and increment the buffer pointer */
        "	st.da\t[%1],a14/a15\n"      /* Store the new circular buffer state */
        : "=d" (data) : "a" (buffer) : "a14", "a15");

    return data;
}


uint16 Ifx_CircularBuffer_get16(Ifx_CircularBuffer *buffer)
{
    Ifx_SizeT data;

    __asm("	ld.da\ta14/a15,[%1]\n"      /* Get circular buffer state */
        "	ld.h\t%0,[a14/a15+c]\n"     /* Get the value from the buffer, and increment the buffer pointer */
        "	st.da\t[%1],a14/a15\n"      /* Store the new circular buffer state */
        : "=d" (data) : "a" (buffer) : "a14", "a15");

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
    __asm("	ld.da\ta14/a15,[%0]\n"      /* Get circular buffer state */
        "	st.w\t[a14/a15+c]0,%1\n"    /* Store the value to the buffer, and increment the buffer pointer */
        "	ld.w\t%1,[a14/a15+c]\n"     /* Read the value from the buffer, to get the buffer pointer incremented (bug workaround) */
        "	st.da\t[%0],a14/a15\n"      /* Store the new circular buffer state */
        :
        : "a" (buffer), "d" (data) : "a14", "a15");
}


void *Ifx_CircularBuffer_read8(Ifx_CircularBuffer *buffer, void *data, Ifx_SizeT count)
{
    count--;
    __asm("	mov.a\ta13,%3\n"                                   /* Get count value */
        "	ld.da\ta14/a15,[%1]\n"                             /* Get circular buffer state */
        "Ifx_CircularBuffer_read1:" "	ld.b\td15,[a14/a15+c]\n"/* read the value from the buffer, and increment the buffer pointer */
        "	st.b\t[%2+],d15\n"                                 /* Store value to the data buffer, and increment the pointer */
        "	loop\ta13,Ifx_CircularBuffer_read1\n"              /* loop */
        "	mov.d\t%0,a15\n"                                   /* Get the new index value */
        "	extr.u\t%0,%0,#0,#16\n": "=d" (buffer->index) : "a" (buffer), "a" (data), "d" (count) : "a13", "a14", "a15",
        "d15");

    return data;
}


void *Ifx_CircularBuffer_read32(Ifx_CircularBuffer *buffer, void *data, Ifx_SizeT count)
{
    count--;
    __asm("	mov.a\ta13,%3\n"                                   /* Get count value */
        "	ld.da\ta14/a15,[%1]\n"                             /* Get circular buffer state */
        "Ifx_CircularBuffer_read2:" "	ld.w\td15,[a14/a15+c]\n"/* read the value from the buffer, and increment the buffer pointer */
        "	st.w\t[%2+],d15\n"                                 /* Store value to the data buffer, and increment the pointer */
        "	loop\ta13,Ifx_CircularBuffer_read2\n"              /* loop */
        "	mov.d\t%0,a15\n"                                   /* Get the new index value */
        "	extr.u\t%0,%0,#0,#16\n": "=d" (buffer->index) : "a" (buffer), "a" (data), "d" (count) : "a13", "a14", "a15",
        "d15");

    return data;
}


const void *Ifx_CircularBuffer_write8(Ifx_CircularBuffer *buffer, const void *data, Ifx_SizeT count)
{
    count--;
    __asm("	mov.a\ta13,%3\n"                              /* Get count value */
        "	ld.da\ta14/a15,[%1]\n"                        /* Get circular buffer state */
        "Ifx_CircularBuffer_write1:" "	ld.b\td15,[%2+]\n"/* Get value from the data buffer, and increment the pointer */
        "	st.b\t[a14/a15+c]0,d15\n"                     /* Store the value to the buffer, and increment the buffer pointer */
        "	ld.b\td15,[a14/a15+c]\n"                      /* Read the value from the buffer, to get the buffer pointer incremented (bug workaround) */
        "	loop\ta13,Ifx_CircularBuffer_write1\n"        /* loop */
        "	mov.d\t%0,a15\n"                              /* Get the new index value */
        "	extr.u\t%0,%0,#0,#16\n": "=d" (buffer->index) : "a" (buffer), "a" (data), "d" (count) : "a13", "a14", "a15",
        "d15");

    return data;
}


const void *Ifx_CircularBuffer_write32(Ifx_CircularBuffer *buffer, const void *data, Ifx_SizeT count)
{
    count--;
    __asm("	mov.a\ta13,%3\n"                              /* Get count value */
        "	ld.da\ta14/a15,[%1]\n"                        /* Get circular buffer state */
        "Ifx_CircularBuffer_write2:" "	ld.w\td15,[%2+]\n"/* Get value from the data buffer, and increment the pointer */
        "	st.w\t[a14/a15+c]0,d15\n"                     /* Store the value to the buffer, and increment the buffer pointer */
        "	ld.w\td15,[a14/a15+c]\n"                      /* Read the value from the buffer, to get the buffer pointer incremented (bug workaround) */
        "	loop\ta13,Ifx_CircularBuffer_write2\n"        /* loop */
        "	mov.d\t%0,a15\n"                              /* Get the new index value */
        "	extr.u\t%0,%0,#0,#16\n": "=d" (buffer->index) : "a" (buffer), "a" (data), "d" (count) : "a13", "a14", "a15",
        "d15");

    return data;
}


#endif
