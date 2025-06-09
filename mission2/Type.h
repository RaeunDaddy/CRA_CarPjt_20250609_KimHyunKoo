#pragma once

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BreakSystem_Q,
    SteeringSystem_Q,
    Run_Test,

    QuestionType_Count,
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

enum RunTest
{
    RunTest_RunCar = 1,
    RunTest_TestCombine,
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

static void delay(int ms)
{
#ifndef _DEBUG
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
#endif
}