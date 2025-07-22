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
/*! \file Ifx_bmpWriteB.c
 *
 * \brief writes bitmap image mono-chrome.
 *
 * This program writes a bmp-image in order to check its parameters.
 *
 */

#include "dsplib-internal.h"

#include <stdlib.h>
#include <stdio.h>

#define IFX_BMP_MAGIC 19778
#define IFX_BMP_CLRSIZE 2
#define IFX_BMP_PPM 1000

#define IFX_BMP_SIZE_BITMAPFILEHEADER 14
#define IFX_BMP_SIZE_BITMAPINFOHEADER 40
#define IFX_BMP_SIZE_COLORTABLEENATRY 4

static void
put_pixel (FILE * f, uint8 pix)
{
    uint8 data = (pix&128?1:0)
               | (pix&64?2:0)
               | (pix&32?4:0)
               | (pix&16?8:0)
               | (pix&8?16:0)
               | (pix&4?32:0)
               | (pix&2?64:0)
               | (pix&1?128:0);
    /*uint8 data = reverse_pixel[pix];*/
    if (EOF==fputc(data, f)) {
        perror ("error: writing uint8");
        exit (1);
    }
}

static void
put_uint8 (FILE * f, uint8 data)
{
    if (EOF==fputc(data, f)) {
        perror ("error: writing uint8");
        exit (1);
    }
}

static void
put_uint16 (FILE * f, uint16 data)
{
    if (1!=fwrite(&data,sizeof(uint16),1,f)) {
        perror ("error: writing uint16");
        exit (1);
    }
}

static void
put_uint32 (FILE * f, uint32 data)
{
    if (1!=fwrite(&data,sizeof(uint32),1,f)) {
        perror ("error: writing uint32");
        exit (1);
    }
}

static void
put_sint32 (FILE * f, sint32 data)
{
    if (1!=fwrite(&data,sizeof(sint32),1,f)) {
        perror ("error: writing sint32");
        exit (1);
    }
}

void
Ifx_bmpWriteB (FILE * f, uint8 * data, uint32 width, uint32 height)
{
    uint32 i,j;
    uint32 byte_width;

    /* align on 32-bit words */
    byte_width = ((width+31)>>3) & ~0x3;
    Ifx_assert (width <= 8*byte_width);
    Ifx_assert (byte_width < 8*(width+31));
    Ifx_assert ((byte_width & 0x3) == 0);

    /* write BITMAPFILEHEADER */
    put_uint16 (f, IFX_BMP_MAGIC);
    put_uint32 (f,
                IFX_BMP_SIZE_BITMAPFILEHEADER
                + IFX_BMP_SIZE_BITMAPINFOHEADER
                + IFX_BMP_CLRSIZE*IFX_BMP_SIZE_COLORTABLEENATRY
                + byte_width*height);
    put_uint32 (f, 0);
    put_uint32 (f,
                IFX_BMP_SIZE_BITMAPFILEHEADER
                + IFX_BMP_SIZE_BITMAPINFOHEADER
                + IFX_BMP_CLRSIZE*IFX_BMP_SIZE_COLORTABLEENATRY);

    /* write BITMAPINFOHEADER */
    put_uint32 (f, IFX_BMP_SIZE_BITMAPINFOHEADER);
    put_sint32 (f, width);
    put_sint32 (f, height);
    put_uint16 (f, 1); /* planes */
    put_uint16 (f, 1); /* bpp */
    put_uint32 (f, 0); /* compression */
    put_uint32 (f, byte_width*height); /* size of image data in bytes */
    put_sint32 (f, IFX_BMP_PPM);
    put_sint32 (f, IFX_BMP_PPM);
    put_uint32 (f, IFX_BMP_CLRSIZE);
    put_uint32 (f, IFX_BMP_CLRSIZE);

    /* write color table */
    for (i=0; i<IFX_BMP_CLRSIZE; i++) {
        put_uint8 (f, i?255:0); /* blue */
        put_uint8 (f, i?255:0); /* green */
        put_uint8 (f, i?255:0); /* red */
        put_uint8 (f, 0);
    }

    /* write image data */
    for (i=0; i<height; i++) {
        for (j=0; j<width; j+=8)
            put_pixel (f, data[i*((width+7)>>3)+(j>>3)]);
        for (; j<byte_width; j++)
            put_uint8 (f, 0);
    }

}

