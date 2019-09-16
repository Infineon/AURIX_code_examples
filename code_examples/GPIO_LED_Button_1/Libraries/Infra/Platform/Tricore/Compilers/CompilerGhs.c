/**
 * \file CompilerGhs.c
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:40 GMT$
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
 *
 */

#include "Cpu/Std/Ifx_Types.h"
#include "Compilers.h"

#if defined(__ghs__) && !defined(WIN32)

typedef int ptrdiff_t;
typedef unsigned int syze_t;
typedef signed int signed_size_t;
#define size_t	syze_t

extern void *memcpy(void *s1, const void *s2, syze_t n);
extern void *memset(void *s, int c, syze_t n);

/* rodata is absolute */
typedef const char rodata_ptr[];
# define PIRBASE	0

#define CONST_FUNCP *const

/*!
 * \brief Initializes C variables.
 *
 * This function is called in the startup. This function initialize the all variables in .data section
 * and clears the .bss section
 *
 * Parameters: Nil
 * Return: Nil
 */
void Ifx_C_Init(void)
{
	/*----------------------------------------------------------------------*/
	/*									*/
	/*	Clear BSS							*/
	/*									*/
	/*----------------------------------------------------------------------*/
	    { /* The .secinfo section is in text; declare functions to force PIC */

	#pragma ghs rodata
	    extern rodata_ptr __ghsbinfo_clear;
	#pragma ghs rodata
	    extern rodata_ptr __ghseinfo_clear;

	    void **b = (void **) ((char *)__ghsbinfo_clear);
	    void **e = (void **) ((char *)__ghseinfo_clear);

	    while (b != e) {
		void *		t;			/* target pointer	*/
		ptrdiff_t	v;			/* value to set		*/
		size_t		n;			/* set n bytes		*/
		t = (char *)(*b++);
		v = *((ptrdiff_t *) b); b++;
		n = *((size_t    *) b); b++;
		memset(t, v, n);
	    }
	    }

	/*----------------*/
	/* initialize iob */
	/*----------------*/
	    {
	    #pragma weak __gh_iob_init
	    extern void __gh_iob_init(void);
	    static void (CONST_FUNCP iob_init_funcp)(void) = __gh_iob_init;
	    /* if cciob.c is loaded, initialize _iob for stdin,stdout,stderr */
	    if (iob_init_funcp) __gh_iob_init();
	    }
}


#endif
