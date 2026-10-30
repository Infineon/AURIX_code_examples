/**
 * \file IfxFlash.h
 * \brief FLASH  basic functionality
 * \ingroup IfxLld_Flash
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
 * \defgroup IfxLld_Flash_Std_Enumerations Enumerations
 * \ingroup IfxLld_Flash_Std
 * \defgroup IfxLld_Flash_Std_CommandSequence CommandSequence Functions
 * \ingroup IfxLld_Flash_Std
 */

#ifndef IFXFLAS_H
#define IFXFLAS_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxFlash_cfg.h"
#include "_Utilities/Ifx_Assert.h"
#include "IfxDmu_reg.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Flash_Std_Enumerations
 * \{ */
/** \} */

/** \addtogroup IfxLld_Flash_Std_CommandSequence
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the operation and error flags for the specified flash module.
 *
 * \param[in] flash Selects the flash (PMU) module.
 *                  Range: 0 (This parameter is unused, given for backward compatibility)
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_clearStatus(uint32 flash);

/**
 * \brief Performs the sequence for entering program page mode for flash operations.
 *
 * \param[in] pageAddr specifies the page being written - the command sequence will be varied accordingly.
 *                     Range: 0xA0000000 to 0xA11FFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval uint8 0 on success, != 0 if invalid or not available page is selected.
 *
 * Usage Example:
 * \code
 *
 * unsigned int pageAddr = IFXFLASH_DFLASH_START + page*IFXFLASH_DFLASH_PAGE_LENGTH;
 *
 * // enter page mode
 * IfxFlash_enterPageMode(pageAddr);
 *
 * \endcode
 *
 */
IFX_INLINE uint8 IfxFlash_enterPageMode(uint32 pageAddr);

/**
 * \brief Performs the erase sequence for multiple sectors in program or data flash.
 *
 * \param[in] sectorAddr  The starting sector address to be erased.
 *                        Range: 0xA0000000 to 0xA0FFFFFF
 * \param[in] numSector   The number of sectors to be erased.
 *                        Range: 0 to 191
 *
 * The given ranges for TC39XB device variant. The ranges are differ variant to variant, refer the IfxFlash_Cfg file and UM.
 *
 * \retval None
 *
 * Usage Example:
 * \code
 *
 * // erase logical sectors of program flash
 *  IfxFlash_eraseMultipleSectors(pFlashTableLog[sector].start,2);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_eraseMultipleSectors(uint32 sectorAddr, uint32 numSector);

/**
 * \brief Performs the erase sequence for a specified sector in program or data flash.
 *
 * \param[in] sectorAddr  The address of the sector to be erased.
 *                        Range: 0xA0000000 to 0xA0FFFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 *
 * Usage Example:
 * \code
 *
 *
 * // erase all sectors of program flash
 * for(sector=0; sector<IFXFLASH_PFLASH_NO_OF_LOG_SECTORS; ++sector) {
 *   // get address from predefined table
 *   unsigned int sector_addr = pFlashTableLog[sector].start;
 *   // erase sector
 *  IfxFlash_eraseSector(sector_addr);
 * }
 *
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_eraseSector(uint32 sectorAddr);

/**
 * \brief Performs the "Erase Verify" sequence for multiple flash sectors starting from a specified address.
 *
 * \param[in] sectorAddr The starting sector address to be verified. Must be a valid flash sector address.
 *                       Range: 0xA0000000 to 0xA0FFFFFF
 * \param[in] numSector  The number of sectors to verify.
 *                       Range: 0 to 191
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_eraseVerifyMultipleSectors(uint32 sectorAddr, uint32 numSector);

/**
 * \brief Performs the "Erase Verify" sequence on the specified flash sector.
 *
 * \param[in] sectorAddr  The sector address to be verified. Must be a valid sector address within the flash memory space.
 *                        Range: 0xA0000000 to 0xA0FFFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_eraseVerifySector(uint32 sectorAddr);

/**
 * \brief Performs a load page sequence with a single 64bit access.
 *
 * \param[in] pageAddr pageAddr start address of page which should be programmed
 *                     Range: 0 to 0xFFFFFFFF
 * \param[in] wordL    Lower Address word.
 *                     Range: 0 to 0xFFFFFFFF
 * \param[in] wordU    Upper address word.
 *                     Range: 0 to 0xFFFFFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 *
 * Usage Example:
 * \code
 *
 * // load 64bit into assembly buffer of program flash
 * IfxFlash_loadPage(IFXFLASH_PFLASH_START, 0x55555555, 0xaaaaaaaa);
 *
 * // load 64bit into assembly buffer of data flash
 * IfxFlash_loadPage(0XAF000000, 0x55555555, 0xaaaaaaaa);
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_loadPage(uint32 pageAddr, uint32 wordL, uint32 wordU);

/**
 * \brief Performs a load page sequence with two 32-bit accesses.
 *
 * \param[in] pageAddr The start address of the page to be programmed.
 *                     Range: 0xA0000000 to 0xA11FFFFF
 * \param[in] wordL    Lower 32-bit word to be loaded into the assembly buffer.
 *                     Range: 0 to 0xFFFFFFFF
 * \param[in] wordU    Upper 32-bit word to be loaded into the assembly buffer.
 *                     Range: 0 to 0xFFFFFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 *
 * Usage Example:
 * \code
 *
 * // load 2*32bit into assembly buffer of program flash
 * IfxFlash_loadPage2X32(IFXFLASH_PFLASH_START, 0x55555555, 0xaaaaaaaa);
 *
 * // load 2*32bit into assembly buffer of data flash
 * IfxFlash_loadPage2X32(0XAF000000, 0x55555555, 0xaaaaaaaa);
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_loadPage2X32(uint32 pageAddr, uint32 wordL, uint32 wordU);

/**
 * \brief Resets the specified flash module to read mode.
 *
 * \param[in] flash  Selects the flash (PMU) module.
 *                   Range: 0 (This parameter is unused, given for backward compatibility)
 *
 * \retval None
 *
 * Usage Example:
 * \code
 *
 * // reset to read mode
 *  IfxFlash_resetToRead(0);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_resetToRead(uint32 flash);

/**
 * \brief Resumes the protection of the specified flash module.
 *
 * \param[in] flash Selects the flash (PMU) module.
 *            Range: 0 (This parameter is unused, given for backward compatibility)
 * 
 * \retval None
 */
IFX_INLINE void IfxFlash_resumeProtection(uint32 flash);

/**
 * \brief Suspends and resumes operations on multiple flash sectors.
 *
 * \param[in] sectorAddr  The starting sector address.
 *                        Range: 0xA0000000 to 0xA0FFFFFF
 * \param[in] numSector   The number of sectors to be operated on.
 *                        Range: 0 to 191
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_suspendResumeMultipleSectors(uint32 sectorAddr, uint32 numSector);

/**
 * \brief Performs the "Suspend Resume" sequence for a specified flash sector.
 *
 * \param[in] sectorAddr The address of the sector to be resumed.
 *                       Range: 0xA0000000 to 0xA0FFFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_suspendResumeSector(uint32 sectorAddr);

/**
 * \brief The function issues command sequence for User Content count.The result of this function is dependent on the
 * difference of the number of logic 1 bits in the selected pages at the  erase-verify condition (N_dv) and at the selected
 * control gate voltage (N_pv). Calling this function with different control gate voltages allows calculation of the Vth distribution.
 *
 * \param[in] wordAddr  The word address for which the User Content count is performed.
 *                      Range: 0 to 0xFFFFFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_userContentCount(uint32 wordAddr);

/**
 * \brief The function issues command sequence for User Margin Count. The result of this function is the number of logic 1 bits in the
 * selected pages at the selected reference current. Calling this function with different reference currents allows calculation of the
 * cell current distribution.
 *
 * \param[in] wordAddr The 32-bit word address indicating the starting location for the margin count operation.
 *                     Range: 0 to 0xFFFFFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_userMarginCount(uint32 wordAddr);

/**
 * \brief The function issues command sequence for User Vth Count.The result of this function is the number of logic 1 bits in the
 * selected pages at the selected control gate voltage. Calling this function with different control gate voltages allows calculation
 * of the Vth distribution.
 *
 * \param[in] wordAddr  The word address where the Vth count operation is performed.
 *                      Range: 0 to 0xFFFFFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_userVthCount(uint32 wordAddr);

/**
 * \brief Performs the "Verify Erased Block (page)" sequence. This command verifies if one page addressed by "PA" is correctly erased, i.e. contain 0 data and ECC bits.
 *
 * \param[in] pageAddr The page address which should be verified. The address must be a valid page address within the flash memory space.
 *                     Range: 0xA0000000 to 0xA11FFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_verifyErasedPage(uint32 pageAddr);

/**
 * \brief Performs the "Verify Erased WL" sequence.This command verifies if one word line addressed by "WA" is correctly erased, i.e. contain 0 data and ECC bits.
 *
 * \param[in] wordLineAddr The 32-bit address of the word line to be verified.
 *                         Range: 0 to 0xFFFFFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_verifyErasedWordLine(uint32 wordLineAddr);

/**
 * \brief Polls the selected status flag in the flash status register until it turns to 0.
 *
 * \param[in] flash      The flash (PMU) module to be checked.
 *                       Range: 0 (This parameter is unused, given for backward compatibility)
 * \param[in] flashType  The type of flash to be checked.
 *                       Range: \ref IfxFlash_FlashType.
 *
 * \retval uint8. 0 on success, != 0 if invalid or not available page is selected.
 *
 * Usage Example:
 * \code
 *
 * // wait until data flash 0 is unbusy
 *  IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);
 *
 * \endcode
 *
 */
IFX_INLINE uint8 IfxFlash_waitUnbusy(uint32 flash, IfxFlash_FlashType flashType);

/**
 * \brief Performs the "Write Burst" sequence, similar to write page but performs a burst transfer instead of page.Make
 * sure the appropriate amount of data is loaded using load page command.
 *
 * \param[in] pageAddr The start address of the page to be programmed.
 *                     The address must correspond to a valid page address in the flash memory.
 *                     Range: 0xA0000000 to 0xA11FFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 *
 * Usage Example:
 * \code
 *
 * // program the second page of the first sector of the Program Flash
 * IfxFlash_writeBurst(0xa0000100);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_writeBurst(uint32 pageAddr);

/**
 * \brief Performs the "Write Burst once" sequence. The command starts the programming process for an aligned group of pages as
 * the normal "Write Burst" does. But before programming it checks if the pages are erased. If the page is not erased
 * (allowing correctable errors) the command fails with PVER and EVER.
 * The command is only supported for PFlash. On sectors with "write-once" protection only this write command can be applied.
 *
 * \param[in] pageAddr The start address of the page to be programmed (must be a valid PFlash page address).
 *                     Range: 0xA0000000 to 0xA11FFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 *
 * Usage Example:
 * \code
 *
 * // program the second page of the first sector of the Program Flash
 * IfxFlash_writeBurstOnce(0xa0000100);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_writeBurstOnce(uint32 pageAddr);

/**
 * \brief Performs the "Write Page" sequence to program a specific page in the flash memory.
 *
 * \param[in] pageAddr The start address of the page to be programmed. The address must correspond to a valid page within the flash memory.
 *                     Range: 0xA0000000 to 0xA11FFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \return None
 *
 * Usage Example:
 * \code
 *
 * // program the second page of the first sector of the Program Flash
 * IfxFlash_writePage(0xa0000100);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_writePage(uint32 pageAddr);

/**
 * \brief Performs the "Write Page Once" sequence, which programs the specified page and performs a program verify after writing.
 *
 * \param[in] pageAddr The start address of the page to be programmed. This address must be aligned to the page size.
 *                     Range: 0xA0000000 to 0xA11FFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 *
 * Usage Example:
 * \code
 *
 * // program the second page of the first sector of the Program Flash
 * IfxFlash_writePageOnce(0xa0000100);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_writePageOnce(uint32 pageAddr);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief The password protection of the selected UCB (if this UCB offers this feature) is temporarily disabled.
 * The command fails by setting PROER when any of the supplied PWs does not match. In this case until the next
 * application reset all further calls of "Disable Protection" fail with PROER independent of the supplied password.
 *
 * \param[in] flash     Selects the flash (PMU) module.
 *                      Range: 0 (This parameter is unused, given for backward compatibility)
 * \param[in] ucb       Selects the user configuration block (UCB) (0 for UCB0, 1 for UCB1, 5 for UCB_HSMC).
 *                      Range: \ref IfxFlash_UcbType.
 * \param[in] password  Pointer to an array of 8 words containing the password.
 *                      Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 *
 * Usage Example:
 * \code
 *
 * uint32 ucbPassword[] = {0x01020304,0x11121314,0x21222324,0x31323334,
						   0x41424344,0x51525354,0x61626364,0x71727374};
 *
 * // disable write protection
 * IfxFlash_disableWriteProtection(0, IfxFlash_UcbType_ucbPflash, ucbPassword);
 *
 * \endcode
 */
IFX_EXTERN void IfxFlash_disableWriteProtection(uint32 flash, IfxFlash_UcbType ucb, uint32 *password);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Waits until all flash banks are out of the busy state.
 * 
 * \retval Return 0 on success.Success means none of the flash banks are in busy state.
 */
IFX_INLINE boolean IfxFlash_waitUnbusyAll(void);

/**
 * \brief Enter Flash Cranking Mode.
 *
 * \return None
 */
IFX_INLINE void IfxFlash_enterCrankingMode(void);

/**
 * \brief Exits the Flash Cranking Mode.
 * 
 * \retval None
 */
IFX_INLINE void IfxFlash_exitCrankingMode(void);

/**
 * \brief Enter the demand mode of the flash module.
 *
 * \return None
 */
IFX_INLINE void IfxFlash_enterDemandMode(void);

/**
 * \brief Exits the demand mode of the flash module.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_exitDemandMode(void);

/**
 * \brief Enters the dynamic idle mode of the flash module to reduce power consumption while allowing quick reactivation.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_enterDynamicIdleMode(void);

/**
 * \brief Exits the dynamic idle mode of the flash module.
 *
 * \return None
 */
IFX_INLINE void IfxFlash_exitDynamicIdleMode(void);

/**
 * \brief Checks if the Flash module is currently in Cranking Mode.
 * 
 * \retval TRUE  Flash module is in Cranking Mode.
 *         FALSE Flash module is not in Cranking Mode.
 */
IFX_INLINE boolean IfxFlash_isCrankingMode(void);

/**
 * \brief Checks if the Flash is currently operating in Demand Mode.
 * 
 * \retval TRUE  Flash is in Demand Mode.
 *         FALSE Flash is not in Demand Mode.
 */
IFX_INLINE boolean IfxFlash_isDemandMode(void);

/**
 * \brief Checks if the Flash module is currently in Dynamic Idle mode.
 *
 * \retval TRUE  Flash is in Dynamic Idle Mode.
 *         FALSE Flash is not in Dynamic Idle Mode.
 */
IFX_INLINE boolean IfxFlash_isDynamicIdleMode(void);

/**
 * \brief Replaces a logical sector in the flash memory.
 *
 * \param[in] pageAddr  The start address of the page which should be programmed.
 *                      Range: 0xA0000000 to 0xA11FFFFF
 *
 * \note: The ranges differ from variant to variant; refer to the IfxFlash_Cfg.h file.
 *
 * \retval None
 */
IFX_INLINE void IfxFlash_replaceLogicalSector(uint32 pageAddr);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxFlash_clearStatus(uint32 flash)
{
    IFX_UNUSED_PARAMETER(flash);
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x5554);

    *addr1 = 0xFA;

    __dsync();
}


