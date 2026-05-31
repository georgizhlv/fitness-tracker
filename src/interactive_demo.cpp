#include <iostream>
#include <string>
#include <cctype>
#include "FitnessTracker.h"
#include "CardioWorkout.h"
#include "StrengthWorkout.h"
#include "YogaWorkout.h"
#include "SwimmingWorkout.h"
#include "User.h"
#include "WorkoutGoal.h"

void displayMenu() {
    std::cout << "\n========== ФИТНЕС ТРАКЕР - ИНТЕРАКТИВНА ДЕМОНСТРАЦИЯ ==========\n";
    std::cout << "1. Добавяне на тренировка (Кардио)\n";
    std::cout << "2. Добавяне на тренировка (Силова)\n";
    std::cout << "3. Добавяне на тренировка (Йога)\n";
    std::cout << "4. Добавяне на тренировка (Плуване)\n";
    std::cout << "5. Преглед на история на тренировките\n";
    std::cout << "6. Преглед на статистика\n";
    std::cout << "7. Преглед на потребителския профил\n";
    std::cout << "8. Филтриране по тип\n";
    std::cout << "9. Преглед на цел и прогрес\n";
    std::cout << "10. Средни показатели\n";
    std::cout << "11. Разпределение на калории\n";
    std::cout << "12. Сортиране по дата\n";
    std::cout << "13. Изтриване на последната тренировка\n";
    std::cout << "14. Запазване и прочит от файл\n";
    std::cout << "0. Изход\n";
    std::cout << "==============================================================\n";
    std::cout << "Изберете опция: ";
}

int main() {
    User user("Иван", 80.0, 178.0, "отслабване");
    WorkoutGoal goal(4, 150, "седмица", 1000.0);
    FitnessTracker tracker(user, goal);

    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║          ДОБРЕ ДОШЛИ В ФИТНЕС ТРАКЕР v1.0               ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    std::cout << "\nПотребител: " << user.getName() << "\n";
    std::cout << "Потребителски данни:\n" << user.getProfile() << "\n";

    int choice = -1;
    while (choice != 0) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string date, intensity;
                int duration, heartRate;
                std::cout << "\n--- Добавяне на КАРДИО тренировка ---\n";
                std::cout << "Дата (YYYY-MM-DD): "; std::getline(std::cin, date);
                std::cout << "Продължителност (мин): "; std::cin >> duration;
                std::cout << "Пулс (уд/мин): "; std::cin >> heartRate;
                std::cin.ignore();
                std::cout << "Интензивност (интервали/лека/умерена): "; std::getline(std::cin, intensity);
                
                tracker.addWorkout(new CardioWorkout(date, duration, heartRate, intensity));
                std::cout << "✓ Тренировката е добавена успешно!\n";
                break;
            }
            case 2: {
                std::string date, muscleGroup;
                int duration, sets, reps;
                std::cout << "\n--- Добавяне на СИЛОВА тренировка ---\n";
                std::cout << "Дата (YYYY-MM-DD): "; std::getline(std::cin, date);
                std::cout << "Продължителност (мин): "; std::cin >> duration;
                std::cout << "Брой серии: "; std::cin >> sets;
                std::cout << "Повторения: "; std::cin >> reps;
                std::cin.ignore();
                std::cout << "Мускулна група (гръб/гръди/крака/рамене): "; std::getline(std::cin, muscleGroup);
                
                tracker.addWorkout(new StrengthWorkout(date, duration, sets, reps, muscleGroup));
                std::cout << "✓ Тренировката е добавена успешно!\n";
                break;
            }
            case 3: {
                std::string date, style, timeOfDay;
                int duration;
                std::cout << "\n--- Добавяне на ЙОГА тренировка ---\n";
                std::cout << "Дата (YYYY-MM-DD): "; std::getline(std::cin, date);
                std::cout << "Продължителност (мин): "; std::cin >> duration;
                std::cin.ignore();
                std::cout << "Стил (Hatha/Vinyasa/Yin): "; std::getline(std::cin, style);
                std::cout << "Време на ден (сутрин/вечер/полдне): "; std::getline(std::cin, timeOfDay);
                
                tracker.addWorkout(new YogaWorkout(date, duration, style, timeOfDay));
                std::cout << "✓ Тренировката е добавена успешно!\n";
                break;
            }
            case 4: {
                std::string date, style;
                int duration, laps;
                std::cout << "\n--- Добавяне на ПЛУВАНЕ тренировка ---\n";
                std::cout << "Дата (YYYY-MM-DD): "; std::getline(std::cin, date);
                std::cout << "Продължителност (мин): "; std::cin >> duration;
                std::cout << "Дължини: "; std::cin >> laps;
                std::cin.ignore();
                std::cout << "Стил (бруст/гръб/пеперуда/вольна): "; std::getline(std::cin, style);
                
                tracker.addWorkout(new SwimmingWorkout(date, duration, laps, style));
                std::cout << "✓ Тренировката е добавена успешно!\n";
                break;
            }
            case 5:
                std::cout << "\n";
                tracker.printHistory();
                break;
            case 6:
                std::cout << "\n";
                tracker.printStats();
                break;
            case 7:
                std::cout << "\n" << user.getProfile() << "\n";
                break;
            case 8: {
                std::string type;
                std::cout << "\nИзберете тип (Кардио/Силова/Йога/Плуване): ";
                std::getline(std::cin, type);
                tracker.filterByType(type);
                break;
            }
            case 9:
                std::cout << "\n";
                tracker.printGoalProgress();
                tracker.checkGoal();
                break;
            case 10:
                std::cout << "\n";
                tracker.printAverageStats();
                break;
            case 11:
                std::cout << "\n";
                tracker.printCalorieBreakdown();
                break;
            case 12:
                tracker.sortByDate();
                std::cout << "✓ История е сортирана по дата\n";
                break;
            case 13: {
                std::cout << "\n--- Изтриване на тренировка ---\n";
                std::cout << "Първо вижте историята (опция 5) за да видите индексите\n";
                int index;
                std::cout << "Въведете индекс за изтриване: ";
                std::cin >> index;
                std::cin.ignore();
                tracker.deleteWorkout(index);
                std::cout << "✓ Тренировката е изтрита\n";
                break;
            }
            case 14:
                std::cout << "\n--- Файлови операции ---\n";
                tracker.saveToFile("workout_history.txt");
                std::cout << "✓ История е запазена в workout_history.txt\n";
                tracker.loadFromFile("workout_history.txt");
                break;
            case 0:
                std::cout << "\nДо скоро! Успешни тренировки! 💪\n";
                break;
            default:
                std::cout << "❌ Невалидна опция. Опитайте отново.\n";
        }
    }

    return 0;
}
