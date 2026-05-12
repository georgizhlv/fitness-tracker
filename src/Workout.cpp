#include "Workout.h"
#include <sstream>

Workout::Workout(const std::string& date, int durationMin, const std::string& notes)
    : date(date), durationMin(durationMin), notes(notes) {}

std::string Workout::getSummary() const {
    std::ostringstream oss;
    oss << "[" << getType() << "] " << date
        << " | " << durationMin << " мин"
        << " | ~" << static_cast<int>(calcCalories()) << " кал";
    if (!notes.empty())
        oss << " | Бележки: " << notes;
    return oss.str();
}

std::string Workout::getDate() const { return date; }
int Workout::getDuration() const { return durationMin; }
std::string Workout::getNotes() const { return notes; }
