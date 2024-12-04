#pragma once
#include "Move.h"

class WaterFall: public Move{
	public:
	WaterFall():Move(90,WATER,true,25,"WaterFall"){
	}
};