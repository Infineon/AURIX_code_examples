/**
 * \file IfxEmem.h
 * \brief EMEM  basic functionality
 * \ingroup IfxLld_Emem
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Emem_Std_Usage How to use the EMEM Driver?
 * \ingroup IfxLld_Emem_Std
 *
 * The EMEM contains RAM blocks (EMEM Tiles) which can be alternatively used for application
 * (ADAS), calibration or trace data storage. The EMEM has interfaces to MCDS, SEP, SRI and BBB.
 *
 * In the following sections it will be described, how to integrate the Emem driver into the application framework.
 *
 * \section IfxLld_Emem_Std_Preparation Preparation
 * \subsection IfxLld_Emem_Std_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 *     #include <Emem/Std/IfxEmem.h>
 * \endcode
 *
 *
 * \subsection IfxLld_Emem_Std_Initialization Initialization
 *
 * \code
 * #define MEM(address) (*((volatile unsigned int *)(address)))
 *
 * IfxEmem_enableModule(&MODULE_EMEM); //Enable clock to the module
 * IfxEmem_setUnlockMode(&MODULE_EMEM); //Set the RAM to Unlock mode
 *
 * // First step: set all Tiles to unused mode
 * IfxEmem_setTileConfigMode(IfxEmem_TileConfigMode_unusedMode,IfxEmem_TileNumber_0);
 * IfxEmem_setTileConfigMode(IfxEmem_TileConfigMode_unusedMode,IfxEmem_TileNumber_1);
 *    .
 *    .
 * IfxEmem_setTileConfigMode(IfxEmem_TileConfigMode_unusedMode,IfxEmem_TileNumber_15);
 *
 * // Second step: set all Tiles to common memory mode
 * IfxEmem_setTileConfigMode(IfxEmem_TileConfigMode_calibMode,IfxEmem_TileNumber_0);
 * IfxEmem_setTileConfigMode(IfxEmem_TileConfigMode_calibMode,IfxEmem_TileNumber_1);
 *    .
 *    .
 * IfxEmem_setTileConfigMode(IfxEmem_TileConfigMode_calibMode,IfxEmem_TileNumber_15);
 *
 * // Disable ECC_ERR before initialization
 * IfxEmem_disableEccErrorReporting(IfxEmem_MpuIndex_0);
 * IfxEmem_disableEccErrorReporting(IfxEmem_MpuIndex_1);
 * IfxEmem_disableEccErrorReporting(IfxEmem_MpuIndex_2);
 * IfxEmem_disableEccErrorReporting(IfxEmem_MpuIndex_3);
 *
 * uint32 i=0;
 *
 * for(i=0;i<=15;i++)
 * {
 *         MEM(IFXEMEM_START_ADDR_CPU + i*32) = 0xAAAAAAAA;
 * }
 *
 * // Enable ECC_ERR after initialization
 * IfxEmem_enableEccErrorReporting(IfxEmem_MpuIndex_0);
 * IfxEmem_enableEccErrorReporting(IfxEmem_MpuIndex_1);
 * IfxEmem_enableEccErrorReporting(IfxEmem_MpuIndex_2);
 * IfxEmem_enableEccErrorReporting(IfxEmem_MpuIndex_3);
 * \endcode
 *
 * \subsection IfxLld_Emem_Std_Writing_and_Reading Writing to and Reading from EMEM RAM
 *
 * \code
 * // Writing into EMEM RAM
 * for(i=0;i<=15;i++)
 * {
 *     MEM(IFXEMEM_START_ADDR_CPU + i*32) = 0x55555555;
 * }
 *
 * // Reading from EMEM RAM and comparing with expected value
 * for(i=0;i<=15;i++)
 * {
 *     if(0x55555555 != MEM(IFXEMEM_START_ADDR_CPU + i*32))
 *     {
 *        // Error: Mismatch in value
 *     }
 * }
 * \endcode
 *
 * \defgroup IfxLld_Emem_Std_Enumerations Enumerations
 * \ingroup IfxLld_Emem_Std
 * \defgroup IfxLld_Emem_Std_Module Module Functions
 * \ingroup IfxLld_Emem_Std
 */

