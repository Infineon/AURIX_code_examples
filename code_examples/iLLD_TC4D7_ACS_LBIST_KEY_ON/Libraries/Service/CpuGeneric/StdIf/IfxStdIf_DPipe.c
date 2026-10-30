/**
 * \file IfxStdIf_DPipe.c
 * \brief Standard interface: Data Pipe
 * \ingroup IfxStdIf
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
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
 */

#include "IfxStdIf_DPipe.h"
#include "_Utilities/Ifx_Assert.h"

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

void IfxStdIf_DPipe_print(IfxStdIf_DPipe *stdif, pchar format, ...)
{
    if (!stdif->txDisabled)
    {
        char      message[STDIF_DPIPE_MAX_PRINT_SIZE + 1];
        Ifx_SizeT count;
        va_list   args;
        va_start(args, format);
        vsprintf((char *)message, format, args);
        va_end(args);
        count = (Ifx_SizeT)strlen(message);
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, count < STDIF_DPIPE_MAX_PRINT_SIZE);
        //return
        IfxStdIf_DPipe_write(stdif, (void *)message, &count, TIME_INFINITE);
    }
    else
    {
        //return TRUE;
    }
}

boolean IfxStdIf_DPipe_ascInit(IfxStdIf_DPipe *stdif, IfxAsclin_Asc *asclin)
{
    /* Ensure the stdif is reset to zeros */
    memset(stdif, 0, sizeof(IfxStdIf_DPipe));

    /* Set the API link */
    stdif->driver         = asclin;
    stdif->write          = (IfxStdIf_DPipe_Write) & IfxAsclin_Asc_write;
    stdif->read           = (IfxStdIf_DPipe_Read) & IfxAsclin_Asc_read;
    stdif->getReadCount   = (IfxStdIf_DPipe_GetReadCount) & IfxAsclin_Asc_getReadCount;
    stdif->getReadEvent   = (IfxStdIf_DPipe_GetReadEvent) & IfxAsclin_Asc_getReadEvent;
    stdif->getWriteCount  = (IfxStdIf_DPipe_GetWriteCount) & IfxAsclin_Asc_getWriteCount;
    stdif->getWriteEvent  = (IfxStdIf_DPipe_GetWriteEvent) & IfxAsclin_Asc_getWriteEvent;
    stdif->canReadCount   = (IfxStdIf_DPipe_CanReadCount) & IfxAsclin_Asc_canReadCount;
    stdif->canWriteCount  = (IfxStdIf_DPipe_CanWriteCount) & IfxAsclin_Asc_canWriteCount;
    stdif->flushTx        = (IfxStdIf_DPipe_FlushTx) & IfxAsclin_Asc_flushTx;
    stdif->clearTx        = (IfxStdIf_DPipe_ClearTx) & IfxAsclin_Asc_clearTx;
    stdif->clearRx        = (IfxStdIf_DPipe_ClearRx) & IfxAsclin_Asc_clearRx;
    stdif->onReceive      = (IfxStdIf_DPipe_OnReceive) & IfxAsclin_Asc_isrReceive;
    stdif->onTransmit     = (IfxStdIf_DPipe_OnTransmit) & IfxAsclin_Asc_isrTransmit;
    stdif->onError        = (IfxStdIf_DPipe_OnError) & IfxAsclin_Asc_isrError;
    stdif->getIsrCount    = (IfxStdIf_DPipe_GetIsrCount) & IfxAsclin_Asc_getIsrCount;
    stdif->getSendCount   = (IfxStdIf_DPipe_GetSendCount) & IfxAsclin_Asc_getSendCount;
    stdif->getTxTimeStamp = (IfxStdIf_DPipe_GetTxTimeStamp) & IfxAsclin_Asc_getTxTimeStamp;
    stdif->resetIsrCount  = (IfxStdIf_DPipe_ResetIsrCount) & IfxAsclin_Asc_resetIsrCount;
    stdif->resetSendCount = (IfxStdIf_DPipe_ResetSendCount) & IfxAsclin_Asc_resetSendCount;
    stdif->txDisabled     = FALSE;
    return TRUE;
}

