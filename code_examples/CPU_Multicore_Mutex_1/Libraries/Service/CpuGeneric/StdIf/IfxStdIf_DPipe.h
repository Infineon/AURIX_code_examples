/**
 * \file IfxStdIf_DPipe.h
 * \brief Standard interface: Data Pipe
 * \ingroup IfxStdIf
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:24 GMT$
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
 *
 * \defgroup library_srvsw_stdif_dpipe Standard interface: Data Pipe
 * \ingroup library_srvsw_stdif
 *
 * The standard interafce data pipe (DPipe) abstract the hardware used for data transfer. It provide, after proper initialization an hardware independant way to write
 * and read data to/from as communciation channel.
 *
 * \par Porting StandardIo to DPipe
 * replace all
 *  - StandardIo type with IfxStdIf_DPipe
 *  - StandardIo_print with IfxStdIf_DPipe_print
 * delete StandardIo.c and StandardIo.h
 * Include "StdIf/IfxStdIf_DPipe.h" instead of "SysSe/Bsp/StandardIo.h"
 *
 * The following files are already ported: Ifx_Console, Ifx_Shell
 *
 */
#ifndef STDIF_DPIPE_H_
#define STDIF_DPIPE_H_ 1

#include "IfxStdIf.h"
//----------------------------------------------------------------------------------------
#ifndef ENDL
#    define ENDL       "\r\n"
#endif

/** \brief Forward declaration */
typedef struct IfxStdIf_DPipe_ IfxStdIf_DPipe;

typedef volatile boolean      *IfxStdIf_DPipe_WriteEvent;
typedef volatile boolean      *IfxStdIf_DPipe_ReadEvent;

/** \brief Size of the buffer allocated on the stack for the print function */
#define STDIF_DPIPE_MAX_PRINT_SIZE (255)

/** \brief Write binary data into the \ref IfxStdIf_DPipe.
 *
 * Initially the parameter 'count' specifies count of data to write.
 * After execution the data pointed by 'count' specifies the data actually written
 *
 * \param stdif Pointer to the interface driver object
 * \param data Pointer to the start of data
 * \param count Pointer to the count of data (in bytes).
 * \param timeout in system timer ticks
 *
 * \retval TRUE Returns TRUE if all items could be written
 * \retval FALSE Returns FALSE if not all the items could be written
 */
typedef boolean (*IfxStdIf_DPipe_Write)(IfxStdIf_InterfaceDriver stdif, void *data, Ifx_SizeT *count, Ifx_TickTime timeout);

/** \brief Read data from the \ref IfxStdIf_DPipe object
 *
 * Initially the parameter 'count' specifies count of data to read.
 * After execution the data pointed by 'count' specifies the data actually read.
 *
 * \param stdif Pointer to the interface driver object
 * \param data Pointer to the start of data
 * \param count Pointer to the count of data (in bytes).
 * \param timeout in system timer ticks
 *
 * \retval TRUE Returns TRUE if all items could be read
 * \retval FALSE Returns FALSE if not all the items could be read
 */
typedef boolean (*IfxStdIf_DPipe_Read)(IfxStdIf_InterfaceDriver stdif, void *data, Ifx_SizeT *count, Ifx_TickTime timeout);

/** \brief Returns the number of bytes in the rx buffer
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return Returns the number of bytes in the rx buffer
 */
typedef sint32 (*IfxStdIf_DPipe_GetReadCount)(IfxStdIf_InterfaceDriver stdif);

/** \brief Returns read event object
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return Returns read event object
 */
typedef IfxStdIf_DPipe_ReadEvent (*IfxStdIf_DPipe_GetReadEvent)(IfxStdIf_InterfaceDriver stdif);

/** \brief Returns number of bytes send
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return Returns number of bytes send
 */
typedef uint32 (*IfxStdIf_DPipe_GetSendCount)(IfxStdIf_InterfaceDriver stdif);

/** \brief Returns the time stamp of the last transmit data
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return Returns the time stamp of the last transmit data
 */
typedef Ifx_TickTime (*IfxStdIf_DPipe_GetTxTimeStamp)(IfxStdIf_InterfaceDriver stdif);

/** \brief Returns the number of free bytes (free space) in the tx buffer
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return Returns the number of free bytes in the tx buffer
 */
typedef sint32 (*IfxStdIf_DPipe_GetWriteCount)(IfxStdIf_InterfaceDriver stdif);

/** \brief Returns write event object
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return Returns write event object
 */
typedef IfxStdIf_DPipe_WriteEvent (*IfxStdIf_DPipe_GetWriteEvent)(IfxStdIf_InterfaceDriver stdif);

/** \brief Indicates if the required number of bytes are available for read in the buffer
 *
 * \param stdif Pointer to the interface driver object
 * \param count Pointer to the count of data (in bytes).
 * \param timeout in system timer ticks
 *
 * \return Returns TRUE if at least count bytes are available for read in the rx buffer,
 * if not the Event is armed to be set when the buffer count is bigger or equal to the requested count
 */
