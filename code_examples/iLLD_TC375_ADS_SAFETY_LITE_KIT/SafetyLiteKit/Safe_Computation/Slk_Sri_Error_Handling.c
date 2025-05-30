/**********************************************************************************************************************
 * \file    Slk_Sri_Error_Handling.c
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

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "SafetyLiteKit/Safe_Computation/Slk_Sri_Error_Handling.h"
#include "IfxPort.h"
#include "IfxMtu.h"
#include "IfxDom_reg.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
/* error flags*/
boolean errorOccurSRI = FALSE;                   /* Flag if the SRI error occurred */
triggerSriError g_trigerSriError;

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/*
 * enable SRI flag if the error is occurred
 * */
void enableErrorOccurranceSRI(void)
{
    errorOccurSRI = TRUE;
}

/*
 * SM:SRI:ERROR_HANDLING
 * This function inject DMA SRI ECC error and it is called periodically
 * */
void runDmaSriEccErrorInjection ()
{
    /* This error will generate ALM8[23]: Alarm: DMA SRI ECC Error */
    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());

    /* CPUx SRI Error Generation Register */
    __mtcr(CPU_SEGEN, 0x80000201);

    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    g_trigerSriError.EccErrorDma = FALSE;
}

/*
 * SM:SRI:ERROR_HANDLING
 * This function inject SRI error and it is called periodically
 * */
void runSriErrorInjection ()
{
    /* Set LED pin mode */
    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());

    /*******************************************************************************************
     * ALM11[3]Test by injecting an SRI write phase error and then writing to an XBAR register *
     ******************************************************************************************/
    __mtcr(CPU_SEGEN, 0x80000101);
    MODULE_DOM0.SCICTRL[15].PECON.B.SETPE = 1;

    /* Below are some more test to inject SRI error, user can enable one by one and then accordingly
     * look to the generated error and alarm */

    /*********************************************************************************
     * test by injecting an SRI write phase error and then writing to a LMU register *
     * User must ensure the availability of the below address i.e. 0xB0400000        *
     ********************************************************************************/
    /*        __mtcr(CPU_SEGEN, 0x80000101);
     uint32 *lmuData = (uint32 * ) 0xB0400000;
     lmuData[0] = 0xffff0000;
     */

    /**************************************************************************
     * Trying to access reserved memory                                       *
     * User must ensure the availability of the below address i.e. 0x401C3000 *
     *************************************************************************/
    /*        __mtcr(CPU_SEGEN, 0x80000001);
     uint32 *reservedMemory = (uint32 * ) 0x401C3000;
     reservedMemory[0] = 0xffff0000;
     */

    /****************************************************************************************
     * CPUx SRI Error Generation Register                                                   *
     * User must ensure the availability of the below address i.e. 0x70000000 or 0x60000000 *
     ***************************************************************************************/
    /*        __mtcr(CPU_SEGEN, 0x80000001);
     uint32 *cpu0dspr = (uint32 * ) 0x70000000;
     cpu0dspr[0] = 0xffff0000;
     */
    /*        __mtcr(CPU_SEGEN, 0x80000001);
     uint32 *cpu1dspr = (uint32 *)0x60000000;
     cpu1dspr[0]= 0xffff0000;
     */

    /**********************************************************************
     * ALM11[6]: Test by injecting an SRI Address phase error and then by *
     * accessing to a BBB register, code example to test it:              *
     *********************************************************************/
    /*        __mtcr (CPU_SEGEN, 0x80000001);
     MODULE_EBCU.CON.U = 0x0;
     */

    /*****************************************************************************
     * ALM11[4]:Test by injecting an SRI write phase error and then writing to a *
     * DMU register                                                              *
     ****************************************************************************/
    /*        __mtcr (CPU_SEGEN, 0x80000001);
     MODULE_DMU.HF_CONTROL.U = 0x0;
     */

    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    g_trigerSriError.SriError = FALSE;

    /*enable that SRI error has been occurred*/
    enableErrorOccurranceSRI();
}

