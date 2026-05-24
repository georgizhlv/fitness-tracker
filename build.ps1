# PowerShell build script for fitness_tracker (Windows)
param(
    [switch]$Clean,
    [switch]$Run
)

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
    if (Test-Path $Target) { Remove-Item $Target; Write-Host "Изчистено: $Target" }
    exit 0
}

$cmd = "$Compiler $Standard $Flags $($Sources -join ' ') -o $Target"
Write-Host "Компилиране..." -ForegroundColor Cyan
Write-Host $cmd
Invoke-Expression $cmd

if ($LASTEXITCODE -eq 0) {
    Write-Host "Успешно: $Target" -ForegroundColor Green
    if ($Run) { & ".\$Target" }
} else {
    Write-Host "Грешка при компилиране." -ForegroundColor Red
    exit 1
}
