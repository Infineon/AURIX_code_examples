<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="TIMER_EGTM" URI="http://resources/4.1.2/app/TIMER_EGTM/0" description="This APP using eGTM to implement timer." mode="NOTSHARABLE" version="4.1.2" minDaveVersion="4.2.4" instanceLabel="TFT_REFRESH_TIMER" appLabel="">
  <properties provideInit="true"/>
  <virtualSignals name="INT" URI="http://resources/4.1.2/app/TIMER_EGTM/0/vs_timer_egtm_interrupt" hwSignal="ccu0tc_irq" hwResource="//@hwResources.0" visible="true"/>
  <requiredApps URI="http://resources/4.1.2/app/TIMER_EGTM/0/appres_egtm_generic" requiredAppName="EGTM_GENERIC" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../EGTM_GENERIC/v4_1_2/EGTM_GENERIC_0.app#/"/>
  </requiredApps>
  <hwResources name="Timer Channel" URI="http://resources/4.1.2/app/TIMER_EGTM/0/hwres_egtm_ch" resourceGroupUri="peripheral/egtm/*/cluster/*/sv0/0/ch/*" solverVariable="true" mResGrpUri="peripheral/egtm/*/cluster/*/sv0/0/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/EGTM0/EGTM0_0.dd#//@provided.877"/>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="atom"/>
    </solverVarMap>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="atom"/>
    </solverVarMap>
  </hwResources>
  <connections URI="http://resources/4.1.2/app/TIMER_EGTM/0/http://resources/4.1.2/app/TIMER_EGTM/0/vs_timer_egtm_interrupt/http://resources/4.1.2/app/INTERRUPT_CONFIG/0/vs_interrupt_in" sourceSignal="INT" targetSignal="REQ" srcVirtualSignal="//@virtualSignals.0">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../INTERRUPT_CONFIG/v4_1_2/INTERRUPT_CONFIG_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../INTERRUPT_CONFIG/v4_1_2/INTERRUPT_CONFIG_0.app#//@virtualSignals.0"/>
  </connections>
</ResourceModel:App>
