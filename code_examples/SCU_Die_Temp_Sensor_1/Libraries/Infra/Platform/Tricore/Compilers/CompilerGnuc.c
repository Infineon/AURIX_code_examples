/**
 * \file CompilerGnuc.c
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

#if defined(__HIGHTEC__) && !defined(WIN32)
/*!
 * \brief Data s C variables.
 */
extern uint32 __clear_table[];  /**< clear table entry */
extern uint32 __copy_table[];   /**< copy table entry */

typedef volatile union
{
    uint8              *ucPtr;
    uint16             *usPtr;
    uint32             *uiPtr;
    unsigned long long *ullPtr;
} IfxStart_CTablePtr;

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
    IfxStart_CTablePtr pBlockDest, pBlockSrc;
    uint32             uiLength, uiCnt;
    uint32            *pTable;
    /* clear table */
    pTable = (uint32 *)&__clear_table;

    while (pTable)
    {
        pBlockDest.uiPtr = (uint32 *)*pTable++;
        uiLength         = *pTable++;

        /* we are finished when length == -1 */
        if (uiLength == 0xFFFFFFFF)
        {
            break;
        }

        uiCnt = uiLength / 8;

        while (uiCnt--)
        {
            *pBlockDest.ullPtr++ = 0;
        }

        if (uiLength & 0x4)
        {
            *pBlockDest.uiPtr++ = 0;
        }

        if (uiLength & 0x2)
        {
            *pBlockDest.usPtr++ = 0;
        }

        if (uiLength & 0x1)
        {
            *pBlockDest.ucPtr = 0;
        }
    }

    /* copy table */
    pTable = (uint32 *)&__copy_table;

    while (pTable)
    {
        pBlockSrc.uiPtr  = (uint32 *)*pTable++;
        pBlockDest.uiPtr = (uint32 *)*pTable++;
        uiLength         = *pTable++;

        /* we are finished when length == -1 */
        if (uiLength == 0xFFFFFFFF)
        {
            break;
        }

        uiCnt = uiLength / 8;

        while (uiCnt--)
        {
            *pBlockDest.ullPtr++ = *pBlockSrc.ullPtr++;
        }

        if (uiLength & 0x4)
        {
            *pBlockDest.uiPtr++ = *pBlockSrc.uiPtr++;
        }

        if (uiLength & 0x2)
        {
            *pBlockDest.usPtr++ = *pBlockSrc.usPtr++;
        }

        if (uiLength & 0x1)
        {
            *pBlockDest.ucPtr = *pBlockSrc.ucPtr;
        }
    }
}


#endif
