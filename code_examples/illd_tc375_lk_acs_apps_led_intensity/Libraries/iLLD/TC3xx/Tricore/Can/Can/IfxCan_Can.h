/**
 * \file IfxCan_Can.h
 * \brief CAN CAN details
 * \ingroup IfxLld_Can
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
 *
 * \defgroup IfxLld_Can_Can_Usage How to use the CAN Interface driver?
 * \ingroup IfxLld_Can
 *
 * The CAN interface driver provides a default configuration for various modes.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Can_Can_Preparation Preparation
 * \subsection IfxLld_Can_Can_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 *     #include <Can/Can/IfxCan_Can.h>
 * \endcode
 *
 * \subsection IfxLld_Can_Can_Variables Variables
 *
 * Declare the CAN handles as global variables in your C code:
 * \code
 *
 * #define TESTED_NODES 2
 * #define NODE0_RAM_OFFSET 0x0
 * #define NODE1_RAM_OFFSET 0x1000
 *
 *     // CAN handle
 *     IfxCan_Can can;
 *
 *     // CAN Node handles
 *     IfxCan_Can_Node canNode[TESTED_NODES];
 *
 *     // data buffers
 *     uint32 txData[2];
 *     uint32 rxData[2];
 *
 * \endcode
 *
 * \subsection IfxLld_Can_Can_Init Module Initialisation
 *
 * The module initialisation can be done as followed:
 * \code
 *     // create module configuration
 *     IfxCan_Can_Config canConfig;
 *     IfxCan_Can_initModuleConfig(&canConfig, &MODULE_CAN0);
 *
 *     // choose the interrupt groups configuration
 *     // Tx interrupts
 *     canConfig.traco.priority = 10;
 *     canConfig.traco.typeOfService = IfxSrc_Tos_cpu0;
 *     canConfig.traco.interruptLine = IfxCan_InterruptLine_0;
 *
 *     // Rx interrupts
 *     canConfig.reint.priority = 11;
 *     canConfig.reint.typeOfService = IfxSrc_Tos_cpu0;
 *     canConfig.reint.interruptLine = IfxCan_InterruptLine_1;
 *
 *     // initialize module
 *     // IfxCan_Can can; // defined globally
 *     IfxCan_Can_initModule(&can, &canConfig);
 * \endcode
 *
 * Note: Application should explicitly configure the system DMA, if system DMA is selected as the service provider for the interrupt.
 *
 * \subsection IfxLld_Can_Can_Init_Node Node Initialisation
 *
 * The Node initialisation can be done as followed:
 * \code
 *     // create node configuration
 *     //Regarding messageRAM address offsets:
 *     //1. The baseAddress will point to module's start address from the handle.
 *     //.baseAddress                    =(uint32)(can->can),
 *     //2. All Other offsets in messageRAM must be uniquely calculated for each node based on number of elements of each section. This application needs to perform after call to initNodeConfig.
 *
 *     // Node 0 as receive node
 *     {
 *         IfxCan_Can_NodeConfig nodeConfig;
 *         IfxCan_Can_initNodeConfig(&nodeConfig, &can);
 *
 *         // initialize Node 0
 *         nodeConfig.nodeId = IfxCan_NodeId_0;
 *         nodeConfig.clockSource = IfxCan_ClockSource_both;
 *
 *         nodeConfig.frame.type = IfxCan_FrameType_receive;
 *
 *         nodeConfig.filterConfig.messageIdLength = IfxCan_MessageIdLength_both;
 *         nodeConfig.filterConfig.extendedListSize = 1;
 *         nodeConfig.filterConfig.standardListSize = 1;
 *
 *         nodeConfig.messageRAM.extendedFilterListStartAddress = 0x80  + NODE0_RAM_OFFSET;
 *         nodeConfig.messageRAM.standardFilterListStartAddress = 0x100 + NODE0_RAM_OFFSET;
 *         nodeConfig.messageRAM.rxBuffersStartAddress          = 0x200 + NODE0_RAM_OFFSET;
 *         //nodeConfig.messageRAM.baseAddress                    = MODULE_CAN0_RAM;// No longer needed, driver derives it from module handle. Check line .baseAddress = (uint32)(can->can),
 *
 *      // enable the required interrupts with respective to group interrupts configuration at module level
 *      nodeConfig.interruptConfig.messageStoredToDedicatedRxBufferEnabled = TRUE;
 *
 *         // initialize Node 0
 *         IfxCan_Can_initNode(&canNode[0], &nodeConfig);
 *     }
 *
 *     // Node 1 as transmit node
 *     {
 *         IfxCan_Can_NodeConfig nodeConfig;
 *         IfxCan_Can_initNodeConfig(&nodeConfig, &can);
 *
 *         nodeConfig.nodeId = IfxCan_NodeId_1;
 *         nodeConfig.clockSource = IfxCan_ClockSource_both;
 *
 *         nodeConfig.frame.type = IfxCan_FrameType_transmit;
 *
 *         nodeConfig.txConfig.dedicatedTxBuffersNumber = 2;
 *
 *         nodeConfig.messageRAM.txBuffersStartAddress = 0x400 + NODE1_RAM_OFFSET;
 *         //nodeConfig.messageRAM.baseAddress           = MODULE_CAN0_RAM;// No longer needed, driver derives it from module handle. Check line .baseAddress = (uint32)(can->can),
 *
 *         // enable the required interrupts with respective to group interrupts configuration at module level
 *         nodeConfig.interruptConfig.transmissionCompletedEnabled = TRUE;
 *
 *         // initialize Node 1;
 *         IfxCan_Can_initNode(&canNode[1], &nodeConfig);
 *     }
 * \endcode
 *
 * \subsection IfxLld_Can_Can_Alternate_Node_Initialization Alternative Node Initialization Method
 *
 * Alternatively the node can be initialized using APIs as shown in the following example sequence given below for receive Node 0:
 *
 * \code
 *     // Node 0 as receive node
 *	   {
 *         IfxCan_Can_NodeConfig nodeConfig;
 *         IfxCan_Can_initNodeConfig(&nodeConfig, &canBasic.drivers.can[0]);
 *
 *         // Update the configuration (clockSource, messageRAM, baudRate, fastBaudRate, frame, rxConfig, filterConfig, Rx pins, busLoopbackEnabled, interruptConfig) as per requirement
 *
 *         nodeConfig.nodeId = IfxCan_NodeId_0;
 *         nodeConfig.clockSource = IfxCan_ClockSource_both;
 *
 *         nodeConfig.frame.type = IfxCan_FrameType_receive;
 *         nodeConfig.frame.mode = IfxCan_FrameMode_standard;
 *         nodeConfig.baudrate.baudrate      = 500000;
 *
 *         nodeConfig.filterConfig.messageIdLength = IfxCan_MessageIdLength_both;
 *         nodeConfig.filterConfig.extendedListSize = 1;
 *         nodeConfig.filterConfig.standardListSize = 1;
 *
 *         nodeConfig.messageRAM.extendedFilterListStartAddress = 0x80  + NODE0_RAM_OFFSET;
 *         nodeConfig.messageRAM.standardFilterListStartAddress = 0x100 + NODE0_RAM_OFFSET;
 *         nodeConfig.messageRAM.rxBuffersStartAddress          = 0x200 + NODE0_RAM_OFFSET;
 *         nodeConfig.messageRAM.baseAddress                    = (uint32)&MODULE_CAN0;
 *
 *         IfxCan_Can_Pins pins;
 *         pins.rxPin = &IfxCan_RXD00B_P20_7_IN;
 *         pins.rxPinMode = IfxPort_InputMode_pullUp;
 *         pins.txPin = &IfxCan_TXD00_P20_8_OUT;
 *         pins.txPinMode = IfxPort_OutputMode_pushPull;
 *         pins.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed2;
 *         nodeConfig.pins = &pins;
 *
 *         // For interrupt configuration user needs to configure the priority and select one of the 16 interrupt lines
 *         nodeConfig.interruptConfig.messageStoredToDedicatedRxBufferEnabled = TRUE;
 *         nodeConfig.interruptConfig.reint.priority = ISR_PRIORITY_CAN0_RX ;
 *         nodeConfig.interruptConfig.reint.interruptLine =  IfxCan_InterruptLine_14;
 *         nodeConfig.interruptConfig.reint.typeOfService = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());
 *
 *         // Initialization sequence for Node 0
 *         IfxCan_Can_Node *nodeRx = &canNode[0];
 *         IfxCan_Can_NodeConfig *config = &nodeConfig;
 *         Ifx_CAN   *canSfr  = config->can;
 *         node->can          = canSfr;
 *
 *         Ifx_CAN_N *nodeSfr = IfxCan_getNodePointer(canSfr, config->nodeId);
 *         node->node         = nodeSfr;
 *
 * 		   // CAN Node clock configuration
 *         IfxCan_Can_initNodeClk(nodeRx, config->can, config->nodeId, config->clockSource);
 *         // Configures the message RAM handle
 * 		   IfxCan_Can_configureNodeMessageRamHandle(nodeRx, &config->messageRAM);
 * 	       //CAN Node baudrate
 * 		   IfxCan_Can_configureBaudrate(nodeRx, &config->baudRate, &config->fastBaudRate, config->calculateBitTimingValues, config->frame.mode);
 * 		   // Receive frame configuration for the CAN node
 * 	       IfxCan_Can_configureRx(nodeRx, &config->frame, &config->rxConfig);
 *         // Configures the acceptance filter for a CAN node
 *         IfxCan_Can_configureFilter(nodeRx, &config->frame, &config->filterConfig);
 *         // Configures the CAN Rx pins
 *         boolean status = IfxCan_Can_configurePins(nodeRx, config->pins);
 *         // Configures interrupt groups configuration
 *         IfxCan_Can_configureInterrupt(nodeRx, &config->interruptConfig);
 *
 *         // Transmit node initialization is also done in the same way as above.
 *         // For configuring the transmit frame configuration for the CAN node use the API:
 *         // IfxCan_Can_configureTx(nodeTx, &config->frame, &config->txConfig);
 *
 *         // For configuring loopback mode, use API : IfxCan_Can_configureLoopbackMode(nodeTx, config->busLoopbackEnabled);
 *     }
 *
 * \endcode
 *
 * \subsection IfxLld_Can_Can_filter Filter Initialisation
 *
 * The filters can be set as following, number of filters can be chosen from nodeConfig.filterConfig.standardListSize or nodeConfig.filterConfig.extendedListSize\n
 * based on the type of filter in the receive node configuration
 *
 * \code
 *     // set filters
 *
 *     // Standard Filter 
 *     // set filter for Rx Buffer 0
 *     {
 *         // Initialize the filter structure
 *         IfxCan_Filter filter;
 *
 *         filter.number = 0;
 *         filter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxBuffer;
 *         filter.id1 = 0x00;
 *         filter.rxBufferOffset = IfxCan_RxBufferId_0;
 *
 *         IfxCan_Can_setStandardFilter(&canNode[0], &filter);
 *     }
 *
 *     // Extended Filter 
 *     // set filter for rxBuffer 1
 *     {
 *          IfxCan_Filter filter;
 *
 *          filter.number = 0;
 *          filter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxBuffer;
 *          filter.id1 = 0x01;
 *          filter.rxBufferOffset = IfxCan_RxBufferId_1;
 *
 *          IfxCan_Can_setExtendedFilter(&canNode[0], &filter);
 *     }
 * \endcode
 *
 * \subsection IfxLld_Can_Can_Synch Nodes Synchronization
 * wait until the Node (M_CAN) is synchronised
 *
 * \code
 *     while (IfxCan_Can_isNodeSynchronized(&canNode[0]) != TRUE);
 *     while (IfxCan_Can_isNodeSynchronized(&canNode[1]) != TRUE);
 * \endcode
 *
 * The CAN is ready for use now!
 *
 * \section IfxLld_Can_Can_StandardDataTransfers Standard Data Transfers
 *
 * The CAN driver provides simple to use transfer functions
 *
 * Data can be sent by the following way:
 * \code
 *
 *     //data that needs to be transmitted
 *     txData[0] = 0xC0CAC01A;
 *     txData[1] = 0xBA5EBA11;
 *
 *     // Initialise the message strcture with defualt values
 *     IfxCan_Message txMsg;
 *     IfxCan_Can_initMessage(&txMsg);
 *
 *     // change the relevent members of message structure
 *     txMsg.bufferNumber = 0;
 *     txMsg.messageId = 0x0;
 *
 *     // Transmit Data
 *     while( IfxCan_Can_sendMessage(&canNode[1], &txMsg, txData) == IfxCan_Status_notSentBusy );
 * \endcode
 *
 * Data can be received by the following way:
 * \code
 *     // Receiving Data
 *
 *     // Initial Rx values. It should be replaced by the received values
 *     rxData[0] = 0xdeaddead;
 *     rxData[1] = 0xdeaddead;
 *
 *     // Initialise the message structure with default values, will be replaced by the received values
 *     IfxCan_Message rxMsg;
 *     IfxCan_Can_initMessage(&rxMsg);
 *
 *     // specify the rx buffer number where the data will be received based on the filter configuration
 *     rxMsg.bufferNumber = 0;
 *
 *     // wait until node receives the data
 *     while ((IfxCan_Can_isNewDataReceived(&canNode[0], (IfxCan_RxBufferId)rxMsg.bufferNumber)) == 0)
 *     { }
 *
 *     // read message
 *     IfxCan_Can_readMessage(&canNode[0], &rxMsg, rxData);
 *
 *     // data is now available at rxData[0] and rxData[1]
 * \endcode
 *
 * \section IfxLld_Can_Can_FDTransfers FD Transfers
 *
 * CAN driver supports FD transfers both long frame trasfers and long & fast frame transfers,
 * FD transfers has to be selected in the node initialisation phase
 *
 * define data buffers globally
 *
 * \code
 *     uint32 txData[16];
 *     uint32 rxData[16];
 * \endcode
 *
 * FD initialisation can be done as followed at node level after initialising the module
 * please refer to Module Initialisation subsection previously
 *
 * \code
 *     // create node configuration
 *
 *     // Node 0 as receive node
 *     {
 *         IfxCan_Can_NodeConfig nodeConfig;
 *         IfxCan_Can_initNodeConfig(&nodeConfig, &can);
 *
 *         // initialize Node 0
 *         nodeConfig.nodeId = IfxCan_NodeId_0;
 *         nodeConfig.clockSource = IfxCan_ClockSource_both;
 *
 *         nodeConfig.frame.type = IfxCan_FrameType_receive;
 *         nodeConfig.frame.mode = IfxCan_FrameMode_fdLong;          // incase of long and fast frames choose IfxCan_FrameMode_fdLongAndFast
 *
 *         nodeConfig.rxConfig.rxBufferDataFieldSize = IfxCan_DataFieldSize_64;   // choose the data field size to allocate rx elements in th emessage RAM
 *                                                                                                  // this is not the data length (DLC) of the message
 *
 *         nodeConfig.filterConfig.standardListSize = 2;
 *
 *         nodeConfig.messageRAM.standardFilterListStartAddress = 0x100 + NODE0_RAM_OFFSET;
 *         nodeConfig.messageRAM.rxBuffersStartAddress          = 0x200 + NODE0_RAM_OFFSET;
 *         //nodeConfig.messageRAM.baseAddress                    = MODULE_CAN0_RAM ; // No longer needed, driver derives it from module handle. Check line .baseAddress = (uint32)(can->can),
 *
 *         // initialize Node 0
 *         IfxCan_Can_initNode(&canNode[0], &nodeConfig);
 *     }
 *
 *     // Node 1 as transmit node
 *     {
 *         IfxCan_Can_NodeConfig nodeConfig;
 *         IfxCan_Can_initNodeConfig(&nodeConfig, &can);
 *
 *         nodeConfig.nodeId = IfxCan_NodeId_1;
 *         nodeConfig.clockSource = IfxCan_ClockSource_both;
 *
 *         nodeConfig.frame.type = IfxCan_FrameType_transmit;
 *         nodeConfig.frame.mode = IfxCan_FrameMode_fdLong;               // incase of long and fast frames choose IfxCan_FrameMode_fdLongAndFast
 *                                                                                                          // it can also be standard frame when the receive node is configured into FD mode
 *
 *         nodeConfig.txConfig.dedicatedTxBuffersNumber = 2;
 *         nodeConfig.txConfig.txBufferDataFieldSize = IfxCan_DataFieldSize_64;   // choose the data field size to allocate tx elements in the message RAM
 *                                                                                                                     // this is not the data length (DLC) of the message
 *
 *         nodeConfig.messageRAM.txBuffersStartAddress = 0x400 + NODE1_RAM_OFFSET;
 *         //nodeConfig.messageRAM.baseAddress           = MODULE_CAN0_RAM ; // No longer needed, driver derives it from module handle. Check line .baseAddress = (uint32)(can->can),
 *
 *         // initialize Node 1;
 *         IfxCan_Can_initNode(&canNode[1], &nodeConfig);
 *     }
 * \endcode
 *
 * filter configuration can be set using IfxCan_Can_setStandardFilter function, please refer to Filter Initialisation subsection previously
 *
 * then wait for the nodes to be synchronized, before sending and receiving, please refer to Nodes Synchronization subsection previously
 *
 * data can be sent and received similarly as standard data transfers except the FD configuration,
 * choose the FD related configuration accordingly in the message structure before sending and receiving
 *
 * transmit example
 *
 * \code
 *     //data that needs to be transmitted
 *     int i;
 *     for (i = 0; i<8; i++)
 *     {
 *         // uint32 txData[16]; //defined globally
 *         txData[i] = 0x11223300 + i;
 *     }
 *
 *     // Initialise the message structure with defualt values
 *     IfxCan_Message txMsg;
 *     IfxCan_Can_initMessage(&txMsg);
 *
 *     // change the relevent members of the message structure
 *     txMsg.bufferNumber = 1;
 *     txMsg.messageId = 0x7ff;
 *     txMsg.dataLengthCode = IfxCan_DataLengthCode_32;     // accordingly txData array is loaded upto txData[8]
 *                       // so it doesn't always have to be 64 bytes, it can be changed in the run time
 *     txMsg.frameMode = IfxCan_FrameMode_fdLong;
 *
 *     // Transmit Data
 *     while( IfxCan_Can_sendMessage(&canNode[1], &txMsg, txData) == IfxCan_Status_notSentBusy );
 * \endcode
 *
 * Receiving Data
 *
 * \code
 *     // Initialise the message structure with default values, will be replaced by the received values
 *     IfxCan_Message rxMsg;
 *     IfxCan_initMessage(&rxMsg);
 *
 *     // specify the rx buffer number where the data will be received
 *     rxMsg.bufferNumber = 1;  // choose the buffer number based on the filter configuration an message ID of the TX message
 *
 *      // wait until node receives the data
 *     while ((IfxCan_Can_isNewDataReceived(&canNode[0], (IfxCan_RxBufferId)rxMsg.bufferNumber)) == 0)
 *     { }
 *
 *     // read message
 *     // uint32 rxData[16] // defined globally
 *     IfxCan_Can_readMessage(&canNode[0], &rxMsg, rxData);
 *
 *     // data is now available at rxData
 * \endcode
 *
 * \section IfxLld_Can_Can_FifoStandardTransfers FIFO Standard Transfers
 *
 * CAN driver supports FIFO transfers for both standard and FD data,
 * FIFO transfers has to be selected in the node initialisation phase
 *
 * FIFO initialisation can be done as followed at node level after initialising the module
 * please refer to Module Initialisation subsection previously
 *
 * \code
 *     // create node configuration
 *
 *     // Node 0 as receive node
 *     {
 *         IfxCan_Can_NodeConfig nodeConfig;
 *         IfxCan_Can_initNodeConfig(&nodeConfig, &can);
 *
 *         // initialize Node 0
 *         nodeConfig.nodeId = IfxCan_NodeId_0;
 *         nodeConfig.clockSource = IfxCan_ClockSource_both;
 *         nodeConfig.frame.type = IfxCan_FrameType_receive;
 *
 *         nodeConfig.filterConfig.standardListSize = 2;
 *
 *         nodeConfig.rxConfig.rxMode = IfxCan_RxMode_sharedFifo0;    // see the Rx mode optins to select between Rx buffers and Rx fifos or the combination
 *         nodeConfig.rxConfig.rxFifo0Size = 64;
 *
 *         nodeConfig.messageRAM.standardFilterListStartAddress = 0x100 + NODE0_RAM_OFFSET;
 *         nodeConfig.messageRAM.rxBuffersStartAddress          = 0x200 + NODE0_RAM_OFFSET;
 *         nodeConfig.messageRAM.rxFifo0StartAddress            = 0x300 + NODE0_RAM_OFFSET;
 *         //nodeConfig.messageRAM.baseAddress                    = MODULE_CAN0_RAM ; // No longer needed, driver derives it from module handle. Check line .baseAddress = (uint32)(can->can),
 *
 *         // initialize Node 0
 *         IfxCan_Can_initNode(&canNode[0], &nodeConfig);
 *     }
 *
 *     // Node 1 as transmit node
 *     {
 *         IfxCan_Can_NodeConfig nodeConfig;
 *         IfxCan_Can_initNodeConfig(&nodeConfig, &can);
 *
 *         nodeConfig.nodeId = IfxCan_NodeId_1;
 *         nodeConfig.clockSource = IfxCan_ClockSource_both;
 *
 *         nodeConfig.frame.type = IfxCan_FrameType_transmit;
 *
 *         nodeConfig.txConfig.txMode = IfxCan_TxMode_fifo;    // see the Rx mode optins to select between Tx buffers and Tx fifo/Queue or the combination
 *         nodeConfig.txConfig.dedicatedTxBuffersNumber = 0;    // since Tx mode is chosen as only FIFO
 *         nodeConfig.txConfig.txFifoQueueSize = 32;
 *
 *         nodeConfig.messageRAM.txBuffersStartAddress = 0x400 + NODE1_RAM_OFFSET;
 *         //nodeConfig.messageRAM.baseAddress           = MODULE_CAN0_RAM ;// No longer needed, driver derives it from module handle. Check line .baseAddress = (uint32)(can->can),
 *
 *         // initialize Node 1;
 *         IfxCan_Can_initNode(&canNode[1], &nodeConfig);
 *     }
 * \endcode
 *
 * filter configuration can be set using IfxCan_Can_setStandardFilter function,\n
 * filter configuration example for FIFO transfers,\n
 * here one filter is set for Rx FIFO and one for RX Buffers because Rx Mode is chosen as sharedFifo0 in nodeConfig.rxConfig of receive node
 * \code
 *     // set filters
 *
 *     // set filter for Rx FIFO 0
 *     {
 *         // Initialize the filter structure
 *         IfxCan_Filter filter;
 *
 *         filter.number = 0;
 *         filter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxFifo1;
 *         filter.type = IfxCan_FilterType_range;
 *         filter.id1 = 0x00;
 *         filter.id2 = 0x00;
 *
 *         IfxCan_Can_setStandardFilter(&canNode[0], &filter);
 *     }
 *
 *     // set filter for rxBuffer 0
 *     {
 *         IfxCan_Filter filter;
 *
 *         filter.number = 1;
 *         filter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxBuffer;
 *         filter.id1 = 0x7f;
 *         filter.rxBufferOffset = IfxCan_RxBufferId_0;
 *
 *         IfxCan_Can_setStandardFilter(&canNode[0], &filter);
 *     }
 * \endcode
 *
 * wait for the nodes to be synchronized, before sending and receiving, please refer to Nodes Synchronization subsection previously
 *
 * data can be sent and received similarly as standard data transfers except the FIFO configuration,
 * choose the FIFO related configuration accordingly in the message structure before sending and receiving
 *
 * transmit and receive example
 *
 * \code
 *     //data that needs to be transmitted
 *     txData[0] = 0x55555555;
 *     txData[1] = 0xAAAAAAAA;
 *
 *     // Initial Rx values. It should be replaced by the received values
 *     rxData[0] = 0xdeaddead;
 *     rxData[1] = 0xdeaddead;
 *
 *     // Initialise the tx message structure with defualt values
 *     IfxCan_Message txMsg;
 *     IfxCan_Can_initMessage(&txMsg);
 *
 *     // change the relevant members of transmit message structure
 *     txMsg.messageId = 0x0;     // since the tx mode is configured as FIFO the ID should be constant for all the messages
 *                             // if the tx mode is configured as Queue then the ID can be changed during run time
 *     txMsg.storeInTxFifoQueue = TRUE;    // enable writing the data into FIFO/Queue,
 *                                          // this will enable the sendMessage API to get the next Tx element based on the put index of the Tx FIFO
 *
 *     // Initialise the rx message structure with defualt values
 *     IfxCan_Message rxMsg;
 *     IfxCan_Can_initMessage(&rxMsg);
 *
 *     // change the relevant members of receive message structure
 *     rxMsg.readFromRxFifo0 = TRUE;    // enable reading the data from Rx FIFO 0
 *                                      // this will enable the readMessage API to get the next Rx element based on the get index of Rx FIFO 0
 *
 *     // send and receive through FIFO
 *     uint32 i = 0;
 *
 *     // #define FIFO_LENGTH 20 // define globally
 *     for (i = 0; i < FIFO_LENGTH; ++i)
 *     {
 *         // Transmit Data
 *         if (IfxCan_Can_isTxFifoQueueFull(&canNode[1]) != TRUE)
 *         {
 *                 while( IfxCan_Can_sendMessage(&canNode[1], &txMsg, txData) == IfxCan_Status_notSentBusy );
 *         }
 *
 *         // Receive Data
 *         // wait until RX FIFO 0 receives new data
 *         while(IfxCan_Can_getRxFifo0FillLevel(&canNode[0]) == 0);
 *
 *         if (IfxCan_Can_getRxFifo0FillLevel(&canNode[0]) > 0)
 *         {
 *             // read message
 *             IfxCan_Can_readMessage(&canNode[0], &rxMsg, rxData);
 *         }
 *
 *         // data is now available at rxData[0] and rxData[1]
 *         result |= clib_trace(rxData[0], txData[0]);
 *         result |= clib_trace(rxData[1], txData[1]);
 *
 *         txData[0]++;
 *         txData[1]++;
 *     }
 * \endcode
 *
 * \section IfxLld_Can_Can_FifoFDTransfers FIFO FD Transfers
 *
 * FD transfers through FIFO is similar to FIFO standard transfers except the FD configuration
 * please refer to FD transfers section and FIFO Standard transfers section, and choose the FD configuration accordingly
 *
 * \defgroup IfxLld_Can_Can CAN Interface Driver
 * \ingroup IfxLld_Can
 * \defgroup IfxLld_Can_Can_Data_Structures Data Structures
 * \ingroup IfxLld_Can_Can
 * \defgroup IfxLld_Can_Can_Module_Initialize_Functions Module Initialize Functions
 * \ingroup IfxLld_Can_Can
 * \defgroup IfxLld_Can_Can_Data_Transfer_Functions Data Transfer Functions
 * \ingroup IfxLld_Can_Can
 * \defgroup IfxLld_Can_Can_Filter_Configuration_Functions Filter Configuration Functions
 * \ingroup IfxLld_Can_Can
 * \defgroup IfxLld_Can_Can_Node_Initialize_Functions Node Initialize Functions
 * \ingroup IfxLld_Can_Can
 */

