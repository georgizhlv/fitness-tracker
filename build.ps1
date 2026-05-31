# PowerShell build script for fitness_tracker (Windows)
param(
    [switch]$Clean,
    [switch]$Run
)

# Set UTF-8 encoding for proper Cyrillic output
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
$PSDefaultParameterValues['Out-File:Encoding'] = 'utf8'

$Compiler = "g++"
$Standard = "-std=c++17"
$Flags    = "-Wall -Iinclude"
$Target   = "fitness_tracker.exe"
$Sources  = @(
    "src\main.cpp",
    "src\Workout.cpp",
    "src\CardioWorkout.cpp",
    "src\StrengthWorkout.cpp",
    "src\YogaWorkout.cpp",
    "src\SwimmingWorkout.cpp",
    "src\User.cpp",
    "src\WorkoutGoal.cpp",
    "src\FitnessTracker.cpp"
)

if ($Clean) {
    if (Test-Path $Target) { Remove-Item $Target; Write-Host "Cleaned: $Target" }
    exit 0
}

$cmd = "$Compiler $Standard $Flags $($Sources -join ' ') -o $Target"
Write-Host "Building..." -ForegroundColor Cyan
Write-Host $cmd
Invoke-Expression $cmd

if ($LASTEXITCODE -eq 0) {
    Write-Host "Success: $Target" -ForegroundColor Green
    if ($Run) { 
        chcp 65001 > $null
        & ".\$Target" 
    }
} else {
    Write-Host "Compilation error." -ForegroundColor Red
    exit 1
}
