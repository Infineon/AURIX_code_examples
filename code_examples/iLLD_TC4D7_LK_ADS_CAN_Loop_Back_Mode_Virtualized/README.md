<img src="./Images/IFX_LOGO_600.gif" align="right" width="150" />  

# iLLD_TC4D7_LK_ADS_CAN_Loop_Back_Mode_Virtualized

**MCMCAN is used to exchange data between two nodes, implemented in the same device using Loop-Back mode.**  

## Device  
The device used in this example is AURIX&trade; TC4D7XP_A-Step_CC_COM    

## Board  
The board used for testing is the AURIX&trade; TC4D7XP_A-Step_CC_COM (KIT_A3G_TC4D7_LITE)  

## Scope of work  
A CAN message is sent from CAN node 0 to CAN node 1 using Loop-Back mode. After the CAN message transmission, an interrupt is generated and an LED is turned on to confirm successful message
transmission. Once the CAN message is successfully received by the CAN node 1, an interrupt is generated. Inside the interrupt service routine the content of the received CAN message is compared to
the content of the transmitted CAN message. In case of a success, another LED is turned on to confirm successful message reception.

## Introduction  
- This demo project provides user with information on how to implement a project to make it runnable within a Virtual Machine (VM) 
- For this reason an existing CAN loop-back AURIX&trade; TC4xx code example is modified so that it can be executed on Virtual Machine of CPU0 (e.g. CPU0-VM2)
- The resulting "virtualized" CAN loop-back project could be used also with Hypervisor (HV) Scheduler offered by the ADS project iLLD_TC4D7_LK_ADS_Virtualization_Hypervisor
- As the functionality is not changed, this demo will help user understand what needs to be changed in SW and in linker files of an existing project to make it runnable in a VM
- The virtualized CAN loop-back project can be built independently (e.g. symbols used here will not conflict with other VMs or Hypervisor Software (SW)), which is a major change when compared to all VMs and Hypervisor built together 

As there is no change in the functionality, request the user to refer the original project documentation for Introduction.

**Add on feature for better testability**

When compared to the original project, this CAN Loop-Back test is enhanced to operate in 2 ways, configurable with macro *CAN_EXTERNAL_LOOP_BACK_ENABLED* define in file *MCMCAN.c*:

- External Loop Back Disabled (*CAN_EXTERNAL_LOOP_BACK_ENABLED* is set to 0): it works exactly like the original CAN loop back code example, i.e. as pure internal loop-back mode (no physical CAN bus needed)
- External Loop Back Enabled (*CAN_EXTERNAL_LOOP_BACK_ENABLED* is set to 1): it works sending a CAN message on CAN0 connector of TriBoard and expecting this message to be received on the CAN1 connector of TriBoard. So the CAN0 and CAN1 CAN-lines must be connected on the board externally

Another added feature is that CAN-transmissions are put into a *while(1)-loop* in *Cpu0_Main.c* with an appropriate delay, so that the user can observe a continuous behaviour rather than transmit once and stop execution.

The project could be configured in 2 ways in order to be executed:

- as hosted VM (e.g. VM2): by enabling VM compilation by setting *IFX_CFG_COMPILE_AS_VM = 1* into file *Ifx_Cfg.h* and by selecting the VM by setting *LCF_LINKASVM = X (e.g. X = 2)*  into linker file *Lcf_Gcc_Tricore_Tc_Virtualized.lsl* OR *Lcf_Tasking_Tricore_Tc_Virtualized.lsl*
- as stand-alone application: by setting *IFX_CFG_COMPILE_AS_VM = 0* into file *Ifx_Cfg.h* and *LCF_LINKASVM = 0* into linker file *Lcf_Gcc_Tricore_Tc_Virtualized.lsl* OR *Lcf_Tasking_Tricore_Tc_Virtualized.lsl*

The "hosted VM" configuration must be executed in combination of a hypervisor software available with the project iLLD_TC4D7_LK_ADS_Virtualization_Hypervisor.

The "stand-alone" configuration could be directly executed as described in "Run and Test" section. 

The project is released by default with "stand-alone" configuration.

**NOTE** Please contact IFX representative for *Lcf_Tasking_Tricore_Tc_Virtualized.lsl*. By default only Gcc linker is available for the user.

## Hardware setup  
This code example has been developed for the board TC4D7XP_A-Step_CC_COM (KIT_A3G_TC4D7_LITE).

<img src="./Images/Kit Image Front.PNG" width="800" />  

## Implementation  

