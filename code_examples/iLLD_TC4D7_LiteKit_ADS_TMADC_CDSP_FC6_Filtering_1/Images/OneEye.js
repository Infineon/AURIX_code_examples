// ============================================================
// CDSP_FFT_Demo: Script to plot a 256-element array as a live XY graph
// ============================================================
//
// This script is executed once after the configuration is loaded
// (see the 'after-configuration-load' attribute in the <config> tag).
//
// What it does:
//   - Defines a function that reads 256 array values and plots them
//     on the XY graph (X = index 0..255, Y = value).
//   - Creates a JS timer that calls the update function every 100 ms.
//   - Exposes startTimer() and stopTimer() functions that are called
//     by the "Start live update" / "Stop live update" buttons.
//
// How to adapt to a real target (e.g. Lauterbach TRACE32 / JLink):
//   Replace the body of getArrayData() with a real memory read.
//   For example, if the target has a float array at address 0x20001000:
//
// ============================================================

oneeye.loadStyleSheet("blue")  // Loads the GUI with blue theme

// --- Graph reference (cached once at load time) ---
var graphFFT = oneeye.findWidgetById("graphFFT");

// --- Graph update function called by the timer ---
function updateGraph()
{
    // Clear the previous frame
    graphFFT.clear();

    // Retrieve channel 0 and populate it with (index, value) pairs
    var channel = graphFFT.getChannel(0);
    for (var i = 0; i < 256; i++)
    {
        var sig = new JsSignal("g_CdspFilters.fftSignalA.fftSignalA[" + i + "]");
        channel.addPoint(i, sig.value);
    }
}

var groupSinusoidal = oneeye.findWidgetById("SinusoidalSignals");
var groupPulseTrain = oneeye.findWidgetById("PulsetrainSignals");
var buttonMode = oneeye.findWidgetById("ModeChange");

// --- Call back function to update the mode from button ---
function modeChange()
{
    var sig = new JsSignal("g_Signal.signalMode");
    if(sig.value == 0)
    {
        sig.value= 1;
    }
    else
    {
        sig.value= 0;
    }
    
    setMode();
}

// --- Function to toggle the button and update the GUI as selected by the mode button ---
function setMode()
{
    var sig = new JsSignal("g_Signal.signalMode");
    if(sig.value == 0)
    {
        buttonMode.setProperty("button-execute-title", "Sinisoidal");
        groupPulseTrain.setProperty("visible", "no");
        groupSinusoidal.setProperty("visible", "yes");
    }
    else
    {
        buttonMode.setProperty("button-execute-title", "Pulsetrain");
        groupSinusoidal.setProperty("visible", "no");
        groupPulseTrain.setProperty("visible", "yes");
    }
}

// --- Timer (28.6 ms interval (35 Hz, same as CDSP gate trigger), auto-started, continuous) ---
var updateTimer1 = new oneeye.Timer(28.6, "{jsCall:updateGraph}", true, false);

// --- Timer (250 ms interval, auto-started, continuous) ---
var updateTimer2 = new oneeye.Timer(250, "{jsCall:setMode}", true, false);

// Draw the first frame immediately so the graph is not empty on load
setMode();
updateGraph();
