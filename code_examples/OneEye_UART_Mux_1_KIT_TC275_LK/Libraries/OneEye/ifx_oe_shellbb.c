/**
 * \file ifx_oe_shellbb.c
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

#include "ifx_oe_shellbb.h"
#include "ifx_oe_shell.h"

boolean Ifx_Oe_ShellBb_init(Ifx_Oe_ShellBb* bb, Ifx_Oe_SyncProtocol* protocol, Ifx_Oe_SyncProtocol_Port localPort, Ifx_Oe_SyncProtocol_Port remotePort, Ifx_Oe_SizeT rxBufferSize, Ifx_Oe_SizeT txBufferSize)
{
    Ifx_Oe_FifoDPipe_init(&bb->_dPipe, rxBufferSize, txBufferSize);

    return Ifx_Oe_SyncProtocol_addClient(protocol, &bb->_bbClient, localPort, remotePort, IFX_OE_SYNCPROTOCOL_MESSAGE_PAYLOAD_MAX_LENGTH, IFX_OE_SHELLBB_TX_BUFFER_LENGTH);
}


void Ifx_Oe_ShellBb_processMessagesPrivate(Ifx_Oe_SyncProtocol_Client* bbClient, Ifx_Oe_FifoDPipe* dPipe)
{
    /* Process received */
    if (bbClient->receive.messageValid)
    {
        Ifx_Oe_SyncProtocol_MessageId id;
        uint32                        length;
        uint8*                        payloadRx;

        if (Ifx_Oe_SyncProtocol_getReadMessageBuffer(bbClient, &id, &payloadRx, &length))
        {
            switch (id)
            {
            case IFX_OE_SYNCPROTOCOL_MESSAGE_ID_RAWBUFFER:
            {
                Ifx_Oe_Fifo_write(dPipe->rx, payloadRx, (Ifx_Oe_SizeT)length, IFX_CFG_OE_SHELL_TIMEOUT);
            }
            break;
            }

            Ifx_Oe_SyncProtocol_releaseReadMessageBuffer(bbClient);
        }
    }

    /* Process data to be send */
    if (Ifx_Oe_SyncProtocol_isSendBusy(bbClient))
    {
        return;
    }

    if (Ifx_Oe_Fifo_isEmpty(dPipe->tx) == FALSE)
    {
        uint32 length;

        length = Ifx_Oe_Fifo_readCount(dPipe->tx);

        length = length > 200 ? 200 : length; /* FIXME Checksum error if payload length is not limited. Check root cause. Check IFX_OE_SYNCPROTOCOL_FRAME_PAYLOAD_MAX_LENGTH, IFX_OE_SYNCPROTOCOL_MESSAGE_PAYLOAD_MAX_LENGTH. Is error still present ?  */

        Ifx_Oe_SyncProtocol_Message* message = Ifx_Oe_SyncProtocol_setSendMessageBuffer(
            bbClient,
            IFX_OE_SYNCPROTOCOL_MESSAGE_ID_RAWBUFFER,
            length);

        if (message != NULL_PTR)
        {
            Ifx_Oe_Fifo_read(dPipe->tx, message->messagePayload, (Ifx_Oe_SizeT)length, Ifx_Oe_Time_0s);
            Ifx_Oe_SyncProtocol_sendMessage(message);
        }
    }
}


void Ifx_Oe_ShellBb_processMessages(Ifx_Oe_ShellBb* bb)
{
    Ifx_Oe_ShellBb_processMessagesPrivate(&bb->_bbClient, &bb->_dPipe);
}
