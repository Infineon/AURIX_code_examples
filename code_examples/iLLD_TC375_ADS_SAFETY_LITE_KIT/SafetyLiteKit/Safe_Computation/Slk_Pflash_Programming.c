/**********************************************************************************************************************
 * \file Slk_Pflash_Programming.c
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
/*
 * For erasing and writing a PFLASH, the file should not be stored at the PFLASH region where erasing and writing occur
 * therefore, Flash_Programming.c and Flash_Programming.h are stored at PSRAM0, please have a look to the linker file
 */

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include <string.h>
#include "SafetyLiteKit/Safe_Computation/Slk_NvmPflash.h"
#include "SafetyLiteKit/Safe_Computation/Slk_Pflash_Programming.h"
#include "SafetyLiteKit/Slk_Cfg.h"
#include "Ifx_Types.h"
#include "IfxFlash.h"
#include "IfxCpu.h"
#include "IfxPfi_reg.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define PFLASH_PAGE_LENGTH           IFXFLASH_PFLASH_PAGE_LENGTH /* 0x20 = 32 Bytes (smallest unit that can be
                                                                  * programmed in the Program Flash memory (PFLASH)) */
#define FLASH_MODULE                 0                           /* Macro to select the flash (PMU) module           */
#define PROGRAM_FLASH                IfxFlash_FlashType_P0       /* Define the Program Flash Bank to be used         */

#define PF_SBE_STARTING_ADDRESS     0xA0200000                /* Address of the PFLASH 0 where the data is written  */
#define PF_DBE_STARTING_ADDRESS     0xA0200020                /* Address of the PFLASH 0 where the data is written  */
#define PF_MBE_STARTING_ADDRESS     0xA0200040                /* Address of the PFLASH 0 where the data is written  */

#define PFLASH_NUM_PAGE_TO_FLASH     1                         /* Number of pages to flash in the PFLASH             */
#define PFLASH_NUM_SECTORS           1                         /* Number of PFLASH sectors to be erased              */

#define WORD_IN_PAGE                 8                         /* one page = 8 words                                 */

#define MEM(address)                *((uint32 *)(address))      /* Macro to simplify the access to a memory address */

/*********************************************************************************************************************/
/*--------------------------------------------Variables/Arrays-------------------------------------------------------*/
/*********************************************************************************************************************/
uint32 injectErrorPflashData[DATA_LENGTH_WORDS_UC];            /* array for injected data                            */

/* This is same dummy safety data i.e. dummySafetyDataUc[DATA_LENGTH_WORDS_UC]; for SBE, DBE and MBE */
uint32 dataPflashUpdate[DATA_LENGTH_WORDS_UC] =
{
    0x0e9957bb, 0x1c706c1e, 0x14c3db3f, 0x7fb17a93, 0xb0d9d5a7, 0x768093e0, 0x88b206a0, 0xc51299e4,
};

triggerNvmPflashBitsError g_triggerNvmPflashBitsError;
/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void erasePFLASH(uint32 sectorAddr);
void writePFLASH(uint32 startingAddr, uint32 *dataToWrite);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/*
 * This function erases a given sector of the Program Flash memory.
 * */
void erasePFLASH(uint32 sectorAddr)
{
    /* Get the current password of the Safety WatchDog module */
    uint16 endInitSafetyPassword = IfxScuWdt_getSafetyWatchdogPasswordInline();

    /* Erase the sector */
    IfxScuWdt_clearSafetyEndinitInline(endInitSafetyPassword);      /* Disable EndInit protection                   */

    IfxFlash_eraseMultipleSectors(sectorAddr, PFLASH_NUM_SECTORS ); /* Erase the given sector                       */

    IfxScuWdt_setSafetyEndinitInline(endInitSafetyPassword);        /* Enable EndInit protection                    */

    /* Wait until the sector is erased */
    IfxFlash_waitUnbusy (FLASH_MODULE, PROGRAM_FLASH);
}

/*
 * This function writes the Program Flash memory.
 * */