IFX_INLINE uint8 IfxFlash_enterPageMode(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x5554);

    if ((pageAddr & 0xff000000) == 0xa0000000)    /* program flash */
    {
        *addr1 = 0x50;
        return 0;
    }
    else if ((pageAddr & 0xff000000) == 0xaf000000)       /* data flash */
    {
        *addr1 = 0x5D;
        return 0;
    }

    __dsync();
    return 1; /* invalid flash address */
}


IFX_INLINE void IfxFlash_eraseMultipleSectors(uint32 sectorAddr, uint32 numSector)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = numSector;
    *addr3 = 0x80;
    *addr4 = 0x50;

    __dsync();
}


IFX_INLINE void IfxFlash_eraseSector(uint32 sectorAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = 1;
    *addr3 = 0x80;
    *addr4 = 0x50;

    __dsync();
}


IFX_INLINE void IfxFlash_eraseVerifyMultipleSectors(uint32 sectorAddr, uint32 numSector)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = numSector;
    *addr3 = 0x80;
    *addr4 = 0x5F;

    __dsync();
}


IFX_INLINE void IfxFlash_eraseVerifySector(uint32 sectorAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = 1;
    *addr3 = 0x80;
    *addr4 = 0x5F;

    __dsync();
}


IFX_INLINE void IfxFlash_loadPage(uint32 pageAddr, uint32 wordL, uint32 wordU)
{
    IFX_UNUSED_PARAMETER(pageAddr);
    uint64 *addr1 = (uint64 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x55f0);

    __st64_lu(addr1, wordL, wordU);

    __dsync();
}


