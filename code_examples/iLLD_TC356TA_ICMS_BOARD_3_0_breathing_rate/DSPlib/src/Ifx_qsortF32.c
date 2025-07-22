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
/*! \file Ifx_qsortF32.c
 *
 * \brief Sort input vector values in increasing order using mergesort algorithm.
 * non recursive implementation
 *
 */

#include "dsplib.h"

/* for sorting additional vector y[] is required
 * constant size prevent malloc usage,
 * if required can be changed to any other MAXLEN value
 * alternative implementation (float32 *x,float32 *y, uint32 n)
 */
#define MAXLEN 400

void
Ifx_qsortF32 (float32 *x,uint32 n)
{
    float32 y[MAXLEN];
	uint32 rght,rend;
    uint32 i,j,m;
    sint32 k, left;

    for (k=1; k < n; k *= 2 ) {
        for (left=0; left+k < n; left += k*2 ) {
            rght = left + k;
            rend = rght + k;
            if (rend > n) rend = n;
            m = left; i = left; j = rght;
            while (i < rght && j < rend) {
                if (x[i] <= x[j]) {
                    y[m] = x[i]; i++;
                } else {
                    y[m] = x[j]; j++;
                }
                m++;
            }
            while (i < rght) {
                y[m]=x[i];
                i++; m++;
            }
            while (j < rend) {
                y[m]=x[j];
                j++; m++;
            }
            for (m=left; m < rend; m++) {
                x[m] = y[m];
            }
        }
    }
}
