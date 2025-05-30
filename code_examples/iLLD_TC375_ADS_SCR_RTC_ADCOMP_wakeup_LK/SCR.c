/**********************************************************************************************************************
 * \file SCR.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "SCR.h"
#include "IfxPms_reg.h"
#include "SCR_AURIX_TC3x.h"

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void IfxScr_initSCR(ScrBootMode const bootMode)
{
    PMS_PMSWCR4.U |= 0x3 | (((uint8)bootMode) << 16);
    /* Wait for SCR to be reset */
    while(!PMS_PMSWSTAT.B.SCRST)
    {}
    /* Clear reset status */
    PMS_PMSWSTATCLR.B.SCRSTCLR = 1; 

    /* The SCR should have booted up by and have status 0x80 */
    while(PMS_PMSWCR2.B.SCRINT != 0x80)
    {}
}

void IfxScr_copySCRprogram(void)
{
    volatile uint8* addr = ((volatile uint8*)PMS_XRAM);
    volatile uint16* addr16 = ((volatile uint16*)(0xF0241FF8));

    for(uint16 addrOffset = 0; addrOffset < SIZE_scr_xram; addrOffset++)
    {
        *addr = scr_xram[addrOffset];
        addr++;
    }

    for(uint8 i = 0; i < 4; i++){
        *(addr16 + i) = 0xAA55;
    }
}

void IfxScr_disableSCR(void)
{
    /* Disable SCR and disable 100MHz clock */
    PMS_PMSWCR4.U = 0x01000000;
    /* Confirm SCR is disabled */
    while(PMS_PMSWSTAT.B.SCR)
    {}
}

void IfxScr_enableSCR(void)
{
    PMS_PMSWCR4.U |= (0x0 << 6) | (0x1 << 25) | (0x1 << 24);

    /* SCR wake-up enable */
    PMS_PMSWCR0.U |= (0x1 << 29);
    /* Confirm that SCR is enabled */
    while(!PMS_PMSWSTAT.B.SCR)
    {}
}

void IfxScr_resetSCR(void)
{
    PMS_PMSWCR4.U |= 0x3;
    /* Wait for SCR to be reset */
    while(!PMS_PMSWSTAT.B.SCRST)
    {}
    /* Clear reset status */
    PMS_PMSWSTATCLR.B.SCRSTCLR = 1;
    /* The SCR should have booted up by and have status 0x80 */
    while(PMS_PMSWCR2.B.SCRINT != 0x80)
    {}
}

/*
 * Function: setRTCperiod_on70kHz
 * --------------------
 * This function updates the 32-bit memory location with the new calibrated timer overflow count
 * for the necessary period. Used for sharing calibrated 70kHz clock period for SCR's RTC timer.
 *
 * msPeriod: required RTC period in ms
 * calibCoeff: calibration coefficient derived with TriCore(TM) based calibration of 70kHz
 * exchangeAddress: mapped SCR address allocated on the SCR for storing RTC 32-bit overflow data
 *
 * returns: none
 */
void IfxScr_setRTCperiodOn70kHz(uint32 const msPeriod, float32 const calibCoeff, uint32* const exchangeAddress)
{
    uint32 tickCounter = (uint32)(70 * msPeriod * calibCoeff);

    *exchangeAddress = tickCounter;
}
