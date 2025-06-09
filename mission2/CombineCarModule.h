#pragma once

#include "Type.h"
#include "IStep.h"

class CombineCarModule {
public:
	CombineCarModule();

	IStep* GetStep(int step);
	void RunProducedCar();
	void TestProducedCar();

private:
	int module[QuestionType_Count]{ 0, };
	IStep* step[QuestionType_Count];

	bool isValidCombine();
	void printCarType();
	void printEngine();
	void printBreakSystem();
	void printSteeringSystem();
	bool isDeadEngine();

#ifdef _DEBUG
public:
#else
private:
#endif
	int getErrorType();
};