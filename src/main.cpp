#include <iostream>
#include "FitnessTracker.h"
#include "CardioWorkout.h"
#include "StrengthWorkout.h"
#include "YogaWorkout.h"
#include "User.h"
#include "WorkoutGoal.h"

int main() {
    // Функционалност 4: потребителски профил
    User user("Иван", 80.0, 178.0, "отслабване");
    std::cout << user.getProfile() << "\n\n";

    // Цел: 3 тренировки и поне 120 минути
    WorkoutGoal goal(3, 120);
    FitnessTracker tracker(user, goal);

    std::cout << "=== Добавяне на тренировки ===\n";

    // Функционалност 1: добавяне на тренировки (полиморфизъм в действие)
    tracker.addWorkout(new CardioWorkout("2025-05-01", 45, 135));
    tracker.addWorkout(new StrengthWorkout("2025-05-03", 60, 4, 12, "крака"));
    tracker.addWorkout(new YogaWorkout("2025-05-05", 30, "Hatha", "сутрин"));
    tracker.addWorkout(new CardioWorkout("2025-05-07", 50, 150, "интервали"));

    // Функционалност 3: история
    tracker.printHistory();

    // Функционалност 5: статистика
    tracker.printStats();

    // Функционалност 6 + 7: прогрес и известяване
    tracker.printGoalProgress();
    tracker.checkGoal();

    // Функционалност 8: филтриране
    tracker.filterByType("Кардио");
    tracker.filterByType("Йога");

    return 0;
}
