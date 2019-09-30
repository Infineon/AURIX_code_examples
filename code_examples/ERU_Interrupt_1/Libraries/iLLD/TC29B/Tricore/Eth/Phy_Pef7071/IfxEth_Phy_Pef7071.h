/**
 * \file IfxEth_Phy_Pef7071.h
 * \brief ETH PHY_PEF7071 details
 * \ingroup IfxLld_Eth
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
 * \defgroup IfxLld_Eth_Phy_Pef7071 PHY_PEF7071
 * \ingroup IfxLld_Eth
 * \defgroup IfxLld_Eth_Phy_Pef7071_Functions Functions
 * \ingroup IfxLld_Eth_Phy_Pef7071
 */

#ifndef IFXETH_PHY_PEF7071_H
#define IFXETH_PHY_PEF7071_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Eth/Std/IfxEth.h"
/** \addtogroup IfxLld_Eth_Phy_Pef7071_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \return Status
 */
IFX_EXTERN uint32 IfxEth_Phy_Pef7071_init(void);

/**
 * \return Link status
 */
IFX_EXTERN boolean IfxEth_Phy_Pef7071_link(void);

/**
 * \return None
 */
IFX_EXTERN void IfxEth_Phy_Pef7071_read_mdio_reg(uint32 layeraddr, uint32 regaddr, uint32 *pdata);

/**
 * \return None
 */
IFX_EXTERN void IfxEth_Phy_Pef7071_write_mdio_reg(uint32 layeraddr, uint32 regaddr, uint32 data);

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN uint32 IfxEth_Phy_Pef7071_iPhyInitDone;

#endif /* IFXETH_PHY_PEF7071_H */
