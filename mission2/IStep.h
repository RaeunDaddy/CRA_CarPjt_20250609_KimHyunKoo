#pragma once

#include "Type.h"

class IStep
{
public:
	virtual void PrintInputInfo() = 0;
	virtual bool CheckValidAnswer(int answer) = 0;
	virtual int GetNextStep(int answer) {
		return (answer == 0) ? myStep - 1 : myStep + 1;
	}
	virtual int GetMyStep() {
		return myStep;
	}
	virtual void ProcessAnswer(int answer) {
		myModule = answer;
		delay(800);
	}
	virtual int GetModule() {
		return myModule;
	}

	int myStep;
	int myModule;
};