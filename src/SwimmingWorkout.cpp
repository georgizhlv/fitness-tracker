#include "SwimmingWorkout.h"
#include <sstream>

// Плуването изгаря ~7 кал/мин; с повече дължини интензивността расте
SwimmingWorkout::SwimmingWorkout(const std::string& date, int durationMin,
                                 int laps, const std::string& notes)
    : Workout(date, durationMin, notes), laps(laps) {}

std::string SwimmingWorkout::getType() const {
    return "Плуване";
}

double SwimmingWorkout::calcCalories() const {
    double base = durationMin * 7.0;
    if (laps > 20) base *= 1.15;
    return base;
}

std::string SwimmingWorkout::getSummary() const {
    std::ostringstream oss;
    oss << Workout::getSummary()
        << " | Дължини: " << laps;
    return oss.str();
}

int SwimmingWorkout::getLaps() const { return laps; }
