#pragma once

#include "IStep.h"

class CarTypeStep : public IStep {
public:
	CarTypeStep(int stepIdx) {
		myStep = stepIdx;
	}
	void PrintInputInfo() override;
	bool CheckValidAnswer(int answer) override;
	int GetNextStep(int answer) override;
	void ProcessAnswer(int answer) override;
};