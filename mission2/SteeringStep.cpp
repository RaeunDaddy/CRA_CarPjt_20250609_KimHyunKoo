#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "SteeringStep.h"

void SteeringStep::PrintInputInfo() {
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

bool SteeringStep::CheckValidAnswer(int answer) {
    if (!(answer >= 0 && answer <= SteeringSystem_MOBIS))
    {
        printf("ERROR :: ������ġ�� 0 ~ 2 ������ ���� ����\n");
        delay(800);
        return false;
    }
    
    return true;
}

void SteeringStep::ProcessAnswer(int answer) {
    switch (answer)
    {
    case SteeringSystem_BOSCH_S:
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        break;
    case SteeringSystem_MOBIS:
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
        break;
    default:
        break;
    }

    IStep::ProcessAnswer(answer);
}