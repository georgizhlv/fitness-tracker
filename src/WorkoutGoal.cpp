#include "WorkoutGoal.h"
#include <sstream>
#include <iomanip>

WorkoutGoal::WorkoutGoal(int targetSessions, int targetMinutes,
                         const std::string& period, double targetCalories)
    : targetSessions(targetSessions), targetMinutes(targetMinutes),
      targetCalories(targetCalories), period(period) {}

bool WorkoutGoal::isAchieved(int sessions, int minutes, double calories) const {
    bool ok = sessions >= targetSessions && minutes >= targetMinutes;
    if (targetCalories > 0) ok = ok && (calories >= targetCalories);
    return ok;
}

std::string WorkoutGoal::getProgress(int sessions, int minutes, double calories) const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(0);
    oss << "Цел (" << period << "): "
        << sessions << "/" << targetSessions << " тренировки, "
        << minutes << "/" << targetMinutes << " мин";
    if (targetCalories > 0)
        oss << ", " << calories << "/" << targetCalories << " ккал";
    if (isAchieved(sessions, minutes, calories))
        oss << "  *** ЦЕЛ ПОСТИГНАТА! ***";
    return oss.str();
}

int WorkoutGoal::getTargetSessions() const { return targetSessions; }
int WorkoutGoal::getTargetMinutes() const { return targetMinutes; }
double WorkoutGoal::getTargetCalories() const { return targetCalories; }
