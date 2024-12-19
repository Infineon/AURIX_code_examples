<img src="./Images/IFX_LOGO_600.gif" align="right" width="150" />  

# RAM_Run_Function_1_KIT_TC397_TFT
A function is stored and executed from SRAM.

## Device  
The device used in this example is AURIX&trade; TC39xTP_A-Step.

## Board  
The board used for testing is the AURIX&trade; TC397 TFT (KIT_A2G_TC397_5V_TFT).

## Scope of work  
This example implements twice the same function which toggles an LED with a wait loop. One function is implemented to be executed from SRAM and the other one from Flash memory. 
The SRAM function is toggling LED1 (P13.0), while the flash function is toggling LED2 (P13.1).

## Introduction  
The Local Memory Unit (LMU) SRAM can be used for *code execution*, data storage or overlay memory.

The LMU can be accessed via cached (segment 9H) or via non-cached (segment BH) memory addresses.

If a code is programmed to be executed from SRAM memory, it is copied from Flash to SRAM by the Start-up Software (SSW) code.

## Hardware setup  
This code example has been developed for the board KIT_A2G_TC397_5V_TFT.

<img src="./Images/TC397_TFT_Top_View.png" width="500" />  

## Implementation  

### SRAM code section creation
The linker file “*Lcf_Tasking_Tricore_Tc.lsl*” is updated by adding a memory section (called *code_lmuram_nc*) for code execution from LMURAM memory.  
The memory section should be assigned to the *non-cached* memory addresses (segment BH) to avoid any data inconsistency.

<img src="./Images/SRAM_code.png" width="600" />

### Locating function code in a specific memory section
The *pragma* compiler keyword with the attribute *section code “<section_identifier>”* is used to specify the memory section from which the implemented function code will be fetched and executed.

The *section code restore* attribute is used after the function implementation to ensure that next implemented functions will be located in the default code memory section (Flash memory).

### LED Toggling
Two functions are implemented, *toggleLedSram()* and *toggleLedFlash()*, to toggle two LEDs from different memory regions.

Using the previously mentioned *pragma* compiler keyword, the *toggleLedSram()* can be executed from PSPR memory.

Both functions are implemented as following:
- Switch On the LED by calling *IfxPort_setPinLow()*
- Wait for a one second delay
- Switch Off the LED by calling *IfxPort_setPinHigh()*
- Wait for a one second delay

The above Port functions can be found in the iLLD header *IfxPort.h*.

**Note**: The LEDs on the used board are low-level active.

## Compiling and programming  
Before testing this code example:  
- Power the board through the dedicated power connector
- Connect the board to the PC through the USB interface  
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"  
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/Widget_Flash.png" width="16"/>

## Run and Test   
After code compilation and flashing the device, perform the following:
- Check that LED1 (D107) and LED2 (D108) are toggling 

<img src="./Images/TC397_TFT_Top_View_Run_and_Test.png" width="500" />  

Additionally, the execution from RAM can be checked by adding a breakpoint inside the *toggleLedSram()* function and verify in the disassembly window of the debugger that the CPU is executing it from LMURAM (Addresses segment BH).

<img src="./Images/Addresses_Run_and_Test.png" width="600" /> 

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