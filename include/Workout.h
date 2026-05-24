#pragma once
#include <string>

class Workout {
protected:
    std::string date;
    int durationMin;
    std::string notes;

public:
    Workout(const std::string& date, int durationMin, const std::string& notes);
    virtual ~Workout() = default;

    // Pure virtual — всеки наследник задължително ги имплементира
    virtual std::string getType() const = 0;
    virtual double calcCalories() const = 0;

    virtual std::string getSummary() const;

    std::string getDate() const;
    int getDuration() const;
    std::string getNotes() const;
    void setNotes(const std::string& n);
};
