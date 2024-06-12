

# iLLD_TC375_ADS_BUS_Memory_Protection_LiteKit
**CPU0 and CPU1 are handles read/write access permission to the local memory of CPU0 from the bus master CPU1.** 

## Device  
The device used in this example is AURIX™ TC37xTP_A-Step.

## Board  
The board used for testing is the AURIX™ TC375 lite Kit (KIT_A2G_TC375_LITE).

## Scope of work
The BUS Memory Protection Unit (BUS MPU) is focused on 2 CPUs (CPU0, CPU1), and handles “read/write” access permission to 
the local memory of CPU0 (DSPR0/PSPR0/DLMU0/Pflash0) from the bus master CPU1.
In this code example the BUS master CPU0 has always “read/write” permission of local memory of CPU0, while
bus master CPU1 does not have access permission to that area. Different test scenarios has been provided to
define access permission for each local memories.   

## Introduction
The BUS MPU mechanism provides protection (indicating over the BUS) against illegal or unintended bus accesses to the local memory (PSPR,
DSPR, DLMU, SRAM, and the local PFlash Bank (LPB)) of each cores. In this code example, the BUS MPU module is focused on CPU0, and CPU1, 
that handles “read/write” access permission to the local memory of CPU0 (DSPR0/PSPR0/DLMU0/Pflash0) from the bus master CPU1. The BUS 
master CPU0 has always “read/write” permission of local memory of CPU0, while bus master CPU1 does not have access permission to that area.

  <img src="./Images/SCOPE_WORK.PNG" width="620" /> 
  
The Bus MPU comprises of:

- 8 read and write protected regions of scratch pad memory (PSPR, DSPR)
 with enables for reads and writes on a per bus master basis. 

- 8 read and write protected regions of DLMU with enables for reads and writes on a per bus master basis.

- Individual master read enables for accesses to the local PFlash Bank (LPB).

<img src="./Images/Regions.PNG" width="335" /> 

**Note:** All safety protection registers are protected from modification by the safety_endinit signal. 

**BUS MPU Registers for Range definitions:**

**SPR**

- Protection ranges of PSPR/DSPR are defined by the Lower address of the region, and the Upper address of the region. 
<br><br>
- The registers, *CPUx_SPR_SPROT_RGNLAi* (i=0-7) to define the lower address of the region, *CPUx_SPR_SPROT_RGNUAi* 
(i=0-7) to define the Upper address of the region of PSPR/DSPR. 

**DLMU**

- Protection ranges of DLMU are defined by the Lower address of the region, and the Upper address of the region. 
<br><br>
- The registers, *CPUx_DLMU_SPROT_RGNLAi* (i=0-7) to define the Lower address of the region, *CPUx_DLMU_SPROT_RGNUAi*
 (i=0-7) to define the Upper address of the region of DLMU. 

**PFlash**

- Entire local PFlash is defined for the region, and no registers are used for defining the Lower address and the 
Upper address. 

**Note:** The protection scheme is based on the use of SRI tags to identify the master attempting the access
(TAG ID based protection), that Indicates which masters are allowed to reach and access to the region.
<br><br>

**Bus Master TAG Assignments:**

Each master interface on the System Peripheral Bus and on the SRI Bus is assigned to a 6-bit identification 
number, the master TAG number identifying up to 64 masters (*see Table 85 of User Manual, AURIX&trade;TC3XX*).
<br>
- *Access enable register:*

Access enable register specify which of the possible master, allows to perform access and which one getting blocked. this register controls access for transactions with the on chip bus master TAG ID, and provides one enable bit for
each possible 6-bit TAG ID (* for the TAG ID <-> master mapping, see On Chip Bus chapter of User Manual, AURIX&trade;TC3XX, which is provided in Infineon website.*).

- The mapping of TAG IDs to Access Enable register is: 

<img src="./Images/TAGID.PNG" width="740" /> 

*For example:*

