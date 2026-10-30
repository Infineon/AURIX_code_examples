/**
 * \file IfxFlash.c
 * \brief FLASH  basic functionality
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
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
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxFlash.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxFlash_disableWriteProtection(uint32 flash, IfxFlash_UcbType ucb, uint32 *password)
{
    IFX_UNUSED_PARAMETER(flash);
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x553c);
    uint32           i;

    *addr1 = ucb;

    /* Write the password to the flash command register, one 32-bit word at a time */
    for (i = 0; i < 8; i++)
    {
        *addr1 = password[i];
    }

    __dsync();
}
