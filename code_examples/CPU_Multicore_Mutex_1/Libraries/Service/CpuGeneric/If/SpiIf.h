/**
 * \file SpiIf.h
 * \brief SPI interface types
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:22 GMT$
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
 * \defgroup library_srvsw_if_spi SPI interface
 * \ingroup library_srvsw_if
 *
 */

#ifndef SPIIF_H
#define SPIIF_H 1

//________________________________________________________________________________________
// INCLUDES

#include "Src/Std/IfxSrc.h"     /* FIXME interface should not have dependencies to the HAL, an If type needs to be defined */

/** \addtogroup library_srvsw_if_spi
 * \{ */

//________________________________________________________________________________________
// CONFIGURATION SWITCHES

//________________________________________________________________________________________
// HELPER MACROS

//________________________________________________________________________________________
// BASIC TYPES

/** \brief SPI Interface Status */
typedef enum
{
    SpiIf_Status_ok,
    SpiIf_Status_busy,
    SpiIf_Status_unknown
} SpiIf_Status;

/** \brief Slave select output timing */
typedef enum
{
    SpiIf_SlsoTiming_0 = 0,             /**< zero delay clock */
    SpiIf_SlsoTiming_1,                 /**< 1 half-clock delay */
    SpiIf_SlsoTiming_2,                 /**< 2 half-clock delay */
    SpiIf_SlsoTiming_3,                 /**< 3 half-clock delay */
    SpiIf_SlsoTiming_4,                 /**< 4 half-clock delay */
    SpiIf_SlsoTiming_5,                 /**< 5 half-clock delay */
    SpiIf_SlsoTiming_6,                 /**< 6 half-clock delay */
    SpiIf_SlsoTiming_7                  /**< 7 half-clock delay */
} SpiIf_SlsoTiming;

/** \brief Heading */
typedef enum
{
    SpiIf_DataHeading_lsbFirst = 0,     /**< LSB first */
    SpiIf_DataHeading_msbFirst          /**< MSB first */
} SpiIf_DataHeading;

/** \brief Clock phase */
typedef enum
{
    SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge = 0,    /**< Shift Tx data on leading edge */
    SpiIf_ShiftClock_shiftTransmitDataOnTrailingEdge        /**< Shift Tx data on training edge */
} SpiIf_ShiftClock;

/** \brief Clock polarity */
typedef enum
{
    SpiIf_ClockPolarity_idleLow = 0,    /**< Idle clock line is low */
    SpiIf_ClockPolarity_idleHigh        /**< Idle clock line is high */
} SpiIf_ClockPolarity;

//________________________________________________________________________________________
// DATA STRUCTURES

/** \brief Alias to the channel structure */
typedef struct SpiIf_Ch_       SpiIf_Ch;
typedef struct SpiIf_ChConfig_ SpiIf_ChConfig;
typedef struct SpiIf_          SpiIf;

typedef volatile struct
{
    uint32 onTransfer : 1;              /**< \brief Channel status: On transfer */
    uint32 byteAccess : 1;              /**< \brief Channel status: 8bit / 16 bit access */
} SpiIf_Flags;

typedef struct
{
    void     *data;
    Ifx_SizeT remaining;
} SpiIf_Job;

/** SPI operation modes */
typedef enum
{                           /* FIXME check conflicts with IfxQspi_Mode */
    SpiIf_Mode_master,      /**< \brief Master mode */
    SpiIf_Mode_slave,       /**< \brief Slave mode */
    SpiIf_Mode_undefined    /**< \brief Undefined mode */
} SpiIf_Mode;

typedef SpiIf_Status (*SpiIf_Exchange)(SpiIf_Ch *handle, const void *src, void *dest, Ifx_SizeT numOfData);
typedef SpiIf_Status (*SpiIf_GetStatus)(SpiIf_Ch *handle);
typedef void         (*SpiIf_OnEvent)(SpiIf *handle);
typedef uint32 SpiIf_SlsoTiming_HalfTsclk; /* SPI slave select output delay - in half-clock (1/(2*baudrate)) units. */
                                           /* A value of 0 would set a delay of 1/Fqspi */

typedef struct
{
    SpiIf_Exchange  exchange;
    SpiIf_GetStatus getStatus;
    SpiIf_OnEvent   onTx;
    SpiIf_OnEvent   onRx;
    SpiIf_OnEvent   onError;
} SpiIf_funcs;

struct SpiIf_
{
    pvoid       driver;             /**< \brief Spi specific driver */
    uint32      sending;            /**< \brief */
    SpiIf_Ch   *activeChannel;      /**< \brief Channel actually transmitting / receiving */
    uint32      txCount;
    uint32      rxCount;
    SpiIf_funcs functions;
};

typedef struct
{
    SpiIf_Mode   mode;                  /**< \brief Specifies the interface operation mode */
    Ifx_Priority rxPriority;            /**< \brief Specifies the priority of the receive interrupt */
    Ifx_Priority txPriority;            /**< \brief Specifies the priority of the transmit interrupt */
    Ifx_Priority erPriority;            /**< \brief Specifies the priority of the error interrupt */
    IfxSrc_Tos   isrProvider;           /**< \brief Specifies the handler of the interrupts */
    Ifx_SizeT    bufferSize;            /**< \brief Specifies the number of channels that can be buffered. If 0, buffering is disabled */
    void        *buffer;                /**< \brief Specifies the buffer location.The buffer parameter must point on a free memory location where the
                                         *          buffer object will be initialised. The Size of this area must be at least
                                         *          equals to "Size + sizeof(Ifx_Fifo) + 8",
                                         *          with "Size=config->bufferSize * Ifx_AlignOn32(sizeof(Spi_Ch*))". Not tacking
                                         *          this in account may result in unpredictable behaviour. */
    float32 maximumBaudrate;            /**< \brief Maximum baudrate used by the channels, this value is used to optimise the SPI internal clock */
} SpiIf_Config;

