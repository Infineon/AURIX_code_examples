/**********************************************************************************************************************
 * \file Flash_Programming.c
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
#include <string.h>
#include "Ifx_Types.h"
#include "Flash_Programming.h"
#include "IfxFlash.h"
#include "IfxCpu.h"
#include "IfxPort.h"
#include "pin.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define PFLASH_PAGE_LENGTH          IFXFLASH_PFLASH_PAGE_LENGTH /* 0x20 = 32 Bytes (smallest unit that can be
                                                                 * programmed in the Program Flash memory (PFLASH)) */
#define DFLASH_PAGE_LENGTH          IFXFLASH_DFLASH_PAGE_LENGTH /* 0x8 = 8 Bytes (smallest unit that can be
                                                                 * programmed in the Data Flash memory (DFLASH))    */
#define FLASH_MODULE                0                           /* Macro to select the flash (PMU) module           */

#define DATA_TO_WRITE               0x01234567                  /* Dummy data to be written into the Flash memories */

#define PFLASH_STARTING_ADDRESS     0xA00E0000                  /* Address of the PFLASH where the data is written  */
#define DFLASH_STARTING_ADDRESS     0xAE000000                  /* Address of the DFLASH where the data is written  */

#define PFLASH_NUM_PAGE_TO_FLASH    2                           /* Number of pages to flash in the PFLASH           */
#define PFLASH_NUM_SECTORS          1                           /* Number of PFLASH sectors to be erased            */
#define DFLASH_NUM_PAGE_TO_FLASH    8                           /* Number of pages to flash in the DFLASH           */
#define DFLASH_NUM_SECTORS          1                           /* Number of DFLASH sectors to be erased            */

/* Definition of the LEDs port pins */
#define LED1                        LED_1               /* LED connected to Port 13, Pin 0                  */
#define LED2                        LED_2               /* LED connected to Port 13, Pin 1                  */

#define MEM(address)                *((uint32 *)(address))      /* Macro to simplify the access to a memory address */

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
uint32  FIRST_FAILING_SECTOR = 0;
/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Function to initialize the LEDs */
void initLEDs()
{
    /* Configure LED1 and LED2 port pins */
    IfxPort_setPinMode(LED1.port, LED1.pinIndex, IfxPort_Mode_outputPushPullGeneral);
    IfxPort_setPinMode(LED2.port, LED2.pinIndex, IfxPort_Mode_outputPushPullGeneral);

    /* Turn off the LEDs (LEDs are low-level active) */
    IfxPort_setPinState(LED1.port, LED1.pinIndex, IfxPort_State_high);
    IfxPort_setPinState(LED2.port, LED2.pinIndex, IfxPort_State_high);
}

/* This function flashes the Program Flash memory calling the routines from the PSPR */
void writeProgramFlash()
{
    uint32 page = 0;         /* Variable to cycle over all the pages          */

    /* Reset the addressed command sequence interpreter */
    IfxFlash_resetToRead(FLASH_MODULE);

    /* Clear flags */
    IfxFlash_clearStatus(FLASH_MODULE);

    /* --------------- ERASE PROCESS --------------- */
    /* Erase the sector */
    IfxFlash_eraseMultipleSectors(PFLASH_STARTING_ADDRESS, PFLASH_NUM_SECTORS); /* Erase the given sectors           */

    /* Wait until request is executed */
    while(FALSE == IfxFlash_isRequestExecuted())
    {}

    /* Clear flags */
    IfxFlash_clearStatus(FLASH_MODULE);

    /* --------------- ERASE VERIFY --------------- */

    /*Optional step to show the use of the comm registers*/

    /* Verify the sector is erased */
    IfxFlash_eraseVerifyMultipleSectors(PFLASH_STARTING_ADDRESS, PFLASH_NUM_SECTORS);
    /* Wait until request is executed */
    while(FALSE == IfxFlash_isRequestExecuted())
    {}
    if(IfxFlash_isErrorDetected(IfxFlash_Error_eraseVerify))
    {
        /*Read the COMM1 to get the position of first failing logical sector within the physical sector range*/
        FIRST_FAILING_SECTOR  = FSI_HOST_COMM1.U;
        while(1)
        {
        }
    }

    /* --------------- WRITE PROCESS --------------- */
    for(page = 0; page < PFLASH_NUM_PAGE_TO_FLASH; page++)      /* Loop over all the pages                          */
    {
        uint32 pageAddr = PFLASH_STARTING_ADDRESS + (page * PFLASH_PAGE_LENGTH); /* Get the address of the page     */

        /* Enter in page mode */
        IfxFlash_enterPageMode(pageAddr);

        /* Wait until page mode is entered */
        while(FALSE == IfxFlash_isPflashInPageMode())
        {}

        /* Clear flags */
        IfxFlash_clearStatus(FLASH_MODULE);

        /* Load data to be written in the page */
        IfxFlash_loadPage2X32(pageAddr, DATA_TO_WRITE, DATA_TO_WRITE); /* Load two words of 32 bits each            */
        IfxFlash_loadPage2X32(pageAddr, DATA_TO_WRITE, DATA_TO_WRITE); /* Load two words of 32 bits each            */
        IfxFlash_loadPage2X32(pageAddr, DATA_TO_WRITE, DATA_TO_WRITE); /* Load two words of 32 bits each            */
        IfxFlash_loadPage2X32(pageAddr, DATA_TO_WRITE, DATA_TO_WRITE); /* Load two words of 32 bits each            */

        /* Clear flags */
        IfxFlash_clearStatus(FLASH_MODULE);

        /* Write the loaded page */
        IfxFlash_writePage(pageAddr);                           /* Write the page                                   */

        /* Wait until request is executed */
        while(FALSE == IfxFlash_isRequestExecuted())
        {}

        /* Clear flags */
        IfxFlash_clearStatus(FLASH_MODULE);
    }
}

