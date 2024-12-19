<img src="./Images/IFX_LOGO_600.gif" align="right" width="150" /> 
      
# iLLD_TC375_ADS_OVERLAY_LITEKIT                               
**The data access overlay (OVC) provides the capability to redirect selected data accesses to the Overlay memory.**  

## Device  
The device used in this example is AURIX™ TC37xTP_A-Step.

## Board  
The board used for testing is the AURIX™ TC375 lite Kit (KIT_A2G_TC375_LITE).

## Scope of work
The data overlay functionality provides the possibility of redirecting data read access from a non-volatile memory
(Target Memory/Code Memory) to a volatile memory (Overlay Memory) for execution. The process usually involves copying code 
from a (non-volatile/Code Memory) to volatile memory, that makes it possible, for example, to modify program parameters 
(which are typically stored in the code memory) during run time of program. Once copied, an overlay mechanism is instituted 
(configure required Overlay Control registers). The registers are prepared to enable/disable the redirection
from non-volatile memory (usually Flash) into volatile memory (SRAM). The CPU convert the addresses to access the volatile 
memory (SRAM) instead the non-volatile memory (Flash). Once the redirecting process has been completed, the modified parameters 
that are in the volatile memory will be stored back to the non-volatile memory (which is not addressed in the provided code example). 
Different test scenarios has been provided in this code example, focused on ensuring that the redirection of memory accesses is 
accurately configured.

## Introduction
The Overlay function serves the purpose of enabling modification of an application's test that are typically stored in PFlash memory. This is achieved by copying PFlash code to SRAM . To illustrate, consider the following Figure.

<img src="./Images/OverlayFunction.PNG" width="620" /> 
<br><br><br>

**Summary of OVC features:**
  
Possibility of redirecting **data accesses** addressing:
- On-chip PFlash  
- Online Data Acquisition OLDA (virtual space) 
- Extended EBU Space (if present)

**Note:** Target memory specified should be NVM Memory.<br>
It means that redirection can happen from the PFlash (NVM Memory) to another memory, but not the opposite.   

Support redirection to Overlay memory located in: 
- Local Memory (LMU) (if present)
- Emulation Device Memory
- External EBU space (if present)
- DSPR or PSPR memory

Overlay Control: 
- Core DMI (Individual overlay system per processor core) 
This means, the address translation is implemented in the DMI it is only effective for data accesses by the TriCore. 

Overlay Blocks:
- Up to 32 overlay ranges (blocks) available in each core instance

Block Size:
- 32 Byte .. 128 kByte
<br><br>

**Registers:**<br>
The overlay function allows each core to utilize up to 32 memory blocks for overlay, with <U>registers</U> available for configuration on each core. The registers to enable the overlay function are divided in: 

-*Block Control via Core Registers*

-*Global Control via SCU Registers*

(*For more details see chapter 5.3.9.7.1 of User Manual of AURIX&trade;TC3XX, for Block Control via Core Registers, and chapter 9.3.5 of User Manual for Global Control via SCU Registers, which is provided in Infineon website.*) 

<img src="./Images/RegistersOverlay.PNG" width="650" /> 

- The Overlay function is enabled using the **IfxCpu_enableOverlayBlock()** function.<br><br> 

**Some Important Notes for OVC Register Configuration:** <br>
- Global control registers are located in the SCU, and to access them, the safety ENDINIT function must first be unlock.<br><br>

- Note that when setting **TBASE** (23 bit), the high 4 bits of the target address are ignored (reserved).<br><br>

- **TBASE** field in **OTAR(0-31)** register is a 23-bit value that represents the base address of the overlayed target memory, such as NVM. The address
used should be right-shifted by 5 bits before being entered into the TBASE field.<br><br> 

- **OBASE** field in **RABR(0-31)** register is a 17-bit value that represents the base address of the overlay memory block for overlay memory, such as
LMU. The address used by the user should be right-shifted by 5 bits before being entered into the OBASE field.<br><br>

- Enabling or disabling the overlay function for each block using the **OVEN** bit in the **RABRx(0-31)** register.

- **OMEM** field in **RABR(0-31)** register is a 4-bit value used to select the type of overlayed memory.<br><br>
  0h-5h:Core 0/1/2/3/4/5 DSPR/PSPR<br>
  8h:LMU<br>
  9h:EMEM<br>
  Ah:EBU<br><br>
  
- **OMASK(0-31)**: Overlay Address Mask, <br><br> 
  000H, 128KB block size<br>
  800H, 64KB block size<br>
  9800H, 64KB block size<br>
  FFEH, 64B block size<br>
  FFFH, 32B block size<br><br>
  
- **OVCCON**: Overlay Control Register, <br><br>

