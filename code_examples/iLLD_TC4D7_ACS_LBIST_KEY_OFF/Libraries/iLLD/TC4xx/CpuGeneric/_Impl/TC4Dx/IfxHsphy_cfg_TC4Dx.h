/**
 * \file IfxHsphy_cfg_TC4Dx.h
 * \brief HSPHY on-chip implementation data
 * \ingroup IfxLld_Hsphy
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
 * \defgroup IfxLld_Hsphy HSPHY
 * \ingroup IfxLld
 * \defgroup IfxLld_Hsphy_Impl Implementation
 * \ingroup IfxLld_Hsphy
 * \defgroup IfxLld_Hsphy_Std Standard Driver
 * \ingroup IfxLld_Hsphy
 */

#ifndef IFXHSPHY_CFG_TC4DX_H
#define IFXHSPHY_CFG_TC4DX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Types.h"
#include "IfxHsphy_reg.h"
#include "IfxHsphy_bf.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of Channels
 */
#define IFXHSPHY_NUM_CHANNELS        				 (3)

/** \brief Number of Modules
 */
#define IFXHSPHY_NUM_MODULES         				 (1)

/** \brief Max number of PHYS inside a single HPSHY across family
 */
#define IFXHSPHY_NUM_OF_PHY          				 (3)

/** \brief Number of PHYS inside a single HPSHY
 */
#define IFXHSPHY_ACTUAL_NUM_OF_PHY   				 (3)

/** \brief Platform macro
 * IFXHSPHY_PLATFORM_SIMULATION = 1 for Simulation platform
 * IFXHSPHY_PLATFORM_SIMULATION = 0 for other platform (default)
 */
#ifndef IFXHSPHY_PLATFORM_SIMULATION
#define IFXHSPHY_PLATFORM_SIMULATION 				 (0)
#endif

/** \brief Availability of HSPHY DLL
 */
#define IFXHSPHY_IS_DLL_AVAILABLE   				 (TRUE)

/** \brief Availability of GETH
 */
#define IFXHSPHY_IS_GETH_AVAILABLE   				 (TRUE)

/** \brief Availability of Interface Pad USXSGMII
 */
#define IFXHSPHY_IS_PADINTERFACE_USXSGMII_AVAILABLE  (TRUE)

/** \brief Availability of Interface Pad PCIE
 */
#define IFXHSPHY_IS_PADINTERFACE_PCIE_AVAILABLE		 (TRUE)

/** \brief Availability of Interface Pad SGBT
 */
#define IFXHSPHY_IS_PADINTERFACE_SGBT_AVAILABLE      (FALSE)

/** \brief Availability of PHY0
 */
#define IFXHSPHY_IS_PHY0_AVAILABLE   				 (TRUE)

/** \brief Availability of PHY2
 */
#define IFXHSPHY_IS_PHY2_AVAILABLE   				 (TRUE)

/** \brief HSPHY target device XGMAC 
 */
#define IFXHSPHY_IS_TRGTDEVICE_XGMAC 			     (TRUE)

/** \brief HSPHY target device PCIE 
 */
#define IFXHSPHY_IS_TRGTDEVICE_PCIE 				 (TRUE)

/** \brief HSPHY target device speed selection for 2.5G mode
 */
#define IFXHSPHY_IS_TRGTDEVICE_SPEED_2P5G  		     (TRUE)

/** \brief HSPHY target device speed selection for 5G mode
 */
#define IFXHSPHY_IS_TRGTDEVICE_SPEED_5G  			 (TRUE)

/** \brief TRIGGER to flush/Initialise FIFO's Implemented inside the XPCS
 */
#define IFXHSPHY_XDATAPATH_INIT_TRIG		 		 (FALSE)

/** \brief Timeout Check
 */
#define IFXHSPHY_TIMEOUT_CHECK 					     (FALSE)

/** \brief TARGET IDX value
 */
#define IFXHSPHY_TRGTDEVICE_IDX_VALUE   			 (1)

/** \brief Hsphy config lookup table value
 */
