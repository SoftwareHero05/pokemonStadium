#pragma once
#include "Move.h"

class EarthPower: public Move{
	public:
	EarthPower():Move(90,GROUND,false,20,"EarthPower"){
	}
};