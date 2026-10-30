/**
 * \file IfxMsc_Msc.h
 * \brief MSC MSC details
 * \ingroup IfxLld_Msc
 *
 * \version iLLD_1_22_0
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
 * \defgroup IfxLld_Msc_Msc_Usage How to use the MSC Interface driver?
 * \ingroup IfxLld_Msc
 *
 * The MSC interface driver provides a default MSC configuration
 *
 *
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Msc_Msc_Preparation Preparation
 * \subsection IfxLld_Msc_Msc_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 *     #include <Msc/Msc/IfxMsc_Msc.h>
 * \endcode
 *
 * \subsection IfxLld_Msc_Msc_Variables Variables
 *
 * Declare the MSC handle as global variable in your C code:
 *
 * \code
 *     // MSC handle
 *     static IfxMsc_Msc *msc;
 *
 *     // IO Pins
 *     static const IfxMsc_Msc_Io IfxMsc_PinMap[IFXMSC_NUM_MODULES] = {
 *     {
 *         { &IfxMsc0_FCLP_P13_1_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc0_FCLN_P13_0_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc0_SOP_P13_3_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc0_SON_P13_2_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc0_EN0_P10_3_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc0_EN1_P11_2_OUT, IfxPort_OutputMode_pushPull },
 *          {NULL_PTR},
 *          {NULL_PTR},
 *         { &IfxMsc0_SDI0_P11_10_IN, IfxPort_InputMode_pullUp },
 *         { &IfxMsc0_INJ0_P00_0_IN, IfxPort_InputMode_pullUp },
 *         { &IfxMsc0_INJ1_P10_5_IN, IfxPort_InputMode_pullUp },
 *         IfxPort_PadDriver_cmosAutomotiveSpeed3
 *     },
 *
 *     #if IFXMSC_NUM_MODULES >= 2
 *     {
 *         { &IfxMsc1_FCLP_P22_1_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc1_FCLN_P22_0_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc1_SOP_P22_3_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc1_SON_P22_2_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc1_EN0_P23_4_OUT, IfxPort_OutputMode_pushPull },
 *         { &IfxMsc1_EN1_P23_5_OUT, IfxPort_OutputMode_pushPull },
 *          {NULL_PTR},
 *          {NULL_PTR},
 *         { &IfxMsc1_SDI0_P23_1_IN, IfxPort_InputMode_pullUp },
 *         { &IfxMsc1_INJ0_P23_3_IN, IfxPort_InputMode_pullUp },
 *         { &IfxMsc1_INJ1_P33_13_IN, IfxPort_InputMode_pullUp },
 *         IfxPort_PadDriver_cmosAutomotiveSpeed3
 *     },
 *     #endif
 * };
 * \endcode
 *
 * \subsection IfxLld_Msc_Msc_Init Module Initialisation
 *
 * The module initialisation can be done as followed:
 * \code
 *     // create configuration (same is used for all MSCs)
 *     IfxMsc_Msc_Config mscConfig;
 *     IfxMsc_Msc_initModuleConfig(&mscConfig, &MODULE_MSC0);
 *
 *     // increase baudrate for faster simulation:
 *     mscConfig.clockConfig.baudrate = 25000000;
 *     mscConfig.clockConfig.dividerMode = IfxMsc_DividerMode_fractional;
 *
 *     // FCL only activated on transfers
 *     mscConfig.outputControlConfig.fclClockControl = IfxMsc_FclClockControlEnabled_activePhaseOnly;
 *
 *     // in this case we also don't need a selection bit
 *     mscConfig.downstreamConfig.srlActivePhaseSelection = IfxMsc_ActivePhaseSelection_none;
 *     mscConfig.downstreamConfig.srhActivePhaseSelection = IfxMsc_ActivePhaseSelection_none;
 *
 *     // initialize MSCs
 *     for(int i=0; i<IFXMSC_NUM_MODULES; ++i) {
 *         // init module pointer
 *         mscConfig.msc = (Ifx_MSC*)IfxMsc_cfg_indexMap[i].module;
 *
 *         // IO Config
 *         mscConfig.io = IfxMsc_PinMap[i];
 *
 *         // initialize module
 *         IfxMsc_Msc_initModule(&msc[i], &mscConfig);
 *     }
 * \endcode
 *
 * The MSC is ready for use now!
 *
 *
 * \section IfxLld_Msc_Msc_DataTransfers Data Transfers
 *
 * The MSC driver provides simple to use transfer function
 *
 * \code
 *     for(int n=0; n<10; ++n) {
 *         // clear IRQ flag of previous transfer
 *         for(int i=0; i<IFXMSC_NUM_MODULES; ++i) {
 *             msc[i].msc->ISC.B.CDEDI = 1;
 *         }
 *
 *         // new transfer
 *         for(int i=0; i<IFXMSC_NUM_MODULES; ++i) {
 *             const unsigned dataL = i*0x1000 + n;
 *             const unsigned dataH = i*0x1000 + 0x0100 + n;
 *             IfxMsc_Msc_sendData(&msc[i], dataL, dataH);
 *         }
 *         // wait until transfers are finished
 *         for(int i=0; i<IFXMSC_NUM_MODULES; ++i) {
 *             while( !msc[i].msc->ISR.B.DEDI ); //  check if new data could be written
 *             while( msc[i].msc->DSS.B.DFA ); //  check if we are still in the active data phase
 *         }
 * }
 * \endcode
 *
 * \defgroup IfxLld_Msc_Msc MSC
 * \ingroup IfxLld_Msc
 * \defgroup IfxLld_Msc_Msc_Enumerations Enumerations
 * \ingroup IfxLld_Msc_Msc
 * \defgroup IfxLld_Msc_Msc_Data_Structures Data Structures
 * \ingroup IfxLld_Msc_Msc
 * \defgroup IfxLld_Msc_Msc_Module_Initialize_Functions Module Initialize Functions
 * \ingroup IfxLld_Msc_Msc
 * \defgroup IfxLld_Msc_Msc_Send_Functions Send Functions
 * \ingroup IfxLld_Msc_Msc
 * \defgroup IfxLld_Msc_Msc_Receive_Functions Receive Functions
 * \ingroup IfxLld_Msc_Msc
 * \defgroup IfxLld_Msc_Msc_Target_Read_Write_Functions Target Read Write Functions
 * \ingroup IfxLld_Msc_Msc
 */

