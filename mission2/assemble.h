#pragma once

#include "Type.h"

#define CLEAR_SCREEN "\033[H\033[2J"

int combinedModule[Run_Test];

void setCarType(int answer);
void setEngine(int answer);
void setbrakeSystem(int answer);
void setSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();