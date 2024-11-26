#pragma once
#include "Move.h"

class FlashCannon: public Move{
	public:
	FlashCannon():Move(90,STEEL,false){
		id = 14;
		nombre = "FlashCannon";
	}
};