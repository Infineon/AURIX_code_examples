/**
 * \file IfxFce.h
 * \brief FCE  basic functionality
 * \ingroup IfxLld_Fce
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
 * \defgroup IfxLld_Fce_Std_Enum Enumerations
 * \ingroup IfxLld_Fce_Std
 * \defgroup IfxLld_Fce_Std_Module Module Functions
 * \ingroup IfxLld_Fce_Std
 * \defgroup IfxLld_Fce_Std_Support Support Function
 * \ingroup IfxLld_Fce_Std
 * \defgroup IfxLld_Fce_Std_InterruptStatus Interrupt Status Functions
 * \ingroup IfxLld_Fce_Std
 */

#ifndef IFXFCE_H
#define IFXFCE_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxFce_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Scu/Std/IfxScuWdt.h"
#include "IfxFce_reg.h"
#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Fce_Std_Enum
 * \{ */
/** \brief Ifx_FCE_CHx(x= 0,1), Specifies the channel used for CRC
 * Definition in Ifx_FCE.IN[x]; (x = 0 to 7)
 */
typedef enum
{
    IfxFce_CrcChannel_0 = 0,      /**< \brief Specifies the channel0 used for CRC  */
    IfxFce_CrcChannel_1,          /**< \brief Specifies the channel1 used for CRC  */
    IfxFce_CrcChannel_2,          /**< \brief Specifies the channel2 used for CRC  */
    IfxFce_CrcChannel_3,          /**< \brief Specifies the channel3 used for CRC  */
    IfxFce_CrcChannel_4,          /**< \brief Specifies the channel4 used for CRC  */
    IfxFce_CrcChannel_5,          /**< \brief Specifies the channel5 used for CRC  */
    IfxFce_CrcChannel_6,          /**< \brief Specifies the channel6 used for CRC  */
    IfxFce_CrcChannel_7           /**< \brief Specifies the channel7 used for CRC  */
} IfxFce_CrcChannel;

/** \} */

/** \brief Specify the CRC kernel used by the fce channel
 * Definition in Ifx_FCE_IN_CFG.B.KERNEL
 */
typedef enum
{
    IfxFce_CrcKernel_0 = 0,  /**< \brief Specifies to use kernel 0 */
    IfxFce_CrcKernel_1 = 1,  /**< \brief Specifies to use kernel 1 */
    IfxFce_CrcKernel_2 = 2,  /**< \brief Specifies to use kernel 2 */
    IfxFce_CrcKernel_3 = 3   /**< \brief Specifies to use kernel 3 */
} IfxFce_CrcKernel;

/** \addtogroup IfxLld_Fce_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the control of the FCE module.
 *
 * \param[inout] fce Pointer to the FCE module registers.
 * 
 * \retval None
 */
IFX_INLINE void IfxFce_disableModule(Ifx_FCE *fce);

/**
 * \brief Enables the control of the FCE module.
 *
 * \param[inout] fce Pointer to the FCE module registers.
 *
 * \retval None
 */
IFX_INLINE void IfxFce_enableModule(Ifx_FCE *fce);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Resets the FCE module by clearing the kernel.
 *
 * \param[inout] fce Pointer to the FCE module registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxFce_resetModule(Ifx_FCE *fce);

/** \} */

/** \addtogroup IfxLld_Fce_Std_Support
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reflects the CRC data by reversing its bits and returns the result.
 *
 * \param[in] crcStartValue The initial CRC value to be reflected.
 * 							Range: 0 to 0xFFFFFFFF
 * \param[in] crcLength     The length of the CRC value to be reflected. Valid lengths are typically 8, 16, or 32 bits.
 * 							Range: 0 to 0xFF
 *
 * \retval uint32 The reflected CRC data after the bit-wise reflection process.
 * 				  Range: 0 to 0xFFFFFFFF
 */
IFX_EXTERN uint32 IfxFce_reflectCrc32(uint32 crcStartValue, uint8 crcLength);

/** \} */

/** \addtogroup IfxLld_Fce_Std_InterruptStatus
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Returns the SRC pointer for FCE
 *
 * \param[in] fce Pointer to the FCE module registers.
 * 
 * \retval Ifx_SRC_SRCR Pointer to the source control register (SRCR) of the FCE module.
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxFce_getSrcPointer(Ifx_FCE *fce);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the CRC error flags for the specified channel in the FCE module.
 *
 * \param[inout] fce     Pointer to the FCE module registers.
 * \param[in]    channel Specifies the CRC channel for which the error flags should be cleared.
 *                       Range: \ref IfxFce_CrcChannel
 *
 * \retval None
 */
IFX_INLINE void IfxFce_clearCrcErrorFlags(Ifx_FCE *fce, IfxFce_CrcChannel channel);

/**
 * \brief Gets the CRC interrupt status for a specified channel
 *
 * \param[in] fce     Pointer to the FCE module registers.
 * \param[in] channel Specifies the CRC channel to query.
 * 					  Range: \ref IfxFce_CrcChannel
 *
 * \retval Ifx_FCE_IN_STS The interrupt status of the specified CRC channel.
 */
IFX_INLINE Ifx_FCE_IN_STS IfxFce_getCrcInterruptStatus(Ifx_FCE *fce, IfxFce_CrcChannel channel);

/**
 * \brief Set the length of over which CRC checksum is calculated.
 *
 * \param[inout] fce       Pointer to the FCE module registers.
 * \param[in]    channel   Specifies the channel for which the CRC length is to be set.
 *                         Range: \ref IfxFce_CrcChannel
 * \param[in]    crcLength Specifies the length of the CRC checksum in bits.
 *                         Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxFce_setChannelCrcLength(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcLength);

/**
 * \brief Sets the CRC start value for the specified channel in the FCE module.
 *
 * \param[inout] fce           Pointer to the FCE module registers.
 * \param[in]    channel       Specifies the CRC channel to configure.
 * 					           Range: \ref IfxFce_CrcChannel
 * \param[in]    crcStartValue The initial CRC value to be set.
 *                             Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxFce_setCrcstartValue(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcStartValue);

/**
 * \brief Sets the expected CRC value to be checked for the specified channel.
 *
 * \param[inout] fce         Pointer to the FCE module registers.
 * \param[in]    channel     Specifies the CRC channel to configure.
 * 						     Range: \ref IfxFce_CrcChannel
 * \param[in]    expectedCrc The expected CRC value to be checked.
 * 						     Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxFce_setExpectedCrc(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 expectedCrc);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxFce_clearCrcErrorFlags(Ifx_FCE *fce, IfxFce_CrcChannel channel)
{
    fce->IN[channel].STS.U = 0x00000000U;
}


IFX_INLINE void IfxFce_disableModule(Ifx_FCE *fce)
{
    uint16 password = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(password);
    fce->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(password);
}


IFX_INLINE void IfxFce_enableModule(Ifx_FCE *fce)
{
    uint16 password = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(password);
    fce->CLC.B.DISR = 0;
    IfxScuWdt_setCpuEndinit(password);
}


IFX_INLINE Ifx_FCE_IN_STS IfxFce_getCrcInterruptStatus(Ifx_FCE *fce, IfxFce_CrcChannel channel)
{
    Ifx_FCE_IN_STS interruptStatus;
    interruptStatus.U = fce->IN[channel].STS.U;

    return interruptStatus;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxFce_getSrcPointer(Ifx_FCE *fce)
{
    IFX_UNUSED_PARAMETER(fce);
    return &SRC_FCE0;
}


IFX_INLINE void IfxFce_setChannelCrcLength(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcLength)
{
    /*write the dafault value 0xFACECAFE to the register */
    fce->IN[channel].LENGTH.U = 0xFACECAFE;
    fce->IN[channel].LENGTH.U = crcLength;
}


IFX_INLINE void IfxFce_setCrcstartValue(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcStartValue)
{
    fce->IN[channel].CRC.U = crcStartValue;
}


IFX_INLINE void IfxFce_setExpectedCrc(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 expectedCrc)
{
    /*write the dafault value 0xFACECAFE to the register */
    fce->IN[channel].CHECK.U = 0xFACECAFE;
    fce->IN[channel].CHECK.U = expectedCrc;
}


#endif /* IFXFCE_H */
