<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="PWM_EGTM" URI="http://resources/4.1.4/app/PWM_EGTM/0" description="This APP generates a PWM using eGTM" mode="NOTSHARABLE" version="4.1.4" minDaveVersion="4.2.4" instanceLabel="PWM_EGTM_0" appLabel="">
  <properties provideInit="true"/>
  <virtualSignals name="PWM" URI="http://resources/4.1.4/app/PWM_EGTM/0/vs_out" hwSignal="out" hwResource="//@hwResources.1"/>
  <virtualSignals name="PWM" URI="http://resources/4.1.4/app/PWM_EGTM/0/vs_out2" hwSignal="out" hwResource="//@hwResources.0"/>
  <virtualSignals name="DTM_IN" URI="http://resources/4.1.4/app/PWM_EGTM/0/vs_in" hwSignal="in" hwResource="//@hwResources.1"/>
  <virtualSignals name="INT" URI="http://resources/4.1.4/app/PWM_EGTM/0/vs_intr" hwSignal="ccu0tc_irq" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="PWM pin" URI="http://resources/4.1.4/app/PWM_EGTM/0/vs_out_pin" hwSignal="pad" hwResource="//@hwResources.2"/>
  <virtualSignals name="PWM pin_signal" URI="http://resources/4.1.4/app/PWM_EGTM/0/__pin_vs_out_pin" hwSignal="pin" hwResource="//@hwResources.3"/>
  <requiredApps URI="http://resources/4.1.4/app/PWM_EGTM/0/appres_egtm_generic" requiredAppName="EGTM_GENERIC" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../EGTM_GENERIC/v4_1_6/EGTM_GENERIC_0.app#/"/>
  </requiredApps>
  <hwResources name="Timer Channel" URI="http://resources/4.1.4/app/PWM_EGTM/0/hwres_module" resourceGroupUri="peripheral/egtm/0/cluster/*/sv0/*/ch/*" solverVariable="true" mResGrpUri="peripheral/egtm/0/cluster/*/sv0/*/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/EGTM0/EGTM0_0.dd#//@provided.890"/>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="tom"/>
    </solverVarMap>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="tom"/>
    </solverVarMap>
  </hwResources>
  <hwResources name="DTM Channel" URI="http://resources/4.1.4/app/PWM_EGTM/0/hwres_dtm" resourceGroupUri="peripheral/egtm/0/cluster/*/dtm/*/ch/*" mResGrpUri="peripheral/egtm/0/cluster/*/dtm/*/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/EGTM0/EGTM0_0.dd#//@provided.889"/>
  </hwResources>
  <hwResources name="Output pin" URI="http://resources/4.1.4/app/PWM_EGTM/0/hwres_port_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P3/P3_3.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="PWM pin" URI="http://resources/4.1.4/app/PWM_EGTM/0/__pin_hwres_port_pad" resourceGroupUri="devicepackage/0/f5" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.1"/>
  </hwResources>
  <connections URI="http://resources/4.1.4/app/PWM_EGTM/0/http://resources/4.1.4/app/PWM_EGTM/0/vs_out2/http://resources/4.1.4/app/PWM_EGTM/0/vs_in" systemDefined="true" sourceSignal="PWM" targetSignal="DTM_IN" srcVirtualSignal="//@virtualSignals.1" targetVirtualSignal="//@virtualSignals.2"/>
  <connections URI="http://resources/4.1.4/app/PWM_EGTM/0/http://resources/4.1.4/app/PWM_EGTM/0/vs_out/http://resources/4.1.4/app/PWM_EGTM/0/vs_out_pin" systemDefined="true" sourceSignal="PWM" targetSignal="PWM pin" srcVirtualSignal="//@virtualSignals.0" targetVirtualSignal="//@virtualSignals.4"/>
  <connections URI="http://resources/4.1.4/app/PWM_EGTM/0/http://resources/4.1.4/app/PWM_EGTM/0/vs_out_pin/http://resources/4.1.4/app/PWM_EGTM/0/__pin_vs_out_pin" systemDefined="true" sourceSignal="PWM pin" targetSignal="PWM pin_signal" srcVirtualSignal="//@virtualSignals.4" targetVirtualSignal="//@virtualSignals.5"/>
  <connections URI="http://resources/4.1.4/app/PWM_EGTM/0/http://resources/4.1.4/app/PWM_EGTM/0/__pin_vs_out_pin/http://resources/4.1.4/app/PWM_EGTM/0/vs_out_pin" systemDefined="true" sourceSignal="PWM pin_signal" targetSignal="PWM pin" srcVirtualSignal="//@virtualSignals.5" targetVirtualSignal="//@virtualSignals.4"/>
</ResourceModel:App>
