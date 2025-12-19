<img src="./Images/IFX_LOGO_600.gif" align="right" width="150" />  

# OneEye_DAS_Shell_1_KIT_AURIX_TC375_LK

**Shell via DAS interface using Infineon GUI Designer(OneEye)**  

## Device  
The device used in this example is AURIX&trade; TC37xTP_A-Step.  

## Board  
The board used for testing is the AURIX&trade; TC375 lite Kit (KIT_A2G_TC375_LITE). 

## Scope of work  
A Shell is used to parse a command line and call the corresponding command execution. An Infineon GUI Designer(OneEye) pipe is used to interface Infineon GUI Designer with the Shell through the DAS interface.
After configuring the Infineon GUI Designer DAS interface, the Shell from iLLDs is used to interpret and manage commands like "info" or "help". The example creates an Infineon GUI Designer pipe and the corresponding DPipe that is used to interface the shell.

## Introduction  
**Infineon GUI Designer** is a GUI that enables the creation of interactive Graphical User Interface. Graphical elements can be drag from a toolbox and drop onto the GUI. The behavior of the created GUI can be customized. Different communication interfaces like UART, Ethernet, CAN, DAS can be used to interact with the embedded system

The **DAS** (Device Access Server) can be used in line with Infineon Microcontroller Starter Kits, Application Kits and DAP MiniWiggler to access the micro controller resources.  

**Recommendation:** It is recommended to go through some of the basic tutorials listed in the help embedded in Infineon GUI Designer (Menu: Help &rarr; Infineon GUI Designer help). This enables a quicker ramp-up in the Infineon GUI Designer concept and ensure a nice journey with Infineon GUI Designer

## Hardware setup  
This code example has been developed for the board KIT_A2G_TC375_LITE.  

The board should be connected to the PC through the USB port.  

<img src="./Images/board_1.png" width="300" />  

## Implementation - AURIX  
**Configuring the Infineon GUI Designer pipe**
An Infineon GUI Designer pipe (*Ifx_Oe_DasPipe*) is a special object that is recognized by Infineon GUI Designer and enables streaming of data between Infineon GUI Designer and the microcontroller. The Infineon GUI Designer pipe is initialized with *Ifx_Oe_DasPipe_init()*. The size parameter passed for the configuration corresponds to the buffer allocated for the data transmission, in this example 2 buffers of 512 bytes are allocated, one for TX and one for the RX direction. The *ifx_oe_daspipe.h* file can be found in the Libraries\OneEye directory.

**Configuring the DPipe**
A DPipe is initialized with *Ifx_Oe_DasPipe_stdIfDPipeInit()*. The DPipe enables access by the shell to the Infineon GUI Designer Pipe.  

**Configuring the Shell**
The shell is initialized with *Ifx_Oe_Shell_init()* passing a pointer to the previously initialized DPipe.

**Running the Shell**
The shell is executed in the background loop by calling *Ifx_Oe_Shell_process()*.

**Enabling the OneEye library**
The OneEye library must be enabled by adding the following line to *Ifx_Cfg.h*:
*#define IFX_CFG_OE_AL_UC IFX_CFG_OE_AL_UC_AURIX_ILLD*

## Compiling and programming  
Before testing this code example:  
- Connect the board to the PC through the USB interface  
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"  
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/micro.png" />  

## Run and Test   

For this training, the Infineon GUI Designer application is required for visualizing the values. Infineon GUI Designer can be opened inside the AURIX&trade; Development Studio using the following icon:  

<img src="./Images/oneEye1.png" width="800" />  

Clicking the Infineon GUI Designer icon automatically opens the OneEye configuration for the active project. If no configuration exists, it is created by AURIX&trade; Development Studio.  

## Implementation - Infineon GUI Designer  

In this training, the OneEye configuration is provided inside the Libraries folder. The following steps are needed to configure the oscilloscope from a brand-new configuration.  

**Setup Infineon GUI Designer for editing**  

Select the Infineon GUI Designer menu *Options &rarr; Edit mode* (if not already checked) to enable the edit mode.
Select the Infineon GUI Designer menu *View &rarr; Browser box*, *View &rarr; Property box* , *View &rarr; Tool box* (if not already checked) to display the browser, property box, and tool box.
Close the Welcome screen if it was shown.

<img src="./Images/oneEye2.png" width="800" />  

**Configuring the DAS interface**  

When the OneEye configuration is created by ADS, it is already setup with a DAS interface.  
Select the DAS interface in the Browser box (1).  

Notice the *system-key* {ADS} that enables the connection to the device in parallel with the ADS debugger  

<img src="./Images/oneEye3.png" width="800" />  

**Create a debug box to get access to variables from the .elf file**  
A debugBox item is already setup by default when ADS creates the OneEye configuration, preconfigured with the *project.elf* file path.  
Select the DAS interface in the Browser box (1).  
Set the id property to *elf*, which enables to group variables into the signal tree later.  
**Note**: this value is not set by default by ADS.  

<img src="./Images/oneEye4.png" width="700" />  

**Open the debug box viewer and connect to the device**  
Select the Infineon GUI Designer menu *View &rarr; Debug box viewer* (if not already checked) to display the debug box. Select the debug box with the id *(elf)* (1) if not yet selected by default.  
Note that the debug box enables the selection of the *.elf* file to be used to get information about the variables.  
The Filter field (2), enables to filter variables by name. E.g. in this example, entering *g_* will filter for global variables.  

To enable the connection with the microcontroller and have read / write access to variables, check the *DAS connection status* box (3).  

<img src="./Images/oneEye5.png" width="700" />  

**Create signals for the Pipe**  
In the debug box, search for the *g_oneEyeDasPipe* (1) variable, right click on it and select *Create pipe for: g_oneEyeDasPipe*. The watch should appear on the right side of the debug box (2). Watches are periodically polled for new values on the micro controller.
Two signals are also automatically created to access the pipe (3), one for the Infineon GUI Designer to microcontroller direction (*ToTarget*), and one for the microcontroller to Infineon GUI Designer direction (*FromTarget*).

<img src="./Images/oneEye6.png"    width="700" />  

The created signals should appear in the browser box under the “signals.elf” group

**Create a text box to display the shell text**
Drag and drop a *textEdit* item from the toolbox onto the layout, and set its *data-in* property to *elf.g_oneEyeDasPipe.FromTarget*. Set the update-method to all-on-new-data.

<img src="./Images/oneEye7.png" width="700" />  

**Create a line edit to enter key stroke to the shell**

Drag and drop a *lineEdit* item from the toolbox onto the layout, and set its data-out property to *elf.g_oneEyeDasPipe.ToTarget*. Check the capture-key property to enable each key stroke to be send.

<img src="./Images/oneEye8.png" width="700" />  

**Test the shell interface**
The shell textbox should display the *Hello World !* text (1), if it is not the case, check that the *DAS connection status* is checked in the debug box viewer.
Enter *info* in the ToTarget lineEdit field (2) and press *ENTER*, the microcontroller will execute the *printShellInfo()* function and should answer as below to acknowledge the command. 

<img src="./Images/oneEye9.png" width="700" />  

Save your configuration with CTRL+S.
Exit the edit mode with the Infineon GUI Designer menu *Options &rarr; Edit mode* and close the *Debug box viewer* to only see the GUI (3)

<img src="./Images/oneEye10.png" width="250" />  

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
