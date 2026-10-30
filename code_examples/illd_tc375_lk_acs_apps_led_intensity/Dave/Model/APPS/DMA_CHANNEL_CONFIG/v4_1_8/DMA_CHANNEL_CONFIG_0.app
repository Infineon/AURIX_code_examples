<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="DMA_CHANNEL_CONFIG" URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0" description="The DMA_CHANNEL_CONFIG APP is used to perform data transfer from a source to a destination without CPU effort on TC3x and TC4x microcontrollers" mode="NOTSHARABLE" version="4.1.8" minDaveVersion="4.2.4" instanceLabel="DMA_CHANNEL_CONFIG_0" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="REQ" URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/vs_interrupt_in" hwSignal="in" hwResource="//@hwResources.1" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../ANALOG_CONVERTER_EVADC/v4_0_4/ANALOG_CONVERTER_EVADC_0.app#//@connections.64"/>
  </virtualSignals>
  <virtualSignals name="INT" URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/vs_interrupt_out" hwSignal="out" hwResource="//@hwResources.1"/>
  <virtualSignals name="global" URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/vs_dma_ch_global" hwSignal="global" hwResource="//@hwResources.0"/>
  <virtualSignals name="INT" URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/vs_dma_ch_intr_req" hwSignal="ch_int" hwResource="//@hwResources.0" visible="true"/>
  <requiredApps URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/appres_dma_gen" requiredAppName="DMA_GENERIC" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../DMA_GENERIC/v4_1_4/DMA_GENERIC_0.app#/"/>
  </requiredApps>
  <hwResources name="Channel" URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/hwres_dma_channel" resourceGroupUri="peripheral/dma/*/ch/*" mResGrpUri="peripheral/dma/*/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DMA0/DMA0_0.dd#//@provided.1"/>
  </hwResources>
  <hwResources name="Interrupt SRN" URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/hwres_interrupt" resourceGroupUri="peripheral/int/0/srn/*" mResGrpUri="peripheral/int/0/srn/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/INT0/INT0_0.dd#//@provided.9"/>
  </hwResources>
  <connections URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/vs_interrupt_out/http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/vs_dma_global" systemDefined="true" sourceSignal="INT" targetSignal="global" srcVirtualSignal="//@virtualSignals.1" proxyTargetVirtualSignalUri="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../DMA_GENERIC/v4_1_4/DMA_GENERIC_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../DMA_GENERIC/v4_1_4/DMA_GENERIC_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/vs_dma_global/http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/vs_dma_ch_global" systemDefined="true" sourceSignal="global" targetSignal="global" targetVirtualSignal="//@virtualSignals.2" proxySrcVirtualSignalUri="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../DMA_GENERIC/v4_1_4/DMA_GENERIC_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../DMA_GENERIC/v4_1_4/DMA_GENERIC_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/http://resources/4.1.8/app/DMA_CHANNEL_CONFIG/0/vs_dma_ch_intr_req/http://resources/4.1.4/app/INTERRUPT_CONFIG/0/vs_interrupt_in" sourceSignal="INT" targetSignal="REQ" srcVirtualSignal="//@virtualSignals.3">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../INTERRUPT_CONFIG/v4_1_4/INTERRUPT_CONFIG_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../INTERRUPT_CONFIG/v4_1_4/INTERRUPT_CONFIG_0.app#//@virtualSignals.0"/>
  </connections>
</ResourceModel:App>
