#ifndef SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_H
#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_H

#include "../Comm/syncprotocol.h"

#if SYNCPROTOCOL_VARIANT == SYNCPROTOCOL_VARIANT_QT
#include <QtGlobal>
#include "pguiitem_oscilloscope_types.h"
#elif SYNCPROTOCOL_VARIANT == SYNCPROTOCOL_VARIANT_AURIX

#endif

#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CONTROL_CMD (0x1100)    /**< \see Oscilloscope_MessageControlCmd */
#if defined(__HIGHTEC__)
typedef struct __attribute__ ((__packed__))
#elif defined(__TASKING__)
typedef struct
#else
typedef struct
#endif
{
    float32 triggerLevel;
    uint32  depth;
    struct
    {
        /** Oscilloscope enable. 0=stopped, 1=running */
        uint16 enabled : 1;
        /** Trigger single. 0=continuous, 1=single */
        uint16 triggerSingle : 1;
        /** Trigger mode. 0=normal, 1=automatic, 1=inverted */
        uint16 triggerMode : 2;
        /** Trigger edge. 0=falling, 1=rising */
        uint16 triggerEdge : 2;
        uint16 reserved : 10;
    } flags;
    /** Sampling interval */
    uint16 samplingInterval;
    /** index of the channel used for the trigger */
    uint16 triggerChannel;
} Oscilloscope_MessageControlCmd;
#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CONTROL_CMD_SIZE (14)

#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_STATE (0x1101)    /**< \see Oscilloscope_MessageState */
#if defined(__HIGHTEC__)
typedef struct __attribute__ ((__packed__))
#elif defined(__TASKING__)
typedef struct
#else
typedef struct
#endif
{
    float32 triggerLevel;
    /** Sampling period in s */
    float32 samplingPeriod;
    uint32  maxDepth;
    uint32  depth;
    struct
    {
        /** Oscilloscope enable. 0=stopped, 1=running */
        uint16 enabled : 1;
        /** Trigger single. 0=continuous, 1=single */
        uint16 triggerSingle : 1;
        /** Trigger mode. 0=normal, 1=automatic, 1=inverted */
        uint16 triggerMode : 2;
        /** Trigger edge. 0=falling, 1=rising */
        uint16 triggerEdge : 2;
        /** Osci state. 1: armed, 2: triggered, 3:stopped, 4: data transfer, else undefined */
        uint16 state : 3;
        uint16 reserved : 7;
    } flags;
    /** Sampling interval */
    uint16 samplingInterval;
    /** index of the channel used for the trigger */
    uint16 triggerChannel;
    /** Number of available channeld */
    uint16 numberOfChannels;
    uint16 numberOfSignals;
} Oscilloscope_MessageState;
#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_STATE_SIZE (26)

#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_GET_STATE_REQ (0x1102)    /**< \see Oscilloscope_MessageGetStateCmd */
#if defined(__HIGHTEC__)
typedef struct __attribute__ ((__packed__))
#elif defined(__TASKING__)
typedef struct
#else
typedef struct
#endif
{
    /** Unused, must be 0 */
    uint32 reserved;
} Oscilloscope_MessageGetStateCmd;
#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_GET_STATE_REQ_SIZE (4)

#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_SIGNAL_INFO (0x1103)    /**< \see Oscilloscope_MessageSignalInfo */
#if defined(__HIGHTEC__)
typedef struct __attribute__ ((__packed__))
#elif defined(__TASKING__)
typedef struct
#else
typedef struct
#endif
{
    uint16 signalId;
    uint16 reserved[7];
    uint8  name[256];
} Oscilloscope_MessageSignalInfo;
#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_SIGNAL_INFO_SIZE (272)

#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_ASSIGN_CHANNEL_CMD (0x1105)    /**< \see Oscilloscope_MessageAssignChannel */
#if defined(__HIGHTEC__)
typedef struct __attribute__ ((__packed__))
#elif defined(__TASKING__)
typedef struct
#else
typedef struct
#endif
{
    uint16 channelId;
    uint16 signalId;
} Oscilloscope_MessageAssignChannel;
#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_ASSIGN_CHANNEL_CMD_SIZE (4)

#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_ASSIGNED_CHANNEL (0x1106)    /**< \see Oscilloscope_MessageAssignedChannel */
#if defined(__HIGHTEC__)
typedef struct __attribute__ ((__packed__))
#elif defined(__TASKING__)
typedef struct
#else
typedef struct
#endif
{
    uint16 channelId;
    uint16 signalId;
    uint32 dataDepth;
} Oscilloscope_MessageAssignedChannel;
#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_ASSIGNED_CHANNEL_CMD_SIZE (8)

#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CHANNEL_DATA (0x1109)         /**< \see Oscilloscope_MessageChannelData */
//#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CHANNEL_DATA_MAX_PAYLOAD (128)
#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CHANNEL_DATA_MAX_PAYLOAD (48) /* Pack in one frame*/
#if defined(__HIGHTEC__)
typedef struct __attribute__ ((__packed__))
#elif defined(__TASKING__)
typedef struct
#else
typedef struct
#endif
{
    uint16 channelId;
    uint16 signalId;
    struct
    {
        /* Set if transmission of a new set of data starts */
        uint16 dataLength : 8;
        uint16 newData : 1;
        uint16 reserved : 7;
    } flags;
    uint16  reserved;
    uint32  dataOffset;
    float32 data[SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CHANNEL_DATA_MAX_PAYLOAD];
} Oscilloscope_MessageChannelData;
//#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CHANNEL_DATA_SIZE (524)
#define SYNCPROTOCOL_MESSAGE_ID_OSCILLOSCOPE_CHANNEL_DATA_SIZE (204)

#endif
