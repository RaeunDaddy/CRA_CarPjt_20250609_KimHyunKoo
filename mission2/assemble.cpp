#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "CombineCarModule.h"

#define CLEAR_SCREEN "\033[H\033[2J"

#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

int main()
{
    char buf[100];
    CombineCarModule combineCarModule;
    IStep* step = combineCarModule.GetStep(CarType_Q);

    while (1)
    {
        printf(CLEAR_SCREEN);
        step->PrintInputInfo();
        printf("===============================\n");

        printf("INPUT > ");
        fgets(buf, sizeof(buf), stdin);

        // 엔터 개행문자 제거
        char *context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("바이바이\n");
            break;
        }

        // 숫자로 된 대답인지 확인
        char *checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환

        // 입력받은 문자가 숫자가 아니라면
        if (*checkNumber != '\0')
        {
            printf("ERROR :: 숫자만 입력 가능\n");
            delay(800);
            continue;
        }

        if (step->CheckValidAnswer(answer) == false) {
            continue;
        }

        int nextStep = step->GetNextStep(answer);
        if ((step->GetMyStep() > nextStep) == false) {
            step->ProcessAnswer(answer);
        }
        step = combineCarModule.GetStep(nextStep);
    }
}

#endif