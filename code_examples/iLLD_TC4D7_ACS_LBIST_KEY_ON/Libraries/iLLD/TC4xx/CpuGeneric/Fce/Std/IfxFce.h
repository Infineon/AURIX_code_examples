/**
 * \file IfxFce.h
 * \brief FCE  basic functionality
 * \ingroup IfxLld_Fce
 *
 * \version iLLD-TC4-v2.6.0
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
#if !defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif
#include "IfxFce_reg.h"
#include "Src/Std/IfxSrc.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"
#if defined(IFX_ILLD_PPU_USAGE)
#include "Ppu/Std/IfxPpu_Intrinsics.h"
#endif

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

/** \brief Disable the control of FCE module.
 *
 * \param[inout] fce Specifies pointer to FCE module registers.
 *
 * \retval None
 */
IFX_INLINE void IfxFce_disableModule(Ifx_FCE *fce);

/** \brief Enable the control of FCE module.
 *
 * \param[inout] fce Specifies pointer to FCE module registers.
 *
 * \retval None
 */
IFX_INLINE void IfxFce_enableModule(Ifx_FCE *fce);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Reset the module to its initial state by clearing the kernel.
 *
 * \param[inout] fce Specifies pointer to FCE module registers.
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

/** \brief Reflects the CRC data and returns it.
 *
 * \param[in] crcStartValue The initial CRC32 value to be reflected. Range: 0 to 0xFFFFFFFF.
 * \param[in] crcLength     The number of bytes to reflect the CRC value over. Range: 0 to 0xFF.
 *
 * \retval uint32 Reflected CRC data. Range: 0 to 0xFFFFFFFF.
 */
IFX_EXTERN uint32 IfxFce_reflectCrc32(uint32 crcStartValue, uint8 crcLength);

/** \} */

/** \addtogroup IfxLld_Fce_Std_InterruptStatus
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Retrieves a pointer to the source configuration register (SRCR) for the given FCE instance.
 *
 * \param[in] fce Specifies pointer to FCE module registers.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the source control register (SRCR) of the FCE module.
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxFce_getSrcPointer(Ifx_FCE *fce);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Specifies pointer to FCE module registers.
 *
 * \param[inout] fce     Specifies the pointer to FCE module handler.
 * \param[in]    channel Specifies the Channel. Range: \ref IfxFce_CrcChannel.
 *
 * \retval None
 */
IFX_INLINE void IfxFce_clearCrcErrorFlags(Ifx_FCE *fce, IfxFce_CrcChannel channel);

/** \brief Retrieves the CRC interrupt status for the specified channel.
 *
 * \param[in] fce     Specifies pointer to FCE module registers.
 * \param[in] channel Specifies the Channel. Range: \ref IfxFce_CrcChannel.
 *
 * \retval Ifx_FCE_IN_STS Return Crc Interrupt Status.
 */
IFX_INLINE Ifx_FCE_IN_STS IfxFce_getCrcInterruptStatus(Ifx_FCE *fce, IfxFce_CrcChannel channel);

/** \brief Set the length of over which CRC checksum is calculated.
 *
 * \param[inout] fce       Specifies pointer to FCE module registers.
 * \param[in]    channel   Specifies the channel. Range: \ref IfxFce_CrcChannel.
 * \param[in]    crcLength Specifies the Length of CRC. Range: 0 to 0xFFFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxFce_setChannelCrcLength(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcLength);

/** \brief Sets the CRC start value for the specified CRC channel in the FCE module.
 *
 * \param[inout] fce           Specifies pointer to FCE module registers.
 * \param[in]    channel       Specifies the CRC channel for which the start value is to be set. Range: \ref IfxFce_CrcChannel.
 * \param[in]    crcStartValue The initial value for the CRC calculation. This 32-bit value isused to seed the CRC algorithm. The choice of the start value
 *                             depends on the specific communication protocol or application requirements. Range: 0 to 0xFFFFFFFF.
 *
 * \retval None
 */
IFX_INLINE void IfxFce_setCrcstartValue(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 crcStartValue);

/** \brief Set expected crc value to be checked.
 *
 * \param[inout] fce         Specifies pointer to FCE module registers
 * \param[in]    channel     Specifies the channel. Range: \ref IfxFce_CrcChannel.
 * \param[in]    expectedCrc Expected CRC value to be checked.
 *
 * \retval None
 */
IFX_INLINE void IfxFce_setExpectedCrc(Ifx_FCE *fce, IfxFce_CrcChannel channel, uint32 expectedCrc);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configures access to the FCE (Function Control Engine) module.
 *
 * \param[in] apConfig config pointer to configuration structure.
 *
 * \retval None
 */
IFX_EXTERN void IfxFce_configureAccessToFce(IfxApApu_ApuConfig *apConfig);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxFce_clearCrcErrorFlags(Ifx_FCE *fce, IfxFce_CrcChannel channel)
{
    fce->IN[channel].STS.U = 0x00000000U;
}


IFX_INLINE void IfxFce_disableModule(Ifx_FCE *fce)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_config);
#endif
    fce->CLC.B.DISR = 1;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_run);
#endif
}


IFX_INLINE void IfxFce_enableModule(Ifx_FCE *fce)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_config);
#endif
    fce->CLC.B.DISR = 0;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&fce->PROTE, IfxApProt_State_run);
#endif
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
    return &SRC_FCE;
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
