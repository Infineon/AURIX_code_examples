/**
 * \file  88EA1517.h
 * \brief
 *
 * \version ASDK_0_5_0
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
 */

#ifndef MARVELL_88EA1517_H
#define MARVELL_88EA1517_H

/*******************************************************************************
 * HEADER FILES
 *******************************************************************************/
#include "eth_phy.h"

/*******************************************************************************
 * MACROS
 *******************************************************************************/
#define MARVELL_88EA1517_PHY_ID                    0x01410DD0      /* PHY_ID for 88EA1517 */
#define MARVELL_88EA1517_PHY_ID_MSK                0xFFFFFFF0      /* PHY_ID for 88EA1517 */

typedef enum CONFIG_88EA1517_MODE
{
  RGMIItoCOPPER          = 0UL,
  SGMIItoCOPPER          = 1UL,
  RGMIIto1000Base_TX     = 2UL,
  RGMIItoAUTOMEDIADETEC  = 3UL,
  RGMIItoSGMII           = 4UL,
} Config_88EA1517_Mode_t;

typedef struct MARVELL_88EA1517
{
  uint8 phy_addr;
  uint16 phy_id1;
  uint16 phy_id2;
  uint16 phy_mode;
  uint16 readval;
  uint16 MAC_specific_Config;
  ETH_PHY_LINK_SPEED_t phy_speed;
  ETH_PHY_LINK_DUPLEX_t phy_duplex;
  sint32(*mdio_write)(uint8 phy_addr, uint32 reg_addr, uint16 reg_val);
  sint32(*mdio_read)(uint8 phy_addr, uint32 reg_addr, uint16 *const reg_val);
} MARVELL_88EA1517_t;

/*******************************************************************************
 * API PROTOTYPES
 *******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 */
sint32 MARVELL_88EA1517_Reset(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_IsResetDone(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_IsPhyIdValid(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_Init(MARVELL_88EA1517_t *const handle, ETH_PHY_CONFIG_t config);

/**
 *
 */
sint32 MARVELL_88EA1517_GetLinkStatus(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_GetLinkSpeed(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_GetLinkMode(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_ConfigureLeds(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_ChangeOpMode(MARVELL_88EA1517_t *const handle, Config_88EA1517_Mode_t OPmode);

/**
 *
 */
sint32 MARVELL_88EA1517_SetPowerDown(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_IsAutonegotiationEnabled(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_IsAutonegotiationDone(MARVELL_88EA1517_t *const handle);

/**
 *
 */
sint32 MARVELL_88EA1517_ForceLinkSpeed(MARVELL_88EA1517_t *const handle, sint32 speed);

#ifdef __cplusplus
}
#endif

#endif
