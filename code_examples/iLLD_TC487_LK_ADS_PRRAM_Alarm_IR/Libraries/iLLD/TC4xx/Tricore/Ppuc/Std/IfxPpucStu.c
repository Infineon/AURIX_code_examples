/**
 * \file IfxPpucStu.c
 * \brief PPUC basic functionality
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508 	    /* To suppress empty file warning */
#endif    
#if defined (__ghs__)    
#pragma diag_suppress 96    /* To suppress empty file warning */
#endif

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) ||defined(DEVICE_TC46X) || defined(DEVICE_TC45X) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX)
#include "IfxPpucStu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPpucStu_initChannel(Ifx_PPU *ppuc, uint8 channelNum, uint32 stuDescriptor, IfxPpucStu_channelConfig *channelConfig)
{
    uint32           tempStuCtrlReg = 0U;
    volatile uint32 *stuCtrlReg;
    volatile uint32 *stuSizeReg;
    volatile uint32 *stuSrcReg;
    volatile uint32 *stuDstReg;
    volatile uint32 *stuWidth;
    volatile uint32 *stuStride;
    uint8            maxChannels = (1 << (IfxPpucStu_getMaxChannels(ppuc) + 4));
    uint16           entryNum    = 4U * channelNum;

    stuCtrlReg      = (volatile uint32 *)(stuDescriptor + (0U * maxChannels) + (entryNum));
    stuSizeReg      = (volatile uint32 *)(stuDescriptor + (4U * maxChannels) + (entryNum));
    stuSrcReg       = (volatile uint32 *)(stuDescriptor + (8U * maxChannels) + (entryNum));
    stuDstReg       = (volatile uint32 *)(stuDescriptor + (12U * maxChannels) + (entryNum));
    stuWidth        = (volatile uint32 *)(stuDescriptor + (16U * maxChannels) + (entryNum));
    stuStride       = (volatile uint32 *)(stuDescriptor + (20U * maxChannels) + (entryNum));

    tempStuCtrlReg |= (channelConfig->srcMemType) << IFXPPUCSTU_SRC_MEMTYPE_OFFSET;
    tempStuCtrlReg |= (channelConfig->dstMemType) << IFXPPUCSTU_DST_MEMTYPE_OFFSET;

    if (channelConfig->srcMemType == IfxPpucStu_Memory_private)
    {
        tempStuCtrlReg |= (channelConfig->srcLaneId) << IFXPPUCSTU_SRC_LANDEID_OFFSET;
        tempStuCtrlReg |= (channelConfig->srcLaneWidth) << IFXPPUCSTU_SRC_LANEWIDTH_OFFSET;
    }

    if (channelConfig->dstMemType == IfxPpucStu_Memory_private)
    {
        tempStuCtrlReg |= (channelConfig->dstLaneId) << IFXPPUCSTU_DST_LANDEID_OFFSET;
        tempStuCtrlReg |= (channelConfig->dstLaneWidth) << IFXPPUCSTU_DST_LANEWIDTH_OFFSET;
    }

    tempStuCtrlReg |= (channelConfig->addressingMode) << IFXPPUCSTU_ADDR_MODE_OFFSET;

    if ((channelConfig->addressingMode) == IfxPpucStu_AddressingMode_block)
    {
        *stuWidth  = ((channelConfig->srcWidth - 1) | ((channelConfig->dstWidth - 1) << IFXPPUCSTU_DSTWIDTH_OFFSET));
        *stuStride = ((channelConfig->srcStride - 1) | ((channelConfig->dstStride - 1) << IFXPPUCSTU_DSTWIDTH_OFFSET));
    }

    tempStuCtrlReg |= (channelConfig->signalType) << IFXPPUCSTU_SIGNALTYPE_OFFSET;

    *stuCtrlReg     = tempStuCtrlReg;

    *stuSizeReg     = (channelConfig->transferSize) - 1U;

    *stuSrcReg      = (channelConfig->sourceAddress);

    *stuDstReg      = (channelConfig->destinationAddress);
}


void IfxPpucStu_initChannelConfig(IfxPpucStu_channelConfig *channelConfig)
{
    const IfxPpucStu_channelConfig defaultConfig = {
        .sourceAddress      = 0x0U,
        .destinationAddress = 0x0U,
        .transferSize       = 0x0U,
        .signalType         = IfxPpucStu_SignalType_event,
        .srcMemType         = IfxPpucStu_Memory_system,
        .dstMemType         = IfxPpucStu_Memory_system,
        .srcLaneId          = IfxPpucStu_LaneId_0,
        .dstLaneId          = IfxPpucStu_LaneId_0,
        .srcLaneWidth       = IfxPpucStu_LandeWidth_16,
        .dstLaneWidth       = IfxPpucStu_LandeWidth_16,
        .srcWidth           = 1U,
        .dstWidth           = 1U,
        .srcStride          = 1U,
        .dstStride          = 1U
    };
    *channelConfig = defaultConfig;
}


void IfxPpucStu_configureAccessToPpucStuDmi(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_PPU_APU.AP.ACCEN.STUDMI, apConfig);
}

#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) ||defined(DEVICE_TC46X) || defined(DEVICE_TC45X)  || defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