IFX_INLINE void IfxFlash_loadPage2X32(uint32 pageAddr, uint32 wordL, uint32 wordU)
{
    IFX_UNUSED_PARAMETER(pageAddr);

    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x55f0);
    __dsync(); /* Ensure residual operations are out of the store buffers */
    *addr1 = wordL;
    addr1++;
    __dsync(); /* Purge store buffers to avoid merging into 64-bit writes */
    *addr1 = wordU;
    __dsync(); /* Purge store buffers to avoid merging into 64-bit writes */
}


IFX_INLINE void IfxFlash_resetToRead(uint32 flash)
{
    IFX_UNUSED_PARAMETER(flash);
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x5554);
    *addr1 = 0xf0;

    __dsync();
}


IFX_INLINE void IfxFlash_resumeProtection(uint32 flash)
{
    IFX_UNUSED_PARAMETER(flash);

    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x5554);

    *addr1 = 0xF5;

    __dsync();
}


IFX_INLINE void IfxFlash_suspendResumeMultipleSectors(uint32 sectorAddr, uint32 numSector)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = numSector;
    *addr3 = 0x70;
    *addr4 = 0xCC;

    __dsync();
}


IFX_INLINE void IfxFlash_suspendResumeSector(uint32 sectorAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = 1;
    *addr3 = 0x70;
    *addr4 = 0xCC;

    __dsync();
}


