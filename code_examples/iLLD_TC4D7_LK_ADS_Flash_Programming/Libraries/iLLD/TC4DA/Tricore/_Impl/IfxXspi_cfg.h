/**
 * \file IfxXspi_cfg.h
 * \brief XSPI on-chip implementation data
 * \ingroup IfxLld_Xspi
 *
 * \version iLLD-TC4-v2.1.1
 * \copyright Copyright (c) 2024 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Xspi Xspi
 * \ingroup IfxLld
 * \defgroup IfxLld_Xspi_Impl Implementation
 * \ingroup IfxLld_Xspi
 * \defgroup IfxLld_Xspi_Std Standard Driver
 * \ingroup IfxLld_Xspi
 * \defgroup IfxLld_Xspi_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Xspi_Impl
 */

#ifndef IFXXSPI_CFG_H
#define IFXXSPI_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxXspi_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXXSPI_NUM_MODULES       (1)

#ifndef IFXXSPI_WRITE_CMD_VALUE
#define IFXXSPI_WRITE_CMD_VALUE   (0x20000000)
#endif

#ifndef IFXXSPI_WRITE_CMD_MASK
#define IFXXSPI_WRITE_CMD_MASK    (0xFFFFFFF8)
#endif

#ifndef IFXXSPI_WRITE_ADDR_VALUE
#define IFXXSPI_WRITE_ADDR_VALUE  (0x0000)
#endif

#ifndef IFXXSPI_WRITE_ADDR_MASK
#define IFXXSPI_WRITE_ADDR_MASK   (0x00000007)
#endif

#ifndef IFXXSPI_WRITE_SHIFT
#define IFXXSPI_WRITE_SHIFT       (3)
#endif

#ifndef IFXXSPI_READ_CMD_VALUE
#define IFXXSPI_READ_CMD_VALUE    (0xA0000000)
#endif

#ifndef IFXXSPI_READ_CMD_MASK
#define IFXXSPI_READ_CMD_MASK     (0xFFFFFFF8)
#endif

#ifndef IFXXSPI_READ_ADDR_VALUE
#define IFXXSPI_READ_ADDR_VALUE   (0x0000)
#endif

#ifndef IFXXSPI_READ_ADDR_MASK
#define IFXXSPI_READ_ADDR_MASK    (0x00000007)
#endif

#ifndef IFXXSPI_READ_SHIFT
#define IFXXSPI_READ_SHIFT        (3)
#endif

#ifndef IFXXSPI_INTERRUPT_CFG
#define IFXXSPI_INTERRUPT_CFG     (1)
#endif
#define IFXXSPI_XIP_REGION0_LOWER (0x98000000)

#define IFXXSPI_XIP_REGION0_UPPER (0x9FFFFFFF)

#define IFXXSPI_XIP_REGION1_LOWER (0xB8000000)

#define IFXXSPI_XIP_REGION1_UPPER (0xBFFFFFFF)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Xspi_Impl_Enumerations
 * \{ */
/** \brief List of the available Xspi resources
 */
typedef enum
{
    IfxXspi_Index_none = -1,  /**< \brief Not Selected */
    IfxXspi_Index_0    = 0,   /**< \brief XSPI Index 0  */
} IfxXspi_Index;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxXspi_cfg_indexMap[IFXXSPI_NUM_MODULES];

#endif /* IFXXSPI_CFG_H */
