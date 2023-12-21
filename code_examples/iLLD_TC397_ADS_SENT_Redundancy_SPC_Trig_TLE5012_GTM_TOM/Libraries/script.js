var initialized;

if (initialized == undefined)
{
  /* variable used to change style sheet run time */
  var x = oneeye.findWidgetById("difference");

  /* variable used to change title run time */
  var y = new  JsSignal("elf.g_angleCoveredDifference");

  /* variable for alarm */
  var z = new  JsSignal("elf.g_alarmFlag");

  initialized = true;
}

if (z.value == true)
{
   y.setProperty("title", "Alarm: Angle Difference  (exceeds limit) ")
   x.setProperty("style-sheet","#__title { color: red; font-weight : Bold; font-size: 14pt } #__lineEdit { color: red;  background-color: lightgray; font-size: 14pt; font-weight : Bold }  #__unit { color:blue } ");
}
else 
{
   y.setProperty("title", "Angle Difference (within limit) ")
   x.setProperty("style-sheet","#__title { color: green; font-size: 14pt }#__lineEdit { color: green;  background-color: lightgray; font-size: 14pt;} #__unit { color:blue } ");
}

