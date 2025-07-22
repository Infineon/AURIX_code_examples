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
/*! \file Ifx_error.c
 * \brief error reporting
 *
 */

#include "dsplib-internal.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*! \fn Ifx_catchError
 * \brief error catcher function
 * The following function is intended to do nothing.
 * It is called when an error is detected in the DSP library.
 * Set a breakpoint in the debugger to catch errors.
 */
void
Ifx_catchError (void)
{
    fflush (stdout);
    fflush (stderr);
    /* do nothing */;
}

/*! \fn Ifx_error (enum Ifx_error_severity sev, char * format, ...)
 * \param[in] sev severity of the error
 * \param[in] format printf-like format string
 *
 * \brief report an error
 *
 * this function reports an error. It is also possible to output
 * an information for debugging purposes. The idea is that the output
 * of this function is somehow conntected to a debugging console.
 */

void
Ifx_error (enum Ifx_error_severity sev, const char * format, ...)
{
#if __unix__||_WIN32||IFX_TRICORE_TARGET
    const char * sev_string = "*unknown*";
    uint8 do_abort = 0;
    va_list ap;

    /* determine severity string */
    switch (sev) {
    case IFX_ERR_PANIC: sev_string = "panic"; do_abort = 1; break;
    case IFX_ERR_ERROR: sev_string = "error"; break;
    case IFX_ERR_WARN: sev_string = "warning"; break;
    case IFX_ERR_INFO: sev_string = "info"; break;
    case IFX_ERR_NONE: return;
    }

    /* print error message */
#if !IFX_TRICORE_TARGET
    fprintf (stderr, "IFX %s: ", sev_string);
    va_start (ap, format);
    vfprintf (stderr, format, ap);
    va_end (ap);
#else /* IFX_TRICORE_TARGET */
    printf ("IFX %s: ", sev_string);
    va_start (ap, format);
    vprintf (format, ap);
    va_end (ap);
#endif /* !IFX_TRICORE_TARGET */

    switch (sev) {
    case IFX_ERR_PANIC:
    case IFX_ERR_ERROR:
        Ifx_catchError ();
        break;
    default:
        /* do nothing */;
    }

    /* abort if it is a fatal error */
    if (do_abort) {
        fflush (stdout);
        fflush (stderr);
        abort();
    }

#else /* !(__unix__||_WIN32||IFX_TRICORE_TARGET) */
# error "need to implement error handler"
#endif /* __unix__||_WIN32||IFX_TRICORE_TARGET */
}
