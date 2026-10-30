<img src="./iLLD_TC4D7_ACS_Examples_TC4/Images/IFX_LOGO_600.gif" align="right" width="150" />  

# AURIX TC4x Example — TriCore + PPU

This example is organized as a **multi-architecture project**, meaning it contains two separate sub-projects that target different processor cores on the same device. Each sub-project is built and flashed independently, producing its own ELF file.

## Project Structure

- **Host project (TriCore)** — Runs on the main TriCore core. Its primary responsibility is to initialize the system and start up the secondary processor core.
- **Accelerator project** — Runs on the secondary processor core. It contains the actual application code.

## How It Works

The two projects work together at runtime: the TriCore host boots first, sets up the necessary resources, and then releases the secondary core to execute its own firmware. Both cores operate independently from their respective ELF images.

## Further Information

Each sub-project has its own dedicated README with architecture-specific details, build instructions, and usage notes. Please refer to those for further information.