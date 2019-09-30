/**
 * \file IfxFlash.c
 * \brief FLASH  basic functionality
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2016 Infineon Technologies AG. All rights reserved.
 *
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxFlash.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxFlash_clearCorrectableErrorTracking(IfxFlash_PortId portId)
{
    MODULE_FLASH0.CBAB[portId].CFG.B.CLR = 1;
}


void IfxFlash_clearUncorrectableErrorTracking(IfxFlash_PortId portId)
{
    MODULE_FLASH0.UBAB[portId].CFG.B.CLR = 1;
}


void IfxFlash_disableCorrectableErrorTracking(IfxFlash_PortId portId, boolean disable)
{
    MODULE_FLASH0.CBAB[portId].CFG.B.DIS = disable;
}


void IfxFlash_disableUncorrectableErrorTracking(IfxFlash_PortId portId, boolean disable)
{
    MODULE_FLASH0.UBAB[portId].CFG.B.DIS = disable;
}


void IfxFlash_disableWriteProtection(uint32 flash, IfxFlash_UcbType ucb, uint32 *password)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x553c);
    uint32           i;

    *addr1 = ucb;

    for (i = 0; i < 8; i++)
    {
        *addr1 = password[i];
    }

    __dsync();
}


uint32 IfxFlash_getTrackedCorrectableErrors(IfxFlash_PortId portId, IfxFlash_ErrorTracking_Address *trackedFlashAdresses)
{
    uint32 numErrors    = 0;
    uint32 fillingLevel = MODULE_FLASH0.CBAB[portId].STAT.U;

    int    i;

    for (i = 0;
         i < IFXFLASH_ERROR_TRACKING_MAX_CORRECTABLE_ERRORS &&
         (fillingLevel & (1 << i)) != 0;
         ++i)
    {
        Ifx_FLASH_CBAB_TOP top;
        top.U = MODULE_FLASH0.CBAB[portId].TOP.U;

        if (top.B.VLD)
        {
            trackedFlashAdresses[numErrors].address   = 0xa0000000 | (top.B.ADDR << 5);
            trackedFlashAdresses[numErrors].errorType = top.B.ERR;
            ++numErrors;
        }

        // clear entry
        MODULE_FLASH0.CBAB[portId].TOP.U = (1 << 31);
    }

    return numErrors;
}


uint32 IfxFlash_getTrackedUncorrectableErrors(IfxFlash_PortId portId, IfxFlash_ErrorTracking_Address *trackedFlashAdresses)
{
    uint32 numErrors    = 0;
    uint32 fillingLevel = MODULE_FLASH0.UBAB[portId].STAT.U;

    int    i;

    for (i = 0;
         i < IFXFLASH_ERROR_TRACKING_MAX_UNCORRECTABLE_ERRORS &&
         (fillingLevel & (1 << i)) != 0;
         ++i)
    {
        Ifx_FLASH_UBAB_TOP top;
        top.U = MODULE_FLASH0.UBAB[portId].TOP.U;

        if (top.B.VLD)
        {
            trackedFlashAdresses[numErrors].address   = 0xa0000000 | (top.B.ADDR << 5);
            trackedFlashAdresses[numErrors].errorType = top.B.ERR;
            ++numErrors;
        }

        // clear entry
        MODULE_FLASH0.UBAB[portId].TOP.U = (1 << 31);
    }

    return numErrors;
}


void IfxFlash_selectCorrectableErrorTracking(IfxFlash_PortId portId, IfxFlash_ErrorTracking errorTracking)
{
    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR,
        errorTracking == IfxFlash_ErrorTracking_none ||
        errorTracking == IfxFlash_ErrorTracking_correctedSingleBitError ||
        errorTracking == IfxFlash_ErrorTracking_correctedDoubleBitError ||
        errorTracking == IfxFlash_ErrorTracking_correctedSingleOrDoubleBitError);

    MODULE_FLASH0.CBAB[portId].CFG.B.SEL = errorTracking;
}


void IfxFlash_selectUncorrectableErrorTracking(IfxFlash_PortId portId, IfxFlash_ErrorTracking errorTracking)
{
    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR,
        errorTracking == IfxFlash_ErrorTracking_none ||
        errorTracking == IfxFlash_ErrorTracking_uncorrectableMultiBitError);

    MODULE_FLASH0.UBAB[portId].CFG.B.SEL = errorTracking;
}
