/**
 * \file ifx_oe_oscibb.c
 *
 * \copyright Copyright (c) 2022 Infineon Technologies AG. All rights reserved.
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such
 * terms of use are agreed, use of this file is subject to following:
 *
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or
 * organization obtaining a copy of the software and accompanying
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
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
 */
#include "ifx_oe_oscibb.h"
#include "ifx_oe_oscibbmessages.h"
#include <string.h>

static boolean Ifx_Oe_OsciBb_sendOscilloscopeState(Ifx_Oe_OsciBb* bb);
static boolean Ifx_Oe_OsciBb_sendOscilloscopeSignalInfo(Ifx_Oe_OsciBb* bb, Ifx_Oe_Osci_SignalId signalId);
static boolean Ifx_Oe_OsciBb_sendOscilloscopeChannelInfo(Ifx_Oe_OsciBb* bb, Ifx_Oe_Osci_ChannelId channelId);
static void    Ifx_Oe_OsciBb_sendOscilloscopeSendChannelsData(Ifx_Oe_OsciBb* bb);

boolean        Ifx_Oe_OsciBb_init(Ifx_Oe_OsciBb* bb, Ifx_Oe_Osci* osci, Ifx_Oe_SyncProtocol* protocol, Ifx_Oe_SyncProtocol_Port localPort, Ifx_Oe_SyncProtocol_Port remotePort)
{
    bb->_osci                  = osci;
    bb->_osciChannelDataOffset = 0;
    bb->_OsciChannelId         = 0;
    Ifx_Oe_Osci_setRemoteControl(osci, TRUE);
    bb->_osciStateSend         = FALSE;
    bb->_osciSignalInfoSend    = 0;
    bb->_osciChannelInfoSend   = 0;

    return Ifx_Oe_SyncProtocol_addClient(protocol, &bb->_bbClient, localPort, remotePort, IFX_OE_SYNCPROTOCOL_MESSAGE_PAYLOAD_MAX_LENGTH, IFX_OE_OSCIBB_TX_BUFFER_LENGTH);
}


