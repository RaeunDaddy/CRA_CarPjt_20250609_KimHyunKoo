#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assemble.h"

void delay(int ms)
{
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
}

void printInputInfo(int step) {
    printf(CLEAR_SCREEN);
    if (step == CarType_Q)
    {
        printf("        ______________\n");
        printf("       /|            | \n");
        printf("  ____/_|_____________|____\n");
        printf(" |                      O  |\n");
        printf(" '-(@)----------------(@)--'\n");
        printf("===============================\n");
        printf("어떤 차량 타입을 선택할까요?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (step == Engine_Q)
    {
        printf("어떤 엔진을 탑재할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. 고장난 엔진\n");
    }
    else if (step == breakSystem_Q)
    {
        printf("어떤 제동장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (step == SteeringSystem_Q)
    {
        printf("어떤 조향장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (step == Run_Test)
    {
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");
}

bool checkValidRange(int step, int answer) {
    if (step == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (step == Engine_Q && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (step == breakSystem_Q && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (step == Run_Test && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(800);
        return false;
    }

    return true;
}

void processAnswer(int step, int answer) {
    if (step == CarType_Q)
    {
        setCarType(answer);
        delay(800);
    }
    else if (step == Engine_Q)
    {
        setEngine(answer);
        delay(800);
    }
    else if (step == breakSystem_Q)
    {
        setbrakeSystem(answer);
        delay(800);
    }
    else if (step == SteeringSystem_Q)
    {
        setSteeringSystem(answer);
        delay(800);
    }
    else if (step == Run_Test && answer == 1)
    {
        runProducedCar();
        delay(2000);
    }
    else if (step == Run_Test && answer == 2)
    {
        printf("Test...\n");
        delay(1500);
        testProducedCar();
        delay(2000);
    }
}

int getNextStep(int step, int answer) {
    if (answer == 0 && step == Run_Test) {
        step = CarType_Q;
    } else if (answer == 0 && step >= 1) {
        step -= 1;
    } else if (step != Run_Test) {
        step += 1;
    }

    return step;
}

bool needGoBackStep(int step, int nextStep) {
    return (step > nextStep);
}

int main()
{
    char buf[100];
    int step = CarType_Q;

    while (1)
    {
        printInputInfo(step);

        printf("INPUT > ");
        fgets(buf, sizeof(buf), stdin);

        // 엔터 개행문자 제거
        char *context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("바이바이\n");
            break;
        }

        // 숫자로 된 대답인지 확인
        char *checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환

        // 입력받은 문자가 숫자가 아니라면
        if (*checkNumber != '\0')
        {
            printf("ERROR :: 숫자만 입력 가능\n");
            delay(800);
            continue;
        }

        if (checkValidRange(step, answer) == false) {
            continue;
        }

        int nextStep = getNextStep(step, answer);
        if (needGoBackStep(step, nextStep) == false) {
            processAnswer(step, answer);
        }
        step = nextStep;
    }
}

void setCarType(int answer)
{
    combinedModule[CarType_Q] = answer;
    if (answer == 1)
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (answer == 2)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (answer == 3)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
}

void setEngine(int answer)
{
    combinedModule[Engine_Q] = answer;
    if (answer == 1)
        printf("GM 엔진을 선택하셨습니다.\n");
    if (answer == 2)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (answer == 3)
        printf("WIA 엔진을 선택하셨습니다.\n");
}

void setbrakeSystem(int answer)
{
    combinedModule[breakSystem_Q] = answer;
    if (answer == 1)
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (answer == 2)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (answer == 3)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

void setSteeringSystem(int answer)
{
    combinedModule[SteeringSystem_Q] = answer;
    if (answer == 1)
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (answer == 2)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
}

int getErrorType() {
    if (combinedModule[CarType_Q] == CarType_SEDAN && combinedModule[breakSystem_Q] == BreakSystem_CONTINENTAL)
    {
        return Error_Sedan_Continental;
    }
    else if (combinedModule[CarType_Q] == CarType_SUV && combinedModule[Engine_Q] == Engine_TOYOTA)
    {
        return Error_SUV_TOYOTA;
    }
    else if (combinedModule[CarType_Q] == CarType_TRUCK && combinedModule[Engine_Q] == Engine_WIA)
    {
        return Error_Truck_WIA;
    }
    else if (combinedModule[CarType_Q] == CarType_TRUCK && combinedModule[breakSystem_Q] == BreakSystem_MANDO)
    {
        return Error_Truck_Mando;
    }
    else if (combinedModule[breakSystem_Q] == BreakSystem_BOSCH_B && combinedModule[SteeringSystem_Q] != SteeringSystem_BOSCH_S)
    {
        return Error_BOSCH_B_BOSCH_S;
    }
    else
    {
        return Error_None;
    }
}

bool isValidCombine()
{
    return (getErrorType() == Error_None);
}

void printCarType() {
    if (combinedModule[CarType_Q] == CarType_SEDAN)
        printf("Car Type : Sedan\n");
    if (combinedModule[CarType_Q] == CarType_SUV)
        printf("Car Type : SUV\n");
    if (combinedModule[CarType_Q] == CarType_TRUCK)
        printf("Car Type : Truck\n");
}
void printEngine() {
    if (combinedModule[Engine_Q] == Engine_GM)
        printf("Engine : GM\n");
    if (combinedModule[Engine_Q] == Engine_TOYOTA)
        printf("Engine : TOYOTA\n");
    if (combinedModule[Engine_Q] == Engine_WIA)
        printf("Engine : WIA\n");
}
void printBreakSystem() {
    if (combinedModule[breakSystem_Q] == BreakSystem_MANDO)
        printf("Break System : Mando");
    if (combinedModule[breakSystem_Q] == BreakSystem_CONTINENTAL)
        printf("Break System : Continental\n");
    if (combinedModule[breakSystem_Q] == BreakSystem_BOSCH_B)
        printf("Break System : Bosch\n");
}
void printSteeringSystem() {
    if (combinedModule[SteeringSystem_Q] == SteeringSystem_BOSCH_S)
        printf("SteeringSystem : Bosch\n");
    if (combinedModule[SteeringSystem_Q] == SteeringSystem_MOBIS)
        printf("SteeringSystem : Mobis\n");
}

bool isDeadEngine() {
    return (combinedModule[Engine_Q] == Engine_Dead);
}

void runProducedCar()
{
    if (isValidCombine() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
        return;
    }

    if (isDeadEngine() == true)
    {
        printf("엔진이 고장나있습니다.\n");
        printf("자동차가 움직이지 않습니다.\n");

        return;
    }

    printCarType();

    printEngine();

    printBreakSystem();
    
    printSteeringSystem();

    printf("자동차가 동작됩니다.\n");
}

void testProducedCar()
{
    switch (getErrorType()) {
    case Error_None:
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
        break;
    case Error_Sedan_Continental:
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
        break;
    case Error_SUV_TOYOTA:
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
        break;
    case Error_Truck_WIA:
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
        break;
    case Error_Truck_Mando:
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
        break;
    case Error_BOSCH_B_BOSCH_S:
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        break;
    default:
        printf("잘못된 조합 정보. getErrorType() 함수 확인 필요");
        break;
    }
}