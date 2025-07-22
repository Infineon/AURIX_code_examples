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
/*! \file Ifx_mtxSvdRealF32.c
 *
 * \brief SVD: Singular Value Decomposition
 *
 * Calculates the Singular Value Decomposition of a Matrix C (not necessarily regular, complex or real).
 * C = U * SIGMA * V* .
 * U is a unitary matrix (=square complex matrix whose columns are orthogonal to each other).
 * SIGMA is a non-square, thus rectangular, diagonal matrix. The diagonal entries are the singular values of the matrix.
 * is the conjugate transpose of a real or complex unitary matrix V.
 *
 * The algorithm used here is based on:
 * Wilkinson and Reinsch: Handbook of Automatic Compuation,
 *   Linear Algebra, Vol. II, Springer Verlag, New York, 1971
 *   Chapter I.10 by Golub and Reinsch
 * and on:
 * Press and Flannery and Teukolsky and Vetterling:
 *   Numerical Recipes in C, 1st edition, Cambridge University Press,
 *   Cambridge, 1988
 */
#include "dsplib-internal.h"

/* part1 of option for selecting IFX_ALLOC_TMP_VECTOR
 * or allocating on stack (MEMALLOC 0)
 */
#define MAXCOL 256
#define MEMALOC 0

#if _MSC_VER
#pragma warning( once : 4018 )
#endif /* _MSC_VER */

static float32
pythag(float32 a, float32 b, enum Ifx_mode mode)
{
    float32 absa,absb;
    absa=IFX_ABS_F32(a);
    absb=IFX_ABS_F32(b);
    if (absa > absb) return absa*Ifx_sqrtF32(1.0f+IFX_SQR_F32(absb/absa),mode);
    else return (absb == 0.0f ? 0.0f : absb*Ifx_sqrtF32(1.0f+IFX_SQR_F32(absa/absb),mode));
}

