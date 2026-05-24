#include "FitnessTracker.h"
#include "CardioWorkout.h"
#include "StrengthWorkout.h"
#include "YogaWorkout.h"
#include "SwimmingWorkout.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>

FitnessTracker::FitnessTracker(const User& user, const WorkoutGoal& goal)
    : user(user), goal(goal) {}

FitnessTracker::~FitnessTracker() {
    for (Workout* w : history)
        delete w;
}

void FitnessTracker::addWorkout(Workout* w) {
    history.push_back(w);
    std::cout << "Тренировката е добавена: " << w->getSummary() << "\n";
}

// Функционалност 9: изтриване на тренировка по индекс
void FitnessTracker::deleteWorkout(int index) {
    if (index < 1 || index > (int)history.size()) {
        std::cout << "Невалиден индекс: " << index << "\n";
        return;
    }
    auto it = history.begin() + (index - 1);
    std::cout << "Изтрита тренировка: " << (*it)->getSummary() << "\n";
    delete *it;
    history.erase(it);
}

// Функционалност 10: сортиране по дата
void FitnessTracker::sortByDate() {
    std::sort(history.begin(), history.end(), [](Workout* a, Workout* b) {
        return a->getDate() < b->getDate();
    });
    std::cout << "Историята е наредена по дата.\n";
}

// Функционалност 3: история на тренировките
void FitnessTracker::printHistory() const {
    if (history.empty()) {
        std::cout << "Няма записани тренировки.\n";
        return;
    }
    std::cout << "\n=== История на тренировките ===\n";
    for (int i = 0; i < (int)history.size(); i++) {
        std::cout << i + 1 << ". " << history[i]->getSummary() << "\n";
    }
    std::cout << "================================\n";
}

// Функционалност 5: статистика
void FitnessTracker::printStats() const {
    int totalMin = 0;
    double totalCal = 0;
    for (Workout* w : history) {
        totalMin += w->getDuration();
        totalCal += w->calcCalories();
    }
    std::cout << "\n=== Статистика ===\n";
    std::cout << "Общо тренировки: " << history.size() << "\n";
    std::cout << "Общо минути:     " << totalMin << "\n";
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Общо калории:    " << totalCal << "\n";
    std::cout << "==================\n";
}

// Функционалност 8: филтриране по вид
void FitnessTracker::filterByType(const std::string& type) const {
    std::cout << "\n=== Тренировки от тип \"" << type << "\" ===\n";
    bool found = false;
    for (Workout* w : history) {
        if (w->getType() == type) {
            std::cout << "  " << w->getSummary() << "\n";
            found = true;
        }
    }
    if (!found)
        std::cout << "  Няма тренировки от този тип.\n";
    std::cout << "======================================\n";
}

// Функционалност 13: разбивка на калории по вид тренировка
void FitnessTracker::printCalorieBreakdown() const {
    std::map<std::string, double> byType;
    for (Workout* w : history)
        byType[w->getType()] += w->calcCalories();
    std::cout << "\n=== Калории по вид тренировка ===\n";
    std::cout << std::fixed << std::setprecision(0);
    for (auto& kv : byType)
        std::cout << "  " << kv.first << ": " << kv.second << " ккал\n";
    std::cout << "=================================\n";
}

// Функционалност 7: известяване при постигната цел
void FitnessTracker::checkGoal() const {
    int sessions = (int)history.size();
    int totalMin = 0;
    for (Workout* w : history)
        totalMin += w->getDuration();

    if (goal.isAchieved(sessions, totalMin)) {
        std::cout << "\n*** ПОЗДРАВЛЕНИЯ! Целта е постигната! ***\n";
    }
}

// Функционалност 6: прогрес към цел
void FitnessTracker::printGoalProgress() const {
    int sessions = (int)history.size();
    int totalMin = 0;
    for (Workout* w : history)
        totalMin += w->getDuration();

    std::cout << "\n" << goal.getProgress(sessions, totalMin) << "\n";
}

// Функционалност 11: средни показатели
void FitnessTracker::printAverageStats() const {
    if (history.empty()) {
        std::cout << "Няма данни за средни показатели.\n";
        return;
    }
    int totalMin = 0;
    double totalCal = 0;
    for (Workout* w : history) {
        totalMin += w->getDuration();
        totalCal += w->calcCalories();
    }
    int n = (int)history.size();
    std::cout << "\n=== Средни показатели ===\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Средна продължителност: " << (double)totalMin / n << " мин\n";
    std::cout << "Средни калории/тренировка: " << totalCal / n << " ккал\n";
    std::cout << "=========================\n";
}

// Функционалност 12: запазване във файл
void FitnessTracker::saveToFile(const std::string& filename) const {
    std::ofstream f(filename);
    if (!f) {
        std::cout << "Грешка при отваряне на файл: " << filename << "\n";
        return;
    }
    for (Workout* w : history)
        f << w->getType() << "|" << w->getDate() << "|" << w->getDuration()
          << "|" << w->getNotes() << "\n";
    std::cout << "Историята е запазена в " << filename << " (" << history.size() << " записа)\n";
}

// Функционалност 12: зареждане от файл (прост формат)
void FitnessTracker::loadFromFile(const std::string& filename) {
    std::ifstream f(filename);
    if (!f) {
        std::cout << "Файлът не е намерен: " << filename << "\n";
        return;
    }
    std::string line;
    int count = 0;
    while (std::getline(f, line)) {
        std::istringstream ss(line);
        std::string type, date, durStr, notes;
        if (!std::getline(ss, type, '|')) continue;
        if (!std::getline(ss, date, '|')) continue;
        if (!std::getline(ss, durStr, '|')) continue;
        std::getline(ss, notes);
        int dur = std::stoi(durStr);
        Workout* w = nullptr;
        if (type == "Кардио")    w = new CardioWorkout(date, dur, 0, notes);
        else if (type == "Сила") w = new StrengthWorkout(date, dur, 0, 0, notes);
        else if (type == "Йога") w = new YogaWorkout(date, dur, "Hatha", notes);
        else if (type == "Плуване") w = new SwimmingWorkout(date, dur, 0, notes);
        if (w) { history.push_back(w); count++; }
    }
    std::cout << "Заредени " << count << " тренировки от " << filename << "\n";
}
