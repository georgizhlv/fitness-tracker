#pragma once
#include "Workout.h"

class StrengthWorkout : public Workout {
private:
    int sets;
    int reps;

public:
    StrengthWorkout(const std::string& date, int durationMin,
                    int sets, int reps, const std::string& notes = "");

    std::string getType() const override;
    double calcCalories() const override;
    std::string getSummary() const override;
};
