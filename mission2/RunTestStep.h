#pragma once

#include "IStep.h"
#include "CombineCarModule.h"

class RunTestStep : public IStep {
public:
	RunTestStep(int stepIdx, CombineCarModule* combinCarModule) {
		myStep = stepIdx;
		myCombineCarModule = combinCarModule;
	}
	void PrintInputInfo() override;
	bool CheckValidAnswer(int answer) override;
	int GetNextStep(int answer) override;
	void ProcessAnswer(int answer) override;

private:
	CombineCarModule* myCombineCarModule;

	void runProducedCar() {
		myCombineCarModule->RunProducedCar();
	}
	void testProducedCar() {
		myCombineCarModule->TestProducedCar();
	}
};