#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "BreakStep.h"

void BreakStep::PrintInputInfo() {
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

bool BreakStep::CheckValidAnswer(int answer) {
    if (!(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: ������ġ�� 0 ~ 3 ������ ���� ����\n");
        delay(800);
        return false;
    }
    
    return true;
}

void BreakStep::ProcessAnswer(int answer) {
    switch (answer)
    {
    case BreakSystem_MANDO:
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
        break;
    case BreakSystem_CONTINENTAL:
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
        break;
    case BreakSystem_BOSCH_B:
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        break;
    default:
        break;
    }

    IStep::ProcessAnswer(answer);
}