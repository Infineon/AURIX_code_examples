/**
 * \file IfxSmu_PinMap.h
 * \brief SMU I/O map
 * \ingroup IfxLld_Smu
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Smu_pinmap SMU Pin Mapping
 * \ingroup IfxLld_Smu
 */

#ifndef IFXSMU_PINMAP_H
#define IFXSMU_PINMAP_H

#include <IfxSmu_reg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Smu_pinmap
 * \{ */

/** \brief Fault Signal Protocol Pin */
typedef const struct
{
    Ifx_SMU*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxSmu_Fsp_Out;

IFX_EXTERN IfxSmu_Fsp_Out IfxSmu_FSP_P33_8_OUT;  /**< \brief SMU_FSP: SMU */

/** \brief Table dimensions */
#define IFXSMU_PINMAP_NUM_MODULES 1
#define IFXSMU_PINMAP_FSP_OUT_NUM_ITEMS 1


/** \brief IfxSmu_Fsp_Out table */
IFX_EXTERN const IfxSmu_Fsp_Out *IfxSmu_Fsp_Out_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_FSP_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXSMU_PINMAP_H */
