var initialized;

  /* -------------------------------------------------------- LBIST -----------------------------------------------------------------*/
  var lbist_1 = oneeye.findWidgetById("TerminatedPORST");
  var lbist_2 = oneeye.findWidgetById("TerminatedProperly");
  var lbist_3 = oneeye.findWidgetById("LbistDone");
  var lbist_4_copy = oneeye.findWidgetById("LBIST_copy");
  var lbist_4 = oneeye.findWidgetById("LBIST");
  
  var lbist_1_sig = new  JsSignal("elf.g_LbistStatus.lbistNotTerminatedByPORST");
  var lbist_2_sig = new  JsSignal("elf.g_LbistStatus.lbistTerminatedProperly");
  var lbist_3_sig = new  JsSignal("elf.g_LbistStatus.lbistDone");
  var lbist_4_sig_copy = new  JsSignal("elf.g_SlkStatus.sswStatus.lbistStatus");
  var lbist_4_sig = new  JsSignal("elf.g_SlkStatus.sswStatus.lbistStatus");
  
  /* -------------------------------------------------------- MONBIST -----------------------------------------------------------------*/
  var monbist_1 = oneeye.findWidgetById("TestOk");
  var monbist_2 = oneeye.findWidgetById("SmuError");
  var monbist_3 = oneeye.findWidgetById("PmsError");
  var monbist_4_copy = oneeye.findWidgetById("MONBIST_copy");
  var monbist_4 = oneeye.findWidgetById("MONBIST");

  var monbist_1_sig = new  JsSignal("elf.g_MonbistStatus.testOkFlag");
  var monbist_2_sig = new  JsSignal("elf.g_MonbistStatus.smuErrorFlag");
  var monbist_3_sig = new  JsSignal("elf.g_MonbistStatus.pmsErrorFlag");
  var monbist_4_sig_copy = new  JsSignal("elf.g_SlkStatus.sswStatus.monbistStatus");
  var monbist_4_sig = new  JsSignal("elf.g_SlkStatus.sswStatus.monbistStatus");

  /* -------------------------------------------------------- MCU FW CHECK -----------------------------------------------------------------*/
  var mcufw_1 = oneeye.findWidgetById("CheckSMU");
  var mcufw_2 = oneeye.findWidgetById("CheckScuStem");
  var mcufw_3 = oneeye.findWidgetById("CheckScuLclcon");
  var mcufw_4 = oneeye.findWidgetById("CheckSsh");
  var mcufw_5_copy = oneeye.findWidgetById("MCUFWCHECK_copy");
  var mcufw_5 = oneeye.findWidgetById("MCUFWCHECK");

  var mcufw_1_sig = new  JsSignal("elf.g_mcuFwCheckStatus.mcuFwCheckSmu");
  var mcufw_2_sig = new  JsSignal("elf.g_mcuFwCheckStatus.mcuFwCheckScuStem");
  var mcufw_3_sig = new  JsSignal("elf.g_mcuFwCheckStatus.mcuFwCheckScuLclcon");
  var mcufw_4_sig = new  JsSignal("elf.g_mcuFwCheckStatus.mcuFwCheckSsh");
  var mcufw_5_sig = new  JsSignal("elf.g_SlkStatus.sswStatus.mcuFwcheckStatus");
  var mcufw_5_sig_copy = new  JsSignal("elf.g_SlkStatus.sswStatus.mcuFwcheckStatus");

  /* -------------------------------------------------------- MCU STARTUP -----------------------------------------------------------------*/
  var mcustart_3_copy = oneeye.findWidgetById("MCUSTARTUP_copy");
  var mcustart_3 = oneeye.findWidgetById("MCUSTARTUP");
    
  var mcustart_3_sig_copy = new  JsSignal("elf.g_SlkStatus.sswStatus.mcuStartupStatus");
  var mcustart_3_sig = new  JsSignal("elf.g_SlkStatus.sswStatus.mcuStartupStatus");

  /* -------------------------------------------------------- ALIVE TEST -----------------------------------------------------------------*/
  var alive_1 = oneeye.findWidgetById("TestSts");
  var alive_2 = oneeye.findWidgetById("TestClearSts");
  var alive_3_copy = oneeye.findWidgetById("ALIVETEST_copy");
  var alive_3 = oneeye.findWidgetById("ALIVETEST");
    
  var alive_1_sig = new  JsSignal("elf.g_SlkStatus.smuStatus.smuCoreAliveTestSts");
  var alive_2_sig = new  JsSignal("elf.g_SlkStatus.smuStatus.smuCoreAliveTestClearSts");
  var alive_3_sig_copy = new  JsSignal("elf.g_SlkStatus.sswStatus.aliveAlarmTestStatus");
  var alive_3_sig = new  JsSignal("elf.g_SlkStatus.sswStatus.aliveAlarmTestStatus");    

  /* -------------------------------------------------------- REG MONITOR TEST -----------------------------------------------------------------*/
  var reg_1 = oneeye.findWidgetById("FlipFlopTriggerTestSts");
  var reg_2 = oneeye.findWidgetById("FlipFlopTestResultCheckSts");
  var reg_3 = oneeye.findWidgetById("FlipFlopTestAlarmFlagClearSts");
  var reg_4_copy = oneeye.findWidgetById("REGMONITOR_copy");
  var reg_4 = oneeye.findWidgetById("REGMONITOR");

  var reg_1_sig = new  JsSignal("elf.g_SlkStatus.smuStatus.smuSafetyFlipFlopTriggerTestSts");
  var reg_2_sig = new  JsSignal("elf.g_SlkStatus.smuStatus.smuSafetyFlipFlopTestResultCheckSts");
  var reg_3_sig = new  JsSignal("elf.g_SlkStatus.smuStatus.smuSafetyFlipFlopTestAlarmFlagClearSts");
  var reg_4_sig_copy = new  JsSignal("elf.g_SlkStatus.smuStatus.regMonitorTestSmu");
  var reg_4_sig = new  JsSignal("elf.g_SlkStatus.smuStatus.regMonitorTestSmu");    

  /* -------------------------------------------------------- MBIST -----------------------------------------------------------------*/
  var mbist_1_copy = oneeye.findWidgetById("MBIST_copy");
  var mbist_1 = oneeye.findWidgetById("MBIST");
  var mbist_2 = oneeye.findWidgetById("MbistErrors");

  var mbist_1_sig_copy = new  JsSignal("elf.g_SlkStatus.sswStatus.mbistStatus");
  var mbist_1_sig = new  JsSignal("elf.g_SlkStatus.sswStatus.mbistStatus");
  var mbist_2_sig = new  JsSignal("elf.g_MbistStatus.noMbistError");

  /* -------------------------------------------------------- CPU -------------------------------------------------------------------*/
  var CPU_ap_check = oneeye.findWidgetById("AP_CHECK_FLAG");
  var CPU_mpu_init_flag = oneeye.findWidgetById("MPU_INIT_FLAG");
  var CPU_code_mpu_flag = oneeye.findWidgetById("CODE_MPU_FLAG");
  var CPU_data_mpu_flag = oneeye.findWidgetById("DATA_MPU_FLAG");
  var CPU_SFR_test = oneeye.findWidgetById("SFR_TEST");

  var CPU_ap_check_sig = new JsSignal("elf.g_CpuStatus.AP_CHECK_FLAG");
  var CPU_mpu_init_flag_sig = new JsSignal("elf.g_CpuStatus.MPU_INIT_FLAG");
  var CPU_code_mpu_flag_sig = new JsSignal("elf.g_CpuStatus.CODE_MPU_FLAG");
  var CPU_data_mpu_flag_sig = new JsSignal("elf.g_CpuStatus.DATA_MPU_FLAG");
  var CPU_SFR_test_sig = new JsSignal("elf.g_CpuStatus.SFR_FLAG");

  /* -------------------------------------------------- Clock Plausibility ----------------------------------------------------------*/
    var clock_plausibility_check = oneeye.findWidgetById("CLOCK_PLAUS");
    var clock_plausibility_check_sig = new JsSignal("elf.g_SlkStatus.timeDiffQspiClockPlaus");
	
 /* ******************************************************************************************************************************** */

