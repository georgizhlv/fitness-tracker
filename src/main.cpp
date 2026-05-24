#include <iostream>
#include "FitnessTracker.h"
#include "CardioWorkout.h"
#include "StrengthWorkout.h"
#include "YogaWorkout.h"
#include "SwimmingWorkout.h"
#include "User.h"
#include "WorkoutGoal.h"

int main() {
    // Функционалност 4: потребителски профил с BMI категория
    User user("Иван", 80.0, 178.0, "отслабване");
    std::cout << user.getProfile() << "\n\n";

    // Цел: 4 тренировки и поне 150 минути за седмица
    WorkoutGoal goal(4, 150);
    FitnessTracker tracker(user, goal);

    std::cout << "=== Добавяне на тренировки ===\n";

    // Функционалност 1: добавяне на тренировки (полиморфизъм)
    tracker.addWorkout(new CardioWorkout("2025-05-07", 50, 150, "интервали"));
    tracker.addWorkout(new StrengthWorkout("2025-05-03", 60, 4, 12, "крака"));
    tracker.addWorkout(new YogaWorkout("2025-05-05", 30, "Hatha", "сутрин"));
    tracker.addWorkout(new CardioWorkout("2025-05-01", 45, 135));
    // Функционалност 2: нов тип тренировка — плуване
    tracker.addWorkout(new SwimmingWorkout("2025-05-09", 40, 25, "бруст"));

    // Функционалност 10: сортиране по дата
    std::cout << "\n";
    tracker.sortByDate();

    // Функционалност 3: история на тренировките
    tracker.printHistory();

    // Функционалност 5: статистика (общо)
    tracker.printStats();

    // Функционалност 11: средни показатели
    tracker.printAverageStats();

    // Функционалности 6 и 7: прогрес и известяване при постигната цел
    tracker.printGoalProgress();
    tracker.checkGoal();

    // Функционалност 8: филтриране по вид
    tracker.filterByType("Кардио");
    tracker.filterByType("Плуване");

    // Функционалност 12: запазване във файл
    std::cout << "\n";
    tracker.saveToFile("workout_history.txt");

    // Функционалност 9: изтриване на тренировка
    std::cout << "\n";
    tracker.deleteWorkout(1);
    tracker.printHistory();

    // Зареждане от файл (демо)
    FitnessTracker tracker2(user, goal);
    tracker2.loadFromFile("workout_history.txt");
    tracker2.printStats();

    return 0;
}
