#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CarTypeStep.h"
#include "EngineStep.h"
#include "BreakStep.h"
#include "SteeringStep.h"
#include "RunTestStep.h"

#include "CombineCarModule.h"

CombineCarModule::CombineCarModule() {
    step[CarType_Q] = new CarTypeStep(CarType_Q);
    step[Engine_Q] = new EngineStep(Engine_Q);
    step[BreakSystem_Q] = new BreakStep(BreakSystem_Q);
    step[SteeringSystem_Q] = new SteeringStep(SteeringSystem_Q);
    step[Run_Test] = new RunTestStep(Run_Test, this);
}

IStep* CombineCarModule::GetStep(int stepIndex) {
    return (stepIndex < QuestionType_Count) ? step[stepIndex] : nullptr;
}

int CombineCarModule::getErrorType() {
    if (step[CarType_Q]->GetModule() == CarType_SEDAN && step[BreakSystem_Q]->GetModule() == BreakSystem_CONTINENTAL)
    {
        return Error_Sedan_Continental;
    }
    
    if (step[CarType_Q]->GetModule() == CarType_SUV && step[Engine_Q]->GetModule() == Engine_TOYOTA)
    {
        return Error_SUV_TOYOTA;
    }
    
    if (step[CarType_Q]->GetModule() == CarType_TRUCK && step[Engine_Q]->GetModule() == Engine_WIA)
    {
        return Error_Truck_WIA;
    }
    
    if (step[CarType_Q]->GetModule() == CarType_TRUCK && step[BreakSystem_Q]->GetModule() == BreakSystem_MANDO)
    {
        return Error_Truck_Mando;
    }
    
    if (step[BreakSystem_Q]->GetModule() == BreakSystem_BOSCH_B && step[SteeringSystem_Q]->GetModule() != SteeringSystem_BOSCH_S)
    {
        return Error_BOSCH_B_BOSCH_S;
    }

    return Error_None;
}

bool CombineCarModule::isValidCombine()
{
    return (getErrorType() == Error_None);
}

void CombineCarModule::RunProducedCar()
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

void CombineCarModule::TestProducedCar()
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
    }
}

void CombineCarModule::printCarType() {
    if (step[CarType_Q]->GetModule() == CarType_SEDAN)
        printf("Car Type : Sedan\n");
    if (step[CarType_Q]->GetModule() == CarType_SUV)
        printf("Car Type : SUV\n");
    if (step[CarType_Q]->GetModule() == CarType_TRUCK)
        printf("Car Type : Truck\n");
}
void CombineCarModule::printEngine() {
    if (step[Engine_Q]->GetModule() == Engine_GM)
        printf("Engine : GM\n");
    if (step[Engine_Q]->GetModule() == Engine_TOYOTA)
        printf("Engine : TOYOTA\n");
    if (step[Engine_Q]->GetModule() == Engine_WIA)
        printf("Engine : WIA\n");
}
void CombineCarModule::printBreakSystem() {
    if (step[BreakSystem_Q]->GetModule() == BreakSystem_MANDO)
        printf("Break System : Mando\n");
    if (step[BreakSystem_Q]->GetModule() == BreakSystem_CONTINENTAL)
        printf("Break System : Continental\n");
    if (step[BreakSystem_Q]->GetModule() == BreakSystem_BOSCH_B)
        printf("Break System : Bosch\n");
}
void CombineCarModule::printSteeringSystem() {
    if (step[SteeringSystem_Q]->GetModule() == SteeringSystem_BOSCH_S)
        printf("SteeringSystem : Bosch\n");
    if (step[SteeringSystem_Q]->GetModule() == SteeringSystem_MOBIS)
        printf("SteeringSystem : Mobis\n");
}

bool CombineCarModule::isDeadEngine() {
    return (step[Engine_Q]->GetModule() == Engine_Dead);
}