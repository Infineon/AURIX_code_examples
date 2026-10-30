<img src="./Images/IFX_LOGO_600.gif" alt="Infineon Technologies" align="right" width="150">

# iLLD_TC4D7_ACS_DEEPCRAFT_ML_PROFILER

## Abstract

Example project for deploying and validating ML models on the Aurix TC4D7 Lite Kit

This code example is organized as a **multi-architecture project**, meaning it
contains multiple separate sub-projects that target different processor cores
on the same device: the TriCore&trade; and the PPU (ARC EV) of the AURIX&trade;
TC4D7.

## Project Structure

- **TriCore&trade; project** ([*illd_tc4d7_acs_deepcraft_ml_profiler_TC4*](illd_tc4d7_acs_deepcraft_ml_profiler_TC4/README.md)) —
  runs on the main TriCore&trade; core (CPU0). Owns the boot sequence, the
  streaming protocol, both transports, the local self-test harness, the shared
  configuration in *PpuShared/* and the *tools/* scripts that build and flash
  both images.
- **PPU project** ([*illd_tc4d7_acs_deepcraft_ml_profiler_PPU*](illd_tc4d7_acs_deepcraft_ml_profiler_PPU/README.md)) —
  runs on the PPU (ARC EV) core. Needed only when *APP_INFER* is
  *APP_INFER_PPU*; it accepts a model input over a shared-memory mailbox, runs
  *IMAI_compute()*, and hands the output back.

## Further Information

Each sub-project has its own dedicated README with architecture-specific
details, build instructions, and usage notes. Start with the
[TriCore&trade; README](illd_tc4d7_acs_deepcraft_ml_profiler_TC4/README.md), which covers
the code example as a whole; refer to the
[PPU README](illd_tc4d7_acs_deepcraft_ml_profiler_PPU/README.md) for what is specific to
the PPU image.
