<img src="./Images/IFX_LOGO_600.gif" align="right" width="150" />  

# iLLD_TC375_ADS_printf_scanf
**The printf/scanf functions are used to send/read data with ASCLIN.**

## Device  
The device used in this example is AURIX&trade; TC37xTP_A-Step

## Board  
The board used for testing is the AURIX&trade; TC375 lite Kit (KIT_A2G_TC375_LITE)  

## Scope of work   
The printf/scanf functions are retargeted for TASKING/GCC compilers to send/read data via ASCLIN in ASC (UART) mode.  

## Introduction  
- The Asynchronous/Synchronous Interface (ASCLIN) module enables asynchronous/synchronous serial communication with external devices
- For this example, asynchronous reception/transmission (UART) is used for the communication between a PC and an AURIX&trade; device

## Hardware setup  
This code example has been developed for the AURIX&trade; TC375 Lite Kit (KIT_A2G_TC375_LITE).  

<img src="./Images/LiteKit_V2_Top.png" width="600" /><br />

## Implementation  
**Configure the Project**  

It further requires the component library files, which can be found in the *Components/serialio* folder.  

**Configure the ASCLIN**  

Configuration of the ASCLIN module for UART communication is done in the function *SERIALIO_Init()*, it takes the desired UART baudrate as parameter.  
The desired baudrate can be defined with the macro *UART_BAUDRATE*, whose default value is set to 115200 baud.

The function *SERIALIO_Init()* initializes an instance of the *IfxAsclin_Asc_Config* structure with default values through the function *IfxAsclin_Asc_initModuleConfig()*.  
The following parameters are then modified:  
- *baudrate* - structure to set the actual communication speed in bit/s
- *pins* - structure to set which GPIO port pins are used for the communication. The definition of the pins used is done in the file *Cpu0_Main.c* in the section for *Serial IO*

Finally, the configuration is applied via the function *IfxAsclin_Asc_initModule()* and the transmission is enabled by setting the Transmit FIFO Level Flag (TFL) via the *FLAGSSET* register.  
All the above functions can be found in the iLLD header *IfxAsclin_Asc.h*.

**Retargeting printf function**  

TASKING compiler

When calling the *printf()* function, the TASKING compiler sends one character at a time using the function *_io_putc()*.  
The function waits until the *IfxAsclin_getTxFifoFillLevelFlagStatus()* returns *TRUE*, then clears the Transmit FIFO Level Flag (TFL) of the Flags Register with the function *IfxAsclin_clearTxFifoFillLevelFlag()*.  
Finally, it sends the given character via UART using the function *IfxAsclin_writeTxData()*.  
The functions mentioned above can be found in the iLLD header *IfxAsclin.h*.

GCC compiler

When calling the *printf()* function, the GCC compiler provides the complete string to be sent using the function *write()*.  
Character by character of the string is sent individually. The following steps are repeated until all characters are sent:  
For this the function waits until the *IfxAsclin_getTxFifoFillLevelFlagStatus()* returns *TRUE*, then clears the Transmit FIFO Level Flag (TFL) of the Flags Register with the function *IfxAsclin_clearTxFifoFillLevelFlag()*.  
Finally, it sends the given character via UART using the function *IfxAsclin_writeTxData()*. 
The functions mentioned above can be found in the iLLD header *IfxAsclin.h*.

**Retargeting scanf function**  

TASKING compiler

When calling the *scanf()* function, the TASKING compiler receives one character at a time using the function *_io_getc()*.  
The function waits until the *IfxAsclin_getRxFifoFillLevelFlagStatus()* returns *TRUE*, then clears the Receive FIFO Level Flag (RFL) of the Flags Register with the function *IfxAsclin_clearRxFifoFillLevelFlag()*.  
Finally, it reads the given character via UART using the function *IfxAsclin_readRxData()*.  
The functions mentioned above can be found in the iLLD header *IfxAsclin.h*.

GCC compiler

When calling the *scanf()* function, the GCC compiler receives the complete string to be read using the function *read()*.  
Character by character of the string is read individually. The following steps are repeated until *enter* is read:  
For this the function waits until the *IfxAsclin_getRxFifoFillLevelFlagStatus()* returns *TRUE*, then clears the Receive FIFO Level Flag (RFL) of the Flags Register with the function *IfxAsclin_clearRxFifoFillLevelFlag()*.  
Finally, it reads the given character via UART using the function *IfxAsclin_readRxData()*. 
The functions mentioned above can be found in the iLLD header *IfxAsclin.h*.

**fflush function**

When calling the *fflush(stdout)* function the output buffer of the standard output stream is flushed.

## Compiling and programming
Before testing this code example:
- Power the board through the dedicated power connector
- Connect the board to the PC through the USB interface
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/micro.png" />  

## Run and Test  
For this example, a serial terminal is required for visualizing the text. The terminal can be opened inside the AURIX&trade; Development Studio using the following icon:  

<img src="./Images/UART_Terminal.gif" width="800" />  

The serial terminal must be configured with the following parameters to enable the communication between the board and the PC:  
- Speed (baud): 115200
- Data bits: 8
- Stop bit: 1

After code compilation and flashing the device, check the open terminal window on AURIX&trade; Development Studio, which looks like the following:  

<img src="./Images/printf.png" width="384" />  

## References  

AURIX&trade; Development Studio is available online:  
- <https://www.infineon.com/aurixdevelopmentstudio>  
- Use the "Import..." function to get access to more code examples  

More code examples can be found on the GIT repository:  
- <https://github.com/Infineon/AURIX_code_examples>  

For additional trainings, visit our webpage:  
- <https://www.infineon.com/aurix-expert-training>  

For questions and support, use the AURIX&trade; Forum:  
- <https://community.infineon.com/t5/AURIX/bd-p/AURIX>  