CPU0 TAG-Number= 000001B, (1D) (Non-safe TAG ID) and 000010B, (2D) (Safe TAG ID).
<br>
CPU1 TAG-Number= 000101B, (5D) (Non-safe TAG ID) and 000110B, (6D) (Safe TAG ID).

This makes it possible for software debug to distinguish which master 
has performed the current transaction, and which master is active in the BUS.
<br><br><br>
**BUS MPU Registers for read/write accessing:**

**SPR**

- Each region of PSPR/DSPR may be enabled for reads/writes on a per bus master basis using the register 
*CPUx_SPR_SPROT_RGNACCENAi_R/W* (i=0-7) (Masters 31-0) and *CPUx_SPR_SPROT_RGNACCENBi_R/W* (i=0-7) (Masters 63-32). 
<br>    
- A read/write access to the PSPR/DSPR memory is seen as valid if the master tag of the access is enabled in the 
*CPUx_SPR_SPROT_RGNACCENi_R/W*  register and the address of the access satisfies the following relationship:
*CPUx_SPR_SPROT_RGNLAi <= address < CPUx_SPR_SPROT_RGNUAi*.    
- If any of these conditions are not satisfied, the access is seen as invalid. 
    
**DLMU**

- Each region of DLMU may be enabled for reads/writes on a per bus master basis using the register 
*CPUx_DLMU_SPROT_RGNACCENAi_R/W* (i=0-7) (Masters 31-0) and *CPUx_DLMU_SPROT_RGNACCENBi_R/W* (i=0-7) (Masters 63-32).
<br><br>
- A read/write access to the DLMU memory is seen as valid if the master tag of the access is enabled in the 
*CPUx_ DLMU_SPROT_RGNACCENi_R/W* register and the address of the access satisfies the following relationship:
*CPUx_DLMU_SPROT_RGNLAi <= address < CPUx_DLMU_SPROT_RGNUAi* 
- If any of these conditions are not satisfied, the access is seen as invalid. 
    
**PFlash**

- The local Pflash bank is protected from read accesses on a per master basis.
<br>
- The individual masters allowed to read the LPB are selected by the register *CPUx_LPB_SPROT_ACCENA _R* 
(i=0-7) (master 31-0) and *CPUx_LPB_SPROT_ACCENB _R* (i=0-7) (master 63- 31) registers.

**Note:** 
In BUS MPU we do not need to *"Enable the Memory Protection"*. Protection is configured using *"Access Enable Registers"*. 

## Hardware setup     
This code example has been developed for the board AURIX&trade; KIT_A2G_TC375_LITE. 

<img src="./Images/KIT_TC375_LIT.PNG" width="300" />   

## Implementation
Three different Tests have been considered for the implementation:
 
*Test 1*: 

- All regions access by all cores Core0, Core1.

*Test 2*: For Non-Overlap Regions 

- Core0 access R/W to Region0 of DSPR0/PSPR0/DLMU0/Pflash0.

- Core0 NOT-access R/W to Region1 of DSPR0/PSPR0/DLMU0/Pflash0.

- Core1 NOT-access R/W to Region0 of DSPR0/PSPR0/DLMU0/Pflash0.
 
- Core1 NOT-access R/W to Region1 of DSPR0/PSPR0/DLMU0/Pflash0.

*Test 3*: For Overlap Regions 

- Core0 access R/W to Region0 of DSPR0/PSPR0/DLMU0/Pflash0.
 
- Core0 NOT-access R/W to Region1 of DSPR0/PSPR0/DLMU0/Pflash0.
 
- Core1 NOT-access R/W to Region0 of DSPR0/PSPR0/DLMU0/Pflash0.
 
- Core1 access R/W to Region1 of DSPR0/PSPR0/DLMU0/Pflash0.

**Note:** Test 3 Execute doing for both *"Non-overlap"* and *"overlap"* areas. 

**Function for defining protection range for each local memory**

All functions are provided by the *BUS_MPU.h*, as shown below:

*define_SPR0_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; defining the protection range for DSPR0/PSPR0
<br>
*define_DLMU0_bus_protection_range()*: &nbsp;&nbsp;&nbsp; defining the protection range for DLMU0
<br>
*define_LPB0_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; defining the protection range for PFlash0
<br><br>
**Function for enable/disable read/write access to the region**

