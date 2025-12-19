<img src="./Images/IFX_LOGO_600.gif" align="right" width="150" />  

# iLLD_TC4D7_LK_ADS_ADC_Single_Channel

**The Enhanced Versatile Analog-to-Digital Converter (EVADC) is configured to measure an analog signal using queued request.** 

## Device  
The device used in this example is AURIX&trade; TC4D7XP_A-Step_MC_COM    

## Board  
The board used for testing is the AURIX&trade; TC4D7 lite Kit (KIT_A3G_TC4D7_LITE)

## Scope of work  
 An analog input channel is continuously converted using the queued mode.
 The input value is determined using the microcontroller’s supply voltage, ground level or letting the analog pin open and floating. Three LEDs are used, each indicating a voltage interval. 
 The ADC value is read in polling mode inside the Cpu0_Main.c while loop.
## Introduction  
The AURIX™ microcontrollers provide a series of analog input channels (up to 16 for each ADC) connected to a cluster of Analog/Digital Converters (up to 12) using the Successive Approximation Register (SAR) principle. Each converter of the ADC cluster is represented as a group and can operate independently of the others

Analog/Digital conversions can be requested by one request source:

- Queued request source, specific to a single group
- A queued source can issue conversion requests for an arbitrary sequence of input channels. The  channel numbers for this sequence can be freely programmed.

The trigger for the conversion via the queued source can be sent:

- Once (by another external module)
- On a regular time base (by an external timer)
- Permanently (by using the refill option)  

## Hardware setup  
This code example has been developed for the board KIT_A3G_TC4D7_LITE 

<img src="./Images/EvalKit_AURIX_TC4x7_Lite_V1_TOP.png" width="800" />  

## Implementation  
SWR-TMADC-001: The software shall provide functionality to initialize, configure, and read a single 
channel of the Triggered Modular Analog-to-Digital Converter (TMADC) peripheral.

The software shall use the Infineon Low-Level Driver (iLLD) functions for all hardware abstraction and peripheral interactions.

The software shall provide a function `initTMADC` that serves as the main entry point for initializing the TMADC peripheral.

The initialization sequence shall first configure the TMADC module and then the specific ADC channel.

The software shall enable the global ADC module clock before any other configuration is performed.

The software shall configure and initialize TMADC module 0 (`IfxAdc_TmadcModule_0`).

The TMADC module configuration shall enable the start-up calibration feature (`calEnable = 1`) to ensure measurement accuracy as specified in the device datasheet.

The software shall configure and initialize TMADC Channel 0 (`IfxAdc_TmadcChannel_0`).

The channel shall be configured to operate in continuous conversion mode (`IfxAdc_TmadcOpMode_continuous`).

The channel shall be assigned to use SAR Core 0 (`IfxAdc_TmadcSarCore_0`) for its conversions.

The analog input sampling time for the channel shall be set to 100 nanoseconds. This value must be compliant with the device's electrical characteristics for the intended operating voltage.

The conversion result for the channel shall be stored in Result Register 0 (`IfxAdc_TmadcResultReg_0`).

The channel's result register shall be configured in "wait-for-read" mode (`waitForRead = 1`) to prevent a new conversion result from overwriting the register before it has been read by the application.

The channel shall be configured to generate a service request using Service Request Node 0 (`IfxAdc_TmadcServReq_0`) when a new conversion result is available.

The channel shall be configured *not* to generate service requests for error events or boundary check violation.

After all module and channel configurations are complete, the software shall start the TMADC module to begin the conversion process.

The software shall provide a function `resultADC` to read the latest conversion result from the configured TMADC channel.

The `resultADC` function shall return the raw, integer value of the ADC conversion.


## Compiling and programming
Before testing this code example:  
- Power the board through the dedicated power connector 
- Connect the board to the PC through the USB interface
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/micro.png" />  

## Run and Test   
After code compilation and flashing the device, verify the behavior of the ADC AN0 channel moving the potentiometer on the board and reading adc_read in the watch view 

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
