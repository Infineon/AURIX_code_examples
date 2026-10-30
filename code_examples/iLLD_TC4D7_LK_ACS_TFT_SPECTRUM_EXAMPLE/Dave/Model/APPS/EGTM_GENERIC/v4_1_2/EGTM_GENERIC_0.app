<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="EGTM_GENERIC" URI="http://resources/4.1.2/app/EGTM_GENERIC/0" description="This APP is used to configure the clocks for the eGTM blocks" version="4.1.2" minDaveVersion="4.2.4" instanceLabel="EGTM_GENERIC_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../TIMER_EGTM/v4_1_2/TIMER_EGTM_0.app#//@requiredApps.0"/>
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../TIMER_EGTM/v4_1_2/TIMER_EGTM_1.app#//@requiredApps.0"/>
  <properties singleton="true" provideInit="true" sharable="true"/>
  <requiredApps URI="http://resources/4.1.2/app/EGTM_GENERIC/0/appres_clock" requiredAppName="CLOCK" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK/v4_1_4/CLOCK_0.app#/"/>
  </requiredApps>
  <hwResources name="Common Block" URI="http://resources/4.1.2/app/EGTM_GENERIC/0/hwres_egtm_common" resourceGroupUri="peripheral/egtm/0/common" mResGrpUri="peripheral/egtm/0/common">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/EGTM0/EGTM0_0.dd#//@provided.20"/>
  </hwResources>
</ResourceModel:App>
