<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="EVADC_GENERIC" URI="http://resources/4.0.4/app/EVADC_GENERIC/0" description="This application configures the EVADC module." version="4.0.4" minDaveVersion="4.2.4" instanceLabel="EVADC_GENERIC_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../ANALOG_CONVERTER_EVADC/v4_0_4/ANALOG_CONVERTER_EVADC_0.app#//@requiredApps.0"/>
  <properties singleton="true" provideInit="true" sharable="true"/>
  <virtualSignals name="INT" URI="http://resources/4.0.4/app/EVADC_GENERIC/0/vs_global_result_event" hwSignal="globev" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="EMUX00" URI="http://resources/4.0.4/app/EVADC_GENERIC/0/vs_ext_mux_00" hwSignal="emux00" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="EMUX01" URI="http://resources/4.0.4/app/EVADC_GENERIC/0/vs_ext_mux_01" hwSignal="emux01" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="EMUX02" URI="http://resources/4.0.4/app/EVADC_GENERIC/0/vs_ext_mux_02" hwSignal="emux02" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="EMUX10" URI="http://resources/4.0.4/app/EVADC_GENERIC/0/vs_ext_mux_10" hwSignal="emux10" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="EMUX11" URI="http://resources/4.0.4/app/EVADC_GENERIC/0/vs_ext_mux_11" hwSignal="emux11" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="EMUX12" URI="http://resources/4.0.4/app/EVADC_GENERIC/0/vs_ext_mux_12" hwSignal="emux12" hwResource="//@hwResources.0" required="false" visible="true"/>
  <requiredApps URI="http://resources/4.0.4/app/EVADC_GENERIC/0/appres_clock" requiredAppName="CLOCK" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK/v4_1_8/CLOCK_0.app#/"/>
  </requiredApps>
  <hwResources name="Common Block" URI="http://resources/4.0.4/app/EVADC_GENERIC/0/hwres_evadc_common" resourceGroupUri="peripheral/evadc/0/common" mResGrpUri="peripheral/evadc/0/common">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/EVADC0/EVADC0_0.dd#//@provided.46"/>
  </hwResources>
</ResourceModel:App>