#define IFXHSPHY_CONFIG_LOOKUPTBL_VALUES  { \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_pcie,      IfxHsphy_TrgtDevice_pcie,  0, IfxHsphy_TrgtDeviceSpeed_8G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_0P1G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_0P1G_125mbps,  NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_0P1G_1P25gbps, NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_1G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_2P5G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_5G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_usxsgmii,  IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_5G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_miiPads,   IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_0P1G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_miiPads,   IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_0P01G,         NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_rmiiPads,  IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_0P1G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_rmiiPads,  IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_0P01G,         NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_rgmiiPads, IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_0P1G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_rgmiiPads, IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_1G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_0,    IfxHsphy_PadNativeInterface_rgmiiPads, IfxHsphy_TrgtDevice_xgmac, 0, IfxHsphy_TrgtDeviceSpeed_0P01G,         NULL_PTR}, \
    {IfxHsphy_PhyIndex_none, IfxHsphy_PadNativeInterface_xspiPads,  IfxHsphy_TrgtDevice_xspi,  0, IfxHsphy_TrgtDeviceSpeed_0P4G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_0P1G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_0P1G_125mbps,  NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_0P1G_1P25gbps, NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_1G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_2P5G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_sgmii,     IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_5G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_sgbt,      IfxHsphy_TrgtDevice_trace, 0, IfxHsphy_TrgtDeviceSpeed_1G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_usxsgmii,  IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_5G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_miiPads,   IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_0P1G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_miiPads,   IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_0P01G,         NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_rmiiPads,  IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_0P1G,          NULL_PTR}, \
    {IfxHsphy_PhyIndex_1,    IfxHsphy_PadNativeInterface_rmiiPads,  IfxHsphy_TrgtDevice_xgmac, 1, IfxHsphy_TrgtDeviceSpeed_0P01G,         NULL_PTR}, \
    {IfxHsphy_PhyIndex_2,    IfxHsphy_PadNativeInterface_pcie,      IfxHsphy_TrgtDevice_pcie,  1, IfxHsphy_TrgtDeviceSpeed_8G,            NULL_PTR}, \
    {IfxHsphy_PhyIndex_2,    IfxHsphy_PadNativeInterface_sgbt,      IfxHsphy_TrgtDevice_trace, 0, IfxHsphy_TrgtDeviceSpeed_1G,            NULL_PTR}  \
	}

#define IFXHSPHY_GETHXPCS_DEFAULT_CONFIG_VALUES {\
     {IfxHsphy_XpcsIndex_0, IfxHsphy_XpcsRefClk_100Mhz, IfxHsphy_EthIndex_0}, \
     {IfxHsphy_XpcsIndex_1, IfxHsphy_XpcsRefClk_100Mhz, IfxHsphy_EthIndex_1}  \
     }

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Hsphy index
 */
typedef enum
{
    IfxHsphy_hsphyIndex_none = -1,  /**< \brief Not Selected */
    IfxHsphy_hsphyIndex_0    = 0,   /**< \brief HSPHY index 0  */
} IfxHsphy_hsphyIndex;

/** \brief PHY index in HPSHY
 */
typedef enum
{
    IfxHsphy_PhyIndex_0    = 0, /**< \brief PHY index 0 */
    IfxHsphy_PhyIndex_1    = 1, /**< \brief PHY index 1 */
    IfxHsphy_PhyIndex_2    = 2, /**< \brief PHY index 2 */
    IfxHsphy_PhyIndex_none = 3  /**< \brief PHY index none */
} IfxHsphy_PhyIndex;

/** \brief Interface Pad selection for target devices to be used
 */
typedef enum
{
    IfxHsphy_PadNativeInterface_usxsgmii = 0,  /**< \brief Pad Interface selection for usxsgmii */
    IfxHsphy_PadNativeInterface_sgmii,         /**< \brief Pad Interface selection for sgmii */
    IfxHsphy_PadNativeInterface_pcie,          /**< \brief Pad Interface selection for  pcie */
    IfxHsphy_PadNativeInterface_sgbt,          /**< \brief Pad Interface selection for sgbt */
    IfxHsphy_PadNativeInterface_rgmiiPads,     /**< \brief Pad Interface selection for rgmiipads */
    IfxHsphy_PadNativeInterface_rmiiPads,      /**< \brief Pad Interface selection for rmiipads */
    IfxHsphy_PadNativeInterface_miiPads,       /**< \brief Pad Interface selection for miipads */
    IfxHsphy_PadNativeInterface_xspiPads       /**< \brief Pad Interface selection for xspipads */
} IfxHsphy_PadNativeInterface;

/** \brief SGMII speed selection
 */
