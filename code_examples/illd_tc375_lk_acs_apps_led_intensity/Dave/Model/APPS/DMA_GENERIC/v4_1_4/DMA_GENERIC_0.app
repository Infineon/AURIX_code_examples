<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="DMA_GENERIC" URI="http://resources/4.1.4/app/DMA_GENERIC/0" description="The DMA_GENERIC APP is used to configure the properities of global DMA which used by individual DMA channels on TC3x and TC4x microcontrollers" version="4.1.4" minDaveVersion="4.2.4" instanceLabel="DMA_GENERIC_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../DMA_CHANNEL_CONFIG/v4_1_8/DMA_CHANNEL_CONFIG_0.app#//@requiredApps.0"/>
  <properties provideInit="true" sharable="true"/>
  <virtualSignals name="global" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_global" hwSignal="global" hwResource="//@hwResources.0">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../DMA_CHANNEL_CONFIG/v4_1_8/DMA_CHANNEL_CONFIG_0.app#//@connections.0"/>
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../DMA_CHANNEL_CONFIG/v4_1_8/DMA_CHANNEL_CONFIG_0.app#//@connections.1"/>
  </virtualSignals>
  <virtualSignals name="GERR_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_gerr" hwSignal="gerr_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="E0_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_0" hwSignal="err_int0" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="E1_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_1" hwSignal="err_int1" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="E2_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_2" hwSignal="err_int2" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="E3_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_3" hwSignal="err_int3" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="E4_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_4" hwSignal="err_int4" hwResource="//@hwResources.0"/>
  <virtualSignals name="E5_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_5" hwSignal="err_int5" hwResource="//@hwResources.0"/>
  <virtualSignals name="E6_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_6" hwSignal="err_int6" hwResource="//@hwResources.0"/>
  <virtualSignals name="E7_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_7" hwSignal="err_int7" hwResource="//@hwResources.0"/>
  <virtualSignals name="E8_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_8" hwSignal="err_int8" hwResource="//@hwResources.0"/>
  <virtualSignals name="E9_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_9" hwSignal="err_int9" hwResource="//@hwResources.0"/>
  <virtualSignals name="E10_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_10" hwSignal="err_int10" hwResource="//@hwResources.0"/>
  <virtualSignals name="E11_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_11" hwSignal="err_int11" hwResource="//@hwResources.0"/>
  <virtualSignals name="E12_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_12" hwSignal="err_int12" hwResource="//@hwResources.0"/>
  <virtualSignals name="E13_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_13" hwSignal="err_int13" hwResource="//@hwResources.0"/>
  <virtualSignals name="E14_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_14" hwSignal="err_int14" hwResource="//@hwResources.0"/>
  <virtualSignals name="E15_INT" URI="http://resources/4.1.4/app/DMA_GENERIC/0/vs_dma_err_intr_15" hwSignal="err_int15" hwResource="//@hwResources.0"/>
  <hwResources name="Common Block" URI="http://resources/4.1.4/app/DMA_GENERIC/0/hwres_dma" resourceGroupUri="peripheral/dma/*/common" mResGrpUri="peripheral/dma/*/common">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DMA0/DMA0_0.dd#//@provided.0"/>
  </hwResources>
</ResourceModel:App>
