param(
    [int]$Baud = 115200,
    [int]$Seconds = 20,
    [string]$Com = 'COM13',
    [switch]$NoReset
)
# The Infineon DAS "JDS COM" (COM13) shares the DAS interface with the flasher's
# dasHost. They cannot both hold the port, so the sequence is:
#   1. reset the board via the flasher (spawns dasHost),
#   2. kill dasHost to release the COM,
#   3. open the port fast and read (DHCP/boot output arrives over the next secs).
# Use the flasher bundled with AURIX Configuration Studio.
$flasher =
    Get-ChildItem 'C:\Infineon\AURIX-Configuration-Studio-*\eclipse\plugins\com.ifx.ads2.flash_*\AurixFlasherSoftwareTool_*\AURIXFlasher.exe' -ErrorAction SilentlyContinue |
    Sort-Object FullName -Descending | Select-Object -First 1 -ExpandProperty FullName
if (-not $flasher) { throw 'AURIXFlasher.exe not found under C:\Infineon\AURIX-Configuration-Studio-*' }

if (-not $NoReset) {
    $rs = Join-Path $env:TEMP 'aurix_reset.txt'
    "INIT`r`nRESET 2" | Set-Content -Encoding ascii $rs
    & $flasher -id 0 -script $rs | Out-Null
    Remove-Item $rs -ErrorAction SilentlyContinue
    Get-Process dasHost -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
}

# Open with a few retries in case the DAS release lags slightly.
$port = New-Object System.IO.Ports.SerialPort($Com, $Baud, 'None', 8, 'One')
$port.ReadTimeout = 1000
$opened = $false
for ($i = 0; $i -lt 20 -and -not $opened; $i++) {
    try { $port.Open(); $opened = $true } catch { Start-Sleep -Milliseconds 100 }
}
if (-not $opened) { Write-Output '!! could not open port'; return }
$port.DiscardInBuffer()

$sw = [System.Diagnostics.Stopwatch]::StartNew()
$ip = $null
while ($sw.Elapsed.TotalSeconds -lt $Seconds) {
    try {
        $line = $port.ReadLine()
        Write-Output $line
        if ($line -match '(\d{1,3}\.){3}\d{1,3}') { $ip = $Matches[0] }
    } catch [TimeoutException] { }
    catch { Write-Output "!! read error: $($_.Exception.Message)"; break }
}
$port.Close(); $port.Dispose()
Write-Output "==== DETECTED IP: $ip ===="