typedef enum
{
    IfxHsphy_SgmiiSpeed_0P1G          = 0,  /**< \brief SGMII 100M speed selection */
    IfxHsphy_SgmiiSpeed_1G            = 1,  /**< \brief SGMII 1G speed selection */
    IfxHsphy_SgmiiSpeed_2P5G          = 2,  /**< \brief SGMII 2P5G speed selection */
    IfxHsphy_SgmiiSpeed_5G            = 3,  /**< \brief SGMII 5G speed selection */
    IfxHsphy_SgmiiSpeed_0P1G_1P25gbps = 4,  /**< \brief SGMII 100M 1.25 gbps speed selection */
    IfxHsphy_SgmiiSpeed_0P1G_125mbps  = 5,  /**< \brief SGMII 100M 125mbps speed selection */
    IfxHsphy_SgmiiSpeed_max           = 6   /**< \brief max SGMII speed selection */
} IfxHsphy_SgmiiSpeed;

/** \brief Target device
 */
typedef enum
{
    IfxHsphy_TrgtDevice_xgmac = 0,  /**< \brief XGAMC dvice */
    IfxHsphy_TrgtDevice_pcie,       /**< \brief PCIE device */
    IfxHsphy_TrgtDevice_xspi,       /**< \brief XSPI device */
    IfxHsphy_TrgtDevice_trace       /**< \brief TRACE device */
} IfxHsphy_TrgtDevice;

/** \brief Target device speed selection
 */
typedef enum
{
    IfxHsphy_TrgtDeviceSpeed_0P01G        = 0,  /**< \brief Target device speed selection for 10M mode */
    IfxHsphy_TrgtDeviceSpeed_0P1G         = 1,  /**< \brief Target device speed selection for 100M mode.(alias to 100M 125mbps mode) */
    IfxHsphy_TrgtDeviceSpeed_0P1G_125mbps = 1,  /**< \brief Target device speed selection for 100M with 125mbps mode */
    IfxHsphy_TrgtDeviceSpeed_0P4G,              /**< \brief Target device speed selection for 400M mode */
    IfxHsphy_TrgtDeviceSpeed_1G,                /**< \brief Target device speed selection for  1G mode */
    IfxHsphy_TrgtDeviceSpeed_2P5G,              /**< \brief Target device speed selection for 2.5G mode */
    IfxHsphy_TrgtDeviceSpeed_5G,                /**< \brief Target device speed selection for 5G mode */
    IfxHsphy_TrgtDeviceSpeed_8G,                /**< \brief Target device speed selection for 8G mode */
    IfxHsphy_TrgtDeviceSpeed_0P1G_1P25gbps = 7  /**< \brief Target device speed selection for serial 100M with 1.25gbps mode */
} IfxHsphy_TrgtDeviceSpeed;

/** \brief Target interface
 */
typedef enum
{
    IfxHsphy_TrgtInterface_xpcs = 0,  /**< \brief XPCS interface */
    IfxHsphy_TrgtInterface_upcs,      /**< \brief UPCS interface */
    IfxHsphy_TrgtInterface_tpcs       /**< \brief TPCS interface */
} IfxHsphy_TrgtInterface;

/** \brief XPCS indexing
 */
typedef enum
{
    IfxHsphy_XpcsIndex_0   = 0, /**< \brief XPCS index 0 */
    IfxHsphy_XpcsIndex_1   = 1, /**< \brief XPCS index 1 */
    IfxHsphy_XpcsIndex_max = 2  /**< \brief Max value of XPCS index */
} IfxHsphy_XpcsIndex;

/** \brief ETH index in HPSHY
 */
typedef enum
{
    IfxHsphy_EthIndex_0    = 0, /**< \brief ETH index 0 */
    IfxHsphy_EthIndex_1    = 1, /**< \brief ETH index 1 */
    IfxHsphy_EthIndex_max  = 2, /**< \brief Max index for ETH */
    IfxHsphy_EthIndex_none = 3  /**< \brief None */
} IfxHsphy_EthIndex;

/** \brief Port Index for MDIO
 */
typedef enum
{
    IfxHsphy_Mdio_PortIndex_0 = 0,  /**< \brief port index  for mdio0 */
    IfxHsphy_Mdio_PortIndex_1 = 1   /**< \brief port index for mdio1 */
} IfxHsphy_Mdio_PortIndex;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxHsphy_cfg_hsphyIndexMap[IFXHSPHY_NUM_MODULES];

#endif /* IFXHSPHY_CFG_TC4DX_H */
