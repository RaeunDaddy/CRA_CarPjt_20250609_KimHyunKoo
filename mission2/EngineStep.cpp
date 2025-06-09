#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "EngineStep.h"

void EngineStep::PrintInputInfo() {
    printf("� ������ ž���ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. ���峭 ����\n");
}

bool EngineStep::CheckValidAnswer(int answer) {
    if (!(answer >= 0 && answer <= Engine_Dead))
    {
        printf("ERROR :: ������ 0 ~ 4 ������ ���� ����\n");
        delay(800);
        return false;
    }

    return true;
}

void EngineStep::ProcessAnswer(int answer) {
    switch (answer)
    {
    case Engine_GM:
        printf("GM ������ �����ϼ̽��ϴ�.\n");
        break;
    case Engine_TOYOTA:
        printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
        break;
    case Engine_WIA:
        printf("WIA ������ �����ϼ̽��ϴ�.\n");
        break;
    default:
        break;
    }

    IStep::ProcessAnswer(answer);
}