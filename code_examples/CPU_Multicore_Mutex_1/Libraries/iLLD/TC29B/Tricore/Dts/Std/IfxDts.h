/**
 * \file IfxDts.h
 * \brief DTS  basic functionality
 * \ingroup IfxLld_Dts
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
 * \defgroup IfxLld_Dts_Std_Control Control functions
 * \ingroup IfxLld_Dts_Std
 * \defgroup IfxLld_Dts_Std_Status Status functions
 * \ingroup IfxLld_Dts_Std
 */

#ifndef IFXDTS_H
#define IFXDTS_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxDts_cfg.h"
#include "IfxScu_reg.h"
#include "IfxScu_bf.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Src/Std/IfxSrc.h"
/** \addtogroup IfxLld_Dts_Std_Control
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disable the writing of register bits except START bit.
 * \return None
 */
IFX_INLINE void IfxDts_disableSensorControl(void);

/** \brief Enables the DTS sensor
 * \return None
 */
IFX_INLINE void IfxDts_enableSensor(void);

/** \brief Starts the next temperature measurement.
 * \return None
 */
IFX_INLINE void IfxDts_startSensor(void);

/** \} */

/** \addtogroup IfxLld_Dts_Std_Status
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Gets the Interrupt request source.
 * \return Address of interrupt request source
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxDts_getSrcPointer(void);

/** \brief Read the temperature measurement result
 * \return Temperature measurement result
 */
IFX_INLINE uint16 IfxDts_getTemperatureValue(void);

/** \brief Returns the current BUSY status of the Sensor
 * \return TRUE if Sensor is busy in measuring temperature otherwise FALSE
 */
IFX_INLINE boolean IfxDts_isBusy(void);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the current READY status of the Sensor.
 * \return TRUE if Sensor is ready for measuring temperature otherwise FALSE
 */
IFX_EXTERN boolean IfxDts_isReady(void);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxDts_disableSensorControl(void)
{
    MODULE_SCU.DTSCON.B.SLCK = 1;
    MODULE_SCU.DTSLIM.B.SLCK = 1;
}


IFX_INLINE void IfxDts_enableSensor(void)
{
    MODULE_SCU.DTSCON.B.PWD = 0;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxDts_getSrcPointer(void)
{
    return &SRC_SCUDTS;
}


IFX_INLINE uint16 IfxDts_getTemperatureValue(void)
{
    return (uint16)MODULE_SCU.DTSSTAT.B.RESULT;
}


IFX_INLINE boolean IfxDts_isBusy(void)
{
    return MODULE_SCU.DTSSTAT.B.BUSY == 1 ? TRUE : FALSE;
}


IFX_INLINE void IfxDts_startSensor(void)
{
    MODULE_SCU.DTSCON.B.START = 1;
}


#endif /* IFXDTS_H */
