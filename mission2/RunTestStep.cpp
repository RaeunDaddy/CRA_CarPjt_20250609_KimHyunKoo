#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Type.h"
#include "RunTestStep.h"

void RunTestStep::PrintInputInfo() {
    printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
    printf("� ������ �ұ��?\n");
    printf("0. ó�� ȭ������ ���ư���\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

bool RunTestStep::CheckValidAnswer(int answer) {
    if (!(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
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