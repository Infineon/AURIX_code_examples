var initialized;

if (initialized == undefined)
{
    var texte_1 = oneeye.findWidgetById("TexteID");
    var triggerredAlarmSignal = new  JsSignal("elf.g_returnSMU")
    var triggerredAlarmSignal2 = new  JsSignal("elf.g_returnSMU")
    var smuAlarmStatus = new JsSignal("smuAlarmStatus")
    var smuAlarmStatus2 = new JsSignal("smuAlarmStatus2")
  
    /*------------------------------------------------ TRAP -----------------------------------------------------*/
    var selectProvokeTrap = new JsSignal("elf.g_SlkStatus.provokeTrapsSelect")

    /*------------------------------------------------ QSPI SAFE Communication --------------------------------- */
    var inject_ErrorTypeQspiSafe = new JsSignal("elf.g_ErrorTypeQspiSafe")
    
    /*------------------------------------------------ DMA ----------------------------------------------------- */
    var inject_dmaErrorStatus = new JsSignal("elf.g_dmaErrorStatus")
    
    /*----------------------------------------Digital Acquisition and actuation -------------------------------- */
    var selectedDigitalAcqActFuc = new JsSignal("elf.g_SlkStatus.digitalAcqActFucSelect")
    
    /*--------------------------------------------------Analog Acquisition ------------------------------------- */
    var selectedAnalogAcqActFuc = new JsSignal("elf.g_SlkStatus.analogAcqFucSelect")
     
    initialized = true;
}