As there is no change in the functionality, it is requested to the user to refer the original iLLD_TC4D9_ADS_CAN_Loop_Back_Mode_Virtualized project documentation for Implementation. However, parts are repeated here for user convenience.

Application code can be separated into three segments:
- Initialization of the MCMCAN module with the accompanying node and filter initialization, implemented in the *initMcmcan()* function
- Initialization of the pins that are connected to the LEDs. LEDs are used to verify the success of a CAN message transmission and reception. This is done inside the *initLeds()* function
- Transmission of the configured CAN message, implemented in the *transmitCanMessage()* function

Additionally, two interrupt service routines (ISRs) are implemented:
- On TX interrupt, the LED1 is turned on to indicate successful CAN message transmission (implemented in *canIsrTxHandler()*)
- On RX interrupt, the ISR verifies the received CAN message and turns on the LED2 to indicate successful reception (implemented in *canIsrRxHandler()*)

**MCMCAN module initialization - copied from original project as is**

Initialization is performed in three phases:
- A default CAN module configuration is loaded into the configuration structure by using the function *IfxCan_Can_initModuleConfig()*. 
Afterwards, the initialization of the CAN module with the user configuration is done with the function *IfxCan_Can_initModule()*

- A default CAN node configuration is loaded into the configuration structure by using the function *IfxCan_Can_initNodeConfig()*. 
Initialization of the CAN nodes (CAN node 0 and 1) with the different CAN node ID values and definition of Loop-Back Mode usage for both nodes 
is done with the function *IfxCan_Can_initNode()*. CAN node 0 is defined as "source node" while CAN node 1 represents a "destination node". 
Additionally, an interrupt configuration for both "source node" and "destination node" is done in this phase

- The configuration structure of the CAN filter assigns the CAN filter 0 to the receive buffer 0. The acceptance criteria in this case is the matching message ID value. 
Afterwards, the initialization of the CAN filter with the user configuration is done with the function *IfxCan_Can_setStandardFilter()*

All functions used for the MCMCAN module, node and filter initialization are declared in the iLLD header *IfxCan_Can.h*.

**Initialization of the pins connected to the LEDs - copied from original project as is**

LEDs are used to verify the success of a CAN message transmission and reception. Before using the LEDs, the port pins to which the LEDs are connected must be configured.

- First step is to set the port pins to level "HIGH"; this keeps the LEDs turned off as a default state (*IfxPort_setPinHigh()* function)
- Second step is to set the port pins to push-pull output mode with the *IfxPort_setPinModeOutput()* function
- Finally, the pad driver strength is defined through the function *IfxPort_setPinPadDriver()*

All functions are declared in the iLLD header *IfxPort.h*.

**CAN message transmission - copied from original project as is**

Before a CAN message is transmitted, two messages need to be initialized. TX message (message that will be transmitted) is initialized with the predefined content. 
RX message (message where the received CAN message will be stored) is initialized with some invalid data (after successful CAN transmission the data will be replaced with the valid data).
- Initialization of both TX and RX messages is done by using *IfxCan_Can_initMessage()*
- A CAN message is transmitted by using the *IfxCan_Can_sendMessage()* function. A CAN message will be continuously transmitted as long as the returned 
status is *IfxCan_Status_notSentBusy* (this status occurs if there is a pending transmit request) 

All functions are declared in the iLLD header *IfxCan_Can.h*.

**Interrupt Service Routines (ISRs) - copied from original project as is**

Two interrupt services routines are implemented: one ISR that is triggered with the successful CAN message transmission and a second one that is triggered with the successful CAN message reception.

- TX interrupt service routine clears the pending interrupt flag with the *IfxCan_Node_clearInterruptFlag()* function and indicates that the CAN message  has been transmitted successfully by turning on LED1.
- RX interrupt service routine clears the pending interrupt flag by using *IfxCan_Node_clearInterruptFlag()* function and reads the received CAN message with the *IfxCan_Can_readMessage()* function. Afterwards, the received data is compared against the transmitted data. In case of success, the LED2 is turned on to indicate that the received message is correct.

The function *IfxCan_Node_clearInterruptFlag()* is declared in the iLLD header *IfxCan.h* while the function *IfxCan_Can_readMessage()* is declared in the iLLD header *IfxCan_Can.h*.

**New feature introduced respect to the original iLLD_TC4D9_ADS_CAN_Loop_Back_Mode_Virtualized project**

