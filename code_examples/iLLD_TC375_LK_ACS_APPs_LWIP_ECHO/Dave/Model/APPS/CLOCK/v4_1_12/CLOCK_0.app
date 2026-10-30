<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="CLOCK" URI="http://resources/4.1.12/app/CLOCK/0" description="APP to configure System and Peripheral Clocks." version="4.1.12" minDaveVersion="4.2.4" instanceLabel="CLOCK_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../ETHERNET_CONFIG/v4_0_8/ETHERNET_CONFIG_0.app#//@requiredApps.1"/>
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../TIMER_STM/v4_1_6/TIMER_STM_0.app#//@requiredApps.0"/>
  <properties singleton="true" provideInit="true" sharable="true"/>
  <virtualSignals name="SYSCLK" URI="http://resources/4.1.12/app/CLOCK/0/vs_syspll_sysclk" hwSignal="sysclk" hwResource="//@hwResources.1" required="false" visible="true"/>
  <virtualSignals name="EXTCLK0" URI="http://resources/4.1.12/app/CLOCK/0/vs_extclk_extclk0" hwSignal="extclk0" hwResource="//@hwResources.5" required="false" visible="true"/>
  <virtualSignals name="EXTCLK1" URI="http://resources/4.1.12/app/CLOCK/0/vs_extclk_extclk1" hwSignal="extclk1" hwResource="//@hwResources.5" required="false" visible="true"/>
  <hwResources name="Oscillator Circuit" URI="http://resources/4.1.12/app/CLOCK/0/hwres_clockctrl_osc" resourceGroupUri="peripheral/scu/0/clkctrl/osc" mResGrpUri="peripheral/scu/0/clkctrl/osc">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/SCU0/SCU0_0.dd#//@provided.1"/>
  </hwResources>
  <hwResources name="System PLL" URI="http://resources/4.1.12/app/CLOCK/0/hwres_clockctrl_syspll" resourceGroupUri="peripheral/scu/0/clkctrl/syspll" mResGrpUri="peripheral/scu/0/clkctrl/syspll">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/SCU0/SCU0_0.dd#//@provided.2"/>
  </hwResources>
  <hwResources name="Peripheral PLL" URI="http://resources/4.1.12/app/CLOCK/0/hwres_clockctrl_peripll" resourceGroupUri="peripheral/scu/0/clkctrl/perpll" mResGrpUri="peripheral/scu/0/clkctrl/perpll">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/SCU0/SCU0_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="Clock Control Unit" URI="http://resources/4.1.12/app/CLOCK/0/hwres_clockctrl_ccu" resourceGroupUri="peripheral/scu/0/clkctrl/ccu" mResGrpUri="peripheral/scu/0/clkctrl/ccu">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/SCU0/SCU0_0.dd#//@provided.3"/>
  </hwResources>
  <hwResources name="Clock Monitor" URI="http://resources/4.1.12/app/CLOCK/0/hwres_clockctrl_clkmon" resourceGroupUri="peripheral/scu/0/clkctrl/clkmon" mResGrpUri="peripheral/scu/0/clkctrl/clkmon">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/SCU0/SCU0_0.dd#//@provided.5"/>
  </hwResources>
  <hwResources name="External Clock" URI="http://resources/4.1.12/app/CLOCK/0/hwres_clockctrl_extclk" resourceGroupUri="peripheral/scu/0/clkctrl/extclk" mResGrpUri="peripheral/scu/0/clkctrl/extclk">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/SCU0/SCU0_0.dd#//@provided.4"/>
  </hwResources>
</ResourceModel:App>
