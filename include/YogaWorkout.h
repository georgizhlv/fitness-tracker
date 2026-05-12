#pragma once
#include "Workout.h"

class YogaWorkout : public Workout {
private:
    std::string style; // напр. "Hatha", "Vinyasa", "Yin"

public:
    YogaWorkout(const std::string& date, int durationMin,
                const std::string& style, const std::string& notes = "");

    std::string getType() const override;
    double calcCalories() const override;
    std::string getSummary() const override;
};