typedef struct
{
    uint32 baudrate : 1;                /**< \brief TRUE = checked, FALSE = ignored */
    uint32 phase : 1;                   /**< \brief TRUE = checked, FALSE = ignored */
    uint32 receive : 1;                 /**< \brief TRUE = checked, FALSE = ignored */
    uint32 transmit : 1;                /**< \brief TRUE = checked, FALSE = ignored */
    uint32 reserved : 28;
} Spi_ErrorChecks;

/** Channel operation mode */
typedef struct
{
    uint32 enabled : 1;                 /**< \brief 1 = channel enabled, 0 = channel disabled */
    uint32 autoCS : 1;                  /**< \brief 1 = chip select is controlled by the hardware module or, 0 = by software. */
    uint32 loopback : 1;                /**< \brief 0 = normal mode, 1 = loopback mode */
    uint32 clockPolarity : 1;           /**< \brief \ref SpiIf_ClockPolarity*/
    uint32 shiftClock : 1;              /**< \brief \ref SpiIf_ShiftClock */
    uint32 dataHeading : 1;             /**< \brief \ref SpiIf_DataHeading */
    uint32 dataWidth : 6;               /**< \brief range 2 .. 32 bits (note 2 = 2-bits, 3 = 3-bits ... */

    uint32 csActiveLevel : 1;           /**< \brief \ref Ifx_ActiveState */

    uint32 parityCheck : 1;             /**< \brief 0 = disabled, 1 = enabled */
    uint32 parityMode : 1;              /**< \brief \ref Ifx_ParityMode */

    SpiIf_SlsoTiming_HalfTsclk  csInactiveDelay;         /**< \brief CS Inactive Delay in Tsclk/2 units */
    SpiIf_SlsoTiming_HalfTsclk  csLeadDelay;             /**< \brief CS Lead Delay in Tsclk/2 units */
    SpiIf_SlsoTiming_HalfTsclk  csTrailDelay;            /**< \brief CS Trail Delay in Tsclk/2 units */

} SpiIf_ChMode;

/** \brief SPI channel callback prototype */
typedef void (*SpiIf_Cbk)(void *data);
typedef void (*TxRxHandler)(SpiIf_Ch *handle);

struct SpiIf_Ch_
{
    SpiIf          *driver;         /**< \brief Pointer to the SPI interface driver */
    SpiIf_Flags     flags;
    Spi_ErrorChecks errorChecks;    /**< \brief Error checks */
    sint32          baudrate;       /**< \brief Real baudrate */
    SpiIf_Job       tx;
    SpiIf_Job       rx;
    SpiIf_Cbk       onExchangeEnd;  /**< \brief Specifies the callback function on end of exchange */
    void           *callbackData;   /**< \brief Specifies pointer to the user specific data on transmit end */
    TxRxHandler     txHandler;
    TxRxHandler     rxHandler;
};

struct SpiIf_ChConfig_
{
    SpiIf          *driver;         /**< \brief Pointer to an implementation of SPI interface driver, e.g. \ref IfxQspi_SpiMaster_ChannelConfig */
    float32         baudrate;       /**< \brief Specifies the SPI baudrate */
    SpiIf_ChMode    mode;           /**< \brief */
    Spi_ErrorChecks errorChecks;    /**< \brief */
};

//________________________________________________________________________________________
// EXPORTED VARIABLES

//________________________________________________________________________________________
// FUNCTION PROTOTYPES

IFX_INLINE void SpiIf_wait(SpiIf_Ch *handle);
IFX_EXTERN void SpiIf_initConfig(SpiIf_Config *config);
IFX_EXTERN void SpiIf_initChannelConfig(SpiIf_ChConfig *config, SpiIf *driver);

/** \name Virtual functions
 * These functions are implemented by a driver.
 * \{ */
IFX_INLINE SpiIf_Status SpiIf_exchange(SpiIf_Ch *handle, const void *src, void *dest, Ifx_SizeT numOfData);
IFX_INLINE SpiIf_Status SpiIf_getStatus(SpiIf_Ch *handle);
/** \} */

/** \} */
//________________________________________________________________________________________
// INLINE FUNCTION IMPLEMENTATIONS

/** Wait as long as the transmission is on-going
 * \note This function blocks CPU for some-time */
IFX_INLINE void SpiIf_wait(SpiIf_Ch *handle)
{
    while (handle->flags.onTransfer != FALSE)
    {}
}


/** Perform the SPI exchange operation.
 * \param handle Pointer to an implementation of SPI interface driver
 * \param src Pointer to the start of data buffer for data to transmit
 * \param dest Pointer to the start of data buffer for received data
 * \param numOfData specifies number of byte/bit to transfer
 * \return STATUS of SPI
 * \note the src and dest may be the same data location.
 */
IFX_INLINE SpiIf_Status SpiIf_exchange(SpiIf_Ch *handle, const void *src, void *dest, Ifx_SizeT numOfData)
{
    return handle->driver->functions.exchange(handle, src, dest, numOfData);
}


/** get the SPI status
 *  * \param handle Pointer to an implementation of SPI interface driver
 *  \return STATUS of SPI
 * */
IFX_INLINE SpiIf_Status SpiIf_getStatus(SpiIf_Ch *handle)
{
    return handle->driver->functions.getStatus(handle);
}


//________________________________________________________________________________________
#endif
