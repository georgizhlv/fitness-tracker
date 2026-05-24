#include "User.h"
#include <sstream>
#include <iomanip>

User::User(const std::string& name, double weight, double height, const std::string& goal)
    : name(name), weight(weight), height(height), goal(goal) {}

double User::getBMI() const {
    double hm = height / 100.0;
    return weight / (hm * hm);
}

std::string User::getBMICategory() const {
    double bmi = getBMI();
    if (bmi < 18.5) return "Поднормено тегло";
    if (bmi < 25.0) return "Нормално тегло";
    if (bmi < 30.0) return "Наднормено тегло";
    return "Затлъстяване";
}

std::string User::getProfile() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Потребител: " << name << "\n"
        << "  Тегло: " << weight << " кг\n"
        << "  Ръст:  " << height << " см\n"
        << "  BMI:   " << getBMI() << " (" << getBMICategory() << ")\n"
        << "  Цел:   " << goal;
    return oss.str();
}

std::string User::getName() const { return name; }
double User::getWeight() const { return weight; }
std::string User::getGoal() const { return goal; }
void User::setWeight(double w) { weight = w; }
void User::setGoal(const std::string& g) { goal = g; }
