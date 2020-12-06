# Powershell Script to compile, test, and upload the CmVM for Windows 64-bit and AVR 8-bit platforms

param (
    [System.IO.FileInfo]$VmAdmin, 
    [switch]$ForAVR, 
    [switch]$ForWindows
)

$ErrorActionPreference = "Stop";

Write-Host

if ($ForAVR) {
    Write-Host "Building $($VmAdmin.BaseName) for ATmega328p..."
}
if ($ForWindows) {
    Write-Host "Building $($VmAdmin.BaseName) for Windows..."
}