void
Ifx_mtxSvdRealF32 (struct Ifx_mtxSvdRealF32State * state)
{
    enum Ifx_mode mode = state->mode;
    float32 * a = state->a;
    float32 * w = state->w;
    float32 * v = state->v;
    uint32 m = state->m;
    uint32 n = state->n;

    sint32 flag,i,its,j,jj,k,l=0,nm;
    float32 anorm,c,f,g,h,s,scale,x,y,z;

    /* part2 of option for selecting IFX_ALLOC_TMP_VECTOR
     * or allocating on stack (MEMALLOC 0)
     */
#if MEMALOC
    IFX_ALLOC_TMP_VECTOR(float32,rv1,n);
#else
    float32 rv1[MAXCOL];
#endif

    /* fill matrix with zeros otherwise */
    Ifx_assert (m>=n);

    g=scale=anorm=0.0f;
    for (i=0; i<n; i++) {
        l=i+1;
        rv1[i]=scale*g;
        g=s=scale=0.0f;
        if (i < m) {
            for (k=i;k<m;k++)
                scale += IFX_ABS_F32(a[k*n+i]);
            if (scale!=0.0f) {
                for (k=i;k<m;k++) {
                    a[k*n+i] /= scale;
                    s += a[k*n+i]*a[k*n+i];
                }
                f=a[i*n+i];
                g = -IFX_COPYSIGN_F32(Ifx_sqrtF32(s,mode),f);
                h=f*g-s;
                a[i*n+i]=f-g;
                for (j=l;j<n;j++) {
                    for (s=0.0f,k=i;k<m;k++) s += a[k*n+i]*a[k*n+j];
                    f=s/h;
                    for (k=i;k<m;k++) a[k*n+j] += f*a[k*n+i];
                }
                for (k=i;k<m;k++) a[k*n+i] *= scale;
            }
        }
        w[i]=scale *g;
        g=s=scale=0.0f;
        if (i <= m && i != n) {
            for (k=l;k<n;k++) scale += IFX_ABS_F32(a[i*n+k]);
            if (scale) {
                for (k=l;k<n;k++) {
                    a[i*n+k] /= scale;
                    s += a[i*n+k]*a[i*n+k];
                }
                f=a[i*n+l];
                g = -IFX_COPYSIGN_F32(Ifx_sqrtF32(s,mode),f);
                h=f*g-s;
                a[i*n+l]=f-g;
                for (k=l;k<n;k++) rv1[k]=a[i*n+k]/h;
                for (j=l;j<m;j++) {
                    for (s=0.0f,k=l;k<n;k++) s += a[j*n+k]*a[i*n+k];
                    for (k=l;k<n;k++) a[j*n+k] += s*rv1[k];
                }
                for (k=l;k<n;k++) a[i*n+k] *= scale;
            }
        }
        anorm=IFX_MAX_F32(anorm,(IFX_ABS_F32(w[i])+IFX_ABS_F32(rv1[i])));
    }
    for (i=n-1;i>=0;i--) {
        if (i < n) {
            if (g) {
                for (j=l;j<n;j++)
                    v[j*n+i]=(a[i*n+j]/a[i*n+l])/g;
                for (j=l;j<n;j++) {
                    for (s=0.0f,k=l;k<n;k++) s += a[i*n+k]*v[k*n+j];
                    for (k=l;k<n;k++) v[k*n+j] += s*v[k*n+i];
                }
            }
            for (j=l;j<n;j++) v[i*n+j]=v[j*n+i]=0.0f;
        }
        v[i*n+i]=1.0f;
        g=rv1[i];
        l=i;
    }
    for (i=n-1;i>=0;i--) {
        l=i+1;
        g=w[i];
        for (j=l;j<n;j++) a[i*n+j]=0.0f;
        if (g) {
            g=1.0f/g;
            for (j=l;j<n;j++) {
                for (s=0.0f,k=l;k<m;k++) s += a[k*n+i]*a[k*n+j];
                f=(s/a[i*n+i])*g;
                for (k=i;k<m;k++) a[k*n+j] += f*a[k*n+i];
            }
            for (j=i;j<m;j++) a[j*n+i] *= g;
        } else for (j=i;j<m;j++) a[j*n+i]=0.0f;
        ++a[i*n+i];
    }
    for (k=n-1;k>=0;k--) {
        for (its=1;its<=30;its++) {
            flag=1;
            for (l=k;l>=0;l--) {
                nm=l-1;
                if ((float32)(IFX_ABS_F32(rv1[l])+anorm) == anorm) {
                    flag=0;
                    break;
                }
                if ((float32)(IFX_ABS_F32(w[nm])+anorm) == anorm) break;
            }
            if (flag) {
                c=0.0f;
                s=1.0f;
                for (i=l;i<=k;i++) {
                    f=s*rv1[i];
                    rv1[i]=c*rv1[i];
                    if ((float32)(IFX_ABS_F32(f)+anorm) == anorm) break;
                    g=w[i];
                    h=pythag(f,g,mode);
                    w[i]=h;
                    h=1.0f/h;
                    c=g*h;
                    s = -f*h;
                    for (j=0;j<m;j++) {
                        y=a[j*n+nm];
                        z=a[j*n+i];
                        a[j*n+nm]=y*c+z*s;
                        a[j*n+i]=z*c-y*s;
                    }
                }
            }
            z=w[k];
            if (l == k) {
                if (z < 0.0f) {
                    w[k] = -z;
                    for (j=0;j<n;j++) v[j*n+k] = -v[j*n+k];
                }
                break;
            }
            if (its == 30) {
                Ifx_error (IFX_ERR_ERROR, "svd does not converge after %d iterations\n", its);
                return;
            }
            x=w[l];
            nm=k-1;
            y=w[nm];
            g=rv1[nm];
            h=rv1[k];
            f=((y-z)*(y+z)+(g-h)*(g+h))/(2.0f*h*y);
            g=pythag(f,1.0f,mode);
            f=((x-z)*(x+z)+h*((y/(f+IFX_COPYSIGN_F32(g,f)))-h))/x;
            c=s=1.0f;
            for (j=l;j<=nm;j++) {
                i=j+1;
                g=rv1[i];
                y=w[i];
                h=s*g;
                g=c*g;
                z=pythag(f,h,mode);
                rv1[j]=z;
                c=f/z;
                s=h/z;
                f=x*c+g*s;
                g = g*c-x*s;
                h=y*s;
                y *= c;
                for (jj=0;jj<n;jj++) {
                    x=v[jj*n+j];
                    z=v[jj*n+i];
                    v[jj*n+j]=x*c+z*s;
                    v[jj*n+i]=z*c-x*s;
                }
                z=pythag(f,h,mode);
                w[j]=z;
                if (z) {
                    z=1.0f/z;
                    c=f*z;
                    s=h*z;
                }
                f=c*g+s*y;
                x=c*y-s*g;
                for (jj=0;jj<m;jj++) {
                    y=a[jj*n+j];
                    z=a[jj*n+i];
                    a[jj*n+j]=y*c+z*s;
                    a[jj*n+i]=z*c-y*s;
                }
            }
            rv1[l]=0.0f;
            rv1[k]=f;
            w[k]=x;
        }
    }
#if MEMALOC
    IFX_FREE_TMP_VECTOR(float32,rv1,n);
#endif
}
