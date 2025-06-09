#pragma once

#include "IStep.h"

class BreakStep : public IStep {
public:
	BreakStep(int stepIdx) {
		myStep = stepIdx;
	}
	void PrintInputInfo() override;
	bool CheckValidAnswer(int answer) override;
	void ProcessAnswer(int answer) override;
};