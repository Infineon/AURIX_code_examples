/**
 * \file IfxEth_Phy_Pef7071.c
 * \brief ETH PHY_PEF7071 details
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxEth_Phy_Pef7071.h"

/******************************************************************************/
/*----------------------------------Macros------------------------------------*/
/******************************************************************************/

#define IFXETH_PHY_PEF7071_MDIO_CTRL     0x00

#define IFXETH_PHY_PEF7071_MDIO_STAT     0x01

#define IFXETH_PHY_PEF7071_MDIO_PHYID1   0x02

#define IFXETH_PHY_PEF7071_MDIO_PHYID2   0x03

#define IFXETH_PHY_PEF7071_MDIO_AN_ADV   0x04

#define IFXETH_PHY_PEF7071_MDIO_AN_LPA   0x05

#define IFXETH_PHY_PEF7071_MDIO_AN_EXP   0x06

#define IFXETH_PHY_PEF7071_MDIO_AN_NPTX  0x07

#define IFXETH_PHY_PEF7071_MDIO_AN_NPRX  0x08

#define IFXETH_PHY_PEF7071_MDIO_GCTRL    0x09

#define IFXETH_PHY_PEF7071_MDIO_GSTAT    0x0A

#define IFXETH_PHY_PEF7071_MDIO_RES11    0x0B

#define IFXETH_PHY_PEF7071_MDIO_RES12    0x0C

#define IFXETH_PHY_PEF7071_MDIO_MMDCTRL  0x0D

#define IFXETH_PHY_PEF7071_MDIO_MMDDATA  0x0E

#define IFXETH_PHY_PEF7071_MDIO_XSTAT    0x0F

#define IFXETH_PHY_PEF7071_MDIO_PHYPERF  0x10

#define IFXETH_PHY_PEF7071_MDIO_PHYSTAT1 0x11

#define IFXETH_PHY_PEF7071_MDIO_PHYSTAT2 0x12

#define IFXETH_PHY_PEF7071_MDIO_PHYCTL1  0x13

#define IFXETH_PHY_PEF7071_MDIO_PHYCTL2  0x14

#define IFXETH_PHY_PEF7071_MDIO_ERRCNT   0x15

#define IFXETH_PHY_PEF7071_MDIO_EECTRL   0x16

#define IFXETH_PHY_PEF7071_MDIO_MIICTRL  0x17

#define IFXETH_PHY_PEF7071_MDIO_MIISTAT  0x18

#define IFXETH_PHY_PEF7071_MDIO_IMASK    0x19

#define IFXETH_PHY_PEF7071_MDIO_ISTAT    0x1A

#define IFXETH_PHY_PEF7071_MDIO_LED      0x1B

#define IFXETH_PHY_PEF7071_MDIO_TPGCTRL  0x1C

#define IFXETH_PHY_PEF7071_MDIO_TPGDATA  0x1D

#define IFXETH_PHY_PEF7071_MDIO_FWV      0x1E

#define IFXETH_PHY_PEF7071_MDIO_RES1F    0x1F

#define IFXETH_PHY_PEF7071_WAIT_GMII_READY() while (ETH_GMII_ADDRESS.B.GB) {}

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

uint32 IfxEth_Phy_Pef7071_iPhyInitDone = 0;

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

uint32 IfxEth_Phy_Pef7071_init(void)
{
    IFXETH_PHY_PEF7071_WAIT_GMII_READY();

    /*  // read once all PHY registers
     * int i;
     * for(i = 0; i < 31; i++)
     * {
     * uint32 value;
     * read_mdio_reg(0, i, &value);
     * } */

    // reset PHY
    IfxEth_Phy_Pef7071_write_mdio_reg(0, IFXETH_PHY_PEF7071_MDIO_CTRL, 0x8000);   // reset
    uint32 value;

    do
    {
        IfxEth_Phy_Pef7071_read_mdio_reg(0, IFXETH_PHY_PEF7071_MDIO_CTRL, &value);
    } while (value & 0x8000);                                                      // wait for reset to finish

    // setup PHY
    IfxEth_Phy_Pef7071_write_mdio_reg(0, IFXETH_PHY_PEF7071_MDIO_MIICTRL, 0xF702); // skew adaptation is needed, RMII mode (10/100MBit)
    IfxEth_Phy_Pef7071_write_mdio_reg(0, IFXETH_PHY_PEF7071_MDIO_GCTRL, 0x0000);   // advertise no 1000BASE-T (full/half duplex)
    IfxEth_Phy_Pef7071_write_mdio_reg(0, IFXETH_PHY_PEF7071_MDIO_AN_ADV, 0x0101);  // advertise 100BASE-TX full duplex only
    IfxEth_Phy_Pef7071_write_mdio_reg(0, IFXETH_PHY_PEF7071_MDIO_CTRL, 0x1200);    // enable auto-negotiation, restart auto-negotiation

    //  we set our loop mode (RJ45) in side the PHY (PHYCTL1 register) if we will have a loop
    //  if (CONFIG_ETH._loop)
    //  write_mdio_reg (0, 0x13, (0x4 << 13) | 0x1);

    // done
    IfxEth_Phy_Pef7071_iPhyInitDone = 1;

    return 1;
}


boolean IfxEth_Phy_Pef7071_link(void)
{
    boolean linkEstablished = FALSE;

    if (IfxEth_Phy_Pef7071_iPhyInitDone)
    {
        uint32 value;
        IfxEth_Phy_Pef7071_read_mdio_reg(0, IFXETH_PHY_PEF7071_MDIO_STAT, &value);
        linkEstablished = ((value & (1 << 2)) != 0) ? TRUE : FALSE;
    }

    return linkEstablished;
}


void IfxEth_Phy_Pef7071_read_mdio_reg(uint32 layeraddr, uint32 regaddr, uint32 *pdata)
{
    // 5bit Physical Layer Adddress, 5bit GMII Regnr, 4bit csrclock divider, Read, Busy
    ETH_GMII_ADDRESS.U = (layeraddr << 11) | (regaddr << 6) | (0 << 2) | (0 << 1) | (1 << 0);

    IFXETH_PHY_PEF7071_WAIT_GMII_READY();

    // get data
    *pdata = ETH_GMII_DATA.U;
}


void IfxEth_Phy_Pef7071_write_mdio_reg(uint32 layeraddr, uint32 regaddr, uint32 data)
{
    // put data
    ETH_GMII_DATA.U = data;

    // 5bit Physical Layer Adddress, 5bit GMII Regnr, 4bit csrclock divider, Write, Busy
    ETH_GMII_ADDRESS.U = (layeraddr << 11) | (regaddr << 6) | (0 << 2) | (1 << 1) | (1 << 0);

    IFXETH_PHY_PEF7071_WAIT_GMII_READY();
}