alarmList= [
  "CPU0_Lockstep_Error ",
  "CPU0_Bus_MpuViolat- ",
  "CPU0_ReadPathError ",
  "Error ",
  "CPU0_PCACHE_ecc_uncor ",
  "CPU0_PCACHE_edc ",
  "CPU0_PSPR_ecc_cor ",
  "CPU0_PSPR_ecc_uncor ",
  "CPU0_PSPR_edc ",
  "CPU0_DSRP_ecc_cor ",
  "CPU0_DSRP_ecc_uncor ",
  "CPU0_DSRP_edc ",
  "CPU0_DTAG_ecc_cor ",
  "CPU0_DTAG_ecc_uncor ",
  "CPU0_DTAG_edc ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU0_Instr.SriEdc ",
  "CPU0_DataSriEdc ",
  "CPU0_CPU_Except.IntTrap ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU1_Lockstep_Error ",
  "CPU1_Bus_MpuViolat- ",
  "CPU1_ReadPathError ",
  "Error ",
  "CPU1_PCACHE_ecc_uncor ",
  "CPU1_PCACHE_edc ",
  "CPU1_PSPR_ecc_cor ",
  "CPU1_PSPR_ecc_uncor ",
  "CPU1_PSPR_edc ",
  "CPU1_DSRP_ecc_cor ",
  "CPU1_DSRP_ecc_uncor ",
  "CPU1_DSRP_edc ",
  "CPU1_DTAG_ecc_cor ",
  "CPU1_DTAG_ecc_uncor ",
  "CPU1_DTAG_edc ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU1_Instr.SriEdc ",
  "CPU1_DataSriEdc ",
  "CPU1_CPU_Except.IntTrap ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU2_Lockstep_Error ",
  "CPU2_Bus_MpuViolat- ",
  "CPU2_ReadPathError ",
  "Error ",
  "CPU2_PCACHE_ecc_uncor ",
  "CPU2_PCACHE_edc ",
  "CPU2_PSPR_ecc_cor ",
  "CPU2_PSPR_ecc_uncor ",
  "CPU2_PSPR_edc ",
  "CPU2_DSRP_ecc_cor ",
  "CPU2_DSRP_ecc_uncor ",
  "CPU2_DSRP_edc ",
  "CPU2_DTAG_ecc_cor ",
  "CPU2_DTAG_ecc_uncor ",
  "CPU2_DTAG_edc ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU2_Instr.SriEdc ",
  "CPU2_DataSriEdc ",
  "CPU2_CPU_Except.IntTrap ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU3_Lockstep_Error ",
  "CPU3_Bus_MpuViolat- ",
  "CPU3_ReadPathError ",
  "Error ",
  "CPU3_PCACHE_ecc_uncor ",
  "CPU3_PCACHE_edc ",
  "CPU3_PSPR_ecc_cor ",
  "CPU3_PSPR_ecc_uncor ",
  "CPU3_PSPR_edc ",
  "CPU3_DSRP_ecc_cor ",
  "CPU3_DSRP_ecc_uncor ",
  "CPU3_DSRP_edc ",
  "CPU3_DTAG_ecc_cor ",
  "CPU3_DTAG_ecc_uncor ",
  "CPU3_DTAG_edc ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU3_Instr.SriEdc ",
  "CPU3_DataSriEdc ",
  "CPU3_CPU_Except.IntTrap ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU4_Bus_MpuViolat- ",
  "CPU4_ReadPathError ",
  "Error ",
  "CPU4_PCACHE_ecc_uncor ",
  "CPU4_PCACHE_edc ",
  "CPU4_PSPR_ecc_cor ",
  "CPU4_PSPR_ecc_uncor ",
  "CPU4_PSPR_edc ",
  "CPU4_DSRP_ecc_cor ",
  "CPU4_DSRP_ecc_uncor ",
  "CPU4_DSRP_edc ",
  "CPU4_DTAG_ecc_cor ",
  "CPU4_DTAG_ecc_uncor ",
  "CPU4_DTAG_edc ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU4_Instr.SriEdc ",
  "CPU4_DataSriEdc ",
  "CPU4_CPU_Except.IntTrap ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU5_Bus_MpuViolat- ",
  "CPU5_ReadPathError ",
  "Error ",
  "CPU5_PCACHE_ecc_uncor ",
  "CPU5_PCACHE_edc ",
  "CPU5_PSPR_ecc_cor ",
  "CPU5_PSPR_ecc_uncor ",
  "CPU5_PSPR_edc ",
  "CPU5_DSRP_ecc_cor ",
  "CPU5_DSRP_ecc_uncor ",
  "CPU5_DSRP_edc ",
  "CPU5_DTAG_ecc_cor ",
  "CPU5_DTAG_ecc_uncor ",
  "CPU5_DTAG_edc ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "CPU5_Instr.SriEdc ",
  "CPU5_DataSriEdc ",
  "CPU5_CPU_Except.IntTrap ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "MTU_Safety_ecc_unc ",
  "IOM_Safety_ecc_unc ",
  "IR_Safety_ecc_unc ",
  "EMEM_Safety_ecc_unc ",
  "SCU_Safety_ecc_unc ",
  "PMS_Safety_ecc_unc ",
  "DMA_Safety_ecc_unc ",
  "SMU_core_Safety_ecc_unc ",
  "SYS_PLL_Safety_ecc_unc ",
  "Error ",
  "GTM_GTM_ecc_cor ",
  "GTM_GTM_ecc_uncor ",
  "GTM_GTM_edc ",
  "ERAY_ERAY_ecc_cor ",
  "ERAY_ERAY_ecc_uncor ",
  "ERAY_ERAY_edc ",
  "CAN_CAN_ecc_cor ",
  "CAN_CAN_ecc_uncor ",
  "CAN_CAN_edc ",
  "Misc_MISC_ecc_cor ",
  "Misc_MISC_ecc_uncor ",
  "Misc_MISC_edc ",
  "Error ",
  "CERBERUS_ecc_unc ",
  "CCU_Safety_ecc_cor ",
  "CCU_Safety_ecc_unc ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "LMU_FSI_RAM_ecc_cor ",
  "LMU_FSI_RAM_ecc_uncor ",
  "LMU_FSI_RAM_edc ",
  "EMEM_EMEM_ecc_cor ",
  "EMEM_EMEM_ecc_uncor ",
  "EMEM_EMEM_edc ",
  "SPU_CIF_ecc_cor ",
  "SPU_CIF_ecc_uncor ",
  "SPU_CIF_edc ",
  "Error ",
  "Error ",
  "Error ",
  "LMU_Lockstep_Error ",
  "LMU_Lockstep_CtrlErr ",
  "LMU_ECC_Error ",
  "LMU_Buslevel_MpuErr ",
  "LMU_EDC_ReadPhaseErr ",
  "XBAR0_SRI_BusError ",
  "XBAR1_SRI_BusError ",
  "XBAR2_SRI_BusError ",
  "SPB_BusError ",
  "BBB_BusError ",
  "FSI_PFlash_1BitErr ",
  "FSI_PFlash_2BitErr ",
  "FSI_Sgl_Bit_BuffFull ",
  "FSI_Dbl_Bit_BuffFull ",
  "FSI_Multiple_Bit_BuffFull ",
  "FSI_Zero_BitErr_BuffFull ",
  "FSI_PFlash_EccError ",
  "FSI_PFlash_EdcError ",
  "FSI_CPUFLASHCON_Conf ",
  "FSI_Flash_StoredConf ",
  "SCU_OS_Clock_Range ",
  "CCU_BckpClk_Range ",
  "CCU_BckpClck_Alive ",
  "SCU_Sys_PllLockLoss ",
  "SCU_Periph_PllLockLoss ",
  "SCU_LBIST_Alarm ",
  "SCU_ERU_Alarm0 ",
  "SCU_ERU_Alarm1 ",
  "SCU_ERU_Alarm2 ",
  "SCU_ERU_Alarm3 ",
  "SCU_CPU0_Wd_TO ",
  "SCU_CPU1_Wd_TO ",
  "SCU_CPU2_Wd_TO ",
  "SCU_CPU3_Wd_TO ",
  "SCU_CPU4_Wd_TO ",
  "SCU_CPU5_Wd_TO ",
  "SCU_Safety_Wd_TO ",
  "SCU_Watchdog_TimeOut ",
  "SCU_LS_DualRail ",
  "SCU_EmergencyStop ",
  "SCU_Pad_HeatingAlarm ",
  "SCU_LBIST_TestMode ",
  "IR_EDC_ConfDataPath ",
  "DMA_DMASRI_EccError ",
  "Error ",
  "IOM_Pin_Mismatch ",
  "SCU_ERU_Alarm4 ",
  "SCU_ERU_Alarm5 ",
  "SCU_ERU_Alarm6 ",
  "SCU_ERU_Alarm7 ",
  "DTS_core_Under_Temp ",
  "DTS_core_Over_Temp ",
  "DTS_Temp_Overflow ",
  "DTS_Temp_Underflow ",
  "Error ",
  "EVR_Overvoltage ",
  "Error ",
  "EVR_Undervoltage ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "EVR_Short_ToLowHight ",
  "HSM_Overvoltage ",
  "HSM_Undervoltage ",
  "Error ",
  "Error ",
  "EMEM_Unexpected_Write ",
  "EMEM_SEP_ControlLogic ",
  "EMEM_LS_CtrlLogicInput ",
  "SPULCKSTP_Comparator ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "SPU_SPU0_SafetyAlarm ",
  "SPU_SPU1_SafetyAlarm ",
  "RIF_RIF0_SafetyAlarm ",
  "RIF_RIF1_SafetyAlarm ",
  "Soft_Alm0: ISR CFG check ",
  "Soft_Alm1: Broken Wire Detection ",
  "Soft_Alm2: Analog ",
  "Soft_Alm3: ECKL monitor",
  "Soft_Alm4: ISR monitor",
  "Soft_Alm5: SBST Crc or Internal Bus Error",
  "Soft_Alm6: QSPI Safe",
  "Soft_Alm7: Digital ",
  "Soft_Alm8: DTS",
  "Soft_Alm9: DMA ",
  "Soft_Alm10: CPU monitor",
  "Soft_Alm11: STM monitor",
  "Soft_Alm12: Pflash/Lmu ",
  "Soft_Alm13: Trap Monitor",
  "Soft_Alm14: Port",
  "Soft_Alm15: Clock Plaus",
  "SMU_Timer0_TimeOut ",
  "SMU_Timer1_TimeOut ",
  "SMU_Pin_FS_Activation ",
  "Error ",
  "SMU_Safety_ecc_cor ",
  "SMU_Safety_ecc_unc ",
  "SMU_Access_EnableErrDetect ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "Error ",
  "LMU_EDC_AddPhase ",
  "LMU_EDC_WritePhase ",
  "XBAR_EDC_AddPhase ",
  "XBAR_EDC_WritePhase ",
  "DMU_EDC_AddPhase ",
  "DMU_EDC_WritePhase ",
  "SFI_BBB_EDC_AddPhase ",
  "SFI_BBB_EDC_WritePhase ",
  "SRI_EDC_ReadPhase ",
  "SFI_SPB_EDC_ReadPhase ",
  "HSSL_HSSL0EDC_ReadPhase ",
  "HSSL_HSSL1EDC_ReadPhase ",
  "CONVERTER_Phase_Syncro ",
  "See alarm status regs", 
  "No alarm detected"  /* This alarm message is just added if we don't have any alarm and show message of alarm status */
]