IFX_INLINE void IfxFlash_userContentCount(uint32 wordAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = wordAddr;
    *addr2 = 0x00;
    *addr3 = 0x60;
    *addr4 = 0x14;
    __dsync();
}


IFX_INLINE void IfxFlash_userMarginCount(uint32 wordAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = wordAddr;
    *addr2 = 0x00;
    *addr3 = 0x60;
    *addr4 = 0x11;
    __dsync();
}


IFX_INLINE void IfxFlash_userVthCount(uint32 wordAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = wordAddr;
    *addr2 = 0x00;
    *addr3 = 0x60;
    *addr4 = 0x12;
    __dsync();
}


IFX_INLINE void IfxFlash_verifyErasedPage(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 00;
    *addr3 = 0x80;
    *addr4 = 0x56;

    __dsync();
}


IFX_INLINE void IfxFlash_verifyErasedWordLine(uint32 wordLineAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = wordLineAddr;
    *addr2 = 00;
    *addr3 = 0x80;
    *addr4 = 0x58;

    __dsync();
}


IFX_INLINE uint8 IfxFlash_waitUnbusy(uint32 flash, IfxFlash_FlashType flashType)
{
    if (flash == 0)
    {
        while (DMU_HF_STATUS.U & (1 << flashType))
        {}
    }
    else
    {
        return 1;    /*invalid flash selected */
    }

    __dsync();
    return 0; /* finished */
}


