#include "WorkoutGoal.h"
#include <sstream>

WorkoutGoal::WorkoutGoal(int targetSessions, int targetMinutes, const std::string& period)
    : targetSessions(targetSessions), targetMinutes(targetMinutes), period(period) {}

bool WorkoutGoal::isAchieved(int sessions, int minutes) const {
    return sessions >= targetSessions && minutes >= targetMinutes;
}

std::string WorkoutGoal::getProgress(int sessions, int minutes) const {
    std::ostringstream oss;
    oss << "Цел (" << period << "): "
        << sessions << "/" << targetSessions << " тренировки, "
        << minutes << "/" << targetMinutes << " мин";
    if (isAchieved(sessions, minutes))
        oss << "  *** ЦЕЛ ПОСТИГНАТА! ***";
    return oss.str();
}

int WorkoutGoal::getTargetSessions() const { return targetSessions; }
int WorkoutGoal::getTargetMinutes() const { return targetMinutes; }
