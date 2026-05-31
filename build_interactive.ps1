# PowerShell build script with interactive mode
param(
    [switch]$Interactive,
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
$InteractiveTarget = "fitness_tracker_interactive.exe"

$BaseSources = @(
    "src\Workout.cpp",
    "src\CardioWorkout.cpp",
    "src\StrengthWorkout.cpp",
    "src\YogaWorkout.cpp",
    "src\SwimmingWorkout.cpp",
    "src\User.cpp",
    "src\WorkoutGoal.cpp",
    "src\FitnessTracker.cpp"
)

$MainSources = @("src\main.cpp") + $BaseSources
$InteractiveSources = @("src\interactive_demo.cpp") + $BaseSources

if ($Clean) {
    if (Test-Path $Target) { Remove-Item $Target; Write-Host "Cleaned: $Target" }
    if (Test-Path $InteractiveTarget) { Remove-Item $InteractiveTarget; Write-Host "Cleaned: $InteractiveTarget" }
    exit 0
}

function BuildTarget($targetName, $sources) {
    $cmd = "$Compiler $Standard $Flags $($sources -join ' ') -o $targetName"
    Write-Host "Building $targetName..." -ForegroundColor Cyan
    Invoke-Expression $cmd
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "Success: $targetName" -ForegroundColor Green
        return $true
    } else {
        Write-Host "Compilation error." -ForegroundColor Red
        return $false
    }
}

if ($Interactive) {
    if (BuildTarget $InteractiveTarget $InteractiveSources) {
        Write-Host "Запуск на интерактивна демонстрация..." -ForegroundColor Yellow
        chcp 65001 > $null
        & ".\$InteractiveTarget"
    }
} else {
    if (BuildTarget $Target $MainSources) {
        if ($Run) { 
            chcp 65001 > $null
            & ".\$Target" 
        }
    }
}
