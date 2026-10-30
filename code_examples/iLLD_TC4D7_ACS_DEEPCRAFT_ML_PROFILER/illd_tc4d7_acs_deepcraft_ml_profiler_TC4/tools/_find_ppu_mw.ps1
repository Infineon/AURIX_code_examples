# Search for the Infineon TC4Dx PPU MetaWare components that the PPU app build needs.
$roots = @('C:\Aurix', 'C:\Infineon')
Write-Output '=== speed_aux.h / arc.tcf mentioning TC4D|PPU|speed ==='
foreach ($r in $roots) {
    Get-ChildItem $r -Recurse -Include 'speed_aux.h', 'arc.tcf' -ErrorAction SilentlyContinue |
        Where-Object { $_.FullName -match 'TC4D|PPU|speed' } |
        Select-Object -ExpandProperty FullName
}
Write-Output '=== tc4dx_system build config ==='
foreach ($r in $roots) {
    Get-ChildItem $r -Recurse -Directory -Filter 'tc4dx_system' -ErrorAction SilentlyContinue |
        Select-Object -ExpandProperty FullName
}
Write-Output '=== any speed_aux.h anywhere under those roots ==='
foreach ($r in $roots) {
    Get-ChildItem $r -Recurse -Filter 'speed_aux.h' -ErrorAction SilentlyContinue |
        Select-Object -ExpandProperty FullName
}
Write-Output '=== MW_PPU_components in workspace ==='
Get-ChildItem 'C:\Users\PetreaC\AURIX-v1.10.30-L-workspace' -Recurse -Directory -Filter 'MW_PPU_components' -ErrorAction SilentlyContinue |
    Select-Object -ExpandProperty FullName
Write-Output 'DONE'