/* --------------------------when No alarm is pending------------------------- */
if (triggerredAlarmSignal.value == 366)
{ 
    smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value];
    smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value];
    oneeye.findWidgetById("SMUSTATUS").setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
    oneeye.findWidgetById("SMUSTATUS2").setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* ---------- TRAP -----ALM10[13] : Safety Mechanism: Software Monitor Alarm: Software Alarm 13 ----*/
else if (triggerredAlarmSignal.value == 333)  
{ 
    if (selectProvokeTrap.value == 1)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Sync HW"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Sync HW"
    }
    
    else if (selectProvokeTrap.value == 2)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Async HW"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Async HW"
    }
    
    else if (selectProvokeTrap.value == 3)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Sync SW"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Sync SW"
    }
    
    else if (selectProvokeTrap.value == 4)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Protection"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Protection"
    }
    
    else if (selectProvokeTrap.value == 5)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " NMI"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " NMI"
    }
    else
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] 
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value]
    }
    oneeye.findWidgetById("SMUSTATUS").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
    oneeye.findWidgetById("SMUSTATUS2").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* ---------- DMA ----- ALM10[9] : Safety Mechanism: Software Monitor Alarm: Software Alarm 9 ----*/
else if (triggerredAlarmSignal.value == 329)  
{ 
    if (inject_dmaErrorStatus.value == 1)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Address CRC Error "
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Address CRC Error "
    }  
    else if (inject_dmaErrorStatus.value == 2)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Data CRC Error"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Data CRC Error"
    }    
    else if (inject_dmaErrorStatus.value == 4)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Timestamp Error"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Timestamp Error"
    }
    else if (inject_dmaErrorStatus.value == 64 )
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Wrong Data Error"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Wrong Data Error"
    }
    else
    {
    }   
    oneeye.findWidgetById("SMUSTATUS").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
    oneeye.findWidgetById("SMUSTATUS2").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* ----------QSPI SAFE Communication -----ALM10[6] : Safety Mechanism: Software Monitor Alarm: Software Alarm 6 ------*/
