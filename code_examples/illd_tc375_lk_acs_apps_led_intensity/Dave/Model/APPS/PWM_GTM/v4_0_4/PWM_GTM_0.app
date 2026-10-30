<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="PWM_GTM" URI="http://resources/4.0.4/app/PWM_GTM/0" description="This APP generates a PWM using GTM" mode="NOTSHARABLE" version="4.0.4" minDaveVersion="4.2.4" instanceLabel="PWM_GTM_0" appLabel="">
  <properties provideInit="true"/>
  <virtualSignals name="PWM" URI="http://resources/4.0.4/app/PWM_GTM/0/vs_out" hwSignal="out" hwResource="//@hwResources.0"/>
  <virtualSignals name="PWM" URI="http://resources/4.0.4/app/PWM_GTM/0/vs_out2" hwSignal="out" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="DTM_IN" URI="http://resources/4.0.4/app/PWM_GTM/0/vs_in" hwSignal="in" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="INT" URI="http://resources/4.0.4/app/PWM_GTM/0/vs_intr" hwSignal="ccu0tc_irq" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="PWM pin" URI="http://resources/4.0.4/app/PWM_GTM/0/vs_out_pin" hwSignal="pad" hwResource="//@hwResources.2"/>
  <virtualSignals name="PWM pin_signal" URI="http://resources/4.0.4/app/PWM_GTM/0/__pin_vs_out_pin" hwSignal="pin" hwResource="//@hwResources.3"/>
  <requiredApps URI="http://resources/4.0.4/app/PWM_GTM/0/appres_gtm_generic" requiredAppName="GTM_GENERIC" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GTM_GENERIC/v4_0_6/GTM_GENERIC_0.app#/"/>
  </requiredApps>
  <hwResources name="Timer Channel" URI="http://resources/4.0.4/app/PWM_GTM/0/hwres_module" resourceGroupUri="peripheral/gtm/0/cluster/*/sv0/*/ch/*" solverVariable="true" mResGrpUri="peripheral/gtm/0/cluster/*/sv0/*/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/GTM0/GTM0_0.dd#//@provided.313"/>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="tom"/>
    </solverVarMap>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="tom"/>
    </solverVarMap>
  </hwResources>
  <hwResources name="DTM Channel" URI="http://resources/4.0.4/app/PWM_GTM/0/hwres_dtm" resourceGroupUri="" required="false" mResGrpUri="peripheral/gtm/0/cluster/*/dtm/*/ch/*"/>
  <hwResources name="Output pin" URI="http://resources/4.0.4/app/PWM_GTM/0/hwres_port_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P0/P0_0.dd#//@provided.25"/>
  </hwResources>
  <hwResources name="PWM pin" URI="http://resources/4.0.4/app/PWM_GTM/0/__pin_hwres_port_pad" resourceGroupUri="devicepackage/0/16" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.2"/>
  </hwResources>
  <connections URI="http://resources/4.0.4/app/PWM_GTM/0/http://resources/4.0.4/app/PWM_GTM/0/vs_out/http://resources/4.0.4/app/PWM_GTM/0/vs_in" systemDefined="true" sourceSignal="PWM" targetSignal="DTM_IN" required="false" srcVirtualSignal="//@virtualSignals.0" targetVirtualSignal="//@virtualSignals.2"/>
  <connections URI="http://resources/4.0.4/app/PWM_GTM/0/http://resources/4.0.4/app/PWM_GTM/0/vs_out/http://resources/4.0.4/app/PWM_GTM/0/vs_out_pin" systemDefined="true" sourceSignal="PWM" targetSignal="PWM pin" srcVirtualSignal="//@virtualSignals.0" targetVirtualSignal="//@virtualSignals.4"/>
  <connections URI="http://resources/4.0.4/app/PWM_GTM/0/http://resources/4.0.4/app/PWM_GTM/0/vs_out2/http://resources/4.0.4/app/PWM_GTM/0/vs_out_pin" systemDefined="true" sourceSignal="PWM" targetSignal="PWM pin" required="false" srcVirtualSignal="//@virtualSignals.1" targetVirtualSignal="//@virtualSignals.4"/>
  <connections URI="http://resources/4.0.4/app/PWM_GTM/0/http://resources/4.0.4/app/PWM_GTM/0/vs_out_pin/http://resources/4.0.4/app/PWM_GTM/0/__pin_vs_out_pin" systemDefined="true" sourceSignal="PWM pin" targetSignal="PWM pin_signal" srcVirtualSignal="//@virtualSignals.4" targetVirtualSignal="//@virtualSignals.5"/>
  <connections URI="http://resources/4.0.4/app/PWM_GTM/0/http://resources/4.0.4/app/PWM_GTM/0/__pin_vs_out_pin/http://resources/4.0.4/app/PWM_GTM/0/vs_out_pin" systemDefined="true" sourceSignal="PWM pin_signal" targetSignal="PWM pin" srcVirtualSignal="//@virtualSignals.5" targetVirtualSignal="//@virtualSignals.4"/>
</ResourceModel:App>
