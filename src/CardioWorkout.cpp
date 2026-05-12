#include "CardioWorkout.h"
#include <sstream>

// Формула: кардио изгаря ~8 кал/мин при средна интензивност
// Коригираме по сърдечен ритъм: над 140 уд/мин -> x1.2
CardioWorkout::CardioWorkout(const std::string& date, int durationMin,
                             int avgHeartRate, const std::string& notes)
    : Workout(date, durationMin, notes), avgHeartRate(avgHeartRate) {}

std::string CardioWorkout::getType() const {
    return "Кардио";
}

double CardioWorkout::calcCalories() const {
    double base = durationMin * 8.0;
    if (avgHeartRate > 140) base *= 1.2;
    return base;
}

std::string CardioWorkout::getSummary() const {
    std::ostringstream oss;
    oss << Workout::getSummary()
        << " | Пулс: " << avgHeartRate << " уд/мин";
    return oss.str();
}
