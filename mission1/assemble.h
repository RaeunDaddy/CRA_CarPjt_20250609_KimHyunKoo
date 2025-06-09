#pragma once

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    breakSystem_Q,
    SteeringSystem_Q,
    Run_Test
};

enum CarType
{
    CarType_SEDAN = 1,
    CarType_SUV,
    CarType_TRUCK
};

enum Engine
{
    Engine_GM = 1,
    Engine_TOYOTA,
    Engine_WIA,
    Engine_Dead,
};

enum BreakSystem
{
    BreakSystem_MANDO = 1,
    BreakSystem_CONTINENTAL,
    BreakSystem_BOSCH_B
};

enum SteeringSystem
{
    SteeringSystem_BOSCH_S = 1,
    SteeringSystem_MOBIS
};

enum ErrorType
{
    Error_None,
    Error_Sedan_Continental,
    Error_SUV_TOYOTA,
    Error_Truck_WIA,
    Error_Truck_Mando,
    Error_BOSCH_B_BOSCH_S,
};

#define CLEAR_SCREEN "\033[H\033[2J"

int combinedModule[Run_Test];

void setCarType(int answer);
void setEngine(int answer);
void setbrakeSystem(int answer);
void setSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);
void printInputInfo(int step);
bool checkValidRange(int step, int answer);
void processAnswer(int step, int answer);
int getNextStep(int step, int answer);
bool needGoBackStep(int step, int nextStep);
void printCarType();
void printEngine();
void printBreakSystem();
void printSteeringSystem();
int getErrorType();
bool isValidCombine();
bool isDeadEngine();
