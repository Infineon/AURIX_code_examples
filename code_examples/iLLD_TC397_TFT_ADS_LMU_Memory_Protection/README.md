<img src="./Images/IFX_LOGO_600.gif" align="right" width="150" /> 
      
# iLLD_TC397_TFT_ADS_LMU_Memory_Protection
**CPU0 and CPU1 are handles read/write access permission to LMU0 from the bus master CPU0 and CPU1.** 

## Device  
The device used in this example is AURIX™ TC39xXX_B-Step.

## Board  
The board used for testing is AURIX&trade; APPLICATION KIT TC3X7 V2.0 (KIT_A2G_TC397_5V_TFT).

## Scope of work
The LMU Memory Protection Unit (LMU MPU) is focused on 2 CPUs (CPU0, CPU1), and handles read/write access permission to 
LMU0 from the bus master CPU0 and CPU1.
In this code example the BUS master CPU0 has always read/write permission of LMU0, while
bus master CPU1 does not have access permission to that area. Different test scenarios has been provided to
define access permission for LMU0.   

## Introduction
The LMU MPU mechanism provides protection (indicating over the BUS) against illegal or unintended bus accesses to the LMU. 
In this code example, the LMU MPU module is focused on CPU0, and CPU1, that handles read/write access permission to LMU0 from the bus master CPU0, and CPU1. The BUS 
master CPU0 has always read/write permission of local memory of CPU0, while bus master CPU1 does not have access permission to that area.

<img src="./Images/Introduction.PNG" width="620" /> 
<br><br><br>
  
- The LMU allows for the definition of 16 protected regions of SRAM memory. 

<img src="./Images/Regions.PNG" width="335" /> 

**LMU Access Enable Registers:**

The LMU implements the standard register protection scheme for peripheral registers using the *ACCEN0* and *ACCEN1* registers. 
This allows the LMU control registers to be protected from write accesses by untrusted masters. 

The registers *ACCEN0 / ACCEN1* are providing one enable bit for each possible 6 bit TAG ID encoding.

The Access Enable Register 0 (*ACCEN0*), and the Access Enable Register 1 (*ACCEN1*) control access for 
transactions to registers with the on chip bus master TAG ID. 

- *ACCEN0* and *ACCEN1* are protected by Safe Endinit while all other registers are Endinit protected. 

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
<br><br>

**Registers for LMU Memory Protection**

*- LMU MPU Registers for range definitions.* 

*- LMU MPU Registers for read/write accessing to ranges.* 

**Note:** The registers implementing the memory protection scheme are protected by the “safety endinit” function. 

**LMU MPU Registers for Range definitions:**

- 16 read and write protected regions with enables for reads and writes on a per bus master basis.

- Protection ranges of LMU are defined by the Lower address of the region, and the Upper address of the region. 
<br><br>
- The registers, *RGNLAx (x=0-15)* define the lower address of the region, *RGNUAx (x=0-15)* 
define the Upper address of the region of LMU. 

**Note** All the sixteen regions will cover all the addressing space of the LMU.

**Note:** It is to be noted that if an address space is not covered by a region, the access will not be granted to any master. 

**LMU MPU Registers for read/write accessing:**

- Two registers *RGNACCENWAx (x=0-15)* and *RGNACCENWBx (x=0-15)*, to individually select the master tags   permitted **write** access to the defined address range.
<br><br>
- Two registers *RGNACCENRAx (x=0-15)* and *RGNACCENRBx (x=0-15)* to individually select the master tags permitted **read** access to the defined address range.

**Note:** The protection scheme is based on the use of SRI tags to identify the master attempting the access
(TAG ID based protection), that Indicates which masters are allowed to reach and access to the region.
<br><br>

## Hardware setup     
This code example has been developed for the board AURIX&trade; KIT_A2G_TC397_TFT. 

<img src="./Images/HARDWARE_SETUP.PNG" width="480" />   

## Implementation
Five different Tests have been considered for the implementation:

*Test 1*: 

- All regions access by all cores Core0, Core1.

*Test 2*: For Non-Overlap Regions(Region 0 and Region 1 are non-verlap):

- Core0 access R/W to Region0 of LMU0.

- Core0 NOT-access R/W to Region1 of LMU0.

- Core1 NOT-access R/W to Region0 of LMU0.
 
- Core1 NOT-access R/W to Region1 LMU0.

*Test 3*: For Overlap Regions 
(Region 0 and Region 1 are overlap, and test has been done for access to non-overlap part):

- Core0 access R/W to Region0 of LMU0.
 
- Core0 NOT-access R/W to Region1 of LMU0.
 
- Core1 NOT-access R/W to Region0 of LMU0.
 
- Core1 access R/W to Region1 of LMU0.

*Test 4*: For Overlap Regions 
(Region 0 and Region 1 are overlap, and test has been done for access to overlap part):

- Core0 access R/W to Region0 of LMU0.
 
- Core0 NOT-access R/W to Region1 of LMU0.
 
- Core1 NOT-access R/W to Region0 of LMU0.
 
- Core1 access R/W to Region1 of LMU0.

