<#
.SYNOPSIS
    Build and/or flash the AURIX(TM) DEEPCRAFT streaming firmware from the command
    line, using the AURIX Configuration Studio (ACS) toolchains and flasher.

.DESCRIPTION
    Wraps the same tools ACS uses, so the edit -> build -> flash loop can run
    without the IDE. Unlike the ADS version of this script, BOTH images can be
    built here: the PPU is ARC-LLVM clang, which works fine from the command line.

      TriCore : make + tricore-elf-gcc-11   ->  illd_tc4d7_acs_deepcraft_ml_profiler_TC4/Debug
      PPU     : make + ARC-LLVM clang       ->  illd_tc4d7_acs_deepcraft_ml_profiler_PPU/Debug
      Flash   : AURIXFlasher.exe            ->  erase/program, then a DCO reset

    The firmware is TWO images that must agree on the shared IPC layout
    (PpuShared/ppu_ipc.h), so -Target defaults to 'both'.

    NOTE: a plain 'make' does NOT regenerate the Eclipse-managed makefiles. If you
    ADD/REMOVE source files or change .cproject (include paths, defines, excludes),
    build once inside ACS first so it regenerates subdir.mk and the -I response
    files, then this script can take over for source-only iterations.

    NOTE: the PPU build needs -DONNX2C_MEMMAP, which ACS does not store durably
    (see README "PPU preprocessor defines"). Ppu_Main.c fails the build with an
    explanatory #error if it goes missing.

.PARAMETER Action
    build | flash | all (default) | clean

.PARAMETER Target
    tricore | ppu | both (default)

.PARAMETER DasId
    DAS port index of the target (default 0).

.PARAMETER AcsRoot
    AURIX Configuration Studio installation directory.

.EXAMPLE
    .\tools\build_flash.ps1                          # build both, then flash both
    .\tools\build_flash.ps1 -Action build            # build only
    .\tools\build_flash.ps1 -Action flash            # flash the existing images
    .\tools\build_flash.ps1 -Action clean            # clean both build outputs
    .\tools\build_flash.ps1 -Target tricore          # TriCore only (APP_INFER_TRICORE)
#>
[CmdletBinding(SupportsShouldProcess = $true)]
param(
    [ValidateSet('build', 'flash', 'all', 'clean')]
    [string]$Action = 'all',
    [ValidateSet('tricore', 'ppu', 'both')]
    [string]$Target = 'both',
    [int]$DasId = 0,
    [string]$AcsRoot = 'C:\Infineon\AURIX-Configuration-Studio-1.0.22'
)

$ErrorActionPreference = 'Stop'

# --- Resolve tool locations -------------------------------------------------- #
$eclipse = Join-Path $AcsRoot 'eclipse'
$make    = Join-Path $eclipse 'tools\make.exe'
$gccBin  = Join-Path $eclipse 'tricore-gcc11\bin'
$arcBin  = Join-Path $eclipse 'arc-llvm\bin'

$flasher =
    Get-ChildItem (Join-Path $eclipse 'plugins\com.ifx.ads2.flash_*\AurixFlasherSoftwareTool_*\AURIXFlasher.exe') -ErrorAction SilentlyContinue |
    Sort-Object FullName -Descending | Select-Object -First 1 -ExpandProperty FullName

foreach ($p in @($make, $gccBin, $arcBin)) {
    if (-not (Test-Path $p)) { throw "Tool not found: $p  (check -AcsRoot)" }
}
if (-not $flasher) { throw "AURIXFlasher.exe not found under $eclipse\plugins (check -AcsRoot)" }

# --- Resolve project / build directories ------------------------------------- #
$root     = Split-Path -Parent $PSScriptRoot        # workspace folder (parent of tools\)
$tcBuild  = Join-Path $root './Debug'
$ppuBuild = Join-Path $root '../illd_tc4d7_acs_deepcraft_ml_profiler_PPU/Debug'
$tcImage  = Join-Path $tcBuild  'illd_tc4d7_acs_deepcraft_ml_profiler_TC4.hex'
$ppuImage = Join-Path $ppuBuild 'illd_tc4d7_acs_deepcraft_ml_profiler_PPU.elf'

foreach ($p in @($tcBuild, $ppuBuild)) {
    if (-not (Test-Path $p)) { throw "Build directory not found: $p  (build once in ACS first)" }
}

# Both toolchains on PATH: the makefiles call the compilers by bare name.
$env:PATH = "$gccBin;$arcBin;$eclipse\tools;$env:PATH"

$wantTricore = $Target -in 'tricore', 'both'
$wantPpu     = $Target -in 'ppu', 'both'

