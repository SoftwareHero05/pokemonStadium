#pragma once
#include "Move.h"

class Flamethrower: public Move{
	public:
	Flamethrower():Move(90,FIRE,false){
		id = 4;
		nombre = "Flamehrower";
	}
};