/**
 * \file IfxRifDphy.c
 * \brief RIF  basic functionality
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Infineon Technologies AG (Infineon) licenses this file to you under the
 * Infineon Automotive SW Lab License v2025-01 (IFASLL). You may not use
 * this file except in compliance with IFASLL.
 *
 * The full license text is contained in IFASLL202501.pdf delivered with this SW.
 * Unless required by applicable law or agreed to in writing, software distributed
 * under this license is distributed "AS IS" without any warranty or liability of any
 * kind and Infineon hereby expressly disclaims any warranties or representations,
 * whether express, implied, statutory or otherwise, including but not limited to
 * warranties of workmanship, merchantability, fitness for a particular purpose,
 * defects in the licensed items, or non-infringement of third parties'
 * intellectual property rights. See the full license text for the specific
 * language governing permissions and limitations under IFASLL.
 *
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if defined(DEVICE_TC45X)
#include "IfxRifDphy.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxRifDphy_isDataLaneInStopState(Ifx_RIF *rif, IfxRif_NumLanes numlanes)
{
    boolean status = FALSE;

    if (numlanes == IfxRif_NumLanes_1)
    {
        status = ((rif->PHY_STOPSTATE.U & 0x1u) == 0x1u) ? TRUE : FALSE;
    }
    else if (numlanes == IfxRif_NumLanes_2)
    {
        status = ((rif->PHY_STOPSTATE.U & 0x3u) == 0x3u) ? TRUE : FALSE;
    }
    else if (numlanes == IfxRif_NumLanes_3)
    {
        status = ((rif->PHY_STOPSTATE.U & 0x7u) == 0x7u) ? TRUE : FALSE;
    }
    else if (numlanes == IfxRif_NumLanes_4)
    {
        status = ((rif->PHY_STOPSTATE.U & 0xFu) == 0xFu) ? TRUE : FALSE;
    }
    else
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE);
    }

    return status;
}


void IfxRifDphy_setLaneWaitStopState(Ifx_RIF *rif, IfxRif_NumLanes numlanes)
{
    if (numlanes == IfxRif_NumLanes_1)
    {
        rif->DPHYCFG.B.FRCLN = 0x1u;
    }
    else if (numlanes == IfxRif_NumLanes_2)
    {
        rif->DPHYCFG.B.FRCLN = 0x3u;
    }
    else if (numlanes == IfxRif_NumLanes_3)
    {
        rif->DPHYCFG.B.FRCLN = 0x7u;
    }
    else
    {
        rif->DPHYCFG.B.FRCLN = 0xFu;
    }
}


void IfxRifDphy_enableLanes(Ifx_RIF *rif, IfxRif_NumLanes numlanes)
{
    if (numlanes == IfxRif_NumLanes_1)
    {
        rif->DPHYCFG.B.EN_LANE = 0x1u;
    }
    else if (numlanes == IfxRif_NumLanes_2)
    {
        rif->DPHYCFG.B.EN_LANE = 0x3u;
    }
    else if (numlanes == IfxRif_NumLanes_3)
    {
        rif->DPHYCFG.B.EN_LANE = 0x7u;
    }
    else
    {
        rif->DPHYCFG.B.EN_LANE = 0xfu;
    }
}


void IfxRifDphy_csi2EnableLanes(Ifx_RIF *rif, IfxRif_NumLanes numlanes)
{
    if (numlanes == IfxRif_NumLanes_1)
    {
        rif->N_LANES.B.N_LANES = 0x0u;
    }
    else if (numlanes == IfxRif_NumLanes_2)
    {
        rif->N_LANES.B.N_LANES = 0x1u;
    }
    else if (numlanes == IfxRif_NumLanes_3)
    {
        rif->N_LANES.B.N_LANES = 0x2u;
    }
    else
    {
        rif->N_LANES.B.N_LANES = 0x3u;
    }
}


void IfxRifDphy_configClockFrequency(Ifx_RIF *rif, float32 freqMhz)
{
    float32 value;
    uint32  roundofValue;
    value                   = (float32)((freqMhz - 17.0f) * 4.0f);

    roundofValue            = (value < 0.0f) ? (value - 0.5f) : (value + 0.5f);

    rif->DPHYCFG.B.CFGCLKFQ = (uint8)roundofValue;
}


uint8 IfxRifDphy_configOperatingHsFrequency(Ifx_RIF *rif, uint16 freqMbps)
{
    uint8 idx;
    uint8 idxPos = 0xFFu;

    for (idx = 0u; idx < IFXRIF_NUM_HS_FREQ_RANGE; idx++)
    {
        if (freqMbps == IfxRif_highFrequencyRangeTable[idx].defaultBitRate_Mbps)
        {
            idxPos               = idx;
            rif->DPHYCFG.B.HSFQR = IfxRif_highFrequencyRangeTable[idx].hsFreqRange;
        }
    }

    return idxPos;
}


void IfxRifDphy_configTestCodeAddress(Ifx_RIF *rif, uint16 address)
{
    /* Ensure that PHY_TEST_CTRL0.PHY_TESTCLK and PHY_TEST_CTRL1.PHY_TESTEN are low */
    if (rif->PHY_TEST_CTRL0.B.PHY_TESTCLK != 0u)
    {
        rif->PHY_TEST_CTRL0.B.PHY_TESTCLK = 0u;
    }

    if (rif->PHY_TEST_CTRL1.B.PHY_TESTEN != 0u)
    {
        rif->PHY_TEST_CTRL1.B.PHY_TESTEN = 0u;
    }

    /* Writing MSB 4 bit address test code */
    rif->PHY_TEST_CTRL1.B.PHY_TESTEN  = 1u;
    rif->PHY_TEST_CTRL0.B.PHY_TESTCLK = 1u;
    rif->PHY_TEST_CTRL1.B.PHY_TESTDIN = 0x00u;
    rif->PHY_TEST_CTRL0.B.PHY_TESTCLK = 0u;
    rif->PHY_TEST_CTRL1.B.PHY_TESTEN  = 0u;
    rif->PHY_TEST_CTRL1.B.PHY_TESTDIN = (uint8)((address >> 8u) & 0xFu);  /* MSB 4bits of 12bit address */
    rif->PHY_TEST_CTRL0.B.PHY_TESTCLK = 1u;

    /* Writing LSB 8-bit address test code */
    rif->PHY_TEST_CTRL0.B.PHY_TESTCLK = 0u;
    rif->PHY_TEST_CTRL1.B.PHY_TESTEN  = 1u;
    rif->PHY_TEST_CTRL0.B.PHY_TESTCLK = 1u;
    rif->PHY_TEST_CTRL1.B.PHY_TESTDIN = (uint8)(address & 0xFFu);    /* LSB 8bits of 12bit address */
    rif->PHY_TEST_CTRL0.B.PHY_TESTCLK = 0u;
}


