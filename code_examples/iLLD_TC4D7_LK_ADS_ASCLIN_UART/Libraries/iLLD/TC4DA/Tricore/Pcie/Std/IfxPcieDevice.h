/**
 * \file IfxPcieDevice.h
 * \brief PCIE  basic functionality
 * \ingroup IfxLld_Pcie
 *
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2023 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 * \defgroup IfxLld_Pcie_Std_Device Device Basic Functionality
 * \ingroup IfxLld_Pcie_Std
 * \defgroup IfxLld_Pcie_Std_Device_Enumerations Enumerations
 * \ingroup IfxLld_Pcie_Std_Device
 * \defgroup IfxLld_Pcie_Std_Device_Structures Structures
 * \ingroup IfxLld_Pcie_Std_Device
 * \defgroup IfxLld_Pcie_Std_Device_Funcctions Functions
 * \ingroup IfxLld_Pcie_Std_Device
 */

#ifndef IFXPCIEDEVICE_H
#define IFXPCIEDEVICE_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Pcie/Std/IfxPcie.h"
#include "_Impl/IfxPcie_cfg.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Get Interrupt Pin from Interrupt Vector
 */
#define IFXPCIEDEVICE_GET_INTERRUPT_PIN_FROM_VECTOR(vector) ((uint8)(vector - IfxPcie_IntVector_remote4MsiIntA + 1u))

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pcie_Std_Device_Enumerations
 * \{ */
/** \brief device type
 */
typedef enum
{
    IfxPcieDevice_Type_endpoint,
    IfxPcieDevice_Type_bridge,
    IfxPcieDevice_Type_cardBus
} IfxPcieDevice_Type;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pcie_Std_Device_Structures
 * \{ */
/** \brief Config Header Bar Bits
 */
typedef struct
{
    uint32 memIo : 1;          /**< \brief If 1, memory is IO type */
    uint32 barType : 2;        /**< \brief 0: 32 bit, 2: 64 bit */
    uint32 prefetch : 1;       /**< \brief prefetchable memory */
    uint32 baseAddr : 28;      /**< \brief BAR start address */
} IfxPcieDevice_CfgHdrBarBits;

/** \brief Config Header Bridge Ctrl Bits
 */
typedef struct
{
    uint16 parityErrEnable : 1;      /**< \brief Parity Error Enable */
    uint16 serrEnable : 1;           /**< \brief SERR # Error Flag */
    uint16 isaEnable : 1;            /**< \brief ISA IO address forwarding */
    uint16 vgaEnable : 1;            /**< \brief VGA enable */
    uint16 vga16Bit : 1;             /**< \brief VGA 16 bit decode */
    uint16 reserved_7 : 1;           /**< \brief Obsolete reserved */
    uint16 secBusReset : 1;          /**< \brief secondary Bus Reset */
    uint16 reserved_8 : 9;           /**< \brief Parity Error Flag */
} IfxPcieDevice_CfgHdrBridgeCtrlBits;

/** \brief Config Command Bits
 */
typedef struct
{
    uint16 ioEnable : 1;              /**< \brief IO space enable */
    uint16 memSpaceEnable : 1;        /**< \brief Memory Space Enable */
    uint16 busMasterEnable : 1;       /**< \brief BUS MASTER Enable */
    uint16 specialCycle : 1;          /**< \brief special cycle enable */
    uint16 memWriteInv : 1;           /**< \brief Memory write and invalidate */
    uint16 vgaPaletteSnoop : 1;       /**< \brief VGA Palette Snoop */
    uint16 parityErrEnable : 1;       /**< \brief parity Eror response */
    uint16 idSel : 1;                 /**< \brief IDSEL stepping */
    uint16 serrEnable : 1;            /**< \brief SERR # Enable */
    uint16 reserved_9 : 1;            /**< \brief reserved */
    uint16 disableInterrupt : 1;      /**< \brief Disable Interrupts */
    uint16 reserved_11 : 5;           /**< \brief reserved */
} IfxPcieDevice_CfgHdrCommandBits;

/** \brief Config Header Secondary Status Bits
 */
typedef struct
{
    uint16 reserved_0 : 8;             /**< \brief reserved */
    uint16 masterParityErr : 1;        /**< \brief Parity Error Flag */
    uint16 reserved_10 : 2;            /**< \brief obsolete_0 */
    uint16 signalTgtAbort : 1;         /**< \brief Completion Abort Error */
    uint16 receiveTgtAbort : 1;        /**< \brief Receive Target Abort */
    uint16 unsupportedReq : 1;         /**< \brief Unsupported Request */
    uint16 systemError : 1;            /**< \brief System Error */
    uint16 detectParityError : 1;      /**< \brief Poisoned TLP received */
} IfxPcieDevice_CfgHdrSecStatusBits;

/** \brief Config Header Status Bits
 */
typedef struct
{
    uint16 reserved_0 : 3;             /**< \brief reserved */
    uint16 interruptStatus : 1;        /**< \brief Interrupt Status */
    uint16 extendedCap : 1;            /**< \brief Extended Capability Presence */
    uint16 reserved_6 : 3;             /**< \brief obsolete_0 */
    uint16 masterParityErr : 1;        /**< \brief Parity Error Flag */
    uint16 reserved_10 : 2;            /**< \brief obsolete_0 */
    uint16 signalTgtAbort : 1;         /**< \brief Completion Abort Error */
    uint16 receiveTgtAbort : 1;        /**< \brief Receive Target Abort */
    uint16 unsupportedReq : 1;         /**< \brief Unsupported Request */
    uint16 systemError : 1;            /**< \brief System Error */
    uint16 detectParityError : 1;      /**< \brief Poisoned TLP received */
} IfxPcieDevice_CfgHdrStatusBits;

/** \brief Config Header Type Bits
 */
typedef struct
{
    uint8 type : 7;             /**< \brief type of header */
    uint8 multiFuncEn : 1;      /**< \brief Multi-Func enable */
} IfxPcieDevice_CfgHdrTypeBits;

/** \} */

/** \addtogroup IfxLld_Pcie_Std_Device_Structures
 * \{ */
/** \brief Config Header Bar
 */
typedef union
{
    volatile IfxPcieDevice_CfgHdrBarBits B;       /**< \brief Bitwise access */
    uint32                               U;       /**< \brief word access */
} IfxPcieDevice_CfgHdrBar;

/** \brief Config Header Bridge Ctrl
 */
typedef union
{
    volatile IfxPcieDevice_CfgHdrBridgeCtrlBits B;       /**< \brief Bitwise access */
    uint16                                      U;       /**< \brief Word Access */
} IfxPcieDevice_CfgHdrBridgeCtrl;

/** \brief Config Command
 */
typedef union
{
    volatile IfxPcieDevice_CfgHdrCommandBits B;       /**< \brief Bitwise access */
    uint16                                   U;       /**< \brief word access */
} IfxPcieDevice_CfgHdrCommand;

/** \brief Config Header Secondary Status
 */
typedef union
{
    volatile IfxPcieDevice_CfgHdrSecStatusBits B;       /**< \brief Bitwise access */
    uint16                                     U;       /**< \brief word access */
} IfxPcieDevice_CfgHdrSecStatus;

/** \brief Config Header Status
 */
typedef union
{
    volatile IfxPcieDevice_CfgHdrStatusBits B;       /**< \brief Bitwise access */
    uint16                                  U;       /**< \brief word access */
} IfxPcieDevice_CfgHdrStatus;

/** \brief Config Header Type
 */
typedef union
{
    volatile IfxPcieDevice_CfgHdrTypeBits B;       /**< \brief Bitwise access */
    uint8                                 U;       /**< \brief word access */
} IfxPcieDevice_CfgHdrType;

/** \brief TLP DWORD1 Bits
 */
typedef struct
{
    uint32 reqBus : 8;       /**< \brief Byte4 7:0 Bus Number */
    uint32 reqDev : 5;       /**< \brief Byte5 7:3 Device Number */
    uint32 reqFunc : 3;      /**< \brief Byte5 2:0 Function Number */
    uint32 tag : 8;          /**< \brief Byte6 7:0 Tag */
    uint32 msgCode : 1;      /**< \brief Byte7 7:0 Message Code */
} IfxPcieDevice_MessageDword2Bits;

/** \brief TLP DWORD0 Bits
 */
typedef struct
{
    uint32 format : 3;       /**< \brief Byte0 7:5 Format */
    uint32 type : 5;         /**< \brief Byte0 4:0 Type */
    uint32 t9 : 1;           /**< \brief Byte1 7:7 T9 */
    uint32 tc : 3;           /**< \brief Byte1 6:4 TC */
    uint32 t8 : 1;           /**< \brief Byte1 3:3 TD */
    uint32 ido : 1;          /**< \brief Byte1 2:2 Attr2 (IDO) */
    uint32 ln : 1;           /**< \brief Byte1 1:1 LN */
    uint32 th : 1;           /**< \brief Byte1 0:0 TH */
    uint32 td : 1;           /**< \brief Byte2 7:7 TD */
    uint32 ep : 1;           /**< \brief Byte2 6:6 EP */
    uint32 attr : 2;         /**< \brief Byte2 5:4 Attr01 */
    uint32 at : 2;           /**< \brief Byte2 3:2 AT */
    uint32 length : 10;      /**< \brief Byte2 1:0 Byte3 7:0 Length */
} IfxPcieDevice_TlpHdrDword1Bits;

/** \brief TLP DWORD2 Bits
 */
typedef struct
{
    uint32 vendorId : 16;      /**< \brief Byte10,11    15:0 Vendor ID */
    uint32 func : 3;           /**< \brief Byte9        2:0 Function Number */
    uint32 dev : 5;            /**< \brief Byte9        7:3 Device Number */
    uint32 bus : 8;            /**< \brief Byte8        7:0 Bus Number */
} IfxPcieDevice_VendorMsgDword3Bits;

/** \} */

/** \addtogroup IfxLld_Pcie_Std_Device_Structures
 * \{ */
/** \brief Config Header Prefetch Memory Bits
 */
typedef struct
{
    uint16 decode64Bit : 1;      /**< \brief decode as 64 bit */
    uint16 reserved_1 : 2;       /**< \brief Reserved */
    uint16 addr : 12;            /**< \brief memory Base/Limit Addr Upper 12 bits */
} IfxPcieDevice_CfgHdrPrefetchMemBits;

/** \brief TLP DWORD0
 */
typedef union
{
    IfxPcieDevice_TlpHdrDword1Bits B;       /**< \brief BITS access */
    uint32                         U;       /**< \brief DWORD access */
} IfxPcieDevice_TlpHdrDword1;

/** \brief TLP DWORD1
 */
typedef union
{
    IfxPcieDevice_MessageDword2Bits Msg;       /**< \brief Message Bits access */
    uint32                          U;         /**< \brief DWORD access */
} IfxPcieDevice_TlpHdrDword2;

/** \brief TLP DWORD2
 */
typedef union
{
    IfxPcieDevice_VendorMsgDword3Bits VendorMsg;       /**< \brief Vendor Message Bits access */
    uint32                            U;               /**< \brief DWORD access */
} IfxPcieDevice_TlpHdrDword3;

/** \brief Config Header type 0
 * NOTE:
 * The below structures do not follow the normal guidelines of "Structure order for padding".
 * This is done to ensure that the structure aligns correctly with PCIE configuration header type.
 * The alignment is ensured by:
 * (1) Types used here are uint8, uint16, uint32, and union and structures with uint32/uint16/uint8
 *  All the elements of above types start at their natural alignment in this structure
 * (2) "reserved" areas placed in appropriate locations, wherever protocol has reserved areas.
 * C Compiler will not "align" a memory element with alignment > its size footprint
 * Therefore, Default padding by compiler does not mis-align this structure
 */
typedef struct
{
    volatile uint16                      vendorId;               /**< \brief vendor ID */
    volatile uint16                      deviceId;               /**< \brief device ID */
    volatile IfxPcieDevice_CfgHdrCommand command;                /**< \brief command */
    volatile IfxPcieDevice_CfgHdrStatus  status;                 /**< \brief status */
    volatile uint8                       revisionId;             /**< \brief revision ID */
    volatile uint8                       programIf;              /**< \brief program IF */
    volatile uint16                      classCode;              /**< \brief class Code */
    volatile uint8                       cacheLineSize;          /**< \brief cache Line Size */
    volatile uint8                       latencyTimer;           /**< \brief Latency Timer */
    volatile IfxPcieDevice_CfgHdrType    headerType;             /**< \brief Header Type, Multi-Func Capability */
    volatile uint8                       bist;                   /**< \brief BIST */
    volatile IfxPcieDevice_CfgHdrBar     bar[6];                 /**< \brief BAR */
    volatile uint32                      carBusCisPtr;           /**< \brief Card bus CIS pointer */
    volatile uint16                      subsysVendorId;         /**< \brief Subsystem Vendor ID */
    volatile uint16                      subsysId;               /**< \brief Subsystem ID */
    volatile uint32                      expansionROMAddr;       /**< \brief expansion ROM address */
    volatile uint8                       capPtr;                 /**< \brief capabilities Offset */
    volatile uint8                       reserved_35h[3];        /**< \brief reserved at offset 35H */
    volatile uint8                       reserved_38h[3];        /**< \brief reserved at offset 38H */
    volatile uint8                       interruptLine;          /**< \brief interrupt Line */
    volatile uint8                       interruptPin;           /**< \brief interrupt Pin */
    volatile uint8                       reserved_3Eh[2];        /**< \brief reserved at offset 3EH */
} IfxPcieDevice_Type0CfgHdr;

/** \brief Config Header type 0
 * NOTE:
 * The below structures do not follow the normal guidelines of "Structure order for padding".
 * This is done to ensure that the structure aligns correctly with PCIE configuration header type.
 * The alignment is ensured by:
 * (1) Types used here are uint8, uint16, uint32, and union and structures with uint32/uint16/uint8
 *  All the elements of above types start at their natural alignment in this structure
 * (2) "reserved" areas placed in appropriate locations, wherever protocol has reserved areas.
 * C Compiler will not "align" a memory element with alignment > its size footprint
 * Therefore, Default padding by compiler does not mis-align this structure
 */
typedef struct
{
    volatile uint16                         vendorId;                 /**< \brief vendor ID */
    volatile uint16                         deviceId;                 /**< \brief device ID */
    volatile IfxPcieDevice_CfgHdrCommand    command;                  /**< \brief command */
    volatile IfxPcieDevice_CfgHdrStatus     status;                   /**< \brief status */
    volatile uint8                          revisionId;               /**< \brief revision ID */
    volatile uint8                          programIf;                /**< \brief program IF */
    volatile uint16                         classCode;                /**< \brief class Code */
    volatile uint8                          cacheLineSize;            /**< \brief cache Line Size */
    volatile uint8                          latencyTimer;             /**< \brief Latency Timer */
    volatile IfxPcieDevice_CfgHdrType       headerType;               /**< \brief Header Type, Multi-Func Capability */
    volatile uint8                          bist;                     /**< \brief BIST */
    volatile IfxPcieDevice_CfgHdrBar        bar[2];                   /**< \brief BAR */
    volatile uint8                          primaryBus;               /**< \brief primary Bus */
    volatile uint8                          secondaryBus;             /**< \brief secondary Bus */
    volatile uint8                          subordinateBus;           /**< \brief subordinate Bus */
    volatile uint8                          secLatencyTimer;          /**< \brief secondary Latency Timer */
    volatile uint8                          ioBase;                   /**< \brief io Base address */
    volatile uint8                          ioLimit;                  /**< \brief io Limit */
    volatile IfxPcieDevice_CfgHdrSecStatus  secStatus;                /**< \brief secondary Status */
    volatile uint16                         memBase;                  /**< \brief memory Base (non-prefetch) */
    volatile uint16                         memLimit;                 /**< \brief memory Limit (non-prefetch) */
    volatile uint16                         prefetchBase;             /**< \brief prefetch memory base */
    volatile uint16                         prefetchLimit;            /**< \brief prefetch memory limit */
    volatile uint32                         prefetchBaseUpper;        /**< \brief prefetch memory base upper 16 Bits */
    volatile uint32                         prefetchLimitUpper;       /**< \brief prefetch memory limit upper 16 bits */
    volatile uint16                         ioBaseUpper;              /**< \brief io base address upper 16 bits */
    volatile uint16                         ioLimitUpper;             /**< \brief io limit address upper 16 bits */
    volatile uint8                         *capPtr;                   /**< \brief capabilities pointer */
    volatile uint8                          reserved_35h[3];          /**< \brief reserved at offset 35H */
    volatile uint32                         expansionROMAddr;         /**< \brief expansion ROM address */
    volatile uint8                          interruptLine;            /**< \brief interrupt Line */
    volatile uint8                          interruptPin;             /**< \brief interrupt Pin */
    volatile IfxPcieDevice_CfgHdrBridgeCtrl bridgeCtrl;               /**< \brief bridge Control */
} IfxPcieDevice_Type1CfgHdr;

/** \} */

/** \addtogroup IfxLld_Pcie_Std_Device_Structures
 * \{ */
/** \brief Union of Configuration Header (Type0, Type1)
 */
typedef union
{
    volatile IfxPcieDevice_Type0CfgHdr type0;       /**< \brief Type 0 Config Header */
    volatile IfxPcieDevice_Type1CfgHdr type1;       /**< \brief Type 1 Config Header */
} IfxPcieDevice_CfgHdr;

/** \brief Config Header Prefetch Memory
 */
typedef union
{
    volatile IfxPcieDevice_CfgHdrPrefetchMemBits B;       /**< \brief Bitwise access */
    uint16                                       U;       /**< \brief Word Access */
} IfxPcieDevice_CfgHdrPrefetchMem;

/** \brief TLP Header
 */
typedef struct
{
    IfxPcieDevice_TlpHdrDword1 Dword1;       /**< \brief Dword 0 */
    IfxPcieDevice_TlpHdrDword2 Dword2;       /**< \brief Dword 1 */
    IfxPcieDevice_TlpHdrDword3 Dword3;       /**< \brief Dword 2 */
    uint32                     Dword4;       /**< \brief Dword 3 */
} IfxPcieDevice_TlpHdr;

/** \} */

/** \addtogroup IfxLld_Pcie_Std_Device_Funcctions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enable the bus master of the device
 * \param configHdr pointer to the configuration
 * \return None
 */
IFX_INLINE void IfxPcieDevice_enableBusMaster(IfxPcieDevice_CfgHdr *configHdr);

/** \brief Enable the memory Space of the device
 * \param configHdr pointer to the configuration
 * \return None
 */
IFX_INLINE void IfxPcieDevice_enableMemorySpace(IfxPcieDevice_CfgHdr *configHdr);

/** \brief Set device ID
 * \param configHdr pointer to the configuration
 * \param deviceId device ID
 * \return None
 */
IFX_INLINE void IfxPcieDevice_setDeviceId(IfxPcieDevice_CfgHdr *configHdr, uint16 deviceId);

/** \brief Set vendor ID
 * \param configHdr pointer to the configuration
 * \param vendorId vendor ID
 * \return None
 */
IFX_INLINE void IfxPcieDevice_setVendorId(IfxPcieDevice_CfgHdr *configHdr, uint16 vendorId);

/** \brief Set Interrupt Pin in CFG header
 * \param configHdr pointer to the configuration
 * \param intPin Interrupt Pin
 * \return None
 */
IFX_INLINE void IfxPcieDevice_setInterruptPin(IfxPcieDevice_CfgHdr *configHdr, uint8 intPin);

/** \brief check if Bus Master is enabled for device
 * \param configHdr pointer to the configuration
 * \return TRUE: Bus Master is enabled
 * FALSE: Bus Master is not enabled
 */
IFX_INLINE boolean IfxPcieDevice_isBusMasterEnabled(IfxPcieDevice_CfgHdr *configHdr);

/** \brief check if memory space is enabled for device
 * \param configHdr pointer to the configuration
 * \return TRUE: Memory space is enabled
 * FALSE: Memory space is not enabled
 */
IFX_INLINE boolean IfxPcieDevice_isMemorySpaceEnabled(IfxPcieDevice_CfgHdr *configHdr);

/** \brief check if interrupt is enabled for device
 * \param configHdr pointer to the configuration
 * \return TRUE: Interrupt is enabled
 * FALSE: Interrupt is not enabled
 */
IFX_INLINE boolean IfxPcieDevice_isInterruptEnabled(IfxPcieDevice_CfgHdr *configHdr);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxPcieDevice_enableBusMaster(IfxPcieDevice_CfgHdr *configHdr)
{
    configHdr->type0.command.B.busMasterEnable = 1u;
    IFXPCIE_CONFIGWRITE_DELAY(IFXPCIE_CFG_CONFIGWRITE_DELAYCOUNT);
}


IFX_INLINE void IfxPcieDevice_enableMemorySpace(IfxPcieDevice_CfgHdr *configHdr)
{
    configHdr->type0.command.B.memSpaceEnable = 1u;
    IFXPCIE_CONFIGWRITE_DELAY(IFXPCIE_CFG_CONFIGWRITE_DELAYCOUNT);
}


IFX_INLINE void IfxPcieDevice_setDeviceId(IfxPcieDevice_CfgHdr *configHdr, uint16 deviceId)
{
    configHdr->type1.deviceId = deviceId;
    IFXPCIE_CONFIGWRITE_DELAY(IFXPCIE_CFG_CONFIGWRITE_DELAYCOUNT);
}


IFX_INLINE void IfxPcieDevice_setVendorId(IfxPcieDevice_CfgHdr *configHdr, uint16 vendorId)
{
    if (vendorId == 0xFFFF)
    {
        //IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, TRUE); /* Vendor ID cannot be 0xFFFF */
    }
    else
    {
        configHdr->type1.vendorId = vendorId;
    }

    IFXPCIE_CONFIGWRITE_DELAY(IFXPCIE_CFG_CONFIGWRITE_DELAYCOUNT);
}


IFX_INLINE void IfxPcieDevice_setInterruptPin(IfxPcieDevice_CfgHdr *configHdr, uint8 intPin)
{
    configHdr->type0.interruptPin = intPin;
    IFXPCIE_CONFIGWRITE_DELAY(IFXPCIE_CFG_CONFIGWRITE_DELAYCOUNT);
}


IFX_INLINE boolean IfxPcieDevice_isBusMasterEnabled(IfxPcieDevice_CfgHdr *configHdr)
{
    return (configHdr->type0.command.B.busMasterEnable == 1u) ? TRUE : FALSE;
}


IFX_INLINE boolean IfxPcieDevice_isMemorySpaceEnabled(IfxPcieDevice_CfgHdr *configHdr)
{
    return (configHdr->type0.command.B.memSpaceEnable == 1u) ? TRUE : FALSE;
}


IFX_INLINE boolean IfxPcieDevice_isInterruptEnabled(IfxPcieDevice_CfgHdr *configHdr)
{
    return (configHdr->type0.command.B.disableInterrupt == 1u) ? FALSE : TRUE;
}


#endif /* IFXPCIEDEVICE_H */
