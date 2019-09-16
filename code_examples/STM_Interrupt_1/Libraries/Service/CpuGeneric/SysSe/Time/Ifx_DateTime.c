/**
 * \file Ifx_DateTime.c
 * \brief Date and time functions.
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:37 GMT$
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

#include "Ifx_DateTime.h"
#include "SysSe/Bsp/Bsp.h"

/* FIXME make compatible to unix time */
sint32 g_DateTimeOffset;

/** \brief Get the real time
 * Note that this function is valid only if DateTime_set() has been called */
void DateTime_get(Ifx_DateTime *dt)
{
    sint32 seconds = (sint32)(now() / TimeConst_1s);

    seconds     = seconds + g_DateTimeOffset;
    dt->hours   = seconds / 3600;
    dt->minutes = seconds / 60;
    dt->minutes = dt->minutes % 60;
    dt->seconds = seconds % 60;
}


/** \brief Set the real time */
void DateTime_set(Ifx_DateTime *dt)
{
    sint32 seconds = dt->seconds - ((sint32)(now() / TimeConst_1s));

    seconds          = seconds + (3600 * dt->hours);
    seconds          = seconds + (60 * dt->minutes);
    g_DateTimeOffset = seconds;
}