IFX_INLINE void IfxFlash_writeBurst(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xa6;

    __dsync();
}


IFX_INLINE void IfxFlash_writeBurstOnce(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xa4;

    __dsync();
}


IFX_INLINE void IfxFlash_writePage(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xaa;

    __dsync();
}


IFX_INLINE void IfxFlash_writePageOnce(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xa8;

    __dsync();
}


IFX_INLINE boolean IfxFlash_waitUnbusyAll(void)
{
#ifdef DEVICE_TC33X
    while (DMU_HF_STATUS.U & IFXFLASH_PFLASH_BUSY_STATUS_MASK)
    {}
#elif defined(DEVICE_TC33XED) || defined(DEVICE_TC36X)
	while (DMU_HF_STATUS.U & IFXFLASH_PFLASH_BUSY_STATUS_MASK)
	{}
#elif defined(DEVICE_TC37X) || defined(DEVICE_TC37XED) || defined (DEVICE_TC35X) 
	while (DMU_HF_STATUS.U & IFXFLASH_PFLASH_BUSY_STATUS_MASK)
    {}
#elif defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X)
	while (DMU_HF_STATUS.U & IFXFLASH_PFLASH_BUSY_STATUS_MASK)
	{}
#elif defined(DEVICE_TC39XB)
	while (DMU_HF_STATUS.U & IFXFLASH_PFLASH_BUSY_STATUS_MASK)
    {}
#endif

    __dsync();
    return 0;

}