void IfxRifDphy_writeTestCodeData(Ifx_RIF *rif, uint16 address, uint8 testCodeData)
{
    /*Need to check whether this address configuration is necessary every time before read/write */
    IfxRifDphy_configTestCodeAddress(rif, address);
    /* Writing testcode data */
    rif->PHY_TEST_CTRL1.B.PHY_TESTEN  = 0u;
    rif->PHY_TEST_CTRL1.B.PHY_TESTDIN = testCodeData;
    rif->PHY_TEST_CTRL0.B.PHY_TESTCLK = 1u;
    rif->PHY_TEST_CTRL0.B.PHY_TESTCLK = 0u;
}


uint8 IfxRifDphy_readTestCodeData(Ifx_RIF *rif, uint16 address)
{
    IfxRifDphy_configTestCodeAddress(rif, address);
    /* Reading testcodedata */
    uint8 testcodedata = rif->PHY_TEST_CTRL1.B.PHY_TESTDOUT;

    rif->PHY_TEST_CTRL1.B.PHY_TESTEN = 0u;
    return testcodedata;
}


void IfxRifDphy_csi2ConfigureDataId(Ifx_RIF *rif, IfxRif_Csi2DataTypeId *dataIds, IfxRif_Csi2VirtualChannelId *vcId)
{
    Ifx_RIF_DATA_IDS_1 dataIds1;
    dataIds1.U        = rif->DATA_IDS_1.U;

    dataIds1.B.DI0_DT = dataIds->dataTypeId_0;
    dataIds1.B.DI1_DT = dataIds->dataTypeId_1;
    dataIds1.B.DI2_DT = dataIds->dataTypeId_2;
    dataIds1.B.DI3_DT = dataIds->dataTypeId_3;

    rif->DATA_IDS_1.U = dataIds1.U;

    Ifx_RIF_DATA_IDS_2 dataIds2;
    dataIds2.U        = rif->DATA_IDS_2.U;

    dataIds2.B.DI4_DT = dataIds->dataTypeId_4;
    dataIds2.B.DI5_DT = dataIds->dataTypeId_5;
    dataIds2.B.DI6_DT = dataIds->dataTypeId_6;
    dataIds2.B.DI7_DT = dataIds->dataTypeId_7;

    rif->DATA_IDS_2.U = dataIds2.U;

    Ifx_RIF_DATA_IDS_VC_1 dataIdsVc1;
    dataIdsVc1.U             = rif->DATA_IDS_VC_1.U;

    dataIdsVc1.B.DI0_VC      = (uint8)vcId->vcDataId_0;
    dataIdsVc1.B.DI1_VC      = (uint8)vcId->vcDataId_1;
    dataIdsVc1.B.DI2_VC      = (uint8)vcId->vcDataId_2;
    dataIdsVc1.B.DI3_VC      = (uint8)vcId->vcDataId_3;

    dataIdsVc1.B.DI0_VCX_0_1 = (uint8)vcId->vcExtensionDataId_0;
    dataIdsVc1.B.DI1_VCX_0_1 = (uint8)vcId->vcExtensionDataId_1;
    dataIdsVc1.B.DI2_VCX_0_1 = (uint8)vcId->vcExtensionDataId_2;
    dataIdsVc1.B.DI3_VCX_0_1 = (uint8)vcId->vcExtensionDataId_3;

    rif->DATA_IDS_VC_1.U     = dataIdsVc1.U;

    Ifx_RIF_DATA_IDS_VC_2 dataIdsVc2;
    dataIdsVc2.U             = rif->DATA_IDS_VC_2.U;

    dataIdsVc2.B.DI4_VC      = (uint8)vcId->vcDataId_4;
    dataIdsVc2.B.DI5_VC      = (uint8)vcId->vcDataId_5;
    dataIdsVc2.B.DI6_VC      = (uint8)vcId->vcDataId_6;
    dataIdsVc2.B.DI7_VC      = (uint8)vcId->vcDataId_7;

    dataIdsVc2.B.DI4_VCX_0_1 = (uint8)vcId->vcExtensionDataId_4;
    dataIdsVc2.B.DI5_VCX_0_1 = (uint8)vcId->vcExtensionDataId_5;
    dataIdsVc2.B.DI6_VCX_0_1 = (uint8)vcId->vcExtensionDataId_6;
    dataIdsVc2.B.DI7_VCX_0_1 = (uint8)vcId->vcExtensionDataId_7;

    rif->DATA_IDS_VC_2.U     = dataIdsVc2.U;
}


