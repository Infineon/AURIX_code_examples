/**********************************************************************************************************************
 * \file Cpu0_Main.c
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
 /*\title EVADC module diagnostics functionality
 * \abstract EVADC module run-time diagnostics configuration
 * \description This example demonstrates run-time configuration of the TC3x EVADC module to perform internal diagnostics.
 * \name BMETAL_TC375_ADS_EVADC_Diagnostics
 * \version V1.0.0
 * \board AURIX TC375 lite Kit, KIT_A2G_TC375_LITE, TC37xTP_A-Step
 * \keywords ADC, AURIX, GTM, EVADC, Diagnostics
 * \documents See README.md
 * \lastUpdated 2023-09-09
 *********************************************************************************************************************/

#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "IfxSrc.h"
#include "IfxScu_reg.h"
#include "IfxPms_reg.h"

#include "GTM.h"
#include "EVADC.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define STATE_DIAGNOSTIC            0       /* Loop state to perform diagnostics */
#define STATE_ANALOG_INPUT          1       /* Loop state to perform analog input sampling */

/* UCB segment with EVADC Vddk records */
#define UCB_BASE_ADDRES             0xAF400000u
#define UCB_G0_OFFSET               0x0A20u
#define UCB_G0_VDDK_RECORD          (*(volatile uint32*)( UCB_BASE_ADDRES + UCB_G0_OFFSET ) )

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
/* Array to store queue conversion result */
volatile float32 g_resultVoltage[2];
/* Notification flag on the queue conversion completion */
volatile uint8 g_adc_event_flag;

/* Variable to hold recent VDDK conversion result */
volatile float32 g_f32resultVddk;
/* Variable to hold recent Converter Diagnostics conversion result */
volatile float32 g_f32resultCD;

IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
/* Functions to perform verification of diagnostics*/
boolean verify_EVADC_G0_Diagnostics( void );
boolean Verify_G0_CD( float32 );
boolean Verify_G0_VDDK( float32 );

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void core0_main(void)
{
    /* Main loop acquisition state variable */
    volatile uint8 acquisition_state = STATE_DIAGNOSTIC;

    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
    * Enable the watchdogs and service them periodically if it is required
    */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    
    /* Set up GPIO as output pins for debug purposes */
    IfxPort_setPinMode( &MODULE_P00, 1, IfxPort_Mode_outputPushPullGeneral );   /* Set up P00.1 for EVADC G0 result event */
    IfxPort_setPinMode( &MODULE_P00, 5, IfxPort_Mode_outputPushPullGeneral );   /* Set up P00.5 for ATOM0_CH4 PWM output display */

    /* initialize EVADC */
    enable_EVADC_G0();

    /* Initialize CPU0 interrupt with priority 0x01 */
    IfxSrc_init( &SRC_VADC_G0_SR0, IfxSrc_Tos_cpu0, 0x01 );
    IfxSrc_enable( &SRC_VADC_G0_SR0 );

    /* Initialize GTM trigger */
    enable_GTM_trigger();

    acquisition_state = STATE_DIAGNOSTIC;

    while( 1 )
    {
        /* Clear EVADC result global notification flag */
        g_adc_event_flag = 0;

        /* Configure and convert either diagnostics signals or analog channels*/
        switch( acquisition_state )
        {
            case STATE_DIAGNOSTIC:
            {
                /* Enable Diagnostics Functionality */
                init_EVADC_G0_Diagnostics();

                /* Wait for results notification flag from Service Request Handler */
                while( g_adc_event_flag != 2 )
                {;}

                /* Copy global result values */
                g_f32resultCD   = g_resultVoltage[0];
                g_f32resultVddk = g_resultVoltage[1];

                /* Verify obtained results against expected values */
                verify_EVADC_G0_Diagnostics();

                acquisition_state = STATE_ANALOG_INPUT;

                break;
            }
            case STATE_ANALOG_INPUT:
            {
                /* Disable Diagnostics Functionality and Enable Analog inputs */
                init_EVADC_G0_AnalogInput();

                /* Wait for results notification flag from Service Request Handler*/
                while( g_adc_event_flag != 2 )
                {;}

                acquisition_state = STATE_DIAGNOSTIC;

                break;
            }
            default:
                acquisition_state = STATE_DIAGNOSTIC;
            break;
        }
    }
}

/* This function implements verification of the Converter Diagnostics and VDDK:
 * - Read raw result from channel result register
 * - Convert raw result into voltage value
 * - Setup global result flag when results from both Channel 0 and Channel 1 are ready
 * - Toggle P00.1 pin
 */