IFX_INLINE void IfxFlash_enterCrankingMode(void)
{
    DMU_HF_CCONTROL.B.CRANKING = 3U;
    __dsync();
}


IFX_INLINE void IfxFlash_exitCrankingMode(void)
{
    DMU_HF_CCONTROL.B.CRANKING = 0U;
    __dsync();
}


IFX_INLINE void IfxFlash_enterDemandMode(void)
{
    DMU_HF_PCONTROL.B.DEMAND = 3U;
    __dsync();
}


IFX_INLINE void IfxFlash_exitDemandMode(void)
{
    DMU_HF_PCONTROL.B.DEMAND = 0U;
    __dsync();
}


IFX_INLINE void IfxFlash_enterDynamicIdleMode(void)
{
    DMU_HF_PCONTROL.B.IDLE = 3U;
    __dsync();
}


IFX_INLINE void IfxFlash_exitDynamicIdleMode(void)
{
    DMU_HF_PCONTROL.B.IDLE = 0U;
    __dsync();
}


IFX_INLINE boolean IfxFlash_isCrankingMode(void)
{
    return (boolean)(DMU_HF_CCONTROL.B.CRANKING == 0x3U);
}


IFX_INLINE boolean IfxFlash_isDemandMode(void)
{
    return (boolean)(DMU_HF_PSTATUS.B.DEMAND == 1U);
}


IFX_INLINE boolean IfxFlash_isDynamicIdleMode(void)
{
    return (boolean)(DMU_HF_PSTATUS.B.IDLE == 1U);
}


IFX_INLINE void IfxFlash_replaceLogicalSector(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xac;

    __dsync();
}


#endif /* IFXFLAS_H */