else if (triggerredAlarmSignal.value == 326) 
{
    if (inject_ErrorTypeQspiSafe.value == 1)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Data Corrupt"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Data Corrupt"
    }
    else if (inject_ErrorTypeQspiSafe.value == 2)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Early Frame"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Early Frame"
    }
    else if (inject_ErrorTypeQspiSafe.value == 3)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Late Frame"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Late Frame"
    }
    else if (inject_ErrorTypeQspiSafe.value == 4)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + " Frame timeout"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + " Frame timeout"
    }
    else 
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] 
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value]
    }
    oneeye.findWidgetById("SMUSTATUS").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
    oneeye.findWidgetById("SMUSTATUS2").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* ---------- Digital Acquisition and Actuation ----- ALM10[7] : Safety Mechanism: Software Monitor Alarm: Software Alarm 7 ----*/
else if (triggerredAlarmSignal.value == 327)  
{ 
    if (selectedDigitalAcqActFuc.value == 1)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: TIM TIM "
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: TIM TIM"
    }
    
    else if (selectedDigitalAcqActFuc.value == 2)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: TIM TIM HW Diversity"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: TIM TIM HW Diversity"
    }
    else if (selectedDigitalAcqActFuc.value == 3)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: TIM CCU6"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: TIM CCU6"
    }
    else if (selectedDigitalAcqActFuc.value == 4)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: CCU6 GPT12"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: CCU6 GPT12"
    }
    else if (selectedDigitalAcqActFuc.value == 5)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: CCU6 GPT12, 1 pin"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: CCU6 GPT12, 1 pin"
    }
    else if (selectedDigitalAcqActFuc.value == 6)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Actuation: TOM IOM"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Actuation: TOM IOM"
    }
    else if (selectedDigitalAcqActFuc.value == 7)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Actuation: CCU6 IOM"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Actuation: CCU6 IOM"
    }
    else if (selectedDigitalAcqActFuc.value == 8)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Actuation: TOM TIM"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Actuation: TOM TIM"
    }
    else if (selectedDigitalAcqActFuc.value == 9)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Actuation: CCU6 GPT12"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Actuation: CCU6 GPT12"
    }               
    else
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Actuation or Acquisition"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Actuation or Acquisition"
    }
    oneeye.findWidgetById("SMUSTATUS").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
    oneeye.findWidgetById("SMUSTATUS2").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* ---------- Analog Acquisition ------------------ ALM10[3] : Safety Mechanism: Software Monitor Alarm: Software Alarm 7 ----*/
