#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "CarTypeStep.h"

void CarTypeStep::PrintInputInfo() {
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

bool CarTypeStep::CheckValidAnswer(int answer) {
    if (!(answer >= CarType_SEDAN && answer <= CarType_TRUCK))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    return true;
}

int CarTypeStep::GetNextStep(int answer) {
    return myStep + 1;
}

void CarTypeStep::ProcessAnswer(int answer) {
    switch (answer)
    {
    case CarType_SEDAN:
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
        break;
    case CarType_SUV:
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
        break;
    case CarType_TRUCK:
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
        break;
    default:
        break;
    }

    IStep::ProcessAnswer(answer);
}