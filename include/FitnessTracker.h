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
    void deleteWorkout(int index);
    void sortByDate();
    void printHistory() const;
    void printStats() const;
    void printAverageStats() const;
    void filterByType(const std::string& type) const;
    void printCalorieBreakdown() const;
    void checkGoal() const;
    void printGoalProgress() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
