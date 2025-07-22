/*****************************************************************************
*
* Copyright (C) 2022 Infineon Technologies AG. All rights reserved.
*
* Infineon Technologies AG (INFINEON) is supplying this file for use
* exclusively with Infineon's microcontroller products. This file can be freely
* distributed within development tools and software supporting such microcontroller
* products.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL, 
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
******************************************************************************/
/*! \file Ifx_bmpReadQ15.c
 *
 * \brief reads bitmap image into Q15 vector.
 *
 * This program reads a bmp-image in order to check its parameters.
 *
 */

#include "dsplib-internal.h"

#include <stdlib.h>
#include <stdio.h>

#define IFX_BMP_MAGIC 19778
#define IFX_BMP_CLRSIZE 256
#define IFX_BMP_PPM 1000

#define IFX_BMP_SIZE_BITMAPFILEHEADER 14
#define IFX_BMP_SIZE_BITMAPINFOHEADER 40
#define IFX_BMP_SIZE_COLORTABLEENATRY 4

static void check_uint8 (FILE * f, uint8 ref)
{
    if (ref!=fgetc(f)) {
        perror ("error: reading uint8 in function check_uint8");
        exit (1);
    }
}

static void check_uint16 (FILE * f, uint16 ref)
{
    uint16 data;
    if (1!=fread(&data,sizeof(uint16),1,f)) {
        perror ("error: reading uint16 in function check_uint16");
        exit (1);
    }
    else if (ref!=data) {
        perror ("error: data does not equal ref in function check_uint16");
        printf ("data: %d, ref: %d\n", data, ref);
        exit (1);
    }
}

static void check_uint32 (FILE * f, uint32 ref)
{
    uint32 data;
    if (1!=fread(&data,sizeof(uint32),1,f)) {
        perror ("error: reading uint32 in function check_uint32");
        exit (1);
    }
    else if (ref!=data) {
        perror ("error: data does not equal ref in function check_uint32");
        printf ("data: %d, ref: %d\n", data, ref);
        exit (1);
    }
}

static uint8 read_uint8 (FILE * f)
{
    uint8 data;
    if (1!=fread(&data,sizeof(uint8),1,f)) {
        uint32 pos = ftell (f);
        perror ("error: reading uint8 in function read_uint8");
        printf ("Position: %d\n", pos);
        exit (1);
    }
    return data;
}

static uint32 read_uint32 (FILE * f)
{
    uint32 data;
    if (1!=fread(&data,sizeof(uint32),1,f)) {
        uint32 pos = ftell (f);
        perror ("error: reading uint32 in function read_uint32");
        printf ("Position: %d\n", pos);
        exit (1);
    }
    return data;
}

static sint32 read_sint32 (FILE * f)
{
    sint32 data;
    if (1!=fread(&data,sizeof(sint32),1,f)) {
        uint32 pos = ftell (f);
        perror ("error: reading sint32 in function read_sint32");
        printf ("Position: %d\n", pos);
        exit (1);
    }
    return data;
}

static void ignore_uint32 (FILE * f)
{
    uint32 data;
    if (1!=fread(&data,sizeof(uint32),1,f)) {
        uint32 pos = ftell (f);
        perror ("error: reading uint32 in function ignore_uint32");
        printf ("Position: %d\n", pos);
        exit (1);
    }
}

static void ignore_sint32 (FILE * f)
{
    sint32 data;
    if (1!=fread(&data,sizeof(sint32),1,f)) {
        uint32 pos = ftell (f);
        perror ("error: reading sint32 in function ignore_sint32");
        printf ("Position: %d\n", pos);
        exit (1);
    }
}

void Ifx_bmpReadQ15 (FILE * f, sint16 ** data, uint32 * width, uint32 * height)
{
    uint32 i, j, byte_width;
    uint32 total_size;
    uint32 data_offset;
    uint32 image_size;

    /* read BITMAPFILEHEADER */
    check_uint16 (f, IFX_BMP_MAGIC);
    total_size = read_uint32 (f);
    ignore_uint32 (f);
    data_offset = read_uint32 (f);

    /* read BITMAPINFOHEADER */
    check_uint32 (f, IFX_BMP_SIZE_BITMAPINFOHEADER);
    *width = read_sint32 (f);
    *height = read_sint32 (f);
    check_uint16 (f, 1); /* planes */
    check_uint16 (f, 8); /* bpp */
    check_uint32 (f, 0); /* compression */
    image_size = read_uint32 (f);
    ignore_sint32 (f);
    ignore_sint32 (f);
    check_uint32 (f, IFX_BMP_CLRSIZE);
    check_uint32 (f, IFX_BMP_CLRSIZE);

    /* read color table */
    for (i=0; i<IFX_BMP_CLRSIZE; i++) {
        check_uint8 (f, i); /* blue */
        check_uint8 (f, i); /* green */
        check_uint8 (f, i); /* red */
        check_uint8 (f, 0);
    }

    /* reconstruct image geometry */
    byte_width = (*width+3) & ~0x3;
    Ifx_assert(*width <= byte_width);
    Ifx_assert(byte_width < *width+4);
    Ifx_assert((byte_width & 0x3) == 0);
    Ifx_assert(byte_width**height<=image_size);

    /* read image data */
    *data = (sint16*) malloc (sizeof(sint16)**width**height);
    fseek (f, SEEK_SET, data_offset);
    for (i=0; i<*height; i++) {
        for (j=0; j<*width; j++)
            (*data)[i**width+j] = read_uint8 (f);
        for (; j<byte_width; j++)
            check_uint8 (f, 0);           /* Why 0? */
    }

    Ifx_assert((uint32)ftell (f) <= total_size);
}
