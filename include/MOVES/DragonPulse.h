#pragma once
#include "Move.h"

class DragonPulse: public Move{
	public:
	DragonPulse():Move(85,DRAGON,true){
		id = 3;
		nombre = "DragonPulse";
	}
};