All functions are provided by the *BUS_MPU.h*, as shown below:

*enable_SPR0_read_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; enable SPR0 read access to the region <br>
*enable_SPR0_write_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp; enable SPR0 write access to the region <br>
*disable_SPR0_read_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp; disable SPR0 read access to the region <br>
*disable_SPR0_write_bus_protection_range()*: &nbsp;&nbsp;&nbsp; disable SPR0 write access to the region <br>
<br>
*enable_DLMU0_read_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp; enable DLMU0 read access to the region <br>
*enable_DLMU0_write_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp;enable DLMU0 write access to the region <br>
*disable_DLMU0_read_bus_protection_range()*: &nbsp;&nbsp;&nbsp;disable&nbsp; DLMU0 read access to the region <br>
*disable_SPR0_write_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; disable DLMU0 write access to the region <br>
<br>
*enable_LPB0_read_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp; enable LPB0 read access to the region <br>
*disable_LPB0_read_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp;disable LPB0 read access to the region <br>
<br>
**Function for test configuration and execute for each local memories**

All functions are provided by the *BUS_MPU_Test.h*.

- The *"g_testIdentifier"* global value is used to trigger test configuration using each Test_Number (1, or 2,...,10, or 11). 
<br><br>
     
The read/write access to region 0 (R0) and region 1 (R1) for each Test scenario to the all local memories of 
CPU0 is shown in the flowchart.    

<img src="./Images/FLOWCHART.PNG" width="800" /> 

**Note:** Core0 and Core1 are *"SYNCHRONIZED"*, Core1 is waiting to core0 configuration to do execute, and core0 is waiting to core1 execute to do configuration.  
<br>
- The following functions are provided for doing synchronization:

             IfxCpu_emitEvent(&g_cpuSyncEvent);
             IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
             g_cpuSyncEvent = 0;    /* To make it possible to do Synchronization several times for CPU0 and CPU1  */

**Note:**  (Default: Configuration has been done by Core0, and Executing for allowing read and write has been done by Core1).
<br><br>
**Note:**  In case of conflict or overlap, if an access for one of the overlapping regions is enabled, it is allowed. 

**The reaction of access to the region which is Not BUS MPU protected:**

If try to read/write access to the BUS from the region that is not protected, the following behavior will be observed:

- write access: Silently ignored, and No trap is triggered actually.<br> ALMx [1] is triggered (*additional information can be found in User Manual Appendix TC37X, TC37x_appx_um_v2.0.pdf, which is provided in Infineon website.*). 
<br><br> 
- read access : DSE trap is triggered, (Data Access Synchronous Error, Class = 4, TIN=2).<br>
ALMx [1] alarm is triggered and *LBE* bit of *DSTR* register is set. *LBE* bit set leads to DSE trap (*see On-chip Bus chapter under SRI errors in the User Manual, AURIX&trade;TC3XX, which is provided in Infineon website.*).

## Compiling and programming
Before testing this code example:  
- Connect the board to the PC through the USB interface  
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"  
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/micro.png" />  

## Run and Test 
The Global variable of *"g_testIdentifier"* is considered to choose and switch to different Tests, according to their Test_Number. 

<img src="./Images/RUN.PNG" width="950" /> 

**Note:**
Doing the following order to run each test:

Reset &rarr; Run &rarr; Stop &rarr; Changing the value of *"g_testIdentifier"* &rarr; Run again, and then see the result based on the Test_Number (1, or 2,...,10, or 11).
 
**Note:** 
To switch to different Tests, and also to exit from the Trap while it occurred, it is necessary to do *Reset*. 
<br><br>

**LEDs behavior in case of trap triggered/No trap triggered**: 

No Trap triggered (LED_SUCCESS): ON &rarr;P00.6 (LED2) : ON

Trap triggered (LED_SUCCESS): OFF &rarr;P00.6 (LED2) : OFF 

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
