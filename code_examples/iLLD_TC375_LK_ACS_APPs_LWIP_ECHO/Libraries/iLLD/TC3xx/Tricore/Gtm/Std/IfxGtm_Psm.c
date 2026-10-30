/**
 * \file IfxGtm_Psm.c
 * \brief GTM  basic functionality
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif
#if !defined(DEVICE_TC33XED) && !defined(DEVICE_TC33X) && !defined (DEVICE_TC35X)
#include "IfxGtm_Psm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxGtm_Psm_Fifo_setChannelEndAddress(IfxGtm_Psm_Fifo fifo, IfxGtm_Psm_FifoChannel channel, uint32 address)
{
    Ifx_GTM_PSM_FIFO_CH *fifoCh        = IfxGtm_Psm_Fifo_getChannelPointer(fifo, channel);
    uint32               start_address = IfxGtm_Psm_Fifo_getChannelStartAddress(fifo, channel);

    if ((address > start_address) &&
        (address < IFXGTM_PSM_FIFORAMSIZE))
    {
        fifoCh->END_ADDR.B.ADDR = (uint32)address;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


void IfxGtm_Psm_Fifo_setChannelStartAddress(IfxGtm_Psm_Fifo fifo, IfxGtm_Psm_FifoChannel channel, uint32 address)
{
    Ifx_GTM_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(fifo, channel);

    if (address < (IFXGTM_PSM_FIFORAMSIZE - 1))  /* START address should be within 0 - 1022 */
    {
        fifoCh->START_ADDR.B.ADDR = (uint32)address;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


void IfxGtm_Psm_Fifo_setChannelSize(IfxGtm_Psm_Fifo fifo, IfxGtm_Psm_FifoChannel channel, uint32 size)
{
    Ifx_GTM_PSM_FIFO_CH *fifoCh        = IfxGtm_Psm_Fifo_getChannelPointer(fifo, channel);
    uint32               start_address = IfxGtm_Psm_Fifo_getChannelStartAddress(fifo, channel);

    if (size < ((IFXGTM_PSM_FIFORAMSIZE - start_address) + (uint32)1))
    {
        fifoCh->END_ADDR.B.ADDR = (uint32)(start_address + size - (uint32)1);
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


void IfxGtm_Psm_Fifo_setChannelUpperWatermark(IfxGtm_Psm_Fifo fifo, IfxGtm_Psm_FifoChannel channel, uint32 upperWm)
{
    Ifx_GTM_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(fifo, channel);
    uint32               size   = IfxGtm_Psm_Fifo_getChannelSize(fifo, channel);

    if (upperWm < (size))  /* should be within 0 - 1023 */
    {
        fifoCh->UPPER_WM.B.ADDR = (uint32)upperWm;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


void IfxGtm_Psm_Fifo_setChannelLowerWatermark(IfxGtm_Psm_Fifo fifo, IfxGtm_Psm_FifoChannel channel, uint32 lowerWm)
{
    Ifx_GTM_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(fifo, channel);
    uint32               size   = IfxGtm_Psm_Fifo_getChannelSize(fifo, channel);

    if (lowerWm < (size))  /* should be within 0 - 1023 */
    {
        fifoCh->LOWER_WM.B.ADDR = (uint32)lowerWm;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }
}


IfxGtm_Psm_FifoChannelStatus IfxGtm_Psm_Fifo_getChannelStatus(IfxGtm_Psm_Fifo fifo, IfxGtm_Psm_FifoChannel channel)
{
    Ifx_GTM_PSM_FIFO_CH         *fifoCh     = IfxGtm_Psm_Fifo_getChannelPointer(fifo, channel);
    IfxGtm_Psm_FifoChannelStatus status     = IfxGtm_Psm_FifoChannelStatus_normal;
    uint32                       status_reg = (uint32)fifoCh->STATUS.U;
    uint8                        index      = 0;

    /* Get the status of the fifo channel */
    while (index < (uint8)IfxGtm_Psm_FifoChannelStatus_normal)
    {
        if (((status_reg >> index) & (uint32)1) == (uint32)1)
        {
            status = (IfxGtm_Psm_FifoChannelStatus)index;
            break;
        }

        index++;
    }

    return status;
}


void IfxGtm_Psm_Fifo_enableChannelInterrupt(IfxGtm_Psm_Fifo fifo, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt)
{
	/* Enable the specified fifo channel interrupt */

    Ifx_GTM_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(fifo, channel);
    uint32              *irq_en = (uint32 *)&(fifoCh->IRQ.EN.U);

    *irq_en |= ((uint32)1 << (uint32)interrupt);
}


void IfxGtm_Psm_Fifo_disableChannelInterrupt(IfxGtm_Psm_Fifo fifo, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt)
{
	/* Disable the specified fifo channel interrupt */

    Ifx_GTM_PSM_FIFO_CH *fifoCh = IfxGtm_Psm_Fifo_getChannelPointer(fifo, channel);
    uint32              *irq_en = (uint32 *)&(fifoCh->IRQ.EN.U);

    *irq_en ^= ((uint32)1 << (uint32)interrupt);
}


void IfxGtm_Psm_Fifo_setChannelInterrupt(IfxGtm_Psm_Fifo fifo, IfxGtm_Psm_FifoChannel channel, IfxGtm_Psm_FifoChannelInterrupt interrupt)
{
	/* Force the specified fifo channel interrupt */

    Ifx_GTM_PSM_FIFO_CH *fifoCh    = IfxGtm_Psm_Fifo_getChannelPointer(fifo, channel);
    uint32              *irq_force = (uint32 *)&(fifoCh->IRQ.FORCINT.U);

    *irq_force |= ((uint32)1 << (uint32)interrupt);
}


void IfxGtm_Psm_F2a_enableStream(IfxGtm_Psm_F2a f2a, IfxGtm_Psm_F2aStream f2aStream)
{
	/* Enables the specified stream of the F2A */

    Ifx_GTM_PSM_F2A *f2aPtr     = IfxGtm_Psm_F2a_getPointer(f2a);
    uint32          *f2a_enable = (uint32 *)&(f2aPtr->ENABLE.U);
    uint32           value      = (uint32)IfxGtm_Psm_F2aStreamState_enabled << (uint32)(f2aStream * 2);
    uint32           mask       = (uint32)3 << (f2aStream * 2);

    /* Update the F2A stream activation register */
    __ldmst_c((volatile void *)f2a_enable, mask, value);
}


void IfxGtm_Psm_F2a_disableStream(IfxGtm_Psm_F2a f2a, IfxGtm_Psm_F2aStream f2aStream)
{
	/* Disables the specified stream of the F2A */

    Ifx_GTM_PSM_F2A *f2aPtr     = IfxGtm_Psm_F2a_getPointer(f2a);
    uint32          *f2a_enable = (uint32 *)&(f2aPtr->ENABLE.U);
    uint32           value      = (uint32)IfxGtm_Psm_F2aStreamState_disabled << (uint32)(f2aStream * 2);
    uint32           mask       = (uint32)3 << (f2aStream * 2);

    /* Update the F2A stream activation register */
    __ldmst_c((volatile void *)f2a_enable, mask, value);
}


IfxGtm_Psm_F2aStreamState IfxGtm_Psm_F2a_getStreamState(IfxGtm_Psm_F2a f2a, IfxGtm_Psm_F2aStream f2aStream)
{
	/* Retrieves the current state of the specified fifo stream */

    Ifx_GTM_PSM_F2A *f2aPtr     = IfxGtm_Psm_F2a_getPointer(f2a);
    uint32           f2a_enable = f2aPtr->ENABLE.U;

    f2a_enable &= ((uint32)3 << (f2aStream * 2));

    return (IfxGtm_Psm_F2aStreamState)(f2a_enable >> (f2aStream * 2));
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
