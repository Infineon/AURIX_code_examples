 /**********************************************************************************************************************
 * \file Power_Supply.h
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

#ifndef POWER_SUPPLY_H_
#define POWER_SUPPLY_H_

#define POWER_GOOD_SIGNALS
#define POWER_ANA_MEASURE

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Cpu/Std/Ifx_Types.h>
#include "TLF3xx8x.h"

#ifdef POWER_ANA_MEASURE
#include "Analog_Measure.h"
#endif
#ifdef POWER_GOOD_SIGNALS
#include "Power_Good_Signals.h"
#endif

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct {
#ifdef POWER_ANA_MEASURE
        Board_Analog_Measure_t *Board_Analog_Measure;
#endif
#ifdef POWER_GOOD_SIGNALS
        Board_PG_Status_t *Board_PG_Status;
#endif

} Power_Supply_t;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
extern Power_Supply_t Board_Power_Supply;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/*
 *  Init's the power supply status measurment's
 */
sint32 Init_Power_Supply_Measurments (void);

/*
 *  measures updates the power supply status
 */
void Power_Supply_Measurments (void);

#endif /* COMPONENTS_POWER_SUPPLY_POWER_SUPPLY_H_ */
