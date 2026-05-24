CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRCS = src/main.cpp src/Workout.cpp src/CardioWorkout.cpp \
       src/StrengthWorkout.cpp src/YogaWorkout.cpp src/SwimmingWorkout.cpp \
       src/User.cpp src/WorkoutGoal.cpp src/FitnessTracker.cpp

TARGET = fitness_tracker

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
