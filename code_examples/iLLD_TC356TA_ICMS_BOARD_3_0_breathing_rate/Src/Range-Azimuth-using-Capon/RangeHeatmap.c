/**********************************************************************************************************************
 * \file RangeHeatmap.c
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
#include <Range-Azimuth-using-Capon/RangeHeatmap.h>

#include "IfxSpu_init.h"
#include "IfxRadar_cfg.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include "dsplib.h"


#define pi  (3.14159265359)

double asm_nu_a;

cfloat32 ASM[RADAR_NUM_VRX_AZIMUTH][RADAR_NUM_DTHETA];      /* Azimuth Steering Matrix*/
float32 asm_theta[RADAR_NUM_DTHETA];    /* (from -90° to 90°)*/

/* intermediate results of capon power spectrum calculation*/
cfloat32 asm_aHv[RADAR_NUM_VRX_AZIMUTH-1];
cfloat32 asm_av[RADAR_NUM_VRX_AZIMUTH-1];
cfloat32 asm_aH[1][RADAR_NUM_VRX_AZIMUTH-1];
cfloat32 asm_a[RADAR_NUM_VRX_AZIMUTH-1][1];
cfloat32 asm_Rn1[RADAR_NUM_VRX_AZIMUTH-1][RADAR_NUM_VRX_AZIMUTH-1];
cfloat32 reg_matrix[RADAR_NUM_VRX_AZIMUTH-1][RADAR_NUM_VRX_AZIMUTH-1];
cfloat32 asm_Rn1a[RADAR_NUM_VRX_AZIMUTH-1][1];
cfloat32 asm_aHRn1[1][RADAR_NUM_VRX_AZIMUTH-1];
cfloat32 asm_aHRn1_reg[1][RADAR_NUM_VRX_AZIMUTH-1];
cfloat32 asm_aHRn1a[1][1];

/***************************************/

void ASM_Generator(void) /* Building the Azimuth Steering matrix - ASM*/
{
    float start = -90.0;
    float end = 90.0;

    /* Calculate the step size*/
    float step = (end - start) / (RADAR_NUM_DTHETA - 1);

    for (uint32 i = 0; i  <RADAR_NUM_DTHETA; i++)
    {
        asm_theta[i] = start + (i * step);
        /*consider positions of 4 virtual antenna in azimuth in BGT60*/
        float Rx_azimuth[RADAR_NUM_VRX_AZIMUTH] = {0, 0.5, 1, 1.5}; /* position of azimuth virtual  antennas combined from Tx1 and Tx2 to virtual array*/

        for (uint32 N=0 ; N < RADAR_NUM_VRX_AZIMUTH ; N++)    /* Number of virtual receive antenna*/
        {
            /**************************************************************************************\
            *                                                                                      *
            *    We have to calculate this vector a(theta) = [1, exp(i*nu), ..., exp(i*(N-1)*nu)]' *
            *             Using Euler's Formula : exp(ix) = cos(x) + i*sin(x)                      *
            *                                                                                      *
            \**************************************************************************************/
            /* assuming distance in units of wavelength between antenna elements and converting Angle from Degrees to Radian for calculation*/
            asm_nu_a = -2*pi*(Rx_azimuth[N]*sin(asm_theta[i]*(pi/180)));

            ASM[N][i].real = cos(asm_nu_a);
            ASM[N][i].imag = sin(asm_nu_a);
        }
    }
}

