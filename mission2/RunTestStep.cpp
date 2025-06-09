#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "RunTestStep.h"

void RunTestStep::PrintInputInfo() {
    printf("멋진 차량이 완성되었습니다.\n");
    printf("어떤 동작을 할까요?\n");
    printf("0. 처음 화면으로 돌아가기\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

bool RunTestStep::CheckValidAnswer(int answer) {
    if (!(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(800);
        return false;
    }
    
    return true;
}

int RunTestStep::GetNextStep(int answer) {
    return (answer == 0) ? CarType_Q : myStep;
}

void RunTestStep::ProcessAnswer(int answer) {
    switch (answer)
    {
    case RunTest_RunCar:
        runProducedCar();
        break;
    case RunTest_TestCombine:
        printf("Test...\n");
        delay(1500);
        testProducedCar();
        break;
    default:
        break;
    }

    delay(2000);
}