*Test 5*: TEST for Alarm triggering. 

(Configuration is the same as Test2):

For Non-Overlap Regions(Region 0 and Region 1 are non-verlap):

- Core0 access R/W to Region0 of LMU0.

- Core0 NOT-access R/W to Region1 of LMU0.

- Core1 NOT-access R/W to Region0 of LMU0.
 
- Core1 NOT-access R/W to Region1 LMU0.
   

**Function for defining protection range for LMU0**

All functions are provided by the *LMU_MPU.h*, as shown below:

*define_LMU0_bus_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; defining the protection range for LMU0
<br>

**Function for enable/disable read/write access to the region of LMU0** <br>
All functions are provided by the *LMU_MPU.h*, as shown below:

*enable_LMU0_read_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; enable LMU0 read access to the region <br>
*enable_LMU0_write_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp; enable LMU0 write access to the region <br>
<br>
*disable_LMU0_read_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp; disable LMU00 read access to the region <br>
*disable_LMU0_write_protection_range()*: &nbsp;&nbsp;&nbsp;&nbsp;disable LMU00 write access to the region <br>
<br>

**Functions for waitTime()**:

Waiting phase in order to not interfere with the pipelining process which is reported as a problem in setting of the protection change.

When altering protection settings, it should be noted that, due to access pipelining and resynchronization delays
in the register block, a write to a memory address affected by the protection change occurring immediately after
the register write initiating the change may, or may not, be affected by the changed settings.

**Function for test configuration and execute for LMU0**<br>
All functions are provided by the *LMU_MPU_Test.h*.

- The *"g_testIdentifier"* global value is used to trigger test configuration using each Test_Number (1, 2, 3, 4, 5). 
<br><br>
     
The read/write access to region 0 (R0) and region 1 (R1) for each Test scenario to LMU0 memory is shown in the flowchart.    

<img src="./Images/FLOWCHARTLMU.PNG" width="1100" /> 

**Note:** Core0 and Core1 are *"SYNCHRONIZED"*, Core1 is waiting to core0 configuration to do execute, and core0 is waiting to core1 execute to do configuration.  
<br>
- The following functions are provided for doing synchronization:

             IfxCpu_emitEvent(&g_cpuSyncEvent);
             IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
             g_cpuSyncEvent = 0;    /* To make it possible to do Synchronization several times for CPU0 and CPU1  */

**Notes:**  
- Default: Configuration has been done by Core0, and Executing for allowing read and write has been done by Core1.

Core0: 
*(Ifx_TagID) TEST_CORE_CONFIG_TAG*

Core1: 
*(Ifx_TagID) TEST_CORE_EXECUTE_TAG*
<br><br>
- The same core cannot be used for the "configuration" and "execution".
<br><br>
- In case of conflict or **overlap**, if an access for one of the overlapping regions is enabled, it is allowed. 
<br><br>
- In the overlap and non overlap regions, the regions from (R2…R15), has configured the same as R1. 

**Access Protection Violation in LMU:**

If either the memory protection or register protection detect a protection violation, the following behavior will be observed:

- write access: No trap is triggered actually.<br> ALM7[15] raises when the CPU writes the area other than the write protection area.

**Notes:**  
SMU will react to the alarm activation as set in the configuration registers for that specific group and index.
The reaction set for the alarm ALM7[15] is interrupt generation. Once the CPU executes the interrupt service routine the LED P13.1 is turned on, signaling to the user the alarm activation.

- read access : DSE trap is triggered, (Data Access Synchronous Error, Class = 4, TIN=2).

In both cases, the error will be signalled to the SMU.

**The reaction for each test:**

<img src="./Images/REACTION.PNG" width="900" />

## Compiling and programming
Before testing this code example:  
- Connect the board to the PC through the USB interface  
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"  
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/micro.png" />  

## Run and Test 
The Global variable of *"g_testIdentifier"* is considered to choose and switch to different Tests, according to their Test_Number. 

<img src="./Images/RUNandTEST.PNG" width="900" /> 

**Note:**
Doing the following order to run each test:

Reset &rarr; Run &rarr; Stop &rarr; Changing the value of *"g_testIdentifier"* &rarr; Run again, and then see the result based on the Test_Number (1, 2, 3, 4, 5).
 
**Note:** 
To switch to different Tests, and also to exit from the Trap while it occurred, it is necessary to do *Reset*. 
<br><br>

**Trap triggered:**

As shown below DSE trap is triggered, (Data Access Synchronous Error, Class = 4, TIN=2.

<img src="./Images/TRAPCLASS4.PNG" width="900" /> 
<br><br>

**Alarm triggered:**

As shown below ALM7[15] raises in Test 5 (Write only). 

<img src="./Images/ALARM.PNG" width="900" /> 

**LEDs behavior in case of trap triggered/No trap triggered**: 

No Trap triggered (LED_SUCCESS): ON &rarr; P 13, 3: ON

Trap triggered (LED_SUCCESS): OFF &rarr; P 13, 3: OFF 

Alarm triggered: ON &rarr; P 13, 1: ON 

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