- The register **OVCCON** have the bits write only (<u>return 0 if read</u>). <br>
   **OVCCON.CSEL0** is to apply settings to **CPU0**,
   **OVCCON.CSEL1** is to apply settings to **CPU1**,... <br><br>
   
- When **OVCCON.OVSTRT** set for each CPU selected with **CSEL**, <u>all the blocks</u> selected with **OVCx_OSEL** will be activated. In the selected CPUs all the blocks
deselected with **OVCx_OSEL** will be deactivated (*see Chapter 9.3.5.1 of User Manual, AURIX&trade;TC3XX*).<br><br>

- When **OVCCON.OVSTP** set for a selected CPU, will deactivate blocks with overlay. This will clear the **OVEN** field in **OVCx_RABRy**. <br><br> 
  
- **OVCCON.DCINVAL** invalidate the cache lines which are not changed. <br>  
Cache invalidation refers to the process whereby entries in cache are replaced or removed, ensuring that the CPU does not use stale or outdated data from the cache when performing read or write operations (thereby maintaining data integrity and consistency between the cache and the main memory). <br><br>
During invalidation, when OVCCON.DCINVAL is written with one, all the <u>unmodified (clean)</u> data cache lines in the selected cores are invalidated. if there are <u>modified (dirty)</u> cache lines, any modified data is saved to main memory before the cache line is invalidated. (A cache line is called “dirty” when the CPU changes the value in the cache but not in the remote memory). <br>
Data Cache invalidation can be combined with OVSTRT or OVSTP action. <br><br> 
   
- Overlay can be disabled or enabled individually for <u>each core</u> with **OVCENABLE** register.<br><br> 
  If **OVCENABLE.OVENx** bit is cleared no address redirection is permitted on Core x regardless of the remaining register settings (write to OVCENABLE register does not change any of the remaining register values.) <br><br> 
  
- Overlay should not be enabled or disabled using global OVCENABLE register if any of the blocks are enabled with RABRx.OVEN. Instead, OVSTRT or OVSTP should be used if concurrent block enabling or disabling is required (*see Note in Chapter 5.3.9.4 of User Manual, AURIX&trade;TC3XX*).<br>  
   
- **Concurrent Matches (Overlap)** in more than one enabled overlay block are not supported (*see Chapter 5.3.9.6 of User Manual, AURIX&trade;TC3XX*).<br><br> 

- **Using DSYNC**: <br> 
Special care needs to be taken to <u>synchronise</u> Overlay redirection change to the executed instruction stream if data consistency is required. External accesses that have not been completed, and may be buffered in the CPU, may still be affected by overlay configuration changes. Therefore, it is advised to ensure completion of all pending accesses (for example, by executing **DSYNC** instruction) before any overlay range is activated of deactivated.  
 
## Hardware setup     
This code example has been developed for the board AURIX&trade; KIT_A2G_TC375_LITE.

<img src="./Images/KIT_TC375_LIT.PNG" width="350" />   

## Implementation
Different Tests have been considered for the implementation. All tests are provided by the *Overlay_Test.h*, which employs the following approach:

- Disable Overlay.
- Copy Values from Target Address (PFlash) into Redirect Address (SRAM).
- Verification of the data written from Target Address (PFlash) to the Redirect Address.
- Enable Overlay (Configure Overlay).
- Write new contents of PFlash into the Buffer (ExpecteBufferContent). 
- Disable Overlay.
- Compare the new contents of the PFlash, stored in the <u>ExpecteBufferContent</u> with the contents of the <u>SRAM (DSPR/PSPR/LMU)</u>. 
If the value written in *ExpecteBufferContent* and *SRAM* will not be equal (even in one case) then the error would be happened and LED_ERROR (LED1), will be toggling, else LED_SUCCESS (LED2) will be toggling, which indicates overlay functionality (this step is provided in the function **Test_MemoryValidation( )**, in the *Overlay_Test.c*). 

*Test 1*: 

- Implementing Overlay with Registers Configuration <u>without</u> using **IfxCpu_enableOverlayBlock()** function, for 1 Block (32 Byte address range), where the Target Memory is PFlash bank (Non-cached), and the LMU(DLMU) as Overlay(Redirect) Memory.

*Test 2*: 

- Implementing Overlay Configuration using **IfxCpu_enableOverlayBlock()** function, where the Target Memory is PFlash bank (Non-cached), and the LMU(DLMU) as Overlay(Redirect) Memory.

*Disabling Interrupt is considered for Test 1, and Test 2, it can be applied also for other Tests, but it is not mandatory.*

*Test 3*: 
 
