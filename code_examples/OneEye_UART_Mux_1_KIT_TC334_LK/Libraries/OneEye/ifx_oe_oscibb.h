/**
 * \file ifx_oe_oscibb.h
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
#ifndef IFX_OE_OSCIBB_H
#define IFX_OE_OSCIBB_H

#include "ifx_oe_syncprotocol.h"
#include "ifx_oe_osci.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef IFX_OE_OSCIBB_TX_BUFFER_LENGTH
#define IFX_OE_OSCIBB_TX_BUFFER_LENGTH (1)
#endif

typedef struct
{
    Ifx_Oe_SyncProtocol_Client _bbClient;
    Ifx_Oe_Osci_ChannelId _OsciChannelId;
    uint32 _osciChannelDataOffset;
    boolean _osciStateSend;
    Ifx_Oe_Osci_SignalId _osciSignalInfoSend;
    Ifx_Oe_Osci_ChannelId _osciChannelInfoSend;
    Ifx_Oe_Osci* _osci;
}Ifx_Oe_OsciBb;

boolean Ifx_Oe_OsciBb_init(Ifx_Oe_OsciBb* bb, Ifx_Oe_Osci* osci, Ifx_Oe_SyncProtocol* protocol, Ifx_Oe_SyncProtocol_Port localPort, Ifx_Oe_SyncProtocol_Port remotePort);
void    Ifx_Oe_OsciBb_processMessages(Ifx_Oe_OsciBb* bb);

#ifdef __cplusplus
}
#endif

#endif
