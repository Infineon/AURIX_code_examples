/**
 * \file ifx_oe_cfg.h
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
 *
 * This file shall contain the user configuration for the OneEye library.
 *
 * This file can be modified by the user.
 *
 */

#include "Ifx_Cfg.h"

//#define IFX_OE_AL_USE_AURIX_ILLD
//#define IFX_CFG_OE_DEFINE_TICKTIME
//#define IFX_CFG_OE_DEFAULT_TIMER (BSP_DEFAULT_TIMER)

#define IFX_CFG_OE_FIFODPIPE_TIMEOUT (Ifx_Oe_Time_getTickForMilliseconds(1000))

//#define IFX_CFG_OE_OSCI_MAX_NUM_OF_SIGNALS (20)
//#define IFX_CFG_OE_OSCI_MAX_NUM_OF_CHANNELS (10)
//#define IFX_CFG_OE_OSCI_NUM_OF_SAMPLES (512)
//#define IFX_CFG_OE_OSCI_SIGNAL_NAME_MAX_LENGTH (20)

//#define IFX_CFG_OE_SHELL_CMD_HISTORY_SIZE (10)     /**<\brief Number of commands to store in history */
//#define IFX_CFG_OE_SHELL_CMD_LINE_SIZE    (128)    /**<\brief max command line IFX_CFG_OE_SHELL_CMD_LINE_SIZE - 1 */
//#define IFX_CFG_OE_SHELL_COMMAND_LISTS    (1)      /**<\brief Number of command lists */
//#define IFX_CFG_OE_SHELL_PROMPT           "Shell>"    /**<\brief Shell prompt */
#define IFX_CFG_OE_SHELL_TIMEOUT (Ifx_Oe_Time_getTickForMilliseconds(1000))

//#define IFX_CFG_OE_XSHELL_CMD_LINE_SIZE (128)       /**<\brief max command line IFX_CFG_OE_XSHELL_CMD_LINE_SIZE - 1 */