# --- PPU compiler flags that ACS cannot store ------------------------------- #
# The ARC toolchain in ACS 1.0.22 exposes only 'includefolders' and
# 'optimizationlevel' as .cproject options - there is no defines, misc-flags or
# debug-format field. These flags therefore have nowhere durable to live, and the
# generated response file that carries them is rewritten whenever ACS regenerates
# the build. Re-assert them here so a command-line build is always correct.
#
#   ONNX2C_MEMMAP : places the model weights in CSM. Without it they stay in
#                   program flash: correct results, ~50x slower, which surfaces
#                   as PPU dispatch timeouts. Ppu_Main.c also #errors on this.
#   IMAI_PROFILING: per-region cycle counts.
#   -gdwarf-4     : clang defaults to DWARF 5, which the Eclipse/CDT DwarfReader
#                   in ACS cannot parse (NullPointerException in
#                   addSourceFilesDwarf5). Keep the PPU ELF readable by the IDE.
function Assert-PpuFlags {
    $opt = Join-Path $ppuBuild 'ARC_C_C___Compiler-Include_Directories.opt'
    if (-not (Test-Path $opt)) { Write-Warning "PPU response file not found: $opt"; return }
    $t = (Get-Content $opt -Raw).TrimEnd()
    $added = @()
    foreach ($flag in '-DONNX2C_MEMMAP', '-DIMAI_PROFILING', '-gdwarf-4') {
        if ($t -notmatch [regex]::Escape($flag)) { $t += " $flag"; $added += $flag }
    }
    if ($added.Count) {
        Set-Content $opt $t -NoNewline -Encoding ascii
        Write-Host "==> [PPU] restored flags ACS dropped: $($added -join ' ')" -ForegroundColor Yellow
    }
}

function Invoke-Make([string]$dir, [string]$label, [string]$mkTarget) {
    $jobs = [Environment]::ProcessorCount
    Write-Host "==> [$label] make $mkTarget (-j$jobs)" -ForegroundColor Cyan
    Push-Location $dir
    try {
        & $make --output-sync "-j$jobs" $mkTarget
        if ($LASTEXITCODE -ne 0) { throw "[$label] make $mkTarget failed (exit $LASTEXITCODE)" }
    }
    finally { Pop-Location }
}

# Program one image WITHOUT starting the core, so several images can be written
# before a single reset. '-erase on' erases only the sectors the image occupies,
# so the TriCore and PPU images (distinct flash regions) do not erase each other.
function Invoke-FlashImage([string]$path) {
    if (-not (Test-Path $path)) { throw "Image not found: $path`nBuild first." }
    $kind = if ([IO.Path]::GetExtension($path) -eq '.elf') { '-elf' } else { '-hex' }
    $f = Get-Item $path
    Write-Host ("==> Programming {0} ({1:N0} B, built {2}) on DAS id {3}" -f $f.Name, $f.Length, $f.LastWriteTime, $DasId) -ForegroundColor Cyan
    if (-not $PSCmdlet.ShouldProcess($path, 'program')) {
        Write-Host "    would run: $kind `"$path`" -id $DasId -erase on -prog on -start off"
        return
    }
    & $flasher $kind $path -id "$DasId" -erase on -prog on -start off
    if ($LASTEXITCODE -ne 0) { throw "Flashing failed for $path (exit $LASTEXITCODE)" }
}

# The flasher's '-start on' can leave a TC4x core halted, so reset explicitly.
function Reset-Device {
    if (-not $PSCmdlet.ShouldProcess('device', 'reset')) { Write-Host '    would run: INIT / RESET 2'; return }
    $script = Join-Path ([IO.Path]::GetTempPath()) 'aurix_reset.txt'
    "INIT`r`nRESET 2" | Set-Content -Encoding ascii $script
    try   { & $flasher -id "$DasId" -script $script | Out-Null }
    finally { Remove-Item $script -ErrorAction SilentlyContinue }
}

function Invoke-Build {
    if ($wantTricore) { Invoke-Make $tcBuild  'TriCore' 'all' }
    if ($wantPpu)     { Assert-PpuFlags; Invoke-Make $ppuBuild 'PPU' 'all' }
}

function Invoke-Clean {
    if ($wantTricore) { Invoke-Make $tcBuild  'TriCore' 'clean' }
    if ($wantPpu)     { Invoke-Make $ppuBuild 'PPU'     'clean' }
}

function Invoke-Flash {
    # A shared-IPC change flashed on only one core fails as garbage data, not an
    # error, so make a stale pairing loud.
    if ($Target -eq 'both' -and (Test-Path $tcImage) -and (Test-Path $ppuImage)) {
        $skew = [math]::Abs(((Get-Item $tcImage).LastWriteTime - (Get-Item $ppuImage).LastWriteTime).TotalMinutes)
        if ($skew -gt 30) {
            Write-Warning ("TriCore and PPU images were built {0:N0} minutes apart. If ppu_ipc.h or the APP_MODEL_MAX_* tunables changed in between, rebuild BOTH first." -f $skew)
        }
    }
    if ($wantTricore) { Invoke-FlashImage $tcImage }
    if ($wantPpu)     { Invoke-FlashImage $ppuImage }
    Reset-Device
    Write-Host "Flash complete ($Target); device reset and running." -ForegroundColor Green
}

Write-Host "Flasher: $flasher" -ForegroundColor DarkGray

switch ($Action) {
    'clean' { Invoke-Clean }
    'build' { Invoke-Build }
    'flash' { Invoke-Flash }
    'all'   { Invoke-Build; Invoke-Flash }
}
