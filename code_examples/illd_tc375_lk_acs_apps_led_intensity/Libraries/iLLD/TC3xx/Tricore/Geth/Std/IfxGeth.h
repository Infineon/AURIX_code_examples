/**
 * \file IfxGeth.h
 * \brief GETH  basic functionality
 * \ingroup IfxLld_Geth
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
 * Standard layer
 *
 * \defgroup IfxLld_Geth_Std_Enumerations Enumerations
 * \ingroup IfxLld_Geth_Std
 * \defgroup IfxLld_Geth_Std_MAC_Functions MAC Functions
 * \ingroup IfxLld_Geth_Std
 * \defgroup IfxLld_Geth_Std_Module_Functions Module Functions
 * \ingroup IfxLld_Geth_Std
 * \defgroup IfxLld_Geth_Std_MTL_Functions MTL Functions
 * \ingroup IfxLld_Geth_Std
 * \defgroup IfxLld_Geth_Std_DMA_Functions DMA Functions
 * \ingroup IfxLld_Geth_Std
 * \defgroup IfxLld_Geth_Std_DataStructures DataStructures
 * \ingroup IfxLld_Geth_Std
 * \defgroup IfxLld_Geth_Std_Unions Unions
 * \ingroup IfxLld_Geth_Std
 */

#ifndef IFXGET_H
#define IFXGET_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGeth_cfg.h"
#include "IfxGeth_reg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Src/Std/IfxSrc.h"
#include "IfxGeth_bf.h"
#include "Stm/Std/IfxStm.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Max number of TX descriptors per list
 */
#ifndef IFXGETH_MAX_TX_DESCRIPTORS
#define IFXGETH_MAX_TX_DESCRIPTORS (8)
#endif

/** \brief Max number of RX descriptors per list
 */
#ifndef IFXGETH_MAX_RX_DESCRIPTORS
#define IFXGETH_MAX_RX_DESCRIPTORS (8)
#endif

/** \brief Waits until GMII is busy
 */