void IfxRifDphy_ldoStartup(Ifx_RIF *rif)
{
    /*1. After powering up VDD and VDDP3RIF0 supply rails, at least 100us wait time is required before enabling the LDO.
     * 2. After initializing the boot firmware, a wait time of 10us is required. */

    rif->DPHY0LDO.B.LDOEN = 0x1u;
    /* Considering 2.5ns(400Mhz) resolution of STM */
    /* 110us wait */
#if defined(IFX_ILLD_PPU_USAGE)
    wait(44000);
#else
    IfxStm_wait(44000);
#endif
    /* Enable the LDO */
    rif->DPHY0LDO.B.LDOSDEN = 0x1u;

    /* To monitor the VDDPHRIF0 rail, PMS.VMONP_VDDPHRIF0RST.RESETOFF must be set to '0' to enable monitoring */
}


void IfxRifDphy_setLanePolarity(Ifx_RIF *rif, IfxRifDphy_lanePolarity pol, IfxRifDphy_laneSelect sel)
{
    uint8  lanePol     = 0;
    uint16 addrTable[] = {0x307, 0x507, 0x707, 0x907, 0xb07};
    uint16 addr        = addrTable[sel];
    lanePol = IfxRifDphy_readTestCodeData(rif, addr);
    IfxRifDphy_writeTestCodeData(rif, addr, (lanePol | pol));
}

#endif /* #if defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
