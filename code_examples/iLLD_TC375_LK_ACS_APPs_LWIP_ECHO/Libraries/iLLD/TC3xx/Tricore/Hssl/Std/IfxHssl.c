/**
 * \file IfxHssl.c
 * \brief HSSL  basic functionality
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
#include "IfxHssl.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxHssl_disableHsctModule(Ifx_HSCT *hsct)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clears the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Disables the Hsct module */
    hsct->CLC.B.DISR = 1;
    /* Sets the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxHssl_disableHsslModule(Ifx_HSSL *hssl)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clears the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Disables the Hssl module */
    hssl->CLC.B.DISR = 1;
    /* Sets the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxHssl_enableHsctModule(Ifx_HSCT *hsct)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clears the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Enables the Hsct module */
    hsct->CLC.B.DISR = 0;
    /* Sets the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxHssl_enableHsslModule(Ifx_HSSL *hssl)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* clears the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Enables the Hssl module */
    hssl->CLC.B.DISR = 0;
    /* Sets the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


Ifx_HSCT *IfxHssl_getHsctAddress(IfxHssl_hsctIndex hsct)
{
    Ifx_HSCT *module;

    if (hsct < IFXHSSL_NUM_MODULES)
    {
        module = (Ifx_HSCT *)IfxHssl_cfg_hsctIndexMap[hsct].module;
    }
    else
    {
        module = NULL_PTR;
    }

    return module;
}


IfxHssl_hsctIndex IfxHssl_getHsctIndex(Ifx_HSCT *hsct)
{
    uint32            index;
    IfxHssl_hsctIndex result;

    result = IfxHssl_hsctIndex_none;

    for (index = 0; index < IFXHSSL_NUM_MODULES; index++)
    {
        if (IfxHssl_cfg_hsctIndexMap[index].module == hsct)
        {
            result = (IfxHssl_hsctIndex)IfxHssl_cfg_hsctIndexMap[index].index;
            break;
        }
    }

    return result;
}


volatile Ifx_SRC_SRCR *IfxHssl_getHsctSrcPointer(Ifx_HSCT *hsct)
{
#if IFXHSSL_NUM_MODULES > 1
    if (hsct == &MODULE_HSCT0)
    {
        return &MODULE_SRC.HSCT.HSCT[0].SR;
    }
    else
    {
        return &MODULE_SRC.HSCT.HSCT[1].SR;
    }
#else
    IFX_UNUSED_PARAMETER(hsct);

	return &MODULE_SRC.HSCT.HSCT[0].SR;
#endif
}


Ifx_HSSL *IfxHssl_getHsslAddress(IfxHssl_hsslIndex hssl)
{
    Ifx_HSSL *module;

    if (hssl < IFXHSSL_NUM_MODULES)
    {
        module = (Ifx_HSSL *)IfxHssl_cfg_hsslIndexMap[hssl].module;
    }
    else
    {
        module = NULL_PTR;
    }

    return module;
}


volatile Ifx_SRC_SRCR *IfxHssl_getHsslCOKSrcPointer(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId)
{
#if IFXHSSL_NUM_MODULES > 1
    if (hssl == &MODULE_HSSL0)
    {
        return &MODULE_SRC.HSSL.HSSL[0].CH[(uint32)channelId].COK;
    }
    else
    {
        return &MODULE_SRC.HSSL.HSSL[1].CH[(uint32)channelId].COK;
    }
#else
    IFX_UNUSED_PARAMETER(hssl);

	return &MODULE_SRC.HSSL.HSSL[0].CH[(uint32)channelId].COK;
#endif

}


volatile Ifx_SRC_SRCR *IfxHssl_getHsslERRSrcPointer(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId)
{
#if IFXHSSL_NUM_MODULES > 1
    if (hssl == &MODULE_HSSL0)
    {
        return &MODULE_SRC.HSSL.HSSL[0].CH[(uint32)channelId].ERR;
    }
    else
    {
        return &MODULE_SRC.HSSL.HSSL[1].CH[(uint32)channelId].ERR;
    }
#else
    IFX_UNUSED_PARAMETER(hssl);

	return &MODULE_SRC.HSSL.HSSL[0].CH[(uint32)channelId].ERR;
#endif
}


volatile Ifx_SRC_SRCR *IfxHssl_getHsslEXISrcPointer(Ifx_HSSL *hssl)
{
#if IFXHSSL_NUM_MODULES > 1
    if (hssl == &MODULE_HSSL0)
    {
        return &MODULE_SRC.HSSL.HSSL[0].EXI;
    }
    else
    {
        return &MODULE_SRC.HSSL.HSSL[1].EXI;
    }
#else
    IFX_UNUSED_PARAMETER(hssl);

	return &MODULE_SRC.HSSL.HSSL[0].EXI;
#endif
}


IfxHssl_hsslIndex IfxHssl_getHsslIndex(Ifx_HSSL *hssl)
{
    uint32            index;
    IfxHssl_hsslIndex result;

    result = IfxHssl_hsslIndex_none;

    for (index = 0; index < IFXHSSL_NUM_MODULES; index++)
    {
        if (IfxHssl_cfg_hsslIndexMap[index].module == hssl)
        {
            result = (IfxHssl_hsslIndex)IfxHssl_cfg_hsslIndexMap[index].index;
            break;
        }
    }

    return result;
}


volatile Ifx_SRC_SRCR *IfxHssl_getHsslRDISrcPointer(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId)
{
#if IFXHSSL_NUM_MODULES > 1
    if (hssl == &MODULE_HSSL0)
    {
        return &MODULE_SRC.HSSL.HSSL[0].CH[(uint32)channelId].RDI;
    }
    else
    {
        return &MODULE_SRC.HSSL.HSSL[1].CH[(uint32)channelId].RDI;
    }
#else
        IFX_UNUSED_PARAMETER(hssl);

		return &MODULE_SRC.HSSL.HSSL[0].CH[(uint32)channelId].RDI;
#endif
}


volatile Ifx_SRC_SRCR *IfxHssl_getHsslTRGSrcPointer(Ifx_HSSL *hssl, IfxHssl_ChannelId channelId)
{
#if IFXHSSL_NUM_MODULES > 1
    if (hssl == &MODULE_HSSL0)
    {
        return &MODULE_SRC.HSSL.HSSL[0].CH[(uint32)channelId].TRG;
    }
    else
    {
        return &MODULE_SRC.HSSL.HSSL[1].CH[(uint32)channelId].TRG;
    }
#else
        IFX_UNUSED_PARAMETER(hssl);

		return &MODULE_SRC.HSSL.HSSL[0].CH[(uint32)channelId].TRG;
#endif
}


void IfxHssl_resetHsctKernel(Ifx_HSCT *hsct)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    /* Only if both Kernel reset bits are set a reset is executed */
    hsct->KRST0.B.RST = 1;
    hsct->KRST1.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    /* Wait until reset is executed */
    while (0 == hsct->KRST0.B.RSTSTAT)
    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    /* Clear Kernel reset status bit */
    hsct->KRSTCLR.B.CLR = 1;
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxHssl_resetHsslKernel(Ifx_HSSL *hssl)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    /* Only if both Kernel reset bits are set a reset is executed */
    hssl->KRST0.B.RST = 1;
    hssl->KRST1.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    /* Wait until reset is executed */
    while (0 == hssl->KRST0.B.RSTSTAT)
    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    /* Clear Kernel reset status bit */
    hssl->KRSTCLR.B.CLR = 1;
    IfxScuWdt_setCpuEndinit(passwd);
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
