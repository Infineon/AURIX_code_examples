/**
 * \file CompilerGhs.c
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
 */

#include "Ifx_Types.h"
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
