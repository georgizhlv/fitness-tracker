#pragma once
#include <string>

class WorkoutGoal {
private:
    int targetSessions;
    int targetMinutes;
    double targetCalories; // 0 = не се следи
    std::string period; // "седмица", "месец"

public:
    WorkoutGoal(int targetSessions, int targetMinutes,
                const std::string& period = "седмица", double targetCalories = 0);

    bool isAchieved(int sessions, int minutes, double calories = 0) const;
    std::string getProgress(int sessions, int minutes, double calories = 0) const;

    int getTargetSessions() const;
    int getTargetMinutes() const;
    double getTargetCalories() const;
};