/* -------------------------------------------------------- LBIST -----------------------------------------------------------------*/

if (lbist_1_sig.value == 1)
{ 
    lbist_1.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (lbist_1_sig.value == 2)
{ 
    lbist_1.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    lbist_1.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (lbist_2_sig.value == 1)
{ 
    lbist_2.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (lbist_2_sig.value == 2)
{ 
    lbist_2.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    lbist_2.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (lbist_3_sig.value == 1)
{ 
    lbist_3.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (lbist_3_sig.value == 2)
{ 
    lbist_3.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    lbist_3.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (lbist_4_sig_copy.value == 1)
{ 
    lbist_4_copy.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (lbist_4_sig_copy.value == 2)
{ 
    lbist_4_copy.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else
{
    lbist_4_copy.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}


if (lbist_4_sig.value == 1)
{ 
    lbist_4.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (lbist_4_sig.value == 2)
{ 
    lbist_4.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else
{
   lbist_4.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* -------------------------------------------------------- MONBIST -----------------------------------------------------------------*/
if (monbist_1_sig.value == 1)
{ 
    monbist_1.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (monbist_1_sig.value == 2)
{ 
    monbist_1.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    monbist_1.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (monbist_2_sig.value == 1)
{ 
    monbist_2.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    monbist_2.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (monbist_3_sig.value == 1)
{ 
    monbist_3.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    monbist_3.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (monbist_4_sig_copy.value == 1)
{ 
    monbist_4_copy.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{   
    monbist_4_copy.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");   
}

if (monbist_4_sig.value == 1)
{ 
    monbist_4.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    monbist_4.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* -------------------------------------------------------- MCU FW CHECK -----------------------------------------------------------------*/
if (mcufw_2_sig.value == 1)
{ 
    mcufw_2.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    mcufw_2.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (mcufw_3_sig.value == 1)
{ 
    mcufw_3.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    mcufw_3.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (mcufw_4_sig.value == 1)
{ 
    mcufw_4.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    mcufw_4.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (mcufw_5_sig_copy.value == 1)
{ 
    mcufw_5_copy.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{   
    mcufw_5_copy.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");   
}

if (mcufw_5_sig.value == 1)
{ 
    mcufw_5.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    mcufw_5.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* -------------------------------------------------------- MCU STARTUP -----------------------------------------------------------------*/
if (mcustart_3_sig_copy.value == 1)
{ 
    mcustart_3_copy.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{   
    mcustart_3_copy.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");   
}

if (mcustart_3_sig.value == 1)
{ 
    mcustart_3.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    mcustart_3.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* -------------------------------------------------------- ALIVE TEST -----------------------------------------------------------------*/
if (alive_1_sig.value == 1)
{ 
    alive_1.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (alive_1_sig.value == 2)
{ 
    alive_1.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    alive_1.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (alive_2_sig.value == 1)
{ 
    alive_2.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (alive_2_sig.value == 2)
{ 
    alive_2.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    alive_2.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (alive_3_sig_copy.value == 1)
{ 
	alive_3_copy.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (alive_3_sig_copy.value == 2)
{ 
    alive_3_copy.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{   
    alive_3_copy.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");   
}

if (alive_3_sig.value == 1)
{ 
    alive_3.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else if (alive_3_sig.value == 2)
{ 
    alive_3.setProperty("style-sheet","#__title { color : blue; font-weight : Bold; font-size: 10pt }#__lineEdit { color : blue;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    alive_3.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* -------------------------------------------------------- REG MONITOR TEST -----------------------------------------------------------------*/
if (reg_1_sig.value == 1)
{ 
    reg_1.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    reg_1.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (reg_2_sig.value == 1)
{ 
    reg_2.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    reg_2.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (reg_3_sig.value == 1)
{ 
    reg_3.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    reg_3.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (reg_4_sig_copy.value == 1)
{ 
	reg_4_copy.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{   
    reg_4_copy.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");   
}

if (reg_4_sig.value == 1)
{ 
    reg_4.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    reg_4.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* -------------------------------------------------------- MBIST -----------------------------------------------------------------*/
if (mbist_1_sig_copy.value == 1)
{ 
	mbist_1_copy.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{   
    mbist_1_copy.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");   
}

if (mbist_1_sig.value == 1)
{ 
    mbist_1.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    mbist_1.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (mbist_2_sig.value == 1)
{ 
    mbist_2.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    mbist_2.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

/*--------------------------------------------------------- CPU -------------------------------------------------------------------*/
if (CPU_ap_check_sig.value == 1)
{ 
    CPU_ap_check.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    CPU_ap_check.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (CPU_mpu_init_flag_sig.value == 1)
{ 
    CPU_mpu_init_flag.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    CPU_mpu_init_flag.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (CPU_code_mpu_flag_sig.value == 1)
{ 
    CPU_code_mpu_flag.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    CPU_code_mpu_flag.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (CPU_data_mpu_flag_sig.value == 1)
{ 
    CPU_data_mpu_flag.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    CPU_data_mpu_flag.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

if (CPU_SFR_test_sig.value == 1)
{ 
    CPU_SFR_test.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 10pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    CPU_SFR_test.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 10pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}

/* -------------------------------------------------- Clock Plausibility ----------------------------------------------------------*/
 /* the values are coming from source code */
 if (clock_plausibility_check_sig.value < 105.0105 && clock_plausibility_check_sig.value > 95.0095)
{ 
    clock_plausibility_check.setProperty("style-sheet","#__title { color : rgba(100, 200,100,1); font-weight : Bold; font-size: 12pt }#__lineEdit { color : rgba(100, 200,100,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
    clock_plausibility_check.setProperty("style-sheet","#__title { color: rgba(120,30,30,1); font-size: 12pt } #__lineEdit { color: rgba(120,30,30,1);  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}