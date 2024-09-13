/**
 * \file  88EA1517.c
 * \brief
 *
 * \version ASDK_0_5_0
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
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

/*******************************************************************************
 * HEADER FILES
 *******************************************************************************/
#include "88EA1517.h"
#include "mii.h"

/*******************************************************************************
 * MACROS
 *******************************************************************************/

/* 88EA1517 PHY Copper specific Status Register 1 - Page 0 Register 17*/
#define MARVELL_88EA1517_PHY_COPPER_CONTROL_REG     0
#define MARVELL_88EA1517_PHY_COPPER_STATUS_REG      1
#define MARVELL_88EA1517_PHY_COPPER_S_CONTROL_REG   16
#define MARVELL_88EA1517_PHY_GLOBAL_STATUS          17
#define MARVELL_88EA1517_PHY_GLOBAL_Copper_LINK     0x0400 /* Real Time */

#define MARVELL_88EA1517_PHY_RGMII_TX_DELAY_EN      0x0010
#define MARVELL_88EA1517_PHY_RGMII_RX_DELAY_EN      0x0020

#define MARVELL_88EA1517_PHY_Copper_Speed           0xC000
#define MARVELL_88EA1517_PHY_STATUS_GBIT            0x8000
#define MARVELL_88EA1517_PHY_STATUS_100             0x4000

#define MARVELL_88EA1517_PHY_STATUS_DUPLEX          0x2000

#define MARVELL_88EA1517_Page_Reg 22

 uint16 Testregval;


/*******************************************************************************
 * API IMPLEMENTATION
 *******************************************************************************/
sint32 MARVELL_88EA1517_Reset(MARVELL_88EA1517_t *const handle)
{
  uint16 regval = 0;

  /* Reset PHY*/
  if (handle->mdio_read(handle->phy_addr, MII_BMCR, &regval) != 0)
  {
    return ETH_PHY_STATUS_ERROR;
  }

  regval |= BMCR_RESET;
  if (handle->mdio_write(handle->phy_addr, MII_BMCR, regval) != 0)
  {
    return ETH_PHY_STATUS_ERROR;    
  }

  return ETH_PHY_STATUS_OK;
}
  
sint32 MARVELL_88EA1517_IsResetDone(MARVELL_88EA1517_t *const handle)
{
  uint16 regval = 0;

  if (handle->mdio_read(handle->phy_addr, MII_BMCR, &regval) != 0)
  {
    return ETH_PHY_STATUS_ERROR;    
  }
  
  return (((regval & BMCR_RESET) == 0) ? TRUE : FALSE);
}


sint32 MARVELL_88EA1517_IsPhyIdValid(MARVELL_88EA1517_t *const handle)
{

  /* Check Device Identification. */
  if (handle->mdio_read(handle->phy_addr, MII_PHYSID1, &handle->phy_id1) != 0)
  {
    return ETH_PHY_STATUS_ERROR;        
  }

  if (handle->mdio_read(handle->phy_addr, MII_PHYSID2, &handle->phy_id2) != 0)
  {
    return ETH_PHY_STATUS_ERROR;        
  }

  if ((((handle->phy_id1 << 16) | handle->phy_id2) & MARVELL_88EA1517_PHY_ID_MSK) != MARVELL_88EA1517_PHY_ID) 
  {
      return FALSE;
  }

  return TRUE;
}

sint32 MARVELL_88EA1517_Init(MARVELL_88EA1517_t *const handle, ETH_PHY_CONFIG_t config)
{
  uint32 retries;
  uint16 regval = 0;
  /*uint8 phy_addr; */

  if (handle == NULL)
  {
    return ETH_PHY_STATUS_ERROR;
  }

  retries = 0xffffffff;
  while ((MARVELL_88EA1517_IsPhyIdValid(handle) != TRUE) && --retries);
  if (retries == 0)
  {
    return ETH_PHY_STATUS_ERROR_ID;
  }

  /* extract interafce setup */
  sint32 interface = config & (ETH_PHY_CONFIG_INTERFACE_Msk << ETH_PHY_CONFIG_INTERFACE_Pos);

 /* We can do autonegotiation */
  handle->mdio_write(handle->phy_addr, MII_BMCR, BMCR_ANRESTART | BMCR_ANENABLE );

   /* A PHY reset should be issued */
  MARVELL_88EA1517_Reset(handle);
  while (MARVELL_88EA1517_IsResetDone(handle) != TRUE);

  /* Check PHY Mode */
  /* set to page 18 */
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 18);
  handle->mdio_read(handle->phy_addr, 20, &handle->phy_mode);
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 0);
 
  /* set to page 2 */
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 2);
  handle->mdio_read(handle->phy_addr, 21, &handle->MAC_specific_Config);
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 0);

  /* check RGMII shew if needed */
  /* read MAC specific control register */
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 2);
  handle->mdio_read(handle->phy_addr, 21, &regval);

  if ((interface == ETH_PHY_CONFIG_INTERFACE_RGMII_ID) ||
      (interface == ETH_PHY_CONFIG_INTERFACE_RGMII_TXID))
  {
    regval |= MARVELL_88EA1517_PHY_RGMII_TX_DELAY_EN;
  }
  else
  {
    regval &= ~MARVELL_88EA1517_PHY_RGMII_TX_DELAY_EN;
  } 

  if ((interface == ETH_PHY_CONFIG_INTERFACE_RGMII_ID) ||
      (interface == ETH_PHY_CONFIG_INTERFACE_RGMII_RXID))
  {
    regval |= MARVELL_88EA1517_PHY_RGMII_RX_DELAY_EN;
  }
  else
  {
    regval &= ~MARVELL_88EA1517_PHY_RGMII_RX_DELAY_EN;
  } 
  
  /* store the skew values into the PHY MAC specific control regsiter */
  handle->mdio_write(handle->phy_addr,21, regval);
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 0);

  /* has to be removed here */
  MARVELL_88EA1517_ConfigureLeds(handle);
 
 
  return ETH_PHY_STATUS_OK;
}

