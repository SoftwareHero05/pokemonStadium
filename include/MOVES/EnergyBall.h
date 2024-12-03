#pragma once
#include "Move.h"

class EnergyBall : public Move
{
public:
	EnergyBall() : Move(90, GRASS, false, 17, "EnergyBall")
	{
	}
};