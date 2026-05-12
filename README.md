# Фитнес Тракер — Проект по ООП

## Компилиране и стартиране

```bash
make
./fitness_tracker
```

## Реализирани функционалности

| # | Функционалност | Файл |
|---|---|---|
| 1 | Добавяне на тренировка | FitnessTracker::addWorkout |
| 2 | Изчисляване на калории | CardioWorkout/StrengthWorkout/YogaWorkout::calcCalories |
| 3 | История на тренировките | FitnessTracker::printHistory |
| 4 | Потребителски профил | User::getProfile |
| 5 | Статистика | FitnessTracker::printStats |
| 6 | Задаване на цели | WorkoutGoal + FitnessTracker::printGoalProgress |
| 7 | Известяване при цел | FitnessTracker::checkGoal |
| 8 | Филтриране по вид | FitnessTracker::filterByType |

## Класова йерархия

```
Workout (abstract)
├── CardioWorkout
├── StrengthWorkout
└── YogaWorkout

User
WorkoutGoal
FitnessTracker  (съдържа User, WorkoutGoal, vector<Workout*>)
```

## Промени спрямо Чекпойнт 1

Дизайнът е запазен без съществени промени. Единственото малко отклонение:
- `FitnessTracker::printStats()` не приема period параметър (опростено за демонстрация — показва статистика за всички тренировки, не само за период). Може да се добави в бъдеще с филтриране по дата.