void Power_Spectrum(void) /* Generating PS and BW matrices with calculations performed with ASM*/
{
    Radar * rdr = &g_rdr;


    for (uint32 bin=RANGE_BIN_MIN ; bin < RANGE_BIN_MAX ; bin++) /* Looping over range bins*/
    {
        for (uint32 j=ANGLE_BIN_MIN; j<ANGLE_BIN_MAX ; j++) /* Looping over RADAR_NUM_DTHETA different angle direction*/
        {
            for (uint32 i=0 ; i < RADAR_NUM_VRX_AZIMUTH-1 ; i++)
            {
                asm_av[i] = ASM[i][j]; /* Filling this vector with theta_n column from ASM*/
                /* Calculating a(theta_n) Hermitian*/
                struct Ifx_mtxHrmComplexF32State state1 = {3, &asm_av[0], &asm_aHv[0], RADAR_NUM_VRX_AZIMUTH-1, 1};
                Ifx_mtxHrmComplexF32(&state1);
                asm_aH[0][i] = asm_aHv[i];
                asm_a[i][0] = asm_av[i];
                for(uint32 k=0 ; k < RADAR_NUM_VRX_AZIMUTH-1 ; k++)
                {
                    asm_Rn1[i][k] = rdr->rmem->Rnn[bin][i][k];
                }
            }

            /* Calculating a^H * Rn^(-1)*/
            struct Ifx_mtxMulComplexF32State statep = {3, &asm_aHRn1[0][0], &asm_aH[0][0], &asm_Rn1[0][0], 1, RADAR_NUM_VRX_AZIMUTH-1, RADAR_NUM_VRX_AZIMUTH-1};
            Ifx_mtxMulComplexF32(&statep);

            /* Calculating a^H * Rn^(-1)*reg_matrix (machine precision reg term)*/
            struct Ifx_mtxMulComplexF32State statep1 = {3, &asm_aHRn1_reg[0][0], &asm_aHRn1[0][0], &reg_matrix[0][0], 1, RADAR_NUM_VRX_AZIMUTH-1, RADAR_NUM_VRX_AZIMUTH-1};
            Ifx_mtxMulComplexF32(&statep1);

            /* Calculating a^H * Rn^(-1) * a*/
            struct Ifx_mtxMulComplexF32State statep2 = {3, &asm_aHRn1a[0][0], &asm_aHRn1[0][0], &asm_a[0][0], 1, 1, RADAR_NUM_VRX_AZIMUTH-1};
            Ifx_mtxMulComplexF32(&statep2);

            /***********************************************************************\
            *                            Power Spectrum                             *
            *                   Calculating 1 / (a^H * Rn^(-1) * a)                 *
            \***********************************************************************/
            rdr->rmem->asm_aHRn1a[bin][j] = asm_aHRn1a[0][0].real;
            rdr->rmem->PS[bin][j] = (uint32)(1 / asm_aHRn1a[0][0].real); /*(a^H * Rn^(-1) * a) is real, imaginary components due to inaccuracies*/
        }
    }
}


void Beamforming(void) /* Generating PS and BW matrices with calculations performed with ASM*/
{
    cfloat32 steeringvector[RADAR_NUM_VRX_AZIMUTH];
    uint8 index_vRx_azimuth[RADAR_NUM_VRX_AZIMUTH] = {2, 4, 5, 7}; /* index of azimuth virtual  antennas combined from Tx1 and Tx2 to virtual array*/
    Radar *rdr = &g_rdr;

    /*loop over targets found*/
    for (int indTarget = 0; indTarget < rdr->det_targets.count; indTarget++)


    {
        /*steering vector for target angle index*/
       for (int indvrx= 0; indvrx<RADAR_NUM_VRX_AZIMUTH;indvrx++ )
       {
           steeringvector[3-indvrx]=ASM[indvrx][rdr->det_targets.targets[indTarget].coord.anglebin];
       }

       /*micro doppler data for selected range bin and virtual antenna*/
       for (int indframe = 0; indframe <RADAR_NUM_MICRO_DOPPLER;indframe++)
       {
           for (uint32 j = 0; j < RADAR_NUM_VRX_AZIMUTH; j++)
                   {   volatile uint8 indexvirtantenna = index_vRx_azimuth[j];
                       rdr->rmem->microDopplertargets[indTarget][j][indframe].real = (float32)rdr->rmem->microDopplerclutterremoved[indframe][indexvirtantenna][rdr->det_targets.targets[indTarget].coord.rangebin].real;
                       rdr->rmem->microDopplertargets[indTarget][j][indframe].imag = (float32)rdr->rmem->microDopplerclutterremoved[indframe][indexvirtantenna][rdr->det_targets.targets[indTarget].coord.rangebin].imag;
                   }
       }

       /* Calculating steering vector (subset of ASM)*micro doppler*/
        struct Ifx_mtxMulComplexF32State state6 = {3, &rdr->rmem->microDopplerbeamformed[indTarget][0], &steeringvector[0], &rdr->rmem->microDopplertargets[indTarget][0][0], 1, RADAR_NUM_MICRO_DOPPLER, RADAR_NUM_VRX_AZIMUTH};
        Ifx_mtxMulComplexF32(&state6);


    }

}
