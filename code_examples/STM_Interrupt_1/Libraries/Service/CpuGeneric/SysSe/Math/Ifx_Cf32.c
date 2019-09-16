/**
 * \file Ifx_Cf32.c
 * \brief Floating point signal, vector, and matrix library
 *
 *
 * \version disabled
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
 */

#include "Ifx_Cf32.h"
#include <float.h>
#include <stdio.h>

#define ENDL "\r\n"

void CplxVecRst_f32(cfloat32 *X, short nX)
{
    for ( ; nX > 0; nX--)
    {
        X->real = X->imag = 0.0;
        X++;
    }
}


void CplxVecCpy_f32S(cfloat32 *X, short *S, short nS, short incrS)
{
    for ( ; nS > 0; nS--)
    {
        (*X).imag = 0.0;
        (*X).real = *(S);
        X++; S   += incrS;
    }
}


void CplxVecCpy_f32(cfloat32 *X, cfloat32 *S, short nS)
{
    for ( ; nS > 0; nS--)
    {
        *X = *S;
        X++; S++;
    }
}


float32 *CplxVecPwr_f32(cfloat32 *X, short nX)
{
    unsigned short i;
    float32       *r = (float32 *)X;

    for (i = 0; i < nX; i++)
    {
        *r = IFX_Cf32_dot(X);
        r++; X++;
    }

    return &r[-nX];
}


float32 *CplxVecMag_f32(cfloat32 *X, short nX)
{
    unsigned short i;
    float32       *r = (float32 *)X;

    for (i = 0; i < nX; i++)
    {
        *r = IFX_Cf32_mag(X);
        r++; X++;
    }

    return &r[-nX];
}


void CplxVecMul_f32(cfloat32 *X, const cfloat32 *mul, short nX)
{
    for ( ; nX > 0; nX--)
    {
        *X = IFX_Cf32_mul(X, mul);
        X++;
    }
}


void VecPwrdB_f32(float32 *X, short nX)
{
    unsigned short i;

    for (i = 0; i < nX; i++)
    {
        *X = (float32)20.0 * log10f(*X);
        X++;
    }
}


void VecPwrdB_SF(sint16 *R, float32 *X, short nX)
{
    unsigned short i;

    for (i = 0; i < nX; i++)
    {
        *R = (sint16)(20.0 * log10f(*X));
        R++; X++;
    }
}


float32 VecMaxIdx_f32(float32 *X, short nX, sint16 *minIdx, sint16 *maxIdx)
{
    float32        maxPeak = FLT_MIN;
    unsigned short m;

    for (m = 0; m < nX; m++)
    {
        if (*X > maxPeak)
        {
            maxPeak = *X;
            *minIdx = m;
        }

        if (*X >= maxPeak)
        {
            *maxIdx = m;
        }

        X++;
    }

    return maxPeak;
}


float32 VecMinIdx_f32(float32 *X, short nX, sint16 *minIdx, sint16 *maxIdx)
{
    float32 minPeak = FLT_MAX;
    short   m;

    for (m = 0; m < nX; m++)
    {
        if (*X < minPeak)
        {
            minPeak = *X;
            *minIdx = m;
        }

        if (*X <= minPeak)
        {
            *maxIdx = m;
        }

        X++;
    }

    return minPeak;
}


void VecOfs_f32(float32 *X, float32 offset, short nX)
{
    unsigned short i;

    for (i = 0; i < nX; i++)
    {
        *X -= offset;
        X++;
    }
}


void VecGain_f32(float32 *X, float32 gain, short nX)
{
    unsigned short i;

    for (i = 0; i < nX; i++)
    {
        *X = *X * gain;
        X++;
    }
}


float32 VecSum_f32(float32 *X, short nX)
{
    float32        sumX = 0;
    unsigned short i;

    for (i = 0; i < nX; i++)
    {
        sumX += *X;
        X++;
    }

    return sumX;
}


float32 VecAvg_f32(float32 *X, short nX)
{
    return VecSum_f32(X, nX) / nX;
}


float32 VecMax_f32(float32 *X, short nX)
{
    unsigned short i;
    float32        r = FLT_MIN;

    for (i = 0; i < nX; i++)
    {
        r = __maxf(r, *X);
        X++;
    }

    return r;
}


float32 VecMin_f32(float32 *X, short nX)
{
    unsigned short i;
    float32        r = FLT_MAX;

    for (i = 0; i < nX; i++)
    {
        r = __minf(r, *X);
        X++;
    }

    return r;
}


void VecHalfSwap_f32(float32 *X, short nX)
{
    unsigned short i;
    unsigned short half = nX / 2;
    float32       *F    = &X[half];

    for (i = 0; i < half; i++)
    {
        float32 tmp = *F;
        *F = *X;
        *X = tmp;
        F++; X++;
    }
}


/* NOTE:
 * (nX <= nW) && ((nW % nX) == 0) && ((nX % 2) == 0)
 * (symW != 0) when the window is symmetrical */
void VecWin_f32(float32 *X, const float32 *W, short nX, short nW, short incrX, short symW)
{
    short step = nW / nX;
    short i;

    if (symW != 0)
    {   /* symmetrical window, using half of the length */
        for (i = 0; i < nX / 2; i++)
        {
            *X = *X * *W;
            X  = &X[incrX];
            W  = &W[step];
        }

        W = &W[-step];

        for ( ; i < nX; i++)
        {
            *X = *X * *W;
            X  = &X[incrX];
            W  = &W[-step];
        }
    }
}


#ifdef __WIN32__

void DataF_printf(FILE *fp, pchar fileName, float32 *data, long nX, int enclosed)
{
    long i;

    if (fileName != NULL)
    {
        fp = fopen(fileName, "w+");
    }

    if (fp != NULL)
    {
        if (enclosed)
        {
            for (i = 0; i < nX; i++)
            {
                fprintf(fp, "_DATAF(%10.20f),"ENDL, *data);
                data = &data[1];
            }
        }
        else
        {
            for (i = 0; i < nX; i++)
            {
                fprintf(fp, "%10.20f,"ENDL, *data);
                data = &data[1];
            }
        }
    }

    if (fileName != NULL)
    {
        fclose(fp);
    }
}


void Cplx_f32_printf(FILE *fp, pchar fileName, cfloat32 *data, long nX, int encloseData)
{
    long i;

    if (fileName != NULL)
    {
        fp = fopen(fileName, "w+");
    }

    if (fp != NULL)
    {
        if (encloseData)
        {
            for (i = 0; i < nX; i++)
            {
                fprintf(fp, "{_DATAF(%10.20f), _DATAF(%10.20f)},"ENDL, data->real, data->imag);
                data = &data[1];
            }
        }
        else
        {
            for (i = 0; i < nX; i++)
            {
                fprintf(fp, "%10.20f, %10.20f"ENDL, data->real, data->imag);
                data = &data[1];
            }
        }
    }

    if (fileName != NULL)
    {
        fclose(fp);
    }
}


#endif
