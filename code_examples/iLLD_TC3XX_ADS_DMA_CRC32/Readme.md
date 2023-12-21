<img src="./Images/IFX_LOGO_600.gif" align="right" width="150" />  

# iLLD_TC3XX_ADS_DMA_CRC32
**Compute CRC over a memory range in PFLASH using DMA**

## Device  
The device used in this example is AURIX™ TC37xTP_A-Step

## Board  
The board used for testing is the AURIX™ TC375 lite Kit (KIT_A2G_TC375_LITE)  

## Scope of work
The Direct Memory Access module (DMA) calculates CRC of transferred data during a transfer.  
The memory range in Program Flash (PFLASH) over which CRC has to be calculate is set as the data source in a DMA transfer and destination as any location in RAM.  
After the DMA transfer is complete the CRC is read from the DMA module.  
This CRC is compared against the CRC calculated using the CPU CRC32 instruction over the same memory range in PFLASH.  
Different LEDs are tunred on depending upon if the CPU and DMA calculated CRCs match or not.  

## Introduction  
- A cyclic redundancy check (CRC) is an error-detecting code commonly used in digital networks and storage devices to detect accidental changes to digital data.
- The *Direct Memory Access* module moves data from a source module to a destination module without CPU intervention
- The *DMA Data Checksum* is cyclic redundancy checksum calculated according to the IEEE 802.3 standard for data moved during a DMA transaction
- *Program Flash:* Divided into one or more banks each connected to a CPU. It is used by the application to store program code and data constants

## Hardware setup  
This code example has been developed for the AURIX™ TC375 Lite Kit (KIT_A2G_TC375_LITE).  

<img src="./Images/Aurix_Top.PNG" width="600" />   

## Implementation  
**Configure the DMA**  
- The function *initDMA()* in *DMA_Mem_CRC.c* sets up the DMA with the source address pointing to the desired range in PFLASH over which CRC is to be calculated  
- The macro *DMA_PFLASH_SRC_ADDR* in *DMA_Mem_CRC.c* specifies the start address of the desired PFLASH range. Change this macro to calculate CRC over a new range  
- The macro *DATA_ARRAY_LENGTH* in *DMA_Mem_CRC.c* specifies the length of the desired PFLASH range. Change it to define a new PFLASH range  

**Trigger the DMA**  
- The function *runDMA()* in *DMA_Mem_CRC.c* starts the DMA transfer from the specified memory range
- The DMA calculated CRC over the selected PFLASH range is available after the transfer is complete
- This function also calculates CRC using the CRC32 instruction offered by the CPU
- If the CPU and DMA CRC match, LED2 (P00.6) is turned on and LED1 (P00.5) is turned off (Success)
- If the CPU and DMA CRC match, LED2 (P00.6) is turned off and LED1 (P00.5) is turned on (Failure)

## Compiling and programming
Before testing this code example:
- Power the board through the dedicated power connector
- Connect the board to the PC through the USB interface
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/micro.png" />  

## Run and Test  
For this example, LED2 (marked in green) will turn and remain on, LED1 will remain off in case of a successfull CRC calculation using both DMA and CPU.  
In case of a failure i.e the DMA and CPU calculated CRC do not match, LED1 (marked in red) will turn and remain on and LED2 will remain off.    

<img src="./Images/Aurix_Top_Leds.PNG" width="600" />  

## References  

AURIX™ Development Studio is available online:  
- <https://www.infineon.com/aurixdevelopmentstudio>  
- Use the "Import..." function to get access to more code examples  

More code examples can be found on the GIT repository:  
- <https://github.com/Infineon/AURIX_code_examples>  

For additional trainings, visit our webpage:  
- <https://www.infineon.com/aurix-expert-training>  

For questions and support, use the AURIX™ Forum:  
- <https://community.infineon.com/t5/AURIX/bd-p/AURIX>  
