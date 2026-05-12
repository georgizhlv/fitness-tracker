#include "FitnessTracker.h"
#include <iostream>
#include <iomanip>

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
