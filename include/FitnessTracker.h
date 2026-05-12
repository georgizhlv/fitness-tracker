#pragma once
#include <vector>
#include <string>
#include "Workout.h"
#include "User.h"
#include "WorkoutGoal.h"

class FitnessTracker {
private:
    User user;
    std::vector<Workout*> history;
    WorkoutGoal goal;

public:
    FitnessTracker(const User& user, const WorkoutGoal& goal);
    ~FitnessTracker();

    void addWorkout(Workout* w);
    void printHistory() const;
    void printStats() const;
    void filterByType(const std::string& type) const;
    void checkGoal() const;
    void printGoalProgress() const;
};