/*
 * This function stores SRI diagnostic information once SRI error occurs
 * */
void storeSriDiagnosticInfo()
{
    static uint32 resultERRADDR[16], resultERR[16];

    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());

    if (MODULE_DOM0.PESTAT.U != 0x00000000 )
    {
        if (MODULE_DOM0.PESTAT.B.PESCI0 == TRUE)
        {
            resultERRADDR[0] = MODULE_DOM0.SCICTRL[0].ERRADDR.U;
            resultERR[0] = MODULE_DOM0.SCICTRL[0].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI1 == TRUE)
        {
            resultERRADDR[1] = MODULE_DOM0.SCICTRL[1].ERRADDR.U;
            resultERR[1] = MODULE_DOM0.SCICTRL[1].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI2 == TRUE)
        {
            resultERRADDR[2] = MODULE_DOM0.SCICTRL[2].ERRADDR.U;
            resultERR[2] = MODULE_DOM0.SCICTRL[2].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI3 == TRUE)
        {
            resultERRADDR[3] = MODULE_DOM0.SCICTRL[3].ERRADDR.U;
            resultERR[3] = MODULE_DOM0.SCICTRL[3].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI4 == TRUE)
        {
            resultERRADDR[4] = MODULE_DOM0.SCICTRL[4].ERRADDR.U;
            resultERR[4] = MODULE_DOM0.SCICTRL[4].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI5 == TRUE)
        {
            resultERRADDR[5] = MODULE_DOM0.SCICTRL[5].ERRADDR.U;
            resultERR[5] = MODULE_DOM0.SCICTRL[5].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI6 == TRUE)
        {
            resultERRADDR[6] = MODULE_DOM0.SCICTRL[6].ERRADDR.U;
            resultERR[6] = MODULE_DOM0.SCICTRL[6].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI7 == TRUE)
        {
            resultERRADDR[7] = MODULE_DOM0.SCICTRL[7].ERRADDR.U;
            resultERR[7] = MODULE_DOM0.SCICTRL[7].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI8 == TRUE)
        {
            resultERRADDR[8] = MODULE_DOM0.SCICTRL[8].ERRADDR.U;
            resultERR[8] = MODULE_DOM0.SCICTRL[8].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI9 == TRUE)
        {
            resultERRADDR[9] = MODULE_DOM0.SCICTRL[9].ERRADDR.U;
            resultERR[9] = MODULE_DOM0.SCICTRL[9].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI10 == TRUE)
        {
            resultERRADDR[10] = MODULE_DOM0.SCICTRL[10].ERRADDR.U;
            resultERR[10] = MODULE_DOM0.SCICTRL[10].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI11 == TRUE)
        {
            resultERRADDR[11] = MODULE_DOM0.SCICTRL[11].ERRADDR.U;
            resultERR[11] = MODULE_DOM0.SCICTRL[11].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI12 == TRUE)
        {
            resultERRADDR[12] = MODULE_DOM0.SCICTRL[12].ERRADDR.U;
            resultERR[12] = MODULE_DOM0.SCICTRL[12].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI13 == TRUE)
        {
            resultERRADDR[13] = MODULE_DOM0.SCICTRL[13].ERRADDR.U;
            resultERR[13] = MODULE_DOM0.SCICTRL[13].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI14 == TRUE)
        {
            resultERRADDR[14] = MODULE_DOM0.SCICTRL[14].ERRADDR.U;
            resultERR[14] = MODULE_DOM0.SCICTRL[14].ERR.U;
        }
        if (MODULE_DOM0.PESTAT.B.PESCI15 == TRUE)
        {
            resultERRADDR[15] = MODULE_DOM0.SCICTRL[15].ERRADDR.U;
            resultERR[15] = MODULE_DOM0.SCICTRL[15].ERR.U;
        }
    }
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
}
