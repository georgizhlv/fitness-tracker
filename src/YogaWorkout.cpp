#include "YogaWorkout.h"
#include <sstream>

// Формула: йога изгаря ~3 кал/мин (по-малко от кардио)
YogaWorkout::YogaWorkout(const std::string& date, int durationMin,
                         const std::string& style, const std::string& notes)
    : Workout(date, durationMin, notes), style(style) {}

std::string YogaWorkout::getType() const {
    return "Йога";
}

double YogaWorkout::calcCalories() const {
    return durationMin * 3.0;
}

std::string YogaWorkout::getSummary() const {
    std::ostringstream oss;
    oss << Workout::getSummary()
        << " | Стил: " << style;
    return oss.str();
}
