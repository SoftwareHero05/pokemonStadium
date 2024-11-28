#pragma once
#include "Move.h"

class Flamethrower: public Move{
	public:
	Flamethrower():Move(90,FIRE,false,4,"Flamethrower"){
	}
};