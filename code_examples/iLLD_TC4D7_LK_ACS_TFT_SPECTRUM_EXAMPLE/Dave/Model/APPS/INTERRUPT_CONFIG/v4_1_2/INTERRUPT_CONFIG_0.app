<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="INTERRUPT_CONFIG" URI="http://resources/4.1.2/app/INTERRUPT_CONFIG/0" description="This APP configures an interrupt. Configuration can be done by signal connections and GUI parameters" mode="NOTSHARABLE" version="4.1.2" minDaveVersion="4.2.4" instanceLabel="TFT_REFRESH_INTERR" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="REQ" URI="http://resources/4.1.2/app/INTERRUPT_CONFIG/0/vs_interrupt_in" hwSignal="in" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../TIMER_EGTM/v4_1_2/TIMER_EGTM_0.app#//@connections.0"/>
  </virtualSignals>
  <virtualSignals name="INT" URI="http://resources/4.1.2/app/INTERRUPT_CONFIG/0/vs_interrupt_out" hwSignal="out" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="global" URI="http://resources/4.1.2/app/INTERRUPT_CONFIG/0/vs_cpu_prio_global" hwSignal="global" hwResource="//@hwResources.1"/>
  <requiredApps URI="http://resources/4.1.2/app/INTERRUPT_CONFIG/0/appres_cpu" requiredAppName="CPU_CORE" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CPU_CORE/v4_1_2/CPU_CORE_0.app#/"/>
  </requiredApps>
  <hwResources name="Interrupt SRN" URI="http://resources/4.1.2/app/INTERRUPT_CONFIG/0/hwres_interrupt" resourceGroupUri="peripheral/int/0/srn/*" mResGrpUri="peripheral/int/0/srn/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/INT0/INT0_0.dd#//@provided.6"/>
  </hwResources>
  <hwResources name="Interrupt" URI="http://resources/4.1.2/app/INTERRUPT_CONFIG/0/hwres_cpu_prio" resourceGroupUri="peripheral/cpu/*/hra/prio/*" mResGrpUri="peripheral/cpu/*/hra/prio/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CPU0/CPU0_0.dd#//@provided.2"/>
  </hwResources>
  <connections URI="http://resources/4.1.2/app/INTERRUPT_CONFIG/0/http://resources/4.1.2/app/INTERRUPT_CONFIG/0/vs_interrupt_out/http://resources/4.1.2/app/INTERRUPT_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="INT" targetSignal="INT" srcVirtualSignal="//@virtualSignals.1" proxyTargetVirtualSignalUri="http://resources/4.1.2/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../CPU_CORE/v4_1_2/CPU_CORE_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../CPU_CORE/v4_1_2/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.1.2/app/INTERRUPT_CONFIG/0/http://resources/4.1.2/app/INTERRUPT_CONFIG/0/vs_cpu_core_global/http://resources/4.1.2/app/INTERRUPT_CONFIG/0/vs_cpu_prio_global" systemDefined="true" sourceSignal="INT" targetSignal="global" targetVirtualSignal="//@virtualSignals.2" proxySrcVirtualSignalUri="http://resources/4.1.2/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../CPU_CORE/v4_1_2/CPU_CORE_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../CPU_CORE/v4_1_2/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
</ResourceModel:App>
