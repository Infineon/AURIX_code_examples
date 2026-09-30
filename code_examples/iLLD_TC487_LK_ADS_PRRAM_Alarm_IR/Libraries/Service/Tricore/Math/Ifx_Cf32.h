/**
 * \file Ifx_Cf32.h
 * \brief Floating point signal, vector, and matrix library
 *
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
 * \defgroup library_srvsw_sysse_math_cf32 Floating point signal, vector, and matrix library
 * \ingroup library_srvsw_sysse_math_f32
 */

#ifndef IFX_CF32_H
#define IFX_CF32_H 1

#if defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxPpu_Intrinsics.h"
#else
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif
#include <math.h>

#define _DATAF(val) ((float32)(val))

/* Complex Arithmetic --------------------------------------------------------*/
IFX_INLINE cfloat32 IFX_Cf32_exp(const cfloat32 *c)
{
    float32  f = (float32)expf(c->real);
    cfloat32 R;
    R.real = f * (float32)cosf(c->imag);
    R.imag = f * (float32)sinf(c->imag);
    return R;
}


IFX_INLINE cfloat32 IFX_Cf32_mul(const cfloat32 *a, const cfloat32 *b)
{
    cfloat32 R;
    R.real = (a->real * b->real) - (a->imag * b->imag);
    R.imag = (a->imag * b->real) + (a->real * b->imag);
    return R;
}


IFX_INLINE cfloat32 IFX_Cf32_amp(const cfloat32 *a, float32 gain)
{
    cfloat32 R;
    R.real = a->real * gain;
    R.imag = a->imag * gain;
    return R;
}


IFX_INLINE float32 IFX_Cf32_dot(const cfloat32 *b)
{
    return (b->real * b->real) + (b->imag * b->imag);
}


IFX_INLINE float32 IFX_Cf32_mag(const cfloat32 *c)
{
    return (float32)sqrtf(IFX_Cf32_dot(c));
}


IFX_INLINE cfloat32 IFX_Cf32_div(const cfloat32 *a, const cfloat32 *b)
{
    float32  denom = IFX_Cf32_dot(b);
    cfloat32 R;
    R.real = ((a->real * b->real) + (a->imag * b->imag)) / denom;
    R.imag = ((a->imag * b->real) - (a->real * b->imag)) / denom;
    return R;
}


IFX_INLINE cfloat32 IFX_Cf32_add(const cfloat32 *a, const cfloat32 *b)
{
    cfloat32 R;
    R.real = (a->real + b->real);
    R.imag = (a->imag + b->imag);
    return R;
}


IFX_INLINE cfloat32 IFX_Cf32_sub(const cfloat32 *a, const cfloat32 *b)
{
    cfloat32 R;
    R.real = (a->real - b->real);
    R.imag = (a->imag - b->imag);
    return R;
}


IFX_INLINE void IFX_Cf32_set(cfloat32 *a, float32 re, float32 im)
{
    a->real = re;
    a->imag = im;
}


IFX_INLINE void IFX_Cf32_reset(cfloat32 *a)
{
    IFX_Cf32_set(a, 0.0, 0.0);
}


IFX_INLINE cfloat32 IFX_Cf32_saturate(cfloat32 *a, float32 *ampl, float32 limit)
{
    cfloat32 R = *a;
    *ampl = IFX_Cf32_mag(a);

    if (*ampl > limit)
    {
        float32 scale = limit / *ampl;
        R.imag = R.imag * scale;
        R.real = R.real * scale;
    }

    return R;
}


IFX_EXTERN void     CplxVecCpy_f32S(cfloat32 *X, short *S, short nS, short incrS);
IFX_EXTERN void     CplxVecRst_f32(cfloat32 *X, short nX);
IFX_EXTERN void     CplxVecCpy_f32(cfloat32 *X, cfloat32 *S, short nS);
IFX_EXTERN float32 *CplxVecPwr_f32(cfloat32 *X, short nX);
IFX_EXTERN float32 *CplxVecMag_f32(cfloat32 *X, short nX);
IFX_EXTERN void     CplxVecMul_f32(cfloat32 *X, const cfloat32 *mul, short nX);

/* Vector Operation ----------------------------------------------------------*/

IFX_EXTERN void    VecWin_f32(float32 *X, const float32 *W, short nX, short nW, short incrX, short symW);
IFX_EXTERN void    VecPwrdB_f32(float32 *X, short nX);
IFX_EXTERN void    VecPwrdB_SF(sint16 *R, float32 *X, short nX);
IFX_EXTERN void    VecGain_f32(float32 *X, float32 gain, short nX);
IFX_EXTERN void    VecOfs_f32(float32 *X, float32 offset, short nX);
IFX_EXTERN float32 VecSum_f32(float32 *X, short nX);
IFX_EXTERN float32 VecAvg_f32(float32 *X, short nX);
IFX_EXTERN float32 VecMax_f32(float32 *X, short nX);
IFX_EXTERN float32 VecMin_f32(float32 *X, short nX);
IFX_EXTERN float32 VecMinIdx_f32(float32 *X, short nX, sint16 *minIdx, sint16 *maxIdx);
IFX_EXTERN float32 VecMaxIdx_f32(float32 *X, short nX, sint16 *minIdx, sint16 *maxIdx);
IFX_EXTERN void    VecHalfSwap_f32(float32 *X, short nX);

/* Helper functions ----------------------------------------------------------*/
#ifdef __WIN32__
#include <stdio.h>
void Cplx_f32_printf(FILE *fp, pchar fileName, cfloat32 *data, long nX, int encloseData);
#else
#define Cplx_f32_printf(...)
#endif

#endif /* IFX_CF32_H */