- Implementing Overlay Configuration, which is <u>multiple overlay blocks</u> <u>simultaneously</u> activated/deactivated, where the Target Memory is PFlash bank (Non-cached), and the MU(DLMU)(Non-cached) as Overlay(Redirect) Memory (2 concurrent Blocks with 32 Byte address range are provided in the code example, and can be applied also for more blocks).

**Important Note in Test3 **:<br>
There is a latency needed for overlay block disabling, where the effect is not instantaneous. So, before checking the disabling of overlay blocks, the instruction **isync()** and
**dsync()** are used for to add a latency (wait time) to observe the result. 

*Test 4*:  

- Implementing Overlay configuration for 1 block (32 Byte address range), where the Target Memory is PFlash bank (Non-cached), and the PSPR/DSPR (Non-cached) as the Overlay(Redirect) Memory. 
 
*Test 5*: 

- Implementing Overlay configuration for 2 blocks (32 Byte address range), where PFlash (Non-cached) as the Target Memory, and the LMU (DLMU) memory, and the PSPR/DSPR memory as the Overlay(Redirect) Memories (1 block in the LMU(DLMU)(Non-cached) Overlay Memory, and 1 other block in the PSPR/DSPR (Non-cached) Overlay (Redirect) Memory). 

*Test 6*: (Test Overlay with cache invalidate (cache enabled))

- Implementing Overlay configuration for 2 blocks, PFlash (Non-cached) as the Target Memory, and 1 block in the LMU(DLMU) (cached) Overlay Memory, and 1 other block in the PSPR/DSPR (cached) Overlay(Redirect) Memory. 

** Note **:<br>
When **OVCCON.DCINVAL** is written with one, all the unmodified (clean) data cache lines in the selected cores are invalidated. The data cache lines containing modified (dirty) data are not effected, and have no any effect on the buffer store operation. 

*Test 7*: 

- Implementing Overlay configuration for 2 <u>concurrent matched (Overlap)</u> blocks, where PFlash (Non-cached) as the Target Memory, and the LMU (DLMU) memory, and the PSPR/DSPR memory as the Overlay(Redirect) memories (1 block in the LMU(DLMU)(Non-cached) Overlay Memory, and 1 other block in the PSPR/DSPR (Non-cached) Overlay (Redirect) Memory).  

** Note **:<br>
When an address matches two, or more, of the enabled overlay blocks, an exception is raised and the memory access is <u>not performed</u>. A load operation with multiple matches on overlay ranges, raises a Data Access Synchronous Error **(DSE)** trap, and a store operation raises Data Access Asynchronous Error **(DAE)** trap (*see Chapter 5.3.9.6 of User Manual, AURIX&trade;TC3XX*).
<br>
In such case, relevant trap information registers are updated which are mentioned below:<br> 
Data Synchronous Trap Register (DSTR), Data Asynchronous Trap Register (DATR), Data Error Address Register (DEADD).

*Test 8*:

- Implementing Overlay configuration using SRAM (LMU) for both Target Memory and the Overlay (Redirect) Memory.<br>  
(Since, the Target address just can be in the PFlash, OLDA (virtual space), and Extended EBU Space (if present), so in this scenario, the Overlay is not enabled, and the ERROR is occurred). 

*Test 9*: 

- Overlay configuration for <u>2KB block size</u>, where PFlash (Non-cached) as the Target Memory, and the PSPR/DSPR as the Overlay(Redirect) Memory. 

**Note:** All tests are provided by the *Overlay_Test.h*. <br><br>

## Compiling and programming
Before testing this code example:  
- Connect the board to the PC through the USB interface  
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"  
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/micro.png" />  

## Run and Test 
The Global variable of *"g_testIdentifier"* is considered to choose and switch to different Tests, according to their Test_Number (*as shown below in the WinIDEA Debugger in AURIX-v1.10.4-L *). 

<img src="./Images/RUNandTEST.PNG" width="900" /> 

**Note:**
Doing the following order to run each test:

Reset &rarr; Resume (Run) &rarr; Suspend &rarr; Changing the value of *"g_testIdentifier"* &rarr; Resume (Run) again, and then see the result based on the Test_Number (1, 2, 3, 4, 5, ...9).
 
**Note:** 
To switch to different Tests, and also to exit from the Trap while it occurred, it is necessary to do *Reset*. 
<br><br>

**Trap triggered:**

As shown below DAE trap is triggered in Test 7(Target Overlap), (Data Access ASynchronous Error, Class = 4, TIN=3).

<img src="./Images/TRAPOverlap.PNG" width="900" /> 
<br><br>

**LEDs behavior in case of Success/Error**: 

(LED_SUCCESS LED2): ON &rarr; P00. 6: ON

(LED_ERROR LED1): ON &rarr; P00. 5: ON 

**The reaction for each test:**

<img src="./Images/OverlayReaction.PNG" width="700" />

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
