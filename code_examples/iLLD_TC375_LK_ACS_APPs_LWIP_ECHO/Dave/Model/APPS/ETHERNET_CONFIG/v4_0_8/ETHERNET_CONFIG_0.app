<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="ETHERNET_CONFIG" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0" description="The GETH module provides a high-speed Ethernet interface, enabling communication with other devices over a 10/100/1000Mbit/s. It supports IEEE 802.3 standards for reliable and efficient data transfer." mode="NOTSHARABLE" version="4.0.8" minDaveVersion="4.2.4" instanceLabel="ETHERNET_CONFIG_0" appLabel="" containingProxySignal="true">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../LWIP_GETH/v4_0_8/LWIP_GETH_0.app#//@requiredApps.3"/>
  <properties provideInit="true"/>
  <virtualSignals name="CRS" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_crs" hwSignal="crs" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="CRS pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_crs_pad" hwSignal="pad" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="CRSDV" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_crs_dv" hwSignal="crsdv" hwResource="//@hwResources.0"/>
  <virtualSignals name="CRS DV pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_crs_dv_pad" hwSignal="pad" hwResource="//@hwResources.2"/>
  <virtualSignals name="COL" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_col" hwSignal="col" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="COL pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_col_pad" hwSignal="pad" hwResource="//@hwResources.3" required="false"/>
  <virtualSignals name="RXER" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxer" hwSignal="rxer" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="RXER pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxer_pad" hwSignal="pad" hwResource="//@hwResources.4" required="false"/>
  <virtualSignals name="RXD0" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxd0" hwSignal="rxd0" hwResource="//@hwResources.0"/>
  <virtualSignals name="RXD0 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd0_pad" hwSignal="pad" hwResource="//@hwResources.5"/>
  <virtualSignals name="RXD1" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxd1" hwSignal="rxd1" hwResource="//@hwResources.0"/>
  <virtualSignals name="RXD1 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd1_pad" hwSignal="pad" hwResource="//@hwResources.6"/>
  <virtualSignals name="RXD2" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxd2" hwSignal="rxd2" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="RXD2 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd2_pad" hwSignal="pad" hwResource="//@hwResources.7" required="false"/>
  <virtualSignals name="RXD3" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxd3" hwSignal="rxd3" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="RXD3 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd3_pad" hwSignal="pad" hwResource="//@hwResources.8" required="false"/>
  <virtualSignals name="TXEN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txen" hwSignal="txen" hwResource="//@hwResources.0"/>
  <virtualSignals name="TXEN pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txen_pad" hwSignal="pad" hwResource="//@hwResources.9"/>
  <virtualSignals name="TXER" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txer" hwSignal="txer" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="TXER pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txer_pad" hwSignal="pad" hwResource="//@hwResources.10" required="false"/>
  <virtualSignals name="TXD0" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txd0" hwSignal="txd0" hwResource="//@hwResources.0"/>
  <virtualSignals name="TXD0 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd0_pad" hwSignal="pad" hwResource="//@hwResources.11"/>
  <virtualSignals name="TXD1" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txd1" hwSignal="txd1" hwResource="//@hwResources.0"/>
  <virtualSignals name="TXD1 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd1_pad" hwSignal="pad" hwResource="//@hwResources.12"/>
  <virtualSignals name="TXD2" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txd2" hwSignal="txd2" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="TXD2 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd2_pad" hwSignal="pad" hwResource="//@hwResources.13" required="false"/>
  <virtualSignals name="TXD3" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txd3" hwSignal="txd3" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="TXD3 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd3_pad" hwSignal="pad" hwResource="//@hwResources.14" required="false"/>
  <virtualSignals name="MDC" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_mdc" hwSignal="mdc" hwResource="//@hwResources.0"/>
  <virtualSignals name="MDC pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdc_pad" hwSignal="pad" hwResource="//@hwResources.15"/>
  <virtualSignals name="MDIO" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_mdio" hwSignal="mdio_in" hwResource="//@hwResources.0"/>
  <virtualSignals name="MDIO pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdio_pad" hwSignal="pad" hwResource="//@hwResources.16"/>
  <virtualSignals name="MDIO" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_mdo" hwSignal="mdio_out" hwResource="//@hwResources.0"/>
  <virtualSignals name="MDIO pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdo_pad" hwSignal="pad" hwResource="//@hwResources.16"/>
  <virtualSignals name="REFCLK" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_ref_clk" hwSignal="refclk" hwResource="//@hwResources.0"/>
  <virtualSignals name="REFCLK pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_ref_clk_pad" hwSignal="pad" hwResource="//@hwResources.17"/>
  <virtualSignals name="TCTL" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_tx_ctl" hwSignal="tctl" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="TCTL pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_tx_ctl_pad" hwSignal="pad" hwResource="//@hwResources.18" required="false"/>
  <virtualSignals name="RCTL" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rx_ctl" hwSignal="rctl" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="RCTL pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rx_ctl_pad" hwSignal="pad" hwResource="//@hwResources.19" required="false"/>
  <virtualSignals name="RCLK" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxc" hwSignal="rxclk" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="RCLK pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxc_pad" hwSignal="pad" hwResource="//@hwResources.20" required="false"/>
  <virtualSignals name="TCLK" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txc_in" hwSignal="txclk_in" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="TCLK" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txc_out" hwSignal="txclk_out" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="TCLK pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txc_pad" hwSignal="pad" hwResource="//@hwResources.21" required="false"/>
  <virtualSignals name="RXDV" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rx_dv" hwSignal="rxdv" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="RXDV pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rx_dv_pad" hwSignal="pad" hwResource="//@hwResources.22" required="false"/>
  <virtualSignals name="GREFCLK" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_gref_clk" hwSignal="grefclk" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="GREFCLK pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_gref_clk_pad" hwSignal="pad" hwResource="//@hwResources.23" required="false"/>
  <virtualSignals name="INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_itr_out" hwSignal="out" hwResource="//@hwResources.24"/>
  <virtualSignals name="INT req" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_itr_in" hwSignal="in" hwResource="//@hwResources.24"/>
  <virtualSignals name="INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_intr" hwSignal="trigo1" hwResource="//@hwResources.0"/>
  <virtualSignals name="TXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx0_itr_out" hwSignal="out" hwResource="//@hwResources.25"/>
  <virtualSignals name="TXDMA_INT req" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx0_itr_in" hwSignal="in" hwResource="//@hwResources.25"/>
  <virtualSignals name="TXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_tx0_itr_out" hwSignal="trigo2" hwResource="//@hwResources.0"/>
  <virtualSignals name="global" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_dma_tx0_global" hwSignal="global" hwResource="//@hwResources.37"/>
  <virtualSignals name="TXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx1_itr_out" hwSignal="out" hwResource="//@hwResources.26" required="false"/>
  <virtualSignals name="TXDMA_INT req" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx1_itr_in" hwSignal="in" hwResource="//@hwResources.26" required="false"/>
  <virtualSignals name="TXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_tx1_itr_out" hwSignal="trigo3" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="global" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_dma_tx1_global" hwSignal="global" hwResource="//@hwResources.38" required="false"/>
  <virtualSignals name="TXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx2_itr_out" hwSignal="out" hwResource="//@hwResources.27" required="false"/>
  <virtualSignals name="TXDMA_INT req" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx2_itr_in" hwSignal="in" hwResource="//@hwResources.27" required="false"/>
  <virtualSignals name="TXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_tx2_itr_out" hwSignal="trigo4" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="global" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_dma_tx2_global" hwSignal="global" hwResource="//@hwResources.39" required="false"/>
  <virtualSignals name="TXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx3_itr_out" hwSignal="out" hwResource="//@hwResources.28" required="false"/>
  <virtualSignals name="TXDMA_INT req" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx3_itr_in" hwSignal="in" hwResource="//@hwResources.28" required="false"/>
  <virtualSignals name="TXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_tx3_itr_out" hwSignal="trigo5" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="global" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_dma_tx3_global" hwSignal="global" hwResource="//@hwResources.40" required="false"/>
  <virtualSignals name="RXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx0_itr_out" hwSignal="out" hwResource="//@hwResources.29"/>
  <virtualSignals name="RXDMA_INT req" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx0_itr_in" hwSignal="in" hwResource="//@hwResources.29"/>
  <virtualSignals name="global" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx0_itr_global" hwSignal="global" hwResource="//@hwResources.33"/>
  <virtualSignals name="RXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_rx0_itr_out" hwSignal="trigo6" hwResource="//@hwResources.0"/>
  <virtualSignals name="RXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx1_itr_out" hwSignal="out" hwResource="//@hwResources.30" required="false"/>
  <virtualSignals name="RXDMA_INT req" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx1_itr_in" hwSignal="in" hwResource="//@hwResources.30" required="false"/>
  <virtualSignals name="global" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx1_itr_global" hwSignal="global" hwResource="//@hwResources.34" required="false"/>
  <virtualSignals name="RXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_rx1_itr_out" hwSignal="trigo7" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="RXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx2_itr_out" hwSignal="out" hwResource="//@hwResources.31" required="false"/>
  <virtualSignals name="RXDMA_INT req" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx2_itr_in" hwSignal="in" hwResource="//@hwResources.31" required="false"/>
  <virtualSignals name="global" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx2_itr_global" hwSignal="global" hwResource="//@hwResources.35" required="false"/>
  <virtualSignals name="RXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_rx2_itr_out" hwSignal="trigo8" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="RXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx3_itr_out" hwSignal="out" hwResource="//@hwResources.32" required="false"/>
  <virtualSignals name="RXDMA_INT req" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx3_itr_in" hwSignal="in" hwResource="//@hwResources.32" required="false"/>
  <virtualSignals name="global" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx3_itr_global" hwSignal="global" hwResource="//@hwResources.36" required="false"/>
  <virtualSignals name="RXDMA_INT" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_rx3_itr_out" hwSignal="trigo9" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="global" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_geth_intr_global" hwSignal="global" hwResource="//@hwResources.41"/>
  <virtualSignals name="CRS pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_crs_pad" hwSignal="pin" hwResource="//@hwResources.42"/>
  <virtualSignals name="CRS DV pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_crs_dv_pad" hwSignal="pin" hwResource="//@hwResources.43"/>
  <virtualSignals name="COL pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_col_pad" hwSignal="pin" hwResource="//@hwResources.44"/>
  <virtualSignals name="RXER pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxer_pad" hwSignal="pin" hwResource="//@hwResources.45"/>
  <virtualSignals name="RXD0 pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd0_pad" hwSignal="pin" hwResource="//@hwResources.46"/>
  <virtualSignals name="RXD1 pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd1_pad" hwSignal="pin" hwResource="//@hwResources.47"/>
  <virtualSignals name="RXD2 pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd2_pad" hwSignal="pin" hwResource="//@hwResources.48"/>
  <virtualSignals name="RXD3 pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd3_pad" hwSignal="pin" hwResource="//@hwResources.49"/>
  <virtualSignals name="TXEN pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txen_pad" hwSignal="pin" hwResource="//@hwResources.50"/>
  <virtualSignals name="TXER pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txer_pad" hwSignal="pin" hwResource="//@hwResources.51"/>
  <virtualSignals name="TXD0 pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd0_pad" hwSignal="pin" hwResource="//@hwResources.52"/>
  <virtualSignals name="TXD1 pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd1_pad" hwSignal="pin" hwResource="//@hwResources.53"/>
  <virtualSignals name="TXD2 pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd2_pad" hwSignal="pin" hwResource="//@hwResources.54"/>
  <virtualSignals name="TXD3 pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd3_pad" hwSignal="pin" hwResource="//@hwResources.55"/>
  <virtualSignals name="MDC pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_mdc_pad" hwSignal="pin" hwResource="//@hwResources.56"/>
  <virtualSignals name="MDIO pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_mdio_pad" hwSignal="pin" hwResource="//@hwResources.57"/>
  <virtualSignals name="REFCLK pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_ref_clk_pad" hwSignal="pin" hwResource="//@hwResources.58"/>
  <virtualSignals name="TCTL pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_tx_ctl_pad" hwSignal="pin" hwResource="//@hwResources.59"/>
  <virtualSignals name="RCTL pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rx_ctl_pad" hwSignal="pin" hwResource="//@hwResources.60"/>
  <virtualSignals name="RCLK pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxc_pad" hwSignal="pin" hwResource="//@hwResources.61"/>
  <virtualSignals name="TCLK pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txc_pad" hwSignal="pin" hwResource="//@hwResources.62"/>
  <virtualSignals name="RXDV pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rx_dv_pad" hwSignal="pin" hwResource="//@hwResources.63"/>
  <virtualSignals name="GREFCLK pin_signal" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_gref_clk_pad" hwSignal="pin" hwResource="//@hwResources.64"/>
  <requiredApps URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/appres_cpu" requiredAppName="CPU_CORE" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/appres_clock" requiredAppName="CLOCK" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK/v4_1_12/CLOCK_0.app#/"/>
  </requiredApps>
  <hwResources name="Module" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_geth" resourceGroupUri="peripheral/geth/*/geth" mResGrpUri="peripheral/geth/*/geth">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/GETH0/GETH0_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="Carrier Sense Signal pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_crs_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="Carrier Sense / Data Valid pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_crs_dv_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P11/P11_11.dd#//@provided.109"/>
  </hwResources>
  <hwResources name="Collision pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_col_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="RX Error pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_rxer_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="RX Data 0 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_rxd0_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P11/P11_11.dd#//@provided.95"/>
  </hwResources>
  <hwResources name="RX Data 1 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_rxd1_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P11/P11_11.dd#//@provided.42"/>
  </hwResources>
  <hwResources name="RX Data 2 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_rxd2_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="RX Data 3 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_rxd3_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="TX Enable pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_txen_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P11/P11_11.dd#//@provided.60"/>
  </hwResources>
  <hwResources name="TX Error pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_txer_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="TX Data 0 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_txd0_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P11/P11_11.dd#//@provided.27"/>
  </hwResources>
  <hwResources name="TX Data 1 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_txd1_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P11/P11_11.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="TX Data 2 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_txd2_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="TX Data 3 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_txd3_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="MDIO Clock pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_mdc_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P21/P21_21.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="MDIO pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_mdio_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P21/P21_21.dd#//@provided.23"/>
  </hwResources>
  <hwResources name="Ref Clock Input pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_ref_clk_pad" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/P11/P11_11.dd#//@provided.78"/>
  </hwResources>
  <hwResources name="TX Control pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_tx_ctl_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="RX Control pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_rx_ctl_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="RX Clock pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_rxc_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="TX Clock pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_txc_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="RX Data Valid pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_rx_dv_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="Gigabit Ref Clock Input pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_gref_clk_pad" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="GETH Interrupt SRN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_geth_itr" resourceGroupUri="peripheral/int/0/srn/*" mResGrpUri="peripheral/int/0/srn/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/INT0/INT0_0.dd#//@provided.9"/>
  </hwResources>
  <hwResources name="TX DMA0 Interrupt SRN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_dma_tx_0_itr" resourceGroupUri="peripheral/int/0/srn/*" mResGrpUri="peripheral/int/0/srn/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/INT0/INT0_0.dd#//@provided.5"/>
  </hwResources>
  <hwResources name="TX DMA1 Interrupt SRN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_dma_tx_1_itr" resourceGroupUri="" required="false" mResGrpUri="peripheral/int/0/srn/*"/>
  <hwResources name="TX DMA2 Interrupt SRN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_dma_tx_2_itr" resourceGroupUri="" required="false" mResGrpUri="peripheral/int/0/srn/*"/>
  <hwResources name="TX DMA3 Interrupt SRN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_dma_tx_3_itr" resourceGroupUri="" required="false" mResGrpUri="peripheral/int/0/srn/*"/>
  <hwResources name="RX DMA0 Interrupt SRN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_dma_rx_0_itr" resourceGroupUri="peripheral/int/0/srn/*" mResGrpUri="peripheral/int/0/srn/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/INT0/INT0_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="RX DMA1 Interrupt SRN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_dma_rx_1_itr" resourceGroupUri="" required="false" mResGrpUri="peripheral/int/0/srn/*"/>
  <hwResources name="RX DMA2 Interrupt SRN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_dma_rx_2_itr" resourceGroupUri="" required="false" mResGrpUri="peripheral/int/0/srn/*"/>
  <hwResources name="RX DMA3 Interrupt SRN" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_dma_rx_3_itr" resourceGroupUri="" required="false" mResGrpUri="peripheral/int/0/srn/*"/>
  <hwResources name="RX DMA0 Interrupt" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_prio_rx_0" resourceGroupUri="peripheral/cpu/*/prio/*" mResGrpUri="peripheral/cpu/*/prio/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CPU0/CPU0_0.dd#//@provided.3"/>
  </hwResources>
  <hwResources name="RX DMA1 Interrupt" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_prio_rx_1" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/*/prio/*"/>
  <hwResources name="RX DMA2 Interrupt" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_prio_rx_2" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/*/prio/*"/>
  <hwResources name="RX DMA3 Interrupt" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_prio_rx_3" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/*/prio/*"/>
  <hwResources name="TX DMA0 Interrupt" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_cpu_prio_dma_tx0" resourceGroupUri="peripheral/cpu/*/prio/*" mResGrpUri="peripheral/cpu/*/prio/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CPU0/CPU0_0.dd#//@provided.5"/>
  </hwResources>
  <hwResources name="TX DMA1 Interrupt" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_cpu_prio_dma_tx1" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/*/prio/*"/>
  <hwResources name="TX DMA2 Interrupt" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_cpu_prio_dma_tx2" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/*/prio/*"/>
  <hwResources name="TX DMA3 Interrupt" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_cpu_prio_dma_tx3" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/*/prio/*"/>
  <hwResources name="GETH Interrupt" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/hwres_cpu_prio_geth_intr" resourceGroupUri="peripheral/cpu/*/prio/*" mResGrpUri="peripheral/cpu/*/prio/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CPU0/CPU0_0.dd#//@provided.1"/>
  </hwResources>
  <hwResources name="CRS pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_crs_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="CRS DV pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_crs_dv_pad" resourceGroupUri="devicepackage/0/*" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.4"/>
  </hwResources>
  <hwResources name="COL pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_col_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="RXER pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_rxer_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="RXD0 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_rxd0_pad" resourceGroupUri="devicepackage/0/*" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.6"/>
  </hwResources>
  <hwResources name="RXD1 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_rxd1_pad" resourceGroupUri="devicepackage/0/*" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.8"/>
  </hwResources>
  <hwResources name="RXD2 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_rxd2_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="RXD3 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_rxd3_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="TXEN pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_txen_pad" resourceGroupUri="devicepackage/0/*" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.7"/>
  </hwResources>
  <hwResources name="TXER pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_txer_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="TXD0 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_txd0_pad" resourceGroupUri="devicepackage/0/*" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.1"/>
  </hwResources>
  <hwResources name="TXD1 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_txd1_pad" resourceGroupUri="devicepackage/0/*" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="TXD2 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_txd2_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="TXD3 pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_txd3_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="MDC pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_mdc_pad" resourceGroupUri="devicepackage/0/*" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.3"/>
  </hwResources>
  <hwResources name="MDIO pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_mdio_pad" resourceGroupUri="devicepackage/0/*" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.2"/>
  </hwResources>
  <hwResources name="REFCLK pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_ref_clk_pad" resourceGroupUri="devicepackage/0/*" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.5"/>
  </hwResources>
  <hwResources name="TCTL pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_tx_ctl_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="RCTL pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_rx_ctl_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="RCLK pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_rxc_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="TCLK pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_txc_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="RXDV pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_rx_dv_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="GREFCLK pin" URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_hwres_gref_clk_pad" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_crs_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_crs" systemDefined="true" sourceSignal="CRS pin" targetSignal="CRS" required="false" srcVirtualSignal="//@virtualSignals.1" targetVirtualSignal="//@virtualSignals.0"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_crs_dv_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_crs_dv" systemDefined="true" sourceSignal="CRS DV pin" targetSignal="CRSDV" srcVirtualSignal="//@virtualSignals.3" targetVirtualSignal="//@virtualSignals.2"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_intr/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_itr_in" systemDefined="true" sourceSignal="INT" targetSignal="INT req" srcVirtualSignal="//@virtualSignals.51" targetVirtualSignal="//@virtualSignals.50"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="INT" targetSignal="INT" srcVirtualSignal="//@virtualSignals.49" proxyTargetVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_geth_intr_global" systemDefined="true" sourceSignal="INT" targetSignal="global" targetVirtualSignal="//@virtualSignals.84" proxySrcVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_tx0_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx0_itr_in" systemDefined="true" sourceSignal="TXDMA_INT" targetSignal="TXDMA_INT req" srcVirtualSignal="//@virtualSignals.54" targetVirtualSignal="//@virtualSignals.53"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx0_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="TXDMA_INT" targetSignal="INT" srcVirtualSignal="//@virtualSignals.52" proxyTargetVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_dma_tx0_global" systemDefined="true" sourceSignal="INT" targetSignal="global" targetVirtualSignal="//@virtualSignals.55" proxySrcVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_tx1_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx1_itr_in" systemDefined="true" sourceSignal="TXDMA_INT" targetSignal="TXDMA_INT req" required="false" srcVirtualSignal="//@virtualSignals.58" targetVirtualSignal="//@virtualSignals.57"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx1_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="TXDMA_INT" targetSignal="INT" required="false" srcVirtualSignal="//@virtualSignals.56" proxyTargetVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <targetVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_dma_tx1_global" systemDefined="true" sourceSignal="INT" targetSignal="global" required="false" targetVirtualSignal="//@virtualSignals.59" proxySrcVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <srcVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_tx2_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx2_itr_in" systemDefined="true" sourceSignal="TXDMA_INT" targetSignal="TXDMA_INT req" required="false" srcVirtualSignal="//@virtualSignals.62" targetVirtualSignal="//@virtualSignals.61"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx2_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="TXDMA_INT" targetSignal="INT" required="false" srcVirtualSignal="//@virtualSignals.60" proxyTargetVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <targetVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_dma_tx2_global" systemDefined="true" sourceSignal="INT" targetSignal="global" required="false" targetVirtualSignal="//@virtualSignals.63" proxySrcVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <srcVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_tx3_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx3_itr_in" systemDefined="true" sourceSignal="TXDMA_INT" targetSignal="TXDMA_INT req" required="false" srcVirtualSignal="//@virtualSignals.66" targetVirtualSignal="//@virtualSignals.65"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_tx3_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="TXDMA_INT" targetSignal="INT" required="false" srcVirtualSignal="//@virtualSignals.64" proxyTargetVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <targetVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_prio_dma_tx3_global" systemDefined="true" sourceSignal="INT" targetSignal="global" required="false" targetVirtualSignal="//@virtualSignals.67" proxySrcVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <srcVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_rx0_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx0_itr_in" systemDefined="true" sourceSignal="RXDMA_INT" targetSignal="RXDMA_INT req" srcVirtualSignal="//@virtualSignals.71" targetVirtualSignal="//@virtualSignals.69"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx0_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="RXDMA_INT" targetSignal="INT" srcVirtualSignal="//@virtualSignals.68" proxyTargetVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx0_itr_global" systemDefined="true" sourceSignal="INT" targetSignal="global" targetVirtualSignal="//@virtualSignals.70" proxySrcVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_rx1_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx1_itr_in" systemDefined="true" sourceSignal="RXDMA_INT" targetSignal="RXDMA_INT req" required="false" srcVirtualSignal="//@virtualSignals.75" targetVirtualSignal="//@virtualSignals.73"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx1_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="RXDMA_INT" targetSignal="INT" required="false" srcVirtualSignal="//@virtualSignals.72" proxyTargetVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <targetVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx1_itr_global" systemDefined="true" sourceSignal="INT" targetSignal="global" required="false" targetVirtualSignal="//@virtualSignals.74" proxySrcVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <srcVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_rx2_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx2_itr_in" systemDefined="true" sourceSignal="RXDMA_INT" targetSignal="RXDMA_INT req" required="false" srcVirtualSignal="//@virtualSignals.79" targetVirtualSignal="//@virtualSignals.77"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx2_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="RXDMA_INT" targetSignal="INT" required="false" srcVirtualSignal="//@virtualSignals.76" proxyTargetVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <targetVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx2_itr_global" systemDefined="true" sourceSignal="INT" targetSignal="global" required="false" targetVirtualSignal="//@virtualSignals.78" proxySrcVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <srcVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_dma_rx3_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx3_itr_in" systemDefined="true" sourceSignal="RXDMA_INT" targetSignal="RXDMA_INT req" required="false" srcVirtualSignal="//@virtualSignals.83" targetVirtualSignal="//@virtualSignals.81"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx3_itr_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global" systemDefined="true" sourceSignal="RXDMA_INT" targetSignal="INT" required="false" srcVirtualSignal="//@virtualSignals.80" proxyTargetVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <targetVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_cpu_core_global/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_dma_rx3_itr_global" systemDefined="true" sourceSignal="INT" targetSignal="global" required="false" targetVirtualSignal="//@virtualSignals.82" proxySrcVirtualSignalUri="http://resources/4.1.6/app/CPU_CORE/0/vs_cpu_core_global" containingProxySignal="true">
    <srcVirtualSignal href="../../CPU_CORE/v4_1_6/CPU_CORE_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_col_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_col" systemDefined="true" sourceSignal="COL pin" targetSignal="COL" required="false" srcVirtualSignal="//@virtualSignals.5" targetVirtualSignal="//@virtualSignals.4"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxer_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxer" systemDefined="true" sourceSignal="RXER pin" targetSignal="RXER" required="false" srcVirtualSignal="//@virtualSignals.7" targetVirtualSignal="//@virtualSignals.6"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd0_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxd0" systemDefined="true" sourceSignal="RXD0 pin" targetSignal="RXD0" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.8"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd1_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxd1" systemDefined="true" sourceSignal="RXD1 pin" targetSignal="RXD1" srcVirtualSignal="//@virtualSignals.11" targetVirtualSignal="//@virtualSignals.10"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd2_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxd2" systemDefined="true" sourceSignal="RXD2 pin" targetSignal="RXD2" required="false" srcVirtualSignal="//@virtualSignals.13" targetVirtualSignal="//@virtualSignals.12"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd3_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxd3" systemDefined="true" sourceSignal="RXD3 pin" targetSignal="RXD3" required="false" srcVirtualSignal="//@virtualSignals.15" targetVirtualSignal="//@virtualSignals.14"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txen/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txen_pad" systemDefined="true" sourceSignal="TXEN" targetSignal="TXEN pin" srcVirtualSignal="//@virtualSignals.16" targetVirtualSignal="//@virtualSignals.17"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txer/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txer_pad" systemDefined="true" sourceSignal="TXER" targetSignal="TXER pin" required="false" srcVirtualSignal="//@virtualSignals.18" targetVirtualSignal="//@virtualSignals.19"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txd0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd0_pad" systemDefined="true" sourceSignal="TXD0" targetSignal="TXD0 pin" srcVirtualSignal="//@virtualSignals.20" targetVirtualSignal="//@virtualSignals.21"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txd1/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd1_pad" systemDefined="true" sourceSignal="TXD1" targetSignal="TXD1 pin" srcVirtualSignal="//@virtualSignals.22" targetVirtualSignal="//@virtualSignals.23"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txd2/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd2_pad" systemDefined="true" sourceSignal="TXD2" targetSignal="TXD2 pin" required="false" srcVirtualSignal="//@virtualSignals.24" targetVirtualSignal="//@virtualSignals.25"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txd3/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd3_pad" systemDefined="true" sourceSignal="TXD3" targetSignal="TXD3 pin" required="false" srcVirtualSignal="//@virtualSignals.26" targetVirtualSignal="//@virtualSignals.27"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_mdc/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdc_pad" systemDefined="true" sourceSignal="MDC" targetSignal="MDC pin" srcVirtualSignal="//@virtualSignals.28" targetVirtualSignal="//@virtualSignals.29"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdio_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_mdio" systemDefined="true" sourceSignal="MDIO pin" targetSignal="MDIO" srcVirtualSignal="//@virtualSignals.31" targetVirtualSignal="//@virtualSignals.30"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_mdo/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdo_pad" systemDefined="true" sourceSignal="MDIO" targetSignal="MDIO pin" srcVirtualSignal="//@virtualSignals.32" targetVirtualSignal="//@virtualSignals.33"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_ref_clk_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_ref_clk" systemDefined="true" sourceSignal="REFCLK pin" targetSignal="REFCLK" srcVirtualSignal="//@virtualSignals.35" targetVirtualSignal="//@virtualSignals.34"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_tx_ctl/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_tx_ctl_pad" systemDefined="true" sourceSignal="TCTL" targetSignal="TCTL pin" required="false" srcVirtualSignal="//@virtualSignals.36" targetVirtualSignal="//@virtualSignals.37"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rx_ctl_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rx_ctl" systemDefined="true" sourceSignal="RCTL pin" targetSignal="RCTL" required="false" srcVirtualSignal="//@virtualSignals.39" targetVirtualSignal="//@virtualSignals.38"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxc_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rxc" systemDefined="true" sourceSignal="RCLK pin" targetSignal="RCLK" required="false" srcVirtualSignal="//@virtualSignals.41" targetVirtualSignal="//@virtualSignals.40"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txc_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txc_in" systemDefined="true" sourceSignal="TCLK pin" targetSignal="TCLK" required="false" srcVirtualSignal="//@virtualSignals.44" targetVirtualSignal="//@virtualSignals.42"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_txc_out/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txc_pad" systemDefined="true" sourceSignal="TCLK" targetSignal="TCLK pin" required="false" srcVirtualSignal="//@virtualSignals.43" targetVirtualSignal="//@virtualSignals.44"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rx_dv_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_rx_dv" systemDefined="true" sourceSignal="RXDV pin" targetSignal="RXDV" required="false" srcVirtualSignal="//@virtualSignals.46" targetVirtualSignal="//@virtualSignals.45"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_gref_clk_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_geth_gref_clk" systemDefined="true" sourceSignal="GREFCLK pin" targetSignal="GREFCLK" required="false" srcVirtualSignal="//@virtualSignals.48" targetVirtualSignal="//@virtualSignals.47"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_crs_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_crs_pad" systemDefined="true" sourceSignal="CRS pin" targetSignal="CRS pin_signal" srcVirtualSignal="//@virtualSignals.1" targetVirtualSignal="//@virtualSignals.85"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_crs_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_crs_pad" systemDefined="true" sourceSignal="CRS pin_signal" targetSignal="CRS pin" srcVirtualSignal="//@virtualSignals.85" targetVirtualSignal="//@virtualSignals.1"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_crs_dv_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_crs_dv_pad" systemDefined="true" sourceSignal="CRS DV pin" targetSignal="CRS DV pin_signal" srcVirtualSignal="//@virtualSignals.3" targetVirtualSignal="//@virtualSignals.86"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_crs_dv_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_crs_dv_pad" systemDefined="true" sourceSignal="CRS DV pin_signal" targetSignal="CRS DV pin" srcVirtualSignal="//@virtualSignals.86" targetVirtualSignal="//@virtualSignals.3"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_col_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_col_pad" systemDefined="true" sourceSignal="COL pin" targetSignal="COL pin_signal" srcVirtualSignal="//@virtualSignals.5" targetVirtualSignal="//@virtualSignals.87"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_col_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_col_pad" systemDefined="true" sourceSignal="COL pin_signal" targetSignal="COL pin" srcVirtualSignal="//@virtualSignals.87" targetVirtualSignal="//@virtualSignals.5"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxer_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxer_pad" systemDefined="true" sourceSignal="RXER pin" targetSignal="RXER pin_signal" srcVirtualSignal="//@virtualSignals.7" targetVirtualSignal="//@virtualSignals.88"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxer_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxer_pad" systemDefined="true" sourceSignal="RXER pin_signal" targetSignal="RXER pin" srcVirtualSignal="//@virtualSignals.88" targetVirtualSignal="//@virtualSignals.7"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd0_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd0_pad" systemDefined="true" sourceSignal="RXD0 pin" targetSignal="RXD0 pin_signal" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.89"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd0_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd0_pad" systemDefined="true" sourceSignal="RXD0 pin_signal" targetSignal="RXD0 pin" srcVirtualSignal="//@virtualSignals.89" targetVirtualSignal="//@virtualSignals.9"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd1_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd1_pad" systemDefined="true" sourceSignal="RXD1 pin" targetSignal="RXD1 pin_signal" srcVirtualSignal="//@virtualSignals.11" targetVirtualSignal="//@virtualSignals.90"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd1_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd1_pad" systemDefined="true" sourceSignal="RXD1 pin_signal" targetSignal="RXD1 pin" srcVirtualSignal="//@virtualSignals.90" targetVirtualSignal="//@virtualSignals.11"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd2_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd2_pad" systemDefined="true" sourceSignal="RXD2 pin" targetSignal="RXD2 pin_signal" srcVirtualSignal="//@virtualSignals.13" targetVirtualSignal="//@virtualSignals.91"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd2_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd2_pad" systemDefined="true" sourceSignal="RXD2 pin_signal" targetSignal="RXD2 pin" srcVirtualSignal="//@virtualSignals.91" targetVirtualSignal="//@virtualSignals.13"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd3_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd3_pad" systemDefined="true" sourceSignal="RXD3 pin" targetSignal="RXD3 pin_signal" srcVirtualSignal="//@virtualSignals.15" targetVirtualSignal="//@virtualSignals.92"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxd3_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxd3_pad" systemDefined="true" sourceSignal="RXD3 pin_signal" targetSignal="RXD3 pin" srcVirtualSignal="//@virtualSignals.92" targetVirtualSignal="//@virtualSignals.15"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txen_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txen_pad" systemDefined="true" sourceSignal="TXEN pin" targetSignal="TXEN pin_signal" srcVirtualSignal="//@virtualSignals.17" targetVirtualSignal="//@virtualSignals.93"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txen_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txen_pad" systemDefined="true" sourceSignal="TXEN pin_signal" targetSignal="TXEN pin" srcVirtualSignal="//@virtualSignals.93" targetVirtualSignal="//@virtualSignals.17"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txer_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txer_pad" systemDefined="true" sourceSignal="TXER pin" targetSignal="TXER pin_signal" srcVirtualSignal="//@virtualSignals.19" targetVirtualSignal="//@virtualSignals.94"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txer_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txer_pad" systemDefined="true" sourceSignal="TXER pin_signal" targetSignal="TXER pin" srcVirtualSignal="//@virtualSignals.94" targetVirtualSignal="//@virtualSignals.19"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd0_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd0_pad" systemDefined="true" sourceSignal="TXD0 pin" targetSignal="TXD0 pin_signal" srcVirtualSignal="//@virtualSignals.21" targetVirtualSignal="//@virtualSignals.95"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd0_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd0_pad" systemDefined="true" sourceSignal="TXD0 pin_signal" targetSignal="TXD0 pin" srcVirtualSignal="//@virtualSignals.95" targetVirtualSignal="//@virtualSignals.21"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd1_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd1_pad" systemDefined="true" sourceSignal="TXD1 pin" targetSignal="TXD1 pin_signal" srcVirtualSignal="//@virtualSignals.23" targetVirtualSignal="//@virtualSignals.96"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd1_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd1_pad" systemDefined="true" sourceSignal="TXD1 pin_signal" targetSignal="TXD1 pin" srcVirtualSignal="//@virtualSignals.96" targetVirtualSignal="//@virtualSignals.23"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd2_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd2_pad" systemDefined="true" sourceSignal="TXD2 pin" targetSignal="TXD2 pin_signal" srcVirtualSignal="//@virtualSignals.25" targetVirtualSignal="//@virtualSignals.97"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd2_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd2_pad" systemDefined="true" sourceSignal="TXD2 pin_signal" targetSignal="TXD2 pin" srcVirtualSignal="//@virtualSignals.97" targetVirtualSignal="//@virtualSignals.25"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd3_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd3_pad" systemDefined="true" sourceSignal="TXD3 pin" targetSignal="TXD3 pin_signal" srcVirtualSignal="//@virtualSignals.27" targetVirtualSignal="//@virtualSignals.98"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txd3_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txd3_pad" systemDefined="true" sourceSignal="TXD3 pin_signal" targetSignal="TXD3 pin" srcVirtualSignal="//@virtualSignals.98" targetVirtualSignal="//@virtualSignals.27"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdc_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_mdc_pad" systemDefined="true" sourceSignal="MDC pin" targetSignal="MDC pin_signal" srcVirtualSignal="//@virtualSignals.29" targetVirtualSignal="//@virtualSignals.99"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_mdc_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdc_pad" systemDefined="true" sourceSignal="MDC pin_signal" targetSignal="MDC pin" srcVirtualSignal="//@virtualSignals.99" targetVirtualSignal="//@virtualSignals.29"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdio_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_mdio_pad" systemDefined="true" sourceSignal="MDIO pin" targetSignal="MDIO pin_signal" srcVirtualSignal="//@virtualSignals.31" targetVirtualSignal="//@virtualSignals.100"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_mdio_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_mdio_pad" systemDefined="true" sourceSignal="MDIO pin_signal" targetSignal="MDIO pin" srcVirtualSignal="//@virtualSignals.100" targetVirtualSignal="//@virtualSignals.31"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_ref_clk_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_ref_clk_pad" systemDefined="true" sourceSignal="REFCLK pin" targetSignal="REFCLK pin_signal" srcVirtualSignal="//@virtualSignals.35" targetVirtualSignal="//@virtualSignals.101"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_ref_clk_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_ref_clk_pad" systemDefined="true" sourceSignal="REFCLK pin_signal" targetSignal="REFCLK pin" srcVirtualSignal="//@virtualSignals.101" targetVirtualSignal="//@virtualSignals.35"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_tx_ctl_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_tx_ctl_pad" systemDefined="true" sourceSignal="TCTL pin" targetSignal="TCTL pin_signal" srcVirtualSignal="//@virtualSignals.37" targetVirtualSignal="//@virtualSignals.102"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_tx_ctl_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_tx_ctl_pad" systemDefined="true" sourceSignal="TCTL pin_signal" targetSignal="TCTL pin" srcVirtualSignal="//@virtualSignals.102" targetVirtualSignal="//@virtualSignals.37"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rx_ctl_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rx_ctl_pad" systemDefined="true" sourceSignal="RCTL pin" targetSignal="RCTL pin_signal" srcVirtualSignal="//@virtualSignals.39" targetVirtualSignal="//@virtualSignals.103"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rx_ctl_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rx_ctl_pad" systemDefined="true" sourceSignal="RCTL pin_signal" targetSignal="RCTL pin" srcVirtualSignal="//@virtualSignals.103" targetVirtualSignal="//@virtualSignals.39"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxc_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxc_pad" systemDefined="true" sourceSignal="RCLK pin" targetSignal="RCLK pin_signal" srcVirtualSignal="//@virtualSignals.41" targetVirtualSignal="//@virtualSignals.104"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rxc_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rxc_pad" systemDefined="true" sourceSignal="RCLK pin_signal" targetSignal="RCLK pin" srcVirtualSignal="//@virtualSignals.104" targetVirtualSignal="//@virtualSignals.41"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txc_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txc_pad" systemDefined="true" sourceSignal="TCLK pin" targetSignal="TCLK pin_signal" srcVirtualSignal="//@virtualSignals.44" targetVirtualSignal="//@virtualSignals.105"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_txc_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_txc_pad" systemDefined="true" sourceSignal="TCLK pin_signal" targetSignal="TCLK pin" srcVirtualSignal="//@virtualSignals.105" targetVirtualSignal="//@virtualSignals.44"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rx_dv_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rx_dv_pad" systemDefined="true" sourceSignal="RXDV pin" targetSignal="RXDV pin_signal" srcVirtualSignal="//@virtualSignals.46" targetVirtualSignal="//@virtualSignals.106"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_rx_dv_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_rx_dv_pad" systemDefined="true" sourceSignal="RXDV pin_signal" targetSignal="RXDV pin" srcVirtualSignal="//@virtualSignals.106" targetVirtualSignal="//@virtualSignals.46"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_gref_clk_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_gref_clk_pad" systemDefined="true" sourceSignal="GREFCLK pin" targetSignal="GREFCLK pin_signal" srcVirtualSignal="//@virtualSignals.48" targetVirtualSignal="//@virtualSignals.107"/>
  <connections URI="http://resources/4.0.8/app/ETHERNET_CONFIG/0/http://resources/4.0.8/app/ETHERNET_CONFIG/0/__pin_vs_gref_clk_pad/http://resources/4.0.8/app/ETHERNET_CONFIG/0/vs_gref_clk_pad" systemDefined="true" sourceSignal="GREFCLK pin_signal" targetSignal="GREFCLK pin" srcVirtualSignal="//@virtualSignals.107" targetVirtualSignal="//@virtualSignals.48"/>
</ResourceModel:App>