**NOTE** Similar configuration also works on TC4D7 LK board.
When *CAN_EXTERNAL_LOOP_BACK_ENABLED* is set to 1 then the project behaves exactly the same except with below differences:
- CAN0 Node0, and CAN1 Node0 are not configured to operate in loop-back mode, instead the pins are initialized as specified in the TriBoard UM
- CAN0 Node0 TX pin is configured for P33.8, and RX pin is configured for P33.7
- To activate CAN transceiver connected to CAN0 Node0, P00.2 is set as GPIO and set to logic 0
- CAN1 Node0 TX pin is configured for P00.0, and RX pin is configured for P00.1
- To activate CAN transceiver connected to CAN0 Node0, P00.1 is set as GPIO and set to logic 0

Due to these initializations, the CAN message is not looped back but instead transmitted on the bus. If the user has access to a CAN analyzer tool, then by connecting the tool to the CAN0 IDC10 port (refer TriBoard UM) one can observe message on the bus. For the demo program to work properly it is however necessary to connect CAN0 and CAN1 IDC10 ports.

**Modifications to project files to virtualize the application**

Following changes shall be performed to make the original CAN_Loop application runnable inside a VM2, and to be able to independently compile it: 

<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-qvuz{background-color:#FFC000;border-color:inherit;font-weight:bold;text-align:center;vertical-align:top}
.tg .tg-0thz{border-color:inherit;font-weight:bold;text-align:left;vertical-align:top}
.tg .tg-za14{border-color:inherit;text-align:left;vertical-align:top}
.tg .tg-j6zm{font-weight:bold;text-align:left;vertical-align:top}
.tg .tg-7zrl{text-align:left;vertical-align:top}
</style>
<table class="tg">
<thead>
  <tr>
    <th class="tg-qvuz">#</th>
    <th class="tg-qvuz">File</th>
    <th class="tg-qvuz">Change</th>
    <th class="tg-qvuz">Reason</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-0thz">1</td>
    <td class="tg-za14"><i>Ifx_Cfg.h</i></td>
    <td class="tg-za14">Updated configuration symbol <i>IFX_STM_RESOLUTION</i></td>
    <td class="tg-za14">This configuration symbol is used for setting the STM resolution during ISR configuration. 
    <br> New set is <i>IFX_STM_RESOLUTION</i> = 400000000 (400 MHz).<br> This change is needed since the STM frequency used by the project is 400 MHz, but it is not strictly mandatory for virtualization. </td>
  </tr>
   <tr>
    <td class="tg-0thz">2</td>
    <td class="tg-za14"><i>Ifx_Cfg.h</i></td>
    <td class="tg-za14">Added configuration symbol <i>IFX_CFG_COMPILE_AS_VM</i></td>
    <td class="tg-za14">This configuration symbol is used for compiling the application to be hosted as VM or to be executed alone without a hypervisor. 
    <br> By setting <i>IFX_CFG_COMPILE_AS_VM</i> = 1, the application is built to be hosted as VM. <br> By setting <i>IFX_CFG_COMPILE_AS_VM</i> = 0, the application is built to be executed alone without a hypervisor. </td>
  </tr>
  <tr>
    <td class="tg-j6zm">3</td>
    <td class="tg-7zrl"><i>iLLD</i></td>
    <td class="tg-7zrl">Used iLLD version 2.3.0</td>
    <td class="tg-7zrl">New iLLD function is needed in case of usage new TC1.8 instructions needed for support virtualization.</td>
  </tr>
  <tr>
    <td class="tg-j6zm">4</td>
    <td class="tg-7zrl"><i>Ifx_Ssw_Tc0.c</i><br><i>Ifx_Ssw_TcX.c</i></td>
    <td class="tg-7zrl">W.r.t. iLLD version 2.3.0 new start-up functions <i>_STARTX1</i> have been added <i>_STARTX1()(X=1,...,5)</i></td>
    <td class="tg-7zrl">This is an important change to ensure virtualization. <br>These new start-up functions are needed as hook to a Hypervisor scheduler aimed to trigger the VM2 of each cores.
    <br> <i>_STARTX1</i> function initializes the context save area, trap, interrupt vector tables, stack-pointer and global variables for each CPUX-VM1, X=0,1,...,5.</td>
  </tr>
  <tr>
    <td class="tg-j6zm">5</td>
    <td class="tg-7zrl"><i>MCMCAN.c</i></td>
    <td class="tg-7zrl">Added global debug counter.</td>
    <td class="tg-7zrl">A new debug counter "<i>g_vm2MainCounterCan</i>" has been added to monitor the CPU0-VM2 activity when scheduled by Hypervisor. It is not a mandatory change for supporting virtualization.</td>
  </tr>
    <tr>
    <td class="tg-j6zm">6</td>
    <td class="tg-7zrl"><i>MCMCAN.c</i></td>
    <td class="tg-7zrl">Added debug global debug counters.</td>
    <td class="tg-7zrl">New handlers "<i>g_CanIsrTxHandlerCalled</i>" and "<i>g_CanIsrRxHandlerCalled</i>" have been added to monitor the new continuously transmission over CAN. These variables are set to FALSE before triggering a transmit and set to TRUE within the respective ISR routines to verify the demo.</td>
  </tr>
  <tr>
    <td class="tg-j6zm">7</td>
    <td class="tg-7zrl"><i>MCMCAN.c</i></td>
    <td class="tg-7zrl">Added following settings: <br><i>g_mcmcan.canNodeConfig.interruptConfig.traco.vmId = IfxSrc_VmId_2</i>
    <br> <i>g_mcmcan.canNodeConfig.interruptConfig.reint.vmId= IfxSrc_VmId_2</i>
    </td>
    <td class="tg-7zrl">This is an important change to ensure virtualization. <br> It is important to set the interrupt source register VMID to VM2 since the original example is built to run in VM2</td>
  </tr>
  <tr>
    <td class="tg-j6zm">8</td>
    <td class="tg-7zrl"><i>MCMCAN.c</i></td>
    <td class="tg-7zrl">Added configuration symbol <i>CAN_EXTERNAL_LOOP_BACK_ENABLED</i> and related new code </td>
    <td class="tg-7zrl">The configuration symbol is used for enable new added code needed for activating actual CAN bus external loop back test.
    <br> <br> When <i>CAN_EXTERNAL_LOOP_BACK_ENABLED</i> is set to 1 then this demo program sends a CAN message on CAN0 (bus) and expects this message to be received on the CAN1 (bus). So the CAN0 and CAN1 CAN-lines must be connected on the board externally.
    <br> <br> If <i>CAN_EXTERNAL_LOOP_BACK_ENABLED</i> is set to 0, then it works exactly like the original CAN loop back project code example</td>
    <tr>
    <td class="tg-j6zm">9</td>
    <td class="tg-7zrl"><i>MCMCAN.c</i></td>
    <td class="tg-7zrl">Added new function <i>waitForNextMessage()</i></td>
    <td class="tg-7zrl">This function is needed to handle the CAN transmission loop adding a constant delay after each transmission.</td>
  </tr>
  <tr>
    <td class="tg-j6zm">10</td>
    <td class="tg-7zrl"><i>MCMCAN.c</i></td>
    <td class="tg-7zrl">Added debug Interrupt Service routine.</td>
    <td class="tg-7zrl">A new debug Interrupt Service routine "<i>Cpu0_Vm1_stm0_Isr()</i>" has been added to trigger a periodic ISR to monitor the CPU0-VM2 activity when scheduled by Hypervisor. It is not a mandatory change for supporting virtualization.</td>
  </tr>
  <tr>
    <td class="tg-j6zm">11</td>
    <td class="tg-7zrl"><i>Cpu0_Main.c</i></td>
    <td class="tg-7zrl">Function <i>transmitCanMessage()</i> moved inside the while loop.</td>
    <td class="tg-7zrl">In order to keep the VM2 transmitting continuously we need to move the transmission function insider the while loop and adding also delay function between two consecutive transmissions.</td>
  </tr>
  <tr>
    <td class="tg-j6zm">12</td>
    <td class="tg-7zrl"><i>Cpu1_Main.c</i></td>
    <td class="tg-7zrl">Added global debug counter.</td>
    <td class="tg-7zrl">A new debug counter "<i>g_Tc1vm2MainCounterCan</i>" has been added to monitor the CPU1-VM2 activity when scheduled by Hypervisor. It is not a mandatory change for supporting virtualization.</td>
  </tr>
  <tr>
    <td class="tg-j6zm">13</td>
    <td class="tg-7zrl"><i>Cpu5_Main.c</i></td>
    <td class="tg-7zrl">Added global debug counter.</td>
    <td class="tg-7zrl">A new debug counter "<i>g_Tc5vm2MainCounterCan</i>" has been added to monitor the CPU5-VM2 activity when scheduled by Hypervisor. It is not a mandatory change for supporting virtualization.</td>    
 </tr>
 <tr>
 <td class="tg-j6zm">14</td>
 <td class="tg-7zrl"><i>Lcf_Tasking_Tricore_Tc_Virtualized.lsl</i></td>
 <td class="tg-7zrl"> Added new linker file to be used with a Hypervisor environment. <br> <br> <br>The linker file <i>Lcf_Tasking_Tricore_Tc.lsl</i>, which was created with the original project with virtualization disabled, is retained only for reference.</td>
 <td class="tg-7zrl">This is an important change to ensure virtualization. <br>The linker has been added to properly allocating memory space needed  by selected VM (e.g. VM2 if linker configuration symbol <i>LCF_LINKASVM</i> = 2). <br><br> The linker file script shall produce an ELF/HEX binary file by using space in RAM and FLASH to be used only by selected VM. <br><br>The linker file script is crucial for allocating properly the code/data of selected VM without interfering with other areas dedicated to other VMs or Hypervisor.
 <br><br> Summary of relevant changes respect to original linker file:
 <br>   1- Updated definitions value of <i>LCF_DSPRX_START</i> and <i>LCF_DSPRX_SIZE, X= 0,...,5</i> for reducing RAM area to be used by selected VM (e.g. VM2 if configuration symbol is <i>LCF_LINKASVM</i> = 2, see next line for details)  
 <br>   2- Updated definitions value of <i>LCF_INTVECX_START, X= 0,...,5</i> for allocating Interrupt Tables to be used by selected VM (e.g. VM2 if configuration symbol is <i>LCF_LINKASVM</i> = 2)
 <br>   3- Updated definitions value of <i>LCF_TRAPVECX_START, X= 0,...,5</i> for allocating TRAP Tables to be used by selected VM (e.g. VM2 if configuration symbol is <i>LCF_LINKASVM</i> = 2)
 <br>   4- Added new definitions value of <i>LCF_STARTPTR_NC_CPUXY, X= 0,...,5; Y= 0,2</i> for handling the start-code start address to be used by selected VM (e.g. VM2 if <i>LCF_LINKASVM</i> = 2) and by Hypervisor
 <br>   5- Created new memory groups for partitioning the RAM and FLASH area and reserving area for selected VM (e.g. VM2 if <i>LCF_LINKASVM</i> = 2) (see Figure below)
 <br>   6- Used new memory groups definitions for handling ustack, istack, csa, data/code for selected VM. </td>
 </tr>
 <tr>
 <td class="tg-j6zm">15</td>
 <td class="tg-7zrl"><i>Lcf_Tasking_Tricore_Tc_Virtualized.lsl</i></td>
 <td class="tg-za14">Added configuration symbols <i>LCF_LINKASVM</i></td>
    <td class="tg-za14">This configuration symbol is used for configuring the memory layout when the application shall be linked as VM. 
    <br> By setting <i>LCF_LINKASVM</i> = x (e.g. x= 2), the application memory is linked for hosting VMx (e.g. VM2. <br> By setting <i>LCF_LINKASVM</i> = 0, the application memory is linked to be executed alone without a hypervisor.
  </td>
 </tr>
</tbody>
</table>

**Note**

No PROT/APU mechanisms has been applied in this project.

**Memory Allocation**

The linker file script is crucial for allocating properly the code/data of VM2 without interfering with other areas dedicated to other VMs (e.g. VM1) or Hypervisor (HV).
Figure below shows in blue the memory regions used by this application once this application will be executed as VM2 and other VMs are running and scheduled by an HV.

<img src="./Images/LinkerHVStandAlone.PNG" width="1300" />  

## Important summary note

Above table shows that no major changes to existing application are needed, except for: 
1. Changes to **startup** (listed in point 3 of above table) 
2. Changes to **linker file** (listed in point 8 of above table)

With these changes we are able to successfully convert an existing code example to run it inside a VM.


## Compiling and programming
Before testing this code example:  
- Connect the board to the PC through the USB interface. If you are using an external debugger then addition +12V power supply must be provided along with appropriate debug connector. 
- Connect the board to the PC through the USB interface
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/micro.png" />  

**Note**

This version of the CAN loop-back  project is a "virtualized" project which means that it needs also a Hypervisor project to be programmed. Please use ADS *illd_tc4d7_lk_ads_virtualization_hypervisor* project as "stand-alone" mode. Refer "Compiling and programming" section of the earlier mentioned hypervisor project. 

## Run and Test   
After code compilation and flashing the device, perform the following steps:
- Check that LED1 P03.9(1) is turned on (successful CAN message transmission by CAN node 0)
- Check that LED2 P03.10(2) is turned on (successful CAN message reception by CAN node 1)

However, please refer to ADS project TC4D7 Lite KIT Virtualization_Hypervisor, *Run and Test* section, in the "stand-alone" mode section, to follow the recommended flashing procedure and test observations.

<img src="./Images/LED.PNG" width="800" />  

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
