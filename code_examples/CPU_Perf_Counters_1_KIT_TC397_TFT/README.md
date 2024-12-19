<img src="./Images/IFX_LOGO_600.gif" align="right" width="150" />  

# CPU_Perf_Counters_1_KIT_TC397_TFT
Measure code performance via the CPU performance counters.

## Device  
The device used in this example is AURIX&trade; TC39xTP_A-Step.

## Board  
The board used for testing is the AURIX&trade; TC397 TFT (KIT_A2G_TC397_5V_TFT).

## Scope of work  
The CPU performance counters are counting the number of instructions, clock ticks and multi counters ticks. They are used to measure the run-time of a c-function. The result is stored in a global variable.

## Introduction  
The CPU performance counters are part of the TriCore&trade; CPU core and need to be accessed via the On-Chip Debug Support (OCDS) module, which is used for debugging and performance optimization.

## Hardware setup  
This code example has been developed for the board KIT_A2G_TC397_TFT.
 
<img src="./Images/TC397_TFT_Top_View.png" width="500" /> 

## Implementation  

### Running CPU performance counters

The function *runCpuPerfCounters()* measures the run-time of the function *loop()*, which is placed between the *IfxCpu_resetAndStartCounters()* and *IfxCpu_stopCounters()*: 
- *IfxCpu_resetAndStartCounters()* to start CPU performance counters. A parameter is specifying the counter mode:
  - *Normal* mode: The counters increment on their respective triggers
  - *Task* mode: Allow an additional gating from the debug unit which can filter data based on specific criteria
- *IfxCpu_stopCounters()* to stop and return counters values

**Note**: For using the performance counters, the On-Chip Debug System has to be enabled. This is ensured by the debugger itself, therefore the example has to be tested within an active debug session. 

## Compiling and programming  
Before testing this code example:  
- Power the board through the dedicated power connector
- Connect the board to the PC through the USB interface  
- Build the project using the dedicated Build button <img src="./Images/build_activeproj.gif" /> or by right-clicking the project name and selecting "Build Project"  
- To flash the device and immediately run the program, click on the dedicated Flash button <img src="./Images/Widget_Flash.png" width="16"/>

## Run and Test
After code compilation and flashing the device, perform the following steps:
- Add the result of the measurement (*g_perfCounts*) to the Watch View of the debugger
- Check the performance of the function *loop()* through the values stored in the structure *g_perfCounts* displayed in the Watch View:
  - Instruction Counter
  - CPU Clock Cycle Counter
  - Counter 1 (implementation specific)
  - Counter 2 (implementation specific)
  - Counter 3 (implementation specific)

<img src="./Images/Run_and_Test.png" width="600" />

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