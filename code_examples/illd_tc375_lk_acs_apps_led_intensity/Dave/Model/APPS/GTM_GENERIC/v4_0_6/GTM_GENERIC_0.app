<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="GTM_GENERIC" URI="http://resources/4.0.6/app/GTM_GENERIC/0" description="This APP is used to configure the clocks for the GTM blocks" version="4.0.6" minDaveVersion="4.2.4" instanceLabel="GTM_GENERIC_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../PWM_GTM/v4_0_4/PWM_GTM_0.app#//@requiredApps.0"/>
  <properties singleton="true" provideInit="true" sharable="true"/>
  <requiredApps URI="http://resources/4.0.6/app/GTM_GENERIC/0/appres_clock" requiredAppName="CLOCK" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK/v4_1_8/CLOCK_0.app#/"/>
  </requiredApps>
  <hwResources name="Common Block" URI="http://resources/4.0.6/app/GTM_GENERIC/0/hwres_gtm_common" resourceGroupUri="peripheral/gtm/0/common" mResGrpUri="peripheral/gtm/0/common">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/GTM0/GTM0_0.dd#//@provided.22"/>
  </hwResources>
</ResourceModel:App>
