#pragma once
#include "Move.h"

class Surf: public Move{
	public:
	Surf():Move(90,WATER,false,16,"Surf"){
	}
};