else if (triggerredAlarmSignal.value == 322)  
{ 
    if (selectedAnalogAcqActFuc.value == 1)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: EVADC EVADC "
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: EVADC EVADC"
    }
    else if (selectedAnalogAcqActFuc.value == 2)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: EDSADC EDSADC"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: EDSADC EDSADC"
    }   
    else if (selectedAnalogAcqActFuc.value == 3)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: EVADC EDSADC"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: EVADC EDSADC"
    } 
    else if (selectedAnalogAcqActFuc.value == 4)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: EVADC 1 Pin"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: EVADC 1 Pin"
    }  
    else if (selectedAnalogAcqActFuc.value == 5)
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition: EVADC EDSADC 1 Pin"
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition: EVADC EDSADC 1 Pin"
    }             
    else
    {
        smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] + "Acquisition "
        smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value] + "Acquisition"
    }
    oneeye.findWidgetById("SMUSTATUS").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
    oneeye.findWidgetById("SMUSTATUS2").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* any other alarm is pending */
else
{
    smuAlarmStatus.value = alarmList[triggerredAlarmSignal.value] 
    smuAlarmStatus2.value = alarmList[triggerredAlarmSignal2.value]
    oneeye.findWidgetById("SMUSTATUS").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
    oneeye.findWidgetById("SMUSTATUS2").setProperty("style-sheet","#__title { color : rgba(120,30,30,1); font-weight : Bold; font-size: 18pt }#__lineEdit { color : rgba(120,30,30,1);  background-color: lightgray; font-size: 12pt; font-weight : Bold }  #__unit { color:blue } ");
}