typedef boolean (*IfxStdIf_DPipe_CanReadCount)(IfxStdIf_InterfaceDriver stdif, Ifx_SizeT count, Ifx_TickTime timeout);

/** \brief  Indicates if there is enough free space to write the data in the buffer
 *
 * \param stdif Pointer to the interface driver object
 * \param count Pointer to the count of data (in bytes).
 * \param timeout in system timer ticks
 *
 * \return Returns TRUE if at least count bytes can be written to the tx buffer,
 *  if not the Event is armed to be set when the buffer free count is bigger or equal to the requested count
 */
typedef boolean (*IfxStdIf_DPipe_CanWriteCount)(IfxStdIf_InterfaceDriver stdif, Ifx_SizeT count, Ifx_TickTime timeout);

/** \brief Flush the transmit buffer by transmitting all data
 *
 * \param stdif Pointer to the interface driver object
 * \param timeout timeout for the flush operation
 *
 * \return Returns TRUE if the FIFO is empty
 */
typedef boolean (*IfxStdIf_DPipe_FlushTx)(IfxStdIf_InterfaceDriver stdif, Ifx_TickTime timeout);

/** \brief Clears the RX buffer by removing all data
 *
 * \param stdif Pointer to the interface driver object
 * \return void
 */
typedef void (*IfxStdIf_DPipe_ClearRx)(IfxStdIf_InterfaceDriver stdif);

/** \brief Clears the TX buffer by removing all data
 *
 * \param stdif Pointer to the interface driver object
 * \return void
 */
typedef void (*IfxStdIf_DPipe_ClearTx)(IfxStdIf_InterfaceDriver stdif);

/** \brief handler called on reveive event
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return none
 */
typedef void (*IfxStdIf_DPipe_OnReceive)(IfxStdIf_InterfaceDriver stdif);
/** \brief handler called on transmit event
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return none
 */
typedef void (*IfxStdIf_DPipe_OnTransmit)(IfxStdIf_InterfaceDriver stdif);
/** \brief handler called on error event
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return none
 */
typedef void (*IfxStdIf_DPipe_OnError)(IfxStdIf_InterfaceDriver stdif);
/** \brief Reset the sendCount counter
 *
 * \param stdif Pointer to the interface driver object
 *
 * \return none
 */
typedef void (*IfxStdIf_DPipe_ResetSendCount)(IfxStdIf_InterfaceDriver stdif);

/** \brief Standard interface object
 */
struct IfxStdIf_DPipe_
{
    IfxStdIf_InterfaceDriver driver;              /**< \brief Pointer to the specific driver object */
    boolean                  txDisabled;          /**< \brief If disabled is set to TRUE, the output is disabled, else enabled */

    /* Standard interface APIs */
    IfxStdIf_DPipe_Write          write;          /**< \brief \see IfxStdIf_DPipe_Write */
    IfxStdIf_DPipe_Read           read;           /**< \brief \see IfxStdIf_DPipe_Read */
    IfxStdIf_DPipe_GetReadCount   getReadCount;   /**< \brief \see IfxStdIf_DPipe_GetReadCount */
    IfxStdIf_DPipe_GetReadEvent   getReadEvent;   /**< \brief \see IfxStdIf_DPipe_GetReadEvent */
    IfxStdIf_DPipe_GetWriteCount  getWriteCount;  /**< \brief \see IfxStdIf_DPipe_GetWriteCount */
    IfxStdIf_DPipe_GetWriteEvent  getWriteEvent;  /**< \brief \see IfxStdIf_DPipe_GetWriteEvent */
    IfxStdIf_DPipe_CanReadCount   canReadCount;   /**< \brief \see IfxStdIf_DPipe_CanReadCount */
    IfxStdIf_DPipe_CanWriteCount  canWriteCount;  /**< \brief \see IfxStdIf_DPipe_CanWriteCount */
    IfxStdIf_DPipe_FlushTx        flushTx;        /**< \brief \see IfxStdIf_DPipe_FlushTx */
    IfxStdIf_DPipe_ClearTx        clearTx;        /**< \brief \see IfxStdIf_DPipe_ClearTx */
    IfxStdIf_DPipe_ClearRx        clearRx;        /**< \brief \see IfxStdIf_DPipe_ClearRx */
    IfxStdIf_DPipe_OnReceive      onReceive;      /**< \brief \see IfxStdIf_DPipe_OnReceive  */
    IfxStdIf_DPipe_OnTransmit     onTransmit;     /**< \brief \see IfxStdIf_DPipe_OnTransmit */
    IfxStdIf_DPipe_OnError        onError;        /**< \brief \see IfxStdIf_DPipe_OnError    */