/* This function verifies if the data has been correctly written in the Program Flash */
void verifyProgramFlash()
{
    uint32 page;                                                /* Variable to cycle over all the pages             */
    uint32 offset;                                              /* Variable to cycle over all the words in a page   */
    uint32 errors = 0;                                          /* Variable to keep record of the errors            */

    /* Verify the written data */
    for(page = 0; page < PFLASH_NUM_PAGE_TO_FLASH; page++)                          /* Loop over all the pages      */
    {
        uint32 pageAddr = PFLASH_STARTING_ADDRESS + (page * PFLASH_PAGE_LENGTH);    /* Get the address of the page  */

        for(offset = 0; offset < PFLASH_PAGE_LENGTH; offset += 0x4)                 /* Loop over the page length    */
        {
            /* Check if the data in the Program Flash is correct */
            if(MEM(pageAddr + offset) != DATA_TO_WRITE)
            {
                /* If not, count the found errors */
                errors++;
            }
        }
    }

    /* If the data is correct, turn on the LED1 */
    if(errors == 0)
    {
        IfxPort_setPinState(LED1.port, LED1.pinIndex, IfxPort_State_low);
    }
}

/* This function flashes the Data Flash memory.
 * It is not needed to run this function from the PSPR, thus functions from the Program Flash memory can be called
 * inside.
 */
void writeDataFlash()
{
    uint32 page;                                                /* Variable to cycle over all the pages             */

    /* Reset the addressed command sequence interpreter */
    IfxFlash_resetToRead(FLASH_MODULE);

    /* Clear flags */
    IfxFlash_clearStatus(FLASH_MODULE);

    /* --------------- ERASE PROCESS --------------- */
    /* Erase the sector */
    IfxFlash_eraseMultipleSectors(DFLASH_STARTING_ADDRESS, DFLASH_NUM_SECTORS); /* Erase the given sector           */

    /* Wait until request is executed */
    while(FALSE == IfxFlash_isRequestExecuted())
    {}

    /* Clear flags */
    IfxFlash_clearStatus(FLASH_MODULE);

    /* --------------- WRITE PROCESS --------------- */
    for(page = 0; page < DFLASH_NUM_PAGE_TO_FLASH; page++)      /* Loop over all the pages                          */
    {
        uint32 pageAddr = DFLASH_STARTING_ADDRESS + (page * DFLASH_PAGE_LENGTH); /* Get the address of the page     */

        /* Enter in page mode */
        IfxFlash_enterPageMode(pageAddr);

        /* Wait until page mode is entered */
        while(FALSE == IfxFlash_isDflashInPageMode())
        {}

        /* Clear flags */
        IfxFlash_clearStatus(FLASH_MODULE);

        /* Load data to be written in the page */
        IfxFlash_loadPage2X32(pageAddr, DATA_TO_WRITE, DATA_TO_WRITE); /* Load two words of 32 bits each            */

        /* Clear flags */
        IfxFlash_clearStatus(FLASH_MODULE);

        /* Write the loaded page */
        IfxFlash_writePage(pageAddr);                           /* Write the page                                   */

        /* Wait until request is executed */
        while(FALSE == IfxFlash_isRequestExecuted())
        {}

        /* Clear flags */
        IfxFlash_clearStatus(FLASH_MODULE);
    }
}

/* This function verifies if the data has been correctly written in the Data Flash */
void verifyDataFlash()
{
    uint32 page;                                                /* Variable to cycle over all the pages             */
    uint32 offset;                                              /* Variable to cycle over all the words in a page   */
    uint32 errors = 0;                                          /* Variable to keep record of the errors            */

    /* Verify the written data */
    for(page = 0; page < DFLASH_NUM_PAGE_TO_FLASH; page++)                          /* Loop over all the pages      */
    {
        uint32 pageAddr = DFLASH_STARTING_ADDRESS + (page * DFLASH_PAGE_LENGTH);    /* Get the address of the page  */

        for(offset = 0; offset < DFLASH_PAGE_LENGTH; offset += 0x4)                 /* Loop over the page length    */
        {
            /* Check if the data in the Data Flash is correct */
            if(MEM(pageAddr + offset) != DATA_TO_WRITE)
            {
                /* If not, count the found errors */
                errors++;
            }
        }
    }

    /* If the data is correct, turn on the LED2 */
    if(errors == 0)
    {
        IfxPort_setPinState(LED2.port, LED2.pinIndex, IfxPort_State_low);
    }
}
