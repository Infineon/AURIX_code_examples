<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="TIMER_STM" URI="http://resources/4.1.6/app/TIMER_STM/0" description="Provides an accurate timer by using hardware STM timer. This can be used as a trigger input to other peripherals or to create an event" mode="NOTSHARABLE" version="4.1.6" minDaveVersion="4.2.4" instanceLabel="TIMER_STM_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../LWIP_GETH/v4_0_8/LWIP_GETH_0.app#//@requiredApps.0"/>
  <properties provideInit="true"/>
  <virtualSignals name="SR0_INT" URI="http://resources/4.1.6/app/TIMER_STM/0/vs_sr0" hwSignal="sr0_int" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="SR1_INT" URI="http://resources/4.1.6/app/TIMER_STM/0/vs_sr1" hwSignal="sr1_int" hwResource="//@hwResources.0" visible="true"/>
  <requiredApps URI="http://resources/4.1.6/app/TIMER_STM/0/appres_clock" requiredAppName="CLOCK" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK/v4_1_12/CLOCK_0.app#/"/>
  </requiredApps>
  <hwResources name="Channel" URI="http://resources/4.1.6/app/TIMER_STM/0/hwres_stm_channel" resourceGroupUri="peripheral/stm/*/common" mResGrpUri="peripheral/stm/*/common">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/STM0/STM0_0.dd#//@provided.0"/>
  </hwResources>
  <connections URI="http://resources/4.1.6/app/TIMER_STM/0/http://resources/4.1.6/app/TIMER_STM/0/vs_sr0/http://resources/4.1.6/app/INTERRUPT_CONFIG/0/vs_interrupt_in" sourceSignal="SR0_INT" targetSignal="REQ" srcVirtualSignal="//@virtualSignals.0">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../INTERRUPT_CONFIG/v4_1_6/INTERRUPT_CONFIG_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../INTERRUPT_CONFIG/v4_1_6/INTERRUPT_CONFIG_0.app#//@virtualSignals.0"/>
  </connections>
</ResourceModel:App>
