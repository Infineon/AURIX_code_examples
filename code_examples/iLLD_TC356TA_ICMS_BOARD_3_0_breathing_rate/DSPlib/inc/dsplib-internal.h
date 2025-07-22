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
#ifndef IFX_DSPLIB_INTERNAL_H
#define IFX_DSPLIB_INTERNAL_H

#ifndef IFX_DSPLIB_H
#include <dsplib.h>
#endif /* IFX_DSPLIB_H */

/*! set a breakpoint on this function to catch errors */
void Ifx_catchError(void);

/*! warn about unimplemented modes */
void Ifx_warnAboutUnimplementedMode (enum Ifx_mode mode, const char * name);

#define IFX_ASIN_TABLE_N 128
/*! table for arcus sinus */
typedef struct{
	float32 a;
	float32 b;
}Ifx_asinTableF32_t;
extern Ifx_asinTableF32_t Ifx_asinTableF32[IFX_ASIN_TABLE_N];

#define IFX_SIN_TABLE_N 128
/*! table for sinus */
typedef struct {
    float32 a;
    float32 b;
}Ifx_sinTableF32_t;
extern Ifx_sinTableF32_t Ifx_sinTableF32[IFX_SIN_TABLE_N];

typedef struct {
   double a;
   double b;
   double c;
   double d;
   double e;
   double f;
   double g;
   double h;
}Coeff_val;

typedef struct {
   double a;
   double b;
   double c;
   double d;
   double e;
   double f;
   double g;
   double h;
   double i;
   double j;
   double k;
   double l;
   double m;
   double n;
   double o;
   double p;
   double q;
   double r;
   double s;
   double t;
   double u;
   double v;
   double w;
   double x;
   double y;
   double z;
   double aa;
   double bb;
   double cc;
   double dd;
   double ee;
   double ff;
   double gg;
   double hh;
}Sqrt_val;

#endif /* IFX_DSPLIB_INTERNAL_H */
