#pragma once
#include <string>

class User {
private:
    std::string name;
    double weight; // кг
    double height; // см
    std::string goal; // "отслабване", "мускулна маса", "издръжливост"

public:
    User(const std::string& name, double weight, double height, const std::string& goal);

    double getBMI() const;
    std::string getProfile() const;

    std::string getName() const;
    double getWeight() const;
    std::string getGoal() const;

    void setWeight(double w);
    void setGoal(const std::string& g);
};