void writePFLASH(uint32 startingAddr, uint32 *dataToWrite)
{
    uint32 page;                                                /* Variable to cycle over all the pages             */
    uint32 offset;                                              /* Variable to cycle over all the words in a page   */
    uint32 nextPageIndex;
    /* Get the current password of the Safety WatchDog module */
    uint16 endInitSafetyPassword = IfxScuWdt_getSafetyWatchdogPasswordInline();

    /* Write all the pages */
    for(page = 0; page < PFLASH_NUM_PAGE_TO_FLASH; page++)              /* Loop over all the pages                  */
    {
        uint32 pageAddr = startingAddr + (page * PFLASH_PAGE_LENGTH);   /* Get the address of the page              */
        nextPageIndex = page * WORD_IN_PAGE;
        /* Enter in page mode */
        IfxFlash_enterPageMode(pageAddr);

        /* Wait until page mode is entered */
        IfxFlash_waitUnbusy (FLASH_MODULE, PROGRAM_FLASH);

        /* Write 32 bytes (8 double words) into the assembly buffer */
        for(offset = 0; offset < 8; offset +=2)        /* Loop over the page length */
        {
            IfxFlash_loadPage2X32(pageAddr, dataToWrite[offset + nextPageIndex],
                    dataToWrite[(offset + nextPageIndex + 1)]);                     /* Load 2 words of 32 bits each */
        }
        /* Write the page */
        IfxScuWdt_clearSafetyEndinitInline(endInitSafetyPassword);      /* Disable EndInit protection               */
        IfxFlash_writePage(pageAddr);                                   /* Write the page                           */

        IfxScuWdt_setSafetyEndinitInline(endInitSafetyPassword);        /* Enable EndInit protection                */

        /* Wait until the page is written in the Program Flash memory */
        IfxFlash_waitUnbusy (FLASH_MODULE, PROGRAM_FLASH);
    }
}

/*
 * This function erase and flash the new data
 * */
void eraseAndWritePflash(uint32 startingAddr, uint32 *dataToWrite)
{
    boolean interruptState = IfxCpu_disableInterrupts(); /* Get the current state of the interrupts and disable them*/

    /* Erase the Program Flash sector before writing */
    erasePFLASH(startingAddr);

    /* Write the Program Flash */
    writePFLASH(startingAddr, dataToWrite);

    IfxCpu_restoreInterrupts(interruptState);            /* Restore the interrupts state                            */
}

/*
 * initialization data for update check
 * */
void initUpdateDataPFLASH(void)
{
    uint32 index;

    /*fill the data write buffer with dummy safety data which CRC is calculated*/
    for (index = 0; index < DATA_LENGTH_WORDS_UC; index++)
    {
        injectErrorPflashData[index] = dataPflashUpdate[index];
    }
}

/*
 * This function flashes the Program Flash memory calling the routines from the PSPR
 * */
void injectECCerrorPFLASH(uint32 errInjType)
{
    /* Get the current state of the interrupts and disable them*/
    boolean interruptState = IfxCpu_disableInterrupts();
    uint16 passwordEndInit;
    volatile uint32 dummyRead;
    uint32 injectErrorAddressPF;

    /* type of injected error */
    switch(errInjType)
    {
        case SINGLE_BIT_ERR_INJ:
            injectErrorPflashData[0] = dataPflashUpdate[0] | 0x10000000; /* change MSB bit to 1 */
            injectErrorAddressPF = PF_SBE_STARTING_ADDRESS;
            break;

        case DOUBLE_BIT_ERR_INJ:
            injectErrorPflashData[0] = dataPflashUpdate[0] | 0x30000000; /* change the last 2 MSB bits to 1 */
            injectErrorAddressPF = PF_DBE_STARTING_ADDRESS;
            break;

        case MULTIPLE_BIT_ERR_INJ:
            injectErrorPflashData[0] = dataPflashUpdate[0] | 0x70000000; /* change the last 3 MSB bits to 1 */
            injectErrorAddressPF = PF_MBE_STARTING_ADDRESS;
            break;

        default:
            break;
    }

    /* Get the current password of the CPU WatchDog module */
    passwordEndInit = IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()]);

    /* Write data at dedicated address in PFLASH */
    writePFLASH(injectErrorAddressPF, &dataPflashUpdate[0]);

    /* SM:NVM.PFLASH:UPDATE_CHECK */
    runUpdateCheckPFLASH(injectErrorAddressPF);

    /* Make dummy read to get ECC value of working Page */
    dummyRead = MEM(injectErrorAddressPF);

    IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], passwordEndInit);

    /* Write in WCODE field the valid ECC value of working Page */
    MODULE_DMU.HF_ECCW.B.WCODE = MODULE_PFI0.ECCR.B.RCODE;

    /* Change ECC encoding configuration so that ECC code is taken from WCODE */
    MODULE_DMU.HF_ECCW.B.PECENCDIS = 3U;

    IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], passwordEndInit);

    /* write to Pflash with error value */
    writePFLASH(injectErrorAddressPF, &injectErrorPflashData[0]);

    /* Change ECC encoding configuration so that ECC code is automatically calculated */
    IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], passwordEndInit);
    MODULE_DMU.HF_ECCW.B.PECENCDIS = 0U;
    IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], passwordEndInit);

    /* Make dummy read to trigger the ECC error */
    dummyRead = MEM(injectErrorAddressPF);

    /* Restore the interrupts state */
    IfxCpu_restoreInterrupts(interruptState);
}