#define IFXGETH_PHY_WAIT_GMII_READY() while (GETH_MAC_MDIO_ADDRESS.B.GB) {}

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Geth_Std_Enumerations
 * \{ */
/** \brief Programmable burst length of DMA channels\n
 * Definition in DMA_CHi_TX_CONTROL.B.PBL and DMA_CHi_RX_CONTROL.B.PBL
 */
typedef enum
{
    IfxGeth_DmaBurstLength_1  = 1,   /**< \brief maximum burst length 1 */
    IfxGeth_DmaBurstLength_2  = 2,   /**< \brief maximum burst length 2 */
    IfxGeth_DmaBurstLength_4  = 4,   /**< \brief maximum burst length 4 */
    IfxGeth_DmaBurstLength_8  = 8,   /**< \brief maximum burst length 8 */
    IfxGeth_DmaBurstLength_16 = 16,  /**< \brief maximum burst length 16 */
    IfxGeth_DmaBurstLength_32 = 32   /**< \brief maximum burst length 32 */
} IfxGeth_DmaBurstLength;

/** \brief DMA channel Index
 */
typedef enum
{
    IfxGeth_DmaChannel_0,     /**< \brief Dma Channel 0  */
    IfxGeth_DmaChannel_1,     /**< \brief Dma Channel 1  */
    IfxGeth_DmaChannel_2,     /**< \brief Dma Channel 2  */
    IfxGeth_DmaChannel_3      /**< \brief Dma Channel 3  */
} IfxGeth_DmaChannel;

/** \brief DMA interrupt flags
 */
typedef enum
{
    IfxGeth_DmaInterruptFlag_transmitInterrupt         = 0,  /**< \brief Transmit Interrupt */
    IfxGeth_DmaInterruptFlag_transmitStopped           = 1,  /**< \brief Transmit Stopped */
    IfxGeth_DmaInterruptFlag_transmitBufferUnavailable = 2,  /**< \brief Trasmit Buffer Unavailable */
    IfxGeth_DmaInterruptFlag_receiveInterrupt          = 6,  /**< \brief Receive Interrupt */
    IfxGeth_DmaInterruptFlag_receiveBufferUnavailable  = 7,  /**< \brief Receive Buffer Unavailable */
    IfxGeth_DmaInterruptFlag_receiveStopped            = 8,  /**< \brief Receive Stopped */
    IfxGeth_DmaInterruptFlag_receiveWatchdogTimeout    = 9,  /**< \brief Receive Watchdog Timeout */
    IfxGeth_DmaInterruptFlag_earlyTransmitInterrupt    = 10, /**< \brief Early Transmit Interrupt */
    IfxGeth_DmaInterruptFlag_earlyReceiveInterrupt     = 11, /**< \brief Early Receive Interrupt */
    IfxGeth_DmaInterruptFlag_fatalBusError             = 12, /**< \brief Fatal Bus Error */
    IfxGeth_DmaInterruptFlag_contextDescriptorError    = 13, /**< \brief Context Descriptor Error */
    IfxGeth_DmaInterruptFlag_abnormalInterruptSummary  = 14, /**< \brief Abnormal Interrupt Summary */
    IfxGeth_DmaInterruptFlag_normalInterruptSummary    = 15  /**< \brief Normal Interrupt Summary */
} IfxGeth_DmaInterruptFlag;

/** \brief Ethernet line speed
 */
typedef enum
{
    IfxGeth_LineSpeed_10Mbps,    /**< \brief 10 Mbps */
    IfxGeth_LineSpeed_100Mbps,   /**< \brief 100 Mbps */
    IfxGeth_LineSpeed_1000Mbps,  /**< \brief 1000 Mbps */
    IfxGeth_LineSpeed_2500Mbps   /**< \brief 2500 Mbps */
} IfxGeth_LineSpeed;

/** \brief MTL interrupt flags
 */
typedef enum
{
    IfxGeth_MtlInterruptFlag_txQueueUnderflow   = 0,  /**< \brief Transmit Queue Underflow */
    IfxGeth_MtlInterruptFlag_averageBitsPerSlot = 1,  /**< \brief Average Bits Per Slot */
    IfxGeth_MtlInterruptFlag_rxQueueOverflow    = 16  /**< \brief Receive Queue Overflow */
} IfxGeth_MtlInterruptFlag;

/** \brief MTL Queue ID
 */
typedef enum
{
    IfxGeth_MtlQueue_0,     /**< \brief Mtl Queue 0  */
    IfxGeth_MtlQueue_1,     /**< \brief Mtl Queue 1  */
    IfxGeth_MtlQueue_2,     /**< \brief Mtl Queue 2  */
    IfxGeth_MtlQueue_3      /**< \brief Mtl Queue 3  */
} IfxGeth_MtlQueue;

/** \brief External Phy Interface RMII Mode
 * Definition in GPCTL.B.EPR
 */
typedef enum
{
    IfxGeth_PhyInterfaceMode_mii   = 0,  /**< \brief MII mode */
    IfxGeth_PhyInterfaceMode_rgmii = 1,  /**< \brief RGMII mode */
    IfxGeth_PhyInterfaceMode_rmii  = 4   /**< \brief RMII mode */
} IfxGeth_PhyInterfaceMode;

/** \brief Preamble Length for Transmit packets\n
 * Definition in MAC_CONFIGURATION.B.PRELEN
 */
typedef enum
{
    IfxGeth_PreambleLength_7Bytes,  /**< \brief 7 bytes of preamble */
    IfxGeth_PreambleLength_5Bytes,  /**< \brief 5 bytes of preamble */
    IfxGeth_PreambleLength_3Bytes   /**< \brief 3 bytes of preamble */
} IfxGeth_PreambleLength;

/** \brief Tx/RX Queue size in blocks of 256 bytes\n
 * Definition in MTL_TXQi_OPERATION_MODE.B.TQS and MTL_RXQi_OPERATION_MODE.B.RQS
 */
typedef enum
{
    IfxGeth_QueueSize_256Bytes,     /**< \brief 256Bytes  */
    IfxGeth_QueueSize_512Bytes,     /**< \brief 512Bytes  */
    IfxGeth_QueueSize_768Bytes,     /**< \brief 768Bytes  */
    IfxGeth_QueueSize_1024Bytes,    /**< \brief 1024Bytes  */
    IfxGeth_QueueSize_1280Bytes,    /**< \brief 1280Bytes  */
    IfxGeth_QueueSize_1536Bytes,    /**< \brief 1536Bytes  */
    IfxGeth_QueueSize_1792Bytes,    /**< \brief 1792Bytes  */
    IfxGeth_QueueSize_2048Bytes,    /**< \brief 2048Bytes  */
    IfxGeth_QueueSize_2304Bytes,    /**< \brief 2304Bytes  */
    IfxGeth_QueueSize_2560Bytes,    /**< \brief 2560Bytes  */
    IfxGeth_QueueSize_2816Bytes,    /**< \brief 2816Bytes  */
    IfxGeth_QueueSize_3072Bytes,    /**< \brief 3072Bytes  */
    IfxGeth_QueueSize_3328Bytes,    /**< \brief 3328Bytes  */
    IfxGeth_QueueSize_3584Bytes,    /**< \brief 3584Bytes  */
    IfxGeth_QueueSize_3840Bytes,    /**< \brief 3840Bytes  */
    IfxGeth_QueueSize_4096Bytes,    /**< \brief 4096Bytes  */
    IfxGeth_QueueSize_4352Bytes,    /**< \brief 4352Bytes  */
    IfxGeth_QueueSize_4608Bytes,    /**< \brief 4608Bytes  */
    IfxGeth_QueueSize_4864Bytes,    /**< \brief 4864Bytes  */
    IfxGeth_QueueSize_5120Bytes,    /**< \brief 5120Bytes  */
    IfxGeth_QueueSize_5376Bytes,    /**< \brief 5376Bytes  */
    IfxGeth_QueueSize_5632Bytes,    /**< \brief 5632Bytes  */
    IfxGeth_QueueSize_5888Bytes,    /**< \brief 5888Bytes  */
    IfxGeth_QueueSize_6144Bytes,    /**< \brief 6144Bytes  */
    IfxGeth_QueueSize_6400Bytes,    /**< \brief 6400Bytes  */
    IfxGeth_QueueSize_6656Bytes,    /**< \brief 6656Bytes  */
    IfxGeth_QueueSize_6912Bytes,    /**< \brief 6912Bytes  */
    IfxGeth_QueueSize_7168Bytes,    /**< \brief 7168Bytes  */
    IfxGeth_QueueSize_7424Bytes,    /**< \brief 7424Bytes  */
    IfxGeth_QueueSize_7680Bytes,    /**< \brief 7680Bytes  */
    IfxGeth_QueueSize_7936Bytes,    /**< \brief 7936Bytes  */
    IfxGeth_QueueSize_8192Bytes     /**< \brief 8192Bytes  */
} IfxGeth_QueueSize;

/** \brief Receive Arbitration Algorithm for Rx Queues\n
 * Definition in MTL_OPERATION_MODE.B.RAA
 */
typedef enum
{
    IfxGeth_RxArbitrationAlgorithm_sp  = 0, /**< \brief Strict Priority */
    IfxGeth_RxArbitrationAlgorithm_wsp = 1  /**< \brief Weighted Strict Priority */
} IfxGeth_RxArbitrationAlgorithm;

/** \brief Rx DMA channel
 */
typedef enum
{
    IfxGeth_RxDmaChannel_0,     /**< \brief Rx Dma Channel 0  */
    IfxGeth_RxDmaChannel_1,     /**< \brief Rx Dma Channel 1  */
    IfxGeth_RxDmaChannel_2,     /**< \brief Rx Dma Channel 2  */
    IfxGeth_RxDmaChannel_3      /**< \brief Rx Dma Channel 3  */
} IfxGeth_RxDmaChannel;

/** \brief Rx MTL Queue ID
 */
typedef enum
{
    IfxGeth_RxMtlQueue_0,     /**< \brief Rx Queue 0  */
    IfxGeth_RxMtlQueue_1,     /**< \brief Rx Queue 1  */
    IfxGeth_RxMtlQueue_2,     /**< \brief Rx Queue 2  */
    IfxGeth_RxMtlQueue_3      /**< \brief Rx Queue 3  */
} IfxGeth_RxMtlQueue;

/** \brief Geth service request index
 */
typedef enum
{
    IfxGeth_ServiceRequest_0,     /**< \brief Service Request SR0  */
    IfxGeth_ServiceRequest_1,     /**< \brief Service Request SR1  */
    IfxGeth_ServiceRequest_2,     /**< \brief Service Request SR2  */
    IfxGeth_ServiceRequest_3,     /**< \brief Service Request SR3  */
    IfxGeth_ServiceRequest_4,     /**< \brief Service Request SR4  */
    IfxGeth_ServiceRequest_5,     /**< \brief Service Request SR5  */
    IfxGeth_ServiceRequest_6,     /**< \brief Service Request SR6  */
    IfxGeth_ServiceRequest_7,     /**< \brief Service Request SR7  */
    IfxGeth_ServiceRequest_8,     /**< \brief Service Request SR8  */
    IfxGeth_ServiceRequest_9      /**< \brief Service Request SR9  */
} IfxGeth_ServiceRequest;

/** \brief Tx DMA channel
 */
typedef enum
{
    IfxGeth_TxDmaChannel_0,     /**< \brief Tx Dma Channel 0  */
    IfxGeth_TxDmaChannel_1,     /**< \brief Tx Dma Channel 1  */
    IfxGeth_TxDmaChannel_2,     /**< \brief Tx Dma Channel 2  */
    IfxGeth_TxDmaChannel_3      /**< \brief Tx Dma Channel 3  */
} IfxGeth_TxDmaChannel;

/** \brief Tx MTL Queue ID
 */
typedef enum
{
    IfxGeth_TxMtlQueue_0,     /**< \brief Tx Queue 0  */
    IfxGeth_TxMtlQueue_1,     /**< \brief Tx Queue 1  */
    IfxGeth_TxMtlQueue_2,     /**< \brief Tx Queue 2  */
    IfxGeth_TxMtlQueue_3      /**< \brief Tx Queue 3  */
} IfxGeth_TxMtlQueue;

/** \brief Tx Scheduling Algorithm for Tx Queues\n
 * Definition in MTL_OPERATION_MODE.B.SCHALG
 */
typedef enum
{
    IfxGeth_TxSchedulingAlgorithm_wrr = 0,  /**< \brief WRR Algorithm */
    IfxGeth_TxSchedulingAlgorithm_sp  = 3   /**< \brief Strict Priority Algorithm */
} IfxGeth_TxSchedulingAlgorithm;

/** \} */

/** \brief Duplex Mode\n
 * Definintion in MAC_CONFIGURATION.B.DM
 */
typedef enum
{
    IfxGeth_DuplexMode_halfDuplex,  /**< \brief Half Duplex Mode */
    IfxGeth_DuplexMode_fullDuplex   /**< \brief Full Duplex Mode */
} IfxGeth_DuplexMode;

/** \brief Loopback Mode\n
 * Definition in MAC_CONFIGURATION.B.LM
 */
typedef enum
{
    IfxGeth_LoopbackMode_disable,  /**< \brief Disable loopback */
    IfxGeth_LoopbackMode_enable    /**< \brief Enable loopback */
} IfxGeth_LoopbackMode;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Geth_Std_DataStructures
 * \{ */
/** \brief Bit Fields of RDES0 Context Descriptor
 */
typedef struct
{
    uint32 RTSL : 32;     /**< \brief Receive Packet Timestamp Low */
} IfxGeth_RxContextDescr0_Bits;

/** \brief Bit Fields of RDES1 Context Descriptor
 */
typedef struct
{
    uint32 RTSH : 32;     /**< \brief Receive Packet Timestamp High */
} IfxGeth_RxContextDescr1_Bits;

/** \brief Bit Fields of RDES2 Context Descriptor
 */
typedef struct
{
    uint32 reserved_0 : 32;     /**< \brief Reserved */
} IfxGeth_RxContextDescr2_Bits;

/** \brief Bit Fields of RDES3 Context Descriptor
 */
typedef struct
{
    uint32 reserved_0 : 29;     /**< \brief Reserved */
    uint32 DE : 1;              /**< \brief Descriptor Error */
    uint32 CTXT : 1;            /**< \brief Receive Context Descriptor */
    uint32 OWN : 1;             /**< \brief Own Bit */
} IfxGeth_RxContextDescr3_Bits;

/** \brief Bit Fields of RDES0 in Read Format
 */
typedef struct
{
    uint32 BUF1AP : 32;     /**< \brief Header or Buffer 1 Address Pointer */
} IfxGeth_RxDescr0_RF_Bits;

/** \brief Bit Fields of RDES0 in Write back Format
 */
typedef struct
{
    uint32 OVT : 16;     /**< \brief Outer VLAN Tag */
    uint32 IVT : 16;     /**< \brief Inner VLAN Tag */
} IfxGeth_RxDescr0_WF_Bits;

/** \brief Bit Fields of RDES1 in Read Format
 */
typedef struct
{
    uint32 reserved_0 : 32;     /**< \brief Reserved */
} IfxGeth_RxDescr1_RF_Bits;

/** \brief Bit Fields of RDES1 in Write back Format
 */
typedef struct
{
    uint32 PT : 3;       /**< \brief Payload Type */
    uint32 IPHE : 1;     /**< \brief IP Header Error */
    uint32 IP4 : 1;      /**< \brief IPV4 Header Present */
    uint32 IP6 : 1;      /**< \brief IPv6 header Present */
    uint32 IPCB : 1;     /**< \brief IP Checksum Bypassed */
    uint32 IPCE : 1;     /**< \brief IP Payload Error */
    uint32 PMT : 4;      /**< \brief PTP Message Type */
    uint32 PFT : 1;      /**< \brief PTP Packet Type */
    uint32 PV : 1;       /**< \brief PTP Version */
    uint32 TSA : 1;      /**< \brief Timestamp Available */
    uint32 TD : 1;       /**< \brief Timestamp Dropped */
    uint32 OPC : 16;     /**< \brief OAM Sub-Type Code, or MAC Control Packet opcode */
} IfxGeth_RxDescr1_WF_Bits;

/** \brief Bit Fields of RDES2 in Read Format
 */
typedef struct
{
    uint32 BUF2AP : 32;     /**< \brief Buffer 2 Address Pointer */
} IfxGeth_RxDescr2_RF_Bits;

/** \brief Bit Fields of RDES2 in Write back Format
 */
typedef struct
{
    uint32 HL : 10;             /**< \brief L3/L4 Header Length */
    uint32 ARPNR : 1;           /**< \brief ARP Reply Not Generated */
    uint32 reserved_11 : 3;     /**< \brief Reserved */
    uint32 ITS : 1;             /**< \brief Inner VLAN Tag Filter Status (ITS) */
    uint32 OTS : 1;             /**< \brief VLAN Filter Status */
    uint32 SAF : 1;             /**< \brief SA Address Filter Fail */
    uint32 DAF : 1;             /**< \brief Destination Address Filter Fail */
    uint32 HF : 1;              /**< \brief Hash Filter Status */
    uint32 MADRM : 8;           /**< \brief MAC Address Match or Hash Value */
    uint32 L3FM : 1;            /**< \brief Layer 3 Filter Match */
    uint32 L4FM : 1;            /**< \brief Layer 4 Filter Match */
    uint32 L3L4FM : 3;          /**< \brief Layer 3 and Layer 4 Filter Number Matched */
} IfxGeth_RxDescr2_WF_Bits;

/** \brief Bit Fields of RDES3 in Read Format
 */
typedef struct
{
    uint32 reserved_0 : 24;     /**< \brief Reserved */
    uint32 BUF1V : 1;           /**< \brief Buffer 1 Address Valid */
    uint32 BUF2V : 1;           /**< \brief Buffer 2 Address Valid */
    uint32 reserved_27 : 4;     /**< \brief Reserved */
    uint32 IOC : 1;             /**< \brief Interrupt on Completion */
    uint32 OWN : 1;             /**< \brief Own bit */
} IfxGeth_RxDescr3_RF_Bits;

/** \brief Bit Fields of RDES3 in Write back Format
 */
typedef struct
{
    uint32 PL : 15;      /**< \brief Packet Length */
    uint32 ES : 1;       /**< \brief Error Summary */
    uint32 LT : 3;       /**< \brief Length/Type Field */
    uint32 DE : 1;       /**< \brief Dribble Bit Error */
    uint32 RE : 1;       /**< \brief Receive Error */
    uint32 OE : 1;       /**< \brief Overflow Error */
    uint32 RWT : 1;      /**< \brief Receive Watchdog Timeout */
    uint32 GP : 1;       /**< \brief Giant Packet */
    uint32 CE : 1;       /**< \brief CRC Error */
    uint32 RS0V : 1;     /**< \brief Receive Status RDES0 Valid */
    uint32 RS1V : 1;     /**< \brief Receive Status RDES1 Valid */
    uint32 RS2V : 1;     /**< \brief Receive Status RDES2 Valid */
    uint32 LD : 1;       /**< \brief Last Descriptor */
    uint32 FD : 1;       /**< \brief First Descriptor */
    uint32 CTXT : 1;     /**< \brief Receive Context Descriptor */
    uint32 OWN : 1;      /**< \brief Own Bit */
} IfxGeth_RxDescr3_WF_Bits;

/** \brief Bit Fields of TDES0 Context Descriptor
 */
typedef struct
{
    uint32 TTSL : 32;     /**< \brief Transmit Packet Timestamp Low */
} IfxGeth_TxContextDescr0_Bits;

/** \brief Bit Fields of TDES1 Context Descriptor
 */
typedef struct
{
    uint32 TTSH : 32;     /**< \brief Transmit Packet Timestamp High */
} IfxGeth_TxContextDescr1_Bits;

/** \brief Bit Fields of TDES2 Context Descriptor
 */
typedef struct
{
    uint32 MSS : 14;            /**< \brief Maximum Segment Size */
    uint32 reserved_14 : 2;     /**< \brief Reserved */
    uint32 IVT : 16;            /**< \brief Inner VLAN Tag */
} IfxGeth_TxContextDescr2_Bits;

/** \brief Bit Fields of TDES3 Context Descriptor
 */
typedef struct
{
    uint32 VT : 16;             /**< \brief VLAN Tag */
    uint32 VLTV : 1;            /**< \brief VLAN Tag Valid */
    uint32 IVLTV : 1;           /**< \brief Inner VLAN Tag Valid */
    uint32 IVTIR : 2;           /**< \brief Inner VLAN Tag Insert or Replace */
    uint32 reserved_20 : 3;     /**< \brief Reserved */
    uint32 CDE : 1;             /**< \brief Context Descriptor Error */
    uint32 reserved_24 : 2;     /**< \brief Reserved */
    uint32 TCMSSV : 1;          /**< \brief One-Step Timestamp Correction Input or MSS Valid */
    uint32 OSTC : 1;            /**< \brief One-Step Timestamp Correction Enable */
    uint32 reserved_28 : 2;     /**< \brief Reserved */
    uint32 CTXT : 1;            /**< \brief Context Type */
    uint32 OWN : 1;             /**< \brief Own Bit */
} IfxGeth_TxContextDescr3_Bits;

/** \brief Bit Fields of TDES0 in Read Format
 */
typedef struct
{
    uint32 BUF1AP : 32;     /**< \brief Buffer 1 Address Pointer */
} IfxGeth_TxDescr0_RF_Bits;

/** \brief Bit Fields of TDES0 in Write-back Format
 */
typedef struct
{
    uint32 TTSL : 32;     /**< \brief Transmit Packet Timestamp Low */
} IfxGeth_TxDescr0_WF_Bits;

/** \brief Bit Fields of TDES1 in Read Format
 */
typedef struct
{
    uint32 BUF2AP : 32;     /**< \brief Buffer 2 or Buffer 1 Address Pointer */
} IfxGeth_TxDescr1_RF_Bits;

/** \brief Bit Fields of TDES1 in Write-back Format
 */
typedef struct
{
    uint32 TTSH : 32;     /**< \brief Transmit Packet Timestamp High */
} IfxGeth_TxDescr1_WF_Bits;

/** \brief Bit Fields of TDES2 in Read Format
 */
typedef struct
{
    uint32 B1L : 14;          /**< \brief Header Length or Buffer 1 Length */
    uint32 VTIR : 2;          /**< \brief VLAN Tag Insertion or Replacement */
    uint32 B2L : 14;          /**< \brief Buffer 2 Length */
    uint32 TTSE_TMWD : 1;     /**< \brief Transmit Timestamp Enable or External TSO Memory Write Enable */
    uint32 IOC : 1;           /**< \brief Interrupt on Completion */
} IfxGeth_TxDescr2_RF_Bits;

/** \brief Bit Fields of TDES2 in Write-back Format
 */
typedef struct
{
    uint32 reserved_0 : 32;     /**< \brief Reserved */
} IfxGeth_TxDescr2_WF_Bits;

/** \brief Bit Fields of TDES3 in Read Format
 */
typedef struct
{
    uint32 FL_TPL : 15;         /**< \brief Packet Length or TCP Payload Length */
    uint32 TPL : 1;             /**< \brief Reserved or TCP Payload Length */
    uint32 CIC_TPL : 2;         /**< \brief Checksum Insertion Control or TCP Payload LengthThese bits control the checksum */
    uint32 TSE : 1;             /**< \brief TCP Segmentation Enable */
    uint32 SLOTNUM_THL : 4;     /**< \brief SLOTNUM: Slot Number Control Bits in AV Mode */
    uint32 SAIC : 3;            /**< \brief SA Insertion Control */
    uint32 CPC : 2;             /**< \brief CRC Pad Control */
    uint32 LD : 1;              /**< \brief Last Descriptor */
    uint32 FD : 1;              /**< \brief First Descriptor */
    uint32 CTXT : 1;            /**< \brief Context TypeThis bit should be set to 1'b0 for normal descriptor */
    uint32 OWN : 1;             /**< \brief Own Bit */
} IfxGeth_TxDescr3_RF_Bits;

/** \brief Bit Fields of TDES3 in Write-back Format
 */
typedef struct
{
    uint32 IHE : 1;              /**< \brief IP Header Error */
    uint32 DB : 1;               /**< \brief Deferred Bit */
    uint32 UF : 1;               /**< \brief Underflow Error */
    uint32 ED : 1;               /**< \brief Excessive Deferral */
    uint32 CC : 4;               /**< \brief Collision Count */
    uint32 EC : 1;               /**< \brief Excessive Collision */
    uint32 LC : 1;               /**< \brief Late Collision */
    uint32 NC : 1;               /**< \brief No Carrier */
    uint32 LOC : 1;              /**< \brief Loss of Carrier */
    uint32 PCE : 1;              /**< \brief Payload Checksum */
    uint32 FF : 1;               /**< \brief Packet Flushed */
    uint32 JT : 1;               /**< \brief Jabber Timeout */
    uint32 ES : 1;               /**< \brief Error Summary */
    uint32 reserved_16 : 1;      /**< \brief Reserved */
    uint32 TTSS : 1;             /**< \brief Tx Timestamp Status */
    uint32 reserved_18 : 10;     /**< \brief Reserved */
    uint32 LD : 1;               /**< \brief Last Descriptor */
    uint32 FD : 1;               /**< \brief First Descriptor */
    uint32 CTXT : 1;             /**< \brief Context Type */
    uint32 OWN : 1;              /**< \brief Own bit */
} IfxGeth_TxDescr3_WF_Bits;

/** \} */

/** \addtogroup IfxLld_Geth_Std_Unions
 * \{ */
/** \brief RDES0
 */
typedef union
{
    IfxGeth_RxDescr0_RF_Bits     R;       /**< \brief Read Format Bitfiled Access */
    IfxGeth_RxDescr0_WF_Bits     W;       /**< \brief Write back Format Bitfiled Access */
    IfxGeth_RxContextDescr0_Bits C;       /**< \brief Context Descriptor Format Bitfiled Access */
    uint32                       U;       /**< \brief Unsigned access */
} IfxGeth_RxDescr0;

/** \brief RDES1
 */
typedef union
{
    IfxGeth_RxDescr1_RF_Bits     R;       /**< \brief Read Format Bitfiled Access */
    IfxGeth_RxDescr1_WF_Bits     W;       /**< \brief Write back Format Bitfiled Access */
    IfxGeth_RxContextDescr1_Bits C;       /**< \brief Context Descriptor Format Bitfiled Access */
    uint32                       U;       /**< \brief Unsigned access */
} IfxGeth_RxDescr1;

/** \brief RDES2
 */
typedef union
{
    IfxGeth_RxDescr2_RF_Bits     R;       /**< \brief Read Format Bitfiled Access */
    IfxGeth_RxDescr2_WF_Bits     W;       /**< \brief Write back Format Bitfiled Access */
    IfxGeth_RxContextDescr2_Bits C;       /**< \brief Context Descriptor Format Bitfiled Access */
    uint32                       U;       /**< \brief Unsigned access */
} IfxGeth_RxDescr2;

/** \brief RDES3
 */
typedef union
{
    IfxGeth_RxDescr3_RF_Bits     R;       /**< \brief Read Format Bitfiled Access */
    IfxGeth_RxDescr3_WF_Bits     W;       /**< \brief Write back Format Bitfiled Access */
    IfxGeth_RxContextDescr3_Bits C;       /**< \brief Context Descriptor Format Bitfiled Access */
    uint32                       U;       /**< \brief Unsigned access */
} IfxGeth_RxDescr3;

/** \brief TDES0
 */
typedef union
{
    IfxGeth_TxDescr0_RF_Bits     R;       /**< \brief Read Format Bitfiled Access */
    IfxGeth_TxDescr0_WF_Bits     W;       /**< \brief Write-back Format Bitfiled Access */
    IfxGeth_TxContextDescr0_Bits C;       /**< \brief Context Descriptor Format Bitfiled Access */
    uint32                       U;       /**< \brief Unsigned access */
} IfxGeth_TxDescr0;

/** \brief TDES1
 */
typedef union
{
    IfxGeth_TxDescr1_RF_Bits     R;       /**< \brief Read Format Bitfiled Access */
    IfxGeth_TxDescr1_WF_Bits     W;       /**< \brief Write-back Format Bitfiled Access */
    IfxGeth_TxContextDescr1_Bits C;       /**< \brief Context Descriptor Format Bitfiled Access */
    uint32                       U;       /**< \brief Unsigned access */
} IfxGeth_TxDescr1;

/** \brief TDES2
 */
typedef union
{
    IfxGeth_TxDescr2_RF_Bits     R;       /**< \brief Read Format Bitfiled Access */
    IfxGeth_TxDescr2_WF_Bits     W;       /**< \brief Write-back Format Bitfiled Access */
    IfxGeth_TxContextDescr2_Bits C;       /**< \brief COntext Descriptor Format Bitfiled Access */
    uint32                       U;       /**< \brief Unsigned access */
} IfxGeth_TxDescr2;

/** \brief TDES3
 */
typedef union
{
    IfxGeth_TxDescr3_RF_Bits     R;       /**< \brief Read Format Bitfiled Access */
    IfxGeth_TxDescr3_WF_Bits     W;       /**< \brief Write-back Format Bitfiled Access */
    IfxGeth_TxContextDescr3_Bits C;       /**< \brief Context Descriptor Format Bitfiled Access */
    uint32                       U;       /**< \brief Unsigned access */
} IfxGeth_TxDescr3;

/** \} */

/** \addtogroup IfxLld_Geth_Std_DataStructures
 * \{ */
/** \brief Rx Descriptor
 */
typedef struct
{
    IfxGeth_RxDescr0 RDES0;       /**< \brief Rx Descriptor DWORD 0 */
    IfxGeth_RxDescr1 RDES1;       /**< \brief Rx Descriptor DWORD 1 */
    IfxGeth_RxDescr2 RDES2;       /**< \brief Rx Descriptor DWORD 2 */
    IfxGeth_RxDescr3 RDES3;       /**< \brief Rx Descriptor DWORD 3 */
} IfxGeth_RxDescr;

/** \brief Tx Descriptor
 */
typedef struct
{
    IfxGeth_TxDescr0 TDES0;       /**< \brief Tx Descriptor DWORD 0 */
    IfxGeth_TxDescr1 TDES1;       /**< \brief Tx Descriptor DWORD 1 */
    IfxGeth_TxDescr2 TDES2;       /**< \brief Tx Descriptor DWORD 2 */
    IfxGeth_TxDescr3 TDES3;       /**< \brief Tx Descriptor DWORD 3 */
} IfxGeth_TxDescr;

/** \} */

/** \addtogroup IfxLld_Geth_Std_Unions
 * \{ */
/** \brief Rx Descriptor List
 */
typedef union
{
    volatile IfxGeth_RxDescr descr[IFXGETH_MAX_RX_DESCRIPTORS];       /**< \brief list of RX descriptors */
} IfxGeth_RxDescrList;

/** \brief Tx Descriptor List
 */
typedef union
{
    volatile IfxGeth_TxDescr descr[IFXGETH_MAX_TX_DESCRIPTORS];       /**< \brief list of TX descriptors */
} IfxGeth_TxDescrList;

/** \} */

/** \addtogroup IfxLld_Geth_Std_MAC_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the Receiver of MAC Core
 *
 * \param[inout] gethSFR Pointer to the GETH register base address
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_disableReceiver(Ifx_GETH *gethSFR);

/**
 * \brief Disables the Transmitter of MAC Core
 *
 * \param[inout] gethSFR Pointer to the GETH register base address
 * 
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_disableTransmitter(Ifx_GETH *gethSFR);

/**
 * \brief Enables the Receiver of the MAC Core
 *
 * \param[inout] gethSFR Pointer to the GETH register base address
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_enableReceiver(Ifx_GETH *gethSFR);

/**
 * \brief Enables the Transmitter of MAC Core
 *
 * \param[inout] gethSFR Pointer to the GETH register base address
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_enableTransmitter(Ifx_GETH *gethSFR);

/**
 * \brief Enables or disables the passing of all multicast packets.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    enabled Boolean flag to enable (TRUE) or disable (FALSE) the passing of all multicast packets.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_setAllMulticastPassing(Ifx_GETH *gethSFR, boolean enabled);

/**
 * \brief Configures CRC checking for received packets
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    enabled Boolean flag to enable (true) or disable (false) CRC checking.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_setCrcChecking(Ifx_GETH *gethSFR, boolean enabled);

/**
 * \brief Enables/Disables the Automatic Pad or CRC Stripping for frames less than 1536 bytes and CRC stripping for Type packets.
 *
 * \param[inout] gethSFR    Pointer to GETH register base address.
 * \param[in]    acsEnabled Automatic Pad or CRC Stripping enable/disable.
 *                          Range: 0 and 1
 * \param[in]    cstEnabled CRC Stripping for Type packets enable/disable.
 *                          Range: 0 and 1
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_setCrcStripping(Ifx_GETH *gethSFR, boolean acsEnabled, boolean cstEnabled);

/**
 * \brief Sets the Duplex Mode
 *
 * \param[inout] gethSFR Pointer to GETH register base address.
 * \param[in]    mode    Duplex Mode
 *                       Range: \ref IfxGeth_DuplexMode
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_setDuplexMode(Ifx_GETH *gethSFR, IfxGeth_DuplexMode mode);

/**
 * \brief Sets the preamble length for MAC transmit packets.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    length  Preamble length for transmit packets.
 *                       Range: \ref IfxGeth_PreambleLength
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_setPreambleLength(Ifx_GETH *gethSFR, IfxGeth_PreambleLength length);

/**
 * \brief Enables or disables the Promiscuous Mode for the GETH MAC.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    enabled Boolean flag to enable (TRUE) or disable (FALSE) Promiscuous Mode.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_setPromiscuousMode(Ifx_GETH *gethSFR, boolean enabled);

/**
 * \brief Sets the priorities for Rx queues for mapping tagged packets.
 *
 * \param[inout] gethSFR    Pointer to the GETH register base address.
 * \param[in]    channel    Rx DMA channel to configure.
 *                          Range: \ref IfxGeth_RxDmaChannel
 * \param[in]    priorities Rx queue priority level.
 *                          Range: 0 to 3
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_setVlanPriorityQueueRouting(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint8 priorities);

/**
 * \brief Enables or disables the insertion of VLAN tags into queues for the GETH module.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    enable  Boolean to enable (TRUE) or disable (FALSE) VLAN insertion.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_setQueueVlanInsertion(Ifx_GETH *gethSFR, boolean enable);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the MAC line speed for the Ethernet controller.
 *
 * \param[inout] gethSFR  Pointer to the GETH register base address.
 * \param[in]    speed    Ethernet line speed to be set.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mac_setLineSpeed(Ifx_GETH *gethSFR, IfxGeth_LineSpeed speed);

/**
 * \brief Sets the MAC Address for the Ethernet controller
 *
 * \param[inout] gethSFR    Pointer to the GETH register base address.
 * \param[in]    macAddress Pointer to a 6-byte array containing the MAC address to be set.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mac_setMacAddress(Ifx_GETH *gethSFR, uint8 *macAddress);

/**
 * \brief Writes the VLAN tag to the specified queue.
 *
 * \param[inout] gethSFR  Pointer to the GETH register base address.
 * \param[in]    queueId  The queue identifier.
 *                        Range: \ref IfxGeth_MtlQueue
 * \param[in]    vLanTag  The VLAN tag to be written, represented as a uint16 value.
 *                        Range: 0 to 0xFFFF
 *                        Bits[15:13]: User Priority field.
 *                        Bit 12     : Canonical Format Indicator (CFI) or Drop Eligible Indicator (DEI).
 *                        Bits[11:0] : VLAN Identifier (VID) field of VLAN tag.
 *
 * \retval TRUE  The write operation was successful.
 *         FALSE The write operation failed.
 */
IFX_EXTERN boolean IfxGeth_mac_writeQueueVlanTag(Ifx_GETH *gethSFR, IfxGeth_MtlQueue queueId, uint16 vLanTag);

/**
 * \brief Reads the VLAN tag from the specified queue.
 *
 * \param[inout] gethSFR  Pointer to the GETH register base address.
 * \param[in]    queueId  Queue index of type IfxGeth_MtlQueue.
 *                        Range: \ref IfxGeth_MtlQueue
 * \param[inout] vLanTag  Pointer to the variable where the retrieved VLAN tag will be stored.
 *
 *
 * \retval TRUE  If the read operation was successful.
 *         FALSE If the read operation failed.
 */
IFX_EXTERN boolean IfxGeth_mac_readQueueVlanTag(Ifx_GETH *gethSFR, IfxGeth_MtlQueue queueId, uint16 *const vLanTag);

/**
 * \brief Reads the VLAN tag filter data for a specified filter identifier from the GETH MAC module.
 *
 * \param[inout] gethSFR   Pointer to the GETH register base address.
 * \param[in]    filterId  Filter identifier to specify which VLAN tag filter to read.
 *                         Range: 0 to 0x1F
 * \param[inout] data      Pointer to the Ifx_GETH_MAC_VLAN_TAG_DATA structure that will be filled with the VLAN tag filter data.
 *
 * \retval TRUE  The VLAN tag filter data was successfully read.
 *         FALSE The read operation failed.
 */
IFX_EXTERN boolean IfxGeth_mac_readVlanTagFilter(Ifx_GETH *gethSFR, uint8 filterId, Ifx_GETH_MAC_VLAN_TAG_DATA *const data);

/**
 * \brief Writes VLAN tag filter data to the specified filter identifier.
 *
 * \param[inout] gethSFR   Pointer to the GETH register base address.
 * \param[in]    filterId  Filter identifier to specify which VLAN tag filter to write.
 *                         Range: 0 to 0x1F
 * \param[in]    data      VLAN tag data structure containing the configuration to be written.
 *
 * \retval TRUE  If the write operation was successful.
 *         FALSE If the write operation failed.
 */
IFX_EXTERN boolean IfxGeth_mac_writeVlanTagFilter(Ifx_GETH *gethSFR, uint8 filterId, Ifx_GETH_MAC_VLAN_TAG_DATA data);

/** \} */

/** \addtogroup IfxLld_Geth_Std_Module_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Checks if the clock for the GETH module is enabled.
 *
 * \param[in] gethSFR Pointer to the GETH register base address.
 *
 * \retval TRUE  If the module is enabled.
 *         FALSE If the module is disabled.
 */
IFX_INLINE boolean IfxGeth_isModuleEnabled(Ifx_GETH *gethSFR);

/**
 * \brief Configures the PHY interface mode for the given GETH instance.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    mode    The desired PHY interface mode.
 *                       Range: \ref IfxGeth_PhyInterfaceMode
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_setPhyInterfaceMode(Ifx_GETH *gethSFR, IfxGeth_PhyInterfaceMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the clock for GETH module.
 *
 * \param[inout] gethSFR Pointer to GETH register base address.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_disableModule(Ifx_GETH *gethSFR);

/**
 * \brief Enables the clock for the GETH module.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_enableModule(Ifx_GETH *gethSFR);

/**
 * \brief Returns the Src Pointer of the selected GETH service request node.
 *
 * \param[in] gethSFR        Pointer to GETH register base address.
 * \param[in] serviceRequest Service Request number.
 *                           Range: \ref IfxGeth_ServiceRequest
 *
 * \retval Ifx_SRC_SRCR, pointer to Src register.
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxGeth_getSrcPointer(Ifx_GETH *gethSFR, IfxGeth_ServiceRequest serviceRequest);

/**
 * \brief Resets the Ethernet kernel module to its initial state.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_resetModule(Ifx_GETH *gethSFR);

/**
 * \brief Retrieves the resource index of the specified GETH instance.
 *
 * \param[in] geth Pointer to the GETH register base address.
 *
 * \retval IfxGeth_Index The resource index of the GETH instance.
 */
IFX_EXTERN IfxGeth_Index IfxGeth_getIndex(Ifx_GETH *geth);

/**
 * \brief Retrieves the memory address of the GETH module registers corresponding to the specified index.
 *
 * \param[in] geth Module index of the GETH.
 *
 * \retval Ifx_GETH* Pointer to the base address of the GETH module registers. The return value should not be NULL if the index is valid.
 */
IFX_EXTERN Ifx_GETH *IfxGeth_getAddress(IfxGeth_Index geth);

/** \} */

/** \addtogroup IfxLld_Geth_Std_MTL_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables the selected Rx Queue for frame reception.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId Rx Queue Index to be enabled.
 *               Range: \ref IfxGeth_RxMtlQueue
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_enableRxQueue(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId);

/**
 * \brief Configures the Receive Arbitration Algorithm for the specified GETH instance.
 *
 * \param[inout] gethSFR               Pointer to the GETH register base address.
 * \param[in]    arbitrationAlgorithm  Rx Arbitration Algorithm to be configured.
 *                                     Range: \ref IfxGeth_RxArbitrationAlgorithm
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_setRxArbitrationAlgorithm(Ifx_GETH *gethSFR, IfxGeth_RxArbitrationAlgorithm arbitrationAlgorithm);

/**
 * \brief Sets the selected DMA Channel mapping for the specified Receive Queue.
 *
 * \param[inout] gethSFR    Pointer to the GETH register base address.
 * \param[in]    queueId    Rx MTL Queue ID.
 *                          Range: \ref IfxGeth_RxMtlQueue
 * \param[in]    dmaChannel DMA channel for the selected Rx Queue.
 *                          Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_setRxQueueDmaChannelMapping(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId, IfxGeth_RxDmaChannel dmaChannel);

/**
 * \brief Sets the selected Rx Queue for DA based DMA channel.
 * 
 * This function configures the specified Rx queue for a DA (Destination Address) based DMA channel.
 * It enables or disables the Receive Store and Forward functionality for the selected queue.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address
 * \param[in]    queueId Rx MTL Queue ID.
 *                       Range: \ref IfxGeth_RxMtlQueue
 * \param[in]    enabled Enable/Disable Receive Store and Forward.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_setRxQueueForDaBasedDmaChannel(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId, boolean enabled);

/**
 * \brief Sets the Tx Scheduling algorithm for the GETH module.
 *
 * \param[inout] gethSFR          Pointer to the GETH register base address.
 * \param[in] schedulingAlgorithm Tx Scheduling Algorithm to be configured.
 *                                Range: \ref IfxGeth_TxSchedulingAlgorithm
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_setTxSchedulingAlgorithm(Ifx_GETH *gethSFR, IfxGeth_TxSchedulingAlgorithm schedulingAlgorithm);

/**
 * \brief Enable and set queue ID to route packets failing unicast filter.
 *
 * \param[inout] gethSFR Pointer to GETH register base address.
 * \param[in]    queueId Rx MTL Queue ID.
 *                       Range: \ref IfxGeth_RxMtlQueue
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_enableUnicastFilterFailQueuing(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId);

/**
 * \brief Disable queuing of packets failing unicast filtering.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_disableUnicastFilterFailQueuing(Ifx_GETH *gethSFR);

/**
 * \brief Enable and set queue ID to route packets failing multicast filter.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId Rx MTL Queue ID.
 *                       Range: \ref IfxGeth_RxMtlQueue
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_enableMulticastFilterFailQueuing(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId);

/**
 * \brief Disables queuing of packets that fail multicast filtering.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_disableMulticastFilterFailQueuing(Ifx_GETH *gethSFR);

/**
 * \brief Enable and set queue ID to route packets failing VLAN tag filter.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId Rx MTL Queue ID.
 *                       Range: \ref IfxGeth_RxMtlQueue
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_enableVlanFilterFailQueuing(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId);

/**
 * \brief Disable queuing of packets failing VLAN tag filtering.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mtl_disableVlanFilterFailQueuing(Ifx_GETH *gethSFR);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears all pending MTL interrupt flags for a specified queue.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId The queue for which to clear interrupt flags.
 *                       Range: \ref IfxGeth_MtlQueue
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_clearAllInterruptFlags(Ifx_GETH *gethSFR, IfxGeth_MtlQueue queueId);

/**
 * \brief Clears the selected MTL interrupt flag.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId Queue Index.
 *                       Range: \ref IfxGeth_MtlQueue
 * \param[in]    flag    MTL interrupt flag to be cleared.
 *                       Range: \ref IfxGeth_MtlInterruptFlag
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_clearInterruptFlag(Ifx_GETH *gethSFR, IfxGeth_MtlQueue queueId, IfxGeth_MtlInterruptFlag flag);

/**
 * \brief Disables the specified MTL interrupt flag for the given queue.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId The queue for which to disable the interrupt.
 *                       Range: \ref IfxGeth_MtlQueue
 * \param[in]    flag    The MTL interrupt flag to disable.
 *                       Range: \ref IfxGeth_MtlInterruptFlag
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_disableInterrupt(Ifx_GETH *gethSFR, IfxGeth_MtlQueue queueId, IfxGeth_MtlInterruptFlag flag);

/**
 * \brief Enables the selected Mtl interrupt flag.
 *
 * \param[inout] gethSFR Pointer to GETH register base address.
 * \param[in]    queueId Queue Index.
 *                       Range: \ref IfxGeth_MtlQueue
 * \param[in]    flag    The MTL interrupt flag to enable.
 *                       Range: \ref IfxGeth_MtlInterruptFlag
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_enableInterrupt(Ifx_GETH *gethSFR, IfxGeth_MtlQueue queueId, IfxGeth_MtlInterruptFlag flag);

/**
 * \brief Enables the selected TX Queue for the MTL module.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId TX Queue Index.
 *                       Range: \ref IfxGeth_TxMtlQueue
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_enableTxQueue(Ifx_GETH *gethSFR, IfxGeth_TxMtlQueue queueId);

/**
 * \brief Checks if the specified MTL interrupt flag is set for the given queue.
 *
 * \param[in] gethSFR Pointer to the GETH register base address.
 * \param[in] queueId Queue Index.
 *                    Range: \ref IfxGeth_MtlQueue
 * \param[in] flag    MTL interrupt flag to check.
 *                    Range: \ref IfxGeth_MtlInterruptFlag
 *
 * \retval TRUE  If the interrupt flag is set.
 *         FALSE If the interrupt flag is not set.
 */
IFX_EXTERN boolean IfxGeth_mtl_isInterruptFlagSet(Ifx_GETH *gethSFR, IfxGeth_MtlQueue queueId, IfxGeth_MtlInterruptFlag flag);

/**
 * \brief Sets the Receive Forward Error Packets for the selected RX Queue.
 * 
 * \param[inout] gethSFR Pointer to GETH register base address.
 * \param[in]    queueId Rx Queue Index.
 *                       Range: \ref IfxGeth_RxMtlQueue
 * \param[in]    enabled Enable/Disable Receive Forward Error Packets.
 *                       Range:TRUE = enabled, FALSE = disabled.
 * 
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_setRxForwardErrorPacket(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId, boolean enabled);

/**
 * \brief Sets the Receive Forward Undersized Good Packets for the selected RX Queue.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId Rx Queue Index.
 *                       Range: \ref IfxGeth_RxMtlQueue
 * \param[in]    enabled Enable/Disable Receive Forward Undersized Good Packets.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_setRxForwardUndersizedGoodPacket(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId, boolean enabled);

/**
 * \brief Sets the size of the selected RX Queue in blocks of 256 bytes.
 *
 * \param[inout] gethSFR   Pointer to GETH register base address.
 * \param[in]    queueId   Rx Queue Index.
 *                         Range: \ref IfxGeth_RxMtlQueue
 * \param[in]    queueSize Rx Queue Size.
 *                         Range: \ref IfxGeth_QueueSize
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_setRxQueueSize(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId, IfxGeth_QueueSize queueSize);

/**
 * \brief Sets the Receive Store And Forward feature for the specified RX queue.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId Rx Queue Index.
 *                       Range: \ref IfxGeth_RxMtlQueue
 * \param[in]    enabled Boolean flag to enable (TRUE) or disable (FALSE).
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_setRxStoreAndForward(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId, boolean enabled);

/**
 * \brief Sets the size of the selected TX Queue.
 *
 * \param[inout] gethSFR   Pointer to the GETH register base address.
 * \param[in]    queueId   Tx Queue Index.
 *                         Range: \ref IfxGeth_TxMtlQueue
 * \param[in]    queueSize Tx Queue Size.
 *                         Range: \ref IfxGeth_QueueSize
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_setTxQueueSize(Ifx_GETH *gethSFR, IfxGeth_TxMtlQueue queueId, IfxGeth_QueueSize queueSize);

/**
 * \brief Sets the Transmit Store And Forward feature for the specified TX queue.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    queueId Tx Queue Index.
 *                       Range: \ref IfxGeth_TxMtlQueue
 * \param[in]    enabled Boolean flag to enable (TRUE) or disable (FALSE) the Transmit Store And Forward feature.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mtl_setTxStoreAndForward(Ifx_GETH *gethSFR, IfxGeth_TxMtlQueue queueId, boolean enabled);

/** \} */

/** \addtogroup IfxLld_Geth_Std_DMA_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Applies a software reset to the MAC and DMA controller.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_applySoftwareReset(Ifx_GETH *gethSFR);

/**
 * \brief Returns the status of selected DMA interrupt flag.
 *
 * \param[inout] gethSFR   Pointer to GETH register base address.
 * \param[in]    channelId DMA channel Id.
 *                         Range: \ref IfxGeth_DmaChannel
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_clearAllInterruptFlags(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId);

/**
 * \brief Clears the specified DMA interrupt flag for the given channel.
 *
 * \param[inout] gethSFR    Pointer to the GETH register base address.
 * \param[in]    channelId  DMA channel Id.
 *                          Range: \ref IfxGeth_DmaChannel
 * \param[in]    flag       The specific DMA interrupt flag to be cleared.
 *                          Range: \ref IfxGeth_DmaChannel
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_clearInterruptFlag(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId, IfxGeth_DmaInterruptFlag flag);

/**
 * \brief Disables the selected DMA interrupt for the specified channel.
 *
 * \param[inout] gethSFR   Pointer to the GETH register base address.
 * \param[in]    channelId DMA channel Id.
 *                         Range: \ref IfxGeth_DmaChannel
 * \param[in]    flag      DMA interrupt flag specifying which interrupt to disable.
 *                         Range: \ref IfxGeth_DmaInterruptFlag
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_disableInterrupt(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId, IfxGeth_DmaInterruptFlag flag);

/**
 * \brief Enables the selected DMA interrupt for the specified channel.
 *
 * \param[inout] gethSFR   Pointer to the GETH register base address.
 * \param[in]    channelId DMA channel Id.
 *                         Range: \ref IfxGeth_DmaChannel
 * \param[in]    flag      DMA interrupt flag.
 *                         Range: \ref IfxGeth_DmaInterruptFlag
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_enableInterrupt(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId, IfxGeth_DmaInterruptFlag flag);

/**
 * \brief Checks if the specified DMA interrupt flag is set for the given channel.
 *
 * \param[in] gethSFR   Pointer to the GETH register base address.
 * \param[in] channelId DMA channel Id.
 *                      Range: \ref IfxGeth_DmaChannel
 * \param[in] flag      DMA interrupt flag to check.
 *                      Range: \ref IfxGeth_DmaInterruptFlag
 *
 * \retval TRUE  If the specified DMA interrupt flag is set.
 *         FALSE If the specified DMA interrupt flag is not set.
 */
IFX_INLINE boolean IfxGeth_dma_isInterruptFlagSet(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId, IfxGeth_DmaInterruptFlag flag);

/**
 * \brief Waits until software reset of MAC and DMA controller is done or until timeout.
 *
 * \param[in] gethSFR Pointer to GETH register base address.
 *
 * \retval TRUE  Software reset of MAC and DMA controller is done.
 *         FALSE Timeout occurred before software reset completion.
 */
IFX_INLINE boolean IfxGeth_dma_isSoftwareResetDone(Ifx_GETH *gethSFR);

/**
 * \brief Configures the DMA address-aligned beats feature.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    enabled Boolean flag to enable (TRUE) or disable (FALSE) address-aligned beats.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setAddressAlignedBeats(Ifx_GETH *gethSFR, boolean enabled);

/**
 * \brief Enables or disables the fixed burst length for DMA transfers in the GETH module.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    enabled Boolean flag to enable or disable the fixed burst length.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setFixedBurst(Ifx_GETH *gethSFR, boolean enabled);

/**
 * \brief Enables or disables the mixed burst length feature for DMA transfers.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    enabled Boolean flag to enable (TRUE) or disable (FALSE) mixed burst.
 *                       Range:TRUE = enabled, FALSE = disabled
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setMixedBurst(Ifx_GETH *gethSFR, boolean enabled);

/**
 * \brief Sets the size of the RX buffers in descriptors for the selected RX channel of DMA.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel The RX DMA channel to configure.
 *                       Range: \ref IfxGeth_RxDmaChannel
 * \param[in]    size    The size of the RX buffers.
 *                       Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setRxBufferSize(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint16 size);

/**
 * \brief Sets the base address of the first descriptor in the Receive descriptor list for a specified Rx DMA channel.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Rx DMA channel identifier.
 *                       Range: \ref IfxGeth_RxDmaChannel
 * \param[in]    address Base address of the first descriptor in the Receive descriptor list.
 *                       Range: 0 to 0xFFFFFFFC
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setRxDescriptorListAddress(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint32 address);

/**
 * \brief Configures the number of Rx descriptors in the descriptor ring for a specified DMA channel.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Rx DMA channel identifier.
 *                       Range: \ref IfxGeth_RxDmaChannel
 * \param[in]    length  Length of the ring, representing the total number of Rx descriptors. Must be a positive integer.
 *                       Range: 0 to 0x3FF
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setRxDescriptorRingLength(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint32 length);

/**
 * \brief Sets the address of the last valid descriptor in the Receive descriptor list.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Rx DMA channel identifier.
 *                       Range: \ref IfxGeth_RxDmaChannel
 * \param[in]    address Memory address of the last valid descriptor in the Receive descriptor list.
 *                       Range: 0 to 0xFFFFFFFC
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setRxDescriptorTailPointer(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint32 address);

/**
 * \brief Configures the maximum burst length for the specified Rx DMA channel.
 * 
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Rx DMA channel ID.
 *                       Range: \ref IfxGeth_RxDmaChannel
 * \param[in]    length  Programmable burst length.
 *                       Range: \ref IfxGeth_DmaBurstLength
 * 
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setRxMaxBurstLength(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, IfxGeth_DmaBurstLength length);

/**
 * \brief sets the base address of the first descriptor in the Transmit descriptor list.
 *
 * \param[inout] gethSFR Pointer to GETH register base address.
 * \param[in]    channel Tx channel Id.
 *                       Range: \ref IfxGeth_TxDmaChannel
 * \param[in]    address Base address of the first descriptor in the Transmit descriptor list.
 *                       Range: 0 to 0xFFFFFFFC
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setTxDescriptorListAddress(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, uint32 address);

/**
 * \brief Sets the length of the TX descriptors ring for a specific DMA channel.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Tx DMA channel ID.
 *                       Range: \ref IfxGeth_TxDmaChannel
 * \param[in]    length  Length of the ring.
 *                       Range: 0 to 0x3FF
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setTxDescriptorRingLength(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, uint32 length);

/**
 * \brief Sets the address of the last valid descriptor in the Transmit descriptor list.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Tx DMA channel ID.
 *                       Range: \ref IfxGeth_TxDmaChannel
 * \param[in]    address Address of the last valid descriptor in the Transmit descriptor list.
 *                       Range: 0 to 0xFFFFFFFC
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setTxDescriptorTailPointer(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, uint32 address);

/**
 * \brief Sets the programmable burst length of the selected Tx channel of DMA.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Tx channel ID.
 *                       Range: \ref IfxGeth_TxDmaChannel
 * \param[in]    length  Programmable burst length.
 *                       Range: \ref IfxGeth_DmaBurstLength
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setTxMaxBurstLength(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, IfxGeth_DmaBurstLength length);

/**
 * \brief starts the receiver of selected Rx channel of DMA.
 *
 * \param[inout] gethSFR Pointer to GETH register base address.
 * \param[in]    channel Rx channel Id.
 *                       Range: \ref IfxGeth_RxDmaChannel
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_startReceiver(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel);

/**
 * \brief Starts the transmitter of the selected Tx DMA channel.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Tx channel ID to be started.
 *                       Range: \ref IfxGeth_TxDmaChannel
 *
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_startTransmitter(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel);

/**
 * \brief Stops the transmitter of a selected Tx DMA channel.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Tx channel ID.
 *                       Range: \ref IfxGeth_TxDmaChannel
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_stopTransmitter(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel);

/**
 * \brief Enables or disables the Tx DMA to operate on the second frame.
 *
 * \param[inout] gethSFR Pointer to the GETH register base address.
 * \param[in]    channel Tx DMA channel ID.
 *                       Range: \ref IfxGeth_TxDmaChannel
 * \param[in]    enable Boolean flag to enable (TRUE) or disable (FALSE).
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_dma_setTxOSF(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, boolean enable);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables/Disables the MAC operation in the loopback mode at GMII or MII.
 *
 * \param[inout] gethSFR Pointer to GETH register base address.
 * \param[in]    mode    Loopback Mode Enable / Disable.
 *
 * \retval None
 */
IFX_INLINE void IfxGeth_mac_setLoopbackMode(Ifx_GETH *gethSFR, IfxGeth_LoopbackMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reads a 32-bit value from a specified MDIO register of Clause 22 PHY.
 *
 * \param[in]    layerAddr The layer address of the PHY device.
 *                         Range: 0 to 0xFFF7F1F
 * \param[in]    regAddr   The address of the MDIO register to read.
 *                         Range: 0 to 0xFFF7F1F
 * \param[inout] pData     Pointer to the variable where the read data will be stored.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_phy_Clause22_readMDIORegister(uint32 layerAddr, uint32 regAddr, uint32 *pData);

/**
 * \brief Writes data to a specified MDIO register of Clause 22 PHY.
 *
 * \param[in] layerAddr The layer address of the PHY device.
 *                      Range: 0 to 0xFFF7F1F
 * \param[in] regAddr   The register address within the PHY layer.
 *                      Range: 0 to 0xFFF7F1F
 * \param[in] data      The data value to be written to the specified register.
 *                      Range: 0 to 0xFFF7F1F
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Phy_Clause22_writeMDIORegister(uint32 layerAddr, uint32 regAddr, uint32 data);

/**
 * \brief Reads a 32-bit value from a Clause 45 PHY MDIO register.
 *
 * \param[in]    layerAddr  Layer address within the Clause 45 PHY device.
 *                          Range: 0 to 0xFFF7F1F
 * \param[in]    deviceAddr Device address within the specified layer.
 *                          Range: 0 to 0xFFF7F1F
 * \param[in]    regAddr    Register address to read from.
 *                          Range: 0 to 0xFFF7F1F
 * \param[inout] pData      Pointer to a uint32 where the read data will be stored.
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_phy_Clause45_readMDIORegister(uint32 layerAddr, uint32 deviceAddr, uint32 regAddr, uint32 *pData);

/**
 * \brief Writes data to a specific MDIO register for Clause 45 PHY.
 *
 * \param[in] layerAddr  The layer address to be used for the MDIO operation.
 *                       Range: 0 to 0xFFF7F1F
 * \param[in] deviceAddr The device address within the specified layer.
 *                       Range: 0 to 0xFFF7F1F
 * \param[in] regAddr    The register address within the specified device.
 *                       Range: 0 to 0xFFF7F1F
 * \param[in] data       The data value to be written to the specified register.
 *                       Range: 0 to 0xFFF7F1F
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_Phy_Clause45_writeMDIORegister(uint32 layerAddr, uint32 deviceAddr, uint32 regAddr, uint32 data);

/**
 * \brief Configures the maximum packet size for the MAC.
 *
 * \param[in] gethSFR       Pointer to the GETH register base address.
 * \param[in] maxPacketSize Minimum size of the frame beyond which giant packet status is set.
 *                          Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxGeth_mac_setMaxPacketSize(Ifx_GETH *gethSFR, uint16 maxPacketSize);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGeth_dma_applySoftwareReset(Ifx_GETH *gethSFR)
{
    gethSFR->DMA_MODE.B.SWR = 1;
}


IFX_INLINE void IfxGeth_dma_clearAllInterruptFlags(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId)
{
    gethSFR->DMA_CH[channelId].STATUS.U = 0;
}


IFX_INLINE void IfxGeth_dma_clearInterruptFlag(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId, IfxGeth_DmaInterruptFlag flag)
{
    uint32 value = (1 << flag);
    gethSFR->DMA_CH[channelId].STATUS.U = value;
}


IFX_INLINE void IfxGeth_dma_disableInterrupt(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId, IfxGeth_DmaInterruptFlag flag)
{
    uint32 value = ~(1 << flag);
    gethSFR->DMA_CH[channelId].INTERRUPT_ENABLE.U &= value;
}


IFX_INLINE void IfxGeth_dma_enableInterrupt(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId, IfxGeth_DmaInterruptFlag flag)
{
    uint32 value = (1 << flag);
    gethSFR->DMA_CH[channelId].INTERRUPT_ENABLE.U |= value;
}


IFX_INLINE boolean IfxGeth_dma_isInterruptFlagSet(Ifx_GETH *gethSFR, IfxGeth_DmaChannel channelId, IfxGeth_DmaInterruptFlag flag)
{
    uint32 value = (1 << flag);

    if (gethSFR->DMA_CH[channelId].STATUS.U & (Ifx_UReg_32Bit)value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


IFX_INLINE boolean IfxGeth_dma_isSoftwareResetDone(Ifx_GETH *gethSFR)
{
    return gethSFR->DMA_MODE.B.SWR == 0;
}


IFX_INLINE void IfxGeth_dma_setAddressAlignedBeats(Ifx_GETH *gethSFR, boolean enabled)
{
    gethSFR->DMA_SYSBUS_MODE.B.AAL = enabled;
}


IFX_INLINE void IfxGeth_dma_setFixedBurst(Ifx_GETH *gethSFR, boolean enabled)
{
    gethSFR->DMA_SYSBUS_MODE.B.FB = enabled;
}


IFX_INLINE void IfxGeth_dma_setMixedBurst(Ifx_GETH *gethSFR, boolean enabled)
{
    gethSFR->DMA_SYSBUS_MODE.B.MB = enabled;
}


IFX_INLINE void IfxGeth_dma_setRxBufferSize(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint16 size)
{
    /* [RBSZ_13_Y:RBSZ_X_0] represents the size of the Rx buffer*/
    gethSFR->DMA_CH[channel].RX_CONTROL.B.RBSZ_13_Y = (uint32)((size >> 2) & IFX_GETH_DMA_CH_RX_CONTROL_RBSZ_13_Y_MSK);
}


IFX_INLINE void IfxGeth_dma_setRxDescriptorListAddress(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint32 address)
{
    gethSFR->DMA_CH[channel].RXDESC_LIST_ADDRESS.U = (uint32)address;
}


IFX_INLINE void IfxGeth_dma_setRxDescriptorRingLength(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint32 length)
{
    gethSFR->DMA_CH[channel].RXDESC_RING_LENGTH.U = length;
}


IFX_INLINE void IfxGeth_dma_setRxDescriptorTailPointer(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint32 address)
{
    gethSFR->DMA_CH[channel].RXDESC_TAIL_POINTER.U = address;
}


IFX_INLINE void IfxGeth_dma_setRxMaxBurstLength(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, IfxGeth_DmaBurstLength length)
{
    gethSFR->DMA_CH[channel].RX_CONTROL.B.RXPBL = length;
}


IFX_INLINE void IfxGeth_dma_setTxDescriptorListAddress(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, uint32 address)
{
    gethSFR->DMA_CH[channel].TXDESC_LIST_ADDRESS.U = address;
}


IFX_INLINE void IfxGeth_dma_setTxDescriptorRingLength(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, uint32 length)
{
    gethSFR->DMA_CH[channel].TXDESC_RING_LENGTH.U = length;
}


IFX_INLINE void IfxGeth_dma_setTxDescriptorTailPointer(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, uint32 address)
{
    gethSFR->DMA_CH[channel].TXDESC_TAIL_POINTER.U = (uint32)address;
}


IFX_INLINE void IfxGeth_dma_setTxMaxBurstLength(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, IfxGeth_DmaBurstLength length)
{
    gethSFR->DMA_CH[channel].TX_CONTROL.B.TXPBL = length;
}


IFX_INLINE void IfxGeth_dma_startReceiver(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel)
{
    gethSFR->DMA_CH[channel].RX_CONTROL.B.SR = TRUE;
}


IFX_INLINE void IfxGeth_dma_startTransmitter(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel)
{
    gethSFR->DMA_CH[channel].TX_CONTROL.B.ST = TRUE;
}


IFX_INLINE void IfxGeth_dma_stopTransmitter(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel)
{
    gethSFR->DMA_CH[channel].TX_CONTROL.B.ST = FALSE;
}


IFX_INLINE boolean IfxGeth_isModuleEnabled(Ifx_GETH *gethSFR)
{
    return (gethSFR->CLC.B.DISS == 0) ? 1 : 0;
}


IFX_INLINE void IfxGeth_mac_disableReceiver(Ifx_GETH *gethSFR)
{
    gethSFR->MAC_CONFIGURATION.B.RE = 0;
}


IFX_INLINE void IfxGeth_mac_disableTransmitter(Ifx_GETH *gethSFR)
{
    gethSFR->MAC_CONFIGURATION.B.TE = 0;
}


IFX_INLINE void IfxGeth_mac_enableReceiver(Ifx_GETH *gethSFR)
{
    gethSFR->MAC_CONFIGURATION.B.RE = 1;
}


IFX_INLINE void IfxGeth_mac_enableTransmitter(Ifx_GETH *gethSFR)
{
    gethSFR->MAC_CONFIGURATION.B.TE = 1;
}


IFX_INLINE void IfxGeth_mac_setAllMulticastPassing(Ifx_GETH *gethSFR, boolean enabled)
{
    gethSFR->MAC_PACKET_FILTER.B.PM = ((enabled == 1) ? 1 : 0);
}


IFX_INLINE void IfxGeth_mac_setCrcChecking(Ifx_GETH *gethSFR, boolean enabled)
{
    gethSFR->MAC_EXT_CONFIGURATION.B.DCRCC = ((enabled == 1) ? 0 : 1);
}


IFX_INLINE void IfxGeth_mac_setCrcStripping(Ifx_GETH *gethSFR, boolean acsEnabled, boolean cstEnabled)
{
    gethSFR->MAC_CONFIGURATION.B.ACS = ((acsEnabled == 1) ? 1 : 0);
    gethSFR->MAC_CONFIGURATION.B.CST = ((cstEnabled == 1) ? 1 : 0);
}


IFX_INLINE void IfxGeth_mac_setDuplexMode(Ifx_GETH *gethSFR, IfxGeth_DuplexMode mode)
{
    gethSFR->MAC_CONFIGURATION.B.DM = mode;
}


IFX_INLINE void IfxGeth_mac_setLoopbackMode(Ifx_GETH *gethSFR, IfxGeth_LoopbackMode mode)
{
    gethSFR->MAC_CONFIGURATION.B.LM = mode;
}


IFX_INLINE void IfxGeth_mac_setPreambleLength(Ifx_GETH *gethSFR, IfxGeth_PreambleLength length)
{
    gethSFR->MAC_CONFIGURATION.B.PRELEN = length;
}


IFX_INLINE void IfxGeth_mac_setPromiscuousMode(Ifx_GETH *gethSFR, boolean enabled)
{
    gethSFR->MAC_PACKET_FILTER.B.PR = ((enabled == 1) ? 1 : 0);
}


IFX_INLINE void IfxGeth_mtl_enableRxQueue(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId)
{
    gethSFR->MAC_RXQ_CTRL0.U |= (2 << (queueId * 2));
}


IFX_INLINE void IfxGeth_mtl_setRxArbitrationAlgorithm(Ifx_GETH *gethSFR, IfxGeth_RxArbitrationAlgorithm arbitrationAlgorithm)
{
    gethSFR->MTL_OPERATION_MODE.B.RAA = arbitrationAlgorithm;
}


IFX_INLINE void IfxGeth_mtl_setRxQueueDmaChannelMapping(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId, IfxGeth_RxDmaChannel dmaChannel)
{
    gethSFR->MTL_RXQ_DMA_MAP0.U |= (dmaChannel << (queueId * 8));
}


IFX_INLINE void IfxGeth_mtl_setRxQueueForDaBasedDmaChannel(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId, boolean enabled)
{
    gethSFR->MTL_RXQ_DMA_MAP0.U |= (enabled << ((queueId * 8) + 4));
}


IFX_INLINE void IfxGeth_mtl_setTxSchedulingAlgorithm(Ifx_GETH *gethSFR, IfxGeth_TxSchedulingAlgorithm schedulingAlgorithm)
{
    gethSFR->MTL_OPERATION_MODE.B.SCHALG = schedulingAlgorithm;
}


IFX_INLINE void IfxGeth_setPhyInterfaceMode(Ifx_GETH *gethSFR, IfxGeth_PhyInterfaceMode mode)
{
    gethSFR->GPCTL.B.EPR = mode;
}


IFX_INLINE void IfxGeth_mac_setVlanPriorityQueueRouting(Ifx_GETH *gethSFR, IfxGeth_RxDmaChannel channel, uint8 priorities)
{
    gethSFR->MAC_RXQ_CTRL2.U = (gethSFR->MAC_RXQ_CTRL2.U & ((uint32)~(0xFFU << (channel * 8)))) | (priorities << (channel * 8));
}


IFX_INLINE void IfxGeth_mtl_enableUnicastFilterFailQueuing(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId)
{
    gethSFR->MAC_RXQ_CTRL4.B.UFFQ  = queueId;
    gethSFR->MAC_RXQ_CTRL4.B.UFFQE = TRUE;
}


IFX_INLINE void IfxGeth_mtl_disableUnicastFilterFailQueuing(Ifx_GETH *gethSFR)
{
    gethSFR->MAC_RXQ_CTRL4.B.UFFQE = FALSE;
}


IFX_INLINE void IfxGeth_mtl_enableMulticastFilterFailQueuing(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId)
{
    gethSFR->MAC_RXQ_CTRL4.B.MFFQ  = queueId;
    gethSFR->MAC_RXQ_CTRL4.B.MFFQE = TRUE;
}


IFX_INLINE void IfxGeth_mtl_disableMulticastFilterFailQueuing(Ifx_GETH *gethSFR)
{
    gethSFR->MAC_RXQ_CTRL4.B.MFFQE = FALSE;
}


IFX_INLINE void IfxGeth_mtl_enableVlanFilterFailQueuing(Ifx_GETH *gethSFR, IfxGeth_RxMtlQueue queueId)
{
    gethSFR->MAC_RXQ_CTRL4.B.VFFQ  = queueId;
    gethSFR->MAC_RXQ_CTRL4.B.VFFQE = TRUE;
}


IFX_INLINE void IfxGeth_mtl_disableVlanFilterFailQueuing(Ifx_GETH *gethSFR)
{
    gethSFR->MAC_RXQ_CTRL4.B.VFFQE = FALSE;
}


IFX_INLINE void IfxGeth_mac_setQueueVlanInsertion(Ifx_GETH *gethSFR, boolean enable)
{
    gethSFR->MAC_VLAN_INCL.B.CBTI = enable;
}


IFX_INLINE void IfxGeth_dma_setTxOSF(Ifx_GETH *gethSFR, IfxGeth_TxDmaChannel channel, boolean enable)
{
    gethSFR->DMA_CH[channel].TX_CONTROL.B.OSF = enable;
}


#endif /* IFXGET_H */
