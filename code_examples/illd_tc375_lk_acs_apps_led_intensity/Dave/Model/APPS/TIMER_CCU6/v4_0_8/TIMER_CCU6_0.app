<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="TIMER_CCU6" URI="http://resources/4.0.8/app/TIMER_CCU6/0" description="Provides an accurate timer by using hardware CCU6 timer. This can be used as a trigger input to other peripherals or to create an event" mode="NOTSHARABLE" version="4.0.8" minDaveVersion="4.2.4" instanceLabel="TIMER_CCU6_0" appLabel="">
  <properties provideInit="true"/>
  <virtualSignals name="INT" URI="http://resources/4.0.8/app/TIMER_CCU6/0/vs_timer_ccu6_period_match_interrupt" hwResource="//@hwResources.0" visible="true" solverVariableName="sv1" solverVariableValue="t12pm"/>
  <requiredApps URI="http://resources/4.0.8/app/TIMER_CCU6/0/appres_clock" requiredAppName="CLOCK" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK/v4_1_8/CLOCK_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.8/app/TIMER_CCU6/0/appres_ccu6_generic" requiredAppName="CCU6_GENERIC" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CCU6_GENERIC/v4_0_4/CCU6_GENERIC_0.app#/"/>
  </requiredApps>
  <hwResources name="Timer Channel" URI="http://resources/4.0.8/app/TIMER_CCU6/0/hwres_CCU6_CCU6x_Timer" resourceGroupUri="peripheral/ccu6/0/*/sv0" solverVariable="true" mResGrpUri="peripheral/ccu6/0/*/sv0">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CCU60/CCU60_0.dd#//@provided.5"/>
    <solverVarMap index="4">
      <value variableName="sv0" solverValue="t12"/>
    </solverVarMap>
    <solverVarMap index="4">
      <value variableName="sv0" solverValue="t12"/>
    </solverVarMap>
  </hwResources>
  <connections URI="http://resources/4.0.8/app/TIMER_CCU6/0/http://resources/4.0.8/app/TIMER_CCU6/0/vs_timer_ccu6_period_match_interrupt/http://resources/4.0.4/app/ANALOG_CONVERTER_EVADC/0/vs_exttrig" sourceSignal="INT" targetSignal="TRG" srcVirtualSignal="//@virtualSignals.0">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../ANALOG_CONVERTER_EVADC/v4_0_4/ANALOG_CONVERTER_EVADC_0.app#//@virtualSignals.32"/>
    <targetVirtualSignal href="../../ANALOG_CONVERTER_EVADC/v4_0_4/ANALOG_CONVERTER_EVADC_0.app#//@virtualSignals.32"/>
  </connections>
</ResourceModel:App>
