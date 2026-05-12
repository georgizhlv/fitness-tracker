#pragma once
#include <string>

class WorkoutGoal {
private:
    int targetSessions;
    int targetMinutes;
    std::string period; // "седмица", "месец"

public:
    WorkoutGoal(int targetSessions, int targetMinutes, const std::string& period = "седмица");

    bool isAchieved(int sessions, int minutes) const;
    std::string getProgress(int sessions, int minutes) const;

    int getTargetSessions() const;
    int getTargetMinutes() const;
};
