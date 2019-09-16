/**
 * \file Ifx_CircularBuffer.asm.c
 * \brief Circular buffer functions (assembler implementation).
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
