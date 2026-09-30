/**
 * \file Ifx_DateTime.c
 * \brief Date and time functions.
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
