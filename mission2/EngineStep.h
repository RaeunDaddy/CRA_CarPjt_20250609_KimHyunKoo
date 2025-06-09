#pragma once

#include "IStep.h"

class EngineStep : public IStep {
public:
	EngineStep(int stepIdx) {
		myStep = stepIdx;
	}
	void PrintInputInfo() override;
	bool CheckValidAnswer(int answer) override;
	void ProcessAnswer(int answer) override;
};