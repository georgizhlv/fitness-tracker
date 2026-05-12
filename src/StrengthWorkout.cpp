#include "StrengthWorkout.h"
#include <sstream>

// Формула: силовата тренировка изгаря ~5 кал/мин базово
// Повече серии/повторения добавят ~0.1 кал на серия*повторение
StrengthWorkout::StrengthWorkout(const std::string& date, int durationMin,
                                 int sets, int reps, const std::string& notes)
    : Workout(date, durationMin, notes), sets(sets), reps(reps) {}

std::string StrengthWorkout::getType() const {
    return "Силова";
}

double StrengthWorkout::calcCalories() const {
    return durationMin * 5.0 + sets * reps * 0.1;
}

std::string StrengthWorkout::getSummary() const {
    std::ostringstream oss;
    oss << Workout::getSummary()
        << " | " << sets << " серии x " << reps << " повт.";
    return oss.str();
}