#ifndef IFXMSC_MSC_H
#define IFXMSC_MSC_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Msc/Std/IfxMsc.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Msc_Msc_Enumerations
 * \{ */
/** \brief Msc Instance Number
 */
typedef enum
{
    IfxMsc_Msc_Target_low  = 0, /**< \brief MSC Target Low */
    IfxMsc_Msc_Target_high = 1  /**< \brief MSC Target High */
} IfxMsc_Msc_Target;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Msc_Msc_Data_Structures
 * \{ */
/** \brief En pin Configuration Structure
 */
typedef struct
{
    IfxMsc_En_Out     *pin;		/**< \brief Pointer to the En Out pinmap structure */
    IfxPort_OutputMode mode;	/**< \brief Specifies the pin output mode */
} IfxMsc_Msc_en;

/** \brief Fcln pin Configuration Structure
 */
typedef struct
{
    IfxMsc_Fcln_Out   *pin;		/**< \brief Pointer to the Fcln Out pinmap structure */
    IfxPort_OutputMode mode;	/**< \brief Specifies the pin output mode */
} IfxMsc_Msc_fcln;

/** \brief Fclp pin Configuration Structure
 */
typedef struct
{
    IfxMsc_Fclp_Out   *pin;		/**< \brief Pointer to the Fclp Out pinmap structure */
    IfxPort_OutputMode mode;	/**< \brief Specifies the pin output mode */
} IfxMsc_Msc_fclp;

/** \brief Inj0 Configuration Structure
 */
typedef struct
{
    IfxMsc_Inj_In    *pin;		/**< \brief Pointer to the Inj In pinmap structure */
    IfxPort_InputMode mode;		/**< \brief Specifies the pin input mode */
} IfxMsc_Msc_inj0;

/** \brief Inj1 Configuration Structure
 */
typedef struct
{
    IfxMsc_Inj_In    *pin;		/**< \brief Pointer to the Inj In pinmap structure */
    IfxPort_InputMode mode;		/**< \brief Specifies the pin input mode */
} IfxMsc_Msc_inj1;

/** \brief Sdi Configuration Structure
 */
typedef struct
{
    IfxMsc_Sdi_In    *pin;		/**< \brief Pointer to the Sdi In pinmap structure */
    IfxPort_InputMode mode;		/**< \brief Specifies the pin input mode */
} IfxMsc_Msc_sdi;

/** \brief Son Configuration Structure
 */
typedef struct
{
    IfxMsc_Son_Out    *pin;		/**< \brief Pointer to the Son Out pinmap structure */
    IfxPort_OutputMode mode;	/**< \brief Specifies the pin output mode */
} IfxMsc_Msc_son;

/** \brief Sop Configuration Structure
 */
typedef struct
{
    IfxMsc_Sop_Out    *pin;		/**< \brief Pointer to the Sop Out pinmap structure */
    IfxPort_OutputMode mode;	/**< \brief Specifies the pin output mode */
} IfxMsc_Msc_sop;

/** \} */

/** \addtogroup IfxLld_Msc_Msc_Data_Structures
 * \{ */
/** \brief ABRA block Configuration Structure
 */
typedef struct
{
    uint32                         abraDownstreamBlockBaudrate;       /**< \brief Specifies ABRA downstream block baud. Range: 0x5F5E1 (0.39 Mbaud) to 0x17D7840 (25 Mbaud) */
    IfxMsc_ShiftClockPhaseDuration lowPhaseOfShiftClock;              /**< \brief Specifies Low phase of shift clock */
    IfxMsc_ShiftClockPhaseDuration highPhaseOfShiftClock;             /**< \brief Specifies High phase of shift clock */
    IfxMsc_ClockSelect             clockSelectAbra;                   /**< \brief Specifies the clock select for ABRA */
    IfxMsc_NDividerAbra            nDividerAbra;                      /**< \brief Specifies the N divider */
    IfxMsc_AsynchronousBlock       abraBlockBypass;                   /**< \brief Specifies ABRA block bypass */
} IfxMsc_Msc_Abra;

/** \brief Clock configuration data Structure
 */
typedef struct
{
    uint32             baudrate;          /**< \brief Specifies the baud rate. Range: 0x5F5E1 (0.39 Mbaud) to 0x17D7840 (25 Mbaud) */
    IfxMsc_DividerMode dividerMode;       /**< \brief Specifies divided clock properties */
    uint16             step;              /**< \brief Specifies the step value. Range: 0 to 0x3FF */
} IfxMsc_Msc_Clock;

/** \brief Configuration Settings for CX mode
 */
typedef struct
{
    IfxMsc_Extension                               extension;                                 /**< \brief To enable or disable the CX mode */
    IfxMsc_CommandFrameLength                      commandFrameLength;
    IfxMsc_ControlFrameExtensionPassivePhaseLength commandFramePassivePhaseLength;
    IfxMsc_ActivePhaseSelection                    srlActivePhaseSelection;                   /**< \brief Specifies the Enable SRL active phase selection bit */
    IfxMsc_ActivePhaseSelection                    srhActivePhaseSelection;                   /**< \brief Specifies the Enable SRH active phase selection bit */
    IfxMsc_DataFrameLength                         srlDataFrameLength;                        /**< \brief Number of SRL bits to be transmitted */
    IfxMsc_DataFrameLength                         srhDataFrameLength;                        /**< \brief Number of SRH bits to be transmitted */
    IfxMsc_MsbBitDataExtension                     srlBitsShiftedAtDataFramesExtension;       /**< \brief Adds 16 to number of SRL data frame bits if enabled */
    IfxMsc_MsbBitDataExtension                     srhBitsShiftedAtDataFramesExtension;       /**< \brief Adds 16 to number of SRH data frame bits if enabled */
    IfxMsc_FastMode                                fastMode;                                  /**< \brief To enable or disable Fast Mode */
    IfxMsc_NDividerDownstream                      nDividerDownstream;                        /**< \brief For configuring DSTE.NDD divider value */
} IfxMsc_Msc_CommandExtensionConfig;

/** \brief Downstream Control Configuration Structure
 */
typedef struct
{
    IfxMsc_TransmissionMode                 transmissionMode;                      /**< \brief Specifies the transmission Mode */
    IfxMsc_DataFrameLength                  srlDataFrameLength;                    /**< \brief Specifies the Number of SRL bits shifted at data frames */
    IfxMsc_DataFrameLength                  srhDataFrameLength;                    /**< \brief Specifies the Number of SRH bits shifted at data frames */
    IfxMsc_ActivePhaseSelection             srlActivePhaseSelection;               /**< \brief Specifies the Enable SRL active phase selection bit */
    IfxMsc_ActivePhaseSelection             srhActivePhaseSelection;               /**< \brief Specifies the Enable SRL active phase selection bit */
    IfxMsc_CommandFrameLength               commandFrameLength;                    /**< \brief Specifies the Number of bits shifted at command frames */
    IfxMsc_DataFramePassivePhaseLength      dataFramePassivePhaseLength;           /**< \brief Specifies the Passive Phase Length at Data Frames */
    IfxMsc_PassiveTimeFrameCount            passiveTimeFrameCount;                 /**< \brief Specifies the Number of Passive Time Frames */
    IfxMsc_ExternalSignalInjection          externalSignalInjectionPin0;           /**< \brief Specifies the Injection Enable Pin 0 */
    IfxMsc_ExternalBitInjectionPosition     injectionPositionPin0;                 /**< \brief Specifies the Injection Position Pin 0 */
    IfxMsc_ExternalSignalInjection          externalSignalInjectionPin1;           /**< \brief Specifies the Injection Enable Pin 1 */
    IfxMsc_ExternalBitInjectionPosition     injectionPositionPin1;                 /**< \brief Specifies the Injection Position Pin 1 */
    IfxMsc_CommandDataCommandRepetitionMode commandDataCommandReceptionMode;       /**< \brief Specifies the Command-Data-Command in Data Repetition Mode */
    uint32                                  downstreamDataSourcesLow;              /**< \brief Specifies the Downstream Data Source selections Low. Range: 0 to 0xFFFFFFFF
    																				* Bifield: SLx (x=0-15) SLx Range: 0 -> SRL[x] is taken from data register DD.DDL[x], 2 -> SRL[x] is taken from the ALTINL input line x, 3 -> SRL[x] is taken from the ALTINL input line x in inverted state. */
    uint32                                  downstreamDataSourcesHigh;             /**< \brief Specifies the Downstream Data Source selections High. Range: 0 to 0xFFFFFFFF
    																				* Bifield: SHx (x=0-15) SHx Range: 0 -> SRH[x] is taken from data register DD.DDH[x]), 2 -> SRH[x] is taken from the ALTINH input line x, 3 -> SRH[x] is taken from the ALTINH input line x in inverted state. */
    uint32                                  emergencyStopEnableBits;               /**< \brief Emergency Stop. Range: 0 to 0xFFFFFFFF
    																				* ENLx Bifield: ENLx (x=0-15) TRUE The emergency stop feature for bit SRL[x] is enabled, FALSE Emergency stop feature for bit SRL[x] is disabled.
    																			    * ENHx Bifield: ENHx (x=0-15) TRUE The emergency stop feature for bit SRH[x] is enabled, FALSE Emergency stop feature for bit SRH[x] is disabled */
} IfxMsc_Msc_DownstreamControlConfig;

/** \brief Downstream Control Extension Configuration Structure
 */
typedef struct
{
    IfxMsc_Extension                               extension;                                     /**< \brief Specifies the Extension Enable */
    IfxMsc_MsbBitDataExtension                     srlBitsShiftedAtDataFramesExtension;           /**< \brief Specifies the Number of SRLE bits shifted at Data Frames */
    IfxMsc_MsbBitDataExtension                     srhBitsShiftedAtDataFramesExtension;           /**< \brief Specifies the Number of SRHE bits shifted at Data Frames */
    uint32                                         downstreamExtensionDataSourcesLow;             /**< \brief Specifies the Downstream Select Data Source Low Extension. Range: 0 to 0xFFFFFFFF
    																							   * Bifield: SLx (x=0-15) SLx Range: 0 -> SRL[x] is taken from data register DD.DDL[x], 2 -> SRL[x] is taken from the ALTINL input line x, 3 -> SRL[x] is taken from the ALTINL input line x in inverted state. */
    uint32                                         downstreamExtensionDataSourcesHigh;            /**< \brief Specifies the Downstream Select Data Source High Extension. Range: 0 to 0xFFFFFFFF
    																							   * Bifield: SHx (x=0-15) SHx Range: 0 -> SRH[x] is taken from data register DD.DDH[x], 2 -> SRH[x] is taken from the ALTINH input line x, 3 -> SRH[x] is taken from the ALTINH input line x in inverted state. */
    uint32                                         emergencyStopExtensionEnableBits;              /**< \brief Emergency Stop Extension. Range: 0 to 0xFFFFFFFF
    																							   * Bifield: ENLx (x=0-15) TRUE The emergency stop feature for bit SRL[x] is enabled, FALSE Emergency stop feature for bit SRL[x] is disabled.
    																						   	   * Bifield: ENHx (x=0-15) TRUE The emergency stop feature for bit SRH[x] is enabled, FALSE Emergency stop feature for bit SRH[x] is disabled. */
    IfxMsc_DataFrameExtensionPassivePhaseLength    dataFrameExtensionPassivePhaseLength;          /**< \brief Specifies the Passive Phase Length at Data Frames Extension */
    IfxMsc_ControlFrameExtensionPassivePhaseLength controlFrameExtensionPassivePhaseLength;       /**< \brief Specifies the Passive Phase Length at Control Frames Extension */
    IfxMsc_NDividerDownstream                      nDividerDownstream;                            /**< \brief Specifies the division ratio for downstream generator clock */
} IfxMsc_Msc_DownstreamControlExtensionConfig;

/** \brief Interrupt Configuration Structure
 */
typedef struct
{
    IfxMsc_DataFrameInterruptNode       dataFrameInterruptNode;             /**< \brief Specifies the Data Frame Interrupt Node */
    IfxMsc_DataFrameInterrupt           dataFrameInterrupt;                 /**< \brief Specifies the Data Frame Interrupt Mode */
    IfxMsc_CommandFrameInterruptNode    commandFrameInterruptNode;          /**< \brief Specifies the Command Frame Interrupt Node */
    IfxMsc_CommandFrameInterrupt        commandFrameInterrupt;              /**< \brief Specifies the Command Frame Interrupt Mode */
    IfxMsc_TimeFrameInterruptNode       timeFrameInterruptNode;             /**< \brief Specifies the Time Frame Interrupt Node */
    IfxMsc_TimeFrameInterrupt           timeFrameInterrupt;                 /**< \brief Specifies the Time Frame Interrupt Mode */
    IfxMsc_ReceiveDataInterruptNode     receiveDataInterruptNode;           /**< \brief Specifies the Receive Interrupt Node */
    IfxMsc_ReceiveDataInterrupt         receiveDataInterrupt;               /**< \brief Specifies the Receive Interrupt Mode */
    IfxMsc_UpstreamTimeoutInterruptNode upstreamTimeoutInterruptNode;       /**< \brief Specifies the Upstream Timeout Interrupt Node */
    IfxMsc_UpstreamTimeoutInterrupt     upstreamTimeoutInterrupt;           /**< \brief Specifies the Upstream Timeout Interrupt Mode */
    IfxMsc_OverflowInterruptNode        overflowInterruptNode;              /**< \brief Specifies the ABRA Overflow Interrupt Node */
    IfxMsc_OverflowInterrupt            overflowInterrupt;                  /**< \brief Specifies the ABRA Overflow Interrupt Mode */
    IfxMsc_UnderflowInterruptNode       underflowInterruptNode;             /**< \brief Specifies the ABRA Underflow Interrupt Node */
    IfxMsc_UnderflowInterrupt           underflowInterrupt;                 /**< \brief Specifies the ABRA Underflow Interrupt Mode */
} IfxMsc_Msc_InterruptConfig;

/** \brief MSC Pin Configuration Structure
 */
typedef struct
{
    IfxMsc_Msc_fclp   fclp;				/**< \brief Specifies configuration for the MSC FCLP output pin */
    IfxMsc_Msc_fcln   fcln;				/**< \brief Specifies configuration for the MSC FCLN output pin */
    IfxMsc_Msc_sop    sop;				/**< \brief Specifies configuration for the MSC SOP output pin */
    IfxMsc_Msc_son    son;				/**< \brief Specifies configuration for the MSC SON output pin */
    IfxMsc_Msc_en     en0;				/**< \brief Specifies configuration for the MSC EN0 output pin */
    IfxMsc_Msc_en     en1;				/**< \brief Specifies configuration for the MSC en1 output pin */
    IfxMsc_Msc_en     en2;				/**< \brief Specifies configuration for the MSC en2 output pin */
    IfxMsc_Msc_en     en3;				/**< \brief Specifies configuration for the MSC en3 output pin */
    IfxMsc_Msc_sdi    sdi;				/**< \brief Specifies configuration for the MSC SDI input pin */
    IfxMsc_Msc_inj0   inj0;		 		/**< \brief Specifies configuration for the MSC INJ0 input pin */
    IfxMsc_Msc_inj1   inj1;				/**< \brief Specifies configuration for the MSC INJ1 input pin */
    IfxPort_PadDriver pinDriver;		/**< \brief Specifies pad driver configuration for all MSC pins */
} IfxMsc_Msc_Io;

/** \brief Output Control Configuration Structure
 */
typedef struct
{
    IfxMsc_FclLinePolarity        fclpPolarity;          /**< \brief Specifies the FCLP Polarity */
    IfxMsc_SoLinePolarity         sopPolarity;           /**< \brief Specifies the SLP Polarity */
    IfxMsc_ChipSelectActiveState  cslpPolarity;          /**< \brief Specifies the CSLP Polarity */
    IfxMsc_SdiLinePolarity        sdiLinePolarity;       /**< \brief Specifies the ILP Polarity */
    IfxMsc_FclClockControlEnabled fclClockControl;       /**< \brief Specifies the CLKCTRL Polarity */
} IfxMsc_Msc_OutputControlConfig;

/** \brief Upstream Control Configuration Structure
 */
typedef struct
{
    IfxMsc_UpstreamChannelFrameType     upstreamChannelFrameType;           /**< \brief Specifies the Upstream Channel Frame Type */
    IfxMsc_UpstreamChannelReceivingRate upstreamChannelReceivingRate;       /**< \brief Specifies the Upstream Channel Receiving Rate */
    IfxMsc_Parity                       parity;                             /**< \brief Specifies the Parity Mode */
    IfxMsc_ServiceRequestDelay          serviceRequestDelay;                /**< \brief Specifies the Service Request Delay */
    IfxMsc_UpstreamTimeoutPrescaler     upstreamTimeoutPrescaler;           /**< \brief Specifies the Upstream Timeout Prescaler */
    IfxMsc_UpstreamTimeoutValue         upstreamTimeoutValue;               /**< \brief Specifies the Upstream Timeout Value */
} IfxMsc_Msc_UpstreamStatusConfig;

/** \} */

/** \addtogroup IfxLld_Msc_Msc_Data_Structures
 * \{ */
/** \brief MSC base address data Structure
 */
typedef struct
{
    Ifx_MSC *msc;       /**< \brief Specifies the pointer to the MSC registers */
} IfxMsc_Msc;

/** \brief MSC Module Configuration Structure
 */
typedef struct
{
    Ifx_MSC                                    *msc;                                          /**< \brief Specifies the pointer to the MSC registers */
    IfxMsc_Msc_Clock                            clockConfig;                                  /**< \brief Specifies the Clock configuration */
    IfxMsc_Msc_UpstreamStatusConfig             upstreamConfig;                               /**< \brief Specifies the Upstream configuration */
    IfxMsc_Msc_InterruptConfig                  interruptConfig;                              /**< \brief Specifies the Interrupt configuration */
    IfxMsc_Msc_OutputControlConfig              outputControlConfig;                          /**< \brief Specifies the Output Control configuration */
    IfxMsc_Msc_DownstreamControlConfig          downstreamConfig;                             /**< \brief Specifies the Downstream configuration */
    IfxMsc_Msc_DownstreamControlExtensionConfig downstreamExtensionConfig;                    /**< \brief Specifies the Downstream Extension configuration */
    IfxMsc_Msc_Abra                             abraConfig;                                   /**< \brief Specifies the ABRA configuration */
    IfxMsc_Target                               target[IFXMSC_NUM_ENABLE_SELECT_LINES];       /**< \brief Specifies the Downstream targets */
    IfxMsc_Msc_Io                               io;                                           /**< \brief Specifies the IO Pin configuration */
    IfxMsc_Msc_CommandExtensionConfig           commandExtensionConfig;                       /**< \brief Configuration for CX mode. */
    IfxMsc_StreamMode                           streamMode;                                   /**< \brief Configuration for Stream mode (upstream or downstream) */
} IfxMsc_Msc_Config;

/** \} */

/** \addtogroup IfxLld_Msc_Msc_Module_Initialize_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief De-initializes the MSC module, releasing any allocated resources and resetting the module to its initial state.
 *
 * \param[inout] msc Pointer to the MSC module handle.
 *
 * \retval None
 *
 * \code
 *     IfxMsc_Msc_deInitModule(&msc);
 * \endcode
 */
IFX_EXTERN void IfxMsc_Msc_deInitModule(IfxMsc_Msc *msc);

/**
 * \brief Initializes the MSC module with the provided configuration.
 *
 * \param[inout] msc    Pointer to the MSC module handle.
 * \param[in]    config Pointer to the MSC module configuration structure.
 *                      This structure contains various configuration parameters such as clock settings,
 *                      interrupt & Output Control configurations, and upstream/downstream settings,
 *                      IO Pin & ABRA settings, downstream targets, and command extension configurations.
 *                      The configuration is used to tailor the MSC module's behavior to the application's requirements.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Msc_Msc_Usage
 */
IFX_EXTERN void IfxMsc_Msc_initModule(IfxMsc_Msc *msc, const IfxMsc_Msc_Config *config);

/**
 * \brief Initializes the MSC module configuration structure with default or user-provided settings.
 *
 * \param[inout] config Pointer to the MSC module configuration structure.
 *                      This structure contains various configuration parameters such as clock settings,
 *                      interrupt & Output Control configurations, and upstream/downstream settings,
 *                      IO Pin & ABRA settings, downstream targets, and command extension configurations.
 *                      The configuration is used to tailor the MSC module's behavior
 *                      to the application's requirements.
 * \param[in]    msc    Pointer to the base address of MSC registers.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Msc_Msc_Usage
 */
IFX_EXTERN void IfxMsc_Msc_initModuleConfig(IfxMsc_Msc_Config *config, Ifx_MSC *msc);

/**
 * \brief Initializes the ABRA (Asynchronous Baud Rate Adjustment Block) of the MSC module with the specified configuration.
 *
 * \param[inout] msc    Pointer to the MSC module handle.
 * \param[in] 	 config Pointer to the MSC module configuration structure.
 *                   	This structure contains various configuration parameters such as clock settings,
 *                   	interrupt & Output Control configurations, and upstream/downstream settings,
 *                   	IO Pin & ABRA settings, downstream targets, and command extension configurations.
 *                   	The configuration is used to tailor the MSC module's behavior
 *                   	to the application's requirements.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Msc_Msc_Usage
 */
IFX_EXTERN void IfxMsc_Msc_initializeAbra(IfxMsc_Msc *msc, const IfxMsc_Msc_Config *config);

/**
 * \brief Initializes the MSC data extension block for 64-bit operation.
 *
 * \param[inout] msc    Pointer to the MSC module handle.
 * \param[in] 	 config Pointer to the MSC module configuration.
 *                   	This structure contains various configuration parameters such as clock settings,
 *                   	interrupt & Output Control configurations, and upstream/downstream settings,
 *                   	IO Pin & ABRA settings, downstream targets, and command extension configurations.
 *                   	The configuration is used to tailor the MSC module's behavior
 *                   	to the application's requirements.
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_Msc_initializeDataExtension(IfxMsc_Msc *msc, const IfxMsc_Msc_Config *config);

/**
 * \brief Initializes the command extension for the MSC module.
 *
 * \param[inout] msc    Pointer to the MSC module handle.
 * \param[in]    config Pointer to the MSC module configuration.
 *                   	This structure contains various configuration parameters such as clock settings,
 *                   	interrupt & Output Control configurations, and upstream/downstream settings,
 *                   	IO Pin & ABRA settings, downstream targets, and command extension configurations.
 *                   	The configuration is used to tailor the MSC module's behavior
 *                   	to the application's requirements.
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_Msc_initializeCommandExtension(IfxMsc_Msc *msc, const IfxMsc_Msc_Config *config);

/** \} */

/** \addtogroup IfxLld_Msc_Msc_Send_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Send downstream command during command frames.
 *
 * \param[inout] msc 	Pointer to the MSC module handle.
 * \param[in] 	command Command to be transmitted.
 * 				      	Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_Msc_sendCommand(IfxMsc_Msc *msc, uint32 command);

/**
 * \brief Sends complete downstream data, combining high and low parts.
 *
 * \param[inout] msc      Pointer to the MSC module handle.
 * \param[in]    dataLow  Low 16-bit part of the data to be transmitted.
 * 					      Range: 0 to 0xFFFF
 * \param[in]    dataHigh High 16-bit part of the data to be transmitted.
 * 					      Range: 0 to 0xFFFF
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Msc_Msc_Usage
 */
IFX_EXTERN void IfxMsc_Msc_sendData(IfxMsc_Msc *msc, uint16 dataLow, uint16 dataHigh);

/**
 * \brief Sends a 64-bit downstream data extension using the specified MSC module handle.
 *
 * \param[inout] msc           Pointer to the MSC module handle.
 * \param[in]    data          The 32 bits of the 64-bit downstream data extension to be transmitted during data frames.
 * 					           Range: 0 to 0xFFFFFFFF
 * \param[in]    dataExtension The 32 bits of the 64-bit downstream data mirror to be transmitted.
 * 							   Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_Msc_sendDataExtension(IfxMsc_Msc *msc, uint32 data, uint32 dataExtension);

/**
 * \brief Sends high downstream data through the MSC module.
 *
 * \param[inout] msc  Pointer to the MSC module handle.
 * \param[in]    data High downstream data to be transmitted.
* 				      Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_Msc_sendDataHigh(IfxMsc_Msc *msc, uint16 data);

/**
 * \brief Sends low downstream data through the MSC module.
 *
 * \param[inout] msc  Pointer to the MSC module handle.
 * \param[in] 	 data Low downstream data to be transmitted.
 * 				      Range: 0 to 0xFFFF
 */
IFX_EXTERN void IfxMsc_Msc_sendDataLow(IfxMsc_Msc *msc, uint16 data);

/** \} */

/** \addtogroup IfxLld_Msc_Msc_Receive_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
* \brief Receive upstream data.
*
* \param[inout] msc 		Pointer to the MSC module handle.
* \param[in] 	upstreamIdx The index of the upstream data register ID for which the data is to be retrieved.
* 			 			 	Range : 0 to 0x3
*
* \retval uint32 Upstream data received.
* 		         Range: 0 to 0xFF
*/
IFX_EXTERN uint32 IfxMsc_Msc_receiveData(IfxMsc_Msc *msc, uint8 upstreamIdx);

/** \} */

/** \addtogroup IfxLld_Msc_Msc_Target_Read_Write_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the target value for the specified phase (high or low).
 *
 * \param[in] msc    Pointer to the MSC module handle.
 * \param[in] target Specifies the phase for which to get the target.
 * 					 Range: \ref IfxMsc_Msc_Target
 *
 * \retval IfxMsc_Target The selected target value based on the input phase.
 *						 Range: \ref IfxMsc_Target
 */
IFX_EXTERN IfxMsc_Target IfxMsc_Msc_getTarget(IfxMsc_Msc *msc, IfxMsc_Msc_Target target);

/**
 * \brief Set the command for target.
 *
 * \param[inout] msc pointer to the MSC module handle.
 * \param[in]    enX enX target to be selected.
 * 				     Range: \ref IfxMsc_Target
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_Msc_setCommandTarget(IfxMsc_Msc *msc, IfxMsc_Target enX);

/**
 * \brief Sets the target data to be transmitted during the high and low phases of the MSC module.
 *
 * \param[inout] msc     Pointer to the MSC module handle.
 * \param[in]    enXHigh Specifies the target to be selected during the high phase.
 * 					     Range: \ref IfxMsc_Target
 * \param[in]    enXLow  Specifies the target to be selected during the low phase.
 * 					     Range: \ref IfxMsc_Target
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_Msc_setDataTarget(IfxMsc_Msc *msc, IfxMsc_Target enXHigh, IfxMsc_Target enXLow);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the data frame interrupt status for the specified MSC module.
 *
 * \param[inout] msc Pointer to the MSC module handle.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_Msc_clearDataFrameInterrupt(IfxMsc_Msc *msc);

/**
 * \brief Gets the status of the active data frame for the specified MSC module.
 *
 * \param[in] msc Pointer to the MSC module handle.
 *
 * \retval boolean TRUE  If there is an active data frame.
 * 		           FALSE If there is no active data frame.
 */
IFX_INLINE boolean IfxMsc_Msc_getActiveDataFrameStatus(IfxMsc_Msc *msc);

/**
 * \brief Checks the status of the data frame interrupt for the MSC module.
 *
 * \param[in] msc Pointer to the MSC module handle.
 *
 * \retval boolean TRUE  If the data frame interrupt is currently active.
 *                 FALSE If the data frame interrupt is not active.
 */
IFX_INLINE boolean IfxMsc_Msc_getDataFrameInterruptStatus(IfxMsc_Msc *msc);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxMsc_Msc_clearDataFrameInterrupt(IfxMsc_Msc *msc)
{
    IfxMsc_clearDataFrameInterruptFlag(msc->msc);
}


IFX_INLINE boolean IfxMsc_Msc_getActiveDataFrameStatus(IfxMsc_Msc *msc)
{
    return IfxMsc_getActiveDataFrameStatus(msc->msc);
}


IFX_INLINE boolean IfxMsc_Msc_getDataFrameInterruptStatus(IfxMsc_Msc *msc)
{
    return IfxMsc_getDataFrameInterruptFlag(msc->msc);
}


#endif /* IFXMSC_MSC_H */
