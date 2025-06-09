#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "EngineStep.h"

void EngineStep::PrintInputInfo() {
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");
}

bool EngineStep::CheckValidAnswer(int answer) {
    if (!(answer >= 0 && answer <= Engine_Dead))
    {
        printf("ERROR :: 엔진은 0 ~ 4 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    return true;
}

void EngineStep::ProcessAnswer(int answer) {
    switch (answer)
    {
    case Engine_GM:
        printf("GM 엔진을 선택하셨습니다.\n");
        break;
    case Engine_TOYOTA:
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
        break;
    case Engine_WIA:
        printf("WIA 엔진을 선택하셨습니다.\n");
        break;
    default:
        break;
    }

    IStep::ProcessAnswer(answer);
}