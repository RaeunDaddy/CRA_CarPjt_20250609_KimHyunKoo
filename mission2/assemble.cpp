#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CombineCarModule.h"
#include "assemble.h"

bool needGoBackStep(int step, int nextStep) {
    return (step > nextStep);
}

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

        // ���� ���๮�� ����
        char *context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("���̹���\n");
            break;
        }

        // ���ڷ� �� ������� Ȯ��
        char *checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

        // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
        if (*checkNumber != '\0')
        {
            printf("ERROR :: ���ڸ� �Է� ����\n");
            delay(800);
            continue;
        }

        if (step->CheckValidAnswer(answer) == false) {
            continue;
        }

        int nextStep = step->GetNextStep(answer);
        if (needGoBackStep(step->GetMyStep(), nextStep) == false) {
            step->ProcessAnswer(answer);
        }
        step = combineCarModule.GetStep(nextStep);
    }
}