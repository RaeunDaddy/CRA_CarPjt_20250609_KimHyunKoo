#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "SteeringStep.h"

void SteeringStep::PrintInputInfo() {
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

bool SteeringStep::CheckValidAnswer(int answer) {
    if (!(answer >= 0 && answer <= SteeringSystem_MOBIS))
    {
        printf("ERROR :: 조향장치는 0 ~ 2 범위만 선택 가능\n");
        delay(800);
        return false;
    }
    
    return true;
}

void SteeringStep::ProcessAnswer(int answer) {
    switch (answer)
    {
    case SteeringSystem_BOSCH_S:
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
        break;
    case SteeringSystem_MOBIS:
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
        break;
    default:
        break;
    }

    IStep::ProcessAnswer(answer);
}