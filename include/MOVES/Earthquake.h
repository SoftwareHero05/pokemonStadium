#pragma once
#include "Move.h"

class Earthquake: public Move{
	public:
	Earthquake():Move(100,GROUND,true){
		id = 7;
		nombre = "Earthquake";
	}
};