boolean verify_EVADC_G0_Diagnostics(void)
{
    Verify_G0_CD( g_f32resultCD );
    Verify_G0_VDDK( g_f32resultVddk );

    return TRUE;
}

/* This function implements verification of the Converter Diagnostics:
 * - Compute expected Converter Diagnostics value and its min-max boundary based on the selected pull-up level (CD_PULLUP_LEVEL)
 * - Compare conversion result with the expected boundary
 */
boolean Verify_G0_CD(float32 f32_CD_result)
{
    /* Converter diagnostics voltage accuracy (dVCSD) is specified in device Datasheet as +-10% * (1.1 × 4.5) / 3.3  = +-15% */
    volatile float32 f_cd_nom = 0.0;  /* Nominal expected value of the Converter diagnostics voltage */
    volatile float32 f_cd_min = 0.0;  /* Upper limit for Converter diagnostics voltage accuracy + EVADC TUE */
    volatile float32 f_cd_max = 0.0;  /* Lower limit for Converter diagnostics voltage accuracy - EVADC TUE */

    switch( CD_PULLUP_LEVEL )
    {
        case 0:
        {
            /* VDDM level */
            f_cd_nom = ANALOG_FULL_SCALE;
            f_cd_min = f_cd_nom * 0.85;
            f_cd_max = f_cd_nom * 1.15;
            break;
        }
        case 1:
        {
            /* VSSM level */
            f_cd_min = 0;
            f_cd_max = 0.05;
            break;
        }
        case 2:
        {
            /* 1/2 VDDM level */
            f_cd_nom = ANALOG_FULL_SCALE * 1/2;
            f_cd_min = f_cd_nom * 0.85;
            f_cd_max = f_cd_nom * 1.15;
            break;
        }
        case 3:
        {
            /* 2/3 VDDM level */
            f_cd_nom = ANALOG_FULL_SCALE * 2/3;
            f_cd_min = f_cd_nom * 0.85;
            f_cd_max = f_cd_nom * 1.15;
            break;
        }
        default:
        {
            /* not allowed value */
            return FALSE;
            break;
        }
    }

    /* Check if the conversion result is within expected min/max boundary */
    if( ( f32_CD_result > f_cd_min  ) && ( f32_CD_result < f_cd_max  ) )
    {
        /* Converter Diagnostics test passed */
        return TRUE;
    }
    else
    {
        /* Converter Diagnostics test failed */
        return FALSE;
    }

    return TRUE;
}

/* This function implements verification of the VDDK supervision signal:
 * - Obtain current temperature using DTS PMS
 * - Read UCB FLASH Group0 record
 * - Compute current expected VDDK value and its min/max boundary
 * - Compare conversion result with the expected values
 */
boolean Verify_G0_VDDK(float32 f32_Vddk_result)
{
    /* Obtain current die temperature using DTS PMS */
    /* T (°C) = [RESULT / Gnom] - 273.1, where Gnom = 7.505 */
    volatile uint32 u_dts_val = PMS_DTSSTAT.B.RESULT;
    volatile float32 f_dts_temp = ( (float32)u_dts_val/(7.505)) - 273.15;

    /* Read UCB FLASH VDDK record */
    volatile uint32 u_vddk_ucb = (UCB_G0_VDDK_RECORD);
    /* Variable to hold base VDDK record - VDDKC */
    volatile uint32 u_vddkc = (u_vddk_ucb >> 0 ) & 0xFFFF;
    /* Variable to hold temperature compensation VDDK record - dVDDK */
    volatile uint32 u_dvddk = (u_vddk_ucb >> 0x10) & 0xFFFF;

    /* Compute nominal VDDK value based VDDKC, dVDDK and current temperature */
    /* VDDK(V) = VDDKC + (DVDDK × (Tj + 40)/1000) */
    volatile float32 f_vddk_nom = u_vddkc + ( u_dvddk * ( (float32)f_dts_temp + 40 ) / 1000 );

    /* Compute min-max boundary of the nominal VDDK */
    volatile float32 f_vddk_min = f_vddk_nom / 1000 * 0.97;
    volatile float32 f_vddk_max = f_vddk_nom / 1000 * 1.03;

    /* Check if the conversion result is within expected min/max boundary */
    if( ( f32_Vddk_result  > f_vddk_min  ) && ( f32_Vddk_result < f_vddk_max ) )
    {
        /* VDDK test passed */
        return TRUE;
    }
    else
    {
        /* VDDK test failed */
        return FALSE;
    }

    return TRUE;
}
