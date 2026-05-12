#pragma once
#include "Workout.h"

class CardioWorkout : public Workout {
private:
    int avgHeartRate;

public:
    CardioWorkout(const std::string& date, int durationMin,
                  int avgHeartRate, const std::string& notes = "");

    std::string getType() const override;
    double calcCalories() const override;
    std::string getSummary() const override;
};
