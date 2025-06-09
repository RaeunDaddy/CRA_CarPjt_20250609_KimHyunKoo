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
        printf("� ���� Ÿ���� �����ұ��?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (step == Engine_Q)
    {
        printf("� ������ ž���ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. ���峭 ����\n");
    }
    else if (step == breakSystem_Q)
    {
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (step == SteeringSystem_Q)
    {
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (step == Run_Test)
    {
        printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
        printf("� ������ �ұ��?\n");
        printf("0. ó�� ȭ������ ���ư���\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");
}

bool checkValidRange(int step, int answer) {
    if (step == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (step == Engine_Q && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (step == breakSystem_Q && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (step == Run_Test && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
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

        // ���� ���๮�� ����
        char *context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("���̹���\n");
            break;
        }

        // ���ڷ� �� ������� Ȯ��
        char *checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

        // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
        if (*checkNumber != '\0')
        {
            printf("ERROR :: ���ڸ� �Է� ����\n");
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
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    if (answer == 2)
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    if (answer == 3)
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
}

void setEngine(int answer)
{
    combinedModule[Engine_Q] = answer;
    if (answer == 1)
        printf("GM ������ �����ϼ̽��ϴ�.\n");
    if (answer == 2)
        printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
    if (answer == 3)
        printf("WIA ������ �����ϼ̽��ϴ�.\n");
}

void setbrakeSystem(int answer)
{
    combinedModule[breakSystem_Q] = answer;
    if (answer == 1)
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    if (answer == 2)
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    if (answer == 3)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void setSteeringSystem(int answer)
{
    combinedModule[SteeringSystem_Q] = answer;
    if (answer == 1)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    if (answer == 2)
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
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
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        return;
    }

    if (isDeadEngine() == true)
    {
        printf("������ ���峪�ֽ��ϴ�.\n");
        printf("�ڵ����� �������� �ʽ��ϴ�.\n");

        return;
    }

    printCarType();

    printEngine();

    printBreakSystem();
    
    printSteeringSystem();

    printf("�ڵ����� ���۵˴ϴ�.\n");
}

void testProducedCar()
{
    switch (getErrorType()) {
    case Error_None:
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
        break;
    case Error_Sedan_Continental:
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        break;
    case Error_SUV_TOYOTA:
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        break;
    case Error_Truck_WIA:
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
        break;
    case Error_Truck_Mando:
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
        break;
    case Error_BOSCH_B_BOSCH_S:
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        break;
    default:
        printf("�߸��� ���� ����. getErrorType() �Լ� Ȯ�� �ʿ�");
        break;
    }
}