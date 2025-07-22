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
/*! \file Ifx_mtxSvdComplexF32.c
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

#if _MSC_VER
#pragma warning( once : 4018 )
#endif /* _MSC_VER */

void
Ifx_mtxSvdComplexF32 (struct Ifx_mtxSvdComplexF32State * state)
{
    enum Ifx_mode mode = state->mode;
    cfloat32 * a = state->a;
    float32 * s = state->w;
    cfloat32 * v = state->v;
    uint32 m = state->m;
    uint32 n = state->n;

    sint32 i, j, k, k1, L, L1, nM1, np,nu,nv,p;
    float32 sn, tol, w, x, y, z;
    float32 cs, eps, eta, f, g, h;
    cfloat32 q,qtmp;

    float32 lotmp;  // temporary variable for local optimization
    uint32  loti,loti2;   // temporary variables for local optimization of indexes

    /* part2 of option for selecting IFX_ALLOC_TMP_VECTOR
     * or allocating on stack (MEMALLOC 0)
     */
    IFX_ALLOC_TMP_VECTOR(float32,b,n);
    IFX_ALLOC_TMP_VECTOR(float32,c,n);
    IFX_ALLOC_TMP_VECTOR(float32,t,n);
    IFX_ALLOC_TMP_VECTOR(cfloat32,u,m*n);

    /* fill matrix with zeros otherwise */
    Ifx_assert (m>=n);

    p=0;   // Number of additional columns (see ALGORITM 358 in Fortran:
           //... "the number of vectors, stored in A(*,N+1:N+P),
           // to which the transformation U* should be applied."
    nu=n;
    nv=n;
    eta = 1.5E-07F;			/* eta = the relative machine precision */
    tol = 1.5E-31F;			/* tol = the smallest normalized positive number, divided by eta */
    np = n + p;
    nM1 = n - 1;
    L = 0;
    /*
      HOUSEHOLDER REDUCTION
    */
    c[0] = 0.0F;
    k = 0;
    while (1)
	{
            k1 = k + 1;
            /*
              ELIMINATION OF a[i][k], i = k, ..., m-1
            */
            z = 0.0F;
            for (i = k; i < m; i++)
                z += IFX_SQR_ABS_CF32(a[i*n+k]);                      // initially norm(a[i][k]);... please see comments C3!!!
            b[k] = 0.0F;
            if (z > tol) {
                z = Ifx_sqrtF32(z,mode);
                b[k] = z;
                loti=k*n+k;
                w = IFX_ABS_CF32(a[loti]);
                IFX_INIT_CF32(q,1.0F,0.0F);  // please see comment C4... initially: q = complex(1.0F, 0.0F);
                if (w != 0.0F) {
                    IFX_S_CDIV_F32(q,a[loti],w);  // please see comment C5... initially: q = a[k][k] / w;
                }
                lotmp=z+w;
                IFX_S_CMUL_F32(a[loti],q,lotmp);  // initially: a[k][k] = q * (z + w);
                if (k != np - 1) {
                    for (j = k1; j < np; j++) {
                        IFX_INIT_CF32(q,0.0F,0.0F);  // initially: q = complex(0.0F, 0.0F);
                        for (i = k; i < m; i++) {
                            loti=i*n+k;
                            loti2=i*n+j;
                            IFX_CMUL_CONJ_F32(qtmp,a[loti],a[loti2]);  // please see comment C6... initially: q += conj(a[i][k]) * a[i][j];
                            IFX_CADD_F32(q,q,qtmp);    // the addition can be made in the same place (i.e. q.real=q.real+...)
                        }
                        // initially q /= z * (z + w);
                        lotmp=z*(z+w);
                        IFX_S_CDIV_F32(q,q,lotmp);  // the division can be done in the same place (i.e. q.real +...)
                        for (i = k; i < m; i++) {
                            // initially: a[i][j] -= q * a[i][k];
                            loti=i*n+k;
                            IFX_CMUL_F32(qtmp,q,a[loti]);
                            loti=i*n+j;
                            IFX_CSUB_F32(a[loti],a[loti],qtmp);
                        }
                    }
                }
                /*
                  PHASE TRANSFORMATION
                */
                // initially: q = -conj(a[k][k]) / abs(a[k][k]);
                loti=k*n+k;
                IFX_INIT_CF32(qtmp,-a[loti].real,a[loti].imag); // qtmp=-conj(a[k][k])
                lotmp=IFX_ABS_CF32(a[loti]);
                IFX_S_CDIV_F32(q,qtmp,lotmp);
                for (j = k1; j < np; j++) {
                    // initially: a[k][j] *= q;  !!! it can't be done in the same place
                    loti=k*n+j;
                    IFX_CMUL_F32(qtmp,a[loti],q);
                    IFX_INIT_CF32(a[loti],qtmp.real,qtmp.imag);
                }
            }
            /*
              ELIMINATION OF a(k][j], j = k+2, ..., n-1
            */
            if (k == nM1) break;
            z = 0.0F;
            for (j = k1; j < n; j++)
                z += IFX_SQR_ABS_CF32(a[k*n+j]);    // initially: norm(a[k][j]);
            c[k1] = 0.0F;
            if (z > tol) {
                z = Ifx_sqrtF32(z,mode);
                c[k1] = z;
                w = IFX_ABS_CF32(a[k*n+k1]);
                IFX_INIT_CF32(q,1.0F,0.0F);
                // initially:if (w != 0.0F) q = a[k][k1] / w;
                loti=k*n+k1;
                if (w != 0.0F) {
                    IFX_S_CDIV_F32(q,a[loti],w);
                }
                // initially:a[k][k1] = q * (z + w);
                lotmp=z+w;
                IFX_S_CMUL_F32(a[loti],q,lotmp);
                for (i = k1; i < m; i++) {
                    /*q = complex(0.0F, 0.0F);
                      for (j = k1; j < n; j++)
                      q += conj(a[k][j]) * a[i][j];
                      q /= z * (z + w);
                      for (j = k1; j < n; j++)
                      a[i][j] -= q * a[k][j];*/
                    IFX_INIT_CF32(q,0.0F,0.0F);
                    for (j = k1; j < n; j++) {
                        loti=k*n+j;
                        loti2=i*n+j;
                        IFX_CMUL_CONJ_F32(qtmp,a[loti],a[loti2]);
                        IFX_CADD_F32(q,q,qtmp);
                    }
                    lotmp=z*(z+w);
                    IFX_S_CDIV_F32(q,q,lotmp);
                    for (j = k1; j < n; j++) {
                        loti=k*n+j;
                        IFX_CMUL_F32(qtmp,q,a[loti]);
                        loti=i*n+j;
                        IFX_CSUB_F32(a[loti],a[loti],qtmp);
                    }
                }
                /*
                  PHASE TRANSFORMATION
                */
                /*q = -conj(a[k][k1]) / abs(a[k][k1]);
                  for (i = k1; i < m; i++)
                  a[i][k1] *= q; */
                loti=k*n+k1;
                IFX_INIT_CF32(qtmp,-a[loti].real,a[loti].imag);
                lotmp=IFX_ABS_CF32(a[loti]);
                IFX_S_CDIV_F32(q,qtmp,lotmp);
                for (i = k1; i < m; i++) {
                    loti=i*n+k1;
                    IFX_CMUL_F32(qtmp,a[loti],q);
                    IFX_INIT_CF32(a[loti],qtmp.real,qtmp.imag);
                }
            }
            k = k1;
	}
    /*
      TOLERANCE FOR NEGLIGIBLE ELEMENTS
    */
    eps = 0.0F;
    for (k = 0; k < n; k++) {
        s[k] = b[k];
        t[k] = c[k];
        if (s[k] + t[k] > eps)
            eps = s[k] + t[k];
    }
    eps *= eta;
    /*
      INITIALIZATION OF u AND v
    */
    if (nu > 0) {
        for (j = 0; j < nu; j++) {
            for (i = 0; i < m; i++) {
                loti=i*n+j;
                IFX_INIT_CF32(u[loti],0.0F,0.0F); //ByM: initially: u[i][j] = complex(0.0F, 0.0F);
            }
            loti=j*n+j;
            IFX_INIT_CF32(u[loti],1.0F,0.0F);   //ByM: initially: u[j][j] = complex(1.0F, 0.0F);
        }
    }
    if (nv > 0) {
        for (j = 0; j < nv; j++) {
            for (i = 0; i < n; i++) {
                loti=i*n+j;
                IFX_INIT_CF32(v[loti],0.0F,0.0F); //ByM: initially: v[i][j] = complex(0.0F, 0.0F);
            }
            loti=j*n+j;
            IFX_INIT_CF32(v[loti],1.0F,0.0F);   //ByM: initially: v[j][j] = complex(1.0F, 0.0F);
        }
    }

    /*
      QR DIAGONALIZATION
    */
    for (k = nM1; k >= 0; k--) {
        /*
          TEST FOR SPLIT
        */
        while (1) {
            for (L = k; L >= 0; L--) {
                if (IFX_ABS_F32(t[L]) <= eps) goto Test;
                if (IFX_ABS_F32(s[L - 1]) <= eps) break;
            }
            /*
              CANCELLATION OF E(L)
            */
            cs = 0.0F;
            sn = 1.0F;
            L1 = L - 1;
            for (i = L; i <= k; i++) {
                f = sn * t[i];
                t[i] *= cs;
                if (IFX_ABS_F32(f) <= eps) goto Test;
                h = s[i];
                w = (float)sqrt(f * f + h * h);
                s[i] = w;
                cs = h / w;
                sn = -f / w;
                if (nu > 0) {
                    for (j = 0; j < n; j++) {
                        /*x = real(u[j][L1]);
                          y = real(u[j][i]);
                          u[j][L1] = complex(x * cs + y * sn, 0.0F);
                          u[j][i] = complex(y * cs - x * sn, 0.0F);*/
                        loti=j*n+L1;
                        loti2=j*n+i;
                        x=u[loti].real;
                        y=u[loti2].real;
                        IFX_INIT_CF32(u[loti],x*cs+y*sn, 0.0F);
                        IFX_INIT_CF32(u[loti2],y*cs-x*sn, 0.0F);
                    }
                }
                /*if (np == n) continue;   // In our case p=0 => np==n
                  for (j = n; j < np; j++)
                  {
                  q = a[L1][j];
                  r = a[i][j];
                  a[L1][j] = q * cs + r * sn;
                  a[i][j] = r * cs - q * sn;
                  }*/
            }
            /*
              TEST FOR CONVERGENCE
            */
          Test:	w = s[k];
            if (L == k) break;
            /*
              ORIGIN SHIFT
            */
            x = s[L];
            y = s[k - 1];
            g = t[k - 1];
            h = t[k];
            f = ((y - w) * (y + w) + (g - h) * (g + h)) / (2.0F * h * y);
            g = Ifx_sqrtF32(f * f + 1.0F,mode);
            if (f < 0.0F) g = -g;
            f = ((x - w) * (x + w) + (y / (f + g) - h) * h) / x;
            /*
              QR STEP
            */
            cs = 1.0F;
            sn = 1.0F;
            L1 = L + 1;
            for (i = L1; i <= k; i++) {
                g = t[i];
                y = s[i];
                h = sn * g;
                g = cs * g;
                w = Ifx_sqrtF32(h * h + f * f, mode);
                t[i - 1] = w;
                cs = f / w;
                sn = h / w;
                f = x * cs + g * sn;
                g = g * cs - x * sn;
                h = y * sn;
                y = y * cs;
                if (nv > 0) {
                    for (j = 0; j < n; j++) {
                        /*x = real(v[j][i - 1]);
                          w = real(v[j][i]);
                          v[j][i - 1] = complex(x * cs + w * sn, 0.0F);
                          v[j][i] = complex(w * cs - x * sn, 0.0F);*/
                        loti2=j*n+i;
                        loti=loti2-1;
                        x=v[loti].real;
                        w=v[loti2].real;
                        IFX_INIT_CF32(v[loti],x*cs+w*sn, 0.0F);
                        IFX_INIT_CF32(v[loti2],w*cs-x*sn, 0.0F);
                    }
                }
                w = Ifx_sqrtF32(h * h + f * f, mode); // initially: (float)sqrt(h * h + f * f);
                s[i - 1] = w;
                cs = f / w;
                sn = h / w;
                f = cs * g + sn * y;
                x = cs * y - sn * g;
                if (nu > 0) {
                    for (j = 0; j < n; j++) {
                        /*y = real(u[j][i - 1]);
                          w = real(u[j][i]);
                          u[j][i - 1] = complex(y * cs + w * sn, 0.0F);
                          u[j][i] = complex(w * cs - y * sn, 0.0F);*/
                        loti2=j*n+i;
                        loti=loti2-1;
                        y=u[loti].real;
                        w=u[loti2].real;
                        IFX_INIT_CF32(u[loti],y*cs+w*sn, 0.0F);
                        IFX_INIT_CF32(u[loti2],w*cs-y*sn, 0.0F);
                    }
                }
                /*if (n == np) continue;
                  for (j = n; j < np; j++)
                  {
                  q = a[i - 1][j];
                  r = a[i][j];
                  a[i - 1][j] = q * cs + r * sn;
                  a[i][j] = r * cs - q * sn;
                  }*/
            }
            t[L] = 0.0F;
            t[k] = f;
            s[k] = x;
        }
        /*
          CONVERGENCE
        */
        if (w >= 0.0F) continue;
        s[k] = -w;
        if (nv == 0) continue;
        for (j = 0; j < n; j++) {
            loti=j*n+k;
            IFX_INIT_CF32(v[loti],-v[loti].real, -v[loti].imag);// initially: v[j][k] = -v[j][k];
        }
    }
    //PrintComplexMatrix(v, n,n,"V before back transform and sort:");
    /*
      SORT SINGULAR VALUES
    */
    for (k = 0; k < n; k++) {	/* sort descending */
        g = -1.0F;
        j = k;
        for (i = k; i < n; i++)	{ /* sort descending */
            if (s[i] <= g) continue;
            g = s[i];
            j = i;
        }
        if (j == k) continue;
        s[j] = s[k];
        s[k] = g;
        if (nv > 0) {
            for (i = 0; i < n; i++) {
                /*q = v[i][j];
                  v[i][j] = v[i][k];
                  v[i][k] = q;*/
                loti=i*n+j;
                loti2=i*n+k;
                IFX_SWAP_CF32(v[loti],v[loti2],q);
            }
        }
        if (nu > 0) {
            for (i = 0; i < n; i++) {
                /*q = u[i][j];
                  u[i][j] = u[i][k];
                  u[i][k] = q;*/
                loti=i*n+j;
                loti2=i*n+k;
                IFX_SWAP_CF32(u[loti],u[loti2],q);
            }
        }
        /*if (n == np) continue;
          for (i = n; i < np; i++)
          {
          q = a[j][i];
          a[j][i] = a[k][i];
          a[k][i] = q;
          }*/
    }

    //Print for debug
    //PrintComplexMatrix(a, m,n,"A modified:");
    //PrintComplexMatrix(v, n,n,"V before back transform:");
    //for (i=0;i<n;i++) printf("%12.6f\n",b[i]);
    /*
      BACK TRANSFORMATION
    */
    if (nu > 0) {
        for (k = nM1; k >= 0; k--) {
            if (b[k] == 0.0F) continue;
            /*q = -a[k][k] / abs(a[k][k]);
              for (j = 0; j < nu; j++)
              u[k][j] *= q;
              for (j = 0; j < nu; j++)
              {
              q = complex(0.0F, 0.0F);
              for (i = k; i < m; i++)
              q += conj(a[i][k]) * u[i][j];
              q /= abs(a[k][k]) * b[k];
              for (i = k; i < m; i++)
              u[i][j] -= q * a[i][k];
              }*/
            loti=k*n+k;
            IFX_INIT_CF32(qtmp,-a[loti].real,-a[loti].imag); // qtmp=-a[k][k]
            lotmp=IFX_ABS_CF32(a[loti]);
            IFX_S_CDIV_F32(q,qtmp,lotmp);
            for (j = 0; j < nu; j++) {
                loti=k*n+j;
                IFX_CMUL_F32(qtmp,u[loti],q);
                IFX_INIT_CF32(u[loti],qtmp.real,qtmp.imag);
            }
            //PrintComplexMatrix(u, m,n,"U in function:");
            for (j = 0; j < nu; j++) {
                IFX_INIT_CF32(q,0.0F,0.0F);
                for (i = k; i < m; i++) {
                    loti=i*n+k;
                    loti2=i*n+j;
                    IFX_CMUL_CONJ_F32(qtmp,a[loti],u[loti2]);
                    IFX_CADD_F32(q,q,qtmp);
                }
                // initially q /= abs(a[k][k]) * b[k];
                loti=k*n+k;
                lotmp=IFX_ABS_CF32(a[loti]);
                lotmp=lotmp*b[k];
                IFX_S_CDIV_F32(q,q,lotmp);
                for (i = k; i < m; i++) {
                    // initially: u[i][j] -= q * a[i][k];
                    loti=i*n+k;
                    IFX_CMUL_F32(qtmp,q,a[loti]);
                    loti=i*n+j;
                    IFX_CSUB_F32(u[loti],u[loti],qtmp);
                }
            }
            //PrintComplexMatrix(u, m,n,"U in function:");

        }
    }
    //PrintComplexMatrix(u, m,n,"U in function:");
    if (nv > 0 && n > 1) {
        for (k = n - 2; k >= 0; k--) {
            k1 = k + 1;
            if (c[k1] == 0.0F) continue;
            /*q = -conj(a[k][k1]) / abs(a[k][k1]);
              for (j = 0; j < nv; j++)
              v[k1][j] *= q;
              for (j = 0; j < nv; j++)
              {
              q = complex(0.0F, 0.0F);
              for (i = k1; i < n; i++)
              q += a[k][i] * v[i][j];
              q = q / (abs(a[k][k1]) * c[k1]);
              for (i = k1; i < n; i++)
              v[i][j] -= q * conj(a[k][i]);
              }*/
            loti=k*n+k1;
            IFX_INIT_CF32(qtmp,-a[loti].real,a[loti].imag); // qtmp=-conj(a[k][k1])
            lotmp=IFX_ABS_CF32(a[loti]);
            IFX_S_CDIV_F32(q,qtmp,lotmp);
            for (j = 0; j < nv; j++) {
                loti=k1*n+j;
                IFX_CMUL_F32(qtmp,v[loti],q);
                IFX_INIT_CF32(v[loti],qtmp.real,qtmp.imag);
            }
            for (j = 0; j < nv; j++) {
                IFX_INIT_CF32(q,0.0F,0.0F);
                for (i = k1; i < n; i++) {
                    loti=k*n+i;
                    loti2=i*n+j;
                    IFX_CMUL_F32(qtmp,a[loti],v[loti2]);
                    IFX_CADD_F32(q,q,qtmp);
                }
                // initially q /= abs(a[k][k1]) * c[k1];
                loti=k*n+k1;
                lotmp=IFX_ABS_CF32(a[loti]);
                lotmp=lotmp*c[k1];
                IFX_S_CDIV_F32(q,q,lotmp);
                for (i = k1; i < n; i++) {
                    // initially:v[i][j] -= q * conj(a[k][i]);
                    loti=k*n+i;
                    IFX_CMUL_CONJ_F32(qtmp,a[loti],q);
                    loti=i*n+j;
                    IFX_CSUB_F32(v[loti],v[loti],qtmp);
                }
            }

        }
    }

    //Print for debug
    //PrintComplexMatrix(u, m,n,"U in function:");
    // copy U in A
    for (i=0;i<m;i++)
        for (j=0;j<n;j++) {
            loti=i*n+j;
            IFX_INIT_CF32(a[loti],u[loti].real,u[loti].imag);
        }

    IFX_FREE_TMP_VECTOR(float32,b,n);
    IFX_FREE_TMP_VECTOR(float32,c,n);
    IFX_FREE_TMP_VECTOR(float32,t,n);
    IFX_FREE_TMP_VECTOR(cfloat32,u,m*n);
}