#ifndef IFXCAN_CAN_H
#define IFXCAN_CAN_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Can/Std/IfxCan.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Can_Can_Data_Structures
 * \{ */
/** \brief Structure for nominal baudrate
 */
typedef struct
{
    uint32 baudrate;            /**< \brief Specifies the baud rate. Unit: baud. Range upto 1000000 */
    uint16 samplePoint;         /**< \brief Specifies the baud rate. Unit: baud. Range : 0 to 10000 */
    uint16 syncJumpWidth;       /**< \brief Synchronization Jump Width. Range: 0 to 127 */
    uint16 prescaler;           /**< \brief Baud Rate Prescaler. Range: 0 to 511 */
    uint8  timeSegment1;        /**< \brief Time segment before sample point. Range: 1 to 255 */
    uint8  timeSegment2;        /**< \brief Time segment after sample point. Range: 1 to 127 */
} IfxCan_Can_BaudRate;

/** \brief Structure for fast baudrate
 */
typedef struct
{
    uint32 baudrate;                    /**< \brief Specifies the baud rate. Unit: baud. Range upto 8000000 */
    uint16 samplePoint;                 /**< \brief Specifies the baud rate. Unit: baud. Range : 0 to 10000 */
    uint16 syncJumpWidth;               /**< \brief Synchronization Jump Width. Range: 0 to 15 */
    uint16 prescaler;                   /**< \brief Baud Rate Prescaler. Range: 0 to 31 */
    uint8  timeSegment1;                /**< \brief Time segment before sample point. Range: 0 to 31 */
    uint8  timeSegment2;                /**< \brief Time segment after sample point. Range: 0 to 15 */
    uint8  tranceiverDelayOffset;       /**< \brief transceiver delay compensation offset. Range: 0 to 127 */
} IfxCan_Can_FastBaudRate;

/** \brief Structure for Acceptance filter configuration
 */
typedef struct
{
    IfxCan_MessageIdLength  messageIdLength;                          /**< \brief Message Id length (Standard / Extended) */
    uint8                   standardListSize;                         /**< \brief List Size Standard. Range: 0 to 0x80 */
    uint8                   extendedListSize;                         /**< \brief List Size Extended. Range: 0 to 0x40 */
    uint32                  extendedIdAndMask;                        /**< \brief Extended ID and Mask. Range: 0  to 0x1FFFFFFF */
    boolean                 rejectRemoteFramesWithStandardId;         /**< \brief Set whether to reject the remote frames with standard id. Range: TRUE if reject, FALSE if do not reject */
    boolean                 rejectRemoteFramesWithExtendedId;         /**< \brief Set whether to reject the remote frames with extended id. Range: TRUE if reject, FALSE if do not reject */
    IfxCan_NonMatchingFrame standardFilterForNonMatchingFrames;       /**< \brief Action to be taken on the frames with ids, which are not matching with the standard filter. */
    IfxCan_NonMatchingFrame extendedFilterForNonMatchingFrames;       /**< \brief Action to be taken on the frames with ids, which are not matching with the extended filter. */
} IfxCan_Can_FilterConfig;

/** \brief Structure for Frame Configuration
 */
typedef struct
{
    IfxCan_FrameType type;       /**< \brief Specifies the frame type */
    IfxCan_FrameMode mode;       /**< \brief Specifies the frame mode */
} IfxCan_Can_Frame;

/** \brief Structure for Interrupt configuration
 */
typedef struct
{
    boolean                     rxFifo0NewMessageEnabled;                      /**< \brief Rx FIFO 0 New Message Interrupt enable/Disable */
    boolean                     rxFifo0WatermarkEnabled;                       /**< \brief Rx Fifo 0 Watermark Interrupt enable/Disable */
    boolean                     rxFifo0FullEnabled;                            /**< \brief Rx Fifo 0 Full Interrupt enable/Disable */
    boolean                     rxFifo0MessageLostEnabled;                     /**< \brief Rx FIFO 0 Message Lost Interrupt enable/Disable */
    boolean                     rxFifo1NewMessageEnabled;                      /**< \brief Rx FIFO 1 New Message Interrupt enable/Disable */
    boolean                     rxFifo1WatermarkEnabled;                       /**< \brief Rx FIFO 1 Watermark Reached Interrupt enable/Disable */
    boolean                     rxFifo1FullEnabled;                            /**< \brief Rx FIFO 1 Full Interrupt enable/Disable */
    boolean                     rxFifo1MessageLostEnabled;                     /**< \brief Rx FIFO 1 Message Lost Interrupt enable/Disable */
    boolean                     highPriorityMessageEnabled;                    /**< \brief High Priority Message Interrupt enable/Disable */
    boolean                     transmissionCompletedEnabled;                  /**< \brief Transmission Completed Interrupt enable/Disable */
    boolean                     transmissionCancellationFinishedEnabled;       /**< \brief Transmission Cancellation Finished Interrupt enable/Disable */
    boolean                     txFifoEmptyEnabled;                            /**< \brief Tx FIFO Empty Interrupt enable/Disable */
    boolean                     txEventFifoNewEntryEnabled;                    /**< \brief Tx Event FIFO New Entry Interrupt enable/Disable */
    boolean                     txEventFifoWatermarkEnabled;                   /**< \brief Tx Event FIFO Watermark Reached Interrupt enable/Disable */
    boolean                     txEventFifoFullEnabled;                        /**< \brief Tx Event FIFO Full Interrupt enable/Disable */
    boolean                     txEventFifoEventLostEnabled;                   /**< \brief Tx Event FIFO Event Lost Interrupt enable/Disable */
    boolean                     timestampWraparoundEnabled;                    /**< \brief Timestamp Wraparound Interrupt enable/Disable */
    boolean                     messageRAMAccessFailureEnabled;                /**< \brief Message RAM Access Failure Interrupt enable/Disable */
    boolean                     timeoutOccurredEnabled;                        /**< \brief Timeout Occurred Interrupt enable/Disable */
    boolean                     messageStoredToDedicatedRxBufferEnabled;       /**< \brief Message stored to Dedicated Rx Buffer Interrupt enable/Disable */
    boolean                     errorLoggingOverflowEnabled;                   /**< \brief Error Logging Overflow Interrupt enable/Disable */
    boolean                     errorPassiveEnabled;                           /**< \brief Error Passive Interrupt enable/Disable */
    boolean                     warningStatusEnabled;                          /**< \brief Warning Status Interrupt enable/Disable */
    boolean                     busOffStatusEnabled;                           /**< \brief Bus_Off Status Interrupt enable/Disable */
    boolean                     watchdogEnabled;                               /**< \brief Watchdog Interrupt enable/Disable */
    boolean                     protocolErrorArbitrationEnabled;               /**< \brief Protocol Error in Arbitration phase Interrupt enable/Disable */
    boolean                     protocolErrorDataEnabled;                      /**< \brief Protocol Error in Data phase Interrupt enable/Disable */
    IfxCan_GroupInterruptConfig tefifo;                                        /**< \brief Configuration for Transmit Event FIFO Incidents interrupts */
    IfxCan_GroupInterruptConfig hpe;                                           /**< \brief Configuration for High Priority Events interrupts */
    IfxCan_GroupInterruptConfig wati;                                          /**< \brief Configuration for Watermark interrupts */
    IfxCan_GroupInterruptConfig alrt;                                          /**< \brief Configuration for Alerts interrupts */
    IfxCan_GroupInterruptConfig moer;                                          /**< \brief Configuration for Module errors interrupts */
    IfxCan_GroupInterruptConfig safe;                                          /**< \brief Configuration for Safety counter overflow interrupt */
    IfxCan_GroupInterruptConfig boff;                                          /**< \brief Configuration for Bus Off interrupt */
    IfxCan_GroupInterruptConfig loi;                                           /**< \brief Configuration for Last Error interrupts */
    IfxCan_GroupInterruptConfig reint;                                         /**< \brief Configuration for iMessage stored in dedicated receive buffer interrupts */
    IfxCan_GroupInterruptConfig rxf1f;                                         /**< \brief Configuration for Receive FIFO1 full interrupts */
    IfxCan_GroupInterruptConfig rxf0f;                                         /**< \brief Configuration for Receive FIFO0 full interrupts */
    IfxCan_GroupInterruptConfig rxf1n;                                         /**< \brief Configuration for Receive FIFO1 new message interrupts */
    IfxCan_GroupInterruptConfig rxf0n;                                         /**< \brief Configuration for Receive FIFO0 new message interrupts */
    IfxCan_GroupInterruptConfig reti;                                          /**< \brief Configuration for Receive Timeouts interrupts */
    IfxCan_GroupInterruptConfig traq;                                          /**< \brief Configuration for Transmission Queue Events interrupts */
    IfxCan_GroupInterruptConfig traco;                                         /**< \brief Configuration for interrupts of the transmission control */
} IfxCan_Can_InterruptConfig;

/** \brief Structure for CAN pin configuration
 */
typedef struct
{
    IfxCan_Txd_Out    *txPin;           /**< \brief Specifies the transmit pin */
    IfxPort_OutputMode txPinMode;       /**< \brief Specifies the transmit pin output mode IfxPort_OutputMode_pushPull */
    IfxCan_Rxd_In     *rxPin;           /**< \brief Specifies the receive pin */
    IfxPort_InputMode  rxPinMode;       /**< \brief Specifies the receive pin as input mode IfxPort_InputMode_noPullDevice */
    IfxPort_PadDriver  padDriver;       /**< \brief Pad driver IfxPort_PadDriver_cmosAutomotiveSpeed2 */
} IfxCan_Can_Pins;

/** \brief Structure for Rx handle Configuration
 */
typedef struct
{
    IfxCan_RxMode        rxMode;                      /**< \brief Rx Buffers or FIFO 0 or combination Mode of reception */
    IfxCan_DataFieldSize rxBufferDataFieldSize;       /**< \brief Rx Buffer Data Field Size */
    IfxCan_DataFieldSize rxFifo0DataFieldSize;        /**< \brief Rx FIFO 0 Data Field Size */
    IfxCan_DataFieldSize rxFifo1DataFieldSize;        /**< \brief Rx FIFO 1 Data Field Size */
    IfxCan_RxFifoMode    rxFifo0OperatingMode;        /**< \brief Rx FIFO 0 operating mode */
    IfxCan_RxFifoMode    rxFifo1OperatingMode;        /**< \brief Rx FIFO 1 operating mode */
    uint8                rxFifo0WatermarkLevel;       /**< \brief Rx FIFO 0 watermark level. Range: 0 to 0x40 */
    uint8                rxFifo1WatermarkLevel;       /**< \brief Rx FIFO 1 watermark level. Range: 0 to 0x40 */
    uint8                rxFifo0Size;                 /**< \brief Rx FIFO 0 Size. Range: 0 to 0x40 */
    uint8                rxFifo1Size;                 /**< \brief Rx FIFO 1 Size. Range: 0 to 0x40 */
} IfxCan_Can_RxConfig;

/** \brief Structure for Tx handle Configuration
 */
typedef struct
{
    IfxCan_TxMode        txMode;                         /**< \brief Tx FIFO/Queue Mode */
    uint8                dedicatedTxBuffersNumber;       /**< \brief Number of Dedicated Transmit Buffers. Range: 0 to 0x20 */
    uint8                txFifoQueueSize;                /**< \brief Transmit FIFO/Queue Size. Range: 0 to 0x20 */
    IfxCan_DataFieldSize txBufferDataFieldSize;          /**< \brief Tx Buffer Data Field Size */
    uint8                txEventFifoSize;                /**< \brief Transmit Event FIFO Size. Range: 0 to 0x20 */
} IfxCan_Can_TxConfig;

/** \} */

/** \addtogroup IfxLld_Can_Can_Data_Structures
 * \{ */
/** \brief Module handle
 */
typedef struct
{
    Ifx_CAN *can;       /**< \brief Specifies the pointer to the CAN registers */
} IfxCan_Can;

/** \brief Configuration Structure of the Module
 */
typedef struct
{
    Ifx_CAN *can;       /**< \brief Specifies the pointer to the CAN registers */
} IfxCan_Can_Config;

/** \brief Node handle
 */
typedef struct
{
    Ifx_CAN          *can;              /**< \brief Specifies the pointer to the CAN registers */
    Ifx_CAN_N        *node;             /**< \brief Specifies the pointer to the CAN Node registers */
    IfxCan_MessageRAM messageRAM;       /**< \brief Structure for Message RAM */
} IfxCan_Can_Node;

/** \brief Configuration Structure of the Node
 */
typedef struct
{
    Ifx_CAN                   *can;                            /**< \brief Specifies the pointer to the CAN registers */
    IfxCan_NodeId              nodeId;                         /**< \brief Specifies the Node number of the MCan */
    IfxCan_ClockSource         clockSource;                    /**< \brief Clock source */
    IfxCan_Can_Frame           frame;                          /**< \brief Structure for Frame Configuration */
    IfxCan_Can_BaudRate        baudRate;                       /**< \brief Structure for nominal baudrate */
    IfxCan_Can_FastBaudRate    fastBaudRate;                   /**< \brief Structure for fast baudrate */
    IfxCan_Can_TxConfig        txConfig;                       /**< \brief Structure for Tx handle Configuration */
    IfxCan_Can_FilterConfig    filterConfig;                   /**< \brief Structure for Acceptance filter configuration */
    IfxCan_Can_RxConfig        rxConfig;                       /**< \brief Structure for Rx handle Configuration */
    IfxCan_MessageRAM          messageRAM;                     /**< \brief Structure for Message RAM */
    IfxCan_Can_InterruptConfig interruptConfig;                /**< \brief Structure for Interrupt configuration */
    IFX_CONST IfxCan_Can_Pins *pins;                           /**< \brief structure for CAN pins */
    boolean                    busLoopbackEnabled;             /**< \brief Internal Virtual CAN bus loopback mode enable / disable choice */
    boolean                    calculateBitTimingValues;       /**< \brief Enable / Disable auto calculation of bit timing values for selected CAN node */
} IfxCan_Can_NodeConfig;

/** \} */

/** \brief Structure for Tx Event FIFO elements
 */
typedef struct
{
    boolean                errorStateIndicator;             /**< \brief Error State Indicator. Range: TRUE if error passive, FALSE if error active  */
    boolean                extendedID;                      /**< \brief Extended Identifier. Range: TRUE if 29-bit extended identifier, FALSE if 11-bit standard identifier */
    boolean                remoteTransmissionRequest;       /**< \brief Remote Transmission Request. Range: TRUE if Remote frame transmitted, FALSE if Data frame transmitted */
    uint32                 identifier;                      /**< \brief Identifier. Range: 0x000 to 0x7FF (Standard); 0 to 0x1FFFFFFF (Extended) */
    uint16                 messageMarker;                   /**< \brief Message Marker. Range 0 to 31 */
    uint8                  eventType;                       /**< \brief Event Type. Range: 1 or 2 (0 and 3 are reserved) */
    IfxCan_FrameFormatType frameFormatType;                 /**< \brief Frame Format Type */
    boolean                bitRateSwitch;                   /**< \brief Bit Rate Switch. Range: TRUE if with bit rate switching, FALSE if without bit rate switching */
    uint8                  dataLengthCode;                  /**< \brief Data Length Code. Range: 0 to 0xF */
} IfxCan_Can_TransmitEvent;

/** \addtogroup IfxLld_Can_Can_Module_Initialize_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes the CAN module according to the provided configuration.
 *
 * \param[inout] can    Pointer to the module handle to be initialized.
 * \param[in]    config Pointer to the configuration structure containing the necessary settings for the CAN module initialization.
 *
 * \retval None
 *
 * \see IfxLld_Can_Can_Usage for example usage.
 */
IFX_EXTERN void IfxCan_Can_initModule(IfxCan_Can *can, const IfxCan_Can_Config *config);

/**
 * \brief Initializes the CAN module configuration structure with default values.
 *
 * \param[inout] config Pointer to the configuration structure to be initialized with default values.
 * \param[in]    can    Pointer to the CAN register interface used for initialization.
 *
 * \retval None
 *
 * \see IfxLld_Can_Can_Usage for example usage.
 */
IFX_EXTERN void IfxCan_Can_initModuleConfig(IfxCan_Can_Config *config, Ifx_CAN *can);

/** \} */

/** \addtogroup IfxLld_Can_Can_Data_Transfer_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Returns Rx FIFO 0 Fill Level for the specified CAN node.
 *
 * \param[in] node Pointer to CAN Node handle.
 *
 * \retval uint8 Fill level of Rx FIFO 0. Range 0 to 64
 *
 * Coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_INLINE uint8 IfxCan_Can_getRxFifo0FillLevel(IfxCan_Can_Node *node);

/**
 * \brief Returns the fill level of the Rx FIFO 1 for the specified CAN node.
 *
 * \param[in] node Pointer to CAN Node handle.
 *
 * \retval uint8 The current fill level of Rx FIFO 1. Range 0 to 64
 *
 * Coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_INLINE uint8 IfxCan_Can_getRxFifo1FillLevel(IfxCan_Can_Node *node);

/**
 * \brief Returns the status of whether the selcted Rx buffer has been updated from new data.
 *
 * \param[in] node       Pointer to CAN Node handle.
 * \param[in] rxBufferId Rx Buffer number to check. Range: \ref IfxCan_RxBufferId
 *
 * \retval TRUE If new data is available in the specified Rx buffer.
 * 		   FALSE If no new data is available in the specified Rx buffer.
 *
 * Coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_INLINE boolean IfxCan_Can_isNewDataReceived(IfxCan_Can_Node *node, IfxCan_RxBufferId rxBufferId);

/**
 * \brief Returns the status of whether Tx Fifo/Queue is full or not.
 *
 * \param[in] node Pointer to CAN Node handle.
 *
 * \retval TRUE If status of Tx Fifo Queue is full.
 *         FALSE If status of Tx Fifo Queue is not full. 
 * 
 * Coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_INLINE boolean IfxCan_Can_isTxFifoQueueFull(IfxCan_Can_Node *node);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a CAN message structure with default values for transmission or reception.
 *
 * \param[inout] message Pointer to the CAN Message structure to be initialized.
 *
 * \retval None
 * 
 * Coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_EXTERN void IfxCan_Can_initMessage(IfxCan_Message *message);

/**
 * \brief Reads a received CAN message from the specified node.
 *
 * \param[inout] node    Pointer to CAN Node handle.
 * \param[inout] message Pointer to structure for Message configuration filled with dummy values and will be relpaced by read values. \see IfxCan_Can_initMessage
 * \param[inout]   data    Pointer to a data array (in words) where the received message data will be stored.
 *
 * \retval None
 * 
 * Coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_EXTERN void IfxCan_Can_readMessage(IfxCan_Can_Node *node, IfxCan_Message *message, uint32 *data);

/**
 * \brief Transmits a CAN message through the specified node.
 *
 * \param[inout] node    Pointer to CAN Node handle.
 * \param[in]    message Pointer to the message configuration structure, defining properties like message ID, length, and mode. \see IfxCan_Can_initMessage
 * \param[in]    data    Pointer to the data payload (in words) to be transmitted with the message.
 *
 * \retval IfxCan_Status The status of the transmission operation. Range: \ref IfxCan_Status
 * 
 * Coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_EXTERN IfxCan_Status IfxCan_Can_sendMessage(IfxCan_Can_Node *node, IfxCan_Message *message, uint32 *data);

/** \} */

/** \addtogroup IfxLld_Can_Can_Filter_Configuration_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Configures the extended filter element configuration for a specified CAN node using the provided filter settings.
 *
 * \param[inout] node   Pointer to CAN Node handle.
 * \param[in]    filter Pointer to the filter configuration structure. This structure defines the filter parameters, including filter number, element configuration, type, IDs, and Rx buffer offset.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_EXTERN void IfxCan_Can_setExtendedFilter(IfxCan_Can_Node *node, IfxCan_Filter *filter);

/**
 * \brief Configures the standard filter element configuration for a specified CAN node using the provided filter settings.
 *
 * \param[inout] node   Pointer to CAN Node handle.
 * \param[in]    filter Pointer to the filter configuration structure that defines the filter properties, including filter number, type, ID values, and buffer offset.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_EXTERN void IfxCan_Can_setStandardFilter(IfxCan_Can_Node *node, IfxCan_Filter *filter);

/** \} */

/** \addtogroup IfxLld_Can_Can_Node_Initialize_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Checks if the CAN node is synchronized.
 *
 * \param[in] node Pointer to CAN Node handle.
 *
 * \retval TRUE If the node is synchronized.
 *         FALSE If synchronization is in progress.
 *
 * A coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_INLINE boolean IfxCan_Can_isNodeSynchronized(IfxCan_Can_Node *node);

/**
 * \brief Checks if a transmit buffer request is pending.
 *
 * \param[in] node       Pointer to CAN Node handle.
 * \param[in] txBufferId Tx Buffer number to check. Range: \ref IfxCan_TxBufferId
 *
 * \retval TRUE If the transmit buffer request is pending.
 * 	       FALSE If the transmit buffer request is not pending.
 */
IFX_INLINE boolean IfxCan_Can_isTxBufferRequestPending(IfxCan_Can_Node *node, IfxCan_TxBufferId txBufferId);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a CAN node with the specified configuration.
 *
 * \param[inout] node   Pointer to CAN Node handle.
 * \param[in]    config Pointer to the configuration structure containing the setup parameters
 *                      for the CAN node, including clock source, baud rates,
 *                      transmission/reception configurations, filter settings,
 *                      interrupt configurations, and pin assignments.
 *
 * \retval TRUE If the the CAN node was successfully initialized.
 *         FALSE If an error occurred during initialization.
 *
 * A coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_EXTERN boolean IfxCan_Can_initNode(IfxCan_Can_Node *node, const IfxCan_Can_NodeConfig *config);

/**
 * \brief Initializes the CAN Node clock configuration.
 *
 * \param[inout] node        Pointer to CAN Node handle.
 * \param[in]    can         Pointer to the CAN registers.
 * \param[in]    nodeId      CAN Node number. Range: \ref IfxCan_NodeId
 * \param[in]    clockSource The type of clock source to be used. Range: \ref IfxCan_ClockSource
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Can_initNodeClk(IfxCan_Can_Node *node, Ifx_CAN *can, IfxCan_NodeId nodeId, IfxCan_ClockSource clockSource);

/**
 * \brief Configures the message RAM handle for the specified CAN node using the provided configuration structure.
 *
 * \param[inout] node       Pointer to CAN Node handle.
 * \param[in]    messageRAM Pointer to configuration structure for Message RAM configuration.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Can_configureNodeMessageRamHandle(IfxCan_Can_Node *node, const IfxCan_MessageRAM *messageRAM);

/**
 * \brief Configures the CAN Node baudrate.
 *
 * \param[inout] node                     Pointer to CAN Node handle.
 * \param[in]    baudRate                 Pointer to structure containing nominal baudrate configuration parameters such as
 *                                        baud rate, sample point, synchronization jump width, prescaler, and time
 *                                        segments.
 * \param[in]    fastBaudRate             Pointer to structure containing fast baudrate configuration parameters, including
 *                                        baud rate, sample point, synchronization jump width, prescaler, time
 *                                        segments, and transceiver delay offset.
 * \param[in]    calculateBitTimingValues Flag to enable/disable automatic calculation of bit timing
 *                                        values for the CAN node. Range: TRUE (calculate),
 *                                        FALSE (do not calculate).
 * \param[in]    frameMode                CAN frame mode. Range: \ref IfxCan_FrameMode
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Can_configureBaudrate(IfxCan_Can_Node *node, const IfxCan_Can_BaudRate *baudRate, const IfxCan_Can_FastBaudRate *fastBaudRate, boolean calculateBitTimingValues, IfxCan_FrameMode frameMode);

/**
 * \brief Configures the transmit frame configuration for the specified CAN node.
 *
 * \param[inout] node     Pointer to CAN Node handle.
 * \param[in]    frame    Pointer to structure for Frame Configuration.
 * \param[in]    txConfig Pointer to structure for Tx handle Configuration.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Can_configureTx(IfxCan_Can_Node *node, const IfxCan_Can_Frame *frame, const IfxCan_Can_TxConfig *txConfig);

/**
 * \brief Configures the receive frame configuration for the CAN node.
 *
 * \param[inout] node     Pointer to CAN Node handle.
 * \param[in]    frame    Pointer to structure for Frame Configuration.
 * \param[in]    rxConfig Pointer to structure for Rx handle Configuration.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Can_configureRx(IfxCan_Can_Node *node, const IfxCan_Can_Frame *frame, const IfxCan_Can_RxConfig *rxConfig);

/**
 * \brief Configures the acceptance filter for a CAN node based on the provided frame and filter settings.
 *
 * \param[inout] node         Pointer to CAN Node handle.
 * \param[in]    frame        Pointer to structure for Frame Configuration.
 * \param[in]    filterConfig Pointer to structure for Acceptance filter configuration.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Can_configureFilter(IfxCan_Can_Node *node, const IfxCan_Can_Frame *frame, const IfxCan_Can_FilterConfig *filterConfig);

/**
 * \brief Configures the CAN pins for a specified node based on the provided pin configuration.
 *
 * \param[inout] node Pointer to CAN Node handle.
 * \param[in]    pins Pointer to the structure containing the pin configuration details,
 *                    including TX pin, TX pin mode, RX pin, RX pin mode, and pad driver settings.
 *
 * \retval TRUE If operation was successful.
 *         FALSE If an error occurred during pin configuration.
 */
IFX_EXTERN boolean IfxCan_Can_configurePins(IfxCan_Can_Node *node, const IfxCan_Can_Pins *pins);

/**
 * \brief Configures the internal virtual CAN bus loopback mode.
 *
 * \param[inout] node               Pointer to CAN Node handle.
 * \param[in]    busLoopbackEnabled Boolean flag to enable (true) or disable (false) the loopback mode.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Can_configureLoopbackMode(IfxCan_Can_Node *node, boolean busLoopbackEnabled);

/**
 * \brief Configures interrupt groups configuration for the specified CAN node.
 *
 * \param[inout] node            Pointer to CAN Node handle.
 * \param[in]    interruptConfig Pointer to a structure containing interrupt
 *                               configuration settings.
 *
 * \retval None
 */
IFX_EXTERN void IfxCan_Can_configureInterrupt(IfxCan_Can_Node *node, const IfxCan_Can_InterruptConfig *interruptConfig);

/**
 * \brief Initializes the CAN node configuration structure with default values.
 *
 * \param[inout] config Pointer to the configuration structure of the node to be initialized.
 * \param[in]    can    Specifies the CAN module handle to be used for configuration.
 *
 * \retval None
 *
 * A coding example can be found in \ref IfxLld_Can_Can_Usage
 *
 */
IFX_EXTERN void IfxCan_Can_initNodeConfig(IfxCan_Can_NodeConfig *config, IfxCan_Can *can);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Reads and extracts Tx event FIFO elements.
 *
 * \param[inout] node                   Pointer to CAN Node handle.
 * \param[inout] canTxEventFifoElements Pointer to structure of Tx event FIFO elements.
 *
 * \retval IfxCan_ReadTxEventStatus Status of read Tx event. Range: \ref IfxCan_ReadTxEventStatus
 */
IFX_EXTERN IfxCan_ReadTxEventStatus IfxCan_Can_readTxEvent(IfxCan_Can_Node *node, IfxCan_Can_TransmitEvent *canTxEventFifoElements);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE uint8 IfxCan_Can_getRxFifo0FillLevel(IfxCan_Can_Node *node)
{
    return IfxCan_Node_getRxFifo0FillLevel(node->node);
}


IFX_INLINE uint8 IfxCan_Can_getRxFifo1FillLevel(IfxCan_Can_Node *node)
{
    return IfxCan_Node_getRxFifo1FillLevel(node->node);
}


IFX_INLINE boolean IfxCan_Can_isNewDataReceived(IfxCan_Can_Node *node, IfxCan_RxBufferId rxBufferId)
{
    return IfxCan_Node_isRxBufferNewDataUpdated(node->node, rxBufferId);
}


IFX_INLINE boolean IfxCan_Can_isNodeSynchronized(IfxCan_Can_Node *node)
{
    return IfxCan_Node_isNodeSynchronized(node->node);
}


IFX_INLINE boolean IfxCan_Can_isTxBufferRequestPending(IfxCan_Can_Node *node, IfxCan_TxBufferId txBufferId)
{
    return IfxCan_Node_isTxBufferRequestPending(node->node, txBufferId);
}


IFX_INLINE boolean IfxCan_Can_isTxFifoQueueFull(IfxCan_Can_Node *node)
{
    return IfxCan_Node_isTxFifoQueueFull(node->node);
}


#endif /* IFXCAN_CAN_H */
