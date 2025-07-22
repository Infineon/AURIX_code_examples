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
/*! \file Ifx_firRealF32Audio.c
 *
 * This FIR filter function takes the previous input into account
 */

#include "dsplib-internal.h"

void Ifx_firRealF32Audio_ref (struct Ifx_firRealF32AudioState *);

void
Ifx_firRealF32Audio_ref (struct Ifx_firRealF32AudioState * state)
{
    int i, j;
    float32 * y = state->y;
    float32 * c = state->c;
    float32 * x = state->x;
    float32 * p = state->p;
    uint32 m = state->m;
    uint32 n = state->n;
    uint32 m1 = m-1;

    memset (y, 0, sizeof(float32)*n);

    if (m1>n) {
        if (m1<2*n) {
            for (i=0; i<m1-n; i++) {
                for (j=m1-i; j<m; j++) {
                    y[i+j-m1] += c[j]*p[i];
                }
                for (j=0; j<n-i; j++) {
                    y[i+j] += c[j]*x[i];
                }
                p[i] = p[n+i];
            }
            for (i=m1-n; i<n; i++) {
                for (j=m1-i; j<m; j++) {
                    y[i+j-m1] += c[j]*p[i];
                }
                for (j=0; j<n-i; j++) {
                    y[i+j] += c[j]*x[i];
                }
                p[i] = x[i-m1+n];
            }
            for (i=n; i<m1; i++) {
                for (j=m1-i; j<m1-i+n; j++) {
                    y[i+j-m1] += c[j]*p[i];
                }
                p[i] = x[i-m1+n];
            }
        }
        else {
            for (i=0; i<n; i++) {
                for (j=m1-i; j<m; j++) {
                    y[i+j-m1] += c[j]*p[i];
                }
                for (j=0; j<n-i; j++) {
                    y[i+j] += c[j]*x[i];
                }
                p[i] = p[n+i];
            }
            for (i=n; i<m1-n; i++) {
                for (j=m1-i; j<m1-i+n; j++) {
                    y[i+j-m1] += c[j]*p[i];
                }

                p[i] = p[n+i];
            }
            for (i=m1-n; i<m1; i++) {

                for (j=m1-i; j<m1-i+n; j++) {
                    y[i+j-m1] += c[j]*p[i];
                }
                p[i] = x[i-m1+n];
            }
        }
    }
    else {
        if (n<2*m1) {
            for (i=0; i<n-m1; i++) {
                for (j=m1-i; j<m; j++) {
                    y[i+j-m1] += c[j]*p[i];
                }
                for (j=0; j<m; j++) {
                    y[i+j] += c[j]*x[i];
                }
            }
            for (i=n-m1; i<m1; i++) {
                for (j=m1-i; j<m; j++) {
                    y[i+j-m1] += c[j]*p[i];
                }
                for (j=0; j<m; j++) {
                    y[i+j] += c[j]*x[i];
                }
                p[i-n+m1] = x[i];
            }
            for (i=m1; i<n; i++) {
                for (j=0; j<n-i; j++) {
                    y[i+j] += c[j]*x[i];
                }
                p[i-n+m1] = x[i];
            }
        }

        else {
            for (i=0; i<m1; i++) {
                for (j=m1-i; j<m; j++) {
                    y[i+j-m1] += c[j]*p[i];
                }
                for (j=0; j<m; j++) {
                    y[i+j] += c[j]*x[i];
                }
            }
            for (i=m1; i<n-m1; i++) {
                for (j=0; j<m; j++) {
                    y[i+j] += c[j]*x[i];
                }
            }
            for (i=n-m1; i<n; i++) {
                for (j=0; j<n-i; j++) {
                    y[i+j] += c[j]*x[i];
                }
                p[i-n+m1] = x[i];
            }

        }
    }
}

void
Ifx_firRealF32Audio (struct Ifx_firRealF32AudioState * state)
{
    enum Ifx_mode mode = state->mode;
    switch (mode) {
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        Ifx_firRealF32Audio_ref (state);
        break;
    default:
        Ifx_warnAboutUnimplementedMode (mode, "firRealF32Audio");
        Ifx_firRealF32Audio_ref (state);
        break;
    }
}
