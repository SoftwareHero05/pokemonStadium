#pragma once
#include "Move.h"

class AuraSphere: public Move{
	public:
	AuraSphere():Move(80,FIGHTING,false){
		id = 1;
		nombre = "AuraSphere";
	}
};