#ifndef IFXEMEM_H
#define IFXEMEM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxEmem_cfg.h"
#include "Scu/Std/IfxScuWdt.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Emem_Std_Enumerations
 * \{ */
/** \brief EMEM tile configuration mode defined in MODULE_EMEM.TILECONFIGXM.B.Tx( x = 0,1,..).
 */
typedef enum
{
    IfxEmem_ExtendMemoryConfigMode_calibMode  = 0, /**< \brief EMEM tile mode to calibration memory. */
    IfxEmem_ExtendMemoryConfigMode_adasMode   = 1, /**< \brief EMEM tile mode to ADAS memory. */
    IfxEmem_ExtendMemoryConfigMode_unusedMode = 3  /**< \brief Tile in Unused Mode */
} IfxEmem_ExtendMemoryConfigMode;

/** \brief EMEM lock state defined in MODULE_EMEM.SBRCTR.B.STBLOCK.
 */
typedef enum
{
    IfxEmem_LockedState_locked   = 0, /**< \brief EMEM locked state. */
    IfxEmem_LockedState_unlocked = 1  /**< \brief EMEM unlocked state. */
} IfxEmem_LockedState;

/** \brief EMEM module clock enabled or disabled state defined in MODULE_EMEM.CLC.B.DISR.
 */
typedef enum
{
    IfxEmem_State_disabled = 0,  /**< \brief EMEM module clock disabled state. */
    IfxEmem_State_enabled  = 1   /**< \brief EMEM module clock enabled state. */
} IfxEmem_State;

/** \brief EMEM tile configuration mode defined in MODULE_EMEM.TILECONFIG.B.Tx( x = 0,1,..).
 */
typedef enum
{
    IfxEmem_TileConfigMode_calibMode        = 0, /**< \brief EMEM tile mode to calibration memory. */
    IfxEmem_TileConfigMode_traceMode        = 2, /**< \brief EMEM tile mode to Trace memory. */
    IfxEmem_TileConfigMode_unusedMode       = 3, /**< \brief Tile in Unused Mode */
    IfxEmem_TileConfigMode_commonMemoryMode = 0  /**< \brief EMEM Tile to be configured to Common Memory Mode */
} IfxEmem_TileConfigMode;

/** \brief Tile Number
 */
typedef enum
{
    IfxEmem_TileNumber_0 = 0,      /**< \brief Tile Number0  */
    IfxEmem_TileNumber_1,          /**< \brief Tile Number1  */
    IfxEmem_TileNumber_2,          /**< \brief Tile Number2  */
    IfxEmem_TileNumber_3,          /**< \brief Tile Number3  */
    IfxEmem_TileNumber_4,          /**< \brief Tile Number4  */
    IfxEmem_TileNumber_5,          /**< \brief Tile Number5  */
    IfxEmem_TileNumber_6,          /**< \brief Tile Number6  */
    IfxEmem_TileNumber_7,          /**< \brief Tile Number7  */
    IfxEmem_TileNumber_8,          /**< \brief Tile Number8  */
    IfxEmem_TileNumber_9,          /**< \brief Tile Number9  */
    IfxEmem_TileNumber_10,         /**< \brief Tile Number10  */
    IfxEmem_TileNumber_11,         /**< \brief Tile Number11  */
    IfxEmem_TileNumber_12,         /**< \brief Tile Number12  */
    IfxEmem_TileNumber_13,         /**< \brief Tile Number13  */
    IfxEmem_TileNumber_14,         /**< \brief Tile Number14  */
    IfxEmem_TileNumber_15          /**< \brief Tile Number15  */
} IfxEmem_TileNumber;

/** \} */

/** \addtogroup IfxLld_Emem_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Checks if the EMEM module is enabled.
 *
 * \retval TRUE If module is enabled.
 *         FALSE If module is disabled.
 */
IFX_INLINE boolean IfxEmem_isModuleEnabled(void);

/**
 * \brief Set the tile to calibration/BBB mode
 * 
 * \param[in] calibrationMode Boolean flag to enable calibration/BBB Mode. Range: TRUE = Tool Mode, FALSE = Application/ADAS Mode
 * \param[in] tile            Tile number to configure. Range: \ref IfxEmem_TileNumber
 * 
 * \retval None
 */
IFX_INLINE void IfxEmem_setCalibrationTileControlMode(boolean calibrationMode, IfxEmem_TileNumber tile);

/**
 * \brief Sets the configuration mode for a specific EMEM tile.
 *
 * \param[in] mode The configuration mode to be set for the EMEM tile. Range: \ref IfxEmem_TileConfigMode
 * \param[in] tile The tile number to configure. Range: \ref IfxEmem_TileNumber
 *
 * \retval None
 */
IFX_INLINE void IfxEmem_setTileConfigMode(const IfxEmem_TileConfigMode mode, IfxEmem_TileNumber tile);

/**
 * \brief Configures the specified EMEM tile to operate in Trace or BBB mode.
 *
 * \param[in] traceMode Boolean flag to enable trace/BBB mode. Range: TRUE = Tool Mode, FALSE = MCDS Mode
 * \param[in] tile      The tile number to configure. Range: \ref IfxEmem_TileNumber
 *
 * \retval None
 */
IFX_INLINE void IfxEmem_setTraceTileControlMode(boolean traceMode, IfxEmem_TileNumber tile);

/**
 * \brief Sets the unlock standby lock flag.
 * 
 * \param[in] flag The unlock standby lock flag value. Range: 0 to 7
 * 
 * \retval None
 */
IFX_INLINE void IfxEmem_setUnlockStandbyLockFlag(const uint8 flag);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the current lock state of the EMEM stand RAM.
 *
 * \retval IfxEmem_LockedState EMEM stand RAM lock state. Range: \ref IfxEmem_LockedState
 */
IFX_EXTERN IfxEmem_LockedState IfxEmem_getLockedState(void);

/**
 * \brief Sets state of the EMEM module clock.
 * 
 * \note Do not use this API for enabling and disabling EMEM without handling Endinit protection in the application.
 * For complete enable and disable of EMEM with Endinit protection handling, please use the following APIs:
 * \see IfxEmem_enableModule
 * \see IfxEmem_disableModule
 *
 * \param[in] state EMEM module clock enabled or disabled state. Range: \ref IfxEmem_State
 *
 * \retval None
 */
IFX_EXTERN void IfxEmem_setClockEnableState(const IfxEmem_State state);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Unlocks the EMEM RAM areas for bus accesses (RW).
 * 
 * \note After a Power On Reset, the SRAM initialization sequence has to be executed atleast once following the Unlock sequence.
 *
 * \param[inout] ememCore Pointer to the EMEM core registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxEmem_setUnlockMode(Ifx_EMEM *ememCore);

/**
 * \brief Enables the EMEM module.
 *
 * \param[inout] ememCore Pointer to the EMEM core registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxEmem_enableModule(Ifx_EMEM *ememCore);

/**
 * \brief Disables the EMEM module.
 *
 * \param[inout] ememCore Pointer to the EMEM core registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxEmem_disableModule(Ifx_EMEM *ememCore);

/**
 * \brief Disables ECC error reporting for the specified memory protection unit by writing into MODULE_EMEMx.MEMCON.B.ERRDIS register.
 *
 * \param[in] mpuIndex Index of the EMEM memory protection unit. Range: \ref IfxEmem_MpuIndex
 *
 * \retval None
 */
IFX_EXTERN void IfxEmem_disableEccErrorReporting(IfxEmem_MpuIndex mpuIndex);

/**
 * \brief Enables ECC error reporting for the specified memory protection unit by writing into the MODULE_EMEMx.MEMCON.B.ERRDIS register.
 *
 * \param[in] mpuIndex Index of the EMEM memory protection unit. Range: \ref IfxEmem_MpuIndex
 *
 * \retval None
 */
IFX_EXTERN void IfxEmem_enableEccErrorReporting(IfxEmem_MpuIndex mpuIndex);

/**
 * \brief Retrieves the index of an EMEM MPU instance based on the provided EMEM MPU base SFR pointer.
 *
 * \param[in] ememMpu Pointer to the EMEM MPU base SFR.
 *
 * \retval IfxEmem_MpuIndex The index of the EMEM MPU instance. Range: \ref IfxEmem_MpuIndex
 */
IFX_EXTERN IfxEmem_MpuIndex IfxEmem_getIndex(Ifx_EMEM_MPU *ememMpu);

/**
 * \brief Retrieves the address of an EMEM MPU instance based on the given index.
 *
 * \param[in] ememMpu Index of the EMEM MPU instance to retrieve the address. Range: \ref IfxEmem_MpuIndex
 *
 * \retval Ifx_EMEM_MPU* Address of the EMEM MPU instance given by Index number.
 */
IFX_EXTERN Ifx_EMEM_MPU *IfxEmem_getAddress(IfxEmem_MpuIndex ememMpu);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxEmem_isModuleEnabled(void)
{
    return (MODULE_EMEM.CLC.B.DISS == 0) ? TRUE : FALSE;
}


IFX_INLINE void IfxEmem_setCalibrationTileControlMode(boolean calibrationMode, IfxEmem_TileNumber tile)
{
    MODULE_EMEM.TILECC.U |= (uint32)(calibrationMode << tile);
}


IFX_INLINE void IfxEmem_setTileConfigMode(const IfxEmem_TileConfigMode mode, IfxEmem_TileNumber tile)
{
    uint32 shift = tile * 2;
    uint32 mask  = ~(0x3 << shift);
    uint32 value = (uint32)mode << shift;
    MODULE_EMEM.TILECONFIG.U = (MODULE_EMEM.TILESTATE.U & mask) | value;
}


IFX_INLINE void IfxEmem_setTraceTileControlMode(boolean traceMode, IfxEmem_TileNumber tile)
{
    MODULE_EMEM.TILECT.U |= (uint32)(traceMode << tile);
}


IFX_INLINE void IfxEmem_setUnlockStandbyLockFlag(const uint8 flag)
{
    if (8 > flag)
    {
        MODULE_EMEM.SBRCTR.B.STBULK = flag;
    }
}


#endif /* IFXEMEM_H */
