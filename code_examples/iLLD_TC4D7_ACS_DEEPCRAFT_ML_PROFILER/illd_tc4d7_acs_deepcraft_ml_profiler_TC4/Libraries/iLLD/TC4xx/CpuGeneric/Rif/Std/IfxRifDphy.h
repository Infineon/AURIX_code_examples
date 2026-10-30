/**
 * \file IfxRifDphy.h
 * \brief RIF  basic functionality
 * \ingroup IfxLld_Rif
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
 * \defgroup IfxLld_Rif_Std_Dphy Dphy Basic Functionality
 * \ingroup IfxLld_Rif_Std
 * \defgroup IfxLld_Rif_Std_Dphy_Struct Data Structures
 * \ingroup IfxLld_Rif_Std_Dphy
 * \defgroup IfxLld_Rif_Std_Dphy_Api Standard Api
 * \ingroup IfxLld_Rif_Std_Dphy
 * \defgroup IfxLld_Rif_Std_Dphy_Status Status
 * \ingroup IfxLld_Rif_Std_Dphy
 */

#ifndef IFXRIFDPHY_H
#define IFXRIFDPHY_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxRif_cfg.h"
#include "IfxRif.h"
#include "_Utilities/Ifx_Assert.h"
#include "SysSe/Bsp/Bsp.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Rif_Std_Dphy_Struct
 * \{ */
/** \brief Dphy lane polarity
 */
typedef enum
{
    IfxRifDphy_lanePolarity_default = 0,  /**< \brief Default polarity */
    IfxRifDphy_lanePolarity_invert  = 1   /**< \brief Inverted polarity */
} IfxRifDphy_lanePolarity;

/** \brief Dphy lane selection
 */
typedef enum
{
    IfxRifDphy_laneSelect_clock = 0,  /**< \brief clock lane */
    IfxRifDphy_laneSelect_data0 = 1,  /**< \brief data lane 0 */
    IfxRifDphy_laneSelect_data1 = 2,  /**< \brief data lane 1 */
    IfxRifDphy_laneSelect_data2 = 3,  /**< \brief data lane 2 */
    IfxRifDphy_laneSelect_data3 = 4   /**< \brief data lane 3 */
} IfxRifDphy_laneSelect;

/** \} */

/** \addtogroup IfxLld_Rif_Std_Dphy_Api
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief CSI-2 host functions: Set or clear D-PHY reset
 * \param rif Specifies the pointer to the base of RIF registers
 * \param state set/reset the DPHY state
 * \return None
 */
IFX_INLINE void IfxRifDphy_setResetState(Ifx_RIF *rif, IfxRif_State state);

/** \brief Sets the shutdown mode for the DPHY component.
 * \param rif Pointer to the RIF (Radio Interface) handle.
 * \param mode select mode ON or Shutdown for DPHY
 * \return None
 */
IFX_INLINE void IfxRifDphy_setShutdownMode(Ifx_RIF *rif, IfxRif_Dphymode mode);

/** \brief CSI-2 host functions: Release D-PHY test codes from reset
 * \param rif Specifies the pointer to the base of RIF registers
 * \param state set/reset the DPHY test clear state
 * \return None
 */
IFX_INLINE void IfxRifDphy_testClear(Ifx_RIF *rif, IfxRif_State state);

/** \brief Set the Base Direction for lane.
 * \param rif Specifies the pointer to the base of RIF registers
 * \return None
 */
IFX_INLINE void IfxRifDphy_setLaneBaseDirection(Ifx_RIF *rif);

/** \brief Clear lane module from wait for stop state
 * \param rif Specifies the pointer to the base of RIF registers
 * \return None
 */
IFX_INLINE void IfxRifDphy_clearLaneWaitStopState(Ifx_RIF *rif);

/** \brief Enable DPHY clock
 * \param rif Specifies the pointer to the base of RIF registers
 * \return None
 */
IFX_INLINE void IfxRifDphy_enableClock(Ifx_RIF *rif);

/** \brief Sets the state of the CSI2 interface for the RIF module.
 * \param rif Specifies the pointer to the base of RIF registers
 * \param state The desired state for the CSI2 interface (reset or active)
 * \return None
 */
IFX_INLINE void IfxRifDphy_csi2SetState(Ifx_RIF *rif, IfxRif_State state);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Force lane module into wait for stop state
 * \param rif Specifies the pointer to the base of RIF registers
 * \param numlanes Select the number of lanes
 * \return None
 */
IFX_EXTERN void IfxRifDphy_setLaneWaitStopState(Ifx_RIF *rif, IfxRif_NumLanes numlanes);

/** \brief Enable the lanes in DPHY
 * \param rif Specifies the pointer to the base of RIF registers
 * \param numlanes Select the number of active lanes
 * \return None
 */
IFX_EXTERN void IfxRifDphy_enableLanes(Ifx_RIF *rif, IfxRif_NumLanes numlanes);

/** \brief Enable the lanes in CSI-2 host
 * \param rif Specifies the pointer to the base of RIF registers
 * \param numlanes Select the number of active lanes
 * \return None
 */
IFX_EXTERN void IfxRifDphy_csi2EnableLanes(Ifx_RIF *rif, IfxRif_NumLanes numlanes);

/** \brief Configure the cfg clock frequency
 * \param rif Specifies the pointer to the base of RIF registers
 * \param freqMhz cfg clock frequency in MHz
 * \return None
 */
IFX_EXTERN void IfxRifDphy_configClockFrequency(Ifx_RIF *rif, float32 freqMhz);

/** \brief Configure the high speed frequency range
 * \param rif Specifies the pointer to the base of RIF registers
 * \param freqMbps high speed frequency in Mbps
 * \return Return the index of the array IfxRif_highFrequencyRangeTable[]
 */
IFX_EXTERN uint8 IfxRifDphy_configOperatingHsFrequency(Ifx_RIF *rif, uint16 freqMbps);

/** \brief Write test code address configuration
 * \param rif Specifies the pointer to the base of RIF registers
 * \param address register address
 * \return None
 */
IFX_EXTERN void IfxRifDphy_configTestCodeAddress(Ifx_RIF *rif, uint16 address);

/** \brief Write test code configuration
 * \param rif Specifies the pointer to the base of RIF registers
 * \param address register address
 * \param testCodeData the value to be written to register
 * \return None
 */
IFX_EXTERN void IfxRifDphy_writeTestCodeData(Ifx_RIF *rif, uint16 address, uint8 testCodeData);

/** \brief Read test code configuration
 * \param rif Specifies the pointer to the base of RIF registers
 * \param address register address.
 * \return Return the value of the register mapped to "address"
 */
IFX_EXTERN uint8 IfxRifDphy_readTestCodeData(Ifx_RIF *rif, uint16 address);

/** \brief Configure data IDs
 * \param rif Specifies the pointer to the base of RIF registers
 * \param dataIds Pointer to configure the data type ids
 * \param vcId Pointer to configure the virtual channel ids
 * \return None
 */
IFX_EXTERN void IfxRifDphy_csi2ConfigureDataId(Ifx_RIF *rif, IfxRif_Csi2DataTypeId *dataIds, IfxRif_Csi2VirtualChannelId *vcId);

/** \brief LDO startup sequence in case internal LDO is used.(Configure it before D-PHY is released from the shutdown mode)
 * \param rif Specifies the pointer to the base of RIF registers
 * \return None
 */
IFX_EXTERN void IfxRifDphy_ldoStartup(Ifx_RIF *rif);

/** \} */

/** \addtogroup IfxLld_Rif_Std_Dphy_Status
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief CSI-2 host functions: Check if clock lane is in stop state
 * \param rif Specifies the pointer to the base of RIF registers
 * \return None
 */
IFX_INLINE boolean IfxRifDphy_isClockLaneInStopState(Ifx_RIF *rif);

/** \brief CSI-2 host functions: Check if clock lane high speed mode
 * \param rif Specifies the pointer to the base of RIF registers
 * \return Status TRUE if clock lane is in high speed mode, otherwise FALSE
 */
IFX_INLINE boolean IfxRifDphy_isClockLaneInHighSpeedMode(Ifx_RIF *rif);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief CSI-2 host functions: Check if data lane is in stop state
 * \param rif Specifies the pointer to the base of RIF registers
 * \param numlanes select number of lanes
 * \return None
 */
IFX_EXTERN boolean IfxRifDphy_isDataLaneInStopState(Ifx_RIF *rif, IfxRif_NumLanes numlanes);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief CSI-2 host functions: set the lane polarity
 * \param rif Specifies the pointer to the base of RIF registers
 * \param pol The desired lane polarity (normal or inverted)
 * \param sel The lane to set the polarity for (clock or data lane)
 * \return None
 */
IFX_EXTERN void IfxRifDphy_setLanePolarity(Ifx_RIF *rif, IfxRifDphy_lanePolarity pol, IfxRifDphy_laneSelect sel);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxRifDphy_setResetState(Ifx_RIF *rif, IfxRif_State state)
{
    rif->DPHY_RSTZ.B.DPHY_RSTZ = (uint8)state;
}


IFX_INLINE void IfxRifDphy_setShutdownMode(Ifx_RIF *rif, IfxRif_Dphymode mode)
{
    rif->PHY_SHUTDOWNZ.B.PHY_SHUTDOWNZ = (uint8)mode;
}


IFX_INLINE void IfxRifDphy_testClear(Ifx_RIF *rif, IfxRif_State state)
{
    rif->PHY_TEST_CTRL0.B.PHY_TESTCLR = (uint8)state;
}


IFX_INLINE boolean IfxRifDphy_isClockLaneInStopState(Ifx_RIF *rif)
{
    boolean state;
    state = (rif->PHY_STOPSTATE.B.PHY_STOPSTATECLK == 1) ? TRUE : FALSE;
    return state;
}


IFX_INLINE boolean IfxRifDphy_isClockLaneInHighSpeedMode(Ifx_RIF *rif)
{
    boolean status;
    status = (rif->PHY_RX.B.PHY_RXCLKACTIVEHS == 1u) ? TRUE : FALSE;
    return status;
}


IFX_INLINE void IfxRifDphy_setLaneBaseDirection(Ifx_RIF *rif)
{
    rif->DPHYCFG.B.BASEDIR = 1u;
}


IFX_INLINE void IfxRifDphy_clearLaneWaitStopState(Ifx_RIF *rif)
{
    rif->DPHYCFG.B.FRCLN = 0u;
}


IFX_INLINE void IfxRifDphy_enableClock(Ifx_RIF *rif)
{
    rif->DPHYCFG.B.ENCLK = 1u;
}


IFX_INLINE void IfxRifDphy_csi2SetState(Ifx_RIF *rif, IfxRif_State state)
{
    rif->CSI2_RESETN.B.CSI2_RESETN = (uint8)state;
}


#endif /* IFXRIFDPHY_H */
