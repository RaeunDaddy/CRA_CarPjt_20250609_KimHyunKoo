#pragma once

#include "IStep.h"

class SteeringStep : public IStep {
public:
	SteeringStep(int stepIdx) {
		myStep = stepIdx;
	}
	void PrintInputInfo() override;
	bool CheckValidAnswer(int answer) override;
	void ProcessAnswer(int answer) override;
};