    IfxStdIf_DPipe_GetSendCount   getSendCount;   /**< \brief \see IfxStdIf_DPipe_GetSendCount    */
    IfxStdIf_DPipe_GetTxTimeStamp getTxTimeStamp; /**< \brief \see IfxStdIf_DPipe_GetTxTimeStamp    */
    IfxStdIf_DPipe_ResetSendCount resetSendCount; /**< \brief \see IfxStdIf_DPipe_ResetSendCount    */
};
/** \addtogroup library_srvsw_stdif_dpipe
 * \{ */
/** \copydoc IfxStdIf_DPipe_Write
 */
IFX_INLINE boolean IfxStdIf_DPipe_write(IfxStdIf_DPipe *stdif, void *data, Ifx_SizeT *count, Ifx_TickTime timeout)
{
    return stdif->write(stdif->driver, data, count, timeout);
}


/** \copydoc IfxStdIf_DPipe_Read
 */
IFX_INLINE boolean IfxStdIf_DPipe_read(IfxStdIf_DPipe *stdif, void *data, Ifx_SizeT *count, Ifx_TickTime timeout)
{
    return stdif->read(stdif->driver, data, count, timeout);
}


/** \copydoc IfxStdIf_DPipe_GetReadCount
 */
IFX_INLINE sint32 IfxStdIf_DPipe_getReadCount(IfxStdIf_DPipe *stdif)
{
    return stdif->getReadCount(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_GetWriteCount
 */
IFX_INLINE sint32 IfxStdIf_DPipe_getWriteCount(IfxStdIf_DPipe *stdif)
{
    return stdif->getWriteCount(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_CanReadCount
 */
IFX_INLINE boolean IfxStdIf_DPipe_canReadCount(IfxStdIf_DPipe *stdif, Ifx_SizeT count, Ifx_TickTime timeout)
{
    return stdif->canReadCount(stdif->driver, count, timeout);
}


/** \copydoc IfxStdIf_DPipe_CanWriteCount
 */
IFX_INLINE boolean IfxStdIf_DPipe_canWriteCount(IfxStdIf_DPipe *stdif, Ifx_SizeT count, Ifx_TickTime timeout)
{
    return stdif->canWriteCount(stdif->driver, count, timeout);
}


/** \copydoc IfxStdIf_DPipe_GetReadEvent
 */
IFX_INLINE IfxStdIf_DPipe_ReadEvent IfxStdIf_DPipe_getReadEvent(IfxStdIf_DPipe *stdif)
{
    return stdif->getReadEvent(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_GetWriteEvent
 */
IFX_INLINE IfxStdIf_DPipe_WriteEvent IfxStdIf_DPipe_getWriteEvent(IfxStdIf_DPipe *stdif)
{
    return stdif->getWriteEvent(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_FlushTx
 */
IFX_INLINE boolean IfxStdIf_DPipe_flushTx(IfxStdIf_DPipe *stdif, Ifx_TickTime timeout)
{
    return stdif->flushTx(stdif->driver, timeout);
}


/** \copydoc IfxStdIf_DPipe_ClearTx
 */
IFX_INLINE void IfxStdIf_DPipe_clearTx(IfxStdIf_DPipe *stdif)
{
    stdif->clearTx(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_ClearRx
 */
IFX_INLINE void IfxStdIf_DPipe_clearRx(IfxStdIf_DPipe *stdif)
{
    stdif->clearRx(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_OnReceive
 */
IFX_INLINE void IfxStdIf_DPipe_onReceive(IfxStdIf_DPipe *stdif)
{
    stdif->onReceive(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_OnTransmit
 */
IFX_INLINE void IfxStdIf_DPipe_onTransmit(IfxStdIf_DPipe *stdif)
{
    stdif->onTransmit(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_OnError
 */
IFX_INLINE void IfxStdIf_DPipe_onError(IfxStdIf_DPipe *stdif)
{
    stdif->onError(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_GetSendCount
 */
IFX_INLINE uint32 IfxStdIf_DPipe_getSendCount(IfxStdIf_DPipe *stdif)
{
    return stdif->getSendCount(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_GetTxTimeStamp
 */
IFX_INLINE Ifx_TickTime IfxStdIf_DPipe_getTxTimeStamp(IfxStdIf_DPipe *stdif)
{
    return stdif->getTxTimeStamp(stdif->driver);
}


/** \copydoc IfxStdIf_DPipe_ResetSendCount
 */
IFX_INLINE void IfxStdIf_DPipe_resetSendCount(IfxStdIf_DPipe *stdif)
{
    stdif->resetSendCount(stdif->driver);
}


IFX_EXTERN void IfxStdIf_DPipe_print(IfxStdIf_DPipe *stdif, pchar format, ...);

/** \} */
//----------------------------------------------------------------------------------------

#endif /* STDIF_DPIPE_H_ */
