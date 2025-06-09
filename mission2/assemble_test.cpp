#ifdef _DEBUG

#include "gmock/gmock.h"
#include "CombineCarModule.h"

TEST(UNIT, CAR) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);

	EXPECT_EQ(CarType_Q, carTypeStep->GetMyStep());

	carTypeStep->PrintInputInfo();

	for (int ans = 0; ans <= CarType_TRUCK + 1; ans++) {
		bool isValid = (ans >= CarType_SEDAN && ans <= CarType_TRUCK);

		EXPECT_EQ(isValid, carTypeStep->CheckValidAnswer(ans));
	}

	for (int ans = CarType_SEDAN; ans <= CarType_TRUCK; ans++) {
		EXPECT_EQ(Engine_Q, carTypeStep->GetNextStep(ans));
	}
}

TEST(UNIT, ENGINE) {
	CombineCarModule combinCarModule;
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);

	EXPECT_EQ(Engine_Q, engineStep->GetMyStep());

	engineStep->PrintInputInfo();

	for (int ans = 0; ans <= Engine_Dead + 1; ans++) {
		bool isValid = (ans >= 0 && ans <= Engine_Dead);

		EXPECT_EQ(isValid, engineStep->CheckValidAnswer(ans));
	}

	for (int ans = 0; ans <= Engine_Dead; ans++) {
		int nextStep = (ans == 0) ? CarType_Q : BreakSystem_Q;

		EXPECT_EQ(nextStep, engineStep->GetNextStep(ans));
	}
}

TEST(UNIT, BREAK) {
	CombineCarModule combinCarModule;
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);

	EXPECT_EQ(BreakSystem_Q, breakStep->GetMyStep());

	breakStep->PrintInputInfo();

	for (int ans = 0; ans <= BreakSystem_BOSCH_B + 1; ans++) {
		bool isValid = (ans >= 0 && ans <= BreakSystem_BOSCH_B);

		EXPECT_EQ(isValid, breakStep->CheckValidAnswer(ans));
	}

	for (int ans = 0; ans <= BreakSystem_BOSCH_B; ans++) {
		int nextStep = (ans == 0) ? Engine_Q : SteeringSystem_Q;

		EXPECT_EQ(nextStep, breakStep->GetNextStep(ans));
	}
}

TEST(UNIT, STEERING) {
	CombineCarModule combinCarModule;
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);

	EXPECT_EQ(SteeringSystem_Q, steeringStep->GetMyStep());

	steeringStep->PrintInputInfo();

	for (int ans = 0; ans <= SteeringSystem_MOBIS + 1; ans++) {
		bool isValid = (ans >= 0 && ans <= SteeringSystem_MOBIS);

		EXPECT_EQ(isValid, steeringStep->CheckValidAnswer(ans));
	}

	for (int ans = 0; ans <= SteeringSystem_MOBIS; ans++) {
		int nextStep = (ans == 0) ? BreakSystem_Q : Run_Test;

		EXPECT_EQ(nextStep, steeringStep->GetNextStep(ans));
	}
}

TEST(UNIT, RUN_TEST) {
	CombineCarModule combinCarModule;
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	EXPECT_EQ(Run_Test, runTestStep->GetMyStep());

	runTestStep->PrintInputInfo();

	for (int ans = 0; ans <= RunTest_TestCombine + 1; ans++) {
		bool isValid = (ans >= 0 && ans <= RunTest_TestCombine);

		EXPECT_EQ(isValid, runTestStep->CheckValidAnswer(ans));
	}

	for (int ans = 0; ans <= SteeringSystem_MOBIS; ans++) {
		int nextStep = (ans == 0) ? CarType_Q : Run_Test;

		EXPECT_EQ(nextStep, runTestStep->GetNextStep(ans));
	}
}

TEST(INTEGRATION, VALID_COMBI_1) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_SEDAN;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_GM;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_MANDO;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_BOSCH_S;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_None, combinCarModule.getErrorType());
}

TEST(INTEGRATION, VALID_COMBI_2) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_SUV;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_WIA;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_BOSCH_B;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_BOSCH_S;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_None, combinCarModule.getErrorType());
}

TEST(INTEGRATION, VALID_COMBI_3) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_TRUCK;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_GM;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_CONTINENTAL;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_BOSCH_S;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_None, combinCarModule.getErrorType());
}

TEST(INTEGRATION, VALID_COMBI_4) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_SEDAN;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_TOYOTA;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_MANDO;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_MOBIS;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_None, combinCarModule.getErrorType());
}

TEST(INTEGRATION, INVALID_COMBI_1) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_SEDAN;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_GM;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_CONTINENTAL;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_BOSCH_S;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_Sedan_Continental, combinCarModule.getErrorType());
}

TEST(INTEGRATION, INVALID_COMBI_2) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_SUV;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_TOYOTA;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_MANDO;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_BOSCH_S;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_SUV_TOYOTA, combinCarModule.getErrorType());
}

TEST(INTEGRATION, INVALID_COMBI_3) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_TRUCK;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_WIA;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_MANDO;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_BOSCH_S;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_Truck_WIA, combinCarModule.getErrorType());
}

TEST(INTEGRATION, INVALID_COMBI_4) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_TRUCK;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_GM;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_MANDO;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_BOSCH_S;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_Truck_Mando, combinCarModule.getErrorType());
}

TEST(INTEGRATION, INVALID_COMBI_5) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_SEDAN;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_GM;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_BOSCH_B;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_MOBIS;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_BOSCH_B_BOSCH_S, combinCarModule.getErrorType());
}

TEST(INTEGRATION, RANDOM_COMBI) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = (rand() % CarType_TRUCK) + 1;
	carTypeStep->ProcessAnswer(car);

	int engine = (rand() % Engine_WIA) + 1;
	engineStep->ProcessAnswer(engine);

	int brk = (rand() % BreakSystem_BOSCH_B) + 1;
	breakStep->ProcessAnswer(brk);

	int steering = (rand() % SteeringSystem_MOBIS) + 1;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);
}

TEST(INTEGRATION, VALID_DEAD_ENGINE) {
	CombineCarModule combinCarModule;
	IStep* carTypeStep = combinCarModule.GetStep(CarType_Q);
	IStep* engineStep = combinCarModule.GetStep(Engine_Q);
	IStep* breakStep = combinCarModule.GetStep(BreakSystem_Q);
	IStep* steeringStep = combinCarModule.GetStep(SteeringSystem_Q);
	IStep* runTestStep = combinCarModule.GetStep(Run_Test);

	int car = CarType_SEDAN;
	carTypeStep->ProcessAnswer(car);

	int engine = Engine_Dead;
	engineStep->ProcessAnswer(engine);

	int brk = BreakSystem_MANDO;
	breakStep->ProcessAnswer(brk);

	int steering = SteeringSystem_BOSCH_S;
	steeringStep->ProcessAnswer(steering);

	runTestStep->ProcessAnswer(RunTest_RunCar);
	runTestStep->ProcessAnswer(RunTest_TestCombine);

	EXPECT_EQ(Error_None, combinCarModule.getErrorType());
}

#endif