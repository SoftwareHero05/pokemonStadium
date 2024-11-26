#pragma once
#include "Move.h"

class EarthPower: public Move{
	public:
	EarthPower():Move(90,GROUND,false){
		id = 20;
		nombre = "EarthPower";
	}
};