static boolean Ifx_Oe_OsciBb_sendOscilloscopeState(Ifx_Oe_OsciBb* bb)
{
    Ifx_Oe_SyncProtocol_Message* message = (Ifx_Oe_SyncProtocol_Message*)Ifx_Oe_SyncProtocol_setSendMessageBuffer(
        &bb->_bbClient,
        IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_STATE,
        sizeof(Ifx_Oe_Osci_MessageState));

    if (message != NULL_PTR)
    {
        Ifx_Oe_Osci_MessageState* m = (Ifx_Oe_Osci_MessageState*)message->messagePayload;

        m->triggerLevel        = Ifx_Oe_Osci_getTriggerLevel(bb->_osci);
        m->samplingPeriod      = Ifx_Oe_Osci_getSamplingPeriod(bb->_osci);
        m->flags.enabled       = Ifx_Oe_Osci_isRunning(bb->_osci) ? 1 : 0;
        m->flags.triggerSingle = Ifx_Oe_Osci_getTriggerSingle(bb->_osci) ? 1 : 0;

        switch (Ifx_Oe_Osci_getTriggerMode(bb->_osci))
        {
        case Ifx_Oe_Osci_TriggerMode_normal:
            m->flags.triggerMode = 0;
            break;
        case Ifx_Oe_Osci_TriggerMode_automatic:
            m->flags.triggerMode = 1;
            break;
        case Ifx_Oe_Osci_TriggerMode_inverted:
            m->flags.triggerMode = 2;
            break;
        case Ifx_Oe_Osci_TriggerMode_align32Bit:
            IFX_OE_ASSERT(FALSE);
            m->flags.triggerMode = 1; /* Default to 1*/
            break;
        }

        switch (Ifx_Oe_Osci_getTriggerEdge(bb->_osci))
        {
        case Ifx_Oe_Osci_TriggerEdge_falling:
            m->flags.triggerEdge = 0;
            break;
        case Ifx_Oe_Osci_TriggerEdge_rising:
            m->flags.triggerEdge = 1;
            break;
        case Ifx_Oe_Osci_TriggerEdge_align32Bit:
            IFX_OE_ASSERT(FALSE);
            m->flags.triggerEdge = 1;
            break;
        }

        m->flags.state      = Ifx_Oe_Osci_getTriggerState(bb->_osci);
        m->flags.reserved   = 0;
        m->samplingInterval = Ifx_Oe_Osci_getSamplingInterval(bb->_osci);
        m->triggerChannel   = Ifx_Oe_Osci_getTriggerSource(bb->_osci);
        m->numberOfChannels = Ifx_Oe_Osci_getNumberOfChannels(bb->_osci);
        m->numberOfSignals  = Ifx_Oe_Osci_getUsedSignals(bb->_osci);
        m->maxDepth         = Ifx_Oe_Osci_getMaxDepth();
        m->depth            = Ifx_Oe_Osci_getDepth(bb->_osci);
        Ifx_Oe_SyncProtocol_sendMessage(message);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


static boolean Ifx_Oe_OsciBb_sendOscilloscopeSignalInfo(Ifx_Oe_OsciBb* bb, Ifx_Oe_Osci_SignalId signalId)
{
    Ifx_Oe_Osci_Signal* info = Ifx_Oe_Osci_getSignalInfo(bb->_osci, signalId);

    if (info != NULL)
    {
        Ifx_Oe_SyncProtocol_Message* message = Ifx_Oe_SyncProtocol_setSendMessageBuffer(
            &bb->_bbClient,
            IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_SIGNAL_INFO,
            16 + strlen(info->name) + 1);

        if (message != NULL_PTR)
        {
            Ifx_Oe_Osci_MessageSignalInfo* m = (Ifx_Oe_Osci_MessageSignalInfo*)message->messagePayload;

            IFX_OE_ASSERT(strlen(info->name) < sizeof(m->name));

            m->signalId    = (uint16)signalId;
            m->reserved[0] = 0;
            m->reserved[1] = 0;
            m->reserved[2] = 0;
            m->reserved[4] = 0;
            m->reserved[5] = 0;
            m->reserved[6] = 0;
            strcpy((char*)m->name, info->name);
            Ifx_Oe_SyncProtocol_sendMessage(message);
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        Ifx_Oe_SyncProtocol_Message* message = Ifx_Oe_SyncProtocol_setSendMessageBuffer(
            &bb->_bbClient,
            IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_SIGNAL_INFO,
            16 + 0 + 1);

        if (message != NULL_PTR)
        {
            Ifx_Oe_Osci_MessageSignalInfo* m = (Ifx_Oe_Osci_MessageSignalInfo*)message->messagePayload;

            m->signalId    = (uint16)signalId;
            m->reserved[0] = 0;
            m->reserved[1] = 0;
            m->reserved[2] = 0;
            m->reserved[4] = 0;
            m->reserved[5] = 0;
            m->reserved[6] = 0;
            m->name[0]     = 0;
            Ifx_Oe_SyncProtocol_sendMessage(message);
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}


static boolean Ifx_Oe_OsciBb_sendOscilloscopeChannelInfo(Ifx_Oe_OsciBb* bb, Ifx_Oe_Osci_ChannelId channelId)
{
    Ifx_Oe_SyncProtocol_Message* message = Ifx_Oe_SyncProtocol_setSendMessageBuffer(
        &bb->_bbClient,
        IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_ASSIGNED_CHANNEL,
        sizeof(Ifx_Oe_Osci_MessageAssignedChannel));

    if (message != NULL_PTR)
    {
        Ifx_Oe_Osci_MessageAssignedChannel* m = (Ifx_Oe_Osci_MessageAssignedChannel*)message->messagePayload;
        m->channelId = channelId;
        m->signalId  = (uint16)Ifx_Oe_Osci_getChannelSignal(bb->_osci, channelId);
        m->dataDepth = Ifx_Oe_Osci_getDepth(bb->_osci);
        Ifx_Oe_SyncProtocol_sendMessage(message);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


static void Ifx_Oe_OsciBb_sendOscilloscopeSendChannelsData(Ifx_Oe_OsciBb* bb)
{
    uint8 newData = 0;

    if (Ifx_Oe_SyncProtocol_isSendBusy(&bb->_bbClient))
    {
        return;
    }

    if (!bb->_osciStateSend)
    {
        bb->_osciStateSend = Ifx_Oe_OsciBb_sendOscilloscopeState(bb);
    }
    else if (bb->_osciSignalInfoSend < IFX_CFG_OE_OSCI_MAX_NUM_OF_SIGNALS)
    {
        if (Ifx_Oe_OsciBb_sendOscilloscopeSignalInfo(bb, bb->_osciSignalInfoSend))
        {
            bb->_osciSignalInfoSend++;
        }
    }
    else if (bb->_osciChannelInfoSend < Ifx_Oe_Osci_getNumberOfChannels(bb->_osci))
    {
        if (Ifx_Oe_OsciBb_sendOscilloscopeChannelInfo(bb, bb->_osciChannelInfoSend))
        {
            bb->_osciChannelInfoSend++;
        }
    }
    else if (Ifx_Oe_Osci_getTriggerState(bb->_osci) == Ifx_Oe_Osci_TriggerState_dataTransfer)
    {
        if ((bb->_OsciChannelId == 0) && (bb->_osciChannelDataOffset == 0))
        {
            /* Wait for new data */
            while ((bb->_OsciChannelId < Ifx_Oe_Osci_getNumberOfChannels(bb->_osci)) && (Ifx_Oe_Osci_getChannelSignal(bb->_osci, bb->_OsciChannelId) == IFX_OE_OSCI_NO_SIGNAL))
            {
                bb->_OsciChannelId++;
            }

            newData = 1;
        }

        if (bb->_OsciChannelId < Ifx_Oe_Osci_getNumberOfChannels(bb->_osci))
        {
            Ifx_Oe_SyncProtocol_Message* message = Ifx_Oe_SyncProtocol_setSendMessageBuffer(
                &bb->_bbClient,
                IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CHANNEL_DATA,
                sizeof(Ifx_Oe_Osci_MessageChannelData));

            if (message != NULL_PTR)
            {
                Ifx_Oe_Osci_MessageChannelData* m = (Ifx_Oe_Osci_MessageChannelData*)message->messagePayload;
                uint16                          index;
                uint32                          length;
                float32*                        data;
                length = Ifx_Oe_Osci_getDepth(bb->_osci) - bb->_osciChannelDataOffset;
                length = length > IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CHANNEL_DATA_MAX_PAYLOAD
                         ? IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CHANNEL_DATA_MAX_PAYLOAD
                         : length;

                m->channelId                = bb->_OsciChannelId;
                m->signalId                 = (uint16)Ifx_Oe_Osci_getChannelSignal(bb->_osci, bb->_OsciChannelId);
                m->flags.dataLength         = length;
                m->flags.newData            = newData;
                m->flags.allDone            = 0;
                m->flags.reserved           = 0;
                m->reserved                 = 0;
                m->dataOffset               = bb->_osciChannelDataOffset;
                bb->_osciChannelDataOffset += length;

                data                        = Ifx_Oe_Osci_getChannelDataPointer(bb->_osci, m->channelId);

                for (index = 0; index < m->flags.dataLength; index++)
                {
                    m->data[index] = data[m->dataOffset + index];
                }

                if (bb->_osciChannelDataOffset == Ifx_Oe_Osci_getDepth(bb->_osci))
                {
                    bb->_osciChannelDataOffset = 0;
                    bb->_OsciChannelId++;

                    while ((bb->_OsciChannelId < Ifx_Oe_Osci_getNumberOfChannels(bb->_osci)) && (Ifx_Oe_Osci_getChannelSignal(bb->_osci, bb->_OsciChannelId) == IFX_OE_OSCI_NO_SIGNAL))
                    {
                        bb->_OsciChannelId++;
                    }

                    if (bb->_OsciChannelId >= Ifx_Oe_Osci_getNumberOfChannels(bb->_osci))
                    {
                        /* Automatically restart */
                        Ifx_Oe_Osci_setDataTransfered(bb->_osci);
                        bb->_OsciChannelId         = 0;
                        bb->_osciChannelDataOffset = 0;
                        m->flags.allDone           = 1;
                    }
                }

                Ifx_Oe_SyncProtocol_sendMessage(message);
            }
        }
    }
}


void Ifx_Oe_OsciBb_processMessages(Ifx_Oe_OsciBb* bb)
{
    if (bb->_osci == NULL)
    {   /* BB un-initialized */
        return;
    }

    if (bb->_bbClient.receive.messageValid)
    {
        Ifx_Oe_SyncProtocol_MessageId id;
        uint32                        length;
        uint8*                        payloadRx;

        if (Ifx_Oe_SyncProtocol_getReadMessageBuffer(&bb->_bbClient, &id, &payloadRx, &length))
        {
            switch (id)
            {
            case IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CONTROL_CMD:
            {
                Ifx_Oe_Osci_MessageControlCmd* m = (Ifx_Oe_Osci_MessageControlCmd*)payloadRx;
                Ifx_Oe_Osci_ControlInterface   actions;

                Ifx_Oe_Osci_clearControldata(&actions);

                if (m->flags.enabled)
                {
                    actions.enable             = 3; /* Enable the Osci */
                    actions.armTrigger         = 1;
                    actions.dataTransfered     = 1;
                    bb->_osciChannelDataOffset = 0;
                    bb->_OsciChannelId         = 0;
                }
                else
                {
                    actions.enable = 2;
                }

                if (m->flags.triggerSingle)
                {
                    actions.single = 3;
                }
                else
                {
                    actions.single = 2;
                }

                switch (m->flags.triggerMode)
                {
                case 0:

                    if (Ifx_Oe_Osci_getTriggerMode(bb->_osci) != Ifx_Oe_Osci_TriggerMode_normal)
                    {
                        actions.triggerMode = 0x4 | Ifx_Oe_Osci_TriggerMode_normal;
                    }

                    break;
                case 1:

                    if (Ifx_Oe_Osci_getTriggerMode(bb->_osci) != Ifx_Oe_Osci_TriggerMode_automatic)
                    {
                        actions.triggerMode = 0x4 | Ifx_Oe_Osci_TriggerMode_automatic;
                    }

                    break;
                case 2:

                    if (Ifx_Oe_Osci_getTriggerMode(bb->_osci) != Ifx_Oe_Osci_TriggerMode_inverted)
                    {
                        actions.triggerMode = 0x4 | Ifx_Oe_Osci_TriggerMode_inverted;
                    }

                    break;
                }

                switch (m->flags.triggerEdge)
                {
                case 0:

                    actions.triggerEdge = 0x2 | Ifx_Oe_Osci_TriggerEdge_falling;
                    break;
                case 1:
                    actions.triggerEdge = 0x2 | Ifx_Oe_Osci_TriggerEdge_rising;
                    break;
                }

                actions.setTriggerLevel = 1;
                actions.triggerLevel    = m->triggerLevel;

                if (Ifx_Oe_Osci_getSamplingInterval(bb->_osci) != m->samplingInterval)
                {
                    actions.setSamplingInterval = 1;
                    actions.samplingInterval    = m->samplingInterval;
                }

                if (Ifx_Oe_Osci_getTriggerSource(bb->_osci) != m->triggerChannel)
                {
                    actions.setTriggerSource = 1;
                    actions.triggerSource    = m->triggerChannel;
                }

                if ((Ifx_Oe_Osci_getDepth(bb->_osci) != m->depth) && (m->depth != 0))
                {
                    actions.setBufferDepth = 1;
                    actions.bufferDepth    = m->depth;
                }

                Ifx_Oe_Osci_setControl(bb->_osci, &actions);
            }
                // _osciStateSend = FALSE;
                break;

            case IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_GET_STATE_REQ:
            {
                bb->_osciStateSend       = FALSE;
                bb->_osciSignalInfoSend  = 0;
                bb->_osciChannelInfoSend = 0;
            }
            break;

            case IFX_OE_SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_ASSIGN_CHANNEL_CMD:
            {
                Ifx_Oe_Osci_MessageAssignChannel* m = (Ifx_Oe_Osci_MessageAssignChannel*)payloadRx;

                Ifx_Oe_Osci_associateSignalToChannel(bb->_osci, m->signalId, m->channelId);
            }
            break;
            }

            Ifx_Oe_SyncProtocol_releaseReadMessageBuffer(&bb->_bbClient);
        }
    }

    bb->_osciStateSend &= !Ifx_Oe_Osci_isStateChanged(bb->_osci);
    Ifx_Oe_OsciBb_sendOscilloscopeSendChannelsData(bb);
}
