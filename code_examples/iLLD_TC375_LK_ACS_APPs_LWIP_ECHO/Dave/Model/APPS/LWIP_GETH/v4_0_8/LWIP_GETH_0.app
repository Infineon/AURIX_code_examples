<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="LWIP_GETH" URI="http://resources/4.0.8/app/LWIP_GETH/0" description="LwIP (lightweight IP) is an open source TCP/IP stack designed for embedded systems. LwIP stack supports the IP, TCP, UDP, ICMP, IGMP, ARP, DHCP, AutoIP, DNS and SNMP protocols. LwIP is provided under BSD style license and maintained at http://savannah.nongnu.org/projects/lwip." mode="NOTSHARABLE" version="4.0.8" minDaveVersion="4.2.4" instanceLabel="LWIP_GETH_0" appLabel="">
  <properties singleton="true" provideInit="true"/>
  <requiredApps URI="http://resources/4.0.8/app/LWIP_GETH/0/appres_timer_stm" requiredAppName="TIMER_STM" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../TIMER_STM/v4_1_6/TIMER_STM_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.8/app/LWIP_GETH/0/appres_printf" requiredAppName="PRINTF_ASCLIN" required="false" requiringMode="SHARABLE"/>
  <requiredApps URI="http://resources/4.0.8/app/LWIP_GETH/0/appres_freertos" requiredAppName="FREERTOS_AURIX" required="false" requiringMode="SHARABLE"/>
  <requiredApps URI="http://resources/4.0.8/app/LWIP_GETH/0/appres_ethernet_0" requiredAppName="ETHERNET_CONFIG">
    <downwardMapList xsi:type="ResourceModel:App" href="../../ETHERNET_CONFIG/v4_0_8/ETHERNET_CONFIG_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.8/app/LWIP_GETH/0/appres_ethernet_1" requiredAppName="ETHERNET_CONFIG" required="false"/>
</ResourceModel:App>
