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
    printf("� ���� Ÿ���� �����ұ��?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

bool CarTypeStep::CheckValidAnswer(int answer) {
    if (!(answer >= CarType_SEDAN && answer <= CarType_TRUCK))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
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
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
        break;
    case CarType_SUV:
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
        break;
    case CarType_TRUCK:
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
        break;
    default:
        break;
    }

    IStep::ProcessAnswer(answer);
}