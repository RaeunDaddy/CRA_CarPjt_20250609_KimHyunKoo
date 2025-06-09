#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "BreakStep.h"

void BreakStep::PrintInputInfo() {
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

bool BreakStep::CheckValidAnswer(int answer) {
    if (!(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: 제동장치는 0 ~ 3 범위만 선택 가능\n");
        delay(800);
        return false;
    }
    
    return true;
}

void BreakStep::ProcessAnswer(int answer) {
    switch (answer)
    {
    case BreakSystem_MANDO:
        printf("MANDO 제동장치를 선택하셨습니다.\n");
        break;
    case BreakSystem_CONTINENTAL:
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
        break;
    case BreakSystem_BOSCH_B:
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
        break;
    default:
        break;
    }

    IStep::ProcessAnswer(answer);
}