sint32 MARVELL_88EA1517_GetLinkStatus(MARVELL_88EA1517_t *const handle)
{
  uint16 regval = 0;
  uint8 phy_addr = handle->phy_addr;
    
  handle->mdio_read(phy_addr, MARVELL_88EA1517_PHY_GLOBAL_STATUS, &regval);
  Testregval = regval;

  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 18);
  handle->mdio_read(handle->phy_addr, 20, &handle->phy_mode);
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 0);


  return ((regval & MARVELL_88EA1517_PHY_GLOBAL_Copper_LINK) ? ETH_PHY_LINK_STATUS_UP : ETH_PHY_LINK_STATUS_DOWN);
}

sint32 MARVELL_88EA1517_GetLinkSpeed(MARVELL_88EA1517_t *const handle)
{
  uint16 regval = 0;
  uint8 phy_addr = handle->phy_addr;

  handle->mdio_write(phy_addr, MARVELL_88EA1517_Page_Reg, 0);
  handle->mdio_read(phy_addr, MARVELL_88EA1517_PHY_GLOBAL_STATUS, &regval);
  /* restore to default page 0 */
  handle->mdio_write(phy_addr, MARVELL_88EA1517_Page_Reg, 0);

  regval = (regval & MARVELL_88EA1517_PHY_Copper_Speed);

  switch (regval) 
  {
    case MARVELL_88EA1517_PHY_STATUS_GBIT:
      return ETH_PHY_LINK_SPEED_1000M;
      break;
    case MARVELL_88EA1517_PHY_STATUS_100:
      return ETH_PHY_LINK_SPEED_100M;
      break;
    default:
      return ETH_PHY_LINK_SPEED_10M;
  }
}

/* Get link duplex settings */
sint32 MARVELL_88EA1517_GetLinkMode(MARVELL_88EA1517_t *const handle)
{
  uint16 regval = 0;
  uint8 phy_addr = handle->phy_addr;

  handle->mdio_write(phy_addr, MARVELL_88EA1517_Page_Reg, 0);
  handle->mdio_read(phy_addr, MARVELL_88EA1517_PHY_GLOBAL_STATUS, &regval);
  /* restore to default page 0 */
  handle->mdio_write(phy_addr, MARVELL_88EA1517_Page_Reg, 0);

  return ((regval & MARVELL_88EA1517_PHY_STATUS_DUPLEX) ? ETH_PHY_LINK_DUPLEX_FULL : ETH_PHY_LINK_DUPLEX_HALF);
}
 

sint32 MARVELL_88EA1517_ConfigureLeds(MARVELL_88EA1517_t *const handle)
{

  /* Change LED Mode */
  /* set to page 18 */
  if (handle->phy_speed == ETH_PHY_LINK_SPEED_1000M){
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 3);
  handle->mdio_write(handle->phy_addr, 16,  0x0011); /* LINKACT */
  handle->mdio_write(handle->phy_addr, 17,  0x4404); /* LINKACT */
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 0);
  }

  if (handle->phy_speed == ETH_PHY_LINK_SPEED_100M){
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 3);
  handle->mdio_write(handle->phy_addr, 16,  0x0018); /* LINKACT force LED0 OFF */
  handle->mdio_write(handle->phy_addr, 17,  0x4404); /* LINKACT */
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 0);
  }

  if (handle->phy_speed == ETH_PHY_LINK_SPEED_10M){
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 3);
  handle->mdio_write(handle->phy_addr, 16,  0x0081); /* LINKACT force LED0 OFF */
  handle->mdio_write(handle->phy_addr, 17,  0x4404); /* LINKACT */
  handle->mdio_write(handle->phy_addr,MARVELL_88EA1517_Page_Reg, 0);
  }

  return ETH_PHY_STATUS_OK;
}



sint32 MARVELL_88EA1517_IsAutonegotiationEnabled(MARVELL_88EA1517_t *const handle)
{
  uint16 regval = 0;
  uint8 phy_addr = handle->phy_addr;

  /* set page first to page 0 */
  handle->mdio_write(phy_addr, MARVELL_88EA1517_Page_Reg, 0);
  
  /* read copper control register in page 0 */
  if (handle->mdio_read(phy_addr, MARVELL_88EA1517_PHY_COPPER_CONTROL_REG, &regval) != 0)
  {
    return ETH_PHY_STATUS_ERROR;            
  }
 
  return (((regval & BMCR_ANENABLE) != 0) ? TRUE : FALSE); 
}

sint32 MARVELL_88EA1517_IsAutonegotiationDone(MARVELL_88EA1517_t *const handle)
{
  uint16 regval = 0;
  uint8 phy_addr = handle->phy_addr;

 /* set page first to page 0 */
  handle->mdio_write(phy_addr, MARVELL_88EA1517_Page_Reg, 0);
  
  /* read copper control register in page 0 */
  if (handle->mdio_read(phy_addr, MARVELL_88EA1517_PHY_COPPER_STATUS_REG, &regval) != 0)
  {
    return ETH_PHY_STATUS_ERROR;            
  }

  return (((regval & BMSR_ANEGCOMPLETE) != 0) ? TRUE : FALSE);
}

