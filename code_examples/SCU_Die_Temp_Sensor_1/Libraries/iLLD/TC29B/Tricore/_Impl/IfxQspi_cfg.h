/**
 * \file IfxQspi_cfg.h
 * \brief QSPI on-chip implementation data
 * \ingroup IfxLld_Qspi
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Qspi QSPI
 * \ingroup IfxLld
 * \defgroup IfxLld_Qspi_Impl Implementation
 * \ingroup IfxLld_Qspi
 * \defgroup IfxLld_Qspi_Std Standard Driver
 * \ingroup IfxLld_Qspi
 * \defgroup IfxLld_Qspi_Impl_Enumerations Enumerations
 * \ingroup IfxLld_Qspi_Impl
 */

#ifndef IFXQSPI_CFG_H
#define IFXQSPI_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxQspi_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXQSPI_HWFIFO_DEPTH (4)

#define IFXQSPI_NUM_MODULES  (6)

#define IFXQSPI_NUM_CHANNELS (16)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available QSPI resources
 */
typedef enum
{
    IfxQspi_Index_none = -1,  /**< \brief Not Selected */
    IfxQspi_Index_0    = 0,   /**< \brief QSPI index 0  */
    IfxQspi_Index_1,          /**< \brief QSPI index 1  */
    IfxQspi_Index_2,          /**< \brief QSPI index 2  */
    IfxQspi_Index_3,          /**< \brief QSPI index 3  */
    IfxQspi_Index_4,          /**< \brief QSPI index 4  */
    IfxQspi_Index_5           /**< \brief QSPI index 5  */
} IfxQspi_Index;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxQspi_cfg_indexMap[IFXQSPI_NUM_MODULES];

#endif /* IFXQSPI_CFG_H */
