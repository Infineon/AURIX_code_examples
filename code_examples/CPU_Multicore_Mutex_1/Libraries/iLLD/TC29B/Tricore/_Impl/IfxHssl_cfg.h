/**
 * \file IfxHssl_cfg.h
 * \brief HSSL on-chip implementation data
 * \ingroup IfxLld_Hssl
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Hssl HSSL
 * \ingroup IfxLld
 * \defgroup IfxLld_Hssl_Impl Implementation
 * \ingroup IfxLld_Hssl
 * \defgroup IfxLld_Hssl_Std Standard Driver
 * \ingroup IfxLld_Hssl
 * \defgroup IfxLld_Hssl_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Hssl_Impl
 */

#ifndef IFXHSSL_CFG_H
#define IFXHSSL_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxHssl_reg.h"
#include "IfxHsct_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXHSSL_NUM_CHANNELS    4

#define IFXHSSL_NUM_MODULES     1

#define IFXHSSL_JTAG_ID_ADDRESS (0xF0000464u)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Hssl_Impl_Enumerations
 * \{ */
/** \brief List of the available Hsct resources
 */
typedef enum
{
    IfxHssl_hsctIndex_none = -1,  /**< \brief Not Selected */
    IfxHssl_hsctIndex_0    = 0,   /**< \brief HSCT index 0  */
} IfxHssl_hsctIndex;

/** \brief List of the available Hssl resources
 */
typedef enum
{
    IfxHssl_hsslIndex_none = -1,  /**< \brief Not Selected */
    IfxHssl_hsslIndex_0    = 0,   /**< \brief HSSL index 0  */
} IfxHssl_hsslIndex;

/** \} */

/** \addtogroup IfxLld_Hssl_Impl_Enumerations
 * \{ */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxHssl_cfg_hsctIndexMap[IFXHSSL_NUM_MODULES];

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxHssl_cfg_hsslIndexMap[IFXHSSL_NUM_MODULES];

/** \} */

#endif /* IFXHSSL_CFG_H */
