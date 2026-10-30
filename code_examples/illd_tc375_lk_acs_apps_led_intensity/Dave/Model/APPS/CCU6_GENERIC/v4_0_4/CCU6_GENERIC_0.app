<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="CCU6_GENERIC" URI="http://resources/4.0.4/app/CCU6_GENERIC/0" description="This CCU6_GENERIC APP has no parameters. It is always used with the APPs that manages one of the channels of the CCU6 and exists to output a register (MOSEL) in code generation that determines whether the signals they output are output as signals (OUT1/2/3) to be output as a module" version="4.0.4" minDaveVersion="4.2.4" instanceLabel="CCU6_GENERIC_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../TIMER_CCU6/v4_0_8/TIMER_CCU6_0.app#//@requiredApps.1"/>
  <properties singleton="true" provideInit="true" sharable="true"/>
  <hwResources name="Common Block" URI="http://resources/4.0.4/app/CCU6_GENERIC/0/hwres_ccu6_common" resourceGroupUri="peripheral/ccu6/0/common" mResGrpUri="peripheral/ccu6/0/common">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CCU60/CCU60_0.dd#//@provided.0"/>
  </hwResources>
</ResourceModel:App>
