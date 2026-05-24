#pragma once
#include "Workout.h"

class SwimmingWorkout : public Workout {
private:
    int laps; // брой дължини

public:
    SwimmingWorkout(const std::string& date, int durationMin,
                    int laps, const std::string& notes = "");

    std::string getType() const override;
    double calcCalories() const override;
    std::string getSummary() const override;

    int getLaps() const;
};
