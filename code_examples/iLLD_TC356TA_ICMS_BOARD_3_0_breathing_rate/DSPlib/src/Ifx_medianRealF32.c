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
/*! \file Ifx_medianRealF32.c
 *
 * \brief compute median of Real vector
 *
 * \a Ifx_medianRealF32 function .
 *------------------------------------------------
 * Reference:
 * Author: Wirth, Niklaus
 * Title: Algorithms + data structures = programs
 * Publisher: Englewood Cliffs: Prentice-Hall, 1976
 * Physical description: 366 p.
 * Series: Prentice-Hall Series in Automatic Computation
 *
 *------------------------------------------------
 * x is the input vector of Real float32
 * function return the median of x
 *
 * Two computation formula are used
 * x with even number of elements
 * after data is sorted!
 * median = (x[(N/2)-1]+x[N/2])/2
 * -----------------------------------------------
 * x with odd number of elements
 * after data is sorted!
 * median = x[N/2]
 *
 * Implemented is non destructive variant, means the input vector x is not change
 * It requires additional local sorting vector a[] with constant size MAXLEN
 * Constant size prevent malloc usage,
 * if required can be changed to any other MAXLEN value
 */
#define MAXLEN 400

#include "dsplib.h"

float32
Ifx_medianRealF32(float32 *x, uint32 n)
{
	  sint32 i,j,l,m,k;
	  float32 z, t;
	  float32 a[MAXLEN];  /* will be used instead x[] vector otherwise a[] will be changed */

	  /* to keep input x[] unchanged copy the x[] to a[] , then use a[]*/
	  for (i=0;i<n;i++)
		  a[i] = x[i];

	  k = (((n)&1)?((n)/2):(((n)/2)-1));

	  l=0 ; m=n-1 ;
	  while (l<m) {
	    z=a[k] ;
	    i=l ;
	    j=m ;
	    do {
	      while (a[i]<z) i++ ;
	      while (z<a[j]) j-- ;
	      if (i<=j) {
	    	 t=a[i];
	    	 a[i]=a[j];
	    	 a[j]=t;
	    	/* ---------------------*/
	         i++ ; j-- ;
	      }
	    } while (i<=j) ;
	    if (j<k) l=i ;
	    if (k<i) m=j ;
	  };

	  z = a[k];

	  /* n = even => median = (a[k]+a[k+1])/2
	   * k = n/2-1
	   */
	  if ((n&1) == 0)
	  {
        z = a[k+1];
	    for(i=k+2;i<n;i++) {
          if(z>a[i]) z=a[i];
	    };
        z = (a[k]+ a[k+1])/2;
	  };

	  return z;
}
